#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (4, c); T (56, x);
  Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))]; T (1, c)]
*/
IND_TYPE c, cp_0, c1256_p_0, c1257_p_0, cp_1, c1256_p_1, cp_2, c1256, c1257, h, hp_0, x, xp_0, x1376_p_0, xp_1, x1376, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y752 = 0;
IND_TYPE x1377 = 0;
IND_TYPE h576 = 0;
IND_TYPE w = 0;
IND_TYPE c1258 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_13156 ,mem_vec_13157 ,mem_vec_13158 ,mem_vec_13159 ,mem_vec_13160 ,mem_vec_13161 ,mem_vec_13162 ,mem_vec_13163 ,mem_vec_13164 ,mem_vec_13165 ,mem_vec_13166 ,mem_vec_13167 ,mem_vec_13168 ,mem_vec_13169 ,mem_vec_13170 ,mem_vec_13171 ,mem_vec_13172 ,mem_vec_13173 ,mem_vec_13174 ,mem_vec_13175 ,mem_vec_13176 ,mem_vec_13177 ,mem_vec_13178 ,mem_vec_13179 ,mem_vec_13180 ,mem_vec_13181 ,mem_vec_13182 ,mem_vec_13183 ,mem_vec_13184 ,mem_vec_13185 ,mem_vec_13186 ,mem_vec_13187 ,mem_vec_13188 ,mem_vec_13189 ,mem_vec_13190 ,mem_vec_13191 ,mem_vec_13192 ,mem_vec_13193 ,mem_vec_13194 ,mem_vec_13195 ,mem_vec_13196 ,mem_vec_13197 ,mem_vec_13198 ,mem_vec_13199 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 1) (64 / 64)
for (c1257 = c1258, c1257_p_0 = 0;
	c1257 < c1258 + 64;
	c1257 += 64, c1257_p_0 += 64){
		for (y = y752, yp_0 = 0;
			y < y752 + 28;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 56) (56 / 1)
			for (x1376 = x1377, x1376_p_0 = 0;
				x1376 < x1377 + 56;
				x1376 += 1, x1376_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 64
				// T (c, 4) (64 / 16)
				for (c1256 = c1257, c1256_p_1 = c1257_p_0, c1256_p_0 = 0;
					c1256 < c1257 + 64;
					c1256 += 16, c1256_p_1 += 16, c1256_p_0 += 16){
					// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
					// T (h, 3) (3 / 1)
					for (h = h576, hp_0 = 0;
						h < h576 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1376, xp_1 = x1376_p_0, xp_0 = 0;
							x < x1376 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_13156 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_13157 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_13158 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_13159 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_13160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_13161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_13162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_13163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_13164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_13165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_13166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_13167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_13168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_13169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_13170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_13171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c1256, cp_2 = c1256_p_1, cp_1 = c1256_p_0, cp_0 = 0;
										c < c1256 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13156);
										mem_vec_13156 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13157);
										mem_vec_13157 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13158);
										mem_vec_13158 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13159);
										mem_vec_13159 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13160);
										mem_vec_13160 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13161);
										mem_vec_13161 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13162);
										mem_vec_13162 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13163);
										mem_vec_13163 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13164);
										mem_vec_13164 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13165);
										mem_vec_13165 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13166);
										mem_vec_13166 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13167);
										mem_vec_13167 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13168);
										mem_vec_13168 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13169);
										mem_vec_13169 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13170);
										mem_vec_13170 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13171);
										mem_vec_13171 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_13156);
										mem_vec_13156 = vec_24;

										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_13157);
										mem_vec_13157 = vec_27;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_13158);
										mem_vec_13158 = vec_29;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_13159);
										mem_vec_13159 = vec_31;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_34 = _mm512_set1_ps(scal_5);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_13160);
										mem_vec_13160 = vec_33;



										vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_13161);
										mem_vec_13161 = vec_35;



										vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_13162);
										mem_vec_13162 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_13163);
										mem_vec_13163 = vec_37;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_39 = _mm512_set1_ps(scal_6);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_13164);
										mem_vec_13164 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_13165);
										mem_vec_13165 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_13166);
										mem_vec_13166 = vec_41;



										vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_13167);
										mem_vec_13167 = vec_42;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_13168);
										mem_vec_13168 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_13169);
										mem_vec_13169 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_13170);
										mem_vec_13170 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_13171);
										mem_vec_13171 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);
										vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_13156);
										mem_vec_13156 = vec_48;

										vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_13157);
										mem_vec_13157 = vec_51;

										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_13158);
										mem_vec_13158 = vec_53;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_13159);
										mem_vec_13159 = vec_55;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_58 = _mm512_set1_ps(scal_9);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_13160);
										mem_vec_13160 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_13161);
										mem_vec_13161 = vec_59;



										vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_13162);
										mem_vec_13162 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_13163);
										mem_vec_13163 = vec_61;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_63 = _mm512_set1_ps(scal_10);


										vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_13164);
										mem_vec_13164 = vec_62;



										vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_13165);
										mem_vec_13165 = vec_64;



										vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_13166);
										mem_vec_13166 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_13167);
										mem_vec_13167 = vec_66;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_68 = _mm512_set1_ps(scal_11);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_13168);
										mem_vec_13168 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_13169);
										mem_vec_13169 = vec_69;



										vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_13170);
										mem_vec_13170 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_13171);
										mem_vec_13171 = vec_71;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13156);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13157);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13158);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13159);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13160);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13161);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13162);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13163);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13164);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13165);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13166);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13167);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13168);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13169);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_13170);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_13171);
						}
					}
				}
			}
		}
		for (y = y752 + 28, yp_0 = 0;
			y < y752 + 28 + 28;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 56) (56 / 1)
			for (x1376 = x1377, x1376_p_0 = 0;
				x1376 < x1377 + 56;
				x1376 += 1, x1376_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 64
				// T (c, 4) (64 / 16)
				for (c1256 = c1257, c1256_p_1 = c1257_p_0, c1256_p_0 = 0;
					c1256 < c1257 + 64;
					c1256 += 16, c1256_p_1 += 16, c1256_p_0 += 16){
					// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
					// T (h, 3) (3 / 1)
					for (h = h576, hp_0 = 0;
						h < h576 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1376, xp_1 = x1376_p_0, xp_0 = 0;
							x < x1376 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_13172 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_13173 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_13174 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_13175 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_13176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_13177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_13178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_13179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_13180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_13181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_13182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_13183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_13184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_13185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_13186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_13187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_13188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_13189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_13190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_13191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_13192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_13193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_13194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_13195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_13196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_13197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_13198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_13199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c1256, cp_2 = c1256_p_1, cp_1 = c1256_p_0, cp_0 = 0;
										c < c1256 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13172);
										mem_vec_13172 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13173);
										mem_vec_13173 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13174);
										mem_vec_13174 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13175);
										mem_vec_13175 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13176);
										mem_vec_13176 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13177);
										mem_vec_13177 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13178);
										mem_vec_13178 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13179);
										mem_vec_13179 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13180);
										mem_vec_13180 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13181);
										mem_vec_13181 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13182);
										mem_vec_13182 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13183);
										mem_vec_13183 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13184);
										mem_vec_13184 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13185);
										mem_vec_13185 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13186);
										mem_vec_13186 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13187);
										mem_vec_13187 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_13188);
										mem_vec_13188 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_13189);
										mem_vec_13189 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_13190);
										mem_vec_13190 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_13191);
										mem_vec_13191 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13192);
										mem_vec_13192 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13193);
										mem_vec_13193 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_13194);
										mem_vec_13194 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_13195);
										mem_vec_13195 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_13196);
										mem_vec_13196 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_13197);
										mem_vec_13197 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_13198);
										mem_vec_13198 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_13199);
										mem_vec_13199 = vec_38;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_13172);
										mem_vec_13172 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_13173);
										mem_vec_13173 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_13174);
										mem_vec_13174 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_13175);
										mem_vec_13175 = vec_46;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_13176);
										mem_vec_13176 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_13177);
										mem_vec_13177 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_13178);
										mem_vec_13178 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_13179);
										mem_vec_13179 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_13180);
										mem_vec_13180 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_13181);
										mem_vec_13181 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_13182);
										mem_vec_13182 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_13183);
										mem_vec_13183 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_13184);
										mem_vec_13184 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_13185);
										mem_vec_13185 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_13186);
										mem_vec_13186 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_13187);
										mem_vec_13187 = vec_62;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_13188);
										mem_vec_13188 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_13189);
										mem_vec_13189 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_13190);
										mem_vec_13190 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_13191);
										mem_vec_13191 = vec_67;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_13192);
										mem_vec_13192 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_13193);
										mem_vec_13193 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_13194);
										mem_vec_13194 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_13195);
										mem_vec_13195 = vec_72;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_13196);
										mem_vec_13196 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_13197);
										mem_vec_13197 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_13198);
										mem_vec_13198 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_13199);
										mem_vec_13199 = vec_77;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_13172);
										mem_vec_13172 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_13173);
										mem_vec_13173 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_13174);
										mem_vec_13174 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_13175);
										mem_vec_13175 = vec_85;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_13176);
										mem_vec_13176 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_13177);
										mem_vec_13177 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_13178);
										mem_vec_13178 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_13179);
										mem_vec_13179 = vec_91;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_13180);
										mem_vec_13180 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_13181);
										mem_vec_13181 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_13182);
										mem_vec_13182 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_13183);
										mem_vec_13183 = vec_96;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_13184);
										mem_vec_13184 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_13185);
										mem_vec_13185 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_13186);
										mem_vec_13186 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_13187);
										mem_vec_13187 = vec_101;
										scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_13188);
										mem_vec_13188 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_13189);
										mem_vec_13189 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_13190);
										mem_vec_13190 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_13191);
										mem_vec_13191 = vec_106;
										scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_13192);
										mem_vec_13192 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_13193);
										mem_vec_13193 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_13194);
										mem_vec_13194 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_13195);
										mem_vec_13195 = vec_111;
										scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_13196);
										mem_vec_13196 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_13197);
										mem_vec_13197 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_13198);
										mem_vec_13198 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_13199);
										mem_vec_13199 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13172);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13173);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13174);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13175);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13176);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13177);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13178);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13179);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13180);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13181);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13182);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13183);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13184);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13185);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_13186);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_13187);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13188);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13189);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_13190);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_13191);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13192);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13193);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_13194);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_13195);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13196);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13197);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_13198);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_13199);
						}
					}
				}
			}
		}
}


}