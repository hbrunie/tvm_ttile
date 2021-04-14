#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (8, x); T (7, x);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (1, x)]
*/
IND_TYPE c, cp_0, x, xp_0, x1448_p_0, x1449_p_0, xp_1, x1448_p_1, xp_2, x1448, x1449, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y724 = 0;
IND_TYPE x1450 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c724 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_13360 ,mem_vec_13361 ,mem_vec_13362 ,mem_vec_13363 ,mem_vec_13364 ,mem_vec_13365 ,mem_vec_13366 ,mem_vec_13367 ,mem_vec_13368 ,mem_vec_13369 ,mem_vec_13370 ,mem_vec_13371 ,mem_vec_13372 ,mem_vec_13373 ,mem_vec_13374 ,mem_vec_13375 ,mem_vec_13376 ,mem_vec_13377 ,mem_vec_13378 ,mem_vec_13379 ,mem_vec_13380 ,mem_vec_13381 ,mem_vec_13382 ,mem_vec_13383 ,mem_vec_13384 ,mem_vec_13385 ,mem_vec_13386 ,mem_vec_13387 ,mem_vec_13388 ,mem_vec_13389 ,mem_vec_13390 ,mem_vec_13391 ,mem_vec_13392 ,mem_vec_13393 ,mem_vec_13394 ,mem_vec_13395 ,mem_vec_13396 ,mem_vec_13397 ,mem_vec_13398 ,mem_vec_13399 ,mem_vec_13400 ,mem_vec_13401 ,mem_vec_13402 ,mem_vec_13403 ,mem_vec_13404 ,mem_vec_13405 ,mem_vec_13406 ,mem_vec_13407 ,mem_vec_13408 ,mem_vec_13409 ,mem_vec_13410 ,mem_vec_13411 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (x, 1) (56 / 56)
for (x1449 = x1450, x1449_p_0 = 0;
	x1449 < x1450 + 56;
	x1449 += 56, x1449_p_0 += 56){
		for (y = y724, yp_0 = 0;
			y < y724 + 42;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 56, h = 1, w = 1, c = 64, f = 64
			// T (x, 7) (56 / 8)
			for (x1448 = x1449, x1448_p_1 = x1449_p_0, x1448_p_0 = 0;
				x1448 < x1449 + 56;
				x1448 += 8, x1448_p_1 += 8, x1448_p_0 += 8){
				// y = ph_y, x = 8, h = 1, w = 1, c = 64, f = 64
				// T (x, 8) (8 / 1)
				for (x = x1448, xp_2 = x1448_p_1, xp_1 = x1448_p_0, xp_0 = 0;
					x < x1448 + 8;
					x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
							mem_vec_13360 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_13361 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_13362 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
							mem_vec_13363 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
							mem_vec_13364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_13365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_13366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
							mem_vec_13367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
							mem_vec_13368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_13369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_13370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
							mem_vec_13371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
							mem_vec_13372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_13373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_13374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
							mem_vec_13375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
							mem_vec_13376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
							mem_vec_13377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
							mem_vec_13378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
							mem_vec_13379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
							mem_vec_13380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
							mem_vec_13381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
							mem_vec_13382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
							mem_vec_13383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
							// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
							// T (c, 64) (64 / 1)
							for (c = c724, cp_0 = 0;
								c < c724 + 64;
								c += 1, cp_0 += 1){
								scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13360);
								mem_vec_13360 = vec_0;

								vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13361);
								mem_vec_13361 = vec_3;

								vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

								vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13362);
								mem_vec_13362 = vec_5;

								vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

								vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13363);
								mem_vec_13363 = vec_7;
								scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
								vec_10 = _mm512_set1_ps(scal_1);


								vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13364);
								mem_vec_13364 = vec_9;



								vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13365);
								mem_vec_13365 = vec_11;



								vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13366);
								mem_vec_13366 = vec_12;



								vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13367);
								mem_vec_13367 = vec_13;
								scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
								vec_15 = _mm512_set1_ps(scal_2);


								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13368);
								mem_vec_13368 = vec_14;



								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13369);
								mem_vec_13369 = vec_16;



								vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13370);
								mem_vec_13370 = vec_17;



								vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13371);
								mem_vec_13371 = vec_18;
								scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
								vec_20 = _mm512_set1_ps(scal_3);


								vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13372);
								mem_vec_13372 = vec_19;



								vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13373);
								mem_vec_13373 = vec_21;



								vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13374);
								mem_vec_13374 = vec_22;



								vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13375);
								mem_vec_13375 = vec_23;
								scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
								vec_25 = _mm512_set1_ps(scal_4);


								vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_13376);
								mem_vec_13376 = vec_24;



								vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_13377);
								mem_vec_13377 = vec_26;



								vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_13378);
								mem_vec_13378 = vec_27;



								vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_13379);
								mem_vec_13379 = vec_28;
								scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
								vec_30 = _mm512_set1_ps(scal_5);


								vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13380);
								mem_vec_13380 = vec_29;



								vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13381);
								mem_vec_13381 = vec_31;



								vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_13382);
								mem_vec_13382 = vec_32;



								vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_13383);
								mem_vec_13383 = vec_33;
							}
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13360);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13361);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13362);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13363);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13364);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13365);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13366);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13367);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13368);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13369);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13370);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13371);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13372);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13373);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_13374);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_13375);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13376);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13377);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_13378);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_13379);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13380);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13381);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_13382);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_13383);
				}
			}
		}
		for (y = y724 + 42, yp_0 = 0;
			y < y724 + 42 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 1, w = 1, c = 64, f = 64
			// T (x, 7) (56 / 8)
			for (x1448 = x1449, x1448_p_1 = x1449_p_0, x1448_p_0 = 0;
				x1448 < x1449 + 56;
				x1448 += 8, x1448_p_1 += 8, x1448_p_0 += 8){
				// y = ph_y, x = 8, h = 1, w = 1, c = 64, f = 64
				// T (x, 8) (8 / 1)
				for (x = x1448, xp_2 = x1448_p_1, xp_1 = x1448_p_0, xp_0 = 0;
					x < x1448 + 8;
					x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
							mem_vec_13384 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_13385 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_13386 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
							mem_vec_13387 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
							mem_vec_13388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_13389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_13390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
							mem_vec_13391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
							mem_vec_13392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_13393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_13394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
							mem_vec_13395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
							mem_vec_13396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_13397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_13398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
							mem_vec_13399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
							mem_vec_13400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
							mem_vec_13401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
							mem_vec_13402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
							mem_vec_13403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
							mem_vec_13404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
							mem_vec_13405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
							mem_vec_13406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
							mem_vec_13407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
							mem_vec_13408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
							mem_vec_13409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
							mem_vec_13410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
							mem_vec_13411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
							// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
							// T (c, 64) (64 / 1)
							for (c = c724, cp_0 = 0;
								c < c724 + 64;
								c += 1, cp_0 += 1){
								scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13384);
								mem_vec_13384 = vec_0;

								vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13385);
								mem_vec_13385 = vec_3;

								vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

								vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13386);
								mem_vec_13386 = vec_5;

								vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

								vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13387);
								mem_vec_13387 = vec_7;
								scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
								vec_10 = _mm512_set1_ps(scal_1);


								vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13388);
								mem_vec_13388 = vec_9;



								vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13389);
								mem_vec_13389 = vec_11;



								vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13390);
								mem_vec_13390 = vec_12;



								vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13391);
								mem_vec_13391 = vec_13;
								scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
								vec_15 = _mm512_set1_ps(scal_2);


								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13392);
								mem_vec_13392 = vec_14;



								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13393);
								mem_vec_13393 = vec_16;



								vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13394);
								mem_vec_13394 = vec_17;



								vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13395);
								mem_vec_13395 = vec_18;
								scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
								vec_20 = _mm512_set1_ps(scal_3);


								vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13396);
								mem_vec_13396 = vec_19;



								vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13397);
								mem_vec_13397 = vec_21;



								vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13398);
								mem_vec_13398 = vec_22;



								vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13399);
								mem_vec_13399 = vec_23;
								scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
								vec_25 = _mm512_set1_ps(scal_4);


								vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_13400);
								mem_vec_13400 = vec_24;



								vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_13401);
								mem_vec_13401 = vec_26;



								vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_13402);
								mem_vec_13402 = vec_27;



								vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_13403);
								mem_vec_13403 = vec_28;
								scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
								vec_30 = _mm512_set1_ps(scal_5);


								vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13404);
								mem_vec_13404 = vec_29;



								vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13405);
								mem_vec_13405 = vec_31;



								vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_13406);
								mem_vec_13406 = vec_32;



								vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_13407);
								mem_vec_13407 = vec_33;
								scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
								vec_35 = _mm512_set1_ps(scal_6);


								vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_13408);
								mem_vec_13408 = vec_34;



								vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_13409);
								mem_vec_13409 = vec_36;



								vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_13410);
								mem_vec_13410 = vec_37;



								vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_13411);
								mem_vec_13411 = vec_38;
							}
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13384);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13385);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13386);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13387);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13388);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13389);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13390);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13391);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13392);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13393);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13394);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13395);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13396);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13397);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_13398);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_13399);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13400);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13401);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_13402);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_13403);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13404);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13405);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_13406);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_13407);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13408);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13409);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_13410);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_13411);
				}
			}
		}
}


}