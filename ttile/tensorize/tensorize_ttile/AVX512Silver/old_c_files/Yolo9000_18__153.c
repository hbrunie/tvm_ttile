#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (2, f);
  T (32, c); T (16, f)]
*/
IND_TYPE c, cp_0, c24_p_0, c25_p_0, cp_1, c24_p_1, cp_2, c24, c25, f, fp_0, f18_p_0, fp_1, f18, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y12 = 0;
IND_TYPE x12 = 0;
IND_TYPE h10 = 0;
IND_TYPE w12 = 0;
IND_TYPE c26 = 0;
IND_TYPE f19 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_187 ,mem_vec_188 ,mem_vec_189 ,mem_vec_190 ,mem_vec_191 ,mem_vec_192 ,mem_vec_193 ,mem_vec_194 ,mem_vec_195 ,mem_vec_196 ,mem_vec_197 ,mem_vec_198 ,mem_vec_199 ,mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,mem_vec_208 ,mem_vec_209 ,mem_vec_210 ,mem_vec_211 ,mem_vec_212 ,mem_vec_213 ,mem_vec_214 ,mem_vec_215 ,mem_vec_216 ,mem_vec_217 ,mem_vec_218 ,mem_vec_219 ,mem_vec_220 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 16) (1024 / 64)
for (f18 = f19, f18_p_0 = 0;
	f18 < f19 + 1024;
	f18 += 64, f18_p_0 += 64){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 64
	// T (c, 32) (512 / 16)
	for (c25 = c26, c25_p_0 = 0;
		c25 < c26 + 512;
		c25 += 16, c25_p_0 += 16){
		// y = 17, x = 17, h = 3, w = 3, c = 16, f = 64
		// T (f, 2) (64 / 32)
		for (f = f18, fp_1 = f18_p_0, fp_0 = 0;
			f < f18 + 64;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y12, yp_0 = 0;
					y < y12 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
					// T (c, 1) (16 / 16)
					for (c24 = c25, c24_p_1 = c25_p_0, c24_p_0 = 0;
						c24 < c25 + 16;
						c24 += 16, c24_p_1 += 16, c24_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x12, xp_0 = 0;
							x < x12 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h10, hp_0 = 0;
								h < h10 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w12, wp_0 = 0;
									w < w12 + 3;
									w += 1, wp_0 += 1){
											mem_vec_187 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_188 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c24, cp_2 = c24_p_1, cp_1 = c24_p_0, cp_0 = 0;
												c < c24 + 16;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_187);
												mem_vec_187 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_188);
												mem_vec_188 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_189);
												mem_vec_189 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_190);
												mem_vec_190 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_191);
												mem_vec_191 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_192);
												mem_vec_192 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_193);
												mem_vec_193 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_194);
												mem_vec_194 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_195);
												mem_vec_195 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_196);
												mem_vec_196 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_197);
												mem_vec_197 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_198);
												mem_vec_198 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_199);
												mem_vec_199 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_200);
												mem_vec_200 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_201);
												mem_vec_201 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_202);
												mem_vec_202 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_187);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_188);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_189);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_190);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_191);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_192);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_193);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_194);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_195);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_196);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_197);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_198);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_199);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_200);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_201);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_202);
								}
							}
						}
					}
				}
				for (y = y12 + 8, yp_0 = 0;
					y < y12 + 8 + 9;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
					// T (c, 1) (16 / 16)
					for (c24 = c25, c24_p_1 = c25_p_0, c24_p_0 = 0;
						c24 < c25 + 16;
						c24 += 16, c24_p_1 += 16, c24_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x12, xp_0 = 0;
							x < x12 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h10, hp_0 = 0;
								h < h10 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w12, wp_0 = 0;
									w < w12 + 3;
									w += 1, wp_0 += 1){
											mem_vec_203 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_204 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c24, cp_2 = c24_p_1, cp_1 = c24_p_0, cp_0 = 0;
												c < c24 + 16;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_203);
												mem_vec_203 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_204);
												mem_vec_204 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_205);
												mem_vec_205 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_206);
												mem_vec_206 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_207);
												mem_vec_207 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_208);
												mem_vec_208 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_209);
												mem_vec_209 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_210);
												mem_vec_210 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_211);
												mem_vec_211 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_212);
												mem_vec_212 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_213);
												mem_vec_213 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_214);
												mem_vec_214 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_215);
												mem_vec_215 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_216);
												mem_vec_216 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_217);
												mem_vec_217 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_218);
												mem_vec_218 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_219);
												mem_vec_219 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_220);
												mem_vec_220 = vec_28;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_203);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_204);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_205);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_206);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_207);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_208);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_209);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_210);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_211);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_212);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_213);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_214);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_215);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_216);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_217);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_218);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_219);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_220);
								}
							}
						}
					}
				}
		}
	}
}


}