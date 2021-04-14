#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (8, x);
  T (3, h); T (8, c); T (7, x);
  Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))]; T (2, c)]
*/
IND_TYPE c, cp_0, c1280_p_0, c1281_p_0, cp_1, c1280_p_1, cp_2, c1280, c1281, h, hp_0, x, xp_0, x1352_p_0, xp_1, x1352, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y752 = 0;
IND_TYPE x1353 = 0;
IND_TYPE h590 = 0;
IND_TYPE w = 0;
IND_TYPE c1282 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_13262 ,mem_vec_13263 ,mem_vec_13264 ,mem_vec_13265 ,mem_vec_13266 ,mem_vec_13267 ,mem_vec_13268 ,mem_vec_13269 ,mem_vec_13270 ,mem_vec_13271 ,mem_vec_13272 ,mem_vec_13273 ,mem_vec_13274 ,mem_vec_13275 ,mem_vec_13276 ,mem_vec_13277 ,mem_vec_13278 ,mem_vec_13279 ,mem_vec_13280 ,mem_vec_13281 ,mem_vec_13282 ,mem_vec_13283 ,mem_vec_13284 ,mem_vec_13285 ,mem_vec_13286 ,mem_vec_13287 ,mem_vec_13288 ,mem_vec_13289 ,mem_vec_13290 ,mem_vec_13291 ,mem_vec_13292 ,mem_vec_13293 ,mem_vec_13294 ,mem_vec_13295 ,mem_vec_13296 ,mem_vec_13297 ,mem_vec_13298 ,mem_vec_13299 ,mem_vec_13300 ,mem_vec_13301 ,mem_vec_13302 ,mem_vec_13303 ,mem_vec_13304 ,mem_vec_13305 ,mem_vec_13306 ,mem_vec_13307 ,mem_vec_13308 ,mem_vec_13309 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 2) (64 / 32)
for (c1281 = c1282, c1281_p_0 = 0;
	c1281 < c1282 + 64;
	c1281 += 32, c1281_p_0 += 32){
		for (y = y752, yp_0 = 0;
			y < y752 + 35;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 64
			// T (x, 7) (56 / 8)
			for (x1352 = x1353, x1352_p_0 = 0;
				x1352 < x1353 + 56;
				x1352 += 8, x1352_p_0 += 8){
				// y = ph_y, x = 8, h = 3, w = 3, c = 32, f = 64
				// T (c, 8) (32 / 4)
				for (c1280 = c1281, c1280_p_1 = c1281_p_0, c1280_p_0 = 0;
					c1280 < c1281 + 32;
					c1280 += 4, c1280_p_1 += 4, c1280_p_0 += 4){
					// y = ph_y, x = 8, h = 3, w = 3, c = 4, f = 64
					// T (h, 3) (3 / 1)
					for (h = h590, hp_0 = 0;
						h < h590 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 4, f = 64
						// T (x, 8) (8 / 1)
						for (x = x1352, xp_1 = x1352_p_0, xp_0 = 0;
							x < x1352 + 8;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_13262 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_13263 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_13264 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_13265 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_13266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_13267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_13268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_13269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_13270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_13271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_13272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_13273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_13274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_13275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_13276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_13277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_13278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_13279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_13280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_13281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c1280, cp_2 = c1280_p_1, cp_1 = c1280_p_0, cp_0 = 0;
										c < c1280 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13262);
										mem_vec_13262 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13263);
										mem_vec_13263 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13264);
										mem_vec_13264 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13265);
										mem_vec_13265 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13266);
										mem_vec_13266 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13267);
										mem_vec_13267 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13268);
										mem_vec_13268 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13269);
										mem_vec_13269 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13270);
										mem_vec_13270 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13271);
										mem_vec_13271 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13272);
										mem_vec_13272 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13273);
										mem_vec_13273 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13274);
										mem_vec_13274 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13275);
										mem_vec_13275 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13276);
										mem_vec_13276 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13277);
										mem_vec_13277 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_13278);
										mem_vec_13278 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_13279);
										mem_vec_13279 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_13280);
										mem_vec_13280 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_13281);
										mem_vec_13281 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_13262);
										mem_vec_13262 = vec_29;

										vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_13263);
										mem_vec_13263 = vec_32;

										vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_13264);
										mem_vec_13264 = vec_34;

										vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_13265);
										mem_vec_13265 = vec_36;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_39 = _mm512_set1_ps(scal_6);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_13266);
										mem_vec_13266 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_13267);
										mem_vec_13267 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_13268);
										mem_vec_13268 = vec_41;



										vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_13269);
										mem_vec_13269 = vec_42;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_13270);
										mem_vec_13270 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_13271);
										mem_vec_13271 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_13272);
										mem_vec_13272 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_13273);
										mem_vec_13273 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_13274);
										mem_vec_13274 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_13275);
										mem_vec_13275 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_13276);
										mem_vec_13276 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_13277);
										mem_vec_13277 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_13278);
										mem_vec_13278 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_13279);
										mem_vec_13279 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_13280);
										mem_vec_13280 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_13281);
										mem_vec_13281 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_59 = _mm512_set1_ps(scal_10);
										vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_13262);
										mem_vec_13262 = vec_58;

										vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_13263);
										mem_vec_13263 = vec_61;

										vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_13264);
										mem_vec_13264 = vec_63;

										vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_13265);
										mem_vec_13265 = vec_65;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_68 = _mm512_set1_ps(scal_11);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_13266);
										mem_vec_13266 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_13267);
										mem_vec_13267 = vec_69;



										vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_13268);
										mem_vec_13268 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_13269);
										mem_vec_13269 = vec_71;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_73 = _mm512_set1_ps(scal_12);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_13270);
										mem_vec_13270 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_13271);
										mem_vec_13271 = vec_74;



										vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_13272);
										mem_vec_13272 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_13273);
										mem_vec_13273 = vec_76;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_78 = _mm512_set1_ps(scal_13);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_13274);
										mem_vec_13274 = vec_77;



										vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_13275);
										mem_vec_13275 = vec_79;



										vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_13276);
										mem_vec_13276 = vec_80;



										vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_13277);
										mem_vec_13277 = vec_81;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_83 = _mm512_set1_ps(scal_14);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_13278);
										mem_vec_13278 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_13279);
										mem_vec_13279 = vec_84;



										vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_13280);
										mem_vec_13280 = vec_85;



										vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_13281);
										mem_vec_13281 = vec_86;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13262);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13263);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13264);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13265);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13266);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13267);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13268);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13269);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13270);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13271);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13272);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13273);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13274);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13275);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_13276);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_13277);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13278);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13279);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_13280);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_13281);
						}
					}
				}
			}
		}
		for (y = y752 + 35, yp_0 = 0;
			y < y752 + 35 + 21;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 64
			// T (x, 7) (56 / 8)
			for (x1352 = x1353, x1352_p_0 = 0;
				x1352 < x1353 + 56;
				x1352 += 8, x1352_p_0 += 8){
				// y = ph_y, x = 8, h = 3, w = 3, c = 32, f = 64
				// T (c, 8) (32 / 4)
				for (c1280 = c1281, c1280_p_1 = c1281_p_0, c1280_p_0 = 0;
					c1280 < c1281 + 32;
					c1280 += 4, c1280_p_1 += 4, c1280_p_0 += 4){
					// y = ph_y, x = 8, h = 3, w = 3, c = 4, f = 64
					// T (h, 3) (3 / 1)
					for (h = h590, hp_0 = 0;
						h < h590 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 4, f = 64
						// T (x, 8) (8 / 1)
						for (x = x1352, xp_1 = x1352_p_0, xp_0 = 0;
							x < x1352 + 8;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_13282 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_13283 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_13284 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_13285 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_13286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_13287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_13288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_13289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_13290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_13291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_13292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_13293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_13294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_13295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_13296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_13297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_13298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_13299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_13300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_13301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_13302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_13303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_13304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_13305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_13306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_13307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_13308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_13309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c1280, cp_2 = c1280_p_1, cp_1 = c1280_p_0, cp_0 = 0;
										c < c1280 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13282);
										mem_vec_13282 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13283);
										mem_vec_13283 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13284);
										mem_vec_13284 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13285);
										mem_vec_13285 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13286);
										mem_vec_13286 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13287);
										mem_vec_13287 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13288);
										mem_vec_13288 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13289);
										mem_vec_13289 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13290);
										mem_vec_13290 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13291);
										mem_vec_13291 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13292);
										mem_vec_13292 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13293);
										mem_vec_13293 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13294);
										mem_vec_13294 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13295);
										mem_vec_13295 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13296);
										mem_vec_13296 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13297);
										mem_vec_13297 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_13298);
										mem_vec_13298 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_13299);
										mem_vec_13299 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_13300);
										mem_vec_13300 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_13301);
										mem_vec_13301 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13302);
										mem_vec_13302 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13303);
										mem_vec_13303 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_13304);
										mem_vec_13304 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_13305);
										mem_vec_13305 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_13306);
										mem_vec_13306 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_13307);
										mem_vec_13307 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_13308);
										mem_vec_13308 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_13309);
										mem_vec_13309 = vec_38;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_13282);
										mem_vec_13282 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_13283);
										mem_vec_13283 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_13284);
										mem_vec_13284 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_13285);
										mem_vec_13285 = vec_46;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_13286);
										mem_vec_13286 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_13287);
										mem_vec_13287 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_13288);
										mem_vec_13288 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_13289);
										mem_vec_13289 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_13290);
										mem_vec_13290 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_13291);
										mem_vec_13291 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_13292);
										mem_vec_13292 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_13293);
										mem_vec_13293 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_13294);
										mem_vec_13294 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_13295);
										mem_vec_13295 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_13296);
										mem_vec_13296 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_13297);
										mem_vec_13297 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_13298);
										mem_vec_13298 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_13299);
										mem_vec_13299 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_13300);
										mem_vec_13300 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_13301);
										mem_vec_13301 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_13302);
										mem_vec_13302 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_13303);
										mem_vec_13303 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_13304);
										mem_vec_13304 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_13305);
										mem_vec_13305 = vec_72;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_13306);
										mem_vec_13306 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_13307);
										mem_vec_13307 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_13308);
										mem_vec_13308 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_13309);
										mem_vec_13309 = vec_77;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_13282);
										mem_vec_13282 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_13283);
										mem_vec_13283 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_13284);
										mem_vec_13284 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_13285);
										mem_vec_13285 = vec_85;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_13286);
										mem_vec_13286 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_13287);
										mem_vec_13287 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_13288);
										mem_vec_13288 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_13289);
										mem_vec_13289 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_13290);
										mem_vec_13290 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_13291);
										mem_vec_13291 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_13292);
										mem_vec_13292 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_13293);
										mem_vec_13293 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_13294);
										mem_vec_13294 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_13295);
										mem_vec_13295 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_13296);
										mem_vec_13296 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_13297);
										mem_vec_13297 = vec_101;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_13298);
										mem_vec_13298 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_13299);
										mem_vec_13299 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_13300);
										mem_vec_13300 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_13301);
										mem_vec_13301 = vec_106;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_13302);
										mem_vec_13302 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_13303);
										mem_vec_13303 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_13304);
										mem_vec_13304 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_13305);
										mem_vec_13305 = vec_111;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_13306);
										mem_vec_13306 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_13307);
										mem_vec_13307 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_13308);
										mem_vec_13308 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_13309);
										mem_vec_13309 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13282);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13283);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13284);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13285);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13286);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13287);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13288);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13289);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13290);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13291);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13292);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13293);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13294);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13295);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_13296);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_13297);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13298);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13299);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_13300);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_13301);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13302);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13303);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_13304);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_13305);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13306);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13307);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_13308);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_13309);
						}
					}
				}
			}
		}
}


}