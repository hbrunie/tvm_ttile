
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (1024, c); Hoist_vars [c]; T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (16, f);
  T (1, c); T (17, x); T (1, y)]
*/
IND_TYPE c, cp_0, c78_p_0, cp_1, c78, f, fp_0, x, xp_0, x78_p_0, xp_1, x78, y, yp_0, y78_p_0, yp_1, y78;
IND_TYPE y79 = 0;
IND_TYPE x79 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c79 = 0;
IND_TYPE f52 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,mem_vec_952 ,mem_vec_953 ,mem_vec_954 ,mem_vec_955 ,mem_vec_956 ,mem_vec_957 ,mem_vec_958 ,mem_vec_959 ,mem_vec_960 ,mem_vec_961 ,mem_vec_962 ,mem_vec_963 ,mem_vec_964 ,mem_vec_965 ,mem_vec_966 ,mem_vec_967 ,mem_vec_968 ,mem_vec_969 ,mem_vec_970 ,mem_vec_971 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
y78 = 0;
y78_p_0 = 0;
x78 = 0;
x78_p_0 = 0;
c78 = 0;
c78_p_0 = 0;
			for (f = f52, fp_0 = 0;f < f52 + 512;f += 32, fp_0 += 32){
					for (y = y78, yp_1 = y78_p_0, yp_0 = 0;y < y78 + 12;y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
						// T (x, 1) (1 / 1)
						for (x = x78, xp_1 = x78_p_0, xp_0 = 0;x < x78 + 1;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_936 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_937 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_938 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_939 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_940 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_941 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_942 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_943 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_944 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_945 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_946 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_947 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_948 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_949 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_950 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_951 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
									// T (c, 1024) (1024 / 1)
									for (c = c78, cp_1 = c78_p_0, cp_0 = 0;c < c78 + 1024;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_936);
										mem_vec_936 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_937);
										mem_vec_937 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_938);
										mem_vec_938 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_939);
										mem_vec_939 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_940);
										mem_vec_940 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_941);
										mem_vec_941 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_942);
										mem_vec_942 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_943);
										mem_vec_943 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_944);
										mem_vec_944 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_945);
										mem_vec_945 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_946);
										mem_vec_946 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_947);
										mem_vec_947 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_948);
										mem_vec_948 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_949);
										mem_vec_949 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_950);
										mem_vec_950 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_951);
										mem_vec_951 = vec_23;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_936);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_937);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_938);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_939);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_940);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_941);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_942);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_943);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_944);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_945);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_946);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_947);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_948);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_949);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_950);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_951);
						}
					}
					for (y = y78 + 12, yp_1 = y78_p_0, yp_0 = 0;y < y78 + 12 + 5;y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
						// T (x, 1) (1 / 1)
						for (x = x78, xp_1 = x78_p_0, xp_0 = 0;x < x78 + 1;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_952 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_953 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_954 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_955 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_956 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_957 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_958 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_959 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_960 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_961 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_962 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_963 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_964 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_965 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_966 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_967 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									mem_vec_968 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_969 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
									mem_vec_970 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_971 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
									// T (c, 1024) (1024 / 1)
									for (c = c78, cp_1 = c78_p_0, cp_0 = 0;c < c78 + 1024;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_952);
										mem_vec_952 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_953);
										mem_vec_953 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_954);
										mem_vec_954 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_955);
										mem_vec_955 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_956);
										mem_vec_956 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_957);
										mem_vec_957 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_958);
										mem_vec_958 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_959);
										mem_vec_959 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_960);
										mem_vec_960 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_961);
										mem_vec_961 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_962);
										mem_vec_962 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_963);
										mem_vec_963 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_964);
										mem_vec_964 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_965);
										mem_vec_965 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_966);
										mem_vec_966 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_967);
										mem_vec_967 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_968);
										mem_vec_968 = vec_24;
										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_969);
										mem_vec_969 = vec_26;
										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_970);
										mem_vec_970 = vec_27;
										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_971);
										mem_vec_971 = vec_28;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_952);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_953);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_954);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_955);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_956);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_957);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_958);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_959);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_960);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_961);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_962);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_963);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_964);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_965);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_966);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_967);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_968);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_969);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_970);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_971);
						}
					}
			}
}
