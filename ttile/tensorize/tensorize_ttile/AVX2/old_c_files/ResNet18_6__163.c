#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); U (4, y); U (3, w); T (8, c); Hoist_vars [c]; T (3, h);
  T (28, x); T (8, c); T (7, y); T (2, f); T (2, c); T (1, f)]
*/
IND_TYPE c, cp_0, c751_p_0, c752_p_0, cp_1, c751_p_1, cp_2, c751, c752, f, fp_0, f748_p_0, fp_1, f748, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y395 = 0;
IND_TYPE x382 = 0;
IND_TYPE h301 = 0;
IND_TYPE w = 0;
IND_TYPE c753 = 0;
IND_TYPE f749 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_4896 ,mem_vec_4897 ,mem_vec_4898 ,mem_vec_4899 ,mem_vec_4900 ,mem_vec_4901 ,mem_vec_4902 ,mem_vec_4903 ,mem_vec_4904 ,mem_vec_4905 ,mem_vec_4906 ,mem_vec_4907 ,mem_vec_4908 ,mem_vec_4909 ,mem_vec_4910 ,mem_vec_4911 ,mem_vec_4912 ,mem_vec_4913 ,mem_vec_4914 ,mem_vec_4915 ,mem_vec_4916 ,mem_vec_4917 ,mem_vec_4918 ,mem_vec_4919 ,mem_vec_4920 ,mem_vec_4921 ,mem_vec_4922 ,mem_vec_4923 ,mem_vec_4924 ,mem_vec_4925 ,mem_vec_4926 ,mem_vec_4927 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
for (f748 = f749, f748_p_0 = 0;
	f748 < f749 + 128;
	f748 += 128, f748_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (c, 2) (128 / 64)
	for (c752 = c753, c752_p_0 = 0;
		c752 < c753 + 128;
		c752 += 64, c752_p_0 += 64){
		// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
		// T (f, 2) (128 / 64)
		for (f = f748, fp_1 = f748_p_0, fp_0 = 0;
			f < f748 + 128;
			f += 64, fp_1 += 64, fp_0 += 64){
			// y = 28, x = 28, h = 3, w = 3, c = 64, f = 64
			// T (y, 7) (28 / 4)
			for (y = y395, yp_0 = 0;
				y < y395 + 28;
				y += 4, yp_0 += 4){
				// y = 4, x = 28, h = 3, w = 3, c = 64, f = 64
				// T (c, 8) (64 / 8)
				for (c751 = c752, c751_p_1 = c752_p_0, c751_p_0 = 0;
					c751 < c752 + 64;
					c751 += 8, c751_p_1 += 8, c751_p_0 += 8){
					// y = 4, x = 28, h = 3, w = 3, c = 8, f = 64
					// T (x, 28) (28 / 1)
					for (x = x382, xp_0 = 0;
						x < x382 + 28;
						x += 1, xp_0 += 1){
						// y = 4, x = 1, h = 3, w = 3, c = 8, f = 64
						// T (h, 3) (3 / 1)
						for (h = h301, hp_0 = 0;
							h < h301 + 3;
							h += 1, hp_0 += 1){
									mem_vec_4896 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4897 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_4898 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4899 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_4900 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_4901 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
									mem_vec_4902 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_4903 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
									mem_vec_4904 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4905 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_4906 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4907 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_4908 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_4909 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
									mem_vec_4910 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_4911 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
									mem_vec_4912 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4913 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_4914 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4915 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_4916 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_4917 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
									mem_vec_4918 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_4919 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
									mem_vec_4920 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_4921 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_4922 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_4923 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_4924 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_4925 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
									mem_vec_4926 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_4927 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
									// y = 4, x = 1, h = 1, w = 3, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c751, cp_2 = c751_p_1, cp_1 = c751_p_0, cp_0 = 0;
										c < c751 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4896);
										mem_vec_4896 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4897);
										mem_vec_4897 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4898);
										mem_vec_4898 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4899);
										mem_vec_4899 = vec_7;

										vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_4900);
										mem_vec_4900 = vec_9;

										vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

										vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_4901);
										mem_vec_4901 = vec_11;

										vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_4902);
										mem_vec_4902 = vec_13;

										vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

										vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_4903);
										mem_vec_4903 = vec_15;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_18 = _mm256_set1_ps(scal_1);


										vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_4904);
										mem_vec_4904 = vec_17;



										vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_4905);
										mem_vec_4905 = vec_19;



										vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_4906);
										mem_vec_4906 = vec_20;



										vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_4907);
										mem_vec_4907 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_4908);
										mem_vec_4908 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_4909);
										mem_vec_4909 = vec_23;



										vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_4910);
										mem_vec_4910 = vec_24;



										vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_4911);
										mem_vec_4911 = vec_25;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_27 = _mm256_set1_ps(scal_2);


										vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_4912);
										mem_vec_4912 = vec_26;



										vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_4913);
										mem_vec_4913 = vec_28;



										vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_4914);
										mem_vec_4914 = vec_29;



										vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_4915);
										mem_vec_4915 = vec_30;



										vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_4916);
										mem_vec_4916 = vec_31;



										vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_4917);
										mem_vec_4917 = vec_32;



										vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_4918);
										mem_vec_4918 = vec_33;



										vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_4919);
										mem_vec_4919 = vec_34;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_36 = _mm256_set1_ps(scal_3);


										vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_4920);
										mem_vec_4920 = vec_35;



										vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_4921);
										mem_vec_4921 = vec_37;



										vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_4922);
										mem_vec_4922 = vec_38;



										vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_4923);
										mem_vec_4923 = vec_39;



										vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_4924);
										mem_vec_4924 = vec_40;



										vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_4925);
										mem_vec_4925 = vec_41;



										vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_4926);
										mem_vec_4926 = vec_42;



										vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_4927);
										mem_vec_4927 = vec_43;
										scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_45 = _mm256_set1_ps(scal_4);
										vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_4896);
										mem_vec_4896 = vec_44;

										vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

										vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_4897);
										mem_vec_4897 = vec_47;

										vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_4898);
										mem_vec_4898 = vec_49;

										vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

										vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_4899);
										mem_vec_4899 = vec_51;

										vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_4900);
										mem_vec_4900 = vec_53;

										vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

										vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_4901);
										mem_vec_4901 = vec_55;

										vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_4902);
										mem_vec_4902 = vec_57;

										vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

										vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_4903);
										mem_vec_4903 = vec_59;
										scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_62 = _mm256_set1_ps(scal_5);


										vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_4904);
										mem_vec_4904 = vec_61;



										vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_4905);
										mem_vec_4905 = vec_63;



										vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_4906);
										mem_vec_4906 = vec_64;



										vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_4907);
										mem_vec_4907 = vec_65;



										vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_4908);
										mem_vec_4908 = vec_66;



										vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_4909);
										mem_vec_4909 = vec_67;



										vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_4910);
										mem_vec_4910 = vec_68;



										vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_4911);
										mem_vec_4911 = vec_69;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_71 = _mm256_set1_ps(scal_6);


										vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_4912);
										mem_vec_4912 = vec_70;



										vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_4913);
										mem_vec_4913 = vec_72;



										vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_4914);
										mem_vec_4914 = vec_73;



										vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_4915);
										mem_vec_4915 = vec_74;



										vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_4916);
										mem_vec_4916 = vec_75;



										vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_4917);
										mem_vec_4917 = vec_76;



										vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_4918);
										mem_vec_4918 = vec_77;



										vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_4919);
										mem_vec_4919 = vec_78;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_80 = _mm256_set1_ps(scal_7);


										vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_4920);
										mem_vec_4920 = vec_79;



										vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_4921);
										mem_vec_4921 = vec_81;



										vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_4922);
										mem_vec_4922 = vec_82;



										vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_4923);
										mem_vec_4923 = vec_83;



										vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_4924);
										mem_vec_4924 = vec_84;



										vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_4925);
										mem_vec_4925 = vec_85;



										vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_4926);
										mem_vec_4926 = vec_86;



										vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_4927);
										mem_vec_4927 = vec_87;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_89 = _mm256_set1_ps(scal_8);
										vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_4896);
										mem_vec_4896 = vec_88;

										vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

										vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_4897);
										mem_vec_4897 = vec_91;

										vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_4898);
										mem_vec_4898 = vec_93;

										vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

										vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_4899);
										mem_vec_4899 = vec_95;

										vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_4900);
										mem_vec_4900 = vec_97;

										vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

										vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_4901);
										mem_vec_4901 = vec_99;

										vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_4902);
										mem_vec_4902 = vec_101;

										vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

										vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_4903);
										mem_vec_4903 = vec_103;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_106 = _mm256_set1_ps(scal_9);


										vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_4904);
										mem_vec_4904 = vec_105;



										vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_4905);
										mem_vec_4905 = vec_107;



										vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_4906);
										mem_vec_4906 = vec_108;



										vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_4907);
										mem_vec_4907 = vec_109;



										vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_4908);
										mem_vec_4908 = vec_110;



										vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_4909);
										mem_vec_4909 = vec_111;



										vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_4910);
										mem_vec_4910 = vec_112;



										vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_4911);
										mem_vec_4911 = vec_113;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_115 = _mm256_set1_ps(scal_10);


										vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_4912);
										mem_vec_4912 = vec_114;



										vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_4913);
										mem_vec_4913 = vec_116;



										vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_4914);
										mem_vec_4914 = vec_117;



										vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_4915);
										mem_vec_4915 = vec_118;



										vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_4916);
										mem_vec_4916 = vec_119;



										vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_4917);
										mem_vec_4917 = vec_120;



										vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_4918);
										mem_vec_4918 = vec_121;



										vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_4919);
										mem_vec_4919 = vec_122;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_124 = _mm256_set1_ps(scal_11);


										vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_4920);
										mem_vec_4920 = vec_123;



										vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_4921);
										mem_vec_4921 = vec_125;



										vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_4922);
										mem_vec_4922 = vec_126;



										vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_4923);
										mem_vec_4923 = vec_127;



										vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_4924);
										mem_vec_4924 = vec_128;



										vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_4925);
										mem_vec_4925 = vec_129;



										vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_4926);
										mem_vec_4926 = vec_130;



										vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_4927);
										mem_vec_4927 = vec_131;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4896);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4897);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4898);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4899);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4900);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_4901);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4902);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_4903);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4904);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4905);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4906);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4907);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4908);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_4909);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4910);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_4911);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4912);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4913);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4914);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4915);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4916);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_4917);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4918);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_4919);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4920);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4921);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4922);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4923);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4924);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_4925);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4926);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_4927);
						}
					}
				}
			}
		}
	}
}


}