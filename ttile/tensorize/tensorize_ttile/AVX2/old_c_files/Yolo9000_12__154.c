#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (34, x); T (2, y); T (1, f); T (32, c); T (2, f);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (8, f)]
*/
IND_TYPE c, cp_0, c15_p_0, cp_1, c15, f, fp_0, f20_p_0, f21_p_0, fp_1, f20_p_1, fp_2, f20, f21, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y15_p_0, yp_1, y15;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y16 = 0;
IND_TYPE x10 = 0;
IND_TYPE h10 = 0;
IND_TYPE w10 = 0;
IND_TYPE c16 = 0;
IND_TYPE f22 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,mem_vec_184 ,mem_vec_185 ,mem_vec_186 ,mem_vec_187 ,mem_vec_188 ,mem_vec_189 ,mem_vec_190 ,mem_vec_191 ,mem_vec_192 ,mem_vec_193 ,mem_vec_194 ,mem_vec_195 ,mem_vec_196 ,mem_vec_197 ,mem_vec_198 ,mem_vec_199 ,mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,mem_vec_208 ,mem_vec_209 ,mem_vec_210 ,mem_vec_211 ,mem_vec_212 ,mem_vec_213 ,mem_vec_214 ,mem_vec_215 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 8) (512 / 64)
for (f21 = f22, f21_p_0 = 0;
	f21 < f22 + 512;
	f21 += 64, f21_p_0 += 64){
		for (y15 = y16, y15_p_0 = 0;
			y15 < y16 + 24;
			y15 += 8, y15_p_0 += 8){
			// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
			// T (f, 2) (64 / 32)
			for (f20 = f21, f20_p_1 = f21_p_0, f20_p_0 = 0;
				f20 < f21 + 64;
				f20 += 32, f20_p_1 += 32, f20_p_0 += 32){
				// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
				// T (c, 32) (256 / 8)
				for (c15 = c16, c15_p_0 = 0;
					c15 < c16 + 256;
					c15 += 8, c15_p_0 += 8){
					// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
					// T (f, 1) (32 / 32)
					for (f = f20, fp_2 = f20_p_1, fp_1 = f20_p_0, fp_0 = 0;
						f < f20 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y15, yp_1 = y15_p_0, yp_0 = 0;
							y < y15 + 8;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
							// T (x, 34) (34 / 1)
							for (x = x10, xp_0 = 0;
								x < x10 + 34;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h10, hp_0 = 0;
									h < h10 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (w, 3) (3 / 1)
									for (w = w10, wp_0 = 0;
										w < w10 + 3;
										w += 1, wp_0 += 1){
												mem_vec_180 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_181 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_182 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_183 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_184 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_185 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_186 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_187 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_188 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_189 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_190 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_191 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_192 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_193 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_194 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_195 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c15, cp_1 = c15_p_0, cp_0 = 0;
													c < c15 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_180);
													mem_vec_180 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_181);
													mem_vec_181 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_182);
													mem_vec_182 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_183);
													mem_vec_183 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_184);
													mem_vec_184 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_185);
													mem_vec_185 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_186);
													mem_vec_186 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_187);
													mem_vec_187 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_188);
													mem_vec_188 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_189);
													mem_vec_189 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_190);
													mem_vec_190 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_191);
													mem_vec_191 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_192);
													mem_vec_192 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_193);
													mem_vec_193 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_194);
													mem_vec_194 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_195);
													mem_vec_195 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_180);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_181);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_182);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_183);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_184);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_185);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_186);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_187);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_188);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_189);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_190);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_191);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_192);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_193);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_194);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_195);
									}
								}
							}
						}
					}
				}
			}
		}
		for (y15 = y16 + 24, y15_p_0 = 0;
			y15 < y16 + 24 + 10;
			y15 += 10, y15_p_0 += 10){
			// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
			// T (f, 2) (64 / 32)
			for (f20 = f21, f20_p_1 = f21_p_0, f20_p_0 = 0;
				f20 < f21 + 64;
				f20 += 32, f20_p_1 += 32, f20_p_0 += 32){
				// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
				// T (c, 32) (256 / 8)
				for (c15 = c16, c15_p_0 = 0;
					c15 < c16 + 256;
					c15 += 8, c15_p_0 += 8){
					// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
					// T (f, 1) (32 / 32)
					for (f = f20, fp_2 = f20_p_1, fp_1 = f20_p_0, fp_0 = 0;
						f < f20 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y15, yp_1 = y15_p_0, yp_0 = 0;
							y < y15 + 10;
							y += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
							// T (x, 34) (34 / 1)
							for (x = x10, xp_0 = 0;
								x < x10 + 34;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h10, hp_0 = 0;
									h < h10 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (w, 3) (3 / 1)
									for (w = w10, wp_0 = 0;
										w < w10 + 3;
										w += 1, wp_0 += 1){
												mem_vec_196 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_197 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_198 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_199 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_200 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_201 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_202 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_203 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_204 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_205 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_206 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_207 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_208 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_209 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_210 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_211 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_212 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_213 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_214 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_215 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c15, cp_1 = c15_p_0, cp_0 = 0;
													c < c15 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_196);
													mem_vec_196 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_197);
													mem_vec_197 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_198);
													mem_vec_198 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_199);
													mem_vec_199 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_200);
													mem_vec_200 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_201);
													mem_vec_201 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_202);
													mem_vec_202 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_203);
													mem_vec_203 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_204);
													mem_vec_204 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_205);
													mem_vec_205 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_206);
													mem_vec_206 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_207);
													mem_vec_207 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_208);
													mem_vec_208 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_209);
													mem_vec_209 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_210);
													mem_vec_210 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_211);
													mem_vec_211 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_212);
													mem_vec_212 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_213);
													mem_vec_213 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_214);
													mem_vec_214 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_215);
													mem_vec_215 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_196);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_197);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_198);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_199);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_200);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_201);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_202);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_203);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_204);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_205);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_206);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_207);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_208);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_209);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_210);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_211);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_212);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_213);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_214);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_215);
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