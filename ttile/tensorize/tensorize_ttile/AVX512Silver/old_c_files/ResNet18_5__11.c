#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (7, x); T (2, c);
  T (4, x); T (7, y); T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c64_p_0, cp_1, c64, f, fp_0, f64_p_0, fp_1, f64, x, xp_0, x75_p_0, xp_1, x75, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y50 = 0;
IND_TYPE x76 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c65 = 0;
IND_TYPE f65 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,mem_vec_453 ,mem_vec_454 ,mem_vec_455 ,mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 1) (128 / 128)
for (f64 = f65, f64_p_0 = 0;
	f64 < f65 + 128;
	f64 += 128, f64_p_0 += 128){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
	// T (f, 2) (128 / 64)
	for (f = f64, fp_1 = f64_p_0, fp_0 = 0;
		f < f64 + 128;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 7) (28 / 4)
		for (y = y50, yp_0 = 0;
			y < y50 + 28;
			y += 4, yp_0 += 4){
			// y = 4, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 4) (28 / 7)
			for (x75 = x76, x75_p_0 = 0;
				x75 < x76 + 28;
				x75 += 7, x75_p_0 += 7){
				// y = 4, x = 7, h = 1, w = 1, c = 64, f = 64
				// T (c, 2) (64 / 32)
				for (c64 = c65, c64_p_0 = 0;
					c64 < c65 + 64;
					c64 += 32, c64_p_0 += 32){
					// y = 4, x = 7, h = 1, w = 1, c = 32, f = 64
					// T (x, 7) (7 / 1)
					for (x = x75, xp_1 = x75_p_0, xp_0 = 0;
						x < x75 + 7;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_448 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_449 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_450 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_451 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 1, c = 32, f = 64
								// T (c, 32) (32 / 1)
								for (c = c64, cp_1 = c64_p_0, cp_0 = 0;
									c < c64 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_448);
									mem_vec_448 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_449);
									mem_vec_449 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_450);
									mem_vec_450 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_451);
									mem_vec_451 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_452);
									mem_vec_452 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_453);
									mem_vec_453 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_454);
									mem_vec_454 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_455);
									mem_vec_455 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_456);
									mem_vec_456 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_457);
									mem_vec_457 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_458);
									mem_vec_458 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_459);
									mem_vec_459 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_460);
									mem_vec_460 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_461);
									mem_vec_461 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_462);
									mem_vec_462 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_463);
									mem_vec_463 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_448);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_449);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_450);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_451);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_452);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_453);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_454);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_455);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_456);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_457);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_458);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_459);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_460);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_461);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_462);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_463);
					}
				}
			}
		}
	}
}


}