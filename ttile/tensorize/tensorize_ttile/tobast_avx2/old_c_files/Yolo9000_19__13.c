#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (1, x); T (4, f);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (128, c); T (1, x); T (4, f)]
*/
IND_TYPE c, cp_0, c690_p_0, cp_1, c690, f, fp_0, f920_p_0, f921_p_0, fp_1, f920_p_1, fp_2, f920, f921, x, xp_0, x920_p_0, x921_p_0, xp_1, x920_p_1, xp_2, x920, x921, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y460 = 0;
IND_TYPE x922 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c691 = 0;
IND_TYPE f922 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_8280 ,mem_vec_8281 ,mem_vec_8282 ,mem_vec_8283 ,mem_vec_8284 ,mem_vec_8285 ,mem_vec_8286 ,mem_vec_8287 ,mem_vec_8288 ,mem_vec_8289 ,mem_vec_8290 ,mem_vec_8291 ,mem_vec_8292 ,mem_vec_8293 ,mem_vec_8294 ,mem_vec_8295 ,mem_vec_8296 ,mem_vec_8297 ,mem_vec_8298 ,mem_vec_8299 ,mem_vec_8300 ,mem_vec_8301 ,mem_vec_8302 ,mem_vec_8303 ,mem_vec_8304 ,mem_vec_8305 ,mem_vec_8306 ,mem_vec_8307 ,mem_vec_8308 ,mem_vec_8309 ,mem_vec_8310 ,mem_vec_8311 ,mem_vec_8312 ,mem_vec_8313 ,mem_vec_8314 ,mem_vec_8315 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 4) (512 / 128)
for (f921 = f922, f921_p_0 = 0;
	f921 < f922 + 512;
	f921 += 128, f921_p_0 += 128){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 128
	// T (x, 1) (17 / 17)
	for (x921 = x922, x921_p_0 = 0;
		x921 < x922 + 17;
		x921 += 17, x921_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 128
		// T (c, 128) (1024 / 8)
		for (c690 = c691, c690_p_0 = 0;
			c690 < c691 + 1024;
			c690 += 8, c690_p_0 += 8){
			// y = 17, x = 17, h = 1, w = 1, c = 8, f = 128
			// T (f, 1) (128 / 128)
			for (f920 = f921, f920_p_1 = f921_p_0, f920_p_0 = 0;
				f920 < f921 + 128;
				f920 += 128, f920_p_1 += 128, f920_p_0 += 128){
					for (y = y460, yp_0 = 0;
						y < y460 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 128
						// T (x, 17) (17 / 1)
						for (x920 = x921, x920_p_1 = x921_p_0, x920_p_0 = 0;
							x920 < x921 + 17;
							x920 += 1, x920_p_1 += 1, x920_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 128
							// T (f, 4) (128 / 32)
							for (f = f920, fp_2 = f920_p_1, fp_1 = f920_p_0, fp_0 = 0;
								f < f920 + 128;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
								// T (x, 1) (1 / 1)
								for (x = x920, xp_2 = x920_p_1, xp_1 = x920_p_0, xp_0 = 0;
									x < x920 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8280 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8281 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_8282 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8283 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_8284 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8285 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_8286 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8287 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_8288 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8289 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_8290 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8291 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_8292 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8293 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_8294 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8295 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c690, cp_1 = c690_p_0, cp_0 = 0;
												c < c690 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8280);
												mem_vec_8280 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8281);
												mem_vec_8281 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8282);
												mem_vec_8282 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8283);
												mem_vec_8283 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8284);
												mem_vec_8284 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8285);
												mem_vec_8285 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8286);
												mem_vec_8286 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8287);
												mem_vec_8287 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8288);
												mem_vec_8288 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8289);
												mem_vec_8289 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8290);
												mem_vec_8290 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8291);
												mem_vec_8291 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8292);
												mem_vec_8292 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8293);
												mem_vec_8293 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8294);
												mem_vec_8294 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8295);
												mem_vec_8295 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8280);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8281);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8282);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8283);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8284);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8285);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8286);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8287);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8288);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8289);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8290);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8291);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8292);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8293);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8294);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8295);
								}
							}
						}
					}
					for (y = y460 + 12, yp_0 = 0;
						y < y460 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 128
						// T (x, 17) (17 / 1)
						for (x920 = x921, x920_p_1 = x921_p_0, x920_p_0 = 0;
							x920 < x921 + 17;
							x920 += 1, x920_p_1 += 1, x920_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 128
							// T (f, 4) (128 / 32)
							for (f = f920, fp_2 = f920_p_1, fp_1 = f920_p_0, fp_0 = 0;
								f < f920 + 128;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
								// T (x, 1) (1 / 1)
								for (x = x920, xp_2 = x920_p_1, xp_1 = x920_p_0, xp_0 = 0;
									x < x920 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8296 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8297 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_8298 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8299 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_8300 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8301 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_8302 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8303 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_8304 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8305 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_8306 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8307 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_8308 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8309 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_8310 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8311 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_8312 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8313 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_8314 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_8315 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c690, cp_1 = c690_p_0, cp_0 = 0;
												c < c690 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8296);
												mem_vec_8296 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8297);
												mem_vec_8297 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8298);
												mem_vec_8298 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8299);
												mem_vec_8299 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8300);
												mem_vec_8300 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8301);
												mem_vec_8301 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8302);
												mem_vec_8302 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8303);
												mem_vec_8303 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8304);
												mem_vec_8304 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8305);
												mem_vec_8305 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8306);
												mem_vec_8306 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8307);
												mem_vec_8307 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8308);
												mem_vec_8308 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8309);
												mem_vec_8309 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8310);
												mem_vec_8310 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8311);
												mem_vec_8311 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8312);
												mem_vec_8312 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8313);
												mem_vec_8313 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8314);
												mem_vec_8314 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8315);
												mem_vec_8315 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8296);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8297);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8298);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8299);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8300);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8301);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8302);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8303);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8304);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8305);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8306);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8307);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8308);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8309);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8310);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8311);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8312);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8313);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8314);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_8315);
								}
							}
						}
					}
			}
		}
	}
}


}