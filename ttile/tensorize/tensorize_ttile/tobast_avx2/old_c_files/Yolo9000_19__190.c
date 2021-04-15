#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (8, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (32, c); T (17, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1032_p_0, cp_1, c1032, f, fp_0, f1376_p_0, f1377_p_0, fp_1, f1376_p_1, fp_2, f1376, f1377, x, xp_0, x1376_p_0, x1377_p_0, xp_1, x1376_p_1, xp_2, x1376, x1377, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y688 = 0;
IND_TYPE x1378 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1033 = 0;
IND_TYPE f1378 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_12384 ,mem_vec_12385 ,mem_vec_12386 ,mem_vec_12387 ,mem_vec_12388 ,mem_vec_12389 ,mem_vec_12390 ,mem_vec_12391 ,mem_vec_12392 ,mem_vec_12393 ,mem_vec_12394 ,mem_vec_12395 ,mem_vec_12396 ,mem_vec_12397 ,mem_vec_12398 ,mem_vec_12399 ,mem_vec_12400 ,mem_vec_12401 ,mem_vec_12402 ,mem_vec_12403 ,mem_vec_12404 ,mem_vec_12405 ,mem_vec_12406 ,mem_vec_12407 ,mem_vec_12408 ,mem_vec_12409 ,mem_vec_12410 ,mem_vec_12411 ,mem_vec_12412 ,mem_vec_12413 ,mem_vec_12414 ,mem_vec_12415 ,mem_vec_12416 ,mem_vec_12417 ,mem_vec_12418 ,mem_vec_12419 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 2) (512 / 256)
for (f1377 = f1378, f1377_p_0 = 0;
	f1377 < f1378 + 512;
	f1377 += 256, f1377_p_0 += 256){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 256
	// T (x, 17) (17 / 1)
	for (x1377 = x1378, x1377_p_0 = 0;
		x1377 < x1378 + 17;
		x1377 += 1, x1377_p_0 += 1){
		// y = 17, x = 1, h = 1, w = 1, c = 1024, f = 256
		// T (c, 32) (1024 / 32)
		for (c1032 = c1033, c1032_p_0 = 0;
			c1032 < c1033 + 1024;
			c1032 += 32, c1032_p_0 += 32){
			// y = 17, x = 1, h = 1, w = 1, c = 32, f = 256
			// T (f, 1) (256 / 256)
			for (f1376 = f1377, f1376_p_1 = f1377_p_0, f1376_p_0 = 0;
				f1376 < f1377 + 256;
				f1376 += 256, f1376_p_1 += 256, f1376_p_0 += 256){
					for (y = y688, yp_0 = 0;
						y < y688 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 256
						// T (x, 1) (1 / 1)
						for (x1376 = x1377, x1376_p_1 = x1377_p_0, x1376_p_0 = 0;
							x1376 < x1377 + 1;
							x1376 += 1, x1376_p_1 += 1, x1376_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1376, fp_2 = f1376_p_1, fp_1 = f1376_p_0, fp_0 = 0;
								f < f1376 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1376, xp_2 = x1376_p_1, xp_1 = x1376_p_0, xp_0 = 0;
									x < x1376 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12384 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_12385 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_12386 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_12387 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_12388 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_12389 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_12390 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_12391 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_12392 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_12393 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_12394 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_12395 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_12396 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_12397 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_12398 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_12399 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c1032, cp_1 = c1032_p_0, cp_0 = 0;
												c < c1032 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12384);
												mem_vec_12384 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12385);
												mem_vec_12385 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12386);
												mem_vec_12386 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12387);
												mem_vec_12387 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12388);
												mem_vec_12388 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12389);
												mem_vec_12389 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12390);
												mem_vec_12390 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12391);
												mem_vec_12391 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12392);
												mem_vec_12392 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12393);
												mem_vec_12393 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12394);
												mem_vec_12394 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12395);
												mem_vec_12395 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12396);
												mem_vec_12396 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12397);
												mem_vec_12397 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12398);
												mem_vec_12398 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12399);
												mem_vec_12399 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12384);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12385);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12386);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12387);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12388);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12389);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12390);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12391);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12392);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12393);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12394);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12395);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12396);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12397);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12398);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12399);
								}
							}
						}
					}
					for (y = y688 + 12, yp_0 = 0;
						y < y688 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 256
						// T (x, 1) (1 / 1)
						for (x1376 = x1377, x1376_p_1 = x1377_p_0, x1376_p_0 = 0;
							x1376 < x1377 + 1;
							x1376 += 1, x1376_p_1 += 1, x1376_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1376, fp_2 = f1376_p_1, fp_1 = f1376_p_0, fp_0 = 0;
								f < f1376 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1376, xp_2 = x1376_p_1, xp_1 = x1376_p_0, xp_0 = 0;
									x < x1376 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12400 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_12401 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_12402 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_12403 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_12404 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_12405 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_12406 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_12407 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_12408 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_12409 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_12410 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_12411 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_12412 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_12413 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_12414 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_12415 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_12416 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_12417 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_12418 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_12419 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c1032, cp_1 = c1032_p_0, cp_0 = 0;
												c < c1032 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12400);
												mem_vec_12400 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12401);
												mem_vec_12401 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12402);
												mem_vec_12402 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12403);
												mem_vec_12403 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12404);
												mem_vec_12404 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12405);
												mem_vec_12405 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12406);
												mem_vec_12406 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12407);
												mem_vec_12407 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12408);
												mem_vec_12408 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12409);
												mem_vec_12409 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12410);
												mem_vec_12410 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12411);
												mem_vec_12411 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12412);
												mem_vec_12412 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12413);
												mem_vec_12413 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12414);
												mem_vec_12414 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12415);
												mem_vec_12415 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12416);
												mem_vec_12416 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12417);
												mem_vec_12417 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12418);
												mem_vec_12418 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12419);
												mem_vec_12419 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12400);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12401);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12402);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12403);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12404);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12405);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12406);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12407);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12408);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12409);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12410);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12411);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12412);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12413);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12414);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12415);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12416);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12417);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12418);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12419);
								}
							}
						}
					}
			}
		}
	}
}


}