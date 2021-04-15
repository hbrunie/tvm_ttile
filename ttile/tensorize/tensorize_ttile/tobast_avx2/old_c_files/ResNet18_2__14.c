#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (4, x);
  T (3, w); T (64, c); T (7, x);
  Lambda_apply y [((Iter 5), (Arg 9)); ((Iter 1), (Arg 11))]; T (4, f);
  T (2, x)]
*/
IND_TYPE c, cp_0, c656_p_0, cp_1, c656, f, fp_0, w, wp_0, x, xp_0, x562_p_0, x563_p_0, xp_1, x562_p_1, xp_2, x562, x563, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y348 = 0;
IND_TYPE x564 = 0;
IND_TYPE h = 0;
IND_TYPE w262 = 0;
IND_TYPE c657 = 0;
IND_TYPE f604 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3840 ,mem_vec_3841 ,mem_vec_3842 ,mem_vec_3843 ,mem_vec_3844 ,mem_vec_3845 ,mem_vec_3846 ,mem_vec_3847 ,mem_vec_3848 ,mem_vec_3849 ,mem_vec_3850 ,mem_vec_3851 ,mem_vec_3852 ,mem_vec_3853 ,mem_vec_3854 ,mem_vec_3855 ,mem_vec_3856 ,mem_vec_3857 ,mem_vec_3858 ,mem_vec_3859 ,mem_vec_3860 ,mem_vec_3861 ,mem_vec_3862 ,mem_vec_3863 ,mem_vec_3864 ,mem_vec_3865 ,mem_vec_3866 ,mem_vec_3867 ,mem_vec_3868 ,mem_vec_3869 ,mem_vec_3870 ,mem_vec_3871 ,mem_vec_3872 ,mem_vec_3873 ,mem_vec_3874 ,mem_vec_3875 ,mem_vec_3876 ,mem_vec_3877 ,mem_vec_3878 ,mem_vec_3879 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 2) (56 / 28)
for (x563 = x564, x563_p_0 = 0;
	x563 < x564 + 56;
	x563 += 28, x563_p_0 += 28){
	// y = 56, x = 28, h = 3, w = 3, c = 64, f = 64
	// T (f, 4) (64 / 16)
	for (f = f604, fp_0 = 0;
		f < f604 + 64;
		f += 16, fp_0 += 16){
			for (y = y348, yp_0 = 0;
				y < y348 + 45;
				y += 9, yp_0 += 9){
				// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 16
				// T (x, 7) (28 / 4)
				for (x562 = x563, x562_p_1 = x563_p_0, x562_p_0 = 0;
					x562 < x563 + 28;
					x562 += 4, x562_p_1 += 4, x562_p_0 += 4){
					// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 16
					// T (c, 64) (64 / 1)
					for (c656 = c657, c656_p_0 = 0;
						c656 < c657 + 64;
						c656 += 1, c656_p_0 += 1){
						// y = ph_y, x = 4, h = 3, w = 3, c = 1, f = 16
						// T (w, 3) (3 / 1)
						for (w = w262, wp_0 = 0;
							w < w262 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 4, h = 3, w = 1, c = 1, f = 16
							// T (x, 4) (4 / 1)
							for (x = x562, xp_2 = x562_p_1, xp_1 = x562_p_0, xp_0 = 0;
								x < x562 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3840 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3841 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_3842 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3843 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_3844 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3845 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_3846 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3847 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_3848 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3849 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_3850 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3851 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_3852 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3853 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_3854 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3855 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_3856 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_3857 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 16
										// T (c, 1) (1 / 1)
										for (c = c656, cp_1 = c656_p_0, cp_0 = 0;
											c < c656 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3840);
											mem_vec_3840 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3841);
											mem_vec_3841 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_3842);
											mem_vec_3842 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_3843);
											mem_vec_3843 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_3844);
											mem_vec_3844 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_3845);
											mem_vec_3845 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_3846);
											mem_vec_3846 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_3847);
											mem_vec_3847 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3848);
											mem_vec_3848 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3849);
											mem_vec_3849 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_3850);
											mem_vec_3850 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_3851);
											mem_vec_3851 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_3852);
											mem_vec_3852 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_3853);
											mem_vec_3853 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_3854);
											mem_vec_3854 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_3855);
											mem_vec_3855 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_3856);
											mem_vec_3856 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_3857);
											mem_vec_3857 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm256_set1_ps(scal_9);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_3840);
											mem_vec_3840 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_3841);
											mem_vec_3841 = vec_32;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_10);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_31, mem_vec_3842);
											mem_vec_3842 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_33, mem_vec_3843);
											mem_vec_3843 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_38 = _mm256_set1_ps(scal_11);


											vec_37 = _mm256_fmadd_ps(vec_38, vec_31, mem_vec_3844);
											mem_vec_3844 = vec_37;



											vec_39 = _mm256_fmadd_ps(vec_38, vec_33, mem_vec_3845);
											mem_vec_3845 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_41 = _mm256_set1_ps(scal_12);


											vec_40 = _mm256_fmadd_ps(vec_41, vec_31, mem_vec_3846);
											mem_vec_3846 = vec_40;



											vec_42 = _mm256_fmadd_ps(vec_41, vec_33, mem_vec_3847);
											mem_vec_3847 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_3848);
											mem_vec_3848 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_3849);
											mem_vec_3849 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_31, mem_vec_3850);
											mem_vec_3850 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_33, mem_vec_3851);
											mem_vec_3851 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_31, mem_vec_3852);
											mem_vec_3852 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_33, mem_vec_3853);
											mem_vec_3853 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_31, mem_vec_3854);
											mem_vec_3854 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_33, mem_vec_3855);
											mem_vec_3855 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_31, mem_vec_3856);
											mem_vec_3856 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_33, mem_vec_3857);
											mem_vec_3857 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm256_set1_ps(scal_18);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_3840);
											mem_vec_3840 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_3841);
											mem_vec_3841 = vec_61;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_64 = _mm256_set1_ps(scal_19);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_60, mem_vec_3842);
											mem_vec_3842 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_62, mem_vec_3843);
											mem_vec_3843 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_67 = _mm256_set1_ps(scal_20);


											vec_66 = _mm256_fmadd_ps(vec_67, vec_60, mem_vec_3844);
											mem_vec_3844 = vec_66;



											vec_68 = _mm256_fmadd_ps(vec_67, vec_62, mem_vec_3845);
											mem_vec_3845 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_70 = _mm256_set1_ps(scal_21);


											vec_69 = _mm256_fmadd_ps(vec_70, vec_60, mem_vec_3846);
											mem_vec_3846 = vec_69;



											vec_71 = _mm256_fmadd_ps(vec_70, vec_62, mem_vec_3847);
											mem_vec_3847 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_22);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_3848);
											mem_vec_3848 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_3849);
											mem_vec_3849 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_76 = _mm256_set1_ps(scal_23);


											vec_75 = _mm256_fmadd_ps(vec_76, vec_60, mem_vec_3850);
											mem_vec_3850 = vec_75;



											vec_77 = _mm256_fmadd_ps(vec_76, vec_62, mem_vec_3851);
											mem_vec_3851 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_24);


											vec_78 = _mm256_fmadd_ps(vec_79, vec_60, mem_vec_3852);
											mem_vec_3852 = vec_78;



											vec_80 = _mm256_fmadd_ps(vec_79, vec_62, mem_vec_3853);
											mem_vec_3853 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_82 = _mm256_set1_ps(scal_25);


											vec_81 = _mm256_fmadd_ps(vec_82, vec_60, mem_vec_3854);
											mem_vec_3854 = vec_81;



											vec_83 = _mm256_fmadd_ps(vec_82, vec_62, mem_vec_3855);
											mem_vec_3855 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_85 = _mm256_set1_ps(scal_26);


											vec_84 = _mm256_fmadd_ps(vec_85, vec_60, mem_vec_3856);
											mem_vec_3856 = vec_84;



											vec_86 = _mm256_fmadd_ps(vec_85, vec_62, mem_vec_3857);
											mem_vec_3857 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3840);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3841);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3842);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3843);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3844);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3845);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3846);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3847);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3848);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3849);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3850);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3851);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3852);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3853);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3854);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_3855);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3856);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_3857);
							}
						}
					}
				}
			}
			for (y = y348 + 45, yp_0 = 0;
				y < y348 + 45 + 11;
				y += 11, yp_0 += 11){
				// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 16
				// T (x, 7) (28 / 4)
				for (x562 = x563, x562_p_1 = x563_p_0, x562_p_0 = 0;
					x562 < x563 + 28;
					x562 += 4, x562_p_1 += 4, x562_p_0 += 4){
					// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 16
					// T (c, 64) (64 / 1)
					for (c656 = c657, c656_p_0 = 0;
						c656 < c657 + 64;
						c656 += 1, c656_p_0 += 1){
						// y = ph_y, x = 4, h = 3, w = 3, c = 1, f = 16
						// T (w, 3) (3 / 1)
						for (w = w262, wp_0 = 0;
							w < w262 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 4, h = 3, w = 1, c = 1, f = 16
							// T (x, 4) (4 / 1)
							for (x = x562, xp_2 = x562_p_1, xp_1 = x562_p_0, xp_0 = 0;
								x < x562 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3858 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3859 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_3860 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3861 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_3862 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3863 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_3864 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3865 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_3866 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3867 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_3868 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3869 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_3870 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3871 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_3872 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3873 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_3874 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_3875 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										mem_vec_3876 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_3877 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
										mem_vec_3878 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_3879 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 16
										// T (c, 1) (1 / 1)
										for (c = c656, cp_1 = c656_p_0, cp_0 = 0;
											c < c656 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3858);
											mem_vec_3858 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3859);
											mem_vec_3859 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_3860);
											mem_vec_3860 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_3861);
											mem_vec_3861 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_3862);
											mem_vec_3862 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_3863);
											mem_vec_3863 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_3864);
											mem_vec_3864 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_3865);
											mem_vec_3865 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3866);
											mem_vec_3866 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3867);
											mem_vec_3867 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_3868);
											mem_vec_3868 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_3869);
											mem_vec_3869 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_3870);
											mem_vec_3870 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_3871);
											mem_vec_3871 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_3872);
											mem_vec_3872 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_3873);
											mem_vec_3873 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_3874);
											mem_vec_3874 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_3875);
											mem_vec_3875 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_3876);
											mem_vec_3876 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_3877);
											mem_vec_3877 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm256_set1_ps(scal_10);


											vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_3878);
											mem_vec_3878 = vec_32;



											vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_3879);
											mem_vec_3879 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_36 = _mm256_set1_ps(scal_11);
											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_3858);
											mem_vec_3858 = vec_35;

											vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_3859);
											mem_vec_3859 = vec_38;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_41 = _mm256_set1_ps(scal_12);


											vec_40 = _mm256_fmadd_ps(vec_41, vec_37, mem_vec_3860);
											mem_vec_3860 = vec_40;



											vec_42 = _mm256_fmadd_ps(vec_41, vec_39, mem_vec_3861);
											mem_vec_3861 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_3862);
											mem_vec_3862 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_39, mem_vec_3863);
											mem_vec_3863 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_37, mem_vec_3864);
											mem_vec_3864 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_39, mem_vec_3865);
											mem_vec_3865 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_37, mem_vec_3866);
											mem_vec_3866 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_39, mem_vec_3867);
											mem_vec_3867 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_3868);
											mem_vec_3868 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_3869);
											mem_vec_3869 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_37, mem_vec_3870);
											mem_vec_3870 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_39, mem_vec_3871);
											mem_vec_3871 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_37, mem_vec_3872);
											mem_vec_3872 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_39, mem_vec_3873);
											mem_vec_3873 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_3874);
											mem_vec_3874 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_3875);
											mem_vec_3875 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_65 = _mm256_set1_ps(scal_20);


											vec_64 = _mm256_fmadd_ps(vec_65, vec_37, mem_vec_3876);
											mem_vec_3876 = vec_64;



											vec_66 = _mm256_fmadd_ps(vec_65, vec_39, mem_vec_3877);
											mem_vec_3877 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_68 = _mm256_set1_ps(scal_21);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_37, mem_vec_3878);
											mem_vec_3878 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_39, mem_vec_3879);
											mem_vec_3879 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_71 = _mm256_set1_ps(scal_22);
											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_3858);
											mem_vec_3858 = vec_70;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_3859);
											mem_vec_3859 = vec_73;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_76 = _mm256_set1_ps(scal_23);


											vec_75 = _mm256_fmadd_ps(vec_76, vec_72, mem_vec_3860);
											mem_vec_3860 = vec_75;



											vec_77 = _mm256_fmadd_ps(vec_76, vec_74, mem_vec_3861);
											mem_vec_3861 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_24);


											vec_78 = _mm256_fmadd_ps(vec_79, vec_72, mem_vec_3862);
											mem_vec_3862 = vec_78;



											vec_80 = _mm256_fmadd_ps(vec_79, vec_74, mem_vec_3863);
											mem_vec_3863 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_82 = _mm256_set1_ps(scal_25);


											vec_81 = _mm256_fmadd_ps(vec_82, vec_72, mem_vec_3864);
											mem_vec_3864 = vec_81;



											vec_83 = _mm256_fmadd_ps(vec_82, vec_74, mem_vec_3865);
											mem_vec_3865 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_85 = _mm256_set1_ps(scal_26);


											vec_84 = _mm256_fmadd_ps(vec_85, vec_72, mem_vec_3866);
											mem_vec_3866 = vec_84;



											vec_86 = _mm256_fmadd_ps(vec_85, vec_74, mem_vec_3867);
											mem_vec_3867 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_3868);
											mem_vec_3868 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_3869);
											mem_vec_3869 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);


											vec_90 = _mm256_fmadd_ps(vec_91, vec_72, mem_vec_3870);
											mem_vec_3870 = vec_90;



											vec_92 = _mm256_fmadd_ps(vec_91, vec_74, mem_vec_3871);
											mem_vec_3871 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);


											vec_93 = _mm256_fmadd_ps(vec_94, vec_72, mem_vec_3872);
											mem_vec_3872 = vec_93;



											vec_95 = _mm256_fmadd_ps(vec_94, vec_74, mem_vec_3873);
											mem_vec_3873 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_97 = _mm256_set1_ps(scal_30);


											vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_3874);
											mem_vec_3874 = vec_96;



											vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_3875);
											mem_vec_3875 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_100 = _mm256_set1_ps(scal_31);


											vec_99 = _mm256_fmadd_ps(vec_100, vec_72, mem_vec_3876);
											mem_vec_3876 = vec_99;



											vec_101 = _mm256_fmadd_ps(vec_100, vec_74, mem_vec_3877);
											mem_vec_3877 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_32);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_72, mem_vec_3878);
											mem_vec_3878 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_74, mem_vec_3879);
											mem_vec_3879 = vec_104;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3858);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3859);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3860);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3861);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3862);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3863);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3864);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3865);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3866);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3867);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3868);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3869);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3870);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3871);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3872);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_3873);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3874);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_3875);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3876);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_3877);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3878);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_3879);
							}
						}
					}
				}
			}
	}
}


}