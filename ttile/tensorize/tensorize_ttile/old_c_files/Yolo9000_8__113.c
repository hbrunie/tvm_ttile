#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 12)); ((Iter 4), (Arg 14))];
  T (2, f); T (32, c); T (1, f); T (68, x); T (4, f)]
*/
IND_TYPE c, cp_0, c942_p_0, cp_1, c942, f, fp_0, f1256_p_0, f1257_p_0, fp_1, f1256_p_1, fp_2, f1256, f1257, h, hp_0, w, wp_0, x, xp_0, x994_p_0, xp_1, x994, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y628 = 0;
IND_TYPE x995 = 0;
IND_TYPE h628 = 0;
IND_TYPE w576 = 0;
IND_TYPE c943 = 0;
IND_TYPE f1258 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_12252 ,mem_vec_12253 ,mem_vec_12254 ,mem_vec_12255 ,mem_vec_12256 ,mem_vec_12257 ,mem_vec_12258 ,mem_vec_12259 ,mem_vec_12260 ,mem_vec_12261 ,mem_vec_12262 ,mem_vec_12263 ,mem_vec_12264 ,mem_vec_12265 ,mem_vec_12266 ,mem_vec_12267 ,mem_vec_12268 ,mem_vec_12269 ,mem_vec_12270 ,mem_vec_12271 ,mem_vec_12272 ,mem_vec_12273 ,mem_vec_12274 ,mem_vec_12275 ,mem_vec_12276 ,mem_vec_12277 ,mem_vec_12278 ,mem_vec_12279 ,mem_vec_12280 ,mem_vec_12281 ,mem_vec_12282 ,mem_vec_12283 ,mem_vec_12284 ,mem_vec_12285 ,mem_vec_12286 ,mem_vec_12287 ,mem_vec_12288 ,mem_vec_12289 ,mem_vec_12290 ,mem_vec_12291 ,mem_vec_12292 ,mem_vec_12293 ,mem_vec_12294 ,mem_vec_12295 ,mem_vec_12296 ,mem_vec_12297 ,mem_vec_12298 ,mem_vec_12299 ,mem_vec_12300 ,mem_vec_12301 ,mem_vec_12302 ,mem_vec_12303 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f1257 = f1258, f1257_p_0 = 0;
	f1257 < f1258 + 256;
	f1257 += 64, f1257_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (x, 68) (68 / 1)
	for (x994 = x995, x994_p_0 = 0;
		x994 < x995 + 68;
		x994 += 1, x994_p_0 += 1){
		// y = 68, x = 1, h = 3, w = 3, c = 128, f = 64
		// T (f, 1) (64 / 64)
		for (f1256 = f1257, f1256_p_1 = f1257_p_0, f1256_p_0 = 0;
			f1256 < f1257 + 64;
			f1256 += 64, f1256_p_1 += 64, f1256_p_0 += 64){
			// y = 68, x = 1, h = 3, w = 3, c = 128, f = 64
			// T (c, 32) (128 / 4)
			for (c942 = c943, c942_p_0 = 0;
				c942 < c943 + 128;
				c942 += 4, c942_p_0 += 4){
				// y = 68, x = 1, h = 3, w = 3, c = 4, f = 64
				// T (f, 2) (64 / 32)
				for (f = f1256, fp_2 = f1256_p_1, fp_1 = f1256_p_0, fp_0 = 0;
					f < f1256 + 64;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y628, yp_0 = 0;
							y < y628 + 12;
							y += 12, yp_0 += 12){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h628, hp_0 = 0;
								h < h628 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w576, wp_0 = 0;
									w < w576 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (x, 1) (1 / 1)
									for (x = x994, xp_1 = x994_p_0, xp_0 = 0;
										x < x994 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_12252 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_12253 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_12254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_12255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_12256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_12257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_12258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_12259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_12260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_12261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_12262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_12263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_12264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_12265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_12266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_12267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_12268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_12269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_12270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_12271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_12272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_12273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_12274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_12275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c942, cp_1 = c942_p_0, cp_0 = 0;
													c < c942 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12252);
													mem_vec_12252 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12253);
													mem_vec_12253 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_12254);
													mem_vec_12254 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_12255);
													mem_vec_12255 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_12256);
													mem_vec_12256 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_12257);
													mem_vec_12257 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_12258);
													mem_vec_12258 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_12259);
													mem_vec_12259 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12260);
													mem_vec_12260 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12261);
													mem_vec_12261 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_12262);
													mem_vec_12262 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_12263);
													mem_vec_12263 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_12264);
													mem_vec_12264 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_12265);
													mem_vec_12265 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_12266);
													mem_vec_12266 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_12267);
													mem_vec_12267 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_12268);
													mem_vec_12268 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_12269);
													mem_vec_12269 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_12270);
													mem_vec_12270 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_12271);
													mem_vec_12271 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_12272);
													mem_vec_12272 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_12273);
													mem_vec_12273 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_12274);
													mem_vec_12274 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_12275);
													mem_vec_12275 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12252);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12253);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12254);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12255);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12256);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12257);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12258);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12259);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12260);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12261);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12262);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12263);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_12264);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_12265);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_12266);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_12267);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_12268);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_12269);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_12270);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_12271);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_12272);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_12273);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_12274);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_12275);
									}
								}
							}
						}
						for (y = y628 + 12, yp_0 = 0;
							y < y628 + 12 + 56;
							y += 14, yp_0 += 14){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h628, hp_0 = 0;
								h < h628 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w576, wp_0 = 0;
									w < w576 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (x, 1) (1 / 1)
									for (x = x994, xp_1 = x994_p_0, xp_0 = 0;
										x < x994 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_12276 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_12277 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_12278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_12279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_12280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_12281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_12282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_12283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_12284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_12285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_12286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_12287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_12288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_12289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_12290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_12291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_12292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_12293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_12294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_12295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_12296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_12297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_12298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_12299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_12300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_12301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_12302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_12303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c942, cp_1 = c942_p_0, cp_0 = 0;
													c < c942 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12276);
													mem_vec_12276 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12277);
													mem_vec_12277 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_12278);
													mem_vec_12278 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_12279);
													mem_vec_12279 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_12280);
													mem_vec_12280 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_12281);
													mem_vec_12281 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_12282);
													mem_vec_12282 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_12283);
													mem_vec_12283 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12284);
													mem_vec_12284 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12285);
													mem_vec_12285 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_12286);
													mem_vec_12286 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_12287);
													mem_vec_12287 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_12288);
													mem_vec_12288 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_12289);
													mem_vec_12289 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_12290);
													mem_vec_12290 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_12291);
													mem_vec_12291 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_12292);
													mem_vec_12292 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_12293);
													mem_vec_12293 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_12294);
													mem_vec_12294 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_12295);
													mem_vec_12295 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_12296);
													mem_vec_12296 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_12297);
													mem_vec_12297 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_12298);
													mem_vec_12298 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_12299);
													mem_vec_12299 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_12300);
													mem_vec_12300 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_12301);
													mem_vec_12301 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_12302);
													mem_vec_12302 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_12303);
													mem_vec_12303 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12276);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12277);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12278);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12279);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12280);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12281);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12282);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12283);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12284);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12285);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12286);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12287);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_12288);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_12289);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_12290);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_12291);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_12292);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_12293);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_12294);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_12295);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_12296);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_12297);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_12298);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_12299);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_12300);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_12301);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_12302);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_12303);
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