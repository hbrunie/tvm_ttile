
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (3, c); Hoist_vars [c]; T (28, x); T (1, c);
  T (7, w); T (7, h); T (4, x);
  Lambda_apply y [((Iter 3), (Arg 10)); ((Iter 2), (Arg 13))]; T (2, f);
  T (2, y)]
*/
IND_TYPE c, cp_0, c207_p_0, cp_1, c207, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x202_p_0, xp_1, x202, y, yp_0, y207_p_0, yp_1, y207;
IND_TYPE y208 = 0;
IND_TYPE x203 = 0;
IND_TYPE h138 = 0;
IND_TYPE w138 = 0;
IND_TYPE c208 = 0;
IND_TYPE f133 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2412 ,mem_vec_2413 ,mem_vec_2414 ,mem_vec_2415 ,mem_vec_2416 ,mem_vec_2417 ,mem_vec_2418 ,mem_vec_2419 ,mem_vec_2420 ,mem_vec_2421 ,mem_vec_2422 ,mem_vec_2423 ,mem_vec_2424 ,mem_vec_2425 ,mem_vec_2426 ,mem_vec_2427 ,mem_vec_2428 ,mem_vec_2429 ,mem_vec_2430 ,mem_vec_2431 ,mem_vec_2432 ,mem_vec_2433 ,mem_vec_2434 ,mem_vec_2435 ,mem_vec_2436 ,mem_vec_2437 ,mem_vec_2438 ,mem_vec_2439 ,mem_vec_2440 ,mem_vec_2441 ,mem_vec_2442 ,mem_vec_2443 ,mem_vec_2444 ,mem_vec_2445 ,mem_vec_2446 ,mem_vec_2447 ,mem_vec_2448 ,mem_vec_2449 ,mem_vec_2450 ,mem_vec_2451 ,mem_vec_2452 ,mem_vec_2453 ,mem_vec_2454 ,mem_vec_2455 ,mem_vec_2456 ,mem_vec_2457 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (y, 2) (112 / 56)
y207 = 0;
y207_p_0 = 0;
	for (f = f133, fp_0 = 0;f < f133 + 64;f += 32, fp_0 += 32){
			for (y = y207, yp_1 = y207_p_0, yp_0 = 0;y < y207 + 30;y += 10, yp_1 += 10, yp_0 += 10){
				// y = ph_y, x = 112, h = 7, w = 7, c = 3, f = 32
				// T (x, 4) (112 / 28)
				for (x202 = x203, x202_p_0 = 0;x202 < x203 + 112;x202 += 28, x202_p_0 += 28){
					// y = ph_y, x = 28, h = 7, w = 7, c = 3, f = 32
					// T (h, 7) (7 / 1)
					for (h = h138, hp_0 = 0;h < h138 + 7;h += 1, hp_0 += 1){
						// y = ph_y, x = 28, h = 1, w = 7, c = 3, f = 32
						// T (w, 7) (7 / 1)
						for (w = w138, wp_0 = 0;w < w138 + 7;w += 1, wp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 1, c = 3, f = 32
							// T (c, 1) (3 / 3)
							for (c207 = c208, c207_p_0 = 0;c207 < c208 + 3;c207 += 3, c207_p_0 += 3){
								// y = ph_y, x = 28, h = 1, w = 1, c = 3, f = 32
								// T (x, 28) (28 / 1)
								for (x = x202, xp_1 = x202_p_0, xp_0 = 0;x < x202 + 28;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2412 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_2413 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_2414 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_2415 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_2416 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_2417 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_2418 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_2419 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_2420 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_2421 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_2422 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_2423 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_2424 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_2425 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_2426 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_2427 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_2428 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_2429 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_2430 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_2431 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
											// T (c, 3) (3 / 1)
											for (c = c207, cp_1 = c207_p_0, cp_0 = 0;c < c207 + 3;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2412);
												mem_vec_2412 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2413);
												mem_vec_2413 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2414);
												mem_vec_2414 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2415);
												mem_vec_2415 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2416);
												mem_vec_2416 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2417);
												mem_vec_2417 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2418);
												mem_vec_2418 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2419);
												mem_vec_2419 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2420);
												mem_vec_2420 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2421);
												mem_vec_2421 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2422);
												mem_vec_2422 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2423);
												mem_vec_2423 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2424);
												mem_vec_2424 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2425);
												mem_vec_2425 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2426);
												mem_vec_2426 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2427);
												mem_vec_2427 = vec_25;
												scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2428);
												mem_vec_2428 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2429);
												mem_vec_2429 = vec_28;
												scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2430);
												mem_vec_2430 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2431);
												mem_vec_2431 = vec_31;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2412);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2413);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2414);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2415);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2416);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2417);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2418);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2419);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2420);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2421);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2422);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_2423);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2424);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_2425);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2426);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_2427);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_2428);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_2429);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_2430);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_2431);
								}
							}
						}
					}
				}
			}
			for (y = y207 + 30, yp_1 = y207_p_0, yp_0 = 0;y < y207 + 30 + 26;y += 13, yp_1 += 13, yp_0 += 13){
				// y = ph_y, x = 112, h = 7, w = 7, c = 3, f = 32
				// T (x, 4) (112 / 28)
				for (x202 = x203, x202_p_0 = 0;x202 < x203 + 112;x202 += 28, x202_p_0 += 28){
					// y = ph_y, x = 28, h = 7, w = 7, c = 3, f = 32
					// T (h, 7) (7 / 1)
					for (h = h138, hp_0 = 0;h < h138 + 7;h += 1, hp_0 += 1){
						// y = ph_y, x = 28, h = 1, w = 7, c = 3, f = 32
						// T (w, 7) (7 / 1)
						for (w = w138, wp_0 = 0;w < w138 + 7;w += 1, wp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 1, c = 3, f = 32
							// T (c, 1) (3 / 3)
							for (c207 = c208, c207_p_0 = 0;c207 < c208 + 3;c207 += 3, c207_p_0 += 3){
								// y = ph_y, x = 28, h = 1, w = 1, c = 3, f = 32
								// T (x, 28) (28 / 1)
								for (x = x202, xp_1 = x202_p_0, xp_0 = 0;x < x202 + 28;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2432 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_2433 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_2434 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_2435 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_2436 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_2437 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_2438 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_2439 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_2440 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_2441 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_2442 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_2443 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_2444 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_2445 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_2446 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_2447 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_2448 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_2449 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_2450 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_2451 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_2452 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_2453 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											mem_vec_2454 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
											mem_vec_2455 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
											mem_vec_2456 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
											mem_vec_2457 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
											// T (c, 3) (3 / 1)
											for (c = c207, cp_1 = c207_p_0, cp_0 = 0;c < c207 + 3;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2432);
												mem_vec_2432 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2433);
												mem_vec_2433 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2434);
												mem_vec_2434 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2435);
												mem_vec_2435 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2436);
												mem_vec_2436 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2437);
												mem_vec_2437 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2438);
												mem_vec_2438 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2439);
												mem_vec_2439 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2440);
												mem_vec_2440 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2441);
												mem_vec_2441 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2442);
												mem_vec_2442 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2443);
												mem_vec_2443 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2444);
												mem_vec_2444 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2445);
												mem_vec_2445 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2446);
												mem_vec_2446 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2447);
												mem_vec_2447 = vec_25;
												scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2448);
												mem_vec_2448 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2449);
												mem_vec_2449 = vec_28;
												scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2450);
												mem_vec_2450 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2451);
												mem_vec_2451 = vec_31;
												scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2452);
												mem_vec_2452 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2453);
												mem_vec_2453 = vec_34;
												scal_11 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);
												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2454);
												mem_vec_2454 = vec_35;
												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2455);
												mem_vec_2455 = vec_37;
												scal_12 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 12) + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_2456);
												mem_vec_2456 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_2457);
												mem_vec_2457 = vec_40;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2432);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2433);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2434);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2435);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2436);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2437);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2438);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2439);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2440);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2441);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2442);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_2443);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2444);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_2445);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2446);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_2447);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_2448);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_2449);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_2450);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_2451);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_2452);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_2453);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_2454);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_2455);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_2456);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_2457);
								}
							}
						}
					}
				}
			}
	}
}
