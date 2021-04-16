#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (7, x); T (1, c);
  T (7, w); T (7, h); T (7, y); T (16, x); T (4, y); T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c48_p_0, cp_1, c48, f, fp_0, f48_p_0, fp_1, f48, h, hp_0, w, wp_0, x, xp_0, x48_p_0, xp_1, x48, y, yp_0, y48_p_0, yp_1, y48;

assert((Y == 112));
assert((X == 112));
assert((H == 7));
assert((W == 7));
assert((C == 3));
assert((F == 64));
IND_TYPE y49 = 0;
IND_TYPE x49 = 0;
IND_TYPE h32 = 0;
IND_TYPE w32 = 0;
IND_TYPE c49 = 0;
IND_TYPE f49 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_256 ,mem_vec_257 ,mem_vec_258 ,mem_vec_259 ,mem_vec_260 ,mem_vec_261 ,mem_vec_262 ,mem_vec_263 ,mem_vec_264 ,mem_vec_265 ,mem_vec_266 ,mem_vec_267 ,mem_vec_268 ,mem_vec_269 ,mem_vec_270 ,mem_vec_271 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (f, 1) (64 / 64)
for (f48 = f49, f48_p_0 = 0;
	f48 < f49 + 64;
	f48 += 64, f48_p_0 += 64){
	// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
	// T (f, 2) (64 / 32)
	for (f = f48, fp_1 = f48_p_0, fp_0 = 0;
		f < f48 + 64;
		f += 32, fp_1 += 32, fp_0 += 32){
		// y = 112, x = 112, h = 7, w = 7, c = 3, f = 32
		// T (y, 4) (112 / 28)
		for (y48 = y49, y48_p_0 = 0;
			y48 < y49 + 112;
			y48 += 28, y48_p_0 += 28){
			// y = 28, x = 112, h = 7, w = 7, c = 3, f = 32
			// T (x, 16) (112 / 7)
			for (x48 = x49, x48_p_0 = 0;
				x48 < x49 + 112;
				x48 += 7, x48_p_0 += 7){
				// y = 28, x = 7, h = 7, w = 7, c = 3, f = 32
				// T (y, 7) (28 / 4)
				for (y = y48, yp_1 = y48_p_0, yp_0 = 0;
					y < y48 + 28;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = 4, x = 7, h = 7, w = 7, c = 3, f = 32
					// T (h, 7) (7 / 1)
					for (h = h32, hp_0 = 0;
						h < h32 + 7;
						h += 1, hp_0 += 1){
						// y = 4, x = 7, h = 1, w = 7, c = 3, f = 32
						// T (w, 7) (7 / 1)
						for (w = w32, wp_0 = 0;
							w < w32 + 7;
							w += 1, wp_0 += 1){
							// y = 4, x = 7, h = 1, w = 1, c = 3, f = 32
							// T (c, 1) (3 / 3)
							for (c48 = c49, c48_p_0 = 0;
								c48 < c49 + 3;
								c48 += 3, c48_p_0 += 3){
								// y = 4, x = 7, h = 1, w = 1, c = 3, f = 32
								// T (x, 7) (7 / 1)
								for (x = x48, xp_1 = x48_p_0, xp_0 = 0;
									x < x48 + 7;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_256 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_257 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_258 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_259 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_260 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_261 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_262 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_263 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_264 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_265 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_266 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_267 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_268 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_269 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_270 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_271 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
											// T (c, 3) (3 / 1)
											for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
												c < c48 + 3;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_256);
												mem_vec_256 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_257);
												mem_vec_257 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_258);
												mem_vec_258 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_259);
												mem_vec_259 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_260);
												mem_vec_260 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_261);
												mem_vec_261 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_262);
												mem_vec_262 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_263);
												mem_vec_263 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_264);
												mem_vec_264 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_265);
												mem_vec_265 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_266);
												mem_vec_266 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_267);
												mem_vec_267 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_268);
												mem_vec_268 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_269);
												mem_vec_269 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_270);
												mem_vec_270 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_271);
												mem_vec_271 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_256);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_257);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_258);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_259);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_260);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_261);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_262);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_263);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_264);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_265);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_266);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_267);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_268);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_269);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_270);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_271);
								}
							}
						}
					}
				}
			}
		}
	}
}


}