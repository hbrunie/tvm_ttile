#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (2, f); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (1, f);
  T (8, c); T (4, f)]
*/
IND_TYPE c, cp_0, c420_p_0, cp_1, c420, f, fp_0, f560_p_0, f561_p_0, fp_1, f560_p_1, fp_2, f560, f561, h, hp_0, w, wp_0, x, xp_0, x420_p_0, xp_1, x420, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y280 = 0;
IND_TYPE x421 = 0;
IND_TYPE h234 = 0;
IND_TYPE w216 = 0;
IND_TYPE c421 = 0;
IND_TYPE f562 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_4160 ,mem_vec_4161 ,mem_vec_4162 ,mem_vec_4163 ,mem_vec_4164 ,mem_vec_4165 ,mem_vec_4166 ,mem_vec_4167 ,mem_vec_4168 ,mem_vec_4169 ,mem_vec_4170 ,mem_vec_4171 ,mem_vec_4172 ,mem_vec_4173 ,mem_vec_4174 ,mem_vec_4175 ,mem_vec_4176 ,mem_vec_4177 ,mem_vec_4178 ,mem_vec_4179 ,mem_vec_4180 ,mem_vec_4181 ,mem_vec_4182 ,mem_vec_4183 ,mem_vec_4184 ,mem_vec_4185 ,mem_vec_4186 ,mem_vec_4187 ,mem_vec_4188 ,mem_vec_4189 ,mem_vec_4190 ,mem_vec_4191 ,mem_vec_4192 ,mem_vec_4193 ,mem_vec_4194 ,mem_vec_4195 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f561 = f562, f561_p_0 = 0;
	f561 < f562 + 256;
	f561 += 64, f561_p_0 += 64){
	// y = 14, x = 14, h = 3, w = 3, c = 128, f = 64
	// T (c, 8) (128 / 16)
	for (c420 = c421, c420_p_0 = 0;
		c420 < c421 + 128;
		c420 += 16, c420_p_0 += 16){
		// y = 14, x = 14, h = 3, w = 3, c = 16, f = 64
		// T (f, 1) (64 / 64)
		for (f560 = f561, f560_p_1 = f561_p_0, f560_p_0 = 0;
			f560 < f561 + 64;
			f560 += 64, f560_p_1 += 64, f560_p_0 += 64){
				for (y = y280, yp_0 = 0;
					y < y280 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 64
					// T (x, 2) (14 / 7)
					for (x420 = x421, x420_p_0 = 0;
						x420 < x421 + 14;
						x420 += 7, x420_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
						// T (f, 2) (64 / 32)
						for (f = f560, fp_2 = f560_p_1, fp_1 = f560_p_0, fp_0 = 0;
							f < f560 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h234, hp_0 = 0;
								h < h234 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w216, wp_0 = 0;
									w < w216 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 1, c = 16, f = 32
									// T (x, 7) (7 / 1)
									for (x = x420, xp_1 = x420_p_0, xp_0 = 0;
										x < x420 + 7;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_4160 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4161 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_4162 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4163 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_4164 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4165 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_4166 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4167 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_4168 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4169 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_4170 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4171 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_4172 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4173 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_4174 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4175 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c420, cp_1 = c420_p_0, cp_0 = 0;
													c < c420 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4160);
													mem_vec_4160 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4161);
													mem_vec_4161 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4162);
													mem_vec_4162 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4163);
													mem_vec_4163 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4164);
													mem_vec_4164 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4165);
													mem_vec_4165 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4166);
													mem_vec_4166 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4167);
													mem_vec_4167 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4168);
													mem_vec_4168 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4169);
													mem_vec_4169 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4170);
													mem_vec_4170 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4171);
													mem_vec_4171 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4172);
													mem_vec_4172 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4173);
													mem_vec_4173 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4174);
													mem_vec_4174 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4175);
													mem_vec_4175 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4160);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4161);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4162);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4163);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4164);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4165);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4166);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4167);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4168);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4169);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4170);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4171);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4172);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4173);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4174);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4175);
									}
								}
							}
						}
					}
				}
				for (y = y280 + 4, yp_0 = 0;
					y < y280 + 4 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 64
					// T (x, 2) (14 / 7)
					for (x420 = x421, x420_p_0 = 0;
						x420 < x421 + 14;
						x420 += 7, x420_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
						// T (f, 2) (64 / 32)
						for (f = f560, fp_2 = f560_p_1, fp_1 = f560_p_0, fp_0 = 0;
							f < f560 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h234, hp_0 = 0;
								h < h234 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w216, wp_0 = 0;
									w < w216 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 1, c = 16, f = 32
									// T (x, 7) (7 / 1)
									for (x = x420, xp_1 = x420_p_0, xp_0 = 0;
										x < x420 + 7;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_4176 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4177 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_4178 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4179 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_4180 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4181 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_4182 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4183 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_4184 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4185 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_4186 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4187 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_4188 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4189 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_4190 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4191 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_4192 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_4193 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_4194 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_4195 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c420, cp_1 = c420_p_0, cp_0 = 0;
													c < c420 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4176);
													mem_vec_4176 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4177);
													mem_vec_4177 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4178);
													mem_vec_4178 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4179);
													mem_vec_4179 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4180);
													mem_vec_4180 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4181);
													mem_vec_4181 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4182);
													mem_vec_4182 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4183);
													mem_vec_4183 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4184);
													mem_vec_4184 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4185);
													mem_vec_4185 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4186);
													mem_vec_4186 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4187);
													mem_vec_4187 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4188);
													mem_vec_4188 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4189);
													mem_vec_4189 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4190);
													mem_vec_4190 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4191);
													mem_vec_4191 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_4192);
													mem_vec_4192 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_4193);
													mem_vec_4193 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_4194);
													mem_vec_4194 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_4195);
													mem_vec_4195 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4176);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4177);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4178);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4179);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4180);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4181);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4182);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4183);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4184);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4185);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4186);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4187);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4188);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4189);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4190);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4191);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4192);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_4193);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4194);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_4195);
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