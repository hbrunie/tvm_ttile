
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (1, f); U (7, y); U (3, h); T (128, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (32, f); T (4, c); T (1, c)]
*/
IND_TYPE c, c0, cp_0, c0_p_0, c1_p_0, c1, cp_1, c0_p_1, cp_2, f, fp_0, w, wp_0, x, xp_0;
IND_TYPE y = 0;
IND_TYPE x0 = 0;
IND_TYPE h = 0;
IND_TYPE w0 = 0;
IND_TYPE c2 = 0;
IND_TYPE f0 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_0 ,mem_vec_1 ,mem_vec_2 ,mem_vec_3 ,mem_vec_4 ,mem_vec_5 ,mem_vec_6 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (c, 1) (512 / 512)
c1 = 0;
c1_p_0 = 0;
c0 = 0;
c0_p_1 = 0;
f = 0;
fp_0 = 0;
			for (w = w0, wp_0 = 0;w < w0 + 3;w += 1, wp_0 += 1){
				// y = 7, x = 7, h = 3, w = 1, c = 128, f = 16
				// T (x, 7) (7 / 1)
				for (x = x0, xp_0 = 0;x < x0 + 7;x += 1, xp_0 += 1){
							mem_vec_0 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
							mem_vec_1 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
							mem_vec_2 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
							mem_vec_3 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
							mem_vec_4 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
							mem_vec_5 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
							mem_vec_6 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
							// y = 7, x = 1, h = 3, w = 1, c = 128, f = 16
							// T (c, 128) (128 / 1)
							for (c = c0, cp_2 = c0_p_1, cp_1 = c0_p_0, cp_0 = 0;c < c0 + 128;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_0);
								mem_vec_0 = vec_0;
								scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
								vec_4 = _mm512_set1_ps(scal_1);
								vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1);
								mem_vec_1 = vec_3;
								scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
								vec_6 = _mm512_set1_ps(scal_2);
								vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2);
								mem_vec_2 = vec_5;
								scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
								vec_8 = _mm512_set1_ps(scal_3);
								vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_3);
								mem_vec_3 = vec_7;
								scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
								vec_10 = _mm512_set1_ps(scal_4);
								vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4);
								mem_vec_4 = vec_9;
								scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
								vec_12 = _mm512_set1_ps(scal_5);
								vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5);
								mem_vec_5 = vec_11;
								scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
								vec_14 = _mm512_set1_ps(scal_6);
								vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_6);
								mem_vec_6 = vec_13;
								scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h + 1) + c];
								vec_16 = _mm512_set1_ps(scal_7);
								vec_17 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
								vec_15 = _mm512_fmadd_ps(vec_16, vec_17, mem_vec_0);
								mem_vec_0 = vec_15;
								scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h + 1) + c];
								vec_19 = _mm512_set1_ps(scal_8);
								vec_18 = _mm512_fmadd_ps(vec_19, vec_17, mem_vec_1);
								mem_vec_1 = vec_18;
								scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h + 1) + c];
								vec_21 = _mm512_set1_ps(scal_9);
								vec_20 = _mm512_fmadd_ps(vec_21, vec_17, mem_vec_2);
								mem_vec_2 = vec_20;
								scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h + 1) + c];
								vec_23 = _mm512_set1_ps(scal_10);
								vec_22 = _mm512_fmadd_ps(vec_23, vec_17, mem_vec_3);
								mem_vec_3 = vec_22;
								scal_11 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h + 1) + c];
								vec_25 = _mm512_set1_ps(scal_11);
								vec_24 = _mm512_fmadd_ps(vec_25, vec_17, mem_vec_4);
								mem_vec_4 = vec_24;
								scal_12 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h + 1) + c];
								vec_27 = _mm512_set1_ps(scal_12);
								vec_26 = _mm512_fmadd_ps(vec_27, vec_17, mem_vec_5);
								mem_vec_5 = vec_26;
								scal_13 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h + 1) + c];
								vec_29 = _mm512_set1_ps(scal_13);
								vec_28 = _mm512_fmadd_ps(vec_29, vec_17, mem_vec_6);
								mem_vec_6 = vec_28;
								scal_14 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h + 2) + c];
								vec_31 = _mm512_set1_ps(scal_14);
								vec_32 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
								vec_30 = _mm512_fmadd_ps(vec_31, vec_32, mem_vec_0);
								mem_vec_0 = vec_30;
								scal_15 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h + 2) + c];
								vec_34 = _mm512_set1_ps(scal_15);
								vec_33 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_1);
								mem_vec_1 = vec_33;
								scal_16 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h + 2) + c];
								vec_36 = _mm512_set1_ps(scal_16);
								vec_35 = _mm512_fmadd_ps(vec_36, vec_32, mem_vec_2);
								mem_vec_2 = vec_35;
								scal_17 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h + 2) + c];
								vec_38 = _mm512_set1_ps(scal_17);
								vec_37 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_3);
								mem_vec_3 = vec_37;
								scal_18 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h + 2) + c];
								vec_40 = _mm512_set1_ps(scal_18);
								vec_39 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_4);
								mem_vec_4 = vec_39;
								scal_19 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h + 2) + c];
								vec_42 = _mm512_set1_ps(scal_19);
								vec_41 = _mm512_fmadd_ps(vec_42, vec_32, mem_vec_5);
								mem_vec_5 = vec_41;
								scal_20 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h + 2) + c];
								vec_44 = _mm512_set1_ps(scal_20);
								vec_43 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_6);
								mem_vec_6 = vec_43;
							}
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_0);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_6);
				}
			}
}
