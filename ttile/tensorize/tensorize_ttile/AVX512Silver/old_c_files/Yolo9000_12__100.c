#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (8, c); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 3), (Arg 9))]; T (16, f);
  T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c47_p_0, cp_1, c47, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x42_p_0, x43_p_0, xp_1, x42_p_1, xp_2, x42, x43, y, yp_0, y28_p_0, yp_1, y28;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y29 = 0;
IND_TYPE x44 = 0;
IND_TYPE h28 = 0;
IND_TYPE w14 = 0;
IND_TYPE c48 = 0;
IND_TYPE f51 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_152 ,mem_vec_153 ,mem_vec_154 ,mem_vec_155 ,mem_vec_156 ,mem_vec_157 ,mem_vec_158 ,mem_vec_159 ,mem_vec_160 ,mem_vec_161 ,mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,mem_vec_168 ,mem_vec_169 ,mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,mem_vec_176 ,mem_vec_177 ,mem_vec_178 ,mem_vec_179 ,mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (y, 1) (34 / 34)
for (y28 = y29, y28_p_0 = 0;
	y28 < y29 + 34;
	y28 += 34, y28_p_0 += 34){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (x, 1) (34 / 34)
	for (x43 = x44, x43_p_0 = 0;
		x43 < x44 + 34;
		x43 += 34, x43_p_0 += 34){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
		// T (f, 16) (512 / 32)
		for (f = f51, fp_0 = 0;
			f < f51 + 512;
			f += 32, fp_0 += 32){
				for (y = y28, yp_1 = y28_p_0, yp_0 = 0;
					y < y28 + 7;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (x, 1) (34 / 34)
					for (x42 = x43, x42_p_1 = x43_p_0, x42_p_0 = 0;
						x42 < x43 + 34;
						x42 += 34, x42_p_1 += 34, x42_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
						// T (c, 8) (256 / 32)
						for (c47 = c48, c47_p_0 = 0;
							c47 < c48 + 256;
							c47 += 32, c47_p_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w14, wp_0 = 0;
								w < w14 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 32, f = 32
								// T (x, 34) (34 / 1)
								for (x = x42, xp_2 = x42_p_1, xp_1 = x42_p_0, xp_0 = 0;
									x < x42 + 34;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h28, hp_0 = 0;
										h < h28 + 3;
										h += 1, hp_0 += 1){
												mem_vec_152 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_153 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c47, cp_1 = c47_p_0, cp_0 = 0;
													c < c47 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_152);
													mem_vec_152 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_153);
													mem_vec_153 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_154);
													mem_vec_154 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_155);
													mem_vec_155 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_156);
													mem_vec_156 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_157);
													mem_vec_157 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_158);
													mem_vec_158 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_159);
													mem_vec_159 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_160);
													mem_vec_160 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_161);
													mem_vec_161 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_162);
													mem_vec_162 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_163);
													mem_vec_163 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_164);
													mem_vec_164 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_165);
													mem_vec_165 = vec_22;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_152);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_153);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_154);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_155);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_156);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_157);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_158);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_159);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_160);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_161);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_162);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_163);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_164);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_165);
									}
								}
							}
						}
					}
				}
				for (y = y28 + 7, yp_1 = y28_p_0, yp_0 = 0;
					y < y28 + 7 + 27;
					y += 9, yp_1 += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (x, 1) (34 / 34)
					for (x42 = x43, x42_p_1 = x43_p_0, x42_p_0 = 0;
						x42 < x43 + 34;
						x42 += 34, x42_p_1 += 34, x42_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
						// T (c, 8) (256 / 32)
						for (c47 = c48, c47_p_0 = 0;
							c47 < c48 + 256;
							c47 += 32, c47_p_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w14, wp_0 = 0;
								w < w14 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 32, f = 32
								// T (x, 34) (34 / 1)
								for (x = x42, xp_2 = x42_p_1, xp_1 = x42_p_0, xp_0 = 0;
									x < x42 + 34;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h28, hp_0 = 0;
										h < h28 + 3;
										h += 1, hp_0 += 1){
												mem_vec_166 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_167 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c47, cp_1 = c47_p_0, cp_0 = 0;
													c < c47 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_166);
													mem_vec_166 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_167);
													mem_vec_167 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_168);
													mem_vec_168 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_169);
													mem_vec_169 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_170);
													mem_vec_170 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_171);
													mem_vec_171 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_172);
													mem_vec_172 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_173);
													mem_vec_173 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_174);
													mem_vec_174 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_175);
													mem_vec_175 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_176);
													mem_vec_176 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_177);
													mem_vec_177 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_178);
													mem_vec_178 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_179);
													mem_vec_179 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_180);
													mem_vec_180 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_181);
													mem_vec_181 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_182);
													mem_vec_182 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_183);
													mem_vec_183 = vec_28;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_166);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_167);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_168);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_169);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_170);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_171);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_172);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_173);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_174);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_175);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_176);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_177);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_178);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_179);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_180);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_181);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_182);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_183);
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