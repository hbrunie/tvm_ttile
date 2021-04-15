#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (64, c); T (8, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (2, c);
  T (2, f); T (2, c)]
*/
IND_TYPE c, cp_0, c1188_p_0, c1189_p_0, c1190_p_0, cp_1, c1188_p_1, c1189_p_1, cp_2, c1188_p_2, cp_3, c1188, c1189, c1190, f, fp_0, f828_p_0, fp_1, f828, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y358 = 0;
IND_TYPE x504 = 0;
IND_TYPE h380 = 0;
IND_TYPE w384 = 0;
IND_TYPE c1191 = 0;
IND_TYPE f829 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_4172 ,mem_vec_4173 ,mem_vec_4174 ,mem_vec_4175 ,mem_vec_4176 ,mem_vec_4177 ,mem_vec_4178 ,mem_vec_4179 ,mem_vec_4180 ,mem_vec_4181 ,mem_vec_4182 ,mem_vec_4183 ,mem_vec_4184 ,mem_vec_4185 ,mem_vec_4186 ,mem_vec_4187 ,mem_vec_4188 ,mem_vec_4189 ,mem_vec_4190 ,mem_vec_4191 ,mem_vec_4192 ,mem_vec_4193 ,mem_vec_4194 ,mem_vec_4195 ,mem_vec_4196 ,mem_vec_4197 ,mem_vec_4198 ,mem_vec_4199 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 2) (1024 / 512)
for (c1190 = c1191, c1190_p_0 = 0;
	c1190 < c1191 + 1024;
	c1190 += 512, c1190_p_0 += 512){
	// y = 7, x = 7, h = 3, w = 3, c = 512, f = 1024
	// T (f, 2) (1024 / 512)
	for (f828 = f829, f828_p_0 = 0;
		f828 < f829 + 1024;
		f828 += 512, f828_p_0 += 512){
		// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
		// T (c, 2) (512 / 256)
		for (c1189 = c1190, c1189_p_1 = c1190_p_0, c1189_p_0 = 0;
			c1189 < c1190 + 512;
			c1189 += 256, c1189_p_1 += 256, c1189_p_0 += 256){
				for (y = y358, yp_0 = 0;
					y < y358 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 512
					// T (f, 8) (512 / 64)
					for (f = f828, fp_1 = f828_p_0, fp_0 = 0;
						f < f828 + 512;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 64
						// T (c, 64) (256 / 4)
						for (c1188 = c1189, c1188_p_2 = c1189_p_1, c1188_p_1 = c1189_p_0, c1188_p_0 = 0;
							c1188 < c1189 + 256;
							c1188 += 4, c1188_p_2 += 4, c1188_p_1 += 4, c1188_p_0 += 4){
							// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
							// T (h, 3) (3 / 1)
							for (h = h380, hp_0 = 0;
								h < h380 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 4, f = 64
								// T (w, 3) (3 / 1)
								for (w = w384, wp_0 = 0;
									w < w384 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 1, c = 4, f = 64
									// T (x, 7) (7 / 1)
									for (x = x504, xp_0 = 0;
										x < x504 + 7;
										x += 1, xp_0 += 1){
												mem_vec_4172 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4173 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4174 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_4175 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_4176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_4179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_4180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_4183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
												// T (c, 4) (4 / 1)
												for (c = c1188, cp_3 = c1188_p_2, cp_2 = c1188_p_1, cp_1 = c1188_p_0, cp_0 = 0;
													c < c1188 + 4;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4172);
													mem_vec_4172 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4173);
													mem_vec_4173 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4174);
													mem_vec_4174 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4175);
													mem_vec_4175 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4176);
													mem_vec_4176 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4177);
													mem_vec_4177 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4178);
													mem_vec_4178 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4179);
													mem_vec_4179 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4180);
													mem_vec_4180 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4181);
													mem_vec_4181 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4182);
													mem_vec_4182 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4183);
													mem_vec_4183 = vec_18;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4172);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4173);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4174);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4175);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4176);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4177);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4178);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4179);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4180);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4181);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4182);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4183);
									}
								}
							}
						}
					}
				}
				for (y = y358 + 3, yp_0 = 0;
					y < y358 + 3 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 512
					// T (f, 8) (512 / 64)
					for (f = f828, fp_1 = f828_p_0, fp_0 = 0;
						f < f828 + 512;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 64
						// T (c, 64) (256 / 4)
						for (c1188 = c1189, c1188_p_2 = c1189_p_1, c1188_p_1 = c1189_p_0, c1188_p_0 = 0;
							c1188 < c1189 + 256;
							c1188 += 4, c1188_p_2 += 4, c1188_p_1 += 4, c1188_p_0 += 4){
							// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
							// T (h, 3) (3 / 1)
							for (h = h380, hp_0 = 0;
								h < h380 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 4, f = 64
								// T (w, 3) (3 / 1)
								for (w = w384, wp_0 = 0;
									w < w384 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 1, c = 4, f = 64
									// T (x, 7) (7 / 1)
									for (x = x504, xp_0 = 0;
										x < x504 + 7;
										x += 1, xp_0 += 1){
												mem_vec_4184 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4185 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4186 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_4187 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_4188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_4191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_4192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_4195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_4196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_4199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
												// T (c, 4) (4 / 1)
												for (c = c1188, cp_3 = c1188_p_2, cp_2 = c1188_p_1, cp_1 = c1188_p_0, cp_0 = 0;
													c < c1188 + 4;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4184);
													mem_vec_4184 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4185);
													mem_vec_4185 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4186);
													mem_vec_4186 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4187);
													mem_vec_4187 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4188);
													mem_vec_4188 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4189);
													mem_vec_4189 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4190);
													mem_vec_4190 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4191);
													mem_vec_4191 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4192);
													mem_vec_4192 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4193);
													mem_vec_4193 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4194);
													mem_vec_4194 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4195);
													mem_vec_4195 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4196);
													mem_vec_4196 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4197);
													mem_vec_4197 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4198);
													mem_vec_4198 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4199);
													mem_vec_4199 = vec_23;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4184);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4185);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4186);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4187);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4188);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4189);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4190);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4191);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4192);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4193);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4194);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4195);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4196);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4197);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4198);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4199);
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