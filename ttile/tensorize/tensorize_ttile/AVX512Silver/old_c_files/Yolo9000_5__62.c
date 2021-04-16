#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (1, x); T (2, y);
  T (2, c); T (136, x); T (17, y)]
*/
IND_TYPE c, cp_0, c363_p_0, cp_1, c363, x, xp_0, x477_p_0, xp_1, x477, y, yp_0, y477_p_0, yp_1, y477;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y478 = 0;
IND_TYPE x478 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c364 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_6354 ,mem_vec_6355 ,mem_vec_6356 ,mem_vec_6357 ,mem_vec_6358 ,mem_vec_6359 ,mem_vec_6360 ,mem_vec_6361 ,mem_vec_6362 ,mem_vec_6363 ,mem_vec_6364 ,mem_vec_6365 ,mem_vec_6366 ,mem_vec_6367 ,mem_vec_6368 ,mem_vec_6369 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 17) (136 / 8)
for (y477 = y478, y477_p_0 = 0;
	y477 < y478 + 136;
	y477 += 8, y477_p_0 += 8){
	// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 136) (136 / 1)
	for (x477 = x478, x477_p_0 = 0;
		x477 < x478 + 136;
		x477 += 1, x477_p_0 += 1){
		// y = 8, x = 1, h = 1, w = 1, c = 128, f = 64
		// T (c, 2) (128 / 64)
		for (c363 = c364, c363_p_0 = 0;
			c363 < c364 + 128;
			c363 += 64, c363_p_0 += 64){
			// y = 8, x = 1, h = 1, w = 1, c = 64, f = 64
			// T (y, 2) (8 / 4)
			for (y = y477, yp_1 = y477_p_0, yp_0 = 0;
				y < y477 + 8;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (x, 1) (1 / 1)
				for (x = x477, xp_1 = x477_p_0, xp_0 = 0;
					x < x477 + 1;
					x += 1, xp_1 += 1, xp_0 += 1){
							mem_vec_6354 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_6355 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_6356 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
							mem_vec_6357 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
							mem_vec_6358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_6359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_6360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
							mem_vec_6361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
							mem_vec_6362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_6363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_6364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
							mem_vec_6365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
							mem_vec_6366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_6367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_6368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
							mem_vec_6369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
							// y = 4, x = 1, h = 1, w = 1, c = 64, f = 64
							// T (c, 64) (64 / 1)
							for (c = c363, cp_1 = c363_p_0, cp_0 = 0;
								c < c363 + 64;
								c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6354);
								mem_vec_6354 = vec_0;

								vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6355);
								mem_vec_6355 = vec_3;

								vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

								vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6356);
								mem_vec_6356 = vec_5;

								vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

								vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6357);
								mem_vec_6357 = vec_7;
								scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
								vec_10 = _mm512_set1_ps(scal_1);


								vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6358);
								mem_vec_6358 = vec_9;



								vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6359);
								mem_vec_6359 = vec_11;



								vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6360);
								mem_vec_6360 = vec_12;



								vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6361);
								mem_vec_6361 = vec_13;
								scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
								vec_15 = _mm512_set1_ps(scal_2);


								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6362);
								mem_vec_6362 = vec_14;



								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6363);
								mem_vec_6363 = vec_16;



								vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6364);
								mem_vec_6364 = vec_17;



								vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6365);
								mem_vec_6365 = vec_18;
								scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
								vec_20 = _mm512_set1_ps(scal_3);


								vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6366);
								mem_vec_6366 = vec_19;



								vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6367);
								mem_vec_6367 = vec_21;



								vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6368);
								mem_vec_6368 = vec_22;



								vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6369);
								mem_vec_6369 = vec_23;
							}
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6354);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6355);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6356);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6357);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6358);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6359);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6360);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6361);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6362);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6363);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6364);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6365);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6366);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6367);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6368);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6369);
				}
			}
		}
	}
}


}