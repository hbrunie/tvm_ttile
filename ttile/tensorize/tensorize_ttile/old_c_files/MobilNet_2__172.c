#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (8, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (7, x); T (4, y); T (2, f); T (8, c); T (2, x)]
*/
IND_TYPE c, cp_0, c60_p_0, cp_1, c60, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x80_p_0, x81_p_0, xp_1, x80_p_1, xp_2, x80, x81, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y40 = 0;
IND_TYPE x82 = 0;
IND_TYPE h40 = 0;
IND_TYPE w40 = 0;
IND_TYPE c61 = 0;
IND_TYPE f40 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_392 ,mem_vec_393 ,mem_vec_394 ,mem_vec_395 ,mem_vec_396 ,mem_vec_397 ,mem_vec_398 ,mem_vec_399 ,mem_vec_400 ,mem_vec_401 ,mem_vec_402 ,mem_vec_403 ,mem_vec_404 ,mem_vec_405 ,mem_vec_406 ,mem_vec_407 ,mem_vec_408 ,mem_vec_409 ,mem_vec_410 ,mem_vec_411 ,mem_vec_412 ,mem_vec_413 ,mem_vec_414 ,mem_vec_415 ,mem_vec_416 ,mem_vec_417 ,mem_vec_418 ,mem_vec_419 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 2) (56 / 28)
for (x81 = x82, x81_p_0 = 0;
	x81 < x82 + 56;
	x81 += 28, x81_p_0 += 28){
	// y = 56, x = 28, h = 3, w = 3, c = 64, f = 64
	// T (c, 8) (64 / 8)
	for (c60 = c61, c60_p_0 = 0;
		c60 < c61 + 64;
		c60 += 8, c60_p_0 += 8){
		// y = 56, x = 28, h = 3, w = 3, c = 8, f = 64
		// T (f, 2) (64 / 32)
		for (f = f40, fp_0 = 0;
			f < f40 + 64;
			f += 32, fp_0 += 32){
			// y = 56, x = 28, h = 3, w = 3, c = 8, f = 32
			// T (y, 4) (56 / 14)
			for (y = y40, yp_0 = 0;
				y < y40 + 56;
				y += 14, yp_0 += 14){
				// y = 14, x = 28, h = 3, w = 3, c = 8, f = 32
				// T (x, 7) (28 / 4)
				for (x80 = x81, x80_p_1 = x81_p_0, x80_p_0 = 0;
					x80 < x81 + 28;
					x80 += 4, x80_p_1 += 4, x80_p_0 += 4){
					// y = 14, x = 4, h = 3, w = 3, c = 8, f = 32
					// T (h, 3) (3 / 1)
					for (h = h40, hp_0 = 0;
						h < h40 + 3;
						h += 1, hp_0 += 1){
						// y = 14, x = 4, h = 1, w = 3, c = 8, f = 32
						// T (w, 3) (3 / 1)
						for (w = w40, wp_0 = 0;
							w < w40 + 3;
							w += 1, wp_0 += 1){
							// y = 14, x = 4, h = 1, w = 1, c = 8, f = 32
							// T (x, 4) (4 / 1)
							for (x = x80, xp_2 = x80_p_1, xp_1 = x80_p_0, xp_0 = 0;
								x < x80 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_392 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_393 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c60, cp_1 = c60_p_0, cp_0 = 0;
											c < c60 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_392);
											mem_vec_392 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_393);
											mem_vec_393 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_394);
											mem_vec_394 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_395);
											mem_vec_395 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_396);
											mem_vec_396 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_397);
											mem_vec_397 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_398);
											mem_vec_398 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_399);
											mem_vec_399 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_400);
											mem_vec_400 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_401);
											mem_vec_401 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_402);
											mem_vec_402 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_403);
											mem_vec_403 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_404);
											mem_vec_404 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_405);
											mem_vec_405 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_406);
											mem_vec_406 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_407);
											mem_vec_407 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_408);
											mem_vec_408 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_409);
											mem_vec_409 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_410);
											mem_vec_410 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_411);
											mem_vec_411 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_412);
											mem_vec_412 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_413);
											mem_vec_413 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_414);
											mem_vec_414 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_415);
											mem_vec_415 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_416);
											mem_vec_416 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_417);
											mem_vec_417 = vec_40;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_418);
											mem_vec_418 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_419);
											mem_vec_419 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_392);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_393);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_394);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_395);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_396);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_397);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_398);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_399);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_400);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_401);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_402);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_403);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_404);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_405);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_406);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_407);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_408);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_409);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_410);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_411);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_412);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_413);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_414);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_415);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_416);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_417);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_418);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_419);
							}
						}
					}
				}
			}
		}
	}
}


}