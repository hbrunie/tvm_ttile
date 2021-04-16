#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (3, h);
  T (17, x); Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))];
  T (8, f); T (8, c); T (2, f); T (2, f)]
*/
IND_TYPE c, cp_0, c69_p_0, cp_1, c69, f, fp_0, f92_p_0, f93_p_0, fp_1, f92_p_1, fp_2, f92, f93, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y46 = 0;
IND_TYPE x46 = 0;
IND_TYPE h34 = 0;
IND_TYPE w = 0;
IND_TYPE c70 = 0;
IND_TYPE f94 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,mem_vec_904 ,mem_vec_905 ,mem_vec_906 ,mem_vec_907 ,mem_vec_908 ,mem_vec_909 ,mem_vec_910 ,mem_vec_911 ,mem_vec_912 ,mem_vec_913 ,mem_vec_914 ,mem_vec_915 ,mem_vec_916 ,mem_vec_917 ,mem_vec_918 ,mem_vec_919 ,mem_vec_920 ,mem_vec_921 ,mem_vec_922 ,mem_vec_923 ,mem_vec_924 ,mem_vec_925 ,mem_vec_926 ,mem_vec_927 ,mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
for (f93 = f94, f93_p_0 = 0;
	f93 < f94 + 1024;
	f93 += 512, f93_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
	// T (f, 2) (512 / 256)
	for (f92 = f93, f92_p_1 = f93_p_0, f92_p_0 = 0;
		f92 < f93 + 512;
		f92 += 256, f92_p_1 += 256, f92_p_0 += 256){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 256
		// T (c, 8) (512 / 64)
		for (c69 = c70, c69_p_0 = 0;
			c69 < c70 + 512;
			c69 += 64, c69_p_0 += 64){
			// y = 17, x = 17, h = 3, w = 3, c = 64, f = 256
			// T (f, 8) (256 / 32)
			for (f = f92, fp_2 = f92_p_1, fp_1 = f92_p_0, fp_0 = 0;
				f < f92 + 256;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y46, yp_0 = 0;
						y < y46 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
						// T (x, 17) (17 / 1)
						for (x = x46, xp_0 = 0;
							x < x46 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h34, hp_0 = 0;
								h < h34 + 3;
								h += 1, hp_0 += 1){
										mem_vec_900 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_901 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_902 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_903 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_904 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_905 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_906 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_907 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_908 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_909 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_910 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_911 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_912 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_913 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_914 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_915 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_916 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_917 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_918 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_919 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c69, cp_1 = c69_p_0, cp_0 = 0;
											c < c69 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_900);
											mem_vec_900 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_901);
											mem_vec_901 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_902);
											mem_vec_902 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_903);
											mem_vec_903 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_904);
											mem_vec_904 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_905);
											mem_vec_905 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_906);
											mem_vec_906 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_907);
											mem_vec_907 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_908);
											mem_vec_908 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_909);
											mem_vec_909 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_910);
											mem_vec_910 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_911);
											mem_vec_911 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_912);
											mem_vec_912 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_913);
											mem_vec_913 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_914);
											mem_vec_914 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_915);
											mem_vec_915 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_916);
											mem_vec_916 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_917);
											mem_vec_917 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_918);
											mem_vec_918 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_919);
											mem_vec_919 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_900);
											mem_vec_900 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_901);
											mem_vec_901 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_902);
											mem_vec_902 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_903);
											mem_vec_903 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_904);
											mem_vec_904 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_905);
											mem_vec_905 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_906);
											mem_vec_906 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_907);
											mem_vec_907 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_908);
											mem_vec_908 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_909);
											mem_vec_909 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_910);
											mem_vec_910 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_911);
											mem_vec_911 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_912);
											mem_vec_912 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_913);
											mem_vec_913 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_914);
											mem_vec_914 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_915);
											mem_vec_915 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_916);
											mem_vec_916 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_917);
											mem_vec_917 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_918);
											mem_vec_918 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_919);
											mem_vec_919 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_900);
											mem_vec_900 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_901);
											mem_vec_901 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_902);
											mem_vec_902 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_903);
											mem_vec_903 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_904);
											mem_vec_904 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_905);
											mem_vec_905 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_906);
											mem_vec_906 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_907);
											mem_vec_907 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_908);
											mem_vec_908 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_909);
											mem_vec_909 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_910);
											mem_vec_910 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_911);
											mem_vec_911 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_912);
											mem_vec_912 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_913);
											mem_vec_913 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_914);
											mem_vec_914 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_915);
											mem_vec_915 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_916);
											mem_vec_916 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_917);
											mem_vec_917 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_918);
											mem_vec_918 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_919);
											mem_vec_919 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_900);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_901);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_902);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_903);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_904);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_905);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_906);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_907);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_908);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_909);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_910);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_911);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_912);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_913);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_914);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_915);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_916);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_917);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_918);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_919);
							}
						}
					}
					for (y = y46 + 5, yp_0 = 0;
						y < y46 + 5 + 12;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
						// T (x, 17) (17 / 1)
						for (x = x46, xp_0 = 0;
							x < x46 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h34, hp_0 = 0;
								h < h34 + 3;
								h += 1, hp_0 += 1){
										mem_vec_920 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_921 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_922 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_923 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_924 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_925 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_926 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_927 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_928 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_929 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_930 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_931 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_932 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_933 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_934 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_935 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_936 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_937 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_938 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_939 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_940 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_941 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_942 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_943 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c69, cp_1 = c69_p_0, cp_0 = 0;
											c < c69 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_920);
											mem_vec_920 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_921);
											mem_vec_921 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_922);
											mem_vec_922 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_923);
											mem_vec_923 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_924);
											mem_vec_924 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_925);
											mem_vec_925 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_926);
											mem_vec_926 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_927);
											mem_vec_927 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_928);
											mem_vec_928 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_929);
											mem_vec_929 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_930);
											mem_vec_930 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_931);
											mem_vec_931 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_932);
											mem_vec_932 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_933);
											mem_vec_933 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_934);
											mem_vec_934 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_935);
											mem_vec_935 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_936);
											mem_vec_936 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_937);
											mem_vec_937 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_938);
											mem_vec_938 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_939);
											mem_vec_939 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_940);
											mem_vec_940 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_941);
											mem_vec_941 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_942);
											mem_vec_942 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_943);
											mem_vec_943 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_920);
											mem_vec_920 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_921);
											mem_vec_921 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_922);
											mem_vec_922 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_923);
											mem_vec_923 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_924);
											mem_vec_924 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_925);
											mem_vec_925 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_926);
											mem_vec_926 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_927);
											mem_vec_927 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_928);
											mem_vec_928 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_929);
											mem_vec_929 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_930);
											mem_vec_930 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_931);
											mem_vec_931 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_932);
											mem_vec_932 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_933);
											mem_vec_933 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_934);
											mem_vec_934 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_935);
											mem_vec_935 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_936);
											mem_vec_936 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_937);
											mem_vec_937 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_938);
											mem_vec_938 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_939);
											mem_vec_939 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_940);
											mem_vec_940 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_941);
											mem_vec_941 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_942);
											mem_vec_942 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_943);
											mem_vec_943 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_920);
											mem_vec_920 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_921);
											mem_vec_921 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_922);
											mem_vec_922 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_923);
											mem_vec_923 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_924);
											mem_vec_924 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_925);
											mem_vec_925 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_926);
											mem_vec_926 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_927);
											mem_vec_927 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_928);
											mem_vec_928 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_929);
											mem_vec_929 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_930);
											mem_vec_930 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_931);
											mem_vec_931 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_932);
											mem_vec_932 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_933);
											mem_vec_933 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_934);
											mem_vec_934 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_935);
											mem_vec_935 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_936);
											mem_vec_936 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_937);
											mem_vec_937 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_938);
											mem_vec_938 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_939);
											mem_vec_939 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_940);
											mem_vec_940 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_941);
											mem_vec_941 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_942);
											mem_vec_942 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_943);
											mem_vec_943 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_920);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_921);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_922);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_923);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_924);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_925);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_926);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_927);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_928);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_929);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_930);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_931);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_932);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_933);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_934);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_935);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_936);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_937);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_938);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_939);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_940);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_941);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_942);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_943);
							}
						}
					}
			}
		}
	}
}


}