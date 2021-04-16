
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (17, x); T (2, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (64, f);
  T (1, c); T (1, y); T (8, c)]
*/
IND_TYPE c, cp_0, c233_p_0, c234_p_0, c235_p_0, cp_1, c233_p_1, c234_p_1, cp_2, c233_p_2, cp_3, c233, c234, c235, f, fp_0, w, wp_0, x, xp_0, y, yp_0, y153_p_0, yp_1, y153;
IND_TYPE y154 = 0;
IND_TYPE x146 = 0;
IND_TYPE h = 0;
IND_TYPE w124 = 0;
IND_TYPE c236 = 0;
IND_TYPE f278 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_2898 ,mem_vec_2899 ,mem_vec_2900 ,mem_vec_2901 ,mem_vec_2902 ,mem_vec_2903 ,mem_vec_2904 ,mem_vec_2905 ,mem_vec_2906 ,mem_vec_2907 ,mem_vec_2908 ,mem_vec_2909 ,mem_vec_2910 ,mem_vec_2911 ,mem_vec_2912 ,mem_vec_2913 ,mem_vec_2914 ,mem_vec_2915 ,mem_vec_2916 ,mem_vec_2917 ,mem_vec_2918 ,mem_vec_2919 ,mem_vec_2920 ,mem_vec_2921 ,mem_vec_2922 ,mem_vec_2923 ,mem_vec_2924 ,mem_vec_2925 ,mem_vec_2926 ,mem_vec_2927 ,mem_vec_2928 ,mem_vec_2929 ,mem_vec_2930 ,mem_vec_2931 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 8) (512 / 64)
c235 = 0;
c235_p_0 = 0;
y153 = 0;
y153_p_0 = 0;
c234 = 0;
c234_p_1 = 0;
			for (f = f278, fp_0 = 0;f < f278 + 1024;f += 16, fp_0 += 16){
					for (y = y153, yp_1 = y153_p_0, yp_0 = 0;y < y153 + 8;y += 8, yp_1 += 8, yp_0 += 8){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
						// T (c, 2) (64 / 32)
						for (c233 = c234, c233_p_2 = c234_p_1, c233_p_1 = c234_p_0, c233_p_0 = 0;c233 < c234 + 64;c233 += 32, c233_p_2 += 32, c233_p_1 += 32, c233_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 16
							// T (x, 17) (17 / 1)
							for (x = x146, xp_0 = 0;x < x146 + 17;x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
								// T (w, 3) (3 / 1)
								for (w = w124, wp_0 = 0;w < w124 + 3;w += 1, wp_0 += 1){
											mem_vec_2898 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_2899 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_2900 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_2901 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_2902 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_2903 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_2904 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_2905 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_2906 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_2907 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_2908 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_2909 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
											mem_vec_2910 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_2911 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
											mem_vec_2912 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_2913 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c233, cp_3 = c233_p_2, cp_2 = c233_p_1, cp_1 = c233_p_0, cp_0 = 0;c < c233 + 32;c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2898);
												mem_vec_2898 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2899);
												mem_vec_2899 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);
												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_2900);
												mem_vec_2900 = vec_5;
												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_2901);
												mem_vec_2901 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);
												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_2902);
												mem_vec_2902 = vec_8;
												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_2903);
												mem_vec_2903 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);
												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_2904);
												mem_vec_2904 = vec_11;
												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_2905);
												mem_vec_2905 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2906);
												mem_vec_2906 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2907);
												mem_vec_2907 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);
												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_2908);
												mem_vec_2908 = vec_17;
												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_2909);
												mem_vec_2909 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);
												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_2910);
												mem_vec_2910 = vec_20;
												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_2911);
												mem_vec_2911 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);
												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_2912);
												mem_vec_2912 = vec_23;
												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_2913);
												mem_vec_2913 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_28 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_2898);
												mem_vec_2898 = vec_26;
												vec_30 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
												vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_2899);
												mem_vec_2899 = vec_29;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_32 = _mm256_set1_ps(scal_9);
												vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_2900);
												mem_vec_2900 = vec_31;
												vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_2901);
												mem_vec_2901 = vec_33;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);
												vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_2902);
												mem_vec_2902 = vec_34;
												vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_2903);
												mem_vec_2903 = vec_36;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);
												vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_2904);
												mem_vec_2904 = vec_37;
												vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_2905);
												mem_vec_2905 = vec_39;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);
												vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_2906);
												mem_vec_2906 = vec_40;
												vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_2907);
												mem_vec_2907 = vec_42;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_2908);
												mem_vec_2908 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_2909);
												mem_vec_2909 = vec_45;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);
												vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_2910);
												mem_vec_2910 = vec_46;
												vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_2911);
												mem_vec_2911 = vec_48;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);
												vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_2912);
												mem_vec_2912 = vec_49;
												vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_2913);
												mem_vec_2913 = vec_51;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_54 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_2898);
												mem_vec_2898 = vec_52;
												vec_56 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
												vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_2899);
												mem_vec_2899 = vec_55;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_17);
												vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_2900);
												mem_vec_2900 = vec_57;
												vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_2901);
												mem_vec_2901 = vec_59;
												scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_61 = _mm256_set1_ps(scal_18);
												vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_2902);
												mem_vec_2902 = vec_60;
												vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_2903);
												mem_vec_2903 = vec_62;
												scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);
												vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_2904);
												mem_vec_2904 = vec_63;
												vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_2905);
												mem_vec_2905 = vec_65;
												scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);
												vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_2906);
												mem_vec_2906 = vec_66;
												vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_2907);
												mem_vec_2907 = vec_68;
												scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);
												vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_2908);
												mem_vec_2908 = vec_69;
												vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_2909);
												mem_vec_2909 = vec_71;
												scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);
												vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_2910);
												mem_vec_2910 = vec_72;
												vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_2911);
												mem_vec_2911 = vec_74;
												scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);
												vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_2912);
												mem_vec_2912 = vec_75;
												vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_2913);
												mem_vec_2913 = vec_77;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2898);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_2899);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2900);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_2901);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2902);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_2903);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2904);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_2905);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2906);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_2907);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2908);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_2909);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2910);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_2911);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2912);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_2913);
								}
							}
						}
					}
					for (y = y153 + 8, yp_1 = y153_p_0, yp_0 = 0;y < y153 + 8 + 9;y += 9, yp_1 += 9, yp_0 += 9){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
						// T (c, 2) (64 / 32)
						for (c233 = c234, c233_p_2 = c234_p_1, c233_p_1 = c234_p_0, c233_p_0 = 0;c233 < c234 + 64;c233 += 32, c233_p_2 += 32, c233_p_1 += 32, c233_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 16
							// T (x, 17) (17 / 1)
							for (x = x146, xp_0 = 0;x < x146 + 17;x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
								// T (w, 3) (3 / 1)
								for (w = w124, wp_0 = 0;w < w124 + 3;w += 1, wp_0 += 1){
											mem_vec_2914 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_2915 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_2916 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_2917 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_2918 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_2919 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_2920 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_2921 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_2922 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_2923 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_2924 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_2925 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
											mem_vec_2926 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_2927 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
											mem_vec_2928 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_2929 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
											mem_vec_2930 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_2931 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c233, cp_3 = c233_p_2, cp_2 = c233_p_1, cp_1 = c233_p_0, cp_0 = 0;c < c233 + 32;c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2914);
												mem_vec_2914 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2915);
												mem_vec_2915 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);
												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_2916);
												mem_vec_2916 = vec_5;
												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_2917);
												mem_vec_2917 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);
												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_2918);
												mem_vec_2918 = vec_8;
												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_2919);
												mem_vec_2919 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);
												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_2920);
												mem_vec_2920 = vec_11;
												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_2921);
												mem_vec_2921 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2922);
												mem_vec_2922 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2923);
												mem_vec_2923 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);
												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_2924);
												mem_vec_2924 = vec_17;
												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_2925);
												mem_vec_2925 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);
												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_2926);
												mem_vec_2926 = vec_20;
												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_2927);
												mem_vec_2927 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);
												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_2928);
												mem_vec_2928 = vec_23;
												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_2929);
												mem_vec_2929 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_2930);
												mem_vec_2930 = vec_26;
												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_2931);
												mem_vec_2931 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_31 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_2914);
												mem_vec_2914 = vec_29;
												vec_33 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_2915);
												mem_vec_2915 = vec_32;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);
												vec_34 = _mm256_fmadd_ps(vec_35, vec_31, mem_vec_2916);
												mem_vec_2916 = vec_34;
												vec_36 = _mm256_fmadd_ps(vec_35, vec_33, mem_vec_2917);
												mem_vec_2917 = vec_36;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);
												vec_37 = _mm256_fmadd_ps(vec_38, vec_31, mem_vec_2918);
												mem_vec_2918 = vec_37;
												vec_39 = _mm256_fmadd_ps(vec_38, vec_33, mem_vec_2919);
												mem_vec_2919 = vec_39;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);
												vec_40 = _mm256_fmadd_ps(vec_41, vec_31, mem_vec_2920);
												mem_vec_2920 = vec_40;
												vec_42 = _mm256_fmadd_ps(vec_41, vec_33, mem_vec_2921);
												mem_vec_2921 = vec_42;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_2922);
												mem_vec_2922 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_2923);
												mem_vec_2923 = vec_45;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);
												vec_46 = _mm256_fmadd_ps(vec_47, vec_31, mem_vec_2924);
												mem_vec_2924 = vec_46;
												vec_48 = _mm256_fmadd_ps(vec_47, vec_33, mem_vec_2925);
												mem_vec_2925 = vec_48;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);
												vec_49 = _mm256_fmadd_ps(vec_50, vec_31, mem_vec_2926);
												mem_vec_2926 = vec_49;
												vec_51 = _mm256_fmadd_ps(vec_50, vec_33, mem_vec_2927);
												mem_vec_2927 = vec_51;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_52 = _mm256_fmadd_ps(vec_53, vec_31, mem_vec_2928);
												mem_vec_2928 = vec_52;
												vec_54 = _mm256_fmadd_ps(vec_53, vec_33, mem_vec_2929);
												mem_vec_2929 = vec_54;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);
												vec_55 = _mm256_fmadd_ps(vec_56, vec_31, mem_vec_2930);
												mem_vec_2930 = vec_55;
												vec_57 = _mm256_fmadd_ps(vec_56, vec_33, mem_vec_2931);
												mem_vec_2931 = vec_57;
												scal_18 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_60 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_2914);
												mem_vec_2914 = vec_58;
												vec_62 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_2915);
												mem_vec_2915 = vec_61;
												scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);
												vec_63 = _mm256_fmadd_ps(vec_64, vec_60, mem_vec_2916);
												mem_vec_2916 = vec_63;
												vec_65 = _mm256_fmadd_ps(vec_64, vec_62, mem_vec_2917);
												mem_vec_2917 = vec_65;
												scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);
												vec_66 = _mm256_fmadd_ps(vec_67, vec_60, mem_vec_2918);
												mem_vec_2918 = vec_66;
												vec_68 = _mm256_fmadd_ps(vec_67, vec_62, mem_vec_2919);
												mem_vec_2919 = vec_68;
												scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);
												vec_69 = _mm256_fmadd_ps(vec_70, vec_60, mem_vec_2920);
												mem_vec_2920 = vec_69;
												vec_71 = _mm256_fmadd_ps(vec_70, vec_62, mem_vec_2921);
												mem_vec_2921 = vec_71;
												scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);
												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_2922);
												mem_vec_2922 = vec_72;
												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_2923);
												mem_vec_2923 = vec_74;
												scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);
												vec_75 = _mm256_fmadd_ps(vec_76, vec_60, mem_vec_2924);
												mem_vec_2924 = vec_75;
												vec_77 = _mm256_fmadd_ps(vec_76, vec_62, mem_vec_2925);
												mem_vec_2925 = vec_77;
												scal_24 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);
												vec_78 = _mm256_fmadd_ps(vec_79, vec_60, mem_vec_2926);
												mem_vec_2926 = vec_78;
												vec_80 = _mm256_fmadd_ps(vec_79, vec_62, mem_vec_2927);
												mem_vec_2927 = vec_80;
												scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);
												vec_81 = _mm256_fmadd_ps(vec_82, vec_60, mem_vec_2928);
												mem_vec_2928 = vec_81;
												vec_83 = _mm256_fmadd_ps(vec_82, vec_62, mem_vec_2929);
												mem_vec_2929 = vec_83;
												scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);
												vec_84 = _mm256_fmadd_ps(vec_85, vec_60, mem_vec_2930);
												mem_vec_2930 = vec_84;
												vec_86 = _mm256_fmadd_ps(vec_85, vec_62, mem_vec_2931);
												mem_vec_2931 = vec_86;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2914);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_2915);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2916);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_2917);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2918);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_2919);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2920);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_2921);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2922);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_2923);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2924);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_2925);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2926);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_2927);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2928);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_2929);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_2930);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8], mem_vec_2931);
								}
							}
						}
					}
			}
}
