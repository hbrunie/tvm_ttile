#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 12)); ((Iter 4), (Arg 14))];
  T (1, f); T (4, c); T (1, f); T (2, x); T (8, f)]
*/
IND_TYPE c, cp_0, c888_p_0, cp_1, c888, f, fp_0, f1184_p_0, f1185_p_0, fp_1, f1184_p_1, fp_2, f1184, f1185, h, hp_0, w, wp_0, x, xp_0, x940_p_0, xp_1, x940, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y592 = 0;
IND_TYPE x941 = 0;
IND_TYPE h592 = 0;
IND_TYPE w540 = 0;
IND_TYPE c889 = 0;
IND_TYPE f1186 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11316 ,mem_vec_11317 ,mem_vec_11318 ,mem_vec_11319 ,mem_vec_11320 ,mem_vec_11321 ,mem_vec_11322 ,mem_vec_11323 ,mem_vec_11324 ,mem_vec_11325 ,mem_vec_11326 ,mem_vec_11327 ,mem_vec_11328 ,mem_vec_11329 ,mem_vec_11330 ,mem_vec_11331 ,mem_vec_11332 ,mem_vec_11333 ,mem_vec_11334 ,mem_vec_11335 ,mem_vec_11336 ,mem_vec_11337 ,mem_vec_11338 ,mem_vec_11339 ,mem_vec_11340 ,mem_vec_11341 ,mem_vec_11342 ,mem_vec_11343 ,mem_vec_11344 ,mem_vec_11345 ,mem_vec_11346 ,mem_vec_11347 ,mem_vec_11348 ,mem_vec_11349 ,mem_vec_11350 ,mem_vec_11351 ,mem_vec_11352 ,mem_vec_11353 ,mem_vec_11354 ,mem_vec_11355 ,mem_vec_11356 ,mem_vec_11357 ,mem_vec_11358 ,mem_vec_11359 ,mem_vec_11360 ,mem_vec_11361 ,mem_vec_11362 ,mem_vec_11363 ,mem_vec_11364 ,mem_vec_11365 ,mem_vec_11366 ,mem_vec_11367 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
for (f1185 = f1186, f1185_p_0 = 0;
	f1185 < f1186 + 256;
	f1185 += 32, f1185_p_0 += 32){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
	// T (x, 2) (68 / 34)
	for (x940 = x941, x940_p_0 = 0;
		x940 < x941 + 68;
		x940 += 34, x940_p_0 += 34){
		// y = 68, x = 34, h = 3, w = 3, c = 128, f = 32
		// T (f, 1) (32 / 32)
		for (f1184 = f1185, f1184_p_1 = f1185_p_0, f1184_p_0 = 0;
			f1184 < f1185 + 32;
			f1184 += 32, f1184_p_1 += 32, f1184_p_0 += 32){
			// y = 68, x = 34, h = 3, w = 3, c = 128, f = 32
			// T (c, 4) (128 / 32)
			for (c888 = c889, c888_p_0 = 0;
				c888 < c889 + 128;
				c888 += 32, c888_p_0 += 32){
				// y = 68, x = 34, h = 3, w = 3, c = 32, f = 32
				// T (f, 1) (32 / 32)
				for (f = f1184, fp_2 = f1184_p_1, fp_1 = f1184_p_0, fp_0 = 0;
					f < f1184 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y592, yp_0 = 0;
							y < y592 + 12;
							y += 12, yp_0 += 12){
							// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h592, hp_0 = 0;
								h < h592 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w540, wp_0 = 0;
									w < w540 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 32, f = 32
									// T (x, 34) (34 / 1)
									for (x = x940, xp_1 = x940_p_0, xp_0 = 0;
										x < x940 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11316 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11317 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_11329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_11330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_11331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_11332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_11333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_11334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_11335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_11336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_11337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_11338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_11339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c888, cp_1 = c888_p_0, cp_0 = 0;
													c < c888 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11316);
													mem_vec_11316 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11317);
													mem_vec_11317 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11318);
													mem_vec_11318 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11319);
													mem_vec_11319 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11320);
													mem_vec_11320 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11321);
													mem_vec_11321 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11322);
													mem_vec_11322 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11323);
													mem_vec_11323 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11324);
													mem_vec_11324 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11325);
													mem_vec_11325 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11326);
													mem_vec_11326 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11327);
													mem_vec_11327 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11328);
													mem_vec_11328 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11329);
													mem_vec_11329 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11330);
													mem_vec_11330 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11331);
													mem_vec_11331 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11332);
													mem_vec_11332 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11333);
													mem_vec_11333 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11334);
													mem_vec_11334 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11335);
													mem_vec_11335 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11336);
													mem_vec_11336 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11337);
													mem_vec_11337 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_11338);
													mem_vec_11338 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_11339);
													mem_vec_11339 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11316);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11317);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11318);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11319);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11320);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11321);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11322);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11323);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11324);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11325);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11326);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11327);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11328);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11329);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11330);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11331);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11332);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11333);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11334);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11335);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11336);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_11337);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_11338);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_11339);
									}
								}
							}
						}
						for (y = y592 + 12, yp_0 = 0;
							y < y592 + 12 + 56;
							y += 14, yp_0 += 14){
							// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h592, hp_0 = 0;
								h < h592 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w540, wp_0 = 0;
									w < w540 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 32, f = 32
									// T (x, 34) (34 / 1)
									for (x = x940, xp_1 = x940_p_0, xp_0 = 0;
										x < x940 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11340 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11341 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_11353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_11354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_11355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_11356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_11357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_11358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_11359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_11360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_11361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_11362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_11363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_11364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_11365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_11366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_11367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c888, cp_1 = c888_p_0, cp_0 = 0;
													c < c888 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11340);
													mem_vec_11340 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11341);
													mem_vec_11341 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11342);
													mem_vec_11342 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11343);
													mem_vec_11343 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11344);
													mem_vec_11344 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11345);
													mem_vec_11345 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11346);
													mem_vec_11346 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11347);
													mem_vec_11347 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11348);
													mem_vec_11348 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11349);
													mem_vec_11349 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11350);
													mem_vec_11350 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11351);
													mem_vec_11351 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11352);
													mem_vec_11352 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11353);
													mem_vec_11353 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11354);
													mem_vec_11354 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11355);
													mem_vec_11355 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11356);
													mem_vec_11356 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11357);
													mem_vec_11357 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11358);
													mem_vec_11358 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11359);
													mem_vec_11359 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11360);
													mem_vec_11360 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11361);
													mem_vec_11361 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_11362);
													mem_vec_11362 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_11363);
													mem_vec_11363 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_11364);
													mem_vec_11364 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_11365);
													mem_vec_11365 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_11366);
													mem_vec_11366 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_11367);
													mem_vec_11367 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11340);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11341);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11342);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11343);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11344);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11345);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11346);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11347);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11348);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11349);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11350);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11351);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11352);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11353);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11354);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11355);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11356);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11357);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11358);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11359);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11360);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_11361);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_11362);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_11363);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_11364);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_11365);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_11366);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_11367);
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