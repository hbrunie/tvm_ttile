#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (1, x); T (8, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (1024, c); T (17, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1188_p_0, cp_1, c1188, f, fp_0, f1584_p_0, f1585_p_0, fp_1, f1584_p_1, fp_2, f1584, f1585, x, xp_0, x1584_p_0, x1585_p_0, xp_1, x1584_p_1, xp_2, x1584, x1585, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y792 = 0;
IND_TYPE x1586 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1189 = 0;
IND_TYPE f1586 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_14256 ,mem_vec_14257 ,mem_vec_14258 ,mem_vec_14259 ,mem_vec_14260 ,mem_vec_14261 ,mem_vec_14262 ,mem_vec_14263 ,mem_vec_14264 ,mem_vec_14265 ,mem_vec_14266 ,mem_vec_14267 ,mem_vec_14268 ,mem_vec_14269 ,mem_vec_14270 ,mem_vec_14271 ,mem_vec_14272 ,mem_vec_14273 ,mem_vec_14274 ,mem_vec_14275 ,mem_vec_14276 ,mem_vec_14277 ,mem_vec_14278 ,mem_vec_14279 ,mem_vec_14280 ,mem_vec_14281 ,mem_vec_14282 ,mem_vec_14283 ,mem_vec_14284 ,mem_vec_14285 ,mem_vec_14286 ,mem_vec_14287 ,mem_vec_14288 ,mem_vec_14289 ,mem_vec_14290 ,mem_vec_14291 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 2) (512 / 256)
for (f1585 = f1586, f1585_p_0 = 0;
	f1585 < f1586 + 512;
	f1585 += 256, f1585_p_0 += 256){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 256
	// T (x, 17) (17 / 1)
	for (x1585 = x1586, x1585_p_0 = 0;
		x1585 < x1586 + 17;
		x1585 += 1, x1585_p_0 += 1){
		// y = 17, x = 1, h = 1, w = 1, c = 1024, f = 256
		// T (c, 1024) (1024 / 1)
		for (c1188 = c1189, c1188_p_0 = 0;
			c1188 < c1189 + 1024;
			c1188 += 1, c1188_p_0 += 1){
			// y = 17, x = 1, h = 1, w = 1, c = 1, f = 256
			// T (f, 1) (256 / 256)
			for (f1584 = f1585, f1584_p_1 = f1585_p_0, f1584_p_0 = 0;
				f1584 < f1585 + 256;
				f1584 += 256, f1584_p_1 += 256, f1584_p_0 += 256){
					for (y = y792, yp_0 = 0;
						y < y792 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 256
						// T (x, 1) (1 / 1)
						for (x1584 = x1585, x1584_p_1 = x1585_p_0, x1584_p_0 = 0;
							x1584 < x1585 + 1;
							x1584 += 1, x1584_p_1 += 1, x1584_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1584, fp_2 = f1584_p_1, fp_1 = f1584_p_0, fp_0 = 0;
								f < f1584 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1584, xp_2 = x1584_p_1, xp_1 = x1584_p_0, xp_0 = 0;
									x < x1584 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14256 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14257 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_14258 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14259 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_14260 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14261 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_14262 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14263 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_14264 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14265 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_14266 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14267 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_14268 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14269 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_14270 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14271 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c1188, cp_1 = c1188_p_0, cp_0 = 0;
												c < c1188 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14256);
												mem_vec_14256 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14257);
												mem_vec_14257 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14258);
												mem_vec_14258 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14259);
												mem_vec_14259 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14260);
												mem_vec_14260 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14261);
												mem_vec_14261 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14262);
												mem_vec_14262 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14263);
												mem_vec_14263 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14264);
												mem_vec_14264 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14265);
												mem_vec_14265 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14266);
												mem_vec_14266 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14267);
												mem_vec_14267 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14268);
												mem_vec_14268 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14269);
												mem_vec_14269 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14270);
												mem_vec_14270 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14271);
												mem_vec_14271 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14256);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_14257);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14258);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_14259);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14260);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_14261);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14262);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_14263);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14264);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_14265);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14266);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_14267);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14268);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_14269);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14270);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_14271);
								}
							}
						}
					}
					for (y = y792 + 12, yp_0 = 0;
						y < y792 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 256
						// T (x, 1) (1 / 1)
						for (x1584 = x1585, x1584_p_1 = x1585_p_0, x1584_p_0 = 0;
							x1584 < x1585 + 1;
							x1584 += 1, x1584_p_1 += 1, x1584_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1584, fp_2 = f1584_p_1, fp_1 = f1584_p_0, fp_0 = 0;
								f < f1584 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1584, xp_2 = x1584_p_1, xp_1 = x1584_p_0, xp_0 = 0;
									x < x1584 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14272 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14273 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_14274 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14275 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_14276 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14277 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_14278 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14279 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_14280 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14281 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_14282 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14283 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_14284 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14285 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_14286 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14287 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_14288 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_14289 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_14290 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_14291 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c1188, cp_1 = c1188_p_0, cp_0 = 0;
												c < c1188 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14272);
												mem_vec_14272 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14273);
												mem_vec_14273 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14274);
												mem_vec_14274 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14275);
												mem_vec_14275 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14276);
												mem_vec_14276 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14277);
												mem_vec_14277 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14278);
												mem_vec_14278 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14279);
												mem_vec_14279 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14280);
												mem_vec_14280 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14281);
												mem_vec_14281 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14282);
												mem_vec_14282 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14283);
												mem_vec_14283 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14284);
												mem_vec_14284 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14285);
												mem_vec_14285 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14286);
												mem_vec_14286 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14287);
												mem_vec_14287 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_14288);
												mem_vec_14288 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_14289);
												mem_vec_14289 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_14290);
												mem_vec_14290 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_14291);
												mem_vec_14291 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14272);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_14273);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14274);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_14275);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14276);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_14277);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14278);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_14279);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14280);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_14281);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14282);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_14283);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14284);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_14285);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14286);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_14287);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14288);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_14289);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14290);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_14291);
								}
							}
						}
					}
			}
		}
	}
}


}