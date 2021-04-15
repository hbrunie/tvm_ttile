#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (8, f); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (256, c)]
*/
IND_TYPE c, cp_0, c1224_p_0, c1225_p_0, cp_1, c1224_p_1, cp_2, c1224, c1225, f, fp_0, x, xp_0, x918_p_0, xp_1, x918, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y612 = 0;
IND_TYPE x919 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1226 = 0;
IND_TYPE f612 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_10320 ,mem_vec_10321 ,mem_vec_10322 ,mem_vec_10323 ,mem_vec_10324 ,mem_vec_10325 ,mem_vec_10326 ,mem_vec_10327 ,mem_vec_10328 ,mem_vec_10329 ,mem_vec_10330 ,mem_vec_10331 ,mem_vec_10332 ,mem_vec_10333 ,mem_vec_10334 ,mem_vec_10335 ,mem_vec_10336 ,mem_vec_10337 ,mem_vec_10338 ,mem_vec_10339 ,mem_vec_10340 ,mem_vec_10341 ,mem_vec_10342 ,mem_vec_10343 ,mem_vec_10344 ,mem_vec_10345 ,mem_vec_10346 ,mem_vec_10347 ,mem_vec_10348 ,mem_vec_10349 ,mem_vec_10350 ,mem_vec_10351 ,mem_vec_10352 ,mem_vec_10353 ,mem_vec_10354 ,mem_vec_10355 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 256) (1024 / 4)
for (c1225 = c1226, c1225_p_0 = 0;
	c1225 < c1226 + 1024;
	c1225 += 4, c1225_p_0 += 4){
		for (y = y612, yp_0 = 0;
			y < y612 + 12;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 512
			// T (x, 17) (17 / 1)
			for (x918 = x919, x918_p_0 = 0;
				x918 < x919 + 17;
				x918 += 1, x918_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 512
				// T (f, 8) (512 / 64)
				for (f = f612, fp_0 = 0;
					f < f612 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
					// T (c, 2) (4 / 2)
					for (c1224 = c1225, c1224_p_1 = c1225_p_0, c1224_p_0 = 0;
						c1224 < c1225 + 4;
						c1224 += 2, c1224_p_1 += 2, c1224_p_0 += 2){
						// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
						// T (x, 1) (1 / 1)
						for (x = x918, xp_1 = x918_p_0, xp_0 = 0;
							x < x918 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10320 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10321 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10322 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10323 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1224, cp_2 = c1224_p_1, cp_1 = c1224_p_0, cp_0 = 0;
										c < c1224 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10320);
										mem_vec_10320 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10321);
										mem_vec_10321 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10322);
										mem_vec_10322 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10323);
										mem_vec_10323 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10324);
										mem_vec_10324 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10325);
										mem_vec_10325 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10326);
										mem_vec_10326 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10327);
										mem_vec_10327 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10328);
										mem_vec_10328 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10329);
										mem_vec_10329 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10330);
										mem_vec_10330 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10331);
										mem_vec_10331 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10332);
										mem_vec_10332 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10333);
										mem_vec_10333 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10334);
										mem_vec_10334 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10335);
										mem_vec_10335 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10320);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10321);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10322);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10323);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10324);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10325);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10326);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10327);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10328);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10329);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10330);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10331);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10332);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10333);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10334);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10335);
						}
					}
				}
			}
		}
		for (y = y612 + 12, yp_0 = 0;
			y < y612 + 12 + 5;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 512
			// T (x, 17) (17 / 1)
			for (x918 = x919, x918_p_0 = 0;
				x918 < x919 + 17;
				x918 += 1, x918_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 512
				// T (f, 8) (512 / 64)
				for (f = f612, fp_0 = 0;
					f < f612 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
					// T (c, 2) (4 / 2)
					for (c1224 = c1225, c1224_p_1 = c1225_p_0, c1224_p_0 = 0;
						c1224 < c1225 + 4;
						c1224 += 2, c1224_p_1 += 2, c1224_p_0 += 2){
						// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
						// T (x, 1) (1 / 1)
						for (x = x918, xp_1 = x918_p_0, xp_0 = 0;
							x < x918 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10336 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10337 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10338 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10339 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_10352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_10355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1224, cp_2 = c1224_p_1, cp_1 = c1224_p_0, cp_0 = 0;
										c < c1224 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10336);
										mem_vec_10336 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10337);
										mem_vec_10337 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10338);
										mem_vec_10338 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10339);
										mem_vec_10339 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10340);
										mem_vec_10340 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10341);
										mem_vec_10341 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10342);
										mem_vec_10342 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10343);
										mem_vec_10343 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10344);
										mem_vec_10344 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10345);
										mem_vec_10345 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10346);
										mem_vec_10346 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10347);
										mem_vec_10347 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10348);
										mem_vec_10348 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10349);
										mem_vec_10349 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10350);
										mem_vec_10350 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10351);
										mem_vec_10351 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10352);
										mem_vec_10352 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10353);
										mem_vec_10353 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10354);
										mem_vec_10354 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10355);
										mem_vec_10355 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10336);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10337);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10338);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10339);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10340);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10341);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10342);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10343);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10344);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10345);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10346);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10347);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10348);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10349);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10350);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10351);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10352);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10353);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10354);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10355);
						}
					}
				}
			}
		}
}


}