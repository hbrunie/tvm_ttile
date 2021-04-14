#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 8), (Arg 11))]; T (2, c);
  T (7, x)]
*/
IND_TYPE c, cp_0, c264_p_0, cp_1, c264, h, hp_0, w, wp_0, x, xp_0, x352_p_0, x353_p_0, xp_1, x352_p_1, xp_2, x352, x353, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y176 = 0;
IND_TYPE x354 = 0;
IND_TYPE h156 = 0;
IND_TYPE w176 = 0;
IND_TYPE c265 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2148 ,mem_vec_2149 ,mem_vec_2150 ,mem_vec_2151 ,mem_vec_2152 ,mem_vec_2153 ,mem_vec_2154 ,mem_vec_2155 ,mem_vec_2156 ,mem_vec_2157 ,mem_vec_2158 ,mem_vec_2159 ,mem_vec_2160 ,mem_vec_2161 ,mem_vec_2162 ,mem_vec_2163 ,mem_vec_2164 ,mem_vec_2165 ,mem_vec_2166 ,mem_vec_2167 ,mem_vec_2168 ,mem_vec_2169 ,mem_vec_2170 ,mem_vec_2171 ,mem_vec_2172 ,mem_vec_2173 ,mem_vec_2174 ,mem_vec_2175 ,mem_vec_2176 ,mem_vec_2177 ,mem_vec_2178 ,mem_vec_2179 ,mem_vec_2180 ,mem_vec_2181 ,mem_vec_2182 ,mem_vec_2183 ,mem_vec_2184 ,mem_vec_2185 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 7) (112 / 16)
for (x353 = x354, x353_p_0 = 0;
	x353 < x354 + 112;
	x353 += 16, x353_p_0 += 16){
	// y = 112, x = 16, h = 3, w = 3, c = 32, f = 32
	// T (c, 2) (32 / 16)
	for (c264 = c265, c264_p_0 = 0;
		c264 < c265 + 32;
		c264 += 16, c264_p_0 += 16){
			for (y = y176, yp_0 = 0;
				y < y176 + 24;
				y += 8, yp_0 += 8){
				// y = ph_y, x = 16, h = 3, w = 3, c = 16, f = 32
				// T (x, 2) (16 / 8)
				for (x352 = x353, x352_p_1 = x353_p_0, x352_p_0 = 0;
					x352 < x353 + 16;
					x352 += 8, x352_p_1 += 8, x352_p_0 += 8){
					// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h156, hp_0 = 0;
						h < h156 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w176, wp_0 = 0;
							w < w176 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 16, f = 32
							// T (x, 8) (8 / 1)
							for (x = x352, xp_2 = x352_p_1, xp_1 = x352_p_0, xp_0 = 0;
								x < x352 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2148 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2149 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_2162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_2163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c264, cp_1 = c264_p_0, cp_0 = 0;
											c < c264 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2148);
											mem_vec_2148 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2149);
											mem_vec_2149 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2150);
											mem_vec_2150 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2151);
											mem_vec_2151 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2152);
											mem_vec_2152 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2153);
											mem_vec_2153 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2154);
											mem_vec_2154 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2155);
											mem_vec_2155 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2156);
											mem_vec_2156 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2157);
											mem_vec_2157 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2158);
											mem_vec_2158 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2159);
											mem_vec_2159 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2160);
											mem_vec_2160 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2161);
											mem_vec_2161 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2162);
											mem_vec_2162 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2163);
											mem_vec_2163 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2148);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2149);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2150);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2151);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2152);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2153);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2154);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2155);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2156);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2157);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2158);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2159);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2160);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2161);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2162);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2163);
							}
						}
					}
				}
			}
			for (y = y176 + 24, yp_0 = 0;
				y < y176 + 24 + 88;
				y += 11, yp_0 += 11){
				// y = ph_y, x = 16, h = 3, w = 3, c = 16, f = 32
				// T (x, 2) (16 / 8)
				for (x352 = x353, x352_p_1 = x353_p_0, x352_p_0 = 0;
					x352 < x353 + 16;
					x352 += 8, x352_p_1 += 8, x352_p_0 += 8){
					// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h156, hp_0 = 0;
						h < h156 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w176, wp_0 = 0;
							w < w176 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 16, f = 32
							// T (x, 8) (8 / 1)
							for (x = x352, xp_2 = x352_p_1, xp_1 = x352_p_0, xp_0 = 0;
								x < x352 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2164 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2165 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_2178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_2179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_2180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_2181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_2182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_2183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_2184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_2185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c264, cp_1 = c264_p_0, cp_0 = 0;
											c < c264 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2164);
											mem_vec_2164 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2165);
											mem_vec_2165 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2166);
											mem_vec_2166 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2167);
											mem_vec_2167 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2168);
											mem_vec_2168 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2169);
											mem_vec_2169 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2170);
											mem_vec_2170 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2171);
											mem_vec_2171 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2172);
											mem_vec_2172 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2173);
											mem_vec_2173 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2174);
											mem_vec_2174 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2175);
											mem_vec_2175 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2176);
											mem_vec_2176 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2177);
											mem_vec_2177 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2178);
											mem_vec_2178 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2179);
											mem_vec_2179 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2180);
											mem_vec_2180 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2181);
											mem_vec_2181 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2182);
											mem_vec_2182 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2183);
											mem_vec_2183 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2184);
											mem_vec_2184 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2185);
											mem_vec_2185 = vec_34;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2164);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2165);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2166);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2167);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2168);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2169);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2170);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2171);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2172);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2173);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2174);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2175);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2176);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2177);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2178);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2179);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2180);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2181);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2182);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2183);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2184);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2185);
							}
						}
					}
				}
			}
	}
}


}