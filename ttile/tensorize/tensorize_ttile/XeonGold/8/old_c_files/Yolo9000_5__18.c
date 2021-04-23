#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x);
  Lambda_apply y [((Iter 9), (Arg 9)); ((Iter 5), (Arg 11))]; T (2, f);
  T (68, x); T (1, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x183_p_0, xp_1, x183, y, yp_0, y183_p_0, yp_1, y183;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y184 = 0;
IND_TYPE x184 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c122 = 0;
IND_TYPE f122 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2388 ,mem_vec_2389 ,mem_vec_2390 ,mem_vec_2391 ,mem_vec_2392 ,mem_vec_2393 ,mem_vec_2394 ,mem_vec_2395 ,mem_vec_2396 ,mem_vec_2397 ,mem_vec_2398 ,mem_vec_2399 ,mem_vec_2400 ,mem_vec_2401 ,mem_vec_2402 ,mem_vec_2403 ,mem_vec_2404 ,mem_vec_2405 ,mem_vec_2406 ,mem_vec_2407 ,mem_vec_2408 ,mem_vec_2409 ,mem_vec_2410 ,mem_vec_2411 ,mem_vec_2412 ,mem_vec_2413 ,mem_vec_2414 ,mem_vec_2415 ,mem_vec_2416 ,mem_vec_2417 ,mem_vec_2418 ,mem_vec_2419 ,mem_vec_2420 ,mem_vec_2421 ,mem_vec_2422 ,mem_vec_2423 ,mem_vec_2424 ,mem_vec_2425 ,mem_vec_2426 ,mem_vec_2427 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y183 = y184, y183_p_0 = 0;
	y183 < y184 + 136;
	y183 += 136, y183_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 68) (136 / 2)
	for (x183 = x184, x183_p_0 = 0;
		x183 < x184 + 136;
		x183 += 2, x183_p_0 += 2){
		// y = 136, x = 2, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f122, fp_0 = 0;
			f < f122 + 64;
			f += 32, fp_0 += 32){
				for (y = y183, yp_1 = y183_p_0, yp_0 = 0;
					y < y183 + 81;
					y += 9, yp_1 += 9, yp_0 += 9){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x183, xp_1 = x183_p_0, xp_0 = 0;
						x < x183 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_2388 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_2389 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_2390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_2391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_2392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_2393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_2394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_2395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_2396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_2397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_2398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_2399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_2400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_2401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_2402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_2403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_2404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_2405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c122, cp_0 = 0;
									c < c122 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2388);
									mem_vec_2388 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2389);
									mem_vec_2389 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2390);
									mem_vec_2390 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2391);
									mem_vec_2391 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2392);
									mem_vec_2392 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2393);
									mem_vec_2393 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2394);
									mem_vec_2394 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2395);
									mem_vec_2395 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2396);
									mem_vec_2396 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2397);
									mem_vec_2397 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2398);
									mem_vec_2398 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2399);
									mem_vec_2399 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2400);
									mem_vec_2400 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2401);
									mem_vec_2401 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2402);
									mem_vec_2402 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2403);
									mem_vec_2403 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2404);
									mem_vec_2404 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2405);
									mem_vec_2405 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2388);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2389);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2390);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2391);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2392);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2393);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2394);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2395);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2396);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2397);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2398);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2399);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2400);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2401);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2402);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2403);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2404);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2405);
					}
				}
				for (y = y183 + 81, yp_1 = y183_p_0, yp_0 = 0;
					y < y183 + 81 + 55;
					y += 11, yp_1 += 11, yp_0 += 11){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x183, xp_1 = x183_p_0, xp_0 = 0;
						x < x183 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_2406 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_2407 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_2408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_2409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_2410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_2411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_2412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_2413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_2414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_2415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_2416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_2417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_2418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_2419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_2420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_2421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_2422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_2423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_2424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_2425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_2426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_2427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c122, cp_0 = 0;
									c < c122 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2406);
									mem_vec_2406 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2407);
									mem_vec_2407 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2408);
									mem_vec_2408 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2409);
									mem_vec_2409 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2410);
									mem_vec_2410 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2411);
									mem_vec_2411 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2412);
									mem_vec_2412 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2413);
									mem_vec_2413 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2414);
									mem_vec_2414 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2415);
									mem_vec_2415 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2416);
									mem_vec_2416 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2417);
									mem_vec_2417 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2418);
									mem_vec_2418 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2419);
									mem_vec_2419 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2420);
									mem_vec_2420 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2421);
									mem_vec_2421 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2422);
									mem_vec_2422 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2423);
									mem_vec_2423 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2424);
									mem_vec_2424 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2425);
									mem_vec_2425 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2426);
									mem_vec_2426 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2427);
									mem_vec_2427 = vec_34;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2406);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2407);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2408);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2409);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2410);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2411);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2412);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2413);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2414);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2415);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2416);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2417);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2418);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2419);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2420);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2421);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2422);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2423);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2424);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2425);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2426);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2427);
					}
				}
		}
	}
}


}