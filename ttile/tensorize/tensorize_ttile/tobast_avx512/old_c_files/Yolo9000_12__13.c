#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); T (16, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 3), (Arg 9))]; T (1, f);
  T (128, c); T (1, f)]
*/
IND_TYPE c, cp_0, c36_p_0, cp_1, c36, f, fp_0, f48_p_0, f49_p_0, fp_1, f48_p_1, fp_2, f48, f49, h, hp_0, w, wp_0, x, xp_0, x36_p_0, xp_1, x36, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y24 = 0;
IND_TYPE x37 = 0;
IND_TYPE h16 = 0;
IND_TYPE w22 = 0;
IND_TYPE c37 = 0;
IND_TYPE f50 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_144 ,mem_vec_145 ,mem_vec_146 ,mem_vec_147 ,mem_vec_148 ,mem_vec_149 ,mem_vec_150 ,mem_vec_151 ,mem_vec_152 ,mem_vec_153 ,mem_vec_154 ,mem_vec_155 ,mem_vec_156 ,mem_vec_157 ,mem_vec_158 ,mem_vec_159 ,mem_vec_160 ,mem_vec_161 ,mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,mem_vec_168 ,mem_vec_169 ,mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f49 = f50, f49_p_0 = 0;
	f49 < f50 + 512;
	f49 += 512, f49_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 128) (256 / 2)
	for (c36 = c37, c36_p_0 = 0;
		c36 < c37 + 256;
		c36 += 2, c36_p_0 += 2){
		// y = 34, x = 34, h = 3, w = 3, c = 2, f = 512
		// T (f, 1) (512 / 512)
		for (f48 = f49, f48_p_1 = f49_p_0, f48_p_0 = 0;
			f48 < f49 + 512;
			f48 += 512, f48_p_1 += 512, f48_p_0 += 512){
				for (y = y24, yp_0 = 0;
					y < y24 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 2, f = 512
					// T (x, 1) (34 / 34)
					for (x36 = x37, x36_p_0 = 0;
						x36 < x37 + 34;
						x36 += 34, x36_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 2, f = 512
						// T (f, 16) (512 / 32)
						for (f = f48, fp_2 = f48_p_1, fp_1 = f48_p_0, fp_0 = 0;
							f < f48 + 512;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h16, hp_0 = 0;
								h < h16 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w22, wp_0 = 0;
									w < w22 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 2, f = 32
									// T (x, 34) (34 / 1)
									for (x = x36, xp_1 = x36_p_0, xp_0 = 0;
										x < x36 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_144 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_145 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c36, cp_1 = c36_p_0, cp_0 = 0;
													c < c36 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_144);
													mem_vec_144 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_145);
													mem_vec_145 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_146);
													mem_vec_146 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_147);
													mem_vec_147 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_148);
													mem_vec_148 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_149);
													mem_vec_149 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_150);
													mem_vec_150 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_151);
													mem_vec_151 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_152);
													mem_vec_152 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_153);
													mem_vec_153 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_154);
													mem_vec_154 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_155);
													mem_vec_155 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_156);
													mem_vec_156 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_157);
													mem_vec_157 = vec_22;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_144);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_145);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_146);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_147);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_148);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_149);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_150);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_151);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_152);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_153);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_154);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_155);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_156);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_157);
									}
								}
							}
						}
					}
				}
				for (y = y24 + 7, yp_0 = 0;
					y < y24 + 7 + 27;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 3, w = 3, c = 2, f = 512
					// T (x, 1) (34 / 34)
					for (x36 = x37, x36_p_0 = 0;
						x36 < x37 + 34;
						x36 += 34, x36_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 2, f = 512
						// T (f, 16) (512 / 32)
						for (f = f48, fp_2 = f48_p_1, fp_1 = f48_p_0, fp_0 = 0;
							f < f48 + 512;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h16, hp_0 = 0;
								h < h16 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w22, wp_0 = 0;
									w < w22 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 2, f = 32
									// T (x, 34) (34 / 1)
									for (x = x36, xp_1 = x36_p_0, xp_0 = 0;
										x < x36 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_158 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_159 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c36, cp_1 = c36_p_0, cp_0 = 0;
													c < c36 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_158);
													mem_vec_158 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_159);
													mem_vec_159 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_160);
													mem_vec_160 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_161);
													mem_vec_161 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_162);
													mem_vec_162 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_163);
													mem_vec_163 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_164);
													mem_vec_164 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_165);
													mem_vec_165 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_166);
													mem_vec_166 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_167);
													mem_vec_167 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_168);
													mem_vec_168 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_169);
													mem_vec_169 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_170);
													mem_vec_170 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_171);
													mem_vec_171 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_172);
													mem_vec_172 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_173);
													mem_vec_173 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_174);
													mem_vec_174 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_175);
													mem_vec_175 = vec_28;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_158);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_159);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_160);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_161);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_162);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_163);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_164);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_165);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_166);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_167);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_168);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_169);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_170);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_171);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_172);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_173);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_174);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_175);
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