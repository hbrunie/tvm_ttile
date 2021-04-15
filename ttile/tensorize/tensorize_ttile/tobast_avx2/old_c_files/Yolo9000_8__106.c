#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (2, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); T (1, f); T (1, x); T (17, y); T (4, f); T (64, c); T (2, x);
  T (2, f)]
*/
IND_TYPE c, cp_0, c78_p_0, cp_1, c78, f, fp_0, f104_p_0, f105_p_0, fp_1, f104_p_1, fp_2, f104, f105, h, hp_0, w, wp_0, x, xp_0, x104_p_0, x105_p_0, xp_1, x104_p_1, xp_2, x104, x105, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y52 = 0;
IND_TYPE x106 = 0;
IND_TYPE h52 = 0;
IND_TYPE w52 = 0;
IND_TYPE c79 = 0;
IND_TYPE f106 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_416 ,mem_vec_417 ,mem_vec_418 ,mem_vec_419 ,mem_vec_420 ,mem_vec_421 ,mem_vec_422 ,mem_vec_423 ,mem_vec_424 ,mem_vec_425 ,mem_vec_426 ,mem_vec_427 ,mem_vec_428 ,mem_vec_429 ,mem_vec_430 ,mem_vec_431 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f105 = f106, f105_p_0 = 0;
	f105 < f106 + 256;
	f105 += 128, f105_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (x, 2) (68 / 34)
	for (x105 = x106, x105_p_0 = 0;
		x105 < x106 + 68;
		x105 += 34, x105_p_0 += 34){
		// y = 68, x = 34, h = 3, w = 3, c = 128, f = 128
		// T (c, 64) (128 / 2)
		for (c78 = c79, c78_p_0 = 0;
			c78 < c79 + 128;
			c78 += 2, c78_p_0 += 2){
			// y = 68, x = 34, h = 3, w = 3, c = 2, f = 128
			// T (f, 4) (128 / 32)
			for (f104 = f105, f104_p_1 = f105_p_0, f104_p_0 = 0;
				f104 < f105 + 128;
				f104 += 32, f104_p_1 += 32, f104_p_0 += 32){
				// y = 68, x = 34, h = 3, w = 3, c = 2, f = 32
				// T (y, 17) (68 / 4)
				for (y = y52, yp_0 = 0;
					y < y52 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 34, h = 3, w = 3, c = 2, f = 32
					// T (x, 1) (34 / 34)
					for (x104 = x105, x104_p_1 = x105_p_0, x104_p_0 = 0;
						x104 < x105 + 34;
						x104 += 34, x104_p_1 += 34, x104_p_0 += 34){
						// y = 4, x = 34, h = 3, w = 3, c = 2, f = 32
						// T (f, 1) (32 / 32)
						for (f = f104, fp_2 = f104_p_1, fp_1 = f104_p_0, fp_0 = 0;
							f < f104 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = 4, x = 34, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h52, hp_0 = 0;
								h < h52 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 34, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w52, wp_0 = 0;
									w < w52 + 3;
									w += 1, wp_0 += 1){
									// y = 4, x = 34, h = 1, w = 1, c = 2, f = 32
									// T (x, 34) (34 / 1)
									for (x = x104, xp_2 = x104_p_1, xp_1 = x104_p_0, xp_0 = 0;
										x < x104 + 34;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_416 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_417 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_418 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_419 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_420 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_421 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_422 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_423 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_424 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_425 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_426 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_427 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_428 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_429 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_430 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_431 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = 4, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c78, cp_1 = c78_p_0, cp_0 = 0;
													c < c78 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_416);
													mem_vec_416 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_417);
													mem_vec_417 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_418);
													mem_vec_418 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_419);
													mem_vec_419 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_420);
													mem_vec_420 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_421);
													mem_vec_421 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_422);
													mem_vec_422 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_423);
													mem_vec_423 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_424);
													mem_vec_424 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_425);
													mem_vec_425 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_426);
													mem_vec_426 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_427);
													mem_vec_427 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_428);
													mem_vec_428 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_429);
													mem_vec_429 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_430);
													mem_vec_430 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_431);
													mem_vec_431 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_416);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_417);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_418);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_419);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_420);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_421);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_422);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_423);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_424);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_425);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_426);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_427);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_428);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_429);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_430);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_431);
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