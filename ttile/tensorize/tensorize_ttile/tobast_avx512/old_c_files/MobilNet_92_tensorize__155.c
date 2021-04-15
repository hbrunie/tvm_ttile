void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (1, c); T (16, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 1), (Arg 3))]; T (8, c);
  T (1, f); T (2, c)]
*/
IND_TYPE c, cp_0, c1308_p_0, c1309_p_0, c1310_p_0, cp_1, c1308_p_1, c1309_p_1, cp_2, c1308_p_2, cp_3, c1308, c1309, c1310, f, fp_0, f900_p_0, fp_1, f900, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y406 = 0;
IND_TYPE x552 = 0;
IND_TYPE h = 0;
IND_TYPE w432 = 0;
IND_TYPE c1311 = 0;
IND_TYPE f901 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_4796 ,mem_vec_4797 ,mem_vec_4798 ,mem_vec_4799 ,mem_vec_4800 ,mem_vec_4801 ,mem_vec_4802 ,mem_vec_4803 ,mem_vec_4804 ,mem_vec_4805 ,mem_vec_4806 ,mem_vec_4807 ,mem_vec_4808 ,mem_vec_4809 ,mem_vec_4810 ,mem_vec_4811 ,mem_vec_4812 ,mem_vec_4813 ,mem_vec_4814 ,mem_vec_4815 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 2) (1024 / 512)
c1310 = 0;
c1310_p_0 = 0;
f900 = 0;
f900_p_0 = 0;
c1309 = 0;
c1309_p_1 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_1 = 0;
c1308 = 0;
c1308_p_2 = 0;
							for (w = w432, wp_0 = 0;w < w432 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 64, f = 64
								// T (x, 7) (7 / 1)
								for (x = x552, xp_0 = 0;x < x552 + 7;x += 1, xp_0 += 1){
											mem_vec_4804 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_4805 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_4806 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_4807 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_4808 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_4809 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_4810 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_4811 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_4812 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_4813 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_4814 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
											mem_vec_4815 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 64
											// T (c, 64) (64 / 1)
											for (c = c1308, cp_3 = c1308_p_2, cp_2 = c1308_p_1, cp_1 = c1308_p_0, cp_0 = 0;c < c1308 + 64;c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4804);
												mem_vec_4804 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4805);
												mem_vec_4805 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4806);
												mem_vec_4806 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4807);
												mem_vec_4807 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4808);
												mem_vec_4808 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4809);
												mem_vec_4809 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4810);
												mem_vec_4810 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4811);
												mem_vec_4811 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4812);
												mem_vec_4812 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4813);
												mem_vec_4813 = vec_16;
												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4814);
												mem_vec_4814 = vec_17;
												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4815);
												mem_vec_4815 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_21 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_4804);
												mem_vec_4804 = vec_19;
												vec_23 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
												vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_4805);
												mem_vec_4805 = vec_22;
												vec_25 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 32]);
												vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_4806);
												mem_vec_4806 = vec_24;
												vec_27 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 48]);
												vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_4807);
												mem_vec_4807 = vec_26;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_29 = _mm512_set1_ps(scal_4);
												vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_4808);
												mem_vec_4808 = vec_28;
												vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_4809);
												mem_vec_4809 = vec_30;
												vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_4810);
												mem_vec_4810 = vec_31;
												vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_4811);
												mem_vec_4811 = vec_32;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_34 = _mm512_set1_ps(scal_5);
												vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_4812);
												mem_vec_4812 = vec_33;
												vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_4813);
												mem_vec_4813 = vec_35;
												vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_4814);
												mem_vec_4814 = vec_36;
												vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_4815);
												mem_vec_4815 = vec_37;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_40 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_4804);
												mem_vec_4804 = vec_38;
												vec_42 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
												vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_4805);
												mem_vec_4805 = vec_41;
												vec_44 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 32]);
												vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_4806);
												mem_vec_4806 = vec_43;
												vec_46 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 48]);
												vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_4807);
												mem_vec_4807 = vec_45;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_48 = _mm512_set1_ps(scal_7);
												vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_4808);
												mem_vec_4808 = vec_47;
												vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_4809);
												mem_vec_4809 = vec_49;
												vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_4810);
												mem_vec_4810 = vec_50;
												vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_4811);
												mem_vec_4811 = vec_51;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_53 = _mm512_set1_ps(scal_8);
												vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_4812);
												mem_vec_4812 = vec_52;
												vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_4813);
												mem_vec_4813 = vec_54;
												vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_4814);
												mem_vec_4814 = vec_55;
												vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_4815);
												mem_vec_4815 = vec_56;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4804);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4805);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_4806);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_4807);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4808);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4809);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_4810);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_4811);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4812);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4813);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_4814);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_4815);
								}
							}
}
