#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x); T (8, y);
  T (1, c); T (136, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]]
*/
IND_TYPE c, cp_0, c126_p_0, cp_1, c126, x, xp_0, x162_p_0, xp_1, x162, y, yp_0, y162_p_0, yp_1, y162;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y163 = 0;
IND_TYPE x163 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c127 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_2188 ,mem_vec_2189 ,mem_vec_2190 ,mem_vec_2191 ,mem_vec_2192 ,mem_vec_2193 ,mem_vec_2194 ,mem_vec_2195 ,mem_vec_2196 ,mem_vec_2197 ,mem_vec_2198 ,mem_vec_2199 ,mem_vec_2200 ,mem_vec_2201 ,mem_vec_2202 ,mem_vec_2203 ,mem_vec_2204 ,mem_vec_2205 ,mem_vec_2206 ,mem_vec_2207 ,mem_vec_2208 ,mem_vec_2209 ,mem_vec_2210 ,mem_vec_2211 ,mem_vec_2212 ,mem_vec_2213 ,mem_vec_2214 ,mem_vec_2215 ,mem_vec_2216 ,mem_vec_2217 ,mem_vec_2218 ,mem_vec_2219 ,mem_vec_2220 ,mem_vec_2221 ,mem_vec_2222 ,mem_vec_2223 ,mem_vec_2224 ,mem_vec_2225 ,mem_vec_2226 ,mem_vec_2227 ,mem_vec_2228 ,mem_vec_2229 ,mem_vec_2230 ,mem_vec_2231 ,mem_vec_2232 ,mem_vec_2233 ,mem_vec_2234 ,mem_vec_2235 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y162 = y163, y162_p_0 = 0;
		y162 < y163 + 80;
		y162 += 40, y162_p_0 += 40){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 136) (136 / 1)
		for (x162 = x163, x162_p_0 = 0;
			x162 < x163 + 136;
			x162 += 1, x162_p_0 += 1){
			// y = 8 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c126 = c127, c126_p_0 = 0;
				c126 < c127 + 128;
				c126 += 128, c126_p_0 += 128){
				// y = 8 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (y, 8) (8 * ph_y / ph_y)
				for (y = y162, yp_1 = y162_p_0, yp_0 = 0;
					y < y162 + 40;
					y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (x, 1) (1 / 1)
					for (x = x162, xp_1 = x162_p_0, xp_0 = 0;
						x < x162 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_2188 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_2189 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_2190 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_2191 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_2192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_2193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_2194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_2195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_2196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_2197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_2198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_2199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_2200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_2201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_2202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_2203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_2204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_2205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_2206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_2207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c126, cp_1 = c126_p_0, cp_0 = 0;
									c < c126 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2188);
									mem_vec_2188 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2189);
									mem_vec_2189 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2190);
									mem_vec_2190 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2191);
									mem_vec_2191 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2192);
									mem_vec_2192 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2193);
									mem_vec_2193 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2194);
									mem_vec_2194 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2195);
									mem_vec_2195 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2196);
									mem_vec_2196 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2197);
									mem_vec_2197 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2198);
									mem_vec_2198 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2199);
									mem_vec_2199 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2200);
									mem_vec_2200 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2201);
									mem_vec_2201 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2202);
									mem_vec_2202 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2203);
									mem_vec_2203 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2204);
									mem_vec_2204 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2205);
									mem_vec_2205 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2206);
									mem_vec_2206 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2207);
									mem_vec_2207 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2188);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2189);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2190);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2191);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2192);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2193);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2194);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2195);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2196);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2197);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2198);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2199);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2200);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2201);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2202);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2203);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2204);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2205);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2206);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2207);
					}
				}
			}
		}
	}
	for (y162 = y163 + 80, y162_p_0 = 0;
		y162 < y163 + 80 + 56;
		y162 += 56, y162_p_0 += 56){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 136) (136 / 1)
		for (x162 = x163, x162_p_0 = 0;
			x162 < x163 + 136;
			x162 += 1, x162_p_0 += 1){
			// y = 8 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c126 = c127, c126_p_0 = 0;
				c126 < c127 + 128;
				c126 += 128, c126_p_0 += 128){
				// y = 8 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (y, 8) (8 * ph_y / ph_y)
				for (y = y162, yp_1 = y162_p_0, yp_0 = 0;
					y < y162 + 56;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (x, 1) (1 / 1)
					for (x = x162, xp_1 = x162_p_0, xp_0 = 0;
						x < x162 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_2208 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_2209 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_2210 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_2211 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_2212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_2213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_2214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_2215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_2216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_2217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_2218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_2219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_2220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_2221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_2222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_2223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_2224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_2225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_2226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_2227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_2228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_2229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_2230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_2231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								mem_vec_2232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_2233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_2234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
								mem_vec_2235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c126, cp_1 = c126_p_0, cp_0 = 0;
									c < c126 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2208);
									mem_vec_2208 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2209);
									mem_vec_2209 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2210);
									mem_vec_2210 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2211);
									mem_vec_2211 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2212);
									mem_vec_2212 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2213);
									mem_vec_2213 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2214);
									mem_vec_2214 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2215);
									mem_vec_2215 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2216);
									mem_vec_2216 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2217);
									mem_vec_2217 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2218);
									mem_vec_2218 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2219);
									mem_vec_2219 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2220);
									mem_vec_2220 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2221);
									mem_vec_2221 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2222);
									mem_vec_2222 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2223);
									mem_vec_2223 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2224);
									mem_vec_2224 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2225);
									mem_vec_2225 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2226);
									mem_vec_2226 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2227);
									mem_vec_2227 = vec_28;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2228);
									mem_vec_2228 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2229);
									mem_vec_2229 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2230);
									mem_vec_2230 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2231);
									mem_vec_2231 = vec_33;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_35 = _mm512_set1_ps(scal_6);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_2232);
									mem_vec_2232 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_2233);
									mem_vec_2233 = vec_36;



									vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_2234);
									mem_vec_2234 = vec_37;



									vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_2235);
									mem_vec_2235 = vec_38;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2208);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2209);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2210);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2211);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2212);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2213);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2214);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2215);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2216);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2217);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2218);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2219);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2220);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2221);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2222);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2223);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2224);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2225);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2226);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2227);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2228);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2229);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_2230);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_2231);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2232);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2233);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_2234);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_2235);
					}
				}
			}
		}
	}


}