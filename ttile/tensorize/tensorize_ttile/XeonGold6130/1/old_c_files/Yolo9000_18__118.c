#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (17, x); T (16, c);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (16, f);
  T (1, c); T (1, c)]
*/
IND_TYPE c, cp_0, c35_p_0, c36_p_0, c37_p_0, cp_1, c35_p_1, c36_p_1, cp_2, c35_p_2, cp_3, c35, c36, c37, f, fp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y14 = 0;
IND_TYPE x14 = 0;
IND_TYPE h = 0;
IND_TYPE w14 = 0;
IND_TYPE c38 = 0;
IND_TYPE f14 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_268 ,mem_vec_269 ,mem_vec_270 ,mem_vec_271 ,mem_vec_272 ,mem_vec_273 ,mem_vec_274 ,mem_vec_275 ,mem_vec_276 ,mem_vec_277 ,mem_vec_278 ,mem_vec_279 ,mem_vec_280 ,mem_vec_281 ,mem_vec_282 ,mem_vec_283 ,mem_vec_284 ,mem_vec_285 ,mem_vec_286 ,mem_vec_287 ,mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,mem_vec_294 ,mem_vec_295 ,mem_vec_296 ,mem_vec_297 ,mem_vec_298 ,mem_vec_299 ,mem_vec_300 ,mem_vec_301 ,mem_vec_302 ,mem_vec_303 ,mem_vec_304 ,mem_vec_305 ,mem_vec_306 ,mem_vec_307 ,mem_vec_308 ,mem_vec_309 ,mem_vec_310 ,mem_vec_311 ,mem_vec_312 ,mem_vec_313 ,mem_vec_314 ,mem_vec_315 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 1) (512 / 512)
for (c37 = c38, c37_p_0 = 0;
	c37 < c38 + 512;
	c37 += 512, c37_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 1) (512 / 512)
	for (c36 = c37, c36_p_1 = c37_p_0, c36_p_0 = 0;
		c36 < c37 + 512;
		c36 += 512, c36_p_1 += 512, c36_p_0 += 512){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
		// T (f, 16) (1024 / 64)
		for (f = f14, fp_0 = 0;
			f < f14 + 1024;
			f += 64, fp_0 += 64){
				for (y = y14, yp_0 = 0;
					y < y14 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 64
					// T (c, 16) (512 / 32)
					for (c35 = c36, c35_p_2 = c36_p_1, c35_p_1 = c36_p_0, c35_p_0 = 0;
						c35 < c36 + 512;
						c35 += 32, c35_p_2 += 32, c35_p_1 += 32, c35_p_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x14, xp_0 = 0;
							x < x14 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
							// T (w, 3) (3 / 1)
							for (w = w14, wp_0 = 0;
								w < w14 + 3;
								w += 1, wp_0 += 1){
										mem_vec_268 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_269 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_270 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_271 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c35, cp_3 = c35_p_2, cp_2 = c35_p_1, cp_1 = c35_p_0, cp_0 = 0;
											c < c35 + 32;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_268);
											mem_vec_268 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_269);
											mem_vec_269 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_270);
											mem_vec_270 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_271);
											mem_vec_271 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_272);
											mem_vec_272 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_273);
											mem_vec_273 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_274);
											mem_vec_274 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_275);
											mem_vec_275 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_276);
											mem_vec_276 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_277);
											mem_vec_277 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_278);
											mem_vec_278 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_279);
											mem_vec_279 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_280);
											mem_vec_280 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_281);
											mem_vec_281 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_282);
											mem_vec_282 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_283);
											mem_vec_283 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_284);
											mem_vec_284 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_285);
											mem_vec_285 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_286);
											mem_vec_286 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_287);
											mem_vec_287 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_268);
											mem_vec_268 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_269);
											mem_vec_269 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_270);
											mem_vec_270 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_271);
											mem_vec_271 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_272);
											mem_vec_272 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_273);
											mem_vec_273 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_274);
											mem_vec_274 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_275);
											mem_vec_275 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_276);
											mem_vec_276 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_277);
											mem_vec_277 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_278);
											mem_vec_278 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_279);
											mem_vec_279 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_280);
											mem_vec_280 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_281);
											mem_vec_281 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_282);
											mem_vec_282 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_283);
											mem_vec_283 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_284);
											mem_vec_284 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_285);
											mem_vec_285 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_286);
											mem_vec_286 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_287);
											mem_vec_287 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_268);
											mem_vec_268 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_269);
											mem_vec_269 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_270);
											mem_vec_270 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_271);
											mem_vec_271 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_272);
											mem_vec_272 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_273);
											mem_vec_273 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_274);
											mem_vec_274 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_275);
											mem_vec_275 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_276);
											mem_vec_276 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_277);
											mem_vec_277 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_278);
											mem_vec_278 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_279);
											mem_vec_279 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_280);
											mem_vec_280 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_281);
											mem_vec_281 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_282);
											mem_vec_282 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_283);
											mem_vec_283 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_284);
											mem_vec_284 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_285);
											mem_vec_285 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_286);
											mem_vec_286 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_287);
											mem_vec_287 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_268);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_269);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_270);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_271);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_272);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_273);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_274);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_275);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_276);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_277);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_278);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_279);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_280);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_281);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_282);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_283);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_284);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_285);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_286);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_287);
							}
						}
					}
				}
				for (y = y14 + 10, yp_0 = 0;
					y < y14 + 10 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 64
					// T (c, 16) (512 / 32)
					for (c35 = c36, c35_p_2 = c36_p_1, c35_p_1 = c36_p_0, c35_p_0 = 0;
						c35 < c36 + 512;
						c35 += 32, c35_p_2 += 32, c35_p_1 += 32, c35_p_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x14, xp_0 = 0;
							x < x14 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
							// T (w, 3) (3 / 1)
							for (w = w14, wp_0 = 0;
								w < w14 + 3;
								w += 1, wp_0 += 1){
										mem_vec_288 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_289 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_290 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_291 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c35, cp_3 = c35_p_2, cp_2 = c35_p_1, cp_1 = c35_p_0, cp_0 = 0;
											c < c35 + 32;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_288);
											mem_vec_288 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_289);
											mem_vec_289 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_290);
											mem_vec_290 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_291);
											mem_vec_291 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_292);
											mem_vec_292 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_293);
											mem_vec_293 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_294);
											mem_vec_294 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_295);
											mem_vec_295 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_296);
											mem_vec_296 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_297);
											mem_vec_297 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_298);
											mem_vec_298 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_299);
											mem_vec_299 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_300);
											mem_vec_300 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_301);
											mem_vec_301 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_302);
											mem_vec_302 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_303);
											mem_vec_303 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_304);
											mem_vec_304 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_305);
											mem_vec_305 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_306);
											mem_vec_306 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_307);
											mem_vec_307 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_308);
											mem_vec_308 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_309);
											mem_vec_309 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_310);
											mem_vec_310 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_311);
											mem_vec_311 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_312);
											mem_vec_312 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_313);
											mem_vec_313 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_314);
											mem_vec_314 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_315);
											mem_vec_315 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_40 = _mm512_set1_ps(scal_7);
											vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_288);
											mem_vec_288 = vec_39;

											vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_289);
											mem_vec_289 = vec_42;

											vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_290);
											mem_vec_290 = vec_44;

											vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_291);
											mem_vec_291 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_292);
											mem_vec_292 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_293);
											mem_vec_293 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_294);
											mem_vec_294 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_295);
											mem_vec_295 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_296);
											mem_vec_296 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_297);
											mem_vec_297 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_298);
											mem_vec_298 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_299);
											mem_vec_299 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_300);
											mem_vec_300 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_301);
											mem_vec_301 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_302);
											mem_vec_302 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_303);
											mem_vec_303 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_304);
											mem_vec_304 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_305);
											mem_vec_305 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_306);
											mem_vec_306 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_307);
											mem_vec_307 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_69 = _mm512_set1_ps(scal_12);


											vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_308);
											mem_vec_308 = vec_68;



											vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_309);
											mem_vec_309 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_310);
											mem_vec_310 = vec_71;



											vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_311);
											mem_vec_311 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_74 = _mm512_set1_ps(scal_13);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_312);
											mem_vec_312 = vec_73;



											vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_313);
											mem_vec_313 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_314);
											mem_vec_314 = vec_76;



											vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_315);
											mem_vec_315 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_14);
											vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_288);
											mem_vec_288 = vec_78;

											vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_289);
											mem_vec_289 = vec_81;

											vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_290);
											mem_vec_290 = vec_83;

											vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_291);
											mem_vec_291 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_292);
											mem_vec_292 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_293);
											mem_vec_293 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_294);
											mem_vec_294 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_295);
											mem_vec_295 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_296);
											mem_vec_296 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_297);
											mem_vec_297 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_298);
											mem_vec_298 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_299);
											mem_vec_299 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_300);
											mem_vec_300 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_301);
											mem_vec_301 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_302);
											mem_vec_302 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_303);
											mem_vec_303 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_18);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_304);
											mem_vec_304 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_305);
											mem_vec_305 = vec_104;



											vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_306);
											mem_vec_306 = vec_105;



											vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_307);
											mem_vec_307 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_108 = _mm512_set1_ps(scal_19);


											vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_308);
											mem_vec_308 = vec_107;



											vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_309);
											mem_vec_309 = vec_109;



											vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_310);
											mem_vec_310 = vec_110;



											vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_311);
											mem_vec_311 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_113 = _mm512_set1_ps(scal_20);


											vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_312);
											mem_vec_312 = vec_112;



											vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_313);
											mem_vec_313 = vec_114;



											vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_314);
											mem_vec_314 = vec_115;



											vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_315);
											mem_vec_315 = vec_116;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_288);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_289);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_290);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_291);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_292);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_293);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_294);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_295);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_296);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_297);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_298);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_299);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_300);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_301);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_302);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_303);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_304);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_305);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_306);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_307);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_308);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_309);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_310);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_311);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_312);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_313);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_314);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_315);
							}
						}
					}
				}
		}
	}
}


}