#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); U (3, w); T (512, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (1, c); T (4, f); T (1, y); T (2, c); T (4, f)]
*/
IND_TYPE c, cp_0, c1128_p_0, c1129_p_0, cp_1, c1128_p_1, cp_2, c1128, c1129, f, fp_0, f846_p_0, fp_1, f846, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y564 = 0;
IND_TYPE x564 = 0;
IND_TYPE h452 = 0;
IND_TYPE w = 0;
IND_TYPE c1130 = 0;
IND_TYPE f847 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7896 ,mem_vec_7897 ,mem_vec_7898 ,mem_vec_7899 ,mem_vec_7900 ,mem_vec_7901 ,mem_vec_7902 ,mem_vec_7903 ,mem_vec_7904 ,mem_vec_7905 ,mem_vec_7906 ,mem_vec_7907 ,mem_vec_7908 ,mem_vec_7909 ,mem_vec_7910 ,mem_vec_7911 ,mem_vec_7912 ,mem_vec_7913 ,mem_vec_7914 ,mem_vec_7915 ,mem_vec_7916 ,mem_vec_7917 ,mem_vec_7918 ,mem_vec_7919 ,mem_vec_7920 ,mem_vec_7921 ,mem_vec_7922 ,mem_vec_7923 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (f, 4) (1024 / 256)
for (f846 = f847, f846_p_0 = 0;
	f846 < f847 + 1024;
	f846 += 256, f846_p_0 += 256){
	// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 256
	// T (c, 2) (1024 / 512)
	for (c1129 = c1130, c1129_p_0 = 0;
		c1129 < c1130 + 1024;
		c1129 += 512, c1129_p_0 += 512){
		// y = 7, x = 7, h = 3, w = 3, c = 512, f = 256
		// T (y, 1) (7 / 7)
		for (y = y564, yp_0 = 0;
			y < y564 + 7;
			y += 7, yp_0 += 7){
			// y = 7, x = 7, h = 3, w = 3, c = 512, f = 256
			// T (f, 4) (256 / 64)
			for (f = f846, fp_1 = f846_p_0, fp_0 = 0;
				f < f846 + 256;
				f += 64, fp_1 += 64, fp_0 += 64){
				// y = 7, x = 7, h = 3, w = 3, c = 512, f = 64
				// T (c, 1) (512 / 512)
				for (c1128 = c1129, c1128_p_1 = c1129_p_0, c1128_p_0 = 0;
					c1128 < c1129 + 512;
					c1128 += 512, c1128_p_1 += 512, c1128_p_0 += 512){
					// y = 7, x = 7, h = 3, w = 3, c = 512, f = 64
					// T (h, 3) (3 / 1)
					for (h = h452, hp_0 = 0;
						h < h452 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 7, h = 1, w = 3, c = 512, f = 64
						// T (x, 7) (7 / 1)
						for (x = x564, xp_0 = 0;
							x < x564 + 7;
							x += 1, xp_0 += 1){
									mem_vec_7896 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_7897 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_7898 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_7899 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_7900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_7901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_7903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_7904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_7905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_7906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_7907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_7908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_7909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_7910 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_7911 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_7912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_7913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_7914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_7915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_7916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_7917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_7918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_7919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_7920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_7921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_7922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_7923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = 7, x = 1, h = 1, w = 3, c = 512, f = 64
									// T (c, 512) (512 / 1)
									for (c = c1128, cp_2 = c1128_p_1, cp_1 = c1128_p_0, cp_0 = 0;
										c < c1128 + 512;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7896);
										mem_vec_7896 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7897);
										mem_vec_7897 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7898);
										mem_vec_7898 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7899);
										mem_vec_7899 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7900);
										mem_vec_7900 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7901);
										mem_vec_7901 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7902);
										mem_vec_7902 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7903);
										mem_vec_7903 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7904);
										mem_vec_7904 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7905);
										mem_vec_7905 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7906);
										mem_vec_7906 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7907);
										mem_vec_7907 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7908);
										mem_vec_7908 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7909);
										mem_vec_7909 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7910);
										mem_vec_7910 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7911);
										mem_vec_7911 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7912);
										mem_vec_7912 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7913);
										mem_vec_7913 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7914);
										mem_vec_7914 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7915);
										mem_vec_7915 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7916);
										mem_vec_7916 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7917);
										mem_vec_7917 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_7918);
										mem_vec_7918 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_7919);
										mem_vec_7919 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_7920);
										mem_vec_7920 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_7921);
										mem_vec_7921 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_7922);
										mem_vec_7922 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_7923);
										mem_vec_7923 = vec_38;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_7896);
										mem_vec_7896 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_7897);
										mem_vec_7897 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_7898);
										mem_vec_7898 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_7899);
										mem_vec_7899 = vec_46;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_7900);
										mem_vec_7900 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_7901);
										mem_vec_7901 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_7902);
										mem_vec_7902 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_7903);
										mem_vec_7903 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_7904);
										mem_vec_7904 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_7905);
										mem_vec_7905 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_7906);
										mem_vec_7906 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_7907);
										mem_vec_7907 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_7908);
										mem_vec_7908 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_7909);
										mem_vec_7909 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_7910);
										mem_vec_7910 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_7911);
										mem_vec_7911 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_7912);
										mem_vec_7912 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_7913);
										mem_vec_7913 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_7914);
										mem_vec_7914 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_7915);
										mem_vec_7915 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_7916);
										mem_vec_7916 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_7917);
										mem_vec_7917 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_7918);
										mem_vec_7918 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_7919);
										mem_vec_7919 = vec_72;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_7920);
										mem_vec_7920 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_7921);
										mem_vec_7921 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_7922);
										mem_vec_7922 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_7923);
										mem_vec_7923 = vec_77;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_7896);
										mem_vec_7896 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_7897);
										mem_vec_7897 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_7898);
										mem_vec_7898 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_7899);
										mem_vec_7899 = vec_85;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_7900);
										mem_vec_7900 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_7901);
										mem_vec_7901 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_7902);
										mem_vec_7902 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_7903);
										mem_vec_7903 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_7904);
										mem_vec_7904 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_7905);
										mem_vec_7905 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_7906);
										mem_vec_7906 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_7907);
										mem_vec_7907 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_7908);
										mem_vec_7908 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_7909);
										mem_vec_7909 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_7910);
										mem_vec_7910 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_7911);
										mem_vec_7911 = vec_101;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_7912);
										mem_vec_7912 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_7913);
										mem_vec_7913 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_7914);
										mem_vec_7914 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_7915);
										mem_vec_7915 = vec_106;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_7916);
										mem_vec_7916 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_7917);
										mem_vec_7917 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_7918);
										mem_vec_7918 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_7919);
										mem_vec_7919 = vec_111;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_7920);
										mem_vec_7920 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_7921);
										mem_vec_7921 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_7922);
										mem_vec_7922 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_7923);
										mem_vec_7923 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7896);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7897);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7898);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7899);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7900);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7901);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7902);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7903);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7904);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7905);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7906);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7907);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7908);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7909);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7910);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7911);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7912);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7913);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_7914);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_7915);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7916);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7917);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_7918);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_7919);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7920);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7921);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_7922);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_7923);
						}
					}
				}
			}
		}
	}
}


}