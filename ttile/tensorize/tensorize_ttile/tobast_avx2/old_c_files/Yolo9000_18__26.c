#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (17, x); T (3, w);
  T (3, h); T (2, f); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (8, f);
  T (128, c); T (2, f)]
*/
IND_TYPE c, cp_0, c42_p_0, cp_1, c42, f, fp_0, f56_p_0, f57_p_0, fp_1, f56_p_1, fp_2, f56, f57, h, hp_0, w, wp_0, x, xp_0, x42_p_0, xp_1, x42, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y28 = 0;
IND_TYPE x43 = 0;
IND_TYPE h28 = 0;
IND_TYPE w28 = 0;
IND_TYPE c43 = 0;
IND_TYPE f58 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_504 ,mem_vec_505 ,mem_vec_506 ,mem_vec_507 ,mem_vec_508 ,mem_vec_509 ,mem_vec_510 ,mem_vec_511 ,mem_vec_512 ,mem_vec_513 ,mem_vec_514 ,mem_vec_515 ,mem_vec_516 ,mem_vec_517 ,mem_vec_518 ,mem_vec_519 ,mem_vec_520 ,mem_vec_521 ,mem_vec_522 ,mem_vec_523 ,mem_vec_524 ,mem_vec_525 ,mem_vec_526 ,mem_vec_527 ,mem_vec_528 ,mem_vec_529 ,mem_vec_530 ,mem_vec_531 ,mem_vec_532 ,mem_vec_533 ,mem_vec_534 ,mem_vec_535 ,mem_vec_536 ,mem_vec_537 ,mem_vec_538 ,mem_vec_539 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
for (f57 = f58, f57_p_0 = 0;
	f57 < f58 + 1024;
	f57 += 512, f57_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
	// T (c, 128) (512 / 4)
	for (c42 = c43, c42_p_0 = 0;
		c42 < c43 + 512;
		c42 += 4, c42_p_0 += 4){
		// y = 17, x = 17, h = 3, w = 3, c = 4, f = 512
		// T (f, 8) (512 / 64)
		for (f56 = f57, f56_p_1 = f57_p_0, f56_p_0 = 0;
			f56 < f57 + 512;
			f56 += 64, f56_p_1 += 64, f56_p_0 += 64){
				for (y = y28, yp_0 = 0;
					y < y28 + 12;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 64
					// T (x, 1) (17 / 17)
					for (x42 = x43, x42_p_0 = 0;
						x42 < x43 + 17;
						x42 += 17, x42_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 64
						// T (f, 2) (64 / 32)
						for (f = f56, fp_2 = f56_p_1, fp_1 = f56_p_0, fp_0 = 0;
							f < f56 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h28, hp_0 = 0;
								h < h28 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w28, wp_0 = 0;
									w < w28 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
									// T (x, 17) (17 / 1)
									for (x = x42, xp_1 = x42_p_0, xp_0 = 0;
										x < x42 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_504 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_505 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_506 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_507 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_508 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_509 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_510 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_511 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_512 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_513 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_514 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_515 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c42, cp_1 = c42_p_0, cp_0 = 0;
													c < c42 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_504);
													mem_vec_504 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_505);
													mem_vec_505 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_506);
													mem_vec_506 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_507);
													mem_vec_507 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_508);
													mem_vec_508 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_509);
													mem_vec_509 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_510);
													mem_vec_510 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_511);
													mem_vec_511 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_512);
													mem_vec_512 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_513);
													mem_vec_513 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_514);
													mem_vec_514 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_515);
													mem_vec_515 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_516);
													mem_vec_516 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_517);
													mem_vec_517 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_518);
													mem_vec_518 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_519);
													mem_vec_519 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_504);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_505);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_506);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_507);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_508);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_509);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_510);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_511);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_512);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_513);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_514);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_515);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_516);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_517);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_518);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_519);
									}
								}
							}
						}
					}
				}
				for (y = y28 + 12, yp_0 = 0;
					y < y28 + 12 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 64
					// T (x, 1) (17 / 17)
					for (x42 = x43, x42_p_0 = 0;
						x42 < x43 + 17;
						x42 += 17, x42_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 64
						// T (f, 2) (64 / 32)
						for (f = f56, fp_2 = f56_p_1, fp_1 = f56_p_0, fp_0 = 0;
							f < f56 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h28, hp_0 = 0;
								h < h28 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w28, wp_0 = 0;
									w < w28 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
									// T (x, 17) (17 / 1)
									for (x = x42, xp_1 = x42_p_0, xp_0 = 0;
										x < x42 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_520 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_521 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_522 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_523 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_528 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_529 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_530 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_531 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_532 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_533 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_534 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_535 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_536 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_537 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_538 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_539 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c42, cp_1 = c42_p_0, cp_0 = 0;
													c < c42 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_520);
													mem_vec_520 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_521);
													mem_vec_521 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_522);
													mem_vec_522 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_523);
													mem_vec_523 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_524);
													mem_vec_524 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_525);
													mem_vec_525 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_526);
													mem_vec_526 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_527);
													mem_vec_527 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_528);
													mem_vec_528 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_529);
													mem_vec_529 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_530);
													mem_vec_530 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_531);
													mem_vec_531 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_532);
													mem_vec_532 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_533);
													mem_vec_533 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_534);
													mem_vec_534 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_535);
													mem_vec_535 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_536);
													mem_vec_536 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_537);
													mem_vec_537 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_538);
													mem_vec_538 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_539);
													mem_vec_539 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_520);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_521);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_522);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_523);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_524);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_525);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_526);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_527);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_528);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_529);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_530);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_531);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_532);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_533);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_534);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_535);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_536);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_537);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_538);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_539);
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