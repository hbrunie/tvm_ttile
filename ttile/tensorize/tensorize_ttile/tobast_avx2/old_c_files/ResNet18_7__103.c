#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (4, f); T (14, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (2, f);
  T (2, c); T (1, f)]
*/
IND_TYPE c, cp_0, c516_p_0, cp_1, c516, f, fp_0, f688_p_0, f689_p_0, fp_1, f688_p_1, fp_2, f688, f689, h, hp_0, w, wp_0, x, xp_0, x516_p_0, xp_1, x516, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y344 = 0;
IND_TYPE x517 = 0;
IND_TYPE h298 = 0;
IND_TYPE w280 = 0;
IND_TYPE c517 = 0;
IND_TYPE f690 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_5312 ,mem_vec_5313 ,mem_vec_5314 ,mem_vec_5315 ,mem_vec_5316 ,mem_vec_5317 ,mem_vec_5318 ,mem_vec_5319 ,mem_vec_5320 ,mem_vec_5321 ,mem_vec_5322 ,mem_vec_5323 ,mem_vec_5324 ,mem_vec_5325 ,mem_vec_5326 ,mem_vec_5327 ,mem_vec_5328 ,mem_vec_5329 ,mem_vec_5330 ,mem_vec_5331 ,mem_vec_5332 ,mem_vec_5333 ,mem_vec_5334 ,mem_vec_5335 ,mem_vec_5336 ,mem_vec_5337 ,mem_vec_5338 ,mem_vec_5339 ,mem_vec_5340 ,mem_vec_5341 ,mem_vec_5342 ,mem_vec_5343 ,mem_vec_5344 ,mem_vec_5345 ,mem_vec_5346 ,mem_vec_5347 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f689 = f690, f689_p_0 = 0;
	f689 < f690 + 256;
	f689 += 256, f689_p_0 += 256){
	// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
	// T (c, 2) (128 / 64)
	for (c516 = c517, c516_p_0 = 0;
		c516 < c517 + 128;
		c516 += 64, c516_p_0 += 64){
		// y = 14, x = 14, h = 3, w = 3, c = 64, f = 256
		// T (f, 2) (256 / 128)
		for (f688 = f689, f688_p_1 = f689_p_0, f688_p_0 = 0;
			f688 < f689 + 256;
			f688 += 128, f688_p_1 += 128, f688_p_0 += 128){
				for (y = y344, yp_0 = 0;
					y < y344 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 128
					// T (x, 14) (14 / 1)
					for (x516 = x517, x516_p_0 = 0;
						x516 < x517 + 14;
						x516 += 1, x516_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 128
						// T (f, 4) (128 / 32)
						for (f = f688, fp_2 = f688_p_1, fp_1 = f688_p_0, fp_0 = 0;
							f < f688 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h298, hp_0 = 0;
								h < h298 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w280, wp_0 = 0;
									w < w280 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (x, 1) (1 / 1)
									for (x = x516, xp_1 = x516_p_0, xp_0 = 0;
										x < x516 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5312 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5313 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_5314 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5315 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_5316 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5317 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_5318 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5319 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_5320 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5321 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_5322 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5323 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_5324 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5325 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_5326 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5327 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c516, cp_1 = c516_p_0, cp_0 = 0;
													c < c516 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5312);
													mem_vec_5312 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5313);
													mem_vec_5313 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5314);
													mem_vec_5314 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5315);
													mem_vec_5315 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5316);
													mem_vec_5316 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5317);
													mem_vec_5317 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5318);
													mem_vec_5318 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5319);
													mem_vec_5319 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5320);
													mem_vec_5320 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5321);
													mem_vec_5321 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5322);
													mem_vec_5322 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5323);
													mem_vec_5323 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5324);
													mem_vec_5324 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5325);
													mem_vec_5325 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5326);
													mem_vec_5326 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5327);
													mem_vec_5327 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5312);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5313);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5314);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5315);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5316);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5317);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5318);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5319);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5320);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5321);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5322);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5323);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5324);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5325);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5326);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5327);
									}
								}
							}
						}
					}
				}
				for (y = y344 + 4, yp_0 = 0;
					y < y344 + 4 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 128
					// T (x, 14) (14 / 1)
					for (x516 = x517, x516_p_0 = 0;
						x516 < x517 + 14;
						x516 += 1, x516_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 128
						// T (f, 4) (128 / 32)
						for (f = f688, fp_2 = f688_p_1, fp_1 = f688_p_0, fp_0 = 0;
							f < f688 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h298, hp_0 = 0;
								h < h298 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w280, wp_0 = 0;
									w < w280 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (x, 1) (1 / 1)
									for (x = x516, xp_1 = x516_p_0, xp_0 = 0;
										x < x516 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5328 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5329 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_5330 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5331 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_5332 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5333 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_5334 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5335 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_5336 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5337 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_5338 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5339 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_5340 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5341 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_5342 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5343 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_5344 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5345 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_5346 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5347 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c516, cp_1 = c516_p_0, cp_0 = 0;
													c < c516 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5328);
													mem_vec_5328 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5329);
													mem_vec_5329 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5330);
													mem_vec_5330 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5331);
													mem_vec_5331 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5332);
													mem_vec_5332 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5333);
													mem_vec_5333 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5334);
													mem_vec_5334 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5335);
													mem_vec_5335 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5336);
													mem_vec_5336 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5337);
													mem_vec_5337 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5338);
													mem_vec_5338 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5339);
													mem_vec_5339 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5340);
													mem_vec_5340 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5341);
													mem_vec_5341 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5342);
													mem_vec_5342 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5343);
													mem_vec_5343 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5344);
													mem_vec_5344 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5345);
													mem_vec_5345 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5346);
													mem_vec_5346 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5347);
													mem_vec_5347 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5328);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5329);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5330);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5331);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5332);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5333);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5334);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5335);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5336);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5337);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5338);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5339);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5340);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5341);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5342);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5343);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5344);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5345);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5346);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5347);
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