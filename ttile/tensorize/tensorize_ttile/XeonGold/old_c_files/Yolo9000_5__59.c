#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 4), (Arg 11))]; T (2, f);
  T (68, x); T (2, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x30_p_0, xp_1, x30, y, yp_0, y30_p_0, yp_1, y30;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y31 = 0;
IND_TYPE x31 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c20 = 0;
IND_TYPE f20 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_412 ,mem_vec_413 ,mem_vec_414 ,mem_vec_415 ,mem_vec_416 ,mem_vec_417 ,mem_vec_418 ,mem_vec_419 ,mem_vec_420 ,mem_vec_421 ,mem_vec_422 ,mem_vec_423 ,mem_vec_424 ,mem_vec_425 ,mem_vec_426 ,mem_vec_427 ,mem_vec_428 ,mem_vec_429 ,mem_vec_430 ,mem_vec_431 ,mem_vec_432 ,mem_vec_433 ,mem_vec_434 ,mem_vec_435 ,mem_vec_436 ,mem_vec_437 ,mem_vec_438 ,mem_vec_439 ,mem_vec_440 ,mem_vec_441 ,mem_vec_442 ,mem_vec_443 ,mem_vec_444 ,mem_vec_445 ,mem_vec_446 ,mem_vec_447 ,mem_vec_448 ,mem_vec_449 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 2) (136 / 68)
for (y30 = y31, y30_p_0 = 0;
	y30 < y31 + 136;
	y30 += 68, y30_p_0 += 68){
	// y = 68, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 68) (136 / 2)
	for (x30 = x31, x30_p_0 = 0;
		x30 < x31 + 136;
		x30 += 2, x30_p_0 += 2){
		// y = 68, x = 2, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f20, fp_0 = 0;
			f < f20 + 64;
			f += 32, fp_0 += 32){
				for (y = y30, yp_1 = y30_p_0, yp_0 = 0;
					y < y30 + 24;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x30, xp_1 = x30_p_0, xp_0 = 0;
						x < x30 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_412 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_413 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c20, cp_0 = 0;
									c < c20 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_412);
									mem_vec_412 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_413);
									mem_vec_413 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_414);
									mem_vec_414 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_415);
									mem_vec_415 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_416);
									mem_vec_416 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_417);
									mem_vec_417 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_418);
									mem_vec_418 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_419);
									mem_vec_419 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_420);
									mem_vec_420 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_421);
									mem_vec_421 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_422);
									mem_vec_422 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_423);
									mem_vec_423 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_424);
									mem_vec_424 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_425);
									mem_vec_425 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_426);
									mem_vec_426 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_427);
									mem_vec_427 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_412);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_413);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_414);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_415);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_416);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_417);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_418);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_419);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_420);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_421);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_422);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_423);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_424);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_425);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_426);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_427);
					}
				}
				for (y = y30 + 24, yp_1 = y30_p_0, yp_0 = 0;
					y < y30 + 24 + 44;
					y += 11, yp_1 += 11, yp_0 += 11){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x30, xp_1 = x30_p_0, xp_0 = 0;
						x < x30 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_428 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_429 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c20, cp_0 = 0;
									c < c20 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_428);
									mem_vec_428 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_429);
									mem_vec_429 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_430);
									mem_vec_430 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_431);
									mem_vec_431 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_432);
									mem_vec_432 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_433);
									mem_vec_433 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_434);
									mem_vec_434 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_435);
									mem_vec_435 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_436);
									mem_vec_436 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_437);
									mem_vec_437 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_438);
									mem_vec_438 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_439);
									mem_vec_439 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_440);
									mem_vec_440 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_441);
									mem_vec_441 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_442);
									mem_vec_442 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_443);
									mem_vec_443 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_444);
									mem_vec_444 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_445);
									mem_vec_445 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_446);
									mem_vec_446 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_447);
									mem_vec_447 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_448);
									mem_vec_448 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_449);
									mem_vec_449 = vec_34;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_428);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_429);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_430);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_431);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_432);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_433);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_434);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_435);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_436);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_437);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_438);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_439);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_440);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_441);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_442);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_443);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_444);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_445);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_446);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_447);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_448);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_449);
					}
				}
		}
	}
}


}