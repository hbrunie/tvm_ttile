#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (34, x); T (2, y); T (1, f); T (8, c); T (1, f);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (16, f)]
*/
IND_TYPE c, cp_0, c461_p_0, cp_1, c461, f, fp_0, f372_p_0, f373_p_0, fp_1, f372_p_1, fp_2, f372, f373, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y265_p_0, yp_1, y265;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y266 = 0;
IND_TYPE x238 = 0;
IND_TYPE h182 = 0;
IND_TYPE w202 = 0;
IND_TYPE c462 = 0;
IND_TYPE f374 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_5192 ,mem_vec_5193 ,mem_vec_5194 ,mem_vec_5195 ,mem_vec_5196 ,mem_vec_5197 ,mem_vec_5198 ,mem_vec_5199 ,mem_vec_5200 ,mem_vec_5201 ,mem_vec_5202 ,mem_vec_5203 ,mem_vec_5204 ,mem_vec_5205 ,mem_vec_5206 ,mem_vec_5207 ,mem_vec_5208 ,mem_vec_5209 ,mem_vec_5210 ,mem_vec_5211 ,mem_vec_5212 ,mem_vec_5213 ,mem_vec_5214 ,mem_vec_5215 ,mem_vec_5216 ,mem_vec_5217 ,mem_vec_5218 ,mem_vec_5219 ,mem_vec_5220 ,mem_vec_5221 ,mem_vec_5222 ,mem_vec_5223 ,mem_vec_5224 ,mem_vec_5225 ,mem_vec_5226 ,mem_vec_5227 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 16) (512 / 32)
for (f373 = f374, f373_p_0 = 0;
	f373 < f374 + 512;
	f373 += 32, f373_p_0 += 32){
		for (y265 = y266, y265_p_0 = 0;
			y265 < y266 + 24;
			y265 += 8, y265_p_0 += 8){
			// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
			// T (f, 1) (32 / 32)
			for (f372 = f373, f372_p_1 = f373_p_0, f372_p_0 = 0;
				f372 < f373 + 32;
				f372 += 32, f372_p_1 += 32, f372_p_0 += 32){
				// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
				// T (c, 8) (256 / 32)
				for (c461 = c462, c461_p_0 = 0;
					c461 < c462 + 256;
					c461 += 32, c461_p_0 += 32){
					// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
					// T (f, 1) (32 / 32)
					for (f = f372, fp_2 = f372_p_1, fp_1 = f372_p_0, fp_0 = 0;
						f < f372 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y265, yp_1 = y265_p_0, yp_0 = 0;
							y < y265 + 8;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
							// T (x, 34) (34 / 1)
							for (x = x238, xp_0 = 0;
								x < x238 + 34;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h182, hp_0 = 0;
									h < h182 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (w, 3) (3 / 1)
									for (w = w202, wp_0 = 0;
										w < w202 + 3;
										w += 1, wp_0 += 1){
												mem_vec_5192 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5193 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_5194 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5195 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_5196 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5197 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_5198 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5199 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_5200 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5201 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_5202 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5203 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_5204 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5205 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_5206 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5207 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c461, cp_1 = c461_p_0, cp_0 = 0;
													c < c461 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5192);
													mem_vec_5192 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5193);
													mem_vec_5193 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5194);
													mem_vec_5194 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5195);
													mem_vec_5195 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5196);
													mem_vec_5196 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5197);
													mem_vec_5197 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5198);
													mem_vec_5198 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5199);
													mem_vec_5199 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5200);
													mem_vec_5200 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5201);
													mem_vec_5201 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5202);
													mem_vec_5202 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5203);
													mem_vec_5203 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5204);
													mem_vec_5204 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5205);
													mem_vec_5205 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5206);
													mem_vec_5206 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5207);
													mem_vec_5207 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5192);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5193);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5194);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5195);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5196);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5197);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5198);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5199);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5200);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5201);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5202);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5203);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5204);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5205);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5206);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5207);
									}
								}
							}
						}
					}
				}
			}
		}
		for (y265 = y266 + 24, y265_p_0 = 0;
			y265 < y266 + 24 + 10;
			y265 += 10, y265_p_0 += 10){
			// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
			// T (f, 1) (32 / 32)
			for (f372 = f373, f372_p_1 = f373_p_0, f372_p_0 = 0;
				f372 < f373 + 32;
				f372 += 32, f372_p_1 += 32, f372_p_0 += 32){
				// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
				// T (c, 8) (256 / 32)
				for (c461 = c462, c461_p_0 = 0;
					c461 < c462 + 256;
					c461 += 32, c461_p_0 += 32){
					// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
					// T (f, 1) (32 / 32)
					for (f = f372, fp_2 = f372_p_1, fp_1 = f372_p_0, fp_0 = 0;
						f < f372 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y265, yp_1 = y265_p_0, yp_0 = 0;
							y < y265 + 10;
							y += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
							// T (x, 34) (34 / 1)
							for (x = x238, xp_0 = 0;
								x < x238 + 34;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h182, hp_0 = 0;
									h < h182 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (w, 3) (3 / 1)
									for (w = w202, wp_0 = 0;
										w < w202 + 3;
										w += 1, wp_0 += 1){
												mem_vec_5208 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5209 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_5210 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5211 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_5212 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5213 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_5214 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5215 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_5216 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5217 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_5218 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5219 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_5220 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5221 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_5222 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5223 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_5224 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5225 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_5226 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5227 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c461, cp_1 = c461_p_0, cp_0 = 0;
													c < c461 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5208);
													mem_vec_5208 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5209);
													mem_vec_5209 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5210);
													mem_vec_5210 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5211);
													mem_vec_5211 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5212);
													mem_vec_5212 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5213);
													mem_vec_5213 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5214);
													mem_vec_5214 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5215);
													mem_vec_5215 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5216);
													mem_vec_5216 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5217);
													mem_vec_5217 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5218);
													mem_vec_5218 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5219);
													mem_vec_5219 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5220);
													mem_vec_5220 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5221);
													mem_vec_5221 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5222);
													mem_vec_5222 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5223);
													mem_vec_5223 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5224);
													mem_vec_5224 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5225);
													mem_vec_5225 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5226);
													mem_vec_5226 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5227);
													mem_vec_5227 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5208);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5209);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5210);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5211);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5212);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5213);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5214);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5215);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5216);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5217);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5218);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5219);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5220);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5221);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5222);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5223);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5224);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5225);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5226);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5227);
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