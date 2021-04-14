#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 8), (Arg 11))]; T (32, c);
  T (7, x)]
*/
IND_TYPE c, cp_0, c270_p_0, cp_1, c270, h, hp_0, w, wp_0, x, xp_0, x360_p_0, x361_p_0, xp_1, x360_p_1, xp_2, x360, x361, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y180 = 0;
IND_TYPE x362 = 0;
IND_TYPE h160 = 0;
IND_TYPE w180 = 0;
IND_TYPE c271 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2224 ,mem_vec_2225 ,mem_vec_2226 ,mem_vec_2227 ,mem_vec_2228 ,mem_vec_2229 ,mem_vec_2230 ,mem_vec_2231 ,mem_vec_2232 ,mem_vec_2233 ,mem_vec_2234 ,mem_vec_2235 ,mem_vec_2236 ,mem_vec_2237 ,mem_vec_2238 ,mem_vec_2239 ,mem_vec_2240 ,mem_vec_2241 ,mem_vec_2242 ,mem_vec_2243 ,mem_vec_2244 ,mem_vec_2245 ,mem_vec_2246 ,mem_vec_2247 ,mem_vec_2248 ,mem_vec_2249 ,mem_vec_2250 ,mem_vec_2251 ,mem_vec_2252 ,mem_vec_2253 ,mem_vec_2254 ,mem_vec_2255 ,mem_vec_2256 ,mem_vec_2257 ,mem_vec_2258 ,mem_vec_2259 ,mem_vec_2260 ,mem_vec_2261 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 7) (112 / 16)
for (x361 = x362, x361_p_0 = 0;
	x361 < x362 + 112;
	x361 += 16, x361_p_0 += 16){
	// y = 112, x = 16, h = 3, w = 3, c = 32, f = 32
	// T (c, 32) (32 / 1)
	for (c270 = c271, c270_p_0 = 0;
		c270 < c271 + 32;
		c270 += 1, c270_p_0 += 1){
			for (y = y180, yp_0 = 0;
				y < y180 + 24;
				y += 8, yp_0 += 8){
				// y = ph_y, x = 16, h = 3, w = 3, c = 1, f = 32
				// T (x, 2) (16 / 8)
				for (x360 = x361, x360_p_1 = x361_p_0, x360_p_0 = 0;
					x360 < x361 + 16;
					x360 += 8, x360_p_1 += 8, x360_p_0 += 8){
					// y = ph_y, x = 8, h = 3, w = 3, c = 1, f = 32
					// T (h, 3) (3 / 1)
					for (h = h160, hp_0 = 0;
						h < h160 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 1, f = 32
						// T (w, 3) (3 / 1)
						for (w = w180, wp_0 = 0;
							w < w180 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 1, f = 32
							// T (x, 8) (8 / 1)
							for (x = x360, xp_2 = x360_p_1, xp_1 = x360_p_0, xp_0 = 0;
								x < x360 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2224 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2225 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_2238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_2239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
										// T (c, 1) (1 / 1)
										for (c = c270, cp_1 = c270_p_0, cp_0 = 0;
											c < c270 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2224);
											mem_vec_2224 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2225);
											mem_vec_2225 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2226);
											mem_vec_2226 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2227);
											mem_vec_2227 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2228);
											mem_vec_2228 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2229);
											mem_vec_2229 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2230);
											mem_vec_2230 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2231);
											mem_vec_2231 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2232);
											mem_vec_2232 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2233);
											mem_vec_2233 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2234);
											mem_vec_2234 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2235);
											mem_vec_2235 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2236);
											mem_vec_2236 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2237);
											mem_vec_2237 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2238);
											mem_vec_2238 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2239);
											mem_vec_2239 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2224);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2225);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2226);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2227);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2228);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2229);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2230);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2231);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2232);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2233);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2234);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2235);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2236);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2237);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2238);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2239);
							}
						}
					}
				}
			}
			for (y = y180 + 24, yp_0 = 0;
				y < y180 + 24 + 88;
				y += 11, yp_0 += 11){
				// y = ph_y, x = 16, h = 3, w = 3, c = 1, f = 32
				// T (x, 2) (16 / 8)
				for (x360 = x361, x360_p_1 = x361_p_0, x360_p_0 = 0;
					x360 < x361 + 16;
					x360 += 8, x360_p_1 += 8, x360_p_0 += 8){
					// y = ph_y, x = 8, h = 3, w = 3, c = 1, f = 32
					// T (h, 3) (3 / 1)
					for (h = h160, hp_0 = 0;
						h < h160 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 1, f = 32
						// T (w, 3) (3 / 1)
						for (w = w180, wp_0 = 0;
							w < w180 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 1, f = 32
							// T (x, 8) (8 / 1)
							for (x = x360, xp_2 = x360_p_1, xp_1 = x360_p_0, xp_0 = 0;
								x < x360 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2240 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2241 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_2254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_2255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_2256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_2257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_2258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_2259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_2260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_2261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
										// T (c, 1) (1 / 1)
										for (c = c270, cp_1 = c270_p_0, cp_0 = 0;
											c < c270 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2240);
											mem_vec_2240 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2241);
											mem_vec_2241 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2242);
											mem_vec_2242 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2243);
											mem_vec_2243 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2244);
											mem_vec_2244 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2245);
											mem_vec_2245 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2246);
											mem_vec_2246 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2247);
											mem_vec_2247 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2248);
											mem_vec_2248 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2249);
											mem_vec_2249 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2250);
											mem_vec_2250 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2251);
											mem_vec_2251 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2252);
											mem_vec_2252 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2253);
											mem_vec_2253 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2254);
											mem_vec_2254 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2255);
											mem_vec_2255 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2256);
											mem_vec_2256 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2257);
											mem_vec_2257 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2258);
											mem_vec_2258 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2259);
											mem_vec_2259 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2260);
											mem_vec_2260 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2261);
											mem_vec_2261 = vec_34;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2240);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2241);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2242);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2243);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2244);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2245);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2246);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2247);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2248);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2249);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2250);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2251);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2252);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2253);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2254);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2255);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2256);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2257);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2258);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2259);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2260);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2261);
							}
						}
					}
				}
			}
	}
}


}