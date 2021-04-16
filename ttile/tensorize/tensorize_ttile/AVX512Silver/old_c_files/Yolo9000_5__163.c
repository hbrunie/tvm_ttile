#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (128, c); Hoist_vars [c]; T (2, x); T (2, y);
  T (1, c); T (68, x); T (17, y)]
*/
IND_TYPE c, cp_0, c354_p_0, cp_1, c354, x, xp_0, x468_p_0, xp_1, x468, y, yp_0, y468_p_0, yp_1, y468;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y469 = 0;
IND_TYPE x469 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c355 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_6306 ,mem_vec_6307 ,mem_vec_6308 ,mem_vec_6309 ,mem_vec_6310 ,mem_vec_6311 ,mem_vec_6312 ,mem_vec_6313 ,mem_vec_6314 ,mem_vec_6315 ,mem_vec_6316 ,mem_vec_6317 ,mem_vec_6318 ,mem_vec_6319 ,mem_vec_6320 ,mem_vec_6321 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 17) (136 / 8)
for (y468 = y469, y468_p_0 = 0;
	y468 < y469 + 136;
	y468 += 8, y468_p_0 += 8){
	// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 68) (136 / 2)
	for (x468 = x469, x468_p_0 = 0;
		x468 < x469 + 136;
		x468 += 2, x468_p_0 += 2){
		// y = 8, x = 2, h = 1, w = 1, c = 128, f = 64
		// T (c, 1) (128 / 128)
		for (c354 = c355, c354_p_0 = 0;
			c354 < c355 + 128;
			c354 += 128, c354_p_0 += 128){
			// y = 8, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 2) (8 / 4)
			for (y = y468, yp_1 = y468_p_0, yp_0 = 0;
				y < y468 + 8;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 2) (2 / 1)
				for (x = x468, xp_1 = x468_p_0, xp_0 = 0;
					x < x468 + 2;
					x += 1, xp_1 += 1, xp_0 += 1){
							mem_vec_6306 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_6307 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_6308 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
							mem_vec_6309 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
							mem_vec_6310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_6311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_6312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
							mem_vec_6313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
							mem_vec_6314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_6315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_6316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
							mem_vec_6317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
							mem_vec_6318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_6319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_6320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
							mem_vec_6321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 64
							// T (c, 128) (128 / 1)
							for (c = c354, cp_1 = c354_p_0, cp_0 = 0;
								c < c354 + 128;
								c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6306);
								mem_vec_6306 = vec_0;

								vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6307);
								mem_vec_6307 = vec_3;

								vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

								vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6308);
								mem_vec_6308 = vec_5;

								vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

								vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6309);
								mem_vec_6309 = vec_7;
								scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
								vec_10 = _mm512_set1_ps(scal_1);


								vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6310);
								mem_vec_6310 = vec_9;



								vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6311);
								mem_vec_6311 = vec_11;



								vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6312);
								mem_vec_6312 = vec_12;



								vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6313);
								mem_vec_6313 = vec_13;
								scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
								vec_15 = _mm512_set1_ps(scal_2);


								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6314);
								mem_vec_6314 = vec_14;



								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6315);
								mem_vec_6315 = vec_16;



								vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6316);
								mem_vec_6316 = vec_17;



								vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6317);
								mem_vec_6317 = vec_18;
								scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
								vec_20 = _mm512_set1_ps(scal_3);


								vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6318);
								mem_vec_6318 = vec_19;



								vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6319);
								mem_vec_6319 = vec_21;



								vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6320);
								mem_vec_6320 = vec_22;



								vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6321);
								mem_vec_6321 = vec_23;
							}
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6306);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6307);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6308);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6309);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6310);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6311);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6312);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6313);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6314);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6315);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6316);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6317);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6318);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6319);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6320);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6321);
				}
			}
		}
	}
}


}