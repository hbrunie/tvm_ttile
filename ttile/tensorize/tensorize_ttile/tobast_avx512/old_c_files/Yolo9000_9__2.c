#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (4, x); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))]; T (4, f);
  T (128, c); T (17, x)]
*/
IND_TYPE c, cp_0, c768_p_0, cp_1, c768, f, fp_0, x, xp_0, x1024_p_0, x1025_p_0, xp_1, x1024_p_1, xp_2, x1024, x1025, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y512 = 0;
IND_TYPE x1026 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c769 = 0;
IND_TYPE f512 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9324 ,mem_vec_9325 ,mem_vec_9326 ,mem_vec_9327 ,mem_vec_9328 ,mem_vec_9329 ,mem_vec_9330 ,mem_vec_9331 ,mem_vec_9332 ,mem_vec_9333 ,mem_vec_9334 ,mem_vec_9335 ,mem_vec_9336 ,mem_vec_9337 ,mem_vec_9338 ,mem_vec_9339 ,mem_vec_9340 ,mem_vec_9341 ,mem_vec_9342 ,mem_vec_9343 ,mem_vec_9344 ,mem_vec_9345 ,mem_vec_9346 ,mem_vec_9347 ,mem_vec_9348 ,mem_vec_9349 ,mem_vec_9350 ,mem_vec_9351 ,mem_vec_9352 ,mem_vec_9353 ,mem_vec_9354 ,mem_vec_9355 ,mem_vec_9356 ,mem_vec_9357 ,mem_vec_9358 ,mem_vec_9359 ,mem_vec_9360 ,mem_vec_9361 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 17) (68 / 4)
for (x1025 = x1026, x1025_p_0 = 0;
	x1025 < x1026 + 68;
	x1025 += 4, x1025_p_0 += 4){
	// y = 68, x = 4, h = 1, w = 1, c = 256, f = 128
	// T (c, 128) (256 / 2)
	for (c768 = c769, c768_p_0 = 0;
		c768 < c769 + 256;
		c768 += 2, c768_p_0 += 2){
		// y = 68, x = 4, h = 1, w = 1, c = 2, f = 128
		// T (f, 4) (128 / 32)
		for (f = f512, fp_0 = 0;
			f < f512 + 128;
			f += 32, fp_0 += 32){
				for (y = y512, yp_0 = 0;
					y < y512 + 18;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 4, h = 1, w = 1, c = 2, f = 32
					// T (x, 1) (4 / 4)
					for (x1024 = x1025, x1024_p_1 = x1025_p_0, x1024_p_0 = 0;
						x1024 < x1025 + 4;
						x1024 += 4, x1024_p_1 += 4, x1024_p_0 += 4){
						// y = ph_y, x = 4, h = 1, w = 1, c = 2, f = 32
						// T (x, 4) (4 / 1)
						for (x = x1024, xp_2 = x1024_p_1, xp_1 = x1024_p_0, xp_0 = 0;
							x < x1024 + 4;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9324 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9325 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_9333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_9334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_9335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_9336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_9337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_9338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_9339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_9340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_9341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c768, cp_1 = c768_p_0, cp_0 = 0;
										c < c768 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9324);
										mem_vec_9324 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9325);
										mem_vec_9325 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9326);
										mem_vec_9326 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9327);
										mem_vec_9327 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9328);
										mem_vec_9328 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9329);
										mem_vec_9329 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9330);
										mem_vec_9330 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9331);
										mem_vec_9331 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9332);
										mem_vec_9332 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9333);
										mem_vec_9333 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9334);
										mem_vec_9334 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9335);
										mem_vec_9335 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9336);
										mem_vec_9336 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9337);
										mem_vec_9337 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9338);
										mem_vec_9338 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9339);
										mem_vec_9339 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9340);
										mem_vec_9340 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9341);
										mem_vec_9341 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9324);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9325);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9326);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9327);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9328);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9329);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9330);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9331);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9332);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9333);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9334);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9335);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9336);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9337);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9338);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9339);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9340);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9341);
						}
					}
				}
				for (y = y512 + 18, yp_0 = 0;
					y < y512 + 18 + 50;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 4, h = 1, w = 1, c = 2, f = 32
					// T (x, 1) (4 / 4)
					for (x1024 = x1025, x1024_p_1 = x1025_p_0, x1024_p_0 = 0;
						x1024 < x1025 + 4;
						x1024 += 4, x1024_p_1 += 4, x1024_p_0 += 4){
						// y = ph_y, x = 4, h = 1, w = 1, c = 2, f = 32
						// T (x, 4) (4 / 1)
						for (x = x1024, xp_2 = x1024_p_1, xp_1 = x1024_p_0, xp_0 = 0;
							x < x1024 + 4;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9342 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9343 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_9351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_9352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_9353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_9354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_9355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_9356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_9357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_9358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_9359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_9360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_9361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c768, cp_1 = c768_p_0, cp_0 = 0;
										c < c768 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9342);
										mem_vec_9342 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9343);
										mem_vec_9343 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9344);
										mem_vec_9344 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9345);
										mem_vec_9345 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9346);
										mem_vec_9346 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9347);
										mem_vec_9347 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9348);
										mem_vec_9348 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9349);
										mem_vec_9349 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9350);
										mem_vec_9350 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9351);
										mem_vec_9351 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9352);
										mem_vec_9352 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9353);
										mem_vec_9353 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9354);
										mem_vec_9354 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9355);
										mem_vec_9355 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9356);
										mem_vec_9356 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9357);
										mem_vec_9357 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9358);
										mem_vec_9358 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9359);
										mem_vec_9359 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9360);
										mem_vec_9360 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9361);
										mem_vec_9361 = vec_31;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9342);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9343);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9344);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9345);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9346);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9347);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9348);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9349);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9350);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9351);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9352);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9353);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9354);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9355);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9356);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9357);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9358);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9359);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9360);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9361);
						}
					}
				}
		}
	}
}


}