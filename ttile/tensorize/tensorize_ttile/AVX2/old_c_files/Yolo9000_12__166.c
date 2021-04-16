#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (34, x); T (8, c);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (8, f);
  T (1, c); T (2, f)]
*/
IND_TYPE c, cp_0, c512_p_0, c513_p_0, cp_1, c512_p_1, cp_2, c512, c513, f, fp_0, f412_p_0, fp_1, f412, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y292 = 0;
IND_TYPE x264 = 0;
IND_TYPE h = 0;
IND_TYPE w222 = 0;
IND_TYPE c514 = 0;
IND_TYPE f413 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_5852 ,mem_vec_5853 ,mem_vec_5854 ,mem_vec_5855 ,mem_vec_5856 ,mem_vec_5857 ,mem_vec_5858 ,mem_vec_5859 ,mem_vec_5860 ,mem_vec_5861 ,mem_vec_5862 ,mem_vec_5863 ,mem_vec_5864 ,mem_vec_5865 ,mem_vec_5866 ,mem_vec_5867 ,mem_vec_5868 ,mem_vec_5869 ,mem_vec_5870 ,mem_vec_5871 ,mem_vec_5872 ,mem_vec_5873 ,mem_vec_5874 ,mem_vec_5875 ,mem_vec_5876 ,mem_vec_5877 ,mem_vec_5878 ,mem_vec_5879 ,mem_vec_5880 ,mem_vec_5881 ,mem_vec_5882 ,mem_vec_5883 ,mem_vec_5884 ,mem_vec_5885 ,mem_vec_5886 ,mem_vec_5887 ,mem_vec_5888 ,mem_vec_5889 ,mem_vec_5890 ,mem_vec_5891 ,mem_vec_5892 ,mem_vec_5893 ,mem_vec_5894 ,mem_vec_5895 ,mem_vec_5896 ,mem_vec_5897 ,mem_vec_5898 ,mem_vec_5899 ,mem_vec_5900 ,mem_vec_5901 ,mem_vec_5902 ,mem_vec_5903 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f412 = f413, f412_p_0 = 0;
	f412 < f413 + 512;
	f412 += 256, f412_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (c, 1) (256 / 256)
	for (c513 = c514, c513_p_0 = 0;
		c513 < c514 + 256;
		c513 += 256, c513_p_0 += 256){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f = f412, fp_1 = f412_p_0, fp_0 = 0;
			f < f412 + 256;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y292, yp_0 = 0;
					y < y292 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (c, 8) (256 / 32)
					for (c512 = c513, c512_p_1 = c513_p_0, c512_p_0 = 0;
						c512 < c513 + 256;
						c512 += 32, c512_p_1 += 32, c512_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (x, 34) (34 / 1)
						for (x = x264, xp_0 = 0;
							x < x264 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w222, wp_0 = 0;
								w < w222 + 3;
								w += 1, wp_0 += 1){
										mem_vec_5852 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5853 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_5854 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5855 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_5856 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5857 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_5858 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5859 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_5860 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5861 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_5862 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5863 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_5864 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5865 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_5866 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5867 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_5868 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5869 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_5870 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5871 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_5872 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5873 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_5874 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5875 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c512, cp_2 = c512_p_1, cp_1 = c512_p_0, cp_0 = 0;
											c < c512 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5852);
											mem_vec_5852 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5853);
											mem_vec_5853 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5854);
											mem_vec_5854 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5855);
											mem_vec_5855 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5856);
											mem_vec_5856 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5857);
											mem_vec_5857 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5858);
											mem_vec_5858 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5859);
											mem_vec_5859 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5860);
											mem_vec_5860 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5861);
											mem_vec_5861 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5862);
											mem_vec_5862 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5863);
											mem_vec_5863 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5864);
											mem_vec_5864 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5865);
											mem_vec_5865 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5866);
											mem_vec_5866 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5867);
											mem_vec_5867 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5868);
											mem_vec_5868 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5869);
											mem_vec_5869 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5870);
											mem_vec_5870 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5871);
											mem_vec_5871 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_5872);
											mem_vec_5872 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_5873);
											mem_vec_5873 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_5874);
											mem_vec_5874 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_5875);
											mem_vec_5875 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_5852);
											mem_vec_5852 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_5853);
											mem_vec_5853 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_5854);
											mem_vec_5854 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_5855);
											mem_vec_5855 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_5856);
											mem_vec_5856 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_5857);
											mem_vec_5857 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_5858);
											mem_vec_5858 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_5859);
											mem_vec_5859 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_5860);
											mem_vec_5860 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_5861);
											mem_vec_5861 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_5862);
											mem_vec_5862 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_5863);
											mem_vec_5863 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_5864);
											mem_vec_5864 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_5865);
											mem_vec_5865 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_5866);
											mem_vec_5866 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_5867);
											mem_vec_5867 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_5868);
											mem_vec_5868 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_5869);
											mem_vec_5869 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_5870);
											mem_vec_5870 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_5871);
											mem_vec_5871 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_5872);
											mem_vec_5872 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_5873);
											mem_vec_5873 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_5874);
											mem_vec_5874 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_5875);
											mem_vec_5875 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_5852);
											mem_vec_5852 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_5853);
											mem_vec_5853 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_5854);
											mem_vec_5854 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_5855);
											mem_vec_5855 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_5856);
											mem_vec_5856 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_5857);
											mem_vec_5857 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_5858);
											mem_vec_5858 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_5859);
											mem_vec_5859 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_5860);
											mem_vec_5860 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_5861);
											mem_vec_5861 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_5862);
											mem_vec_5862 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_5863);
											mem_vec_5863 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_5864);
											mem_vec_5864 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_5865);
											mem_vec_5865 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_5866);
											mem_vec_5866 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_5867);
											mem_vec_5867 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_5868);
											mem_vec_5868 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_5869);
											mem_vec_5869 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_5870);
											mem_vec_5870 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_5871);
											mem_vec_5871 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_5872);
											mem_vec_5872 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_5873);
											mem_vec_5873 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_5874);
											mem_vec_5874 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_5875);
											mem_vec_5875 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5852);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5853);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5854);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5855);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5856);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5857);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5858);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5859);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5860);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5861);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5862);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5863);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5864);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5865);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5866);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5867);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5868);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5869);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5870);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5871);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5872);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_5873);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5874);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_5875);
							}
						}
					}
				}
				for (y = y292 + 6, yp_0 = 0;
					y < y292 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (c, 8) (256 / 32)
					for (c512 = c513, c512_p_1 = c513_p_0, c512_p_0 = 0;
						c512 < c513 + 256;
						c512 += 32, c512_p_1 += 32, c512_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (x, 34) (34 / 1)
						for (x = x264, xp_0 = 0;
							x < x264 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w222, wp_0 = 0;
								w < w222 + 3;
								w += 1, wp_0 += 1){
										mem_vec_5876 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5877 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_5878 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5879 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_5880 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5881 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_5882 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5883 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_5884 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5885 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_5886 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5887 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_5888 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5889 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_5890 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5891 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_5892 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5893 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_5894 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5895 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_5896 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5897 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_5898 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5899 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										mem_vec_5900 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_5901 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_5902 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_5903 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c512, cp_2 = c512_p_1, cp_1 = c512_p_0, cp_0 = 0;
											c < c512 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5876);
											mem_vec_5876 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5877);
											mem_vec_5877 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5878);
											mem_vec_5878 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5879);
											mem_vec_5879 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5880);
											mem_vec_5880 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5881);
											mem_vec_5881 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5882);
											mem_vec_5882 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5883);
											mem_vec_5883 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5884);
											mem_vec_5884 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5885);
											mem_vec_5885 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5886);
											mem_vec_5886 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5887);
											mem_vec_5887 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5888);
											mem_vec_5888 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5889);
											mem_vec_5889 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5890);
											mem_vec_5890 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5891);
											mem_vec_5891 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5892);
											mem_vec_5892 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5893);
											mem_vec_5893 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5894);
											mem_vec_5894 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5895);
											mem_vec_5895 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_5896);
											mem_vec_5896 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_5897);
											mem_vec_5897 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_5898);
											mem_vec_5898 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_5899);
											mem_vec_5899 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_5900);
											mem_vec_5900 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_5901);
											mem_vec_5901 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_5902);
											mem_vec_5902 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_5903);
											mem_vec_5903 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_40 = _mm256_set1_ps(scal_7);
											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_5876);
											mem_vec_5876 = vec_39;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_5877);
											mem_vec_5877 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_5878);
											mem_vec_5878 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_5879);
											mem_vec_5879 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_5880);
											mem_vec_5880 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_5881);
											mem_vec_5881 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_5882);
											mem_vec_5882 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_5883);
											mem_vec_5883 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_5884);
											mem_vec_5884 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_5885);
											mem_vec_5885 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_5886);
											mem_vec_5886 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_5887);
											mem_vec_5887 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_5888);
											mem_vec_5888 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_5889);
											mem_vec_5889 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_5890);
											mem_vec_5890 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_5891);
											mem_vec_5891 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_5892);
											mem_vec_5892 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_5893);
											mem_vec_5893 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_5894);
											mem_vec_5894 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_5895);
											mem_vec_5895 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_69 = _mm256_set1_ps(scal_12);


											vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_5896);
											mem_vec_5896 = vec_68;



											vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_5897);
											mem_vec_5897 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_5898);
											mem_vec_5898 = vec_71;



											vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_5899);
											mem_vec_5899 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_13);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_5900);
											mem_vec_5900 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_5901);
											mem_vec_5901 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_5902);
											mem_vec_5902 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_5903);
											mem_vec_5903 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_14);
											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_5876);
											mem_vec_5876 = vec_78;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_5877);
											mem_vec_5877 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_5878);
											mem_vec_5878 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_5879);
											mem_vec_5879 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_5880);
											mem_vec_5880 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_5881);
											mem_vec_5881 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_5882);
											mem_vec_5882 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_5883);
											mem_vec_5883 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_5884);
											mem_vec_5884 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_5885);
											mem_vec_5885 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_5886);
											mem_vec_5886 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_5887);
											mem_vec_5887 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_5888);
											mem_vec_5888 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_5889);
											mem_vec_5889 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_5890);
											mem_vec_5890 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_5891);
											mem_vec_5891 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_18);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_5892);
											mem_vec_5892 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_5893);
											mem_vec_5893 = vec_104;



											vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_5894);
											mem_vec_5894 = vec_105;



											vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_5895);
											mem_vec_5895 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_108 = _mm256_set1_ps(scal_19);


											vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_5896);
											mem_vec_5896 = vec_107;



											vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_5897);
											mem_vec_5897 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_5898);
											mem_vec_5898 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_5899);
											mem_vec_5899 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_113 = _mm256_set1_ps(scal_20);


											vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_5900);
											mem_vec_5900 = vec_112;



											vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_5901);
											mem_vec_5901 = vec_114;



											vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_5902);
											mem_vec_5902 = vec_115;



											vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_5903);
											mem_vec_5903 = vec_116;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5876);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5877);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5878);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5879);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5880);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5881);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5882);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5883);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5884);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5885);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5886);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5887);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5888);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5889);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5890);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5891);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5892);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5893);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5894);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5895);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5896);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_5897);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5898);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_5899);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5900);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_5901);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5902);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_5903);
							}
						}
					}
				}
		}
	}
}


}