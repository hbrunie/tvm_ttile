void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (4, c); T (2, f); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (1, f)]
*/
IND_TYPE c, cp_0, c393_p_0, cp_1, c393, f, fp_0, f393_p_0, fp_1, f393, h, hp_0, x, xp_0, x365_p_0, xp_1, x365, y, yp_0;
IND_TYPE y262 = 0;
IND_TYPE x366 = 0;
IND_TYPE h219 = 0;
IND_TYPE w = 0;
IND_TYPE c394 = 0;
IND_TYPE f394 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3808 ,mem_vec_3809 ,mem_vec_3810 ,mem_vec_3811 ,mem_vec_3812 ,mem_vec_3813 ,mem_vec_3814 ,mem_vec_3815 ,mem_vec_3816 ,mem_vec_3817 ,mem_vec_3818 ,mem_vec_3819 ,mem_vec_3820 ,mem_vec_3821 ,mem_vec_3822 ,mem_vec_3823 ,mem_vec_3824 ,mem_vec_3825 ,mem_vec_3826 ,mem_vec_3827 ,mem_vec_3828 ,mem_vec_3829 ,mem_vec_3830 ,mem_vec_3831 ,mem_vec_3832 ,mem_vec_3833 ,mem_vec_3834 ,mem_vec_3835 ,mem_vec_3836 ,mem_vec_3837 ,mem_vec_3838 ,mem_vec_3839 ,mem_vec_3840 ,mem_vec_3841 ,mem_vec_3842 ,mem_vec_3843 ,mem_vec_3844 ,mem_vec_3845 ,mem_vec_3846 ,mem_vec_3847 ,mem_vec_3848 ,mem_vec_3849 ,mem_vec_3850 ,mem_vec_3851 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
f393 = 0;
f393_p_0 = 0;
y = 0;
yp_0 = 0;
x365 = 0;
x365_p_0 = 0;
f = 0;
fp_1 = 0;
c393 = 0;
c393_p_0 = 0;
						for (h = h219, hp_0 = 0;h < h219 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 32, f = 64
							// T (x, 14) (14 / 1)
							for (x = x365, xp_1 = x365_p_0, xp_0 = 0;x < x365 + 14;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3828 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_3829 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_3830 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_3831 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_3832 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_3833 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_3834 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_3835 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_3836 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_3837 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_3838 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_3839 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										mem_vec_3840 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_3841 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_3842 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
										mem_vec_3843 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
										mem_vec_3844 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_3845 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_3846 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
										mem_vec_3847 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
										mem_vec_3848 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_3849 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_3850 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
										mem_vec_3851 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c393, cp_1 = c393_p_0, cp_0 = 0;c < c393 + 32;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3828);
											mem_vec_3828 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3829);
											mem_vec_3829 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3830);
											mem_vec_3830 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3831);
											mem_vec_3831 = vec_7;
											scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3832);
											mem_vec_3832 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3833);
											mem_vec_3833 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3834);
											mem_vec_3834 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3835);
											mem_vec_3835 = vec_13;
											scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3836);
											mem_vec_3836 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3837);
											mem_vec_3837 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3838);
											mem_vec_3838 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3839);
											mem_vec_3839 = vec_18;
											scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3840);
											mem_vec_3840 = vec_19;
											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3841);
											mem_vec_3841 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3842);
											mem_vec_3842 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3843);
											mem_vec_3843 = vec_23;
											scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3844);
											mem_vec_3844 = vec_24;
											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3845);
											mem_vec_3845 = vec_26;
											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3846);
											mem_vec_3846 = vec_27;
											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3847);
											mem_vec_3847 = vec_28;
											scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3848);
											mem_vec_3848 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3849);
											mem_vec_3849 = vec_31;
											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_3850);
											mem_vec_3850 = vec_32;
											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_3851);
											mem_vec_3851 = vec_33;
											scal_6 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * y + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_3828);
											mem_vec_3828 = vec_34;
											vec_38 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_3829);
											mem_vec_3829 = vec_37;
											vec_40 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_3830);
											mem_vec_3830 = vec_39;
											vec_42 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_3831);
											mem_vec_3831 = vec_41;
											scal_7 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 1) + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_3832);
											mem_vec_3832 = vec_43;
											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_3833);
											mem_vec_3833 = vec_45;
											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_3834);
											mem_vec_3834 = vec_46;
											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_3835);
											mem_vec_3835 = vec_47;
											scal_8 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 2) + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_3836);
											mem_vec_3836 = vec_48;
											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_3837);
											mem_vec_3837 = vec_50;
											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_3838);
											mem_vec_3838 = vec_51;
											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_3839);
											mem_vec_3839 = vec_52;
											scal_9 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 3) + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);
											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_3840);
											mem_vec_3840 = vec_53;
											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_3841);
											mem_vec_3841 = vec_55;
											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_3842);
											mem_vec_3842 = vec_56;
											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_3843);
											mem_vec_3843 = vec_57;
											scal_10 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 4) + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_3844);
											mem_vec_3844 = vec_58;
											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_3845);
											mem_vec_3845 = vec_60;
											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_3846);
											mem_vec_3846 = vec_61;
											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_3847);
											mem_vec_3847 = vec_62;
											scal_11 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 5) + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);
											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_3848);
											mem_vec_3848 = vec_63;
											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_3849);
											mem_vec_3849 = vec_65;
											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_3850);
											mem_vec_3850 = vec_66;
											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_3851);
											mem_vec_3851 = vec_67;
											scal_12 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * y + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_3828);
											mem_vec_3828 = vec_68;
											vec_72 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_3829);
											mem_vec_3829 = vec_71;
											vec_74 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_3830);
											mem_vec_3830 = vec_73;
											vec_76 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_3831);
											mem_vec_3831 = vec_75;
											scal_13 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 1) + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);
											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_3832);
											mem_vec_3832 = vec_77;
											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_3833);
											mem_vec_3833 = vec_79;
											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_3834);
											mem_vec_3834 = vec_80;
											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_3835);
											mem_vec_3835 = vec_81;
											scal_14 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 2) + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);
											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_3836);
											mem_vec_3836 = vec_82;
											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_3837);
											mem_vec_3837 = vec_84;
											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_3838);
											mem_vec_3838 = vec_85;
											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_3839);
											mem_vec_3839 = vec_86;
											scal_15 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 3) + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);
											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_3840);
											mem_vec_3840 = vec_87;
											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_3841);
											mem_vec_3841 = vec_89;
											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_3842);
											mem_vec_3842 = vec_90;
											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_3843);
											mem_vec_3843 = vec_91;
											scal_16 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 4) + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);
											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_3844);
											mem_vec_3844 = vec_92;
											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_3845);
											mem_vec_3845 = vec_94;
											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_3846);
											mem_vec_3846 = vec_95;
											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_3847);
											mem_vec_3847 = vec_96;
											scal_17 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 5) + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);
											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_3848);
											mem_vec_3848 = vec_97;
											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_3849);
											mem_vec_3849 = vec_99;
											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_3850);
											mem_vec_3850 = vec_100;
											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_3851);
											mem_vec_3851 = vec_101;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3828);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3829);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_3830);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_3831);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3832);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3833);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_3834);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_3835);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3836);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3837);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_3838);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_3839);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3840);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3841);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_3842);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_3843);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3844);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3845);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_3846);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_3847);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3848);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3849);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_3850);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_3851);
							}
						}
}
