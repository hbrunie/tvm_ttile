void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, c); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (64, f);
  T (8, c); T (1, f)]
*/
IND_TYPE c, cp_0, c254_p_0, c255_p_0, cp_1, c254_p_1, cp_2, c254, c255, f, fp_0, f250_p_0, fp_1, f250, w, wp_0, x, xp_0, x216_p_0, xp_1, x216, y, yp_0;
IND_TYPE y144 = 0;
IND_TYPE x217 = 0;
IND_TYPE h = 0;
IND_TYPE w144 = 0;
IND_TYPE c256 = 0;
IND_TYPE f251 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1922 ,mem_vec_1923 ,mem_vec_1924 ,mem_vec_1925 ,mem_vec_1926 ,mem_vec_1927 ,mem_vec_1928 ,mem_vec_1929 ,mem_vec_1930 ,mem_vec_1931 ,mem_vec_1932 ,mem_vec_1933 ,mem_vec_1934 ,mem_vec_1935 ,mem_vec_1936 ,mem_vec_1937 ,mem_vec_1938 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 1) (1024 / 1024)
f250 = 0;
f250_p_0 = 0;
c255 = 0;
c255_p_0 = 0;
f = 0;
fp_1 = 0;
y = 0;
yp_0 = 0;
x216 = 0;
x216_p_0 = 0;
c254 = 0;
c254_p_1 = 0;
							for (w = w144, wp_0 = 0;w < w144 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
								// T (x, 1) (1 / 1)
								for (x = x216, xp_1 = x216_p_0, xp_0 = 0;x < x216 + 1;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1930 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_1931 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_1932 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_1933 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_1934 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_1935 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_1936 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_1937 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_1938 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c254, cp_2 = c254_p_1, cp_1 = c254_p_0, cp_0 = 0;c < c254 + 32;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1930);
												mem_vec_1930 = vec_0;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);
												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1931);
												mem_vec_1931 = vec_3;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1932);
												mem_vec_1932 = vec_5;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);
												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1933);
												mem_vec_1933 = vec_7;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1934);
												mem_vec_1934 = vec_9;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_12 = _mm512_set1_ps(scal_5);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1935);
												mem_vec_1935 = vec_11;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_14 = _mm512_set1_ps(scal_6);
												vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_1936);
												mem_vec_1936 = vec_13;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_16 = _mm512_set1_ps(scal_7);
												vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_1937);
												mem_vec_1937 = vec_15;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_18 = _mm512_set1_ps(scal_8);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1938);
												mem_vec_1938 = vec_17;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_20 = _mm512_set1_ps(scal_9);
												vec_21 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_1930);
												mem_vec_1930 = vec_19;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_23 = _mm512_set1_ps(scal_10);
												vec_22 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_1931);
												mem_vec_1931 = vec_22;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_25 = _mm512_set1_ps(scal_11);
												vec_24 = _mm512_fmadd_ps(vec_25, vec_21, mem_vec_1932);
												mem_vec_1932 = vec_24;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_27 = _mm512_set1_ps(scal_12);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_21, mem_vec_1933);
												mem_vec_1933 = vec_26;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_29 = _mm512_set1_ps(scal_13);
												vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_1934);
												mem_vec_1934 = vec_28;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_31 = _mm512_set1_ps(scal_14);
												vec_30 = _mm512_fmadd_ps(vec_31, vec_21, mem_vec_1935);
												mem_vec_1935 = vec_30;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
												vec_33 = _mm512_set1_ps(scal_15);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_21, mem_vec_1936);
												mem_vec_1936 = vec_32;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
												vec_35 = _mm512_set1_ps(scal_16);
												vec_34 = _mm512_fmadd_ps(vec_35, vec_21, mem_vec_1937);
												mem_vec_1937 = vec_34;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
												vec_37 = _mm512_set1_ps(scal_17);
												vec_36 = _mm512_fmadd_ps(vec_37, vec_21, mem_vec_1938);
												mem_vec_1938 = vec_36;
												scal_18 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_39 = _mm512_set1_ps(scal_18);
												vec_40 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_1930);
												mem_vec_1930 = vec_38;
												scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_42 = _mm512_set1_ps(scal_19);
												vec_41 = _mm512_fmadd_ps(vec_42, vec_40, mem_vec_1931);
												mem_vec_1931 = vec_41;
												scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_44 = _mm512_set1_ps(scal_20);
												vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_1932);
												mem_vec_1932 = vec_43;
												scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_46 = _mm512_set1_ps(scal_21);
												vec_45 = _mm512_fmadd_ps(vec_46, vec_40, mem_vec_1933);
												mem_vec_1933 = vec_45;
												scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_48 = _mm512_set1_ps(scal_22);
												vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_1934);
												mem_vec_1934 = vec_47;
												scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_50 = _mm512_set1_ps(scal_23);
												vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_1935);
												mem_vec_1935 = vec_49;
												scal_24 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
												vec_52 = _mm512_set1_ps(scal_24);
												vec_51 = _mm512_fmadd_ps(vec_52, vec_40, mem_vec_1936);
												mem_vec_1936 = vec_51;
												scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
												vec_54 = _mm512_set1_ps(scal_25);
												vec_53 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_1937);
												mem_vec_1937 = vec_53;
												scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
												vec_56 = _mm512_set1_ps(scal_26);
												vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_1938);
												mem_vec_1938 = vec_55;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1930);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1931);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1932);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1933);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1934);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1935);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1936);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_1937);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_1938);
								}
							}
}
