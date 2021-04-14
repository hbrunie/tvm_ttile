void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (17, x);
  T (3, w); T (4, f); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (1, f);
  T (8, c); T (2, f)]
*/
IND_TYPE c, cp_0, c1028_p_0, cp_1, c1028, f, fp_0, f1064_p_0, f1065_p_0, fp_1, f1064_p_1, fp_2, f1064, f1065, w, wp_0, x, xp_0, x1028_p_0, xp_1, x1028, y, yp_0;
IND_TYPE y624 = 0;
IND_TYPE x1029 = 0;
IND_TYPE h = 0;
IND_TYPE w624 = 0;
IND_TYPE c1029 = 0;
IND_TYPE f1066 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11910 ,mem_vec_11911 ,mem_vec_11912 ,mem_vec_11913 ,mem_vec_11914 ,mem_vec_11915 ,mem_vec_11916 ,mem_vec_11917 ,mem_vec_11918 ,mem_vec_11919 ,mem_vec_11920 ,mem_vec_11921 ,mem_vec_11922 ,mem_vec_11923 ,mem_vec_11924 ,mem_vec_11925 ,mem_vec_11926 ,mem_vec_11927 ,mem_vec_11928 ,mem_vec_11929 ,mem_vec_11930 ,mem_vec_11931 ,mem_vec_11932 ,mem_vec_11933 ,mem_vec_11934 ,mem_vec_11935 ,mem_vec_11936 ,mem_vec_11937 ,mem_vec_11938 ,mem_vec_11939 ,mem_vec_11940 ,mem_vec_11941 ,mem_vec_11942 ,mem_vec_11943 ,mem_vec_11944 ,mem_vec_11945 ,mem_vec_11946 ,mem_vec_11947 ,mem_vec_11948 ,mem_vec_11949 ,mem_vec_11950 ,mem_vec_11951 ,mem_vec_11952 ,mem_vec_11953 ,mem_vec_11954 ,mem_vec_11955 ,mem_vec_11956 ,mem_vec_11957 ,mem_vec_11958 ,mem_vec_11959 ,mem_vec_11960 ,mem_vec_11961 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
f1065 = 0;
f1065_p_0 = 0;
c1028 = 0;
c1028_p_0 = 0;
f1064 = 0;
f1064_p_1 = 0;
y = 0;
yp_0 = 0;
x1028 = 0;
x1028_p_0 = 0;
f = 0;
fp_2 = 0;
							for (w = w624, wp_0 = 0;w < w624 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 64
								// T (x, 17) (17 / 1)
								for (x = x1028, xp_1 = x1028_p_0, xp_0 = 0;x < x1028 + 17;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11934 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_11935 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_11936 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_11937 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_11938 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_11939 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_11940 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_11941 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_11942 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_11943 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_11944 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
											mem_vec_11945 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
											mem_vec_11946 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_11947 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_11948 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
											mem_vec_11949 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
											mem_vec_11950 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_11951 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_11952 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
											mem_vec_11953 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
											mem_vec_11954 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_11955 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_11956 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
											mem_vec_11957 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
											mem_vec_11958 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_11959 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_11960 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
											mem_vec_11961 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 64
											// T (c, 32) (32 / 1)
											for (c = c1028, cp_1 = c1028_p_0, cp_0 = 0;c < c1028 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11934);
												mem_vec_11934 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11935);
												mem_vec_11935 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11936);
												mem_vec_11936 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11937);
												mem_vec_11937 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11938);
												mem_vec_11938 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11939);
												mem_vec_11939 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11940);
												mem_vec_11940 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11941);
												mem_vec_11941 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11942);
												mem_vec_11942 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11943);
												mem_vec_11943 = vec_16;
												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11944);
												mem_vec_11944 = vec_17;
												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11945);
												mem_vec_11945 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11946);
												mem_vec_11946 = vec_19;
												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11947);
												mem_vec_11947 = vec_21;
												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11948);
												mem_vec_11948 = vec_22;
												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11949);
												mem_vec_11949 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11950);
												mem_vec_11950 = vec_24;
												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11951);
												mem_vec_11951 = vec_26;
												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11952);
												mem_vec_11952 = vec_27;
												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11953);
												mem_vec_11953 = vec_28;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11954);
												mem_vec_11954 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11955);
												mem_vec_11955 = vec_31;
												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_11956);
												mem_vec_11956 = vec_32;
												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_11957);
												mem_vec_11957 = vec_33;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_11958);
												mem_vec_11958 = vec_34;
												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_11959);
												mem_vec_11959 = vec_36;
												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_11960);
												mem_vec_11960 = vec_37;
												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_11961);
												mem_vec_11961 = vec_38;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_40 = _mm512_set1_ps(scal_7);
												vec_41 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_11934);
												mem_vec_11934 = vec_39;
												vec_43 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
												vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_11935);
												mem_vec_11935 = vec_42;
												vec_45 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 32]);
												vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_11936);
												mem_vec_11936 = vec_44;
												vec_47 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 48]);
												vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_11937);
												mem_vec_11937 = vec_46;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_11938);
												mem_vec_11938 = vec_48;
												vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_11939);
												mem_vec_11939 = vec_50;
												vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_11940);
												mem_vec_11940 = vec_51;
												vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_11941);
												mem_vec_11941 = vec_52;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_54 = _mm512_set1_ps(scal_9);
												vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_11942);
												mem_vec_11942 = vec_53;
												vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_11943);
												mem_vec_11943 = vec_55;
												vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_11944);
												mem_vec_11944 = vec_56;
												vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_11945);
												mem_vec_11945 = vec_57;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_59 = _mm512_set1_ps(scal_10);
												vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_11946);
												mem_vec_11946 = vec_58;
												vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_11947);
												mem_vec_11947 = vec_60;
												vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_11948);
												mem_vec_11948 = vec_61;
												vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_11949);
												mem_vec_11949 = vec_62;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_64 = _mm512_set1_ps(scal_11);
												vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_11950);
												mem_vec_11950 = vec_63;
												vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_11951);
												mem_vec_11951 = vec_65;
												vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_11952);
												mem_vec_11952 = vec_66;
												vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_11953);
												mem_vec_11953 = vec_67;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_11954);
												mem_vec_11954 = vec_68;
												vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_11955);
												mem_vec_11955 = vec_70;
												vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_11956);
												mem_vec_11956 = vec_71;
												vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_11957);
												mem_vec_11957 = vec_72;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
												vec_74 = _mm512_set1_ps(scal_13);
												vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_11958);
												mem_vec_11958 = vec_73;
												vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_11959);
												mem_vec_11959 = vec_75;
												vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_11960);
												mem_vec_11960 = vec_76;
												vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_11961);
												mem_vec_11961 = vec_77;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_79 = _mm512_set1_ps(scal_14);
												vec_80 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_11934);
												mem_vec_11934 = vec_78;
												vec_82 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
												vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_11935);
												mem_vec_11935 = vec_81;
												vec_84 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 32]);
												vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_11936);
												mem_vec_11936 = vec_83;
												vec_86 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 48]);
												vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_11937);
												mem_vec_11937 = vec_85;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_88 = _mm512_set1_ps(scal_15);
												vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_11938);
												mem_vec_11938 = vec_87;
												vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_11939);
												mem_vec_11939 = vec_89;
												vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_11940);
												mem_vec_11940 = vec_90;
												vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_11941);
												mem_vec_11941 = vec_91;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_93 = _mm512_set1_ps(scal_16);
												vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_11942);
												mem_vec_11942 = vec_92;
												vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_11943);
												mem_vec_11943 = vec_94;
												vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_11944);
												mem_vec_11944 = vec_95;
												vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_11945);
												mem_vec_11945 = vec_96;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_98 = _mm512_set1_ps(scal_17);
												vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_11946);
												mem_vec_11946 = vec_97;
												vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_11947);
												mem_vec_11947 = vec_99;
												vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_11948);
												mem_vec_11948 = vec_100;
												vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_11949);
												mem_vec_11949 = vec_101;
												scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_103 = _mm512_set1_ps(scal_18);
												vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_11950);
												mem_vec_11950 = vec_102;
												vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_11951);
												mem_vec_11951 = vec_104;
												vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_11952);
												mem_vec_11952 = vec_105;
												vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_11953);
												mem_vec_11953 = vec_106;
												scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_108 = _mm512_set1_ps(scal_19);
												vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_11954);
												mem_vec_11954 = vec_107;
												vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_11955);
												mem_vec_11955 = vec_109;
												vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_11956);
												mem_vec_11956 = vec_110;
												vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_11957);
												mem_vec_11957 = vec_111;
												scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
												vec_113 = _mm512_set1_ps(scal_20);
												vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_11958);
												mem_vec_11958 = vec_112;
												vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_11959);
												mem_vec_11959 = vec_114;
												vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_11960);
												mem_vec_11960 = vec_115;
												vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_11961);
												mem_vec_11961 = vec_116;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_11934);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_11935);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_11936);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_11937);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_11938);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_11939);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_11940);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_11941);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_11942);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_11943);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_11944);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_11945);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_11946);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_11947);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_11948);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_11949);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_11950);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_11951);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_11952);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_11953);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_11954);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_11955);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_11956);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_11957);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_11958);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_11959);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_11960);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_11961);
								}
							}
}
