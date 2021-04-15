#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (3, c); Hoist_vars [c]; T (17, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 4), (Arg 7)); ((Iter 5), (Arg 8))];
  T (4, x); T (8, y); T (8, x)]
*/
IND_TYPE c, cp_0, h, hp_0, w, wp_0, x, xp_0, x170_p_0, x171_p_0, xp_1, x170_p_1, xp_2, x170, x171, y, yp_0, y138_p_0, yp_1, y138;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y139 = 0;
IND_TYPE x172 = 0;
IND_TYPE h68 = 0;
IND_TYPE w54 = 0;
IND_TYPE c88 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_400 ,mem_vec_401 ,mem_vec_402 ,mem_vec_403 ,mem_vec_404 ,mem_vec_405 ,mem_vec_406 ,mem_vec_407 ,mem_vec_408 ,mem_vec_409 ,mem_vec_410 ,mem_vec_411 ,mem_vec_412 ,mem_vec_413 ,mem_vec_414 ,mem_vec_415 ,mem_vec_416 ,mem_vec_417 ,mem_vec_418 ,mem_vec_419 ,mem_vec_420 ,mem_vec_421 ,mem_vec_422 ,mem_vec_423 ,mem_vec_424 ,mem_vec_425 ,mem_vec_426 ,mem_vec_427 ,mem_vec_428 ,mem_vec_429 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (x, 8) (544 / 68)
for (x171 = x172, x171_p_0 = 0;
	x171 < x172 + 544;
	x171 += 68, x171_p_0 += 68){
	// y = 544, x = 68, h = 3, w = 3, c = 3, f = 32
	// T (y, 8) (544 / 68)
	for (y138 = y139, y138_p_0 = 0;
		y138 < y139 + 544;
		y138 += 68, y138_p_0 += 68){
		// y = 68, x = 68, h = 3, w = 3, c = 3, f = 32
		// T (x, 4) (68 / 17)
		for (x170 = x171, x170_p_1 = x171_p_0, x170_p_0 = 0;
			x170 < x171 + 68;
			x170 += 17, x170_p_1 += 17, x170_p_0 += 17){
				for (y = y138, yp_1 = y138_p_0, yp_0 = 0;
					y < y138 + 28;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 3, f = 32
					// T (h, 3) (3 / 1)
					for (h = h68, hp_0 = 0;
						h < h68 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 17, h = 1, w = 3, c = 3, f = 32
						// T (w, 3) (3 / 1)
						for (w = w54, wp_0 = 0;
							w < w54 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 17, h = 1, w = 1, c = 3, f = 32
							// T (x, 17) (17 / 1)
							for (x = x170, xp_2 = x170_p_1, xp_1 = x170_p_0, xp_0 = 0;
								x < x170 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_400 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_401 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c88, cp_0 = 0;
											c < c88 + 3;
											c += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_400);
											mem_vec_400 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_401);
											mem_vec_401 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_402);
											mem_vec_402 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_403);
											mem_vec_403 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_404);
											mem_vec_404 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_405);
											mem_vec_405 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_406);
											mem_vec_406 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_407);
											mem_vec_407 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_408);
											mem_vec_408 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_409);
											mem_vec_409 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_410);
											mem_vec_410 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_411);
											mem_vec_411 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_412);
											mem_vec_412 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_413);
											mem_vec_413 = vec_22;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_400);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_401);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_402);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_403);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_404);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_405);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_406);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_407);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_408);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_409);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_410);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_411);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_412);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_413);
							}
						}
					}
				}
				for (y = y138 + 28, yp_1 = y138_p_0, yp_0 = 0;
					y < y138 + 28 + 40;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 3, f = 32
					// T (h, 3) (3 / 1)
					for (h = h68, hp_0 = 0;
						h < h68 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 17, h = 1, w = 3, c = 3, f = 32
						// T (w, 3) (3 / 1)
						for (w = w54, wp_0 = 0;
							w < w54 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 17, h = 1, w = 1, c = 3, f = 32
							// T (x, 17) (17 / 1)
							for (x = x170, xp_2 = x170_p_1, xp_1 = x170_p_0, xp_0 = 0;
								x < x170 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_414 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_415 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c88, cp_0 = 0;
											c < c88 + 3;
											c += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_414);
											mem_vec_414 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_415);
											mem_vec_415 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_416);
											mem_vec_416 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_417);
											mem_vec_417 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_418);
											mem_vec_418 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_419);
											mem_vec_419 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_420);
											mem_vec_420 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_421);
											mem_vec_421 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_422);
											mem_vec_422 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_423);
											mem_vec_423 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_424);
											mem_vec_424 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_425);
											mem_vec_425 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_426);
											mem_vec_426 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_427);
											mem_vec_427 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_428);
											mem_vec_428 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_429);
											mem_vec_429 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_414);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_415);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_416);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_417);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_418);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_419);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_420);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_421);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_422);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_423);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_424);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_425);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_426);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_427);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_428);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_429);
							}
						}
					}
				}
		}
	}
}


}