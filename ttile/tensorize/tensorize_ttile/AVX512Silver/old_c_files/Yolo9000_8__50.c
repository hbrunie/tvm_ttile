#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); U (3, w); T (64, c); Hoist_vars [c];
  T (68, x); T (2, c); T (4, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 4), (Arg 15))]; T (1, x);
  T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c411_p_0, cp_1, c411, f, fp_0, f548_p_0, f549_p_0, fp_1, f548_p_1, fp_2, f548, f549, x, xp_0, x411_p_0, xp_1, x411, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y274 = 0;
IND_TYPE x412 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c412 = 0;
IND_TYPE f550 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_100 ,scal_101 ,scal_102 ,scal_103 ,scal_104 ,scal_105 ,scal_106 ,scal_107 ,scal_108 ,scal_109 ,scal_11 ,scal_110 ,scal_111 ,scal_112 ,scal_113 ,scal_114 ,scal_115 ,scal_116 ,scal_117 ,scal_118 ,scal_119 ,scal_12 ,scal_120 ,scal_121 ,scal_122 ,scal_123 ,scal_124 ,scal_125 ,scal_126 ,scal_127 ,scal_128 ,scal_129 ,scal_13 ,scal_130 ,scal_131 ,scal_132 ,scal_133 ,scal_134 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_45 ,scal_46 ,scal_47 ,scal_48 ,scal_49 ,scal_5 ,scal_50 ,scal_51 ,scal_52 ,scal_53 ,scal_54 ,scal_55 ,scal_56 ,scal_57 ,scal_58 ,scal_59 ,scal_6 ,scal_60 ,scal_61 ,scal_62 ,scal_63 ,scal_64 ,scal_65 ,scal_66 ,scal_67 ,scal_68 ,scal_69 ,scal_7 ,scal_70 ,scal_71 ,scal_72 ,scal_73 ,scal_74 ,scal_75 ,scal_76 ,scal_77 ,scal_78 ,scal_79 ,scal_8 ,scal_80 ,scal_81 ,scal_82 ,scal_83 ,scal_84 ,scal_85 ,scal_86 ,scal_87 ,scal_88 ,scal_89 ,scal_9 ,scal_90 ,scal_91 ,scal_92 ,scal_93 ,scal_94 ,scal_95 ,scal_96 ,scal_97 ,scal_98 ,scal_99;
__m512 mem_vec_5612 ,mem_vec_5613 ,mem_vec_5614 ,mem_vec_5615 ,mem_vec_5616 ,mem_vec_5617 ,mem_vec_5618 ,mem_vec_5619 ,mem_vec_5620 ,mem_vec_5621 ,mem_vec_5622 ,mem_vec_5623 ,mem_vec_5624 ,mem_vec_5625 ,mem_vec_5626 ,mem_vec_5627 ,mem_vec_5628 ,mem_vec_5629 ,mem_vec_5630 ,mem_vec_5631 ,mem_vec_5632 ,mem_vec_5633 ,mem_vec_5634 ,mem_vec_5635 ,mem_vec_5636 ,mem_vec_5637 ,mem_vec_5638 ,mem_vec_5639 ,mem_vec_5640 ,mem_vec_5641 ,mem_vec_5642 ,mem_vec_5643 ,mem_vec_5644 ,mem_vec_5645 ,mem_vec_5646 ,mem_vec_5647 ,mem_vec_5648 ,mem_vec_5649 ,mem_vec_5650 ,mem_vec_5651 ,mem_vec_5652 ,mem_vec_5653 ,mem_vec_5654 ,mem_vec_5655 ,mem_vec_5656 ,mem_vec_5657 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_132 ,vec_133 ,vec_134 ,vec_135 ,vec_136 ,vec_137 ,vec_138 ,vec_139 ,vec_14 ,vec_140 ,vec_141 ,vec_142 ,vec_143 ,vec_144 ,vec_145 ,vec_146 ,vec_147 ,vec_148 ,vec_149 ,vec_15 ,vec_150 ,vec_151 ,vec_152 ,vec_153 ,vec_154 ,vec_155 ,vec_156 ,vec_157 ,vec_158 ,vec_159 ,vec_16 ,vec_160 ,vec_161 ,vec_162 ,vec_163 ,vec_164 ,vec_165 ,vec_166 ,vec_167 ,vec_168 ,vec_169 ,vec_17 ,vec_170 ,vec_171 ,vec_172 ,vec_173 ,vec_174 ,vec_175 ,vec_176 ,vec_177 ,vec_178 ,vec_179 ,vec_18 ,vec_180 ,vec_181 ,vec_182 ,vec_183 ,vec_184 ,vec_185 ,vec_186 ,vec_187 ,vec_188 ,vec_189 ,vec_19 ,vec_190 ,vec_191 ,vec_192 ,vec_193 ,vec_194 ,vec_195 ,vec_196 ,vec_197 ,vec_198 ,vec_199 ,vec_2 ,vec_20 ,vec_200 ,vec_201 ,vec_202 ,vec_203 ,vec_204 ,vec_205 ,vec_206 ,vec_207 ,vec_208 ,vec_209 ,vec_21 ,vec_210 ,vec_211 ,vec_212 ,vec_213 ,vec_214 ,vec_215 ,vec_216 ,vec_217 ,vec_218 ,vec_219 ,vec_22 ,vec_220 ,vec_221 ,vec_222 ,vec_223 ,vec_224 ,vec_225 ,vec_226 ,vec_227 ,vec_228 ,vec_229 ,vec_23 ,vec_230 ,vec_231 ,vec_232 ,vec_233 ,vec_234 ,vec_235 ,vec_236 ,vec_237 ,vec_238 ,vec_239 ,vec_24 ,vec_240 ,vec_241 ,vec_242 ,vec_243 ,vec_244 ,vec_245 ,vec_246 ,vec_247 ,vec_248 ,vec_249 ,vec_25 ,vec_250 ,vec_251 ,vec_252 ,vec_253 ,vec_254 ,vec_255 ,vec_256 ,vec_257 ,vec_258 ,vec_259 ,vec_26 ,vec_260 ,vec_261 ,vec_262 ,vec_263 ,vec_264 ,vec_265 ,vec_266 ,vec_267 ,vec_268 ,vec_269 ,vec_27 ,vec_270 ,vec_271 ,vec_272 ,vec_273 ,vec_274 ,vec_275 ,vec_276 ,vec_277 ,vec_278 ,vec_279 ,vec_28 ,vec_280 ,vec_281 ,vec_282 ,vec_283 ,vec_284 ,vec_285 ,vec_286 ,vec_287 ,vec_288 ,vec_289 ,vec_29 ,vec_290 ,vec_291 ,vec_292 ,vec_293 ,vec_294 ,vec_295 ,vec_296 ,vec_297 ,vec_298 ,vec_299 ,vec_3 ,vec_30 ,vec_300 ,vec_301 ,vec_302 ,vec_303 ,vec_304 ,vec_305 ,vec_306 ,vec_307 ,vec_308 ,vec_309 ,vec_31 ,vec_310 ,vec_311 ,vec_312 ,vec_313 ,vec_314 ,vec_315 ,vec_316 ,vec_317 ,vec_318 ,vec_319 ,vec_32 ,vec_320 ,vec_321 ,vec_322 ,vec_323 ,vec_324 ,vec_325 ,vec_326 ,vec_327 ,vec_328 ,vec_329 ,vec_33 ,vec_330 ,vec_331 ,vec_332 ,vec_333 ,vec_334 ,vec_335 ,vec_336 ,vec_337 ,vec_338 ,vec_339 ,vec_34 ,vec_340 ,vec_341 ,vec_342 ,vec_343 ,vec_344 ,vec_345 ,vec_346 ,vec_347 ,vec_348 ,vec_349 ,vec_35 ,vec_350 ,vec_351 ,vec_352 ,vec_353 ,vec_354 ,vec_355 ,vec_356 ,vec_357 ,vec_358 ,vec_359 ,vec_36 ,vec_360 ,vec_361 ,vec_362 ,vec_363 ,vec_364 ,vec_365 ,vec_366 ,vec_367 ,vec_368 ,vec_369 ,vec_37 ,vec_370 ,vec_371 ,vec_372 ,vec_373 ,vec_374 ,vec_375 ,vec_376 ,vec_377 ,vec_378 ,vec_379 ,vec_38 ,vec_380 ,vec_381 ,vec_382 ,vec_383 ,vec_384 ,vec_385 ,vec_386 ,vec_387 ,vec_388 ,vec_389 ,vec_39 ,vec_390 ,vec_391 ,vec_392 ,vec_393 ,vec_394 ,vec_395 ,vec_396 ,vec_397 ,vec_398 ,vec_399 ,vec_4 ,vec_40 ,vec_400 ,vec_401 ,vec_402 ,vec_403 ,vec_404 ,vec_405 ,vec_406 ,vec_407 ,vec_408 ,vec_409 ,vec_41 ,vec_410 ,vec_411 ,vec_412 ,vec_413 ,vec_414 ,vec_415 ,vec_416 ,vec_417 ,vec_418 ,vec_419 ,vec_42 ,vec_420 ,vec_421 ,vec_422 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f549 = f550, f549_p_0 = 0;
	f549 < f550 + 256;
	f549 += 256, f549_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (f, 2) (256 / 128)
	for (f548 = f549, f548_p_1 = f549_p_0, f548_p_0 = 0;
		f548 < f549 + 256;
		f548 += 128, f548_p_1 += 128, f548_p_0 += 128){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
		// T (x, 1) (68 / 68)
		for (x411 = x412, x411_p_0 = 0;
			x411 < x412 + 68;
			x411 += 68, x411_p_0 += 68){
				for (y = y274, yp_0 = 0;
					y < y274 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 128
					// T (f, 4) (128 / 32)
					for (f = f548, fp_2 = f548_p_1, fp_1 = f548_p_0, fp_0 = 0;
						f < f548 + 128;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 32
						// T (c, 2) (128 / 64)
						for (c411 = c412, c411_p_0 = 0;
							c411 < c412 + 128;
							c411 += 64, c411_p_0 += 64){
							// y = ph_y, x = 68, h = 3, w = 3, c = 64, f = 32
							// T (x, 68) (68 / 1)
							for (x = x411, xp_1 = x411_p_0, xp_0 = 0;
								x < x411 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5612 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5613 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_5625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_5626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_5627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c411, cp_1 = c411_p_0, cp_0 = 0;
											c < c411 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5612);
											mem_vec_5612 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5613);
											mem_vec_5613 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5614);
											mem_vec_5614 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5615);
											mem_vec_5615 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5616);
											mem_vec_5616 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5617);
											mem_vec_5617 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5618);
											mem_vec_5618 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5619);
											mem_vec_5619 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5620);
											mem_vec_5620 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5621);
											mem_vec_5621 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5622);
											mem_vec_5622 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5623);
											mem_vec_5623 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5624);
											mem_vec_5624 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5625);
											mem_vec_5625 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5626);
											mem_vec_5626 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5627);
											mem_vec_5627 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_5612);
											mem_vec_5612 = vec_26;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_5613);
											mem_vec_5613 = vec_29;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_5614);
											mem_vec_5614 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_5615);
											mem_vec_5615 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_5616);
											mem_vec_5616 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_5617);
											mem_vec_5617 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_5618);
											mem_vec_5618 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_5619);
											mem_vec_5619 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_5620);
											mem_vec_5620 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_5621);
											mem_vec_5621 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_5622);
											mem_vec_5622 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_5623);
											mem_vec_5623 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_5624);
											mem_vec_5624 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_5625);
											mem_vec_5625 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_5626);
											mem_vec_5626 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_5627);
											mem_vec_5627 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_53 = _mm512_set1_ps(scal_16);
											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_5612);
											mem_vec_5612 = vec_52;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_5613);
											mem_vec_5613 = vec_55;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_17);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_5614);
											mem_vec_5614 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_5615);
											mem_vec_5615 = vec_59;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_61 = _mm512_set1_ps(scal_18);


											vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_5616);
											mem_vec_5616 = vec_60;



											vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_5617);
											mem_vec_5617 = vec_62;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_5618);
											mem_vec_5618 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_5619);
											mem_vec_5619 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_5620);
											mem_vec_5620 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_5621);
											mem_vec_5621 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_5622);
											mem_vec_5622 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_5623);
											mem_vec_5623 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_5624);
											mem_vec_5624 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_5625);
											mem_vec_5625 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_5626);
											mem_vec_5626 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_5627);
											mem_vec_5627 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_79 = _mm512_set1_ps(scal_24);
											vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_5612);
											mem_vec_5612 = vec_78;

											vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_5613);
											mem_vec_5613 = vec_81;
											scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_84 = _mm512_set1_ps(scal_25);


											vec_83 = _mm512_fmadd_ps(vec_84, vec_80, mem_vec_5614);
											mem_vec_5614 = vec_83;



											vec_85 = _mm512_fmadd_ps(vec_84, vec_82, mem_vec_5615);
											mem_vec_5615 = vec_85;
											scal_26 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_87 = _mm512_set1_ps(scal_26);


											vec_86 = _mm512_fmadd_ps(vec_87, vec_80, mem_vec_5616);
											mem_vec_5616 = vec_86;



											vec_88 = _mm512_fmadd_ps(vec_87, vec_82, mem_vec_5617);
											mem_vec_5617 = vec_88;
											scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_90 = _mm512_set1_ps(scal_27);


											vec_89 = _mm512_fmadd_ps(vec_90, vec_80, mem_vec_5618);
											mem_vec_5618 = vec_89;



											vec_91 = _mm512_fmadd_ps(vec_90, vec_82, mem_vec_5619);
											mem_vec_5619 = vec_91;
											scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_93 = _mm512_set1_ps(scal_28);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_5620);
											mem_vec_5620 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_5621);
											mem_vec_5621 = vec_94;
											scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_96 = _mm512_set1_ps(scal_29);


											vec_95 = _mm512_fmadd_ps(vec_96, vec_80, mem_vec_5622);
											mem_vec_5622 = vec_95;



											vec_97 = _mm512_fmadd_ps(vec_96, vec_82, mem_vec_5623);
											mem_vec_5623 = vec_97;
											scal_30 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_99 = _mm512_set1_ps(scal_30);


											vec_98 = _mm512_fmadd_ps(vec_99, vec_80, mem_vec_5624);
											mem_vec_5624 = vec_98;



											vec_100 = _mm512_fmadd_ps(vec_99, vec_82, mem_vec_5625);
											mem_vec_5625 = vec_100;
											scal_31 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
											vec_102 = _mm512_set1_ps(scal_31);


											vec_101 = _mm512_fmadd_ps(vec_102, vec_80, mem_vec_5626);
											mem_vec_5626 = vec_101;



											vec_103 = _mm512_fmadd_ps(vec_102, vec_82, mem_vec_5627);
											mem_vec_5627 = vec_103;
											scal_32 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_105 = _mm512_set1_ps(scal_32);
											vec_106 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_104 = _mm512_fmadd_ps(vec_105, vec_106, mem_vec_5612);
											mem_vec_5612 = vec_104;

											vec_108 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_107 = _mm512_fmadd_ps(vec_105, vec_108, mem_vec_5613);
											mem_vec_5613 = vec_107;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_110 = _mm512_set1_ps(scal_33);


											vec_109 = _mm512_fmadd_ps(vec_110, vec_106, mem_vec_5614);
											mem_vec_5614 = vec_109;



											vec_111 = _mm512_fmadd_ps(vec_110, vec_108, mem_vec_5615);
											mem_vec_5615 = vec_111;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_113 = _mm512_set1_ps(scal_34);


											vec_112 = _mm512_fmadd_ps(vec_113, vec_106, mem_vec_5616);
											mem_vec_5616 = vec_112;



											vec_114 = _mm512_fmadd_ps(vec_113, vec_108, mem_vec_5617);
											mem_vec_5617 = vec_114;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_116 = _mm512_set1_ps(scal_35);


											vec_115 = _mm512_fmadd_ps(vec_116, vec_106, mem_vec_5618);
											mem_vec_5618 = vec_115;



											vec_117 = _mm512_fmadd_ps(vec_116, vec_108, mem_vec_5619);
											mem_vec_5619 = vec_117;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_119 = _mm512_set1_ps(scal_36);


											vec_118 = _mm512_fmadd_ps(vec_119, vec_106, mem_vec_5620);
											mem_vec_5620 = vec_118;



											vec_120 = _mm512_fmadd_ps(vec_119, vec_108, mem_vec_5621);
											mem_vec_5621 = vec_120;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
											vec_122 = _mm512_set1_ps(scal_37);


											vec_121 = _mm512_fmadd_ps(vec_122, vec_106, mem_vec_5622);
											mem_vec_5622 = vec_121;



											vec_123 = _mm512_fmadd_ps(vec_122, vec_108, mem_vec_5623);
											mem_vec_5623 = vec_123;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
											vec_125 = _mm512_set1_ps(scal_38);


											vec_124 = _mm512_fmadd_ps(vec_125, vec_106, mem_vec_5624);
											mem_vec_5624 = vec_124;



											vec_126 = _mm512_fmadd_ps(vec_125, vec_108, mem_vec_5625);
											mem_vec_5625 = vec_126;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 1) + c];
											vec_128 = _mm512_set1_ps(scal_39);


											vec_127 = _mm512_fmadd_ps(vec_128, vec_106, mem_vec_5626);
											mem_vec_5626 = vec_127;



											vec_129 = _mm512_fmadd_ps(vec_128, vec_108, mem_vec_5627);
											mem_vec_5627 = vec_129;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_131 = _mm512_set1_ps(scal_40);
											vec_132 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_130 = _mm512_fmadd_ps(vec_131, vec_132, mem_vec_5612);
											mem_vec_5612 = vec_130;

											vec_134 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_133 = _mm512_fmadd_ps(vec_131, vec_134, mem_vec_5613);
											mem_vec_5613 = vec_133;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_136 = _mm512_set1_ps(scal_41);


											vec_135 = _mm512_fmadd_ps(vec_136, vec_132, mem_vec_5614);
											mem_vec_5614 = vec_135;



											vec_137 = _mm512_fmadd_ps(vec_136, vec_134, mem_vec_5615);
											mem_vec_5615 = vec_137;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_139 = _mm512_set1_ps(scal_42);


											vec_138 = _mm512_fmadd_ps(vec_139, vec_132, mem_vec_5616);
											mem_vec_5616 = vec_138;



											vec_140 = _mm512_fmadd_ps(vec_139, vec_134, mem_vec_5617);
											mem_vec_5617 = vec_140;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_142 = _mm512_set1_ps(scal_43);


											vec_141 = _mm512_fmadd_ps(vec_142, vec_132, mem_vec_5618);
											mem_vec_5618 = vec_141;



											vec_143 = _mm512_fmadd_ps(vec_142, vec_134, mem_vec_5619);
											mem_vec_5619 = vec_143;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_145 = _mm512_set1_ps(scal_44);


											vec_144 = _mm512_fmadd_ps(vec_145, vec_132, mem_vec_5620);
											mem_vec_5620 = vec_144;



											vec_146 = _mm512_fmadd_ps(vec_145, vec_134, mem_vec_5621);
											mem_vec_5621 = vec_146;
											scal_45 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
											vec_148 = _mm512_set1_ps(scal_45);


											vec_147 = _mm512_fmadd_ps(vec_148, vec_132, mem_vec_5622);
											mem_vec_5622 = vec_147;



											vec_149 = _mm512_fmadd_ps(vec_148, vec_134, mem_vec_5623);
											mem_vec_5623 = vec_149;
											scal_46 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
											vec_151 = _mm512_set1_ps(scal_46);


											vec_150 = _mm512_fmadd_ps(vec_151, vec_132, mem_vec_5624);
											mem_vec_5624 = vec_150;



											vec_152 = _mm512_fmadd_ps(vec_151, vec_134, mem_vec_5625);
											mem_vec_5625 = vec_152;
											scal_47 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 2) + c];
											vec_154 = _mm512_set1_ps(scal_47);


											vec_153 = _mm512_fmadd_ps(vec_154, vec_132, mem_vec_5626);
											mem_vec_5626 = vec_153;



											vec_155 = _mm512_fmadd_ps(vec_154, vec_134, mem_vec_5627);
											mem_vec_5627 = vec_155;
											scal_48 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_157 = _mm512_set1_ps(scal_48);
											vec_158 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_156 = _mm512_fmadd_ps(vec_157, vec_158, mem_vec_5612);
											mem_vec_5612 = vec_156;

											vec_160 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_159 = _mm512_fmadd_ps(vec_157, vec_160, mem_vec_5613);
											mem_vec_5613 = vec_159;
											scal_49 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_162 = _mm512_set1_ps(scal_49);


											vec_161 = _mm512_fmadd_ps(vec_162, vec_158, mem_vec_5614);
											mem_vec_5614 = vec_161;



											vec_163 = _mm512_fmadd_ps(vec_162, vec_160, mem_vec_5615);
											mem_vec_5615 = vec_163;
											scal_50 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_165 = _mm512_set1_ps(scal_50);


											vec_164 = _mm512_fmadd_ps(vec_165, vec_158, mem_vec_5616);
											mem_vec_5616 = vec_164;



											vec_166 = _mm512_fmadd_ps(vec_165, vec_160, mem_vec_5617);
											mem_vec_5617 = vec_166;
											scal_51 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_168 = _mm512_set1_ps(scal_51);


											vec_167 = _mm512_fmadd_ps(vec_168, vec_158, mem_vec_5618);
											mem_vec_5618 = vec_167;



											vec_169 = _mm512_fmadd_ps(vec_168, vec_160, mem_vec_5619);
											mem_vec_5619 = vec_169;
											scal_52 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_171 = _mm512_set1_ps(scal_52);


											vec_170 = _mm512_fmadd_ps(vec_171, vec_158, mem_vec_5620);
											mem_vec_5620 = vec_170;



											vec_172 = _mm512_fmadd_ps(vec_171, vec_160, mem_vec_5621);
											mem_vec_5621 = vec_172;
											scal_53 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_174 = _mm512_set1_ps(scal_53);


											vec_173 = _mm512_fmadd_ps(vec_174, vec_158, mem_vec_5622);
											mem_vec_5622 = vec_173;



											vec_175 = _mm512_fmadd_ps(vec_174, vec_160, mem_vec_5623);
											mem_vec_5623 = vec_175;
											scal_54 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_177 = _mm512_set1_ps(scal_54);


											vec_176 = _mm512_fmadd_ps(vec_177, vec_158, mem_vec_5624);
											mem_vec_5624 = vec_176;



											vec_178 = _mm512_fmadd_ps(vec_177, vec_160, mem_vec_5625);
											mem_vec_5625 = vec_178;
											scal_55 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
											vec_180 = _mm512_set1_ps(scal_55);


											vec_179 = _mm512_fmadd_ps(vec_180, vec_158, mem_vec_5626);
											mem_vec_5626 = vec_179;



											vec_181 = _mm512_fmadd_ps(vec_180, vec_160, mem_vec_5627);
											mem_vec_5627 = vec_181;
											scal_56 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_183 = _mm512_set1_ps(scal_56);
											vec_184 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_182 = _mm512_fmadd_ps(vec_183, vec_184, mem_vec_5612);
											mem_vec_5612 = vec_182;

											vec_186 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_185 = _mm512_fmadd_ps(vec_183, vec_186, mem_vec_5613);
											mem_vec_5613 = vec_185;
											scal_57 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_188 = _mm512_set1_ps(scal_57);


											vec_187 = _mm512_fmadd_ps(vec_188, vec_184, mem_vec_5614);
											mem_vec_5614 = vec_187;



											vec_189 = _mm512_fmadd_ps(vec_188, vec_186, mem_vec_5615);
											mem_vec_5615 = vec_189;
											scal_58 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_191 = _mm512_set1_ps(scal_58);


											vec_190 = _mm512_fmadd_ps(vec_191, vec_184, mem_vec_5616);
											mem_vec_5616 = vec_190;



											vec_192 = _mm512_fmadd_ps(vec_191, vec_186, mem_vec_5617);
											mem_vec_5617 = vec_192;
											scal_59 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_194 = _mm512_set1_ps(scal_59);


											vec_193 = _mm512_fmadd_ps(vec_194, vec_184, mem_vec_5618);
											mem_vec_5618 = vec_193;



											vec_195 = _mm512_fmadd_ps(vec_194, vec_186, mem_vec_5619);
											mem_vec_5619 = vec_195;
											scal_60 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_197 = _mm512_set1_ps(scal_60);


											vec_196 = _mm512_fmadd_ps(vec_197, vec_184, mem_vec_5620);
											mem_vec_5620 = vec_196;



											vec_198 = _mm512_fmadd_ps(vec_197, vec_186, mem_vec_5621);
											mem_vec_5621 = vec_198;
											scal_61 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
											vec_200 = _mm512_set1_ps(scal_61);


											vec_199 = _mm512_fmadd_ps(vec_200, vec_184, mem_vec_5622);
											mem_vec_5622 = vec_199;



											vec_201 = _mm512_fmadd_ps(vec_200, vec_186, mem_vec_5623);
											mem_vec_5623 = vec_201;
											scal_62 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
											vec_203 = _mm512_set1_ps(scal_62);


											vec_202 = _mm512_fmadd_ps(vec_203, vec_184, mem_vec_5624);
											mem_vec_5624 = vec_202;



											vec_204 = _mm512_fmadd_ps(vec_203, vec_186, mem_vec_5625);
											mem_vec_5625 = vec_204;
											scal_63 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 1) + c];
											vec_206 = _mm512_set1_ps(scal_63);


											vec_205 = _mm512_fmadd_ps(vec_206, vec_184, mem_vec_5626);
											mem_vec_5626 = vec_205;



											vec_207 = _mm512_fmadd_ps(vec_206, vec_186, mem_vec_5627);
											mem_vec_5627 = vec_207;
											scal_64 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_209 = _mm512_set1_ps(scal_64);
											vec_210 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_208 = _mm512_fmadd_ps(vec_209, vec_210, mem_vec_5612);
											mem_vec_5612 = vec_208;

											vec_212 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_211 = _mm512_fmadd_ps(vec_209, vec_212, mem_vec_5613);
											mem_vec_5613 = vec_211;
											scal_65 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_214 = _mm512_set1_ps(scal_65);


											vec_213 = _mm512_fmadd_ps(vec_214, vec_210, mem_vec_5614);
											mem_vec_5614 = vec_213;



											vec_215 = _mm512_fmadd_ps(vec_214, vec_212, mem_vec_5615);
											mem_vec_5615 = vec_215;
											scal_66 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_217 = _mm512_set1_ps(scal_66);


											vec_216 = _mm512_fmadd_ps(vec_217, vec_210, mem_vec_5616);
											mem_vec_5616 = vec_216;



											vec_218 = _mm512_fmadd_ps(vec_217, vec_212, mem_vec_5617);
											mem_vec_5617 = vec_218;
											scal_67 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_220 = _mm512_set1_ps(scal_67);


											vec_219 = _mm512_fmadd_ps(vec_220, vec_210, mem_vec_5618);
											mem_vec_5618 = vec_219;



											vec_221 = _mm512_fmadd_ps(vec_220, vec_212, mem_vec_5619);
											mem_vec_5619 = vec_221;
											scal_68 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_223 = _mm512_set1_ps(scal_68);


											vec_222 = _mm512_fmadd_ps(vec_223, vec_210, mem_vec_5620);
											mem_vec_5620 = vec_222;



											vec_224 = _mm512_fmadd_ps(vec_223, vec_212, mem_vec_5621);
											mem_vec_5621 = vec_224;
											scal_69 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
											vec_226 = _mm512_set1_ps(scal_69);


											vec_225 = _mm512_fmadd_ps(vec_226, vec_210, mem_vec_5622);
											mem_vec_5622 = vec_225;



											vec_227 = _mm512_fmadd_ps(vec_226, vec_212, mem_vec_5623);
											mem_vec_5623 = vec_227;
											scal_70 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
											vec_229 = _mm512_set1_ps(scal_70);


											vec_228 = _mm512_fmadd_ps(vec_229, vec_210, mem_vec_5624);
											mem_vec_5624 = vec_228;



											vec_230 = _mm512_fmadd_ps(vec_229, vec_212, mem_vec_5625);
											mem_vec_5625 = vec_230;
											scal_71 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 2) + c];
											vec_232 = _mm512_set1_ps(scal_71);


											vec_231 = _mm512_fmadd_ps(vec_232, vec_210, mem_vec_5626);
											mem_vec_5626 = vec_231;



											vec_233 = _mm512_fmadd_ps(vec_232, vec_212, mem_vec_5627);
											mem_vec_5627 = vec_233;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5612);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5613);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5614);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5615);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5616);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5617);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5618);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5619);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5620);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5621);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5622);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5623);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5624);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5625);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5626);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5627);
							}
						}
					}
				}
				for (y = y274 + 8, yp_0 = 0;
					y < y274 + 8 + 60;
					y += 15, yp_0 += 15){
					// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 128
					// T (f, 4) (128 / 32)
					for (f = f548, fp_2 = f548_p_1, fp_1 = f548_p_0, fp_0 = 0;
						f < f548 + 128;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 32
						// T (c, 2) (128 / 64)
						for (c411 = c412, c411_p_0 = 0;
							c411 < c412 + 128;
							c411 += 64, c411_p_0 += 64){
							// y = ph_y, x = 68, h = 3, w = 3, c = 64, f = 32
							// T (x, 68) (68 / 1)
							for (x = x411, xp_1 = x411_p_0, xp_0 = 0;
								x < x411 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5628 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5629 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_5641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_5642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_5643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_5644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_5645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_5646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_5647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_5648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_5649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_5650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_5651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_5652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_5653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_5654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_5655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										mem_vec_5656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
										mem_vec_5657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c411, cp_1 = c411_p_0, cp_0 = 0;
											c < c411 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5628);
											mem_vec_5628 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5629);
											mem_vec_5629 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5630);
											mem_vec_5630 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5631);
											mem_vec_5631 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5632);
											mem_vec_5632 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5633);
											mem_vec_5633 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5634);
											mem_vec_5634 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5635);
											mem_vec_5635 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5636);
											mem_vec_5636 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5637);
											mem_vec_5637 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5638);
											mem_vec_5638 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5639);
											mem_vec_5639 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5640);
											mem_vec_5640 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5641);
											mem_vec_5641 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5642);
											mem_vec_5642 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5643);
											mem_vec_5643 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5644);
											mem_vec_5644 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5645);
											mem_vec_5645 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5646);
											mem_vec_5646 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5647);
											mem_vec_5647 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5648);
											mem_vec_5648 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5649);
											mem_vec_5649 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_5650);
											mem_vec_5650 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_5651);
											mem_vec_5651 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_5652);
											mem_vec_5652 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_5653);
											mem_vec_5653 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_5654);
											mem_vec_5654 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_5655);
											mem_vec_5655 = vec_43;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
											vec_45 = _mm512_set1_ps(scal_14);


											vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_5656);
											mem_vec_5656 = vec_44;



											vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_5657);
											mem_vec_5657 = vec_46;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_48 = _mm512_set1_ps(scal_15);
											vec_49 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_47 = _mm512_fmadd_ps(vec_48, vec_49, mem_vec_5628);
											mem_vec_5628 = vec_47;

											vec_51 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_50 = _mm512_fmadd_ps(vec_48, vec_51, mem_vec_5629);
											mem_vec_5629 = vec_50;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_49, mem_vec_5630);
											mem_vec_5630 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_51, mem_vec_5631);
											mem_vec_5631 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_49, mem_vec_5632);
											mem_vec_5632 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_51, mem_vec_5633);
											mem_vec_5633 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_49, mem_vec_5634);
											mem_vec_5634 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_51, mem_vec_5635);
											mem_vec_5635 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_49, mem_vec_5636);
											mem_vec_5636 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_51, mem_vec_5637);
											mem_vec_5637 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_49, mem_vec_5638);
											mem_vec_5638 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_51, mem_vec_5639);
											mem_vec_5639 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_49, mem_vec_5640);
											mem_vec_5640 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_51, mem_vec_5641);
											mem_vec_5641 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_71 = _mm512_set1_ps(scal_22);


											vec_70 = _mm512_fmadd_ps(vec_71, vec_49, mem_vec_5642);
											mem_vec_5642 = vec_70;



											vec_72 = _mm512_fmadd_ps(vec_71, vec_51, mem_vec_5643);
											mem_vec_5643 = vec_72;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_74 = _mm512_set1_ps(scal_23);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_49, mem_vec_5644);
											mem_vec_5644 = vec_73;



											vec_75 = _mm512_fmadd_ps(vec_74, vec_51, mem_vec_5645);
											mem_vec_5645 = vec_75;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_77 = _mm512_set1_ps(scal_24);


											vec_76 = _mm512_fmadd_ps(vec_77, vec_49, mem_vec_5646);
											mem_vec_5646 = vec_76;



											vec_78 = _mm512_fmadd_ps(vec_77, vec_51, mem_vec_5647);
											mem_vec_5647 = vec_78;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_80 = _mm512_set1_ps(scal_25);


											vec_79 = _mm512_fmadd_ps(vec_80, vec_49, mem_vec_5648);
											mem_vec_5648 = vec_79;



											vec_81 = _mm512_fmadd_ps(vec_80, vec_51, mem_vec_5649);
											mem_vec_5649 = vec_81;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
											vec_83 = _mm512_set1_ps(scal_26);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_49, mem_vec_5650);
											mem_vec_5650 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_51, mem_vec_5651);
											mem_vec_5651 = vec_84;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
											vec_86 = _mm512_set1_ps(scal_27);


											vec_85 = _mm512_fmadd_ps(vec_86, vec_49, mem_vec_5652);
											mem_vec_5652 = vec_85;



											vec_87 = _mm512_fmadd_ps(vec_86, vec_51, mem_vec_5653);
											mem_vec_5653 = vec_87;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 1) + c];
											vec_89 = _mm512_set1_ps(scal_28);


											vec_88 = _mm512_fmadd_ps(vec_89, vec_49, mem_vec_5654);
											mem_vec_5654 = vec_88;



											vec_90 = _mm512_fmadd_ps(vec_89, vec_51, mem_vec_5655);
											mem_vec_5655 = vec_90;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h + 1) + c];
											vec_92 = _mm512_set1_ps(scal_29);


											vec_91 = _mm512_fmadd_ps(vec_92, vec_49, mem_vec_5656);
											mem_vec_5656 = vec_91;



											vec_93 = _mm512_fmadd_ps(vec_92, vec_51, mem_vec_5657);
											mem_vec_5657 = vec_93;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_95 = _mm512_set1_ps(scal_30);
											vec_96 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_94 = _mm512_fmadd_ps(vec_95, vec_96, mem_vec_5628);
											mem_vec_5628 = vec_94;

											vec_98 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_97 = _mm512_fmadd_ps(vec_95, vec_98, mem_vec_5629);
											mem_vec_5629 = vec_97;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_96, mem_vec_5630);
											mem_vec_5630 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_98, mem_vec_5631);
											mem_vec_5631 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_96, mem_vec_5632);
											mem_vec_5632 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_98, mem_vec_5633);
											mem_vec_5633 = vec_104;
											scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_106 = _mm512_set1_ps(scal_33);


											vec_105 = _mm512_fmadd_ps(vec_106, vec_96, mem_vec_5634);
											mem_vec_5634 = vec_105;



											vec_107 = _mm512_fmadd_ps(vec_106, vec_98, mem_vec_5635);
											mem_vec_5635 = vec_107;
											scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_109 = _mm512_set1_ps(scal_34);


											vec_108 = _mm512_fmadd_ps(vec_109, vec_96, mem_vec_5636);
											mem_vec_5636 = vec_108;



											vec_110 = _mm512_fmadd_ps(vec_109, vec_98, mem_vec_5637);
											mem_vec_5637 = vec_110;
											scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_112 = _mm512_set1_ps(scal_35);


											vec_111 = _mm512_fmadd_ps(vec_112, vec_96, mem_vec_5638);
											mem_vec_5638 = vec_111;



											vec_113 = _mm512_fmadd_ps(vec_112, vec_98, mem_vec_5639);
											mem_vec_5639 = vec_113;
											scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_115 = _mm512_set1_ps(scal_36);


											vec_114 = _mm512_fmadd_ps(vec_115, vec_96, mem_vec_5640);
											mem_vec_5640 = vec_114;



											vec_116 = _mm512_fmadd_ps(vec_115, vec_98, mem_vec_5641);
											mem_vec_5641 = vec_116;
											scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_118 = _mm512_set1_ps(scal_37);


											vec_117 = _mm512_fmadd_ps(vec_118, vec_96, mem_vec_5642);
											mem_vec_5642 = vec_117;



											vec_119 = _mm512_fmadd_ps(vec_118, vec_98, mem_vec_5643);
											mem_vec_5643 = vec_119;
											scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_121 = _mm512_set1_ps(scal_38);


											vec_120 = _mm512_fmadd_ps(vec_121, vec_96, mem_vec_5644);
											mem_vec_5644 = vec_120;



											vec_122 = _mm512_fmadd_ps(vec_121, vec_98, mem_vec_5645);
											mem_vec_5645 = vec_122;
											scal_39 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_124 = _mm512_set1_ps(scal_39);


											vec_123 = _mm512_fmadd_ps(vec_124, vec_96, mem_vec_5646);
											mem_vec_5646 = vec_123;



											vec_125 = _mm512_fmadd_ps(vec_124, vec_98, mem_vec_5647);
											mem_vec_5647 = vec_125;
											scal_40 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_127 = _mm512_set1_ps(scal_40);


											vec_126 = _mm512_fmadd_ps(vec_127, vec_96, mem_vec_5648);
											mem_vec_5648 = vec_126;



											vec_128 = _mm512_fmadd_ps(vec_127, vec_98, mem_vec_5649);
											mem_vec_5649 = vec_128;
											scal_41 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
											vec_130 = _mm512_set1_ps(scal_41);


											vec_129 = _mm512_fmadd_ps(vec_130, vec_96, mem_vec_5650);
											mem_vec_5650 = vec_129;



											vec_131 = _mm512_fmadd_ps(vec_130, vec_98, mem_vec_5651);
											mem_vec_5651 = vec_131;
											scal_42 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
											vec_133 = _mm512_set1_ps(scal_42);


											vec_132 = _mm512_fmadd_ps(vec_133, vec_96, mem_vec_5652);
											mem_vec_5652 = vec_132;



											vec_134 = _mm512_fmadd_ps(vec_133, vec_98, mem_vec_5653);
											mem_vec_5653 = vec_134;
											scal_43 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 2) + c];
											vec_136 = _mm512_set1_ps(scal_43);


											vec_135 = _mm512_fmadd_ps(vec_136, vec_96, mem_vec_5654);
											mem_vec_5654 = vec_135;



											vec_137 = _mm512_fmadd_ps(vec_136, vec_98, mem_vec_5655);
											mem_vec_5655 = vec_137;
											scal_44 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h + 2) + c];
											vec_139 = _mm512_set1_ps(scal_44);


											vec_138 = _mm512_fmadd_ps(vec_139, vec_96, mem_vec_5656);
											mem_vec_5656 = vec_138;



											vec_140 = _mm512_fmadd_ps(vec_139, vec_98, mem_vec_5657);
											mem_vec_5657 = vec_140;
											scal_45 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_142 = _mm512_set1_ps(scal_45);
											vec_143 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_141 = _mm512_fmadd_ps(vec_142, vec_143, mem_vec_5628);
											mem_vec_5628 = vec_141;

											vec_145 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_144 = _mm512_fmadd_ps(vec_142, vec_145, mem_vec_5629);
											mem_vec_5629 = vec_144;
											scal_46 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_147 = _mm512_set1_ps(scal_46);


											vec_146 = _mm512_fmadd_ps(vec_147, vec_143, mem_vec_5630);
											mem_vec_5630 = vec_146;



											vec_148 = _mm512_fmadd_ps(vec_147, vec_145, mem_vec_5631);
											mem_vec_5631 = vec_148;
											scal_47 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_150 = _mm512_set1_ps(scal_47);


											vec_149 = _mm512_fmadd_ps(vec_150, vec_143, mem_vec_5632);
											mem_vec_5632 = vec_149;



											vec_151 = _mm512_fmadd_ps(vec_150, vec_145, mem_vec_5633);
											mem_vec_5633 = vec_151;
											scal_48 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_153 = _mm512_set1_ps(scal_48);


											vec_152 = _mm512_fmadd_ps(vec_153, vec_143, mem_vec_5634);
											mem_vec_5634 = vec_152;



											vec_154 = _mm512_fmadd_ps(vec_153, vec_145, mem_vec_5635);
											mem_vec_5635 = vec_154;
											scal_49 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_156 = _mm512_set1_ps(scal_49);


											vec_155 = _mm512_fmadd_ps(vec_156, vec_143, mem_vec_5636);
											mem_vec_5636 = vec_155;



											vec_157 = _mm512_fmadd_ps(vec_156, vec_145, mem_vec_5637);
											mem_vec_5637 = vec_157;
											scal_50 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_159 = _mm512_set1_ps(scal_50);


											vec_158 = _mm512_fmadd_ps(vec_159, vec_143, mem_vec_5638);
											mem_vec_5638 = vec_158;



											vec_160 = _mm512_fmadd_ps(vec_159, vec_145, mem_vec_5639);
											mem_vec_5639 = vec_160;
											scal_51 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_162 = _mm512_set1_ps(scal_51);


											vec_161 = _mm512_fmadd_ps(vec_162, vec_143, mem_vec_5640);
											mem_vec_5640 = vec_161;



											vec_163 = _mm512_fmadd_ps(vec_162, vec_145, mem_vec_5641);
											mem_vec_5641 = vec_163;
											scal_52 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
											vec_165 = _mm512_set1_ps(scal_52);


											vec_164 = _mm512_fmadd_ps(vec_165, vec_143, mem_vec_5642);
											mem_vec_5642 = vec_164;



											vec_166 = _mm512_fmadd_ps(vec_165, vec_145, mem_vec_5643);
											mem_vec_5643 = vec_166;
											scal_53 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
											vec_168 = _mm512_set1_ps(scal_53);


											vec_167 = _mm512_fmadd_ps(vec_168, vec_143, mem_vec_5644);
											mem_vec_5644 = vec_167;



											vec_169 = _mm512_fmadd_ps(vec_168, vec_145, mem_vec_5645);
											mem_vec_5645 = vec_169;
											scal_54 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
											vec_171 = _mm512_set1_ps(scal_54);


											vec_170 = _mm512_fmadd_ps(vec_171, vec_143, mem_vec_5646);
											mem_vec_5646 = vec_170;



											vec_172 = _mm512_fmadd_ps(vec_171, vec_145, mem_vec_5647);
											mem_vec_5647 = vec_172;
											scal_55 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
											vec_174 = _mm512_set1_ps(scal_55);


											vec_173 = _mm512_fmadd_ps(vec_174, vec_143, mem_vec_5648);
											mem_vec_5648 = vec_173;



											vec_175 = _mm512_fmadd_ps(vec_174, vec_145, mem_vec_5649);
											mem_vec_5649 = vec_175;
											scal_56 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h) + c];
											vec_177 = _mm512_set1_ps(scal_56);


											vec_176 = _mm512_fmadd_ps(vec_177, vec_143, mem_vec_5650);
											mem_vec_5650 = vec_176;



											vec_178 = _mm512_fmadd_ps(vec_177, vec_145, mem_vec_5651);
											mem_vec_5651 = vec_178;
											scal_57 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 12 + h) + c];
											vec_180 = _mm512_set1_ps(scal_57);


											vec_179 = _mm512_fmadd_ps(vec_180, vec_143, mem_vec_5652);
											mem_vec_5652 = vec_179;



											vec_181 = _mm512_fmadd_ps(vec_180, vec_145, mem_vec_5653);
											mem_vec_5653 = vec_181;
											scal_58 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 13 + h) + c];
											vec_183 = _mm512_set1_ps(scal_58);


											vec_182 = _mm512_fmadd_ps(vec_183, vec_143, mem_vec_5654);
											mem_vec_5654 = vec_182;



											vec_184 = _mm512_fmadd_ps(vec_183, vec_145, mem_vec_5655);
											mem_vec_5655 = vec_184;
											scal_59 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 14 + h) + c];
											vec_186 = _mm512_set1_ps(scal_59);


											vec_185 = _mm512_fmadd_ps(vec_186, vec_143, mem_vec_5656);
											mem_vec_5656 = vec_185;



											vec_187 = _mm512_fmadd_ps(vec_186, vec_145, mem_vec_5657);
											mem_vec_5657 = vec_187;
											scal_60 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_189 = _mm512_set1_ps(scal_60);
											vec_190 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_188 = _mm512_fmadd_ps(vec_189, vec_190, mem_vec_5628);
											mem_vec_5628 = vec_188;

											vec_192 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_191 = _mm512_fmadd_ps(vec_189, vec_192, mem_vec_5629);
											mem_vec_5629 = vec_191;
											scal_61 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_194 = _mm512_set1_ps(scal_61);


											vec_193 = _mm512_fmadd_ps(vec_194, vec_190, mem_vec_5630);
											mem_vec_5630 = vec_193;



											vec_195 = _mm512_fmadd_ps(vec_194, vec_192, mem_vec_5631);
											mem_vec_5631 = vec_195;
											scal_62 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_197 = _mm512_set1_ps(scal_62);


											vec_196 = _mm512_fmadd_ps(vec_197, vec_190, mem_vec_5632);
											mem_vec_5632 = vec_196;



											vec_198 = _mm512_fmadd_ps(vec_197, vec_192, mem_vec_5633);
											mem_vec_5633 = vec_198;
											scal_63 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_200 = _mm512_set1_ps(scal_63);


											vec_199 = _mm512_fmadd_ps(vec_200, vec_190, mem_vec_5634);
											mem_vec_5634 = vec_199;



											vec_201 = _mm512_fmadd_ps(vec_200, vec_192, mem_vec_5635);
											mem_vec_5635 = vec_201;
											scal_64 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_203 = _mm512_set1_ps(scal_64);


											vec_202 = _mm512_fmadd_ps(vec_203, vec_190, mem_vec_5636);
											mem_vec_5636 = vec_202;



											vec_204 = _mm512_fmadd_ps(vec_203, vec_192, mem_vec_5637);
											mem_vec_5637 = vec_204;
											scal_65 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
											vec_206 = _mm512_set1_ps(scal_65);


											vec_205 = _mm512_fmadd_ps(vec_206, vec_190, mem_vec_5638);
											mem_vec_5638 = vec_205;



											vec_207 = _mm512_fmadd_ps(vec_206, vec_192, mem_vec_5639);
											mem_vec_5639 = vec_207;
											scal_66 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
											vec_209 = _mm512_set1_ps(scal_66);


											vec_208 = _mm512_fmadd_ps(vec_209, vec_190, mem_vec_5640);
											mem_vec_5640 = vec_208;



											vec_210 = _mm512_fmadd_ps(vec_209, vec_192, mem_vec_5641);
											mem_vec_5641 = vec_210;
											scal_67 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 1) + c];
											vec_212 = _mm512_set1_ps(scal_67);


											vec_211 = _mm512_fmadd_ps(vec_212, vec_190, mem_vec_5642);
											mem_vec_5642 = vec_211;



											vec_213 = _mm512_fmadd_ps(vec_212, vec_192, mem_vec_5643);
											mem_vec_5643 = vec_213;
											scal_68 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 1) + c];
											vec_215 = _mm512_set1_ps(scal_68);


											vec_214 = _mm512_fmadd_ps(vec_215, vec_190, mem_vec_5644);
											mem_vec_5644 = vec_214;



											vec_216 = _mm512_fmadd_ps(vec_215, vec_192, mem_vec_5645);
											mem_vec_5645 = vec_216;
											scal_69 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 1) + c];
											vec_218 = _mm512_set1_ps(scal_69);


											vec_217 = _mm512_fmadd_ps(vec_218, vec_190, mem_vec_5646);
											mem_vec_5646 = vec_217;



											vec_219 = _mm512_fmadd_ps(vec_218, vec_192, mem_vec_5647);
											mem_vec_5647 = vec_219;
											scal_70 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 1) + c];
											vec_221 = _mm512_set1_ps(scal_70);


											vec_220 = _mm512_fmadd_ps(vec_221, vec_190, mem_vec_5648);
											mem_vec_5648 = vec_220;



											vec_222 = _mm512_fmadd_ps(vec_221, vec_192, mem_vec_5649);
											mem_vec_5649 = vec_222;
											scal_71 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h + 1) + c];
											vec_224 = _mm512_set1_ps(scal_71);


											vec_223 = _mm512_fmadd_ps(vec_224, vec_190, mem_vec_5650);
											mem_vec_5650 = vec_223;



											vec_225 = _mm512_fmadd_ps(vec_224, vec_192, mem_vec_5651);
											mem_vec_5651 = vec_225;
											scal_72 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 12 + h + 1) + c];
											vec_227 = _mm512_set1_ps(scal_72);


											vec_226 = _mm512_fmadd_ps(vec_227, vec_190, mem_vec_5652);
											mem_vec_5652 = vec_226;



											vec_228 = _mm512_fmadd_ps(vec_227, vec_192, mem_vec_5653);
											mem_vec_5653 = vec_228;
											scal_73 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 13 + h + 1) + c];
											vec_230 = _mm512_set1_ps(scal_73);


											vec_229 = _mm512_fmadd_ps(vec_230, vec_190, mem_vec_5654);
											mem_vec_5654 = vec_229;



											vec_231 = _mm512_fmadd_ps(vec_230, vec_192, mem_vec_5655);
											mem_vec_5655 = vec_231;
											scal_74 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 14 + h + 1) + c];
											vec_233 = _mm512_set1_ps(scal_74);


											vec_232 = _mm512_fmadd_ps(vec_233, vec_190, mem_vec_5656);
											mem_vec_5656 = vec_232;



											vec_234 = _mm512_fmadd_ps(vec_233, vec_192, mem_vec_5657);
											mem_vec_5657 = vec_234;
											scal_75 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_236 = _mm512_set1_ps(scal_75);
											vec_237 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_235 = _mm512_fmadd_ps(vec_236, vec_237, mem_vec_5628);
											mem_vec_5628 = vec_235;

											vec_239 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_238 = _mm512_fmadd_ps(vec_236, vec_239, mem_vec_5629);
											mem_vec_5629 = vec_238;
											scal_76 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_241 = _mm512_set1_ps(scal_76);


											vec_240 = _mm512_fmadd_ps(vec_241, vec_237, mem_vec_5630);
											mem_vec_5630 = vec_240;



											vec_242 = _mm512_fmadd_ps(vec_241, vec_239, mem_vec_5631);
											mem_vec_5631 = vec_242;
											scal_77 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_244 = _mm512_set1_ps(scal_77);


											vec_243 = _mm512_fmadd_ps(vec_244, vec_237, mem_vec_5632);
											mem_vec_5632 = vec_243;



											vec_245 = _mm512_fmadd_ps(vec_244, vec_239, mem_vec_5633);
											mem_vec_5633 = vec_245;
											scal_78 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_247 = _mm512_set1_ps(scal_78);


											vec_246 = _mm512_fmadd_ps(vec_247, vec_237, mem_vec_5634);
											mem_vec_5634 = vec_246;



											vec_248 = _mm512_fmadd_ps(vec_247, vec_239, mem_vec_5635);
											mem_vec_5635 = vec_248;
											scal_79 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_250 = _mm512_set1_ps(scal_79);


											vec_249 = _mm512_fmadd_ps(vec_250, vec_237, mem_vec_5636);
											mem_vec_5636 = vec_249;



											vec_251 = _mm512_fmadd_ps(vec_250, vec_239, mem_vec_5637);
											mem_vec_5637 = vec_251;
											scal_80 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
											vec_253 = _mm512_set1_ps(scal_80);


											vec_252 = _mm512_fmadd_ps(vec_253, vec_237, mem_vec_5638);
											mem_vec_5638 = vec_252;



											vec_254 = _mm512_fmadd_ps(vec_253, vec_239, mem_vec_5639);
											mem_vec_5639 = vec_254;
											scal_81 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
											vec_256 = _mm512_set1_ps(scal_81);


											vec_255 = _mm512_fmadd_ps(vec_256, vec_237, mem_vec_5640);
											mem_vec_5640 = vec_255;



											vec_257 = _mm512_fmadd_ps(vec_256, vec_239, mem_vec_5641);
											mem_vec_5641 = vec_257;
											scal_82 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 2) + c];
											vec_259 = _mm512_set1_ps(scal_82);


											vec_258 = _mm512_fmadd_ps(vec_259, vec_237, mem_vec_5642);
											mem_vec_5642 = vec_258;



											vec_260 = _mm512_fmadd_ps(vec_259, vec_239, mem_vec_5643);
											mem_vec_5643 = vec_260;
											scal_83 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 2) + c];
											vec_262 = _mm512_set1_ps(scal_83);


											vec_261 = _mm512_fmadd_ps(vec_262, vec_237, mem_vec_5644);
											mem_vec_5644 = vec_261;



											vec_263 = _mm512_fmadd_ps(vec_262, vec_239, mem_vec_5645);
											mem_vec_5645 = vec_263;
											scal_84 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 2) + c];
											vec_265 = _mm512_set1_ps(scal_84);


											vec_264 = _mm512_fmadd_ps(vec_265, vec_237, mem_vec_5646);
											mem_vec_5646 = vec_264;



											vec_266 = _mm512_fmadd_ps(vec_265, vec_239, mem_vec_5647);
											mem_vec_5647 = vec_266;
											scal_85 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 2) + c];
											vec_268 = _mm512_set1_ps(scal_85);


											vec_267 = _mm512_fmadd_ps(vec_268, vec_237, mem_vec_5648);
											mem_vec_5648 = vec_267;



											vec_269 = _mm512_fmadd_ps(vec_268, vec_239, mem_vec_5649);
											mem_vec_5649 = vec_269;
											scal_86 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h + 2) + c];
											vec_271 = _mm512_set1_ps(scal_86);


											vec_270 = _mm512_fmadd_ps(vec_271, vec_237, mem_vec_5650);
											mem_vec_5650 = vec_270;



											vec_272 = _mm512_fmadd_ps(vec_271, vec_239, mem_vec_5651);
											mem_vec_5651 = vec_272;
											scal_87 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 12 + h + 2) + c];
											vec_274 = _mm512_set1_ps(scal_87);


											vec_273 = _mm512_fmadd_ps(vec_274, vec_237, mem_vec_5652);
											mem_vec_5652 = vec_273;



											vec_275 = _mm512_fmadd_ps(vec_274, vec_239, mem_vec_5653);
											mem_vec_5653 = vec_275;
											scal_88 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 13 + h + 2) + c];
											vec_277 = _mm512_set1_ps(scal_88);


											vec_276 = _mm512_fmadd_ps(vec_277, vec_237, mem_vec_5654);
											mem_vec_5654 = vec_276;



											vec_278 = _mm512_fmadd_ps(vec_277, vec_239, mem_vec_5655);
											mem_vec_5655 = vec_278;
											scal_89 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 14 + h + 2) + c];
											vec_280 = _mm512_set1_ps(scal_89);


											vec_279 = _mm512_fmadd_ps(vec_280, vec_237, mem_vec_5656);
											mem_vec_5656 = vec_279;



											vec_281 = _mm512_fmadd_ps(vec_280, vec_239, mem_vec_5657);
											mem_vec_5657 = vec_281;
											scal_90 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_283 = _mm512_set1_ps(scal_90);
											vec_284 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_282 = _mm512_fmadd_ps(vec_283, vec_284, mem_vec_5628);
											mem_vec_5628 = vec_282;

											vec_286 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_285 = _mm512_fmadd_ps(vec_283, vec_286, mem_vec_5629);
											mem_vec_5629 = vec_285;
											scal_91 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_288 = _mm512_set1_ps(scal_91);


											vec_287 = _mm512_fmadd_ps(vec_288, vec_284, mem_vec_5630);
											mem_vec_5630 = vec_287;



											vec_289 = _mm512_fmadd_ps(vec_288, vec_286, mem_vec_5631);
											mem_vec_5631 = vec_289;
											scal_92 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_291 = _mm512_set1_ps(scal_92);


											vec_290 = _mm512_fmadd_ps(vec_291, vec_284, mem_vec_5632);
											mem_vec_5632 = vec_290;



											vec_292 = _mm512_fmadd_ps(vec_291, vec_286, mem_vec_5633);
											mem_vec_5633 = vec_292;
											scal_93 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_294 = _mm512_set1_ps(scal_93);


											vec_293 = _mm512_fmadd_ps(vec_294, vec_284, mem_vec_5634);
											mem_vec_5634 = vec_293;



											vec_295 = _mm512_fmadd_ps(vec_294, vec_286, mem_vec_5635);
											mem_vec_5635 = vec_295;
											scal_94 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_297 = _mm512_set1_ps(scal_94);


											vec_296 = _mm512_fmadd_ps(vec_297, vec_284, mem_vec_5636);
											mem_vec_5636 = vec_296;



											vec_298 = _mm512_fmadd_ps(vec_297, vec_286, mem_vec_5637);
											mem_vec_5637 = vec_298;
											scal_95 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_300 = _mm512_set1_ps(scal_95);


											vec_299 = _mm512_fmadd_ps(vec_300, vec_284, mem_vec_5638);
											mem_vec_5638 = vec_299;



											vec_301 = _mm512_fmadd_ps(vec_300, vec_286, mem_vec_5639);
											mem_vec_5639 = vec_301;
											scal_96 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_303 = _mm512_set1_ps(scal_96);


											vec_302 = _mm512_fmadd_ps(vec_303, vec_284, mem_vec_5640);
											mem_vec_5640 = vec_302;



											vec_304 = _mm512_fmadd_ps(vec_303, vec_286, mem_vec_5641);
											mem_vec_5641 = vec_304;
											scal_97 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
											vec_306 = _mm512_set1_ps(scal_97);


											vec_305 = _mm512_fmadd_ps(vec_306, vec_284, mem_vec_5642);
											mem_vec_5642 = vec_305;



											vec_307 = _mm512_fmadd_ps(vec_306, vec_286, mem_vec_5643);
											mem_vec_5643 = vec_307;
											scal_98 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
											vec_309 = _mm512_set1_ps(scal_98);


											vec_308 = _mm512_fmadd_ps(vec_309, vec_284, mem_vec_5644);
											mem_vec_5644 = vec_308;



											vec_310 = _mm512_fmadd_ps(vec_309, vec_286, mem_vec_5645);
											mem_vec_5645 = vec_310;
											scal_99 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
											vec_312 = _mm512_set1_ps(scal_99);


											vec_311 = _mm512_fmadd_ps(vec_312, vec_284, mem_vec_5646);
											mem_vec_5646 = vec_311;



											vec_313 = _mm512_fmadd_ps(vec_312, vec_286, mem_vec_5647);
											mem_vec_5647 = vec_313;
											scal_100 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
											vec_315 = _mm512_set1_ps(scal_100);


											vec_314 = _mm512_fmadd_ps(vec_315, vec_284, mem_vec_5648);
											mem_vec_5648 = vec_314;



											vec_316 = _mm512_fmadd_ps(vec_315, vec_286, mem_vec_5649);
											mem_vec_5649 = vec_316;
											scal_101 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h) + c];
											vec_318 = _mm512_set1_ps(scal_101);


											vec_317 = _mm512_fmadd_ps(vec_318, vec_284, mem_vec_5650);
											mem_vec_5650 = vec_317;



											vec_319 = _mm512_fmadd_ps(vec_318, vec_286, mem_vec_5651);
											mem_vec_5651 = vec_319;
											scal_102 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 12 + h) + c];
											vec_321 = _mm512_set1_ps(scal_102);


											vec_320 = _mm512_fmadd_ps(vec_321, vec_284, mem_vec_5652);
											mem_vec_5652 = vec_320;



											vec_322 = _mm512_fmadd_ps(vec_321, vec_286, mem_vec_5653);
											mem_vec_5653 = vec_322;
											scal_103 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 13 + h) + c];
											vec_324 = _mm512_set1_ps(scal_103);


											vec_323 = _mm512_fmadd_ps(vec_324, vec_284, mem_vec_5654);
											mem_vec_5654 = vec_323;



											vec_325 = _mm512_fmadd_ps(vec_324, vec_286, mem_vec_5655);
											mem_vec_5655 = vec_325;
											scal_104 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 14 + h) + c];
											vec_327 = _mm512_set1_ps(scal_104);


											vec_326 = _mm512_fmadd_ps(vec_327, vec_284, mem_vec_5656);
											mem_vec_5656 = vec_326;



											vec_328 = _mm512_fmadd_ps(vec_327, vec_286, mem_vec_5657);
											mem_vec_5657 = vec_328;
											scal_105 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_330 = _mm512_set1_ps(scal_105);
											vec_331 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_329 = _mm512_fmadd_ps(vec_330, vec_331, mem_vec_5628);
											mem_vec_5628 = vec_329;

											vec_333 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_332 = _mm512_fmadd_ps(vec_330, vec_333, mem_vec_5629);
											mem_vec_5629 = vec_332;
											scal_106 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_335 = _mm512_set1_ps(scal_106);


											vec_334 = _mm512_fmadd_ps(vec_335, vec_331, mem_vec_5630);
											mem_vec_5630 = vec_334;



											vec_336 = _mm512_fmadd_ps(vec_335, vec_333, mem_vec_5631);
											mem_vec_5631 = vec_336;
											scal_107 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_338 = _mm512_set1_ps(scal_107);


											vec_337 = _mm512_fmadd_ps(vec_338, vec_331, mem_vec_5632);
											mem_vec_5632 = vec_337;



											vec_339 = _mm512_fmadd_ps(vec_338, vec_333, mem_vec_5633);
											mem_vec_5633 = vec_339;
											scal_108 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_341 = _mm512_set1_ps(scal_108);


											vec_340 = _mm512_fmadd_ps(vec_341, vec_331, mem_vec_5634);
											mem_vec_5634 = vec_340;



											vec_342 = _mm512_fmadd_ps(vec_341, vec_333, mem_vec_5635);
											mem_vec_5635 = vec_342;
											scal_109 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_344 = _mm512_set1_ps(scal_109);


											vec_343 = _mm512_fmadd_ps(vec_344, vec_331, mem_vec_5636);
											mem_vec_5636 = vec_343;



											vec_345 = _mm512_fmadd_ps(vec_344, vec_333, mem_vec_5637);
											mem_vec_5637 = vec_345;
											scal_110 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
											vec_347 = _mm512_set1_ps(scal_110);


											vec_346 = _mm512_fmadd_ps(vec_347, vec_331, mem_vec_5638);
											mem_vec_5638 = vec_346;



											vec_348 = _mm512_fmadd_ps(vec_347, vec_333, mem_vec_5639);
											mem_vec_5639 = vec_348;
											scal_111 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
											vec_350 = _mm512_set1_ps(scal_111);


											vec_349 = _mm512_fmadd_ps(vec_350, vec_331, mem_vec_5640);
											mem_vec_5640 = vec_349;



											vec_351 = _mm512_fmadd_ps(vec_350, vec_333, mem_vec_5641);
											mem_vec_5641 = vec_351;
											scal_112 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 1) + c];
											vec_353 = _mm512_set1_ps(scal_112);


											vec_352 = _mm512_fmadd_ps(vec_353, vec_331, mem_vec_5642);
											mem_vec_5642 = vec_352;



											vec_354 = _mm512_fmadd_ps(vec_353, vec_333, mem_vec_5643);
											mem_vec_5643 = vec_354;
											scal_113 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 1) + c];
											vec_356 = _mm512_set1_ps(scal_113);


											vec_355 = _mm512_fmadd_ps(vec_356, vec_331, mem_vec_5644);
											mem_vec_5644 = vec_355;



											vec_357 = _mm512_fmadd_ps(vec_356, vec_333, mem_vec_5645);
											mem_vec_5645 = vec_357;
											scal_114 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 1) + c];
											vec_359 = _mm512_set1_ps(scal_114);


											vec_358 = _mm512_fmadd_ps(vec_359, vec_331, mem_vec_5646);
											mem_vec_5646 = vec_358;



											vec_360 = _mm512_fmadd_ps(vec_359, vec_333, mem_vec_5647);
											mem_vec_5647 = vec_360;
											scal_115 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 1) + c];
											vec_362 = _mm512_set1_ps(scal_115);


											vec_361 = _mm512_fmadd_ps(vec_362, vec_331, mem_vec_5648);
											mem_vec_5648 = vec_361;



											vec_363 = _mm512_fmadd_ps(vec_362, vec_333, mem_vec_5649);
											mem_vec_5649 = vec_363;
											scal_116 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h + 1) + c];
											vec_365 = _mm512_set1_ps(scal_116);


											vec_364 = _mm512_fmadd_ps(vec_365, vec_331, mem_vec_5650);
											mem_vec_5650 = vec_364;



											vec_366 = _mm512_fmadd_ps(vec_365, vec_333, mem_vec_5651);
											mem_vec_5651 = vec_366;
											scal_117 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 12 + h + 1) + c];
											vec_368 = _mm512_set1_ps(scal_117);


											vec_367 = _mm512_fmadd_ps(vec_368, vec_331, mem_vec_5652);
											mem_vec_5652 = vec_367;



											vec_369 = _mm512_fmadd_ps(vec_368, vec_333, mem_vec_5653);
											mem_vec_5653 = vec_369;
											scal_118 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 13 + h + 1) + c];
											vec_371 = _mm512_set1_ps(scal_118);


											vec_370 = _mm512_fmadd_ps(vec_371, vec_331, mem_vec_5654);
											mem_vec_5654 = vec_370;



											vec_372 = _mm512_fmadd_ps(vec_371, vec_333, mem_vec_5655);
											mem_vec_5655 = vec_372;
											scal_119 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 14 + h + 1) + c];
											vec_374 = _mm512_set1_ps(scal_119);


											vec_373 = _mm512_fmadd_ps(vec_374, vec_331, mem_vec_5656);
											mem_vec_5656 = vec_373;



											vec_375 = _mm512_fmadd_ps(vec_374, vec_333, mem_vec_5657);
											mem_vec_5657 = vec_375;
											scal_120 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_377 = _mm512_set1_ps(scal_120);
											vec_378 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_376 = _mm512_fmadd_ps(vec_377, vec_378, mem_vec_5628);
											mem_vec_5628 = vec_376;

											vec_380 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_379 = _mm512_fmadd_ps(vec_377, vec_380, mem_vec_5629);
											mem_vec_5629 = vec_379;
											scal_121 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_382 = _mm512_set1_ps(scal_121);


											vec_381 = _mm512_fmadd_ps(vec_382, vec_378, mem_vec_5630);
											mem_vec_5630 = vec_381;



											vec_383 = _mm512_fmadd_ps(vec_382, vec_380, mem_vec_5631);
											mem_vec_5631 = vec_383;
											scal_122 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_385 = _mm512_set1_ps(scal_122);


											vec_384 = _mm512_fmadd_ps(vec_385, vec_378, mem_vec_5632);
											mem_vec_5632 = vec_384;



											vec_386 = _mm512_fmadd_ps(vec_385, vec_380, mem_vec_5633);
											mem_vec_5633 = vec_386;
											scal_123 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_388 = _mm512_set1_ps(scal_123);


											vec_387 = _mm512_fmadd_ps(vec_388, vec_378, mem_vec_5634);
											mem_vec_5634 = vec_387;



											vec_389 = _mm512_fmadd_ps(vec_388, vec_380, mem_vec_5635);
											mem_vec_5635 = vec_389;
											scal_124 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_391 = _mm512_set1_ps(scal_124);


											vec_390 = _mm512_fmadd_ps(vec_391, vec_378, mem_vec_5636);
											mem_vec_5636 = vec_390;



											vec_392 = _mm512_fmadd_ps(vec_391, vec_380, mem_vec_5637);
											mem_vec_5637 = vec_392;
											scal_125 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
											vec_394 = _mm512_set1_ps(scal_125);


											vec_393 = _mm512_fmadd_ps(vec_394, vec_378, mem_vec_5638);
											mem_vec_5638 = vec_393;



											vec_395 = _mm512_fmadd_ps(vec_394, vec_380, mem_vec_5639);
											mem_vec_5639 = vec_395;
											scal_126 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
											vec_397 = _mm512_set1_ps(scal_126);


											vec_396 = _mm512_fmadd_ps(vec_397, vec_378, mem_vec_5640);
											mem_vec_5640 = vec_396;



											vec_398 = _mm512_fmadd_ps(vec_397, vec_380, mem_vec_5641);
											mem_vec_5641 = vec_398;
											scal_127 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 2) + c];
											vec_400 = _mm512_set1_ps(scal_127);


											vec_399 = _mm512_fmadd_ps(vec_400, vec_378, mem_vec_5642);
											mem_vec_5642 = vec_399;



											vec_401 = _mm512_fmadd_ps(vec_400, vec_380, mem_vec_5643);
											mem_vec_5643 = vec_401;
											scal_128 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 2) + c];
											vec_403 = _mm512_set1_ps(scal_128);


											vec_402 = _mm512_fmadd_ps(vec_403, vec_378, mem_vec_5644);
											mem_vec_5644 = vec_402;



											vec_404 = _mm512_fmadd_ps(vec_403, vec_380, mem_vec_5645);
											mem_vec_5645 = vec_404;
											scal_129 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 2) + c];
											vec_406 = _mm512_set1_ps(scal_129);


											vec_405 = _mm512_fmadd_ps(vec_406, vec_378, mem_vec_5646);
											mem_vec_5646 = vec_405;



											vec_407 = _mm512_fmadd_ps(vec_406, vec_380, mem_vec_5647);
											mem_vec_5647 = vec_407;
											scal_130 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 2) + c];
											vec_409 = _mm512_set1_ps(scal_130);


											vec_408 = _mm512_fmadd_ps(vec_409, vec_378, mem_vec_5648);
											mem_vec_5648 = vec_408;



											vec_410 = _mm512_fmadd_ps(vec_409, vec_380, mem_vec_5649);
											mem_vec_5649 = vec_410;
											scal_131 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h + 2) + c];
											vec_412 = _mm512_set1_ps(scal_131);


											vec_411 = _mm512_fmadd_ps(vec_412, vec_378, mem_vec_5650);
											mem_vec_5650 = vec_411;



											vec_413 = _mm512_fmadd_ps(vec_412, vec_380, mem_vec_5651);
											mem_vec_5651 = vec_413;
											scal_132 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 12 + h + 2) + c];
											vec_415 = _mm512_set1_ps(scal_132);


											vec_414 = _mm512_fmadd_ps(vec_415, vec_378, mem_vec_5652);
											mem_vec_5652 = vec_414;



											vec_416 = _mm512_fmadd_ps(vec_415, vec_380, mem_vec_5653);
											mem_vec_5653 = vec_416;
											scal_133 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 13 + h + 2) + c];
											vec_418 = _mm512_set1_ps(scal_133);


											vec_417 = _mm512_fmadd_ps(vec_418, vec_378, mem_vec_5654);
											mem_vec_5654 = vec_417;



											vec_419 = _mm512_fmadd_ps(vec_418, vec_380, mem_vec_5655);
											mem_vec_5655 = vec_419;
											scal_134 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 14 + h + 2) + c];
											vec_421 = _mm512_set1_ps(scal_134);


											vec_420 = _mm512_fmadd_ps(vec_421, vec_378, mem_vec_5656);
											mem_vec_5656 = vec_420;



											vec_422 = _mm512_fmadd_ps(vec_421, vec_380, mem_vec_5657);
											mem_vec_5657 = vec_422;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5628);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5629);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5630);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5631);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5632);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5633);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5634);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5635);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5636);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5637);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5638);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5639);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5640);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5641);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5642);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5643);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5644);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5645);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5646);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5647);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5648);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_5649);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_5650);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_5651);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_5652);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_5653);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_5654);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_5655);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_5656);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_5657);
							}
						}
					}
				}
		}
	}
}


}