#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (8, f); T (34, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 1), (Arg 14))]; T (1, f);
  T (64, c); T (2, f)]
*/
IND_TYPE c, cp_0, c372_p_0, cp_1, c372, f, fp_0, f496_p_0, f497_p_0, fp_1, f496_p_1, fp_2, f496, f497, h, hp_0, w, wp_0, x, xp_0, x372_p_0, xp_1, x372, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y248 = 0;
IND_TYPE x373 = 0;
IND_TYPE h248 = 0;
IND_TYPE w248 = 0;
IND_TYPE c373 = 0;
IND_TYPE f498 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5312 ,mem_vec_5313 ,mem_vec_5314 ,mem_vec_5315 ,mem_vec_5316 ,mem_vec_5317 ,mem_vec_5318 ,mem_vec_5319 ,mem_vec_5320 ,mem_vec_5321 ,mem_vec_5322 ,mem_vec_5323 ,mem_vec_5324 ,mem_vec_5325 ,mem_vec_5326 ,mem_vec_5327 ,mem_vec_5328 ,mem_vec_5329 ,mem_vec_5330 ,mem_vec_5331 ,mem_vec_5332 ,mem_vec_5333 ,mem_vec_5334 ,mem_vec_5335 ,mem_vec_5336 ,mem_vec_5337 ,mem_vec_5338 ,mem_vec_5339 ,mem_vec_5340 ,mem_vec_5341 ,mem_vec_5342 ,mem_vec_5343 ,mem_vec_5344 ,mem_vec_5345 ,mem_vec_5346 ,mem_vec_5347 ,mem_vec_5348 ,mem_vec_5349 ,mem_vec_5350 ,mem_vec_5351 ,mem_vec_5352 ,mem_vec_5353 ,mem_vec_5354 ,mem_vec_5355 ,mem_vec_5356 ,mem_vec_5357 ,mem_vec_5358 ,mem_vec_5359 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f497 = f498, f497_p_0 = 0;
	f497 < f498 + 512;
	f497 += 256, f497_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (c, 64) (256 / 4)
	for (c372 = c373, c372_p_0 = 0;
		c372 < c373 + 256;
		c372 += 4, c372_p_0 += 4){
		// y = 34, x = 34, h = 3, w = 3, c = 4, f = 256
		// T (f, 1) (256 / 256)
		for (f496 = f497, f496_p_1 = f497_p_0, f496_p_0 = 0;
			f496 < f497 + 256;
			f496 += 256, f496_p_1 += 256, f496_p_0 += 256){
				for (y = y248, yp_0 = 0;
					y < y248 + 20;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 256
					// T (x, 34) (34 / 1)
					for (x372 = x373, x372_p_0 = 0;
						x372 < x373 + 34;
						x372 += 1, x372_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 256
						// T (f, 8) (256 / 32)
						for (f = f496, fp_2 = f496_p_1, fp_1 = f496_p_0, fp_0 = 0;
							f < f496 + 256;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h248, hp_0 = 0;
								h < h248 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w248, wp_0 = 0;
									w < w248 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (x, 1) (1 / 1)
									for (x = x372, xp_1 = x372_p_0, xp_0 = 0;
										x < x372 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5312 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5313 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_5323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_5324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_5325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_5326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_5327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_5328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_5329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_5330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_5331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c372, cp_1 = c372_p_0, cp_0 = 0;
													c < c372 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5312);
													mem_vec_5312 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5313);
													mem_vec_5313 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5314);
													mem_vec_5314 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5315);
													mem_vec_5315 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5316);
													mem_vec_5316 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5317);
													mem_vec_5317 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5318);
													mem_vec_5318 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5319);
													mem_vec_5319 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5320);
													mem_vec_5320 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5321);
													mem_vec_5321 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5322);
													mem_vec_5322 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5323);
													mem_vec_5323 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5324);
													mem_vec_5324 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5325);
													mem_vec_5325 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5326);
													mem_vec_5326 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5327);
													mem_vec_5327 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5328);
													mem_vec_5328 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5329);
													mem_vec_5329 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5330);
													mem_vec_5330 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5331);
													mem_vec_5331 = vec_31;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5312);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5313);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5314);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5315);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5316);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5317);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5318);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5319);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5320);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5321);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5322);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5323);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5324);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5325);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5326);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5327);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5328);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5329);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5330);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5331);
									}
								}
							}
						}
					}
				}
				for (y = y248 + 20, yp_0 = 0;
					y < y248 + 20 + 14;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 256
					// T (x, 34) (34 / 1)
					for (x372 = x373, x372_p_0 = 0;
						x372 < x373 + 34;
						x372 += 1, x372_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 256
						// T (f, 8) (256 / 32)
						for (f = f496, fp_2 = f496_p_1, fp_1 = f496_p_0, fp_0 = 0;
							f < f496 + 256;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h248, hp_0 = 0;
								h < h248 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w248, wp_0 = 0;
									w < w248 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (x, 1) (1 / 1)
									for (x = x372, xp_1 = x372_p_0, xp_0 = 0;
										x < x372 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5332 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5333 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_5343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_5344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_5345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_5346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_5347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_5348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_5349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_5350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_5351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_5352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_5353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_5354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_5355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_5356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_5357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_5358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_5359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c372, cp_1 = c372_p_0, cp_0 = 0;
													c < c372 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5332);
													mem_vec_5332 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5333);
													mem_vec_5333 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5334);
													mem_vec_5334 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5335);
													mem_vec_5335 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5336);
													mem_vec_5336 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5337);
													mem_vec_5337 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5338);
													mem_vec_5338 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5339);
													mem_vec_5339 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5340);
													mem_vec_5340 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5341);
													mem_vec_5341 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5342);
													mem_vec_5342 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5343);
													mem_vec_5343 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5344);
													mem_vec_5344 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5345);
													mem_vec_5345 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5346);
													mem_vec_5346 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5347);
													mem_vec_5347 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5348);
													mem_vec_5348 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5349);
													mem_vec_5349 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5350);
													mem_vec_5350 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5351);
													mem_vec_5351 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5352);
													mem_vec_5352 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5353);
													mem_vec_5353 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_5354);
													mem_vec_5354 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_5355);
													mem_vec_5355 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_5356);
													mem_vec_5356 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_5357);
													mem_vec_5357 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_5358);
													mem_vec_5358 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_5359);
													mem_vec_5359 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5332);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5333);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5334);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5335);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5336);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5337);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5338);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5339);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5340);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5341);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5342);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5343);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5344);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5345);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5346);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5347);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5348);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5349);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5350);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5351);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5352);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_5353);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_5354);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_5355);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_5356);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_5357);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_5358);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_5359);
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