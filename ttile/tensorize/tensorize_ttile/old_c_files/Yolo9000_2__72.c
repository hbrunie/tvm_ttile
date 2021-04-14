#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 13), (Arg 14)); ((Iter 6), (Arg 15))]; T (2, f);
  T (2, c); T (2, x); T (17, x)]
*/
IND_TYPE c, cp_0, c1116_p_0, cp_1, c1116, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x1860_p_0, x1861_p_0, x1862_p_0, xp_1, x1860_p_1, x1861_p_1, xp_2, x1860_p_2, xp_3, x1860, x1861, x1862, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y744 = 0;
IND_TYPE x1863 = 0;
IND_TYPE h744 = 0;
IND_TYPE w604 = 0;
IND_TYPE c1117 = 0;
IND_TYPE f604 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9312 ,mem_vec_9313 ,mem_vec_9314 ,mem_vec_9315 ,mem_vec_9316 ,mem_vec_9317 ,mem_vec_9318 ,mem_vec_9319 ,mem_vec_9320 ,mem_vec_9321 ,mem_vec_9322 ,mem_vec_9323 ,mem_vec_9324 ,mem_vec_9325 ,mem_vec_9326 ,mem_vec_9327 ,mem_vec_9328 ,mem_vec_9329 ,mem_vec_9330 ,mem_vec_9331 ,mem_vec_9332 ,mem_vec_9333 ,mem_vec_9334 ,mem_vec_9335 ,mem_vec_9336 ,mem_vec_9337 ,mem_vec_9338 ,mem_vec_9339 ,mem_vec_9340 ,mem_vec_9341 ,mem_vec_9342 ,mem_vec_9343 ,mem_vec_9344 ,mem_vec_9345 ,mem_vec_9346 ,mem_vec_9347 ,mem_vec_9348 ,mem_vec_9349 ,mem_vec_9350 ,mem_vec_9351 ,mem_vec_9352 ,mem_vec_9353 ,mem_vec_9354 ,mem_vec_9355 ,mem_vec_9356 ,mem_vec_9357 ,mem_vec_9358 ,mem_vec_9359 ,mem_vec_9360 ,mem_vec_9361 ,mem_vec_9362 ,mem_vec_9363 ,mem_vec_9364 ,mem_vec_9365 ,mem_vec_9366 ,mem_vec_9367 ,mem_vec_9368 ,mem_vec_9369 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 17) (272 / 16)
for (x1862 = x1863, x1862_p_0 = 0;
	x1862 < x1863 + 272;
	x1862 += 16, x1862_p_0 += 16){
	// y = 272, x = 16, h = 3, w = 3, c = 32, f = 64
	// T (x, 2) (16 / 8)
	for (x1861 = x1862, x1861_p_1 = x1862_p_0, x1861_p_0 = 0;
		x1861 < x1862 + 16;
		x1861 += 8, x1861_p_1 += 8, x1861_p_0 += 8){
		// y = 272, x = 8, h = 3, w = 3, c = 32, f = 64
		// T (c, 2) (32 / 16)
		for (c1116 = c1117, c1116_p_0 = 0;
			c1116 < c1117 + 32;
			c1116 += 16, c1116_p_0 += 16){
			// y = 272, x = 8, h = 3, w = 3, c = 16, f = 64
			// T (f, 2) (64 / 32)
			for (f = f604, fp_0 = 0;
				f < f604 + 64;
				f += 32, fp_0 += 32){
					for (y = y744, yp_0 = 0;
						y < y744 + 182;
						y += 14, yp_0 += 14){
						// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 32
						// T (x, 2) (8 / 4)
						for (x1860 = x1861, x1860_p_2 = x1861_p_1, x1860_p_1 = x1861_p_0, x1860_p_0 = 0;
							x1860 < x1861 + 8;
							x1860 += 4, x1860_p_2 += 4, x1860_p_1 += 4, x1860_p_0 += 4){
							// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h744, hp_0 = 0;
								h < h744 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w604, wp_0 = 0;
									w < w604 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 1, c = 16, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1860, xp_3 = x1860_p_2, xp_2 = x1860_p_1, xp_1 = x1860_p_0, xp_0 = 0;
										x < x1860 + 4;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9312 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9313 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_9325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_9326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_9327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_9328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_9329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_9330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_9331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_9332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_9333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_9334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_9335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_9336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_9337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_9338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_9339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1116, cp_1 = c1116_p_0, cp_0 = 0;
													c < c1116 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9312);
													mem_vec_9312 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9313);
													mem_vec_9313 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9314);
													mem_vec_9314 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9315);
													mem_vec_9315 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9316);
													mem_vec_9316 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9317);
													mem_vec_9317 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9318);
													mem_vec_9318 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9319);
													mem_vec_9319 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9320);
													mem_vec_9320 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9321);
													mem_vec_9321 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9322);
													mem_vec_9322 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9323);
													mem_vec_9323 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9324);
													mem_vec_9324 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9325);
													mem_vec_9325 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9326);
													mem_vec_9326 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9327);
													mem_vec_9327 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9328);
													mem_vec_9328 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9329);
													mem_vec_9329 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9330);
													mem_vec_9330 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9331);
													mem_vec_9331 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9332);
													mem_vec_9332 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9333);
													mem_vec_9333 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9334);
													mem_vec_9334 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9335);
													mem_vec_9335 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_9336);
													mem_vec_9336 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_9337);
													mem_vec_9337 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_9338);
													mem_vec_9338 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_9339);
													mem_vec_9339 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9312);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9313);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9314);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9315);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9316);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9317);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9318);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9319);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9320);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9321);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9322);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9323);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9324);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9325);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9326);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9327);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9328);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9329);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9330);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9331);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9332);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9333);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9334);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9335);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_9336);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_9337);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_9338);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_9339);
									}
								}
							}
						}
					}
					for (y = y744 + 182, yp_0 = 0;
						y < y744 + 182 + 90;
						y += 15, yp_0 += 15){
						// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 32
						// T (x, 2) (8 / 4)
						for (x1860 = x1861, x1860_p_2 = x1861_p_1, x1860_p_1 = x1861_p_0, x1860_p_0 = 0;
							x1860 < x1861 + 8;
							x1860 += 4, x1860_p_2 += 4, x1860_p_1 += 4, x1860_p_0 += 4){
							// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h744, hp_0 = 0;
								h < h744 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w604, wp_0 = 0;
									w < w604 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 1, c = 16, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1860, xp_3 = x1860_p_2, xp_2 = x1860_p_1, xp_1 = x1860_p_0, xp_0 = 0;
										x < x1860 + 4;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9340 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9341 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_9353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_9354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_9355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_9356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_9357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_9358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_9359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_9360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_9361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_9362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_9363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_9364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_9365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_9366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_9367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												mem_vec_9368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
												mem_vec_9369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1116, cp_1 = c1116_p_0, cp_0 = 0;
													c < c1116 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9340);
													mem_vec_9340 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9341);
													mem_vec_9341 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9342);
													mem_vec_9342 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9343);
													mem_vec_9343 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9344);
													mem_vec_9344 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9345);
													mem_vec_9345 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9346);
													mem_vec_9346 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9347);
													mem_vec_9347 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9348);
													mem_vec_9348 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9349);
													mem_vec_9349 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9350);
													mem_vec_9350 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9351);
													mem_vec_9351 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9352);
													mem_vec_9352 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9353);
													mem_vec_9353 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9354);
													mem_vec_9354 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9355);
													mem_vec_9355 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9356);
													mem_vec_9356 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9357);
													mem_vec_9357 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9358);
													mem_vec_9358 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9359);
													mem_vec_9359 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9360);
													mem_vec_9360 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9361);
													mem_vec_9361 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9362);
													mem_vec_9362 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9363);
													mem_vec_9363 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_9364);
													mem_vec_9364 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_9365);
													mem_vec_9365 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_9366);
													mem_vec_9366 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_9367);
													mem_vec_9367 = vec_43;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
													vec_45 = _mm512_set1_ps(scal_14);


													vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_9368);
													mem_vec_9368 = vec_44;



													vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_9369);
													mem_vec_9369 = vec_46;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9340);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9341);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9342);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9343);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9344);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9345);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9346);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9347);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9348);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9349);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9350);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9351);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9352);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9353);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9354);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9355);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9356);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9357);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9358);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9359);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9360);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9361);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9362);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9363);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_9364);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_9365);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_9366);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_9367);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_9368);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_9369);
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