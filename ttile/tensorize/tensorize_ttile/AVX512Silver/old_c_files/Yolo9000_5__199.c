#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (4, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (1, c);
  T (34, x); T (4, y)]
*/
IND_TYPE c, cp_0, c284_p_0, cp_1, c284, x, xp_0, x384_p_0, xp_1, x384, y, yp_0, y384_p_0, yp_1, y384;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y385 = 0;
IND_TYPE x385 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c285 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_5326 ,mem_vec_5327 ,mem_vec_5328 ,mem_vec_5329 ,mem_vec_5330 ,mem_vec_5331 ,mem_vec_5332 ,mem_vec_5333 ,mem_vec_5334 ,mem_vec_5335 ,mem_vec_5336 ,mem_vec_5337 ,mem_vec_5338 ,mem_vec_5339 ,mem_vec_5340 ,mem_vec_5341 ,mem_vec_5342 ,mem_vec_5343 ,mem_vec_5344 ,mem_vec_5345 ,mem_vec_5346 ,mem_vec_5347 ,mem_vec_5348 ,mem_vec_5349 ,mem_vec_5350 ,mem_vec_5351 ,mem_vec_5352 ,mem_vec_5353 ,mem_vec_5354 ,mem_vec_5355 ,mem_vec_5356 ,mem_vec_5357 ,mem_vec_5358 ,mem_vec_5359 ,mem_vec_5360 ,mem_vec_5361 ,mem_vec_5362 ,mem_vec_5363 ,mem_vec_5364 ,mem_vec_5365 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 4) (136 / 34)
for (y384 = y385, y384_p_0 = 0;
	y384 < y385 + 136;
	y384 += 34, y384_p_0 += 34){
	// y = 34, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 34) (136 / 4)
	for (x384 = x385, x384_p_0 = 0;
		x384 < x385 + 136;
		x384 += 4, x384_p_0 += 4){
		// y = 34, x = 4, h = 1, w = 1, c = 128, f = 64
		// T (c, 1) (128 / 128)
		for (c284 = c285, c284_p_0 = 0;
			c284 < c285 + 128;
			c284 += 128, c284_p_0 += 128){
				for (y = y384, yp_1 = y384_p_0, yp_0 = 0;
					y < y384 + 4;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 64
					// T (x, 4) (4 / 1)
					for (x = x384, xp_1 = x384_p_0, xp_0 = 0;
						x < x384 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_5326 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_5327 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_5328 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_5329 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_5330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_5331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_5332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_5333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_5334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_5335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_5336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_5337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_5338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_5339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_5340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_5341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c284, cp_1 = c284_p_0, cp_0 = 0;
									c < c284 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5326);
									mem_vec_5326 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5327);
									mem_vec_5327 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5328);
									mem_vec_5328 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5329);
									mem_vec_5329 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5330);
									mem_vec_5330 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5331);
									mem_vec_5331 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5332);
									mem_vec_5332 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5333);
									mem_vec_5333 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5334);
									mem_vec_5334 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5335);
									mem_vec_5335 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5336);
									mem_vec_5336 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5337);
									mem_vec_5337 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5338);
									mem_vec_5338 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5339);
									mem_vec_5339 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5340);
									mem_vec_5340 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5341);
									mem_vec_5341 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5326);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5327);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5328);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5329);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5330);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5331);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5332);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5333);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5334);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5335);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5336);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5337);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5338);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5339);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5340);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5341);
					}
				}
				for (y = y384 + 4, yp_1 = y384_p_0, yp_0 = 0;
					y < y384 + 4 + 30;
					y += 6, yp_1 += 6, yp_0 += 6){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 64
					// T (x, 4) (4 / 1)
					for (x = x384, xp_1 = x384_p_0, xp_0 = 0;
						x < x384 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_5342 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_5343 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_5344 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_5345 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_5346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_5347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_5348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_5349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_5350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_5351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_5352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_5353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_5354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_5355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_5356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_5357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_5358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_5359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_5360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_5361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_5362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_5363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_5364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_5365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c284, cp_1 = c284_p_0, cp_0 = 0;
									c < c284 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5342);
									mem_vec_5342 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5343);
									mem_vec_5343 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5344);
									mem_vec_5344 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5345);
									mem_vec_5345 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5346);
									mem_vec_5346 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5347);
									mem_vec_5347 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5348);
									mem_vec_5348 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5349);
									mem_vec_5349 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5350);
									mem_vec_5350 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5351);
									mem_vec_5351 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5352);
									mem_vec_5352 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5353);
									mem_vec_5353 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5354);
									mem_vec_5354 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5355);
									mem_vec_5355 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5356);
									mem_vec_5356 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5357);
									mem_vec_5357 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5358);
									mem_vec_5358 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5359);
									mem_vec_5359 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5360);
									mem_vec_5360 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5361);
									mem_vec_5361 = vec_28;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5362);
									mem_vec_5362 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5363);
									mem_vec_5363 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5364);
									mem_vec_5364 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5365);
									mem_vec_5365 = vec_33;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5342);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5343);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5344);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5345);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5346);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5347);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5348);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5349);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5350);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5351);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5352);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5353);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5354);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5355);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5356);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5357);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5358);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5359);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5360);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5361);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5362);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5363);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_5364);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_5365);
					}
				}
		}
	}
}


}