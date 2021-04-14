
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (28, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 11)); ((Iter 3), (Arg 15))]; T (2, f);
  T (64, c); T (2, x)]
*/
IND_TYPE c, cp_0, c622_p_0, cp_1, c622, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x680_p_0, x681_p_0, xp_1, x680_p_1, xp_2, x680, x681, y, yp_0;
IND_TYPE y372 = 0;
IND_TYPE x682 = 0;
IND_TYPE h346 = 0;
IND_TYPE w338 = 0;
IND_TYPE c623 = 0;
IND_TYPE f308 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5880 ,mem_vec_5881 ,mem_vec_5882 ,mem_vec_5883 ,mem_vec_5884 ,mem_vec_5885 ,mem_vec_5886 ,mem_vec_5887 ,mem_vec_5888 ,mem_vec_5889 ,mem_vec_5890 ,mem_vec_5891 ,mem_vec_5892 ,mem_vec_5893 ,mem_vec_5894 ,mem_vec_5895 ,mem_vec_5896 ,mem_vec_5897 ,mem_vec_5898 ,mem_vec_5899 ,mem_vec_5900 ,mem_vec_5901 ,mem_vec_5902 ,mem_vec_5903 ,mem_vec_5904 ,mem_vec_5905 ,mem_vec_5906 ,mem_vec_5907 ,mem_vec_5908 ,mem_vec_5909 ,mem_vec_5910 ,mem_vec_5911 ,mem_vec_5912 ,mem_vec_5913 ,mem_vec_5914 ,mem_vec_5915 ,mem_vec_5916 ,mem_vec_5917 ,mem_vec_5918 ,mem_vec_5919 ,mem_vec_5920 ,mem_vec_5921 ,mem_vec_5922 ,mem_vec_5923 ,mem_vec_5924 ,mem_vec_5925 ,mem_vec_5926 ,mem_vec_5927 ,mem_vec_5928 ,mem_vec_5929 ,mem_vec_5930 ,mem_vec_5931 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 2) (56 / 28)
x681 = 0;
x681_p_0 = 0;
c622 = 0;
c622_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x680 = 0;
x680_p_1 = 0;
						for (h = h346, hp_0 = 0;h < h346 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 1, f = 32
							// T (w, 3) (3 / 1)
							for (w = w338, wp_0 = 0;w < w338 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 28, h = 1, w = 1, c = 1, f = 32
								// T (x, 28) (28 / 1)
								for (x = x680, xp_2 = x680_p_1, xp_1 = x680_p_0, xp_0 = 0;x < x680 + 28;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5880 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_5881 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_5882 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5883 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_5884 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5885 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_5886 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5887 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_5888 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_5889 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_5890 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_5891 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_5892 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_5893 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_5894 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_5895 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_5896 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_5897 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_5898 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_5899 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_5900 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_5901 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c622, cp_1 = c622_p_0, cp_0 = 0;c < c622 + 1;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5880);
												mem_vec_5880 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5881);
												mem_vec_5881 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5882);
												mem_vec_5882 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5883);
												mem_vec_5883 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5884);
												mem_vec_5884 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5885);
												mem_vec_5885 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5886);
												mem_vec_5886 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5887);
												mem_vec_5887 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5888);
												mem_vec_5888 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5889);
												mem_vec_5889 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5890);
												mem_vec_5890 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5891);
												mem_vec_5891 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5892);
												mem_vec_5892 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5893);
												mem_vec_5893 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5894);
												mem_vec_5894 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5895);
												mem_vec_5895 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5896);
												mem_vec_5896 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5897);
												mem_vec_5897 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5898);
												mem_vec_5898 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5899);
												mem_vec_5899 = vec_31;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5900);
												mem_vec_5900 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5901);
												mem_vec_5901 = vec_34;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5880);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5881);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5882);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5883);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5884);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5885);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5886);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5887);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5888);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5889);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5890);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5891);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5892);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_5893);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5894);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_5895);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_5896);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_5897);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_5898);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_5899);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_5900);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_5901);
								}
							}
						}
}
