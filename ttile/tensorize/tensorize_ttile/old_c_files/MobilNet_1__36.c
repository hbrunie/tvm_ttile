#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (4, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 8), (Arg 11))]; T (4, c);
  T (14, x)]
*/
IND_TYPE c, cp_0, c288_p_0, cp_1, c288, h, hp_0, w, wp_0, x, xp_0, x384_p_0, x385_p_0, xp_1, x384_p_1, xp_2, x384, x385, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y192 = 0;
IND_TYPE x386 = 0;
IND_TYPE h172 = 0;
IND_TYPE w192 = 0;
IND_TYPE c289 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2452 ,mem_vec_2453 ,mem_vec_2454 ,mem_vec_2455 ,mem_vec_2456 ,mem_vec_2457 ,mem_vec_2458 ,mem_vec_2459 ,mem_vec_2460 ,mem_vec_2461 ,mem_vec_2462 ,mem_vec_2463 ,mem_vec_2464 ,mem_vec_2465 ,mem_vec_2466 ,mem_vec_2467 ,mem_vec_2468 ,mem_vec_2469 ,mem_vec_2470 ,mem_vec_2471 ,mem_vec_2472 ,mem_vec_2473 ,mem_vec_2474 ,mem_vec_2475 ,mem_vec_2476 ,mem_vec_2477 ,mem_vec_2478 ,mem_vec_2479 ,mem_vec_2480 ,mem_vec_2481 ,mem_vec_2482 ,mem_vec_2483 ,mem_vec_2484 ,mem_vec_2485 ,mem_vec_2486 ,mem_vec_2487 ,mem_vec_2488 ,mem_vec_2489 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 14) (112 / 8)
for (x385 = x386, x385_p_0 = 0;
	x385 < x386 + 112;
	x385 += 8, x385_p_0 += 8){
	// y = 112, x = 8, h = 3, w = 3, c = 32, f = 32
	// T (c, 4) (32 / 8)
	for (c288 = c289, c288_p_0 = 0;
		c288 < c289 + 32;
		c288 += 8, c288_p_0 += 8){
			for (y = y192, yp_0 = 0;
				y < y192 + 24;
				y += 8, yp_0 += 8){
				// y = ph_y, x = 8, h = 3, w = 3, c = 8, f = 32
				// T (x, 4) (8 / 2)
				for (x384 = x385, x384_p_1 = x385_p_0, x384_p_0 = 0;
					x384 < x385 + 8;
					x384 += 2, x384_p_1 += 2, x384_p_0 += 2){
					// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
					// T (h, 3) (3 / 1)
					for (h = h172, hp_0 = 0;
						h < h172 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 32
						// T (w, 3) (3 / 1)
						for (w = w192, wp_0 = 0;
							w < w192 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 1, c = 8, f = 32
							// T (x, 2) (2 / 1)
							for (x = x384, xp_2 = x384_p_1, xp_1 = x384_p_0, xp_0 = 0;
								x < x384 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2452 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2453 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_2466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_2467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c288, cp_1 = c288_p_0, cp_0 = 0;
											c < c288 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2452);
											mem_vec_2452 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2453);
											mem_vec_2453 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2454);
											mem_vec_2454 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2455);
											mem_vec_2455 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2456);
											mem_vec_2456 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2457);
											mem_vec_2457 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2458);
											mem_vec_2458 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2459);
											mem_vec_2459 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2460);
											mem_vec_2460 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2461);
											mem_vec_2461 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2462);
											mem_vec_2462 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2463);
											mem_vec_2463 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2464);
											mem_vec_2464 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2465);
											mem_vec_2465 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2466);
											mem_vec_2466 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2467);
											mem_vec_2467 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2452);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2453);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2454);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2455);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2456);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2457);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2458);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2459);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2460);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2461);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2462);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2463);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2464);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2465);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2466);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2467);
							}
						}
					}
				}
			}
			for (y = y192 + 24, yp_0 = 0;
				y < y192 + 24 + 88;
				y += 11, yp_0 += 11){
				// y = ph_y, x = 8, h = 3, w = 3, c = 8, f = 32
				// T (x, 4) (8 / 2)
				for (x384 = x385, x384_p_1 = x385_p_0, x384_p_0 = 0;
					x384 < x385 + 8;
					x384 += 2, x384_p_1 += 2, x384_p_0 += 2){
					// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
					// T (h, 3) (3 / 1)
					for (h = h172, hp_0 = 0;
						h < h172 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 32
						// T (w, 3) (3 / 1)
						for (w = w192, wp_0 = 0;
							w < w192 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 1, c = 8, f = 32
							// T (x, 2) (2 / 1)
							for (x = x384, xp_2 = x384_p_1, xp_1 = x384_p_0, xp_0 = 0;
								x < x384 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2468 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2469 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_2482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_2483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_2484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_2485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_2486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_2487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_2488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_2489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c288, cp_1 = c288_p_0, cp_0 = 0;
											c < c288 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2468);
											mem_vec_2468 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2469);
											mem_vec_2469 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2470);
											mem_vec_2470 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2471);
											mem_vec_2471 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2472);
											mem_vec_2472 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2473);
											mem_vec_2473 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2474);
											mem_vec_2474 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2475);
											mem_vec_2475 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2476);
											mem_vec_2476 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2477);
											mem_vec_2477 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2478);
											mem_vec_2478 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2479);
											mem_vec_2479 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2480);
											mem_vec_2480 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2481);
											mem_vec_2481 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2482);
											mem_vec_2482 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2483);
											mem_vec_2483 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2484);
											mem_vec_2484 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2485);
											mem_vec_2485 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2486);
											mem_vec_2486 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2487);
											mem_vec_2487 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2488);
											mem_vec_2488 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2489);
											mem_vec_2489 = vec_34;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2468);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2469);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2470);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2471);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2472);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2473);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2474);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2475);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2476);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2477);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2478);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2479);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2480);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2481);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2482);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2483);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2484);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2485);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2486);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2487);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2488);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2489);
							}
						}
					}
				}
			}
	}
}


}