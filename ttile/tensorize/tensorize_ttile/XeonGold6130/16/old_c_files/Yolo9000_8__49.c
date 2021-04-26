#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (4, c); T (4, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 4), (Arg 15))]; T (4, x);
  T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c165_p_0, cp_1, c165, f, fp_0, f220_p_0, f221_p_0, fp_1, f220_p_1, fp_2, f220, f221, h, hp_0, w, wp_0, x, xp_0, x165_p_0, xp_1, x165, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y110 = 0;
IND_TYPE x166 = 0;
IND_TYPE h110 = 0;
IND_TYPE w101 = 0;
IND_TYPE c166 = 0;
IND_TYPE f222 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2260 ,mem_vec_2261 ,mem_vec_2262 ,mem_vec_2263 ,mem_vec_2264 ,mem_vec_2265 ,mem_vec_2266 ,mem_vec_2267 ,mem_vec_2268 ,mem_vec_2269 ,mem_vec_2270 ,mem_vec_2271 ,mem_vec_2272 ,mem_vec_2273 ,mem_vec_2274 ,mem_vec_2275 ,mem_vec_2276 ,mem_vec_2277 ,mem_vec_2278 ,mem_vec_2279 ,mem_vec_2280 ,mem_vec_2281 ,mem_vec_2282 ,mem_vec_2283 ,mem_vec_2284 ,mem_vec_2285 ,mem_vec_2286 ,mem_vec_2287 ,mem_vec_2288 ,mem_vec_2289 ,mem_vec_2290 ,mem_vec_2291 ,mem_vec_2292 ,mem_vec_2293 ,mem_vec_2294 ,mem_vec_2295 ,mem_vec_2296 ,mem_vec_2297 ,mem_vec_2298 ,mem_vec_2299 ,mem_vec_2300 ,mem_vec_2301 ,mem_vec_2302 ,mem_vec_2303 ,mem_vec_2304 ,mem_vec_2305 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f221 = f222, f221_p_0 = 0;
	f221 < f222 + 256;
	f221 += 256, f221_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (f, 2) (256 / 128)
	for (f220 = f221, f220_p_1 = f221_p_0, f220_p_0 = 0;
		f220 < f221 + 256;
		f220 += 128, f220_p_1 += 128, f220_p_0 += 128){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
		// T (x, 4) (68 / 17)
		for (x165 = x166, x165_p_0 = 0;
			x165 < x166 + 68;
			x165 += 17, x165_p_0 += 17){
				for (y = y110, yp_0 = 0;
					y < y110 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 128
					// T (f, 4) (128 / 32)
					for (f = f220, fp_2 = f220_p_1, fp_1 = f220_p_0, fp_0 = 0;
						f < f220 + 128;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c165 = c166, c165_p_0 = 0;
							c165 < c166 + 128;
							c165 += 32, c165_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w101, wp_0 = 0;
								w < w101 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x165, xp_1 = x165_p_0, xp_0 = 0;
									x < x165 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h110, hp_0 = 0;
										h < h110 + 3;
										h += 1, hp_0 += 1){
												mem_vec_2260 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2261 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_2271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_2272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_2273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_2274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_2275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c165, cp_1 = c165_p_0, cp_0 = 0;
													c < c165 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2260);
													mem_vec_2260 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2261);
													mem_vec_2261 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2262);
													mem_vec_2262 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2263);
													mem_vec_2263 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2264);
													mem_vec_2264 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2265);
													mem_vec_2265 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2266);
													mem_vec_2266 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2267);
													mem_vec_2267 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2268);
													mem_vec_2268 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2269);
													mem_vec_2269 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2270);
													mem_vec_2270 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2271);
													mem_vec_2271 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2272);
													mem_vec_2272 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2273);
													mem_vec_2273 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2274);
													mem_vec_2274 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2275);
													mem_vec_2275 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2260);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2261);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2262);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2263);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2264);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2265);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2266);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2267);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2268);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2269);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2270);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2271);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2272);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2273);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2274);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2275);
									}
								}
							}
						}
					}
				}
				for (y = y110 + 8, yp_0 = 0;
					y < y110 + 8 + 60;
					y += 15, yp_0 += 15){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 128
					// T (f, 4) (128 / 32)
					for (f = f220, fp_2 = f220_p_1, fp_1 = f220_p_0, fp_0 = 0;
						f < f220 + 128;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c165 = c166, c165_p_0 = 0;
							c165 < c166 + 128;
							c165 += 32, c165_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w101, wp_0 = 0;
								w < w101 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x165, xp_1 = x165_p_0, xp_0 = 0;
									x < x165 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h110, hp_0 = 0;
										h < h110 + 3;
										h += 1, hp_0 += 1){
												mem_vec_2276 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2277 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_2287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_2288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_2289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_2290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_2291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_2292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_2293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_2294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_2295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_2296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_2297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_2298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_2299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_2300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_2301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_2302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_2303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												mem_vec_2304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
												mem_vec_2305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c165, cp_1 = c165_p_0, cp_0 = 0;
													c < c165 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2276);
													mem_vec_2276 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2277);
													mem_vec_2277 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2278);
													mem_vec_2278 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2279);
													mem_vec_2279 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2280);
													mem_vec_2280 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2281);
													mem_vec_2281 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2282);
													mem_vec_2282 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2283);
													mem_vec_2283 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2284);
													mem_vec_2284 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2285);
													mem_vec_2285 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2286);
													mem_vec_2286 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2287);
													mem_vec_2287 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2288);
													mem_vec_2288 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2289);
													mem_vec_2289 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2290);
													mem_vec_2290 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2291);
													mem_vec_2291 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2292);
													mem_vec_2292 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2293);
													mem_vec_2293 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2294);
													mem_vec_2294 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2295);
													mem_vec_2295 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2296);
													mem_vec_2296 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2297);
													mem_vec_2297 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2298);
													mem_vec_2298 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2299);
													mem_vec_2299 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_2300);
													mem_vec_2300 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_2301);
													mem_vec_2301 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_2302);
													mem_vec_2302 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_2303);
													mem_vec_2303 = vec_43;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
													vec_45 = _mm512_set1_ps(scal_14);


													vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_2304);
													mem_vec_2304 = vec_44;



													vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_2305);
													mem_vec_2305 = vec_46;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2276);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2277);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2278);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2279);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2280);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2281);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2282);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2283);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2284);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2285);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2286);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2287);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2288);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2289);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2290);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2291);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2292);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2293);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2294);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2295);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2296);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2297);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2298);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_2299);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_2300);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_2301);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_2302);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_2303);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_2304);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_2305);
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