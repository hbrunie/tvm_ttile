#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (34, x); T (8, c);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (16, f);
  T (2, c); T (1, f)]
*/
IND_TYPE c, cp_0, c22_p_0, c23_p_0, cp_1, c22_p_1, cp_2, c22, c23, f, fp_0, f27_p_0, fp_1, f27, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y20 = 0;
IND_TYPE x14 = 0;
IND_TYPE h = 0;
IND_TYPE w14 = 0;
IND_TYPE c24 = 0;
IND_TYPE f28 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_268 ,mem_vec_269 ,mem_vec_270 ,mem_vec_271 ,mem_vec_272 ,mem_vec_273 ,mem_vec_274 ,mem_vec_275 ,mem_vec_276 ,mem_vec_277 ,mem_vec_278 ,mem_vec_279 ,mem_vec_280 ,mem_vec_281 ,mem_vec_282 ,mem_vec_283 ,mem_vec_284 ,mem_vec_285 ,mem_vec_286 ,mem_vec_287 ,mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,mem_vec_294 ,mem_vec_295 ,mem_vec_296 ,mem_vec_297 ,mem_vec_298 ,mem_vec_299 ,mem_vec_300 ,mem_vec_301 ,mem_vec_302 ,mem_vec_303 ,mem_vec_304 ,mem_vec_305 ,mem_vec_306 ,mem_vec_307 ,mem_vec_308 ,mem_vec_309 ,mem_vec_310 ,mem_vec_311 ,mem_vec_312 ,mem_vec_313 ,mem_vec_314 ,mem_vec_315 ,mem_vec_316 ,mem_vec_317 ,mem_vec_318 ,mem_vec_319 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f27 = f28, f27_p_0 = 0;
	f27 < f28 + 512;
	f27 += 512, f27_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 2) (256 / 128)
	for (c23 = c24, c23_p_0 = 0;
		c23 < c24 + 256;
		c23 += 128, c23_p_0 += 128){
		// y = 34, x = 34, h = 3, w = 3, c = 128, f = 512
		// T (f, 16) (512 / 32)
		for (f = f27, fp_1 = f27_p_0, fp_0 = 0;
			f < f27 + 512;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y20, yp_0 = 0;
					y < y20 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (c, 8) (128 / 16)
					for (c22 = c23, c22_p_1 = c23_p_0, c22_p_0 = 0;
						c22 < c23 + 128;
						c22 += 16, c22_p_1 += 16, c22_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (x, 34) (34 / 1)
						for (x = x14, xp_0 = 0;
							x < x14 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w14, wp_0 = 0;
								w < w14 + 3;
								w += 1, wp_0 += 1){
										mem_vec_268 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_269 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_270 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_271 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_272 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_273 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_274 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_275 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_276 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_277 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_278 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_279 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_280 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_281 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_282 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_283 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_284 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_285 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_286 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_287 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_288 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_289 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_290 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_291 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c22, cp_2 = c22_p_1, cp_1 = c22_p_0, cp_0 = 0;
											c < c22 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_268);
											mem_vec_268 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_269);
											mem_vec_269 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_270);
											mem_vec_270 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_271);
											mem_vec_271 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_272);
											mem_vec_272 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_273);
											mem_vec_273 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_274);
											mem_vec_274 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_275);
											mem_vec_275 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_276);
											mem_vec_276 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_277);
											mem_vec_277 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_278);
											mem_vec_278 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_279);
											mem_vec_279 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_280);
											mem_vec_280 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_281);
											mem_vec_281 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_282);
											mem_vec_282 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_283);
											mem_vec_283 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_284);
											mem_vec_284 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_285);
											mem_vec_285 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_286);
											mem_vec_286 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_287);
											mem_vec_287 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_288);
											mem_vec_288 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_289);
											mem_vec_289 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_290);
											mem_vec_290 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_291);
											mem_vec_291 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_268);
											mem_vec_268 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_269);
											mem_vec_269 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_270);
											mem_vec_270 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_271);
											mem_vec_271 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_272);
											mem_vec_272 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_273);
											mem_vec_273 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_274);
											mem_vec_274 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_275);
											mem_vec_275 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_276);
											mem_vec_276 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_277);
											mem_vec_277 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_278);
											mem_vec_278 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_279);
											mem_vec_279 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_280);
											mem_vec_280 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_281);
											mem_vec_281 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_282);
											mem_vec_282 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_283);
											mem_vec_283 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_284);
											mem_vec_284 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_285);
											mem_vec_285 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_286);
											mem_vec_286 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_287);
											mem_vec_287 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_288);
											mem_vec_288 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_289);
											mem_vec_289 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_290);
											mem_vec_290 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_291);
											mem_vec_291 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_268);
											mem_vec_268 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_269);
											mem_vec_269 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_270);
											mem_vec_270 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_271);
											mem_vec_271 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_272);
											mem_vec_272 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_273);
											mem_vec_273 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_274);
											mem_vec_274 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_275);
											mem_vec_275 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_276);
											mem_vec_276 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_277);
											mem_vec_277 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_278);
											mem_vec_278 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_279);
											mem_vec_279 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_280);
											mem_vec_280 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_281);
											mem_vec_281 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_282);
											mem_vec_282 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_283);
											mem_vec_283 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_284);
											mem_vec_284 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_285);
											mem_vec_285 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_286);
											mem_vec_286 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_287);
											mem_vec_287 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_288);
											mem_vec_288 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_289);
											mem_vec_289 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_290);
											mem_vec_290 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_291);
											mem_vec_291 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_268);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_269);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_270);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_271);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_272);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_273);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_274);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_275);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_276);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_277);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_278);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_279);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_280);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_281);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_282);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_283);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_284);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_285);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_286);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_287);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_288);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_289);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_290);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_291);
							}
						}
					}
				}
				for (y = y20 + 6, yp_0 = 0;
					y < y20 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (c, 8) (128 / 16)
					for (c22 = c23, c22_p_1 = c23_p_0, c22_p_0 = 0;
						c22 < c23 + 128;
						c22 += 16, c22_p_1 += 16, c22_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (x, 34) (34 / 1)
						for (x = x14, xp_0 = 0;
							x < x14 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w14, wp_0 = 0;
								w < w14 + 3;
								w += 1, wp_0 += 1){
										mem_vec_292 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_293 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_294 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_295 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_296 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_297 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_298 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_299 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_300 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_301 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_302 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_303 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_304 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_305 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_306 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_307 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_308 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_309 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_310 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_311 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_312 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_313 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_314 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_315 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										mem_vec_316 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_317 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_318 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_319 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c22, cp_2 = c22_p_1, cp_1 = c22_p_0, cp_0 = 0;
											c < c22 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_292);
											mem_vec_292 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_293);
											mem_vec_293 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_294);
											mem_vec_294 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_295);
											mem_vec_295 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_296);
											mem_vec_296 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_297);
											mem_vec_297 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_298);
											mem_vec_298 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_299);
											mem_vec_299 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_300);
											mem_vec_300 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_301);
											mem_vec_301 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_302);
											mem_vec_302 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_303);
											mem_vec_303 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_304);
											mem_vec_304 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_305);
											mem_vec_305 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_306);
											mem_vec_306 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_307);
											mem_vec_307 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_308);
											mem_vec_308 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_309);
											mem_vec_309 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_310);
											mem_vec_310 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_311);
											mem_vec_311 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_312);
											mem_vec_312 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_313);
											mem_vec_313 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_314);
											mem_vec_314 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_315);
											mem_vec_315 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_316);
											mem_vec_316 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_317);
											mem_vec_317 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_318);
											mem_vec_318 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_319);
											mem_vec_319 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_40 = _mm256_set1_ps(scal_7);
											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_292);
											mem_vec_292 = vec_39;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_293);
											mem_vec_293 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_294);
											mem_vec_294 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_295);
											mem_vec_295 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_296);
											mem_vec_296 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_297);
											mem_vec_297 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_298);
											mem_vec_298 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_299);
											mem_vec_299 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_300);
											mem_vec_300 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_301);
											mem_vec_301 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_302);
											mem_vec_302 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_303);
											mem_vec_303 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_304);
											mem_vec_304 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_305);
											mem_vec_305 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_306);
											mem_vec_306 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_307);
											mem_vec_307 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_308);
											mem_vec_308 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_309);
											mem_vec_309 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_310);
											mem_vec_310 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_311);
											mem_vec_311 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_69 = _mm256_set1_ps(scal_12);


											vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_312);
											mem_vec_312 = vec_68;



											vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_313);
											mem_vec_313 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_314);
											mem_vec_314 = vec_71;



											vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_315);
											mem_vec_315 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_13);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_316);
											mem_vec_316 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_317);
											mem_vec_317 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_318);
											mem_vec_318 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_319);
											mem_vec_319 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_14);
											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_292);
											mem_vec_292 = vec_78;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_293);
											mem_vec_293 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_294);
											mem_vec_294 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_295);
											mem_vec_295 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_296);
											mem_vec_296 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_297);
											mem_vec_297 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_298);
											mem_vec_298 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_299);
											mem_vec_299 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_300);
											mem_vec_300 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_301);
											mem_vec_301 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_302);
											mem_vec_302 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_303);
											mem_vec_303 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_304);
											mem_vec_304 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_305);
											mem_vec_305 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_306);
											mem_vec_306 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_307);
											mem_vec_307 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_18);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_308);
											mem_vec_308 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_309);
											mem_vec_309 = vec_104;



											vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_310);
											mem_vec_310 = vec_105;



											vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_311);
											mem_vec_311 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_108 = _mm256_set1_ps(scal_19);


											vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_312);
											mem_vec_312 = vec_107;



											vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_313);
											mem_vec_313 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_314);
											mem_vec_314 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_315);
											mem_vec_315 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_113 = _mm256_set1_ps(scal_20);


											vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_316);
											mem_vec_316 = vec_112;



											vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_317);
											mem_vec_317 = vec_114;



											vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_318);
											mem_vec_318 = vec_115;



											vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_319);
											mem_vec_319 = vec_116;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_292);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_293);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_294);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_295);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_296);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_297);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_298);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_299);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_300);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_301);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_302);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_303);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_304);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_305);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_306);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_307);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_308);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_309);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_310);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_311);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_312);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_313);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_314);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_315);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_316);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_317);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_318);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_319);
							}
						}
					}
				}
		}
	}
}


}