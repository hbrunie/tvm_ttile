#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (2, f); T (7, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (4, f);
  T (16, c); T (1, f)]
*/
IND_TYPE c, cp_0, c990_p_0, cp_1, c990, f, fp_0, f1320_p_0, f1321_p_0, fp_1, f1320_p_1, fp_2, f1320, f1321, h, hp_0, x, xp_0, x990_p_0, xp_1, x990, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y660 = 0;
IND_TYPE x991 = 0;
IND_TYPE h472 = 0;
IND_TYPE w = 0;
IND_TYPE c991 = 0;
IND_TYPE f1322 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11224 ,mem_vec_11225 ,mem_vec_11226 ,mem_vec_11227 ,mem_vec_11228 ,mem_vec_11229 ,mem_vec_11230 ,mem_vec_11231 ,mem_vec_11232 ,mem_vec_11233 ,mem_vec_11234 ,mem_vec_11235 ,mem_vec_11236 ,mem_vec_11237 ,mem_vec_11238 ,mem_vec_11239 ,mem_vec_11240 ,mem_vec_11241 ,mem_vec_11242 ,mem_vec_11243 ,mem_vec_11244 ,mem_vec_11245 ,mem_vec_11246 ,mem_vec_11247 ,mem_vec_11248 ,mem_vec_11249 ,mem_vec_11250 ,mem_vec_11251 ,mem_vec_11252 ,mem_vec_11253 ,mem_vec_11254 ,mem_vec_11255 ,mem_vec_11256 ,mem_vec_11257 ,mem_vec_11258 ,mem_vec_11259 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f1321 = f1322, f1321_p_0 = 0;
	f1321 < f1322 + 256;
	f1321 += 256, f1321_p_0 += 256){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
	// T (c, 16) (256 / 16)
	for (c990 = c991, c990_p_0 = 0;
		c990 < c991 + 256;
		c990 += 16, c990_p_0 += 16){
		// y = 14, x = 14, h = 3, w = 3, c = 16, f = 256
		// T (f, 4) (256 / 64)
		for (f1320 = f1321, f1320_p_1 = f1321_p_0, f1320_p_0 = 0;
			f1320 < f1321 + 256;
			f1320 += 64, f1320_p_1 += 64, f1320_p_0 += 64){
				for (y = y660, yp_0 = 0;
					y < y660 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 64
					// T (x, 7) (14 / 2)
					for (x990 = x991, x990_p_0 = 0;
						x990 < x991 + 14;
						x990 += 2, x990_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 64
						// T (f, 2) (64 / 32)
						for (f = f1320, fp_2 = f1320_p_1, fp_1 = f1320_p_0, fp_0 = 0;
							f < f1320 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h472, hp_0 = 0;
								h < h472 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 16, f = 32
								// T (x, 2) (2 / 1)
								for (x = x990, xp_1 = x990_p_0, xp_0 = 0;
									x < x990 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11224 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_11225 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_11226 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_11227 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_11228 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_11229 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_11230 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_11231 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_11232 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_11233 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_11234 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11235 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_11236 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_11237 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_11238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_11239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c990, cp_1 = c990_p_0, cp_0 = 0;
												c < c990 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11224);
												mem_vec_11224 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11225);
												mem_vec_11225 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11226);
												mem_vec_11226 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11227);
												mem_vec_11227 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11228);
												mem_vec_11228 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11229);
												mem_vec_11229 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11230);
												mem_vec_11230 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11231);
												mem_vec_11231 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11232);
												mem_vec_11232 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11233);
												mem_vec_11233 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11234);
												mem_vec_11234 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11235);
												mem_vec_11235 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11236);
												mem_vec_11236 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11237);
												mem_vec_11237 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11238);
												mem_vec_11238 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11239);
												mem_vec_11239 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_11224);
												mem_vec_11224 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_11225);
												mem_vec_11225 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_11226);
												mem_vec_11226 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_11227);
												mem_vec_11227 = vec_31;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_11228);
												mem_vec_11228 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_11229);
												mem_vec_11229 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_11230);
												mem_vec_11230 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_11231);
												mem_vec_11231 = vec_37;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_11232);
												mem_vec_11232 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_11233);
												mem_vec_11233 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_11234);
												mem_vec_11234 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_11235);
												mem_vec_11235 = vec_42;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_11236);
												mem_vec_11236 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_11237);
												mem_vec_11237 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_11238);
												mem_vec_11238 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_11239);
												mem_vec_11239 = vec_47;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_11224);
												mem_vec_11224 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_11225);
												mem_vec_11225 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_11226);
												mem_vec_11226 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_11227);
												mem_vec_11227 = vec_55;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_11228);
												mem_vec_11228 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_11229);
												mem_vec_11229 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_11230);
												mem_vec_11230 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_11231);
												mem_vec_11231 = vec_61;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_11232);
												mem_vec_11232 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_11233);
												mem_vec_11233 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_11234);
												mem_vec_11234 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_11235);
												mem_vec_11235 = vec_66;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_11236);
												mem_vec_11236 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_11237);
												mem_vec_11237 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_11238);
												mem_vec_11238 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_11239);
												mem_vec_11239 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11224);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11225);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11226);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11227);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11228);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11229);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11230);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11231);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11232);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11233);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11234);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11235);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11236);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11237);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11238);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11239);
								}
							}
						}
					}
				}
				for (y = y660 + 4, yp_0 = 0;
					y < y660 + 4 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 64
					// T (x, 7) (14 / 2)
					for (x990 = x991, x990_p_0 = 0;
						x990 < x991 + 14;
						x990 += 2, x990_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 64
						// T (f, 2) (64 / 32)
						for (f = f1320, fp_2 = f1320_p_1, fp_1 = f1320_p_0, fp_0 = 0;
							f < f1320 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h472, hp_0 = 0;
								h < h472 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 16, f = 32
								// T (x, 2) (2 / 1)
								for (x = x990, xp_1 = x990_p_0, xp_0 = 0;
									x < x990 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11240 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_11241 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_11242 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_11243 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_11244 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_11245 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_11246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_11247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_11248 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_11249 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_11250 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11251 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_11252 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_11253 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_11254 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_11255 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_11256 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_11257 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_11258 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_11259 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c990, cp_1 = c990_p_0, cp_0 = 0;
												c < c990 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11240);
												mem_vec_11240 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11241);
												mem_vec_11241 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11242);
												mem_vec_11242 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11243);
												mem_vec_11243 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11244);
												mem_vec_11244 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11245);
												mem_vec_11245 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11246);
												mem_vec_11246 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11247);
												mem_vec_11247 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11248);
												mem_vec_11248 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11249);
												mem_vec_11249 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11250);
												mem_vec_11250 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11251);
												mem_vec_11251 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11252);
												mem_vec_11252 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11253);
												mem_vec_11253 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11254);
												mem_vec_11254 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11255);
												mem_vec_11255 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11256);
												mem_vec_11256 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11257);
												mem_vec_11257 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11258);
												mem_vec_11258 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11259);
												mem_vec_11259 = vec_28;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_11240);
												mem_vec_11240 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_11241);
												mem_vec_11241 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_11242);
												mem_vec_11242 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_11243);
												mem_vec_11243 = vec_36;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_11244);
												mem_vec_11244 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_11245);
												mem_vec_11245 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_11246);
												mem_vec_11246 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_11247);
												mem_vec_11247 = vec_42;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_11248);
												mem_vec_11248 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_11249);
												mem_vec_11249 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_11250);
												mem_vec_11250 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_11251);
												mem_vec_11251 = vec_47;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_11252);
												mem_vec_11252 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_11253);
												mem_vec_11253 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_11254);
												mem_vec_11254 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_11255);
												mem_vec_11255 = vec_52;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_11256);
												mem_vec_11256 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_11257);
												mem_vec_11257 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_11258);
												mem_vec_11258 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_11259);
												mem_vec_11259 = vec_57;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_11240);
												mem_vec_11240 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_11241);
												mem_vec_11241 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_11242);
												mem_vec_11242 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_11243);
												mem_vec_11243 = vec_65;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_11244);
												mem_vec_11244 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_11245);
												mem_vec_11245 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_11246);
												mem_vec_11246 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_11247);
												mem_vec_11247 = vec_71;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_11248);
												mem_vec_11248 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_11249);
												mem_vec_11249 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_11250);
												mem_vec_11250 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_11251);
												mem_vec_11251 = vec_76;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_11252);
												mem_vec_11252 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_11253);
												mem_vec_11253 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_11254);
												mem_vec_11254 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_11255);
												mem_vec_11255 = vec_81;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_11256);
												mem_vec_11256 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_11257);
												mem_vec_11257 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_11258);
												mem_vec_11258 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_11259);
												mem_vec_11259 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11240);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11241);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11242);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11243);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11244);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11245);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11246);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11247);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11248);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11249);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11250);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11251);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11252);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11253);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11254);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11255);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11256);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11257);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11258);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11259);
								}
							}
						}
					}
				}
		}
	}
}


}