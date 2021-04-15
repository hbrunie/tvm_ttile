#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (1, x); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 4), (Arg 15))]; T (4, f);
  T (256, c); T (34, x)]
*/
IND_TYPE c, cp_0, c690_p_0, cp_1, c690, f, fp_0, x, xp_0, x920_p_0, x921_p_0, xp_1, x920_p_1, xp_2, x920, x921, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y460 = 0;
IND_TYPE x922 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c691 = 0;
IND_TYPE f460 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8272 ,mem_vec_8273 ,mem_vec_8274 ,mem_vec_8275 ,mem_vec_8276 ,mem_vec_8277 ,mem_vec_8278 ,mem_vec_8279 ,mem_vec_8280 ,mem_vec_8281 ,mem_vec_8282 ,mem_vec_8283 ,mem_vec_8284 ,mem_vec_8285 ,mem_vec_8286 ,mem_vec_8287 ,mem_vec_8288 ,mem_vec_8289 ,mem_vec_8290 ,mem_vec_8291 ,mem_vec_8292 ,mem_vec_8293 ,mem_vec_8294 ,mem_vec_8295 ,mem_vec_8296 ,mem_vec_8297 ,mem_vec_8298 ,mem_vec_8299 ,mem_vec_8300 ,mem_vec_8301 ,mem_vec_8302 ,mem_vec_8303 ,mem_vec_8304 ,mem_vec_8305 ,mem_vec_8306 ,mem_vec_8307 ,mem_vec_8308 ,mem_vec_8309 ,mem_vec_8310 ,mem_vec_8311 ,mem_vec_8312 ,mem_vec_8313 ,mem_vec_8314 ,mem_vec_8315 ,mem_vec_8316 ,mem_vec_8317 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 34) (68 / 2)
for (x921 = x922, x921_p_0 = 0;
	x921 < x922 + 68;
	x921 += 2, x921_p_0 += 2){
	// y = 68, x = 2, h = 1, w = 1, c = 256, f = 128
	// T (c, 256) (256 / 1)
	for (c690 = c691, c690_p_0 = 0;
		c690 < c691 + 256;
		c690 += 1, c690_p_0 += 1){
		// y = 68, x = 2, h = 1, w = 1, c = 1, f = 128
		// T (f, 4) (128 / 32)
		for (f = f460, fp_0 = 0;
			f < f460 + 128;
			f += 32, fp_0 += 32){
				for (y = y460, yp_0 = 0;
					y < y460 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 2, h = 1, w = 1, c = 1, f = 32
					// T (x, 2) (2 / 1)
					for (x920 = x921, x920_p_1 = x921_p_0, x920_p_0 = 0;
						x920 < x921 + 2;
						x920 += 1, x920_p_1 += 1, x920_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
						// T (x, 1) (1 / 1)
						for (x = x920, xp_2 = x920_p_1, xp_1 = x920_p_0, xp_0 = 0;
							x < x920 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8272 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8273 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_8274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_8276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_8278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_8279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_8280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_8281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_8282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_8283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_8284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_8285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_8286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_8287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c690, cp_1 = c690_p_0, cp_0 = 0;
										c < c690 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8272);
										mem_vec_8272 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8273);
										mem_vec_8273 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8274);
										mem_vec_8274 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8275);
										mem_vec_8275 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8276);
										mem_vec_8276 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8277);
										mem_vec_8277 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8278);
										mem_vec_8278 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8279);
										mem_vec_8279 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8280);
										mem_vec_8280 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8281);
										mem_vec_8281 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8282);
										mem_vec_8282 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8283);
										mem_vec_8283 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8284);
										mem_vec_8284 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8285);
										mem_vec_8285 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8286);
										mem_vec_8286 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8287);
										mem_vec_8287 = vec_25;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8272);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8273);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8274);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8275);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8276);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8277);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8278);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8279);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8280);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8281);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8282);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8283);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8284);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8285);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8286);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8287);
						}
					}
				}
				for (y = y460 + 8, yp_0 = 0;
					y < y460 + 8 + 60;
					y += 15, yp_0 += 15){
					// y = ph_y, x = 2, h = 1, w = 1, c = 1, f = 32
					// T (x, 2) (2 / 1)
					for (x920 = x921, x920_p_1 = x921_p_0, x920_p_0 = 0;
						x920 < x921 + 2;
						x920 += 1, x920_p_1 += 1, x920_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
						// T (x, 1) (1 / 1)
						for (x = x920, xp_2 = x920_p_1, xp_1 = x920_p_0, xp_0 = 0;
							x < x920 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8288 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8289 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_8290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_8292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_8294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_8295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_8296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_8297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_8298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_8299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_8300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_8301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_8302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_8303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_8304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_8305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_8306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_8307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_8308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_8309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_8310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_8311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_8312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_8313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_8314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_8315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									mem_vec_8316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
									mem_vec_8317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c690, cp_1 = c690_p_0, cp_0 = 0;
										c < c690 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8288);
										mem_vec_8288 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8289);
										mem_vec_8289 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8290);
										mem_vec_8290 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8291);
										mem_vec_8291 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8292);
										mem_vec_8292 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8293);
										mem_vec_8293 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8294);
										mem_vec_8294 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8295);
										mem_vec_8295 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8296);
										mem_vec_8296 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8297);
										mem_vec_8297 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8298);
										mem_vec_8298 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8299);
										mem_vec_8299 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8300);
										mem_vec_8300 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8301);
										mem_vec_8301 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8302);
										mem_vec_8302 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8303);
										mem_vec_8303 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8304);
										mem_vec_8304 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8305);
										mem_vec_8305 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8306);
										mem_vec_8306 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8307);
										mem_vec_8307 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8308);
										mem_vec_8308 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8309);
										mem_vec_8309 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8310);
										mem_vec_8310 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8311);
										mem_vec_8311 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8312);
										mem_vec_8312 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8313);
										mem_vec_8313 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_8314);
										mem_vec_8314 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_8315);
										mem_vec_8315 = vec_43;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
										vec_45 = _mm512_set1_ps(scal_14);


										vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_8316);
										mem_vec_8316 = vec_44;



										vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_8317);
										mem_vec_8317 = vec_46;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8288);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8289);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8290);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8291);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8292);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8293);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8294);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8295);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8296);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8297);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8298);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8299);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8300);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8301);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8302);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8303);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8304);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8305);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8306);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8307);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8308);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8309);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8310);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8311);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_8312);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_8313);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_8314);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_8315);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_8316);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_8317);
						}
					}
				}
		}
	}
}


}