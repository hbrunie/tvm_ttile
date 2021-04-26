void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (14, x);
  T (3, w); T (2, c); T (2, f); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 3), (Arg 12))]; T (2, x)]
*/
IND_TYPE c, cp_0, c471_p_0, cp_1, c471, f, fp_0, w, wp_0, x, xp_0, x586_p_0, x587_p_0, xp_1, x586_p_1, xp_2, x586, x587, y, yp_0;
IND_TYPE y335 = 0;
IND_TYPE x588 = 0;
IND_TYPE h = 0;
IND_TYPE w284 = 0;
IND_TYPE c472 = 0;
IND_TYPE f264 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4956 ,mem_vec_4957 ,mem_vec_4958 ,mem_vec_4959 ,mem_vec_4960 ,mem_vec_4961 ,mem_vec_4962 ,mem_vec_4963 ,mem_vec_4964 ,mem_vec_4965 ,mem_vec_4966 ,mem_vec_4967 ,mem_vec_4968 ,mem_vec_4969 ,mem_vec_4970 ,mem_vec_4971 ,mem_vec_4972 ,mem_vec_4973 ,mem_vec_4974 ,mem_vec_4975 ,mem_vec_4976 ,mem_vec_4977 ,mem_vec_4978 ,mem_vec_4979 ,mem_vec_4980 ,mem_vec_4981 ,mem_vec_4982 ,mem_vec_4983 ,mem_vec_4984 ,mem_vec_4985 ,mem_vec_4986 ,mem_vec_4987 ,mem_vec_4988 ,mem_vec_4989 ,mem_vec_4990 ,mem_vec_4991 ,mem_vec_4992 ,mem_vec_4993 ,mem_vec_4994 ,mem_vec_4995 ,mem_vec_4996 ,mem_vec_4997 ,mem_vec_4998 ,mem_vec_4999 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 2) (56 / 28)
x587 = 0;
x587_p_0 = 0;
y = 0;
yp_0 = 0;
x586 = 0;
x586_p_1 = 0;
f = 0;
fp_0 = 0;
c471 = 0;
c471_p_0 = 0;
						for (w = w284, wp_0 = 0;w < w284 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 32, f = 32
							// T (x, 14) (14 / 1)
							for (x = x586, xp_2 = x586_p_1, xp_1 = x586_p_0, xp_0 = 0;x < x586 + 14;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4976 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4977 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_4978 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4979 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_4980 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4981 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_4982 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4983 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_4984 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_4985 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_4986 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_4987 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_4988 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_4989 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_4990 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_4991 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_4992 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_4993 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_4994 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_4995 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										mem_vec_4996 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_4997 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
										mem_vec_4998 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
										mem_vec_4999 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c471, cp_1 = c471_p_0, cp_0 = 0;c < c471 + 32;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4976);
											mem_vec_4976 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4977);
											mem_vec_4977 = vec_3;
											scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4978);
											mem_vec_4978 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4979);
											mem_vec_4979 = vec_7;
											scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4980);
											mem_vec_4980 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4981);
											mem_vec_4981 = vec_10;
											scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4982);
											mem_vec_4982 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4983);
											mem_vec_4983 = vec_13;
											scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4984);
											mem_vec_4984 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4985);
											mem_vec_4985 = vec_16;
											scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4986);
											mem_vec_4986 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4987);
											mem_vec_4987 = vec_19;
											scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4988);
											mem_vec_4988 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4989);
											mem_vec_4989 = vec_22;
											scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4990);
											mem_vec_4990 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4991);
											mem_vec_4991 = vec_25;
											scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4992);
											mem_vec_4992 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4993);
											mem_vec_4993 = vec_28;
											scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4994);
											mem_vec_4994 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4995);
											mem_vec_4995 = vec_31;
											scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4996);
											mem_vec_4996 = vec_32;
											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4997);
											mem_vec_4997 = vec_34;
											scal_11 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4998);
											mem_vec_4998 = vec_35;
											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4999);
											mem_vec_4999 = vec_37;
											scal_12 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_12);
											vec_40 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_4976);
											mem_vec_4976 = vec_38;
											vec_42 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
											vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_4977);
											mem_vec_4977 = vec_41;
											scal_13 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_4978);
											mem_vec_4978 = vec_43;
											vec_45 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_4979);
											mem_vec_4979 = vec_45;
											scal_14 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);
											vec_46 = _mm512_fmadd_ps(vec_47, vec_40, mem_vec_4980);
											mem_vec_4980 = vec_46;
											vec_48 = _mm512_fmadd_ps(vec_47, vec_42, mem_vec_4981);
											mem_vec_4981 = vec_48;
											scal_15 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);
											vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_4982);
											mem_vec_4982 = vec_49;
											vec_51 = _mm512_fmadd_ps(vec_50, vec_42, mem_vec_4983);
											mem_vec_4983 = vec_51;
											scal_16 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);
											vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_4984);
											mem_vec_4984 = vec_52;
											vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_4985);
											mem_vec_4985 = vec_54;
											scal_17 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);
											vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_4986);
											mem_vec_4986 = vec_55;
											vec_57 = _mm512_fmadd_ps(vec_56, vec_42, mem_vec_4987);
											mem_vec_4987 = vec_57;
											scal_18 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);
											vec_58 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_4988);
											mem_vec_4988 = vec_58;
											vec_60 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_4989);
											mem_vec_4989 = vec_60;
											scal_19 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);
											vec_61 = _mm512_fmadd_ps(vec_62, vec_40, mem_vec_4990);
											mem_vec_4990 = vec_61;
											vec_63 = _mm512_fmadd_ps(vec_62, vec_42, mem_vec_4991);
											mem_vec_4991 = vec_63;
											scal_20 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h + 1) + c];
											vec_65 = _mm512_set1_ps(scal_20);
											vec_64 = _mm512_fmadd_ps(vec_65, vec_40, mem_vec_4992);
											mem_vec_4992 = vec_64;
											vec_66 = _mm512_fmadd_ps(vec_65, vec_42, mem_vec_4993);
											mem_vec_4993 = vec_66;
											scal_21 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_21);
											vec_67 = _mm512_fmadd_ps(vec_68, vec_40, mem_vec_4994);
											mem_vec_4994 = vec_67;
											vec_69 = _mm512_fmadd_ps(vec_68, vec_42, mem_vec_4995);
											mem_vec_4995 = vec_69;
											scal_22 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h + 1) + c];
											vec_71 = _mm512_set1_ps(scal_22);
											vec_70 = _mm512_fmadd_ps(vec_71, vec_40, mem_vec_4996);
											mem_vec_4996 = vec_70;
											vec_72 = _mm512_fmadd_ps(vec_71, vec_42, mem_vec_4997);
											mem_vec_4997 = vec_72;
											scal_23 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 11) + h + 1) + c];
											vec_74 = _mm512_set1_ps(scal_23);
											vec_73 = _mm512_fmadd_ps(vec_74, vec_40, mem_vec_4998);
											mem_vec_4998 = vec_73;
											vec_75 = _mm512_fmadd_ps(vec_74, vec_42, mem_vec_4999);
											mem_vec_4999 = vec_75;
											scal_24 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h + 2) + c];
											vec_77 = _mm512_set1_ps(scal_24);
											vec_78 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_76 = _mm512_fmadd_ps(vec_77, vec_78, mem_vec_4976);
											mem_vec_4976 = vec_76;
											vec_80 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
											vec_79 = _mm512_fmadd_ps(vec_77, vec_80, mem_vec_4977);
											mem_vec_4977 = vec_79;
											scal_25 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);
											vec_81 = _mm512_fmadd_ps(vec_82, vec_78, mem_vec_4978);
											mem_vec_4978 = vec_81;
											vec_83 = _mm512_fmadd_ps(vec_82, vec_80, mem_vec_4979);
											mem_vec_4979 = vec_83;
											scal_26 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);
											vec_84 = _mm512_fmadd_ps(vec_85, vec_78, mem_vec_4980);
											mem_vec_4980 = vec_84;
											vec_86 = _mm512_fmadd_ps(vec_85, vec_80, mem_vec_4981);
											mem_vec_4981 = vec_86;
											scal_27 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);
											vec_87 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_4982);
											mem_vec_4982 = vec_87;
											vec_89 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_4983);
											mem_vec_4983 = vec_89;
											scal_28 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);
											vec_90 = _mm512_fmadd_ps(vec_91, vec_78, mem_vec_4984);
											mem_vec_4984 = vec_90;
											vec_92 = _mm512_fmadd_ps(vec_91, vec_80, mem_vec_4985);
											mem_vec_4985 = vec_92;
											scal_29 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);
											vec_93 = _mm512_fmadd_ps(vec_94, vec_78, mem_vec_4986);
											mem_vec_4986 = vec_93;
											vec_95 = _mm512_fmadd_ps(vec_94, vec_80, mem_vec_4987);
											mem_vec_4987 = vec_95;
											scal_30 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h + 2) + c];
											vec_97 = _mm512_set1_ps(scal_30);
											vec_96 = _mm512_fmadd_ps(vec_97, vec_78, mem_vec_4988);
											mem_vec_4988 = vec_96;
											vec_98 = _mm512_fmadd_ps(vec_97, vec_80, mem_vec_4989);
											mem_vec_4989 = vec_98;
											scal_31 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h + 2) + c];
											vec_100 = _mm512_set1_ps(scal_31);
											vec_99 = _mm512_fmadd_ps(vec_100, vec_78, mem_vec_4990);
											mem_vec_4990 = vec_99;
											vec_101 = _mm512_fmadd_ps(vec_100, vec_80, mem_vec_4991);
											mem_vec_4991 = vec_101;
											scal_32 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_32);
											vec_102 = _mm512_fmadd_ps(vec_103, vec_78, mem_vec_4992);
											mem_vec_4992 = vec_102;
											vec_104 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_4993);
											mem_vec_4993 = vec_104;
											scal_33 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h + 2) + c];
											vec_106 = _mm512_set1_ps(scal_33);
											vec_105 = _mm512_fmadd_ps(vec_106, vec_78, mem_vec_4994);
											mem_vec_4994 = vec_105;
											vec_107 = _mm512_fmadd_ps(vec_106, vec_80, mem_vec_4995);
											mem_vec_4995 = vec_107;
											scal_34 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h + 2) + c];
											vec_109 = _mm512_set1_ps(scal_34);
											vec_108 = _mm512_fmadd_ps(vec_109, vec_78, mem_vec_4996);
											mem_vec_4996 = vec_108;
											vec_110 = _mm512_fmadd_ps(vec_109, vec_80, mem_vec_4997);
											mem_vec_4997 = vec_110;
											scal_35 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 11) + h + 2) + c];
											vec_112 = _mm512_set1_ps(scal_35);
											vec_111 = _mm512_fmadd_ps(vec_112, vec_78, mem_vec_4998);
											mem_vec_4998 = vec_111;
											vec_113 = _mm512_fmadd_ps(vec_112, vec_80, mem_vec_4999);
											mem_vec_4999 = vec_113;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4976);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4977);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4978);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4979);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4980);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4981);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4982);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4983);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4984);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4985);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4986);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4987);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4988);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4989);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4990);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_4991);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4992);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_4993);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_4994);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_4995);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_4996);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_4997);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_4998);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_4999);
							}
						}
}
