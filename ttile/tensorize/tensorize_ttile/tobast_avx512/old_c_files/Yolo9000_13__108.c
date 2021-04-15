#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 10)); ((Iter 2), (Arg 12))]; T (8, f);
  T (16, c); T (34, x)]
*/
IND_TYPE c, cp_0, c582_p_0, cp_1, c582, f, fp_0, x, xp_0, x776_p_0, x777_p_0, xp_1, x776_p_1, xp_2, x776, x777, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y388 = 0;
IND_TYPE x778 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c583 = 0;
IND_TYPE f388 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7544 ,mem_vec_7545 ,mem_vec_7546 ,mem_vec_7547 ,mem_vec_7548 ,mem_vec_7549 ,mem_vec_7550 ,mem_vec_7551 ,mem_vec_7552 ,mem_vec_7553 ,mem_vec_7554 ,mem_vec_7555 ,mem_vec_7556 ,mem_vec_7557 ,mem_vec_7558 ,mem_vec_7559 ,mem_vec_7560 ,mem_vec_7561 ,mem_vec_7562 ,mem_vec_7563 ,mem_vec_7564 ,mem_vec_7565 ,mem_vec_7566 ,mem_vec_7567 ,mem_vec_7568 ,mem_vec_7569 ,mem_vec_7570 ,mem_vec_7571 ,mem_vec_7572 ,mem_vec_7573 ,mem_vec_7574 ,mem_vec_7575 ,mem_vec_7576 ,mem_vec_7577 ,mem_vec_7578 ,mem_vec_7579 ,mem_vec_7580 ,mem_vec_7581 ,mem_vec_7582 ,mem_vec_7583 ,mem_vec_7584 ,mem_vec_7585 ,mem_vec_7586 ,mem_vec_7587 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 34) (34 / 1)
for (x777 = x778, x777_p_0 = 0;
	x777 < x778 + 34;
	x777 += 1, x777_p_0 += 1){
	// y = 34, x = 1, h = 1, w = 1, c = 512, f = 256
	// T (c, 16) (512 / 32)
	for (c582 = c583, c582_p_0 = 0;
		c582 < c583 + 512;
		c582 += 32, c582_p_0 += 32){
		// y = 34, x = 1, h = 1, w = 1, c = 32, f = 256
		// T (f, 8) (256 / 32)
		for (f = f388, fp_0 = 0;
			f < f388 + 256;
			f += 32, fp_0 += 32){
				for (y = y388, yp_0 = 0;
					y < y388 + 10;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
					// T (x, 1) (1 / 1)
					for (x776 = x777, x776_p_1 = x777_p_0, x776_p_0 = 0;
						x776 < x777 + 1;
						x776 += 1, x776_p_1 += 1, x776_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
						// T (x, 1) (1 / 1)
						for (x = x776, xp_2 = x776_p_1, xp_1 = x776_p_0, xp_0 = 0;
							x < x776 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_7544 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_7545 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_7546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_7547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_7549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_7550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_7551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_7552 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_7553 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_7554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_7555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_7556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_7557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_7558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_7559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_7560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_7561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_7562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_7563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c582, cp_1 = c582_p_0, cp_0 = 0;
										c < c582 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7544);
										mem_vec_7544 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7545);
										mem_vec_7545 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7546);
										mem_vec_7546 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7547);
										mem_vec_7547 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7548);
										mem_vec_7548 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7549);
										mem_vec_7549 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7550);
										mem_vec_7550 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7551);
										mem_vec_7551 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7552);
										mem_vec_7552 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7553);
										mem_vec_7553 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7554);
										mem_vec_7554 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7555);
										mem_vec_7555 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7556);
										mem_vec_7556 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7557);
										mem_vec_7557 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7558);
										mem_vec_7558 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7559);
										mem_vec_7559 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7560);
										mem_vec_7560 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7561);
										mem_vec_7561 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7562);
										mem_vec_7562 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7563);
										mem_vec_7563 = vec_31;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7544);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7545);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7546);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7547);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7548);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7549);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7550);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7551);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7552);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7553);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7554);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7555);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7556);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7557);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7558);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7559);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7560);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7561);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7562);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7563);
						}
					}
				}
				for (y = y388 + 10, yp_0 = 0;
					y < y388 + 10 + 24;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
					// T (x, 1) (1 / 1)
					for (x776 = x777, x776_p_1 = x777_p_0, x776_p_0 = 0;
						x776 < x777 + 1;
						x776 += 1, x776_p_1 += 1, x776_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
						// T (x, 1) (1 / 1)
						for (x = x776, xp_2 = x776_p_1, xp_1 = x776_p_0, xp_0 = 0;
							x < x776 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_7564 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_7565 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_7566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_7567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_7569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_7570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_7571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_7572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_7573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_7574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_7575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_7576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_7577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_7578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_7579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_7580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_7581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_7582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_7583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_7584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_7585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_7586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_7587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c582, cp_1 = c582_p_0, cp_0 = 0;
										c < c582 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7564);
										mem_vec_7564 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7565);
										mem_vec_7565 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7566);
										mem_vec_7566 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7567);
										mem_vec_7567 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7568);
										mem_vec_7568 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7569);
										mem_vec_7569 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7570);
										mem_vec_7570 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7571);
										mem_vec_7571 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7572);
										mem_vec_7572 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7573);
										mem_vec_7573 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7574);
										mem_vec_7574 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7575);
										mem_vec_7575 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7576);
										mem_vec_7576 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7577);
										mem_vec_7577 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7578);
										mem_vec_7578 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7579);
										mem_vec_7579 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7580);
										mem_vec_7580 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7581);
										mem_vec_7581 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7582);
										mem_vec_7582 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7583);
										mem_vec_7583 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7584);
										mem_vec_7584 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7585);
										mem_vec_7585 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_7586);
										mem_vec_7586 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_7587);
										mem_vec_7587 = vec_37;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7564);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7565);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7566);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7567);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7568);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7569);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7570);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7571);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7572);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7573);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7574);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7575);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7576);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7577);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7578);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7579);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7580);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7581);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7582);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7583);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7584);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7585);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_7586);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_7587);
						}
					}
				}
		}
	}
}


}