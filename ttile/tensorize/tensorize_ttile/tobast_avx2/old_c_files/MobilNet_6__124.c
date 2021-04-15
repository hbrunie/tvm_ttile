#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (1, f); T (14, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (1, f);
  T (256, c); T (8, f)]
*/
IND_TYPE c, cp_0, c510_p_0, cp_1, c510, f, fp_0, f680_p_0, f681_p_0, fp_1, f680_p_1, fp_2, f680, f681, h, hp_0, w, wp_0, x, xp_0, x510_p_0, xp_1, x510, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y340 = 0;
IND_TYPE x511 = 0;
IND_TYPE h284 = 0;
IND_TYPE w276 = 0;
IND_TYPE c511 = 0;
IND_TYPE f682 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_5160 ,mem_vec_5161 ,mem_vec_5162 ,mem_vec_5163 ,mem_vec_5164 ,mem_vec_5165 ,mem_vec_5166 ,mem_vec_5167 ,mem_vec_5168 ,mem_vec_5169 ,mem_vec_5170 ,mem_vec_5171 ,mem_vec_5172 ,mem_vec_5173 ,mem_vec_5174 ,mem_vec_5175 ,mem_vec_5176 ,mem_vec_5177 ,mem_vec_5178 ,mem_vec_5179 ,mem_vec_5180 ,mem_vec_5181 ,mem_vec_5182 ,mem_vec_5183 ,mem_vec_5184 ,mem_vec_5185 ,mem_vec_5186 ,mem_vec_5187 ,mem_vec_5188 ,mem_vec_5189 ,mem_vec_5190 ,mem_vec_5191 ,mem_vec_5192 ,mem_vec_5193 ,mem_vec_5194 ,mem_vec_5195 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 8) (256 / 32)
for (f681 = f682, f681_p_0 = 0;
	f681 < f682 + 256;
	f681 += 32, f681_p_0 += 32){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 32
	// T (c, 256) (256 / 1)
	for (c510 = c511, c510_p_0 = 0;
		c510 < c511 + 256;
		c510 += 1, c510_p_0 += 1){
		// y = 14, x = 14, h = 3, w = 3, c = 1, f = 32
		// T (f, 1) (32 / 32)
		for (f680 = f681, f680_p_1 = f681_p_0, f680_p_0 = 0;
			f680 < f681 + 32;
			f680 += 32, f680_p_1 += 32, f680_p_0 += 32){
				for (y = y340, yp_0 = 0;
					y < y340 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
					// T (x, 14) (14 / 1)
					for (x510 = x511, x510_p_0 = 0;
						x510 < x511 + 14;
						x510 += 1, x510_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
						// T (f, 1) (32 / 32)
						for (f = f680, fp_2 = f680_p_1, fp_1 = f680_p_0, fp_0 = 0;
							f < f680 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
							// T (h, 3) (3 / 1)
							for (h = h284, hp_0 = 0;
								h < h284 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w276, wp_0 = 0;
									w < w276 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (x, 1) (1 / 1)
									for (x = x510, xp_1 = x510_p_0, xp_0 = 0;
										x < x510 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5160 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5161 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_5162 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5163 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_5164 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5165 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_5166 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5167 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_5168 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5169 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_5170 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5171 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_5172 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5173 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_5174 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5175 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c510, cp_1 = c510_p_0, cp_0 = 0;
													c < c510 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5160);
													mem_vec_5160 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5161);
													mem_vec_5161 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5162);
													mem_vec_5162 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5163);
													mem_vec_5163 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5164);
													mem_vec_5164 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5165);
													mem_vec_5165 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5166);
													mem_vec_5166 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5167);
													mem_vec_5167 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5168);
													mem_vec_5168 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5169);
													mem_vec_5169 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5170);
													mem_vec_5170 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5171);
													mem_vec_5171 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5172);
													mem_vec_5172 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5173);
													mem_vec_5173 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5174);
													mem_vec_5174 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5175);
													mem_vec_5175 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5160);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5161);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5162);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5163);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5164);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5165);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5166);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5167);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5168);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5169);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5170);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5171);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5172);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5173);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5174);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5175);
									}
								}
							}
						}
					}
				}
				for (y = y340 + 4, yp_0 = 0;
					y < y340 + 4 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
					// T (x, 14) (14 / 1)
					for (x510 = x511, x510_p_0 = 0;
						x510 < x511 + 14;
						x510 += 1, x510_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
						// T (f, 1) (32 / 32)
						for (f = f680, fp_2 = f680_p_1, fp_1 = f680_p_0, fp_0 = 0;
							f < f680 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
							// T (h, 3) (3 / 1)
							for (h = h284, hp_0 = 0;
								h < h284 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w276, wp_0 = 0;
									w < w276 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (x, 1) (1 / 1)
									for (x = x510, xp_1 = x510_p_0, xp_0 = 0;
										x < x510 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5176 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5177 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_5178 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5179 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_5180 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5181 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_5182 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5183 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_5184 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5185 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_5186 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5187 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_5188 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5189 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_5190 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5191 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_5192 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5193 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_5194 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5195 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c510, cp_1 = c510_p_0, cp_0 = 0;
													c < c510 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5176);
													mem_vec_5176 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5177);
													mem_vec_5177 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5178);
													mem_vec_5178 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5179);
													mem_vec_5179 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5180);
													mem_vec_5180 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5181);
													mem_vec_5181 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5182);
													mem_vec_5182 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5183);
													mem_vec_5183 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5184);
													mem_vec_5184 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5185);
													mem_vec_5185 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5186);
													mem_vec_5186 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5187);
													mem_vec_5187 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5188);
													mem_vec_5188 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5189);
													mem_vec_5189 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5190);
													mem_vec_5190 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5191);
													mem_vec_5191 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5192);
													mem_vec_5192 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5193);
													mem_vec_5193 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5194);
													mem_vec_5194 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5195);
													mem_vec_5195 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5176);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5177);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5178);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5179);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5180);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5181);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5182);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5183);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5184);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5185);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5186);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5187);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5188);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5189);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5190);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5191);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5192);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5193);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5194);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5195);
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