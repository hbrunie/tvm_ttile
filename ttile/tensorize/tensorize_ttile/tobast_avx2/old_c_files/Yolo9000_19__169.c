#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (1, x); T (2, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (1024, c); T (17, x); T (4, f)]
*/
IND_TYPE c, cp_0, c1194_p_0, cp_1, c1194, f, fp_0, f1592_p_0, f1593_p_0, fp_1, f1592_p_1, fp_2, f1592, f1593, x, xp_0, x1592_p_0, x1593_p_0, xp_1, x1592_p_1, xp_2, x1592, x1593, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y796 = 0;
IND_TYPE x1594 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1195 = 0;
IND_TYPE f1594 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_14328 ,mem_vec_14329 ,mem_vec_14330 ,mem_vec_14331 ,mem_vec_14332 ,mem_vec_14333 ,mem_vec_14334 ,mem_vec_14335 ,mem_vec_14336 ,mem_vec_14337 ,mem_vec_14338 ,mem_vec_14339 ,mem_vec_14340 ,mem_vec_14341 ,mem_vec_14342 ,mem_vec_14343 ,mem_vec_14344 ,mem_vec_14345 ,mem_vec_14346 ,mem_vec_14347 ,mem_vec_14348 ,mem_vec_14349 ,mem_vec_14350 ,mem_vec_14351 ,mem_vec_14352 ,mem_vec_14353 ,mem_vec_14354 ,mem_vec_14355 ,mem_vec_14356 ,mem_vec_14357 ,mem_vec_14358 ,mem_vec_14359 ,mem_vec_14360 ,mem_vec_14361 ,mem_vec_14362 ,mem_vec_14363 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 4) (512 / 128)
for (f1593 = f1594, f1593_p_0 = 0;
	f1593 < f1594 + 512;
	f1593 += 128, f1593_p_0 += 128){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 128
	// T (x, 17) (17 / 1)
	for (x1593 = x1594, x1593_p_0 = 0;
		x1593 < x1594 + 17;
		x1593 += 1, x1593_p_0 += 1){
		// y = 17, x = 1, h = 1, w = 1, c = 1024, f = 128
		// T (c, 1024) (1024 / 1)
		for (c1194 = c1195, c1194_p_0 = 0;
			c1194 < c1195 + 1024;
			c1194 += 1, c1194_p_0 += 1){
			// y = 17, x = 1, h = 1, w = 1, c = 1, f = 128
			// T (f, 2) (128 / 64)
			for (f1592 = f1593, f1592_p_1 = f1593_p_0, f1592_p_0 = 0;
				f1592 < f1593 + 128;
				f1592 += 64, f1592_p_1 += 64, f1592_p_0 += 64){
					for (y = y796, yp_0 = 0;
						y < y796 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
						// T (x, 1) (1 / 1)
						for (x1592 = x1593, x1592_p_1 = x1593_p_0, x1592_p_0 = 0;
							x1592 < x1593 + 1;
							x1592 += 1, x1592_p_1 += 1, x1592_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1592, fp_2 = f1592_p_1, fp_1 = f1592_p_0, fp_0 = 0;
								f < f1592 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1592, xp_2 = x1592_p_1, xp_1 = x1592_p_0, xp_0 = 0;
									x < x1592 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14328 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14329 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_14330 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14331 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_14332 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14333 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_14334 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14335 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_14336 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14337 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_14338 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14339 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_14340 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14341 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_14342 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14343 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c1194, cp_1 = c1194_p_0, cp_0 = 0;
												c < c1194 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14328);
												mem_vec_14328 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14329);
												mem_vec_14329 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14330);
												mem_vec_14330 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14331);
												mem_vec_14331 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14332);
												mem_vec_14332 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14333);
												mem_vec_14333 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14334);
												mem_vec_14334 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14335);
												mem_vec_14335 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14336);
												mem_vec_14336 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14337);
												mem_vec_14337 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14338);
												mem_vec_14338 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14339);
												mem_vec_14339 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14340);
												mem_vec_14340 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14341);
												mem_vec_14341 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14342);
												mem_vec_14342 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14343);
												mem_vec_14343 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14328);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_14329);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14330);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_14331);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14332);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_14333);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14334);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_14335);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14336);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_14337);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14338);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_14339);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14340);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_14341);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14342);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_14343);
								}
							}
						}
					}
					for (y = y796 + 12, yp_0 = 0;
						y < y796 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
						// T (x, 1) (1 / 1)
						for (x1592 = x1593, x1592_p_1 = x1593_p_0, x1592_p_0 = 0;
							x1592 < x1593 + 1;
							x1592 += 1, x1592_p_1 += 1, x1592_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1592, fp_2 = f1592_p_1, fp_1 = f1592_p_0, fp_0 = 0;
								f < f1592 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1592, xp_2 = x1592_p_1, xp_1 = x1592_p_0, xp_0 = 0;
									x < x1592 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14344 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14345 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_14346 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14347 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_14348 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14349 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_14350 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14351 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_14352 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14353 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_14354 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14355 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_14356 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14357 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_14358 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14359 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_14360 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_14361 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_14362 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_14363 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c1194, cp_1 = c1194_p_0, cp_0 = 0;
												c < c1194 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14344);
												mem_vec_14344 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14345);
												mem_vec_14345 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14346);
												mem_vec_14346 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14347);
												mem_vec_14347 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14348);
												mem_vec_14348 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14349);
												mem_vec_14349 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14350);
												mem_vec_14350 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14351);
												mem_vec_14351 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14352);
												mem_vec_14352 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14353);
												mem_vec_14353 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14354);
												mem_vec_14354 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14355);
												mem_vec_14355 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14356);
												mem_vec_14356 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14357);
												mem_vec_14357 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14358);
												mem_vec_14358 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14359);
												mem_vec_14359 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_14360);
												mem_vec_14360 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_14361);
												mem_vec_14361 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_14362);
												mem_vec_14362 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_14363);
												mem_vec_14363 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14344);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_14345);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14346);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_14347);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14348);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_14349);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14350);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_14351);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14352);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_14353);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14354);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_14355);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14356);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_14357);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14358);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_14359);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14360);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_14361);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14362);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_14363);
								}
							}
						}
					}
			}
		}
	}
}


}