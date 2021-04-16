#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 3), (Arg 9))]; T (2, f);
  T (68, x); T (4, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x315_p_0, xp_1, x315, y, yp_0, y315_p_0, yp_1, y315;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y316 = 0;
IND_TYPE x316 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c238 = 0;
IND_TYPE f182 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_4386 ,mem_vec_4387 ,mem_vec_4388 ,mem_vec_4389 ,mem_vec_4390 ,mem_vec_4391 ,mem_vec_4392 ,mem_vec_4393 ,mem_vec_4394 ,mem_vec_4395 ,mem_vec_4396 ,mem_vec_4397 ,mem_vec_4398 ,mem_vec_4399 ,mem_vec_4400 ,mem_vec_4401 ,mem_vec_4402 ,mem_vec_4403 ,mem_vec_4404 ,mem_vec_4405 ,mem_vec_4406 ,mem_vec_4407 ,mem_vec_4408 ,mem_vec_4409 ,mem_vec_4410 ,mem_vec_4411 ,mem_vec_4412 ,mem_vec_4413 ,mem_vec_4414 ,mem_vec_4415 ,mem_vec_4416 ,mem_vec_4417 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 4) (136 / 34)
for (y315 = y316, y315_p_0 = 0;
	y315 < y316 + 136;
	y315 += 34, y315_p_0 += 34){
	// y = 34, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 68) (136 / 2)
	for (x315 = x316, x315_p_0 = 0;
		x315 < x316 + 136;
		x315 += 2, x315_p_0 += 2){
		// y = 34, x = 2, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f182, fp_0 = 0;
			f < f182 + 64;
			f += 32, fp_0 += 32){
				for (y = y315, yp_1 = y315_p_0, yp_0 = 0;
					y < y315 + 7;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x315, xp_1 = x315_p_0, xp_0 = 0;
						x < x315 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_4386 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_4387 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_4388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_4389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_4390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_4391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_4392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_4393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_4394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_4395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_4396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_4397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_4398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_4399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c238, cp_0 = 0;
									c < c238 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4386);
									mem_vec_4386 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4387);
									mem_vec_4387 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4388);
									mem_vec_4388 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4389);
									mem_vec_4389 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4390);
									mem_vec_4390 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4391);
									mem_vec_4391 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4392);
									mem_vec_4392 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4393);
									mem_vec_4393 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4394);
									mem_vec_4394 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4395);
									mem_vec_4395 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4396);
									mem_vec_4396 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4397);
									mem_vec_4397 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4398);
									mem_vec_4398 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4399);
									mem_vec_4399 = vec_22;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4386);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4387);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4388);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4389);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4390);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4391);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4392);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4393);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4394);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4395);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4396);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4397);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4398);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4399);
					}
				}
				for (y = y315 + 7, yp_1 = y315_p_0, yp_0 = 0;
					y < y315 + 7 + 27;
					y += 9, yp_1 += 9, yp_0 += 9){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x315, xp_1 = x315_p_0, xp_0 = 0;
						x < x315 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_4400 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_4401 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_4402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_4403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_4404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_4405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_4406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_4407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_4408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_4409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_4410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_4411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_4412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_4413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_4414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_4415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_4416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_4417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c238, cp_0 = 0;
									c < c238 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4400);
									mem_vec_4400 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4401);
									mem_vec_4401 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4402);
									mem_vec_4402 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4403);
									mem_vec_4403 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4404);
									mem_vec_4404 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4405);
									mem_vec_4405 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4406);
									mem_vec_4406 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4407);
									mem_vec_4407 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4408);
									mem_vec_4408 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4409);
									mem_vec_4409 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4410);
									mem_vec_4410 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4411);
									mem_vec_4411 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4412);
									mem_vec_4412 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4413);
									mem_vec_4413 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4414);
									mem_vec_4414 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4415);
									mem_vec_4415 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4416);
									mem_vec_4416 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4417);
									mem_vec_4417 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4400);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4401);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4402);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4403);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4404);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4405);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4406);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4407);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4408);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4409);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4410);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4411);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4412);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4413);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4414);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4415);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4416);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4417);
					}
				}
		}
	}
}


}