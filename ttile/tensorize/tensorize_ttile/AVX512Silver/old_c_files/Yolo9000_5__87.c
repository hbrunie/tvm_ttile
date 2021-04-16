#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (128, c); Hoist_vars [c]; T (1, x); T (2, y);
  T (1, c); T (136, x); T (17, y)]
*/
IND_TYPE c, cp_0, c360_p_0, cp_1, c360, x, xp_0, x474_p_0, xp_1, x474, y, yp_0, y474_p_0, yp_1, y474;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y475 = 0;
IND_TYPE x475 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c361 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_6338 ,mem_vec_6339 ,mem_vec_6340 ,mem_vec_6341 ,mem_vec_6342 ,mem_vec_6343 ,mem_vec_6344 ,mem_vec_6345 ,mem_vec_6346 ,mem_vec_6347 ,mem_vec_6348 ,mem_vec_6349 ,mem_vec_6350 ,mem_vec_6351 ,mem_vec_6352 ,mem_vec_6353 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 17) (136 / 8)
for (y474 = y475, y474_p_0 = 0;
	y474 < y475 + 136;
	y474 += 8, y474_p_0 += 8){
	// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 136) (136 / 1)
	for (x474 = x475, x474_p_0 = 0;
		x474 < x475 + 136;
		x474 += 1, x474_p_0 += 1){
		// y = 8, x = 1, h = 1, w = 1, c = 128, f = 64
		// T (c, 1) (128 / 128)
		for (c360 = c361, c360_p_0 = 0;
			c360 < c361 + 128;
			c360 += 128, c360_p_0 += 128){
			// y = 8, x = 1, h = 1, w = 1, c = 128, f = 64
			// T (y, 2) (8 / 4)
			for (y = y474, yp_1 = y474_p_0, yp_0 = 0;
				y < y474 + 8;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (1 / 1)
				for (x = x474, xp_1 = x474_p_0, xp_0 = 0;
					x < x474 + 1;
					x += 1, xp_1 += 1, xp_0 += 1){
							mem_vec_6338 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_6339 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_6340 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
							mem_vec_6341 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
							mem_vec_6342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_6343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_6344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
							mem_vec_6345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
							mem_vec_6346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_6347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_6348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
							mem_vec_6349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
							mem_vec_6350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_6351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_6352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
							mem_vec_6353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 64
							// T (c, 128) (128 / 1)
							for (c = c360, cp_1 = c360_p_0, cp_0 = 0;
								c < c360 + 128;
								c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6338);
								mem_vec_6338 = vec_0;

								vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6339);
								mem_vec_6339 = vec_3;

								vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

								vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6340);
								mem_vec_6340 = vec_5;

								vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

								vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6341);
								mem_vec_6341 = vec_7;
								scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
								vec_10 = _mm512_set1_ps(scal_1);


								vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6342);
								mem_vec_6342 = vec_9;



								vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6343);
								mem_vec_6343 = vec_11;



								vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6344);
								mem_vec_6344 = vec_12;



								vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6345);
								mem_vec_6345 = vec_13;
								scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
								vec_15 = _mm512_set1_ps(scal_2);


								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6346);
								mem_vec_6346 = vec_14;



								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6347);
								mem_vec_6347 = vec_16;



								vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6348);
								mem_vec_6348 = vec_17;



								vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6349);
								mem_vec_6349 = vec_18;
								scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
								vec_20 = _mm512_set1_ps(scal_3);


								vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6350);
								mem_vec_6350 = vec_19;



								vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6351);
								mem_vec_6351 = vec_21;



								vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6352);
								mem_vec_6352 = vec_22;



								vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6353);
								mem_vec_6353 = vec_23;
							}
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6338);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6339);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6340);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6341);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6342);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6343);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6344);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6345);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6346);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6347);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6348);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6349);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6350);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6351);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6352);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6353);
				}
			}
		}
	}
}


}