
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (1, x); T (1, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (16, f); T (1024, c); T (17, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1182_p_0, cp_1, c1182, f, fp_0, f1576_p_0, f1577_p_0, fp_1, f1576_p_1, fp_2, f1576, f1577, x, xp_0, x1576_p_0, x1577_p_0, xp_1, x1576_p_1, xp_2, x1576, x1577, y, yp_0;
IND_TYPE y788 = 0;
IND_TYPE x1578 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1183 = 0;
IND_TYPE f1578 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_14184 ,mem_vec_14185 ,mem_vec_14186 ,mem_vec_14187 ,mem_vec_14188 ,mem_vec_14189 ,mem_vec_14190 ,mem_vec_14191 ,mem_vec_14192 ,mem_vec_14193 ,mem_vec_14194 ,mem_vec_14195 ,mem_vec_14196 ,mem_vec_14197 ,mem_vec_14198 ,mem_vec_14199 ,mem_vec_14200 ,mem_vec_14201 ,mem_vec_14202 ,mem_vec_14203 ,mem_vec_14204 ,mem_vec_14205 ,mem_vec_14206 ,mem_vec_14207 ,mem_vec_14208 ,mem_vec_14209 ,mem_vec_14210 ,mem_vec_14211 ,mem_vec_14212 ,mem_vec_14213 ,mem_vec_14214 ,mem_vec_14215 ,mem_vec_14216 ,mem_vec_14217 ,mem_vec_14218 ,mem_vec_14219 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 1) (512 / 512)
f1577 = 0;
f1577_p_0 = 0;
x1577 = 0;
x1577_p_0 = 0;
c1182 = 0;
c1182_p_0 = 0;
f1576 = 0;
f1576_p_1 = 0;
y = 0;
yp_0 = 0;
x1576 = 0;
x1576_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1576, xp_2 = x1576_p_1, xp_1 = x1576_p_0, xp_0 = 0;x < x1576 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14184 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_14185 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_14186 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_14187 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_14188 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_14189 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_14190 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_14191 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_14192 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_14193 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_14194 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_14195 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_14196 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_14197 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_14198 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_14199 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c1182, cp_1 = c1182_p_0, cp_0 = 0;c < c1182 + 1;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14184);
												mem_vec_14184 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14185);
												mem_vec_14185 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14186);
												mem_vec_14186 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14187);
												mem_vec_14187 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14188);
												mem_vec_14188 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14189);
												mem_vec_14189 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14190);
												mem_vec_14190 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14191);
												mem_vec_14191 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14192);
												mem_vec_14192 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14193);
												mem_vec_14193 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14194);
												mem_vec_14194 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14195);
												mem_vec_14195 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14196);
												mem_vec_14196 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14197);
												mem_vec_14197 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14198);
												mem_vec_14198 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14199);
												mem_vec_14199 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_14184);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_14185);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_14186);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_14187);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_14188);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_14189);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_14190);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_14191);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_14192);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_14193);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_14194);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_14195);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_14196);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_14197);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_14198);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_14199);
								}
}
