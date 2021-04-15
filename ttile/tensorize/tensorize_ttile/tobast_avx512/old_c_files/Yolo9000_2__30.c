#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (8, y); U (3, h); U (3, w); T (2, c); Hoist_vars [c];
  T (1, x); T (34, x); T (34, y); T (4, f); T (16, c); T (2, x); T (4, x)]
*/
IND_TYPE c, cp_0, c684_p_0, cp_1, c684, f, fp_0, x, xp_0, x1148_p_0, x1149_p_0, x1150_p_0, xp_1, x1148_p_1, x1149_p_1, xp_2, x1148_p_2, xp_3, x1148, x1149, x1150, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y476 = 0;
IND_TYPE x1151 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c685 = 0;
IND_TYPE f378 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_45 ,scal_46 ,scal_47 ,scal_48 ,scal_49 ,scal_5 ,scal_50 ,scal_51 ,scal_52 ,scal_53 ,scal_54 ,scal_55 ,scal_56 ,scal_57 ,scal_58 ,scal_59 ,scal_6 ,scal_60 ,scal_61 ,scal_62 ,scal_63 ,scal_64 ,scal_65 ,scal_66 ,scal_67 ,scal_68 ,scal_69 ,scal_7 ,scal_70 ,scal_71 ,scal_8 ,scal_9;
__m512 mem_vec_2528 ,mem_vec_2529 ,mem_vec_2530 ,mem_vec_2531 ,mem_vec_2532 ,mem_vec_2533 ,mem_vec_2534 ,mem_vec_2535 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_132 ,vec_133 ,vec_134 ,vec_135 ,vec_136 ,vec_137 ,vec_138 ,vec_139 ,vec_14 ,vec_140 ,vec_141 ,vec_142 ,vec_143 ,vec_144 ,vec_145 ,vec_146 ,vec_147 ,vec_148 ,vec_149 ,vec_15 ,vec_150 ,vec_151 ,vec_152 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 4) (272 / 68)
for (x1150 = x1151, x1150_p_0 = 0;
	x1150 < x1151 + 272;
	x1150 += 68, x1150_p_0 += 68){
	// y = 272, x = 68, h = 3, w = 3, c = 32, f = 64
	// T (x, 2) (68 / 34)
	for (x1149 = x1150, x1149_p_1 = x1150_p_0, x1149_p_0 = 0;
		x1149 < x1150 + 68;
		x1149 += 34, x1149_p_1 += 34, x1149_p_0 += 34){
		// y = 272, x = 34, h = 3, w = 3, c = 32, f = 64
		// T (c, 16) (32 / 2)
		for (c684 = c685, c684_p_0 = 0;
			c684 < c685 + 32;
			c684 += 2, c684_p_0 += 2){
			// y = 272, x = 34, h = 3, w = 3, c = 2, f = 64
			// T (f, 4) (64 / 16)
			for (f = f378, fp_0 = 0;
				f < f378 + 64;
				f += 16, fp_0 += 16){
				// y = 272, x = 34, h = 3, w = 3, c = 2, f = 16
				// T (y, 34) (272 / 8)
				for (y = y476, yp_0 = 0;
					y < y476 + 272;
					y += 8, yp_0 += 8){
					// y = 8, x = 34, h = 3, w = 3, c = 2, f = 16
					// T (x, 34) (34 / 1)
					for (x1148 = x1149, x1148_p_2 = x1149_p_1, x1148_p_1 = x1149_p_0, x1148_p_0 = 0;
						x1148 < x1149 + 34;
						x1148 += 1, x1148_p_2 += 1, x1148_p_1 += 1, x1148_p_0 += 1){
						// y = 8, x = 1, h = 3, w = 3, c = 2, f = 16
						// T (x, 1) (1 / 1)
						for (x = x1148, xp_3 = x1148_p_2, xp_2 = x1148_p_1, xp_1 = x1148_p_0, xp_0 = 0;
							x < x1148 + 1;
							x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_2528 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2529 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_2531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_2532 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_2533 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_2534 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_2535 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									// y = 8, x = 1, h = 3, w = 3, c = 2, f = 16
									// T (c, 2) (2 / 1)
									for (c = c684, cp_1 = c684_p_0, cp_0 = 0;
										c < c684 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2528);
										mem_vec_2528 = vec_0;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_2529);
										mem_vec_2529 = vec_3;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2530);
										mem_vec_2530 = vec_5;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_2531);
										mem_vec_2531 = vec_7;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2532);
										mem_vec_2532 = vec_9;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_12 = _mm512_set1_ps(scal_5);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2533);
										mem_vec_2533 = vec_11;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_14 = _mm512_set1_ps(scal_6);


										vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_2534);
										mem_vec_2534 = vec_13;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_16 = _mm512_set1_ps(scal_7);


										vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_2535);
										mem_vec_2535 = vec_15;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_18 = _mm512_set1_ps(scal_8);
										vec_19 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_17 = _mm512_fmadd_ps(vec_18, vec_19, mem_vec_2528);
										mem_vec_2528 = vec_17;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_21 = _mm512_set1_ps(scal_9);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_19, mem_vec_2529);
										mem_vec_2529 = vec_20;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_23 = _mm512_set1_ps(scal_10);


										vec_22 = _mm512_fmadd_ps(vec_23, vec_19, mem_vec_2530);
										mem_vec_2530 = vec_22;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_25 = _mm512_set1_ps(scal_11);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_19, mem_vec_2531);
										mem_vec_2531 = vec_24;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_27 = _mm512_set1_ps(scal_12);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_19, mem_vec_2532);
										mem_vec_2532 = vec_26;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_13);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_19, mem_vec_2533);
										mem_vec_2533 = vec_28;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_31 = _mm512_set1_ps(scal_14);


										vec_30 = _mm512_fmadd_ps(vec_31, vec_19, mem_vec_2534);
										mem_vec_2534 = vec_30;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_33 = _mm512_set1_ps(scal_15);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_19, mem_vec_2535);
										mem_vec_2535 = vec_32;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_35 = _mm512_set1_ps(scal_16);
										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_2528);
										mem_vec_2528 = vec_34;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_38 = _mm512_set1_ps(scal_17);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_2529);
										mem_vec_2529 = vec_37;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_40 = _mm512_set1_ps(scal_18);


										vec_39 = _mm512_fmadd_ps(vec_40, vec_36, mem_vec_2530);
										mem_vec_2530 = vec_39;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_42 = _mm512_set1_ps(scal_19);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_36, mem_vec_2531);
										mem_vec_2531 = vec_41;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_44 = _mm512_set1_ps(scal_20);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_2532);
										mem_vec_2532 = vec_43;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_46 = _mm512_set1_ps(scal_21);


										vec_45 = _mm512_fmadd_ps(vec_46, vec_36, mem_vec_2533);
										mem_vec_2533 = vec_45;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_48 = _mm512_set1_ps(scal_22);


										vec_47 = _mm512_fmadd_ps(vec_48, vec_36, mem_vec_2534);
										mem_vec_2534 = vec_47;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_50 = _mm512_set1_ps(scal_23);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_2535);
										mem_vec_2535 = vec_49;
										scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_52 = _mm512_set1_ps(scal_24);
										vec_53 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_51 = _mm512_fmadd_ps(vec_52, vec_53, mem_vec_2528);
										mem_vec_2528 = vec_51;
										scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_55 = _mm512_set1_ps(scal_25);


										vec_54 = _mm512_fmadd_ps(vec_55, vec_53, mem_vec_2529);
										mem_vec_2529 = vec_54;
										scal_26 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_57 = _mm512_set1_ps(scal_26);


										vec_56 = _mm512_fmadd_ps(vec_57, vec_53, mem_vec_2530);
										mem_vec_2530 = vec_56;
										scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_59 = _mm512_set1_ps(scal_27);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_53, mem_vec_2531);
										mem_vec_2531 = vec_58;
										scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_61 = _mm512_set1_ps(scal_28);


										vec_60 = _mm512_fmadd_ps(vec_61, vec_53, mem_vec_2532);
										mem_vec_2532 = vec_60;
										scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_63 = _mm512_set1_ps(scal_29);


										vec_62 = _mm512_fmadd_ps(vec_63, vec_53, mem_vec_2533);
										mem_vec_2533 = vec_62;
										scal_30 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_65 = _mm512_set1_ps(scal_30);


										vec_64 = _mm512_fmadd_ps(vec_65, vec_53, mem_vec_2534);
										mem_vec_2534 = vec_64;
										scal_31 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_67 = _mm512_set1_ps(scal_31);


										vec_66 = _mm512_fmadd_ps(vec_67, vec_53, mem_vec_2535);
										mem_vec_2535 = vec_66;
										scal_32 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
										vec_69 = _mm512_set1_ps(scal_32);
										vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

										vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_2528);
										mem_vec_2528 = vec_68;
										scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
										vec_72 = _mm512_set1_ps(scal_33);


										vec_71 = _mm512_fmadd_ps(vec_72, vec_70, mem_vec_2529);
										mem_vec_2529 = vec_71;
										scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
										vec_74 = _mm512_set1_ps(scal_34);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_70, mem_vec_2530);
										mem_vec_2530 = vec_73;
										scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
										vec_76 = _mm512_set1_ps(scal_35);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_70, mem_vec_2531);
										mem_vec_2531 = vec_75;
										scal_36 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
										vec_78 = _mm512_set1_ps(scal_36);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_2532);
										mem_vec_2532 = vec_77;
										scal_37 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
										vec_80 = _mm512_set1_ps(scal_37);


										vec_79 = _mm512_fmadd_ps(vec_80, vec_70, mem_vec_2533);
										mem_vec_2533 = vec_79;
										scal_38 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
										vec_82 = _mm512_set1_ps(scal_38);


										vec_81 = _mm512_fmadd_ps(vec_82, vec_70, mem_vec_2534);
										mem_vec_2534 = vec_81;
										scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 1) + c];
										vec_84 = _mm512_set1_ps(scal_39);


										vec_83 = _mm512_fmadd_ps(vec_84, vec_70, mem_vec_2535);
										mem_vec_2535 = vec_83;
										scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
										vec_86 = _mm512_set1_ps(scal_40);
										vec_87 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

										vec_85 = _mm512_fmadd_ps(vec_86, vec_87, mem_vec_2528);
										mem_vec_2528 = vec_85;
										scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
										vec_89 = _mm512_set1_ps(scal_41);


										vec_88 = _mm512_fmadd_ps(vec_89, vec_87, mem_vec_2529);
										mem_vec_2529 = vec_88;
										scal_42 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
										vec_91 = _mm512_set1_ps(scal_42);


										vec_90 = _mm512_fmadd_ps(vec_91, vec_87, mem_vec_2530);
										mem_vec_2530 = vec_90;
										scal_43 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
										vec_93 = _mm512_set1_ps(scal_43);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_87, mem_vec_2531);
										mem_vec_2531 = vec_92;
										scal_44 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
										vec_95 = _mm512_set1_ps(scal_44);


										vec_94 = _mm512_fmadd_ps(vec_95, vec_87, mem_vec_2532);
										mem_vec_2532 = vec_94;
										scal_45 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
										vec_97 = _mm512_set1_ps(scal_45);


										vec_96 = _mm512_fmadd_ps(vec_97, vec_87, mem_vec_2533);
										mem_vec_2533 = vec_96;
										scal_46 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
										vec_99 = _mm512_set1_ps(scal_46);


										vec_98 = _mm512_fmadd_ps(vec_99, vec_87, mem_vec_2534);
										mem_vec_2534 = vec_98;
										scal_47 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 2) + c];
										vec_101 = _mm512_set1_ps(scal_47);


										vec_100 = _mm512_fmadd_ps(vec_101, vec_87, mem_vec_2535);
										mem_vec_2535 = vec_100;
										scal_48 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_103 = _mm512_set1_ps(scal_48);
										vec_104 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_102 = _mm512_fmadd_ps(vec_103, vec_104, mem_vec_2528);
										mem_vec_2528 = vec_102;
										scal_49 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_106 = _mm512_set1_ps(scal_49);


										vec_105 = _mm512_fmadd_ps(vec_106, vec_104, mem_vec_2529);
										mem_vec_2529 = vec_105;
										scal_50 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_108 = _mm512_set1_ps(scal_50);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_104, mem_vec_2530);
										mem_vec_2530 = vec_107;
										scal_51 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_110 = _mm512_set1_ps(scal_51);


										vec_109 = _mm512_fmadd_ps(vec_110, vec_104, mem_vec_2531);
										mem_vec_2531 = vec_109;
										scal_52 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_112 = _mm512_set1_ps(scal_52);


										vec_111 = _mm512_fmadd_ps(vec_112, vec_104, mem_vec_2532);
										mem_vec_2532 = vec_111;
										scal_53 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_114 = _mm512_set1_ps(scal_53);


										vec_113 = _mm512_fmadd_ps(vec_114, vec_104, mem_vec_2533);
										mem_vec_2533 = vec_113;
										scal_54 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_116 = _mm512_set1_ps(scal_54);


										vec_115 = _mm512_fmadd_ps(vec_116, vec_104, mem_vec_2534);
										mem_vec_2534 = vec_115;
										scal_55 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_118 = _mm512_set1_ps(scal_55);


										vec_117 = _mm512_fmadd_ps(vec_118, vec_104, mem_vec_2535);
										mem_vec_2535 = vec_117;
										scal_56 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
										vec_120 = _mm512_set1_ps(scal_56);
										vec_121 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

										vec_119 = _mm512_fmadd_ps(vec_120, vec_121, mem_vec_2528);
										mem_vec_2528 = vec_119;
										scal_57 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
										vec_123 = _mm512_set1_ps(scal_57);


										vec_122 = _mm512_fmadd_ps(vec_123, vec_121, mem_vec_2529);
										mem_vec_2529 = vec_122;
										scal_58 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
										vec_125 = _mm512_set1_ps(scal_58);


										vec_124 = _mm512_fmadd_ps(vec_125, vec_121, mem_vec_2530);
										mem_vec_2530 = vec_124;
										scal_59 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
										vec_127 = _mm512_set1_ps(scal_59);


										vec_126 = _mm512_fmadd_ps(vec_127, vec_121, mem_vec_2531);
										mem_vec_2531 = vec_126;
										scal_60 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
										vec_129 = _mm512_set1_ps(scal_60);


										vec_128 = _mm512_fmadd_ps(vec_129, vec_121, mem_vec_2532);
										mem_vec_2532 = vec_128;
										scal_61 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
										vec_131 = _mm512_set1_ps(scal_61);


										vec_130 = _mm512_fmadd_ps(vec_131, vec_121, mem_vec_2533);
										mem_vec_2533 = vec_130;
										scal_62 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
										vec_133 = _mm512_set1_ps(scal_62);


										vec_132 = _mm512_fmadd_ps(vec_133, vec_121, mem_vec_2534);
										mem_vec_2534 = vec_132;
										scal_63 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 1) + c];
										vec_135 = _mm512_set1_ps(scal_63);


										vec_134 = _mm512_fmadd_ps(vec_135, vec_121, mem_vec_2535);
										mem_vec_2535 = vec_134;
										scal_64 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
										vec_137 = _mm512_set1_ps(scal_64);
										vec_138 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

										vec_136 = _mm512_fmadd_ps(vec_137, vec_138, mem_vec_2528);
										mem_vec_2528 = vec_136;
										scal_65 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
										vec_140 = _mm512_set1_ps(scal_65);


										vec_139 = _mm512_fmadd_ps(vec_140, vec_138, mem_vec_2529);
										mem_vec_2529 = vec_139;
										scal_66 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
										vec_142 = _mm512_set1_ps(scal_66);


										vec_141 = _mm512_fmadd_ps(vec_142, vec_138, mem_vec_2530);
										mem_vec_2530 = vec_141;
										scal_67 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
										vec_144 = _mm512_set1_ps(scal_67);


										vec_143 = _mm512_fmadd_ps(vec_144, vec_138, mem_vec_2531);
										mem_vec_2531 = vec_143;
										scal_68 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
										vec_146 = _mm512_set1_ps(scal_68);


										vec_145 = _mm512_fmadd_ps(vec_146, vec_138, mem_vec_2532);
										mem_vec_2532 = vec_145;
										scal_69 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
										vec_148 = _mm512_set1_ps(scal_69);


										vec_147 = _mm512_fmadd_ps(vec_148, vec_138, mem_vec_2533);
										mem_vec_2533 = vec_147;
										scal_70 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
										vec_150 = _mm512_set1_ps(scal_70);


										vec_149 = _mm512_fmadd_ps(vec_150, vec_138, mem_vec_2534);
										mem_vec_2534 = vec_149;
										scal_71 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 2) + c];
										vec_152 = _mm512_set1_ps(scal_71);


										vec_151 = _mm512_fmadd_ps(vec_152, vec_138, mem_vec_2535);
										mem_vec_2535 = vec_151;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2528);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2529);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2530);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2531);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2532);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2533);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2534);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2535);
						}
					}
				}
			}
		}
	}
}


}