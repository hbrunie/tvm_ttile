#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (2, c);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (8, x);
  T (2, f); T (4, c); T (2, f)]
*/
IND_TYPE c, cp_0, c648_p_0, c649_p_0, cp_1, c648_p_1, cp_2, c648, c649, f, fp_0, f479_p_0, fp_1, f479, h, hp_0, x, xp_0, x486_p_0, xp_1, x486, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y324 = 0;
IND_TYPE x487 = 0;
IND_TYPE h231 = 0;
IND_TYPE w = 0;
IND_TYPE c650 = 0;
IND_TYPE f480 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7276 ,mem_vec_7277 ,mem_vec_7278 ,mem_vec_7279 ,mem_vec_7280 ,mem_vec_7281 ,mem_vec_7282 ,mem_vec_7283 ,mem_vec_7284 ,mem_vec_7285 ,mem_vec_7286 ,mem_vec_7287 ,mem_vec_7288 ,mem_vec_7289 ,mem_vec_7290 ,mem_vec_7291 ,mem_vec_7292 ,mem_vec_7293 ,mem_vec_7294 ,mem_vec_7295 ,mem_vec_7296 ,mem_vec_7297 ,mem_vec_7298 ,mem_vec_7299 ,mem_vec_7300 ,mem_vec_7301 ,mem_vec_7302 ,mem_vec_7303 ,mem_vec_7304 ,mem_vec_7305 ,mem_vec_7306 ,mem_vec_7307 ,mem_vec_7308 ,mem_vec_7309 ,mem_vec_7310 ,mem_vec_7311 ,mem_vec_7312 ,mem_vec_7313 ,mem_vec_7314 ,mem_vec_7315 ,mem_vec_7316 ,mem_vec_7317 ,mem_vec_7318 ,mem_vec_7319 ,mem_vec_7320 ,mem_vec_7321 ,mem_vec_7322 ,mem_vec_7323 ,mem_vec_7324 ,mem_vec_7325 ,mem_vec_7326 ,mem_vec_7327 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f479 = f480, f479_p_0 = 0;
	f479 < f480 + 128;
	f479 += 64, f479_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 64
	// T (c, 4) (128 / 32)
	for (c649 = c650, c649_p_0 = 0;
		c649 < c650 + 128;
		c649 += 32, c649_p_0 += 32){
		// y = 56, x = 56, h = 3, w = 3, c = 32, f = 64
		// T (f, 2) (64 / 32)
		for (f = f479, fp_1 = f479_p_0, fp_0 = 0;
			f < f479 + 64;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 56, x = 56, h = 3, w = 3, c = 32, f = 32
			// T (x, 8) (56 / 7)
			for (x486 = x487, x486_p_0 = 0;
				x486 < x487 + 56;
				x486 += 7, x486_p_0 += 7){
					for (y = y324, yp_0 = 0;
						y < y324 + 42;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 32
						// T (c, 2) (32 / 16)
						for (c648 = c649, c648_p_1 = c649_p_0, c648_p_0 = 0;
							c648 < c649 + 32;
							c648 += 16, c648_p_1 += 16, c648_p_0 += 16){
							// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h231, hp_0 = 0;
								h < h231 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 32
								// T (x, 7) (7 / 1)
								for (x = x486, xp_1 = x486_p_0, xp_0 = 0;
									x < x486 + 7;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7276 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7277 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7278 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7279 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_7280 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7281 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7282 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7283 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_7284 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7285 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7286 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7287 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_7288 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7289 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_7290 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7291 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_7292 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7293 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_7294 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7295 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_7296 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7297 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_7298 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_7299 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c648, cp_2 = c648_p_1, cp_1 = c648_p_0, cp_0 = 0;
												c < c648 + 16;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7276);
												mem_vec_7276 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7277);
												mem_vec_7277 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7278);
												mem_vec_7278 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7279);
												mem_vec_7279 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7280);
												mem_vec_7280 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7281);
												mem_vec_7281 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7282);
												mem_vec_7282 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7283);
												mem_vec_7283 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7284);
												mem_vec_7284 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7285);
												mem_vec_7285 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7286);
												mem_vec_7286 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7287);
												mem_vec_7287 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7288);
												mem_vec_7288 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7289);
												mem_vec_7289 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7290);
												mem_vec_7290 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7291);
												mem_vec_7291 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_7292);
												mem_vec_7292 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_7293);
												mem_vec_7293 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_7294);
												mem_vec_7294 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_7295);
												mem_vec_7295 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_7296);
												mem_vec_7296 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_7297);
												mem_vec_7297 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_7298);
												mem_vec_7298 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_7299);
												mem_vec_7299 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_7276);
												mem_vec_7276 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_7277);
												mem_vec_7277 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_7278);
												mem_vec_7278 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_7279);
												mem_vec_7279 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_7280);
												mem_vec_7280 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_7281);
												mem_vec_7281 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_7282);
												mem_vec_7282 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_7283);
												mem_vec_7283 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_7284);
												mem_vec_7284 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_7285);
												mem_vec_7285 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_7286);
												mem_vec_7286 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_7287);
												mem_vec_7287 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_7288);
												mem_vec_7288 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_7289);
												mem_vec_7289 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_7290);
												mem_vec_7290 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_7291);
												mem_vec_7291 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_7292);
												mem_vec_7292 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_7293);
												mem_vec_7293 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_7294);
												mem_vec_7294 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_7295);
												mem_vec_7295 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_7296);
												mem_vec_7296 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_7297);
												mem_vec_7297 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_7298);
												mem_vec_7298 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_7299);
												mem_vec_7299 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_7276);
												mem_vec_7276 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_7277);
												mem_vec_7277 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_7278);
												mem_vec_7278 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_7279);
												mem_vec_7279 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_7280);
												mem_vec_7280 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_7281);
												mem_vec_7281 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_7282);
												mem_vec_7282 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_7283);
												mem_vec_7283 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_7284);
												mem_vec_7284 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_7285);
												mem_vec_7285 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_7286);
												mem_vec_7286 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_7287);
												mem_vec_7287 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_7288);
												mem_vec_7288 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_7289);
												mem_vec_7289 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_7290);
												mem_vec_7290 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_7291);
												mem_vec_7291 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_7292);
												mem_vec_7292 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_7293);
												mem_vec_7293 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_7294);
												mem_vec_7294 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_7295);
												mem_vec_7295 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_7296);
												mem_vec_7296 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_7297);
												mem_vec_7297 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_7298);
												mem_vec_7298 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_7299);
												mem_vec_7299 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7276);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7277);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7278);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7279);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7280);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7281);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7282);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7283);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7284);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7285);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7286);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7287);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7288);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7289);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7290);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7291);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7292);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7293);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7294);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_7295);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7296);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_7297);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7298);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_7299);
								}
							}
						}
					}
					for (y = y324 + 42, yp_0 = 0;
						y < y324 + 42 + 14;
						y += 7, yp_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 32
						// T (c, 2) (32 / 16)
						for (c648 = c649, c648_p_1 = c649_p_0, c648_p_0 = 0;
							c648 < c649 + 32;
							c648 += 16, c648_p_1 += 16, c648_p_0 += 16){
							// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h231, hp_0 = 0;
								h < h231 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 32
								// T (x, 7) (7 / 1)
								for (x = x486, xp_1 = x486_p_0, xp_0 = 0;
									x < x486 + 7;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7300 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7301 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7302 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7303 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_7304 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7305 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7306 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7307 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_7308 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7309 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7310 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7311 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_7312 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7313 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_7314 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7315 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_7316 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7317 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_7318 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7319 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_7320 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7321 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_7322 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_7323 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											mem_vec_7324 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_7325 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_7326 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_7327 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c648, cp_2 = c648_p_1, cp_1 = c648_p_0, cp_0 = 0;
												c < c648 + 16;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7300);
												mem_vec_7300 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7301);
												mem_vec_7301 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7302);
												mem_vec_7302 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7303);
												mem_vec_7303 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7304);
												mem_vec_7304 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7305);
												mem_vec_7305 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7306);
												mem_vec_7306 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7307);
												mem_vec_7307 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7308);
												mem_vec_7308 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7309);
												mem_vec_7309 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7310);
												mem_vec_7310 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7311);
												mem_vec_7311 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7312);
												mem_vec_7312 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7313);
												mem_vec_7313 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7314);
												mem_vec_7314 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7315);
												mem_vec_7315 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_7316);
												mem_vec_7316 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_7317);
												mem_vec_7317 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_7318);
												mem_vec_7318 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_7319);
												mem_vec_7319 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_7320);
												mem_vec_7320 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_7321);
												mem_vec_7321 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_7322);
												mem_vec_7322 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_7323);
												mem_vec_7323 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_7324);
												mem_vec_7324 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_7325);
												mem_vec_7325 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_7326);
												mem_vec_7326 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_7327);
												mem_vec_7327 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_40 = _mm256_set1_ps(scal_7);
												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_7300);
												mem_vec_7300 = vec_39;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_7301);
												mem_vec_7301 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_7302);
												mem_vec_7302 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_7303);
												mem_vec_7303 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_7304);
												mem_vec_7304 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_7305);
												mem_vec_7305 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_7306);
												mem_vec_7306 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_7307);
												mem_vec_7307 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_7308);
												mem_vec_7308 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_7309);
												mem_vec_7309 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_7310);
												mem_vec_7310 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_7311);
												mem_vec_7311 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_7312);
												mem_vec_7312 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_7313);
												mem_vec_7313 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_7314);
												mem_vec_7314 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_7315);
												mem_vec_7315 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_7316);
												mem_vec_7316 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_7317);
												mem_vec_7317 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_7318);
												mem_vec_7318 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_7319);
												mem_vec_7319 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);


												vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_7320);
												mem_vec_7320 = vec_68;



												vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_7321);
												mem_vec_7321 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_7322);
												mem_vec_7322 = vec_71;



												vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_7323);
												mem_vec_7323 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_74 = _mm256_set1_ps(scal_13);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_7324);
												mem_vec_7324 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_7325);
												mem_vec_7325 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_7326);
												mem_vec_7326 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_7327);
												mem_vec_7327 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_79 = _mm256_set1_ps(scal_14);
												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_7300);
												mem_vec_7300 = vec_78;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_7301);
												mem_vec_7301 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_7302);
												mem_vec_7302 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_7303);
												mem_vec_7303 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_7304);
												mem_vec_7304 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_7305);
												mem_vec_7305 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_7306);
												mem_vec_7306 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_7307);
												mem_vec_7307 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_7308);
												mem_vec_7308 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_7309);
												mem_vec_7309 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_7310);
												mem_vec_7310 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_7311);
												mem_vec_7311 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_7312);
												mem_vec_7312 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_7313);
												mem_vec_7313 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_7314);
												mem_vec_7314 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_7315);
												mem_vec_7315 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_103 = _mm256_set1_ps(scal_18);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_7316);
												mem_vec_7316 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_7317);
												mem_vec_7317 = vec_104;



												vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_7318);
												mem_vec_7318 = vec_105;



												vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_7319);
												mem_vec_7319 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_108 = _mm256_set1_ps(scal_19);


												vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_7320);
												mem_vec_7320 = vec_107;



												vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_7321);
												mem_vec_7321 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_7322);
												mem_vec_7322 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_7323);
												mem_vec_7323 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_113 = _mm256_set1_ps(scal_20);


												vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_7324);
												mem_vec_7324 = vec_112;



												vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_7325);
												mem_vec_7325 = vec_114;



												vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_7326);
												mem_vec_7326 = vec_115;



												vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_7327);
												mem_vec_7327 = vec_116;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7300);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7301);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7302);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7303);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7304);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7305);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7306);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7307);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7308);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7309);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7310);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7311);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7312);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7313);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7314);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7315);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7316);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7317);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7318);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_7319);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7320);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_7321);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7322);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_7323);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7324);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_7325);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7326);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_7327);
								}
							}
						}
					}
			}
		}
	}
}


}