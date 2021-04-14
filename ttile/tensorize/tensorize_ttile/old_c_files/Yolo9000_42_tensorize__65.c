void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 7), (Arg 13)); ((Iter 3), (Arg 15))]; T (4, f);
  T (2, c); T (68, x)]
*/
IND_TYPE c, cp_0, c858_p_0, cp_1, c858, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x1144_p_0, x1145_p_0, xp_1, x1144_p_1, xp_2, x1144, x1145, y, yp_0;
IND_TYPE y572 = 0;
IND_TYPE x1146 = 0;
IND_TYPE h572 = 0;
IND_TYPE w542 = 0;
IND_TYPE c859 = 0;
IND_TYPE f572 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11844 ,mem_vec_11845 ,mem_vec_11846 ,mem_vec_11847 ,mem_vec_11848 ,mem_vec_11849 ,mem_vec_11850 ,mem_vec_11851 ,mem_vec_11852 ,mem_vec_11853 ,mem_vec_11854 ,mem_vec_11855 ,mem_vec_11856 ,mem_vec_11857 ,mem_vec_11858 ,mem_vec_11859 ,mem_vec_11860 ,mem_vec_11861 ,mem_vec_11862 ,mem_vec_11863 ,mem_vec_11864 ,mem_vec_11865 ,mem_vec_11866 ,mem_vec_11867 ,mem_vec_11868 ,mem_vec_11869 ,mem_vec_11870 ,mem_vec_11871 ,mem_vec_11872 ,mem_vec_11873 ,mem_vec_11874 ,mem_vec_11875 ,mem_vec_11876 ,mem_vec_11877 ,mem_vec_11878 ,mem_vec_11879 ,mem_vec_11880 ,mem_vec_11881 ,mem_vec_11882 ,mem_vec_11883 ,mem_vec_11884 ,mem_vec_11885 ,mem_vec_11886 ,mem_vec_11887 ,mem_vec_11888 ,mem_vec_11889 ,mem_vec_11890 ,mem_vec_11891 ,mem_vec_11892 ,mem_vec_11893 ,mem_vec_11894 ,mem_vec_11895 ,mem_vec_11896 ,mem_vec_11897 ,mem_vec_11898 ,mem_vec_11899 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 68) (136 / 2)
x1145 = 0;
x1145_p_0 = 0;
c858 = 0;
c858_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1144 = 0;
x1144_p_1 = 0;
						for (h = h572, hp_0 = 0;h < h572 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w542, wp_0 = 0;w < w542 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1144, xp_2 = x1144_p_1, xp_1 = x1144_p_0, xp_0 = 0;x < x1144 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11870 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_11871 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_11872 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_11873 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_11874 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_11875 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_11876 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_11877 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_11878 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_11879 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_11880 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_11881 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_11882 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_11883 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_11884 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_11885 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_11886 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_11887 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_11888 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_11889 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_11890 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_11891 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											mem_vec_11892 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
											mem_vec_11893 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
											mem_vec_11894 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
											mem_vec_11895 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
											mem_vec_11896 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
											mem_vec_11897 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
											mem_vec_11898 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f]);
											mem_vec_11899 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c858, cp_1 = c858_p_0, cp_0 = 0;c < c858 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11870);
												mem_vec_11870 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11871);
												mem_vec_11871 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11872);
												mem_vec_11872 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11873);
												mem_vec_11873 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11874);
												mem_vec_11874 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11875);
												mem_vec_11875 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11876);
												mem_vec_11876 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11877);
												mem_vec_11877 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11878);
												mem_vec_11878 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11879);
												mem_vec_11879 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11880);
												mem_vec_11880 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11881);
												mem_vec_11881 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11882);
												mem_vec_11882 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11883);
												mem_vec_11883 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11884);
												mem_vec_11884 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11885);
												mem_vec_11885 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11886);
												mem_vec_11886 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11887);
												mem_vec_11887 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11888);
												mem_vec_11888 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11889);
												mem_vec_11889 = vec_31;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11890);
												mem_vec_11890 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11891);
												mem_vec_11891 = vec_34;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);
												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_11892);
												mem_vec_11892 = vec_35;
												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_11893);
												mem_vec_11893 = vec_37;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_11894);
												mem_vec_11894 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_11895);
												mem_vec_11895 = vec_40;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);
												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_11896);
												mem_vec_11896 = vec_41;
												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_11897);
												mem_vec_11897 = vec_43;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 14 + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);
												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_11898);
												mem_vec_11898 = vec_44;
												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_11899);
												mem_vec_11899 = vec_46;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_11870);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_11871);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_11872);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_11873);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_11874);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_11875);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_11876);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_11877);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_11878);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_11879);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_11880);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_11881);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_11882);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_11883);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_11884);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_11885);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_11886);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_11887);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_11888);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_11889);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_11890);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_11891);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_11892);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_11893);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_11894);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_11895);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_11896);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_11897);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f], mem_vec_11898);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f + 16], mem_vec_11899);
								}
							}
						}
}
