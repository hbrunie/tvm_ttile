#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (8, y); U (3, w); T (32, c); Hoist_vars [c]; T (8, x);
  T (1, w); T (3, h); T (1, x); T (14, y); T (1, c); T (14, x)]
*/
IND_TYPE c, c0, cp_0, c0_p_0, cp_1, h, hp_0, w, wp_0, x, x0, xp_0, x0_p_0, x1_p_0, x1, xp_1, x0_p_1, xp_2, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y0 = 0;
IND_TYPE x2 = 0;
IND_TYPE h0 = 0;
IND_TYPE w0 = 0;
IND_TYPE c1 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_0 ,mem_vec_1 ,mem_vec_10 ,mem_vec_11 ,mem_vec_12 ,mem_vec_13 ,mem_vec_14 ,mem_vec_15 ,mem_vec_16 ,mem_vec_17 ,mem_vec_18 ,mem_vec_19 ,mem_vec_2 ,mem_vec_20 ,mem_vec_21 ,mem_vec_22 ,mem_vec_23 ,mem_vec_24 ,mem_vec_25 ,mem_vec_26 ,mem_vec_27 ,mem_vec_28 ,mem_vec_29 ,mem_vec_3 ,mem_vec_30 ,mem_vec_31 ,mem_vec_4 ,mem_vec_5 ,mem_vec_6 ,mem_vec_7 ,mem_vec_8 ,mem_vec_9 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 14) (112 / 8)
for (x1 = x2, x1_p_0 = 0;
	x1 < x2 + 112;
	x1 += 8, x1_p_0 += 8){
	// y = 112, x = 8, h = 3, w = 3, c = 32, f = 32
	// T (c, 1) (32 / 32)
	for (c0 = c1, c0_p_0 = 0;
		c0 < c1 + 32;
		c0 += 32, c0_p_0 += 32){
		// y = 112, x = 8, h = 3, w = 3, c = 32, f = 32
		// T (y, 14) (112 / 8)
		for (y = y0, yp_0 = 0;
			y < y0 + 112;
			y += 8, yp_0 += 8){
			// y = 8, x = 8, h = 3, w = 3, c = 32, f = 32
			// T (x, 1) (8 / 8)
			for (x0 = x1, x0_p_1 = x1_p_0, x0_p_0 = 0;
				x0 < x1 + 8;
				x0 += 8, x0_p_1 += 8, x0_p_0 += 8){
				// y = 8, x = 8, h = 3, w = 3, c = 32, f = 32
				// T (h, 3) (3 / 1)
				for (h = h0, hp_0 = 0;
					h < h0 + 3;
					h += 1, hp_0 += 1){
					// y = 8, x = 8, h = 1, w = 3, c = 32, f = 32
					// T (w, 1) (3 / 3)
					for (w = w0, wp_0 = 0;
						w < w0 + 3;
						w += 3, wp_0 += 3){
						// y = 8, x = 8, h = 1, w = 3, c = 32, f = 32
						// T (x, 8) (8 / 1)
						for (x = x0, xp_2 = x0_p_1, xp_1 = x0_p_0, xp_0 = 0;
							x < x0 + 8;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_0 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_2 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_4 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_6 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_8 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_10 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_11 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_12 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_13 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_14 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_15 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_16 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_17 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_18 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_19 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									mem_vec_20 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_21 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
									mem_vec_22 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_23 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
									mem_vec_24 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_25 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
									mem_vec_26 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_27 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
									mem_vec_28 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_29 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
									mem_vec_30 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_31 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 24]);
									// y = 8, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c0, cp_1 = c0_p_0, cp_0 = 0;
										c < c0 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_0);
										mem_vec_0 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1);
										mem_vec_1 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2);
										mem_vec_2 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3);
										mem_vec_3 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4);
										mem_vec_4 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5);
										mem_vec_5 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6);
										mem_vec_6 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7);
										mem_vec_7 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8);
										mem_vec_8 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9);
										mem_vec_9 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10);
										mem_vec_10 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11);
										mem_vec_11 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12);
										mem_vec_12 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13);
										mem_vec_13 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14);
										mem_vec_14 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_15);
										mem_vec_15 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_16);
										mem_vec_16 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_17);
										mem_vec_17 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_18);
										mem_vec_18 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_19);
										mem_vec_19 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm256_set1_ps(scal_5);


										vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_20);
										mem_vec_20 = vec_29;



										vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_21);
										mem_vec_21 = vec_31;



										vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_22);
										mem_vec_22 = vec_32;



										vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_23);
										mem_vec_23 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm256_set1_ps(scal_6);


										vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_24);
										mem_vec_24 = vec_34;



										vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_25);
										mem_vec_25 = vec_36;



										vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_26);
										mem_vec_26 = vec_37;



										vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_27);
										mem_vec_27 = vec_38;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_40 = _mm256_set1_ps(scal_7);


										vec_39 = _mm256_fmadd_ps(vec_40, vec_2, mem_vec_28);
										mem_vec_28 = vec_39;



										vec_41 = _mm256_fmadd_ps(vec_40, vec_4, mem_vec_29);
										mem_vec_29 = vec_41;



										vec_42 = _mm256_fmadd_ps(vec_40, vec_6, mem_vec_30);
										mem_vec_30 = vec_42;



										vec_43 = _mm256_fmadd_ps(vec_40, vec_8, mem_vec_31);
										mem_vec_31 = vec_43;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_45 = _mm256_set1_ps(scal_8);
										vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_0);
										mem_vec_0 = vec_44;

										vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

										vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_1);
										mem_vec_1 = vec_47;

										vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_2);
										mem_vec_2 = vec_49;

										vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

										vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_3);
										mem_vec_3 = vec_51;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_54 = _mm256_set1_ps(scal_9);


										vec_53 = _mm256_fmadd_ps(vec_54, vec_46, mem_vec_4);
										mem_vec_4 = vec_53;



										vec_55 = _mm256_fmadd_ps(vec_54, vec_48, mem_vec_5);
										mem_vec_5 = vec_55;



										vec_56 = _mm256_fmadd_ps(vec_54, vec_50, mem_vec_6);
										mem_vec_6 = vec_56;



										vec_57 = _mm256_fmadd_ps(vec_54, vec_52, mem_vec_7);
										mem_vec_7 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_59 = _mm256_set1_ps(scal_10);


										vec_58 = _mm256_fmadd_ps(vec_59, vec_46, mem_vec_8);
										mem_vec_8 = vec_58;



										vec_60 = _mm256_fmadd_ps(vec_59, vec_48, mem_vec_9);
										mem_vec_9 = vec_60;



										vec_61 = _mm256_fmadd_ps(vec_59, vec_50, mem_vec_10);
										mem_vec_10 = vec_61;



										vec_62 = _mm256_fmadd_ps(vec_59, vec_52, mem_vec_11);
										mem_vec_11 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_64 = _mm256_set1_ps(scal_11);


										vec_63 = _mm256_fmadd_ps(vec_64, vec_46, mem_vec_12);
										mem_vec_12 = vec_63;



										vec_65 = _mm256_fmadd_ps(vec_64, vec_48, mem_vec_13);
										mem_vec_13 = vec_65;



										vec_66 = _mm256_fmadd_ps(vec_64, vec_50, mem_vec_14);
										mem_vec_14 = vec_66;



										vec_67 = _mm256_fmadd_ps(vec_64, vec_52, mem_vec_15);
										mem_vec_15 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_69 = _mm256_set1_ps(scal_12);


										vec_68 = _mm256_fmadd_ps(vec_69, vec_46, mem_vec_16);
										mem_vec_16 = vec_68;



										vec_70 = _mm256_fmadd_ps(vec_69, vec_48, mem_vec_17);
										mem_vec_17 = vec_70;



										vec_71 = _mm256_fmadd_ps(vec_69, vec_50, mem_vec_18);
										mem_vec_18 = vec_71;



										vec_72 = _mm256_fmadd_ps(vec_69, vec_52, mem_vec_19);
										mem_vec_19 = vec_72;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_74 = _mm256_set1_ps(scal_13);


										vec_73 = _mm256_fmadd_ps(vec_74, vec_46, mem_vec_20);
										mem_vec_20 = vec_73;



										vec_75 = _mm256_fmadd_ps(vec_74, vec_48, mem_vec_21);
										mem_vec_21 = vec_75;



										vec_76 = _mm256_fmadd_ps(vec_74, vec_50, mem_vec_22);
										mem_vec_22 = vec_76;



										vec_77 = _mm256_fmadd_ps(vec_74, vec_52, mem_vec_23);
										mem_vec_23 = vec_77;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_79 = _mm256_set1_ps(scal_14);


										vec_78 = _mm256_fmadd_ps(vec_79, vec_46, mem_vec_24);
										mem_vec_24 = vec_78;



										vec_80 = _mm256_fmadd_ps(vec_79, vec_48, mem_vec_25);
										mem_vec_25 = vec_80;



										vec_81 = _mm256_fmadd_ps(vec_79, vec_50, mem_vec_26);
										mem_vec_26 = vec_81;



										vec_82 = _mm256_fmadd_ps(vec_79, vec_52, mem_vec_27);
										mem_vec_27 = vec_82;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_84 = _mm256_set1_ps(scal_15);


										vec_83 = _mm256_fmadd_ps(vec_84, vec_46, mem_vec_28);
										mem_vec_28 = vec_83;



										vec_85 = _mm256_fmadd_ps(vec_84, vec_48, mem_vec_29);
										mem_vec_29 = vec_85;



										vec_86 = _mm256_fmadd_ps(vec_84, vec_50, mem_vec_30);
										mem_vec_30 = vec_86;



										vec_87 = _mm256_fmadd_ps(vec_84, vec_52, mem_vec_31);
										mem_vec_31 = vec_87;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_89 = _mm256_set1_ps(scal_16);
										vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_0);
										mem_vec_0 = vec_88;

										vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

										vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_1);
										mem_vec_1 = vec_91;

										vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_2);
										mem_vec_2 = vec_93;

										vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

										vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_3);
										mem_vec_3 = vec_95;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_98 = _mm256_set1_ps(scal_17);


										vec_97 = _mm256_fmadd_ps(vec_98, vec_90, mem_vec_4);
										mem_vec_4 = vec_97;



										vec_99 = _mm256_fmadd_ps(vec_98, vec_92, mem_vec_5);
										mem_vec_5 = vec_99;



										vec_100 = _mm256_fmadd_ps(vec_98, vec_94, mem_vec_6);
										mem_vec_6 = vec_100;



										vec_101 = _mm256_fmadd_ps(vec_98, vec_96, mem_vec_7);
										mem_vec_7 = vec_101;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_103 = _mm256_set1_ps(scal_18);


										vec_102 = _mm256_fmadd_ps(vec_103, vec_90, mem_vec_8);
										mem_vec_8 = vec_102;



										vec_104 = _mm256_fmadd_ps(vec_103, vec_92, mem_vec_9);
										mem_vec_9 = vec_104;



										vec_105 = _mm256_fmadd_ps(vec_103, vec_94, mem_vec_10);
										mem_vec_10 = vec_105;



										vec_106 = _mm256_fmadd_ps(vec_103, vec_96, mem_vec_11);
										mem_vec_11 = vec_106;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_108 = _mm256_set1_ps(scal_19);


										vec_107 = _mm256_fmadd_ps(vec_108, vec_90, mem_vec_12);
										mem_vec_12 = vec_107;



										vec_109 = _mm256_fmadd_ps(vec_108, vec_92, mem_vec_13);
										mem_vec_13 = vec_109;



										vec_110 = _mm256_fmadd_ps(vec_108, vec_94, mem_vec_14);
										mem_vec_14 = vec_110;



										vec_111 = _mm256_fmadd_ps(vec_108, vec_96, mem_vec_15);
										mem_vec_15 = vec_111;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_113 = _mm256_set1_ps(scal_20);


										vec_112 = _mm256_fmadd_ps(vec_113, vec_90, mem_vec_16);
										mem_vec_16 = vec_112;



										vec_114 = _mm256_fmadd_ps(vec_113, vec_92, mem_vec_17);
										mem_vec_17 = vec_114;



										vec_115 = _mm256_fmadd_ps(vec_113, vec_94, mem_vec_18);
										mem_vec_18 = vec_115;



										vec_116 = _mm256_fmadd_ps(vec_113, vec_96, mem_vec_19);
										mem_vec_19 = vec_116;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_118 = _mm256_set1_ps(scal_21);


										vec_117 = _mm256_fmadd_ps(vec_118, vec_90, mem_vec_20);
										mem_vec_20 = vec_117;



										vec_119 = _mm256_fmadd_ps(vec_118, vec_92, mem_vec_21);
										mem_vec_21 = vec_119;



										vec_120 = _mm256_fmadd_ps(vec_118, vec_94, mem_vec_22);
										mem_vec_22 = vec_120;



										vec_121 = _mm256_fmadd_ps(vec_118, vec_96, mem_vec_23);
										mem_vec_23 = vec_121;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_123 = _mm256_set1_ps(scal_22);


										vec_122 = _mm256_fmadd_ps(vec_123, vec_90, mem_vec_24);
										mem_vec_24 = vec_122;



										vec_124 = _mm256_fmadd_ps(vec_123, vec_92, mem_vec_25);
										mem_vec_25 = vec_124;



										vec_125 = _mm256_fmadd_ps(vec_123, vec_94, mem_vec_26);
										mem_vec_26 = vec_125;



										vec_126 = _mm256_fmadd_ps(vec_123, vec_96, mem_vec_27);
										mem_vec_27 = vec_126;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_128 = _mm256_set1_ps(scal_23);


										vec_127 = _mm256_fmadd_ps(vec_128, vec_90, mem_vec_28);
										mem_vec_28 = vec_127;



										vec_129 = _mm256_fmadd_ps(vec_128, vec_92, mem_vec_29);
										mem_vec_29 = vec_129;



										vec_130 = _mm256_fmadd_ps(vec_128, vec_94, mem_vec_30);
										mem_vec_30 = vec_130;



										vec_131 = _mm256_fmadd_ps(vec_128, vec_96, mem_vec_31);
										mem_vec_31 = vec_131;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_0);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_15);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_16);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_17);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_18);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_19);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_20);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_21);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_22);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_23);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_24);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_25);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_26);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_27);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_28);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_29);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_30);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 24], mem_vec_31);
						}
					}
				}
			}
		}
	}
}


}