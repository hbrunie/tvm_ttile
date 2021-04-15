#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (1, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 1), (Arg 10))]; T (16, f);
  T (256, c); T (2, f)]
*/
IND_TYPE c, cp_0, c18_p_0, cp_1, c18, f, fp_0, f24_p_0, f25_p_0, fp_1, f24_p_1, fp_2, f24, f25, h, hp_0, w, wp_0, x, xp_0, x18_p_0, xp_1, x18, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y12 = 0;
IND_TYPE x19 = 0;
IND_TYPE h12 = 0;
IND_TYPE w12 = 0;
IND_TYPE c19 = 0;
IND_TYPE f26 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,mem_vec_208 ,mem_vec_209 ,mem_vec_210 ,mem_vec_211 ,mem_vec_212 ,mem_vec_213 ,mem_vec_214 ,mem_vec_215 ,mem_vec_216 ,mem_vec_217 ,mem_vec_218 ,mem_vec_219 ,mem_vec_220 ,mem_vec_221 ,mem_vec_222 ,mem_vec_223 ,mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,mem_vec_232 ,mem_vec_233 ,mem_vec_234 ,mem_vec_235 ,mem_vec_236 ,mem_vec_237 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
for (f25 = f26, f25_p_0 = 0;
	f25 < f26 + 1024;
	f25 += 512, f25_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
	// T (c, 256) (512 / 2)
	for (c18 = c19, c18_p_0 = 0;
		c18 < c19 + 512;
		c18 += 2, c18_p_0 += 2){
		// y = 17, x = 17, h = 3, w = 3, c = 2, f = 512
		// T (f, 16) (512 / 32)
		for (f24 = f25, f24_p_1 = f25_p_0, f24_p_0 = 0;
			f24 < f25 + 512;
			f24 += 32, f24_p_1 += 32, f24_p_0 += 32){
				for (y = y12, yp_0 = 0;
					y < y12 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 32
					// T (x, 17) (17 / 1)
					for (x18 = x19, x18_p_0 = 0;
						x18 < x19 + 17;
						x18 += 1, x18_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
						// T (f, 1) (32 / 32)
						for (f = f24, fp_2 = f24_p_1, fp_1 = f24_p_0, fp_0 = 0;
							f < f24 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h12, hp_0 = 0;
								h < h12 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w12, wp_0 = 0;
									w < w12 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x18, xp_1 = x18_p_0, xp_0 = 0;
										x < x18 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_204 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_205 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c18, cp_1 = c18_p_0, cp_0 = 0;
													c < c18 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_204);
													mem_vec_204 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_205);
													mem_vec_205 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_206);
													mem_vec_206 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_207);
													mem_vec_207 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_208);
													mem_vec_208 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_209);
													mem_vec_209 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_210);
													mem_vec_210 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_211);
													mem_vec_211 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_212);
													mem_vec_212 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_213);
													mem_vec_213 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_214);
													mem_vec_214 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_215);
													mem_vec_215 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_216);
													mem_vec_216 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_217);
													mem_vec_217 = vec_22;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_204);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_205);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_206);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_207);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_208);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_209);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_210);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_211);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_212);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_213);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_214);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_215);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_216);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_217);
									}
								}
							}
						}
					}
				}
				for (y = y12 + 7, yp_0 = 0;
					y < y12 + 7 + 10;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 32
					// T (x, 17) (17 / 1)
					for (x18 = x19, x18_p_0 = 0;
						x18 < x19 + 17;
						x18 += 1, x18_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
						// T (f, 1) (32 / 32)
						for (f = f24, fp_2 = f24_p_1, fp_1 = f24_p_0, fp_0 = 0;
							f < f24 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h12, hp_0 = 0;
								h < h12 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w12, wp_0 = 0;
									w < w12 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x18, xp_1 = x18_p_0, xp_0 = 0;
										x < x18 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_218 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_219 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c18, cp_1 = c18_p_0, cp_0 = 0;
													c < c18 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_218);
													mem_vec_218 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_219);
													mem_vec_219 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_220);
													mem_vec_220 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_221);
													mem_vec_221 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_222);
													mem_vec_222 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_223);
													mem_vec_223 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_224);
													mem_vec_224 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_225);
													mem_vec_225 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_226);
													mem_vec_226 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_227);
													mem_vec_227 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_228);
													mem_vec_228 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_229);
													mem_vec_229 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_230);
													mem_vec_230 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_231);
													mem_vec_231 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_232);
													mem_vec_232 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_233);
													mem_vec_233 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_234);
													mem_vec_234 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_235);
													mem_vec_235 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_236);
													mem_vec_236 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_237);
													mem_vec_237 = vec_31;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_218);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_219);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_220);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_221);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_222);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_223);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_224);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_225);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_226);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_227);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_228);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_229);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_230);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_231);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_232);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_233);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_234);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_235);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_236);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_237);
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