
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (16, c); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (32, f);
  T (2, c); T (17, x)]
*/
IND_TYPE c, cp_0, c162_p_0, c163_p_0, cp_1, c162_p_1, cp_2, c162, c163, f, fp_0, w, wp_0, x, xp_0, x162_p_0, x163_p_0, xp_1, x162_p_1, xp_2, x162, x163, y, yp_0;
IND_TYPE y108 = 0;
IND_TYPE x164 = 0;
IND_TYPE h = 0;
IND_TYPE w106 = 0;
IND_TYPE c164 = 0;
IND_TYPE f216 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1956 ,mem_vec_1957 ,mem_vec_1958 ,mem_vec_1959 ,mem_vec_1960 ,mem_vec_1961 ,mem_vec_1962 ,mem_vec_1963 ,mem_vec_1964 ,mem_vec_1965 ,mem_vec_1966 ,mem_vec_1967 ,mem_vec_1968 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (x, 17) (34 / 2)
x163 = 0;
x163_p_0 = 0;
c163 = 0;
c163_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x162 = 0;
x162_p_1 = 0;
c162 = 0;
c162_p_1 = 0;
							for (w = w106, wp_0 = 0;w < w106 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 8, f = 16
								// T (x, 2) (2 / 1)
								for (x = x162, xp_2 = x162_p_1, xp_1 = x162_p_0, xp_0 = 0;x < x162 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1956 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_1957 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_1958 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_1959 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_1960 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_1961 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
											// T (c, 8) (8 / 1)
											for (c = c162, cp_2 = c162_p_1, cp_1 = c162_p_0, cp_0 = 0;c < c162 + 8;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1956);
												mem_vec_1956 = vec_0;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);
												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1957);
												mem_vec_1957 = vec_3;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1958);
												mem_vec_1958 = vec_5;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);
												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1959);
												mem_vec_1959 = vec_7;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1960);
												mem_vec_1960 = vec_9;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_12 = _mm512_set1_ps(scal_5);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1961);
												mem_vec_1961 = vec_11;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_14 = _mm512_set1_ps(scal_6);
												vec_15 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_13 = _mm512_fmadd_ps(vec_14, vec_15, mem_vec_1956);
												mem_vec_1956 = vec_13;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_17 = _mm512_set1_ps(scal_7);
												vec_16 = _mm512_fmadd_ps(vec_17, vec_15, mem_vec_1957);
												mem_vec_1957 = vec_16;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_19 = _mm512_set1_ps(scal_8);
												vec_18 = _mm512_fmadd_ps(vec_19, vec_15, mem_vec_1958);
												mem_vec_1958 = vec_18;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_21 = _mm512_set1_ps(scal_9);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_15, mem_vec_1959);
												mem_vec_1959 = vec_20;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_23 = _mm512_set1_ps(scal_10);
												vec_22 = _mm512_fmadd_ps(vec_23, vec_15, mem_vec_1960);
												mem_vec_1960 = vec_22;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_25 = _mm512_set1_ps(scal_11);
												vec_24 = _mm512_fmadd_ps(vec_25, vec_15, mem_vec_1961);
												mem_vec_1961 = vec_24;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_27 = _mm512_set1_ps(scal_12);
												vec_28 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_1956);
												mem_vec_1956 = vec_26;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_30 = _mm512_set1_ps(scal_13);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_28, mem_vec_1957);
												mem_vec_1957 = vec_29;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_32 = _mm512_set1_ps(scal_14);
												vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_1958);
												mem_vec_1958 = vec_31;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_34 = _mm512_set1_ps(scal_15);
												vec_33 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_1959);
												mem_vec_1959 = vec_33;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_36 = _mm512_set1_ps(scal_16);
												vec_35 = _mm512_fmadd_ps(vec_36, vec_28, mem_vec_1960);
												mem_vec_1960 = vec_35;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_38 = _mm512_set1_ps(scal_17);
												vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_1961);
												mem_vec_1961 = vec_37;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1956);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1957);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1958);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1959);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1960);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1961);
								}
							}
}
