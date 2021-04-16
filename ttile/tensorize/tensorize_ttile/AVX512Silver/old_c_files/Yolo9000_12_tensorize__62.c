
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (2, y); U (3, w); T (256, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (1, c); T (1, f); T (17, y); T (1, x); T (4, f); T (2, f)]
*/
IND_TYPE c, cp_0, c36_p_0, cp_1, c36, f, fp_0, f41_p_0, f42_p_0, fp_1, f41_p_1, fp_2, f41, f42, h, hp_0, x, xp_0, x33_p_0, xp_1, x33, y, yp_0;
IND_TYPE y22 = 0;
IND_TYPE x34 = 0;
IND_TYPE h22 = 0;
IND_TYPE w = 0;
IND_TYPE c37 = 0;
IND_TYPE f43 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_112 ,mem_vec_113 ,mem_vec_114 ,mem_vec_115 ,mem_vec_116 ,mem_vec_117 ,mem_vec_118 ,mem_vec_119 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
f42 = 0;
f42_p_0 = 0;
f41 = 0;
f41_p_1 = 0;
x33 = 0;
x33_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c36 = 0;
c36_p_0 = 0;
						for (h = h22, hp_0 = 0;h < h22 + 3;h += 1, hp_0 += 1){
							// y = 2, x = 34, h = 1, w = 3, c = 256, f = 64
							// T (x, 34) (34 / 1)
							for (x = x33, xp_1 = x33_p_0, xp_0 = 0;x < x33 + 34;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_112 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_113 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_114 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_115 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_116 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_117 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_118 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_119 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										// y = 2, x = 1, h = 1, w = 3, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c36, cp_1 = c36_p_0, cp_0 = 0;c < c36 + 256;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_112);
											mem_vec_112 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_113);
											mem_vec_113 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_114);
											mem_vec_114 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_115);
											mem_vec_115 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_116);
											mem_vec_116 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_117);
											mem_vec_117 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_118);
											mem_vec_118 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_119);
											mem_vec_119 = vec_13;
											scal_2 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_16 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_112);
											mem_vec_112 = vec_14;
											vec_18 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_113);
											mem_vec_113 = vec_17;
											vec_20 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
											vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_114);
											mem_vec_114 = vec_19;
											vec_22 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
											vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_115);
											mem_vec_115 = vec_21;
											scal_3 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
											vec_24 = _mm512_set1_ps(scal_3);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_116);
											mem_vec_116 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_117);
											mem_vec_117 = vec_25;
											vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_118);
											mem_vec_118 = vec_26;
											vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_119);
											mem_vec_119 = vec_27;
											scal_4 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_112);
											mem_vec_112 = vec_28;
											vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_113);
											mem_vec_113 = vec_31;
											vec_34 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
											vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_114);
											mem_vec_114 = vec_33;
											vec_36 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
											vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_115);
											mem_vec_115 = vec_35;
											scal_5 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
											vec_38 = _mm512_set1_ps(scal_5);
											vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_116);
											mem_vec_116 = vec_37;
											vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_117);
											mem_vec_117 = vec_39;
											vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_118);
											mem_vec_118 = vec_40;
											vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_119);
											mem_vec_119 = vec_41;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_112);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_113);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_114);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_115);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_116);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_117);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_118);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_119);
							}
						}
}
