#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); U (3, w); T (16, c); Hoist_vars [c];
  T (17, x); T (4, c);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]; T (64, f);
  T (8, c); T (1, f)]
*/
IND_TYPE c, cp_0, c376_p_0, c377_p_0, cp_1, c376_p_1, cp_2, c376, c377, f, fp_0, f282_p_0, fp_1, f282, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y188 = 0;
IND_TYPE x188 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c378 = 0;
IND_TYPE f283 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_45 ,scal_46 ,scal_47 ,scal_48 ,scal_49 ,scal_5 ,scal_50 ,scal_51 ,scal_52 ,scal_53 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1843 ,mem_vec_1844 ,mem_vec_1845 ,mem_vec_1846 ,mem_vec_1847 ,mem_vec_1848 ,mem_vec_1849 ,mem_vec_1850 ,mem_vec_1851 ,mem_vec_1852 ,mem_vec_1853 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 1) (1024 / 1024)
for (f282 = f283, f282_p_0 = 0;
	f282 < f283 + 1024;
	f282 += 1024, f282_p_0 += 1024){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 8) (512 / 64)
	for (c377 = c378, c377_p_0 = 0;
		c377 < c378 + 512;
		c377 += 64, c377_p_0 += 64){
		// y = 17, x = 17, h = 3, w = 3, c = 64, f = 1024
		// T (f, 64) (1024 / 16)
		for (f = f282, fp_1 = f282_p_0, fp_0 = 0;
			f < f282 + 1024;
			f += 16, fp_1 += 16, fp_0 += 16){
				for (y = y188, yp_0 = 0;
					y < y188 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
					// T (c, 4) (64 / 16)
					for (c376 = c377, c376_p_1 = c377_p_0, c376_p_0 = 0;
						c376 < c377 + 64;
						c376 += 16, c376_p_1 += 16, c376_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 16
						// T (x, 17) (17 / 1)
						for (x = x188, xp_0 = 0;
							x < x188 + 17;
							x += 1, xp_0 += 1){
									mem_vec_1843 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
									// T (c, 16) (16 / 1)
									for (c = c376, cp_2 = c376_p_1, cp_1 = c376_p_0, cp_0 = 0;
										c < c376 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1843);
										mem_vec_1843 = vec_0;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1844);
										mem_vec_1844 = vec_3;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1845);
										mem_vec_1845 = vec_5;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1846);
										mem_vec_1846 = vec_7;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1847);
										mem_vec_1847 = vec_9;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_12 = _mm512_set1_ps(scal_5);
										vec_13 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_11 = _mm512_fmadd_ps(vec_12, vec_13, mem_vec_1843);
										mem_vec_1843 = vec_11;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_15 = _mm512_set1_ps(scal_6);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_13, mem_vec_1844);
										mem_vec_1844 = vec_14;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_17 = _mm512_set1_ps(scal_7);


										vec_16 = _mm512_fmadd_ps(vec_17, vec_13, mem_vec_1845);
										mem_vec_1845 = vec_16;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_19 = _mm512_set1_ps(scal_8);


										vec_18 = _mm512_fmadd_ps(vec_19, vec_13, mem_vec_1846);
										mem_vec_1846 = vec_18;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_21 = _mm512_set1_ps(scal_9);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_13, mem_vec_1847);
										mem_vec_1847 = vec_20;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_23 = _mm512_set1_ps(scal_10);
										vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_22 = _mm512_fmadd_ps(vec_23, vec_24, mem_vec_1843);
										mem_vec_1843 = vec_22;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_26 = _mm512_set1_ps(scal_11);


										vec_25 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_1844);
										mem_vec_1844 = vec_25;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_28 = _mm512_set1_ps(scal_12);


										vec_27 = _mm512_fmadd_ps(vec_28, vec_24, mem_vec_1845);
										mem_vec_1845 = vec_27;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_30 = _mm512_set1_ps(scal_13);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_24, mem_vec_1846);
										mem_vec_1846 = vec_29;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_32 = _mm512_set1_ps(scal_14);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_1847);
										mem_vec_1847 = vec_31;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_34 = _mm512_set1_ps(scal_15);
										vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_33 = _mm512_fmadd_ps(vec_34, vec_35, mem_vec_1843);
										mem_vec_1843 = vec_33;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_37 = _mm512_set1_ps(scal_16);


										vec_36 = _mm512_fmadd_ps(vec_37, vec_35, mem_vec_1844);
										mem_vec_1844 = vec_36;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_39 = _mm512_set1_ps(scal_17);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_1845);
										mem_vec_1845 = vec_38;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_41 = _mm512_set1_ps(scal_18);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_35, mem_vec_1846);
										mem_vec_1846 = vec_40;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_43 = _mm512_set1_ps(scal_19);


										vec_42 = _mm512_fmadd_ps(vec_43, vec_35, mem_vec_1847);
										mem_vec_1847 = vec_42;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
										vec_45 = _mm512_set1_ps(scal_20);
										vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

										vec_44 = _mm512_fmadd_ps(vec_45, vec_46, mem_vec_1843);
										mem_vec_1843 = vec_44;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
										vec_48 = _mm512_set1_ps(scal_21);


										vec_47 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_1844);
										mem_vec_1844 = vec_47;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
										vec_50 = _mm512_set1_ps(scal_22);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_46, mem_vec_1845);
										mem_vec_1845 = vec_49;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
										vec_52 = _mm512_set1_ps(scal_23);


										vec_51 = _mm512_fmadd_ps(vec_52, vec_46, mem_vec_1846);
										mem_vec_1846 = vec_51;
										scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_24);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_46, mem_vec_1847);
										mem_vec_1847 = vec_53;
										scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
										vec_56 = _mm512_set1_ps(scal_25);
										vec_57 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

										vec_55 = _mm512_fmadd_ps(vec_56, vec_57, mem_vec_1843);
										mem_vec_1843 = vec_55;
										scal_26 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
										vec_59 = _mm512_set1_ps(scal_26);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_57, mem_vec_1844);
										mem_vec_1844 = vec_58;
										scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
										vec_61 = _mm512_set1_ps(scal_27);


										vec_60 = _mm512_fmadd_ps(vec_61, vec_57, mem_vec_1845);
										mem_vec_1845 = vec_60;
										scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
										vec_63 = _mm512_set1_ps(scal_28);


										vec_62 = _mm512_fmadd_ps(vec_63, vec_57, mem_vec_1846);
										mem_vec_1846 = vec_62;
										scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
										vec_65 = _mm512_set1_ps(scal_29);


										vec_64 = _mm512_fmadd_ps(vec_65, vec_57, mem_vec_1847);
										mem_vec_1847 = vec_64;
										scal_30 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_67 = _mm512_set1_ps(scal_30);
										vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_66 = _mm512_fmadd_ps(vec_67, vec_68, mem_vec_1843);
										mem_vec_1843 = vec_66;
										scal_31 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_70 = _mm512_set1_ps(scal_31);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_1844);
										mem_vec_1844 = vec_69;
										scal_32 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_72 = _mm512_set1_ps(scal_32);


										vec_71 = _mm512_fmadd_ps(vec_72, vec_68, mem_vec_1845);
										mem_vec_1845 = vec_71;
										scal_33 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_74 = _mm512_set1_ps(scal_33);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_68, mem_vec_1846);
										mem_vec_1846 = vec_73;
										scal_34 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_76 = _mm512_set1_ps(scal_34);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_1847);
										mem_vec_1847 = vec_75;
										scal_35 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
										vec_78 = _mm512_set1_ps(scal_35);
										vec_79 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

										vec_77 = _mm512_fmadd_ps(vec_78, vec_79, mem_vec_1843);
										mem_vec_1843 = vec_77;
										scal_36 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
										vec_81 = _mm512_set1_ps(scal_36);


										vec_80 = _mm512_fmadd_ps(vec_81, vec_79, mem_vec_1844);
										mem_vec_1844 = vec_80;
										scal_37 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
										vec_83 = _mm512_set1_ps(scal_37);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_79, mem_vec_1845);
										mem_vec_1845 = vec_82;
										scal_38 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
										vec_85 = _mm512_set1_ps(scal_38);


										vec_84 = _mm512_fmadd_ps(vec_85, vec_79, mem_vec_1846);
										mem_vec_1846 = vec_84;
										scal_39 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
										vec_87 = _mm512_set1_ps(scal_39);


										vec_86 = _mm512_fmadd_ps(vec_87, vec_79, mem_vec_1847);
										mem_vec_1847 = vec_86;
										scal_40 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
										vec_89 = _mm512_set1_ps(scal_40);
										vec_90 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

										vec_88 = _mm512_fmadd_ps(vec_89, vec_90, mem_vec_1843);
										mem_vec_1843 = vec_88;
										scal_41 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
										vec_92 = _mm512_set1_ps(scal_41);


										vec_91 = _mm512_fmadd_ps(vec_92, vec_90, mem_vec_1844);
										mem_vec_1844 = vec_91;
										scal_42 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
										vec_94 = _mm512_set1_ps(scal_42);


										vec_93 = _mm512_fmadd_ps(vec_94, vec_90, mem_vec_1845);
										mem_vec_1845 = vec_93;
										scal_43 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
										vec_96 = _mm512_set1_ps(scal_43);


										vec_95 = _mm512_fmadd_ps(vec_96, vec_90, mem_vec_1846);
										mem_vec_1846 = vec_95;
										scal_44 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_44);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_90, mem_vec_1847);
										mem_vec_1847 = vec_97;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1843);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1844);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1845);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1846);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1847);
						}
					}
				}
				for (y = y188 + 5, yp_0 = 0;
					y < y188 + 5 + 12;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
					// T (c, 4) (64 / 16)
					for (c376 = c377, c376_p_1 = c377_p_0, c376_p_0 = 0;
						c376 < c377 + 64;
						c376 += 16, c376_p_1 += 16, c376_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 16
						// T (x, 17) (17 / 1)
						for (x = x188, xp_0 = 0;
							x < x188 + 17;
							x += 1, xp_0 += 1){
									mem_vec_1848 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
									// T (c, 16) (16 / 1)
									for (c = c376, cp_2 = c376_p_1, cp_1 = c376_p_0, cp_0 = 0;
										c < c376 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1848);
										mem_vec_1848 = vec_0;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1849);
										mem_vec_1849 = vec_3;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1850);
										mem_vec_1850 = vec_5;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1851);
										mem_vec_1851 = vec_7;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1852);
										mem_vec_1852 = vec_9;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_12 = _mm512_set1_ps(scal_5);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1853);
										mem_vec_1853 = vec_11;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_14 = _mm512_set1_ps(scal_6);
										vec_15 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_13 = _mm512_fmadd_ps(vec_14, vec_15, mem_vec_1848);
										mem_vec_1848 = vec_13;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_17 = _mm512_set1_ps(scal_7);


										vec_16 = _mm512_fmadd_ps(vec_17, vec_15, mem_vec_1849);
										mem_vec_1849 = vec_16;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_19 = _mm512_set1_ps(scal_8);


										vec_18 = _mm512_fmadd_ps(vec_19, vec_15, mem_vec_1850);
										mem_vec_1850 = vec_18;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_21 = _mm512_set1_ps(scal_9);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_15, mem_vec_1851);
										mem_vec_1851 = vec_20;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_23 = _mm512_set1_ps(scal_10);


										vec_22 = _mm512_fmadd_ps(vec_23, vec_15, mem_vec_1852);
										mem_vec_1852 = vec_22;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_25 = _mm512_set1_ps(scal_11);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_15, mem_vec_1853);
										mem_vec_1853 = vec_24;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_27 = _mm512_set1_ps(scal_12);
										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_1848);
										mem_vec_1848 = vec_26;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_30 = _mm512_set1_ps(scal_13);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_28, mem_vec_1849);
										mem_vec_1849 = vec_29;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_32 = _mm512_set1_ps(scal_14);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_1850);
										mem_vec_1850 = vec_31;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_34 = _mm512_set1_ps(scal_15);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_1851);
										mem_vec_1851 = vec_33;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_36 = _mm512_set1_ps(scal_16);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_28, mem_vec_1852);
										mem_vec_1852 = vec_35;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_38 = _mm512_set1_ps(scal_17);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_1853);
										mem_vec_1853 = vec_37;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_40 = _mm512_set1_ps(scal_18);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_1848);
										mem_vec_1848 = vec_39;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_43 = _mm512_set1_ps(scal_19);


										vec_42 = _mm512_fmadd_ps(vec_43, vec_41, mem_vec_1849);
										mem_vec_1849 = vec_42;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_45 = _mm512_set1_ps(scal_20);


										vec_44 = _mm512_fmadd_ps(vec_45, vec_41, mem_vec_1850);
										mem_vec_1850 = vec_44;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_47 = _mm512_set1_ps(scal_21);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_41, mem_vec_1851);
										mem_vec_1851 = vec_46;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_49 = _mm512_set1_ps(scal_22);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_1852);
										mem_vec_1852 = vec_48;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_51 = _mm512_set1_ps(scal_23);


										vec_50 = _mm512_fmadd_ps(vec_51, vec_41, mem_vec_1853);
										mem_vec_1853 = vec_50;
										scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
										vec_53 = _mm512_set1_ps(scal_24);
										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

										vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_1848);
										mem_vec_1848 = vec_52;
										scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
										vec_56 = _mm512_set1_ps(scal_25);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_54, mem_vec_1849);
										mem_vec_1849 = vec_55;
										scal_26 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
										vec_58 = _mm512_set1_ps(scal_26);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_1850);
										mem_vec_1850 = vec_57;
										scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
										vec_60 = _mm512_set1_ps(scal_27);


										vec_59 = _mm512_fmadd_ps(vec_60, vec_54, mem_vec_1851);
										mem_vec_1851 = vec_59;
										scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
										vec_62 = _mm512_set1_ps(scal_28);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_54, mem_vec_1852);
										mem_vec_1852 = vec_61;
										scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_29);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_1853);
										mem_vec_1853 = vec_63;
										scal_30 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
										vec_66 = _mm512_set1_ps(scal_30);
										vec_67 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

										vec_65 = _mm512_fmadd_ps(vec_66, vec_67, mem_vec_1848);
										mem_vec_1848 = vec_65;
										scal_31 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
										vec_69 = _mm512_set1_ps(scal_31);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_67, mem_vec_1849);
										mem_vec_1849 = vec_68;
										scal_32 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
										vec_71 = _mm512_set1_ps(scal_32);


										vec_70 = _mm512_fmadd_ps(vec_71, vec_67, mem_vec_1850);
										mem_vec_1850 = vec_70;
										scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
										vec_73 = _mm512_set1_ps(scal_33);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_67, mem_vec_1851);
										mem_vec_1851 = vec_72;
										scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
										vec_75 = _mm512_set1_ps(scal_34);


										vec_74 = _mm512_fmadd_ps(vec_75, vec_67, mem_vec_1852);
										mem_vec_1852 = vec_74;
										scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
										vec_77 = _mm512_set1_ps(scal_35);


										vec_76 = _mm512_fmadd_ps(vec_77, vec_67, mem_vec_1853);
										mem_vec_1853 = vec_76;
										scal_36 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_79 = _mm512_set1_ps(scal_36);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_1848);
										mem_vec_1848 = vec_78;
										scal_37 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_82 = _mm512_set1_ps(scal_37);


										vec_81 = _mm512_fmadd_ps(vec_82, vec_80, mem_vec_1849);
										mem_vec_1849 = vec_81;
										scal_38 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_84 = _mm512_set1_ps(scal_38);


										vec_83 = _mm512_fmadd_ps(vec_84, vec_80, mem_vec_1850);
										mem_vec_1850 = vec_83;
										scal_39 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_86 = _mm512_set1_ps(scal_39);


										vec_85 = _mm512_fmadd_ps(vec_86, vec_80, mem_vec_1851);
										mem_vec_1851 = vec_85;
										scal_40 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_88 = _mm512_set1_ps(scal_40);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_1852);
										mem_vec_1852 = vec_87;
										scal_41 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_90 = _mm512_set1_ps(scal_41);


										vec_89 = _mm512_fmadd_ps(vec_90, vec_80, mem_vec_1853);
										mem_vec_1853 = vec_89;
										scal_42 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
										vec_92 = _mm512_set1_ps(scal_42);
										vec_93 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

										vec_91 = _mm512_fmadd_ps(vec_92, vec_93, mem_vec_1848);
										mem_vec_1848 = vec_91;
										scal_43 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
										vec_95 = _mm512_set1_ps(scal_43);


										vec_94 = _mm512_fmadd_ps(vec_95, vec_93, mem_vec_1849);
										mem_vec_1849 = vec_94;
										scal_44 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
										vec_97 = _mm512_set1_ps(scal_44);


										vec_96 = _mm512_fmadd_ps(vec_97, vec_93, mem_vec_1850);
										mem_vec_1850 = vec_96;
										scal_45 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
										vec_99 = _mm512_set1_ps(scal_45);


										vec_98 = _mm512_fmadd_ps(vec_99, vec_93, mem_vec_1851);
										mem_vec_1851 = vec_98;
										scal_46 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
										vec_101 = _mm512_set1_ps(scal_46);


										vec_100 = _mm512_fmadd_ps(vec_101, vec_93, mem_vec_1852);
										mem_vec_1852 = vec_100;
										scal_47 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
										vec_103 = _mm512_set1_ps(scal_47);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_93, mem_vec_1853);
										mem_vec_1853 = vec_102;
										scal_48 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
										vec_105 = _mm512_set1_ps(scal_48);
										vec_106 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

										vec_104 = _mm512_fmadd_ps(vec_105, vec_106, mem_vec_1848);
										mem_vec_1848 = vec_104;
										scal_49 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
										vec_108 = _mm512_set1_ps(scal_49);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_106, mem_vec_1849);
										mem_vec_1849 = vec_107;
										scal_50 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
										vec_110 = _mm512_set1_ps(scal_50);


										vec_109 = _mm512_fmadd_ps(vec_110, vec_106, mem_vec_1850);
										mem_vec_1850 = vec_109;
										scal_51 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
										vec_112 = _mm512_set1_ps(scal_51);


										vec_111 = _mm512_fmadd_ps(vec_112, vec_106, mem_vec_1851);
										mem_vec_1851 = vec_111;
										scal_52 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
										vec_114 = _mm512_set1_ps(scal_52);


										vec_113 = _mm512_fmadd_ps(vec_114, vec_106, mem_vec_1852);
										mem_vec_1852 = vec_113;
										scal_53 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
										vec_116 = _mm512_set1_ps(scal_53);


										vec_115 = _mm512_fmadd_ps(vec_116, vec_106, mem_vec_1853);
										mem_vec_1853 = vec_115;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1848);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1849);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1850);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1851);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1852);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1853);
						}
					}
				}
		}
	}
}


}