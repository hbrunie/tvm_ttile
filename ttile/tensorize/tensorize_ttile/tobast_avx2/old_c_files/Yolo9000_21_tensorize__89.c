
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (8, x);
  T (3, w); T (8, y); T (1, f); T (32, c); T (17, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (2, f);
  T (2, x)]
*/
IND_TYPE c, cp_0, c834_p_0, cp_1, c834, f, fp_0, f706_p_0, fp_1, f706, w, wp_0, x, xp_0, x1112_p_0, x1113_p_0, xp_1, x1112_p_1, xp_2, x1112, x1113, y, yp_0, y834_p_0, yp_1, y834;
IND_TYPE y835 = 0;
IND_TYPE x1114 = 0;
IND_TYPE h = 0;
IND_TYPE w506 = 0;
IND_TYPE c835 = 0;
IND_TYPE f707 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8056 ,mem_vec_8057 ,mem_vec_8058 ,mem_vec_8059 ,mem_vec_8060 ,mem_vec_8061 ,mem_vec_8062 ,mem_vec_8063 ,mem_vec_8064 ,mem_vec_8065 ,mem_vec_8066 ,mem_vec_8067 ,mem_vec_8068 ,mem_vec_8069 ,mem_vec_8070 ,mem_vec_8071 ,mem_vec_8072 ,mem_vec_8073 ,mem_vec_8074 ,mem_vec_8075 ,mem_vec_8076 ,mem_vec_8077 ,mem_vec_8078 ,mem_vec_8079 ,mem_vec_8080 ,mem_vec_8081 ,mem_vec_8082 ,mem_vec_8083 ,mem_vec_8084 ,mem_vec_8085 ,mem_vec_8086 ,mem_vec_8087 ,mem_vec_8088 ,mem_vec_8089 ,mem_vec_8090 ,mem_vec_8091 ,mem_vec_8092 ,mem_vec_8093 ,mem_vec_8094 ,mem_vec_8095 ,mem_vec_8096 ,mem_vec_8097 ,mem_vec_8098 ,mem_vec_8099 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
x1113 = 0;
x1113_p_0 = 0;
f706 = 0;
f706_p_0 = 0;
y834 = 0;
y834_p_0 = 0;
x1112 = 0;
x1112_p_1 = 0;
c834 = 0;
c834_p_0 = 0;
f = 0;
fp_1 = 0;
y = 0;
yp_1 = 0;
								for (w = w506, wp_0 = 0;w < w506 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 8, h = 3, w = 1, c = 1, f = 32
									// T (x, 8) (8 / 1)
									for (x = x1112, xp_2 = x1112_p_1, xp_1 = x1112_p_0, xp_0 = 0;x < x1112 + 8;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8056 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_8057 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_8058 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_8059 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_8060 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_8061 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_8062 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_8063 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_8064 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_8065 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_8066 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_8067 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_8068 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_8069 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_8070 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_8071 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c834, cp_1 = c834_p_0, cp_0 = 0;c < c834 + 1;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8056);
													mem_vec_8056 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8057);
													mem_vec_8057 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8058);
													mem_vec_8058 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8059);
													mem_vec_8059 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8060);
													mem_vec_8060 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8061);
													mem_vec_8061 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8062);
													mem_vec_8062 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8063);
													mem_vec_8063 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8064);
													mem_vec_8064 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8065);
													mem_vec_8065 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8066);
													mem_vec_8066 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8067);
													mem_vec_8067 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8068);
													mem_vec_8068 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8069);
													mem_vec_8069 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8070);
													mem_vec_8070 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8071);
													mem_vec_8071 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_8056);
													mem_vec_8056 = vec_24;
													vec_28 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_8057);
													mem_vec_8057 = vec_27;
													vec_30 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_8058);
													mem_vec_8058 = vec_29;
													vec_32 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 24]);
													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_8059);
													mem_vec_8059 = vec_31;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
													vec_34 = _mm256_set1_ps(scal_5);
													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_8060);
													mem_vec_8060 = vec_33;
													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_8061);
													mem_vec_8061 = vec_35;
													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_8062);
													mem_vec_8062 = vec_36;
													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_8063);
													mem_vec_8063 = vec_37;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);
													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_8064);
													mem_vec_8064 = vec_38;
													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_8065);
													mem_vec_8065 = vec_40;
													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_8066);
													mem_vec_8066 = vec_41;
													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_8067);
													mem_vec_8067 = vec_42;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);
													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_8068);
													mem_vec_8068 = vec_43;
													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_8069);
													mem_vec_8069 = vec_45;
													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_8070);
													mem_vec_8070 = vec_46;
													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_8071);
													mem_vec_8071 = vec_47;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_8056);
													mem_vec_8056 = vec_48;
													vec_52 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_8057);
													mem_vec_8057 = vec_51;
													vec_54 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_8058);
													mem_vec_8058 = vec_53;
													vec_56 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 24]);
													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_8059);
													mem_vec_8059 = vec_55;
													scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_9);
													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_8060);
													mem_vec_8060 = vec_57;
													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_8061);
													mem_vec_8061 = vec_59;
													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_8062);
													mem_vec_8062 = vec_60;
													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_8063);
													mem_vec_8063 = vec_61;
													scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
													vec_63 = _mm256_set1_ps(scal_10);
													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_8064);
													mem_vec_8064 = vec_62;
													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_8065);
													mem_vec_8065 = vec_64;
													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_8066);
													mem_vec_8066 = vec_65;
													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_8067);
													mem_vec_8067 = vec_66;
													scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);
													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_8068);
													mem_vec_8068 = vec_67;
													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_8069);
													mem_vec_8069 = vec_69;
													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_8070);
													mem_vec_8070 = vec_70;
													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_8071);
													mem_vec_8071 = vec_71;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8056);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_8057);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_8058);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_8059);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8060);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_8061);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_8062);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_8063);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_8064);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_8065);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_8066);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_8067);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_8068);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_8069);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_8070);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_8071);
									}
								}
}
