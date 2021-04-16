#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (7, x); T (4, c);
  T (4, x); T (7, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c73_p_0, cp_1, c73, f, fp_0, f73_p_0, fp_1, f73, x, xp_0, x84_p_0, xp_1, x84, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y56 = 0;
IND_TYPE x85 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c74 = 0;
IND_TYPE f74 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_496 ,mem_vec_497 ,mem_vec_498 ,mem_vec_499 ,mem_vec_500 ,mem_vec_501 ,mem_vec_502 ,mem_vec_503 ,mem_vec_504 ,mem_vec_505 ,mem_vec_506 ,mem_vec_507 ,mem_vec_508 ,mem_vec_509 ,mem_vec_510 ,mem_vec_511 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f73 = f74, f73_p_0 = 0;
	f73 < f74 + 128;
	f73 += 64, f73_p_0 += 64){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
	// T (f, 1) (64 / 64)
	for (f = f73, fp_1 = f73_p_0, fp_0 = 0;
		f < f73 + 64;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 7) (28 / 4)
		for (y = y56, yp_0 = 0;
			y < y56 + 28;
			y += 4, yp_0 += 4){
			// y = 4, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 4) (28 / 7)
			for (x84 = x85, x84_p_0 = 0;
				x84 < x85 + 28;
				x84 += 7, x84_p_0 += 7){
				// y = 4, x = 7, h = 1, w = 1, c = 64, f = 64
				// T (c, 4) (64 / 16)
				for (c73 = c74, c73_p_0 = 0;
					c73 < c74 + 64;
					c73 += 16, c73_p_0 += 16){
					// y = 4, x = 7, h = 1, w = 1, c = 16, f = 64
					// T (x, 7) (7 / 1)
					for (x = x84, xp_1 = x84_p_0, xp_0 = 0;
						x < x84 + 7;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_496 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_497 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_498 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_499 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 1, c = 16, f = 64
								// T (c, 16) (16 / 1)
								for (c = c73, cp_1 = c73_p_0, cp_0 = 0;
									c < c73 + 16;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_496);
									mem_vec_496 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_497);
									mem_vec_497 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_498);
									mem_vec_498 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_499);
									mem_vec_499 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_500);
									mem_vec_500 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_501);
									mem_vec_501 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_502);
									mem_vec_502 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_503);
									mem_vec_503 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_504);
									mem_vec_504 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_505);
									mem_vec_505 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_506);
									mem_vec_506 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_507);
									mem_vec_507 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_508);
									mem_vec_508 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_509);
									mem_vec_509 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_510);
									mem_vec_510 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_511);
									mem_vec_511 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_496);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_497);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_498);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_499);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_500);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_501);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_502);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_503);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_504);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_505);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_506);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_507);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_508);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_509);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_510);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_511);
					}
				}
			}
		}
	}
}


}