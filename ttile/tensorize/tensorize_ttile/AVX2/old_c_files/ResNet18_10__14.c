#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); U (3, h); T (64, c); Hoist_vars [c]; T (3, w);
  T (7, x); T (1, y); T (4, f); T (8, c); T (2, f); T (2, f)]
*/
IND_TYPE c, cp_0, c33_p_0, cp_1, c33, f, fp_0, f44_p_0, f45_p_0, fp_1, f44_p_1, fp_2, f44, f45, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y22 = 0;
IND_TYPE x22 = 0;
IND_TYPE h = 0;
IND_TYPE w17 = 0;
IND_TYPE c34 = 0;
IND_TYPE f46 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_308 ,mem_vec_309 ,mem_vec_310 ,mem_vec_311 ,mem_vec_312 ,mem_vec_313 ,mem_vec_314 ,mem_vec_315 ,mem_vec_316 ,mem_vec_317 ,mem_vec_318 ,mem_vec_319 ,mem_vec_320 ,mem_vec_321 ,mem_vec_322 ,mem_vec_323 ,mem_vec_324 ,mem_vec_325 ,mem_vec_326 ,mem_vec_327 ,mem_vec_328 ,mem_vec_329 ,mem_vec_330 ,mem_vec_331 ,mem_vec_332 ,mem_vec_333 ,mem_vec_334 ,mem_vec_335 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (f, 2) (512 / 256)
for (f45 = f46, f45_p_0 = 0;
	f45 < f46 + 512;
	f45 += 256, f45_p_0 += 256){
	// y = 7, x = 7, h = 3, w = 3, c = 512, f = 256
	// T (f, 2) (256 / 128)
	for (f44 = f45, f44_p_1 = f45_p_0, f44_p_0 = 0;
		f44 < f45 + 256;
		f44 += 128, f44_p_1 += 128, f44_p_0 += 128){
		// y = 7, x = 7, h = 3, w = 3, c = 512, f = 128
		// T (c, 8) (512 / 64)
		for (c33 = c34, c33_p_0 = 0;
			c33 < c34 + 512;
			c33 += 64, c33_p_0 += 64){
			// y = 7, x = 7, h = 3, w = 3, c = 64, f = 128
			// T (f, 4) (128 / 32)
			for (f = f44, fp_2 = f44_p_1, fp_1 = f44_p_0, fp_0 = 0;
				f < f44 + 128;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
				// y = 7, x = 7, h = 3, w = 3, c = 64, f = 32
				// T (y, 1) (7 / 7)
				for (y = y22, yp_0 = 0;
					y < y22 + 7;
					y += 7, yp_0 += 7){
					// y = 7, x = 7, h = 3, w = 3, c = 64, f = 32
					// T (x, 7) (7 / 1)
					for (x = x22, xp_0 = 0;
						x < x22 + 7;
						x += 1, xp_0 += 1){
						// y = 7, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w17, wp_0 = 0;
							w < w17 + 3;
							w += 1, wp_0 += 1){
									mem_vec_308 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_309 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_310 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_311 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_312 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_313 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_314 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_315 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_316 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_317 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_318 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_319 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_320 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_321 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_322 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_323 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_324 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_325 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_326 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_327 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									mem_vec_328 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_329 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
									mem_vec_330 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_331 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
									mem_vec_332 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_333 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
									mem_vec_334 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_335 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
									// y = 7, x = 1, h = 3, w = 1, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c33, cp_1 = c33_p_0, cp_0 = 0;
										c < c33 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_308);
										mem_vec_308 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_309);
										mem_vec_309 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_310);
										mem_vec_310 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_311);
										mem_vec_311 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_312);
										mem_vec_312 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_313);
										mem_vec_313 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_314);
										mem_vec_314 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_315);
										mem_vec_315 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_316);
										mem_vec_316 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_317);
										mem_vec_317 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_318);
										mem_vec_318 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_319);
										mem_vec_319 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_320);
										mem_vec_320 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_321);
										mem_vec_321 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_322);
										mem_vec_322 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_323);
										mem_vec_323 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_324);
										mem_vec_324 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_325);
										mem_vec_325 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_326);
										mem_vec_326 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_327);
										mem_vec_327 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm256_set1_ps(scal_5);


										vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_328);
										mem_vec_328 = vec_29;



										vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_329);
										mem_vec_329 = vec_31;



										vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_330);
										mem_vec_330 = vec_32;



										vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_331);
										mem_vec_331 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_35 = _mm256_set1_ps(scal_6);


										vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_332);
										mem_vec_332 = vec_34;



										vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_333);
										mem_vec_333 = vec_36;



										vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_334);
										mem_vec_334 = vec_37;



										vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_335);
										mem_vec_335 = vec_38;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_40 = _mm256_set1_ps(scal_7);
										vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_308);
										mem_vec_308 = vec_39;

										vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

										vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_309);
										mem_vec_309 = vec_42;

										vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_310);
										mem_vec_310 = vec_44;

										vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

										vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_311);
										mem_vec_311 = vec_46;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_49 = _mm256_set1_ps(scal_8);


										vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_312);
										mem_vec_312 = vec_48;



										vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_313);
										mem_vec_313 = vec_50;



										vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_314);
										mem_vec_314 = vec_51;



										vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_315);
										mem_vec_315 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_54 = _mm256_set1_ps(scal_9);


										vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_316);
										mem_vec_316 = vec_53;



										vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_317);
										mem_vec_317 = vec_55;



										vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_318);
										mem_vec_318 = vec_56;



										vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_319);
										mem_vec_319 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_59 = _mm256_set1_ps(scal_10);


										vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_320);
										mem_vec_320 = vec_58;



										vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_321);
										mem_vec_321 = vec_60;



										vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_322);
										mem_vec_322 = vec_61;



										vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_323);
										mem_vec_323 = vec_62;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
										vec_64 = _mm256_set1_ps(scal_11);


										vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_324);
										mem_vec_324 = vec_63;



										vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_325);
										mem_vec_325 = vec_65;



										vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_326);
										mem_vec_326 = vec_66;



										vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_327);
										mem_vec_327 = vec_67;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
										vec_69 = _mm256_set1_ps(scal_12);


										vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_328);
										mem_vec_328 = vec_68;



										vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_329);
										mem_vec_329 = vec_70;



										vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_330);
										mem_vec_330 = vec_71;



										vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_331);
										mem_vec_331 = vec_72;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
										vec_74 = _mm256_set1_ps(scal_13);


										vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_332);
										mem_vec_332 = vec_73;



										vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_333);
										mem_vec_333 = vec_75;



										vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_334);
										mem_vec_334 = vec_76;



										vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_335);
										mem_vec_335 = vec_77;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_79 = _mm256_set1_ps(scal_14);
										vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_308);
										mem_vec_308 = vec_78;

										vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

										vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_309);
										mem_vec_309 = vec_81;

										vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_310);
										mem_vec_310 = vec_83;

										vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

										vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_311);
										mem_vec_311 = vec_85;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_88 = _mm256_set1_ps(scal_15);


										vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_312);
										mem_vec_312 = vec_87;



										vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_313);
										mem_vec_313 = vec_89;



										vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_314);
										mem_vec_314 = vec_90;



										vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_315);
										mem_vec_315 = vec_91;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_93 = _mm256_set1_ps(scal_16);


										vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_316);
										mem_vec_316 = vec_92;



										vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_317);
										mem_vec_317 = vec_94;



										vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_318);
										mem_vec_318 = vec_95;



										vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_319);
										mem_vec_319 = vec_96;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_98 = _mm256_set1_ps(scal_17);


										vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_320);
										mem_vec_320 = vec_97;



										vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_321);
										mem_vec_321 = vec_99;



										vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_322);
										mem_vec_322 = vec_100;



										vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_323);
										mem_vec_323 = vec_101;
										scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
										vec_103 = _mm256_set1_ps(scal_18);


										vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_324);
										mem_vec_324 = vec_102;



										vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_325);
										mem_vec_325 = vec_104;



										vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_326);
										mem_vec_326 = vec_105;



										vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_327);
										mem_vec_327 = vec_106;
										scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
										vec_108 = _mm256_set1_ps(scal_19);


										vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_328);
										mem_vec_328 = vec_107;



										vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_329);
										mem_vec_329 = vec_109;



										vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_330);
										mem_vec_330 = vec_110;



										vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_331);
										mem_vec_331 = vec_111;
										scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
										vec_113 = _mm256_set1_ps(scal_20);


										vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_332);
										mem_vec_332 = vec_112;



										vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_333);
										mem_vec_333 = vec_114;



										vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_334);
										mem_vec_334 = vec_115;



										vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_335);
										mem_vec_335 = vec_116;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_308);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_309);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_310);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_311);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_312);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_313);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_314);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_315);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_316);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_317);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_318);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_319);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_320);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_321);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_322);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_323);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_324);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_325);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_326);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_327);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_328);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_329);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_330);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_331);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_332);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_333);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_334);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_335);
						}
					}
				}
			}
		}
	}
}


}