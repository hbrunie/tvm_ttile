#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (8, c); T (8, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (2, x);
  T (1, f); T (1, f)]
*/
IND_TYPE c, cp_0, c15_p_0, cp_1, c15, f, fp_0, f20_p_0, f21_p_0, fp_1, f20_p_1, fp_2, f20, f21, h, hp_0, w, wp_0, x, xp_0, x15_p_0, xp_1, x15, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y10 = 0;
IND_TYPE x16 = 0;
IND_TYPE h10 = 0;
IND_TYPE w10 = 0;
IND_TYPE c16 = 0;
IND_TYPE f22 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,mem_vec_208 ,mem_vec_209 ,mem_vec_210 ,mem_vec_211 ,mem_vec_212 ,mem_vec_213 ,mem_vec_214 ,mem_vec_215 ,mem_vec_216 ,mem_vec_217 ,mem_vec_218 ,mem_vec_219 ,mem_vec_220 ,mem_vec_221 ,mem_vec_222 ,mem_vec_223 ,mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,mem_vec_232 ,mem_vec_233 ,mem_vec_234 ,mem_vec_235 ,mem_vec_236 ,mem_vec_237 ,mem_vec_238 ,mem_vec_239 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f21 = f22, f21_p_0 = 0;
	f21 < f22 + 256;
	f21 += 256, f21_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (f, 1) (256 / 256)
	for (f20 = f21, f20_p_1 = f21_p_0, f20_p_0 = 0;
		f20 < f21 + 256;
		f20 += 256, f20_p_1 += 256, f20_p_0 += 256){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
		// T (x, 2) (68 / 34)
		for (x15 = x16, x15_p_0 = 0;
			x15 < x16 + 68;
			x15 += 34, x15_p_0 += 34){
				for (y = y10, yp_0 = 0;
					y < y10 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 256
					// T (f, 8) (256 / 32)
					for (f = f20, fp_2 = f20_p_1, fp_1 = f20_p_0, fp_0 = 0;
						f < f20 + 256;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c15 = c16, c15_p_0 = 0;
							c15 < c16 + 128;
							c15 += 16, c15_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w10, wp_0 = 0;
								w < w10 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x15, xp_1 = x15_p_0, xp_0 = 0;
									x < x15 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h10, hp_0 = 0;
										h < h10 + 3;
										h += 1, hp_0 += 1){
												mem_vec_200 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_201 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c15, cp_1 = c15_p_0, cp_0 = 0;
													c < c15 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_200);
													mem_vec_200 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_201);
													mem_vec_201 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_202);
													mem_vec_202 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_203);
													mem_vec_203 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_204);
													mem_vec_204 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_205);
													mem_vec_205 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_206);
													mem_vec_206 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_207);
													mem_vec_207 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_208);
													mem_vec_208 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_209);
													mem_vec_209 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_210);
													mem_vec_210 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_211);
													mem_vec_211 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_212);
													mem_vec_212 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_213);
													mem_vec_213 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_214);
													mem_vec_214 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_215);
													mem_vec_215 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_200);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_201);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_202);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_203);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_204);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_205);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_206);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_207);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_208);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_209);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_210);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_211);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_212);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_213);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_214);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_215);
									}
								}
							}
						}
					}
				}
				for (y = y10 + 8, yp_0 = 0;
					y < y10 + 8 + 60;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 256
					// T (f, 8) (256 / 32)
					for (f = f20, fp_2 = f20_p_1, fp_1 = f20_p_0, fp_0 = 0;
						f < f20 + 256;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c15 = c16, c15_p_0 = 0;
							c15 < c16 + 128;
							c15 += 16, c15_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w10, wp_0 = 0;
								w < w10 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x15, xp_1 = x15_p_0, xp_0 = 0;
									x < x15 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h10, hp_0 = 0;
										h < h10 + 3;
										h += 1, hp_0 += 1){
												mem_vec_216 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_217 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c15, cp_1 = c15_p_0, cp_0 = 0;
													c < c15 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_216);
													mem_vec_216 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_217);
													mem_vec_217 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_218);
													mem_vec_218 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_219);
													mem_vec_219 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_220);
													mem_vec_220 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_221);
													mem_vec_221 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_222);
													mem_vec_222 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_223);
													mem_vec_223 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_224);
													mem_vec_224 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_225);
													mem_vec_225 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_226);
													mem_vec_226 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_227);
													mem_vec_227 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_228);
													mem_vec_228 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_229);
													mem_vec_229 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_230);
													mem_vec_230 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_231);
													mem_vec_231 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_232);
													mem_vec_232 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_233);
													mem_vec_233 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_234);
													mem_vec_234 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_235);
													mem_vec_235 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_236);
													mem_vec_236 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_237);
													mem_vec_237 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_238);
													mem_vec_238 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_239);
													mem_vec_239 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_216);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_217);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_218);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_219);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_220);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_221);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_222);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_223);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_224);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_225);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_226);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_227);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_228);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_229);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_230);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_231);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_232);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_233);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_234);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_235);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_236);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_237);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_238);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_239);
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