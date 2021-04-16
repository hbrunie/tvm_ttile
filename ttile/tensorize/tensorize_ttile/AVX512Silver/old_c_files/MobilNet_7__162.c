#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (14, x); T (1, c); T (2, y); T (16, f); T (16, c)]
*/
IND_TYPE c, cp_0, c93_p_0, c94_p_0, cp_1, c93_p_1, cp_2, c93, c94, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y50 = 0;
IND_TYPE x50 = 0;
IND_TYPE h38 = 0;
IND_TYPE w37 = 0;
IND_TYPE c95 = 0;
IND_TYPE f57 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_553 ,mem_vec_554 ,mem_vec_555 ,mem_vec_556 ,mem_vec_557 ,mem_vec_558 ,mem_vec_559 ,mem_vec_560 ,mem_vec_561 ,mem_vec_562 ,mem_vec_563 ,mem_vec_564 ,mem_vec_565 ,mem_vec_566 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (c, 16) (512 / 32)
for (c94 = c95, c94_p_0 = 0;
	c94 < c95 + 512;
	c94 += 32, c94_p_0 += 32){
	// y = 14, x = 14, h = 3, w = 3, c = 32, f = 512
	// T (f, 16) (512 / 32)
	for (f = f57, fp_0 = 0;
		f < f57 + 512;
		f += 32, fp_0 += 32){
		// y = 14, x = 14, h = 3, w = 3, c = 32, f = 32
		// T (y, 2) (14 / 7)
		for (y = y50, yp_0 = 0;
			y < y50 + 14;
			y += 7, yp_0 += 7){
			// y = 7, x = 14, h = 3, w = 3, c = 32, f = 32
			// T (c, 1) (32 / 32)
			for (c93 = c94, c93_p_1 = c94_p_0, c93_p_0 = 0;
				c93 < c94 + 32;
				c93 += 32, c93_p_1 += 32, c93_p_0 += 32){
				// y = 7, x = 14, h = 3, w = 3, c = 32, f = 32
				// T (x, 14) (14 / 1)
				for (x = x50, xp_0 = 0;
					x < x50 + 14;
					x += 1, xp_0 += 1){
					// y = 7, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h38, hp_0 = 0;
						h < h38 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w37, wp_0 = 0;
							w < w37 + 3;
							w += 1, wp_0 += 1){
									mem_vec_553 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_554 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c93, cp_2 = c93_p_1, cp_1 = c93_p_0, cp_0 = 0;
										c < c93 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_553);
										mem_vec_553 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_554);
										mem_vec_554 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_555);
										mem_vec_555 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_556);
										mem_vec_556 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_557);
										mem_vec_557 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_558);
										mem_vec_558 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_559);
										mem_vec_559 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_560);
										mem_vec_560 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_561);
										mem_vec_561 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_562);
										mem_vec_562 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_563);
										mem_vec_563 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_564);
										mem_vec_564 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_565);
										mem_vec_565 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_566);
										mem_vec_566 = vec_22;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_553);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_554);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_555);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_556);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_557);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_558);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_559);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_560);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_561);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_562);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_563);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_564);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_565);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_566);
						}
					}
				}
			}
		}
	}
}


}