#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x);
  Lambda_apply y [((Iter 11), (Arg 11)); ((Iter 1), (Arg 15))]; T (2, f);
  T (136, x); T (1, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x33_p_0, xp_1, x33, y, yp_0, y33_p_0, yp_1, y33;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y34 = 0;
IND_TYPE x34 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c25 = 0;
IND_TYPE f19 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_382 ,mem_vec_383 ,mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,mem_vec_392 ,mem_vec_393 ,mem_vec_394 ,mem_vec_395 ,mem_vec_396 ,mem_vec_397 ,mem_vec_398 ,mem_vec_399 ,mem_vec_400 ,mem_vec_401 ,mem_vec_402 ,mem_vec_403 ,mem_vec_404 ,mem_vec_405 ,mem_vec_406 ,mem_vec_407 ,mem_vec_408 ,mem_vec_409 ,mem_vec_410 ,mem_vec_411 ,mem_vec_412 ,mem_vec_413 ,mem_vec_414 ,mem_vec_415 ,mem_vec_416 ,mem_vec_417 ,mem_vec_418 ,mem_vec_419 ,mem_vec_420 ,mem_vec_421 ,mem_vec_422 ,mem_vec_423 ,mem_vec_424 ,mem_vec_425 ,mem_vec_426 ,mem_vec_427 ,mem_vec_428 ,mem_vec_429 ,mem_vec_430 ,mem_vec_431 ,mem_vec_432 ,mem_vec_433 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y33 = y34, y33_p_0 = 0;
	y33 < y34 + 136;
	y33 += 136, y33_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 136) (136 / 1)
	for (x33 = x34, x33_p_0 = 0;
		x33 < x34 + 136;
		x33 += 1, x33_p_0 += 1){
		// y = 136, x = 1, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f19, fp_0 = 0;
			f < f19 + 64;
			f += 32, fp_0 += 32){
				for (y = y33, yp_1 = y33_p_0, yp_0 = 0;
					y < y33 + 121;
					y += 11, yp_1 += 11, yp_0 += 11){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (x, 1) (1 / 1)
					for (x = x33, xp_1 = x33_p_0, xp_0 = 0;
						x < x33 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_382 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_383 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c25, cp_0 = 0;
									c < c25 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_382);
									mem_vec_382 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_383);
									mem_vec_383 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_384);
									mem_vec_384 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_385);
									mem_vec_385 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_386);
									mem_vec_386 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_387);
									mem_vec_387 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_388);
									mem_vec_388 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_389);
									mem_vec_389 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_390);
									mem_vec_390 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_391);
									mem_vec_391 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_392);
									mem_vec_392 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_393);
									mem_vec_393 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_394);
									mem_vec_394 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_395);
									mem_vec_395 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_396);
									mem_vec_396 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_397);
									mem_vec_397 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_398);
									mem_vec_398 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_399);
									mem_vec_399 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_400);
									mem_vec_400 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_401);
									mem_vec_401 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_402);
									mem_vec_402 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_403);
									mem_vec_403 = vec_34;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_382);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_383);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_384);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_385);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_386);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_387);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_388);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_389);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_390);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_391);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_392);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_393);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_394);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_395);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_396);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_397);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_398);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_399);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_400);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_401);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_402);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_403);
					}
				}
				for (y = y33 + 121, yp_1 = y33_p_0, yp_0 = 0;
					y < y33 + 121 + 15;
					y += 15, yp_1 += 15, yp_0 += 15){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (x, 1) (1 / 1)
					for (x = x33, xp_1 = x33_p_0, xp_0 = 0;
						x < x33 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_404 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_405 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								mem_vec_426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
								mem_vec_427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
								mem_vec_428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
								mem_vec_429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
								mem_vec_430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
								mem_vec_431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
								mem_vec_432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
								mem_vec_433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c25, cp_0 = 0;
									c < c25 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_404);
									mem_vec_404 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_405);
									mem_vec_405 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_406);
									mem_vec_406 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_407);
									mem_vec_407 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_408);
									mem_vec_408 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_409);
									mem_vec_409 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_410);
									mem_vec_410 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_411);
									mem_vec_411 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_412);
									mem_vec_412 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_413);
									mem_vec_413 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_414);
									mem_vec_414 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_415);
									mem_vec_415 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_416);
									mem_vec_416 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_417);
									mem_vec_417 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_418);
									mem_vec_418 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_419);
									mem_vec_419 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_420);
									mem_vec_420 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_421);
									mem_vec_421 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_422);
									mem_vec_422 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_423);
									mem_vec_423 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_424);
									mem_vec_424 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_425);
									mem_vec_425 = vec_34;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_426);
									mem_vec_426 = vec_35;



									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_427);
									mem_vec_427 = vec_37;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
									vec_39 = _mm512_set1_ps(scal_12);


									vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_428);
									mem_vec_428 = vec_38;



									vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_429);
									mem_vec_429 = vec_40;
									scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
									vec_42 = _mm512_set1_ps(scal_13);


									vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_430);
									mem_vec_430 = vec_41;



									vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_431);
									mem_vec_431 = vec_43;
									scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
									vec_45 = _mm512_set1_ps(scal_14);


									vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_432);
									mem_vec_432 = vec_44;



									vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_433);
									mem_vec_433 = vec_46;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_404);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_405);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_406);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_407);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_408);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_409);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_410);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_411);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_412);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_413);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_414);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_415);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_416);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_417);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_418);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_419);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_420);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_421);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_422);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_423);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_424);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_425);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_426);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_427);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_428);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_429);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_430);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_431);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_432);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_433);
					}
				}
		}
	}
}


}