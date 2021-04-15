#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (32, c);
  T (8, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]; T (8, c)]
*/
IND_TYPE c, cp_0, c1024_p_0, c1025_p_0, cp_1, c1024_p_1, cp_2, c1024, c1025, f, fp_0, x, xp_0, x768_p_0, xp_1, x768, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y512 = 0;
IND_TYPE x769 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1026 = 0;
IND_TYPE f512 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_8472 ,mem_vec_8473 ,mem_vec_8474 ,mem_vec_8475 ,mem_vec_8476 ,mem_vec_8477 ,mem_vec_8478 ,mem_vec_8479 ,mem_vec_8480 ,mem_vec_8481 ,mem_vec_8482 ,mem_vec_8483 ,mem_vec_8484 ,mem_vec_8485 ,mem_vec_8486 ,mem_vec_8487 ,mem_vec_8488 ,mem_vec_8489 ,mem_vec_8490 ,mem_vec_8491 ,mem_vec_8492 ,mem_vec_8493 ,mem_vec_8494 ,mem_vec_8495 ,mem_vec_8496 ,mem_vec_8497 ,mem_vec_8498 ,mem_vec_8499 ,mem_vec_8500 ,mem_vec_8501 ,mem_vec_8502 ,mem_vec_8503 ,mem_vec_8504 ,mem_vec_8505 ,mem_vec_8506 ,mem_vec_8507 ,mem_vec_8508 ,mem_vec_8509 ,mem_vec_8510 ,mem_vec_8511 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 8) (1024 / 128)
for (c1025 = c1026, c1025_p_0 = 0;
	c1025 < c1026 + 1024;
	c1025 += 128, c1025_p_0 += 128){
		for (y = y512, yp_0 = 0;
			y < y512 + 3;
			y += 3, yp_0 += 3){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (x, 17) (17 / 1)
			for (x768 = x769, x768_p_0 = 0;
				x768 < x769 + 17;
				x768 += 1, x768_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 512
				// T (f, 8) (512 / 64)
				for (f = f512, fp_0 = 0;
					f < f512 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (c, 32) (128 / 4)
					for (c1024 = c1025, c1024_p_1 = c1025_p_0, c1024_p_0 = 0;
						c1024 < c1025 + 128;
						c1024 += 4, c1024_p_1 += 4, c1024_p_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
						// T (x, 1) (1 / 1)
						for (x = x768, xp_1 = x768_p_0, xp_0 = 0;
							x < x768 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8472 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8473 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_8474 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_8475 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_8476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_8478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_8479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_8480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_8482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_8483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c1024, cp_2 = c1024_p_1, cp_1 = c1024_p_0, cp_0 = 0;
										c < c1024 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8472);
										mem_vec_8472 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8473);
										mem_vec_8473 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8474);
										mem_vec_8474 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8475);
										mem_vec_8475 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8476);
										mem_vec_8476 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8477);
										mem_vec_8477 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8478);
										mem_vec_8478 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8479);
										mem_vec_8479 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8480);
										mem_vec_8480 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8481);
										mem_vec_8481 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_8482);
										mem_vec_8482 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_8483);
										mem_vec_8483 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8472);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8473);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8474);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8475);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8476);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8477);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8478);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8479);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8480);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8481);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8482);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8483);
						}
					}
				}
			}
		}
		for (y = y512 + 3, yp_0 = 0;
			y < y512 + 3 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (x, 17) (17 / 1)
			for (x768 = x769, x768_p_0 = 0;
				x768 < x769 + 17;
				x768 += 1, x768_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 512
				// T (f, 8) (512 / 64)
				for (f = f512, fp_0 = 0;
					f < f512 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (c, 32) (128 / 4)
					for (c1024 = c1025, c1024_p_1 = c1025_p_0, c1024_p_0 = 0;
						c1024 < c1025 + 128;
						c1024 += 4, c1024_p_1 += 4, c1024_p_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
						// T (x, 1) (1 / 1)
						for (x = x768, xp_1 = x768_p_0, xp_0 = 0;
							x < x768 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8484 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8485 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_8486 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_8487 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_8488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_8490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_8491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_8492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_8494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_8495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_8496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_8497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_8498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_8499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_8500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_8501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_8502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_8503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_8504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_8505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_8506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_8507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_8508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_8509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_8510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_8511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c1024, cp_2 = c1024_p_1, cp_1 = c1024_p_0, cp_0 = 0;
										c < c1024 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8484);
										mem_vec_8484 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8485);
										mem_vec_8485 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8486);
										mem_vec_8486 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8487);
										mem_vec_8487 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8488);
										mem_vec_8488 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8489);
										mem_vec_8489 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8490);
										mem_vec_8490 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8491);
										mem_vec_8491 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8492);
										mem_vec_8492 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8493);
										mem_vec_8493 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_8494);
										mem_vec_8494 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_8495);
										mem_vec_8495 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8496);
										mem_vec_8496 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_8497);
										mem_vec_8497 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_8498);
										mem_vec_8498 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_8499);
										mem_vec_8499 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_8500);
										mem_vec_8500 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_8501);
										mem_vec_8501 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_8502);
										mem_vec_8502 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_8503);
										mem_vec_8503 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8504);
										mem_vec_8504 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8505);
										mem_vec_8505 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_8506);
										mem_vec_8506 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_8507);
										mem_vec_8507 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_8508);
										mem_vec_8508 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_8509);
										mem_vec_8509 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_8510);
										mem_vec_8510 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_8511);
										mem_vec_8511 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8484);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8485);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8486);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8487);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8488);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8489);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8490);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8491);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8492);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8493);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8494);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8495);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8496);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8497);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_8498);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_8499);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8500);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8501);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_8502);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_8503);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8504);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8505);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_8506);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_8507);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8508);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8509);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_8510);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_8511);
						}
					}
				}
			}
		}
}


}