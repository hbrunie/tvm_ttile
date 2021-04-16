#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); U (3, w); T (64, c); Hoist_vars [c];
  T (68, x); T (2, c); T (1, f);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 4), (Arg 11))]; T (1, x);
  T (2, f); T (4, f)]
*/
IND_TYPE c, cp_0, c282_p_0, cp_1, c282, f, fp_0, f376_p_0, f377_p_0, fp_1, f376_p_1, fp_2, f376, f377, x, xp_0, x282_p_0, xp_1, x282, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y188 = 0;
IND_TYPE x283 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c283 = 0;
IND_TYPE f378 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_45 ,scal_46 ,scal_47 ,scal_48 ,scal_49 ,scal_5 ,scal_50 ,scal_51 ,scal_52 ,scal_53 ,scal_54 ,scal_55 ,scal_56 ,scal_57 ,scal_58 ,scal_59 ,scal_6 ,scal_60 ,scal_61 ,scal_62 ,scal_63 ,scal_64 ,scal_65 ,scal_66 ,scal_67 ,scal_68 ,scal_69 ,scal_7 ,scal_70 ,scal_71 ,scal_72 ,scal_73 ,scal_74 ,scal_75 ,scal_76 ,scal_77 ,scal_78 ,scal_79 ,scal_8 ,scal_80 ,scal_81 ,scal_82 ,scal_83 ,scal_84 ,scal_85 ,scal_86 ,scal_87 ,scal_88 ,scal_89 ,scal_9 ,scal_90 ,scal_91 ,scal_92 ,scal_93 ,scal_94 ,scal_95 ,scal_96 ,scal_97 ,scal_98;
__m512 mem_vec_4144 ,mem_vec_4145 ,mem_vec_4146 ,mem_vec_4147 ,mem_vec_4148 ,mem_vec_4149 ,mem_vec_4150 ,mem_vec_4151 ,mem_vec_4152 ,mem_vec_4153 ,mem_vec_4154 ,mem_vec_4155 ,mem_vec_4156 ,mem_vec_4157 ,mem_vec_4158 ,mem_vec_4159 ,mem_vec_4160 ,mem_vec_4161 ,mem_vec_4162 ,mem_vec_4163 ,mem_vec_4164 ,mem_vec_4165 ,mem_vec_4166 ,mem_vec_4167 ,mem_vec_4168 ,mem_vec_4169 ,mem_vec_4170 ,mem_vec_4171 ,mem_vec_4172 ,mem_vec_4173 ,mem_vec_4174 ,mem_vec_4175 ,mem_vec_4176 ,mem_vec_4177 ,mem_vec_4178 ,mem_vec_4179 ,mem_vec_4180 ,mem_vec_4181 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_132 ,vec_133 ,vec_134 ,vec_135 ,vec_136 ,vec_137 ,vec_138 ,vec_139 ,vec_14 ,vec_140 ,vec_141 ,vec_142 ,vec_143 ,vec_144 ,vec_145 ,vec_146 ,vec_147 ,vec_148 ,vec_149 ,vec_15 ,vec_150 ,vec_151 ,vec_152 ,vec_153 ,vec_154 ,vec_155 ,vec_156 ,vec_157 ,vec_158 ,vec_159 ,vec_16 ,vec_160 ,vec_161 ,vec_162 ,vec_163 ,vec_164 ,vec_165 ,vec_166 ,vec_167 ,vec_168 ,vec_169 ,vec_17 ,vec_170 ,vec_171 ,vec_172 ,vec_173 ,vec_174 ,vec_175 ,vec_176 ,vec_177 ,vec_178 ,vec_179 ,vec_18 ,vec_180 ,vec_181 ,vec_182 ,vec_183 ,vec_184 ,vec_185 ,vec_186 ,vec_187 ,vec_188 ,vec_189 ,vec_19 ,vec_190 ,vec_191 ,vec_192 ,vec_193 ,vec_194 ,vec_195 ,vec_196 ,vec_197 ,vec_198 ,vec_199 ,vec_2 ,vec_20 ,vec_200 ,vec_201 ,vec_202 ,vec_203 ,vec_204 ,vec_205 ,vec_206 ,vec_207 ,vec_208 ,vec_209 ,vec_21 ,vec_210 ,vec_211 ,vec_212 ,vec_213 ,vec_214 ,vec_215 ,vec_216 ,vec_217 ,vec_218 ,vec_219 ,vec_22 ,vec_220 ,vec_221 ,vec_222 ,vec_223 ,vec_224 ,vec_225 ,vec_226 ,vec_227 ,vec_228 ,vec_229 ,vec_23 ,vec_230 ,vec_231 ,vec_232 ,vec_233 ,vec_234 ,vec_235 ,vec_236 ,vec_237 ,vec_238 ,vec_239 ,vec_24 ,vec_240 ,vec_241 ,vec_242 ,vec_243 ,vec_244 ,vec_245 ,vec_246 ,vec_247 ,vec_248 ,vec_249 ,vec_25 ,vec_250 ,vec_251 ,vec_252 ,vec_253 ,vec_254 ,vec_255 ,vec_256 ,vec_257 ,vec_258 ,vec_259 ,vec_26 ,vec_260 ,vec_261 ,vec_262 ,vec_263 ,vec_264 ,vec_265 ,vec_266 ,vec_267 ,vec_268 ,vec_269 ,vec_27 ,vec_270 ,vec_271 ,vec_272 ,vec_273 ,vec_274 ,vec_275 ,vec_276 ,vec_277 ,vec_278 ,vec_279 ,vec_28 ,vec_280 ,vec_281 ,vec_282 ,vec_283 ,vec_284 ,vec_285 ,vec_286 ,vec_287 ,vec_288 ,vec_289 ,vec_29 ,vec_290 ,vec_291 ,vec_292 ,vec_293 ,vec_294 ,vec_295 ,vec_296 ,vec_297 ,vec_298 ,vec_299 ,vec_3 ,vec_30 ,vec_300 ,vec_301 ,vec_302 ,vec_303 ,vec_304 ,vec_305 ,vec_306 ,vec_307 ,vec_308 ,vec_309 ,vec_31 ,vec_310 ,vec_311 ,vec_312 ,vec_313 ,vec_314 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f377 = f378, f377_p_0 = 0;
	f377 < f378 + 256;
	f377 += 64, f377_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (f, 2) (64 / 32)
	for (f376 = f377, f376_p_1 = f377_p_0, f376_p_0 = 0;
		f376 < f377 + 64;
		f376 += 32, f376_p_1 += 32, f376_p_0 += 32){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (x, 1) (68 / 68)
		for (x282 = x283, x282_p_0 = 0;
			x282 < x283 + 68;
			x282 += 68, x282_p_0 += 68){
				for (y = y188, yp_0 = 0;
					y < y188 + 24;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f376, fp_2 = f376_p_1, fp_1 = f376_p_0, fp_0 = 0;
						f < f376 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 32
						// T (c, 2) (128 / 64)
						for (c282 = c283, c282_p_0 = 0;
							c282 < c283 + 128;
							c282 += 64, c282_p_0 += 64){
							// y = ph_y, x = 68, h = 3, w = 3, c = 64, f = 32
							// T (x, 68) (68 / 1)
							for (x = x282, xp_1 = x282_p_0, xp_0 = 0;
								x < x282 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4144 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4145 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_4159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c282, cp_1 = c282_p_0, cp_0 = 0;
											c < c282 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4144);
											mem_vec_4144 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4145);
											mem_vec_4145 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4146);
											mem_vec_4146 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4147);
											mem_vec_4147 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4148);
											mem_vec_4148 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4149);
											mem_vec_4149 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4150);
											mem_vec_4150 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4151);
											mem_vec_4151 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4152);
											mem_vec_4152 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4153);
											mem_vec_4153 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4154);
											mem_vec_4154 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4155);
											mem_vec_4155 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4156);
											mem_vec_4156 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4157);
											mem_vec_4157 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4158);
											mem_vec_4158 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4159);
											mem_vec_4159 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_4144);
											mem_vec_4144 = vec_26;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_4145);
											mem_vec_4145 = vec_29;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_4146);
											mem_vec_4146 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_4147);
											mem_vec_4147 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_4148);
											mem_vec_4148 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_4149);
											mem_vec_4149 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_4150);
											mem_vec_4150 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_4151);
											mem_vec_4151 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_4152);
											mem_vec_4152 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_4153);
											mem_vec_4153 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_4154);
											mem_vec_4154 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_4155);
											mem_vec_4155 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_4156);
											mem_vec_4156 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_4157);
											mem_vec_4157 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_4158);
											mem_vec_4158 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_4159);
											mem_vec_4159 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_53 = _mm512_set1_ps(scal_16);
											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_4144);
											mem_vec_4144 = vec_52;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_4145);
											mem_vec_4145 = vec_55;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_17);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_4146);
											mem_vec_4146 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_4147);
											mem_vec_4147 = vec_59;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_61 = _mm512_set1_ps(scal_18);


											vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_4148);
											mem_vec_4148 = vec_60;



											vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_4149);
											mem_vec_4149 = vec_62;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_4150);
											mem_vec_4150 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_4151);
											mem_vec_4151 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_4152);
											mem_vec_4152 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_4153);
											mem_vec_4153 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_4154);
											mem_vec_4154 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_4155);
											mem_vec_4155 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_4156);
											mem_vec_4156 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_4157);
											mem_vec_4157 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_4158);
											mem_vec_4158 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_4159);
											mem_vec_4159 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_79 = _mm512_set1_ps(scal_24);
											vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_4144);
											mem_vec_4144 = vec_78;

											vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_4145);
											mem_vec_4145 = vec_81;
											scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_84 = _mm512_set1_ps(scal_25);


											vec_83 = _mm512_fmadd_ps(vec_84, vec_80, mem_vec_4146);
											mem_vec_4146 = vec_83;



											vec_85 = _mm512_fmadd_ps(vec_84, vec_82, mem_vec_4147);
											mem_vec_4147 = vec_85;
											scal_26 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_87 = _mm512_set1_ps(scal_26);


											vec_86 = _mm512_fmadd_ps(vec_87, vec_80, mem_vec_4148);
											mem_vec_4148 = vec_86;



											vec_88 = _mm512_fmadd_ps(vec_87, vec_82, mem_vec_4149);
											mem_vec_4149 = vec_88;
											scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_90 = _mm512_set1_ps(scal_27);


											vec_89 = _mm512_fmadd_ps(vec_90, vec_80, mem_vec_4150);
											mem_vec_4150 = vec_89;



											vec_91 = _mm512_fmadd_ps(vec_90, vec_82, mem_vec_4151);
											mem_vec_4151 = vec_91;
											scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_93 = _mm512_set1_ps(scal_28);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_4152);
											mem_vec_4152 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_4153);
											mem_vec_4153 = vec_94;
											scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_96 = _mm512_set1_ps(scal_29);


											vec_95 = _mm512_fmadd_ps(vec_96, vec_80, mem_vec_4154);
											mem_vec_4154 = vec_95;



											vec_97 = _mm512_fmadd_ps(vec_96, vec_82, mem_vec_4155);
											mem_vec_4155 = vec_97;
											scal_30 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_99 = _mm512_set1_ps(scal_30);


											vec_98 = _mm512_fmadd_ps(vec_99, vec_80, mem_vec_4156);
											mem_vec_4156 = vec_98;



											vec_100 = _mm512_fmadd_ps(vec_99, vec_82, mem_vec_4157);
											mem_vec_4157 = vec_100;
											scal_31 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
											vec_102 = _mm512_set1_ps(scal_31);


											vec_101 = _mm512_fmadd_ps(vec_102, vec_80, mem_vec_4158);
											mem_vec_4158 = vec_101;



											vec_103 = _mm512_fmadd_ps(vec_102, vec_82, mem_vec_4159);
											mem_vec_4159 = vec_103;
											scal_32 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_105 = _mm512_set1_ps(scal_32);
											vec_106 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_104 = _mm512_fmadd_ps(vec_105, vec_106, mem_vec_4144);
											mem_vec_4144 = vec_104;

											vec_108 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_107 = _mm512_fmadd_ps(vec_105, vec_108, mem_vec_4145);
											mem_vec_4145 = vec_107;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_110 = _mm512_set1_ps(scal_33);


											vec_109 = _mm512_fmadd_ps(vec_110, vec_106, mem_vec_4146);
											mem_vec_4146 = vec_109;



											vec_111 = _mm512_fmadd_ps(vec_110, vec_108, mem_vec_4147);
											mem_vec_4147 = vec_111;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_113 = _mm512_set1_ps(scal_34);


											vec_112 = _mm512_fmadd_ps(vec_113, vec_106, mem_vec_4148);
											mem_vec_4148 = vec_112;



											vec_114 = _mm512_fmadd_ps(vec_113, vec_108, mem_vec_4149);
											mem_vec_4149 = vec_114;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_116 = _mm512_set1_ps(scal_35);


											vec_115 = _mm512_fmadd_ps(vec_116, vec_106, mem_vec_4150);
											mem_vec_4150 = vec_115;



											vec_117 = _mm512_fmadd_ps(vec_116, vec_108, mem_vec_4151);
											mem_vec_4151 = vec_117;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_119 = _mm512_set1_ps(scal_36);


											vec_118 = _mm512_fmadd_ps(vec_119, vec_106, mem_vec_4152);
											mem_vec_4152 = vec_118;



											vec_120 = _mm512_fmadd_ps(vec_119, vec_108, mem_vec_4153);
											mem_vec_4153 = vec_120;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
											vec_122 = _mm512_set1_ps(scal_37);


											vec_121 = _mm512_fmadd_ps(vec_122, vec_106, mem_vec_4154);
											mem_vec_4154 = vec_121;



											vec_123 = _mm512_fmadd_ps(vec_122, vec_108, mem_vec_4155);
											mem_vec_4155 = vec_123;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
											vec_125 = _mm512_set1_ps(scal_38);


											vec_124 = _mm512_fmadd_ps(vec_125, vec_106, mem_vec_4156);
											mem_vec_4156 = vec_124;



											vec_126 = _mm512_fmadd_ps(vec_125, vec_108, mem_vec_4157);
											mem_vec_4157 = vec_126;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 1) + c];
											vec_128 = _mm512_set1_ps(scal_39);


											vec_127 = _mm512_fmadd_ps(vec_128, vec_106, mem_vec_4158);
											mem_vec_4158 = vec_127;



											vec_129 = _mm512_fmadd_ps(vec_128, vec_108, mem_vec_4159);
											mem_vec_4159 = vec_129;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_131 = _mm512_set1_ps(scal_40);
											vec_132 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_130 = _mm512_fmadd_ps(vec_131, vec_132, mem_vec_4144);
											mem_vec_4144 = vec_130;

											vec_134 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_133 = _mm512_fmadd_ps(vec_131, vec_134, mem_vec_4145);
											mem_vec_4145 = vec_133;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_136 = _mm512_set1_ps(scal_41);


											vec_135 = _mm512_fmadd_ps(vec_136, vec_132, mem_vec_4146);
											mem_vec_4146 = vec_135;



											vec_137 = _mm512_fmadd_ps(vec_136, vec_134, mem_vec_4147);
											mem_vec_4147 = vec_137;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_139 = _mm512_set1_ps(scal_42);


											vec_138 = _mm512_fmadd_ps(vec_139, vec_132, mem_vec_4148);
											mem_vec_4148 = vec_138;



											vec_140 = _mm512_fmadd_ps(vec_139, vec_134, mem_vec_4149);
											mem_vec_4149 = vec_140;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_142 = _mm512_set1_ps(scal_43);


											vec_141 = _mm512_fmadd_ps(vec_142, vec_132, mem_vec_4150);
											mem_vec_4150 = vec_141;



											vec_143 = _mm512_fmadd_ps(vec_142, vec_134, mem_vec_4151);
											mem_vec_4151 = vec_143;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_145 = _mm512_set1_ps(scal_44);


											vec_144 = _mm512_fmadd_ps(vec_145, vec_132, mem_vec_4152);
											mem_vec_4152 = vec_144;



											vec_146 = _mm512_fmadd_ps(vec_145, vec_134, mem_vec_4153);
											mem_vec_4153 = vec_146;
											scal_45 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
											vec_148 = _mm512_set1_ps(scal_45);


											vec_147 = _mm512_fmadd_ps(vec_148, vec_132, mem_vec_4154);
											mem_vec_4154 = vec_147;



											vec_149 = _mm512_fmadd_ps(vec_148, vec_134, mem_vec_4155);
											mem_vec_4155 = vec_149;
											scal_46 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
											vec_151 = _mm512_set1_ps(scal_46);


											vec_150 = _mm512_fmadd_ps(vec_151, vec_132, mem_vec_4156);
											mem_vec_4156 = vec_150;



											vec_152 = _mm512_fmadd_ps(vec_151, vec_134, mem_vec_4157);
											mem_vec_4157 = vec_152;
											scal_47 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 2) + c];
											vec_154 = _mm512_set1_ps(scal_47);


											vec_153 = _mm512_fmadd_ps(vec_154, vec_132, mem_vec_4158);
											mem_vec_4158 = vec_153;



											vec_155 = _mm512_fmadd_ps(vec_154, vec_134, mem_vec_4159);
											mem_vec_4159 = vec_155;
											scal_48 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_157 = _mm512_set1_ps(scal_48);
											vec_158 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_156 = _mm512_fmadd_ps(vec_157, vec_158, mem_vec_4144);
											mem_vec_4144 = vec_156;

											vec_160 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_159 = _mm512_fmadd_ps(vec_157, vec_160, mem_vec_4145);
											mem_vec_4145 = vec_159;
											scal_49 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_162 = _mm512_set1_ps(scal_49);


											vec_161 = _mm512_fmadd_ps(vec_162, vec_158, mem_vec_4146);
											mem_vec_4146 = vec_161;



											vec_163 = _mm512_fmadd_ps(vec_162, vec_160, mem_vec_4147);
											mem_vec_4147 = vec_163;
											scal_50 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_165 = _mm512_set1_ps(scal_50);


											vec_164 = _mm512_fmadd_ps(vec_165, vec_158, mem_vec_4148);
											mem_vec_4148 = vec_164;



											vec_166 = _mm512_fmadd_ps(vec_165, vec_160, mem_vec_4149);
											mem_vec_4149 = vec_166;
											scal_51 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_168 = _mm512_set1_ps(scal_51);


											vec_167 = _mm512_fmadd_ps(vec_168, vec_158, mem_vec_4150);
											mem_vec_4150 = vec_167;



											vec_169 = _mm512_fmadd_ps(vec_168, vec_160, mem_vec_4151);
											mem_vec_4151 = vec_169;
											scal_52 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_171 = _mm512_set1_ps(scal_52);


											vec_170 = _mm512_fmadd_ps(vec_171, vec_158, mem_vec_4152);
											mem_vec_4152 = vec_170;



											vec_172 = _mm512_fmadd_ps(vec_171, vec_160, mem_vec_4153);
											mem_vec_4153 = vec_172;
											scal_53 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_174 = _mm512_set1_ps(scal_53);


											vec_173 = _mm512_fmadd_ps(vec_174, vec_158, mem_vec_4154);
											mem_vec_4154 = vec_173;



											vec_175 = _mm512_fmadd_ps(vec_174, vec_160, mem_vec_4155);
											mem_vec_4155 = vec_175;
											scal_54 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_177 = _mm512_set1_ps(scal_54);


											vec_176 = _mm512_fmadd_ps(vec_177, vec_158, mem_vec_4156);
											mem_vec_4156 = vec_176;



											vec_178 = _mm512_fmadd_ps(vec_177, vec_160, mem_vec_4157);
											mem_vec_4157 = vec_178;
											scal_55 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
											vec_180 = _mm512_set1_ps(scal_55);


											vec_179 = _mm512_fmadd_ps(vec_180, vec_158, mem_vec_4158);
											mem_vec_4158 = vec_179;



											vec_181 = _mm512_fmadd_ps(vec_180, vec_160, mem_vec_4159);
											mem_vec_4159 = vec_181;
											scal_56 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_183 = _mm512_set1_ps(scal_56);
											vec_184 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_182 = _mm512_fmadd_ps(vec_183, vec_184, mem_vec_4144);
											mem_vec_4144 = vec_182;

											vec_186 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_185 = _mm512_fmadd_ps(vec_183, vec_186, mem_vec_4145);
											mem_vec_4145 = vec_185;
											scal_57 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_188 = _mm512_set1_ps(scal_57);


											vec_187 = _mm512_fmadd_ps(vec_188, vec_184, mem_vec_4146);
											mem_vec_4146 = vec_187;



											vec_189 = _mm512_fmadd_ps(vec_188, vec_186, mem_vec_4147);
											mem_vec_4147 = vec_189;
											scal_58 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_191 = _mm512_set1_ps(scal_58);


											vec_190 = _mm512_fmadd_ps(vec_191, vec_184, mem_vec_4148);
											mem_vec_4148 = vec_190;



											vec_192 = _mm512_fmadd_ps(vec_191, vec_186, mem_vec_4149);
											mem_vec_4149 = vec_192;
											scal_59 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_194 = _mm512_set1_ps(scal_59);


											vec_193 = _mm512_fmadd_ps(vec_194, vec_184, mem_vec_4150);
											mem_vec_4150 = vec_193;



											vec_195 = _mm512_fmadd_ps(vec_194, vec_186, mem_vec_4151);
											mem_vec_4151 = vec_195;
											scal_60 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_197 = _mm512_set1_ps(scal_60);


											vec_196 = _mm512_fmadd_ps(vec_197, vec_184, mem_vec_4152);
											mem_vec_4152 = vec_196;



											vec_198 = _mm512_fmadd_ps(vec_197, vec_186, mem_vec_4153);
											mem_vec_4153 = vec_198;
											scal_61 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
											vec_200 = _mm512_set1_ps(scal_61);


											vec_199 = _mm512_fmadd_ps(vec_200, vec_184, mem_vec_4154);
											mem_vec_4154 = vec_199;



											vec_201 = _mm512_fmadd_ps(vec_200, vec_186, mem_vec_4155);
											mem_vec_4155 = vec_201;
											scal_62 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
											vec_203 = _mm512_set1_ps(scal_62);


											vec_202 = _mm512_fmadd_ps(vec_203, vec_184, mem_vec_4156);
											mem_vec_4156 = vec_202;



											vec_204 = _mm512_fmadd_ps(vec_203, vec_186, mem_vec_4157);
											mem_vec_4157 = vec_204;
											scal_63 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 1) + c];
											vec_206 = _mm512_set1_ps(scal_63);


											vec_205 = _mm512_fmadd_ps(vec_206, vec_184, mem_vec_4158);
											mem_vec_4158 = vec_205;



											vec_207 = _mm512_fmadd_ps(vec_206, vec_186, mem_vec_4159);
											mem_vec_4159 = vec_207;
											scal_64 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_209 = _mm512_set1_ps(scal_64);
											vec_210 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_208 = _mm512_fmadd_ps(vec_209, vec_210, mem_vec_4144);
											mem_vec_4144 = vec_208;

											vec_212 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_211 = _mm512_fmadd_ps(vec_209, vec_212, mem_vec_4145);
											mem_vec_4145 = vec_211;
											scal_65 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_214 = _mm512_set1_ps(scal_65);


											vec_213 = _mm512_fmadd_ps(vec_214, vec_210, mem_vec_4146);
											mem_vec_4146 = vec_213;



											vec_215 = _mm512_fmadd_ps(vec_214, vec_212, mem_vec_4147);
											mem_vec_4147 = vec_215;
											scal_66 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_217 = _mm512_set1_ps(scal_66);


											vec_216 = _mm512_fmadd_ps(vec_217, vec_210, mem_vec_4148);
											mem_vec_4148 = vec_216;



											vec_218 = _mm512_fmadd_ps(vec_217, vec_212, mem_vec_4149);
											mem_vec_4149 = vec_218;
											scal_67 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_220 = _mm512_set1_ps(scal_67);


											vec_219 = _mm512_fmadd_ps(vec_220, vec_210, mem_vec_4150);
											mem_vec_4150 = vec_219;



											vec_221 = _mm512_fmadd_ps(vec_220, vec_212, mem_vec_4151);
											mem_vec_4151 = vec_221;
											scal_68 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_223 = _mm512_set1_ps(scal_68);


											vec_222 = _mm512_fmadd_ps(vec_223, vec_210, mem_vec_4152);
											mem_vec_4152 = vec_222;



											vec_224 = _mm512_fmadd_ps(vec_223, vec_212, mem_vec_4153);
											mem_vec_4153 = vec_224;
											scal_69 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
											vec_226 = _mm512_set1_ps(scal_69);


											vec_225 = _mm512_fmadd_ps(vec_226, vec_210, mem_vec_4154);
											mem_vec_4154 = vec_225;



											vec_227 = _mm512_fmadd_ps(vec_226, vec_212, mem_vec_4155);
											mem_vec_4155 = vec_227;
											scal_70 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
											vec_229 = _mm512_set1_ps(scal_70);


											vec_228 = _mm512_fmadd_ps(vec_229, vec_210, mem_vec_4156);
											mem_vec_4156 = vec_228;



											vec_230 = _mm512_fmadd_ps(vec_229, vec_212, mem_vec_4157);
											mem_vec_4157 = vec_230;
											scal_71 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 2) + c];
											vec_232 = _mm512_set1_ps(scal_71);


											vec_231 = _mm512_fmadd_ps(vec_232, vec_210, mem_vec_4158);
											mem_vec_4158 = vec_231;



											vec_233 = _mm512_fmadd_ps(vec_232, vec_212, mem_vec_4159);
											mem_vec_4159 = vec_233;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4144);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4145);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4146);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4147);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4148);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4149);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4150);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4151);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4152);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4153);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4154);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4155);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4156);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4157);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4158);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4159);
							}
						}
					}
				}
				for (y = y188 + 24, yp_0 = 0;
					y < y188 + 24 + 44;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f376, fp_2 = f376_p_1, fp_1 = f376_p_0, fp_0 = 0;
						f < f376 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 32
						// T (c, 2) (128 / 64)
						for (c282 = c283, c282_p_0 = 0;
							c282 < c283 + 128;
							c282 += 64, c282_p_0 += 64){
							// y = ph_y, x = 68, h = 3, w = 3, c = 64, f = 32
							// T (x, 68) (68 / 1)
							for (x = x282, xp_1 = x282_p_0, xp_0 = 0;
								x < x282 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4160 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4161 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_4175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_4176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_4177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_4178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_4179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_4180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_4181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c282, cp_1 = c282_p_0, cp_0 = 0;
											c < c282 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4160);
											mem_vec_4160 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4161);
											mem_vec_4161 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4162);
											mem_vec_4162 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4163);
											mem_vec_4163 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4164);
											mem_vec_4164 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4165);
											mem_vec_4165 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4166);
											mem_vec_4166 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4167);
											mem_vec_4167 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4168);
											mem_vec_4168 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4169);
											mem_vec_4169 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4170);
											mem_vec_4170 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4171);
											mem_vec_4171 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4172);
											mem_vec_4172 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4173);
											mem_vec_4173 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4174);
											mem_vec_4174 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4175);
											mem_vec_4175 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4176);
											mem_vec_4176 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4177);
											mem_vec_4177 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4178);
											mem_vec_4178 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4179);
											mem_vec_4179 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4180);
											mem_vec_4180 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4181);
											mem_vec_4181 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_4160);
											mem_vec_4160 = vec_35;

											vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_4161);
											mem_vec_4161 = vec_38;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_4162);
											mem_vec_4162 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_4163);
											mem_vec_4163 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_4164);
											mem_vec_4164 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_4165);
											mem_vec_4165 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_4166);
											mem_vec_4166 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_4167);
											mem_vec_4167 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_4168);
											mem_vec_4168 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_4169);
											mem_vec_4169 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_4170);
											mem_vec_4170 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_4171);
											mem_vec_4171 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_4172);
											mem_vec_4172 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_4173);
											mem_vec_4173 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_4174);
											mem_vec_4174 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_4175);
											mem_vec_4175 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_4176);
											mem_vec_4176 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_4177);
											mem_vec_4177 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_4178);
											mem_vec_4178 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_4179);
											mem_vec_4179 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_4180);
											mem_vec_4180 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_4181);
											mem_vec_4181 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_71 = _mm512_set1_ps(scal_22);
											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_4160);
											mem_vec_4160 = vec_70;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_4161);
											mem_vec_4161 = vec_73;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_4162);
											mem_vec_4162 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_4163);
											mem_vec_4163 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_4164);
											mem_vec_4164 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_4165);
											mem_vec_4165 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_4166);
											mem_vec_4166 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_4167);
											mem_vec_4167 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_4168);
											mem_vec_4168 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_4169);
											mem_vec_4169 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_4170);
											mem_vec_4170 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_4171);
											mem_vec_4171 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_4172);
											mem_vec_4172 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_4173);
											mem_vec_4173 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_4174);
											mem_vec_4174 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_4175);
											mem_vec_4175 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_97 = _mm512_set1_ps(scal_30);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_4176);
											mem_vec_4176 = vec_96;



											vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_4177);
											mem_vec_4177 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_4178);
											mem_vec_4178 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_4179);
											mem_vec_4179 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_4180);
											mem_vec_4180 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_4181);
											mem_vec_4181 = vec_104;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_106 = _mm512_set1_ps(scal_33);
											vec_107 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_105 = _mm512_fmadd_ps(vec_106, vec_107, mem_vec_4160);
											mem_vec_4160 = vec_105;

											vec_109 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_108 = _mm512_fmadd_ps(vec_106, vec_109, mem_vec_4161);
											mem_vec_4161 = vec_108;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_111 = _mm512_set1_ps(scal_34);


											vec_110 = _mm512_fmadd_ps(vec_111, vec_107, mem_vec_4162);
											mem_vec_4162 = vec_110;



											vec_112 = _mm512_fmadd_ps(vec_111, vec_109, mem_vec_4163);
											mem_vec_4163 = vec_112;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_114 = _mm512_set1_ps(scal_35);


											vec_113 = _mm512_fmadd_ps(vec_114, vec_107, mem_vec_4164);
											mem_vec_4164 = vec_113;



											vec_115 = _mm512_fmadd_ps(vec_114, vec_109, mem_vec_4165);
											mem_vec_4165 = vec_115;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_117 = _mm512_set1_ps(scal_36);


											vec_116 = _mm512_fmadd_ps(vec_117, vec_107, mem_vec_4166);
											mem_vec_4166 = vec_116;



											vec_118 = _mm512_fmadd_ps(vec_117, vec_109, mem_vec_4167);
											mem_vec_4167 = vec_118;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_120 = _mm512_set1_ps(scal_37);


											vec_119 = _mm512_fmadd_ps(vec_120, vec_107, mem_vec_4168);
											mem_vec_4168 = vec_119;



											vec_121 = _mm512_fmadd_ps(vec_120, vec_109, mem_vec_4169);
											mem_vec_4169 = vec_121;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_123 = _mm512_set1_ps(scal_38);


											vec_122 = _mm512_fmadd_ps(vec_123, vec_107, mem_vec_4170);
											mem_vec_4170 = vec_122;



											vec_124 = _mm512_fmadd_ps(vec_123, vec_109, mem_vec_4171);
											mem_vec_4171 = vec_124;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_126 = _mm512_set1_ps(scal_39);


											vec_125 = _mm512_fmadd_ps(vec_126, vec_107, mem_vec_4172);
											mem_vec_4172 = vec_125;



											vec_127 = _mm512_fmadd_ps(vec_126, vec_109, mem_vec_4173);
											mem_vec_4173 = vec_127;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
											vec_129 = _mm512_set1_ps(scal_40);


											vec_128 = _mm512_fmadd_ps(vec_129, vec_107, mem_vec_4174);
											mem_vec_4174 = vec_128;



											vec_130 = _mm512_fmadd_ps(vec_129, vec_109, mem_vec_4175);
											mem_vec_4175 = vec_130;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
											vec_132 = _mm512_set1_ps(scal_41);


											vec_131 = _mm512_fmadd_ps(vec_132, vec_107, mem_vec_4176);
											mem_vec_4176 = vec_131;



											vec_133 = _mm512_fmadd_ps(vec_132, vec_109, mem_vec_4177);
											mem_vec_4177 = vec_133;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
											vec_135 = _mm512_set1_ps(scal_42);


											vec_134 = _mm512_fmadd_ps(vec_135, vec_107, mem_vec_4178);
											mem_vec_4178 = vec_134;



											vec_136 = _mm512_fmadd_ps(vec_135, vec_109, mem_vec_4179);
											mem_vec_4179 = vec_136;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
											vec_138 = _mm512_set1_ps(scal_43);


											vec_137 = _mm512_fmadd_ps(vec_138, vec_107, mem_vec_4180);
											mem_vec_4180 = vec_137;



											vec_139 = _mm512_fmadd_ps(vec_138, vec_109, mem_vec_4181);
											mem_vec_4181 = vec_139;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_141 = _mm512_set1_ps(scal_44);
											vec_142 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_140 = _mm512_fmadd_ps(vec_141, vec_142, mem_vec_4160);
											mem_vec_4160 = vec_140;

											vec_144 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_143 = _mm512_fmadd_ps(vec_141, vec_144, mem_vec_4161);
											mem_vec_4161 = vec_143;
											scal_45 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_146 = _mm512_set1_ps(scal_45);


											vec_145 = _mm512_fmadd_ps(vec_146, vec_142, mem_vec_4162);
											mem_vec_4162 = vec_145;



											vec_147 = _mm512_fmadd_ps(vec_146, vec_144, mem_vec_4163);
											mem_vec_4163 = vec_147;
											scal_46 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_149 = _mm512_set1_ps(scal_46);


											vec_148 = _mm512_fmadd_ps(vec_149, vec_142, mem_vec_4164);
											mem_vec_4164 = vec_148;



											vec_150 = _mm512_fmadd_ps(vec_149, vec_144, mem_vec_4165);
											mem_vec_4165 = vec_150;
											scal_47 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_152 = _mm512_set1_ps(scal_47);


											vec_151 = _mm512_fmadd_ps(vec_152, vec_142, mem_vec_4166);
											mem_vec_4166 = vec_151;



											vec_153 = _mm512_fmadd_ps(vec_152, vec_144, mem_vec_4167);
											mem_vec_4167 = vec_153;
											scal_48 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_155 = _mm512_set1_ps(scal_48);


											vec_154 = _mm512_fmadd_ps(vec_155, vec_142, mem_vec_4168);
											mem_vec_4168 = vec_154;



											vec_156 = _mm512_fmadd_ps(vec_155, vec_144, mem_vec_4169);
											mem_vec_4169 = vec_156;
											scal_49 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
											vec_158 = _mm512_set1_ps(scal_49);


											vec_157 = _mm512_fmadd_ps(vec_158, vec_142, mem_vec_4170);
											mem_vec_4170 = vec_157;



											vec_159 = _mm512_fmadd_ps(vec_158, vec_144, mem_vec_4171);
											mem_vec_4171 = vec_159;
											scal_50 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
											vec_161 = _mm512_set1_ps(scal_50);


											vec_160 = _mm512_fmadd_ps(vec_161, vec_142, mem_vec_4172);
											mem_vec_4172 = vec_160;



											vec_162 = _mm512_fmadd_ps(vec_161, vec_144, mem_vec_4173);
											mem_vec_4173 = vec_162;
											scal_51 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 1) + c];
											vec_164 = _mm512_set1_ps(scal_51);


											vec_163 = _mm512_fmadd_ps(vec_164, vec_142, mem_vec_4174);
											mem_vec_4174 = vec_163;



											vec_165 = _mm512_fmadd_ps(vec_164, vec_144, mem_vec_4175);
											mem_vec_4175 = vec_165;
											scal_52 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 1) + c];
											vec_167 = _mm512_set1_ps(scal_52);


											vec_166 = _mm512_fmadd_ps(vec_167, vec_142, mem_vec_4176);
											mem_vec_4176 = vec_166;



											vec_168 = _mm512_fmadd_ps(vec_167, vec_144, mem_vec_4177);
											mem_vec_4177 = vec_168;
											scal_53 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 1) + c];
											vec_170 = _mm512_set1_ps(scal_53);


											vec_169 = _mm512_fmadd_ps(vec_170, vec_142, mem_vec_4178);
											mem_vec_4178 = vec_169;



											vec_171 = _mm512_fmadd_ps(vec_170, vec_144, mem_vec_4179);
											mem_vec_4179 = vec_171;
											scal_54 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 1) + c];
											vec_173 = _mm512_set1_ps(scal_54);


											vec_172 = _mm512_fmadd_ps(vec_173, vec_142, mem_vec_4180);
											mem_vec_4180 = vec_172;



											vec_174 = _mm512_fmadd_ps(vec_173, vec_144, mem_vec_4181);
											mem_vec_4181 = vec_174;
											scal_55 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_176 = _mm512_set1_ps(scal_55);
											vec_177 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_175 = _mm512_fmadd_ps(vec_176, vec_177, mem_vec_4160);
											mem_vec_4160 = vec_175;

											vec_179 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_178 = _mm512_fmadd_ps(vec_176, vec_179, mem_vec_4161);
											mem_vec_4161 = vec_178;
											scal_56 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_181 = _mm512_set1_ps(scal_56);


											vec_180 = _mm512_fmadd_ps(vec_181, vec_177, mem_vec_4162);
											mem_vec_4162 = vec_180;



											vec_182 = _mm512_fmadd_ps(vec_181, vec_179, mem_vec_4163);
											mem_vec_4163 = vec_182;
											scal_57 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_184 = _mm512_set1_ps(scal_57);


											vec_183 = _mm512_fmadd_ps(vec_184, vec_177, mem_vec_4164);
											mem_vec_4164 = vec_183;



											vec_185 = _mm512_fmadd_ps(vec_184, vec_179, mem_vec_4165);
											mem_vec_4165 = vec_185;
											scal_58 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_187 = _mm512_set1_ps(scal_58);


											vec_186 = _mm512_fmadd_ps(vec_187, vec_177, mem_vec_4166);
											mem_vec_4166 = vec_186;



											vec_188 = _mm512_fmadd_ps(vec_187, vec_179, mem_vec_4167);
											mem_vec_4167 = vec_188;
											scal_59 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_190 = _mm512_set1_ps(scal_59);


											vec_189 = _mm512_fmadd_ps(vec_190, vec_177, mem_vec_4168);
											mem_vec_4168 = vec_189;



											vec_191 = _mm512_fmadd_ps(vec_190, vec_179, mem_vec_4169);
											mem_vec_4169 = vec_191;
											scal_60 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
											vec_193 = _mm512_set1_ps(scal_60);


											vec_192 = _mm512_fmadd_ps(vec_193, vec_177, mem_vec_4170);
											mem_vec_4170 = vec_192;



											vec_194 = _mm512_fmadd_ps(vec_193, vec_179, mem_vec_4171);
											mem_vec_4171 = vec_194;
											scal_61 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
											vec_196 = _mm512_set1_ps(scal_61);


											vec_195 = _mm512_fmadd_ps(vec_196, vec_177, mem_vec_4172);
											mem_vec_4172 = vec_195;



											vec_197 = _mm512_fmadd_ps(vec_196, vec_179, mem_vec_4173);
											mem_vec_4173 = vec_197;
											scal_62 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 2) + c];
											vec_199 = _mm512_set1_ps(scal_62);


											vec_198 = _mm512_fmadd_ps(vec_199, vec_177, mem_vec_4174);
											mem_vec_4174 = vec_198;



											vec_200 = _mm512_fmadd_ps(vec_199, vec_179, mem_vec_4175);
											mem_vec_4175 = vec_200;
											scal_63 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 2) + c];
											vec_202 = _mm512_set1_ps(scal_63);


											vec_201 = _mm512_fmadd_ps(vec_202, vec_177, mem_vec_4176);
											mem_vec_4176 = vec_201;



											vec_203 = _mm512_fmadd_ps(vec_202, vec_179, mem_vec_4177);
											mem_vec_4177 = vec_203;
											scal_64 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 2) + c];
											vec_205 = _mm512_set1_ps(scal_64);


											vec_204 = _mm512_fmadd_ps(vec_205, vec_177, mem_vec_4178);
											mem_vec_4178 = vec_204;



											vec_206 = _mm512_fmadd_ps(vec_205, vec_179, mem_vec_4179);
											mem_vec_4179 = vec_206;
											scal_65 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 2) + c];
											vec_208 = _mm512_set1_ps(scal_65);


											vec_207 = _mm512_fmadd_ps(vec_208, vec_177, mem_vec_4180);
											mem_vec_4180 = vec_207;



											vec_209 = _mm512_fmadd_ps(vec_208, vec_179, mem_vec_4181);
											mem_vec_4181 = vec_209;
											scal_66 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_211 = _mm512_set1_ps(scal_66);
											vec_212 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_210 = _mm512_fmadd_ps(vec_211, vec_212, mem_vec_4160);
											mem_vec_4160 = vec_210;

											vec_214 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_213 = _mm512_fmadd_ps(vec_211, vec_214, mem_vec_4161);
											mem_vec_4161 = vec_213;
											scal_67 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_216 = _mm512_set1_ps(scal_67);


											vec_215 = _mm512_fmadd_ps(vec_216, vec_212, mem_vec_4162);
											mem_vec_4162 = vec_215;



											vec_217 = _mm512_fmadd_ps(vec_216, vec_214, mem_vec_4163);
											mem_vec_4163 = vec_217;
											scal_68 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_219 = _mm512_set1_ps(scal_68);


											vec_218 = _mm512_fmadd_ps(vec_219, vec_212, mem_vec_4164);
											mem_vec_4164 = vec_218;



											vec_220 = _mm512_fmadd_ps(vec_219, vec_214, mem_vec_4165);
											mem_vec_4165 = vec_220;
											scal_69 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_222 = _mm512_set1_ps(scal_69);


											vec_221 = _mm512_fmadd_ps(vec_222, vec_212, mem_vec_4166);
											mem_vec_4166 = vec_221;



											vec_223 = _mm512_fmadd_ps(vec_222, vec_214, mem_vec_4167);
											mem_vec_4167 = vec_223;
											scal_70 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_225 = _mm512_set1_ps(scal_70);


											vec_224 = _mm512_fmadd_ps(vec_225, vec_212, mem_vec_4168);
											mem_vec_4168 = vec_224;



											vec_226 = _mm512_fmadd_ps(vec_225, vec_214, mem_vec_4169);
											mem_vec_4169 = vec_226;
											scal_71 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_228 = _mm512_set1_ps(scal_71);


											vec_227 = _mm512_fmadd_ps(vec_228, vec_212, mem_vec_4170);
											mem_vec_4170 = vec_227;



											vec_229 = _mm512_fmadd_ps(vec_228, vec_214, mem_vec_4171);
											mem_vec_4171 = vec_229;
											scal_72 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_231 = _mm512_set1_ps(scal_72);


											vec_230 = _mm512_fmadd_ps(vec_231, vec_212, mem_vec_4172);
											mem_vec_4172 = vec_230;



											vec_232 = _mm512_fmadd_ps(vec_231, vec_214, mem_vec_4173);
											mem_vec_4173 = vec_232;
											scal_73 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
											vec_234 = _mm512_set1_ps(scal_73);


											vec_233 = _mm512_fmadd_ps(vec_234, vec_212, mem_vec_4174);
											mem_vec_4174 = vec_233;



											vec_235 = _mm512_fmadd_ps(vec_234, vec_214, mem_vec_4175);
											mem_vec_4175 = vec_235;
											scal_74 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
											vec_237 = _mm512_set1_ps(scal_74);


											vec_236 = _mm512_fmadd_ps(vec_237, vec_212, mem_vec_4176);
											mem_vec_4176 = vec_236;



											vec_238 = _mm512_fmadd_ps(vec_237, vec_214, mem_vec_4177);
											mem_vec_4177 = vec_238;
											scal_75 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
											vec_240 = _mm512_set1_ps(scal_75);


											vec_239 = _mm512_fmadd_ps(vec_240, vec_212, mem_vec_4178);
											mem_vec_4178 = vec_239;



											vec_241 = _mm512_fmadd_ps(vec_240, vec_214, mem_vec_4179);
											mem_vec_4179 = vec_241;
											scal_76 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
											vec_243 = _mm512_set1_ps(scal_76);


											vec_242 = _mm512_fmadd_ps(vec_243, vec_212, mem_vec_4180);
											mem_vec_4180 = vec_242;



											vec_244 = _mm512_fmadd_ps(vec_243, vec_214, mem_vec_4181);
											mem_vec_4181 = vec_244;
											scal_77 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_246 = _mm512_set1_ps(scal_77);
											vec_247 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_245 = _mm512_fmadd_ps(vec_246, vec_247, mem_vec_4160);
											mem_vec_4160 = vec_245;

											vec_249 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_248 = _mm512_fmadd_ps(vec_246, vec_249, mem_vec_4161);
											mem_vec_4161 = vec_248;
											scal_78 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_251 = _mm512_set1_ps(scal_78);


											vec_250 = _mm512_fmadd_ps(vec_251, vec_247, mem_vec_4162);
											mem_vec_4162 = vec_250;



											vec_252 = _mm512_fmadd_ps(vec_251, vec_249, mem_vec_4163);
											mem_vec_4163 = vec_252;
											scal_79 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_254 = _mm512_set1_ps(scal_79);


											vec_253 = _mm512_fmadd_ps(vec_254, vec_247, mem_vec_4164);
											mem_vec_4164 = vec_253;



											vec_255 = _mm512_fmadd_ps(vec_254, vec_249, mem_vec_4165);
											mem_vec_4165 = vec_255;
											scal_80 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_257 = _mm512_set1_ps(scal_80);


											vec_256 = _mm512_fmadd_ps(vec_257, vec_247, mem_vec_4166);
											mem_vec_4166 = vec_256;



											vec_258 = _mm512_fmadd_ps(vec_257, vec_249, mem_vec_4167);
											mem_vec_4167 = vec_258;
											scal_81 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_260 = _mm512_set1_ps(scal_81);


											vec_259 = _mm512_fmadd_ps(vec_260, vec_247, mem_vec_4168);
											mem_vec_4168 = vec_259;



											vec_261 = _mm512_fmadd_ps(vec_260, vec_249, mem_vec_4169);
											mem_vec_4169 = vec_261;
											scal_82 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
											vec_263 = _mm512_set1_ps(scal_82);


											vec_262 = _mm512_fmadd_ps(vec_263, vec_247, mem_vec_4170);
											mem_vec_4170 = vec_262;



											vec_264 = _mm512_fmadd_ps(vec_263, vec_249, mem_vec_4171);
											mem_vec_4171 = vec_264;
											scal_83 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
											vec_266 = _mm512_set1_ps(scal_83);


											vec_265 = _mm512_fmadd_ps(vec_266, vec_247, mem_vec_4172);
											mem_vec_4172 = vec_265;



											vec_267 = _mm512_fmadd_ps(vec_266, vec_249, mem_vec_4173);
											mem_vec_4173 = vec_267;
											scal_84 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 1) + c];
											vec_269 = _mm512_set1_ps(scal_84);


											vec_268 = _mm512_fmadd_ps(vec_269, vec_247, mem_vec_4174);
											mem_vec_4174 = vec_268;



											vec_270 = _mm512_fmadd_ps(vec_269, vec_249, mem_vec_4175);
											mem_vec_4175 = vec_270;
											scal_85 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 1) + c];
											vec_272 = _mm512_set1_ps(scal_85);


											vec_271 = _mm512_fmadd_ps(vec_272, vec_247, mem_vec_4176);
											mem_vec_4176 = vec_271;



											vec_273 = _mm512_fmadd_ps(vec_272, vec_249, mem_vec_4177);
											mem_vec_4177 = vec_273;
											scal_86 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 1) + c];
											vec_275 = _mm512_set1_ps(scal_86);


											vec_274 = _mm512_fmadd_ps(vec_275, vec_247, mem_vec_4178);
											mem_vec_4178 = vec_274;



											vec_276 = _mm512_fmadd_ps(vec_275, vec_249, mem_vec_4179);
											mem_vec_4179 = vec_276;
											scal_87 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 1) + c];
											vec_278 = _mm512_set1_ps(scal_87);


											vec_277 = _mm512_fmadd_ps(vec_278, vec_247, mem_vec_4180);
											mem_vec_4180 = vec_277;



											vec_279 = _mm512_fmadd_ps(vec_278, vec_249, mem_vec_4181);
											mem_vec_4181 = vec_279;
											scal_88 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_281 = _mm512_set1_ps(scal_88);
											vec_282 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_280 = _mm512_fmadd_ps(vec_281, vec_282, mem_vec_4160);
											mem_vec_4160 = vec_280;

											vec_284 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_283 = _mm512_fmadd_ps(vec_281, vec_284, mem_vec_4161);
											mem_vec_4161 = vec_283;
											scal_89 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_286 = _mm512_set1_ps(scal_89);


											vec_285 = _mm512_fmadd_ps(vec_286, vec_282, mem_vec_4162);
											mem_vec_4162 = vec_285;



											vec_287 = _mm512_fmadd_ps(vec_286, vec_284, mem_vec_4163);
											mem_vec_4163 = vec_287;
											scal_90 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_289 = _mm512_set1_ps(scal_90);


											vec_288 = _mm512_fmadd_ps(vec_289, vec_282, mem_vec_4164);
											mem_vec_4164 = vec_288;



											vec_290 = _mm512_fmadd_ps(vec_289, vec_284, mem_vec_4165);
											mem_vec_4165 = vec_290;
											scal_91 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_292 = _mm512_set1_ps(scal_91);


											vec_291 = _mm512_fmadd_ps(vec_292, vec_282, mem_vec_4166);
											mem_vec_4166 = vec_291;



											vec_293 = _mm512_fmadd_ps(vec_292, vec_284, mem_vec_4167);
											mem_vec_4167 = vec_293;
											scal_92 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_295 = _mm512_set1_ps(scal_92);


											vec_294 = _mm512_fmadd_ps(vec_295, vec_282, mem_vec_4168);
											mem_vec_4168 = vec_294;



											vec_296 = _mm512_fmadd_ps(vec_295, vec_284, mem_vec_4169);
											mem_vec_4169 = vec_296;
											scal_93 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
											vec_298 = _mm512_set1_ps(scal_93);


											vec_297 = _mm512_fmadd_ps(vec_298, vec_282, mem_vec_4170);
											mem_vec_4170 = vec_297;



											vec_299 = _mm512_fmadd_ps(vec_298, vec_284, mem_vec_4171);
											mem_vec_4171 = vec_299;
											scal_94 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
											vec_301 = _mm512_set1_ps(scal_94);


											vec_300 = _mm512_fmadd_ps(vec_301, vec_282, mem_vec_4172);
											mem_vec_4172 = vec_300;



											vec_302 = _mm512_fmadd_ps(vec_301, vec_284, mem_vec_4173);
											mem_vec_4173 = vec_302;
											scal_95 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 2) + c];
											vec_304 = _mm512_set1_ps(scal_95);


											vec_303 = _mm512_fmadd_ps(vec_304, vec_282, mem_vec_4174);
											mem_vec_4174 = vec_303;



											vec_305 = _mm512_fmadd_ps(vec_304, vec_284, mem_vec_4175);
											mem_vec_4175 = vec_305;
											scal_96 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 2) + c];
											vec_307 = _mm512_set1_ps(scal_96);


											vec_306 = _mm512_fmadd_ps(vec_307, vec_282, mem_vec_4176);
											mem_vec_4176 = vec_306;



											vec_308 = _mm512_fmadd_ps(vec_307, vec_284, mem_vec_4177);
											mem_vec_4177 = vec_308;
											scal_97 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 2) + c];
											vec_310 = _mm512_set1_ps(scal_97);


											vec_309 = _mm512_fmadd_ps(vec_310, vec_282, mem_vec_4178);
											mem_vec_4178 = vec_309;



											vec_311 = _mm512_fmadd_ps(vec_310, vec_284, mem_vec_4179);
											mem_vec_4179 = vec_311;
											scal_98 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 2) + c];
											vec_313 = _mm512_set1_ps(scal_98);


											vec_312 = _mm512_fmadd_ps(vec_313, vec_282, mem_vec_4180);
											mem_vec_4180 = vec_312;



											vec_314 = _mm512_fmadd_ps(vec_313, vec_284, mem_vec_4181);
											mem_vec_4181 = vec_314;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4160);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4161);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4162);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4163);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4164);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4165);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4166);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4167);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4168);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4169);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4170);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4171);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4172);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4173);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4174);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4175);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4176);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4177);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4178);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4179);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4180);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4181);
							}
						}
					}
				}
		}
	}
}


}