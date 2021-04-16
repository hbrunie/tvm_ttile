#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (4, x); T (4, y);
  T (1, c); T (34, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]]
*/
IND_TYPE c, cp_0, c227_p_0, cp_1, c227, x, xp_0, x303_p_0, xp_1, x303, y, yp_0, y303_p_0, yp_1, y303;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y304 = 0;
IND_TYPE x304 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c228 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_4222 ,mem_vec_4223 ,mem_vec_4224 ,mem_vec_4225 ,mem_vec_4226 ,mem_vec_4227 ,mem_vec_4228 ,mem_vec_4229 ,mem_vec_4230 ,mem_vec_4231 ,mem_vec_4232 ,mem_vec_4233 ,mem_vec_4234 ,mem_vec_4235 ,mem_vec_4236 ,mem_vec_4237 ,mem_vec_4238 ,mem_vec_4239 ,mem_vec_4240 ,mem_vec_4241 ,mem_vec_4242 ,mem_vec_4243 ,mem_vec_4244 ,mem_vec_4245 ,mem_vec_4246 ,mem_vec_4247 ,mem_vec_4248 ,mem_vec_4249 ,mem_vec_4250 ,mem_vec_4251 ,mem_vec_4252 ,mem_vec_4253 ,mem_vec_4254 ,mem_vec_4255 ,mem_vec_4256 ,mem_vec_4257 ,mem_vec_4258 ,mem_vec_4259 ,mem_vec_4260 ,mem_vec_4261 ,mem_vec_4262 ,mem_vec_4263 ,mem_vec_4264 ,mem_vec_4265 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y303 = y304, y303_p_0 = 0;
		y303 < y304 + 80;
		y303 += 16, y303_p_0 += 16){
		// y = 4 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 34) (136 / 4)
		for (x303 = x304, x303_p_0 = 0;
			x303 < x304 + 136;
			x303 += 4, x303_p_0 += 4){
			// y = 4 * ph_y, x = 4, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c227 = c228, c227_p_0 = 0;
				c227 < c228 + 128;
				c227 += 128, c227_p_0 += 128){
				// y = 4 * ph_y, x = 4, h = 1, w = 1, c = 128, f = 64
				// T (y, 4) (4 * ph_y / ph_y)
				for (y = y303, yp_1 = y303_p_0, yp_0 = 0;
					y < y303 + 16;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 64
					// T (x, 4) (4 / 1)
					for (x = x303, xp_1 = x303_p_0, xp_0 = 0;
						x < x303 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_4222 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_4223 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_4224 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_4225 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_4226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_4227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_4228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_4229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_4230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_4231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_4232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_4233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_4234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_4235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_4236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_4237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c227, cp_1 = c227_p_0, cp_0 = 0;
									c < c227 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4222);
									mem_vec_4222 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4223);
									mem_vec_4223 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4224);
									mem_vec_4224 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4225);
									mem_vec_4225 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4226);
									mem_vec_4226 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4227);
									mem_vec_4227 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4228);
									mem_vec_4228 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4229);
									mem_vec_4229 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4230);
									mem_vec_4230 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4231);
									mem_vec_4231 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4232);
									mem_vec_4232 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4233);
									mem_vec_4233 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4234);
									mem_vec_4234 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4235);
									mem_vec_4235 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4236);
									mem_vec_4236 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4237);
									mem_vec_4237 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4222);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4223);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4224);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4225);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4226);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4227);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4228);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4229);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4230);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4231);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4232);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4233);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4234);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4235);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4236);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4237);
					}
				}
			}
		}
	}
	for (y303 = y304 + 80, y303_p_0 = 0;
		y303 < y304 + 80 + 56;
		y303 += 28, y303_p_0 += 28){
		// y = 4 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 34) (136 / 4)
		for (x303 = x304, x303_p_0 = 0;
			x303 < x304 + 136;
			x303 += 4, x303_p_0 += 4){
			// y = 4 * ph_y, x = 4, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c227 = c228, c227_p_0 = 0;
				c227 < c228 + 128;
				c227 += 128, c227_p_0 += 128){
				// y = 4 * ph_y, x = 4, h = 1, w = 1, c = 128, f = 64
				// T (y, 4) (4 * ph_y / ph_y)
				for (y = y303, yp_1 = y303_p_0, yp_0 = 0;
					y < y303 + 28;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 64
					// T (x, 4) (4 / 1)
					for (x = x303, xp_1 = x303_p_0, xp_0 = 0;
						x < x303 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_4238 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_4239 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_4240 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_4241 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_4242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_4243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_4244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_4245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_4246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_4247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_4248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_4249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_4250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_4251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_4252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_4253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_4254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_4255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_4256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_4257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_4258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_4259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_4260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_4261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								mem_vec_4262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_4263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_4264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
								mem_vec_4265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c227, cp_1 = c227_p_0, cp_0 = 0;
									c < c227 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4238);
									mem_vec_4238 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4239);
									mem_vec_4239 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4240);
									mem_vec_4240 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4241);
									mem_vec_4241 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4242);
									mem_vec_4242 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4243);
									mem_vec_4243 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4244);
									mem_vec_4244 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4245);
									mem_vec_4245 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4246);
									mem_vec_4246 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4247);
									mem_vec_4247 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4248);
									mem_vec_4248 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4249);
									mem_vec_4249 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4250);
									mem_vec_4250 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4251);
									mem_vec_4251 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4252);
									mem_vec_4252 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4253);
									mem_vec_4253 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_4254);
									mem_vec_4254 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_4255);
									mem_vec_4255 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_4256);
									mem_vec_4256 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_4257);
									mem_vec_4257 = vec_28;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4258);
									mem_vec_4258 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4259);
									mem_vec_4259 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_4260);
									mem_vec_4260 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_4261);
									mem_vec_4261 = vec_33;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_35 = _mm512_set1_ps(scal_6);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_4262);
									mem_vec_4262 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_4263);
									mem_vec_4263 = vec_36;



									vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_4264);
									mem_vec_4264 = vec_37;



									vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_4265);
									mem_vec_4265 = vec_38;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4238);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4239);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4240);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4241);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4242);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4243);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4244);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4245);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4246);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4247);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4248);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4249);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4250);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4251);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4252);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4253);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4254);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4255);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_4256);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_4257);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4258);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4259);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_4260);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_4261);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4262);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4263);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_4264);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_4265);
					}
				}
			}
		}
	}


}