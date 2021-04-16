#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (3, h);
  T (34, x); T (4, c);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (16, f);
  T (2, c); T (1, f)]
*/
IND_TYPE c, cp_0, c74_p_0, c75_p_0, cp_1, c74_p_1, cp_2, c74, c75, f, fp_0, f73_p_0, fp_1, f73, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y52 = 0;
IND_TYPE x42 = 0;
IND_TYPE h35 = 0;
IND_TYPE w = 0;
IND_TYPE c76 = 0;
IND_TYPE f74 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,mem_vec_904 ,mem_vec_905 ,mem_vec_906 ,mem_vec_907 ,mem_vec_908 ,mem_vec_909 ,mem_vec_910 ,mem_vec_911 ,mem_vec_912 ,mem_vec_913 ,mem_vec_914 ,mem_vec_915 ,mem_vec_916 ,mem_vec_917 ,mem_vec_918 ,mem_vec_919 ,mem_vec_920 ,mem_vec_921 ,mem_vec_922 ,mem_vec_923 ,mem_vec_924 ,mem_vec_925 ,mem_vec_926 ,mem_vec_927 ,mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f73 = f74, f73_p_0 = 0;
	f73 < f74 + 512;
	f73 += 512, f73_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 2) (256 / 128)
	for (c75 = c76, c75_p_0 = 0;
		c75 < c76 + 256;
		c75 += 128, c75_p_0 += 128){
		// y = 34, x = 34, h = 3, w = 3, c = 128, f = 512
		// T (f, 16) (512 / 32)
		for (f = f73, fp_1 = f73_p_0, fp_0 = 0;
			f < f73 + 512;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y52, yp_0 = 0;
					y < y52 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (c, 4) (128 / 32)
					for (c74 = c75, c74_p_1 = c75_p_0, c74_p_0 = 0;
						c74 < c75 + 128;
						c74 += 32, c74_p_1 += 32, c74_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (x, 34) (34 / 1)
						for (x = x42, xp_0 = 0;
							x < x42 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h35, hp_0 = 0;
								h < h35 + 3;
								h += 1, hp_0 += 1){
										mem_vec_896 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_897 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_898 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_899 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_900 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_901 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_902 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_903 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_904 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_905 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_906 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_907 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_908 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_909 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_910 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_911 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c74, cp_2 = c74_p_1, cp_1 = c74_p_0, cp_0 = 0;
											c < c74 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_896);
											mem_vec_896 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_897);
											mem_vec_897 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_898);
											mem_vec_898 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_899);
											mem_vec_899 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_900);
											mem_vec_900 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_901);
											mem_vec_901 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_902);
											mem_vec_902 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_903);
											mem_vec_903 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_904);
											mem_vec_904 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_905);
											mem_vec_905 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_906);
											mem_vec_906 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_907);
											mem_vec_907 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_908);
											mem_vec_908 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_909);
											mem_vec_909 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_910);
											mem_vec_910 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_911);
											mem_vec_911 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_896);
											mem_vec_896 = vec_24;

											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_897);
											mem_vec_897 = vec_27;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_898);
											mem_vec_898 = vec_29;

											vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_899);
											mem_vec_899 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm256_set1_ps(scal_5);


											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_900);
											mem_vec_900 = vec_33;



											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_901);
											mem_vec_901 = vec_35;



											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_902);
											mem_vec_902 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_903);
											mem_vec_903 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_904);
											mem_vec_904 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_905);
											mem_vec_905 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_906);
											mem_vec_906 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_907);
											mem_vec_907 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_908);
											mem_vec_908 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_909);
											mem_vec_909 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_910);
											mem_vec_910 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_911);
											mem_vec_911 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_896);
											mem_vec_896 = vec_48;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_897);
											mem_vec_897 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_898);
											mem_vec_898 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_899);
											mem_vec_899 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm256_set1_ps(scal_9);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_900);
											mem_vec_900 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_901);
											mem_vec_901 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_902);
											mem_vec_902 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_903);
											mem_vec_903 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm256_set1_ps(scal_10);


											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_904);
											mem_vec_904 = vec_62;



											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_905);
											mem_vec_905 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_906);
											mem_vec_906 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_907);
											mem_vec_907 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_908);
											mem_vec_908 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_909);
											mem_vec_909 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_910);
											mem_vec_910 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_911);
											mem_vec_911 = vec_71;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_896);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_897);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_898);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_899);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_900);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_901);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_902);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_903);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_904);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_905);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_906);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_907);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_908);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_909);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_910);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_911);
							}
						}
					}
				}
				for (y = y52 + 4, yp_0 = 0;
					y < y52 + 4 + 30;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (c, 4) (128 / 32)
					for (c74 = c75, c74_p_1 = c75_p_0, c74_p_0 = 0;
						c74 < c75 + 128;
						c74 += 32, c74_p_1 += 32, c74_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (x, 34) (34 / 1)
						for (x = x42, xp_0 = 0;
							x < x42 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h35, hp_0 = 0;
								h < h35 + 3;
								h += 1, hp_0 += 1){
										mem_vec_912 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_913 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_914 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_915 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_916 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_917 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_918 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_919 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_920 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_921 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_922 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_923 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_924 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_925 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_926 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_927 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_928 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_929 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_930 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_931 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_932 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_933 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_934 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_935 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c74, cp_2 = c74_p_1, cp_1 = c74_p_0, cp_0 = 0;
											c < c74 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_912);
											mem_vec_912 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_913);
											mem_vec_913 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_914);
											mem_vec_914 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_915);
											mem_vec_915 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_916);
											mem_vec_916 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_917);
											mem_vec_917 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_918);
											mem_vec_918 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_919);
											mem_vec_919 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_920);
											mem_vec_920 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_921);
											mem_vec_921 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_922);
											mem_vec_922 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_923);
											mem_vec_923 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_924);
											mem_vec_924 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_925);
											mem_vec_925 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_926);
											mem_vec_926 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_927);
											mem_vec_927 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_928);
											mem_vec_928 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_929);
											mem_vec_929 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_930);
											mem_vec_930 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_931);
											mem_vec_931 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_932);
											mem_vec_932 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_933);
											mem_vec_933 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_934);
											mem_vec_934 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_935);
											mem_vec_935 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_912);
											mem_vec_912 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_913);
											mem_vec_913 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_914);
											mem_vec_914 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_915);
											mem_vec_915 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_916);
											mem_vec_916 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_917);
											mem_vec_917 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_918);
											mem_vec_918 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_919);
											mem_vec_919 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_920);
											mem_vec_920 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_921);
											mem_vec_921 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_922);
											mem_vec_922 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_923);
											mem_vec_923 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_924);
											mem_vec_924 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_925);
											mem_vec_925 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_926);
											mem_vec_926 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_927);
											mem_vec_927 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_928);
											mem_vec_928 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_929);
											mem_vec_929 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_930);
											mem_vec_930 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_931);
											mem_vec_931 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_932);
											mem_vec_932 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_933);
											mem_vec_933 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_934);
											mem_vec_934 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_935);
											mem_vec_935 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_912);
											mem_vec_912 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_913);
											mem_vec_913 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_914);
											mem_vec_914 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_915);
											mem_vec_915 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_916);
											mem_vec_916 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_917);
											mem_vec_917 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_918);
											mem_vec_918 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_919);
											mem_vec_919 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_920);
											mem_vec_920 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_921);
											mem_vec_921 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_922);
											mem_vec_922 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_923);
											mem_vec_923 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_924);
											mem_vec_924 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_925);
											mem_vec_925 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_926);
											mem_vec_926 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_927);
											mem_vec_927 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_928);
											mem_vec_928 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_929);
											mem_vec_929 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_930);
											mem_vec_930 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_931);
											mem_vec_931 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_932);
											mem_vec_932 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_933);
											mem_vec_933 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_934);
											mem_vec_934 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_935);
											mem_vec_935 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_912);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_913);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_914);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_915);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_916);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_917);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_918);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_919);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_920);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_921);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_922);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_923);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_924);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_925);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_926);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_927);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_928);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_929);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_930);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_931);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_932);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_933);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_934);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_935);
							}
						}
					}
				}
		}
	}
}


}