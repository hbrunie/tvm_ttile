#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (17, x); T (16, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (64, f);
  T (1, c); T (1, y); T (1, c)]
*/
IND_TYPE c, cp_0, c283_p_0, c284_p_0, c285_p_0, cp_1, c283_p_1, c284_p_1, cp_2, c283_p_2, cp_3, c283, c284, c285, f, fp_0, w, wp_0, x, xp_0, y, yp_0, y183_p_0, yp_1, y183;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y184 = 0;
IND_TYPE x166 = 0;
IND_TYPE h = 0;
IND_TYPE w144 = 0;
IND_TYPE c286 = 0;
IND_TYPE f298 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3238 ,mem_vec_3239 ,mem_vec_3240 ,mem_vec_3241 ,mem_vec_3242 ,mem_vec_3243 ,mem_vec_3244 ,mem_vec_3245 ,mem_vec_3246 ,mem_vec_3247 ,mem_vec_3248 ,mem_vec_3249 ,mem_vec_3250 ,mem_vec_3251 ,mem_vec_3252 ,mem_vec_3253 ,mem_vec_3254 ,mem_vec_3255 ,mem_vec_3256 ,mem_vec_3257 ,mem_vec_3258 ,mem_vec_3259 ,mem_vec_3260 ,mem_vec_3261 ,mem_vec_3262 ,mem_vec_3263 ,mem_vec_3264 ,mem_vec_3265 ,mem_vec_3266 ,mem_vec_3267 ,mem_vec_3268 ,mem_vec_3269 ,mem_vec_3270 ,mem_vec_3271 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 1) (512 / 512)
for (c285 = c286, c285_p_0 = 0;
	c285 < c286 + 512;
	c285 += 512, c285_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (y, 1) (17 / 17)
	for (y183 = y184, y183_p_0 = 0;
		y183 < y184 + 17;
		y183 += 17, y183_p_0 += 17){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
		// T (c, 1) (512 / 512)
		for (c284 = c285, c284_p_1 = c285_p_0, c284_p_0 = 0;
			c284 < c285 + 512;
			c284 += 512, c284_p_1 += 512, c284_p_0 += 512){
			// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
			// T (f, 64) (1024 / 16)
			for (f = f298, fp_0 = 0;
				f < f298 + 1024;
				f += 16, fp_0 += 16){
					for (y = y183, yp_1 = y183_p_0, yp_0 = 0;
						y < y183 + 8;
						y += 8, yp_1 += 8, yp_0 += 8){
						// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 16
						// T (c, 16) (512 / 32)
						for (c283 = c284, c283_p_2 = c284_p_1, c283_p_1 = c284_p_0, c283_p_0 = 0;
							c283 < c284 + 512;
							c283 += 32, c283_p_2 += 32, c283_p_1 += 32, c283_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 16
							// T (x, 17) (17 / 1)
							for (x = x166, xp_0 = 0;
								x < x166 + 17;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
								// T (w, 3) (3 / 1)
								for (w = w144, wp_0 = 0;
									w < w144 + 3;
									w += 1, wp_0 += 1){
											mem_vec_3238 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3239 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_3240 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3241 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_3242 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3243 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_3244 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3245 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_3246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_3248 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3249 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_3250 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3251 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_3252 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3253 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c283, cp_3 = c283_p_2, cp_2 = c283_p_1, cp_1 = c283_p_0, cp_0 = 0;
												c < c283 + 32;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3238);
												mem_vec_3238 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3239);
												mem_vec_3239 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_3240);
												mem_vec_3240 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_3241);
												mem_vec_3241 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_3242);
												mem_vec_3242 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_3243);
												mem_vec_3243 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_3244);
												mem_vec_3244 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_3245);
												mem_vec_3245 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3246);
												mem_vec_3246 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3247);
												mem_vec_3247 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_3248);
												mem_vec_3248 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_3249);
												mem_vec_3249 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_3250);
												mem_vec_3250 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_3251);
												mem_vec_3251 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_3252);
												mem_vec_3252 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_3253);
												mem_vec_3253 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_3238);
												mem_vec_3238 = vec_26;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_3239);
												mem_vec_3239 = vec_29;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_32 = _mm256_set1_ps(scal_9);


												vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_3240);
												mem_vec_3240 = vec_31;



												vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_3241);
												mem_vec_3241 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_3242);
												mem_vec_3242 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_3243);
												mem_vec_3243 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_3244);
												mem_vec_3244 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_3245);
												mem_vec_3245 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_3246);
												mem_vec_3246 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_3247);
												mem_vec_3247 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_3248);
												mem_vec_3248 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_3249);
												mem_vec_3249 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_3250);
												mem_vec_3250 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_3251);
												mem_vec_3251 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_3252);
												mem_vec_3252 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_3253);
												mem_vec_3253 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_3238);
												mem_vec_3238 = vec_52;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_3239);
												mem_vec_3239 = vec_55;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_17);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_3240);
												mem_vec_3240 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_3241);
												mem_vec_3241 = vec_59;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_61 = _mm256_set1_ps(scal_18);


												vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_3242);
												mem_vec_3242 = vec_60;



												vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_3243);
												mem_vec_3243 = vec_62;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_3244);
												mem_vec_3244 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_3245);
												mem_vec_3245 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_3246);
												mem_vec_3246 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_3247);
												mem_vec_3247 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_3248);
												mem_vec_3248 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_3249);
												mem_vec_3249 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_3250);
												mem_vec_3250 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_3251);
												mem_vec_3251 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_3252);
												mem_vec_3252 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_3253);
												mem_vec_3253 = vec_77;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3238);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3239);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3240);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3241);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3242);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3243);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3244);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3245);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3246);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3247);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3248);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3249);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3250);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3251);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3252);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_3253);
								}
							}
						}
					}
					for (y = y183 + 8, yp_1 = y183_p_0, yp_0 = 0;
						y < y183 + 8 + 9;
						y += 9, yp_1 += 9, yp_0 += 9){
						// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 16
						// T (c, 16) (512 / 32)
						for (c283 = c284, c283_p_2 = c284_p_1, c283_p_1 = c284_p_0, c283_p_0 = 0;
							c283 < c284 + 512;
							c283 += 32, c283_p_2 += 32, c283_p_1 += 32, c283_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 16
							// T (x, 17) (17 / 1)
							for (x = x166, xp_0 = 0;
								x < x166 + 17;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
								// T (w, 3) (3 / 1)
								for (w = w144, wp_0 = 0;
									w < w144 + 3;
									w += 1, wp_0 += 1){
											mem_vec_3254 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3255 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_3256 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3257 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_3258 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3259 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_3260 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3261 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_3262 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3263 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_3264 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3265 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_3266 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3267 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_3268 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3269 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_3270 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_3271 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c283, cp_3 = c283_p_2, cp_2 = c283_p_1, cp_1 = c283_p_0, cp_0 = 0;
												c < c283 + 32;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3254);
												mem_vec_3254 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3255);
												mem_vec_3255 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_3256);
												mem_vec_3256 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_3257);
												mem_vec_3257 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_3258);
												mem_vec_3258 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_3259);
												mem_vec_3259 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_3260);
												mem_vec_3260 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_3261);
												mem_vec_3261 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3262);
												mem_vec_3262 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3263);
												mem_vec_3263 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_3264);
												mem_vec_3264 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_3265);
												mem_vec_3265 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_3266);
												mem_vec_3266 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_3267);
												mem_vec_3267 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_3268);
												mem_vec_3268 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_3269);
												mem_vec_3269 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_3270);
												mem_vec_3270 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_3271);
												mem_vec_3271 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_3254);
												mem_vec_3254 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_3255);
												mem_vec_3255 = vec_32;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_31, mem_vec_3256);
												mem_vec_3256 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_33, mem_vec_3257);
												mem_vec_3257 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_31, mem_vec_3258);
												mem_vec_3258 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_33, mem_vec_3259);
												mem_vec_3259 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_31, mem_vec_3260);
												mem_vec_3260 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_33, mem_vec_3261);
												mem_vec_3261 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_3262);
												mem_vec_3262 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_3263);
												mem_vec_3263 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_31, mem_vec_3264);
												mem_vec_3264 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_33, mem_vec_3265);
												mem_vec_3265 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_31, mem_vec_3266);
												mem_vec_3266 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_33, mem_vec_3267);
												mem_vec_3267 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_31, mem_vec_3268);
												mem_vec_3268 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_33, mem_vec_3269);
												mem_vec_3269 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_31, mem_vec_3270);
												mem_vec_3270 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_33, mem_vec_3271);
												mem_vec_3271 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_3254);
												mem_vec_3254 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_3255);
												mem_vec_3255 = vec_61;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_60, mem_vec_3256);
												mem_vec_3256 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_62, mem_vec_3257);
												mem_vec_3257 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_60, mem_vec_3258);
												mem_vec_3258 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_62, mem_vec_3259);
												mem_vec_3259 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_60, mem_vec_3260);
												mem_vec_3260 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_62, mem_vec_3261);
												mem_vec_3261 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_3262);
												mem_vec_3262 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_3263);
												mem_vec_3263 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_60, mem_vec_3264);
												mem_vec_3264 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_62, mem_vec_3265);
												mem_vec_3265 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_60, mem_vec_3266);
												mem_vec_3266 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_62, mem_vec_3267);
												mem_vec_3267 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_60, mem_vec_3268);
												mem_vec_3268 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_62, mem_vec_3269);
												mem_vec_3269 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_60, mem_vec_3270);
												mem_vec_3270 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_62, mem_vec_3271);
												mem_vec_3271 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3254);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3255);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3256);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3257);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3258);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3259);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3260);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3261);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3262);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3263);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3264);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3265);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3266);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3267);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3268);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_3269);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3270);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_3271);
								}
							}
						}
					}
			}
		}
	}
}


}