#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (17, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))]; T (4, f);
  T (64, c); T (4, x)]
*/
IND_TYPE c, cp_0, c762_p_0, cp_1, c762, f, fp_0, x, xp_0, x1016_p_0, x1017_p_0, xp_1, x1016_p_1, xp_2, x1016, x1017, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y508 = 0;
IND_TYPE x1018 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c763 = 0;
IND_TYPE f508 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9248 ,mem_vec_9249 ,mem_vec_9250 ,mem_vec_9251 ,mem_vec_9252 ,mem_vec_9253 ,mem_vec_9254 ,mem_vec_9255 ,mem_vec_9256 ,mem_vec_9257 ,mem_vec_9258 ,mem_vec_9259 ,mem_vec_9260 ,mem_vec_9261 ,mem_vec_9262 ,mem_vec_9263 ,mem_vec_9264 ,mem_vec_9265 ,mem_vec_9266 ,mem_vec_9267 ,mem_vec_9268 ,mem_vec_9269 ,mem_vec_9270 ,mem_vec_9271 ,mem_vec_9272 ,mem_vec_9273 ,mem_vec_9274 ,mem_vec_9275 ,mem_vec_9276 ,mem_vec_9277 ,mem_vec_9278 ,mem_vec_9279 ,mem_vec_9280 ,mem_vec_9281 ,mem_vec_9282 ,mem_vec_9283 ,mem_vec_9284 ,mem_vec_9285 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 4) (68 / 17)
for (x1017 = x1018, x1017_p_0 = 0;
	x1017 < x1018 + 68;
	x1017 += 17, x1017_p_0 += 17){
	// y = 68, x = 17, h = 1, w = 1, c = 256, f = 128
	// T (c, 64) (256 / 4)
	for (c762 = c763, c762_p_0 = 0;
		c762 < c763 + 256;
		c762 += 4, c762_p_0 += 4){
		// y = 68, x = 17, h = 1, w = 1, c = 4, f = 128
		// T (f, 4) (128 / 32)
		for (f = f508, fp_0 = 0;
			f < f508 + 128;
			f += 32, fp_0 += 32){
				for (y = y508, yp_0 = 0;
					y < y508 + 18;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
					// T (x, 17) (17 / 1)
					for (x1016 = x1017, x1016_p_1 = x1017_p_0, x1016_p_0 = 0;
						x1016 < x1017 + 17;
						x1016 += 1, x1016_p_1 += 1, x1016_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1016, xp_2 = x1016_p_1, xp_1 = x1016_p_0, xp_0 = 0;
							x < x1016 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9248 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9249 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_9257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_9258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_9259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_9260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_9261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_9262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_9263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_9264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_9265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c762, cp_1 = c762_p_0, cp_0 = 0;
										c < c762 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9248);
										mem_vec_9248 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9249);
										mem_vec_9249 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9250);
										mem_vec_9250 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9251);
										mem_vec_9251 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9252);
										mem_vec_9252 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9253);
										mem_vec_9253 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9254);
										mem_vec_9254 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9255);
										mem_vec_9255 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9256);
										mem_vec_9256 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9257);
										mem_vec_9257 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9258);
										mem_vec_9258 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9259);
										mem_vec_9259 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9260);
										mem_vec_9260 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9261);
										mem_vec_9261 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9262);
										mem_vec_9262 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9263);
										mem_vec_9263 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9264);
										mem_vec_9264 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9265);
										mem_vec_9265 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9248);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9249);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9250);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9251);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9252);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9253);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9254);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9255);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9256);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9257);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9258);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9259);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9260);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9261);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9262);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9263);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9264);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9265);
						}
					}
				}
				for (y = y508 + 18, yp_0 = 0;
					y < y508 + 18 + 50;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
					// T (x, 17) (17 / 1)
					for (x1016 = x1017, x1016_p_1 = x1017_p_0, x1016_p_0 = 0;
						x1016 < x1017 + 17;
						x1016 += 1, x1016_p_1 += 1, x1016_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1016, xp_2 = x1016_p_1, xp_1 = x1016_p_0, xp_0 = 0;
							x < x1016 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9266 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9267 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_9275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_9276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_9277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_9278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_9279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_9280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_9281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_9282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_9283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_9284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_9285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c762, cp_1 = c762_p_0, cp_0 = 0;
										c < c762 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9266);
										mem_vec_9266 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9267);
										mem_vec_9267 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9268);
										mem_vec_9268 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9269);
										mem_vec_9269 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9270);
										mem_vec_9270 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9271);
										mem_vec_9271 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9272);
										mem_vec_9272 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9273);
										mem_vec_9273 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9274);
										mem_vec_9274 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9275);
										mem_vec_9275 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9276);
										mem_vec_9276 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9277);
										mem_vec_9277 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9278);
										mem_vec_9278 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9279);
										mem_vec_9279 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9280);
										mem_vec_9280 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9281);
										mem_vec_9281 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9282);
										mem_vec_9282 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9283);
										mem_vec_9283 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9284);
										mem_vec_9284 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9285);
										mem_vec_9285 = vec_31;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9266);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9267);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9268);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9269);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9270);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9271);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9272);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9273);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9274);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9275);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9276);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9277);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9278);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9279);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9280);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9281);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9282);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9283);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9284);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9285);
						}
					}
				}
		}
	}
}


}