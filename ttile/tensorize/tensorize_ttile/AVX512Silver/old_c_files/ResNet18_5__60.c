#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (4, x); T (2, c);
  T (7, x); T (7, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c85_p_0, cp_1, c85, f, fp_0, f85_p_0, fp_1, f85, x, xp_0, x96_p_0, xp_1, x96, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y64 = 0;
IND_TYPE x97 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c86 = 0;
IND_TYPE f86 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_560 ,mem_vec_561 ,mem_vec_562 ,mem_vec_563 ,mem_vec_564 ,mem_vec_565 ,mem_vec_566 ,mem_vec_567 ,mem_vec_568 ,mem_vec_569 ,mem_vec_570 ,mem_vec_571 ,mem_vec_572 ,mem_vec_573 ,mem_vec_574 ,mem_vec_575 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f85 = f86, f85_p_0 = 0;
	f85 < f86 + 128;
	f85 += 64, f85_p_0 += 64){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
	// T (f, 1) (64 / 64)
	for (f = f85, fp_1 = f85_p_0, fp_0 = 0;
		f < f85 + 64;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 7) (28 / 4)
		for (y = y64, yp_0 = 0;
			y < y64 + 28;
			y += 4, yp_0 += 4){
			// y = 4, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 7) (28 / 4)
			for (x96 = x97, x96_p_0 = 0;
				x96 < x97 + 28;
				x96 += 4, x96_p_0 += 4){
				// y = 4, x = 4, h = 1, w = 1, c = 64, f = 64
				// T (c, 2) (64 / 32)
				for (c85 = c86, c85_p_0 = 0;
					c85 < c86 + 64;
					c85 += 32, c85_p_0 += 32){
					// y = 4, x = 4, h = 1, w = 1, c = 32, f = 64
					// T (x, 4) (4 / 1)
					for (x = x96, xp_1 = x96_p_0, xp_0 = 0;
						x < x96 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_560 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_561 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_562 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_563 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 1, c = 32, f = 64
								// T (c, 32) (32 / 1)
								for (c = c85, cp_1 = c85_p_0, cp_0 = 0;
									c < c85 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_560);
									mem_vec_560 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_561);
									mem_vec_561 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_562);
									mem_vec_562 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_563);
									mem_vec_563 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_564);
									mem_vec_564 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_565);
									mem_vec_565 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_566);
									mem_vec_566 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_567);
									mem_vec_567 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_568);
									mem_vec_568 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_569);
									mem_vec_569 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_570);
									mem_vec_570 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_571);
									mem_vec_571 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_572);
									mem_vec_572 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_573);
									mem_vec_573 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_574);
									mem_vec_574 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_575);
									mem_vec_575 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_560);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_561);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_562);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_563);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_564);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_565);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_566);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_567);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_568);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_569);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_570);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_571);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_572);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_573);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_574);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_575);
					}
				}
			}
		}
	}
}


}