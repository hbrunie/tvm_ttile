#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (1, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 3), (Arg 9))]; T (8, f);
  T (4, c); T (2, f)]
*/
IND_TYPE c, cp_0, c42_p_0, cp_1, c42, f, fp_0, f56_p_0, f57_p_0, fp_1, f56_p_1, fp_2, f56, f57, h, hp_0, w, wp_0, x, xp_0, x42_p_0, xp_1, x42, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y28 = 0;
IND_TYPE x43 = 0;
IND_TYPE h20 = 0;
IND_TYPE w26 = 0;
IND_TYPE c43 = 0;
IND_TYPE f58 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_208 ,mem_vec_209 ,mem_vec_210 ,mem_vec_211 ,mem_vec_212 ,mem_vec_213 ,mem_vec_214 ,mem_vec_215 ,mem_vec_216 ,mem_vec_217 ,mem_vec_218 ,mem_vec_219 ,mem_vec_220 ,mem_vec_221 ,mem_vec_222 ,mem_vec_223 ,mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,mem_vec_232 ,mem_vec_233 ,mem_vec_234 ,mem_vec_235 ,mem_vec_236 ,mem_vec_237 ,mem_vec_238 ,mem_vec_239 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f57 = f58, f57_p_0 = 0;
	f57 < f58 + 512;
	f57 += 256, f57_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (c, 4) (256 / 64)
	for (c42 = c43, c42_p_0 = 0;
		c42 < c43 + 256;
		c42 += 64, c42_p_0 += 64){
		// y = 34, x = 34, h = 3, w = 3, c = 64, f = 256
		// T (f, 8) (256 / 32)
		for (f56 = f57, f56_p_1 = f57_p_0, f56_p_0 = 0;
			f56 < f57 + 256;
			f56 += 32, f56_p_1 += 32, f56_p_0 += 32){
				for (y = y28, yp_0 = 0;
					y < y28 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
					// T (x, 17) (34 / 2)
					for (x42 = x43, x42_p_0 = 0;
						x42 < x43 + 34;
						x42 += 2, x42_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
						// T (f, 1) (32 / 32)
						for (f = f56, fp_2 = f56_p_1, fp_1 = f56_p_0, fp_0 = 0;
							f < f56 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h20, hp_0 = 0;
								h < h20 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w26, wp_0 = 0;
									w < w26 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 32
									// T (x, 2) (2 / 1)
									for (x = x42, xp_1 = x42_p_0, xp_0 = 0;
										x < x42 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_208 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_209 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c42, cp_1 = c42_p_0, cp_0 = 0;
													c < c42 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_208);
													mem_vec_208 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_209);
													mem_vec_209 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_210);
													mem_vec_210 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_211);
													mem_vec_211 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_212);
													mem_vec_212 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_213);
													mem_vec_213 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_214);
													mem_vec_214 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_215);
													mem_vec_215 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_216);
													mem_vec_216 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_217);
													mem_vec_217 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_218);
													mem_vec_218 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_219);
													mem_vec_219 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_220);
													mem_vec_220 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_221);
													mem_vec_221 = vec_22;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_208);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_209);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_210);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_211);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_212);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_213);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_214);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_215);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_216);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_217);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_218);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_219);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_220);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_221);
									}
								}
							}
						}
					}
				}
				for (y = y28 + 7, yp_0 = 0;
					y < y28 + 7 + 27;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
					// T (x, 17) (34 / 2)
					for (x42 = x43, x42_p_0 = 0;
						x42 < x43 + 34;
						x42 += 2, x42_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
						// T (f, 1) (32 / 32)
						for (f = f56, fp_2 = f56_p_1, fp_1 = f56_p_0, fp_0 = 0;
							f < f56 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h20, hp_0 = 0;
								h < h20 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w26, wp_0 = 0;
									w < w26 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 32
									// T (x, 2) (2 / 1)
									for (x = x42, xp_1 = x42_p_0, xp_0 = 0;
										x < x42 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_222 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_223 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c42, cp_1 = c42_p_0, cp_0 = 0;
													c < c42 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_222);
													mem_vec_222 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_223);
													mem_vec_223 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_224);
													mem_vec_224 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_225);
													mem_vec_225 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_226);
													mem_vec_226 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_227);
													mem_vec_227 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_228);
													mem_vec_228 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_229);
													mem_vec_229 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_230);
													mem_vec_230 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_231);
													mem_vec_231 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_232);
													mem_vec_232 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_233);
													mem_vec_233 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_234);
													mem_vec_234 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_235);
													mem_vec_235 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_236);
													mem_vec_236 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_237);
													mem_vec_237 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_238);
													mem_vec_238 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_239);
													mem_vec_239 = vec_28;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_222);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_223);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_224);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_225);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_226);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_227);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_228);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_229);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_230);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_231);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_232);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_233);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_234);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_235);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_236);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_237);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_238);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_239);
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