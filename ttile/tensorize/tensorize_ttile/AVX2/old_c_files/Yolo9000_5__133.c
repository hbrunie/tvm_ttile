#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (2, x); T (4, y); T (2, f); T (1, x); T (2, y); T (68, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c213_p_0, cp_1, c213, f, fp_0, x, xp_0, x355_p_0, x356_p_0, x357_p_0, xp_1, x355_p_1, x356_p_1, xp_2, x355_p_2, xp_3, x355, x356, x357, y, yp_0, y284_p_0, y285_p_0, yp_1, y284_p_1, yp_2, y284, y285;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y286 = 0;
IND_TYPE x358 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c214 = 0;
IND_TYPE f142 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_2156 ,mem_vec_2157 ,mem_vec_2158 ,mem_vec_2159 ,mem_vec_2160 ,mem_vec_2161 ,mem_vec_2162 ,mem_vec_2163 ,mem_vec_2164 ,mem_vec_2165 ,mem_vec_2166 ,mem_vec_2167 ,mem_vec_2168 ,mem_vec_2169 ,mem_vec_2170 ,mem_vec_2171 ,mem_vec_2172 ,mem_vec_2173 ,mem_vec_2174 ,mem_vec_2175 ,mem_vec_2176 ,mem_vec_2177 ,mem_vec_2178 ,mem_vec_2179 ,mem_vec_2180 ,mem_vec_2181 ,mem_vec_2182 ,mem_vec_2183 ,mem_vec_2184 ,mem_vec_2185 ,mem_vec_2186 ,mem_vec_2187 ,mem_vec_2188 ,mem_vec_2189 ,mem_vec_2190 ,mem_vec_2191 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y285 = y286, y285_p_0 = 0;
		y285 < y286 + 96;
		y285 += 32, y285_p_0 += 32){
		// y = 2 * (4 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x357 = x358, x357_p_0 = 0;
			x357 < x358 + 136;
			x357 += 2, x357_p_0 += 2){
			// y = 2 * (4 * ph_y), x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 2) (2 * (4 * ph_y) / 4 * ph_y)
			for (y284 = y285, y284_p_1 = y285_p_0, y284_p_0 = 0;
				y284 < y285 + 32;
				y284 += 16, y284_p_1 += 16, y284_p_0 += 16){
				// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (2 / 2)
				for (x356 = x357, x356_p_1 = x357_p_0, x356_p_0 = 0;
					x356 < x357 + 2;
					x356 += 2, x356_p_1 += 2, x356_p_0 += 2){
					// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f142, fp_0 = 0;
						f < f142 + 64;
						f += 32, fp_0 += 32){
						// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 4) (4 * ph_y / ph_y)
						for (y = y284, yp_2 = y284_p_1, yp_1 = y284_p_0, yp_0 = 0;
							y < y284 + 16;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 2) (2 / 1)
							for (x355 = x356, x355_p_2 = x356_p_1, x355_p_1 = x356_p_0, x355_p_0 = 0;
								x355 < x356 + 2;
								x355 += 1, x355_p_2 += 1, x355_p_1 += 1, x355_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 1) (128 / 128)
								for (c213 = c214, c213_p_0 = 0;
									c213 < c214 + 128;
									c213 += 128, c213_p_0 += 128){
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (x, 1) (1 / 1)
									for (x = x355, xp_3 = x355_p_2, xp_2 = x355_p_1, xp_1 = x355_p_0, xp_0 = 0;
										x < x355 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2156 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2157 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_2158 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2159 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_2160 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2161 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_2162 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2163 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_2164 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2165 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_2166 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2167 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_2168 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2169 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_2170 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2171 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c213, cp_1 = c213_p_0, cp_0 = 0;
													c < c213 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2156);
													mem_vec_2156 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2157);
													mem_vec_2157 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2158);
													mem_vec_2158 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2159);
													mem_vec_2159 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2160);
													mem_vec_2160 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2161);
													mem_vec_2161 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2162);
													mem_vec_2162 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2163);
													mem_vec_2163 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2164);
													mem_vec_2164 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2165);
													mem_vec_2165 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2166);
													mem_vec_2166 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2167);
													mem_vec_2167 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2168);
													mem_vec_2168 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2169);
													mem_vec_2169 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2170);
													mem_vec_2170 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2171);
													mem_vec_2171 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2156);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2157);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2158);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2159);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2160);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2161);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2162);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2163);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2164);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2165);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2166);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2167);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2168);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2169);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2170);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2171);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y285 = y286 + 96, y285_p_0 = 0;
		y285 < y286 + 96 + 40;
		y285 += 40, y285_p_0 += 40){
		// y = 2 * (4 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x357 = x358, x357_p_0 = 0;
			x357 < x358 + 136;
			x357 += 2, x357_p_0 += 2){
			// y = 2 * (4 * ph_y), x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 2) (2 * (4 * ph_y) / 4 * ph_y)
			for (y284 = y285, y284_p_1 = y285_p_0, y284_p_0 = 0;
				y284 < y285 + 40;
				y284 += 20, y284_p_1 += 20, y284_p_0 += 20){
				// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (2 / 2)
				for (x356 = x357, x356_p_1 = x357_p_0, x356_p_0 = 0;
					x356 < x357 + 2;
					x356 += 2, x356_p_1 += 2, x356_p_0 += 2){
					// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f142, fp_0 = 0;
						f < f142 + 64;
						f += 32, fp_0 += 32){
						// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 4) (4 * ph_y / ph_y)
						for (y = y284, yp_2 = y284_p_1, yp_1 = y284_p_0, yp_0 = 0;
							y < y284 + 20;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 2) (2 / 1)
							for (x355 = x356, x355_p_2 = x356_p_1, x355_p_1 = x356_p_0, x355_p_0 = 0;
								x355 < x356 + 2;
								x355 += 1, x355_p_2 += 1, x355_p_1 += 1, x355_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 1) (128 / 128)
								for (c213 = c214, c213_p_0 = 0;
									c213 < c214 + 128;
									c213 += 128, c213_p_0 += 128){
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (x, 1) (1 / 1)
									for (x = x355, xp_3 = x355_p_2, xp_2 = x355_p_1, xp_1 = x355_p_0, xp_0 = 0;
										x < x355 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2172 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2173 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_2174 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2175 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_2176 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2177 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_2178 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2179 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_2180 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2181 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_2182 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2183 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_2184 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2185 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_2186 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2187 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_2188 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2189 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_2190 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2191 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c213, cp_1 = c213_p_0, cp_0 = 0;
													c < c213 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2172);
													mem_vec_2172 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2173);
													mem_vec_2173 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2174);
													mem_vec_2174 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2175);
													mem_vec_2175 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2176);
													mem_vec_2176 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2177);
													mem_vec_2177 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2178);
													mem_vec_2178 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2179);
													mem_vec_2179 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2180);
													mem_vec_2180 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2181);
													mem_vec_2181 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2182);
													mem_vec_2182 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2183);
													mem_vec_2183 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2184);
													mem_vec_2184 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2185);
													mem_vec_2185 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2186);
													mem_vec_2186 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2187);
													mem_vec_2187 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2188);
													mem_vec_2188 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2189);
													mem_vec_2189 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2190);
													mem_vec_2190 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2191);
													mem_vec_2191 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2172);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2173);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2174);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2175);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2176);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2177);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2178);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2179);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2180);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2181);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2182);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2183);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2184);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2185);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2186);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2187);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2188);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2189);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2190);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_2191);
									}
								}
							}
						}
					}
				}
			}
		}
	}


}