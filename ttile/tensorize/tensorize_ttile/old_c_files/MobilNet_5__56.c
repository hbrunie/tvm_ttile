#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (4, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (4, y); T (1, f); T (4, c); T (4, f); T (16, c); T (28, x);
  T (1, f)]
*/
IND_TYPE c, cp_0, c336_p_0, c337_p_0, cp_1, c336_p_1, cp_2, c336, c337, f, fp_0, f324_p_0, f325_p_0, fp_1, f324_p_1, fp_2, f324, f325, h, hp_0, w, wp_0, x, xp_0, x252_p_0, xp_1, x252, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y168 = 0;
IND_TYPE x253 = 0;
IND_TYPE h168 = 0;
IND_TYPE w168 = 0;
IND_TYPE c338 = 0;
IND_TYPE f326 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_2352 ,mem_vec_2353 ,mem_vec_2354 ,mem_vec_2355 ,mem_vec_2356 ,mem_vec_2357 ,mem_vec_2358 ,mem_vec_2359 ,mem_vec_2360 ,mem_vec_2361 ,mem_vec_2362 ,mem_vec_2363 ,mem_vec_2364 ,mem_vec_2365 ,mem_vec_2366 ,mem_vec_2367 ,mem_vec_2368 ,mem_vec_2369 ,mem_vec_2370 ,mem_vec_2371 ,mem_vec_2372 ,mem_vec_2373 ,mem_vec_2374 ,mem_vec_2375 ,mem_vec_2376 ,mem_vec_2377 ,mem_vec_2378 ,mem_vec_2379 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f325 = f326, f325_p_0 = 0;
	f325 < f326 + 256;
	f325 += 256, f325_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (x, 28) (28 / 1)
	for (x252 = x253, x252_p_0 = 0;
		x252 < x253 + 28;
		x252 += 1, x252_p_0 += 1){
		// y = 28, x = 1, h = 3, w = 3, c = 256, f = 256
		// T (c, 16) (256 / 16)
		for (c337 = c338, c337_p_0 = 0;
			c337 < c338 + 256;
			c337 += 16, c337_p_0 += 16){
			// y = 28, x = 1, h = 3, w = 3, c = 16, f = 256
			// T (f, 4) (256 / 64)
			for (f324 = f325, f324_p_1 = f325_p_0, f324_p_0 = 0;
				f324 < f325 + 256;
				f324 += 64, f324_p_1 += 64, f324_p_0 += 64){
				// y = 28, x = 1, h = 3, w = 3, c = 16, f = 64
				// T (c, 4) (16 / 4)
				for (c336 = c337, c336_p_1 = c337_p_0, c336_p_0 = 0;
					c336 < c337 + 16;
					c336 += 4, c336_p_1 += 4, c336_p_0 += 4){
					// y = 28, x = 1, h = 3, w = 3, c = 4, f = 64
					// T (f, 1) (64 / 64)
					for (f = f324, fp_2 = f324_p_1, fp_1 = f324_p_0, fp_0 = 0;
						f < f324 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = 28, x = 1, h = 3, w = 3, c = 4, f = 64
						// T (y, 4) (28 / 7)
						for (y = y168, yp_0 = 0;
							y < y168 + 28;
							y += 7, yp_0 += 7){
							// y = 7, x = 1, h = 3, w = 3, c = 4, f = 64
							// T (h, 3) (3 / 1)
							for (h = h168, hp_0 = 0;
								h < h168 + 3;
								h += 1, hp_0 += 1){
								// y = 7, x = 1, h = 1, w = 3, c = 4, f = 64
								// T (w, 3) (3 / 1)
								for (w = w168, wp_0 = 0;
									w < w168 + 3;
									w += 1, wp_0 += 1){
									// y = 7, x = 1, h = 1, w = 1, c = 4, f = 64
									// T (x, 1) (1 / 1)
									for (x = x252, xp_1 = x252_p_0, xp_0 = 0;
										x < x252 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2352 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2353 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2354 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_2355 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_2356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_2359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_2360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_2363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_2364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_2367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_2368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_2371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												mem_vec_2372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_2373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_2374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
												mem_vec_2375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
												mem_vec_2376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_2377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_2378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
												mem_vec_2379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
												// y = 7, x = 1, h = 1, w = 1, c = 4, f = 64
												// T (c, 4) (4 / 1)
												for (c = c336, cp_2 = c336_p_1, cp_1 = c336_p_0, cp_0 = 0;
													c < c336 + 4;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2352);
													mem_vec_2352 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2353);
													mem_vec_2353 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2354);
													mem_vec_2354 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2355);
													mem_vec_2355 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2356);
													mem_vec_2356 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2357);
													mem_vec_2357 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2358);
													mem_vec_2358 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2359);
													mem_vec_2359 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2360);
													mem_vec_2360 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2361);
													mem_vec_2361 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2362);
													mem_vec_2362 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2363);
													mem_vec_2363 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2364);
													mem_vec_2364 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2365);
													mem_vec_2365 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2366);
													mem_vec_2366 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2367);
													mem_vec_2367 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2368);
													mem_vec_2368 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2369);
													mem_vec_2369 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2370);
													mem_vec_2370 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2371);
													mem_vec_2371 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2372);
													mem_vec_2372 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2373);
													mem_vec_2373 = vec_31;



													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2374);
													mem_vec_2374 = vec_32;



													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2375);
													mem_vec_2375 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm512_set1_ps(scal_6);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_2376);
													mem_vec_2376 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_2377);
													mem_vec_2377 = vec_36;



													vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_2378);
													mem_vec_2378 = vec_37;



													vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_2379);
													mem_vec_2379 = vec_38;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2352);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2353);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2354);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2355);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2356);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2357);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2358);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2359);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2360);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2361);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2362);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2363);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2364);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2365);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2366);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2367);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2368);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2369);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2370);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2371);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2372);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2373);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_2374);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_2375);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2376);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2377);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_2378);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_2379);
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


}