#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (1, f); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))]; T (16, f);
  T (32, c); T (1, f)]
*/
IND_TYPE c, cp_0, c1050_p_0, cp_1, c1050, f, fp_0, f1400_p_0, f1401_p_0, fp_1, f1400_p_1, fp_2, f1400, f1401, h, hp_0, x, xp_0, x1050_p_0, xp_1, x1050, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y700 = 0;
IND_TYPE x1051 = 0;
IND_TYPE h514 = 0;
IND_TYPE w = 0;
IND_TYPE c1051 = 0;
IND_TYPE f1402 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_12208 ,mem_vec_12209 ,mem_vec_12210 ,mem_vec_12211 ,mem_vec_12212 ,mem_vec_12213 ,mem_vec_12214 ,mem_vec_12215 ,mem_vec_12216 ,mem_vec_12217 ,mem_vec_12218 ,mem_vec_12219 ,mem_vec_12220 ,mem_vec_12221 ,mem_vec_12222 ,mem_vec_12223 ,mem_vec_12224 ,mem_vec_12225 ,mem_vec_12226 ,mem_vec_12227 ,mem_vec_12228 ,mem_vec_12229 ,mem_vec_12230 ,mem_vec_12231 ,mem_vec_12232 ,mem_vec_12233 ,mem_vec_12234 ,mem_vec_12235 ,mem_vec_12236 ,mem_vec_12237 ,mem_vec_12238 ,mem_vec_12239 ,mem_vec_12240 ,mem_vec_12241 ,mem_vec_12242 ,mem_vec_12243 ,mem_vec_12244 ,mem_vec_12245 ,mem_vec_12246 ,mem_vec_12247 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (f, 1) (512 / 512)
for (f1401 = f1402, f1401_p_0 = 0;
	f1401 < f1402 + 512;
	f1401 += 512, f1401_p_0 += 512){
	// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
	// T (c, 32) (512 / 16)
	for (c1050 = c1051, c1050_p_0 = 0;
		c1050 < c1051 + 512;
		c1050 += 16, c1050_p_0 += 16){
		// y = 14, x = 14, h = 3, w = 3, c = 16, f = 512
		// T (f, 16) (512 / 32)
		for (f1400 = f1401, f1400_p_1 = f1401_p_0, f1400_p_0 = 0;
			f1400 < f1401 + 512;
			f1400 += 32, f1400_p_1 += 32, f1400_p_0 += 32){
				for (y = y700, yp_0 = 0;
					y < y700 + 8;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
					// T (x, 2) (14 / 7)
					for (x1050 = x1051, x1050_p_0 = 0;
						x1050 < x1051 + 14;
						x1050 += 7, x1050_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 32
						// T (f, 1) (32 / 32)
						for (f = f1400, fp_2 = f1400_p_1, fp_1 = f1400_p_0, fp_0 = 0;
							f < f1400 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h514, hp_0 = 0;
								h < h514 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 32
								// T (x, 7) (7 / 1)
								for (x = x1050, xp_1 = x1050_p_0, xp_0 = 0;
									x < x1050 + 7;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12208 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_12209 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_12210 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_12211 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_12212 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_12213 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_12214 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_12215 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_12216 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_12217 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_12218 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_12219 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_12220 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_12221 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_12222 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_12223 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c1050, cp_1 = c1050_p_0, cp_0 = 0;
												c < c1050 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12208);
												mem_vec_12208 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12209);
												mem_vec_12209 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12210);
												mem_vec_12210 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12211);
												mem_vec_12211 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12212);
												mem_vec_12212 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12213);
												mem_vec_12213 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12214);
												mem_vec_12214 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12215);
												mem_vec_12215 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12216);
												mem_vec_12216 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12217);
												mem_vec_12217 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12218);
												mem_vec_12218 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12219);
												mem_vec_12219 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12220);
												mem_vec_12220 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12221);
												mem_vec_12221 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12222);
												mem_vec_12222 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12223);
												mem_vec_12223 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_12208);
												mem_vec_12208 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_12209);
												mem_vec_12209 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_12210);
												mem_vec_12210 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_12211);
												mem_vec_12211 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_12212);
												mem_vec_12212 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_12213);
												mem_vec_12213 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_12214);
												mem_vec_12214 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_12215);
												mem_vec_12215 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_12216);
												mem_vec_12216 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_12217);
												mem_vec_12217 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_12218);
												mem_vec_12218 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_12219);
												mem_vec_12219 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_12220);
												mem_vec_12220 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_12221);
												mem_vec_12221 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_12222);
												mem_vec_12222 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_12223);
												mem_vec_12223 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_12208);
												mem_vec_12208 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_12209);
												mem_vec_12209 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_12210);
												mem_vec_12210 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_12211);
												mem_vec_12211 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_12212);
												mem_vec_12212 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_12213);
												mem_vec_12213 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_12214);
												mem_vec_12214 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_12215);
												mem_vec_12215 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_12216);
												mem_vec_12216 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_12217);
												mem_vec_12217 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_12218);
												mem_vec_12218 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_12219);
												mem_vec_12219 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_12220);
												mem_vec_12220 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_12221);
												mem_vec_12221 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_12222);
												mem_vec_12222 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_12223);
												mem_vec_12223 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12208);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12209);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12210);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12211);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12212);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12213);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12214);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12215);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12216);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12217);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12218);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12219);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12220);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12221);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12222);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12223);
								}
							}
						}
					}
				}
				for (y = y700 + 8, yp_0 = 0;
					y < y700 + 8 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
					// T (x, 2) (14 / 7)
					for (x1050 = x1051, x1050_p_0 = 0;
						x1050 < x1051 + 14;
						x1050 += 7, x1050_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 32
						// T (f, 1) (32 / 32)
						for (f = f1400, fp_2 = f1400_p_1, fp_1 = f1400_p_0, fp_0 = 0;
							f < f1400 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h514, hp_0 = 0;
								h < h514 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 32
								// T (x, 7) (7 / 1)
								for (x = x1050, xp_1 = x1050_p_0, xp_0 = 0;
									x < x1050 + 7;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12224 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_12225 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_12226 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_12227 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_12228 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_12229 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_12230 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_12231 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_12232 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_12233 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_12234 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_12235 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_12236 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_12237 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_12238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_12239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_12240 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_12241 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_12242 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_12243 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_12244 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_12245 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_12246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_12247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c1050, cp_1 = c1050_p_0, cp_0 = 0;
												c < c1050 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12224);
												mem_vec_12224 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12225);
												mem_vec_12225 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12226);
												mem_vec_12226 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12227);
												mem_vec_12227 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12228);
												mem_vec_12228 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12229);
												mem_vec_12229 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12230);
												mem_vec_12230 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12231);
												mem_vec_12231 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12232);
												mem_vec_12232 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12233);
												mem_vec_12233 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12234);
												mem_vec_12234 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12235);
												mem_vec_12235 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12236);
												mem_vec_12236 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12237);
												mem_vec_12237 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12238);
												mem_vec_12238 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12239);
												mem_vec_12239 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12240);
												mem_vec_12240 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12241);
												mem_vec_12241 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12242);
												mem_vec_12242 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12243);
												mem_vec_12243 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_12244);
												mem_vec_12244 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_12245);
												mem_vec_12245 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_12246);
												mem_vec_12246 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_12247);
												mem_vec_12247 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_12224);
												mem_vec_12224 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_12225);
												mem_vec_12225 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_12226);
												mem_vec_12226 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_12227);
												mem_vec_12227 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_12228);
												mem_vec_12228 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_12229);
												mem_vec_12229 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_12230);
												mem_vec_12230 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_12231);
												mem_vec_12231 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_12232);
												mem_vec_12232 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_12233);
												mem_vec_12233 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_12234);
												mem_vec_12234 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_12235);
												mem_vec_12235 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_12236);
												mem_vec_12236 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_12237);
												mem_vec_12237 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_12238);
												mem_vec_12238 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_12239);
												mem_vec_12239 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_12240);
												mem_vec_12240 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_12241);
												mem_vec_12241 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_12242);
												mem_vec_12242 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_12243);
												mem_vec_12243 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_12244);
												mem_vec_12244 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_12245);
												mem_vec_12245 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_12246);
												mem_vec_12246 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_12247);
												mem_vec_12247 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_12224);
												mem_vec_12224 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_12225);
												mem_vec_12225 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_12226);
												mem_vec_12226 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_12227);
												mem_vec_12227 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_12228);
												mem_vec_12228 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_12229);
												mem_vec_12229 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_12230);
												mem_vec_12230 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_12231);
												mem_vec_12231 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_12232);
												mem_vec_12232 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_12233);
												mem_vec_12233 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_12234);
												mem_vec_12234 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_12235);
												mem_vec_12235 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_12236);
												mem_vec_12236 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_12237);
												mem_vec_12237 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_12238);
												mem_vec_12238 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_12239);
												mem_vec_12239 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_12240);
												mem_vec_12240 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_12241);
												mem_vec_12241 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_12242);
												mem_vec_12242 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_12243);
												mem_vec_12243 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_12244);
												mem_vec_12244 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_12245);
												mem_vec_12245 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_12246);
												mem_vec_12246 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_12247);
												mem_vec_12247 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12224);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12225);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12226);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12227);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12228);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12229);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12230);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12231);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12232);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12233);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12234);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12235);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12236);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12237);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12238);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12239);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12240);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12241);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12242);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12243);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12244);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_12245);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12246);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_12247);
								}
							}
						}
					}
				}
		}
	}
}


}