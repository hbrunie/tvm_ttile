#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (17, x); T (3, w);
  T (3, h); T (1, f); T (1, x);
  Lambda_apply y [((Iter 4), (Arg 3)); ((Iter 1), (Arg 5))]; T (8, f);
  T (4, c); T (2, f)]
*/
IND_TYPE c, cp_0, c36_p_0, cp_1, c36, f, fp_0, f48_p_0, f49_p_0, fp_1, f48_p_1, fp_2, f48, f49, h, hp_0, w, wp_0, x, xp_0, x36_p_0, xp_1, x36, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y24 = 0;
IND_TYPE x37 = 0;
IND_TYPE h24 = 0;
IND_TYPE w24 = 0;
IND_TYPE c37 = 0;
IND_TYPE f50 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_396 ,mem_vec_397 ,mem_vec_398 ,mem_vec_399 ,mem_vec_400 ,mem_vec_401 ,mem_vec_402 ,mem_vec_403 ,mem_vec_404 ,mem_vec_405 ,mem_vec_406 ,mem_vec_407 ,mem_vec_408 ,mem_vec_409 ,mem_vec_410 ,mem_vec_411 ,mem_vec_412 ,mem_vec_413 ,mem_vec_414 ,mem_vec_415 ,mem_vec_416 ,mem_vec_417 ,mem_vec_418 ,mem_vec_419 ,mem_vec_420 ,mem_vec_421 ,mem_vec_422 ,mem_vec_423 ,mem_vec_424 ,mem_vec_425 ,mem_vec_426 ,mem_vec_427 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
for (f49 = f50, f49_p_0 = 0;
	f49 < f50 + 1024;
	f49 += 512, f49_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
	// T (c, 4) (512 / 128)
	for (c36 = c37, c36_p_0 = 0;
		c36 < c37 + 512;
		c36 += 128, c36_p_0 += 128){
		// y = 17, x = 17, h = 3, w = 3, c = 128, f = 512
		// T (f, 8) (512 / 64)
		for (f48 = f49, f48_p_1 = f49_p_0, f48_p_0 = 0;
			f48 < f49 + 512;
			f48 += 64, f48_p_1 += 64, f48_p_0 += 64){
				for (y = y24, yp_0 = 0;
					y < y24 + 12;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
					// T (x, 1) (17 / 17)
					for (x36 = x37, x36_p_0 = 0;
						x36 < x37 + 17;
						x36 += 17, x36_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
						// T (f, 1) (64 / 64)
						for (f = f48, fp_2 = f48_p_1, fp_1 = f48_p_0, fp_0 = 0;
							f < f48 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
							// T (h, 3) (3 / 1)
							for (h = h24, hp_0 = 0;
								h < h24 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 128, f = 64
								// T (w, 3) (3 / 1)
								for (w = w24, wp_0 = 0;
									w < w24 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
									// T (x, 17) (17 / 1)
									for (x = x36, xp_1 = x36_p_0, xp_0 = 0;
										x < x36 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_396 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_397 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_398 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_399 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
												// T (c, 128) (128 / 1)
												for (c = c36, cp_1 = c36_p_0, cp_0 = 0;
													c < c36 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_396);
													mem_vec_396 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_397);
													mem_vec_397 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_398);
													mem_vec_398 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_399);
													mem_vec_399 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_400);
													mem_vec_400 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_401);
													mem_vec_401 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_402);
													mem_vec_402 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_403);
													mem_vec_403 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_404);
													mem_vec_404 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_405);
													mem_vec_405 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_406);
													mem_vec_406 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_407);
													mem_vec_407 = vec_18;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_396);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_397);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_398);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_399);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_400);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_401);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_402);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_403);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_404);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_405);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_406);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_407);
									}
								}
							}
						}
					}
				}
				for (y = y24 + 12, yp_0 = 0;
					y < y24 + 12 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
					// T (x, 1) (17 / 17)
					for (x36 = x37, x36_p_0 = 0;
						x36 < x37 + 17;
						x36 += 17, x36_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
						// T (f, 1) (64 / 64)
						for (f = f48, fp_2 = f48_p_1, fp_1 = f48_p_0, fp_0 = 0;
							f < f48 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
							// T (h, 3) (3 / 1)
							for (h = h24, hp_0 = 0;
								h < h24 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 128, f = 64
								// T (w, 3) (3 / 1)
								for (w = w24, wp_0 = 0;
									w < w24 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
									// T (x, 17) (17 / 1)
									for (x = x36, xp_1 = x36_p_0, xp_0 = 0;
										x < x36 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_408 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_409 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_410 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_411 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
												// T (c, 128) (128 / 1)
												for (c = c36, cp_1 = c36_p_0, cp_0 = 0;
													c < c36 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_408);
													mem_vec_408 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_409);
													mem_vec_409 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_410);
													mem_vec_410 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_411);
													mem_vec_411 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_412);
													mem_vec_412 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_413);
													mem_vec_413 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_414);
													mem_vec_414 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_415);
													mem_vec_415 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_416);
													mem_vec_416 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_417);
													mem_vec_417 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_418);
													mem_vec_418 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_419);
													mem_vec_419 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_420);
													mem_vec_420 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_421);
													mem_vec_421 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_422);
													mem_vec_422 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_423);
													mem_vec_423 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_424);
													mem_vec_424 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_425);
													mem_vec_425 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_426);
													mem_vec_426 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_427);
													mem_vec_427 = vec_28;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_408);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_409);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_410);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_411);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_412);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_413);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_414);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_415);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_416);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_417);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_418);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_419);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_420);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_421);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_422);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_423);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_424);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_425);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_426);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_427);
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