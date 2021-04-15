#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (1, x); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 12)); ((Iter 4), (Arg 14))]; T (4, f);
  T (256, c); T (34, x)]
*/
IND_TYPE c, cp_0, c1080_p_0, cp_1, c1080, f, fp_0, x, xp_0, x1440_p_0, x1441_p_0, xp_1, x1440_p_1, xp_2, x1440, x1441, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y720 = 0;
IND_TYPE x1442 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1081 = 0;
IND_TYPE f720 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14288 ,mem_vec_14289 ,mem_vec_14290 ,mem_vec_14291 ,mem_vec_14292 ,mem_vec_14293 ,mem_vec_14294 ,mem_vec_14295 ,mem_vec_14296 ,mem_vec_14297 ,mem_vec_14298 ,mem_vec_14299 ,mem_vec_14300 ,mem_vec_14301 ,mem_vec_14302 ,mem_vec_14303 ,mem_vec_14304 ,mem_vec_14305 ,mem_vec_14306 ,mem_vec_14307 ,mem_vec_14308 ,mem_vec_14309 ,mem_vec_14310 ,mem_vec_14311 ,mem_vec_14312 ,mem_vec_14313 ,mem_vec_14314 ,mem_vec_14315 ,mem_vec_14316 ,mem_vec_14317 ,mem_vec_14318 ,mem_vec_14319 ,mem_vec_14320 ,mem_vec_14321 ,mem_vec_14322 ,mem_vec_14323 ,mem_vec_14324 ,mem_vec_14325 ,mem_vec_14326 ,mem_vec_14327 ,mem_vec_14328 ,mem_vec_14329 ,mem_vec_14330 ,mem_vec_14331 ,mem_vec_14332 ,mem_vec_14333 ,mem_vec_14334 ,mem_vec_14335 ,mem_vec_14336 ,mem_vec_14337 ,mem_vec_14338 ,mem_vec_14339 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 34) (68 / 2)
for (x1441 = x1442, x1441_p_0 = 0;
	x1441 < x1442 + 68;
	x1441 += 2, x1441_p_0 += 2){
	// y = 68, x = 2, h = 1, w = 1, c = 256, f = 128
	// T (c, 256) (256 / 1)
	for (c1080 = c1081, c1080_p_0 = 0;
		c1080 < c1081 + 256;
		c1080 += 1, c1080_p_0 += 1){
		// y = 68, x = 2, h = 1, w = 1, c = 1, f = 128
		// T (f, 4) (128 / 32)
		for (f = f720, fp_0 = 0;
			f < f720 + 128;
			f += 32, fp_0 += 32){
				for (y = y720, yp_0 = 0;
					y < y720 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 2, h = 1, w = 1, c = 1, f = 32
					// T (x, 2) (2 / 1)
					for (x1440 = x1441, x1440_p_1 = x1441_p_0, x1440_p_0 = 0;
						x1440 < x1441 + 2;
						x1440 += 1, x1440_p_1 += 1, x1440_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1440, xp_2 = x1440_p_1, xp_1 = x1440_p_0, xp_0 = 0;
							x < x1440 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14288 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14289 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_14301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_14302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_14303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_14304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_14305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_14306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_14307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_14308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_14309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_14310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_14311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c1080, cp_1 = c1080_p_0, cp_0 = 0;
										c < c1080 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14288);
										mem_vec_14288 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14289);
										mem_vec_14289 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14290);
										mem_vec_14290 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14291);
										mem_vec_14291 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14292);
										mem_vec_14292 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14293);
										mem_vec_14293 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14294);
										mem_vec_14294 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14295);
										mem_vec_14295 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14296);
										mem_vec_14296 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14297);
										mem_vec_14297 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14298);
										mem_vec_14298 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14299);
										mem_vec_14299 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14300);
										mem_vec_14300 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14301);
										mem_vec_14301 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14302);
										mem_vec_14302 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14303);
										mem_vec_14303 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14304);
										mem_vec_14304 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14305);
										mem_vec_14305 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14306);
										mem_vec_14306 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14307);
										mem_vec_14307 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_14308);
										mem_vec_14308 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_14309);
										mem_vec_14309 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_14310);
										mem_vec_14310 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_14311);
										mem_vec_14311 = vec_37;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14288);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14289);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14290);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14291);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14292);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14293);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14294);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14295);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14296);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14297);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14298);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14299);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14300);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14301);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14302);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14303);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14304);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14305);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14306);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14307);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_14308);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_14309);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_14310);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_14311);
						}
					}
				}
				for (y = y720 + 12, yp_0 = 0;
					y < y720 + 12 + 56;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 2, h = 1, w = 1, c = 1, f = 32
					// T (x, 2) (2 / 1)
					for (x1440 = x1441, x1440_p_1 = x1441_p_0, x1440_p_0 = 0;
						x1440 < x1441 + 2;
						x1440 += 1, x1440_p_1 += 1, x1440_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1440, xp_2 = x1440_p_1, xp_1 = x1440_p_0, xp_0 = 0;
							x < x1440 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14312 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14313 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_14325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_14326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_14327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_14328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_14329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_14330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_14331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_14332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_14333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_14334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_14335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_14336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_14337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_14338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_14339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c1080, cp_1 = c1080_p_0, cp_0 = 0;
										c < c1080 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14312);
										mem_vec_14312 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14313);
										mem_vec_14313 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14314);
										mem_vec_14314 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14315);
										mem_vec_14315 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14316);
										mem_vec_14316 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14317);
										mem_vec_14317 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14318);
										mem_vec_14318 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14319);
										mem_vec_14319 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14320);
										mem_vec_14320 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14321);
										mem_vec_14321 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14322);
										mem_vec_14322 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14323);
										mem_vec_14323 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14324);
										mem_vec_14324 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14325);
										mem_vec_14325 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14326);
										mem_vec_14326 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14327);
										mem_vec_14327 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14328);
										mem_vec_14328 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14329);
										mem_vec_14329 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14330);
										mem_vec_14330 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14331);
										mem_vec_14331 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_14332);
										mem_vec_14332 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_14333);
										mem_vec_14333 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_14334);
										mem_vec_14334 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_14335);
										mem_vec_14335 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_14336);
										mem_vec_14336 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_14337);
										mem_vec_14337 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_14338);
										mem_vec_14338 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_14339);
										mem_vec_14339 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14312);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14313);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14314);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14315);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14316);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14317);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14318);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14319);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14320);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14321);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14322);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14323);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14324);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14325);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14326);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14327);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14328);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14329);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14330);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14331);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_14332);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_14333);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_14334);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_14335);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_14336);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_14337);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_14338);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_14339);
						}
					}
				}
		}
	}
}


}