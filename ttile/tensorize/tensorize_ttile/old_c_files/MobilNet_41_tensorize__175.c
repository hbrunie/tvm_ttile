
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (28, x); T (3, w);
  T (3, h); T (2, f); T (4, c); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 10))]; T (2, f)]
*/
IND_TYPE c, cp_0, c444_p_0, cp_1, c444, f, fp_0, f444_p_0, fp_1, f444, h, hp_0, w, wp_0, x, xp_0, x444_p_0, xp_1, x444, y, yp_0;
IND_TYPE y296 = 0;
IND_TYPE x445 = 0;
IND_TYPE h228 = 0;
IND_TYPE w266 = 0;
IND_TYPE c445 = 0;
IND_TYPE f445 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3440 ,mem_vec_3441 ,mem_vec_3442 ,mem_vec_3443 ,mem_vec_3444 ,mem_vec_3445 ,mem_vec_3446 ,mem_vec_3447 ,mem_vec_3448 ,mem_vec_3449 ,mem_vec_3450 ,mem_vec_3451 ,mem_vec_3452 ,mem_vec_3453 ,mem_vec_3454 ,mem_vec_3455 ,mem_vec_3456 ,mem_vec_3457 ,mem_vec_3458 ,mem_vec_3459 ,mem_vec_3460 ,mem_vec_3461 ,mem_vec_3462 ,mem_vec_3463 ,mem_vec_3464 ,mem_vec_3465 ,mem_vec_3466 ,mem_vec_3467 ,mem_vec_3468 ,mem_vec_3469 ,mem_vec_3470 ,mem_vec_3471 ,mem_vec_3472 ,mem_vec_3473 ,mem_vec_3474 ,mem_vec_3475 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
f444 = 0;
f444_p_0 = 0;
y = 0;
yp_0 = 0;
x444 = 0;
x444_p_0 = 0;
c444 = 0;
c444_p_0 = 0;
f = 0;
fp_1 = 0;
						for (h = h228, hp_0 = 0;h < h228 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w266, wp_0 = 0;w < w266 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 28, h = 1, w = 1, c = 32, f = 32
								// T (x, 28) (28 / 1)
								for (x = x444, xp_1 = x444_p_0, xp_0 = 0;x < x444 + 28;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3440 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_3441 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_3442 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_3443 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_3444 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_3445 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_3446 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_3447 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_3448 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_3449 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_3450 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_3451 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_3452 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_3453 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_3454 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_3455 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c444, cp_1 = c444_p_0, cp_0 = 0;c < c444 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3440);
												mem_vec_3440 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3441);
												mem_vec_3441 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3442);
												mem_vec_3442 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3443);
												mem_vec_3443 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3444);
												mem_vec_3444 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3445);
												mem_vec_3445 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3446);
												mem_vec_3446 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3447);
												mem_vec_3447 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3448);
												mem_vec_3448 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3449);
												mem_vec_3449 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3450);
												mem_vec_3450 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3451);
												mem_vec_3451 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3452);
												mem_vec_3452 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3453);
												mem_vec_3453 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3454);
												mem_vec_3454 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3455);
												mem_vec_3455 = vec_25;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3440);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3441);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3442);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3443);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3444);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3445);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3446);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3447);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3448);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3449);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3450);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3451);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_3452);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_3453);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_3454);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_3455);
								}
							}
						}
}
