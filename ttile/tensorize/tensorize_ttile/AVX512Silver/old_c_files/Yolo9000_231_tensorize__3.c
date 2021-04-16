
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (1, f); ULambda y; T (1024, c); Hoist_vars [c]; T (17, x); T (19, f);
  T (1, x); T (1, y); T (1, c); T (93, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (1, f)]
*/
IND_TYPE c, cp_0, c360_p_0, cp_1, c360, f, fp_0, f480_p_0, f481_p_0, fp_1, f480_p_1, fp_2, f480, f481, x, xp_0, x480_p_0, x481_p_0, xp_1, x480_p_1, xp_2, x480, x481, y, yp_0, y360_p_0, yp_1, y360;
IND_TYPE y361 = 0;
IND_TYPE x482 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c361 = 0;
IND_TYPE f482 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_2040 ,mem_vec_2041 ,mem_vec_2042 ,mem_vec_2043 ,mem_vec_2044 ,mem_vec_2045 ,mem_vec_2046 ,mem_vec_2047 ,mem_vec_2048 ,mem_vec_2049 ,mem_vec_2050 ,mem_vec_2051 ,mem_vec_2052 ,mem_vec_2053 ,mem_vec_2054 ,mem_vec_2055 ,mem_vec_2056 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_2 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
// T (f, 1) (28272 / 28272)
f481 = 0;
f481_p_0 = 0;
y360 = 0;
y360_p_0 = 0;
x481 = 0;
x481_p_0 = 0;
f480 = 0;
f480_p_1 = 0;
c360 = 0;
c360_p_0 = 0;
y = 0;
yp_1 = 0;
x480 = 0;
x480_p_1 = 0;
f = 0;
fp_2 = 0;
									for (x = x480, xp_2 = x480_p_1, xp_1 = x480_p_0, xp_0 = 0;x < x480 + 17;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2040 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_2041 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_2042 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_2043 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_2044 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_2045 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_2046 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_2047 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 16
												// T (c, 1024) (1024 / 1)
												for (c = c360, cp_1 = c360_p_0, cp_0 = 0;c < c360 + 1024;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2040);
													mem_vec_2040 = vec_0;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);
													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_2041);
													mem_vec_2041 = vec_3;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2042);
													mem_vec_2042 = vec_5;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);
													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_2043);
													mem_vec_2043 = vec_7;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);
													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2044);
													mem_vec_2044 = vec_9;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2045);
													mem_vec_2045 = vec_11;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);
													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_2046);
													mem_vec_2046 = vec_13;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);
													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_2047);
													mem_vec_2047 = vec_15;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2040);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2041);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2042);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2043);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2044);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2045);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2046);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2047);
									}
}
