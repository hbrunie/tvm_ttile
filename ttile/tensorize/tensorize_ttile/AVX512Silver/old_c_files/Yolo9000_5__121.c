#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x); T (8, y);
  T (1, c); T (68, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]]
*/
IND_TYPE c, cp_0, c123_p_0, cp_1, c123, x, xp_0, x159_p_0, xp_1, x159, y, yp_0, y159_p_0, yp_1, y159;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y160 = 0;
IND_TYPE x160 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c124 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_2140 ,mem_vec_2141 ,mem_vec_2142 ,mem_vec_2143 ,mem_vec_2144 ,mem_vec_2145 ,mem_vec_2146 ,mem_vec_2147 ,mem_vec_2148 ,mem_vec_2149 ,mem_vec_2150 ,mem_vec_2151 ,mem_vec_2152 ,mem_vec_2153 ,mem_vec_2154 ,mem_vec_2155 ,mem_vec_2156 ,mem_vec_2157 ,mem_vec_2158 ,mem_vec_2159 ,mem_vec_2160 ,mem_vec_2161 ,mem_vec_2162 ,mem_vec_2163 ,mem_vec_2164 ,mem_vec_2165 ,mem_vec_2166 ,mem_vec_2167 ,mem_vec_2168 ,mem_vec_2169 ,mem_vec_2170 ,mem_vec_2171 ,mem_vec_2172 ,mem_vec_2173 ,mem_vec_2174 ,mem_vec_2175 ,mem_vec_2176 ,mem_vec_2177 ,mem_vec_2178 ,mem_vec_2179 ,mem_vec_2180 ,mem_vec_2181 ,mem_vec_2182 ,mem_vec_2183 ,mem_vec_2184 ,mem_vec_2185 ,mem_vec_2186 ,mem_vec_2187 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y159 = y160, y159_p_0 = 0;
		y159 < y160 + 80;
		y159 += 40, y159_p_0 += 40){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x159 = x160, x159_p_0 = 0;
			x159 < x160 + 136;
			x159 += 2, x159_p_0 += 2){
			// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c123 = c124, c123_p_0 = 0;
				c123 < c124 + 128;
				c123 += 128, c123_p_0 += 128){
				// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (y, 8) (8 * ph_y / ph_y)
				for (y = y159, yp_1 = y159_p_0, yp_0 = 0;
					y < y159 + 40;
					y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (x, 2) (2 / 1)
					for (x = x159, xp_1 = x159_p_0, xp_0 = 0;
						x < x159 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_2140 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_2141 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_2142 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_2143 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_2144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_2145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_2146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_2147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_2148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_2149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_2150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_2151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_2152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_2153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_2154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_2155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_2156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_2157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_2158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_2159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c123, cp_1 = c123_p_0, cp_0 = 0;
									c < c123 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2140);
									mem_vec_2140 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2141);
									mem_vec_2141 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2142);
									mem_vec_2142 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2143);
									mem_vec_2143 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2144);
									mem_vec_2144 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2145);
									mem_vec_2145 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2146);
									mem_vec_2146 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2147);
									mem_vec_2147 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2148);
									mem_vec_2148 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2149);
									mem_vec_2149 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2150);
									mem_vec_2150 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2151);
									mem_vec_2151 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2152);
									mem_vec_2152 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2153);
									mem_vec_2153 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2154);
									mem_vec_2154 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2155);
									mem_vec_2155 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2156);
									mem_vec_2156 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2157);
									mem_vec_2157 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2158);
									mem_vec_2158 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2159);
									mem_vec_2159 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2140);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2141);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2142);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2143);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2144);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2145);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2146);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2147);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2148);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2149);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2150);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2151);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2152);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2153);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2154);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2155);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2156);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2157);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2158);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2159);
					}
				}
			}
		}
	}
	for (y159 = y160 + 80, y159_p_0 = 0;
		y159 < y160 + 80 + 56;
		y159 += 56, y159_p_0 += 56){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x159 = x160, x159_p_0 = 0;
			x159 < x160 + 136;
			x159 += 2, x159_p_0 += 2){
			// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c123 = c124, c123_p_0 = 0;
				c123 < c124 + 128;
				c123 += 128, c123_p_0 += 128){
				// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (y, 8) (8 * ph_y / ph_y)
				for (y = y159, yp_1 = y159_p_0, yp_0 = 0;
					y < y159 + 56;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (x, 2) (2 / 1)
					for (x = x159, xp_1 = x159_p_0, xp_0 = 0;
						x < x159 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_2160 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_2161 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_2162 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_2163 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_2164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_2165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_2166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_2167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_2168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_2169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_2170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_2171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_2172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_2173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_2174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_2175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_2176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_2177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_2178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_2179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_2180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_2181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_2182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_2183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								mem_vec_2184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_2185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_2186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
								mem_vec_2187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c123, cp_1 = c123_p_0, cp_0 = 0;
									c < c123 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2160);
									mem_vec_2160 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2161);
									mem_vec_2161 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2162);
									mem_vec_2162 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2163);
									mem_vec_2163 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2164);
									mem_vec_2164 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2165);
									mem_vec_2165 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2166);
									mem_vec_2166 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2167);
									mem_vec_2167 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2168);
									mem_vec_2168 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2169);
									mem_vec_2169 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2170);
									mem_vec_2170 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2171);
									mem_vec_2171 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2172);
									mem_vec_2172 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2173);
									mem_vec_2173 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2174);
									mem_vec_2174 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2175);
									mem_vec_2175 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2176);
									mem_vec_2176 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2177);
									mem_vec_2177 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2178);
									mem_vec_2178 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2179);
									mem_vec_2179 = vec_28;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2180);
									mem_vec_2180 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2181);
									mem_vec_2181 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2182);
									mem_vec_2182 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2183);
									mem_vec_2183 = vec_33;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_35 = _mm512_set1_ps(scal_6);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_2184);
									mem_vec_2184 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_2185);
									mem_vec_2185 = vec_36;



									vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_2186);
									mem_vec_2186 = vec_37;



									vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_2187);
									mem_vec_2187 = vec_38;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2160);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2161);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2162);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2163);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2164);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2165);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2166);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2167);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2168);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2169);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2170);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2171);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2172);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2173);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2174);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2175);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2176);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2177);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2178);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2179);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2180);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2181);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_2182);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_2183);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2184);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2185);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_2186);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_2187);
					}
				}
			}
		}
	}


}