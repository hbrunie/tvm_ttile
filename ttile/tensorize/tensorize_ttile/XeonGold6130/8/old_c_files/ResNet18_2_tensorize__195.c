
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (3, w);
  T (56, x); Lambda_apply y [((Iter 4), (Arg 11)); ((Iter 1), (Arg 12))];
  T (1, c); T (4, f); T (1, y)]
*/
IND_TYPE c, cp_0, c276_p_0, cp_1, c276, f, fp_0, w, wp_0, x, xp_0, y, yp_0, y194_p_0, yp_1, y194;
IND_TYPE y195 = 0;
IND_TYPE x348 = 0;
IND_TYPE h = 0;
IND_TYPE w164 = 0;
IND_TYPE c277 = 0;
IND_TYPE f156 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2891 ,mem_vec_2892 ,mem_vec_2893 ,mem_vec_2894 ,mem_vec_2895 ,mem_vec_2896 ,mem_vec_2897 ,mem_vec_2898 ,mem_vec_2899 ,mem_vec_2900 ,mem_vec_2901 ,mem_vec_2902 ,mem_vec_2903 ,mem_vec_2904 ,mem_vec_2905 ,mem_vec_2906 ,mem_vec_2907 ,mem_vec_2908 ,mem_vec_2909 ,mem_vec_2910 ,mem_vec_2911 ,mem_vec_2912 ,mem_vec_2913 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (y, 1) (56 / 56)
y194 = 0;
y194_p_0 = 0;
f = 0;
fp_0 = 0;
		for (c276 = c277, c276_p_0 = 0;c276 < c277 + 64;c276 += 64, c276_p_0 += 64){
				for (y = y194, yp_1 = y194_p_0, yp_0 = 0;y < y194 + 44;y += 11, yp_1 += 11, yp_0 += 11){
					// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 16
					// T (x, 56) (56 / 1)
					for (x = x348, xp_0 = 0;x < x348 + 56;x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
						// T (w, 3) (3 / 1)
						for (w = w164, wp_0 = 0;w < w164 + 3;w += 1, wp_0 += 1){
									mem_vec_2891 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_2892 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_2893 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_2894 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_2895 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_2896 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_2897 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_2898 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
									mem_vec_2899 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
									mem_vec_2900 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
									mem_vec_2901 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
									// T (c, 64) (64 / 1)
									for (c = c276, cp_1 = c276_p_0, cp_0 = 0;c < c276 + 64;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2891);
										mem_vec_2891 = vec_0;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);
										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_2892);
										mem_vec_2892 = vec_3;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);
										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2893);
										mem_vec_2893 = vec_5;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);
										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_2894);
										mem_vec_2894 = vec_7;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2895);
										mem_vec_2895 = vec_9;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_12 = _mm512_set1_ps(scal_5);
										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2896);
										mem_vec_2896 = vec_11;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_14 = _mm512_set1_ps(scal_6);
										vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_2897);
										mem_vec_2897 = vec_13;
										scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
										vec_16 = _mm512_set1_ps(scal_7);
										vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_2898);
										mem_vec_2898 = vec_15;
										scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
										vec_18 = _mm512_set1_ps(scal_8);
										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2899);
										mem_vec_2899 = vec_17;
										scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
										vec_20 = _mm512_set1_ps(scal_9);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2900);
										mem_vec_2900 = vec_19;
										scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
										vec_22 = _mm512_set1_ps(scal_10);
										vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_2901);
										mem_vec_2901 = vec_21;
										scal_11 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
										vec_24 = _mm512_set1_ps(scal_11);
										vec_25 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
										vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_2891);
										mem_vec_2891 = vec_23;
										scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
										vec_27 = _mm512_set1_ps(scal_12);
										vec_26 = _mm512_fmadd_ps(vec_27, vec_25, mem_vec_2892);
										mem_vec_2892 = vec_26;
										scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_13);
										vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_2893);
										mem_vec_2893 = vec_28;
										scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
										vec_31 = _mm512_set1_ps(scal_14);
										vec_30 = _mm512_fmadd_ps(vec_31, vec_25, mem_vec_2894);
										mem_vec_2894 = vec_30;
										scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
										vec_33 = _mm512_set1_ps(scal_15);
										vec_32 = _mm512_fmadd_ps(vec_33, vec_25, mem_vec_2895);
										mem_vec_2895 = vec_32;
										scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_16);
										vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_2896);
										mem_vec_2896 = vec_34;
										scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
										vec_37 = _mm512_set1_ps(scal_17);
										vec_36 = _mm512_fmadd_ps(vec_37, vec_25, mem_vec_2897);
										mem_vec_2897 = vec_36;
										scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_18);
										vec_38 = _mm512_fmadd_ps(vec_39, vec_25, mem_vec_2898);
										mem_vec_2898 = vec_38;
										scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
										vec_41 = _mm512_set1_ps(scal_19);
										vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_2899);
										mem_vec_2899 = vec_40;
										scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 1) + c];
										vec_43 = _mm512_set1_ps(scal_20);
										vec_42 = _mm512_fmadd_ps(vec_43, vec_25, mem_vec_2900);
										mem_vec_2900 = vec_42;
										scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 1) + c];
										vec_45 = _mm512_set1_ps(scal_21);
										vec_44 = _mm512_fmadd_ps(vec_45, vec_25, mem_vec_2901);
										mem_vec_2901 = vec_44;
										scal_22 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
										vec_47 = _mm512_set1_ps(scal_22);
										vec_48 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
										vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_2891);
										mem_vec_2891 = vec_46;
										scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
										vec_50 = _mm512_set1_ps(scal_23);
										vec_49 = _mm512_fmadd_ps(vec_50, vec_48, mem_vec_2892);
										mem_vec_2892 = vec_49;
										scal_24 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
										vec_52 = _mm512_set1_ps(scal_24);
										vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_2893);
										mem_vec_2893 = vec_51;
										scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
										vec_54 = _mm512_set1_ps(scal_25);
										vec_53 = _mm512_fmadd_ps(vec_54, vec_48, mem_vec_2894);
										mem_vec_2894 = vec_53;
										scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
										vec_56 = _mm512_set1_ps(scal_26);
										vec_55 = _mm512_fmadd_ps(vec_56, vec_48, mem_vec_2895);
										mem_vec_2895 = vec_55;
										scal_27 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
										vec_58 = _mm512_set1_ps(scal_27);
										vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_2896);
										mem_vec_2896 = vec_57;
										scal_28 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
										vec_60 = _mm512_set1_ps(scal_28);
										vec_59 = _mm512_fmadd_ps(vec_60, vec_48, mem_vec_2897);
										mem_vec_2897 = vec_59;
										scal_29 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
										vec_62 = _mm512_set1_ps(scal_29);
										vec_61 = _mm512_fmadd_ps(vec_62, vec_48, mem_vec_2898);
										mem_vec_2898 = vec_61;
										scal_30 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
										vec_64 = _mm512_set1_ps(scal_30);
										vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_2899);
										mem_vec_2899 = vec_63;
										scal_31 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 2) + c];
										vec_66 = _mm512_set1_ps(scal_31);
										vec_65 = _mm512_fmadd_ps(vec_66, vec_48, mem_vec_2900);
										mem_vec_2900 = vec_65;
										scal_32 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 2) + c];
										vec_68 = _mm512_set1_ps(scal_32);
										vec_67 = _mm512_fmadd_ps(vec_68, vec_48, mem_vec_2901);
										mem_vec_2901 = vec_67;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2891);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2892);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2893);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2894);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2895);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2896);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2897);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2898);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_2899);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_2900);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_2901);
						}
					}
				}
				for (y = y194 + 44, yp_1 = y194_p_0, yp_0 = 0;y < y194 + 44 + 12;y += 12, yp_1 += 12, yp_0 += 12){
					// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 16
					// T (x, 56) (56 / 1)
					for (x = x348, xp_0 = 0;x < x348 + 56;x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
						// T (w, 3) (3 / 1)
						for (w = w164, wp_0 = 0;w < w164 + 3;w += 1, wp_0 += 1){
									mem_vec_2902 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_2903 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_2904 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_2905 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_2906 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_2907 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_2908 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_2909 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
									mem_vec_2910 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
									mem_vec_2911 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
									mem_vec_2912 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
									mem_vec_2913 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
									// T (c, 64) (64 / 1)
									for (c = c276, cp_1 = c276_p_0, cp_0 = 0;c < c276 + 64;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2902);
										mem_vec_2902 = vec_0;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);
										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_2903);
										mem_vec_2903 = vec_3;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);
										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2904);
										mem_vec_2904 = vec_5;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);
										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_2905);
										mem_vec_2905 = vec_7;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2906);
										mem_vec_2906 = vec_9;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_12 = _mm512_set1_ps(scal_5);
										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2907);
										mem_vec_2907 = vec_11;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_14 = _mm512_set1_ps(scal_6);
										vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_2908);
										mem_vec_2908 = vec_13;
										scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
										vec_16 = _mm512_set1_ps(scal_7);
										vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_2909);
										mem_vec_2909 = vec_15;
										scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
										vec_18 = _mm512_set1_ps(scal_8);
										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2910);
										mem_vec_2910 = vec_17;
										scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
										vec_20 = _mm512_set1_ps(scal_9);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2911);
										mem_vec_2911 = vec_19;
										scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
										vec_22 = _mm512_set1_ps(scal_10);
										vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_2912);
										mem_vec_2912 = vec_21;
										scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
										vec_24 = _mm512_set1_ps(scal_11);
										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2913);
										mem_vec_2913 = vec_23;
										scal_12 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
										vec_26 = _mm512_set1_ps(scal_12);
										vec_27 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
										vec_25 = _mm512_fmadd_ps(vec_26, vec_27, mem_vec_2902);
										mem_vec_2902 = vec_25;
										scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_13);
										vec_28 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_2903);
										mem_vec_2903 = vec_28;
										scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
										vec_31 = _mm512_set1_ps(scal_14);
										vec_30 = _mm512_fmadd_ps(vec_31, vec_27, mem_vec_2904);
										mem_vec_2904 = vec_30;
										scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
										vec_33 = _mm512_set1_ps(scal_15);
										vec_32 = _mm512_fmadd_ps(vec_33, vec_27, mem_vec_2905);
										mem_vec_2905 = vec_32;
										scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_16);
										vec_34 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_2906);
										mem_vec_2906 = vec_34;
										scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
										vec_37 = _mm512_set1_ps(scal_17);
										vec_36 = _mm512_fmadd_ps(vec_37, vec_27, mem_vec_2907);
										mem_vec_2907 = vec_36;
										scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_18);
										vec_38 = _mm512_fmadd_ps(vec_39, vec_27, mem_vec_2908);
										mem_vec_2908 = vec_38;
										scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
										vec_41 = _mm512_set1_ps(scal_19);
										vec_40 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_2909);
										mem_vec_2909 = vec_40;
										scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
										vec_43 = _mm512_set1_ps(scal_20);
										vec_42 = _mm512_fmadd_ps(vec_43, vec_27, mem_vec_2910);
										mem_vec_2910 = vec_42;
										scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 1) + c];
										vec_45 = _mm512_set1_ps(scal_21);
										vec_44 = _mm512_fmadd_ps(vec_45, vec_27, mem_vec_2911);
										mem_vec_2911 = vec_44;
										scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 1) + c];
										vec_47 = _mm512_set1_ps(scal_22);
										vec_46 = _mm512_fmadd_ps(vec_47, vec_27, mem_vec_2912);
										mem_vec_2912 = vec_46;
										scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_23);
										vec_48 = _mm512_fmadd_ps(vec_49, vec_27, mem_vec_2913);
										mem_vec_2913 = vec_48;
										scal_24 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
										vec_51 = _mm512_set1_ps(scal_24);
										vec_52 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
										vec_50 = _mm512_fmadd_ps(vec_51, vec_52, mem_vec_2902);
										mem_vec_2902 = vec_50;
										scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
										vec_54 = _mm512_set1_ps(scal_25);
										vec_53 = _mm512_fmadd_ps(vec_54, vec_52, mem_vec_2903);
										mem_vec_2903 = vec_53;
										scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
										vec_56 = _mm512_set1_ps(scal_26);
										vec_55 = _mm512_fmadd_ps(vec_56, vec_52, mem_vec_2904);
										mem_vec_2904 = vec_55;
										scal_27 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
										vec_58 = _mm512_set1_ps(scal_27);
										vec_57 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_2905);
										mem_vec_2905 = vec_57;
										scal_28 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
										vec_60 = _mm512_set1_ps(scal_28);
										vec_59 = _mm512_fmadd_ps(vec_60, vec_52, mem_vec_2906);
										mem_vec_2906 = vec_59;
										scal_29 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
										vec_62 = _mm512_set1_ps(scal_29);
										vec_61 = _mm512_fmadd_ps(vec_62, vec_52, mem_vec_2907);
										mem_vec_2907 = vec_61;
										scal_30 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
										vec_64 = _mm512_set1_ps(scal_30);
										vec_63 = _mm512_fmadd_ps(vec_64, vec_52, mem_vec_2908);
										mem_vec_2908 = vec_63;
										scal_31 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
										vec_66 = _mm512_set1_ps(scal_31);
										vec_65 = _mm512_fmadd_ps(vec_66, vec_52, mem_vec_2909);
										mem_vec_2909 = vec_65;
										scal_32 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
										vec_68 = _mm512_set1_ps(scal_32);
										vec_67 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_2910);
										mem_vec_2910 = vec_67;
										scal_33 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 2) + c];
										vec_70 = _mm512_set1_ps(scal_33);
										vec_69 = _mm512_fmadd_ps(vec_70, vec_52, mem_vec_2911);
										mem_vec_2911 = vec_69;
										scal_34 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 2) + c];
										vec_72 = _mm512_set1_ps(scal_34);
										vec_71 = _mm512_fmadd_ps(vec_72, vec_52, mem_vec_2912);
										mem_vec_2912 = vec_71;
										scal_35 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 2) + c];
										vec_74 = _mm512_set1_ps(scal_35);
										vec_73 = _mm512_fmadd_ps(vec_74, vec_52, mem_vec_2913);
										mem_vec_2913 = vec_73;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2902);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2903);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2904);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2905);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2906);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2907);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2908);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2909);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_2910);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_2911);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_2912);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_2913);
						}
					}
				}
		}
}
