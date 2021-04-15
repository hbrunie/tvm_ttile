#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (1, x); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (8, c); T (17, x)]
*/
IND_TYPE c, cp_0, c1158_p_0, cp_1, c1158, f, fp_0, x, xp_0, x1544_p_0, x1545_p_0, xp_1, x1544_p_1, xp_2, x1544, x1545, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y772 = 0;
IND_TYPE x1546 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1159 = 0;
IND_TYPE f772 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_16352 ,mem_vec_16353 ,mem_vec_16354 ,mem_vec_16355 ,mem_vec_16356 ,mem_vec_16357 ,mem_vec_16358 ,mem_vec_16359 ,mem_vec_16360 ,mem_vec_16361 ,mem_vec_16362 ,mem_vec_16363 ,mem_vec_16364 ,mem_vec_16365 ,mem_vec_16366 ,mem_vec_16367 ,mem_vec_16368 ,mem_vec_16369 ,mem_vec_16370 ,mem_vec_16371 ,mem_vec_16372 ,mem_vec_16373 ,mem_vec_16374 ,mem_vec_16375 ,mem_vec_16376 ,mem_vec_16377 ,mem_vec_16378 ,mem_vec_16379 ,mem_vec_16380 ,mem_vec_16381 ,mem_vec_16382 ,mem_vec_16383 ,mem_vec_16384 ,mem_vec_16385 ,mem_vec_16386 ,mem_vec_16387 ,mem_vec_16388 ,mem_vec_16389 ,mem_vec_16390 ,mem_vec_16391 ,mem_vec_16392 ,mem_vec_16393 ,mem_vec_16394 ,mem_vec_16395 ,mem_vec_16396 ,mem_vec_16397 ,mem_vec_16398 ,mem_vec_16399 ,mem_vec_16400 ,mem_vec_16401 ,mem_vec_16402 ,mem_vec_16403 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 17) (34 / 2)
for (x1545 = x1546, x1545_p_0 = 0;
	x1545 < x1546 + 34;
	x1545 += 2, x1545_p_0 += 2){
	// y = 34, x = 2, h = 1, w = 1, c = 512, f = 256
	// T (c, 8) (512 / 64)
	for (c1158 = c1159, c1158_p_0 = 0;
		c1158 < c1159 + 512;
		c1158 += 64, c1158_p_0 += 64){
		// y = 34, x = 2, h = 1, w = 1, c = 64, f = 256
		// T (f, 4) (256 / 64)
		for (f = f772, fp_0 = 0;
			f < f772 + 256;
			f += 64, fp_0 += 64){
				for (y = y772, yp_0 = 0;
					y < y772 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 64
					// T (x, 2) (2 / 1)
					for (x1544 = x1545, x1544_p_1 = x1545_p_0, x1544_p_0 = 0;
						x1544 < x1545 + 2;
						x1544 += 1, x1544_p_1 += 1, x1544_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1544, xp_2 = x1544_p_1, xp_1 = x1544_p_0, xp_0 = 0;
							x < x1544 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_16352 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_16353 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_16354 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_16355 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_16356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_16357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_16358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_16359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_16360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_16361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_16362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_16363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_16364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_16365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_16366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_16367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_16368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_16369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_16370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_16371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_16372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_16373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_16374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_16375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c1158, cp_1 = c1158_p_0, cp_0 = 0;
										c < c1158 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_16352);
										mem_vec_16352 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_16353);
										mem_vec_16353 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_16354);
										mem_vec_16354 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_16355);
										mem_vec_16355 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_16356);
										mem_vec_16356 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_16357);
										mem_vec_16357 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_16358);
										mem_vec_16358 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_16359);
										mem_vec_16359 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_16360);
										mem_vec_16360 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_16361);
										mem_vec_16361 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_16362);
										mem_vec_16362 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_16363);
										mem_vec_16363 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_16364);
										mem_vec_16364 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_16365);
										mem_vec_16365 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_16366);
										mem_vec_16366 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_16367);
										mem_vec_16367 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_16368);
										mem_vec_16368 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_16369);
										mem_vec_16369 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_16370);
										mem_vec_16370 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_16371);
										mem_vec_16371 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_16372);
										mem_vec_16372 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_16373);
										mem_vec_16373 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_16374);
										mem_vec_16374 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_16375);
										mem_vec_16375 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16352);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_16353);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_16354);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_16355);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_16356);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_16357);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_16358);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_16359);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_16360);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_16361);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_16362);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_16363);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_16364);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_16365);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_16366);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_16367);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_16368);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_16369);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_16370);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_16371);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_16372);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_16373);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_16374);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_16375);
						}
					}
				}
				for (y = y772 + 6, yp_0 = 0;
					y < y772 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 64
					// T (x, 2) (2 / 1)
					for (x1544 = x1545, x1544_p_1 = x1545_p_0, x1544_p_0 = 0;
						x1544 < x1545 + 2;
						x1544 += 1, x1544_p_1 += 1, x1544_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1544, xp_2 = x1544_p_1, xp_1 = x1544_p_0, xp_0 = 0;
							x < x1544 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_16376 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_16377 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_16378 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_16379 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_16380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_16381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_16382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_16383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_16384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_16385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_16386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_16387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_16388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_16389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_16390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_16391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_16392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_16393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_16394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_16395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_16396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_16397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_16398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_16399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_16400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_16401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_16402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_16403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c1158, cp_1 = c1158_p_0, cp_0 = 0;
										c < c1158 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_16376);
										mem_vec_16376 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_16377);
										mem_vec_16377 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_16378);
										mem_vec_16378 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_16379);
										mem_vec_16379 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_16380);
										mem_vec_16380 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_16381);
										mem_vec_16381 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_16382);
										mem_vec_16382 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_16383);
										mem_vec_16383 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_16384);
										mem_vec_16384 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_16385);
										mem_vec_16385 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_16386);
										mem_vec_16386 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_16387);
										mem_vec_16387 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_16388);
										mem_vec_16388 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_16389);
										mem_vec_16389 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_16390);
										mem_vec_16390 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_16391);
										mem_vec_16391 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_16392);
										mem_vec_16392 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_16393);
										mem_vec_16393 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_16394);
										mem_vec_16394 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_16395);
										mem_vec_16395 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_16396);
										mem_vec_16396 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_16397);
										mem_vec_16397 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_16398);
										mem_vec_16398 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_16399);
										mem_vec_16399 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_16400);
										mem_vec_16400 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_16401);
										mem_vec_16401 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_16402);
										mem_vec_16402 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_16403);
										mem_vec_16403 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16376);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_16377);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_16378);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_16379);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_16380);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_16381);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_16382);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_16383);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_16384);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_16385);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_16386);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_16387);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_16388);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_16389);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_16390);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_16391);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_16392);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_16393);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_16394);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_16395);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_16396);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_16397);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_16398);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_16399);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_16400);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_16401);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_16402);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_16403);
						}
					}
				}
		}
	}
}


}