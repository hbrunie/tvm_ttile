#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x); T (4, y);
  T (1, c); T (68, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]]
*/
IND_TYPE c, cp_0, c230_p_0, cp_1, c230, x, xp_0, x306_p_0, xp_1, x306, y, yp_0, y306_p_0, yp_1, y306;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y307 = 0;
IND_TYPE x307 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c231 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_4266 ,mem_vec_4267 ,mem_vec_4268 ,mem_vec_4269 ,mem_vec_4270 ,mem_vec_4271 ,mem_vec_4272 ,mem_vec_4273 ,mem_vec_4274 ,mem_vec_4275 ,mem_vec_4276 ,mem_vec_4277 ,mem_vec_4278 ,mem_vec_4279 ,mem_vec_4280 ,mem_vec_4281 ,mem_vec_4282 ,mem_vec_4283 ,mem_vec_4284 ,mem_vec_4285 ,mem_vec_4286 ,mem_vec_4287 ,mem_vec_4288 ,mem_vec_4289 ,mem_vec_4290 ,mem_vec_4291 ,mem_vec_4292 ,mem_vec_4293 ,mem_vec_4294 ,mem_vec_4295 ,mem_vec_4296 ,mem_vec_4297 ,mem_vec_4298 ,mem_vec_4299 ,mem_vec_4300 ,mem_vec_4301 ,mem_vec_4302 ,mem_vec_4303 ,mem_vec_4304 ,mem_vec_4305 ,mem_vec_4306 ,mem_vec_4307 ,mem_vec_4308 ,mem_vec_4309 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y306 = y307, y306_p_0 = 0;
		y306 < y307 + 80;
		y306 += 16, y306_p_0 += 16){
		// y = 4 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x306 = x307, x306_p_0 = 0;
			x306 < x307 + 136;
			x306 += 2, x306_p_0 += 2){
			// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c230 = c231, c230_p_0 = 0;
				c230 < c231 + 128;
				c230 += 128, c230_p_0 += 128){
				// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (y, 4) (4 * ph_y / ph_y)
				for (y = y306, yp_1 = y306_p_0, yp_0 = 0;
					y < y306 + 16;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (x, 2) (2 / 1)
					for (x = x306, xp_1 = x306_p_0, xp_0 = 0;
						x < x306 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_4266 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_4267 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_4268 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_4269 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_4270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_4271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_4272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_4273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_4274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_4275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_4276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_4277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_4278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_4279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_4280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_4281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c230, cp_1 = c230_p_0, cp_0 = 0;
									c < c230 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4266);
									mem_vec_4266 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4267);
									mem_vec_4267 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4268);
									mem_vec_4268 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4269);
									mem_vec_4269 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4270);
									mem_vec_4270 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4271);
									mem_vec_4271 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4272);
									mem_vec_4272 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4273);
									mem_vec_4273 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4274);
									mem_vec_4274 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4275);
									mem_vec_4275 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4276);
									mem_vec_4276 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4277);
									mem_vec_4277 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4278);
									mem_vec_4278 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4279);
									mem_vec_4279 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4280);
									mem_vec_4280 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4281);
									mem_vec_4281 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4266);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4267);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4268);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4269);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4270);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4271);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4272);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4273);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4274);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4275);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4276);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4277);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4278);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4279);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4280);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4281);
					}
				}
			}
		}
	}
	for (y306 = y307 + 80, y306_p_0 = 0;
		y306 < y307 + 80 + 56;
		y306 += 28, y306_p_0 += 28){
		// y = 4 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x306 = x307, x306_p_0 = 0;
			x306 < x307 + 136;
			x306 += 2, x306_p_0 += 2){
			// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c230 = c231, c230_p_0 = 0;
				c230 < c231 + 128;
				c230 += 128, c230_p_0 += 128){
				// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (y, 4) (4 * ph_y / ph_y)
				for (y = y306, yp_1 = y306_p_0, yp_0 = 0;
					y < y306 + 28;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (x, 2) (2 / 1)
					for (x = x306, xp_1 = x306_p_0, xp_0 = 0;
						x < x306 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_4282 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_4283 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_4284 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_4285 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_4286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_4287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_4288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_4289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_4290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_4291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_4292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_4293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_4294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_4295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_4296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_4297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_4298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_4299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_4300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_4301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_4302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_4303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_4304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_4305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								mem_vec_4306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_4307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_4308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
								mem_vec_4309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c230, cp_1 = c230_p_0, cp_0 = 0;
									c < c230 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4282);
									mem_vec_4282 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4283);
									mem_vec_4283 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4284);
									mem_vec_4284 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4285);
									mem_vec_4285 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4286);
									mem_vec_4286 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4287);
									mem_vec_4287 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4288);
									mem_vec_4288 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4289);
									mem_vec_4289 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4290);
									mem_vec_4290 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4291);
									mem_vec_4291 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4292);
									mem_vec_4292 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4293);
									mem_vec_4293 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4294);
									mem_vec_4294 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4295);
									mem_vec_4295 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4296);
									mem_vec_4296 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4297);
									mem_vec_4297 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_4298);
									mem_vec_4298 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_4299);
									mem_vec_4299 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_4300);
									mem_vec_4300 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_4301);
									mem_vec_4301 = vec_28;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4302);
									mem_vec_4302 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4303);
									mem_vec_4303 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_4304);
									mem_vec_4304 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_4305);
									mem_vec_4305 = vec_33;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_35 = _mm512_set1_ps(scal_6);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_4306);
									mem_vec_4306 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_4307);
									mem_vec_4307 = vec_36;



									vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_4308);
									mem_vec_4308 = vec_37;



									vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_4309);
									mem_vec_4309 = vec_38;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4282);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4283);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4284);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4285);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4286);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4287);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4288);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4289);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4290);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4291);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4292);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4293);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4294);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4295);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4296);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4297);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4298);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4299);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_4300);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_4301);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4302);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4303);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_4304);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_4305);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4306);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4307);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_4308);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_4309);
					}
				}
			}
		}
	}


}