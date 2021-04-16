#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (1, x); T (16, y); T (2, c); T (2, f); T (272, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (1, x)]
*/
IND_TYPE c, cp_0, c120_p_0, cp_1, c120, f, fp_0, w, wp_0, x, xp_0, x160_p_0, x161_p_0, xp_1, x160_p_1, xp_2, x160, x161, y, yp_0, y144_p_0, yp_1, y144;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y145 = 0;
IND_TYPE x162 = 0;
IND_TYPE h = 0;
IND_TYPE w74 = 0;
IND_TYPE c121 = 0;
IND_TYPE f77 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1332 ,mem_vec_1333 ,mem_vec_1334 ,mem_vec_1335 ,mem_vec_1336 ,mem_vec_1337 ,mem_vec_1338 ,mem_vec_1339 ,mem_vec_1340 ,mem_vec_1341 ,mem_vec_1342 ,mem_vec_1343 ,mem_vec_1344 ,mem_vec_1345 ,mem_vec_1346 ,mem_vec_1347 ,mem_vec_1348 ,mem_vec_1349 ,mem_vec_1350 ,mem_vec_1351 ,mem_vec_1352 ,mem_vec_1353 ,mem_vec_1354 ,mem_vec_1355 ,mem_vec_1356 ,mem_vec_1357 ,mem_vec_1358 ,mem_vec_1359 ,mem_vec_1360 ,mem_vec_1361 ,mem_vec_1362 ,mem_vec_1363 ,mem_vec_1364 ,mem_vec_1365 ,mem_vec_1366 ,mem_vec_1367 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 1) (272 / 272)
for (x161 = x162, x161_p_0 = 0;
	x161 < x162 + 272;
	x161 += 272, x161_p_0 += 272){
		for (y144 = y145, y144_p_0 = 0;
			y144 < y145 + 192;
			y144 += 64, y144_p_0 += 64){
			// y = 16 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
			// T (x, 272) (272 / 1)
			for (x160 = x161, x160_p_1 = x161_p_0, x160_p_0 = 0;
				x160 < x161 + 272;
				x160 += 1, x160_p_1 += 1, x160_p_0 += 1){
				// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f77, fp_0 = 0;
					f < f77 + 64;
					f += 32, fp_0 += 32){
					// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c120 = c121, c120_p_0 = 0;
						c120 < c121 + 32;
						c120 += 16, c120_p_0 += 16){
						// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (y, 16) (16 * ph_y / ph_y)
						for (y = y144, yp_1 = y144_p_0, yp_0 = 0;
							y < y144 + 64;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (x, 1) (1 / 1)
							for (x = x160, xp_2 = x160_p_1, xp_1 = x160_p_0, xp_0 = 0;
								x < x160 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w74, wp_0 = 0;
									w < w74 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1332 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1333 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1334 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1335 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_1336 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1337 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1338 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1339 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_1340 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1341 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1342 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1343 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_1344 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1345 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1346 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1347 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c120, cp_1 = c120_p_0, cp_0 = 0;
												c < c120 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1332);
												mem_vec_1332 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1333);
												mem_vec_1333 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1334);
												mem_vec_1334 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1335);
												mem_vec_1335 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1336);
												mem_vec_1336 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1337);
												mem_vec_1337 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1338);
												mem_vec_1338 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1339);
												mem_vec_1339 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1340);
												mem_vec_1340 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1341);
												mem_vec_1341 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1342);
												mem_vec_1342 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1343);
												mem_vec_1343 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1344);
												mem_vec_1344 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1345);
												mem_vec_1345 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1346);
												mem_vec_1346 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1347);
												mem_vec_1347 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_1332);
												mem_vec_1332 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_1333);
												mem_vec_1333 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_1334);
												mem_vec_1334 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_1335);
												mem_vec_1335 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_1336);
												mem_vec_1336 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_1337);
												mem_vec_1337 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_1338);
												mem_vec_1338 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_1339);
												mem_vec_1339 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_1340);
												mem_vec_1340 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_1341);
												mem_vec_1341 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_1342);
												mem_vec_1342 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_1343);
												mem_vec_1343 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_1344);
												mem_vec_1344 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_1345);
												mem_vec_1345 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_1346);
												mem_vec_1346 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_1347);
												mem_vec_1347 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_1332);
												mem_vec_1332 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_1333);
												mem_vec_1333 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_1334);
												mem_vec_1334 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_1335);
												mem_vec_1335 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_1336);
												mem_vec_1336 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_1337);
												mem_vec_1337 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_1338);
												mem_vec_1338 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_1339);
												mem_vec_1339 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_1340);
												mem_vec_1340 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_1341);
												mem_vec_1341 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_1342);
												mem_vec_1342 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_1343);
												mem_vec_1343 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_1344);
												mem_vec_1344 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_1345);
												mem_vec_1345 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_1346);
												mem_vec_1346 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_1347);
												mem_vec_1347 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1332);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1333);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1334);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1335);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1336);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1337);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1338);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1339);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1340);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1341);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1342);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1343);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1344);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1345);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1346);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1347);
								}
							}
						}
					}
				}
			}
		}
		for (y144 = y145 + 192, y144_p_0 = 0;
			y144 < y145 + 192 + 80;
			y144 += 80, y144_p_0 += 80){
			// y = 16 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
			// T (x, 272) (272 / 1)
			for (x160 = x161, x160_p_1 = x161_p_0, x160_p_0 = 0;
				x160 < x161 + 272;
				x160 += 1, x160_p_1 += 1, x160_p_0 += 1){
				// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f77, fp_0 = 0;
					f < f77 + 64;
					f += 32, fp_0 += 32){
					// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c120 = c121, c120_p_0 = 0;
						c120 < c121 + 32;
						c120 += 16, c120_p_0 += 16){
						// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (y, 16) (16 * ph_y / ph_y)
						for (y = y144, yp_1 = y144_p_0, yp_0 = 0;
							y < y144 + 80;
							y += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (x, 1) (1 / 1)
							for (x = x160, xp_2 = x160_p_1, xp_1 = x160_p_0, xp_0 = 0;
								x < x160 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w74, wp_0 = 0;
									w < w74 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1348 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1349 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1350 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1351 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_1352 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1353 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1354 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1355 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_1356 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1357 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1358 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1359 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_1360 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1361 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1362 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1363 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_1364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_1366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c120, cp_1 = c120_p_0, cp_0 = 0;
												c < c120 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1348);
												mem_vec_1348 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1349);
												mem_vec_1349 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1350);
												mem_vec_1350 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1351);
												mem_vec_1351 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1352);
												mem_vec_1352 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1353);
												mem_vec_1353 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1354);
												mem_vec_1354 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1355);
												mem_vec_1355 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1356);
												mem_vec_1356 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1357);
												mem_vec_1357 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1358);
												mem_vec_1358 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1359);
												mem_vec_1359 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1360);
												mem_vec_1360 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1361);
												mem_vec_1361 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1362);
												mem_vec_1362 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1363);
												mem_vec_1363 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1364);
												mem_vec_1364 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1365);
												mem_vec_1365 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1366);
												mem_vec_1366 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1367);
												mem_vec_1367 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_1348);
												mem_vec_1348 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_1349);
												mem_vec_1349 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_1350);
												mem_vec_1350 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_1351);
												mem_vec_1351 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_1352);
												mem_vec_1352 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_1353);
												mem_vec_1353 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_1354);
												mem_vec_1354 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_1355);
												mem_vec_1355 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_1356);
												mem_vec_1356 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_1357);
												mem_vec_1357 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_1358);
												mem_vec_1358 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_1359);
												mem_vec_1359 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_1360);
												mem_vec_1360 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_1361);
												mem_vec_1361 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_1362);
												mem_vec_1362 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_1363);
												mem_vec_1363 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_1364);
												mem_vec_1364 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_1365);
												mem_vec_1365 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_1366);
												mem_vec_1366 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_1367);
												mem_vec_1367 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_1348);
												mem_vec_1348 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_1349);
												mem_vec_1349 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_1350);
												mem_vec_1350 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_1351);
												mem_vec_1351 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_1352);
												mem_vec_1352 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_1353);
												mem_vec_1353 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_1354);
												mem_vec_1354 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_1355);
												mem_vec_1355 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_1356);
												mem_vec_1356 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_1357);
												mem_vec_1357 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_1358);
												mem_vec_1358 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_1359);
												mem_vec_1359 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_1360);
												mem_vec_1360 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_1361);
												mem_vec_1361 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_1362);
												mem_vec_1362 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_1363);
												mem_vec_1363 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_1364);
												mem_vec_1364 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_1365);
												mem_vec_1365 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_1366);
												mem_vec_1366 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_1367);
												mem_vec_1367 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1348);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1349);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1350);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1351);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1352);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1353);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1354);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1355);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1356);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1357);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1358);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1359);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1360);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1361);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1362);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1363);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1364);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1365);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1366);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1367);
								}
							}
						}
					}
				}
			}
		}
}


}