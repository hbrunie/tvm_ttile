
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (2, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (8, f); T (32, c); T (17, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1026_p_0, cp_1, c1026, f, fp_0, f1368_p_0, f1369_p_0, fp_1, f1368_p_1, fp_2, f1368, f1369, x, xp_0, x1368_p_0, x1369_p_0, xp_1, x1368_p_1, xp_2, x1368, x1369, y, yp_0;
IND_TYPE y684 = 0;
IND_TYPE x1370 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1027 = 0;
IND_TYPE f1370 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_12312 ,mem_vec_12313 ,mem_vec_12314 ,mem_vec_12315 ,mem_vec_12316 ,mem_vec_12317 ,mem_vec_12318 ,mem_vec_12319 ,mem_vec_12320 ,mem_vec_12321 ,mem_vec_12322 ,mem_vec_12323 ,mem_vec_12324 ,mem_vec_12325 ,mem_vec_12326 ,mem_vec_12327 ,mem_vec_12328 ,mem_vec_12329 ,mem_vec_12330 ,mem_vec_12331 ,mem_vec_12332 ,mem_vec_12333 ,mem_vec_12334 ,mem_vec_12335 ,mem_vec_12336 ,mem_vec_12337 ,mem_vec_12338 ,mem_vec_12339 ,mem_vec_12340 ,mem_vec_12341 ,mem_vec_12342 ,mem_vec_12343 ,mem_vec_12344 ,mem_vec_12345 ,mem_vec_12346 ,mem_vec_12347 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 1) (512 / 512)
f1369 = 0;
f1369_p_0 = 0;
x1369 = 0;
x1369_p_0 = 0;
c1026 = 0;
c1026_p_0 = 0;
f1368 = 0;
f1368_p_1 = 0;
y = 0;
yp_0 = 0;
x1368 = 0;
x1368_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1368, xp_2 = x1368_p_1, xp_1 = x1368_p_0, xp_0 = 0;x < x1368 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12312 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_12313 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_12314 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_12315 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_12316 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_12317 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_12318 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_12319 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_12320 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_12321 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_12322 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_12323 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_12324 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_12325 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_12326 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_12327 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c1026, cp_1 = c1026_p_0, cp_0 = 0;c < c1026 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12312);
												mem_vec_12312 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12313);
												mem_vec_12313 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12314);
												mem_vec_12314 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12315);
												mem_vec_12315 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12316);
												mem_vec_12316 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12317);
												mem_vec_12317 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12318);
												mem_vec_12318 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12319);
												mem_vec_12319 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12320);
												mem_vec_12320 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12321);
												mem_vec_12321 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12322);
												mem_vec_12322 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12323);
												mem_vec_12323 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12324);
												mem_vec_12324 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12325);
												mem_vec_12325 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12326);
												mem_vec_12326 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12327);
												mem_vec_12327 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_12312);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_12313);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_12314);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_12315);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_12316);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_12317);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_12318);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_12319);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_12320);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_12321);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_12322);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_12323);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_12324);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_12325);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_12326);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_12327);
								}
}
