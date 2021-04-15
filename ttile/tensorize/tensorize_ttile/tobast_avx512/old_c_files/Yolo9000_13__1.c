#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (2, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (512, c); T (17, x)]
*/
IND_TYPE c, cp_0, c1152_p_0, cp_1, c1152, f, fp_0, x, xp_0, x1536_p_0, x1537_p_0, xp_1, x1536_p_1, xp_2, x1536, x1537, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y768 = 0;
IND_TYPE x1538 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1153 = 0;
IND_TYPE f768 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_16248 ,mem_vec_16249 ,mem_vec_16250 ,mem_vec_16251 ,mem_vec_16252 ,mem_vec_16253 ,mem_vec_16254 ,mem_vec_16255 ,mem_vec_16256 ,mem_vec_16257 ,mem_vec_16258 ,mem_vec_16259 ,mem_vec_16260 ,mem_vec_16261 ,mem_vec_16262 ,mem_vec_16263 ,mem_vec_16264 ,mem_vec_16265 ,mem_vec_16266 ,mem_vec_16267 ,mem_vec_16268 ,mem_vec_16269 ,mem_vec_16270 ,mem_vec_16271 ,mem_vec_16272 ,mem_vec_16273 ,mem_vec_16274 ,mem_vec_16275 ,mem_vec_16276 ,mem_vec_16277 ,mem_vec_16278 ,mem_vec_16279 ,mem_vec_16280 ,mem_vec_16281 ,mem_vec_16282 ,mem_vec_16283 ,mem_vec_16284 ,mem_vec_16285 ,mem_vec_16286 ,mem_vec_16287 ,mem_vec_16288 ,mem_vec_16289 ,mem_vec_16290 ,mem_vec_16291 ,mem_vec_16292 ,mem_vec_16293 ,mem_vec_16294 ,mem_vec_16295 ,mem_vec_16296 ,mem_vec_16297 ,mem_vec_16298 ,mem_vec_16299 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 17) (34 / 2)
for (x1537 = x1538, x1537_p_0 = 0;
	x1537 < x1538 + 34;
	x1537 += 2, x1537_p_0 += 2){
	// y = 34, x = 2, h = 1, w = 1, c = 512, f = 256
	// T (c, 512) (512 / 1)
	for (c1152 = c1153, c1152_p_0 = 0;
		c1152 < c1153 + 512;
		c1152 += 1, c1152_p_0 += 1){
		// y = 34, x = 2, h = 1, w = 1, c = 1, f = 256
		// T (f, 4) (256 / 64)
		for (f = f768, fp_0 = 0;
			f < f768 + 256;
			f += 64, fp_0 += 64){
				for (y = y768, yp_0 = 0;
					y < y768 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 2, h = 1, w = 1, c = 1, f = 64
					// T (x, 1) (2 / 2)
					for (x1536 = x1537, x1536_p_1 = x1537_p_0, x1536_p_0 = 0;
						x1536 < x1537 + 2;
						x1536 += 2, x1536_p_1 += 2, x1536_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 1, f = 64
						// T (x, 2) (2 / 1)
						for (x = x1536, xp_2 = x1536_p_1, xp_1 = x1536_p_0, xp_0 = 0;
							x < x1536 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_16248 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_16249 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_16250 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_16251 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_16252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_16253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_16254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_16255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_16256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_16257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_16258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_16259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_16260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_16261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_16262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_16263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_16264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_16265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_16266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_16267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_16268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_16269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_16270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_16271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c1152, cp_1 = c1152_p_0, cp_0 = 0;
										c < c1152 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_16248);
										mem_vec_16248 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_16249);
										mem_vec_16249 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_16250);
										mem_vec_16250 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_16251);
										mem_vec_16251 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_16252);
										mem_vec_16252 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_16253);
										mem_vec_16253 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_16254);
										mem_vec_16254 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_16255);
										mem_vec_16255 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_16256);
										mem_vec_16256 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_16257);
										mem_vec_16257 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_16258);
										mem_vec_16258 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_16259);
										mem_vec_16259 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_16260);
										mem_vec_16260 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_16261);
										mem_vec_16261 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_16262);
										mem_vec_16262 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_16263);
										mem_vec_16263 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_16264);
										mem_vec_16264 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_16265);
										mem_vec_16265 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_16266);
										mem_vec_16266 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_16267);
										mem_vec_16267 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_16268);
										mem_vec_16268 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_16269);
										mem_vec_16269 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_16270);
										mem_vec_16270 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_16271);
										mem_vec_16271 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16248);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_16249);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_16250);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_16251);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_16252);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_16253);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_16254);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_16255);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_16256);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_16257);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_16258);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_16259);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_16260);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_16261);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_16262);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_16263);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_16264);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_16265);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_16266);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_16267);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_16268);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_16269);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_16270);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_16271);
						}
					}
				}
				for (y = y768 + 6, yp_0 = 0;
					y < y768 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 2, h = 1, w = 1, c = 1, f = 64
					// T (x, 1) (2 / 2)
					for (x1536 = x1537, x1536_p_1 = x1537_p_0, x1536_p_0 = 0;
						x1536 < x1537 + 2;
						x1536 += 2, x1536_p_1 += 2, x1536_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 1, f = 64
						// T (x, 2) (2 / 1)
						for (x = x1536, xp_2 = x1536_p_1, xp_1 = x1536_p_0, xp_0 = 0;
							x < x1536 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_16272 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_16273 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_16274 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_16275 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_16276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_16277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_16278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_16279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_16280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_16281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_16282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_16283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_16284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_16285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_16286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_16287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_16288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_16289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_16290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_16291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_16292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_16293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_16294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_16295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_16296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_16297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_16298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_16299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c1152, cp_1 = c1152_p_0, cp_0 = 0;
										c < c1152 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_16272);
										mem_vec_16272 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_16273);
										mem_vec_16273 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_16274);
										mem_vec_16274 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_16275);
										mem_vec_16275 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_16276);
										mem_vec_16276 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_16277);
										mem_vec_16277 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_16278);
										mem_vec_16278 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_16279);
										mem_vec_16279 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_16280);
										mem_vec_16280 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_16281);
										mem_vec_16281 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_16282);
										mem_vec_16282 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_16283);
										mem_vec_16283 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_16284);
										mem_vec_16284 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_16285);
										mem_vec_16285 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_16286);
										mem_vec_16286 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_16287);
										mem_vec_16287 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_16288);
										mem_vec_16288 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_16289);
										mem_vec_16289 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_16290);
										mem_vec_16290 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_16291);
										mem_vec_16291 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_16292);
										mem_vec_16292 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_16293);
										mem_vec_16293 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_16294);
										mem_vec_16294 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_16295);
										mem_vec_16295 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_16296);
										mem_vec_16296 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_16297);
										mem_vec_16297 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_16298);
										mem_vec_16298 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_16299);
										mem_vec_16299 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16272);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_16273);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_16274);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_16275);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_16276);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_16277);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_16278);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_16279);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_16280);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_16281);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_16282);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_16283);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_16284);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_16285);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_16286);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_16287);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_16288);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_16289);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_16290);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_16291);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_16292);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_16293);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_16294);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_16295);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_16296);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_16297);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_16298);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_16299);
						}
					}
				}
		}
	}
}


}