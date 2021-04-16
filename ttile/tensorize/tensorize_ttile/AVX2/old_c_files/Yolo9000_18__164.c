#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (17, x); T (8, c); T (1, y); T (64, f); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (2, c)]
*/
IND_TYPE c, cp_0, c454_p_0, c455_p_0, c456_p_0, cp_1, c454_p_1, c455_p_1, cp_2, c454_p_2, cp_3, c454, c455, c456, f, fp_0, w, wp_0, x, xp_0, y, yp_0, y293_p_0, yp_1, y293;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y294 = 0;
IND_TYPE x264 = 0;
IND_TYPE h = 0;
IND_TYPE w234 = 0;
IND_TYPE c457 = 0;
IND_TYPE f470 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_5262 ,mem_vec_5263 ,mem_vec_5264 ,mem_vec_5265 ,mem_vec_5266 ,mem_vec_5267 ,mem_vec_5268 ,mem_vec_5269 ,mem_vec_5270 ,mem_vec_5271 ,mem_vec_5272 ,mem_vec_5273 ,mem_vec_5274 ,mem_vec_5275 ,mem_vec_5276 ,mem_vec_5277 ,mem_vec_5278 ,mem_vec_5279 ,mem_vec_5280 ,mem_vec_5281 ,mem_vec_5282 ,mem_vec_5283 ,mem_vec_5284 ,mem_vec_5285 ,mem_vec_5286 ,mem_vec_5287 ,mem_vec_5288 ,mem_vec_5289 ,mem_vec_5290 ,mem_vec_5291 ,mem_vec_5292 ,mem_vec_5293 ,mem_vec_5294 ,mem_vec_5295 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 2) (512 / 256)
for (c456 = c457, c456_p_0 = 0;
	c456 < c457 + 512;
	c456 += 256, c456_p_0 += 256){
		for (y293 = y294, y293_p_0 = 0;
			y293 < y294 + 8;
			y293 += 8, y293_p_0 += 8){
			// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 1024
			// T (c, 1) (256 / 256)
			for (c455 = c456, c455_p_1 = c456_p_0, c455_p_0 = 0;
				c455 < c456 + 256;
				c455 += 256, c455_p_1 += 256, c455_p_0 += 256){
				// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 1024
				// T (f, 64) (1024 / 16)
				for (f = f470, fp_0 = 0;
					f < f470 + 1024;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 16
					// T (y, 1) (ph_y / ph_y)
					for (y = y293, yp_1 = y293_p_0, yp_0 = 0;
						y < y293 + 8;
						y += 8, yp_1 += 8, yp_0 += 8){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 16
						// T (c, 8) (256 / 32)
						for (c454 = c455, c454_p_2 = c455_p_1, c454_p_1 = c455_p_0, c454_p_0 = 0;
							c454 < c455 + 256;
							c454 += 32, c454_p_2 += 32, c454_p_1 += 32, c454_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 16
							// T (x, 17) (17 / 1)
							for (x = x264, xp_0 = 0;
								x < x264 + 17;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
								// T (w, 3) (3 / 1)
								for (w = w234, wp_0 = 0;
									w < w234 + 3;
									w += 1, wp_0 += 1){
											mem_vec_5262 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5263 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5264 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5265 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5266 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5267 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5268 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5269 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5270 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5271 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_5272 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5273 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_5274 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5275 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_5276 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5277 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c454, cp_3 = c454_p_2, cp_2 = c454_p_1, cp_1 = c454_p_0, cp_0 = 0;
												c < c454 + 32;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5262);
												mem_vec_5262 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5263);
												mem_vec_5263 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_5264);
												mem_vec_5264 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_5265);
												mem_vec_5265 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_5266);
												mem_vec_5266 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_5267);
												mem_vec_5267 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_5268);
												mem_vec_5268 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_5269);
												mem_vec_5269 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5270);
												mem_vec_5270 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5271);
												mem_vec_5271 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_5272);
												mem_vec_5272 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_5273);
												mem_vec_5273 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_5274);
												mem_vec_5274 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_5275);
												mem_vec_5275 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_5276);
												mem_vec_5276 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_5277);
												mem_vec_5277 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_5262);
												mem_vec_5262 = vec_26;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_5263);
												mem_vec_5263 = vec_29;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_32 = _mm256_set1_ps(scal_9);


												vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_5264);
												mem_vec_5264 = vec_31;



												vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_5265);
												mem_vec_5265 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_5266);
												mem_vec_5266 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_5267);
												mem_vec_5267 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_5268);
												mem_vec_5268 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_5269);
												mem_vec_5269 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_5270);
												mem_vec_5270 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_5271);
												mem_vec_5271 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_5272);
												mem_vec_5272 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_5273);
												mem_vec_5273 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_5274);
												mem_vec_5274 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_5275);
												mem_vec_5275 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_5276);
												mem_vec_5276 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_5277);
												mem_vec_5277 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_5262);
												mem_vec_5262 = vec_52;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_5263);
												mem_vec_5263 = vec_55;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_17);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_5264);
												mem_vec_5264 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_5265);
												mem_vec_5265 = vec_59;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_61 = _mm256_set1_ps(scal_18);


												vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_5266);
												mem_vec_5266 = vec_60;



												vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_5267);
												mem_vec_5267 = vec_62;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_5268);
												mem_vec_5268 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_5269);
												mem_vec_5269 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_5270);
												mem_vec_5270 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_5271);
												mem_vec_5271 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_5272);
												mem_vec_5272 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_5273);
												mem_vec_5273 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_5274);
												mem_vec_5274 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_5275);
												mem_vec_5275 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_5276);
												mem_vec_5276 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_5277);
												mem_vec_5277 = vec_77;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5262);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5263);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5264);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5265);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5266);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5267);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5268);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5269);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5270);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5271);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5272);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_5273);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5274);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_5275);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5276);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_5277);
								}
							}
						}
					}
				}
			}
		}
		for (y293 = y294 + 8, y293_p_0 = 0;
			y293 < y294 + 8 + 9;
			y293 += 9, y293_p_0 += 9){
			// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 1024
			// T (c, 1) (256 / 256)
			for (c455 = c456, c455_p_1 = c456_p_0, c455_p_0 = 0;
				c455 < c456 + 256;
				c455 += 256, c455_p_1 += 256, c455_p_0 += 256){
				// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 1024
				// T (f, 64) (1024 / 16)
				for (f = f470, fp_0 = 0;
					f < f470 + 1024;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 16
					// T (y, 1) (ph_y / ph_y)
					for (y = y293, yp_1 = y293_p_0, yp_0 = 0;
						y < y293 + 9;
						y += 9, yp_1 += 9, yp_0 += 9){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 16
						// T (c, 8) (256 / 32)
						for (c454 = c455, c454_p_2 = c455_p_1, c454_p_1 = c455_p_0, c454_p_0 = 0;
							c454 < c455 + 256;
							c454 += 32, c454_p_2 += 32, c454_p_1 += 32, c454_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 16
							// T (x, 17) (17 / 1)
							for (x = x264, xp_0 = 0;
								x < x264 + 17;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
								// T (w, 3) (3 / 1)
								for (w = w234, wp_0 = 0;
									w < w234 + 3;
									w += 1, wp_0 += 1){
											mem_vec_5278 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5279 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5280 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5281 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5282 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5283 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5284 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5285 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5286 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5287 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_5288 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5289 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_5290 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5291 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_5292 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5293 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_5294 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_5295 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c454, cp_3 = c454_p_2, cp_2 = c454_p_1, cp_1 = c454_p_0, cp_0 = 0;
												c < c454 + 32;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5278);
												mem_vec_5278 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5279);
												mem_vec_5279 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_5280);
												mem_vec_5280 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_5281);
												mem_vec_5281 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_5282);
												mem_vec_5282 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_5283);
												mem_vec_5283 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_5284);
												mem_vec_5284 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_5285);
												mem_vec_5285 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5286);
												mem_vec_5286 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5287);
												mem_vec_5287 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_5288);
												mem_vec_5288 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_5289);
												mem_vec_5289 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_5290);
												mem_vec_5290 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_5291);
												mem_vec_5291 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_5292);
												mem_vec_5292 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_5293);
												mem_vec_5293 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_5294);
												mem_vec_5294 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_5295);
												mem_vec_5295 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_5278);
												mem_vec_5278 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_5279);
												mem_vec_5279 = vec_32;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_31, mem_vec_5280);
												mem_vec_5280 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_33, mem_vec_5281);
												mem_vec_5281 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_31, mem_vec_5282);
												mem_vec_5282 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_33, mem_vec_5283);
												mem_vec_5283 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_31, mem_vec_5284);
												mem_vec_5284 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_33, mem_vec_5285);
												mem_vec_5285 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_5286);
												mem_vec_5286 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_5287);
												mem_vec_5287 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_31, mem_vec_5288);
												mem_vec_5288 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_33, mem_vec_5289);
												mem_vec_5289 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_31, mem_vec_5290);
												mem_vec_5290 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_33, mem_vec_5291);
												mem_vec_5291 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_31, mem_vec_5292);
												mem_vec_5292 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_33, mem_vec_5293);
												mem_vec_5293 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_31, mem_vec_5294);
												mem_vec_5294 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_33, mem_vec_5295);
												mem_vec_5295 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_5278);
												mem_vec_5278 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_5279);
												mem_vec_5279 = vec_61;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_60, mem_vec_5280);
												mem_vec_5280 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_62, mem_vec_5281);
												mem_vec_5281 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_60, mem_vec_5282);
												mem_vec_5282 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_62, mem_vec_5283);
												mem_vec_5283 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_60, mem_vec_5284);
												mem_vec_5284 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_62, mem_vec_5285);
												mem_vec_5285 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_5286);
												mem_vec_5286 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_5287);
												mem_vec_5287 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_60, mem_vec_5288);
												mem_vec_5288 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_62, mem_vec_5289);
												mem_vec_5289 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_60, mem_vec_5290);
												mem_vec_5290 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_62, mem_vec_5291);
												mem_vec_5291 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_60, mem_vec_5292);
												mem_vec_5292 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_62, mem_vec_5293);
												mem_vec_5293 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_60, mem_vec_5294);
												mem_vec_5294 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_62, mem_vec_5295);
												mem_vec_5295 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5278);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5279);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5280);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5281);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5282);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5283);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5284);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5285);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5286);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5287);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5288);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_5289);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5290);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_5291);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5292);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_5293);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5294);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_5295);
								}
							}
						}
					}
				}
			}
		}
}


}