#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (8, f);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (512, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c768_p_0, cp_1, c768, f, fp_0, f1024_p_0, f1025_p_0, fp_1, f1024_p_1, fp_2, f1024, f1025, x, xp_0, x1024_p_0, x1025_p_0, xp_1, x1024_p_1, xp_2, x1024, x1025, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y512 = 0;
IND_TYPE x1026 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c769 = 0;
IND_TYPE f1026 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_9216 ,mem_vec_9217 ,mem_vec_9218 ,mem_vec_9219 ,mem_vec_9220 ,mem_vec_9221 ,mem_vec_9222 ,mem_vec_9223 ,mem_vec_9224 ,mem_vec_9225 ,mem_vec_9226 ,mem_vec_9227 ,mem_vec_9228 ,mem_vec_9229 ,mem_vec_9230 ,mem_vec_9231 ,mem_vec_9232 ,mem_vec_9233 ,mem_vec_9234 ,mem_vec_9235 ,mem_vec_9236 ,mem_vec_9237 ,mem_vec_9238 ,mem_vec_9239 ,mem_vec_9240 ,mem_vec_9241 ,mem_vec_9242 ,mem_vec_9243 ,mem_vec_9244 ,mem_vec_9245 ,mem_vec_9246 ,mem_vec_9247 ,mem_vec_9248 ,mem_vec_9249 ,mem_vec_9250 ,mem_vec_9251 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 1) (512 / 512)
for (f1025 = f1026, f1025_p_0 = 0;
	f1025 < f1026 + 512;
	f1025 += 512, f1025_p_0 += 512){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (x, 1) (17 / 17)
	for (x1025 = x1026, x1025_p_0 = 0;
		x1025 < x1026 + 17;
		x1025 += 17, x1025_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 512) (1024 / 2)
		for (c768 = c769, c768_p_0 = 0;
			c768 < c769 + 1024;
			c768 += 2, c768_p_0 += 2){
			// y = 17, x = 17, h = 1, w = 1, c = 2, f = 512
			// T (f, 2) (512 / 256)
			for (f1024 = f1025, f1024_p_1 = f1025_p_0, f1024_p_0 = 0;
				f1024 < f1025 + 512;
				f1024 += 256, f1024_p_1 += 256, f1024_p_0 += 256){
					for (y = y512, yp_0 = 0;
						y < y512 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 256
						// T (x, 17) (17 / 1)
						for (x1024 = x1025, x1024_p_1 = x1025_p_0, x1024_p_0 = 0;
							x1024 < x1025 + 17;
							x1024 += 1, x1024_p_1 += 1, x1024_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1024, fp_2 = f1024_p_1, fp_1 = f1024_p_0, fp_0 = 0;
								f < f1024 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1024, xp_2 = x1024_p_1, xp_1 = x1024_p_0, xp_0 = 0;
									x < x1024 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9216 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9217 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_9218 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9219 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_9220 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9221 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_9222 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9223 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_9224 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9225 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_9226 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9227 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_9228 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9229 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_9230 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9231 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c768, cp_1 = c768_p_0, cp_0 = 0;
												c < c768 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9216);
												mem_vec_9216 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9217);
												mem_vec_9217 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9218);
												mem_vec_9218 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9219);
												mem_vec_9219 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9220);
												mem_vec_9220 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9221);
												mem_vec_9221 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9222);
												mem_vec_9222 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9223);
												mem_vec_9223 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9224);
												mem_vec_9224 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9225);
												mem_vec_9225 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9226);
												mem_vec_9226 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9227);
												mem_vec_9227 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9228);
												mem_vec_9228 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9229);
												mem_vec_9229 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9230);
												mem_vec_9230 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9231);
												mem_vec_9231 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9216);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9217);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9218);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9219);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9220);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9221);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9222);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9223);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9224);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9225);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9226);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9227);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9228);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9229);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9230);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9231);
								}
							}
						}
					}
					for (y = y512 + 12, yp_0 = 0;
						y < y512 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 256
						// T (x, 17) (17 / 1)
						for (x1024 = x1025, x1024_p_1 = x1025_p_0, x1024_p_0 = 0;
							x1024 < x1025 + 17;
							x1024 += 1, x1024_p_1 += 1, x1024_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1024, fp_2 = f1024_p_1, fp_1 = f1024_p_0, fp_0 = 0;
								f < f1024 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1024, xp_2 = x1024_p_1, xp_1 = x1024_p_0, xp_0 = 0;
									x < x1024 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9232 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9233 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_9234 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9235 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_9236 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9237 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_9238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_9240 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9241 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_9242 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9243 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_9244 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9245 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_9246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_9248 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_9249 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_9250 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_9251 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c768, cp_1 = c768_p_0, cp_0 = 0;
												c < c768 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9232);
												mem_vec_9232 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9233);
												mem_vec_9233 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9234);
												mem_vec_9234 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9235);
												mem_vec_9235 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9236);
												mem_vec_9236 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9237);
												mem_vec_9237 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9238);
												mem_vec_9238 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9239);
												mem_vec_9239 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9240);
												mem_vec_9240 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9241);
												mem_vec_9241 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9242);
												mem_vec_9242 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9243);
												mem_vec_9243 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9244);
												mem_vec_9244 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9245);
												mem_vec_9245 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9246);
												mem_vec_9246 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9247);
												mem_vec_9247 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_9248);
												mem_vec_9248 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_9249);
												mem_vec_9249 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_9250);
												mem_vec_9250 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_9251);
												mem_vec_9251 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9232);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9233);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9234);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9235);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9236);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9237);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9238);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9239);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9240);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9241);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9242);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9243);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9244);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9245);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9246);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9247);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9248);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9249);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9250);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_9251);
								}
							}
						}
					}
			}
		}
	}
}


}