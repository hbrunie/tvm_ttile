#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (4, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))]; T (4, f);
  T (16, c); T (1, f)]
*/
IND_TYPE c, cp_0, c984_p_0, cp_1, c984, f, fp_0, f1312_p_0, f1313_p_0, fp_1, f1312_p_1, fp_2, f1312, f1313, h, hp_0, x, xp_0, x984_p_0, xp_1, x984, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y656 = 0;
IND_TYPE x985 = 0;
IND_TYPE h470 = 0;
IND_TYPE w = 0;
IND_TYPE c985 = 0;
IND_TYPE f1314 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11328 ,mem_vec_11329 ,mem_vec_11330 ,mem_vec_11331 ,mem_vec_11332 ,mem_vec_11333 ,mem_vec_11334 ,mem_vec_11335 ,mem_vec_11336 ,mem_vec_11337 ,mem_vec_11338 ,mem_vec_11339 ,mem_vec_11340 ,mem_vec_11341 ,mem_vec_11342 ,mem_vec_11343 ,mem_vec_11344 ,mem_vec_11345 ,mem_vec_11346 ,mem_vec_11347 ,mem_vec_11348 ,mem_vec_11349 ,mem_vec_11350 ,mem_vec_11351 ,mem_vec_11352 ,mem_vec_11353 ,mem_vec_11354 ,mem_vec_11355 ,mem_vec_11356 ,mem_vec_11357 ,mem_vec_11358 ,mem_vec_11359 ,mem_vec_11360 ,mem_vec_11361 ,mem_vec_11362 ,mem_vec_11363 ,mem_vec_11364 ,mem_vec_11365 ,mem_vec_11366 ,mem_vec_11367 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (f, 1) (512 / 512)
for (f1313 = f1314, f1313_p_0 = 0;
	f1313 < f1314 + 512;
	f1313 += 512, f1313_p_0 += 512){
	// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
	// T (c, 16) (512 / 32)
	for (c984 = c985, c984_p_0 = 0;
		c984 < c985 + 512;
		c984 += 32, c984_p_0 += 32){
		// y = 14, x = 14, h = 3, w = 3, c = 32, f = 512
		// T (f, 4) (512 / 128)
		for (f1312 = f1313, f1312_p_1 = f1313_p_0, f1312_p_0 = 0;
			f1312 < f1313 + 512;
			f1312 += 128, f1312_p_1 += 128, f1312_p_0 += 128){
				for (y = y656, yp_0 = 0;
					y < y656 + 8;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 128
					// T (x, 1) (14 / 14)
					for (x984 = x985, x984_p_0 = 0;
						x984 < x985 + 14;
						x984 += 14, x984_p_0 += 14){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 128
						// T (f, 4) (128 / 32)
						for (f = f1312, fp_2 = f1312_p_1, fp_1 = f1312_p_0, fp_0 = 0;
							f < f1312 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h470, hp_0 = 0;
								h < h470 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 3, c = 32, f = 32
								// T (x, 14) (14 / 1)
								for (x = x984, xp_1 = x984_p_0, xp_0 = 0;
									x < x984 + 14;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11328 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_11329 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_11330 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_11331 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_11332 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_11333 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_11334 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_11335 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_11336 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_11337 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_11338 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11339 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_11340 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_11341 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_11342 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_11343 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c984, cp_1 = c984_p_0, cp_0 = 0;
												c < c984 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11328);
												mem_vec_11328 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11329);
												mem_vec_11329 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11330);
												mem_vec_11330 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11331);
												mem_vec_11331 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11332);
												mem_vec_11332 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11333);
												mem_vec_11333 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11334);
												mem_vec_11334 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11335);
												mem_vec_11335 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11336);
												mem_vec_11336 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11337);
												mem_vec_11337 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11338);
												mem_vec_11338 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11339);
												mem_vec_11339 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11340);
												mem_vec_11340 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11341);
												mem_vec_11341 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11342);
												mem_vec_11342 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11343);
												mem_vec_11343 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_11328);
												mem_vec_11328 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_11329);
												mem_vec_11329 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_11330);
												mem_vec_11330 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_11331);
												mem_vec_11331 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_11332);
												mem_vec_11332 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_11333);
												mem_vec_11333 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_11334);
												mem_vec_11334 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_11335);
												mem_vec_11335 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_11336);
												mem_vec_11336 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_11337);
												mem_vec_11337 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_11338);
												mem_vec_11338 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_11339);
												mem_vec_11339 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_11340);
												mem_vec_11340 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_11341);
												mem_vec_11341 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_11342);
												mem_vec_11342 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_11343);
												mem_vec_11343 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_11328);
												mem_vec_11328 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_11329);
												mem_vec_11329 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_11330);
												mem_vec_11330 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_11331);
												mem_vec_11331 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_11332);
												mem_vec_11332 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_11333);
												mem_vec_11333 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_11334);
												mem_vec_11334 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_11335);
												mem_vec_11335 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_11336);
												mem_vec_11336 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_11337);
												mem_vec_11337 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_11338);
												mem_vec_11338 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_11339);
												mem_vec_11339 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_11340);
												mem_vec_11340 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_11341);
												mem_vec_11341 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_11342);
												mem_vec_11342 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_11343);
												mem_vec_11343 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11328);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11329);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11330);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11331);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11332);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11333);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11334);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11335);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11336);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11337);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11338);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11339);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11340);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11341);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11342);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11343);
								}
							}
						}
					}
				}
				for (y = y656 + 8, yp_0 = 0;
					y < y656 + 8 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 128
					// T (x, 1) (14 / 14)
					for (x984 = x985, x984_p_0 = 0;
						x984 < x985 + 14;
						x984 += 14, x984_p_0 += 14){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 128
						// T (f, 4) (128 / 32)
						for (f = f1312, fp_2 = f1312_p_1, fp_1 = f1312_p_0, fp_0 = 0;
							f < f1312 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h470, hp_0 = 0;
								h < h470 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 3, c = 32, f = 32
								// T (x, 14) (14 / 1)
								for (x = x984, xp_1 = x984_p_0, xp_0 = 0;
									x < x984 + 14;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11344 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_11345 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_11346 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_11347 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_11348 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_11349 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_11350 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_11351 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_11352 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_11353 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_11354 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11355 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_11356 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_11357 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_11358 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_11359 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_11360 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_11361 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_11362 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_11363 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_11364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_11365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_11366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_11367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c984, cp_1 = c984_p_0, cp_0 = 0;
												c < c984 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11344);
												mem_vec_11344 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11345);
												mem_vec_11345 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11346);
												mem_vec_11346 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11347);
												mem_vec_11347 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11348);
												mem_vec_11348 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11349);
												mem_vec_11349 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11350);
												mem_vec_11350 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11351);
												mem_vec_11351 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11352);
												mem_vec_11352 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11353);
												mem_vec_11353 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11354);
												mem_vec_11354 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11355);
												mem_vec_11355 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11356);
												mem_vec_11356 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11357);
												mem_vec_11357 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11358);
												mem_vec_11358 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11359);
												mem_vec_11359 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11360);
												mem_vec_11360 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11361);
												mem_vec_11361 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11362);
												mem_vec_11362 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11363);
												mem_vec_11363 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_11364);
												mem_vec_11364 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_11365);
												mem_vec_11365 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_11366);
												mem_vec_11366 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_11367);
												mem_vec_11367 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_11344);
												mem_vec_11344 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_11345);
												mem_vec_11345 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_11346);
												mem_vec_11346 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_11347);
												mem_vec_11347 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_11348);
												mem_vec_11348 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_11349);
												mem_vec_11349 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_11350);
												mem_vec_11350 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_11351);
												mem_vec_11351 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_11352);
												mem_vec_11352 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_11353);
												mem_vec_11353 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_11354);
												mem_vec_11354 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_11355);
												mem_vec_11355 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_11356);
												mem_vec_11356 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_11357);
												mem_vec_11357 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_11358);
												mem_vec_11358 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_11359);
												mem_vec_11359 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_11360);
												mem_vec_11360 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_11361);
												mem_vec_11361 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_11362);
												mem_vec_11362 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_11363);
												mem_vec_11363 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_11364);
												mem_vec_11364 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_11365);
												mem_vec_11365 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_11366);
												mem_vec_11366 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_11367);
												mem_vec_11367 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_11344);
												mem_vec_11344 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_11345);
												mem_vec_11345 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_11346);
												mem_vec_11346 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_11347);
												mem_vec_11347 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_11348);
												mem_vec_11348 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_11349);
												mem_vec_11349 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_11350);
												mem_vec_11350 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_11351);
												mem_vec_11351 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_11352);
												mem_vec_11352 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_11353);
												mem_vec_11353 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_11354);
												mem_vec_11354 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_11355);
												mem_vec_11355 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_11356);
												mem_vec_11356 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_11357);
												mem_vec_11357 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_11358);
												mem_vec_11358 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_11359);
												mem_vec_11359 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_11360);
												mem_vec_11360 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_11361);
												mem_vec_11361 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_11362);
												mem_vec_11362 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_11363);
												mem_vec_11363 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_11364);
												mem_vec_11364 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_11365);
												mem_vec_11365 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_11366);
												mem_vec_11366 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_11367);
												mem_vec_11367 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11344);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11345);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11346);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11347);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11348);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11349);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11350);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11351);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11352);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11353);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11354);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11355);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11356);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11357);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11358);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11359);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11360);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11361);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11362);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11363);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11364);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_11365);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11366);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_11367);
								}
							}
						}
					}
				}
		}
	}
}


}