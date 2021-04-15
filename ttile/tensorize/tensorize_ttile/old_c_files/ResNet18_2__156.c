#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (8, c); T (56, x);
  Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))]; T (1, c)]
*/
IND_TYPE c, cp_0, c1080_p_0, c1081_p_0, cp_1, c1080_p_1, cp_2, c1080, c1081, w, wp_0, x, xp_0, x1202_p_0, xp_1, x1202, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y652 = 0;
IND_TYPE x1203 = 0;
IND_TYPE h = 0;
IND_TYPE w618 = 0;
IND_TYPE c1082 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10854 ,mem_vec_10855 ,mem_vec_10856 ,mem_vec_10857 ,mem_vec_10858 ,mem_vec_10859 ,mem_vec_10860 ,mem_vec_10861 ,mem_vec_10862 ,mem_vec_10863 ,mem_vec_10864 ,mem_vec_10865 ,mem_vec_10866 ,mem_vec_10867 ,mem_vec_10868 ,mem_vec_10869 ,mem_vec_10870 ,mem_vec_10871 ,mem_vec_10872 ,mem_vec_10873 ,mem_vec_10874 ,mem_vec_10875 ,mem_vec_10876 ,mem_vec_10877 ,mem_vec_10878 ,mem_vec_10879 ,mem_vec_10880 ,mem_vec_10881 ,mem_vec_10882 ,mem_vec_10883 ,mem_vec_10884 ,mem_vec_10885 ,mem_vec_10886 ,mem_vec_10887 ,mem_vec_10888 ,mem_vec_10889 ,mem_vec_10890 ,mem_vec_10891 ,mem_vec_10892 ,mem_vec_10893 ,mem_vec_10894 ,mem_vec_10895 ,mem_vec_10896 ,mem_vec_10897 ,mem_vec_10898 ,mem_vec_10899 ,mem_vec_10900 ,mem_vec_10901 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 1) (64 / 64)
for (c1081 = c1082, c1081_p_0 = 0;
	c1081 < c1082 + 64;
	c1081 += 64, c1081_p_0 += 64){
		for (y = y652, yp_0 = 0;
			y < y652 + 35;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 56) (56 / 1)
			for (x1202 = x1203, x1202_p_0 = 0;
				x1202 < x1203 + 56;
				x1202 += 1, x1202_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 64
				// T (c, 8) (64 / 8)
				for (c1080 = c1081, c1080_p_1 = c1081_p_0, c1080_p_0 = 0;
					c1080 < c1081 + 64;
					c1080 += 8, c1080_p_1 += 8, c1080_p_0 += 8){
					// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 64
					// T (w, 3) (3 / 1)
					for (w = w618, wp_0 = 0;
						w < w618 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1202, xp_1 = x1202_p_0, xp_0 = 0;
							x < x1202 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10854 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10855 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10856 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10857 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_10870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_10873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1080, cp_2 = c1080_p_1, cp_1 = c1080_p_0, cp_0 = 0;
										c < c1080 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10854);
										mem_vec_10854 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10855);
										mem_vec_10855 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10856);
										mem_vec_10856 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10857);
										mem_vec_10857 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10858);
										mem_vec_10858 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10859);
										mem_vec_10859 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10860);
										mem_vec_10860 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10861);
										mem_vec_10861 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10862);
										mem_vec_10862 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10863);
										mem_vec_10863 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10864);
										mem_vec_10864 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10865);
										mem_vec_10865 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10866);
										mem_vec_10866 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10867);
										mem_vec_10867 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10868);
										mem_vec_10868 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10869);
										mem_vec_10869 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10870);
										mem_vec_10870 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10871);
										mem_vec_10871 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10872);
										mem_vec_10872 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10873);
										mem_vec_10873 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_10854);
										mem_vec_10854 = vec_29;

										vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_10855);
										mem_vec_10855 = vec_32;

										vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_10856);
										mem_vec_10856 = vec_34;

										vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_10857);
										mem_vec_10857 = vec_36;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_6);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_10858);
										mem_vec_10858 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_10859);
										mem_vec_10859 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_10860);
										mem_vec_10860 = vec_41;



										vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_10861);
										mem_vec_10861 = vec_42;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_10862);
										mem_vec_10862 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_10863);
										mem_vec_10863 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_10864);
										mem_vec_10864 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_10865);
										mem_vec_10865 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_10866);
										mem_vec_10866 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_10867);
										mem_vec_10867 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_10868);
										mem_vec_10868 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_10869);
										mem_vec_10869 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_10870);
										mem_vec_10870 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_10871);
										mem_vec_10871 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_10872);
										mem_vec_10872 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_10873);
										mem_vec_10873 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_59 = _mm512_set1_ps(scal_10);
										vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_10854);
										mem_vec_10854 = vec_58;

										vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_10855);
										mem_vec_10855 = vec_61;

										vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_10856);
										mem_vec_10856 = vec_63;

										vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_10857);
										mem_vec_10857 = vec_65;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_68 = _mm512_set1_ps(scal_11);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_10858);
										mem_vec_10858 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_10859);
										mem_vec_10859 = vec_69;



										vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_10860);
										mem_vec_10860 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_10861);
										mem_vec_10861 = vec_71;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_73 = _mm512_set1_ps(scal_12);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_10862);
										mem_vec_10862 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_10863);
										mem_vec_10863 = vec_74;



										vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_10864);
										mem_vec_10864 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_10865);
										mem_vec_10865 = vec_76;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_78 = _mm512_set1_ps(scal_13);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_10866);
										mem_vec_10866 = vec_77;



										vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_10867);
										mem_vec_10867 = vec_79;



										vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_10868);
										mem_vec_10868 = vec_80;



										vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_10869);
										mem_vec_10869 = vec_81;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_83 = _mm512_set1_ps(scal_14);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_10870);
										mem_vec_10870 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_10871);
										mem_vec_10871 = vec_84;



										vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_10872);
										mem_vec_10872 = vec_85;



										vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_10873);
										mem_vec_10873 = vec_86;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10854);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10855);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10856);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10857);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10858);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10859);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10860);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10861);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10862);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10863);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10864);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10865);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10866);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10867);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10868);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10869);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10870);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10871);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10872);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10873);
						}
					}
				}
			}
		}
		for (y = y652 + 35, yp_0 = 0;
			y < y652 + 35 + 21;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 56) (56 / 1)
			for (x1202 = x1203, x1202_p_0 = 0;
				x1202 < x1203 + 56;
				x1202 += 1, x1202_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 64
				// T (c, 8) (64 / 8)
				for (c1080 = c1081, c1080_p_1 = c1081_p_0, c1080_p_0 = 0;
					c1080 < c1081 + 64;
					c1080 += 8, c1080_p_1 += 8, c1080_p_0 += 8){
					// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 64
					// T (w, 3) (3 / 1)
					for (w = w618, wp_0 = 0;
						w < w618 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1202, xp_1 = x1202_p_0, xp_0 = 0;
							x < x1202 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10874 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10875 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10876 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10877 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10880 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10881 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10882 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_10890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_10893 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_10894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_10897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_10898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_10899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_10900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_10901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1080, cp_2 = c1080_p_1, cp_1 = c1080_p_0, cp_0 = 0;
										c < c1080 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10874);
										mem_vec_10874 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10875);
										mem_vec_10875 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10876);
										mem_vec_10876 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10877);
										mem_vec_10877 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10878);
										mem_vec_10878 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10879);
										mem_vec_10879 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10880);
										mem_vec_10880 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10881);
										mem_vec_10881 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10882);
										mem_vec_10882 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10883);
										mem_vec_10883 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10884);
										mem_vec_10884 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10885);
										mem_vec_10885 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10886);
										mem_vec_10886 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10887);
										mem_vec_10887 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10888);
										mem_vec_10888 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10889);
										mem_vec_10889 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10890);
										mem_vec_10890 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10891);
										mem_vec_10891 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10892);
										mem_vec_10892 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10893);
										mem_vec_10893 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10894);
										mem_vec_10894 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10895);
										mem_vec_10895 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_10896);
										mem_vec_10896 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_10897);
										mem_vec_10897 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_10898);
										mem_vec_10898 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_10899);
										mem_vec_10899 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_10900);
										mem_vec_10900 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_10901);
										mem_vec_10901 = vec_38;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_10874);
										mem_vec_10874 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_10875);
										mem_vec_10875 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_10876);
										mem_vec_10876 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_10877);
										mem_vec_10877 = vec_46;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_10878);
										mem_vec_10878 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_10879);
										mem_vec_10879 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_10880);
										mem_vec_10880 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_10881);
										mem_vec_10881 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_10882);
										mem_vec_10882 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_10883);
										mem_vec_10883 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_10884);
										mem_vec_10884 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_10885);
										mem_vec_10885 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_10886);
										mem_vec_10886 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_10887);
										mem_vec_10887 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_10888);
										mem_vec_10888 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_10889);
										mem_vec_10889 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_10890);
										mem_vec_10890 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_10891);
										mem_vec_10891 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_10892);
										mem_vec_10892 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_10893);
										mem_vec_10893 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_10894);
										mem_vec_10894 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_10895);
										mem_vec_10895 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_10896);
										mem_vec_10896 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_10897);
										mem_vec_10897 = vec_72;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_10898);
										mem_vec_10898 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_10899);
										mem_vec_10899 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_10900);
										mem_vec_10900 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_10901);
										mem_vec_10901 = vec_77;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_10874);
										mem_vec_10874 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_10875);
										mem_vec_10875 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_10876);
										mem_vec_10876 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_10877);
										mem_vec_10877 = vec_85;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_10878);
										mem_vec_10878 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_10879);
										mem_vec_10879 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_10880);
										mem_vec_10880 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_10881);
										mem_vec_10881 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_10882);
										mem_vec_10882 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_10883);
										mem_vec_10883 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_10884);
										mem_vec_10884 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_10885);
										mem_vec_10885 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_10886);
										mem_vec_10886 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_10887);
										mem_vec_10887 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_10888);
										mem_vec_10888 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_10889);
										mem_vec_10889 = vec_101;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_10890);
										mem_vec_10890 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_10891);
										mem_vec_10891 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_10892);
										mem_vec_10892 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_10893);
										mem_vec_10893 = vec_106;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_10894);
										mem_vec_10894 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_10895);
										mem_vec_10895 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_10896);
										mem_vec_10896 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_10897);
										mem_vec_10897 = vec_111;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_10898);
										mem_vec_10898 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_10899);
										mem_vec_10899 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_10900);
										mem_vec_10900 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_10901);
										mem_vec_10901 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10874);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10875);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10876);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10877);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10878);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10879);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10880);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10881);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10882);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10883);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10884);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10885);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10886);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10887);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10888);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10889);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10890);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10891);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10892);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10893);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10894);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10895);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_10896);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_10897);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10898);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10899);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_10900);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_10901);
						}
					}
				}
			}
		}
}


}