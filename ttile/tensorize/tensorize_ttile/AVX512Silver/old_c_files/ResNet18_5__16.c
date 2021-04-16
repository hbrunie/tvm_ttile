#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (14, x); T (4, c);
  T (2, x); T (7, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c55_p_0, cp_1, c55, f, fp_0, f55_p_0, fp_1, f55, x, xp_0, x66_p_0, xp_1, x66, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y44 = 0;
IND_TYPE x67 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c56 = 0;
IND_TYPE f56 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_400 ,mem_vec_401 ,mem_vec_402 ,mem_vec_403 ,mem_vec_404 ,mem_vec_405 ,mem_vec_406 ,mem_vec_407 ,mem_vec_408 ,mem_vec_409 ,mem_vec_410 ,mem_vec_411 ,mem_vec_412 ,mem_vec_413 ,mem_vec_414 ,mem_vec_415 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f55 = f56, f55_p_0 = 0;
	f55 < f56 + 128;
	f55 += 64, f55_p_0 += 64){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
	// T (f, 1) (64 / 64)
	for (f = f55, fp_1 = f55_p_0, fp_0 = 0;
		f < f55 + 64;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 7) (28 / 4)
		for (y = y44, yp_0 = 0;
			y < y44 + 28;
			y += 4, yp_0 += 4){
			// y = 4, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 2) (28 / 14)
			for (x66 = x67, x66_p_0 = 0;
				x66 < x67 + 28;
				x66 += 14, x66_p_0 += 14){
				// y = 4, x = 14, h = 1, w = 1, c = 64, f = 64
				// T (c, 4) (64 / 16)
				for (c55 = c56, c55_p_0 = 0;
					c55 < c56 + 64;
					c55 += 16, c55_p_0 += 16){
					// y = 4, x = 14, h = 1, w = 1, c = 16, f = 64
					// T (x, 14) (14 / 1)
					for (x = x66, xp_1 = x66_p_0, xp_0 = 0;
						x < x66 + 14;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_400 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_401 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_402 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_403 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 1, c = 16, f = 64
								// T (c, 16) (16 / 1)
								for (c = c55, cp_1 = c55_p_0, cp_0 = 0;
									c < c55 + 16;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_400);
									mem_vec_400 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_401);
									mem_vec_401 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_402);
									mem_vec_402 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_403);
									mem_vec_403 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_404);
									mem_vec_404 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_405);
									mem_vec_405 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_406);
									mem_vec_406 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_407);
									mem_vec_407 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_408);
									mem_vec_408 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_409);
									mem_vec_409 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_410);
									mem_vec_410 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_411);
									mem_vec_411 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_412);
									mem_vec_412 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_413);
									mem_vec_413 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_414);
									mem_vec_414 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_415);
									mem_vec_415 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_400);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_401);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_402);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_403);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_404);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_405);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_406);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_407);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_408);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_409);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_410);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_411);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_412);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_413);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_414);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_415);
					}
				}
			}
		}
	}
}


}