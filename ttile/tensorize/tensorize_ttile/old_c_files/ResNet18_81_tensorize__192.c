
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (2, f); T (128, c); T (14, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (4, f)]
*/
IND_TYPE c, cp_0, c762_p_0, cp_1, c762, f, fp_0, f834_p_0, fp_1, f834, h, hp_0, w, wp_0, x, xp_0, x762_p_0, xp_1, x762, y, yp_0;
IND_TYPE y508 = 0;
IND_TYPE x763 = 0;
IND_TYPE h434 = 0;
IND_TYPE w458 = 0;
IND_TYPE c763 = 0;
IND_TYPE f835 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6872 ,mem_vec_6873 ,mem_vec_6874 ,mem_vec_6875 ,mem_vec_6876 ,mem_vec_6877 ,mem_vec_6878 ,mem_vec_6879 ,mem_vec_6880 ,mem_vec_6881 ,mem_vec_6882 ,mem_vec_6883 ,mem_vec_6884 ,mem_vec_6885 ,mem_vec_6886 ,mem_vec_6887 ,mem_vec_6888 ,mem_vec_6889 ,mem_vec_6890 ,mem_vec_6891 ,mem_vec_6892 ,mem_vec_6893 ,mem_vec_6894 ,mem_vec_6895 ,mem_vec_6896 ,mem_vec_6897 ,mem_vec_6898 ,mem_vec_6899 ,mem_vec_6900 ,mem_vec_6901 ,mem_vec_6902 ,mem_vec_6903 ,mem_vec_6904 ,mem_vec_6905 ,mem_vec_6906 ,mem_vec_6907 ,mem_vec_6908 ,mem_vec_6909 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
f834 = 0;
f834_p_0 = 0;
y = 0;
yp_0 = 0;
x762 = 0;
x762_p_0 = 0;
c762 = 0;
c762_p_0 = 0;
f = 0;
fp_1 = 0;
						for (h = h434, hp_0 = 0;h < h434 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 1, f = 32
							// T (w, 3) (3 / 1)
							for (w = w458, wp_0 = 0;w < w458 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 1, c = 1, f = 32
								// T (x, 2) (2 / 1)
								for (x = x762, xp_1 = x762_p_0, xp_0 = 0;x < x762 + 2;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6872 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_6873 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_6874 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_6875 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_6876 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_6877 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_6878 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_6879 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_6880 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_6881 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_6882 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_6883 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_6884 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_6885 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_6886 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_6887 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_6888 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_6889 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c762, cp_1 = c762_p_0, cp_0 = 0;c < c762 + 1;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6872);
												mem_vec_6872 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6873);
												mem_vec_6873 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6874);
												mem_vec_6874 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6875);
												mem_vec_6875 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6876);
												mem_vec_6876 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6877);
												mem_vec_6877 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6878);
												mem_vec_6878 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6879);
												mem_vec_6879 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6880);
												mem_vec_6880 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6881);
												mem_vec_6881 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6882);
												mem_vec_6882 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6883);
												mem_vec_6883 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6884);
												mem_vec_6884 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6885);
												mem_vec_6885 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6886);
												mem_vec_6886 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6887);
												mem_vec_6887 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6888);
												mem_vec_6888 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6889);
												mem_vec_6889 = vec_28;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6872);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6873);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6874);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6875);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6876);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6877);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6878);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6879);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6880);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6881);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6882);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6883);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_6884);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_6885);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_6886);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_6887);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_6888);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_6889);
								}
							}
						}
}
