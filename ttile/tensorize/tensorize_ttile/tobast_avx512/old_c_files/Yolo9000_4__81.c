#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); U (3, w); T (8, c); Hoist_vars [c];
  T (2, x); T (2, x);
  Lambda_apply y [((Iter 7), (Arg 10)); ((Iter 6), (Arg 11))]; T (4, f);
  T (8, c); T (34, x)]
*/
IND_TYPE c, cp_0, c1092_p_0, cp_1, c1092, f, fp_0, x, xp_0, x1386_p_0, x1387_p_0, xp_1, x1386_p_1, xp_2, x1386, x1387, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y728 = 0;
IND_TYPE x1388 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1093 = 0;
IND_TYPE f794 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_45 ,scal_46 ,scal_47 ,scal_48 ,scal_49 ,scal_5 ,scal_50 ,scal_51 ,scal_52 ,scal_53 ,scal_54 ,scal_55 ,scal_56 ,scal_57 ,scal_58 ,scal_59 ,scal_6 ,scal_60 ,scal_61 ,scal_62 ,scal_63 ,scal_64 ,scal_65 ,scal_66 ,scal_67 ,scal_68 ,scal_69 ,scal_7 ,scal_70 ,scal_71 ,scal_72 ,scal_73 ,scal_74 ,scal_75 ,scal_76 ,scal_77 ,scal_78 ,scal_79 ,scal_8 ,scal_80 ,scal_81 ,scal_82 ,scal_83 ,scal_84 ,scal_85 ,scal_86 ,scal_87 ,scal_88 ,scal_89 ,scal_9 ,scal_90 ,scal_91 ,scal_92 ,scal_93 ,scal_94 ,scal_95 ,scal_96 ,scal_97 ,scal_98;
__m512 mem_vec_11126 ,mem_vec_11127 ,mem_vec_11128 ,mem_vec_11129 ,mem_vec_11130 ,mem_vec_11131 ,mem_vec_11132 ,mem_vec_11133 ,mem_vec_11134 ,mem_vec_11135 ,mem_vec_11136 ,mem_vec_11137 ,mem_vec_11138 ,mem_vec_11139 ,mem_vec_11140 ,mem_vec_11141 ,mem_vec_11142 ,mem_vec_11143 ,mem_vec_11144 ,mem_vec_11145 ,mem_vec_11146 ,mem_vec_11147 ,mem_vec_11148 ,mem_vec_11149 ,mem_vec_11150 ,mem_vec_11151 ,mem_vec_11152 ,mem_vec_11153 ,mem_vec_11154 ,mem_vec_11155 ,mem_vec_11156 ,mem_vec_11157 ,mem_vec_11158 ,mem_vec_11159 ,mem_vec_11160 ,mem_vec_11161 ,mem_vec_11162 ,mem_vec_11163 ,mem_vec_11164 ,mem_vec_11165 ,mem_vec_11166 ,mem_vec_11167 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_132 ,vec_133 ,vec_134 ,vec_135 ,vec_136 ,vec_137 ,vec_138 ,vec_139 ,vec_14 ,vec_140 ,vec_141 ,vec_142 ,vec_143 ,vec_144 ,vec_145 ,vec_146 ,vec_147 ,vec_148 ,vec_149 ,vec_15 ,vec_150 ,vec_151 ,vec_152 ,vec_153 ,vec_154 ,vec_155 ,vec_156 ,vec_157 ,vec_158 ,vec_159 ,vec_16 ,vec_160 ,vec_161 ,vec_162 ,vec_163 ,vec_164 ,vec_165 ,vec_166 ,vec_167 ,vec_168 ,vec_169 ,vec_17 ,vec_170 ,vec_171 ,vec_172 ,vec_173 ,vec_174 ,vec_175 ,vec_176 ,vec_177 ,vec_178 ,vec_179 ,vec_18 ,vec_180 ,vec_181 ,vec_182 ,vec_183 ,vec_184 ,vec_185 ,vec_186 ,vec_187 ,vec_188 ,vec_189 ,vec_19 ,vec_190 ,vec_191 ,vec_192 ,vec_193 ,vec_194 ,vec_195 ,vec_196 ,vec_197 ,vec_198 ,vec_199 ,vec_2 ,vec_20 ,vec_200 ,vec_201 ,vec_202 ,vec_203 ,vec_204 ,vec_205 ,vec_206 ,vec_207 ,vec_208 ,vec_209 ,vec_21 ,vec_210 ,vec_211 ,vec_212 ,vec_213 ,vec_214 ,vec_215 ,vec_216 ,vec_217 ,vec_218 ,vec_219 ,vec_22 ,vec_220 ,vec_221 ,vec_222 ,vec_223 ,vec_224 ,vec_225 ,vec_226 ,vec_227 ,vec_228 ,vec_229 ,vec_23 ,vec_230 ,vec_231 ,vec_232 ,vec_233 ,vec_234 ,vec_235 ,vec_236 ,vec_237 ,vec_238 ,vec_239 ,vec_24 ,vec_240 ,vec_241 ,vec_242 ,vec_243 ,vec_244 ,vec_245 ,vec_246 ,vec_247 ,vec_248 ,vec_249 ,vec_25 ,vec_250 ,vec_251 ,vec_252 ,vec_253 ,vec_254 ,vec_255 ,vec_256 ,vec_257 ,vec_258 ,vec_259 ,vec_26 ,vec_260 ,vec_261 ,vec_262 ,vec_263 ,vec_264 ,vec_265 ,vec_266 ,vec_267 ,vec_268 ,vec_269 ,vec_27 ,vec_270 ,vec_271 ,vec_272 ,vec_273 ,vec_274 ,vec_275 ,vec_276 ,vec_277 ,vec_278 ,vec_279 ,vec_28 ,vec_280 ,vec_281 ,vec_282 ,vec_283 ,vec_284 ,vec_285 ,vec_286 ,vec_287 ,vec_288 ,vec_289 ,vec_29 ,vec_290 ,vec_291 ,vec_292 ,vec_293 ,vec_294 ,vec_295 ,vec_296 ,vec_297 ,vec_298 ,vec_299 ,vec_3 ,vec_30 ,vec_300 ,vec_301 ,vec_302 ,vec_303 ,vec_304 ,vec_305 ,vec_306 ,vec_307 ,vec_308 ,vec_309 ,vec_31 ,vec_310 ,vec_311 ,vec_312 ,vec_313 ,vec_314 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 34) (136 / 4)
for (x1387 = x1388, x1387_p_0 = 0;
	x1387 < x1388 + 136;
	x1387 += 4, x1387_p_0 += 4){
	// y = 136, x = 4, h = 3, w = 3, c = 64, f = 128
	// T (c, 8) (64 / 8)
	for (c1092 = c1093, c1092_p_0 = 0;
		c1092 < c1093 + 64;
		c1092 += 8, c1092_p_0 += 8){
		// y = 136, x = 4, h = 3, w = 3, c = 8, f = 128
		// T (f, 4) (128 / 32)
		for (f = f794, fp_0 = 0;
			f < f794 + 128;
			f += 32, fp_0 += 32){
				for (y = y728, yp_0 = 0;
					y < y728 + 70;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 32
					// T (x, 2) (4 / 2)
					for (x1386 = x1387, x1386_p_1 = x1387_p_0, x1386_p_0 = 0;
						x1386 < x1387 + 4;
						x1386 += 2, x1386_p_1 += 2, x1386_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
						// T (x, 2) (2 / 1)
						for (x = x1386, xp_2 = x1386_p_1, xp_1 = x1386_p_0, xp_0 = 0;
							x < x1386 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_11126 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_11127 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_11128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_11129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_11130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_11131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_11132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_11133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_11134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_11135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_11136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_11137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_11138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_11139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_11140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_11141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_11142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_11143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_11144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_11145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c1092, cp_1 = c1092_p_0, cp_0 = 0;
										c < c1092 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11126);
										mem_vec_11126 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11127);
										mem_vec_11127 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11128);
										mem_vec_11128 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11129);
										mem_vec_11129 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11130);
										mem_vec_11130 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11131);
										mem_vec_11131 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11132);
										mem_vec_11132 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11133);
										mem_vec_11133 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11134);
										mem_vec_11134 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11135);
										mem_vec_11135 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11136);
										mem_vec_11136 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11137);
										mem_vec_11137 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11138);
										mem_vec_11138 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11139);
										mem_vec_11139 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11140);
										mem_vec_11140 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11141);
										mem_vec_11141 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11142);
										mem_vec_11142 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11143);
										mem_vec_11143 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11144);
										mem_vec_11144 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11145);
										mem_vec_11145 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_33 = _mm512_set1_ps(scal_10);
										vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_11126);
										mem_vec_11126 = vec_32;

										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_11127);
										mem_vec_11127 = vec_35;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_11128);
										mem_vec_11128 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_11129);
										mem_vec_11129 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_11130);
										mem_vec_11130 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_11131);
										mem_vec_11131 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_11132);
										mem_vec_11132 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_11133);
										mem_vec_11133 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_11134);
										mem_vec_11134 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_11135);
										mem_vec_11135 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_11136);
										mem_vec_11136 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_11137);
										mem_vec_11137 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_53 = _mm512_set1_ps(scal_16);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_11138);
										mem_vec_11138 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_11139);
										mem_vec_11139 = vec_54;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_56 = _mm512_set1_ps(scal_17);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_11140);
										mem_vec_11140 = vec_55;



										vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_11141);
										mem_vec_11141 = vec_57;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_18);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_11142);
										mem_vec_11142 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_11143);
										mem_vec_11143 = vec_60;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
										vec_62 = _mm512_set1_ps(scal_19);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_11144);
										mem_vec_11144 = vec_61;



										vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_11145);
										mem_vec_11145 = vec_63;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_65 = _mm512_set1_ps(scal_20);
										vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_11126);
										mem_vec_11126 = vec_64;

										vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_11127);
										mem_vec_11127 = vec_67;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_70 = _mm512_set1_ps(scal_21);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_11128);
										mem_vec_11128 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_11129);
										mem_vec_11129 = vec_71;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_73 = _mm512_set1_ps(scal_22);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_11130);
										mem_vec_11130 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_11131);
										mem_vec_11131 = vec_74;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_11132);
										mem_vec_11132 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_11133);
										mem_vec_11133 = vec_77;
										scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_79 = _mm512_set1_ps(scal_24);


										vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_11134);
										mem_vec_11134 = vec_78;



										vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_11135);
										mem_vec_11135 = vec_80;
										scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_82 = _mm512_set1_ps(scal_25);


										vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_11136);
										mem_vec_11136 = vec_81;



										vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_11137);
										mem_vec_11137 = vec_83;
										scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_85 = _mm512_set1_ps(scal_26);


										vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_11138);
										mem_vec_11138 = vec_84;



										vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_11139);
										mem_vec_11139 = vec_86;
										scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_27);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_11140);
										mem_vec_11140 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_11141);
										mem_vec_11141 = vec_89;
										scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
										vec_91 = _mm512_set1_ps(scal_28);


										vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_11142);
										mem_vec_11142 = vec_90;



										vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_11143);
										mem_vec_11143 = vec_92;
										scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
										vec_94 = _mm512_set1_ps(scal_29);


										vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_11144);
										mem_vec_11144 = vec_93;



										vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_11145);
										mem_vec_11145 = vec_95;
										scal_30 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_97 = _mm512_set1_ps(scal_30);
										vec_98 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_96 = _mm512_fmadd_ps(vec_97, vec_98, mem_vec_11126);
										mem_vec_11126 = vec_96;

										vec_100 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_99 = _mm512_fmadd_ps(vec_97, vec_100, mem_vec_11127);
										mem_vec_11127 = vec_99;
										scal_31 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_102 = _mm512_set1_ps(scal_31);


										vec_101 = _mm512_fmadd_ps(vec_102, vec_98, mem_vec_11128);
										mem_vec_11128 = vec_101;



										vec_103 = _mm512_fmadd_ps(vec_102, vec_100, mem_vec_11129);
										mem_vec_11129 = vec_103;
										scal_32 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_105 = _mm512_set1_ps(scal_32);


										vec_104 = _mm512_fmadd_ps(vec_105, vec_98, mem_vec_11130);
										mem_vec_11130 = vec_104;



										vec_106 = _mm512_fmadd_ps(vec_105, vec_100, mem_vec_11131);
										mem_vec_11131 = vec_106;
										scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_108 = _mm512_set1_ps(scal_33);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_98, mem_vec_11132);
										mem_vec_11132 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_100, mem_vec_11133);
										mem_vec_11133 = vec_109;
										scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_111 = _mm512_set1_ps(scal_34);


										vec_110 = _mm512_fmadd_ps(vec_111, vec_98, mem_vec_11134);
										mem_vec_11134 = vec_110;



										vec_112 = _mm512_fmadd_ps(vec_111, vec_100, mem_vec_11135);
										mem_vec_11135 = vec_112;
										scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_114 = _mm512_set1_ps(scal_35);


										vec_113 = _mm512_fmadd_ps(vec_114, vec_98, mem_vec_11136);
										mem_vec_11136 = vec_113;



										vec_115 = _mm512_fmadd_ps(vec_114, vec_100, mem_vec_11137);
										mem_vec_11137 = vec_115;
										scal_36 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_117 = _mm512_set1_ps(scal_36);


										vec_116 = _mm512_fmadd_ps(vec_117, vec_98, mem_vec_11138);
										mem_vec_11138 = vec_116;



										vec_118 = _mm512_fmadd_ps(vec_117, vec_100, mem_vec_11139);
										mem_vec_11139 = vec_118;
										scal_37 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_120 = _mm512_set1_ps(scal_37);


										vec_119 = _mm512_fmadd_ps(vec_120, vec_98, mem_vec_11140);
										mem_vec_11140 = vec_119;



										vec_121 = _mm512_fmadd_ps(vec_120, vec_100, mem_vec_11141);
										mem_vec_11141 = vec_121;
										scal_38 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
										vec_123 = _mm512_set1_ps(scal_38);


										vec_122 = _mm512_fmadd_ps(vec_123, vec_98, mem_vec_11142);
										mem_vec_11142 = vec_122;



										vec_124 = _mm512_fmadd_ps(vec_123, vec_100, mem_vec_11143);
										mem_vec_11143 = vec_124;
										scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
										vec_126 = _mm512_set1_ps(scal_39);


										vec_125 = _mm512_fmadd_ps(vec_126, vec_98, mem_vec_11144);
										mem_vec_11144 = vec_125;



										vec_127 = _mm512_fmadd_ps(vec_126, vec_100, mem_vec_11145);
										mem_vec_11145 = vec_127;
										scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
										vec_129 = _mm512_set1_ps(scal_40);
										vec_130 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

										vec_128 = _mm512_fmadd_ps(vec_129, vec_130, mem_vec_11126);
										mem_vec_11126 = vec_128;

										vec_132 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f + 16]);

										vec_131 = _mm512_fmadd_ps(vec_129, vec_132, mem_vec_11127);
										mem_vec_11127 = vec_131;
										scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
										vec_134 = _mm512_set1_ps(scal_41);


										vec_133 = _mm512_fmadd_ps(vec_134, vec_130, mem_vec_11128);
										mem_vec_11128 = vec_133;



										vec_135 = _mm512_fmadd_ps(vec_134, vec_132, mem_vec_11129);
										mem_vec_11129 = vec_135;
										scal_42 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
										vec_137 = _mm512_set1_ps(scal_42);


										vec_136 = _mm512_fmadd_ps(vec_137, vec_130, mem_vec_11130);
										mem_vec_11130 = vec_136;



										vec_138 = _mm512_fmadd_ps(vec_137, vec_132, mem_vec_11131);
										mem_vec_11131 = vec_138;
										scal_43 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
										vec_140 = _mm512_set1_ps(scal_43);


										vec_139 = _mm512_fmadd_ps(vec_140, vec_130, mem_vec_11132);
										mem_vec_11132 = vec_139;



										vec_141 = _mm512_fmadd_ps(vec_140, vec_132, mem_vec_11133);
										mem_vec_11133 = vec_141;
										scal_44 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
										vec_143 = _mm512_set1_ps(scal_44);


										vec_142 = _mm512_fmadd_ps(vec_143, vec_130, mem_vec_11134);
										mem_vec_11134 = vec_142;



										vec_144 = _mm512_fmadd_ps(vec_143, vec_132, mem_vec_11135);
										mem_vec_11135 = vec_144;
										scal_45 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
										vec_146 = _mm512_set1_ps(scal_45);


										vec_145 = _mm512_fmadd_ps(vec_146, vec_130, mem_vec_11136);
										mem_vec_11136 = vec_145;



										vec_147 = _mm512_fmadd_ps(vec_146, vec_132, mem_vec_11137);
										mem_vec_11137 = vec_147;
										scal_46 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
										vec_149 = _mm512_set1_ps(scal_46);


										vec_148 = _mm512_fmadd_ps(vec_149, vec_130, mem_vec_11138);
										mem_vec_11138 = vec_148;



										vec_150 = _mm512_fmadd_ps(vec_149, vec_132, mem_vec_11139);
										mem_vec_11139 = vec_150;
										scal_47 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 1) + c];
										vec_152 = _mm512_set1_ps(scal_47);


										vec_151 = _mm512_fmadd_ps(vec_152, vec_130, mem_vec_11140);
										mem_vec_11140 = vec_151;



										vec_153 = _mm512_fmadd_ps(vec_152, vec_132, mem_vec_11141);
										mem_vec_11141 = vec_153;
										scal_48 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 1) + c];
										vec_155 = _mm512_set1_ps(scal_48);


										vec_154 = _mm512_fmadd_ps(vec_155, vec_130, mem_vec_11142);
										mem_vec_11142 = vec_154;



										vec_156 = _mm512_fmadd_ps(vec_155, vec_132, mem_vec_11143);
										mem_vec_11143 = vec_156;
										scal_49 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 1) + c];
										vec_158 = _mm512_set1_ps(scal_49);


										vec_157 = _mm512_fmadd_ps(vec_158, vec_130, mem_vec_11144);
										mem_vec_11144 = vec_157;



										vec_159 = _mm512_fmadd_ps(vec_158, vec_132, mem_vec_11145);
										mem_vec_11145 = vec_159;
										scal_50 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
										vec_161 = _mm512_set1_ps(scal_50);
										vec_162 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

										vec_160 = _mm512_fmadd_ps(vec_161, vec_162, mem_vec_11126);
										mem_vec_11126 = vec_160;

										vec_164 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f + 16]);

										vec_163 = _mm512_fmadd_ps(vec_161, vec_164, mem_vec_11127);
										mem_vec_11127 = vec_163;
										scal_51 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
										vec_166 = _mm512_set1_ps(scal_51);


										vec_165 = _mm512_fmadd_ps(vec_166, vec_162, mem_vec_11128);
										mem_vec_11128 = vec_165;



										vec_167 = _mm512_fmadd_ps(vec_166, vec_164, mem_vec_11129);
										mem_vec_11129 = vec_167;
										scal_52 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
										vec_169 = _mm512_set1_ps(scal_52);


										vec_168 = _mm512_fmadd_ps(vec_169, vec_162, mem_vec_11130);
										mem_vec_11130 = vec_168;



										vec_170 = _mm512_fmadd_ps(vec_169, vec_164, mem_vec_11131);
										mem_vec_11131 = vec_170;
										scal_53 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
										vec_172 = _mm512_set1_ps(scal_53);


										vec_171 = _mm512_fmadd_ps(vec_172, vec_162, mem_vec_11132);
										mem_vec_11132 = vec_171;



										vec_173 = _mm512_fmadd_ps(vec_172, vec_164, mem_vec_11133);
										mem_vec_11133 = vec_173;
										scal_54 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
										vec_175 = _mm512_set1_ps(scal_54);


										vec_174 = _mm512_fmadd_ps(vec_175, vec_162, mem_vec_11134);
										mem_vec_11134 = vec_174;



										vec_176 = _mm512_fmadd_ps(vec_175, vec_164, mem_vec_11135);
										mem_vec_11135 = vec_176;
										scal_55 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
										vec_178 = _mm512_set1_ps(scal_55);


										vec_177 = _mm512_fmadd_ps(vec_178, vec_162, mem_vec_11136);
										mem_vec_11136 = vec_177;



										vec_179 = _mm512_fmadd_ps(vec_178, vec_164, mem_vec_11137);
										mem_vec_11137 = vec_179;
										scal_56 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
										vec_181 = _mm512_set1_ps(scal_56);


										vec_180 = _mm512_fmadd_ps(vec_181, vec_162, mem_vec_11138);
										mem_vec_11138 = vec_180;



										vec_182 = _mm512_fmadd_ps(vec_181, vec_164, mem_vec_11139);
										mem_vec_11139 = vec_182;
										scal_57 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 2) + c];
										vec_184 = _mm512_set1_ps(scal_57);


										vec_183 = _mm512_fmadd_ps(vec_184, vec_162, mem_vec_11140);
										mem_vec_11140 = vec_183;



										vec_185 = _mm512_fmadd_ps(vec_184, vec_164, mem_vec_11141);
										mem_vec_11141 = vec_185;
										scal_58 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 2) + c];
										vec_187 = _mm512_set1_ps(scal_58);


										vec_186 = _mm512_fmadd_ps(vec_187, vec_162, mem_vec_11142);
										mem_vec_11142 = vec_186;



										vec_188 = _mm512_fmadd_ps(vec_187, vec_164, mem_vec_11143);
										mem_vec_11143 = vec_188;
										scal_59 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 2) + c];
										vec_190 = _mm512_set1_ps(scal_59);


										vec_189 = _mm512_fmadd_ps(vec_190, vec_162, mem_vec_11144);
										mem_vec_11144 = vec_189;



										vec_191 = _mm512_fmadd_ps(vec_190, vec_164, mem_vec_11145);
										mem_vec_11145 = vec_191;
										scal_60 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_193 = _mm512_set1_ps(scal_60);
										vec_194 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_192 = _mm512_fmadd_ps(vec_193, vec_194, mem_vec_11126);
										mem_vec_11126 = vec_192;

										vec_196 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_195 = _mm512_fmadd_ps(vec_193, vec_196, mem_vec_11127);
										mem_vec_11127 = vec_195;
										scal_61 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_198 = _mm512_set1_ps(scal_61);


										vec_197 = _mm512_fmadd_ps(vec_198, vec_194, mem_vec_11128);
										mem_vec_11128 = vec_197;



										vec_199 = _mm512_fmadd_ps(vec_198, vec_196, mem_vec_11129);
										mem_vec_11129 = vec_199;
										scal_62 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_201 = _mm512_set1_ps(scal_62);


										vec_200 = _mm512_fmadd_ps(vec_201, vec_194, mem_vec_11130);
										mem_vec_11130 = vec_200;



										vec_202 = _mm512_fmadd_ps(vec_201, vec_196, mem_vec_11131);
										mem_vec_11131 = vec_202;
										scal_63 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_204 = _mm512_set1_ps(scal_63);


										vec_203 = _mm512_fmadd_ps(vec_204, vec_194, mem_vec_11132);
										mem_vec_11132 = vec_203;



										vec_205 = _mm512_fmadd_ps(vec_204, vec_196, mem_vec_11133);
										mem_vec_11133 = vec_205;
										scal_64 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_207 = _mm512_set1_ps(scal_64);


										vec_206 = _mm512_fmadd_ps(vec_207, vec_194, mem_vec_11134);
										mem_vec_11134 = vec_206;



										vec_208 = _mm512_fmadd_ps(vec_207, vec_196, mem_vec_11135);
										mem_vec_11135 = vec_208;
										scal_65 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_210 = _mm512_set1_ps(scal_65);


										vec_209 = _mm512_fmadd_ps(vec_210, vec_194, mem_vec_11136);
										mem_vec_11136 = vec_209;



										vec_211 = _mm512_fmadd_ps(vec_210, vec_196, mem_vec_11137);
										mem_vec_11137 = vec_211;
										scal_66 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_213 = _mm512_set1_ps(scal_66);


										vec_212 = _mm512_fmadd_ps(vec_213, vec_194, mem_vec_11138);
										mem_vec_11138 = vec_212;



										vec_214 = _mm512_fmadd_ps(vec_213, vec_196, mem_vec_11139);
										mem_vec_11139 = vec_214;
										scal_67 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_216 = _mm512_set1_ps(scal_67);


										vec_215 = _mm512_fmadd_ps(vec_216, vec_194, mem_vec_11140);
										mem_vec_11140 = vec_215;



										vec_217 = _mm512_fmadd_ps(vec_216, vec_196, mem_vec_11141);
										mem_vec_11141 = vec_217;
										scal_68 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
										vec_219 = _mm512_set1_ps(scal_68);


										vec_218 = _mm512_fmadd_ps(vec_219, vec_194, mem_vec_11142);
										mem_vec_11142 = vec_218;



										vec_220 = _mm512_fmadd_ps(vec_219, vec_196, mem_vec_11143);
										mem_vec_11143 = vec_220;
										scal_69 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
										vec_222 = _mm512_set1_ps(scal_69);


										vec_221 = _mm512_fmadd_ps(vec_222, vec_194, mem_vec_11144);
										mem_vec_11144 = vec_221;



										vec_223 = _mm512_fmadd_ps(vec_222, vec_196, mem_vec_11145);
										mem_vec_11145 = vec_223;
										scal_70 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
										vec_225 = _mm512_set1_ps(scal_70);
										vec_226 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

										vec_224 = _mm512_fmadd_ps(vec_225, vec_226, mem_vec_11126);
										mem_vec_11126 = vec_224;

										vec_228 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f + 16]);

										vec_227 = _mm512_fmadd_ps(vec_225, vec_228, mem_vec_11127);
										mem_vec_11127 = vec_227;
										scal_71 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
										vec_230 = _mm512_set1_ps(scal_71);


										vec_229 = _mm512_fmadd_ps(vec_230, vec_226, mem_vec_11128);
										mem_vec_11128 = vec_229;



										vec_231 = _mm512_fmadd_ps(vec_230, vec_228, mem_vec_11129);
										mem_vec_11129 = vec_231;
										scal_72 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
										vec_233 = _mm512_set1_ps(scal_72);


										vec_232 = _mm512_fmadd_ps(vec_233, vec_226, mem_vec_11130);
										mem_vec_11130 = vec_232;



										vec_234 = _mm512_fmadd_ps(vec_233, vec_228, mem_vec_11131);
										mem_vec_11131 = vec_234;
										scal_73 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
										vec_236 = _mm512_set1_ps(scal_73);


										vec_235 = _mm512_fmadd_ps(vec_236, vec_226, mem_vec_11132);
										mem_vec_11132 = vec_235;



										vec_237 = _mm512_fmadd_ps(vec_236, vec_228, mem_vec_11133);
										mem_vec_11133 = vec_237;
										scal_74 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
										vec_239 = _mm512_set1_ps(scal_74);


										vec_238 = _mm512_fmadd_ps(vec_239, vec_226, mem_vec_11134);
										mem_vec_11134 = vec_238;



										vec_240 = _mm512_fmadd_ps(vec_239, vec_228, mem_vec_11135);
										mem_vec_11135 = vec_240;
										scal_75 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
										vec_242 = _mm512_set1_ps(scal_75);


										vec_241 = _mm512_fmadd_ps(vec_242, vec_226, mem_vec_11136);
										mem_vec_11136 = vec_241;



										vec_243 = _mm512_fmadd_ps(vec_242, vec_228, mem_vec_11137);
										mem_vec_11137 = vec_243;
										scal_76 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
										vec_245 = _mm512_set1_ps(scal_76);


										vec_244 = _mm512_fmadd_ps(vec_245, vec_226, mem_vec_11138);
										mem_vec_11138 = vec_244;



										vec_246 = _mm512_fmadd_ps(vec_245, vec_228, mem_vec_11139);
										mem_vec_11139 = vec_246;
										scal_77 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 1) + c];
										vec_248 = _mm512_set1_ps(scal_77);


										vec_247 = _mm512_fmadd_ps(vec_248, vec_226, mem_vec_11140);
										mem_vec_11140 = vec_247;



										vec_249 = _mm512_fmadd_ps(vec_248, vec_228, mem_vec_11141);
										mem_vec_11141 = vec_249;
										scal_78 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 1) + c];
										vec_251 = _mm512_set1_ps(scal_78);


										vec_250 = _mm512_fmadd_ps(vec_251, vec_226, mem_vec_11142);
										mem_vec_11142 = vec_250;



										vec_252 = _mm512_fmadd_ps(vec_251, vec_228, mem_vec_11143);
										mem_vec_11143 = vec_252;
										scal_79 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 1) + c];
										vec_254 = _mm512_set1_ps(scal_79);


										vec_253 = _mm512_fmadd_ps(vec_254, vec_226, mem_vec_11144);
										mem_vec_11144 = vec_253;



										vec_255 = _mm512_fmadd_ps(vec_254, vec_228, mem_vec_11145);
										mem_vec_11145 = vec_255;
										scal_80 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
										vec_257 = _mm512_set1_ps(scal_80);
										vec_258 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

										vec_256 = _mm512_fmadd_ps(vec_257, vec_258, mem_vec_11126);
										mem_vec_11126 = vec_256;

										vec_260 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f + 16]);

										vec_259 = _mm512_fmadd_ps(vec_257, vec_260, mem_vec_11127);
										mem_vec_11127 = vec_259;
										scal_81 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
										vec_262 = _mm512_set1_ps(scal_81);


										vec_261 = _mm512_fmadd_ps(vec_262, vec_258, mem_vec_11128);
										mem_vec_11128 = vec_261;



										vec_263 = _mm512_fmadd_ps(vec_262, vec_260, mem_vec_11129);
										mem_vec_11129 = vec_263;
										scal_82 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
										vec_265 = _mm512_set1_ps(scal_82);


										vec_264 = _mm512_fmadd_ps(vec_265, vec_258, mem_vec_11130);
										mem_vec_11130 = vec_264;



										vec_266 = _mm512_fmadd_ps(vec_265, vec_260, mem_vec_11131);
										mem_vec_11131 = vec_266;
										scal_83 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
										vec_268 = _mm512_set1_ps(scal_83);


										vec_267 = _mm512_fmadd_ps(vec_268, vec_258, mem_vec_11132);
										mem_vec_11132 = vec_267;



										vec_269 = _mm512_fmadd_ps(vec_268, vec_260, mem_vec_11133);
										mem_vec_11133 = vec_269;
										scal_84 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
										vec_271 = _mm512_set1_ps(scal_84);


										vec_270 = _mm512_fmadd_ps(vec_271, vec_258, mem_vec_11134);
										mem_vec_11134 = vec_270;



										vec_272 = _mm512_fmadd_ps(vec_271, vec_260, mem_vec_11135);
										mem_vec_11135 = vec_272;
										scal_85 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
										vec_274 = _mm512_set1_ps(scal_85);


										vec_273 = _mm512_fmadd_ps(vec_274, vec_258, mem_vec_11136);
										mem_vec_11136 = vec_273;



										vec_275 = _mm512_fmadd_ps(vec_274, vec_260, mem_vec_11137);
										mem_vec_11137 = vec_275;
										scal_86 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
										vec_277 = _mm512_set1_ps(scal_86);


										vec_276 = _mm512_fmadd_ps(vec_277, vec_258, mem_vec_11138);
										mem_vec_11138 = vec_276;



										vec_278 = _mm512_fmadd_ps(vec_277, vec_260, mem_vec_11139);
										mem_vec_11139 = vec_278;
										scal_87 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 2) + c];
										vec_280 = _mm512_set1_ps(scal_87);


										vec_279 = _mm512_fmadd_ps(vec_280, vec_258, mem_vec_11140);
										mem_vec_11140 = vec_279;



										vec_281 = _mm512_fmadd_ps(vec_280, vec_260, mem_vec_11141);
										mem_vec_11141 = vec_281;
										scal_88 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 2) + c];
										vec_283 = _mm512_set1_ps(scal_88);


										vec_282 = _mm512_fmadd_ps(vec_283, vec_258, mem_vec_11142);
										mem_vec_11142 = vec_282;



										vec_284 = _mm512_fmadd_ps(vec_283, vec_260, mem_vec_11143);
										mem_vec_11143 = vec_284;
										scal_89 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 2) + c];
										vec_286 = _mm512_set1_ps(scal_89);


										vec_285 = _mm512_fmadd_ps(vec_286, vec_258, mem_vec_11144);
										mem_vec_11144 = vec_285;



										vec_287 = _mm512_fmadd_ps(vec_286, vec_260, mem_vec_11145);
										mem_vec_11145 = vec_287;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11126);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11127);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11128);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11129);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11130);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11131);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11132);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11133);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11134);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11135);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11136);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11137);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11138);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11139);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11140);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11141);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11142);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11143);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11144);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11145);
						}
					}
				}
				for (y = y728 + 70, yp_0 = 0;
					y < y728 + 70 + 66;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 32
					// T (x, 2) (4 / 2)
					for (x1386 = x1387, x1386_p_1 = x1387_p_0, x1386_p_0 = 0;
						x1386 < x1387 + 4;
						x1386 += 2, x1386_p_1 += 2, x1386_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
						// T (x, 2) (2 / 1)
						for (x = x1386, xp_2 = x1386_p_1, xp_1 = x1386_p_0, xp_0 = 0;
							x < x1386 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_11146 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_11147 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_11148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_11149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_11150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_11151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_11152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_11153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_11154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_11155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_11156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_11157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_11158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_11159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_11160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_11161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_11162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_11163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_11164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_11165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_11166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_11167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c1092, cp_1 = c1092_p_0, cp_0 = 0;
										c < c1092 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11146);
										mem_vec_11146 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11147);
										mem_vec_11147 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11148);
										mem_vec_11148 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11149);
										mem_vec_11149 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11150);
										mem_vec_11150 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11151);
										mem_vec_11151 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11152);
										mem_vec_11152 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11153);
										mem_vec_11153 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11154);
										mem_vec_11154 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11155);
										mem_vec_11155 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11156);
										mem_vec_11156 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11157);
										mem_vec_11157 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11158);
										mem_vec_11158 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11159);
										mem_vec_11159 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11160);
										mem_vec_11160 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11161);
										mem_vec_11161 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11162);
										mem_vec_11162 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11163);
										mem_vec_11163 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11164);
										mem_vec_11164 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11165);
										mem_vec_11165 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11166);
										mem_vec_11166 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11167);
										mem_vec_11167 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_36 = _mm512_set1_ps(scal_11);
										vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_11146);
										mem_vec_11146 = vec_35;

										vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_11147);
										mem_vec_11147 = vec_38;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_11148);
										mem_vec_11148 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_11149);
										mem_vec_11149 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_11150);
										mem_vec_11150 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_11151);
										mem_vec_11151 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_11152);
										mem_vec_11152 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_11153);
										mem_vec_11153 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_11154);
										mem_vec_11154 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_11155);
										mem_vec_11155 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_53 = _mm512_set1_ps(scal_16);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_11156);
										mem_vec_11156 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_11157);
										mem_vec_11157 = vec_54;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_56 = _mm512_set1_ps(scal_17);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_11158);
										mem_vec_11158 = vec_55;



										vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_11159);
										mem_vec_11159 = vec_57;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_18);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_11160);
										mem_vec_11160 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_11161);
										mem_vec_11161 = vec_60;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
										vec_62 = _mm512_set1_ps(scal_19);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_11162);
										mem_vec_11162 = vec_61;



										vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_11163);
										mem_vec_11163 = vec_63;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
										vec_65 = _mm512_set1_ps(scal_20);


										vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_11164);
										mem_vec_11164 = vec_64;



										vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_11165);
										mem_vec_11165 = vec_66;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
										vec_68 = _mm512_set1_ps(scal_21);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_11166);
										mem_vec_11166 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_11167);
										mem_vec_11167 = vec_69;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_71 = _mm512_set1_ps(scal_22);
										vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_11146);
										mem_vec_11146 = vec_70;

										vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_11147);
										mem_vec_11147 = vec_73;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_11148);
										mem_vec_11148 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_11149);
										mem_vec_11149 = vec_77;
										scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_79 = _mm512_set1_ps(scal_24);


										vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_11150);
										mem_vec_11150 = vec_78;



										vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_11151);
										mem_vec_11151 = vec_80;
										scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_82 = _mm512_set1_ps(scal_25);


										vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_11152);
										mem_vec_11152 = vec_81;



										vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_11153);
										mem_vec_11153 = vec_83;
										scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_85 = _mm512_set1_ps(scal_26);


										vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_11154);
										mem_vec_11154 = vec_84;



										vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_11155);
										mem_vec_11155 = vec_86;
										scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_27);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_11156);
										mem_vec_11156 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_11157);
										mem_vec_11157 = vec_89;
										scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_91 = _mm512_set1_ps(scal_28);


										vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_11158);
										mem_vec_11158 = vec_90;



										vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_11159);
										mem_vec_11159 = vec_92;
										scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_94 = _mm512_set1_ps(scal_29);


										vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_11160);
										mem_vec_11160 = vec_93;



										vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_11161);
										mem_vec_11161 = vec_95;
										scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
										vec_97 = _mm512_set1_ps(scal_30);


										vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_11162);
										mem_vec_11162 = vec_96;



										vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_11163);
										mem_vec_11163 = vec_98;
										scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
										vec_100 = _mm512_set1_ps(scal_31);


										vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_11164);
										mem_vec_11164 = vec_99;



										vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_11165);
										mem_vec_11165 = vec_101;
										scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
										vec_103 = _mm512_set1_ps(scal_32);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_11166);
										mem_vec_11166 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_11167);
										mem_vec_11167 = vec_104;
										scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_106 = _mm512_set1_ps(scal_33);
										vec_107 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_105 = _mm512_fmadd_ps(vec_106, vec_107, mem_vec_11146);
										mem_vec_11146 = vec_105;

										vec_109 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_108 = _mm512_fmadd_ps(vec_106, vec_109, mem_vec_11147);
										mem_vec_11147 = vec_108;
										scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_111 = _mm512_set1_ps(scal_34);


										vec_110 = _mm512_fmadd_ps(vec_111, vec_107, mem_vec_11148);
										mem_vec_11148 = vec_110;



										vec_112 = _mm512_fmadd_ps(vec_111, vec_109, mem_vec_11149);
										mem_vec_11149 = vec_112;
										scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_114 = _mm512_set1_ps(scal_35);


										vec_113 = _mm512_fmadd_ps(vec_114, vec_107, mem_vec_11150);
										mem_vec_11150 = vec_113;



										vec_115 = _mm512_fmadd_ps(vec_114, vec_109, mem_vec_11151);
										mem_vec_11151 = vec_115;
										scal_36 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_117 = _mm512_set1_ps(scal_36);


										vec_116 = _mm512_fmadd_ps(vec_117, vec_107, mem_vec_11152);
										mem_vec_11152 = vec_116;



										vec_118 = _mm512_fmadd_ps(vec_117, vec_109, mem_vec_11153);
										mem_vec_11153 = vec_118;
										scal_37 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_120 = _mm512_set1_ps(scal_37);


										vec_119 = _mm512_fmadd_ps(vec_120, vec_107, mem_vec_11154);
										mem_vec_11154 = vec_119;



										vec_121 = _mm512_fmadd_ps(vec_120, vec_109, mem_vec_11155);
										mem_vec_11155 = vec_121;
										scal_38 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_123 = _mm512_set1_ps(scal_38);


										vec_122 = _mm512_fmadd_ps(vec_123, vec_107, mem_vec_11156);
										mem_vec_11156 = vec_122;



										vec_124 = _mm512_fmadd_ps(vec_123, vec_109, mem_vec_11157);
										mem_vec_11157 = vec_124;
										scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_126 = _mm512_set1_ps(scal_39);


										vec_125 = _mm512_fmadd_ps(vec_126, vec_107, mem_vec_11158);
										mem_vec_11158 = vec_125;



										vec_127 = _mm512_fmadd_ps(vec_126, vec_109, mem_vec_11159);
										mem_vec_11159 = vec_127;
										scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_129 = _mm512_set1_ps(scal_40);


										vec_128 = _mm512_fmadd_ps(vec_129, vec_107, mem_vec_11160);
										mem_vec_11160 = vec_128;



										vec_130 = _mm512_fmadd_ps(vec_129, vec_109, mem_vec_11161);
										mem_vec_11161 = vec_130;
										scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
										vec_132 = _mm512_set1_ps(scal_41);


										vec_131 = _mm512_fmadd_ps(vec_132, vec_107, mem_vec_11162);
										mem_vec_11162 = vec_131;



										vec_133 = _mm512_fmadd_ps(vec_132, vec_109, mem_vec_11163);
										mem_vec_11163 = vec_133;
										scal_42 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
										vec_135 = _mm512_set1_ps(scal_42);


										vec_134 = _mm512_fmadd_ps(vec_135, vec_107, mem_vec_11164);
										mem_vec_11164 = vec_134;



										vec_136 = _mm512_fmadd_ps(vec_135, vec_109, mem_vec_11165);
										mem_vec_11165 = vec_136;
										scal_43 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
										vec_138 = _mm512_set1_ps(scal_43);


										vec_137 = _mm512_fmadd_ps(vec_138, vec_107, mem_vec_11166);
										mem_vec_11166 = vec_137;



										vec_139 = _mm512_fmadd_ps(vec_138, vec_109, mem_vec_11167);
										mem_vec_11167 = vec_139;
										scal_44 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
										vec_141 = _mm512_set1_ps(scal_44);
										vec_142 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

										vec_140 = _mm512_fmadd_ps(vec_141, vec_142, mem_vec_11146);
										mem_vec_11146 = vec_140;

										vec_144 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f + 16]);

										vec_143 = _mm512_fmadd_ps(vec_141, vec_144, mem_vec_11147);
										mem_vec_11147 = vec_143;
										scal_45 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
										vec_146 = _mm512_set1_ps(scal_45);


										vec_145 = _mm512_fmadd_ps(vec_146, vec_142, mem_vec_11148);
										mem_vec_11148 = vec_145;



										vec_147 = _mm512_fmadd_ps(vec_146, vec_144, mem_vec_11149);
										mem_vec_11149 = vec_147;
										scal_46 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
										vec_149 = _mm512_set1_ps(scal_46);


										vec_148 = _mm512_fmadd_ps(vec_149, vec_142, mem_vec_11150);
										mem_vec_11150 = vec_148;



										vec_150 = _mm512_fmadd_ps(vec_149, vec_144, mem_vec_11151);
										mem_vec_11151 = vec_150;
										scal_47 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
										vec_152 = _mm512_set1_ps(scal_47);


										vec_151 = _mm512_fmadd_ps(vec_152, vec_142, mem_vec_11152);
										mem_vec_11152 = vec_151;



										vec_153 = _mm512_fmadd_ps(vec_152, vec_144, mem_vec_11153);
										mem_vec_11153 = vec_153;
										scal_48 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
										vec_155 = _mm512_set1_ps(scal_48);


										vec_154 = _mm512_fmadd_ps(vec_155, vec_142, mem_vec_11154);
										mem_vec_11154 = vec_154;



										vec_156 = _mm512_fmadd_ps(vec_155, vec_144, mem_vec_11155);
										mem_vec_11155 = vec_156;
										scal_49 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
										vec_158 = _mm512_set1_ps(scal_49);


										vec_157 = _mm512_fmadd_ps(vec_158, vec_142, mem_vec_11156);
										mem_vec_11156 = vec_157;



										vec_159 = _mm512_fmadd_ps(vec_158, vec_144, mem_vec_11157);
										mem_vec_11157 = vec_159;
										scal_50 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
										vec_161 = _mm512_set1_ps(scal_50);


										vec_160 = _mm512_fmadd_ps(vec_161, vec_142, mem_vec_11158);
										mem_vec_11158 = vec_160;



										vec_162 = _mm512_fmadd_ps(vec_161, vec_144, mem_vec_11159);
										mem_vec_11159 = vec_162;
										scal_51 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 1) + c];
										vec_164 = _mm512_set1_ps(scal_51);


										vec_163 = _mm512_fmadd_ps(vec_164, vec_142, mem_vec_11160);
										mem_vec_11160 = vec_163;



										vec_165 = _mm512_fmadd_ps(vec_164, vec_144, mem_vec_11161);
										mem_vec_11161 = vec_165;
										scal_52 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 1) + c];
										vec_167 = _mm512_set1_ps(scal_52);


										vec_166 = _mm512_fmadd_ps(vec_167, vec_142, mem_vec_11162);
										mem_vec_11162 = vec_166;



										vec_168 = _mm512_fmadd_ps(vec_167, vec_144, mem_vec_11163);
										mem_vec_11163 = vec_168;
										scal_53 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 1) + c];
										vec_170 = _mm512_set1_ps(scal_53);


										vec_169 = _mm512_fmadd_ps(vec_170, vec_142, mem_vec_11164);
										mem_vec_11164 = vec_169;



										vec_171 = _mm512_fmadd_ps(vec_170, vec_144, mem_vec_11165);
										mem_vec_11165 = vec_171;
										scal_54 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 1) + c];
										vec_173 = _mm512_set1_ps(scal_54);


										vec_172 = _mm512_fmadd_ps(vec_173, vec_142, mem_vec_11166);
										mem_vec_11166 = vec_172;



										vec_174 = _mm512_fmadd_ps(vec_173, vec_144, mem_vec_11167);
										mem_vec_11167 = vec_174;
										scal_55 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
										vec_176 = _mm512_set1_ps(scal_55);
										vec_177 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

										vec_175 = _mm512_fmadd_ps(vec_176, vec_177, mem_vec_11146);
										mem_vec_11146 = vec_175;

										vec_179 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f + 16]);

										vec_178 = _mm512_fmadd_ps(vec_176, vec_179, mem_vec_11147);
										mem_vec_11147 = vec_178;
										scal_56 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
										vec_181 = _mm512_set1_ps(scal_56);


										vec_180 = _mm512_fmadd_ps(vec_181, vec_177, mem_vec_11148);
										mem_vec_11148 = vec_180;



										vec_182 = _mm512_fmadd_ps(vec_181, vec_179, mem_vec_11149);
										mem_vec_11149 = vec_182;
										scal_57 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
										vec_184 = _mm512_set1_ps(scal_57);


										vec_183 = _mm512_fmadd_ps(vec_184, vec_177, mem_vec_11150);
										mem_vec_11150 = vec_183;



										vec_185 = _mm512_fmadd_ps(vec_184, vec_179, mem_vec_11151);
										mem_vec_11151 = vec_185;
										scal_58 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
										vec_187 = _mm512_set1_ps(scal_58);


										vec_186 = _mm512_fmadd_ps(vec_187, vec_177, mem_vec_11152);
										mem_vec_11152 = vec_186;



										vec_188 = _mm512_fmadd_ps(vec_187, vec_179, mem_vec_11153);
										mem_vec_11153 = vec_188;
										scal_59 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
										vec_190 = _mm512_set1_ps(scal_59);


										vec_189 = _mm512_fmadd_ps(vec_190, vec_177, mem_vec_11154);
										mem_vec_11154 = vec_189;



										vec_191 = _mm512_fmadd_ps(vec_190, vec_179, mem_vec_11155);
										mem_vec_11155 = vec_191;
										scal_60 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
										vec_193 = _mm512_set1_ps(scal_60);


										vec_192 = _mm512_fmadd_ps(vec_193, vec_177, mem_vec_11156);
										mem_vec_11156 = vec_192;



										vec_194 = _mm512_fmadd_ps(vec_193, vec_179, mem_vec_11157);
										mem_vec_11157 = vec_194;
										scal_61 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
										vec_196 = _mm512_set1_ps(scal_61);


										vec_195 = _mm512_fmadd_ps(vec_196, vec_177, mem_vec_11158);
										mem_vec_11158 = vec_195;



										vec_197 = _mm512_fmadd_ps(vec_196, vec_179, mem_vec_11159);
										mem_vec_11159 = vec_197;
										scal_62 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 2) + c];
										vec_199 = _mm512_set1_ps(scal_62);


										vec_198 = _mm512_fmadd_ps(vec_199, vec_177, mem_vec_11160);
										mem_vec_11160 = vec_198;



										vec_200 = _mm512_fmadd_ps(vec_199, vec_179, mem_vec_11161);
										mem_vec_11161 = vec_200;
										scal_63 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 2) + c];
										vec_202 = _mm512_set1_ps(scal_63);


										vec_201 = _mm512_fmadd_ps(vec_202, vec_177, mem_vec_11162);
										mem_vec_11162 = vec_201;



										vec_203 = _mm512_fmadd_ps(vec_202, vec_179, mem_vec_11163);
										mem_vec_11163 = vec_203;
										scal_64 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 2) + c];
										vec_205 = _mm512_set1_ps(scal_64);


										vec_204 = _mm512_fmadd_ps(vec_205, vec_177, mem_vec_11164);
										mem_vec_11164 = vec_204;



										vec_206 = _mm512_fmadd_ps(vec_205, vec_179, mem_vec_11165);
										mem_vec_11165 = vec_206;
										scal_65 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 2) + c];
										vec_208 = _mm512_set1_ps(scal_65);


										vec_207 = _mm512_fmadd_ps(vec_208, vec_177, mem_vec_11166);
										mem_vec_11166 = vec_207;



										vec_209 = _mm512_fmadd_ps(vec_208, vec_179, mem_vec_11167);
										mem_vec_11167 = vec_209;
										scal_66 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_211 = _mm512_set1_ps(scal_66);
										vec_212 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_210 = _mm512_fmadd_ps(vec_211, vec_212, mem_vec_11146);
										mem_vec_11146 = vec_210;

										vec_214 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_213 = _mm512_fmadd_ps(vec_211, vec_214, mem_vec_11147);
										mem_vec_11147 = vec_213;
										scal_67 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_216 = _mm512_set1_ps(scal_67);


										vec_215 = _mm512_fmadd_ps(vec_216, vec_212, mem_vec_11148);
										mem_vec_11148 = vec_215;



										vec_217 = _mm512_fmadd_ps(vec_216, vec_214, mem_vec_11149);
										mem_vec_11149 = vec_217;
										scal_68 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_219 = _mm512_set1_ps(scal_68);


										vec_218 = _mm512_fmadd_ps(vec_219, vec_212, mem_vec_11150);
										mem_vec_11150 = vec_218;



										vec_220 = _mm512_fmadd_ps(vec_219, vec_214, mem_vec_11151);
										mem_vec_11151 = vec_220;
										scal_69 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_222 = _mm512_set1_ps(scal_69);


										vec_221 = _mm512_fmadd_ps(vec_222, vec_212, mem_vec_11152);
										mem_vec_11152 = vec_221;



										vec_223 = _mm512_fmadd_ps(vec_222, vec_214, mem_vec_11153);
										mem_vec_11153 = vec_223;
										scal_70 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_225 = _mm512_set1_ps(scal_70);


										vec_224 = _mm512_fmadd_ps(vec_225, vec_212, mem_vec_11154);
										mem_vec_11154 = vec_224;



										vec_226 = _mm512_fmadd_ps(vec_225, vec_214, mem_vec_11155);
										mem_vec_11155 = vec_226;
										scal_71 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_228 = _mm512_set1_ps(scal_71);


										vec_227 = _mm512_fmadd_ps(vec_228, vec_212, mem_vec_11156);
										mem_vec_11156 = vec_227;



										vec_229 = _mm512_fmadd_ps(vec_228, vec_214, mem_vec_11157);
										mem_vec_11157 = vec_229;
										scal_72 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_231 = _mm512_set1_ps(scal_72);


										vec_230 = _mm512_fmadd_ps(vec_231, vec_212, mem_vec_11158);
										mem_vec_11158 = vec_230;



										vec_232 = _mm512_fmadd_ps(vec_231, vec_214, mem_vec_11159);
										mem_vec_11159 = vec_232;
										scal_73 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_234 = _mm512_set1_ps(scal_73);


										vec_233 = _mm512_fmadd_ps(vec_234, vec_212, mem_vec_11160);
										mem_vec_11160 = vec_233;



										vec_235 = _mm512_fmadd_ps(vec_234, vec_214, mem_vec_11161);
										mem_vec_11161 = vec_235;
										scal_74 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
										vec_237 = _mm512_set1_ps(scal_74);


										vec_236 = _mm512_fmadd_ps(vec_237, vec_212, mem_vec_11162);
										mem_vec_11162 = vec_236;



										vec_238 = _mm512_fmadd_ps(vec_237, vec_214, mem_vec_11163);
										mem_vec_11163 = vec_238;
										scal_75 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
										vec_240 = _mm512_set1_ps(scal_75);


										vec_239 = _mm512_fmadd_ps(vec_240, vec_212, mem_vec_11164);
										mem_vec_11164 = vec_239;



										vec_241 = _mm512_fmadd_ps(vec_240, vec_214, mem_vec_11165);
										mem_vec_11165 = vec_241;
										scal_76 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
										vec_243 = _mm512_set1_ps(scal_76);


										vec_242 = _mm512_fmadd_ps(vec_243, vec_212, mem_vec_11166);
										mem_vec_11166 = vec_242;



										vec_244 = _mm512_fmadd_ps(vec_243, vec_214, mem_vec_11167);
										mem_vec_11167 = vec_244;
										scal_77 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
										vec_246 = _mm512_set1_ps(scal_77);
										vec_247 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

										vec_245 = _mm512_fmadd_ps(vec_246, vec_247, mem_vec_11146);
										mem_vec_11146 = vec_245;

										vec_249 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f + 16]);

										vec_248 = _mm512_fmadd_ps(vec_246, vec_249, mem_vec_11147);
										mem_vec_11147 = vec_248;
										scal_78 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
										vec_251 = _mm512_set1_ps(scal_78);


										vec_250 = _mm512_fmadd_ps(vec_251, vec_247, mem_vec_11148);
										mem_vec_11148 = vec_250;



										vec_252 = _mm512_fmadd_ps(vec_251, vec_249, mem_vec_11149);
										mem_vec_11149 = vec_252;
										scal_79 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
										vec_254 = _mm512_set1_ps(scal_79);


										vec_253 = _mm512_fmadd_ps(vec_254, vec_247, mem_vec_11150);
										mem_vec_11150 = vec_253;



										vec_255 = _mm512_fmadd_ps(vec_254, vec_249, mem_vec_11151);
										mem_vec_11151 = vec_255;
										scal_80 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
										vec_257 = _mm512_set1_ps(scal_80);


										vec_256 = _mm512_fmadd_ps(vec_257, vec_247, mem_vec_11152);
										mem_vec_11152 = vec_256;



										vec_258 = _mm512_fmadd_ps(vec_257, vec_249, mem_vec_11153);
										mem_vec_11153 = vec_258;
										scal_81 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
										vec_260 = _mm512_set1_ps(scal_81);


										vec_259 = _mm512_fmadd_ps(vec_260, vec_247, mem_vec_11154);
										mem_vec_11154 = vec_259;



										vec_261 = _mm512_fmadd_ps(vec_260, vec_249, mem_vec_11155);
										mem_vec_11155 = vec_261;
										scal_82 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
										vec_263 = _mm512_set1_ps(scal_82);


										vec_262 = _mm512_fmadd_ps(vec_263, vec_247, mem_vec_11156);
										mem_vec_11156 = vec_262;



										vec_264 = _mm512_fmadd_ps(vec_263, vec_249, mem_vec_11157);
										mem_vec_11157 = vec_264;
										scal_83 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
										vec_266 = _mm512_set1_ps(scal_83);


										vec_265 = _mm512_fmadd_ps(vec_266, vec_247, mem_vec_11158);
										mem_vec_11158 = vec_265;



										vec_267 = _mm512_fmadd_ps(vec_266, vec_249, mem_vec_11159);
										mem_vec_11159 = vec_267;
										scal_84 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 1) + c];
										vec_269 = _mm512_set1_ps(scal_84);


										vec_268 = _mm512_fmadd_ps(vec_269, vec_247, mem_vec_11160);
										mem_vec_11160 = vec_268;



										vec_270 = _mm512_fmadd_ps(vec_269, vec_249, mem_vec_11161);
										mem_vec_11161 = vec_270;
										scal_85 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 1) + c];
										vec_272 = _mm512_set1_ps(scal_85);


										vec_271 = _mm512_fmadd_ps(vec_272, vec_247, mem_vec_11162);
										mem_vec_11162 = vec_271;



										vec_273 = _mm512_fmadd_ps(vec_272, vec_249, mem_vec_11163);
										mem_vec_11163 = vec_273;
										scal_86 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 1) + c];
										vec_275 = _mm512_set1_ps(scal_86);


										vec_274 = _mm512_fmadd_ps(vec_275, vec_247, mem_vec_11164);
										mem_vec_11164 = vec_274;



										vec_276 = _mm512_fmadd_ps(vec_275, vec_249, mem_vec_11165);
										mem_vec_11165 = vec_276;
										scal_87 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 1) + c];
										vec_278 = _mm512_set1_ps(scal_87);


										vec_277 = _mm512_fmadd_ps(vec_278, vec_247, mem_vec_11166);
										mem_vec_11166 = vec_277;



										vec_279 = _mm512_fmadd_ps(vec_278, vec_249, mem_vec_11167);
										mem_vec_11167 = vec_279;
										scal_88 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
										vec_281 = _mm512_set1_ps(scal_88);
										vec_282 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

										vec_280 = _mm512_fmadd_ps(vec_281, vec_282, mem_vec_11146);
										mem_vec_11146 = vec_280;

										vec_284 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f + 16]);

										vec_283 = _mm512_fmadd_ps(vec_281, vec_284, mem_vec_11147);
										mem_vec_11147 = vec_283;
										scal_89 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
										vec_286 = _mm512_set1_ps(scal_89);


										vec_285 = _mm512_fmadd_ps(vec_286, vec_282, mem_vec_11148);
										mem_vec_11148 = vec_285;



										vec_287 = _mm512_fmadd_ps(vec_286, vec_284, mem_vec_11149);
										mem_vec_11149 = vec_287;
										scal_90 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
										vec_289 = _mm512_set1_ps(scal_90);


										vec_288 = _mm512_fmadd_ps(vec_289, vec_282, mem_vec_11150);
										mem_vec_11150 = vec_288;



										vec_290 = _mm512_fmadd_ps(vec_289, vec_284, mem_vec_11151);
										mem_vec_11151 = vec_290;
										scal_91 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
										vec_292 = _mm512_set1_ps(scal_91);


										vec_291 = _mm512_fmadd_ps(vec_292, vec_282, mem_vec_11152);
										mem_vec_11152 = vec_291;



										vec_293 = _mm512_fmadd_ps(vec_292, vec_284, mem_vec_11153);
										mem_vec_11153 = vec_293;
										scal_92 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
										vec_295 = _mm512_set1_ps(scal_92);


										vec_294 = _mm512_fmadd_ps(vec_295, vec_282, mem_vec_11154);
										mem_vec_11154 = vec_294;



										vec_296 = _mm512_fmadd_ps(vec_295, vec_284, mem_vec_11155);
										mem_vec_11155 = vec_296;
										scal_93 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
										vec_298 = _mm512_set1_ps(scal_93);


										vec_297 = _mm512_fmadd_ps(vec_298, vec_282, mem_vec_11156);
										mem_vec_11156 = vec_297;



										vec_299 = _mm512_fmadd_ps(vec_298, vec_284, mem_vec_11157);
										mem_vec_11157 = vec_299;
										scal_94 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
										vec_301 = _mm512_set1_ps(scal_94);


										vec_300 = _mm512_fmadd_ps(vec_301, vec_282, mem_vec_11158);
										mem_vec_11158 = vec_300;



										vec_302 = _mm512_fmadd_ps(vec_301, vec_284, mem_vec_11159);
										mem_vec_11159 = vec_302;
										scal_95 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 2) + c];
										vec_304 = _mm512_set1_ps(scal_95);


										vec_303 = _mm512_fmadd_ps(vec_304, vec_282, mem_vec_11160);
										mem_vec_11160 = vec_303;



										vec_305 = _mm512_fmadd_ps(vec_304, vec_284, mem_vec_11161);
										mem_vec_11161 = vec_305;
										scal_96 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 2) + c];
										vec_307 = _mm512_set1_ps(scal_96);


										vec_306 = _mm512_fmadd_ps(vec_307, vec_282, mem_vec_11162);
										mem_vec_11162 = vec_306;



										vec_308 = _mm512_fmadd_ps(vec_307, vec_284, mem_vec_11163);
										mem_vec_11163 = vec_308;
										scal_97 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 2) + c];
										vec_310 = _mm512_set1_ps(scal_97);


										vec_309 = _mm512_fmadd_ps(vec_310, vec_282, mem_vec_11164);
										mem_vec_11164 = vec_309;



										vec_311 = _mm512_fmadd_ps(vec_310, vec_284, mem_vec_11165);
										mem_vec_11165 = vec_311;
										scal_98 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 2) + c];
										vec_313 = _mm512_set1_ps(scal_98);


										vec_312 = _mm512_fmadd_ps(vec_313, vec_282, mem_vec_11166);
										mem_vec_11166 = vec_312;



										vec_314 = _mm512_fmadd_ps(vec_313, vec_284, mem_vec_11167);
										mem_vec_11167 = vec_314;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11146);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11147);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11148);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11149);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11150);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11151);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11152);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11153);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11154);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11155);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11156);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11157);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11158);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11159);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11160);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11161);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11162);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11163);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11164);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11165);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11166);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_11167);
						}
					}
				}
		}
	}
}


}