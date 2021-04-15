#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); U (3, w); T (256, c); Hoist_vars [c];
  T (34, x); T (1, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 10)); ((Iter 2), (Arg 12))]; T (16, f);
  T (1, c); T (1, f)]
*/
IND_TYPE c, cp_0, c1276_p_0, cp_1, c1276, f, fp_0, f1208_p_0, f1209_p_0, fp_1, f1208_p_1, fp_2, f1208, f1209, x, xp_0, x1276_p_0, xp_1, x1276, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y752 = 0;
IND_TYPE x1277 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1277 = 0;
IND_TYPE f1210 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_100 ,scal_101 ,scal_102 ,scal_103 ,scal_104 ,scal_105 ,scal_106 ,scal_107 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_45 ,scal_46 ,scal_47 ,scal_48 ,scal_49 ,scal_5 ,scal_50 ,scal_51 ,scal_52 ,scal_53 ,scal_54 ,scal_55 ,scal_56 ,scal_57 ,scal_58 ,scal_59 ,scal_6 ,scal_60 ,scal_61 ,scal_62 ,scal_63 ,scal_64 ,scal_65 ,scal_66 ,scal_67 ,scal_68 ,scal_69 ,scal_7 ,scal_70 ,scal_71 ,scal_72 ,scal_73 ,scal_74 ,scal_75 ,scal_76 ,scal_77 ,scal_78 ,scal_79 ,scal_8 ,scal_80 ,scal_81 ,scal_82 ,scal_83 ,scal_84 ,scal_85 ,scal_86 ,scal_87 ,scal_88 ,scal_89 ,scal_9 ,scal_90 ,scal_91 ,scal_92 ,scal_93 ,scal_94 ,scal_95 ,scal_96 ,scal_97 ,scal_98 ,scal_99;
__m512 mem_vec_10626 ,mem_vec_10627 ,mem_vec_10628 ,mem_vec_10629 ,mem_vec_10630 ,mem_vec_10631 ,mem_vec_10632 ,mem_vec_10633 ,mem_vec_10634 ,mem_vec_10635 ,mem_vec_10636 ,mem_vec_10637 ,mem_vec_10638 ,mem_vec_10639 ,mem_vec_10640 ,mem_vec_10641 ,mem_vec_10642 ,mem_vec_10643 ,mem_vec_10644 ,mem_vec_10645 ,mem_vec_10646 ,mem_vec_10647 ,mem_vec_10648 ,mem_vec_10649 ,mem_vec_10650 ,mem_vec_10651 ,mem_vec_10652 ,mem_vec_10653 ,mem_vec_10654 ,mem_vec_10655 ,mem_vec_10656 ,mem_vec_10657 ,mem_vec_10658 ,mem_vec_10659 ,mem_vec_10660 ,mem_vec_10661 ,mem_vec_10662 ,mem_vec_10663 ,mem_vec_10664 ,mem_vec_10665 ,mem_vec_10666 ,mem_vec_10667 ,mem_vec_10668 ,mem_vec_10669 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_132 ,vec_133 ,vec_134 ,vec_135 ,vec_136 ,vec_137 ,vec_138 ,vec_139 ,vec_14 ,vec_140 ,vec_141 ,vec_142 ,vec_143 ,vec_144 ,vec_145 ,vec_146 ,vec_147 ,vec_148 ,vec_149 ,vec_15 ,vec_150 ,vec_151 ,vec_152 ,vec_153 ,vec_154 ,vec_155 ,vec_156 ,vec_157 ,vec_158 ,vec_159 ,vec_16 ,vec_160 ,vec_161 ,vec_162 ,vec_163 ,vec_164 ,vec_165 ,vec_166 ,vec_167 ,vec_168 ,vec_169 ,vec_17 ,vec_170 ,vec_171 ,vec_172 ,vec_173 ,vec_174 ,vec_175 ,vec_176 ,vec_177 ,vec_178 ,vec_179 ,vec_18 ,vec_180 ,vec_181 ,vec_182 ,vec_183 ,vec_184 ,vec_185 ,vec_186 ,vec_187 ,vec_188 ,vec_189 ,vec_19 ,vec_190 ,vec_191 ,vec_192 ,vec_193 ,vec_194 ,vec_195 ,vec_196 ,vec_197 ,vec_198 ,vec_199 ,vec_2 ,vec_20 ,vec_200 ,vec_201 ,vec_202 ,vec_203 ,vec_204 ,vec_205 ,vec_206 ,vec_207 ,vec_208 ,vec_209 ,vec_21 ,vec_210 ,vec_211 ,vec_212 ,vec_213 ,vec_214 ,vec_215 ,vec_216 ,vec_217 ,vec_218 ,vec_219 ,vec_22 ,vec_220 ,vec_221 ,vec_222 ,vec_223 ,vec_224 ,vec_225 ,vec_226 ,vec_227 ,vec_228 ,vec_229 ,vec_23 ,vec_230 ,vec_231 ,vec_232 ,vec_233 ,vec_234 ,vec_235 ,vec_236 ,vec_237 ,vec_238 ,vec_239 ,vec_24 ,vec_240 ,vec_241 ,vec_242 ,vec_243 ,vec_244 ,vec_245 ,vec_246 ,vec_247 ,vec_248 ,vec_249 ,vec_25 ,vec_250 ,vec_251 ,vec_252 ,vec_253 ,vec_254 ,vec_255 ,vec_256 ,vec_257 ,vec_258 ,vec_259 ,vec_26 ,vec_260 ,vec_261 ,vec_262 ,vec_263 ,vec_264 ,vec_265 ,vec_266 ,vec_267 ,vec_268 ,vec_269 ,vec_27 ,vec_270 ,vec_271 ,vec_272 ,vec_273 ,vec_274 ,vec_275 ,vec_276 ,vec_277 ,vec_278 ,vec_279 ,vec_28 ,vec_280 ,vec_281 ,vec_282 ,vec_283 ,vec_284 ,vec_285 ,vec_286 ,vec_287 ,vec_288 ,vec_289 ,vec_29 ,vec_290 ,vec_291 ,vec_292 ,vec_293 ,vec_294 ,vec_295 ,vec_296 ,vec_297 ,vec_298 ,vec_299 ,vec_3 ,vec_30 ,vec_300 ,vec_301 ,vec_302 ,vec_303 ,vec_304 ,vec_305 ,vec_306 ,vec_307 ,vec_308 ,vec_309 ,vec_31 ,vec_310 ,vec_311 ,vec_312 ,vec_313 ,vec_314 ,vec_315 ,vec_316 ,vec_317 ,vec_318 ,vec_319 ,vec_32 ,vec_320 ,vec_321 ,vec_322 ,vec_323 ,vec_324 ,vec_325 ,vec_326 ,vec_327 ,vec_328 ,vec_329 ,vec_33 ,vec_330 ,vec_331 ,vec_332 ,vec_333 ,vec_334 ,vec_335 ,vec_336 ,vec_337 ,vec_338 ,vec_339 ,vec_34 ,vec_340 ,vec_341 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f1209 = f1210, f1209_p_0 = 0;
	f1209 < f1210 + 512;
	f1209 += 512, f1209_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 1) (256 / 256)
	for (c1276 = c1277, c1276_p_0 = 0;
		c1276 < c1277 + 256;
		c1276 += 256, c1276_p_0 += 256){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
		// T (f, 16) (512 / 32)
		for (f1208 = f1209, f1208_p_1 = f1209_p_0, f1208_p_0 = 0;
			f1208 < f1209 + 512;
			f1208 += 32, f1208_p_1 += 32, f1208_p_0 += 32){
				for (y = y752, yp_0 = 0;
					y < y752 + 10;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (x, 1) (34 / 34)
					for (x1276 = x1277, x1276_p_0 = 0;
						x1276 < x1277 + 34;
						x1276 += 34, x1276_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
						// T (f, 1) (32 / 32)
						for (f = f1208, fp_2 = f1208_p_1, fp_1 = f1208_p_0, fp_0 = 0;
							f < f1208 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
							// T (x, 34) (34 / 1)
							for (x = x1276, xp_1 = x1276_p_0, xp_0 = 0;
								x < x1276 + 34;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10626 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10627 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_10635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_10636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_10637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_10638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_10639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_10640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_10641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_10642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_10643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_10644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_10645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c1276, cp_1 = c1276_p_0, cp_0 = 0;
											c < c1276 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10626);
											mem_vec_10626 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10627);
											mem_vec_10627 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10628);
											mem_vec_10628 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10629);
											mem_vec_10629 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10630);
											mem_vec_10630 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10631);
											mem_vec_10631 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10632);
											mem_vec_10632 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10633);
											mem_vec_10633 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10634);
											mem_vec_10634 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10635);
											mem_vec_10635 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10636);
											mem_vec_10636 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10637);
											mem_vec_10637 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10638);
											mem_vec_10638 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10639);
											mem_vec_10639 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10640);
											mem_vec_10640 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10641);
											mem_vec_10641 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10642);
											mem_vec_10642 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10643);
											mem_vec_10643 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10644);
											mem_vec_10644 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10645);
											mem_vec_10645 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_10626);
											mem_vec_10626 = vec_32;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_10627);
											mem_vec_10627 = vec_35;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_10628);
											mem_vec_10628 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_10629);
											mem_vec_10629 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_10630);
											mem_vec_10630 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_10631);
											mem_vec_10631 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_10632);
											mem_vec_10632 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_10633);
											mem_vec_10633 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_10634);
											mem_vec_10634 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_10635);
											mem_vec_10635 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_10636);
											mem_vec_10636 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_10637);
											mem_vec_10637 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_10638);
											mem_vec_10638 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_10639);
											mem_vec_10639 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_10640);
											mem_vec_10640 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_10641);
											mem_vec_10641 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_10642);
											mem_vec_10642 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_10643);
											mem_vec_10643 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_10644);
											mem_vec_10644 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_10645);
											mem_vec_10645 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_65 = _mm512_set1_ps(scal_20);
											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_10626);
											mem_vec_10626 = vec_64;

											vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_10627);
											mem_vec_10627 = vec_67;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_10628);
											mem_vec_10628 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_10629);
											mem_vec_10629 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_10630);
											mem_vec_10630 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_10631);
											mem_vec_10631 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_10632);
											mem_vec_10632 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_10633);
											mem_vec_10633 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_10634);
											mem_vec_10634 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_10635);
											mem_vec_10635 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_10636);
											mem_vec_10636 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_10637);
											mem_vec_10637 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_10638);
											mem_vec_10638 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_10639);
											mem_vec_10639 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_10640);
											mem_vec_10640 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_10641);
											mem_vec_10641 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_10642);
											mem_vec_10642 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_10643);
											mem_vec_10643 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_10644);
											mem_vec_10644 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_10645);
											mem_vec_10645 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_97 = _mm512_set1_ps(scal_30);
											vec_98 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_96 = _mm512_fmadd_ps(vec_97, vec_98, mem_vec_10626);
											mem_vec_10626 = vec_96;

											vec_100 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_99 = _mm512_fmadd_ps(vec_97, vec_100, mem_vec_10627);
											mem_vec_10627 = vec_99;
											scal_31 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_102 = _mm512_set1_ps(scal_31);


											vec_101 = _mm512_fmadd_ps(vec_102, vec_98, mem_vec_10628);
											mem_vec_10628 = vec_101;



											vec_103 = _mm512_fmadd_ps(vec_102, vec_100, mem_vec_10629);
											mem_vec_10629 = vec_103;
											scal_32 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_105 = _mm512_set1_ps(scal_32);


											vec_104 = _mm512_fmadd_ps(vec_105, vec_98, mem_vec_10630);
											mem_vec_10630 = vec_104;



											vec_106 = _mm512_fmadd_ps(vec_105, vec_100, mem_vec_10631);
											mem_vec_10631 = vec_106;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_108 = _mm512_set1_ps(scal_33);


											vec_107 = _mm512_fmadd_ps(vec_108, vec_98, mem_vec_10632);
											mem_vec_10632 = vec_107;



											vec_109 = _mm512_fmadd_ps(vec_108, vec_100, mem_vec_10633);
											mem_vec_10633 = vec_109;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_111 = _mm512_set1_ps(scal_34);


											vec_110 = _mm512_fmadd_ps(vec_111, vec_98, mem_vec_10634);
											mem_vec_10634 = vec_110;



											vec_112 = _mm512_fmadd_ps(vec_111, vec_100, mem_vec_10635);
											mem_vec_10635 = vec_112;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_114 = _mm512_set1_ps(scal_35);


											vec_113 = _mm512_fmadd_ps(vec_114, vec_98, mem_vec_10636);
											mem_vec_10636 = vec_113;



											vec_115 = _mm512_fmadd_ps(vec_114, vec_100, mem_vec_10637);
											mem_vec_10637 = vec_115;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_117 = _mm512_set1_ps(scal_36);


											vec_116 = _mm512_fmadd_ps(vec_117, vec_98, mem_vec_10638);
											mem_vec_10638 = vec_116;



											vec_118 = _mm512_fmadd_ps(vec_117, vec_100, mem_vec_10639);
											mem_vec_10639 = vec_118;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
											vec_120 = _mm512_set1_ps(scal_37);


											vec_119 = _mm512_fmadd_ps(vec_120, vec_98, mem_vec_10640);
											mem_vec_10640 = vec_119;



											vec_121 = _mm512_fmadd_ps(vec_120, vec_100, mem_vec_10641);
											mem_vec_10641 = vec_121;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
											vec_123 = _mm512_set1_ps(scal_38);


											vec_122 = _mm512_fmadd_ps(vec_123, vec_98, mem_vec_10642);
											mem_vec_10642 = vec_122;



											vec_124 = _mm512_fmadd_ps(vec_123, vec_100, mem_vec_10643);
											mem_vec_10643 = vec_124;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
											vec_126 = _mm512_set1_ps(scal_39);


											vec_125 = _mm512_fmadd_ps(vec_126, vec_98, mem_vec_10644);
											mem_vec_10644 = vec_125;



											vec_127 = _mm512_fmadd_ps(vec_126, vec_100, mem_vec_10645);
											mem_vec_10645 = vec_127;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_129 = _mm512_set1_ps(scal_40);
											vec_130 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_128 = _mm512_fmadd_ps(vec_129, vec_130, mem_vec_10626);
											mem_vec_10626 = vec_128;

											vec_132 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_131 = _mm512_fmadd_ps(vec_129, vec_132, mem_vec_10627);
											mem_vec_10627 = vec_131;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_134 = _mm512_set1_ps(scal_41);


											vec_133 = _mm512_fmadd_ps(vec_134, vec_130, mem_vec_10628);
											mem_vec_10628 = vec_133;



											vec_135 = _mm512_fmadd_ps(vec_134, vec_132, mem_vec_10629);
											mem_vec_10629 = vec_135;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_137 = _mm512_set1_ps(scal_42);


											vec_136 = _mm512_fmadd_ps(vec_137, vec_130, mem_vec_10630);
											mem_vec_10630 = vec_136;



											vec_138 = _mm512_fmadd_ps(vec_137, vec_132, mem_vec_10631);
											mem_vec_10631 = vec_138;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_140 = _mm512_set1_ps(scal_43);


											vec_139 = _mm512_fmadd_ps(vec_140, vec_130, mem_vec_10632);
											mem_vec_10632 = vec_139;



											vec_141 = _mm512_fmadd_ps(vec_140, vec_132, mem_vec_10633);
											mem_vec_10633 = vec_141;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_143 = _mm512_set1_ps(scal_44);


											vec_142 = _mm512_fmadd_ps(vec_143, vec_130, mem_vec_10634);
											mem_vec_10634 = vec_142;



											vec_144 = _mm512_fmadd_ps(vec_143, vec_132, mem_vec_10635);
											mem_vec_10635 = vec_144;
											scal_45 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
											vec_146 = _mm512_set1_ps(scal_45);


											vec_145 = _mm512_fmadd_ps(vec_146, vec_130, mem_vec_10636);
											mem_vec_10636 = vec_145;



											vec_147 = _mm512_fmadd_ps(vec_146, vec_132, mem_vec_10637);
											mem_vec_10637 = vec_147;
											scal_46 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
											vec_149 = _mm512_set1_ps(scal_46);


											vec_148 = _mm512_fmadd_ps(vec_149, vec_130, mem_vec_10638);
											mem_vec_10638 = vec_148;



											vec_150 = _mm512_fmadd_ps(vec_149, vec_132, mem_vec_10639);
											mem_vec_10639 = vec_150;
											scal_47 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 1) + c];
											vec_152 = _mm512_set1_ps(scal_47);


											vec_151 = _mm512_fmadd_ps(vec_152, vec_130, mem_vec_10640);
											mem_vec_10640 = vec_151;



											vec_153 = _mm512_fmadd_ps(vec_152, vec_132, mem_vec_10641);
											mem_vec_10641 = vec_153;
											scal_48 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 1) + c];
											vec_155 = _mm512_set1_ps(scal_48);


											vec_154 = _mm512_fmadd_ps(vec_155, vec_130, mem_vec_10642);
											mem_vec_10642 = vec_154;



											vec_156 = _mm512_fmadd_ps(vec_155, vec_132, mem_vec_10643);
											mem_vec_10643 = vec_156;
											scal_49 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 1) + c];
											vec_158 = _mm512_set1_ps(scal_49);


											vec_157 = _mm512_fmadd_ps(vec_158, vec_130, mem_vec_10644);
											mem_vec_10644 = vec_157;



											vec_159 = _mm512_fmadd_ps(vec_158, vec_132, mem_vec_10645);
											mem_vec_10645 = vec_159;
											scal_50 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_161 = _mm512_set1_ps(scal_50);
											vec_162 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_160 = _mm512_fmadd_ps(vec_161, vec_162, mem_vec_10626);
											mem_vec_10626 = vec_160;

											vec_164 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_163 = _mm512_fmadd_ps(vec_161, vec_164, mem_vec_10627);
											mem_vec_10627 = vec_163;
											scal_51 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_166 = _mm512_set1_ps(scal_51);


											vec_165 = _mm512_fmadd_ps(vec_166, vec_162, mem_vec_10628);
											mem_vec_10628 = vec_165;



											vec_167 = _mm512_fmadd_ps(vec_166, vec_164, mem_vec_10629);
											mem_vec_10629 = vec_167;
											scal_52 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_169 = _mm512_set1_ps(scal_52);


											vec_168 = _mm512_fmadd_ps(vec_169, vec_162, mem_vec_10630);
											mem_vec_10630 = vec_168;



											vec_170 = _mm512_fmadd_ps(vec_169, vec_164, mem_vec_10631);
											mem_vec_10631 = vec_170;
											scal_53 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_172 = _mm512_set1_ps(scal_53);


											vec_171 = _mm512_fmadd_ps(vec_172, vec_162, mem_vec_10632);
											mem_vec_10632 = vec_171;



											vec_173 = _mm512_fmadd_ps(vec_172, vec_164, mem_vec_10633);
											mem_vec_10633 = vec_173;
											scal_54 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_175 = _mm512_set1_ps(scal_54);


											vec_174 = _mm512_fmadd_ps(vec_175, vec_162, mem_vec_10634);
											mem_vec_10634 = vec_174;



											vec_176 = _mm512_fmadd_ps(vec_175, vec_164, mem_vec_10635);
											mem_vec_10635 = vec_176;
											scal_55 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
											vec_178 = _mm512_set1_ps(scal_55);


											vec_177 = _mm512_fmadd_ps(vec_178, vec_162, mem_vec_10636);
											mem_vec_10636 = vec_177;



											vec_179 = _mm512_fmadd_ps(vec_178, vec_164, mem_vec_10637);
											mem_vec_10637 = vec_179;
											scal_56 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
											vec_181 = _mm512_set1_ps(scal_56);


											vec_180 = _mm512_fmadd_ps(vec_181, vec_162, mem_vec_10638);
											mem_vec_10638 = vec_180;



											vec_182 = _mm512_fmadd_ps(vec_181, vec_164, mem_vec_10639);
											mem_vec_10639 = vec_182;
											scal_57 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 2) + c];
											vec_184 = _mm512_set1_ps(scal_57);


											vec_183 = _mm512_fmadd_ps(vec_184, vec_162, mem_vec_10640);
											mem_vec_10640 = vec_183;



											vec_185 = _mm512_fmadd_ps(vec_184, vec_164, mem_vec_10641);
											mem_vec_10641 = vec_185;
											scal_58 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 2) + c];
											vec_187 = _mm512_set1_ps(scal_58);


											vec_186 = _mm512_fmadd_ps(vec_187, vec_162, mem_vec_10642);
											mem_vec_10642 = vec_186;



											vec_188 = _mm512_fmadd_ps(vec_187, vec_164, mem_vec_10643);
											mem_vec_10643 = vec_188;
											scal_59 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 2) + c];
											vec_190 = _mm512_set1_ps(scal_59);


											vec_189 = _mm512_fmadd_ps(vec_190, vec_162, mem_vec_10644);
											mem_vec_10644 = vec_189;



											vec_191 = _mm512_fmadd_ps(vec_190, vec_164, mem_vec_10645);
											mem_vec_10645 = vec_191;
											scal_60 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_193 = _mm512_set1_ps(scal_60);
											vec_194 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_192 = _mm512_fmadd_ps(vec_193, vec_194, mem_vec_10626);
											mem_vec_10626 = vec_192;

											vec_196 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_195 = _mm512_fmadd_ps(vec_193, vec_196, mem_vec_10627);
											mem_vec_10627 = vec_195;
											scal_61 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_198 = _mm512_set1_ps(scal_61);


											vec_197 = _mm512_fmadd_ps(vec_198, vec_194, mem_vec_10628);
											mem_vec_10628 = vec_197;



											vec_199 = _mm512_fmadd_ps(vec_198, vec_196, mem_vec_10629);
											mem_vec_10629 = vec_199;
											scal_62 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_201 = _mm512_set1_ps(scal_62);


											vec_200 = _mm512_fmadd_ps(vec_201, vec_194, mem_vec_10630);
											mem_vec_10630 = vec_200;



											vec_202 = _mm512_fmadd_ps(vec_201, vec_196, mem_vec_10631);
											mem_vec_10631 = vec_202;
											scal_63 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_204 = _mm512_set1_ps(scal_63);


											vec_203 = _mm512_fmadd_ps(vec_204, vec_194, mem_vec_10632);
											mem_vec_10632 = vec_203;



											vec_205 = _mm512_fmadd_ps(vec_204, vec_196, mem_vec_10633);
											mem_vec_10633 = vec_205;
											scal_64 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_207 = _mm512_set1_ps(scal_64);


											vec_206 = _mm512_fmadd_ps(vec_207, vec_194, mem_vec_10634);
											mem_vec_10634 = vec_206;



											vec_208 = _mm512_fmadd_ps(vec_207, vec_196, mem_vec_10635);
											mem_vec_10635 = vec_208;
											scal_65 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_210 = _mm512_set1_ps(scal_65);


											vec_209 = _mm512_fmadd_ps(vec_210, vec_194, mem_vec_10636);
											mem_vec_10636 = vec_209;



											vec_211 = _mm512_fmadd_ps(vec_210, vec_196, mem_vec_10637);
											mem_vec_10637 = vec_211;
											scal_66 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_213 = _mm512_set1_ps(scal_66);


											vec_212 = _mm512_fmadd_ps(vec_213, vec_194, mem_vec_10638);
											mem_vec_10638 = vec_212;



											vec_214 = _mm512_fmadd_ps(vec_213, vec_196, mem_vec_10639);
											mem_vec_10639 = vec_214;
											scal_67 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
											vec_216 = _mm512_set1_ps(scal_67);


											vec_215 = _mm512_fmadd_ps(vec_216, vec_194, mem_vec_10640);
											mem_vec_10640 = vec_215;



											vec_217 = _mm512_fmadd_ps(vec_216, vec_196, mem_vec_10641);
											mem_vec_10641 = vec_217;
											scal_68 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
											vec_219 = _mm512_set1_ps(scal_68);


											vec_218 = _mm512_fmadd_ps(vec_219, vec_194, mem_vec_10642);
											mem_vec_10642 = vec_218;



											vec_220 = _mm512_fmadd_ps(vec_219, vec_196, mem_vec_10643);
											mem_vec_10643 = vec_220;
											scal_69 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
											vec_222 = _mm512_set1_ps(scal_69);


											vec_221 = _mm512_fmadd_ps(vec_222, vec_194, mem_vec_10644);
											mem_vec_10644 = vec_221;



											vec_223 = _mm512_fmadd_ps(vec_222, vec_196, mem_vec_10645);
											mem_vec_10645 = vec_223;
											scal_70 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_225 = _mm512_set1_ps(scal_70);
											vec_226 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_224 = _mm512_fmadd_ps(vec_225, vec_226, mem_vec_10626);
											mem_vec_10626 = vec_224;

											vec_228 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_227 = _mm512_fmadd_ps(vec_225, vec_228, mem_vec_10627);
											mem_vec_10627 = vec_227;
											scal_71 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_230 = _mm512_set1_ps(scal_71);


											vec_229 = _mm512_fmadd_ps(vec_230, vec_226, mem_vec_10628);
											mem_vec_10628 = vec_229;



											vec_231 = _mm512_fmadd_ps(vec_230, vec_228, mem_vec_10629);
											mem_vec_10629 = vec_231;
											scal_72 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_233 = _mm512_set1_ps(scal_72);


											vec_232 = _mm512_fmadd_ps(vec_233, vec_226, mem_vec_10630);
											mem_vec_10630 = vec_232;



											vec_234 = _mm512_fmadd_ps(vec_233, vec_228, mem_vec_10631);
											mem_vec_10631 = vec_234;
											scal_73 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_236 = _mm512_set1_ps(scal_73);


											vec_235 = _mm512_fmadd_ps(vec_236, vec_226, mem_vec_10632);
											mem_vec_10632 = vec_235;



											vec_237 = _mm512_fmadd_ps(vec_236, vec_228, mem_vec_10633);
											mem_vec_10633 = vec_237;
											scal_74 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_239 = _mm512_set1_ps(scal_74);


											vec_238 = _mm512_fmadd_ps(vec_239, vec_226, mem_vec_10634);
											mem_vec_10634 = vec_238;



											vec_240 = _mm512_fmadd_ps(vec_239, vec_228, mem_vec_10635);
											mem_vec_10635 = vec_240;
											scal_75 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
											vec_242 = _mm512_set1_ps(scal_75);


											vec_241 = _mm512_fmadd_ps(vec_242, vec_226, mem_vec_10636);
											mem_vec_10636 = vec_241;



											vec_243 = _mm512_fmadd_ps(vec_242, vec_228, mem_vec_10637);
											mem_vec_10637 = vec_243;
											scal_76 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
											vec_245 = _mm512_set1_ps(scal_76);


											vec_244 = _mm512_fmadd_ps(vec_245, vec_226, mem_vec_10638);
											mem_vec_10638 = vec_244;



											vec_246 = _mm512_fmadd_ps(vec_245, vec_228, mem_vec_10639);
											mem_vec_10639 = vec_246;
											scal_77 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 1) + c];
											vec_248 = _mm512_set1_ps(scal_77);


											vec_247 = _mm512_fmadd_ps(vec_248, vec_226, mem_vec_10640);
											mem_vec_10640 = vec_247;



											vec_249 = _mm512_fmadd_ps(vec_248, vec_228, mem_vec_10641);
											mem_vec_10641 = vec_249;
											scal_78 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 1) + c];
											vec_251 = _mm512_set1_ps(scal_78);


											vec_250 = _mm512_fmadd_ps(vec_251, vec_226, mem_vec_10642);
											mem_vec_10642 = vec_250;



											vec_252 = _mm512_fmadd_ps(vec_251, vec_228, mem_vec_10643);
											mem_vec_10643 = vec_252;
											scal_79 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 1) + c];
											vec_254 = _mm512_set1_ps(scal_79);


											vec_253 = _mm512_fmadd_ps(vec_254, vec_226, mem_vec_10644);
											mem_vec_10644 = vec_253;



											vec_255 = _mm512_fmadd_ps(vec_254, vec_228, mem_vec_10645);
											mem_vec_10645 = vec_255;
											scal_80 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_257 = _mm512_set1_ps(scal_80);
											vec_258 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_256 = _mm512_fmadd_ps(vec_257, vec_258, mem_vec_10626);
											mem_vec_10626 = vec_256;

											vec_260 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_259 = _mm512_fmadd_ps(vec_257, vec_260, mem_vec_10627);
											mem_vec_10627 = vec_259;
											scal_81 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_262 = _mm512_set1_ps(scal_81);


											vec_261 = _mm512_fmadd_ps(vec_262, vec_258, mem_vec_10628);
											mem_vec_10628 = vec_261;



											vec_263 = _mm512_fmadd_ps(vec_262, vec_260, mem_vec_10629);
											mem_vec_10629 = vec_263;
											scal_82 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_265 = _mm512_set1_ps(scal_82);


											vec_264 = _mm512_fmadd_ps(vec_265, vec_258, mem_vec_10630);
											mem_vec_10630 = vec_264;



											vec_266 = _mm512_fmadd_ps(vec_265, vec_260, mem_vec_10631);
											mem_vec_10631 = vec_266;
											scal_83 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_268 = _mm512_set1_ps(scal_83);


											vec_267 = _mm512_fmadd_ps(vec_268, vec_258, mem_vec_10632);
											mem_vec_10632 = vec_267;



											vec_269 = _mm512_fmadd_ps(vec_268, vec_260, mem_vec_10633);
											mem_vec_10633 = vec_269;
											scal_84 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_271 = _mm512_set1_ps(scal_84);


											vec_270 = _mm512_fmadd_ps(vec_271, vec_258, mem_vec_10634);
											mem_vec_10634 = vec_270;



											vec_272 = _mm512_fmadd_ps(vec_271, vec_260, mem_vec_10635);
											mem_vec_10635 = vec_272;
											scal_85 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
											vec_274 = _mm512_set1_ps(scal_85);


											vec_273 = _mm512_fmadd_ps(vec_274, vec_258, mem_vec_10636);
											mem_vec_10636 = vec_273;



											vec_275 = _mm512_fmadd_ps(vec_274, vec_260, mem_vec_10637);
											mem_vec_10637 = vec_275;
											scal_86 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
											vec_277 = _mm512_set1_ps(scal_86);


											vec_276 = _mm512_fmadd_ps(vec_277, vec_258, mem_vec_10638);
											mem_vec_10638 = vec_276;



											vec_278 = _mm512_fmadd_ps(vec_277, vec_260, mem_vec_10639);
											mem_vec_10639 = vec_278;
											scal_87 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 2) + c];
											vec_280 = _mm512_set1_ps(scal_87);


											vec_279 = _mm512_fmadd_ps(vec_280, vec_258, mem_vec_10640);
											mem_vec_10640 = vec_279;



											vec_281 = _mm512_fmadd_ps(vec_280, vec_260, mem_vec_10641);
											mem_vec_10641 = vec_281;
											scal_88 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 2) + c];
											vec_283 = _mm512_set1_ps(scal_88);


											vec_282 = _mm512_fmadd_ps(vec_283, vec_258, mem_vec_10642);
											mem_vec_10642 = vec_282;



											vec_284 = _mm512_fmadd_ps(vec_283, vec_260, mem_vec_10643);
											mem_vec_10643 = vec_284;
											scal_89 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 2) + c];
											vec_286 = _mm512_set1_ps(scal_89);


											vec_285 = _mm512_fmadd_ps(vec_286, vec_258, mem_vec_10644);
											mem_vec_10644 = vec_285;



											vec_287 = _mm512_fmadd_ps(vec_286, vec_260, mem_vec_10645);
											mem_vec_10645 = vec_287;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10626);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10627);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10628);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10629);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10630);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10631);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10632);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10633);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10634);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10635);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10636);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10637);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10638);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10639);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10640);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10641);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10642);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10643);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10644);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10645);
							}
						}
					}
				}
				for (y = y752 + 10, yp_0 = 0;
					y < y752 + 10 + 24;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (x, 1) (34 / 34)
					for (x1276 = x1277, x1276_p_0 = 0;
						x1276 < x1277 + 34;
						x1276 += 34, x1276_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
						// T (f, 1) (32 / 32)
						for (f = f1208, fp_2 = f1208_p_1, fp_1 = f1208_p_0, fp_0 = 0;
							f < f1208 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
							// T (x, 34) (34 / 1)
							for (x = x1276, xp_1 = x1276_p_0, xp_0 = 0;
								x < x1276 + 34;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10646 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10647 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_10655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_10656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_10657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_10658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_10659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_10660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_10661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_10662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_10663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_10664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_10665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_10666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_10667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_10668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_10669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c1276, cp_1 = c1276_p_0, cp_0 = 0;
											c < c1276 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10646);
											mem_vec_10646 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10647);
											mem_vec_10647 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10648);
											mem_vec_10648 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10649);
											mem_vec_10649 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10650);
											mem_vec_10650 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10651);
											mem_vec_10651 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10652);
											mem_vec_10652 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10653);
											mem_vec_10653 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10654);
											mem_vec_10654 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10655);
											mem_vec_10655 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10656);
											mem_vec_10656 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10657);
											mem_vec_10657 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10658);
											mem_vec_10658 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10659);
											mem_vec_10659 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10660);
											mem_vec_10660 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10661);
											mem_vec_10661 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10662);
											mem_vec_10662 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10663);
											mem_vec_10663 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10664);
											mem_vec_10664 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10665);
											mem_vec_10665 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10666);
											mem_vec_10666 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10667);
											mem_vec_10667 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_10668);
											mem_vec_10668 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_10669);
											mem_vec_10669 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_12);
											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_10646);
											mem_vec_10646 = vec_38;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_10647);
											mem_vec_10647 = vec_41;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_10648);
											mem_vec_10648 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_10649);
											mem_vec_10649 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_40, mem_vec_10650);
											mem_vec_10650 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_42, mem_vec_10651);
											mem_vec_10651 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_10652);
											mem_vec_10652 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_42, mem_vec_10653);
											mem_vec_10653 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_10654);
											mem_vec_10654 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_10655);
											mem_vec_10655 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_10656);
											mem_vec_10656 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_42, mem_vec_10657);
											mem_vec_10657 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_10658);
											mem_vec_10658 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_10659);
											mem_vec_10659 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_40, mem_vec_10660);
											mem_vec_10660 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_42, mem_vec_10661);
											mem_vec_10661 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_40, mem_vec_10662);
											mem_vec_10662 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_42, mem_vec_10663);
											mem_vec_10663 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_40, mem_vec_10664);
											mem_vec_10664 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_42, mem_vec_10665);
											mem_vec_10665 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_71 = _mm512_set1_ps(scal_22);


											vec_70 = _mm512_fmadd_ps(vec_71, vec_40, mem_vec_10666);
											mem_vec_10666 = vec_70;



											vec_72 = _mm512_fmadd_ps(vec_71, vec_42, mem_vec_10667);
											mem_vec_10667 = vec_72;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
											vec_74 = _mm512_set1_ps(scal_23);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_40, mem_vec_10668);
											mem_vec_10668 = vec_73;



											vec_75 = _mm512_fmadd_ps(vec_74, vec_42, mem_vec_10669);
											mem_vec_10669 = vec_75;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_77 = _mm512_set1_ps(scal_24);
											vec_78 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_76 = _mm512_fmadd_ps(vec_77, vec_78, mem_vec_10646);
											mem_vec_10646 = vec_76;

											vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_79 = _mm512_fmadd_ps(vec_77, vec_80, mem_vec_10647);
											mem_vec_10647 = vec_79;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_78, mem_vec_10648);
											mem_vec_10648 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_80, mem_vec_10649);
											mem_vec_10649 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_78, mem_vec_10650);
											mem_vec_10650 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_80, mem_vec_10651);
											mem_vec_10651 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_10652);
											mem_vec_10652 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_10653);
											mem_vec_10653 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_78, mem_vec_10654);
											mem_vec_10654 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_80, mem_vec_10655);
											mem_vec_10655 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_78, mem_vec_10656);
											mem_vec_10656 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_80, mem_vec_10657);
											mem_vec_10657 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_97 = _mm512_set1_ps(scal_30);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_78, mem_vec_10658);
											mem_vec_10658 = vec_96;



											vec_98 = _mm512_fmadd_ps(vec_97, vec_80, mem_vec_10659);
											mem_vec_10659 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_78, mem_vec_10660);
											mem_vec_10660 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_80, mem_vec_10661);
											mem_vec_10661 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_78, mem_vec_10662);
											mem_vec_10662 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_10663);
											mem_vec_10663 = vec_104;
											scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_106 = _mm512_set1_ps(scal_33);


											vec_105 = _mm512_fmadd_ps(vec_106, vec_78, mem_vec_10664);
											mem_vec_10664 = vec_105;



											vec_107 = _mm512_fmadd_ps(vec_106, vec_80, mem_vec_10665);
											mem_vec_10665 = vec_107;
											scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_109 = _mm512_set1_ps(scal_34);


											vec_108 = _mm512_fmadd_ps(vec_109, vec_78, mem_vec_10666);
											mem_vec_10666 = vec_108;



											vec_110 = _mm512_fmadd_ps(vec_109, vec_80, mem_vec_10667);
											mem_vec_10667 = vec_110;
											scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
											vec_112 = _mm512_set1_ps(scal_35);


											vec_111 = _mm512_fmadd_ps(vec_112, vec_78, mem_vec_10668);
											mem_vec_10668 = vec_111;



											vec_113 = _mm512_fmadd_ps(vec_112, vec_80, mem_vec_10669);
											mem_vec_10669 = vec_113;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_115 = _mm512_set1_ps(scal_36);
											vec_116 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_114 = _mm512_fmadd_ps(vec_115, vec_116, mem_vec_10646);
											mem_vec_10646 = vec_114;

											vec_118 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_117 = _mm512_fmadd_ps(vec_115, vec_118, mem_vec_10647);
											mem_vec_10647 = vec_117;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_120 = _mm512_set1_ps(scal_37);


											vec_119 = _mm512_fmadd_ps(vec_120, vec_116, mem_vec_10648);
											mem_vec_10648 = vec_119;



											vec_121 = _mm512_fmadd_ps(vec_120, vec_118, mem_vec_10649);
											mem_vec_10649 = vec_121;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_123 = _mm512_set1_ps(scal_38);


											vec_122 = _mm512_fmadd_ps(vec_123, vec_116, mem_vec_10650);
											mem_vec_10650 = vec_122;



											vec_124 = _mm512_fmadd_ps(vec_123, vec_118, mem_vec_10651);
											mem_vec_10651 = vec_124;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_126 = _mm512_set1_ps(scal_39);


											vec_125 = _mm512_fmadd_ps(vec_126, vec_116, mem_vec_10652);
											mem_vec_10652 = vec_125;



											vec_127 = _mm512_fmadd_ps(vec_126, vec_118, mem_vec_10653);
											mem_vec_10653 = vec_127;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_129 = _mm512_set1_ps(scal_40);


											vec_128 = _mm512_fmadd_ps(vec_129, vec_116, mem_vec_10654);
											mem_vec_10654 = vec_128;



											vec_130 = _mm512_fmadd_ps(vec_129, vec_118, mem_vec_10655);
											mem_vec_10655 = vec_130;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_132 = _mm512_set1_ps(scal_41);


											vec_131 = _mm512_fmadd_ps(vec_132, vec_116, mem_vec_10656);
											mem_vec_10656 = vec_131;



											vec_133 = _mm512_fmadd_ps(vec_132, vec_118, mem_vec_10657);
											mem_vec_10657 = vec_133;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_135 = _mm512_set1_ps(scal_42);


											vec_134 = _mm512_fmadd_ps(vec_135, vec_116, mem_vec_10658);
											mem_vec_10658 = vec_134;



											vec_136 = _mm512_fmadd_ps(vec_135, vec_118, mem_vec_10659);
											mem_vec_10659 = vec_136;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
											vec_138 = _mm512_set1_ps(scal_43);


											vec_137 = _mm512_fmadd_ps(vec_138, vec_116, mem_vec_10660);
											mem_vec_10660 = vec_137;



											vec_139 = _mm512_fmadd_ps(vec_138, vec_118, mem_vec_10661);
											mem_vec_10661 = vec_139;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
											vec_141 = _mm512_set1_ps(scal_44);


											vec_140 = _mm512_fmadd_ps(vec_141, vec_116, mem_vec_10662);
											mem_vec_10662 = vec_140;



											vec_142 = _mm512_fmadd_ps(vec_141, vec_118, mem_vec_10663);
											mem_vec_10663 = vec_142;
											scal_45 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
											vec_144 = _mm512_set1_ps(scal_45);


											vec_143 = _mm512_fmadd_ps(vec_144, vec_116, mem_vec_10664);
											mem_vec_10664 = vec_143;



											vec_145 = _mm512_fmadd_ps(vec_144, vec_118, mem_vec_10665);
											mem_vec_10665 = vec_145;
											scal_46 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
											vec_147 = _mm512_set1_ps(scal_46);


											vec_146 = _mm512_fmadd_ps(vec_147, vec_116, mem_vec_10666);
											mem_vec_10666 = vec_146;



											vec_148 = _mm512_fmadd_ps(vec_147, vec_118, mem_vec_10667);
											mem_vec_10667 = vec_148;
											scal_47 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h) + c];
											vec_150 = _mm512_set1_ps(scal_47);


											vec_149 = _mm512_fmadd_ps(vec_150, vec_116, mem_vec_10668);
											mem_vec_10668 = vec_149;



											vec_151 = _mm512_fmadd_ps(vec_150, vec_118, mem_vec_10669);
											mem_vec_10669 = vec_151;
											scal_48 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_153 = _mm512_set1_ps(scal_48);
											vec_154 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_152 = _mm512_fmadd_ps(vec_153, vec_154, mem_vec_10646);
											mem_vec_10646 = vec_152;

											vec_156 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_155 = _mm512_fmadd_ps(vec_153, vec_156, mem_vec_10647);
											mem_vec_10647 = vec_155;
											scal_49 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_158 = _mm512_set1_ps(scal_49);


											vec_157 = _mm512_fmadd_ps(vec_158, vec_154, mem_vec_10648);
											mem_vec_10648 = vec_157;



											vec_159 = _mm512_fmadd_ps(vec_158, vec_156, mem_vec_10649);
											mem_vec_10649 = vec_159;
											scal_50 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_161 = _mm512_set1_ps(scal_50);


											vec_160 = _mm512_fmadd_ps(vec_161, vec_154, mem_vec_10650);
											mem_vec_10650 = vec_160;



											vec_162 = _mm512_fmadd_ps(vec_161, vec_156, mem_vec_10651);
											mem_vec_10651 = vec_162;
											scal_51 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_164 = _mm512_set1_ps(scal_51);


											vec_163 = _mm512_fmadd_ps(vec_164, vec_154, mem_vec_10652);
											mem_vec_10652 = vec_163;



											vec_165 = _mm512_fmadd_ps(vec_164, vec_156, mem_vec_10653);
											mem_vec_10653 = vec_165;
											scal_52 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_167 = _mm512_set1_ps(scal_52);


											vec_166 = _mm512_fmadd_ps(vec_167, vec_154, mem_vec_10654);
											mem_vec_10654 = vec_166;



											vec_168 = _mm512_fmadd_ps(vec_167, vec_156, mem_vec_10655);
											mem_vec_10655 = vec_168;
											scal_53 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
											vec_170 = _mm512_set1_ps(scal_53);


											vec_169 = _mm512_fmadd_ps(vec_170, vec_154, mem_vec_10656);
											mem_vec_10656 = vec_169;



											vec_171 = _mm512_fmadd_ps(vec_170, vec_156, mem_vec_10657);
											mem_vec_10657 = vec_171;
											scal_54 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
											vec_173 = _mm512_set1_ps(scal_54);


											vec_172 = _mm512_fmadd_ps(vec_173, vec_154, mem_vec_10658);
											mem_vec_10658 = vec_172;



											vec_174 = _mm512_fmadd_ps(vec_173, vec_156, mem_vec_10659);
											mem_vec_10659 = vec_174;
											scal_55 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 1) + c];
											vec_176 = _mm512_set1_ps(scal_55);


											vec_175 = _mm512_fmadd_ps(vec_176, vec_154, mem_vec_10660);
											mem_vec_10660 = vec_175;



											vec_177 = _mm512_fmadd_ps(vec_176, vec_156, mem_vec_10661);
											mem_vec_10661 = vec_177;
											scal_56 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 1) + c];
											vec_179 = _mm512_set1_ps(scal_56);


											vec_178 = _mm512_fmadd_ps(vec_179, vec_154, mem_vec_10662);
											mem_vec_10662 = vec_178;



											vec_180 = _mm512_fmadd_ps(vec_179, vec_156, mem_vec_10663);
											mem_vec_10663 = vec_180;
											scal_57 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 1) + c];
											vec_182 = _mm512_set1_ps(scal_57);


											vec_181 = _mm512_fmadd_ps(vec_182, vec_154, mem_vec_10664);
											mem_vec_10664 = vec_181;



											vec_183 = _mm512_fmadd_ps(vec_182, vec_156, mem_vec_10665);
											mem_vec_10665 = vec_183;
											scal_58 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 1) + c];
											vec_185 = _mm512_set1_ps(scal_58);


											vec_184 = _mm512_fmadd_ps(vec_185, vec_154, mem_vec_10666);
											mem_vec_10666 = vec_184;



											vec_186 = _mm512_fmadd_ps(vec_185, vec_156, mem_vec_10667);
											mem_vec_10667 = vec_186;
											scal_59 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h + 1) + c];
											vec_188 = _mm512_set1_ps(scal_59);


											vec_187 = _mm512_fmadd_ps(vec_188, vec_154, mem_vec_10668);
											mem_vec_10668 = vec_187;



											vec_189 = _mm512_fmadd_ps(vec_188, vec_156, mem_vec_10669);
											mem_vec_10669 = vec_189;
											scal_60 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_191 = _mm512_set1_ps(scal_60);
											vec_192 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_190 = _mm512_fmadd_ps(vec_191, vec_192, mem_vec_10646);
											mem_vec_10646 = vec_190;

											vec_194 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_193 = _mm512_fmadd_ps(vec_191, vec_194, mem_vec_10647);
											mem_vec_10647 = vec_193;
											scal_61 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_196 = _mm512_set1_ps(scal_61);


											vec_195 = _mm512_fmadd_ps(vec_196, vec_192, mem_vec_10648);
											mem_vec_10648 = vec_195;



											vec_197 = _mm512_fmadd_ps(vec_196, vec_194, mem_vec_10649);
											mem_vec_10649 = vec_197;
											scal_62 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_199 = _mm512_set1_ps(scal_62);


											vec_198 = _mm512_fmadd_ps(vec_199, vec_192, mem_vec_10650);
											mem_vec_10650 = vec_198;



											vec_200 = _mm512_fmadd_ps(vec_199, vec_194, mem_vec_10651);
											mem_vec_10651 = vec_200;
											scal_63 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_202 = _mm512_set1_ps(scal_63);


											vec_201 = _mm512_fmadd_ps(vec_202, vec_192, mem_vec_10652);
											mem_vec_10652 = vec_201;



											vec_203 = _mm512_fmadd_ps(vec_202, vec_194, mem_vec_10653);
											mem_vec_10653 = vec_203;
											scal_64 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_205 = _mm512_set1_ps(scal_64);


											vec_204 = _mm512_fmadd_ps(vec_205, vec_192, mem_vec_10654);
											mem_vec_10654 = vec_204;



											vec_206 = _mm512_fmadd_ps(vec_205, vec_194, mem_vec_10655);
											mem_vec_10655 = vec_206;
											scal_65 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
											vec_208 = _mm512_set1_ps(scal_65);


											vec_207 = _mm512_fmadd_ps(vec_208, vec_192, mem_vec_10656);
											mem_vec_10656 = vec_207;



											vec_209 = _mm512_fmadd_ps(vec_208, vec_194, mem_vec_10657);
											mem_vec_10657 = vec_209;
											scal_66 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
											vec_211 = _mm512_set1_ps(scal_66);


											vec_210 = _mm512_fmadd_ps(vec_211, vec_192, mem_vec_10658);
											mem_vec_10658 = vec_210;



											vec_212 = _mm512_fmadd_ps(vec_211, vec_194, mem_vec_10659);
											mem_vec_10659 = vec_212;
											scal_67 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 2) + c];
											vec_214 = _mm512_set1_ps(scal_67);


											vec_213 = _mm512_fmadd_ps(vec_214, vec_192, mem_vec_10660);
											mem_vec_10660 = vec_213;



											vec_215 = _mm512_fmadd_ps(vec_214, vec_194, mem_vec_10661);
											mem_vec_10661 = vec_215;
											scal_68 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 2) + c];
											vec_217 = _mm512_set1_ps(scal_68);


											vec_216 = _mm512_fmadd_ps(vec_217, vec_192, mem_vec_10662);
											mem_vec_10662 = vec_216;



											vec_218 = _mm512_fmadd_ps(vec_217, vec_194, mem_vec_10663);
											mem_vec_10663 = vec_218;
											scal_69 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 2) + c];
											vec_220 = _mm512_set1_ps(scal_69);


											vec_219 = _mm512_fmadd_ps(vec_220, vec_192, mem_vec_10664);
											mem_vec_10664 = vec_219;



											vec_221 = _mm512_fmadd_ps(vec_220, vec_194, mem_vec_10665);
											mem_vec_10665 = vec_221;
											scal_70 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 2) + c];
											vec_223 = _mm512_set1_ps(scal_70);


											vec_222 = _mm512_fmadd_ps(vec_223, vec_192, mem_vec_10666);
											mem_vec_10666 = vec_222;



											vec_224 = _mm512_fmadd_ps(vec_223, vec_194, mem_vec_10667);
											mem_vec_10667 = vec_224;
											scal_71 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h + 2) + c];
											vec_226 = _mm512_set1_ps(scal_71);


											vec_225 = _mm512_fmadd_ps(vec_226, vec_192, mem_vec_10668);
											mem_vec_10668 = vec_225;



											vec_227 = _mm512_fmadd_ps(vec_226, vec_194, mem_vec_10669);
											mem_vec_10669 = vec_227;
											scal_72 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_229 = _mm512_set1_ps(scal_72);
											vec_230 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_228 = _mm512_fmadd_ps(vec_229, vec_230, mem_vec_10646);
											mem_vec_10646 = vec_228;

											vec_232 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_231 = _mm512_fmadd_ps(vec_229, vec_232, mem_vec_10647);
											mem_vec_10647 = vec_231;
											scal_73 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_234 = _mm512_set1_ps(scal_73);


											vec_233 = _mm512_fmadd_ps(vec_234, vec_230, mem_vec_10648);
											mem_vec_10648 = vec_233;



											vec_235 = _mm512_fmadd_ps(vec_234, vec_232, mem_vec_10649);
											mem_vec_10649 = vec_235;
											scal_74 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_237 = _mm512_set1_ps(scal_74);


											vec_236 = _mm512_fmadd_ps(vec_237, vec_230, mem_vec_10650);
											mem_vec_10650 = vec_236;



											vec_238 = _mm512_fmadd_ps(vec_237, vec_232, mem_vec_10651);
											mem_vec_10651 = vec_238;
											scal_75 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_240 = _mm512_set1_ps(scal_75);


											vec_239 = _mm512_fmadd_ps(vec_240, vec_230, mem_vec_10652);
											mem_vec_10652 = vec_239;



											vec_241 = _mm512_fmadd_ps(vec_240, vec_232, mem_vec_10653);
											mem_vec_10653 = vec_241;
											scal_76 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_243 = _mm512_set1_ps(scal_76);


											vec_242 = _mm512_fmadd_ps(vec_243, vec_230, mem_vec_10654);
											mem_vec_10654 = vec_242;



											vec_244 = _mm512_fmadd_ps(vec_243, vec_232, mem_vec_10655);
											mem_vec_10655 = vec_244;
											scal_77 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_246 = _mm512_set1_ps(scal_77);


											vec_245 = _mm512_fmadd_ps(vec_246, vec_230, mem_vec_10656);
											mem_vec_10656 = vec_245;



											vec_247 = _mm512_fmadd_ps(vec_246, vec_232, mem_vec_10657);
											mem_vec_10657 = vec_247;
											scal_78 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_249 = _mm512_set1_ps(scal_78);


											vec_248 = _mm512_fmadd_ps(vec_249, vec_230, mem_vec_10658);
											mem_vec_10658 = vec_248;



											vec_250 = _mm512_fmadd_ps(vec_249, vec_232, mem_vec_10659);
											mem_vec_10659 = vec_250;
											scal_79 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
											vec_252 = _mm512_set1_ps(scal_79);


											vec_251 = _mm512_fmadd_ps(vec_252, vec_230, mem_vec_10660);
											mem_vec_10660 = vec_251;



											vec_253 = _mm512_fmadd_ps(vec_252, vec_232, mem_vec_10661);
											mem_vec_10661 = vec_253;
											scal_80 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
											vec_255 = _mm512_set1_ps(scal_80);


											vec_254 = _mm512_fmadd_ps(vec_255, vec_230, mem_vec_10662);
											mem_vec_10662 = vec_254;



											vec_256 = _mm512_fmadd_ps(vec_255, vec_232, mem_vec_10663);
											mem_vec_10663 = vec_256;
											scal_81 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
											vec_258 = _mm512_set1_ps(scal_81);


											vec_257 = _mm512_fmadd_ps(vec_258, vec_230, mem_vec_10664);
											mem_vec_10664 = vec_257;



											vec_259 = _mm512_fmadd_ps(vec_258, vec_232, mem_vec_10665);
											mem_vec_10665 = vec_259;
											scal_82 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
											vec_261 = _mm512_set1_ps(scal_82);


											vec_260 = _mm512_fmadd_ps(vec_261, vec_230, mem_vec_10666);
											mem_vec_10666 = vec_260;



											vec_262 = _mm512_fmadd_ps(vec_261, vec_232, mem_vec_10667);
											mem_vec_10667 = vec_262;
											scal_83 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h) + c];
											vec_264 = _mm512_set1_ps(scal_83);


											vec_263 = _mm512_fmadd_ps(vec_264, vec_230, mem_vec_10668);
											mem_vec_10668 = vec_263;



											vec_265 = _mm512_fmadd_ps(vec_264, vec_232, mem_vec_10669);
											mem_vec_10669 = vec_265;
											scal_84 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_267 = _mm512_set1_ps(scal_84);
											vec_268 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_266 = _mm512_fmadd_ps(vec_267, vec_268, mem_vec_10646);
											mem_vec_10646 = vec_266;

											vec_270 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_269 = _mm512_fmadd_ps(vec_267, vec_270, mem_vec_10647);
											mem_vec_10647 = vec_269;
											scal_85 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_272 = _mm512_set1_ps(scal_85);


											vec_271 = _mm512_fmadd_ps(vec_272, vec_268, mem_vec_10648);
											mem_vec_10648 = vec_271;



											vec_273 = _mm512_fmadd_ps(vec_272, vec_270, mem_vec_10649);
											mem_vec_10649 = vec_273;
											scal_86 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_275 = _mm512_set1_ps(scal_86);


											vec_274 = _mm512_fmadd_ps(vec_275, vec_268, mem_vec_10650);
											mem_vec_10650 = vec_274;



											vec_276 = _mm512_fmadd_ps(vec_275, vec_270, mem_vec_10651);
											mem_vec_10651 = vec_276;
											scal_87 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_278 = _mm512_set1_ps(scal_87);


											vec_277 = _mm512_fmadd_ps(vec_278, vec_268, mem_vec_10652);
											mem_vec_10652 = vec_277;



											vec_279 = _mm512_fmadd_ps(vec_278, vec_270, mem_vec_10653);
											mem_vec_10653 = vec_279;
											scal_88 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_281 = _mm512_set1_ps(scal_88);


											vec_280 = _mm512_fmadd_ps(vec_281, vec_268, mem_vec_10654);
											mem_vec_10654 = vec_280;



											vec_282 = _mm512_fmadd_ps(vec_281, vec_270, mem_vec_10655);
											mem_vec_10655 = vec_282;
											scal_89 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
											vec_284 = _mm512_set1_ps(scal_89);


											vec_283 = _mm512_fmadd_ps(vec_284, vec_268, mem_vec_10656);
											mem_vec_10656 = vec_283;



											vec_285 = _mm512_fmadd_ps(vec_284, vec_270, mem_vec_10657);
											mem_vec_10657 = vec_285;
											scal_90 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
											vec_287 = _mm512_set1_ps(scal_90);


											vec_286 = _mm512_fmadd_ps(vec_287, vec_268, mem_vec_10658);
											mem_vec_10658 = vec_286;



											vec_288 = _mm512_fmadd_ps(vec_287, vec_270, mem_vec_10659);
											mem_vec_10659 = vec_288;
											scal_91 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 1) + c];
											vec_290 = _mm512_set1_ps(scal_91);


											vec_289 = _mm512_fmadd_ps(vec_290, vec_268, mem_vec_10660);
											mem_vec_10660 = vec_289;



											vec_291 = _mm512_fmadd_ps(vec_290, vec_270, mem_vec_10661);
											mem_vec_10661 = vec_291;
											scal_92 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 1) + c];
											vec_293 = _mm512_set1_ps(scal_92);


											vec_292 = _mm512_fmadd_ps(vec_293, vec_268, mem_vec_10662);
											mem_vec_10662 = vec_292;



											vec_294 = _mm512_fmadd_ps(vec_293, vec_270, mem_vec_10663);
											mem_vec_10663 = vec_294;
											scal_93 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 1) + c];
											vec_296 = _mm512_set1_ps(scal_93);


											vec_295 = _mm512_fmadd_ps(vec_296, vec_268, mem_vec_10664);
											mem_vec_10664 = vec_295;



											vec_297 = _mm512_fmadd_ps(vec_296, vec_270, mem_vec_10665);
											mem_vec_10665 = vec_297;
											scal_94 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 1) + c];
											vec_299 = _mm512_set1_ps(scal_94);


											vec_298 = _mm512_fmadd_ps(vec_299, vec_268, mem_vec_10666);
											mem_vec_10666 = vec_298;



											vec_300 = _mm512_fmadd_ps(vec_299, vec_270, mem_vec_10667);
											mem_vec_10667 = vec_300;
											scal_95 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h + 1) + c];
											vec_302 = _mm512_set1_ps(scal_95);


											vec_301 = _mm512_fmadd_ps(vec_302, vec_268, mem_vec_10668);
											mem_vec_10668 = vec_301;



											vec_303 = _mm512_fmadd_ps(vec_302, vec_270, mem_vec_10669);
											mem_vec_10669 = vec_303;
											scal_96 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_305 = _mm512_set1_ps(scal_96);
											vec_306 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_304 = _mm512_fmadd_ps(vec_305, vec_306, mem_vec_10646);
											mem_vec_10646 = vec_304;

											vec_308 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_307 = _mm512_fmadd_ps(vec_305, vec_308, mem_vec_10647);
											mem_vec_10647 = vec_307;
											scal_97 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_310 = _mm512_set1_ps(scal_97);


											vec_309 = _mm512_fmadd_ps(vec_310, vec_306, mem_vec_10648);
											mem_vec_10648 = vec_309;



											vec_311 = _mm512_fmadd_ps(vec_310, vec_308, mem_vec_10649);
											mem_vec_10649 = vec_311;
											scal_98 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_313 = _mm512_set1_ps(scal_98);


											vec_312 = _mm512_fmadd_ps(vec_313, vec_306, mem_vec_10650);
											mem_vec_10650 = vec_312;



											vec_314 = _mm512_fmadd_ps(vec_313, vec_308, mem_vec_10651);
											mem_vec_10651 = vec_314;
											scal_99 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_316 = _mm512_set1_ps(scal_99);


											vec_315 = _mm512_fmadd_ps(vec_316, vec_306, mem_vec_10652);
											mem_vec_10652 = vec_315;



											vec_317 = _mm512_fmadd_ps(vec_316, vec_308, mem_vec_10653);
											mem_vec_10653 = vec_317;
											scal_100 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_319 = _mm512_set1_ps(scal_100);


											vec_318 = _mm512_fmadd_ps(vec_319, vec_306, mem_vec_10654);
											mem_vec_10654 = vec_318;



											vec_320 = _mm512_fmadd_ps(vec_319, vec_308, mem_vec_10655);
											mem_vec_10655 = vec_320;
											scal_101 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
											vec_322 = _mm512_set1_ps(scal_101);


											vec_321 = _mm512_fmadd_ps(vec_322, vec_306, mem_vec_10656);
											mem_vec_10656 = vec_321;



											vec_323 = _mm512_fmadd_ps(vec_322, vec_308, mem_vec_10657);
											mem_vec_10657 = vec_323;
											scal_102 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
											vec_325 = _mm512_set1_ps(scal_102);


											vec_324 = _mm512_fmadd_ps(vec_325, vec_306, mem_vec_10658);
											mem_vec_10658 = vec_324;



											vec_326 = _mm512_fmadd_ps(vec_325, vec_308, mem_vec_10659);
											mem_vec_10659 = vec_326;
											scal_103 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 2) + c];
											vec_328 = _mm512_set1_ps(scal_103);


											vec_327 = _mm512_fmadd_ps(vec_328, vec_306, mem_vec_10660);
											mem_vec_10660 = vec_327;



											vec_329 = _mm512_fmadd_ps(vec_328, vec_308, mem_vec_10661);
											mem_vec_10661 = vec_329;
											scal_104 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 2) + c];
											vec_331 = _mm512_set1_ps(scal_104);


											vec_330 = _mm512_fmadd_ps(vec_331, vec_306, mem_vec_10662);
											mem_vec_10662 = vec_330;



											vec_332 = _mm512_fmadd_ps(vec_331, vec_308, mem_vec_10663);
											mem_vec_10663 = vec_332;
											scal_105 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 2) + c];
											vec_334 = _mm512_set1_ps(scal_105);


											vec_333 = _mm512_fmadd_ps(vec_334, vec_306, mem_vec_10664);
											mem_vec_10664 = vec_333;



											vec_335 = _mm512_fmadd_ps(vec_334, vec_308, mem_vec_10665);
											mem_vec_10665 = vec_335;
											scal_106 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 2) + c];
											vec_337 = _mm512_set1_ps(scal_106);


											vec_336 = _mm512_fmadd_ps(vec_337, vec_306, mem_vec_10666);
											mem_vec_10666 = vec_336;



											vec_338 = _mm512_fmadd_ps(vec_337, vec_308, mem_vec_10667);
											mem_vec_10667 = vec_338;
											scal_107 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h + 2) + c];
											vec_340 = _mm512_set1_ps(scal_107);


											vec_339 = _mm512_fmadd_ps(vec_340, vec_306, mem_vec_10668);
											mem_vec_10668 = vec_339;



											vec_341 = _mm512_fmadd_ps(vec_340, vec_308, mem_vec_10669);
											mem_vec_10669 = vec_341;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10646);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10647);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10648);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10649);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10650);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10651);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10652);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10653);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10654);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10655);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10656);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10657);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10658);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10659);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10660);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10661);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10662);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10663);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10664);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10665);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10666);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10667);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_10668);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_10669);
							}
						}
					}
				}
		}
	}
}


}