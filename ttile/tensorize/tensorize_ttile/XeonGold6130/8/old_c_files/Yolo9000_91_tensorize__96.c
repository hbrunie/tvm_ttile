
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (4, x); T (1, c);
  T (4, f); T (1, x); T (2, y); T (17, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 1), (Arg 14))]]
*/
IND_TYPE c, cp_0, c375_p_0, cp_1, c375, f, fp_0, x, xp_0, x500_p_0, x501_p_0, xp_1, x500_p_1, xp_2, x500, x501, y, yp_0, y375_p_0, yp_1, y375;
IND_TYPE y376 = 0;
IND_TYPE x502 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c376 = 0;
IND_TYPE f250 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5928 ,mem_vec_5929 ,mem_vec_5930 ,mem_vec_5931 ,mem_vec_5932 ,mem_vec_5933 ,mem_vec_5934 ,mem_vec_5935 ,mem_vec_5936 ,mem_vec_5937 ,mem_vec_5938 ,mem_vec_5939 ,mem_vec_5940 ,mem_vec_5941 ,mem_vec_5942 ,mem_vec_5943 ,mem_vec_5944 ,mem_vec_5945 ,mem_vec_5946 ,mem_vec_5947 ,mem_vec_5948 ,mem_vec_5949 ,mem_vec_5950 ,mem_vec_5951 ,mem_vec_5952 ,mem_vec_5953 ,mem_vec_5954 ,mem_vec_5955 ,mem_vec_5956 ,mem_vec_5957 ,mem_vec_5958 ,mem_vec_5959 ,mem_vec_5960 ,mem_vec_5961 ,mem_vec_5962 ,mem_vec_5963 ,mem_vec_5964 ,mem_vec_5965 ,mem_vec_5966 ,mem_vec_5967 ,mem_vec_5968 ,mem_vec_5969 ,mem_vec_5970 ,mem_vec_5971 ,mem_vec_5972 ,mem_vec_5973 ,mem_vec_5974 ,mem_vec_5975 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y375 = 0;
y375_p_0 = 0;
x501 = 0;
x501_p_0 = 0;
y = 0;
yp_1 = 0;
x500 = 0;
x500_p_1 = 0;
f = 0;
fp_0 = 0;
c375 = 0;
c375_p_0 = 0;
							for (x = x500, xp_2 = x500_p_1, xp_1 = x500_p_0, xp_0 = 0;x < x500 + 4;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5928 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_5929 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_5930 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_5931 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_5932 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_5933 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_5934 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_5935 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_5936 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_5937 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_5938 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_5939 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_5940 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_5941 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_5942 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_5943 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_5944 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_5945 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_5946 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_5947 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c375, cp_1 = c375_p_0, cp_0 = 0;c < c375 + 256;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5928);
											mem_vec_5928 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5929);
											mem_vec_5929 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5930);
											mem_vec_5930 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5931);
											mem_vec_5931 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5932);
											mem_vec_5932 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5933);
											mem_vec_5933 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5934);
											mem_vec_5934 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5935);
											mem_vec_5935 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5936);
											mem_vec_5936 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5937);
											mem_vec_5937 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5938);
											mem_vec_5938 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5939);
											mem_vec_5939 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5940);
											mem_vec_5940 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5941);
											mem_vec_5941 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5942);
											mem_vec_5942 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5943);
											mem_vec_5943 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5944);
											mem_vec_5944 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5945);
											mem_vec_5945 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5946);
											mem_vec_5946 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5947);
											mem_vec_5947 = vec_31;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5928);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5929);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5930);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5931);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5932);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5933);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5934);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5935);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5936);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5937);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5938);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5939);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5940);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_5941);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5942);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_5943);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_5944);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_5945);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_5946);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_5947);
							}
}
