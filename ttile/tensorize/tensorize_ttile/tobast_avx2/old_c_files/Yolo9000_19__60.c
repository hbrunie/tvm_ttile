#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (1024, c); Hoist_vars [c]; T (1, x); T (2, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (4, f); T (1, c); T (17, x); T (2, f)]
*/
IND_TYPE c, cp_0, c864_p_0, cp_1, c864, f, fp_0, f1152_p_0, f1153_p_0, fp_1, f1152_p_1, fp_2, f1152, f1153, x, xp_0, x1152_p_0, x1153_p_0, xp_1, x1152_p_1, xp_2, x1152, x1153, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y576 = 0;
IND_TYPE x1154 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c865 = 0;
IND_TYPE f1154 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_10368 ,mem_vec_10369 ,mem_vec_10370 ,mem_vec_10371 ,mem_vec_10372 ,mem_vec_10373 ,mem_vec_10374 ,mem_vec_10375 ,mem_vec_10376 ,mem_vec_10377 ,mem_vec_10378 ,mem_vec_10379 ,mem_vec_10380 ,mem_vec_10381 ,mem_vec_10382 ,mem_vec_10383 ,mem_vec_10384 ,mem_vec_10385 ,mem_vec_10386 ,mem_vec_10387 ,mem_vec_10388 ,mem_vec_10389 ,mem_vec_10390 ,mem_vec_10391 ,mem_vec_10392 ,mem_vec_10393 ,mem_vec_10394 ,mem_vec_10395 ,mem_vec_10396 ,mem_vec_10397 ,mem_vec_10398 ,mem_vec_10399 ,mem_vec_10400 ,mem_vec_10401 ,mem_vec_10402 ,mem_vec_10403 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 2) (512 / 256)
for (f1153 = f1154, f1153_p_0 = 0;
	f1153 < f1154 + 512;
	f1153 += 256, f1153_p_0 += 256){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 256
	// T (x, 17) (17 / 1)
	for (x1153 = x1154, x1153_p_0 = 0;
		x1153 < x1154 + 17;
		x1153 += 1, x1153_p_0 += 1){
		// y = 17, x = 1, h = 1, w = 1, c = 1024, f = 256
		// T (c, 1) (1024 / 1024)
		for (c864 = c865, c864_p_0 = 0;
			c864 < c865 + 1024;
			c864 += 1024, c864_p_0 += 1024){
			// y = 17, x = 1, h = 1, w = 1, c = 1024, f = 256
			// T (f, 4) (256 / 64)
			for (f1152 = f1153, f1152_p_1 = f1153_p_0, f1152_p_0 = 0;
				f1152 < f1153 + 256;
				f1152 += 64, f1152_p_1 += 64, f1152_p_0 += 64){
					for (y = y576, yp_0 = 0;
						y < y576 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 64
						// T (x, 1) (1 / 1)
						for (x1152 = x1153, x1152_p_1 = x1153_p_0, x1152_p_0 = 0;
							x1152 < x1153 + 1;
							x1152 += 1, x1152_p_1 += 1, x1152_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1152, fp_2 = f1152_p_1, fp_1 = f1152_p_0, fp_0 = 0;
								f < f1152 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1152, xp_2 = x1152_p_1, xp_1 = x1152_p_0, xp_0 = 0;
									x < x1152 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_10368 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_10369 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_10370 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_10371 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_10372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_10373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_10374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_10375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_10376 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_10377 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_10378 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_10379 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_10380 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_10381 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_10382 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_10383 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
											// T (c, 1024) (1024 / 1)
											for (c = c864, cp_1 = c864_p_0, cp_0 = 0;
												c < c864 + 1024;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10368);
												mem_vec_10368 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10369);
												mem_vec_10369 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10370);
												mem_vec_10370 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10371);
												mem_vec_10371 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10372);
												mem_vec_10372 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10373);
												mem_vec_10373 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10374);
												mem_vec_10374 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10375);
												mem_vec_10375 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10376);
												mem_vec_10376 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10377);
												mem_vec_10377 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10378);
												mem_vec_10378 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10379);
												mem_vec_10379 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10380);
												mem_vec_10380 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10381);
												mem_vec_10381 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10382);
												mem_vec_10382 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10383);
												mem_vec_10383 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10368);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10369);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10370);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10371);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10372);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10373);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10374);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10375);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10376);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10377);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10378);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10379);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10380);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10381);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10382);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10383);
								}
							}
						}
					}
					for (y = y576 + 12, yp_0 = 0;
						y < y576 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 64
						// T (x, 1) (1 / 1)
						for (x1152 = x1153, x1152_p_1 = x1153_p_0, x1152_p_0 = 0;
							x1152 < x1153 + 1;
							x1152 += 1, x1152_p_1 += 1, x1152_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1152, fp_2 = f1152_p_1, fp_1 = f1152_p_0, fp_0 = 0;
								f < f1152 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1152, xp_2 = x1152_p_1, xp_1 = x1152_p_0, xp_0 = 0;
									x < x1152 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_10384 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_10385 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_10386 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_10387 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_10388 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_10389 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_10390 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_10391 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_10392 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_10393 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_10394 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_10395 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_10396 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_10397 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_10398 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_10399 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_10400 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_10401 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_10402 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_10403 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
											// T (c, 1024) (1024 / 1)
											for (c = c864, cp_1 = c864_p_0, cp_0 = 0;
												c < c864 + 1024;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10384);
												mem_vec_10384 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10385);
												mem_vec_10385 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10386);
												mem_vec_10386 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10387);
												mem_vec_10387 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10388);
												mem_vec_10388 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10389);
												mem_vec_10389 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10390);
												mem_vec_10390 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10391);
												mem_vec_10391 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10392);
												mem_vec_10392 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10393);
												mem_vec_10393 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10394);
												mem_vec_10394 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10395);
												mem_vec_10395 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10396);
												mem_vec_10396 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10397);
												mem_vec_10397 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10398);
												mem_vec_10398 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10399);
												mem_vec_10399 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10400);
												mem_vec_10400 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10401);
												mem_vec_10401 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10402);
												mem_vec_10402 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10403);
												mem_vec_10403 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10384);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10385);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10386);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10387);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10388);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10389);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10390);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10391);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10392);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10393);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10394);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10395);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10396);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10397);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10398);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10399);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10400);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10401);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10402);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10403);
								}
							}
						}
					}
			}
		}
	}
}


}