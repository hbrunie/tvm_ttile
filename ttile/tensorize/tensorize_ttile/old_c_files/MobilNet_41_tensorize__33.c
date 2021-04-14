
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (1, f); T (4, c); T (14, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 10))]; T (4, f)]
*/
IND_TYPE c, cp_0, c486_p_0, cp_1, c486, f, fp_0, f486_p_0, fp_1, f486, h, hp_0, w, wp_0, x, xp_0, x486_p_0, xp_1, x486, y, yp_0;
IND_TYPE y324 = 0;
IND_TYPE x487 = 0;
IND_TYPE h256 = 0;
IND_TYPE w294 = 0;
IND_TYPE c487 = 0;
IND_TYPE f487 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3944 ,mem_vec_3945 ,mem_vec_3946 ,mem_vec_3947 ,mem_vec_3948 ,mem_vec_3949 ,mem_vec_3950 ,mem_vec_3951 ,mem_vec_3952 ,mem_vec_3953 ,mem_vec_3954 ,mem_vec_3955 ,mem_vec_3956 ,mem_vec_3957 ,mem_vec_3958 ,mem_vec_3959 ,mem_vec_3960 ,mem_vec_3961 ,mem_vec_3962 ,mem_vec_3963 ,mem_vec_3964 ,mem_vec_3965 ,mem_vec_3966 ,mem_vec_3967 ,mem_vec_3968 ,mem_vec_3969 ,mem_vec_3970 ,mem_vec_3971 ,mem_vec_3972 ,mem_vec_3973 ,mem_vec_3974 ,mem_vec_3975 ,mem_vec_3976 ,mem_vec_3977 ,mem_vec_3978 ,mem_vec_3979 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 4) (128 / 32)
f486 = 0;
f486_p_0 = 0;
y = 0;
yp_0 = 0;
x486 = 0;
x486_p_0 = 0;
c486 = 0;
c486_p_0 = 0;
f = 0;
fp_1 = 0;
						for (h = h256, hp_0 = 0;h < h256 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w294, wp_0 = 0;w < w294 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 32
								// T (x, 2) (2 / 1)
								for (x = x486, xp_1 = x486_p_0, xp_0 = 0;x < x486 + 2;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3944 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_3945 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_3946 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_3947 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_3948 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_3949 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_3950 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_3951 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_3952 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_3953 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_3954 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_3955 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_3956 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_3957 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_3958 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_3959 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c486, cp_1 = c486_p_0, cp_0 = 0;c < c486 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3944);
												mem_vec_3944 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3945);
												mem_vec_3945 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3946);
												mem_vec_3946 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3947);
												mem_vec_3947 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3948);
												mem_vec_3948 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3949);
												mem_vec_3949 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3950);
												mem_vec_3950 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3951);
												mem_vec_3951 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3952);
												mem_vec_3952 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3953);
												mem_vec_3953 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3954);
												mem_vec_3954 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3955);
												mem_vec_3955 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3956);
												mem_vec_3956 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3957);
												mem_vec_3957 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3958);
												mem_vec_3958 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3959);
												mem_vec_3959 = vec_25;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3944);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3945);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3946);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3947);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3948);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3949);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3950);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3951);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3952);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3953);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3954);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3955);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_3956);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_3957);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_3958);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_3959);
								}
							}
						}
}
