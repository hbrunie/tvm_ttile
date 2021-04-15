#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x); T (34, x);
  Lambda_apply y [((Iter 7), (Arg 12)); ((Iter 4), (Arg 13))]; T (2, f);
  T (2, x)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x1328_p_0, x1329_p_0, xp_1, x1328_p_1, xp_2, x1328, x1329, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y696 = 0;
IND_TYPE x1330 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c760 = 0;
IND_TYPE f632 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_13192 ,mem_vec_13193 ,mem_vec_13194 ,mem_vec_13195 ,mem_vec_13196 ,mem_vec_13197 ,mem_vec_13198 ,mem_vec_13199 ,mem_vec_13200 ,mem_vec_13201 ,mem_vec_13202 ,mem_vec_13203 ,mem_vec_13204 ,mem_vec_13205 ,mem_vec_13206 ,mem_vec_13207 ,mem_vec_13208 ,mem_vec_13209 ,mem_vec_13210 ,mem_vec_13211 ,mem_vec_13212 ,mem_vec_13213 ,mem_vec_13214 ,mem_vec_13215 ,mem_vec_13216 ,mem_vec_13217 ,mem_vec_13218 ,mem_vec_13219 ,mem_vec_13220 ,mem_vec_13221 ,mem_vec_13222 ,mem_vec_13223 ,mem_vec_13224 ,mem_vec_13225 ,mem_vec_13226 ,mem_vec_13227 ,mem_vec_13228 ,mem_vec_13229 ,mem_vec_13230 ,mem_vec_13231 ,mem_vec_13232 ,mem_vec_13233 ,mem_vec_13234 ,mem_vec_13235 ,mem_vec_13236 ,mem_vec_13237 ,mem_vec_13238 ,mem_vec_13239 ,mem_vec_13240 ,mem_vec_13241 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 2) (136 / 68)
for (x1329 = x1330, x1329_p_0 = 0;
	x1329 < x1330 + 136;
	x1329 += 68, x1329_p_0 += 68){
	// y = 136, x = 68, h = 1, w = 1, c = 128, f = 64
	// T (f, 2) (64 / 32)
	for (f = f632, fp_0 = 0;
		f < f632 + 64;
		f += 32, fp_0 += 32){
			for (y = y696, yp_0 = 0;
				y < y696 + 84;
				y += 12, yp_0 += 12){
				// y = ph_y, x = 68, h = 1, w = 1, c = 128, f = 32
				// T (x, 34) (68 / 2)
				for (x1328 = x1329, x1328_p_1 = x1329_p_0, x1328_p_0 = 0;
					x1328 < x1329 + 68;
					x1328 += 2, x1328_p_1 += 2, x1328_p_0 += 2){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x1328, xp_2 = x1328_p_1, xp_1 = x1328_p_0, xp_0 = 0;
						x < x1328 + 2;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_13192 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_13193 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_13194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_13195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_13196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_13197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_13198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_13199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_13200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_13201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_13202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_13203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_13204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_13205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_13206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_13207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_13208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_13209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_13210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_13211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_13212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_13213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								mem_vec_13214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
								mem_vec_13215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c760, cp_0 = 0;
									c < c760 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13192);
									mem_vec_13192 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13193);
									mem_vec_13193 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_13194);
									mem_vec_13194 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_13195);
									mem_vec_13195 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_13196);
									mem_vec_13196 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_13197);
									mem_vec_13197 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_13198);
									mem_vec_13198 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_13199);
									mem_vec_13199 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13200);
									mem_vec_13200 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13201);
									mem_vec_13201 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_13202);
									mem_vec_13202 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_13203);
									mem_vec_13203 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_13204);
									mem_vec_13204 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_13205);
									mem_vec_13205 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_13206);
									mem_vec_13206 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_13207);
									mem_vec_13207 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_13208);
									mem_vec_13208 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_13209);
									mem_vec_13209 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13210);
									mem_vec_13210 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13211);
									mem_vec_13211 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_13212);
									mem_vec_13212 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_13213);
									mem_vec_13213 = vec_34;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_13214);
									mem_vec_13214 = vec_35;



									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_13215);
									mem_vec_13215 = vec_37;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13192);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13193);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13194);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13195);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13196);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13197);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13198);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13199);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13200);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13201);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13202);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13203);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13204);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13205);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_13206);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_13207);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_13208);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_13209);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_13210);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_13211);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_13212);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_13213);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_13214);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_13215);
					}
				}
			}
			for (y = y696 + 84, yp_0 = 0;
				y < y696 + 84 + 52;
				y += 13, yp_0 += 13){
				// y = ph_y, x = 68, h = 1, w = 1, c = 128, f = 32
				// T (x, 34) (68 / 2)
				for (x1328 = x1329, x1328_p_1 = x1329_p_0, x1328_p_0 = 0;
					x1328 < x1329 + 68;
					x1328 += 2, x1328_p_1 += 2, x1328_p_0 += 2){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x1328, xp_2 = x1328_p_1, xp_1 = x1328_p_0, xp_0 = 0;
						x < x1328 + 2;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_13216 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_13217 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_13218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_13219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_13220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_13221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_13222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_13223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_13224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_13225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_13226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_13227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_13228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_13229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_13230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_13231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_13232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_13233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_13234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_13235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_13236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_13237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								mem_vec_13238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
								mem_vec_13239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
								mem_vec_13240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
								mem_vec_13241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c760, cp_0 = 0;
									c < c760 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13216);
									mem_vec_13216 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13217);
									mem_vec_13217 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_13218);
									mem_vec_13218 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_13219);
									mem_vec_13219 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_13220);
									mem_vec_13220 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_13221);
									mem_vec_13221 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_13222);
									mem_vec_13222 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_13223);
									mem_vec_13223 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13224);
									mem_vec_13224 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13225);
									mem_vec_13225 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_13226);
									mem_vec_13226 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_13227);
									mem_vec_13227 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_13228);
									mem_vec_13228 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_13229);
									mem_vec_13229 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_13230);
									mem_vec_13230 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_13231);
									mem_vec_13231 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_13232);
									mem_vec_13232 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_13233);
									mem_vec_13233 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13234);
									mem_vec_13234 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13235);
									mem_vec_13235 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_13236);
									mem_vec_13236 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_13237);
									mem_vec_13237 = vec_34;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_13238);
									mem_vec_13238 = vec_35;



									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_13239);
									mem_vec_13239 = vec_37;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
									vec_39 = _mm512_set1_ps(scal_12);


									vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_13240);
									mem_vec_13240 = vec_38;



									vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_13241);
									mem_vec_13241 = vec_40;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13216);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13217);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13218);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13219);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13220);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13221);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13222);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13223);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13224);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13225);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13226);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13227);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13228);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13229);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_13230);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_13231);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_13232);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_13233);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_13234);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_13235);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_13236);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_13237);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_13238);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_13239);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_13240);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_13241);
					}
				}
			}
	}
}


}