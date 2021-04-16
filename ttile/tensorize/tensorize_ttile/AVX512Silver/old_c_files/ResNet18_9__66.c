#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (14, x); T (8, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 1), (Arg 8))]; T (8, f)]
*/
IND_TYPE c, cp_0, c483_p_0, cp_1, c483, f, fp_0, f483_p_0, fp_1, f483, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y322 = 0;
IND_TYPE x322 = 0;
IND_TYPE h = 0;
IND_TYPE w239 = 0;
IND_TYPE c484 = 0;
IND_TYPE f484 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2441 ,mem_vec_2442 ,mem_vec_2443 ,mem_vec_2444 ,mem_vec_2445 ,mem_vec_2446 ,mem_vec_2447 ,mem_vec_2448 ,mem_vec_2449 ,mem_vec_2450 ,mem_vec_2451 ,mem_vec_2452 ,mem_vec_2453 ,mem_vec_2454 ,mem_vec_2455 ,mem_vec_2456 ,mem_vec_2457 ,mem_vec_2458 ,mem_vec_2459 ,mem_vec_2460 ,mem_vec_2461 ,mem_vec_2462 ,mem_vec_2463 ,mem_vec_2464 ,mem_vec_2465 ,mem_vec_2466 ,mem_vec_2467 ,mem_vec_2468 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 8) (256 / 32)
for (f483 = f484, f483_p_0 = 0;
	f483 < f484 + 256;
	f483 += 32, f483_p_0 += 32){
		for (y = y322, yp_0 = 0;
			y < y322 + 6;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 32
			// T (f, 1) (32 / 32)
			for (f = f483, fp_1 = f483_p_0, fp_0 = 0;
				f < f483 + 32;
				f += 32, fp_1 += 32, fp_0 += 32){
				// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 32
				// T (c, 8) (256 / 32)
				for (c483 = c484, c483_p_0 = 0;
					c483 < c484 + 256;
					c483 += 32, c483_p_0 += 32){
					// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
					// T (x, 14) (14 / 1)
					for (x = x322, xp_0 = 0;
						x < x322 + 14;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w239, wp_0 = 0;
							w < w239 + 3;
							w += 1, wp_0 += 1){
									mem_vec_2441 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2442 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_2445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_2446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_2447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_2448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_2449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_2450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_2451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_2452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c483, cp_1 = c483_p_0, cp_0 = 0;
										c < c483 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2441);
										mem_vec_2441 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2442);
										mem_vec_2442 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2443);
										mem_vec_2443 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2444);
										mem_vec_2444 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2445);
										mem_vec_2445 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2446);
										mem_vec_2446 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2447);
										mem_vec_2447 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2448);
										mem_vec_2448 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2449);
										mem_vec_2449 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2450);
										mem_vec_2450 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2451);
										mem_vec_2451 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2452);
										mem_vec_2452 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_21 = _mm512_set1_ps(scal_6);
										vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_2441);
										mem_vec_2441 = vec_20;

										vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_2442);
										mem_vec_2442 = vec_23;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_26 = _mm512_set1_ps(scal_7);


										vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_2443);
										mem_vec_2443 = vec_25;



										vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_2444);
										mem_vec_2444 = vec_27;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_8);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_2445);
										mem_vec_2445 = vec_28;



										vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_2446);
										mem_vec_2446 = vec_30;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_32 = _mm512_set1_ps(scal_9);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_2447);
										mem_vec_2447 = vec_31;



										vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_2448);
										mem_vec_2448 = vec_33;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_2449);
										mem_vec_2449 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_2450);
										mem_vec_2450 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_2451);
										mem_vec_2451 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_2452);
										mem_vec_2452 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_41 = _mm512_set1_ps(scal_12);
										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_2441);
										mem_vec_2441 = vec_40;

										vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_2442);
										mem_vec_2442 = vec_43;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_46 = _mm512_set1_ps(scal_13);


										vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_2443);
										mem_vec_2443 = vec_45;



										vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_2444);
										mem_vec_2444 = vec_47;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_49 = _mm512_set1_ps(scal_14);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_2445);
										mem_vec_2445 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_2446);
										mem_vec_2446 = vec_50;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_52 = _mm512_set1_ps(scal_15);


										vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_2447);
										mem_vec_2447 = vec_51;



										vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_2448);
										mem_vec_2448 = vec_53;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_55 = _mm512_set1_ps(scal_16);


										vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_2449);
										mem_vec_2449 = vec_54;



										vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_2450);
										mem_vec_2450 = vec_56;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_58 = _mm512_set1_ps(scal_17);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_2451);
										mem_vec_2451 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_2452);
										mem_vec_2452 = vec_59;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2441);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2442);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2443);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2444);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2445);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2446);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2447);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2448);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2449);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2450);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2451);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2452);
						}
					}
				}
			}
		}
		for (y = y322 + 6, yp_0 = 0;
			y < y322 + 6 + 8;
			y += 8, yp_0 += 8){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 32
			// T (f, 1) (32 / 32)
			for (f = f483, fp_1 = f483_p_0, fp_0 = 0;
				f < f483 + 32;
				f += 32, fp_1 += 32, fp_0 += 32){
				// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 32
				// T (c, 8) (256 / 32)
				for (c483 = c484, c483_p_0 = 0;
					c483 < c484 + 256;
					c483 += 32, c483_p_0 += 32){
					// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
					// T (x, 14) (14 / 1)
					for (x = x322, xp_0 = 0;
						x < x322 + 14;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w239, wp_0 = 0;
							w < w239 + 3;
							w += 1, wp_0 += 1){
									mem_vec_2453 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2454 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_2457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_2458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_2459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_2460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_2461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_2462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_2463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_2464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_2465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_2466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_2467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_2468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c483, cp_1 = c483_p_0, cp_0 = 0;
										c < c483 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2453);
										mem_vec_2453 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2454);
										mem_vec_2454 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2455);
										mem_vec_2455 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2456);
										mem_vec_2456 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2457);
										mem_vec_2457 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2458);
										mem_vec_2458 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2459);
										mem_vec_2459 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2460);
										mem_vec_2460 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2461);
										mem_vec_2461 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2462);
										mem_vec_2462 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2463);
										mem_vec_2463 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2464);
										mem_vec_2464 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2465);
										mem_vec_2465 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2466);
										mem_vec_2466 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2467);
										mem_vec_2467 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2468);
										mem_vec_2468 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_27 = _mm512_set1_ps(scal_8);
										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_2453);
										mem_vec_2453 = vec_26;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_2454);
										mem_vec_2454 = vec_29;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_32 = _mm512_set1_ps(scal_9);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_2455);
										mem_vec_2455 = vec_31;



										vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_2456);
										mem_vec_2456 = vec_33;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_2457);
										mem_vec_2457 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_2458);
										mem_vec_2458 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_2459);
										mem_vec_2459 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_2460);
										mem_vec_2460 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_2461);
										mem_vec_2461 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_2462);
										mem_vec_2462 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_2463);
										mem_vec_2463 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_2464);
										mem_vec_2464 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_2465);
										mem_vec_2465 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_2466);
										mem_vec_2466 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_2467);
										mem_vec_2467 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_2468);
										mem_vec_2468 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_53 = _mm512_set1_ps(scal_16);
										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_2453);
										mem_vec_2453 = vec_52;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_2454);
										mem_vec_2454 = vec_55;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_58 = _mm512_set1_ps(scal_17);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_2455);
										mem_vec_2455 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_2456);
										mem_vec_2456 = vec_59;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_61 = _mm512_set1_ps(scal_18);


										vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_2457);
										mem_vec_2457 = vec_60;



										vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_2458);
										mem_vec_2458 = vec_62;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_64 = _mm512_set1_ps(scal_19);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_2459);
										mem_vec_2459 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_2460);
										mem_vec_2460 = vec_65;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_67 = _mm512_set1_ps(scal_20);


										vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_2461);
										mem_vec_2461 = vec_66;



										vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_2462);
										mem_vec_2462 = vec_68;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_70 = _mm512_set1_ps(scal_21);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_2463);
										mem_vec_2463 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_2464);
										mem_vec_2464 = vec_71;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_73 = _mm512_set1_ps(scal_22);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_2465);
										mem_vec_2465 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_2466);
										mem_vec_2466 = vec_74;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_2467);
										mem_vec_2467 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_2468);
										mem_vec_2468 = vec_77;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2453);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2454);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2455);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2456);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2457);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2458);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2459);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2460);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2461);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2462);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2463);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2464);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2465);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2466);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2467);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2468);
						}
					}
				}
			}
		}
}


}