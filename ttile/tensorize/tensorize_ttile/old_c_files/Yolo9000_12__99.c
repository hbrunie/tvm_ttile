#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (8, f); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (1, f);
  T (256, c); T (1, f)]
*/
IND_TYPE c, cp_0, c1190_p_0, cp_1, c1190, f, fp_0, f1280_p_0, f1281_p_0, fp_1, f1280_p_1, fp_2, f1280, f1281, h, hp_0, x, xp_0, x1190_p_0, xp_1, x1190, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y732 = 0;
IND_TYPE x1191 = 0;
IND_TYPE h572 = 0;
IND_TYPE w = 0;
IND_TYPE c1191 = 0;
IND_TYPE f1282 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14294 ,mem_vec_14295 ,mem_vec_14296 ,mem_vec_14297 ,mem_vec_14298 ,mem_vec_14299 ,mem_vec_14300 ,mem_vec_14301 ,mem_vec_14302 ,mem_vec_14303 ,mem_vec_14304 ,mem_vec_14305 ,mem_vec_14306 ,mem_vec_14307 ,mem_vec_14308 ,mem_vec_14309 ,mem_vec_14310 ,mem_vec_14311 ,mem_vec_14312 ,mem_vec_14313 ,mem_vec_14314 ,mem_vec_14315 ,mem_vec_14316 ,mem_vec_14317 ,mem_vec_14318 ,mem_vec_14319 ,mem_vec_14320 ,mem_vec_14321 ,mem_vec_14322 ,mem_vec_14323 ,mem_vec_14324 ,mem_vec_14325 ,mem_vec_14326 ,mem_vec_14327 ,mem_vec_14328 ,mem_vec_14329 ,mem_vec_14330 ,mem_vec_14331 ,mem_vec_14332 ,mem_vec_14333 ,mem_vec_14334 ,mem_vec_14335 ,mem_vec_14336 ,mem_vec_14337 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f1281 = f1282, f1281_p_0 = 0;
	f1281 < f1282 + 512;
	f1281 += 512, f1281_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 256) (256 / 1)
	for (c1190 = c1191, c1190_p_0 = 0;
		c1190 < c1191 + 256;
		c1190 += 1, c1190_p_0 += 1){
		// y = 34, x = 34, h = 3, w = 3, c = 1, f = 512
		// T (f, 1) (512 / 512)
		for (f1280 = f1281, f1280_p_1 = f1281_p_0, f1280_p_0 = 0;
			f1280 < f1281 + 512;
			f1280 += 512, f1280_p_1 += 512, f1280_p_0 += 512){
				for (y = y732, yp_0 = 0;
					y < y732 + 20;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 512
					// T (x, 1) (34 / 34)
					for (x1190 = x1191, x1190_p_0 = 0;
						x1190 < x1191 + 34;
						x1190 += 34, x1190_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 512
						// T (f, 8) (512 / 64)
						for (f = f1280, fp_2 = f1280_p_1, fp_1 = f1280_p_0, fp_0 = 0;
							f < f1280 + 512;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 64
							// T (h, 3) (3 / 1)
							for (h = h572, hp_0 = 0;
								h < h572 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 1, f = 64
								// T (x, 34) (34 / 1)
								for (x = x1190, xp_1 = x1190_p_0, xp_0 = 0;
									x < x1190 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14294 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14295 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14296 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_14297 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_14298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_14301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_14302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_14305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_14306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_14309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
											// T (c, 1) (1 / 1)
											for (c = c1190, cp_1 = c1190_p_0, cp_0 = 0;
												c < c1190 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14294);
												mem_vec_14294 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14295);
												mem_vec_14295 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14296);
												mem_vec_14296 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14297);
												mem_vec_14297 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14298);
												mem_vec_14298 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14299);
												mem_vec_14299 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14300);
												mem_vec_14300 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14301);
												mem_vec_14301 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14302);
												mem_vec_14302 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14303);
												mem_vec_14303 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14304);
												mem_vec_14304 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14305);
												mem_vec_14305 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14306);
												mem_vec_14306 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14307);
												mem_vec_14307 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14308);
												mem_vec_14308 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14309);
												mem_vec_14309 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_14294);
												mem_vec_14294 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_14295);
												mem_vec_14295 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_14296);
												mem_vec_14296 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_14297);
												mem_vec_14297 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_14298);
												mem_vec_14298 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_14299);
												mem_vec_14299 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_14300);
												mem_vec_14300 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_14301);
												mem_vec_14301 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_14302);
												mem_vec_14302 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_14303);
												mem_vec_14303 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_14304);
												mem_vec_14304 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_14305);
												mem_vec_14305 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_14306);
												mem_vec_14306 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_14307);
												mem_vec_14307 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_14308);
												mem_vec_14308 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_14309);
												mem_vec_14309 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_14294);
												mem_vec_14294 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_14295);
												mem_vec_14295 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_14296);
												mem_vec_14296 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_14297);
												mem_vec_14297 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_14298);
												mem_vec_14298 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_14299);
												mem_vec_14299 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_14300);
												mem_vec_14300 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_14301);
												mem_vec_14301 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_14302);
												mem_vec_14302 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_14303);
												mem_vec_14303 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_14304);
												mem_vec_14304 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_14305);
												mem_vec_14305 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_14306);
												mem_vec_14306 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_14307);
												mem_vec_14307 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_14308);
												mem_vec_14308 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_14309);
												mem_vec_14309 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14294);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14295);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14296);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14297);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14298);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14299);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14300);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14301);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14302);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14303);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14304);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14305);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14306);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14307);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14308);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14309);
								}
							}
						}
					}
				}
				for (y = y732 + 20, yp_0 = 0;
					y < y732 + 20 + 14;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 512
					// T (x, 1) (34 / 34)
					for (x1190 = x1191, x1190_p_0 = 0;
						x1190 < x1191 + 34;
						x1190 += 34, x1190_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 512
						// T (f, 8) (512 / 64)
						for (f = f1280, fp_2 = f1280_p_1, fp_1 = f1280_p_0, fp_0 = 0;
							f < f1280 + 512;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 64
							// T (h, 3) (3 / 1)
							for (h = h572, hp_0 = 0;
								h < h572 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 1, f = 64
								// T (x, 34) (34 / 1)
								for (x = x1190, xp_1 = x1190_p_0, xp_0 = 0;
									x < x1190 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14310 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14311 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14312 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_14313 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_14314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_14317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_14318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_14321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_14322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_14325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_14326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_14327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_14328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_14329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_14330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_14331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_14332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_14333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											mem_vec_14334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_14335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_14336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
											mem_vec_14337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
											// T (c, 1) (1 / 1)
											for (c = c1190, cp_1 = c1190_p_0, cp_0 = 0;
												c < c1190 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14310);
												mem_vec_14310 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14311);
												mem_vec_14311 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14312);
												mem_vec_14312 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14313);
												mem_vec_14313 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14314);
												mem_vec_14314 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14315);
												mem_vec_14315 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14316);
												mem_vec_14316 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14317);
												mem_vec_14317 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14318);
												mem_vec_14318 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14319);
												mem_vec_14319 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14320);
												mem_vec_14320 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14321);
												mem_vec_14321 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14322);
												mem_vec_14322 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14323);
												mem_vec_14323 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14324);
												mem_vec_14324 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14325);
												mem_vec_14325 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14326);
												mem_vec_14326 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14327);
												mem_vec_14327 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14328);
												mem_vec_14328 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14329);
												mem_vec_14329 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14330);
												mem_vec_14330 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14331);
												mem_vec_14331 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14332);
												mem_vec_14332 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14333);
												mem_vec_14333 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_14334);
												mem_vec_14334 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_14335);
												mem_vec_14335 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_14336);
												mem_vec_14336 = vec_37;



												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_14337);
												mem_vec_14337 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_40 = _mm512_set1_ps(scal_7);
												vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_14310);
												mem_vec_14310 = vec_39;

												vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_14311);
												mem_vec_14311 = vec_42;

												vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_14312);
												mem_vec_14312 = vec_44;

												vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_14313);
												mem_vec_14313 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_14314);
												mem_vec_14314 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_14315);
												mem_vec_14315 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_14316);
												mem_vec_14316 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_14317);
												mem_vec_14317 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_14318);
												mem_vec_14318 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_14319);
												mem_vec_14319 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_14320);
												mem_vec_14320 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_14321);
												mem_vec_14321 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_14322);
												mem_vec_14322 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_14323);
												mem_vec_14323 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_14324);
												mem_vec_14324 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_14325);
												mem_vec_14325 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_14326);
												mem_vec_14326 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_14327);
												mem_vec_14327 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_14328);
												mem_vec_14328 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_14329);
												mem_vec_14329 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);


												vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_14330);
												mem_vec_14330 = vec_68;



												vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_14331);
												mem_vec_14331 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_14332);
												mem_vec_14332 = vec_71;



												vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_14333);
												mem_vec_14333 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_74 = _mm512_set1_ps(scal_13);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_14334);
												mem_vec_14334 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_14335);
												mem_vec_14335 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_14336);
												mem_vec_14336 = vec_76;



												vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_14337);
												mem_vec_14337 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_79 = _mm512_set1_ps(scal_14);
												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_14310);
												mem_vec_14310 = vec_78;

												vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_14311);
												mem_vec_14311 = vec_81;

												vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_14312);
												mem_vec_14312 = vec_83;

												vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_14313);
												mem_vec_14313 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_14314);
												mem_vec_14314 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_14315);
												mem_vec_14315 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_14316);
												mem_vec_14316 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_14317);
												mem_vec_14317 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_14318);
												mem_vec_14318 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_14319);
												mem_vec_14319 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_14320);
												mem_vec_14320 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_14321);
												mem_vec_14321 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_14322);
												mem_vec_14322 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_14323);
												mem_vec_14323 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_14324);
												mem_vec_14324 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_14325);
												mem_vec_14325 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_103 = _mm512_set1_ps(scal_18);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_14326);
												mem_vec_14326 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_14327);
												mem_vec_14327 = vec_104;



												vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_14328);
												mem_vec_14328 = vec_105;



												vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_14329);
												mem_vec_14329 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_108 = _mm512_set1_ps(scal_19);


												vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_14330);
												mem_vec_14330 = vec_107;



												vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_14331);
												mem_vec_14331 = vec_109;



												vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_14332);
												mem_vec_14332 = vec_110;



												vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_14333);
												mem_vec_14333 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_113 = _mm512_set1_ps(scal_20);


												vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_14334);
												mem_vec_14334 = vec_112;



												vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_14335);
												mem_vec_14335 = vec_114;



												vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_14336);
												mem_vec_14336 = vec_115;



												vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_14337);
												mem_vec_14337 = vec_116;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14310);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14311);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14312);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14313);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14314);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14315);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14316);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14317);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14318);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14319);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14320);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14321);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14322);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14323);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14324);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14325);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14326);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14327);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14328);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14329);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14330);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14331);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_14332);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_14333);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14334);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14335);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_14336);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_14337);
								}
							}
						}
					}
				}
		}
	}
}


}