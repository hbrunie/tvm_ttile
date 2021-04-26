
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); U (8, y); T (128, c); Hoist_vars [c]; T (17, x); T (1, y);
  T (2, f); T (8, x); T (17, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x201_p_0, xp_1, x201, y, yp_0, y201_p_0, yp_1, y201;
IND_TYPE y202 = 0;
IND_TYPE x202 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c134 = 0;
IND_TYPE f134 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_2620 ,mem_vec_2621 ,mem_vec_2622 ,mem_vec_2623 ,mem_vec_2624 ,mem_vec_2625 ,mem_vec_2626 ,mem_vec_2627 ,mem_vec_2628 ,mem_vec_2629 ,mem_vec_2630 ,mem_vec_2631 ,mem_vec_2632 ,mem_vec_2633 ,mem_vec_2634 ,mem_vec_2635 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 17) (136 / 8)
y201 = 0;
y201_p_0 = 0;
x201 = 0;
x201_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_1 = 0;
				for (x = x201, xp_1 = x201_p_0, xp_0 = 0;x < x201 + 17;x += 1, xp_1 += 1, xp_0 += 1){
							mem_vec_2620 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
							mem_vec_2621 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
							mem_vec_2622 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
							mem_vec_2623 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
							mem_vec_2624 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
							mem_vec_2625 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
							mem_vec_2626 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
							mem_vec_2627 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
							mem_vec_2628 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
							mem_vec_2629 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
							mem_vec_2630 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
							mem_vec_2631 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
							mem_vec_2632 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
							mem_vec_2633 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
							mem_vec_2634 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
							mem_vec_2635 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
							// y = 8, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 128) (128 / 1)
							for (c = c134, cp_0 = 0;c < c134 + 128;c += 1, cp_0 += 1){
								scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2620);
								mem_vec_2620 = vec_0;
								vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2621);
								mem_vec_2621 = vec_3;
								scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
								vec_6 = _mm512_set1_ps(scal_1);
								vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2622);
								mem_vec_2622 = vec_5;
								vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2623);
								mem_vec_2623 = vec_7;
								scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
								vec_9 = _mm512_set1_ps(scal_2);
								vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2624);
								mem_vec_2624 = vec_8;
								vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2625);
								mem_vec_2625 = vec_10;
								scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
								vec_12 = _mm512_set1_ps(scal_3);
								vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2626);
								mem_vec_2626 = vec_11;
								vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2627);
								mem_vec_2627 = vec_13;
								scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
								vec_15 = _mm512_set1_ps(scal_4);
								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2628);
								mem_vec_2628 = vec_14;
								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2629);
								mem_vec_2629 = vec_16;
								scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
								vec_18 = _mm512_set1_ps(scal_5);
								vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2630);
								mem_vec_2630 = vec_17;
								vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2631);
								mem_vec_2631 = vec_19;
								scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
								vec_21 = _mm512_set1_ps(scal_6);
								vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2632);
								mem_vec_2632 = vec_20;
								vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2633);
								mem_vec_2633 = vec_22;
								scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
								vec_24 = _mm512_set1_ps(scal_7);
								vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2634);
								mem_vec_2634 = vec_23;
								vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2635);
								mem_vec_2635 = vec_25;
							}
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2620);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2621);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2622);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2623);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2624);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2625);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2626);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2627);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2628);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2629);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2630);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_2631);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2632);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_2633);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2634);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_2635);
				}
}
