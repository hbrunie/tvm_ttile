#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (1, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 4), (Arg 15))]; T (4, f);
  T (32, c); T (68, x)]
*/
IND_TYPE c, cp_0, c702_p_0, cp_1, c702, f, fp_0, x, xp_0, x936_p_0, x937_p_0, xp_1, x936_p_1, xp_2, x936, x937, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y468 = 0;
IND_TYPE x938 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c703 = 0;
IND_TYPE f468 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8456 ,mem_vec_8457 ,mem_vec_8458 ,mem_vec_8459 ,mem_vec_8460 ,mem_vec_8461 ,mem_vec_8462 ,mem_vec_8463 ,mem_vec_8464 ,mem_vec_8465 ,mem_vec_8466 ,mem_vec_8467 ,mem_vec_8468 ,mem_vec_8469 ,mem_vec_8470 ,mem_vec_8471 ,mem_vec_8472 ,mem_vec_8473 ,mem_vec_8474 ,mem_vec_8475 ,mem_vec_8476 ,mem_vec_8477 ,mem_vec_8478 ,mem_vec_8479 ,mem_vec_8480 ,mem_vec_8481 ,mem_vec_8482 ,mem_vec_8483 ,mem_vec_8484 ,mem_vec_8485 ,mem_vec_8486 ,mem_vec_8487 ,mem_vec_8488 ,mem_vec_8489 ,mem_vec_8490 ,mem_vec_8491 ,mem_vec_8492 ,mem_vec_8493 ,mem_vec_8494 ,mem_vec_8495 ,mem_vec_8496 ,mem_vec_8497 ,mem_vec_8498 ,mem_vec_8499 ,mem_vec_8500 ,mem_vec_8501 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 68) (68 / 1)
for (x937 = x938, x937_p_0 = 0;
	x937 < x938 + 68;
	x937 += 1, x937_p_0 += 1){
	// y = 68, x = 1, h = 1, w = 1, c = 256, f = 128
	// T (c, 32) (256 / 8)
	for (c702 = c703, c702_p_0 = 0;
		c702 < c703 + 256;
		c702 += 8, c702_p_0 += 8){
		// y = 68, x = 1, h = 1, w = 1, c = 8, f = 128
		// T (f, 4) (128 / 32)
		for (f = f468, fp_0 = 0;
			f < f468 + 128;
			f += 32, fp_0 += 32){
				for (y = y468, yp_0 = 0;
					y < y468 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
					// T (x, 1) (1 / 1)
					for (x936 = x937, x936_p_1 = x937_p_0, x936_p_0 = 0;
						x936 < x937 + 1;
						x936 += 1, x936_p_1 += 1, x936_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
						// T (x, 1) (1 / 1)
						for (x = x936, xp_2 = x936_p_1, xp_1 = x936_p_0, xp_0 = 0;
							x < x936 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8456 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8457 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_8458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_8460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_8462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_8463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_8464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_8465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_8466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_8467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_8468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_8469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_8470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_8471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c702, cp_1 = c702_p_0, cp_0 = 0;
										c < c702 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8456);
										mem_vec_8456 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8457);
										mem_vec_8457 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8458);
										mem_vec_8458 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8459);
										mem_vec_8459 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8460);
										mem_vec_8460 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8461);
										mem_vec_8461 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8462);
										mem_vec_8462 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8463);
										mem_vec_8463 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8464);
										mem_vec_8464 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8465);
										mem_vec_8465 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8466);
										mem_vec_8466 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8467);
										mem_vec_8467 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8468);
										mem_vec_8468 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8469);
										mem_vec_8469 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8470);
										mem_vec_8470 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8471);
										mem_vec_8471 = vec_25;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8456);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8457);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8458);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8459);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8460);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8461);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8462);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8463);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8464);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8465);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8466);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8467);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8468);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8469);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8470);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8471);
						}
					}
				}
				for (y = y468 + 8, yp_0 = 0;
					y < y468 + 8 + 60;
					y += 15, yp_0 += 15){
					// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
					// T (x, 1) (1 / 1)
					for (x936 = x937, x936_p_1 = x937_p_0, x936_p_0 = 0;
						x936 < x937 + 1;
						x936 += 1, x936_p_1 += 1, x936_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
						// T (x, 1) (1 / 1)
						for (x = x936, xp_2 = x936_p_1, xp_1 = x936_p_0, xp_0 = 0;
							x < x936 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8472 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8473 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_8474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_8476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_8478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_8479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_8480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_8481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_8482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_8483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_8484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_8485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_8486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_8487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_8488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_8489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_8490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_8491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_8492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_8493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_8494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_8495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_8496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_8497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_8498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_8499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									mem_vec_8500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
									mem_vec_8501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c702, cp_1 = c702_p_0, cp_0 = 0;
										c < c702 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8472);
										mem_vec_8472 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8473);
										mem_vec_8473 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8474);
										mem_vec_8474 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8475);
										mem_vec_8475 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8476);
										mem_vec_8476 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8477);
										mem_vec_8477 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8478);
										mem_vec_8478 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8479);
										mem_vec_8479 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8480);
										mem_vec_8480 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8481);
										mem_vec_8481 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8482);
										mem_vec_8482 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8483);
										mem_vec_8483 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8484);
										mem_vec_8484 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8485);
										mem_vec_8485 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8486);
										mem_vec_8486 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8487);
										mem_vec_8487 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8488);
										mem_vec_8488 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8489);
										mem_vec_8489 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8490);
										mem_vec_8490 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8491);
										mem_vec_8491 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8492);
										mem_vec_8492 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8493);
										mem_vec_8493 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8494);
										mem_vec_8494 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8495);
										mem_vec_8495 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8496);
										mem_vec_8496 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8497);
										mem_vec_8497 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_8498);
										mem_vec_8498 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_8499);
										mem_vec_8499 = vec_43;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
										vec_45 = _mm512_set1_ps(scal_14);


										vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_8500);
										mem_vec_8500 = vec_44;



										vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_8501);
										mem_vec_8501 = vec_46;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8472);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8473);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8474);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8475);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8476);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8477);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8478);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8479);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8480);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8481);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8482);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8483);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8484);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8485);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8486);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8487);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8488);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8489);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8490);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8491);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8492);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8493);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8494);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8495);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_8496);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_8497);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_8498);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_8499);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_8500);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_8501);
						}
					}
				}
		}
	}
}


}