
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (2, y); U (3, h); T (16, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, c); T (2, x); T (17, y); T (1, y); T (136, x); T (8, y)]
*/
IND_TYPE c, cp_0, c93_p_0, cp_1, c93, w, wp_0, x, xp_0, x124_p_0, x125_p_0, xp_1, x124_p_1, xp_2, x124, x125, y, yp_0, y124_p_0, y125_p_0, yp_1, y124_p_1, yp_2, y124, y125;
IND_TYPE y126 = 0;
IND_TYPE x126 = 0;
IND_TYPE h = 0;
IND_TYPE w62 = 0;
IND_TYPE c94 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_248 ,mem_vec_249 ,mem_vec_250 ,mem_vec_251 ,mem_vec_252 ,mem_vec_253 ,mem_vec_254 ,mem_vec_255 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 8) (272 / 34)
y125 = 0;
y125_p_0 = 0;
x125 = 0;
x125_p_0 = 0;
y124 = 0;
y124_p_1 = 0;
y = 0;
yp_2 = 0;
x124 = 0;
x124_p_1 = 0;
c93 = 0;
c93_p_0 = 0;
						for (w = w62, wp_0 = 0;w < w62 + 3;w += 1, wp_0 += 1){
							// y = 2, x = 1, h = 3, w = 1, c = 16, f = 64
							// T (x, 1) (1 / 1)
							for (x = x124, xp_2 = x124_p_1, xp_1 = x124_p_0, xp_0 = 0;x < x124 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_248 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_249 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_250 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_251 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_252 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_253 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_254 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_255 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										// y = 2, x = 1, h = 3, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c93, cp_1 = c93_p_0, cp_0 = 0;c < c93 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_248);
											mem_vec_248 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_249);
											mem_vec_249 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_250);
											mem_vec_250 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_251);
											mem_vec_251 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_252);
											mem_vec_252 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_253);
											mem_vec_253 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_254);
											mem_vec_254 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_255);
											mem_vec_255 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_16 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_248);
											mem_vec_248 = vec_14;
											vec_18 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_249);
											mem_vec_249 = vec_17;
											vec_20 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 32]);
											vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_250);
											mem_vec_250 = vec_19;
											vec_22 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 48]);
											vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_251);
											mem_vec_251 = vec_21;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_24 = _mm512_set1_ps(scal_3);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_252);
											mem_vec_252 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_253);
											mem_vec_253 = vec_25;
											vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_254);
											mem_vec_254 = vec_26;
											vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_255);
											mem_vec_255 = vec_27;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_30 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_248);
											mem_vec_248 = vec_28;
											vec_32 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_249);
											mem_vec_249 = vec_31;
											vec_34 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 32]);
											vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_250);
											mem_vec_250 = vec_33;
											vec_36 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 48]);
											vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_251);
											mem_vec_251 = vec_35;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_38 = _mm512_set1_ps(scal_5);
											vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_252);
											mem_vec_252 = vec_37;
											vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_253);
											mem_vec_253 = vec_39;
											vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_254);
											mem_vec_254 = vec_40;
											vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_255);
											mem_vec_255 = vec_41;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_248);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_249);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_250);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_251);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_252);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_253);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_254);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_255);
							}
						}
}
