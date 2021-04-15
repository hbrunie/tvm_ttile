#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (8, f); T (17, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (256, c)]
*/
IND_TYPE c, cp_0, c1592_p_0, c1593_p_0, cp_1, c1592_p_1, cp_2, c1592, c1593, f, fp_0, x, xp_0, x1194_p_0, xp_1, x1194, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y796 = 0;
IND_TYPE x1195 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1594 = 0;
IND_TYPE f796 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_14520 ,mem_vec_14521 ,mem_vec_14522 ,mem_vec_14523 ,mem_vec_14524 ,mem_vec_14525 ,mem_vec_14526 ,mem_vec_14527 ,mem_vec_14528 ,mem_vec_14529 ,mem_vec_14530 ,mem_vec_14531 ,mem_vec_14532 ,mem_vec_14533 ,mem_vec_14534 ,mem_vec_14535 ,mem_vec_14536 ,mem_vec_14537 ,mem_vec_14538 ,mem_vec_14539 ,mem_vec_14540 ,mem_vec_14541 ,mem_vec_14542 ,mem_vec_14543 ,mem_vec_14544 ,mem_vec_14545 ,mem_vec_14546 ,mem_vec_14547 ,mem_vec_14548 ,mem_vec_14549 ,mem_vec_14550 ,mem_vec_14551 ,mem_vec_14552 ,mem_vec_14553 ,mem_vec_14554 ,mem_vec_14555 ,mem_vec_14556 ,mem_vec_14557 ,mem_vec_14558 ,mem_vec_14559 ,mem_vec_14560 ,mem_vec_14561 ,mem_vec_14562 ,mem_vec_14563 ,mem_vec_14564 ,mem_vec_14565 ,mem_vec_14566 ,mem_vec_14567 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 256) (1024 / 4)
for (c1593 = c1594, c1593_p_0 = 0;
	c1593 < c1594 + 1024;
	c1593 += 4, c1593_p_0 += 4){
		for (y = y796, yp_0 = 0;
			y < y796 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 512
			// T (x, 17) (17 / 1)
			for (x1194 = x1195, x1194_p_0 = 0;
				x1194 < x1195 + 17;
				x1194 += 1, x1194_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 512
				// T (f, 8) (512 / 64)
				for (f = f796, fp_0 = 0;
					f < f796 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
					// T (c, 2) (4 / 2)
					for (c1592 = c1593, c1592_p_1 = c1593_p_0, c1592_p_0 = 0;
						c1592 < c1593 + 4;
						c1592 += 2, c1592_p_1 += 2, c1592_p_0 += 2){
						// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1194, xp_1 = x1194_p_0, xp_0 = 0;
							x < x1194 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14520 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14521 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14522 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_14523 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_14524 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14525 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14526 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_14527 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_14528 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14529 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_14531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_14532 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14533 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14534 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_14535 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_14536 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14537 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_14539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1592, cp_2 = c1592_p_1, cp_1 = c1592_p_0, cp_0 = 0;
										c < c1592 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14520);
										mem_vec_14520 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14521);
										mem_vec_14521 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14522);
										mem_vec_14522 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14523);
										mem_vec_14523 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14524);
										mem_vec_14524 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14525);
										mem_vec_14525 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14526);
										mem_vec_14526 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14527);
										mem_vec_14527 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14528);
										mem_vec_14528 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14529);
										mem_vec_14529 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14530);
										mem_vec_14530 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14531);
										mem_vec_14531 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14532);
										mem_vec_14532 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14533);
										mem_vec_14533 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14534);
										mem_vec_14534 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14535);
										mem_vec_14535 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14536);
										mem_vec_14536 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14537);
										mem_vec_14537 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14538);
										mem_vec_14538 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14539);
										mem_vec_14539 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14520);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14521);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14522);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14523);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14524);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14525);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14526);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14527);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14528);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14529);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14530);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14531);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14532);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14533);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14534);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14535);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14536);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14537);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14538);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14539);
						}
					}
				}
			}
		}
		for (y = y796 + 10, yp_0 = 0;
			y < y796 + 10 + 7;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 512
			// T (x, 17) (17 / 1)
			for (x1194 = x1195, x1194_p_0 = 0;
				x1194 < x1195 + 17;
				x1194 += 1, x1194_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 512
				// T (f, 8) (512 / 64)
				for (f = f796, fp_0 = 0;
					f < f796 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
					// T (c, 2) (4 / 2)
					for (c1592 = c1593, c1592_p_1 = c1593_p_0, c1592_p_0 = 0;
						c1592 < c1593 + 4;
						c1592 += 2, c1592_p_1 += 2, c1592_p_0 += 2){
						// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1194, xp_1 = x1194_p_0, xp_0 = 0;
							x < x1194 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14540 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14541 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14542 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_14543 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_14544 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14545 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_14547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_14548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_14551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_14552 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14553 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_14555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_14556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_14559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_14560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_14563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_14564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_14565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_14566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_14567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1592, cp_2 = c1592_p_1, cp_1 = c1592_p_0, cp_0 = 0;
										c < c1592 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14540);
										mem_vec_14540 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14541);
										mem_vec_14541 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14542);
										mem_vec_14542 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14543);
										mem_vec_14543 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14544);
										mem_vec_14544 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14545);
										mem_vec_14545 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14546);
										mem_vec_14546 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14547);
										mem_vec_14547 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14548);
										mem_vec_14548 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14549);
										mem_vec_14549 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14550);
										mem_vec_14550 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14551);
										mem_vec_14551 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14552);
										mem_vec_14552 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14553);
										mem_vec_14553 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14554);
										mem_vec_14554 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14555);
										mem_vec_14555 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14556);
										mem_vec_14556 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14557);
										mem_vec_14557 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14558);
										mem_vec_14558 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14559);
										mem_vec_14559 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14560);
										mem_vec_14560 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14561);
										mem_vec_14561 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14562);
										mem_vec_14562 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14563);
										mem_vec_14563 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_14564);
										mem_vec_14564 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_14565);
										mem_vec_14565 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_14566);
										mem_vec_14566 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_14567);
										mem_vec_14567 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14540);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14541);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14542);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14543);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14544);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14545);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14546);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14547);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14548);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14549);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14550);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14551);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14552);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14553);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14554);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14555);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14556);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14557);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14558);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14559);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14560);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14561);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_14562);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_14563);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14564);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14565);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_14566);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_14567);
						}
					}
				}
			}
		}
}


}