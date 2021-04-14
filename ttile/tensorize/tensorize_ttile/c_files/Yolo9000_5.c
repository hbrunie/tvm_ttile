#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x); T (136, x);
  Lambda_apply y [((Iter 6), (Arg 11)); ((Iter 5), (Arg 14))]; T (2, f);
  T (1, x)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x936_p_0, x937_p_0, xp_1, x936_p_1, xp_2, x936, x937, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y468 = 0;
IND_TYPE x938 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c468 = 0;
IND_TYPE f468 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9276 ,mem_vec_9277 ,mem_vec_9278 ,mem_vec_9279 ,mem_vec_9280 ,mem_vec_9281 ,mem_vec_9282 ,mem_vec_9283 ,mem_vec_9284 ,mem_vec_9285 ,mem_vec_9286 ,mem_vec_9287 ,mem_vec_9288 ,mem_vec_9289 ,mem_vec_9290 ,mem_vec_9291 ,mem_vec_9292 ,mem_vec_9293 ,mem_vec_9294 ,mem_vec_9295 ,mem_vec_9296 ,mem_vec_9297 ,mem_vec_9298 ,mem_vec_9299 ,mem_vec_9300 ,mem_vec_9301 ,mem_vec_9302 ,mem_vec_9303 ,mem_vec_9304 ,mem_vec_9305 ,mem_vec_9306 ,mem_vec_9307 ,mem_vec_9308 ,mem_vec_9309 ,mem_vec_9310 ,mem_vec_9311 ,mem_vec_9312 ,mem_vec_9313 ,mem_vec_9314 ,mem_vec_9315 ,mem_vec_9316 ,mem_vec_9317 ,mem_vec_9318 ,mem_vec_9319 ,mem_vec_9320 ,mem_vec_9321 ,mem_vec_9322 ,mem_vec_9323 ,mem_vec_9324 ,mem_vec_9325 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 1) (136 / 136)
for (x937 = x938, x937_p_0 = 0;
	x937 < x938 + 136;
	x937 += 136, x937_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (f, 2) (64 / 32)
	for (f = f468, fp_0 = 0;
		f < f468 + 64;
		f += 32, fp_0 += 32){
			for (y = y468, yp_0 = 0;
				y < y468 + 66;
				y += 11, yp_0 += 11){
				// y = ph_y, x = 136, h = 1, w = 1, c = 128, f = 32
				// T (x, 136) (136 / 1)
				for (x936 = x937, x936_p_1 = x937_p_0, x936_p_0 = 0;
					x936 < x937 + 136;
					x936 += 1, x936_p_1 += 1, x936_p_0 += 1){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (x, 1) (1 / 1)
					for (x = x936, xp_2 = x936_p_1, xp_1 = x936_p_0, xp_0 = 0;
						x < x936 + 1;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_9276 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_9277 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_9278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_9279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_9280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_9281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_9282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_9283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_9284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_9285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_9286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_9287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_9288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_9289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_9290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_9291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_9292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_9293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_9294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_9295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_9296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_9297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c468, cp_0 = 0;
									c < c468 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9276);
									mem_vec_9276 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9277);
									mem_vec_9277 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9278);
									mem_vec_9278 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9279);
									mem_vec_9279 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9280);
									mem_vec_9280 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9281);
									mem_vec_9281 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9282);
									mem_vec_9282 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9283);
									mem_vec_9283 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9284);
									mem_vec_9284 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9285);
									mem_vec_9285 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9286);
									mem_vec_9286 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9287);
									mem_vec_9287 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9288);
									mem_vec_9288 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9289);
									mem_vec_9289 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9290);
									mem_vec_9290 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9291);
									mem_vec_9291 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9292);
									mem_vec_9292 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9293);
									mem_vec_9293 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9294);
									mem_vec_9294 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9295);
									mem_vec_9295 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9296);
									mem_vec_9296 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9297);
									mem_vec_9297 = vec_34;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9276);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9277);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9278);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9279);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9280);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9281);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9282);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9283);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9284);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9285);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9286);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9287);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9288);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9289);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9290);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9291);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9292);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9293);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9294);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9295);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9296);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9297);
					}
				}
			}
			for (y = y468 + 66, yp_0 = 0;
				y < y468 + 66 + 70;
				y += 14, yp_0 += 14){
				// y = ph_y, x = 136, h = 1, w = 1, c = 128, f = 32
				// T (x, 136) (136 / 1)
				for (x936 = x937, x936_p_1 = x937_p_0, x936_p_0 = 0;
					x936 < x937 + 136;
					x936 += 1, x936_p_1 += 1, x936_p_0 += 1){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (x, 1) (1 / 1)
					for (x = x936, xp_2 = x936_p_1, xp_1 = x936_p_0, xp_0 = 0;
						x < x936 + 1;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_9298 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_9299 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_9300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_9301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_9302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_9303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_9304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_9305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_9306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_9307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_9308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_9309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_9310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_9311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_9312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_9313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_9314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_9315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_9316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_9317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_9318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_9319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								mem_vec_9320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
								mem_vec_9321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
								mem_vec_9322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
								mem_vec_9323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
								mem_vec_9324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
								mem_vec_9325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c468, cp_0 = 0;
									c < c468 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9298);
									mem_vec_9298 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9299);
									mem_vec_9299 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9300);
									mem_vec_9300 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9301);
									mem_vec_9301 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9302);
									mem_vec_9302 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9303);
									mem_vec_9303 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9304);
									mem_vec_9304 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9305);
									mem_vec_9305 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9306);
									mem_vec_9306 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9307);
									mem_vec_9307 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9308);
									mem_vec_9308 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9309);
									mem_vec_9309 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9310);
									mem_vec_9310 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9311);
									mem_vec_9311 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9312);
									mem_vec_9312 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9313);
									mem_vec_9313 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9314);
									mem_vec_9314 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9315);
									mem_vec_9315 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9316);
									mem_vec_9316 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9317);
									mem_vec_9317 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9318);
									mem_vec_9318 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9319);
									mem_vec_9319 = vec_34;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9320);
									mem_vec_9320 = vec_35;



									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9321);
									mem_vec_9321 = vec_37;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
									vec_39 = _mm512_set1_ps(scal_12);


									vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_9322);
									mem_vec_9322 = vec_38;



									vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_9323);
									mem_vec_9323 = vec_40;
									scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
									vec_42 = _mm512_set1_ps(scal_13);


									vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_9324);
									mem_vec_9324 = vec_41;



									vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_9325);
									mem_vec_9325 = vec_43;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9298);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9299);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9300);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9301);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9302);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9303);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9304);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9305);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9306);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9307);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9308);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9309);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9310);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9311);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9312);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9313);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9314);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9315);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9316);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9317);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9318);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9319);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9320);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9321);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_9322);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_9323);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_9324);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_9325);
					}
				}
			}
	}
}


}