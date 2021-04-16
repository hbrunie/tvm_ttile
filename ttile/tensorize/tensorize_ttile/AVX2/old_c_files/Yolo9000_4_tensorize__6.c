
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); U (8, y); U (3, h); T (32, c); Hoist_vars [c]; T (17, x);
  T (3, w); T (2, c); T (17, y); T (8, f); T (8, x); T (1, y); T (1, x)]
*/
IND_TYPE c, cp_0, c519_p_0, cp_1, c519, f, fp_0, w, wp_0, x, xp_0, x692_p_0, x693_p_0, xp_1, x692_p_1, xp_2, x692, x693, y, yp_0, y476_p_0, yp_1, y476;
IND_TYPE y477 = 0;
IND_TYPE x694 = 0;
IND_TYPE h = 0;
IND_TYPE w331 = 0;
IND_TYPE c520 = 0;
IND_TYPE f389 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_5976 ,mem_vec_5977 ,mem_vec_5978 ,mem_vec_5979 ,mem_vec_5980 ,mem_vec_5981 ,mem_vec_5982 ,mem_vec_5983 ,mem_vec_5984 ,mem_vec_5985 ,mem_vec_5986 ,mem_vec_5987 ,mem_vec_5988 ,mem_vec_5989 ,mem_vec_5990 ,mem_vec_5991 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
x693 = 0;
x693_p_0 = 0;
y476 = 0;
y476_p_0 = 0;
x692 = 0;
x692_p_1 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_1 = 0;
c519 = 0;
c519_p_0 = 0;
						for (w = w331, wp_0 = 0;w < w331 + 3;w += 1, wp_0 += 1){
							// y = 8, x = 17, h = 3, w = 1, c = 32, f = 16
							// T (x, 17) (17 / 1)
							for (x = x692, xp_2 = x692_p_1, xp_1 = x692_p_0, xp_0 = 0;x < x692 + 17;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5976 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_5977 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_5978 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_5979 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_5980 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_5981 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_5982 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_5983 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_5984 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_5985 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
										mem_vec_5986 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_5987 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
										mem_vec_5988 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_5989 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
										mem_vec_5990 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_5991 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
										// y = 8, x = 1, h = 3, w = 1, c = 32, f = 16
										// T (c, 32) (32 / 1)
										for (c = c519, cp_1 = c519_p_0, cp_0 = 0;c < c519 + 32;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5976);
											mem_vec_5976 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5977);
											mem_vec_5977 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);
											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_5978);
											mem_vec_5978 = vec_5;
											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_5979);
											mem_vec_5979 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);
											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_5980);
											mem_vec_5980 = vec_8;
											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_5981);
											mem_vec_5981 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);
											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_5982);
											mem_vec_5982 = vec_11;
											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_5983);
											mem_vec_5983 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5984);
											mem_vec_5984 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5985);
											mem_vec_5985 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);
											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_5986);
											mem_vec_5986 = vec_17;
											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_5987);
											mem_vec_5987 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);
											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_5988);
											mem_vec_5988 = vec_20;
											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_5989);
											mem_vec_5989 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);
											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_5990);
											mem_vec_5990 = vec_23;
											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_5991);
											mem_vec_5991 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_27 = _mm256_set1_ps(scal_8);
											vec_28 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_5976);
											mem_vec_5976 = vec_26;
											vec_30 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
											vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_5977);
											mem_vec_5977 = vec_29;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_32 = _mm256_set1_ps(scal_9);
											vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_5978);
											mem_vec_5978 = vec_31;
											vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_5979);
											mem_vec_5979 = vec_33;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_10);
											vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_5980);
											mem_vec_5980 = vec_34;
											vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_5981);
											mem_vec_5981 = vec_36;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_38 = _mm256_set1_ps(scal_11);
											vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_5982);
											mem_vec_5982 = vec_37;
											vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_5983);
											mem_vec_5983 = vec_39;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
											vec_41 = _mm256_set1_ps(scal_12);
											vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_5984);
											mem_vec_5984 = vec_40;
											vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_5985);
											mem_vec_5985 = vec_42;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);
											vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_5986);
											mem_vec_5986 = vec_43;
											vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_5987);
											mem_vec_5987 = vec_45;
											scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);
											vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_5988);
											mem_vec_5988 = vec_46;
											vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_5989);
											mem_vec_5989 = vec_48;
											scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);
											vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_5990);
											mem_vec_5990 = vec_49;
											vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_5991);
											mem_vec_5991 = vec_51;
											scal_16 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_53 = _mm256_set1_ps(scal_16);
											vec_54 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_5976);
											mem_vec_5976 = vec_52;
											vec_56 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
											vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_5977);
											mem_vec_5977 = vec_55;
											scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_58 = _mm256_set1_ps(scal_17);
											vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_5978);
											mem_vec_5978 = vec_57;
											vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_5979);
											mem_vec_5979 = vec_59;
											scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_61 = _mm256_set1_ps(scal_18);
											vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_5980);
											mem_vec_5980 = vec_60;
											vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_5981);
											mem_vec_5981 = vec_62;
											scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_64 = _mm256_set1_ps(scal_19);
											vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_5982);
											mem_vec_5982 = vec_63;
											vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_5983);
											mem_vec_5983 = vec_65;
											scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
											vec_67 = _mm256_set1_ps(scal_20);
											vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_5984);
											mem_vec_5984 = vec_66;
											vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_5985);
											mem_vec_5985 = vec_68;
											scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
											vec_70 = _mm256_set1_ps(scal_21);
											vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_5986);
											mem_vec_5986 = vec_69;
											vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_5987);
											mem_vec_5987 = vec_71;
											scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_22);
											vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_5988);
											mem_vec_5988 = vec_72;
											vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_5989);
											mem_vec_5989 = vec_74;
											scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
											vec_76 = _mm256_set1_ps(scal_23);
											vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_5990);
											mem_vec_5990 = vec_75;
											vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_5991);
											mem_vec_5991 = vec_77;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5976);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_5977);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5978);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_5979);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5980);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_5981);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5982);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_5983);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5984);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_5985);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5986);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_5987);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5988);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_5989);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5990);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_5991);
							}
						}
}
