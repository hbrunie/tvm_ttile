#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (17, x); T (2, c);
  T (1, y); T (8, f); T (2, c);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]]
*/
IND_TYPE c, cp_0, c456_p_0, c457_p_0, cp_1, c456_p_1, cp_2, c456, c457, f, fp_0, x, xp_0, y, yp_0, y342_p_0, yp_1, y342;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y343 = 0;
IND_TYPE x228 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c458 = 0;
IND_TYPE f228 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_4512 ,mem_vec_4513 ,mem_vec_4514 ,mem_vec_4515 ,mem_vec_4516 ,mem_vec_4517 ,mem_vec_4518 ,mem_vec_4519 ,mem_vec_4520 ,mem_vec_4521 ,mem_vec_4522 ,mem_vec_4523 ,mem_vec_4524 ,mem_vec_4525 ,mem_vec_4526 ,mem_vec_4527 ,mem_vec_4528 ,mem_vec_4529 ,mem_vec_4530 ,mem_vec_4531 ,mem_vec_4532 ,mem_vec_4533 ,mem_vec_4534 ,mem_vec_4535 ,mem_vec_4536 ,mem_vec_4537 ,mem_vec_4538 ,mem_vec_4539 ,mem_vec_4540 ,mem_vec_4541 ,mem_vec_4542 ,mem_vec_4543 ,mem_vec_4544 ,mem_vec_4545 ,mem_vec_4546 ,mem_vec_4547 ,mem_vec_4548 ,mem_vec_4549 ,mem_vec_4550 ,mem_vec_4551 ,mem_vec_4552 ,mem_vec_4553 ,mem_vec_4554 ,mem_vec_4555 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y342 = y343, y342_p_0 = 0;
		y342 < y343 + 5;
		y342 += 5, y342_p_0 += 5){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 2) (1024 / 512)
		for (c457 = c458, c457_p_0 = 0;
			c457 < c458 + 1024;
			c457 += 512, c457_p_0 += 512){
			// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 512
			// T (f, 8) (512 / 64)
			for (f = f228, fp_0 = 0;
				f < f228 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y342, yp_1 = y342_p_0, yp_0 = 0;
					y < y342 + 5;
					y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 2) (512 / 256)
					for (c456 = c457, c456_p_1 = c457_p_0, c456_p_0 = 0;
						c456 < c457 + 512;
						c456 += 256, c456_p_1 += 256, c456_p_0 += 256){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (x, 17) (17 / 1)
						for (x = x228, xp_0 = 0;
							x < x228 + 17;
							x += 1, xp_0 += 1){
									mem_vec_4512 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4513 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4514 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_4515 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_4516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_4519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_4520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4522 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_4523 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_4524 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_4525 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_4526 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_4527 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_4528 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_4529 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_4530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_4531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c456, cp_2 = c456_p_1, cp_1 = c456_p_0, cp_0 = 0;
										c < c456 + 256;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4512);
										mem_vec_4512 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4513);
										mem_vec_4513 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4514);
										mem_vec_4514 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4515);
										mem_vec_4515 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4516);
										mem_vec_4516 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4517);
										mem_vec_4517 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4518);
										mem_vec_4518 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4519);
										mem_vec_4519 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4520);
										mem_vec_4520 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4521);
										mem_vec_4521 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4522);
										mem_vec_4522 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4523);
										mem_vec_4523 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4524);
										mem_vec_4524 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4525);
										mem_vec_4525 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4526);
										mem_vec_4526 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4527);
										mem_vec_4527 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_4528);
										mem_vec_4528 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_4529);
										mem_vec_4529 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_4530);
										mem_vec_4530 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_4531);
										mem_vec_4531 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4512);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4513);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4514);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4515);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4516);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4517);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4518);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4519);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4520);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4521);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4522);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4523);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4524);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4525);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4526);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4527);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4528);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4529);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_4530);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_4531);
						}
					}
				}
			}
		}
	}
	for (y342 = y343 + 5, y342_p_0 = 0;
		y342 < y343 + 5 + 12;
		y342 += 6, y342_p_0 += 6){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 2) (1024 / 512)
		for (c457 = c458, c457_p_0 = 0;
			c457 < c458 + 1024;
			c457 += 512, c457_p_0 += 512){
			// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 512
			// T (f, 8) (512 / 64)
			for (f = f228, fp_0 = 0;
				f < f228 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y342, yp_1 = y342_p_0, yp_0 = 0;
					y < y342 + 6;
					y += 6, yp_1 += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 2) (512 / 256)
					for (c456 = c457, c456_p_1 = c457_p_0, c456_p_0 = 0;
						c456 < c457 + 512;
						c456 += 256, c456_p_1 += 256, c456_p_0 += 256){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (x, 17) (17 / 1)
						for (x = x228, xp_0 = 0;
							x < x228 + 17;
							x += 1, xp_0 += 1){
									mem_vec_4532 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4533 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4534 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_4535 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_4536 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4537 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_4539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_4540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4542 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_4543 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_4544 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_4545 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_4546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_4547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_4548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_4549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_4550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_4551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_4552 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_4553 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_4554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_4555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c456, cp_2 = c456_p_1, cp_1 = c456_p_0, cp_0 = 0;
										c < c456 + 256;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4532);
										mem_vec_4532 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4533);
										mem_vec_4533 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4534);
										mem_vec_4534 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4535);
										mem_vec_4535 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4536);
										mem_vec_4536 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4537);
										mem_vec_4537 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4538);
										mem_vec_4538 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4539);
										mem_vec_4539 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4540);
										mem_vec_4540 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4541);
										mem_vec_4541 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4542);
										mem_vec_4542 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4543);
										mem_vec_4543 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4544);
										mem_vec_4544 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4545);
										mem_vec_4545 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4546);
										mem_vec_4546 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4547);
										mem_vec_4547 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_4548);
										mem_vec_4548 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_4549);
										mem_vec_4549 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_4550);
										mem_vec_4550 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_4551);
										mem_vec_4551 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4552);
										mem_vec_4552 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4553);
										mem_vec_4553 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_4554);
										mem_vec_4554 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_4555);
										mem_vec_4555 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4532);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4533);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4534);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4535);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4536);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4537);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4538);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4539);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4540);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4541);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4542);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4543);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4544);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4545);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4546);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4547);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4548);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4549);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_4550);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_4551);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4552);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4553);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_4554);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_4555);
						}
					}
				}
			}
		}
	}


}