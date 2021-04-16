#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (2, x); T (1, y); T (2, f); T (1, x); T (8, y); T (68, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c234_p_0, cp_1, c234, f, fp_0, x, xp_0, x390_p_0, x391_p_0, x392_p_0, xp_1, x390_p_1, x391_p_1, xp_2, x390_p_2, xp_3, x390, x391, x392, y, yp_0, y312_p_0, y313_p_0, yp_1, y312_p_1, yp_2, y312, y313;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y314 = 0;
IND_TYPE x393 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c235 = 0;
IND_TYPE f156 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_2408 ,mem_vec_2409 ,mem_vec_2410 ,mem_vec_2411 ,mem_vec_2412 ,mem_vec_2413 ,mem_vec_2414 ,mem_vec_2415 ,mem_vec_2416 ,mem_vec_2417 ,mem_vec_2418 ,mem_vec_2419 ,mem_vec_2420 ,mem_vec_2421 ,mem_vec_2422 ,mem_vec_2423 ,mem_vec_2424 ,mem_vec_2425 ,mem_vec_2426 ,mem_vec_2427 ,mem_vec_2428 ,mem_vec_2429 ,mem_vec_2430 ,mem_vec_2431 ,mem_vec_2432 ,mem_vec_2433 ,mem_vec_2434 ,mem_vec_2435 ,mem_vec_2436 ,mem_vec_2437 ,mem_vec_2438 ,mem_vec_2439 ,mem_vec_2440 ,mem_vec_2441 ,mem_vec_2442 ,mem_vec_2443 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y313 = y314, y313_p_0 = 0;
		y313 < y314 + 96;
		y313 += 32, y313_p_0 += 32){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x392 = x393, x392_p_0 = 0;
			x392 < x393 + 136;
			x392 += 2, x392_p_0 += 2){
			// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 8) (8 * ph_y / ph_y)
			for (y312 = y313, y312_p_1 = y313_p_0, y312_p_0 = 0;
				y312 < y313 + 32;
				y312 += 4, y312_p_1 += 4, y312_p_0 += 4){
				// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (2 / 2)
				for (x391 = x392, x391_p_1 = x392_p_0, x391_p_0 = 0;
					x391 < x392 + 2;
					x391 += 2, x391_p_1 += 2, x391_p_0 += 2){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f156, fp_0 = 0;
						f < f156 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 1) (ph_y / ph_y)
						for (y = y312, yp_2 = y312_p_1, yp_1 = y312_p_0, yp_0 = 0;
							y < y312 + 4;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 2) (2 / 1)
							for (x390 = x391, x390_p_2 = x391_p_1, x390_p_1 = x391_p_0, x390_p_0 = 0;
								x390 < x391 + 2;
								x390 += 1, x390_p_2 += 1, x390_p_1 += 1, x390_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 2) (128 / 64)
								for (c234 = c235, c234_p_0 = 0;
									c234 < c235 + 128;
									c234 += 64, c234_p_0 += 64){
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (x, 1) (1 / 1)
									for (x = x390, xp_3 = x390_p_2, xp_2 = x390_p_1, xp_1 = x390_p_0, xp_0 = 0;
										x < x390 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2408 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2409 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_2410 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2411 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_2412 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2413 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_2414 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2415 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_2416 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2417 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_2418 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2419 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_2420 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2421 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_2422 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2423 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c234, cp_1 = c234_p_0, cp_0 = 0;
													c < c234 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2408);
													mem_vec_2408 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2409);
													mem_vec_2409 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2410);
													mem_vec_2410 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2411);
													mem_vec_2411 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2412);
													mem_vec_2412 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2413);
													mem_vec_2413 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2414);
													mem_vec_2414 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2415);
													mem_vec_2415 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2416);
													mem_vec_2416 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2417);
													mem_vec_2417 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2418);
													mem_vec_2418 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2419);
													mem_vec_2419 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2420);
													mem_vec_2420 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2421);
													mem_vec_2421 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2422);
													mem_vec_2422 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2423);
													mem_vec_2423 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2408);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2409);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2410);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2411);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2412);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2413);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2414);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2415);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2416);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2417);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2418);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2419);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2420);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2421);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2422);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2423);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y313 = y314 + 96, y313_p_0 = 0;
		y313 < y314 + 96 + 40;
		y313 += 40, y313_p_0 += 40){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x392 = x393, x392_p_0 = 0;
			x392 < x393 + 136;
			x392 += 2, x392_p_0 += 2){
			// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 8) (8 * ph_y / ph_y)
			for (y312 = y313, y312_p_1 = y313_p_0, y312_p_0 = 0;
				y312 < y313 + 40;
				y312 += 5, y312_p_1 += 5, y312_p_0 += 5){
				// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (2 / 2)
				for (x391 = x392, x391_p_1 = x392_p_0, x391_p_0 = 0;
					x391 < x392 + 2;
					x391 += 2, x391_p_1 += 2, x391_p_0 += 2){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f156, fp_0 = 0;
						f < f156 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 1) (ph_y / ph_y)
						for (y = y312, yp_2 = y312_p_1, yp_1 = y312_p_0, yp_0 = 0;
							y < y312 + 5;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 2) (2 / 1)
							for (x390 = x391, x390_p_2 = x391_p_1, x390_p_1 = x391_p_0, x390_p_0 = 0;
								x390 < x391 + 2;
								x390 += 1, x390_p_2 += 1, x390_p_1 += 1, x390_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 2) (128 / 64)
								for (c234 = c235, c234_p_0 = 0;
									c234 < c235 + 128;
									c234 += 64, c234_p_0 += 64){
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (x, 1) (1 / 1)
									for (x = x390, xp_3 = x390_p_2, xp_2 = x390_p_1, xp_1 = x390_p_0, xp_0 = 0;
										x < x390 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2424 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2425 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_2426 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2427 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_2428 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2429 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_2430 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2431 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_2432 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2433 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_2434 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2435 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_2436 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2437 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_2438 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2439 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_2440 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2441 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_2442 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2443 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c234, cp_1 = c234_p_0, cp_0 = 0;
													c < c234 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2424);
													mem_vec_2424 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2425);
													mem_vec_2425 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2426);
													mem_vec_2426 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2427);
													mem_vec_2427 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2428);
													mem_vec_2428 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2429);
													mem_vec_2429 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2430);
													mem_vec_2430 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2431);
													mem_vec_2431 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2432);
													mem_vec_2432 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2433);
													mem_vec_2433 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2434);
													mem_vec_2434 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2435);
													mem_vec_2435 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2436);
													mem_vec_2436 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2437);
													mem_vec_2437 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2438);
													mem_vec_2438 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2439);
													mem_vec_2439 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2440);
													mem_vec_2440 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2441);
													mem_vec_2441 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2442);
													mem_vec_2442 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2443);
													mem_vec_2443 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2424);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2425);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2426);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2427);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2428);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2429);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2430);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2431);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2432);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2433);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2434);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2435);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2436);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2437);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2438);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2439);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2440);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2441);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2442);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_2443);
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