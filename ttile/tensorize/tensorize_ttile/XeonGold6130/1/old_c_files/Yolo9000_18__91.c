#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (17, x); T (32, c);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (16, f);
  T (1, c); T (1, c)]
*/
IND_TYPE c, cp_0, c40_p_0, c41_p_0, c42_p_0, cp_1, c40_p_1, c41_p_1, cp_2, c40_p_2, cp_3, c40, c41, c42, f, fp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y16 = 0;
IND_TYPE x16 = 0;
IND_TYPE h = 0;
IND_TYPE w16 = 0;
IND_TYPE c43 = 0;
IND_TYPE f16 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_316 ,mem_vec_317 ,mem_vec_318 ,mem_vec_319 ,mem_vec_320 ,mem_vec_321 ,mem_vec_322 ,mem_vec_323 ,mem_vec_324 ,mem_vec_325 ,mem_vec_326 ,mem_vec_327 ,mem_vec_328 ,mem_vec_329 ,mem_vec_330 ,mem_vec_331 ,mem_vec_332 ,mem_vec_333 ,mem_vec_334 ,mem_vec_335 ,mem_vec_336 ,mem_vec_337 ,mem_vec_338 ,mem_vec_339 ,mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,mem_vec_346 ,mem_vec_347 ,mem_vec_348 ,mem_vec_349 ,mem_vec_350 ,mem_vec_351 ,mem_vec_352 ,mem_vec_353 ,mem_vec_354 ,mem_vec_355 ,mem_vec_356 ,mem_vec_357 ,mem_vec_358 ,mem_vec_359 ,mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 1) (512 / 512)
for (c42 = c43, c42_p_0 = 0;
	c42 < c43 + 512;
	c42 += 512, c42_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 1) (512 / 512)
	for (c41 = c42, c41_p_1 = c42_p_0, c41_p_0 = 0;
		c41 < c42 + 512;
		c41 += 512, c41_p_1 += 512, c41_p_0 += 512){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
		// T (f, 16) (1024 / 64)
		for (f = f16, fp_0 = 0;
			f < f16 + 1024;
			f += 64, fp_0 += 64){
				for (y = y16, yp_0 = 0;
					y < y16 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 64
					// T (c, 32) (512 / 16)
					for (c40 = c41, c40_p_2 = c41_p_1, c40_p_1 = c41_p_0, c40_p_0 = 0;
						c40 < c41 + 512;
						c40 += 16, c40_p_2 += 16, c40_p_1 += 16, c40_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x16, xp_0 = 0;
							x < x16 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
							// T (w, 3) (3 / 1)
							for (w = w16, wp_0 = 0;
								w < w16 + 3;
								w += 1, wp_0 += 1){
										mem_vec_316 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_317 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_318 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_319 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c40, cp_3 = c40_p_2, cp_2 = c40_p_1, cp_1 = c40_p_0, cp_0 = 0;
											c < c40 + 16;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_316);
											mem_vec_316 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_317);
											mem_vec_317 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_318);
											mem_vec_318 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_319);
											mem_vec_319 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_320);
											mem_vec_320 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_321);
											mem_vec_321 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_322);
											mem_vec_322 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_323);
											mem_vec_323 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_324);
											mem_vec_324 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_325);
											mem_vec_325 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_326);
											mem_vec_326 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_327);
											mem_vec_327 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_328);
											mem_vec_328 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_329);
											mem_vec_329 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_330);
											mem_vec_330 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_331);
											mem_vec_331 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_332);
											mem_vec_332 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_333);
											mem_vec_333 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_334);
											mem_vec_334 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_335);
											mem_vec_335 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_316);
											mem_vec_316 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_317);
											mem_vec_317 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_318);
											mem_vec_318 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_319);
											mem_vec_319 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_320);
											mem_vec_320 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_321);
											mem_vec_321 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_322);
											mem_vec_322 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_323);
											mem_vec_323 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_324);
											mem_vec_324 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_325);
											mem_vec_325 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_326);
											mem_vec_326 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_327);
											mem_vec_327 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_328);
											mem_vec_328 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_329);
											mem_vec_329 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_330);
											mem_vec_330 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_331);
											mem_vec_331 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_332);
											mem_vec_332 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_333);
											mem_vec_333 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_334);
											mem_vec_334 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_335);
											mem_vec_335 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_316);
											mem_vec_316 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_317);
											mem_vec_317 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_318);
											mem_vec_318 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_319);
											mem_vec_319 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_320);
											mem_vec_320 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_321);
											mem_vec_321 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_322);
											mem_vec_322 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_323);
											mem_vec_323 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_324);
											mem_vec_324 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_325);
											mem_vec_325 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_326);
											mem_vec_326 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_327);
											mem_vec_327 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_328);
											mem_vec_328 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_329);
											mem_vec_329 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_330);
											mem_vec_330 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_331);
											mem_vec_331 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_332);
											mem_vec_332 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_333);
											mem_vec_333 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_334);
											mem_vec_334 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_335);
											mem_vec_335 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_316);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_317);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_318);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_319);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_320);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_321);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_322);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_323);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_324);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_325);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_326);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_327);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_328);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_329);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_330);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_331);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_332);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_333);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_334);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_335);
							}
						}
					}
				}
				for (y = y16 + 10, yp_0 = 0;
					y < y16 + 10 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 64
					// T (c, 32) (512 / 16)
					for (c40 = c41, c40_p_2 = c41_p_1, c40_p_1 = c41_p_0, c40_p_0 = 0;
						c40 < c41 + 512;
						c40 += 16, c40_p_2 += 16, c40_p_1 += 16, c40_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x16, xp_0 = 0;
							x < x16 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
							// T (w, 3) (3 / 1)
							for (w = w16, wp_0 = 0;
								w < w16 + 3;
								w += 1, wp_0 += 1){
										mem_vec_336 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_337 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_338 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_339 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c40, cp_3 = c40_p_2, cp_2 = c40_p_1, cp_1 = c40_p_0, cp_0 = 0;
											c < c40 + 16;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_336);
											mem_vec_336 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_337);
											mem_vec_337 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_338);
											mem_vec_338 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_339);
											mem_vec_339 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_340);
											mem_vec_340 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_341);
											mem_vec_341 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_342);
											mem_vec_342 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_343);
											mem_vec_343 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_344);
											mem_vec_344 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_345);
											mem_vec_345 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_346);
											mem_vec_346 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_347);
											mem_vec_347 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_348);
											mem_vec_348 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_349);
											mem_vec_349 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_350);
											mem_vec_350 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_351);
											mem_vec_351 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_352);
											mem_vec_352 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_353);
											mem_vec_353 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_354);
											mem_vec_354 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_355);
											mem_vec_355 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_356);
											mem_vec_356 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_357);
											mem_vec_357 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_358);
											mem_vec_358 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_359);
											mem_vec_359 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_360);
											mem_vec_360 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_361);
											mem_vec_361 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_362);
											mem_vec_362 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_363);
											mem_vec_363 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_40 = _mm512_set1_ps(scal_7);
											vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_336);
											mem_vec_336 = vec_39;

											vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_337);
											mem_vec_337 = vec_42;

											vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_338);
											mem_vec_338 = vec_44;

											vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_339);
											mem_vec_339 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_340);
											mem_vec_340 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_341);
											mem_vec_341 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_342);
											mem_vec_342 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_343);
											mem_vec_343 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_344);
											mem_vec_344 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_345);
											mem_vec_345 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_346);
											mem_vec_346 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_347);
											mem_vec_347 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_348);
											mem_vec_348 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_349);
											mem_vec_349 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_350);
											mem_vec_350 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_351);
											mem_vec_351 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_352);
											mem_vec_352 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_353);
											mem_vec_353 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_354);
											mem_vec_354 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_355);
											mem_vec_355 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_69 = _mm512_set1_ps(scal_12);


											vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_356);
											mem_vec_356 = vec_68;



											vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_357);
											mem_vec_357 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_358);
											mem_vec_358 = vec_71;



											vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_359);
											mem_vec_359 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_74 = _mm512_set1_ps(scal_13);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_360);
											mem_vec_360 = vec_73;



											vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_361);
											mem_vec_361 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_362);
											mem_vec_362 = vec_76;



											vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_363);
											mem_vec_363 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_14);
											vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_336);
											mem_vec_336 = vec_78;

											vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_337);
											mem_vec_337 = vec_81;

											vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_338);
											mem_vec_338 = vec_83;

											vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_339);
											mem_vec_339 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_340);
											mem_vec_340 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_341);
											mem_vec_341 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_342);
											mem_vec_342 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_343);
											mem_vec_343 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_344);
											mem_vec_344 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_345);
											mem_vec_345 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_346);
											mem_vec_346 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_347);
											mem_vec_347 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_348);
											mem_vec_348 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_349);
											mem_vec_349 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_350);
											mem_vec_350 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_351);
											mem_vec_351 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_18);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_352);
											mem_vec_352 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_353);
											mem_vec_353 = vec_104;



											vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_354);
											mem_vec_354 = vec_105;



											vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_355);
											mem_vec_355 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_108 = _mm512_set1_ps(scal_19);


											vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_356);
											mem_vec_356 = vec_107;



											vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_357);
											mem_vec_357 = vec_109;



											vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_358);
											mem_vec_358 = vec_110;



											vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_359);
											mem_vec_359 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_113 = _mm512_set1_ps(scal_20);


											vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_360);
											mem_vec_360 = vec_112;



											vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_361);
											mem_vec_361 = vec_114;



											vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_362);
											mem_vec_362 = vec_115;



											vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_363);
											mem_vec_363 = vec_116;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_336);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_337);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_338);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_339);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_340);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_341);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_342);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_343);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_344);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_345);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_346);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_347);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_348);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_349);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_350);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_351);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_352);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_353);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_354);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_355);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_356);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_357);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_358);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_359);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_360);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_361);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_362);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_363);
							}
						}
					}
				}
		}
	}
}


}