#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x);
  Lambda_apply y [((Iter 5), (Arg 11)); ((Iter 1), (Arg 13))]; T (2, f);
  T (68, x); T (2, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x234_p_0, xp_1, x234, y, yp_0, y234_p_0, yp_1, y234;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y235 = 0;
IND_TYPE x235 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c178 = 0;
IND_TYPE f134 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3200 ,mem_vec_3201 ,mem_vec_3202 ,mem_vec_3203 ,mem_vec_3204 ,mem_vec_3205 ,mem_vec_3206 ,mem_vec_3207 ,mem_vec_3208 ,mem_vec_3209 ,mem_vec_3210 ,mem_vec_3211 ,mem_vec_3212 ,mem_vec_3213 ,mem_vec_3214 ,mem_vec_3215 ,mem_vec_3216 ,mem_vec_3217 ,mem_vec_3218 ,mem_vec_3219 ,mem_vec_3220 ,mem_vec_3221 ,mem_vec_3222 ,mem_vec_3223 ,mem_vec_3224 ,mem_vec_3225 ,mem_vec_3226 ,mem_vec_3227 ,mem_vec_3228 ,mem_vec_3229 ,mem_vec_3230 ,mem_vec_3231 ,mem_vec_3232 ,mem_vec_3233 ,mem_vec_3234 ,mem_vec_3235 ,mem_vec_3236 ,mem_vec_3237 ,mem_vec_3238 ,mem_vec_3239 ,mem_vec_3240 ,mem_vec_3241 ,mem_vec_3242 ,mem_vec_3243 ,mem_vec_3244 ,mem_vec_3245 ,mem_vec_3246 ,mem_vec_3247 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 2) (136 / 68)
for (y234 = y235, y234_p_0 = 0;
	y234 < y235 + 136;
	y234 += 68, y234_p_0 += 68){
	// y = 68, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 68) (136 / 2)
	for (x234 = x235, x234_p_0 = 0;
		x234 < x235 + 136;
		x234 += 2, x234_p_0 += 2){
		// y = 68, x = 2, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f134, fp_0 = 0;
			f < f134 + 64;
			f += 32, fp_0 += 32){
				for (y = y234, yp_1 = y234_p_0, yp_0 = 0;
					y < y234 + 55;
					y += 11, yp_1 += 11, yp_0 += 11){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x234, xp_1 = x234_p_0, xp_0 = 0;
						x < x234 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_3200 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_3201 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_3202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_3203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_3204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_3205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_3206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_3207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_3208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_3209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_3210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_3211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_3212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_3213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_3214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_3215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_3216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_3217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_3218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_3219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_3220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_3221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c178, cp_0 = 0;
									c < c178 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3200);
									mem_vec_3200 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3201);
									mem_vec_3201 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3202);
									mem_vec_3202 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3203);
									mem_vec_3203 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3204);
									mem_vec_3204 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3205);
									mem_vec_3205 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3206);
									mem_vec_3206 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3207);
									mem_vec_3207 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3208);
									mem_vec_3208 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3209);
									mem_vec_3209 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3210);
									mem_vec_3210 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3211);
									mem_vec_3211 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3212);
									mem_vec_3212 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3213);
									mem_vec_3213 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3214);
									mem_vec_3214 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3215);
									mem_vec_3215 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3216);
									mem_vec_3216 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3217);
									mem_vec_3217 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3218);
									mem_vec_3218 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3219);
									mem_vec_3219 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3220);
									mem_vec_3220 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3221);
									mem_vec_3221 = vec_34;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3200);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3201);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3202);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3203);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3204);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3205);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3206);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3207);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3208);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3209);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3210);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3211);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3212);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3213);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3214);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3215);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3216);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3217);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3218);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3219);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3220);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3221);
					}
				}
				for (y = y234 + 55, yp_1 = y234_p_0, yp_0 = 0;
					y < y234 + 55 + 13;
					y += 13, yp_1 += 13, yp_0 += 13){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x234, xp_1 = x234_p_0, xp_0 = 0;
						x < x234 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_3222 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_3223 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_3224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_3225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_3226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_3227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_3228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_3229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_3230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_3231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_3232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_3233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_3234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_3235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_3236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_3237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_3238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_3239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_3240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_3241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_3242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_3243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								mem_vec_3244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
								mem_vec_3245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
								mem_vec_3246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
								mem_vec_3247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c178, cp_0 = 0;
									c < c178 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3222);
									mem_vec_3222 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3223);
									mem_vec_3223 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3224);
									mem_vec_3224 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3225);
									mem_vec_3225 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3226);
									mem_vec_3226 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3227);
									mem_vec_3227 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3228);
									mem_vec_3228 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3229);
									mem_vec_3229 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3230);
									mem_vec_3230 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3231);
									mem_vec_3231 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3232);
									mem_vec_3232 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3233);
									mem_vec_3233 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3234);
									mem_vec_3234 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3235);
									mem_vec_3235 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3236);
									mem_vec_3236 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3237);
									mem_vec_3237 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3238);
									mem_vec_3238 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3239);
									mem_vec_3239 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3240);
									mem_vec_3240 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3241);
									mem_vec_3241 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3242);
									mem_vec_3242 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3243);
									mem_vec_3243 = vec_34;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3244);
									mem_vec_3244 = vec_35;



									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3245);
									mem_vec_3245 = vec_37;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
									vec_39 = _mm512_set1_ps(scal_12);


									vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3246);
									mem_vec_3246 = vec_38;



									vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3247);
									mem_vec_3247 = vec_40;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3222);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3223);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3224);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3225);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3226);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3227);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3228);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3229);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3230);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3231);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3232);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3233);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3234);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3235);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3236);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3237);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3238);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3239);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3240);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3241);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3242);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3243);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3244);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3245);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3246);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_3247);
					}
				}
		}
	}
}


}