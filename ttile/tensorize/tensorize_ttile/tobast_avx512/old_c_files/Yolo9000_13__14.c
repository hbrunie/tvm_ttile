#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (17, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (2, c); T (2, x)]
*/
IND_TYPE c, cp_0, c1098_p_0, cp_1, c1098, f, fp_0, x, xp_0, x1464_p_0, x1465_p_0, xp_1, x1464_p_1, xp_2, x1464, x1465, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y732 = 0;
IND_TYPE x1466 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1099 = 0;
IND_TYPE f732 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_15312 ,mem_vec_15313 ,mem_vec_15314 ,mem_vec_15315 ,mem_vec_15316 ,mem_vec_15317 ,mem_vec_15318 ,mem_vec_15319 ,mem_vec_15320 ,mem_vec_15321 ,mem_vec_15322 ,mem_vec_15323 ,mem_vec_15324 ,mem_vec_15325 ,mem_vec_15326 ,mem_vec_15327 ,mem_vec_15328 ,mem_vec_15329 ,mem_vec_15330 ,mem_vec_15331 ,mem_vec_15332 ,mem_vec_15333 ,mem_vec_15334 ,mem_vec_15335 ,mem_vec_15336 ,mem_vec_15337 ,mem_vec_15338 ,mem_vec_15339 ,mem_vec_15340 ,mem_vec_15341 ,mem_vec_15342 ,mem_vec_15343 ,mem_vec_15344 ,mem_vec_15345 ,mem_vec_15346 ,mem_vec_15347 ,mem_vec_15348 ,mem_vec_15349 ,mem_vec_15350 ,mem_vec_15351 ,mem_vec_15352 ,mem_vec_15353 ,mem_vec_15354 ,mem_vec_15355 ,mem_vec_15356 ,mem_vec_15357 ,mem_vec_15358 ,mem_vec_15359 ,mem_vec_15360 ,mem_vec_15361 ,mem_vec_15362 ,mem_vec_15363 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 2) (34 / 17)
for (x1465 = x1466, x1465_p_0 = 0;
	x1465 < x1466 + 34;
	x1465 += 17, x1465_p_0 += 17){
	// y = 34, x = 17, h = 1, w = 1, c = 512, f = 256
	// T (c, 2) (512 / 256)
	for (c1098 = c1099, c1098_p_0 = 0;
		c1098 < c1099 + 512;
		c1098 += 256, c1098_p_0 += 256){
		// y = 34, x = 17, h = 1, w = 1, c = 256, f = 256
		// T (f, 4) (256 / 64)
		for (f = f732, fp_0 = 0;
			f < f732 + 256;
			f += 64, fp_0 += 64){
				for (y = y732, yp_0 = 0;
					y < y732 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (x, 1) (17 / 17)
					for (x1464 = x1465, x1464_p_1 = x1465_p_0, x1464_p_0 = 0;
						x1464 < x1465 + 17;
						x1464 += 17, x1464_p_1 += 17, x1464_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (x, 17) (17 / 1)
						for (x = x1464, xp_2 = x1464_p_1, xp_1 = x1464_p_0, xp_0 = 0;
							x < x1464 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15312 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_15313 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_15314 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_15315 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_15316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_15317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_15318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_15319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_15320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_15321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_15322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_15323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_15324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_15325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_15326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_15327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_15328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_15329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_15330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_15331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_15332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_15333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_15334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_15335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c1098, cp_1 = c1098_p_0, cp_0 = 0;
										c < c1098 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15312);
										mem_vec_15312 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15313);
										mem_vec_15313 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_15314);
										mem_vec_15314 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_15315);
										mem_vec_15315 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_15316);
										mem_vec_15316 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_15317);
										mem_vec_15317 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_15318);
										mem_vec_15318 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_15319);
										mem_vec_15319 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15320);
										mem_vec_15320 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15321);
										mem_vec_15321 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_15322);
										mem_vec_15322 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_15323);
										mem_vec_15323 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_15324);
										mem_vec_15324 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_15325);
										mem_vec_15325 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_15326);
										mem_vec_15326 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_15327);
										mem_vec_15327 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_15328);
										mem_vec_15328 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_15329);
										mem_vec_15329 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_15330);
										mem_vec_15330 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_15331);
										mem_vec_15331 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15332);
										mem_vec_15332 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15333);
										mem_vec_15333 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_15334);
										mem_vec_15334 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_15335);
										mem_vec_15335 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15312);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15313);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_15314);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_15315);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15316);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15317);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_15318);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_15319);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15320);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15321);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_15322);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_15323);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15324);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15325);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_15326);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_15327);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15328);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15329);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_15330);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_15331);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15332);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15333);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_15334);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_15335);
						}
					}
				}
				for (y = y732 + 6, yp_0 = 0;
					y < y732 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (x, 1) (17 / 17)
					for (x1464 = x1465, x1464_p_1 = x1465_p_0, x1464_p_0 = 0;
						x1464 < x1465 + 17;
						x1464 += 17, x1464_p_1 += 17, x1464_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (x, 17) (17 / 1)
						for (x = x1464, xp_2 = x1464_p_1, xp_1 = x1464_p_0, xp_0 = 0;
							x < x1464 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15336 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_15337 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_15338 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_15339 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_15340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_15341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_15342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_15343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_15344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_15345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_15346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_15347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_15348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_15349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_15350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_15351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_15352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_15353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_15354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_15355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_15356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_15357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_15358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_15359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_15360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_15361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_15362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_15363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c1098, cp_1 = c1098_p_0, cp_0 = 0;
										c < c1098 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15336);
										mem_vec_15336 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15337);
										mem_vec_15337 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_15338);
										mem_vec_15338 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_15339);
										mem_vec_15339 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_15340);
										mem_vec_15340 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_15341);
										mem_vec_15341 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_15342);
										mem_vec_15342 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_15343);
										mem_vec_15343 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15344);
										mem_vec_15344 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15345);
										mem_vec_15345 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_15346);
										mem_vec_15346 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_15347);
										mem_vec_15347 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_15348);
										mem_vec_15348 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_15349);
										mem_vec_15349 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_15350);
										mem_vec_15350 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_15351);
										mem_vec_15351 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_15352);
										mem_vec_15352 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_15353);
										mem_vec_15353 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_15354);
										mem_vec_15354 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_15355);
										mem_vec_15355 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15356);
										mem_vec_15356 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15357);
										mem_vec_15357 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_15358);
										mem_vec_15358 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_15359);
										mem_vec_15359 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_15360);
										mem_vec_15360 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_15361);
										mem_vec_15361 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_15362);
										mem_vec_15362 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_15363);
										mem_vec_15363 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15336);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15337);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_15338);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_15339);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15340);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15341);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_15342);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_15343);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15344);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15345);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_15346);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_15347);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15348);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15349);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_15350);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_15351);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15352);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15353);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_15354);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_15355);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15356);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15357);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_15358);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_15359);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_15360);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_15361);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_15362);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_15363);
						}
					}
				}
		}
	}
}


}