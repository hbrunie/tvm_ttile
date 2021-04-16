#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (34, x); T (2, y); T (1, f); T (32, c); T (8, f);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (2, f)]
*/
IND_TYPE c, cp_0, c43_p_0, cp_1, c43, f, fp_0, f48_p_0, f49_p_0, fp_1, f48_p_1, fp_2, f48, f49, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y35_p_0, yp_1, y35;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y36 = 0;
IND_TYPE x26 = 0;
IND_TYPE h24 = 0;
IND_TYPE w24 = 0;
IND_TYPE c44 = 0;
IND_TYPE f50 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_532 ,mem_vec_533 ,mem_vec_534 ,mem_vec_535 ,mem_vec_536 ,mem_vec_537 ,mem_vec_538 ,mem_vec_539 ,mem_vec_540 ,mem_vec_541 ,mem_vec_542 ,mem_vec_543 ,mem_vec_544 ,mem_vec_545 ,mem_vec_546 ,mem_vec_547 ,mem_vec_548 ,mem_vec_549 ,mem_vec_550 ,mem_vec_551 ,mem_vec_552 ,mem_vec_553 ,mem_vec_554 ,mem_vec_555 ,mem_vec_556 ,mem_vec_557 ,mem_vec_558 ,mem_vec_559 ,mem_vec_560 ,mem_vec_561 ,mem_vec_562 ,mem_vec_563 ,mem_vec_564 ,mem_vec_565 ,mem_vec_566 ,mem_vec_567 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f49 = f50, f49_p_0 = 0;
	f49 < f50 + 512;
	f49 += 256, f49_p_0 += 256){
		for (y35 = y36, y35_p_0 = 0;
			y35 < y36 + 24;
			y35 += 8, y35_p_0 += 8){
			// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 256
			// T (f, 8) (256 / 32)
			for (f48 = f49, f48_p_1 = f49_p_0, f48_p_0 = 0;
				f48 < f49 + 256;
				f48 += 32, f48_p_1 += 32, f48_p_0 += 32){
				// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
				// T (c, 32) (256 / 8)
				for (c43 = c44, c43_p_0 = 0;
					c43 < c44 + 256;
					c43 += 8, c43_p_0 += 8){
					// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
					// T (f, 1) (32 / 32)
					for (f = f48, fp_2 = f48_p_1, fp_1 = f48_p_0, fp_0 = 0;
						f < f48 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y35, yp_1 = y35_p_0, yp_0 = 0;
							y < y35 + 8;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
							// T (x, 34) (34 / 1)
							for (x = x26, xp_0 = 0;
								x < x26 + 34;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h24, hp_0 = 0;
									h < h24 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (w, 3) (3 / 1)
									for (w = w24, wp_0 = 0;
										w < w24 + 3;
										w += 1, wp_0 += 1){
												mem_vec_532 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_533 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_534 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_535 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_536 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_537 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_538 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_539 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_540 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_541 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_542 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_543 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_544 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_545 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_546 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_547 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c43, cp_1 = c43_p_0, cp_0 = 0;
													c < c43 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_532);
													mem_vec_532 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_533);
													mem_vec_533 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_534);
													mem_vec_534 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_535);
													mem_vec_535 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_536);
													mem_vec_536 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_537);
													mem_vec_537 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_538);
													mem_vec_538 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_539);
													mem_vec_539 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_540);
													mem_vec_540 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_541);
													mem_vec_541 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_542);
													mem_vec_542 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_543);
													mem_vec_543 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_544);
													mem_vec_544 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_545);
													mem_vec_545 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_546);
													mem_vec_546 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_547);
													mem_vec_547 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_532);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_533);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_534);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_535);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_536);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_537);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_538);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_539);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_540);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_541);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_542);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_543);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_544);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_545);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_546);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_547);
									}
								}
							}
						}
					}
				}
			}
		}
		for (y35 = y36 + 24, y35_p_0 = 0;
			y35 < y36 + 24 + 10;
			y35 += 10, y35_p_0 += 10){
			// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 256
			// T (f, 8) (256 / 32)
			for (f48 = f49, f48_p_1 = f49_p_0, f48_p_0 = 0;
				f48 < f49 + 256;
				f48 += 32, f48_p_1 += 32, f48_p_0 += 32){
				// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
				// T (c, 32) (256 / 8)
				for (c43 = c44, c43_p_0 = 0;
					c43 < c44 + 256;
					c43 += 8, c43_p_0 += 8){
					// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
					// T (f, 1) (32 / 32)
					for (f = f48, fp_2 = f48_p_1, fp_1 = f48_p_0, fp_0 = 0;
						f < f48 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y35, yp_1 = y35_p_0, yp_0 = 0;
							y < y35 + 10;
							y += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
							// T (x, 34) (34 / 1)
							for (x = x26, xp_0 = 0;
								x < x26 + 34;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h24, hp_0 = 0;
									h < h24 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (w, 3) (3 / 1)
									for (w = w24, wp_0 = 0;
										w < w24 + 3;
										w += 1, wp_0 += 1){
												mem_vec_548 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_549 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_550 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_551 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_552 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_553 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_554 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_555 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_556 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_557 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_558 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_559 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_560 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_561 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_562 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_563 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_564 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_565 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_566 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_567 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c43, cp_1 = c43_p_0, cp_0 = 0;
													c < c43 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_548);
													mem_vec_548 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_549);
													mem_vec_549 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_550);
													mem_vec_550 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_551);
													mem_vec_551 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_552);
													mem_vec_552 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_553);
													mem_vec_553 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_554);
													mem_vec_554 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_555);
													mem_vec_555 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_556);
													mem_vec_556 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_557);
													mem_vec_557 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_558);
													mem_vec_558 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_559);
													mem_vec_559 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_560);
													mem_vec_560 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_561);
													mem_vec_561 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_562);
													mem_vec_562 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_563);
													mem_vec_563 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_564);
													mem_vec_564 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_565);
													mem_vec_565 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_566);
													mem_vec_566 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_567);
													mem_vec_567 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_548);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_549);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_550);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_551);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_552);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_553);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_554);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_555);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_556);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_557);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_558);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_559);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_560);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_561);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_562);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_563);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_564);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_565);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_566);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_567);
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