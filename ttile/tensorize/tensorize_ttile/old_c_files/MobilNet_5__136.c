#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (4, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (4, y); T (2, f); T (32, c); T (1, f); T (2, c); T (28, x);
  T (2, f)]
*/
IND_TYPE c, cp_0, c320_p_0, c321_p_0, cp_1, c320_p_1, cp_2, c320, c321, f, fp_0, f308_p_0, f309_p_0, fp_1, f308_p_1, fp_2, f308, f309, h, hp_0, w, wp_0, x, xp_0, x240_p_0, xp_1, x240, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y160 = 0;
IND_TYPE x241 = 0;
IND_TYPE h160 = 0;
IND_TYPE w160 = 0;
IND_TYPE c322 = 0;
IND_TYPE f310 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_2240 ,mem_vec_2241 ,mem_vec_2242 ,mem_vec_2243 ,mem_vec_2244 ,mem_vec_2245 ,mem_vec_2246 ,mem_vec_2247 ,mem_vec_2248 ,mem_vec_2249 ,mem_vec_2250 ,mem_vec_2251 ,mem_vec_2252 ,mem_vec_2253 ,mem_vec_2254 ,mem_vec_2255 ,mem_vec_2256 ,mem_vec_2257 ,mem_vec_2258 ,mem_vec_2259 ,mem_vec_2260 ,mem_vec_2261 ,mem_vec_2262 ,mem_vec_2263 ,mem_vec_2264 ,mem_vec_2265 ,mem_vec_2266 ,mem_vec_2267 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f309 = f310, f309_p_0 = 0;
	f309 < f310 + 256;
	f309 += 128, f309_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 128
	// T (x, 28) (28 / 1)
	for (x240 = x241, x240_p_0 = 0;
		x240 < x241 + 28;
		x240 += 1, x240_p_0 += 1){
		// y = 28, x = 1, h = 3, w = 3, c = 256, f = 128
		// T (c, 2) (256 / 128)
		for (c321 = c322, c321_p_0 = 0;
			c321 < c322 + 256;
			c321 += 128, c321_p_0 += 128){
			// y = 28, x = 1, h = 3, w = 3, c = 128, f = 128
			// T (f, 1) (128 / 128)
			for (f308 = f309, f308_p_1 = f309_p_0, f308_p_0 = 0;
				f308 < f309 + 128;
				f308 += 128, f308_p_1 += 128, f308_p_0 += 128){
				// y = 28, x = 1, h = 3, w = 3, c = 128, f = 128
				// T (c, 32) (128 / 4)
				for (c320 = c321, c320_p_1 = c321_p_0, c320_p_0 = 0;
					c320 < c321 + 128;
					c320 += 4, c320_p_1 += 4, c320_p_0 += 4){
					// y = 28, x = 1, h = 3, w = 3, c = 4, f = 128
					// T (f, 2) (128 / 64)
					for (f = f308, fp_2 = f308_p_1, fp_1 = f308_p_0, fp_0 = 0;
						f < f308 + 128;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = 28, x = 1, h = 3, w = 3, c = 4, f = 64
						// T (y, 4) (28 / 7)
						for (y = y160, yp_0 = 0;
							y < y160 + 28;
							y += 7, yp_0 += 7){
							// y = 7, x = 1, h = 3, w = 3, c = 4, f = 64
							// T (h, 3) (3 / 1)
							for (h = h160, hp_0 = 0;
								h < h160 + 3;
								h += 1, hp_0 += 1){
								// y = 7, x = 1, h = 1, w = 3, c = 4, f = 64
								// T (w, 3) (3 / 1)
								for (w = w160, wp_0 = 0;
									w < w160 + 3;
									w += 1, wp_0 += 1){
									// y = 7, x = 1, h = 1, w = 1, c = 4, f = 64
									// T (x, 1) (1 / 1)
									for (x = x240, xp_1 = x240_p_0, xp_0 = 0;
										x < x240 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2240 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2241 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2242 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_2243 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_2244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_2247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_2248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_2251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_2252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_2255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_2256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_2259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												mem_vec_2260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_2261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_2262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
												mem_vec_2263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
												mem_vec_2264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_2265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_2266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
												mem_vec_2267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
												// y = 7, x = 1, h = 1, w = 1, c = 4, f = 64
												// T (c, 4) (4 / 1)
												for (c = c320, cp_2 = c320_p_1, cp_1 = c320_p_0, cp_0 = 0;
													c < c320 + 4;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2240);
													mem_vec_2240 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2241);
													mem_vec_2241 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2242);
													mem_vec_2242 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2243);
													mem_vec_2243 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2244);
													mem_vec_2244 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2245);
													mem_vec_2245 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2246);
													mem_vec_2246 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2247);
													mem_vec_2247 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2248);
													mem_vec_2248 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2249);
													mem_vec_2249 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2250);
													mem_vec_2250 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2251);
													mem_vec_2251 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2252);
													mem_vec_2252 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2253);
													mem_vec_2253 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2254);
													mem_vec_2254 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2255);
													mem_vec_2255 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2256);
													mem_vec_2256 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2257);
													mem_vec_2257 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2258);
													mem_vec_2258 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2259);
													mem_vec_2259 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2260);
													mem_vec_2260 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2261);
													mem_vec_2261 = vec_31;



													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2262);
													mem_vec_2262 = vec_32;



													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2263);
													mem_vec_2263 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm512_set1_ps(scal_6);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_2264);
													mem_vec_2264 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_2265);
													mem_vec_2265 = vec_36;



													vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_2266);
													mem_vec_2266 = vec_37;



													vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_2267);
													mem_vec_2267 = vec_38;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2240);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2241);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2242);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2243);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2244);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2245);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2246);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2247);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2248);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2249);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2250);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2251);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2252);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2253);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2254);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2255);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2256);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2257);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2258);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2259);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2260);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2261);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_2262);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_2263);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2264);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2265);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_2266);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_2267);
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


}