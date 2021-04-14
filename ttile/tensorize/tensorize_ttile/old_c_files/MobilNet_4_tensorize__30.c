
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (1, f); T (4, c); T (2, x); T (4, y); T (2, f)]
*/
IND_TYPE c, cp_0, c108_p_0, cp_1, c108, f, fp_0, f108_p_0, fp_1, f108, h, hp_0, w, wp_0, x, xp_0, x108_p_0, xp_1, x108, y, yp_0;
IND_TYPE y72 = 0;
IND_TYPE x109 = 0;
IND_TYPE h72 = 0;
IND_TYPE w72 = 0;
IND_TYPE c109 = 0;
IND_TYPE f109 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1008 ,mem_vec_1009 ,mem_vec_1010 ,mem_vec_1011 ,mem_vec_1012 ,mem_vec_1013 ,mem_vec_1014 ,mem_vec_1015 ,mem_vec_1016 ,mem_vec_1017 ,mem_vec_1018 ,mem_vec_1019 ,mem_vec_1020 ,mem_vec_1021 ,mem_vec_1022 ,mem_vec_1023 ,mem_vec_1024 ,mem_vec_1025 ,mem_vec_1026 ,mem_vec_1027 ,mem_vec_1028 ,mem_vec_1029 ,mem_vec_1030 ,mem_vec_1031 ,mem_vec_1032 ,mem_vec_1033 ,mem_vec_1034 ,mem_vec_1035 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
f108 = 0;
f108_p_0 = 0;
y = 0;
yp_0 = 0;
x108 = 0;
x108_p_0 = 0;
c108 = 0;
c108_p_0 = 0;
f = 0;
fp_1 = 0;
					for (h = h72, hp_0 = 0;h < h72 + 3;h += 1, hp_0 += 1){
						// y = 7, x = 14, h = 1, w = 3, c = 32, f = 64
						// T (w, 3) (3 / 1)
						for (w = w72, wp_0 = 0;w < w72 + 3;w += 1, wp_0 += 1){
							// y = 7, x = 14, h = 1, w = 1, c = 32, f = 64
							// T (x, 14) (14 / 1)
							for (x = x108, xp_1 = x108_p_0, xp_0 = 0;x < x108 + 14;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1008 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_1009 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_1010 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_1011 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_1012 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_1013 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_1014 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_1015 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_1016 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_1017 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_1018 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_1019 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										mem_vec_1020 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_1021 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_1022 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
										mem_vec_1023 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
										mem_vec_1024 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_1025 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_1026 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
										mem_vec_1027 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
										mem_vec_1028 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_1029 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_1030 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
										mem_vec_1031 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
										mem_vec_1032 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_1033 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_1034 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
										mem_vec_1035 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c108, cp_1 = c108_p_0, cp_0 = 0;c < c108 + 32;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1008);
											mem_vec_1008 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1009);
											mem_vec_1009 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1010);
											mem_vec_1010 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1011);
											mem_vec_1011 = vec_7;
											scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1012);
											mem_vec_1012 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1013);
											mem_vec_1013 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1014);
											mem_vec_1014 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1015);
											mem_vec_1015 = vec_13;
											scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1016);
											mem_vec_1016 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1017);
											mem_vec_1017 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1018);
											mem_vec_1018 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1019);
											mem_vec_1019 = vec_18;
											scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1020);
											mem_vec_1020 = vec_19;
											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1021);
											mem_vec_1021 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1022);
											mem_vec_1022 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1023);
											mem_vec_1023 = vec_23;
											scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1024);
											mem_vec_1024 = vec_24;
											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1025);
											mem_vec_1025 = vec_26;
											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1026);
											mem_vec_1026 = vec_27;
											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1027);
											mem_vec_1027 = vec_28;
											scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1028);
											mem_vec_1028 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1029);
											mem_vec_1029 = vec_31;
											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1030);
											mem_vec_1030 = vec_32;
											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1031);
											mem_vec_1031 = vec_33;
											scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_1032);
											mem_vec_1032 = vec_34;
											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_1033);
											mem_vec_1033 = vec_36;
											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_1034);
											mem_vec_1034 = vec_37;
											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_1035);
											mem_vec_1035 = vec_38;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1008);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1009);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_1010);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_1011);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1012);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1013);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_1014);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_1015);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1016);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1017);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_1018);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_1019);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1020);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1021);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_1022);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_1023);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1024);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1025);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_1026);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_1027);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1028);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1029);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_1030);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_1031);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1032);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_1033);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_1034);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_1035);
							}
						}
					}
}
