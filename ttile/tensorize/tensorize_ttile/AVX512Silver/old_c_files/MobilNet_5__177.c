#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); U (3, w); T (64, c); Hoist_vars [c];
  T (28, x); T (4, c);
  Lambda_apply y [((Iter 1), (Arg 13)); ((Iter 1), (Arg 15))]; T (8, f);
  T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c514_p_0, cp_1, c514, f, fp_0, x, xp_0, x453_p_0, xp_1, x453, y, yp_0, y446_p_0, yp_1, y446;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y447 = 0;
IND_TYPE x454 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c515 = 0;
IND_TYPE f404 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_100 ,scal_101 ,scal_102 ,scal_103 ,scal_104 ,scal_105 ,scal_106 ,scal_107 ,scal_108 ,scal_109 ,scal_11 ,scal_110 ,scal_111 ,scal_112 ,scal_113 ,scal_114 ,scal_115 ,scal_116 ,scal_117 ,scal_118 ,scal_119 ,scal_12 ,scal_120 ,scal_121 ,scal_122 ,scal_123 ,scal_124 ,scal_125 ,scal_126 ,scal_127 ,scal_128 ,scal_129 ,scal_13 ,scal_130 ,scal_131 ,scal_132 ,scal_133 ,scal_134 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_45 ,scal_46 ,scal_47 ,scal_48 ,scal_49 ,scal_5 ,scal_50 ,scal_51 ,scal_52 ,scal_53 ,scal_54 ,scal_55 ,scal_56 ,scal_57 ,scal_58 ,scal_59 ,scal_6 ,scal_60 ,scal_61 ,scal_62 ,scal_63 ,scal_64 ,scal_65 ,scal_66 ,scal_67 ,scal_68 ,scal_69 ,scal_7 ,scal_70 ,scal_71 ,scal_72 ,scal_73 ,scal_74 ,scal_75 ,scal_76 ,scal_77 ,scal_78 ,scal_79 ,scal_8 ,scal_80 ,scal_81 ,scal_82 ,scal_83 ,scal_84 ,scal_85 ,scal_86 ,scal_87 ,scal_88 ,scal_89 ,scal_9 ,scal_90 ,scal_91 ,scal_92 ,scal_93 ,scal_94 ,scal_95 ,scal_96 ,scal_97 ,scal_98 ,scal_99;
__m512 mem_vec_2897 ,mem_vec_2898 ,mem_vec_2899 ,mem_vec_2900 ,mem_vec_2901 ,mem_vec_2902 ,mem_vec_2903 ,mem_vec_2904 ,mem_vec_2905 ,mem_vec_2906 ,mem_vec_2907 ,mem_vec_2908 ,mem_vec_2909 ,mem_vec_2910 ,mem_vec_2911 ,mem_vec_2912 ,mem_vec_2913 ,mem_vec_2914 ,mem_vec_2915 ,mem_vec_2916 ,mem_vec_2917 ,mem_vec_2918 ,mem_vec_2919 ,mem_vec_2920 ,mem_vec_2921 ,mem_vec_2922 ,mem_vec_2923 ,mem_vec_2924 ,mem_vec_2925 ,mem_vec_2926 ,mem_vec_2927 ,mem_vec_2928 ,mem_vec_2929 ,mem_vec_2930 ,mem_vec_2931 ,mem_vec_2932 ,mem_vec_2933 ,mem_vec_2934 ,mem_vec_2935 ,mem_vec_2936 ,mem_vec_2937 ,mem_vec_2938 ,mem_vec_2939 ,mem_vec_2940 ,mem_vec_2941 ,mem_vec_2942 ,mem_vec_2943 ,mem_vec_2944 ,mem_vec_2945 ,mem_vec_2946 ,mem_vec_2947 ,mem_vec_2948 ,mem_vec_2949 ,mem_vec_2950 ,mem_vec_2951 ,mem_vec_2952 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_132 ,vec_133 ,vec_134 ,vec_135 ,vec_136 ,vec_137 ,vec_138 ,vec_139 ,vec_14 ,vec_140 ,vec_141 ,vec_142 ,vec_143 ,vec_144 ,vec_145 ,vec_146 ,vec_147 ,vec_148 ,vec_149 ,vec_15 ,vec_150 ,vec_151 ,vec_152 ,vec_153 ,vec_154 ,vec_155 ,vec_156 ,vec_157 ,vec_158 ,vec_159 ,vec_16 ,vec_160 ,vec_161 ,vec_162 ,vec_163 ,vec_164 ,vec_165 ,vec_166 ,vec_167 ,vec_168 ,vec_169 ,vec_17 ,vec_170 ,vec_171 ,vec_172 ,vec_173 ,vec_174 ,vec_175 ,vec_176 ,vec_177 ,vec_178 ,vec_179 ,vec_18 ,vec_180 ,vec_181 ,vec_182 ,vec_183 ,vec_184 ,vec_185 ,vec_186 ,vec_187 ,vec_188 ,vec_189 ,vec_19 ,vec_190 ,vec_191 ,vec_192 ,vec_193 ,vec_194 ,vec_195 ,vec_196 ,vec_197 ,vec_198 ,vec_199 ,vec_2 ,vec_20 ,vec_200 ,vec_201 ,vec_202 ,vec_203 ,vec_204 ,vec_205 ,vec_206 ,vec_207 ,vec_208 ,vec_209 ,vec_21 ,vec_210 ,vec_211 ,vec_212 ,vec_213 ,vec_214 ,vec_215 ,vec_216 ,vec_217 ,vec_218 ,vec_219 ,vec_22 ,vec_220 ,vec_221 ,vec_222 ,vec_223 ,vec_224 ,vec_225 ,vec_226 ,vec_227 ,vec_228 ,vec_229 ,vec_23 ,vec_230 ,vec_231 ,vec_232 ,vec_233 ,vec_234 ,vec_235 ,vec_236 ,vec_237 ,vec_238 ,vec_239 ,vec_24 ,vec_240 ,vec_241 ,vec_242 ,vec_243 ,vec_244 ,vec_245 ,vec_246 ,vec_247 ,vec_248 ,vec_249 ,vec_25 ,vec_250 ,vec_251 ,vec_252 ,vec_253 ,vec_254 ,vec_255 ,vec_256 ,vec_257 ,vec_258 ,vec_259 ,vec_26 ,vec_260 ,vec_261 ,vec_262 ,vec_263 ,vec_264 ,vec_265 ,vec_266 ,vec_267 ,vec_268 ,vec_269 ,vec_27 ,vec_270 ,vec_271 ,vec_272 ,vec_273 ,vec_274 ,vec_275 ,vec_276 ,vec_277 ,vec_278 ,vec_279 ,vec_28 ,vec_280 ,vec_281 ,vec_282 ,vec_283 ,vec_284 ,vec_285 ,vec_286 ,vec_287 ,vec_288 ,vec_289 ,vec_29 ,vec_290 ,vec_291 ,vec_292 ,vec_293 ,vec_294 ,vec_295 ,vec_296 ,vec_297 ,vec_298 ,vec_299 ,vec_3 ,vec_30 ,vec_300 ,vec_301 ,vec_302 ,vec_303 ,vec_304 ,vec_305 ,vec_306 ,vec_307 ,vec_308 ,vec_309 ,vec_31 ,vec_310 ,vec_311 ,vec_312 ,vec_313 ,vec_314 ,vec_315 ,vec_316 ,vec_317 ,vec_318 ,vec_319 ,vec_32 ,vec_320 ,vec_321 ,vec_322 ,vec_323 ,vec_324 ,vec_325 ,vec_326 ,vec_327 ,vec_328 ,vec_329 ,vec_33 ,vec_330 ,vec_331 ,vec_332 ,vec_333 ,vec_334 ,vec_335 ,vec_336 ,vec_337 ,vec_338 ,vec_339 ,vec_34 ,vec_340 ,vec_341 ,vec_342 ,vec_343 ,vec_344 ,vec_345 ,vec_346 ,vec_347 ,vec_348 ,vec_349 ,vec_35 ,vec_350 ,vec_351 ,vec_352 ,vec_353 ,vec_354 ,vec_355 ,vec_356 ,vec_357 ,vec_358 ,vec_359 ,vec_36 ,vec_360 ,vec_361 ,vec_362 ,vec_363 ,vec_364 ,vec_365 ,vec_366 ,vec_367 ,vec_368 ,vec_369 ,vec_37 ,vec_370 ,vec_371 ,vec_372 ,vec_373 ,vec_374 ,vec_375 ,vec_376 ,vec_377 ,vec_378 ,vec_379 ,vec_38 ,vec_380 ,vec_381 ,vec_382 ,vec_383 ,vec_384 ,vec_385 ,vec_386 ,vec_387 ,vec_388 ,vec_389 ,vec_39 ,vec_390 ,vec_391 ,vec_392 ,vec_393 ,vec_394 ,vec_395 ,vec_396 ,vec_397 ,vec_398 ,vec_399 ,vec_4 ,vec_40 ,vec_400 ,vec_401 ,vec_402 ,vec_403 ,vec_404 ,vec_405 ,vec_406 ,vec_407 ,vec_408 ,vec_409 ,vec_41 ,vec_410 ,vec_411 ,vec_412 ,vec_413 ,vec_414 ,vec_415 ,vec_416 ,vec_417 ,vec_418 ,vec_419 ,vec_42 ,vec_420 ,vec_421 ,vec_422 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (y, 1) (28 / 28)
for (y446 = y447, y446_p_0 = 0;
	y446 < y447 + 28;
	y446 += 28, y446_p_0 += 28){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (x, 1) (28 / 28)
	for (x453 = x454, x453_p_0 = 0;
		x453 < x454 + 28;
		x453 += 28, x453_p_0 += 28){
		// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f = f404, fp_0 = 0;
			f < f404 + 256;
			f += 32, fp_0 += 32){
				for (y = y446, yp_1 = y446_p_0, yp_0 = 0;
					y < y446 + 13;
					y += 13, yp_1 += 13, yp_0 += 13){
					// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
					// T (c, 4) (256 / 64)
					for (c514 = c515, c514_p_0 = 0;
						c514 < c515 + 256;
						c514 += 64, c514_p_0 += 64){
						// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
						// T (x, 28) (28 / 1)
						for (x = x453, xp_1 = x453_p_0, xp_0 = 0;
							x < x453 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_2897 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2898 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_2901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_2902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_2903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_2904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_2905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_2906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_2907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_2908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_2909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_2910 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_2911 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_2912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_2913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_2914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_2915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_2916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_2917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_2918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_2919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_2920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_2921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_2922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c514, cp_1 = c514_p_0, cp_0 = 0;
										c < c514 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2897);
										mem_vec_2897 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2898);
										mem_vec_2898 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2899);
										mem_vec_2899 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2900);
										mem_vec_2900 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2901);
										mem_vec_2901 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2902);
										mem_vec_2902 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2903);
										mem_vec_2903 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2904);
										mem_vec_2904 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2905);
										mem_vec_2905 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2906);
										mem_vec_2906 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2907);
										mem_vec_2907 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2908);
										mem_vec_2908 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2909);
										mem_vec_2909 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2910);
										mem_vec_2910 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2911);
										mem_vec_2911 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2912);
										mem_vec_2912 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2913);
										mem_vec_2913 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2914);
										mem_vec_2914 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2915);
										mem_vec_2915 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2916);
										mem_vec_2916 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2917);
										mem_vec_2917 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2918);
										mem_vec_2918 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2919);
										mem_vec_2919 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2920);
										mem_vec_2920 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_2921);
										mem_vec_2921 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_2922);
										mem_vec_2922 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_42 = _mm512_set1_ps(scal_13);
										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_41 = _mm512_fmadd_ps(vec_42, vec_43, mem_vec_2897);
										mem_vec_2897 = vec_41;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_44 = _mm512_fmadd_ps(vec_42, vec_45, mem_vec_2898);
										mem_vec_2898 = vec_44;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_43, mem_vec_2899);
										mem_vec_2899 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_45, mem_vec_2900);
										mem_vec_2900 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_43, mem_vec_2901);
										mem_vec_2901 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_45, mem_vec_2902);
										mem_vec_2902 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_53 = _mm512_set1_ps(scal_16);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_43, mem_vec_2903);
										mem_vec_2903 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_45, mem_vec_2904);
										mem_vec_2904 = vec_54;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_56 = _mm512_set1_ps(scal_17);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_43, mem_vec_2905);
										mem_vec_2905 = vec_55;



										vec_57 = _mm512_fmadd_ps(vec_56, vec_45, mem_vec_2906);
										mem_vec_2906 = vec_57;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_18);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_2907);
										mem_vec_2907 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_2908);
										mem_vec_2908 = vec_60;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_62 = _mm512_set1_ps(scal_19);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_43, mem_vec_2909);
										mem_vec_2909 = vec_61;



										vec_63 = _mm512_fmadd_ps(vec_62, vec_45, mem_vec_2910);
										mem_vec_2910 = vec_63;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_65 = _mm512_set1_ps(scal_20);


										vec_64 = _mm512_fmadd_ps(vec_65, vec_43, mem_vec_2911);
										mem_vec_2911 = vec_64;



										vec_66 = _mm512_fmadd_ps(vec_65, vec_45, mem_vec_2912);
										mem_vec_2912 = vec_66;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
										vec_68 = _mm512_set1_ps(scal_21);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_43, mem_vec_2913);
										mem_vec_2913 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_45, mem_vec_2914);
										mem_vec_2914 = vec_69;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
										vec_71 = _mm512_set1_ps(scal_22);


										vec_70 = _mm512_fmadd_ps(vec_71, vec_43, mem_vec_2915);
										mem_vec_2915 = vec_70;



										vec_72 = _mm512_fmadd_ps(vec_71, vec_45, mem_vec_2916);
										mem_vec_2916 = vec_72;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
										vec_74 = _mm512_set1_ps(scal_23);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_2917);
										mem_vec_2917 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_2918);
										mem_vec_2918 = vec_75;
										scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
										vec_77 = _mm512_set1_ps(scal_24);


										vec_76 = _mm512_fmadd_ps(vec_77, vec_43, mem_vec_2919);
										mem_vec_2919 = vec_76;



										vec_78 = _mm512_fmadd_ps(vec_77, vec_45, mem_vec_2920);
										mem_vec_2920 = vec_78;
										scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
										vec_80 = _mm512_set1_ps(scal_25);


										vec_79 = _mm512_fmadd_ps(vec_80, vec_43, mem_vec_2921);
										mem_vec_2921 = vec_79;



										vec_81 = _mm512_fmadd_ps(vec_80, vec_45, mem_vec_2922);
										mem_vec_2922 = vec_81;
										scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_83 = _mm512_set1_ps(scal_26);
										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_82 = _mm512_fmadd_ps(vec_83, vec_84, mem_vec_2897);
										mem_vec_2897 = vec_82;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_85 = _mm512_fmadd_ps(vec_83, vec_86, mem_vec_2898);
										mem_vec_2898 = vec_85;
										scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_27);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_2899);
										mem_vec_2899 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_2900);
										mem_vec_2900 = vec_89;
										scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_91 = _mm512_set1_ps(scal_28);


										vec_90 = _mm512_fmadd_ps(vec_91, vec_84, mem_vec_2901);
										mem_vec_2901 = vec_90;



										vec_92 = _mm512_fmadd_ps(vec_91, vec_86, mem_vec_2902);
										mem_vec_2902 = vec_92;
										scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_94 = _mm512_set1_ps(scal_29);


										vec_93 = _mm512_fmadd_ps(vec_94, vec_84, mem_vec_2903);
										mem_vec_2903 = vec_93;



										vec_95 = _mm512_fmadd_ps(vec_94, vec_86, mem_vec_2904);
										mem_vec_2904 = vec_95;
										scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_97 = _mm512_set1_ps(scal_30);


										vec_96 = _mm512_fmadd_ps(vec_97, vec_84, mem_vec_2905);
										mem_vec_2905 = vec_96;



										vec_98 = _mm512_fmadd_ps(vec_97, vec_86, mem_vec_2906);
										mem_vec_2906 = vec_98;
										scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_100 = _mm512_set1_ps(scal_31);


										vec_99 = _mm512_fmadd_ps(vec_100, vec_84, mem_vec_2907);
										mem_vec_2907 = vec_99;



										vec_101 = _mm512_fmadd_ps(vec_100, vec_86, mem_vec_2908);
										mem_vec_2908 = vec_101;
										scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_103 = _mm512_set1_ps(scal_32);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_2909);
										mem_vec_2909 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_2910);
										mem_vec_2910 = vec_104;
										scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_106 = _mm512_set1_ps(scal_33);


										vec_105 = _mm512_fmadd_ps(vec_106, vec_84, mem_vec_2911);
										mem_vec_2911 = vec_105;



										vec_107 = _mm512_fmadd_ps(vec_106, vec_86, mem_vec_2912);
										mem_vec_2912 = vec_107;
										scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
										vec_109 = _mm512_set1_ps(scal_34);


										vec_108 = _mm512_fmadd_ps(vec_109, vec_84, mem_vec_2913);
										mem_vec_2913 = vec_108;



										vec_110 = _mm512_fmadd_ps(vec_109, vec_86, mem_vec_2914);
										mem_vec_2914 = vec_110;
										scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
										vec_112 = _mm512_set1_ps(scal_35);


										vec_111 = _mm512_fmadd_ps(vec_112, vec_84, mem_vec_2915);
										mem_vec_2915 = vec_111;



										vec_113 = _mm512_fmadd_ps(vec_112, vec_86, mem_vec_2916);
										mem_vec_2916 = vec_113;
										scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
										vec_115 = _mm512_set1_ps(scal_36);


										vec_114 = _mm512_fmadd_ps(vec_115, vec_84, mem_vec_2917);
										mem_vec_2917 = vec_114;



										vec_116 = _mm512_fmadd_ps(vec_115, vec_86, mem_vec_2918);
										mem_vec_2918 = vec_116;
										scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
										vec_118 = _mm512_set1_ps(scal_37);


										vec_117 = _mm512_fmadd_ps(vec_118, vec_84, mem_vec_2919);
										mem_vec_2919 = vec_117;



										vec_119 = _mm512_fmadd_ps(vec_118, vec_86, mem_vec_2920);
										mem_vec_2920 = vec_119;
										scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
										vec_121 = _mm512_set1_ps(scal_38);


										vec_120 = _mm512_fmadd_ps(vec_121, vec_84, mem_vec_2921);
										mem_vec_2921 = vec_120;



										vec_122 = _mm512_fmadd_ps(vec_121, vec_86, mem_vec_2922);
										mem_vec_2922 = vec_122;
										scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_124 = _mm512_set1_ps(scal_39);
										vec_125 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_123 = _mm512_fmadd_ps(vec_124, vec_125, mem_vec_2897);
										mem_vec_2897 = vec_123;

										vec_127 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_126 = _mm512_fmadd_ps(vec_124, vec_127, mem_vec_2898);
										mem_vec_2898 = vec_126;
										scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_129 = _mm512_set1_ps(scal_40);


										vec_128 = _mm512_fmadd_ps(vec_129, vec_125, mem_vec_2899);
										mem_vec_2899 = vec_128;



										vec_130 = _mm512_fmadd_ps(vec_129, vec_127, mem_vec_2900);
										mem_vec_2900 = vec_130;
										scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_132 = _mm512_set1_ps(scal_41);


										vec_131 = _mm512_fmadd_ps(vec_132, vec_125, mem_vec_2901);
										mem_vec_2901 = vec_131;



										vec_133 = _mm512_fmadd_ps(vec_132, vec_127, mem_vec_2902);
										mem_vec_2902 = vec_133;
										scal_42 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_135 = _mm512_set1_ps(scal_42);


										vec_134 = _mm512_fmadd_ps(vec_135, vec_125, mem_vec_2903);
										mem_vec_2903 = vec_134;



										vec_136 = _mm512_fmadd_ps(vec_135, vec_127, mem_vec_2904);
										mem_vec_2904 = vec_136;
										scal_43 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_138 = _mm512_set1_ps(scal_43);


										vec_137 = _mm512_fmadd_ps(vec_138, vec_125, mem_vec_2905);
										mem_vec_2905 = vec_137;



										vec_139 = _mm512_fmadd_ps(vec_138, vec_127, mem_vec_2906);
										mem_vec_2906 = vec_139;
										scal_44 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_141 = _mm512_set1_ps(scal_44);


										vec_140 = _mm512_fmadd_ps(vec_141, vec_125, mem_vec_2907);
										mem_vec_2907 = vec_140;



										vec_142 = _mm512_fmadd_ps(vec_141, vec_127, mem_vec_2908);
										mem_vec_2908 = vec_142;
										scal_45 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_144 = _mm512_set1_ps(scal_45);


										vec_143 = _mm512_fmadd_ps(vec_144, vec_125, mem_vec_2909);
										mem_vec_2909 = vec_143;



										vec_145 = _mm512_fmadd_ps(vec_144, vec_127, mem_vec_2910);
										mem_vec_2910 = vec_145;
										scal_46 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_147 = _mm512_set1_ps(scal_46);


										vec_146 = _mm512_fmadd_ps(vec_147, vec_125, mem_vec_2911);
										mem_vec_2911 = vec_146;



										vec_148 = _mm512_fmadd_ps(vec_147, vec_127, mem_vec_2912);
										mem_vec_2912 = vec_148;
										scal_47 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
										vec_150 = _mm512_set1_ps(scal_47);


										vec_149 = _mm512_fmadd_ps(vec_150, vec_125, mem_vec_2913);
										mem_vec_2913 = vec_149;



										vec_151 = _mm512_fmadd_ps(vec_150, vec_127, mem_vec_2914);
										mem_vec_2914 = vec_151;
										scal_48 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
										vec_153 = _mm512_set1_ps(scal_48);


										vec_152 = _mm512_fmadd_ps(vec_153, vec_125, mem_vec_2915);
										mem_vec_2915 = vec_152;



										vec_154 = _mm512_fmadd_ps(vec_153, vec_127, mem_vec_2916);
										mem_vec_2916 = vec_154;
										scal_49 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
										vec_156 = _mm512_set1_ps(scal_49);


										vec_155 = _mm512_fmadd_ps(vec_156, vec_125, mem_vec_2917);
										mem_vec_2917 = vec_155;



										vec_157 = _mm512_fmadd_ps(vec_156, vec_127, mem_vec_2918);
										mem_vec_2918 = vec_157;
										scal_50 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h) + c];
										vec_159 = _mm512_set1_ps(scal_50);


										vec_158 = _mm512_fmadd_ps(vec_159, vec_125, mem_vec_2919);
										mem_vec_2919 = vec_158;



										vec_160 = _mm512_fmadd_ps(vec_159, vec_127, mem_vec_2920);
										mem_vec_2920 = vec_160;
										scal_51 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 12 + h) + c];
										vec_162 = _mm512_set1_ps(scal_51);


										vec_161 = _mm512_fmadd_ps(vec_162, vec_125, mem_vec_2921);
										mem_vec_2921 = vec_161;



										vec_163 = _mm512_fmadd_ps(vec_162, vec_127, mem_vec_2922);
										mem_vec_2922 = vec_163;
										scal_52 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
										vec_165 = _mm512_set1_ps(scal_52);
										vec_166 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

										vec_164 = _mm512_fmadd_ps(vec_165, vec_166, mem_vec_2897);
										mem_vec_2897 = vec_164;

										vec_168 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f + 16]);

										vec_167 = _mm512_fmadd_ps(vec_165, vec_168, mem_vec_2898);
										mem_vec_2898 = vec_167;
										scal_53 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
										vec_170 = _mm512_set1_ps(scal_53);


										vec_169 = _mm512_fmadd_ps(vec_170, vec_166, mem_vec_2899);
										mem_vec_2899 = vec_169;



										vec_171 = _mm512_fmadd_ps(vec_170, vec_168, mem_vec_2900);
										mem_vec_2900 = vec_171;
										scal_54 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
										vec_173 = _mm512_set1_ps(scal_54);


										vec_172 = _mm512_fmadd_ps(vec_173, vec_166, mem_vec_2901);
										mem_vec_2901 = vec_172;



										vec_174 = _mm512_fmadd_ps(vec_173, vec_168, mem_vec_2902);
										mem_vec_2902 = vec_174;
										scal_55 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
										vec_176 = _mm512_set1_ps(scal_55);


										vec_175 = _mm512_fmadd_ps(vec_176, vec_166, mem_vec_2903);
										mem_vec_2903 = vec_175;



										vec_177 = _mm512_fmadd_ps(vec_176, vec_168, mem_vec_2904);
										mem_vec_2904 = vec_177;
										scal_56 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
										vec_179 = _mm512_set1_ps(scal_56);


										vec_178 = _mm512_fmadd_ps(vec_179, vec_166, mem_vec_2905);
										mem_vec_2905 = vec_178;



										vec_180 = _mm512_fmadd_ps(vec_179, vec_168, mem_vec_2906);
										mem_vec_2906 = vec_180;
										scal_57 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
										vec_182 = _mm512_set1_ps(scal_57);


										vec_181 = _mm512_fmadd_ps(vec_182, vec_166, mem_vec_2907);
										mem_vec_2907 = vec_181;



										vec_183 = _mm512_fmadd_ps(vec_182, vec_168, mem_vec_2908);
										mem_vec_2908 = vec_183;
										scal_58 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
										vec_185 = _mm512_set1_ps(scal_58);


										vec_184 = _mm512_fmadd_ps(vec_185, vec_166, mem_vec_2909);
										mem_vec_2909 = vec_184;



										vec_186 = _mm512_fmadd_ps(vec_185, vec_168, mem_vec_2910);
										mem_vec_2910 = vec_186;
										scal_59 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 1) + c];
										vec_188 = _mm512_set1_ps(scal_59);


										vec_187 = _mm512_fmadd_ps(vec_188, vec_166, mem_vec_2911);
										mem_vec_2911 = vec_187;



										vec_189 = _mm512_fmadd_ps(vec_188, vec_168, mem_vec_2912);
										mem_vec_2912 = vec_189;
										scal_60 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 1) + c];
										vec_191 = _mm512_set1_ps(scal_60);


										vec_190 = _mm512_fmadd_ps(vec_191, vec_166, mem_vec_2913);
										mem_vec_2913 = vec_190;



										vec_192 = _mm512_fmadd_ps(vec_191, vec_168, mem_vec_2914);
										mem_vec_2914 = vec_192;
										scal_61 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 1) + c];
										vec_194 = _mm512_set1_ps(scal_61);


										vec_193 = _mm512_fmadd_ps(vec_194, vec_166, mem_vec_2915);
										mem_vec_2915 = vec_193;



										vec_195 = _mm512_fmadd_ps(vec_194, vec_168, mem_vec_2916);
										mem_vec_2916 = vec_195;
										scal_62 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 1) + c];
										vec_197 = _mm512_set1_ps(scal_62);


										vec_196 = _mm512_fmadd_ps(vec_197, vec_166, mem_vec_2917);
										mem_vec_2917 = vec_196;



										vec_198 = _mm512_fmadd_ps(vec_197, vec_168, mem_vec_2918);
										mem_vec_2918 = vec_198;
										scal_63 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h + 1) + c];
										vec_200 = _mm512_set1_ps(scal_63);


										vec_199 = _mm512_fmadd_ps(vec_200, vec_166, mem_vec_2919);
										mem_vec_2919 = vec_199;



										vec_201 = _mm512_fmadd_ps(vec_200, vec_168, mem_vec_2920);
										mem_vec_2920 = vec_201;
										scal_64 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 12 + h + 1) + c];
										vec_203 = _mm512_set1_ps(scal_64);


										vec_202 = _mm512_fmadd_ps(vec_203, vec_166, mem_vec_2921);
										mem_vec_2921 = vec_202;



										vec_204 = _mm512_fmadd_ps(vec_203, vec_168, mem_vec_2922);
										mem_vec_2922 = vec_204;
										scal_65 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
										vec_206 = _mm512_set1_ps(scal_65);
										vec_207 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

										vec_205 = _mm512_fmadd_ps(vec_206, vec_207, mem_vec_2897);
										mem_vec_2897 = vec_205;

										vec_209 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f + 16]);

										vec_208 = _mm512_fmadd_ps(vec_206, vec_209, mem_vec_2898);
										mem_vec_2898 = vec_208;
										scal_66 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
										vec_211 = _mm512_set1_ps(scal_66);


										vec_210 = _mm512_fmadd_ps(vec_211, vec_207, mem_vec_2899);
										mem_vec_2899 = vec_210;



										vec_212 = _mm512_fmadd_ps(vec_211, vec_209, mem_vec_2900);
										mem_vec_2900 = vec_212;
										scal_67 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
										vec_214 = _mm512_set1_ps(scal_67);


										vec_213 = _mm512_fmadd_ps(vec_214, vec_207, mem_vec_2901);
										mem_vec_2901 = vec_213;



										vec_215 = _mm512_fmadd_ps(vec_214, vec_209, mem_vec_2902);
										mem_vec_2902 = vec_215;
										scal_68 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
										vec_217 = _mm512_set1_ps(scal_68);


										vec_216 = _mm512_fmadd_ps(vec_217, vec_207, mem_vec_2903);
										mem_vec_2903 = vec_216;



										vec_218 = _mm512_fmadd_ps(vec_217, vec_209, mem_vec_2904);
										mem_vec_2904 = vec_218;
										scal_69 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
										vec_220 = _mm512_set1_ps(scal_69);


										vec_219 = _mm512_fmadd_ps(vec_220, vec_207, mem_vec_2905);
										mem_vec_2905 = vec_219;



										vec_221 = _mm512_fmadd_ps(vec_220, vec_209, mem_vec_2906);
										mem_vec_2906 = vec_221;
										scal_70 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
										vec_223 = _mm512_set1_ps(scal_70);


										vec_222 = _mm512_fmadd_ps(vec_223, vec_207, mem_vec_2907);
										mem_vec_2907 = vec_222;



										vec_224 = _mm512_fmadd_ps(vec_223, vec_209, mem_vec_2908);
										mem_vec_2908 = vec_224;
										scal_71 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
										vec_226 = _mm512_set1_ps(scal_71);


										vec_225 = _mm512_fmadd_ps(vec_226, vec_207, mem_vec_2909);
										mem_vec_2909 = vec_225;



										vec_227 = _mm512_fmadd_ps(vec_226, vec_209, mem_vec_2910);
										mem_vec_2910 = vec_227;
										scal_72 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 2) + c];
										vec_229 = _mm512_set1_ps(scal_72);


										vec_228 = _mm512_fmadd_ps(vec_229, vec_207, mem_vec_2911);
										mem_vec_2911 = vec_228;



										vec_230 = _mm512_fmadd_ps(vec_229, vec_209, mem_vec_2912);
										mem_vec_2912 = vec_230;
										scal_73 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 2) + c];
										vec_232 = _mm512_set1_ps(scal_73);


										vec_231 = _mm512_fmadd_ps(vec_232, vec_207, mem_vec_2913);
										mem_vec_2913 = vec_231;



										vec_233 = _mm512_fmadd_ps(vec_232, vec_209, mem_vec_2914);
										mem_vec_2914 = vec_233;
										scal_74 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 2) + c];
										vec_235 = _mm512_set1_ps(scal_74);


										vec_234 = _mm512_fmadd_ps(vec_235, vec_207, mem_vec_2915);
										mem_vec_2915 = vec_234;



										vec_236 = _mm512_fmadd_ps(vec_235, vec_209, mem_vec_2916);
										mem_vec_2916 = vec_236;
										scal_75 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 2) + c];
										vec_238 = _mm512_set1_ps(scal_75);


										vec_237 = _mm512_fmadd_ps(vec_238, vec_207, mem_vec_2917);
										mem_vec_2917 = vec_237;



										vec_239 = _mm512_fmadd_ps(vec_238, vec_209, mem_vec_2918);
										mem_vec_2918 = vec_239;
										scal_76 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h + 2) + c];
										vec_241 = _mm512_set1_ps(scal_76);


										vec_240 = _mm512_fmadd_ps(vec_241, vec_207, mem_vec_2919);
										mem_vec_2919 = vec_240;



										vec_242 = _mm512_fmadd_ps(vec_241, vec_209, mem_vec_2920);
										mem_vec_2920 = vec_242;
										scal_77 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 12 + h + 2) + c];
										vec_244 = _mm512_set1_ps(scal_77);


										vec_243 = _mm512_fmadd_ps(vec_244, vec_207, mem_vec_2921);
										mem_vec_2921 = vec_243;



										vec_245 = _mm512_fmadd_ps(vec_244, vec_209, mem_vec_2922);
										mem_vec_2922 = vec_245;
										scal_78 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_247 = _mm512_set1_ps(scal_78);
										vec_248 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_246 = _mm512_fmadd_ps(vec_247, vec_248, mem_vec_2897);
										mem_vec_2897 = vec_246;

										vec_250 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_249 = _mm512_fmadd_ps(vec_247, vec_250, mem_vec_2898);
										mem_vec_2898 = vec_249;
										scal_79 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_252 = _mm512_set1_ps(scal_79);


										vec_251 = _mm512_fmadd_ps(vec_252, vec_248, mem_vec_2899);
										mem_vec_2899 = vec_251;



										vec_253 = _mm512_fmadd_ps(vec_252, vec_250, mem_vec_2900);
										mem_vec_2900 = vec_253;
										scal_80 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_255 = _mm512_set1_ps(scal_80);


										vec_254 = _mm512_fmadd_ps(vec_255, vec_248, mem_vec_2901);
										mem_vec_2901 = vec_254;



										vec_256 = _mm512_fmadd_ps(vec_255, vec_250, mem_vec_2902);
										mem_vec_2902 = vec_256;
										scal_81 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_258 = _mm512_set1_ps(scal_81);


										vec_257 = _mm512_fmadd_ps(vec_258, vec_248, mem_vec_2903);
										mem_vec_2903 = vec_257;



										vec_259 = _mm512_fmadd_ps(vec_258, vec_250, mem_vec_2904);
										mem_vec_2904 = vec_259;
										scal_82 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_261 = _mm512_set1_ps(scal_82);


										vec_260 = _mm512_fmadd_ps(vec_261, vec_248, mem_vec_2905);
										mem_vec_2905 = vec_260;



										vec_262 = _mm512_fmadd_ps(vec_261, vec_250, mem_vec_2906);
										mem_vec_2906 = vec_262;
										scal_83 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_264 = _mm512_set1_ps(scal_83);


										vec_263 = _mm512_fmadd_ps(vec_264, vec_248, mem_vec_2907);
										mem_vec_2907 = vec_263;



										vec_265 = _mm512_fmadd_ps(vec_264, vec_250, mem_vec_2908);
										mem_vec_2908 = vec_265;
										scal_84 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_267 = _mm512_set1_ps(scal_84);


										vec_266 = _mm512_fmadd_ps(vec_267, vec_248, mem_vec_2909);
										mem_vec_2909 = vec_266;



										vec_268 = _mm512_fmadd_ps(vec_267, vec_250, mem_vec_2910);
										mem_vec_2910 = vec_268;
										scal_85 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_270 = _mm512_set1_ps(scal_85);


										vec_269 = _mm512_fmadd_ps(vec_270, vec_248, mem_vec_2911);
										mem_vec_2911 = vec_269;



										vec_271 = _mm512_fmadd_ps(vec_270, vec_250, mem_vec_2912);
										mem_vec_2912 = vec_271;
										scal_86 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
										vec_273 = _mm512_set1_ps(scal_86);


										vec_272 = _mm512_fmadd_ps(vec_273, vec_248, mem_vec_2913);
										mem_vec_2913 = vec_272;



										vec_274 = _mm512_fmadd_ps(vec_273, vec_250, mem_vec_2914);
										mem_vec_2914 = vec_274;
										scal_87 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
										vec_276 = _mm512_set1_ps(scal_87);


										vec_275 = _mm512_fmadd_ps(vec_276, vec_248, mem_vec_2915);
										mem_vec_2915 = vec_275;



										vec_277 = _mm512_fmadd_ps(vec_276, vec_250, mem_vec_2916);
										mem_vec_2916 = vec_277;
										scal_88 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
										vec_279 = _mm512_set1_ps(scal_88);


										vec_278 = _mm512_fmadd_ps(vec_279, vec_248, mem_vec_2917);
										mem_vec_2917 = vec_278;



										vec_280 = _mm512_fmadd_ps(vec_279, vec_250, mem_vec_2918);
										mem_vec_2918 = vec_280;
										scal_89 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h) + c];
										vec_282 = _mm512_set1_ps(scal_89);


										vec_281 = _mm512_fmadd_ps(vec_282, vec_248, mem_vec_2919);
										mem_vec_2919 = vec_281;



										vec_283 = _mm512_fmadd_ps(vec_282, vec_250, mem_vec_2920);
										mem_vec_2920 = vec_283;
										scal_90 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 12 + h) + c];
										vec_285 = _mm512_set1_ps(scal_90);


										vec_284 = _mm512_fmadd_ps(vec_285, vec_248, mem_vec_2921);
										mem_vec_2921 = vec_284;



										vec_286 = _mm512_fmadd_ps(vec_285, vec_250, mem_vec_2922);
										mem_vec_2922 = vec_286;
										scal_91 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
										vec_288 = _mm512_set1_ps(scal_91);
										vec_289 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

										vec_287 = _mm512_fmadd_ps(vec_288, vec_289, mem_vec_2897);
										mem_vec_2897 = vec_287;

										vec_291 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f + 16]);

										vec_290 = _mm512_fmadd_ps(vec_288, vec_291, mem_vec_2898);
										mem_vec_2898 = vec_290;
										scal_92 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
										vec_293 = _mm512_set1_ps(scal_92);


										vec_292 = _mm512_fmadd_ps(vec_293, vec_289, mem_vec_2899);
										mem_vec_2899 = vec_292;



										vec_294 = _mm512_fmadd_ps(vec_293, vec_291, mem_vec_2900);
										mem_vec_2900 = vec_294;
										scal_93 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
										vec_296 = _mm512_set1_ps(scal_93);


										vec_295 = _mm512_fmadd_ps(vec_296, vec_289, mem_vec_2901);
										mem_vec_2901 = vec_295;



										vec_297 = _mm512_fmadd_ps(vec_296, vec_291, mem_vec_2902);
										mem_vec_2902 = vec_297;
										scal_94 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
										vec_299 = _mm512_set1_ps(scal_94);


										vec_298 = _mm512_fmadd_ps(vec_299, vec_289, mem_vec_2903);
										mem_vec_2903 = vec_298;



										vec_300 = _mm512_fmadd_ps(vec_299, vec_291, mem_vec_2904);
										mem_vec_2904 = vec_300;
										scal_95 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
										vec_302 = _mm512_set1_ps(scal_95);


										vec_301 = _mm512_fmadd_ps(vec_302, vec_289, mem_vec_2905);
										mem_vec_2905 = vec_301;



										vec_303 = _mm512_fmadd_ps(vec_302, vec_291, mem_vec_2906);
										mem_vec_2906 = vec_303;
										scal_96 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
										vec_305 = _mm512_set1_ps(scal_96);


										vec_304 = _mm512_fmadd_ps(vec_305, vec_289, mem_vec_2907);
										mem_vec_2907 = vec_304;



										vec_306 = _mm512_fmadd_ps(vec_305, vec_291, mem_vec_2908);
										mem_vec_2908 = vec_306;
										scal_97 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
										vec_308 = _mm512_set1_ps(scal_97);


										vec_307 = _mm512_fmadd_ps(vec_308, vec_289, mem_vec_2909);
										mem_vec_2909 = vec_307;



										vec_309 = _mm512_fmadd_ps(vec_308, vec_291, mem_vec_2910);
										mem_vec_2910 = vec_309;
										scal_98 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 1) + c];
										vec_311 = _mm512_set1_ps(scal_98);


										vec_310 = _mm512_fmadd_ps(vec_311, vec_289, mem_vec_2911);
										mem_vec_2911 = vec_310;



										vec_312 = _mm512_fmadd_ps(vec_311, vec_291, mem_vec_2912);
										mem_vec_2912 = vec_312;
										scal_99 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 1) + c];
										vec_314 = _mm512_set1_ps(scal_99);


										vec_313 = _mm512_fmadd_ps(vec_314, vec_289, mem_vec_2913);
										mem_vec_2913 = vec_313;



										vec_315 = _mm512_fmadd_ps(vec_314, vec_291, mem_vec_2914);
										mem_vec_2914 = vec_315;
										scal_100 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 1) + c];
										vec_317 = _mm512_set1_ps(scal_100);


										vec_316 = _mm512_fmadd_ps(vec_317, vec_289, mem_vec_2915);
										mem_vec_2915 = vec_316;



										vec_318 = _mm512_fmadd_ps(vec_317, vec_291, mem_vec_2916);
										mem_vec_2916 = vec_318;
										scal_101 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 1) + c];
										vec_320 = _mm512_set1_ps(scal_101);


										vec_319 = _mm512_fmadd_ps(vec_320, vec_289, mem_vec_2917);
										mem_vec_2917 = vec_319;



										vec_321 = _mm512_fmadd_ps(vec_320, vec_291, mem_vec_2918);
										mem_vec_2918 = vec_321;
										scal_102 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h + 1) + c];
										vec_323 = _mm512_set1_ps(scal_102);


										vec_322 = _mm512_fmadd_ps(vec_323, vec_289, mem_vec_2919);
										mem_vec_2919 = vec_322;



										vec_324 = _mm512_fmadd_ps(vec_323, vec_291, mem_vec_2920);
										mem_vec_2920 = vec_324;
										scal_103 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 12 + h + 1) + c];
										vec_326 = _mm512_set1_ps(scal_103);


										vec_325 = _mm512_fmadd_ps(vec_326, vec_289, mem_vec_2921);
										mem_vec_2921 = vec_325;



										vec_327 = _mm512_fmadd_ps(vec_326, vec_291, mem_vec_2922);
										mem_vec_2922 = vec_327;
										scal_104 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
										vec_329 = _mm512_set1_ps(scal_104);
										vec_330 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

										vec_328 = _mm512_fmadd_ps(vec_329, vec_330, mem_vec_2897);
										mem_vec_2897 = vec_328;

										vec_332 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f + 16]);

										vec_331 = _mm512_fmadd_ps(vec_329, vec_332, mem_vec_2898);
										mem_vec_2898 = vec_331;
										scal_105 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
										vec_334 = _mm512_set1_ps(scal_105);


										vec_333 = _mm512_fmadd_ps(vec_334, vec_330, mem_vec_2899);
										mem_vec_2899 = vec_333;



										vec_335 = _mm512_fmadd_ps(vec_334, vec_332, mem_vec_2900);
										mem_vec_2900 = vec_335;
										scal_106 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
										vec_337 = _mm512_set1_ps(scal_106);


										vec_336 = _mm512_fmadd_ps(vec_337, vec_330, mem_vec_2901);
										mem_vec_2901 = vec_336;



										vec_338 = _mm512_fmadd_ps(vec_337, vec_332, mem_vec_2902);
										mem_vec_2902 = vec_338;
										scal_107 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
										vec_340 = _mm512_set1_ps(scal_107);


										vec_339 = _mm512_fmadd_ps(vec_340, vec_330, mem_vec_2903);
										mem_vec_2903 = vec_339;



										vec_341 = _mm512_fmadd_ps(vec_340, vec_332, mem_vec_2904);
										mem_vec_2904 = vec_341;
										scal_108 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
										vec_343 = _mm512_set1_ps(scal_108);


										vec_342 = _mm512_fmadd_ps(vec_343, vec_330, mem_vec_2905);
										mem_vec_2905 = vec_342;



										vec_344 = _mm512_fmadd_ps(vec_343, vec_332, mem_vec_2906);
										mem_vec_2906 = vec_344;
										scal_109 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
										vec_346 = _mm512_set1_ps(scal_109);


										vec_345 = _mm512_fmadd_ps(vec_346, vec_330, mem_vec_2907);
										mem_vec_2907 = vec_345;



										vec_347 = _mm512_fmadd_ps(vec_346, vec_332, mem_vec_2908);
										mem_vec_2908 = vec_347;
										scal_110 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
										vec_349 = _mm512_set1_ps(scal_110);


										vec_348 = _mm512_fmadd_ps(vec_349, vec_330, mem_vec_2909);
										mem_vec_2909 = vec_348;



										vec_350 = _mm512_fmadd_ps(vec_349, vec_332, mem_vec_2910);
										mem_vec_2910 = vec_350;
										scal_111 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 2) + c];
										vec_352 = _mm512_set1_ps(scal_111);


										vec_351 = _mm512_fmadd_ps(vec_352, vec_330, mem_vec_2911);
										mem_vec_2911 = vec_351;



										vec_353 = _mm512_fmadd_ps(vec_352, vec_332, mem_vec_2912);
										mem_vec_2912 = vec_353;
										scal_112 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 2) + c];
										vec_355 = _mm512_set1_ps(scal_112);


										vec_354 = _mm512_fmadd_ps(vec_355, vec_330, mem_vec_2913);
										mem_vec_2913 = vec_354;



										vec_356 = _mm512_fmadd_ps(vec_355, vec_332, mem_vec_2914);
										mem_vec_2914 = vec_356;
										scal_113 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 2) + c];
										vec_358 = _mm512_set1_ps(scal_113);


										vec_357 = _mm512_fmadd_ps(vec_358, vec_330, mem_vec_2915);
										mem_vec_2915 = vec_357;



										vec_359 = _mm512_fmadd_ps(vec_358, vec_332, mem_vec_2916);
										mem_vec_2916 = vec_359;
										scal_114 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 2) + c];
										vec_361 = _mm512_set1_ps(scal_114);


										vec_360 = _mm512_fmadd_ps(vec_361, vec_330, mem_vec_2917);
										mem_vec_2917 = vec_360;



										vec_362 = _mm512_fmadd_ps(vec_361, vec_332, mem_vec_2918);
										mem_vec_2918 = vec_362;
										scal_115 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h + 2) + c];
										vec_364 = _mm512_set1_ps(scal_115);


										vec_363 = _mm512_fmadd_ps(vec_364, vec_330, mem_vec_2919);
										mem_vec_2919 = vec_363;



										vec_365 = _mm512_fmadd_ps(vec_364, vec_332, mem_vec_2920);
										mem_vec_2920 = vec_365;
										scal_116 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 12 + h + 2) + c];
										vec_367 = _mm512_set1_ps(scal_116);


										vec_366 = _mm512_fmadd_ps(vec_367, vec_330, mem_vec_2921);
										mem_vec_2921 = vec_366;



										vec_368 = _mm512_fmadd_ps(vec_367, vec_332, mem_vec_2922);
										mem_vec_2922 = vec_368;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2897);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2898);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2899);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2900);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2901);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2902);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2903);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2904);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2905);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2906);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2907);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2908);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2909);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2910);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2911);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2912);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2913);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2914);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2915);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2916);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2917);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2918);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2919);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_2920);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_2921);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_2922);
						}
					}
				}
				for (y = y446 + 13, yp_1 = y446_p_0, yp_0 = 0;
					y < y446 + 13 + 15;
					y += 15, yp_1 += 15, yp_0 += 15){
					// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
					// T (c, 4) (256 / 64)
					for (c514 = c515, c514_p_0 = 0;
						c514 < c515 + 256;
						c514 += 64, c514_p_0 += 64){
						// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
						// T (x, 28) (28 / 1)
						for (x = x453, xp_1 = x453_p_0, xp_0 = 0;
							x < x453 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_2923 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2924 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_2927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_2928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_2929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_2930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_2931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_2932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_2933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_2934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_2935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_2936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_2937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_2938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_2939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_2940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_2941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_2942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_2943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_2944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_2945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_2946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_2947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_2948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_2949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_2950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									mem_vec_2951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
									mem_vec_2952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
									// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c514, cp_1 = c514_p_0, cp_0 = 0;
										c < c514 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2923);
										mem_vec_2923 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2924);
										mem_vec_2924 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2925);
										mem_vec_2925 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2926);
										mem_vec_2926 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2927);
										mem_vec_2927 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2928);
										mem_vec_2928 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2929);
										mem_vec_2929 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2930);
										mem_vec_2930 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2931);
										mem_vec_2931 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2932);
										mem_vec_2932 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2933);
										mem_vec_2933 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2934);
										mem_vec_2934 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2935);
										mem_vec_2935 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2936);
										mem_vec_2936 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2937);
										mem_vec_2937 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2938);
										mem_vec_2938 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2939);
										mem_vec_2939 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2940);
										mem_vec_2940 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2941);
										mem_vec_2941 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2942);
										mem_vec_2942 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2943);
										mem_vec_2943 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2944);
										mem_vec_2944 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2945);
										mem_vec_2945 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2946);
										mem_vec_2946 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_2947);
										mem_vec_2947 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_2948);
										mem_vec_2948 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_2949);
										mem_vec_2949 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_2950);
										mem_vec_2950 = vec_43;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
										vec_45 = _mm512_set1_ps(scal_14);


										vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_2951);
										mem_vec_2951 = vec_44;



										vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_2952);
										mem_vec_2952 = vec_46;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_48 = _mm512_set1_ps(scal_15);
										vec_49 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_47 = _mm512_fmadd_ps(vec_48, vec_49, mem_vec_2923);
										mem_vec_2923 = vec_47;

										vec_51 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_50 = _mm512_fmadd_ps(vec_48, vec_51, mem_vec_2924);
										mem_vec_2924 = vec_50;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_53 = _mm512_set1_ps(scal_16);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_49, mem_vec_2925);
										mem_vec_2925 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_51, mem_vec_2926);
										mem_vec_2926 = vec_54;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_56 = _mm512_set1_ps(scal_17);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_49, mem_vec_2927);
										mem_vec_2927 = vec_55;



										vec_57 = _mm512_fmadd_ps(vec_56, vec_51, mem_vec_2928);
										mem_vec_2928 = vec_57;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_18);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_49, mem_vec_2929);
										mem_vec_2929 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_51, mem_vec_2930);
										mem_vec_2930 = vec_60;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_62 = _mm512_set1_ps(scal_19);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_49, mem_vec_2931);
										mem_vec_2931 = vec_61;



										vec_63 = _mm512_fmadd_ps(vec_62, vec_51, mem_vec_2932);
										mem_vec_2932 = vec_63;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_65 = _mm512_set1_ps(scal_20);


										vec_64 = _mm512_fmadd_ps(vec_65, vec_49, mem_vec_2933);
										mem_vec_2933 = vec_64;



										vec_66 = _mm512_fmadd_ps(vec_65, vec_51, mem_vec_2934);
										mem_vec_2934 = vec_66;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_68 = _mm512_set1_ps(scal_21);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_49, mem_vec_2935);
										mem_vec_2935 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_51, mem_vec_2936);
										mem_vec_2936 = vec_69;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_71 = _mm512_set1_ps(scal_22);


										vec_70 = _mm512_fmadd_ps(vec_71, vec_49, mem_vec_2937);
										mem_vec_2937 = vec_70;



										vec_72 = _mm512_fmadd_ps(vec_71, vec_51, mem_vec_2938);
										mem_vec_2938 = vec_72;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
										vec_74 = _mm512_set1_ps(scal_23);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_49, mem_vec_2939);
										mem_vec_2939 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_51, mem_vec_2940);
										mem_vec_2940 = vec_75;
										scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
										vec_77 = _mm512_set1_ps(scal_24);


										vec_76 = _mm512_fmadd_ps(vec_77, vec_49, mem_vec_2941);
										mem_vec_2941 = vec_76;



										vec_78 = _mm512_fmadd_ps(vec_77, vec_51, mem_vec_2942);
										mem_vec_2942 = vec_78;
										scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
										vec_80 = _mm512_set1_ps(scal_25);


										vec_79 = _mm512_fmadd_ps(vec_80, vec_49, mem_vec_2943);
										mem_vec_2943 = vec_79;



										vec_81 = _mm512_fmadd_ps(vec_80, vec_51, mem_vec_2944);
										mem_vec_2944 = vec_81;
										scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
										vec_83 = _mm512_set1_ps(scal_26);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_49, mem_vec_2945);
										mem_vec_2945 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_51, mem_vec_2946);
										mem_vec_2946 = vec_84;
										scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
										vec_86 = _mm512_set1_ps(scal_27);


										vec_85 = _mm512_fmadd_ps(vec_86, vec_49, mem_vec_2947);
										mem_vec_2947 = vec_85;



										vec_87 = _mm512_fmadd_ps(vec_86, vec_51, mem_vec_2948);
										mem_vec_2948 = vec_87;
										scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 1) + c];
										vec_89 = _mm512_set1_ps(scal_28);


										vec_88 = _mm512_fmadd_ps(vec_89, vec_49, mem_vec_2949);
										mem_vec_2949 = vec_88;



										vec_90 = _mm512_fmadd_ps(vec_89, vec_51, mem_vec_2950);
										mem_vec_2950 = vec_90;
										scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h + 1) + c];
										vec_92 = _mm512_set1_ps(scal_29);


										vec_91 = _mm512_fmadd_ps(vec_92, vec_49, mem_vec_2951);
										mem_vec_2951 = vec_91;



										vec_93 = _mm512_fmadd_ps(vec_92, vec_51, mem_vec_2952);
										mem_vec_2952 = vec_93;
										scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_95 = _mm512_set1_ps(scal_30);
										vec_96 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_94 = _mm512_fmadd_ps(vec_95, vec_96, mem_vec_2923);
										mem_vec_2923 = vec_94;

										vec_98 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_97 = _mm512_fmadd_ps(vec_95, vec_98, mem_vec_2924);
										mem_vec_2924 = vec_97;
										scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_100 = _mm512_set1_ps(scal_31);


										vec_99 = _mm512_fmadd_ps(vec_100, vec_96, mem_vec_2925);
										mem_vec_2925 = vec_99;



										vec_101 = _mm512_fmadd_ps(vec_100, vec_98, mem_vec_2926);
										mem_vec_2926 = vec_101;
										scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_103 = _mm512_set1_ps(scal_32);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_96, mem_vec_2927);
										mem_vec_2927 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_98, mem_vec_2928);
										mem_vec_2928 = vec_104;
										scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_106 = _mm512_set1_ps(scal_33);


										vec_105 = _mm512_fmadd_ps(vec_106, vec_96, mem_vec_2929);
										mem_vec_2929 = vec_105;



										vec_107 = _mm512_fmadd_ps(vec_106, vec_98, mem_vec_2930);
										mem_vec_2930 = vec_107;
										scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_109 = _mm512_set1_ps(scal_34);


										vec_108 = _mm512_fmadd_ps(vec_109, vec_96, mem_vec_2931);
										mem_vec_2931 = vec_108;



										vec_110 = _mm512_fmadd_ps(vec_109, vec_98, mem_vec_2932);
										mem_vec_2932 = vec_110;
										scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_112 = _mm512_set1_ps(scal_35);


										vec_111 = _mm512_fmadd_ps(vec_112, vec_96, mem_vec_2933);
										mem_vec_2933 = vec_111;



										vec_113 = _mm512_fmadd_ps(vec_112, vec_98, mem_vec_2934);
										mem_vec_2934 = vec_113;
										scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_115 = _mm512_set1_ps(scal_36);


										vec_114 = _mm512_fmadd_ps(vec_115, vec_96, mem_vec_2935);
										mem_vec_2935 = vec_114;



										vec_116 = _mm512_fmadd_ps(vec_115, vec_98, mem_vec_2936);
										mem_vec_2936 = vec_116;
										scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_118 = _mm512_set1_ps(scal_37);


										vec_117 = _mm512_fmadd_ps(vec_118, vec_96, mem_vec_2937);
										mem_vec_2937 = vec_117;



										vec_119 = _mm512_fmadd_ps(vec_118, vec_98, mem_vec_2938);
										mem_vec_2938 = vec_119;
										scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
										vec_121 = _mm512_set1_ps(scal_38);


										vec_120 = _mm512_fmadd_ps(vec_121, vec_96, mem_vec_2939);
										mem_vec_2939 = vec_120;



										vec_122 = _mm512_fmadd_ps(vec_121, vec_98, mem_vec_2940);
										mem_vec_2940 = vec_122;
										scal_39 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
										vec_124 = _mm512_set1_ps(scal_39);


										vec_123 = _mm512_fmadd_ps(vec_124, vec_96, mem_vec_2941);
										mem_vec_2941 = vec_123;



										vec_125 = _mm512_fmadd_ps(vec_124, vec_98, mem_vec_2942);
										mem_vec_2942 = vec_125;
										scal_40 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
										vec_127 = _mm512_set1_ps(scal_40);


										vec_126 = _mm512_fmadd_ps(vec_127, vec_96, mem_vec_2943);
										mem_vec_2943 = vec_126;



										vec_128 = _mm512_fmadd_ps(vec_127, vec_98, mem_vec_2944);
										mem_vec_2944 = vec_128;
										scal_41 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
										vec_130 = _mm512_set1_ps(scal_41);


										vec_129 = _mm512_fmadd_ps(vec_130, vec_96, mem_vec_2945);
										mem_vec_2945 = vec_129;



										vec_131 = _mm512_fmadd_ps(vec_130, vec_98, mem_vec_2946);
										mem_vec_2946 = vec_131;
										scal_42 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
										vec_133 = _mm512_set1_ps(scal_42);


										vec_132 = _mm512_fmadd_ps(vec_133, vec_96, mem_vec_2947);
										mem_vec_2947 = vec_132;



										vec_134 = _mm512_fmadd_ps(vec_133, vec_98, mem_vec_2948);
										mem_vec_2948 = vec_134;
										scal_43 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h + 2) + c];
										vec_136 = _mm512_set1_ps(scal_43);


										vec_135 = _mm512_fmadd_ps(vec_136, vec_96, mem_vec_2949);
										mem_vec_2949 = vec_135;



										vec_137 = _mm512_fmadd_ps(vec_136, vec_98, mem_vec_2950);
										mem_vec_2950 = vec_137;
										scal_44 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h + 2) + c];
										vec_139 = _mm512_set1_ps(scal_44);


										vec_138 = _mm512_fmadd_ps(vec_139, vec_96, mem_vec_2951);
										mem_vec_2951 = vec_138;



										vec_140 = _mm512_fmadd_ps(vec_139, vec_98, mem_vec_2952);
										mem_vec_2952 = vec_140;
										scal_45 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_142 = _mm512_set1_ps(scal_45);
										vec_143 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_141 = _mm512_fmadd_ps(vec_142, vec_143, mem_vec_2923);
										mem_vec_2923 = vec_141;

										vec_145 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_144 = _mm512_fmadd_ps(vec_142, vec_145, mem_vec_2924);
										mem_vec_2924 = vec_144;
										scal_46 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_147 = _mm512_set1_ps(scal_46);


										vec_146 = _mm512_fmadd_ps(vec_147, vec_143, mem_vec_2925);
										mem_vec_2925 = vec_146;



										vec_148 = _mm512_fmadd_ps(vec_147, vec_145, mem_vec_2926);
										mem_vec_2926 = vec_148;
										scal_47 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_150 = _mm512_set1_ps(scal_47);


										vec_149 = _mm512_fmadd_ps(vec_150, vec_143, mem_vec_2927);
										mem_vec_2927 = vec_149;



										vec_151 = _mm512_fmadd_ps(vec_150, vec_145, mem_vec_2928);
										mem_vec_2928 = vec_151;
										scal_48 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_153 = _mm512_set1_ps(scal_48);


										vec_152 = _mm512_fmadd_ps(vec_153, vec_143, mem_vec_2929);
										mem_vec_2929 = vec_152;



										vec_154 = _mm512_fmadd_ps(vec_153, vec_145, mem_vec_2930);
										mem_vec_2930 = vec_154;
										scal_49 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_156 = _mm512_set1_ps(scal_49);


										vec_155 = _mm512_fmadd_ps(vec_156, vec_143, mem_vec_2931);
										mem_vec_2931 = vec_155;



										vec_157 = _mm512_fmadd_ps(vec_156, vec_145, mem_vec_2932);
										mem_vec_2932 = vec_157;
										scal_50 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_159 = _mm512_set1_ps(scal_50);


										vec_158 = _mm512_fmadd_ps(vec_159, vec_143, mem_vec_2933);
										mem_vec_2933 = vec_158;



										vec_160 = _mm512_fmadd_ps(vec_159, vec_145, mem_vec_2934);
										mem_vec_2934 = vec_160;
										scal_51 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_162 = _mm512_set1_ps(scal_51);


										vec_161 = _mm512_fmadd_ps(vec_162, vec_143, mem_vec_2935);
										mem_vec_2935 = vec_161;



										vec_163 = _mm512_fmadd_ps(vec_162, vec_145, mem_vec_2936);
										mem_vec_2936 = vec_163;
										scal_52 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_165 = _mm512_set1_ps(scal_52);


										vec_164 = _mm512_fmadd_ps(vec_165, vec_143, mem_vec_2937);
										mem_vec_2937 = vec_164;



										vec_166 = _mm512_fmadd_ps(vec_165, vec_145, mem_vec_2938);
										mem_vec_2938 = vec_166;
										scal_53 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
										vec_168 = _mm512_set1_ps(scal_53);


										vec_167 = _mm512_fmadd_ps(vec_168, vec_143, mem_vec_2939);
										mem_vec_2939 = vec_167;



										vec_169 = _mm512_fmadd_ps(vec_168, vec_145, mem_vec_2940);
										mem_vec_2940 = vec_169;
										scal_54 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
										vec_171 = _mm512_set1_ps(scal_54);


										vec_170 = _mm512_fmadd_ps(vec_171, vec_143, mem_vec_2941);
										mem_vec_2941 = vec_170;



										vec_172 = _mm512_fmadd_ps(vec_171, vec_145, mem_vec_2942);
										mem_vec_2942 = vec_172;
										scal_55 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
										vec_174 = _mm512_set1_ps(scal_55);


										vec_173 = _mm512_fmadd_ps(vec_174, vec_143, mem_vec_2943);
										mem_vec_2943 = vec_173;



										vec_175 = _mm512_fmadd_ps(vec_174, vec_145, mem_vec_2944);
										mem_vec_2944 = vec_175;
										scal_56 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h) + c];
										vec_177 = _mm512_set1_ps(scal_56);


										vec_176 = _mm512_fmadd_ps(vec_177, vec_143, mem_vec_2945);
										mem_vec_2945 = vec_176;



										vec_178 = _mm512_fmadd_ps(vec_177, vec_145, mem_vec_2946);
										mem_vec_2946 = vec_178;
										scal_57 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 12 + h) + c];
										vec_180 = _mm512_set1_ps(scal_57);


										vec_179 = _mm512_fmadd_ps(vec_180, vec_143, mem_vec_2947);
										mem_vec_2947 = vec_179;



										vec_181 = _mm512_fmadd_ps(vec_180, vec_145, mem_vec_2948);
										mem_vec_2948 = vec_181;
										scal_58 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 13 + h) + c];
										vec_183 = _mm512_set1_ps(scal_58);


										vec_182 = _mm512_fmadd_ps(vec_183, vec_143, mem_vec_2949);
										mem_vec_2949 = vec_182;



										vec_184 = _mm512_fmadd_ps(vec_183, vec_145, mem_vec_2950);
										mem_vec_2950 = vec_184;
										scal_59 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 14 + h) + c];
										vec_186 = _mm512_set1_ps(scal_59);


										vec_185 = _mm512_fmadd_ps(vec_186, vec_143, mem_vec_2951);
										mem_vec_2951 = vec_185;



										vec_187 = _mm512_fmadd_ps(vec_186, vec_145, mem_vec_2952);
										mem_vec_2952 = vec_187;
										scal_60 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
										vec_189 = _mm512_set1_ps(scal_60);
										vec_190 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

										vec_188 = _mm512_fmadd_ps(vec_189, vec_190, mem_vec_2923);
										mem_vec_2923 = vec_188;

										vec_192 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f + 16]);

										vec_191 = _mm512_fmadd_ps(vec_189, vec_192, mem_vec_2924);
										mem_vec_2924 = vec_191;
										scal_61 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
										vec_194 = _mm512_set1_ps(scal_61);


										vec_193 = _mm512_fmadd_ps(vec_194, vec_190, mem_vec_2925);
										mem_vec_2925 = vec_193;



										vec_195 = _mm512_fmadd_ps(vec_194, vec_192, mem_vec_2926);
										mem_vec_2926 = vec_195;
										scal_62 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
										vec_197 = _mm512_set1_ps(scal_62);


										vec_196 = _mm512_fmadd_ps(vec_197, vec_190, mem_vec_2927);
										mem_vec_2927 = vec_196;



										vec_198 = _mm512_fmadd_ps(vec_197, vec_192, mem_vec_2928);
										mem_vec_2928 = vec_198;
										scal_63 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
										vec_200 = _mm512_set1_ps(scal_63);


										vec_199 = _mm512_fmadd_ps(vec_200, vec_190, mem_vec_2929);
										mem_vec_2929 = vec_199;



										vec_201 = _mm512_fmadd_ps(vec_200, vec_192, mem_vec_2930);
										mem_vec_2930 = vec_201;
										scal_64 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
										vec_203 = _mm512_set1_ps(scal_64);


										vec_202 = _mm512_fmadd_ps(vec_203, vec_190, mem_vec_2931);
										mem_vec_2931 = vec_202;



										vec_204 = _mm512_fmadd_ps(vec_203, vec_192, mem_vec_2932);
										mem_vec_2932 = vec_204;
										scal_65 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
										vec_206 = _mm512_set1_ps(scal_65);


										vec_205 = _mm512_fmadd_ps(vec_206, vec_190, mem_vec_2933);
										mem_vec_2933 = vec_205;



										vec_207 = _mm512_fmadd_ps(vec_206, vec_192, mem_vec_2934);
										mem_vec_2934 = vec_207;
										scal_66 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
										vec_209 = _mm512_set1_ps(scal_66);


										vec_208 = _mm512_fmadd_ps(vec_209, vec_190, mem_vec_2935);
										mem_vec_2935 = vec_208;



										vec_210 = _mm512_fmadd_ps(vec_209, vec_192, mem_vec_2936);
										mem_vec_2936 = vec_210;
										scal_67 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 1) + c];
										vec_212 = _mm512_set1_ps(scal_67);


										vec_211 = _mm512_fmadd_ps(vec_212, vec_190, mem_vec_2937);
										mem_vec_2937 = vec_211;



										vec_213 = _mm512_fmadd_ps(vec_212, vec_192, mem_vec_2938);
										mem_vec_2938 = vec_213;
										scal_68 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 1) + c];
										vec_215 = _mm512_set1_ps(scal_68);


										vec_214 = _mm512_fmadd_ps(vec_215, vec_190, mem_vec_2939);
										mem_vec_2939 = vec_214;



										vec_216 = _mm512_fmadd_ps(vec_215, vec_192, mem_vec_2940);
										mem_vec_2940 = vec_216;
										scal_69 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 1) + c];
										vec_218 = _mm512_set1_ps(scal_69);


										vec_217 = _mm512_fmadd_ps(vec_218, vec_190, mem_vec_2941);
										mem_vec_2941 = vec_217;



										vec_219 = _mm512_fmadd_ps(vec_218, vec_192, mem_vec_2942);
										mem_vec_2942 = vec_219;
										scal_70 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 1) + c];
										vec_221 = _mm512_set1_ps(scal_70);


										vec_220 = _mm512_fmadd_ps(vec_221, vec_190, mem_vec_2943);
										mem_vec_2943 = vec_220;



										vec_222 = _mm512_fmadd_ps(vec_221, vec_192, mem_vec_2944);
										mem_vec_2944 = vec_222;
										scal_71 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h + 1) + c];
										vec_224 = _mm512_set1_ps(scal_71);


										vec_223 = _mm512_fmadd_ps(vec_224, vec_190, mem_vec_2945);
										mem_vec_2945 = vec_223;



										vec_225 = _mm512_fmadd_ps(vec_224, vec_192, mem_vec_2946);
										mem_vec_2946 = vec_225;
										scal_72 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 12 + h + 1) + c];
										vec_227 = _mm512_set1_ps(scal_72);


										vec_226 = _mm512_fmadd_ps(vec_227, vec_190, mem_vec_2947);
										mem_vec_2947 = vec_226;



										vec_228 = _mm512_fmadd_ps(vec_227, vec_192, mem_vec_2948);
										mem_vec_2948 = vec_228;
										scal_73 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 13 + h + 1) + c];
										vec_230 = _mm512_set1_ps(scal_73);


										vec_229 = _mm512_fmadd_ps(vec_230, vec_190, mem_vec_2949);
										mem_vec_2949 = vec_229;



										vec_231 = _mm512_fmadd_ps(vec_230, vec_192, mem_vec_2950);
										mem_vec_2950 = vec_231;
										scal_74 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 14 + h + 1) + c];
										vec_233 = _mm512_set1_ps(scal_74);


										vec_232 = _mm512_fmadd_ps(vec_233, vec_190, mem_vec_2951);
										mem_vec_2951 = vec_232;



										vec_234 = _mm512_fmadd_ps(vec_233, vec_192, mem_vec_2952);
										mem_vec_2952 = vec_234;
										scal_75 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
										vec_236 = _mm512_set1_ps(scal_75);
										vec_237 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

										vec_235 = _mm512_fmadd_ps(vec_236, vec_237, mem_vec_2923);
										mem_vec_2923 = vec_235;

										vec_239 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f + 16]);

										vec_238 = _mm512_fmadd_ps(vec_236, vec_239, mem_vec_2924);
										mem_vec_2924 = vec_238;
										scal_76 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
										vec_241 = _mm512_set1_ps(scal_76);


										vec_240 = _mm512_fmadd_ps(vec_241, vec_237, mem_vec_2925);
										mem_vec_2925 = vec_240;



										vec_242 = _mm512_fmadd_ps(vec_241, vec_239, mem_vec_2926);
										mem_vec_2926 = vec_242;
										scal_77 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
										vec_244 = _mm512_set1_ps(scal_77);


										vec_243 = _mm512_fmadd_ps(vec_244, vec_237, mem_vec_2927);
										mem_vec_2927 = vec_243;



										vec_245 = _mm512_fmadd_ps(vec_244, vec_239, mem_vec_2928);
										mem_vec_2928 = vec_245;
										scal_78 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
										vec_247 = _mm512_set1_ps(scal_78);


										vec_246 = _mm512_fmadd_ps(vec_247, vec_237, mem_vec_2929);
										mem_vec_2929 = vec_246;



										vec_248 = _mm512_fmadd_ps(vec_247, vec_239, mem_vec_2930);
										mem_vec_2930 = vec_248;
										scal_79 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
										vec_250 = _mm512_set1_ps(scal_79);


										vec_249 = _mm512_fmadd_ps(vec_250, vec_237, mem_vec_2931);
										mem_vec_2931 = vec_249;



										vec_251 = _mm512_fmadd_ps(vec_250, vec_239, mem_vec_2932);
										mem_vec_2932 = vec_251;
										scal_80 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
										vec_253 = _mm512_set1_ps(scal_80);


										vec_252 = _mm512_fmadd_ps(vec_253, vec_237, mem_vec_2933);
										mem_vec_2933 = vec_252;



										vec_254 = _mm512_fmadd_ps(vec_253, vec_239, mem_vec_2934);
										mem_vec_2934 = vec_254;
										scal_81 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
										vec_256 = _mm512_set1_ps(scal_81);


										vec_255 = _mm512_fmadd_ps(vec_256, vec_237, mem_vec_2935);
										mem_vec_2935 = vec_255;



										vec_257 = _mm512_fmadd_ps(vec_256, vec_239, mem_vec_2936);
										mem_vec_2936 = vec_257;
										scal_82 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 2) + c];
										vec_259 = _mm512_set1_ps(scal_82);


										vec_258 = _mm512_fmadd_ps(vec_259, vec_237, mem_vec_2937);
										mem_vec_2937 = vec_258;



										vec_260 = _mm512_fmadd_ps(vec_259, vec_239, mem_vec_2938);
										mem_vec_2938 = vec_260;
										scal_83 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 2) + c];
										vec_262 = _mm512_set1_ps(scal_83);


										vec_261 = _mm512_fmadd_ps(vec_262, vec_237, mem_vec_2939);
										mem_vec_2939 = vec_261;



										vec_263 = _mm512_fmadd_ps(vec_262, vec_239, mem_vec_2940);
										mem_vec_2940 = vec_263;
										scal_84 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 2) + c];
										vec_265 = _mm512_set1_ps(scal_84);


										vec_264 = _mm512_fmadd_ps(vec_265, vec_237, mem_vec_2941);
										mem_vec_2941 = vec_264;



										vec_266 = _mm512_fmadd_ps(vec_265, vec_239, mem_vec_2942);
										mem_vec_2942 = vec_266;
										scal_85 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 2) + c];
										vec_268 = _mm512_set1_ps(scal_85);


										vec_267 = _mm512_fmadd_ps(vec_268, vec_237, mem_vec_2943);
										mem_vec_2943 = vec_267;



										vec_269 = _mm512_fmadd_ps(vec_268, vec_239, mem_vec_2944);
										mem_vec_2944 = vec_269;
										scal_86 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h + 2) + c];
										vec_271 = _mm512_set1_ps(scal_86);


										vec_270 = _mm512_fmadd_ps(vec_271, vec_237, mem_vec_2945);
										mem_vec_2945 = vec_270;



										vec_272 = _mm512_fmadd_ps(vec_271, vec_239, mem_vec_2946);
										mem_vec_2946 = vec_272;
										scal_87 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 12 + h + 2) + c];
										vec_274 = _mm512_set1_ps(scal_87);


										vec_273 = _mm512_fmadd_ps(vec_274, vec_237, mem_vec_2947);
										mem_vec_2947 = vec_273;



										vec_275 = _mm512_fmadd_ps(vec_274, vec_239, mem_vec_2948);
										mem_vec_2948 = vec_275;
										scal_88 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 13 + h + 2) + c];
										vec_277 = _mm512_set1_ps(scal_88);


										vec_276 = _mm512_fmadd_ps(vec_277, vec_237, mem_vec_2949);
										mem_vec_2949 = vec_276;



										vec_278 = _mm512_fmadd_ps(vec_277, vec_239, mem_vec_2950);
										mem_vec_2950 = vec_278;
										scal_89 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 14 + h + 2) + c];
										vec_280 = _mm512_set1_ps(scal_89);


										vec_279 = _mm512_fmadd_ps(vec_280, vec_237, mem_vec_2951);
										mem_vec_2951 = vec_279;



										vec_281 = _mm512_fmadd_ps(vec_280, vec_239, mem_vec_2952);
										mem_vec_2952 = vec_281;
										scal_90 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_283 = _mm512_set1_ps(scal_90);
										vec_284 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_282 = _mm512_fmadd_ps(vec_283, vec_284, mem_vec_2923);
										mem_vec_2923 = vec_282;

										vec_286 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_285 = _mm512_fmadd_ps(vec_283, vec_286, mem_vec_2924);
										mem_vec_2924 = vec_285;
										scal_91 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_288 = _mm512_set1_ps(scal_91);


										vec_287 = _mm512_fmadd_ps(vec_288, vec_284, mem_vec_2925);
										mem_vec_2925 = vec_287;



										vec_289 = _mm512_fmadd_ps(vec_288, vec_286, mem_vec_2926);
										mem_vec_2926 = vec_289;
										scal_92 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_291 = _mm512_set1_ps(scal_92);


										vec_290 = _mm512_fmadd_ps(vec_291, vec_284, mem_vec_2927);
										mem_vec_2927 = vec_290;



										vec_292 = _mm512_fmadd_ps(vec_291, vec_286, mem_vec_2928);
										mem_vec_2928 = vec_292;
										scal_93 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_294 = _mm512_set1_ps(scal_93);


										vec_293 = _mm512_fmadd_ps(vec_294, vec_284, mem_vec_2929);
										mem_vec_2929 = vec_293;



										vec_295 = _mm512_fmadd_ps(vec_294, vec_286, mem_vec_2930);
										mem_vec_2930 = vec_295;
										scal_94 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_297 = _mm512_set1_ps(scal_94);


										vec_296 = _mm512_fmadd_ps(vec_297, vec_284, mem_vec_2931);
										mem_vec_2931 = vec_296;



										vec_298 = _mm512_fmadd_ps(vec_297, vec_286, mem_vec_2932);
										mem_vec_2932 = vec_298;
										scal_95 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_300 = _mm512_set1_ps(scal_95);


										vec_299 = _mm512_fmadd_ps(vec_300, vec_284, mem_vec_2933);
										mem_vec_2933 = vec_299;



										vec_301 = _mm512_fmadd_ps(vec_300, vec_286, mem_vec_2934);
										mem_vec_2934 = vec_301;
										scal_96 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_303 = _mm512_set1_ps(scal_96);


										vec_302 = _mm512_fmadd_ps(vec_303, vec_284, mem_vec_2935);
										mem_vec_2935 = vec_302;



										vec_304 = _mm512_fmadd_ps(vec_303, vec_286, mem_vec_2936);
										mem_vec_2936 = vec_304;
										scal_97 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_306 = _mm512_set1_ps(scal_97);


										vec_305 = _mm512_fmadd_ps(vec_306, vec_284, mem_vec_2937);
										mem_vec_2937 = vec_305;



										vec_307 = _mm512_fmadd_ps(vec_306, vec_286, mem_vec_2938);
										mem_vec_2938 = vec_307;
										scal_98 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
										vec_309 = _mm512_set1_ps(scal_98);


										vec_308 = _mm512_fmadd_ps(vec_309, vec_284, mem_vec_2939);
										mem_vec_2939 = vec_308;



										vec_310 = _mm512_fmadd_ps(vec_309, vec_286, mem_vec_2940);
										mem_vec_2940 = vec_310;
										scal_99 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
										vec_312 = _mm512_set1_ps(scal_99);


										vec_311 = _mm512_fmadd_ps(vec_312, vec_284, mem_vec_2941);
										mem_vec_2941 = vec_311;



										vec_313 = _mm512_fmadd_ps(vec_312, vec_286, mem_vec_2942);
										mem_vec_2942 = vec_313;
										scal_100 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
										vec_315 = _mm512_set1_ps(scal_100);


										vec_314 = _mm512_fmadd_ps(vec_315, vec_284, mem_vec_2943);
										mem_vec_2943 = vec_314;



										vec_316 = _mm512_fmadd_ps(vec_315, vec_286, mem_vec_2944);
										mem_vec_2944 = vec_316;
										scal_101 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h) + c];
										vec_318 = _mm512_set1_ps(scal_101);


										vec_317 = _mm512_fmadd_ps(vec_318, vec_284, mem_vec_2945);
										mem_vec_2945 = vec_317;



										vec_319 = _mm512_fmadd_ps(vec_318, vec_286, mem_vec_2946);
										mem_vec_2946 = vec_319;
										scal_102 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 12 + h) + c];
										vec_321 = _mm512_set1_ps(scal_102);


										vec_320 = _mm512_fmadd_ps(vec_321, vec_284, mem_vec_2947);
										mem_vec_2947 = vec_320;



										vec_322 = _mm512_fmadd_ps(vec_321, vec_286, mem_vec_2948);
										mem_vec_2948 = vec_322;
										scal_103 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 13 + h) + c];
										vec_324 = _mm512_set1_ps(scal_103);


										vec_323 = _mm512_fmadd_ps(vec_324, vec_284, mem_vec_2949);
										mem_vec_2949 = vec_323;



										vec_325 = _mm512_fmadd_ps(vec_324, vec_286, mem_vec_2950);
										mem_vec_2950 = vec_325;
										scal_104 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 14 + h) + c];
										vec_327 = _mm512_set1_ps(scal_104);


										vec_326 = _mm512_fmadd_ps(vec_327, vec_284, mem_vec_2951);
										mem_vec_2951 = vec_326;



										vec_328 = _mm512_fmadd_ps(vec_327, vec_286, mem_vec_2952);
										mem_vec_2952 = vec_328;
										scal_105 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
										vec_330 = _mm512_set1_ps(scal_105);
										vec_331 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

										vec_329 = _mm512_fmadd_ps(vec_330, vec_331, mem_vec_2923);
										mem_vec_2923 = vec_329;

										vec_333 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f + 16]);

										vec_332 = _mm512_fmadd_ps(vec_330, vec_333, mem_vec_2924);
										mem_vec_2924 = vec_332;
										scal_106 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
										vec_335 = _mm512_set1_ps(scal_106);


										vec_334 = _mm512_fmadd_ps(vec_335, vec_331, mem_vec_2925);
										mem_vec_2925 = vec_334;



										vec_336 = _mm512_fmadd_ps(vec_335, vec_333, mem_vec_2926);
										mem_vec_2926 = vec_336;
										scal_107 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
										vec_338 = _mm512_set1_ps(scal_107);


										vec_337 = _mm512_fmadd_ps(vec_338, vec_331, mem_vec_2927);
										mem_vec_2927 = vec_337;



										vec_339 = _mm512_fmadd_ps(vec_338, vec_333, mem_vec_2928);
										mem_vec_2928 = vec_339;
										scal_108 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
										vec_341 = _mm512_set1_ps(scal_108);


										vec_340 = _mm512_fmadd_ps(vec_341, vec_331, mem_vec_2929);
										mem_vec_2929 = vec_340;



										vec_342 = _mm512_fmadd_ps(vec_341, vec_333, mem_vec_2930);
										mem_vec_2930 = vec_342;
										scal_109 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
										vec_344 = _mm512_set1_ps(scal_109);


										vec_343 = _mm512_fmadd_ps(vec_344, vec_331, mem_vec_2931);
										mem_vec_2931 = vec_343;



										vec_345 = _mm512_fmadd_ps(vec_344, vec_333, mem_vec_2932);
										mem_vec_2932 = vec_345;
										scal_110 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
										vec_347 = _mm512_set1_ps(scal_110);


										vec_346 = _mm512_fmadd_ps(vec_347, vec_331, mem_vec_2933);
										mem_vec_2933 = vec_346;



										vec_348 = _mm512_fmadd_ps(vec_347, vec_333, mem_vec_2934);
										mem_vec_2934 = vec_348;
										scal_111 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
										vec_350 = _mm512_set1_ps(scal_111);


										vec_349 = _mm512_fmadd_ps(vec_350, vec_331, mem_vec_2935);
										mem_vec_2935 = vec_349;



										vec_351 = _mm512_fmadd_ps(vec_350, vec_333, mem_vec_2936);
										mem_vec_2936 = vec_351;
										scal_112 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 1) + c];
										vec_353 = _mm512_set1_ps(scal_112);


										vec_352 = _mm512_fmadd_ps(vec_353, vec_331, mem_vec_2937);
										mem_vec_2937 = vec_352;



										vec_354 = _mm512_fmadd_ps(vec_353, vec_333, mem_vec_2938);
										mem_vec_2938 = vec_354;
										scal_113 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 1) + c];
										vec_356 = _mm512_set1_ps(scal_113);


										vec_355 = _mm512_fmadd_ps(vec_356, vec_331, mem_vec_2939);
										mem_vec_2939 = vec_355;



										vec_357 = _mm512_fmadd_ps(vec_356, vec_333, mem_vec_2940);
										mem_vec_2940 = vec_357;
										scal_114 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 1) + c];
										vec_359 = _mm512_set1_ps(scal_114);


										vec_358 = _mm512_fmadd_ps(vec_359, vec_331, mem_vec_2941);
										mem_vec_2941 = vec_358;



										vec_360 = _mm512_fmadd_ps(vec_359, vec_333, mem_vec_2942);
										mem_vec_2942 = vec_360;
										scal_115 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 1) + c];
										vec_362 = _mm512_set1_ps(scal_115);


										vec_361 = _mm512_fmadd_ps(vec_362, vec_331, mem_vec_2943);
										mem_vec_2943 = vec_361;



										vec_363 = _mm512_fmadd_ps(vec_362, vec_333, mem_vec_2944);
										mem_vec_2944 = vec_363;
										scal_116 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h + 1) + c];
										vec_365 = _mm512_set1_ps(scal_116);


										vec_364 = _mm512_fmadd_ps(vec_365, vec_331, mem_vec_2945);
										mem_vec_2945 = vec_364;



										vec_366 = _mm512_fmadd_ps(vec_365, vec_333, mem_vec_2946);
										mem_vec_2946 = vec_366;
										scal_117 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 12 + h + 1) + c];
										vec_368 = _mm512_set1_ps(scal_117);


										vec_367 = _mm512_fmadd_ps(vec_368, vec_331, mem_vec_2947);
										mem_vec_2947 = vec_367;



										vec_369 = _mm512_fmadd_ps(vec_368, vec_333, mem_vec_2948);
										mem_vec_2948 = vec_369;
										scal_118 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 13 + h + 1) + c];
										vec_371 = _mm512_set1_ps(scal_118);


										vec_370 = _mm512_fmadd_ps(vec_371, vec_331, mem_vec_2949);
										mem_vec_2949 = vec_370;



										vec_372 = _mm512_fmadd_ps(vec_371, vec_333, mem_vec_2950);
										mem_vec_2950 = vec_372;
										scal_119 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 14 + h + 1) + c];
										vec_374 = _mm512_set1_ps(scal_119);


										vec_373 = _mm512_fmadd_ps(vec_374, vec_331, mem_vec_2951);
										mem_vec_2951 = vec_373;



										vec_375 = _mm512_fmadd_ps(vec_374, vec_333, mem_vec_2952);
										mem_vec_2952 = vec_375;
										scal_120 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
										vec_377 = _mm512_set1_ps(scal_120);
										vec_378 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

										vec_376 = _mm512_fmadd_ps(vec_377, vec_378, mem_vec_2923);
										mem_vec_2923 = vec_376;

										vec_380 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f + 16]);

										vec_379 = _mm512_fmadd_ps(vec_377, vec_380, mem_vec_2924);
										mem_vec_2924 = vec_379;
										scal_121 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
										vec_382 = _mm512_set1_ps(scal_121);


										vec_381 = _mm512_fmadd_ps(vec_382, vec_378, mem_vec_2925);
										mem_vec_2925 = vec_381;



										vec_383 = _mm512_fmadd_ps(vec_382, vec_380, mem_vec_2926);
										mem_vec_2926 = vec_383;
										scal_122 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
										vec_385 = _mm512_set1_ps(scal_122);


										vec_384 = _mm512_fmadd_ps(vec_385, vec_378, mem_vec_2927);
										mem_vec_2927 = vec_384;



										vec_386 = _mm512_fmadd_ps(vec_385, vec_380, mem_vec_2928);
										mem_vec_2928 = vec_386;
										scal_123 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
										vec_388 = _mm512_set1_ps(scal_123);


										vec_387 = _mm512_fmadd_ps(vec_388, vec_378, mem_vec_2929);
										mem_vec_2929 = vec_387;



										vec_389 = _mm512_fmadd_ps(vec_388, vec_380, mem_vec_2930);
										mem_vec_2930 = vec_389;
										scal_124 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
										vec_391 = _mm512_set1_ps(scal_124);


										vec_390 = _mm512_fmadd_ps(vec_391, vec_378, mem_vec_2931);
										mem_vec_2931 = vec_390;



										vec_392 = _mm512_fmadd_ps(vec_391, vec_380, mem_vec_2932);
										mem_vec_2932 = vec_392;
										scal_125 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
										vec_394 = _mm512_set1_ps(scal_125);


										vec_393 = _mm512_fmadd_ps(vec_394, vec_378, mem_vec_2933);
										mem_vec_2933 = vec_393;



										vec_395 = _mm512_fmadd_ps(vec_394, vec_380, mem_vec_2934);
										mem_vec_2934 = vec_395;
										scal_126 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
										vec_397 = _mm512_set1_ps(scal_126);


										vec_396 = _mm512_fmadd_ps(vec_397, vec_378, mem_vec_2935);
										mem_vec_2935 = vec_396;



										vec_398 = _mm512_fmadd_ps(vec_397, vec_380, mem_vec_2936);
										mem_vec_2936 = vec_398;
										scal_127 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 2) + c];
										vec_400 = _mm512_set1_ps(scal_127);


										vec_399 = _mm512_fmadd_ps(vec_400, vec_378, mem_vec_2937);
										mem_vec_2937 = vec_399;



										vec_401 = _mm512_fmadd_ps(vec_400, vec_380, mem_vec_2938);
										mem_vec_2938 = vec_401;
										scal_128 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 2) + c];
										vec_403 = _mm512_set1_ps(scal_128);


										vec_402 = _mm512_fmadd_ps(vec_403, vec_378, mem_vec_2939);
										mem_vec_2939 = vec_402;



										vec_404 = _mm512_fmadd_ps(vec_403, vec_380, mem_vec_2940);
										mem_vec_2940 = vec_404;
										scal_129 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 2) + c];
										vec_406 = _mm512_set1_ps(scal_129);


										vec_405 = _mm512_fmadd_ps(vec_406, vec_378, mem_vec_2941);
										mem_vec_2941 = vec_405;



										vec_407 = _mm512_fmadd_ps(vec_406, vec_380, mem_vec_2942);
										mem_vec_2942 = vec_407;
										scal_130 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 2) + c];
										vec_409 = _mm512_set1_ps(scal_130);


										vec_408 = _mm512_fmadd_ps(vec_409, vec_378, mem_vec_2943);
										mem_vec_2943 = vec_408;



										vec_410 = _mm512_fmadd_ps(vec_409, vec_380, mem_vec_2944);
										mem_vec_2944 = vec_410;
										scal_131 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h + 2) + c];
										vec_412 = _mm512_set1_ps(scal_131);


										vec_411 = _mm512_fmadd_ps(vec_412, vec_378, mem_vec_2945);
										mem_vec_2945 = vec_411;



										vec_413 = _mm512_fmadd_ps(vec_412, vec_380, mem_vec_2946);
										mem_vec_2946 = vec_413;
										scal_132 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 12 + h + 2) + c];
										vec_415 = _mm512_set1_ps(scal_132);


										vec_414 = _mm512_fmadd_ps(vec_415, vec_378, mem_vec_2947);
										mem_vec_2947 = vec_414;



										vec_416 = _mm512_fmadd_ps(vec_415, vec_380, mem_vec_2948);
										mem_vec_2948 = vec_416;
										scal_133 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 13 + h + 2) + c];
										vec_418 = _mm512_set1_ps(scal_133);


										vec_417 = _mm512_fmadd_ps(vec_418, vec_378, mem_vec_2949);
										mem_vec_2949 = vec_417;



										vec_419 = _mm512_fmadd_ps(vec_418, vec_380, mem_vec_2950);
										mem_vec_2950 = vec_419;
										scal_134 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 14 + h + 2) + c];
										vec_421 = _mm512_set1_ps(scal_134);


										vec_420 = _mm512_fmadd_ps(vec_421, vec_378, mem_vec_2951);
										mem_vec_2951 = vec_420;



										vec_422 = _mm512_fmadd_ps(vec_421, vec_380, mem_vec_2952);
										mem_vec_2952 = vec_422;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2923);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2924);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2925);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2926);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2927);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2928);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2929);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2930);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2931);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2932);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2933);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2934);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2935);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2936);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2937);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2938);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2939);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2940);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2941);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2942);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2943);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2944);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2945);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_2946);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_2947);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_2948);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_2949);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_2950);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_2951);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_2952);
						}
					}
				}
		}
	}
}


}