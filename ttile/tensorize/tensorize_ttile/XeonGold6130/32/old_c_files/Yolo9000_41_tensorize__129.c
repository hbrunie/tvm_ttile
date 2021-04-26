
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (4, c); T (4, f); T (1, x);
  Lambda_apply y [((Iter 11), (Arg 10)); ((Iter 2), (Arg 13))]; T (4, x)]
*/
IND_TYPE c, cp_0, c57_p_0, cp_1, c57, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x76_p_0, x77_p_0, xp_1, x76_p_1, xp_2, x76, x77, y, yp_0;
IND_TYPE y38 = 0;
IND_TYPE x78 = 0;
IND_TYPE h38 = 0;
IND_TYPE w38 = 0;
IND_TYPE c58 = 0;
IND_TYPE f38 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,mem_vec_952 ,mem_vec_953 ,mem_vec_954 ,mem_vec_955 ,mem_vec_956 ,mem_vec_957 ,mem_vec_958 ,mem_vec_959 ,mem_vec_960 ,mem_vec_961 ,mem_vec_962 ,mem_vec_963 ,mem_vec_964 ,mem_vec_965 ,mem_vec_966 ,mem_vec_967 ,mem_vec_968 ,mem_vec_969 ,mem_vec_970 ,mem_vec_971 ,mem_vec_972 ,mem_vec_973 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 4) (136 / 34)
x77 = 0;
x77_p_0 = 0;
y = 0;
yp_0 = 0;
x76 = 0;
x76_p_1 = 0;
f = 0;
fp_0 = 0;
c57 = 0;
c57_p_0 = 0;
						for (w = w38, wp_0 = 0;w < w38 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
							// T (x, 34) (34 / 1)
							for (x = x76, xp_2 = x76_p_1, xp_1 = x76_p_0, xp_0 = 0;x < x76 + 34;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h38, hp_0 = 0;h < h38 + 3;h += 1, hp_0 += 1){
											mem_vec_928 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_929 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_930 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_931 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_932 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_933 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_934 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_935 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_936 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_937 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_938 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_939 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_940 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_941 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_942 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_943 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_944 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_945 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_946 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_947 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c57, cp_1 = c57_p_0, cp_0 = 0;c < c57 + 16;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_928);
												mem_vec_928 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_929);
												mem_vec_929 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_930);
												mem_vec_930 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_931);
												mem_vec_931 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_932);
												mem_vec_932 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_933);
												mem_vec_933 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_934);
												mem_vec_934 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_935);
												mem_vec_935 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_936);
												mem_vec_936 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_937);
												mem_vec_937 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_938);
												mem_vec_938 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_939);
												mem_vec_939 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_940);
												mem_vec_940 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_941);
												mem_vec_941 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_942);
												mem_vec_942 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_943);
												mem_vec_943 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_944);
												mem_vec_944 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_945);
												mem_vec_945 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_946);
												mem_vec_946 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_947);
												mem_vec_947 = vec_31;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_928);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_929);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_930);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_931);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_932);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_933);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_934);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_935);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_936);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_937);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_938);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_939);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_940);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_941);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_942);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_943);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_944);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_945);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_946);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_947);
								}
							}
						}
}
