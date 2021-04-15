#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (2, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (8, x); T (68, y); T (16, c); T (1, x); T (34, x)]
*/
IND_TYPE c, cp_0, c72_p_0, cp_1, c72, h, hp_0, w, wp_0, x, xp_0, x120_p_0, x121_p_0, x122_p_0, xp_1, x120_p_1, x121_p_1, xp_2, x120_p_2, xp_3, x120, x121, x122, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y48 = 0;
IND_TYPE x123 = 0;
IND_TYPE h48 = 0;
IND_TYPE w48 = 0;
IND_TYPE c73 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,mem_vec_392 ,mem_vec_393 ,mem_vec_394 ,mem_vec_395 ,mem_vec_396 ,mem_vec_397 ,mem_vec_398 ,mem_vec_399 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 34) (272 / 8)
for (x122 = x123, x122_p_0 = 0;
	x122 < x123 + 272;
	x122 += 8, x122_p_0 += 8){
	// y = 272, x = 8, h = 3, w = 3, c = 32, f = 64
	// T (x, 1) (8 / 8)
	for (x121 = x122, x121_p_1 = x122_p_0, x121_p_0 = 0;
		x121 < x122 + 8;
		x121 += 8, x121_p_1 += 8, x121_p_0 += 8){
		// y = 272, x = 8, h = 3, w = 3, c = 32, f = 64
		// T (c, 16) (32 / 2)
		for (c72 = c73, c72_p_0 = 0;
			c72 < c73 + 32;
			c72 += 2, c72_p_0 += 2){
			// y = 272, x = 8, h = 3, w = 3, c = 2, f = 64
			// T (y, 68) (272 / 4)
			for (y = y48, yp_0 = 0;
				y < y48 + 272;
				y += 4, yp_0 += 4){
				// y = 4, x = 8, h = 3, w = 3, c = 2, f = 64
				// T (x, 8) (8 / 1)
				for (x120 = x121, x120_p_2 = x121_p_1, x120_p_1 = x121_p_0, x120_p_0 = 0;
					x120 < x121 + 8;
					x120 += 1, x120_p_2 += 1, x120_p_1 += 1, x120_p_0 += 1){
					// y = 4, x = 1, h = 3, w = 3, c = 2, f = 64
					// T (h, 3) (3 / 1)
					for (h = h48, hp_0 = 0;
						h < h48 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 1, h = 1, w = 3, c = 2, f = 64
						// T (w, 3) (3 / 1)
						for (w = w48, wp_0 = 0;
							w < w48 + 3;
							w += 1, wp_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 2, f = 64
							// T (x, 1) (1 / 1)
							for (x = x120, xp_3 = x120_p_2, xp_2 = x120_p_1, xp_1 = x120_p_0, xp_0 = 0;
								x < x120 + 1;
								x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_384 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_385 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_386 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_387 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = 4, x = 1, h = 1, w = 1, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c72, cp_1 = c72_p_0, cp_0 = 0;
											c < c72 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_384);
											mem_vec_384 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_385);
											mem_vec_385 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_386);
											mem_vec_386 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_387);
											mem_vec_387 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_388);
											mem_vec_388 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_389);
											mem_vec_389 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_390);
											mem_vec_390 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_391);
											mem_vec_391 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_392);
											mem_vec_392 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_393);
											mem_vec_393 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_394);
											mem_vec_394 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_395);
											mem_vec_395 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_396);
											mem_vec_396 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_397);
											mem_vec_397 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_398);
											mem_vec_398 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_399);
											mem_vec_399 = vec_23;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_384);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_385);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_386);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_387);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_388);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_389);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_390);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_391);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_392);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_393);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_394);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_395);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_396);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_397);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_398);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_399);
							}
						}
					}
				}
			}
		}
	}
}


}