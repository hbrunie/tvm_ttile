void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 9)); ((Iter 1), (Arg 11))]; T (2, f);
  T (1, c); T (8, x)]
*/
IND_TYPE c, cp_0, c422_p_0, cp_1, c422, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x418_p_0, x419_p_0, xp_1, x418_p_1, xp_2, x418, x419, y, yp_0;
IND_TYPE y240 = 0;
IND_TYPE x420 = 0;
IND_TYPE h204 = 0;
IND_TYPE w216 = 0;
IND_TYPE c423 = 0;
IND_TYPE f178 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2912 ,mem_vec_2913 ,mem_vec_2914 ,mem_vec_2915 ,mem_vec_2916 ,mem_vec_2917 ,mem_vec_2918 ,mem_vec_2919 ,mem_vec_2920 ,mem_vec_2921 ,mem_vec_2922 ,mem_vec_2923 ,mem_vec_2924 ,mem_vec_2925 ,mem_vec_2926 ,mem_vec_2927 ,mem_vec_2928 ,mem_vec_2929 ,mem_vec_2930 ,mem_vec_2931 ,mem_vec_2932 ,mem_vec_2933 ,mem_vec_2934 ,mem_vec_2935 ,mem_vec_2936 ,mem_vec_2937 ,mem_vec_2938 ,mem_vec_2939 ,mem_vec_2940 ,mem_vec_2941 ,mem_vec_2942 ,mem_vec_2943 ,mem_vec_2944 ,mem_vec_2945 ,mem_vec_2946 ,mem_vec_2947 ,mem_vec_2948 ,mem_vec_2949 ,mem_vec_2950 ,mem_vec_2951 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 8) (56 / 7)
x419 = 0;
x419_p_0 = 0;
c422 = 0;
c422_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x418 = 0;
x418_p_1 = 0;
						for (h = h204, hp_0 = 0;h < h204 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w216, wp_0 = 0;w < w216 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 1, c = 64, f = 32
								// T (x, 7) (7 / 1)
								for (x = x418, xp_2 = x418_p_1, xp_1 = x418_p_0, xp_0 = 0;x < x418 + 7;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2930 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_2931 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_2932 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_2933 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_2934 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_2935 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_2936 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_2937 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_2938 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_2939 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_2940 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_2941 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_2942 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_2943 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_2944 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_2945 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_2946 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_2947 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_2948 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_2949 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_2950 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_2951 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c422, cp_1 = c422_p_0, cp_0 = 0;c < c422 + 64;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2930);
												mem_vec_2930 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2931);
												mem_vec_2931 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2932);
												mem_vec_2932 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2933);
												mem_vec_2933 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2934);
												mem_vec_2934 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2935);
												mem_vec_2935 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2936);
												mem_vec_2936 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2937);
												mem_vec_2937 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2938);
												mem_vec_2938 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2939);
												mem_vec_2939 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2940);
												mem_vec_2940 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2941);
												mem_vec_2941 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2942);
												mem_vec_2942 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2943);
												mem_vec_2943 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2944);
												mem_vec_2944 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2945);
												mem_vec_2945 = vec_25;
												scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2946);
												mem_vec_2946 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2947);
												mem_vec_2947 = vec_28;
												scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2948);
												mem_vec_2948 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2949);
												mem_vec_2949 = vec_31;
												scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2950);
												mem_vec_2950 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2951);
												mem_vec_2951 = vec_34;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2930);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2931);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2932);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2933);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2934);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2935);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2936);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2937);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2938);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2939);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2940);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_2941);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2942);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_2943);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2944);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_2945);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_2946);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_2947);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_2948);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_2949);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_2950);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_2951);
								}
							}
						}
}
