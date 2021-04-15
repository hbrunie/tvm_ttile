#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (4, x); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))]; T (4, f);
  T (256, c); T (17, x)]
*/
IND_TYPE c, cp_0, c774_p_0, cp_1, c774, f, fp_0, x, xp_0, x1032_p_0, x1033_p_0, xp_1, x1032_p_1, xp_2, x1032, x1033, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y516 = 0;
IND_TYPE x1034 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c775 = 0;
IND_TYPE f516 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9400 ,mem_vec_9401 ,mem_vec_9402 ,mem_vec_9403 ,mem_vec_9404 ,mem_vec_9405 ,mem_vec_9406 ,mem_vec_9407 ,mem_vec_9408 ,mem_vec_9409 ,mem_vec_9410 ,mem_vec_9411 ,mem_vec_9412 ,mem_vec_9413 ,mem_vec_9414 ,mem_vec_9415 ,mem_vec_9416 ,mem_vec_9417 ,mem_vec_9418 ,mem_vec_9419 ,mem_vec_9420 ,mem_vec_9421 ,mem_vec_9422 ,mem_vec_9423 ,mem_vec_9424 ,mem_vec_9425 ,mem_vec_9426 ,mem_vec_9427 ,mem_vec_9428 ,mem_vec_9429 ,mem_vec_9430 ,mem_vec_9431 ,mem_vec_9432 ,mem_vec_9433 ,mem_vec_9434 ,mem_vec_9435 ,mem_vec_9436 ,mem_vec_9437 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 17) (68 / 4)
for (x1033 = x1034, x1033_p_0 = 0;
	x1033 < x1034 + 68;
	x1033 += 4, x1033_p_0 += 4){
	// y = 68, x = 4, h = 1, w = 1, c = 256, f = 128
	// T (c, 256) (256 / 1)
	for (c774 = c775, c774_p_0 = 0;
		c774 < c775 + 256;
		c774 += 1, c774_p_0 += 1){
		// y = 68, x = 4, h = 1, w = 1, c = 1, f = 128
		// T (f, 4) (128 / 32)
		for (f = f516, fp_0 = 0;
			f < f516 + 128;
			f += 32, fp_0 += 32){
				for (y = y516, yp_0 = 0;
					y < y516 + 18;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 4, h = 1, w = 1, c = 1, f = 32
					// T (x, 1) (4 / 4)
					for (x1032 = x1033, x1032_p_1 = x1033_p_0, x1032_p_0 = 0;
						x1032 < x1033 + 4;
						x1032 += 4, x1032_p_1 += 4, x1032_p_0 += 4){
						// y = ph_y, x = 4, h = 1, w = 1, c = 1, f = 32
						// T (x, 4) (4 / 1)
						for (x = x1032, xp_2 = x1032_p_1, xp_1 = x1032_p_0, xp_0 = 0;
							x < x1032 + 4;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9400 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9401 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_9409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_9410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_9411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_9412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_9413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_9414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_9415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_9416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_9417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c774, cp_1 = c774_p_0, cp_0 = 0;
										c < c774 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9400);
										mem_vec_9400 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9401);
										mem_vec_9401 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9402);
										mem_vec_9402 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9403);
										mem_vec_9403 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9404);
										mem_vec_9404 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9405);
										mem_vec_9405 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9406);
										mem_vec_9406 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9407);
										mem_vec_9407 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9408);
										mem_vec_9408 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9409);
										mem_vec_9409 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9410);
										mem_vec_9410 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9411);
										mem_vec_9411 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9412);
										mem_vec_9412 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9413);
										mem_vec_9413 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9414);
										mem_vec_9414 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9415);
										mem_vec_9415 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9416);
										mem_vec_9416 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9417);
										mem_vec_9417 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9400);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9401);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9402);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9403);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9404);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9405);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9406);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9407);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9408);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9409);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9410);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9411);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9412);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9413);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9414);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9415);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9416);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9417);
						}
					}
				}
				for (y = y516 + 18, yp_0 = 0;
					y < y516 + 18 + 50;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 4, h = 1, w = 1, c = 1, f = 32
					// T (x, 1) (4 / 4)
					for (x1032 = x1033, x1032_p_1 = x1033_p_0, x1032_p_0 = 0;
						x1032 < x1033 + 4;
						x1032 += 4, x1032_p_1 += 4, x1032_p_0 += 4){
						// y = ph_y, x = 4, h = 1, w = 1, c = 1, f = 32
						// T (x, 4) (4 / 1)
						for (x = x1032, xp_2 = x1032_p_1, xp_1 = x1032_p_0, xp_0 = 0;
							x < x1032 + 4;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9418 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9419 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_9427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_9428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_9429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_9430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_9431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_9432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_9433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_9434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_9435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_9436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_9437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c774, cp_1 = c774_p_0, cp_0 = 0;
										c < c774 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9418);
										mem_vec_9418 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9419);
										mem_vec_9419 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9420);
										mem_vec_9420 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9421);
										mem_vec_9421 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9422);
										mem_vec_9422 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9423);
										mem_vec_9423 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9424);
										mem_vec_9424 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9425);
										mem_vec_9425 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9426);
										mem_vec_9426 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9427);
										mem_vec_9427 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9428);
										mem_vec_9428 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9429);
										mem_vec_9429 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9430);
										mem_vec_9430 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9431);
										mem_vec_9431 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9432);
										mem_vec_9432 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9433);
										mem_vec_9433 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9434);
										mem_vec_9434 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9435);
										mem_vec_9435 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9436);
										mem_vec_9436 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9437);
										mem_vec_9437 = vec_31;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9418);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9419);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9420);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9421);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9422);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9423);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9424);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9425);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9426);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9427);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9428);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9429);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9430);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9431);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9432);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9433);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9434);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9435);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9436);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9437);
						}
					}
				}
		}
	}
}


}