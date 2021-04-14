
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (28, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 3), (Arg 12))]; T (2, f);
  T (1, c); T (1, x)]
*/
IND_TYPE c, cp_0, c458_p_0, cp_1, c458, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x466_p_0, x467_p_0, xp_1, x466_p_1, xp_2, x466, x467, y, yp_0;
IND_TYPE y264 = 0;
IND_TYPE x468 = 0;
IND_TYPE h228 = 0;
IND_TYPE w240 = 0;
IND_TYPE c459 = 0;
IND_TYPE f202 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3416 ,mem_vec_3417 ,mem_vec_3418 ,mem_vec_3419 ,mem_vec_3420 ,mem_vec_3421 ,mem_vec_3422 ,mem_vec_3423 ,mem_vec_3424 ,mem_vec_3425 ,mem_vec_3426 ,mem_vec_3427 ,mem_vec_3428 ,mem_vec_3429 ,mem_vec_3430 ,mem_vec_3431 ,mem_vec_3432 ,mem_vec_3433 ,mem_vec_3434 ,mem_vec_3435 ,mem_vec_3436 ,mem_vec_3437 ,mem_vec_3438 ,mem_vec_3439 ,mem_vec_3440 ,mem_vec_3441 ,mem_vec_3442 ,mem_vec_3443 ,mem_vec_3444 ,mem_vec_3445 ,mem_vec_3446 ,mem_vec_3447 ,mem_vec_3448 ,mem_vec_3449 ,mem_vec_3450 ,mem_vec_3451 ,mem_vec_3452 ,mem_vec_3453 ,mem_vec_3454 ,mem_vec_3455 ,mem_vec_3456 ,mem_vec_3457 ,mem_vec_3458 ,mem_vec_3459 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 1) (56 / 56)
x467 = 0;
x467_p_0 = 0;
c458 = 0;
c458_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x466 = 0;
x466_p_1 = 0;
						for (h = h228, hp_0 = 0;h < h228 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w240, wp_0 = 0;w < w240 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 32
								// T (x, 2) (2 / 1)
								for (x = x466, xp_2 = x466_p_1, xp_1 = x466_p_0, xp_0 = 0;x < x466 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3416 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_3417 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_3418 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_3419 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_3420 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_3421 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_3422 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_3423 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_3424 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_3425 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_3426 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_3427 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_3428 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_3429 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_3430 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_3431 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_3432 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_3433 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_3434 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_3435 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c458, cp_1 = c458_p_0, cp_0 = 0;c < c458 + 64;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3416);
												mem_vec_3416 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3417);
												mem_vec_3417 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3418);
												mem_vec_3418 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3419);
												mem_vec_3419 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3420);
												mem_vec_3420 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3421);
												mem_vec_3421 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3422);
												mem_vec_3422 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3423);
												mem_vec_3423 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3424);
												mem_vec_3424 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3425);
												mem_vec_3425 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3426);
												mem_vec_3426 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3427);
												mem_vec_3427 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3428);
												mem_vec_3428 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3429);
												mem_vec_3429 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3430);
												mem_vec_3430 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3431);
												mem_vec_3431 = vec_25;
												scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3432);
												mem_vec_3432 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3433);
												mem_vec_3433 = vec_28;
												scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3434);
												mem_vec_3434 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3435);
												mem_vec_3435 = vec_31;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3416);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3417);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3418);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3419);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3420);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3421);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3422);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3423);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3424);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3425);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3426);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3427);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_3428);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_3429);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_3430);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_3431);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_3432);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_3433);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_3434);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_3435);
								}
							}
						}
}
