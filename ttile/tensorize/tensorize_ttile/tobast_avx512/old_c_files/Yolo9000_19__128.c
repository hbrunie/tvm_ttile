#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (1, x); T (128, c);
  T (8, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]; T (8, c)]
*/
IND_TYPE c, cp_0, c1032_p_0, c1033_p_0, cp_1, c1032_p_1, cp_2, c1032, c1033, f, fp_0, x, xp_0, x774_p_0, xp_1, x774, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y516 = 0;
IND_TYPE x775 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1034 = 0;
IND_TYPE f516 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_8552 ,mem_vec_8553 ,mem_vec_8554 ,mem_vec_8555 ,mem_vec_8556 ,mem_vec_8557 ,mem_vec_8558 ,mem_vec_8559 ,mem_vec_8560 ,mem_vec_8561 ,mem_vec_8562 ,mem_vec_8563 ,mem_vec_8564 ,mem_vec_8565 ,mem_vec_8566 ,mem_vec_8567 ,mem_vec_8568 ,mem_vec_8569 ,mem_vec_8570 ,mem_vec_8571 ,mem_vec_8572 ,mem_vec_8573 ,mem_vec_8574 ,mem_vec_8575 ,mem_vec_8576 ,mem_vec_8577 ,mem_vec_8578 ,mem_vec_8579 ,mem_vec_8580 ,mem_vec_8581 ,mem_vec_8582 ,mem_vec_8583 ,mem_vec_8584 ,mem_vec_8585 ,mem_vec_8586 ,mem_vec_8587 ,mem_vec_8588 ,mem_vec_8589 ,mem_vec_8590 ,mem_vec_8591 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 8) (1024 / 128)
for (c1033 = c1034, c1033_p_0 = 0;
	c1033 < c1034 + 1024;
	c1033 += 128, c1033_p_0 += 128){
		for (y = y516, yp_0 = 0;
			y < y516 + 3;
			y += 3, yp_0 += 3){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (x, 17) (17 / 1)
			for (x774 = x775, x774_p_0 = 0;
				x774 < x775 + 17;
				x774 += 1, x774_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 512
				// T (f, 8) (512 / 64)
				for (f = f516, fp_0 = 0;
					f < f516 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (c, 128) (128 / 1)
					for (c1032 = c1033, c1032_p_1 = c1033_p_0, c1032_p_0 = 0;
						c1032 < c1033 + 128;
						c1032 += 1, c1032_p_1 += 1, c1032_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
						// T (x, 1) (1 / 1)
						for (x = x774, xp_1 = x774_p_0, xp_0 = 0;
							x < x774 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8552 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8553 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_8554 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_8555 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_8556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_8558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_8559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_8560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_8562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_8563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c1032, cp_2 = c1032_p_1, cp_1 = c1032_p_0, cp_0 = 0;
										c < c1032 + 1;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8552);
										mem_vec_8552 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8553);
										mem_vec_8553 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8554);
										mem_vec_8554 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8555);
										mem_vec_8555 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8556);
										mem_vec_8556 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8557);
										mem_vec_8557 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8558);
										mem_vec_8558 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8559);
										mem_vec_8559 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8560);
										mem_vec_8560 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8561);
										mem_vec_8561 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_8562);
										mem_vec_8562 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_8563);
										mem_vec_8563 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8552);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8553);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8554);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8555);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8556);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8557);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8558);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8559);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8560);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8561);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8562);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8563);
						}
					}
				}
			}
		}
		for (y = y516 + 3, yp_0 = 0;
			y < y516 + 3 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (x, 17) (17 / 1)
			for (x774 = x775, x774_p_0 = 0;
				x774 < x775 + 17;
				x774 += 1, x774_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 512
				// T (f, 8) (512 / 64)
				for (f = f516, fp_0 = 0;
					f < f516 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (c, 128) (128 / 1)
					for (c1032 = c1033, c1032_p_1 = c1033_p_0, c1032_p_0 = 0;
						c1032 < c1033 + 128;
						c1032 += 1, c1032_p_1 += 1, c1032_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
						// T (x, 1) (1 / 1)
						for (x = x774, xp_1 = x774_p_0, xp_0 = 0;
							x < x774 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8564 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8565 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_8566 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_8567 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_8568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_8570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_8571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_8572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_8574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_8575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_8576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_8577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_8578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_8579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_8580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_8581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_8582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_8583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_8584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_8585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_8586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_8587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_8588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_8589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_8590 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_8591 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c1032, cp_2 = c1032_p_1, cp_1 = c1032_p_0, cp_0 = 0;
										c < c1032 + 1;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8564);
										mem_vec_8564 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8565);
										mem_vec_8565 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8566);
										mem_vec_8566 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8567);
										mem_vec_8567 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8568);
										mem_vec_8568 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8569);
										mem_vec_8569 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8570);
										mem_vec_8570 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8571);
										mem_vec_8571 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8572);
										mem_vec_8572 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8573);
										mem_vec_8573 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_8574);
										mem_vec_8574 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_8575);
										mem_vec_8575 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8576);
										mem_vec_8576 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_8577);
										mem_vec_8577 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_8578);
										mem_vec_8578 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_8579);
										mem_vec_8579 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_8580);
										mem_vec_8580 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_8581);
										mem_vec_8581 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_8582);
										mem_vec_8582 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_8583);
										mem_vec_8583 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8584);
										mem_vec_8584 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8585);
										mem_vec_8585 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_8586);
										mem_vec_8586 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_8587);
										mem_vec_8587 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_8588);
										mem_vec_8588 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_8589);
										mem_vec_8589 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_8590);
										mem_vec_8590 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_8591);
										mem_vec_8591 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8564);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8565);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8566);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8567);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8568);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8569);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8570);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8571);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8572);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8573);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8574);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8575);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8576);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8577);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_8578);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_8579);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8580);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8581);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_8582);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_8583);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8584);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8585);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_8586);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_8587);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8588);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8589);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_8590);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_8591);
						}
					}
				}
			}
		}
}


}