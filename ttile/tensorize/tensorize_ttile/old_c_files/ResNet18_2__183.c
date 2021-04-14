#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (4, x);
  T (3, w); T (4, c); T (14, x);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (2, c)]
*/
IND_TYPE c, cp_0, c1112_p_0, c1113_p_0, cp_1, c1112_p_1, cp_2, c1112, c1113, w, wp_0, x, xp_0, x1226_p_0, xp_1, x1226, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y668 = 0;
IND_TYPE x1227 = 0;
IND_TYPE h = 0;
IND_TYPE w634 = 0;
IND_TYPE c1114 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11262 ,mem_vec_11263 ,mem_vec_11264 ,mem_vec_11265 ,mem_vec_11266 ,mem_vec_11267 ,mem_vec_11268 ,mem_vec_11269 ,mem_vec_11270 ,mem_vec_11271 ,mem_vec_11272 ,mem_vec_11273 ,mem_vec_11274 ,mem_vec_11275 ,mem_vec_11276 ,mem_vec_11277 ,mem_vec_11278 ,mem_vec_11279 ,mem_vec_11280 ,mem_vec_11281 ,mem_vec_11282 ,mem_vec_11283 ,mem_vec_11284 ,mem_vec_11285 ,mem_vec_11286 ,mem_vec_11287 ,mem_vec_11288 ,mem_vec_11289 ,mem_vec_11290 ,mem_vec_11291 ,mem_vec_11292 ,mem_vec_11293 ,mem_vec_11294 ,mem_vec_11295 ,mem_vec_11296 ,mem_vec_11297 ,mem_vec_11298 ,mem_vec_11299 ,mem_vec_11300 ,mem_vec_11301 ,mem_vec_11302 ,mem_vec_11303 ,mem_vec_11304 ,mem_vec_11305 ,mem_vec_11306 ,mem_vec_11307 ,mem_vec_11308 ,mem_vec_11309 ,mem_vec_11310 ,mem_vec_11311 ,mem_vec_11312 ,mem_vec_11313 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 2) (64 / 32)
for (c1113 = c1114, c1113_p_0 = 0;
	c1113 < c1114 + 64;
	c1113 += 32, c1113_p_0 += 32){
		for (y = y668, yp_0 = 0;
			y < y668 + 42;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 64
			// T (x, 14) (56 / 4)
			for (x1226 = x1227, x1226_p_0 = 0;
				x1226 < x1227 + 56;
				x1226 += 4, x1226_p_0 += 4){
				// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 64
				// T (c, 4) (32 / 8)
				for (c1112 = c1113, c1112_p_1 = c1113_p_0, c1112_p_0 = 0;
					c1112 < c1113 + 32;
					c1112 += 8, c1112_p_1 += 8, c1112_p_0 += 8){
					// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 64
					// T (w, 3) (3 / 1)
					for (w = w634, wp_0 = 0;
						w < w634 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 4, h = 3, w = 1, c = 8, f = 64
						// T (x, 4) (4 / 1)
						for (x = x1226, xp_1 = x1226_p_0, xp_0 = 0;
							x < x1226 + 4;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_11262 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_11263 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_11264 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_11265 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_11266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_11267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_11268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_11269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_11270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_11271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_11272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_11273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_11274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_11275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_11276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_11277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_11278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_11279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_11280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_11281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_11282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_11283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_11284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_11285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1112, cp_2 = c1112_p_1, cp_1 = c1112_p_0, cp_0 = 0;
										c < c1112 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11262);
										mem_vec_11262 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11263);
										mem_vec_11263 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11264);
										mem_vec_11264 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11265);
										mem_vec_11265 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11266);
										mem_vec_11266 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11267);
										mem_vec_11267 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11268);
										mem_vec_11268 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11269);
										mem_vec_11269 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11270);
										mem_vec_11270 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11271);
										mem_vec_11271 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11272);
										mem_vec_11272 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11273);
										mem_vec_11273 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11274);
										mem_vec_11274 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11275);
										mem_vec_11275 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11276);
										mem_vec_11276 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11277);
										mem_vec_11277 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11278);
										mem_vec_11278 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11279);
										mem_vec_11279 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11280);
										mem_vec_11280 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11281);
										mem_vec_11281 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11282);
										mem_vec_11282 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11283);
										mem_vec_11283 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_11284);
										mem_vec_11284 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_11285);
										mem_vec_11285 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_11262);
										mem_vec_11262 = vec_34;

										vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_11263);
										mem_vec_11263 = vec_37;

										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_11264);
										mem_vec_11264 = vec_39;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_11265);
										mem_vec_11265 = vec_41;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_11266);
										mem_vec_11266 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_11267);
										mem_vec_11267 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_11268);
										mem_vec_11268 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_11269);
										mem_vec_11269 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_11270);
										mem_vec_11270 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_11271);
										mem_vec_11271 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_11272);
										mem_vec_11272 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_11273);
										mem_vec_11273 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_11274);
										mem_vec_11274 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_11275);
										mem_vec_11275 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_11276);
										mem_vec_11276 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_11277);
										mem_vec_11277 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_11278);
										mem_vec_11278 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_11279);
										mem_vec_11279 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_11280);
										mem_vec_11280 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_11281);
										mem_vec_11281 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_11282);
										mem_vec_11282 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_11283);
										mem_vec_11283 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_11284);
										mem_vec_11284 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_11285);
										mem_vec_11285 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_69 = _mm512_set1_ps(scal_12);
										vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_11262);
										mem_vec_11262 = vec_68;

										vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_11263);
										mem_vec_11263 = vec_71;

										vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_11264);
										mem_vec_11264 = vec_73;

										vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_11265);
										mem_vec_11265 = vec_75;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_78 = _mm512_set1_ps(scal_13);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_11266);
										mem_vec_11266 = vec_77;



										vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_11267);
										mem_vec_11267 = vec_79;



										vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_11268);
										mem_vec_11268 = vec_80;



										vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_11269);
										mem_vec_11269 = vec_81;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_83 = _mm512_set1_ps(scal_14);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_11270);
										mem_vec_11270 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_11271);
										mem_vec_11271 = vec_84;



										vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_11272);
										mem_vec_11272 = vec_85;



										vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_11273);
										mem_vec_11273 = vec_86;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_11274);
										mem_vec_11274 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_11275);
										mem_vec_11275 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_11276);
										mem_vec_11276 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_11277);
										mem_vec_11277 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_11278);
										mem_vec_11278 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_11279);
										mem_vec_11279 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_11280);
										mem_vec_11280 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_11281);
										mem_vec_11281 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_11282);
										mem_vec_11282 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_11283);
										mem_vec_11283 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_11284);
										mem_vec_11284 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_11285);
										mem_vec_11285 = vec_101;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11262);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11263);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11264);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11265);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11266);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11267);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11268);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11269);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11270);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11271);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11272);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11273);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11274);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11275);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_11276);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_11277);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11278);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11279);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_11280);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_11281);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11282);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11283);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_11284);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_11285);
						}
					}
				}
			}
		}
		for (y = y668 + 42, yp_0 = 0;
			y < y668 + 42 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 64
			// T (x, 14) (56 / 4)
			for (x1226 = x1227, x1226_p_0 = 0;
				x1226 < x1227 + 56;
				x1226 += 4, x1226_p_0 += 4){
				// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 64
				// T (c, 4) (32 / 8)
				for (c1112 = c1113, c1112_p_1 = c1113_p_0, c1112_p_0 = 0;
					c1112 < c1113 + 32;
					c1112 += 8, c1112_p_1 += 8, c1112_p_0 += 8){
					// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 64
					// T (w, 3) (3 / 1)
					for (w = w634, wp_0 = 0;
						w < w634 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 4, h = 3, w = 1, c = 8, f = 64
						// T (x, 4) (4 / 1)
						for (x = x1226, xp_1 = x1226_p_0, xp_0 = 0;
							x < x1226 + 4;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_11286 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_11287 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_11288 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_11289 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_11290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_11291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_11292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_11293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_11294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_11295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_11296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_11297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_11298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_11299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_11300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_11301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_11302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_11303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_11304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_11305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_11306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_11307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_11308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_11309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_11310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_11311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_11312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_11313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1112, cp_2 = c1112_p_1, cp_1 = c1112_p_0, cp_0 = 0;
										c < c1112 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11286);
										mem_vec_11286 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11287);
										mem_vec_11287 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11288);
										mem_vec_11288 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11289);
										mem_vec_11289 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11290);
										mem_vec_11290 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11291);
										mem_vec_11291 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11292);
										mem_vec_11292 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11293);
										mem_vec_11293 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11294);
										mem_vec_11294 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11295);
										mem_vec_11295 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11296);
										mem_vec_11296 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11297);
										mem_vec_11297 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11298);
										mem_vec_11298 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11299);
										mem_vec_11299 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11300);
										mem_vec_11300 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11301);
										mem_vec_11301 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11302);
										mem_vec_11302 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11303);
										mem_vec_11303 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11304);
										mem_vec_11304 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11305);
										mem_vec_11305 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11306);
										mem_vec_11306 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11307);
										mem_vec_11307 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_11308);
										mem_vec_11308 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_11309);
										mem_vec_11309 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_11310);
										mem_vec_11310 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_11311);
										mem_vec_11311 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_11312);
										mem_vec_11312 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_11313);
										mem_vec_11313 = vec_38;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_11286);
										mem_vec_11286 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_11287);
										mem_vec_11287 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_11288);
										mem_vec_11288 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_11289);
										mem_vec_11289 = vec_46;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_11290);
										mem_vec_11290 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_11291);
										mem_vec_11291 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_11292);
										mem_vec_11292 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_11293);
										mem_vec_11293 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_11294);
										mem_vec_11294 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_11295);
										mem_vec_11295 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_11296);
										mem_vec_11296 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_11297);
										mem_vec_11297 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_11298);
										mem_vec_11298 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_11299);
										mem_vec_11299 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_11300);
										mem_vec_11300 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_11301);
										mem_vec_11301 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_11302);
										mem_vec_11302 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_11303);
										mem_vec_11303 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_11304);
										mem_vec_11304 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_11305);
										mem_vec_11305 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_11306);
										mem_vec_11306 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_11307);
										mem_vec_11307 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_11308);
										mem_vec_11308 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_11309);
										mem_vec_11309 = vec_72;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_11310);
										mem_vec_11310 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_11311);
										mem_vec_11311 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_11312);
										mem_vec_11312 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_11313);
										mem_vec_11313 = vec_77;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_11286);
										mem_vec_11286 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_11287);
										mem_vec_11287 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_11288);
										mem_vec_11288 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_11289);
										mem_vec_11289 = vec_85;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_11290);
										mem_vec_11290 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_11291);
										mem_vec_11291 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_11292);
										mem_vec_11292 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_11293);
										mem_vec_11293 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_11294);
										mem_vec_11294 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_11295);
										mem_vec_11295 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_11296);
										mem_vec_11296 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_11297);
										mem_vec_11297 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_11298);
										mem_vec_11298 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_11299);
										mem_vec_11299 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_11300);
										mem_vec_11300 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_11301);
										mem_vec_11301 = vec_101;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_11302);
										mem_vec_11302 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_11303);
										mem_vec_11303 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_11304);
										mem_vec_11304 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_11305);
										mem_vec_11305 = vec_106;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_11306);
										mem_vec_11306 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_11307);
										mem_vec_11307 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_11308);
										mem_vec_11308 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_11309);
										mem_vec_11309 = vec_111;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_11310);
										mem_vec_11310 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_11311);
										mem_vec_11311 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_11312);
										mem_vec_11312 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_11313);
										mem_vec_11313 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11286);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11287);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11288);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11289);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11290);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11291);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11292);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11293);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11294);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11295);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11296);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11297);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11298);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11299);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_11300);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_11301);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11302);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11303);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_11304);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_11305);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11306);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11307);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_11308);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_11309);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11310);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11311);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_11312);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_11313);
						}
					}
				}
			}
		}
}


}