#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (8, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 4), (Arg 15))]; T (2, x);
  T (2, f); T (4, f)]
*/
IND_TYPE c, cp_0, c9_p_0, cp_1, c9, f, fp_0, f12_p_0, f13_p_0, fp_1, f12_p_1, fp_2, f12, f13, h, hp_0, w, wp_0, x, xp_0, x9_p_0, xp_1, x9, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y6 = 0;
IND_TYPE x10 = 0;
IND_TYPE h6 = 0;
IND_TYPE w6 = 0;
IND_TYPE c10 = 0;
IND_TYPE f14 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_138 ,mem_vec_139 ,mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,mem_vec_144 ,mem_vec_145 ,mem_vec_146 ,mem_vec_147 ,mem_vec_148 ,mem_vec_149 ,mem_vec_150 ,mem_vec_151 ,mem_vec_152 ,mem_vec_153 ,mem_vec_154 ,mem_vec_155 ,mem_vec_156 ,mem_vec_157 ,mem_vec_158 ,mem_vec_159 ,mem_vec_160 ,mem_vec_161 ,mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,mem_vec_168 ,mem_vec_169 ,mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,mem_vec_176 ,mem_vec_177 ,mem_vec_178 ,mem_vec_179 ,mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f13 = f14, f13_p_0 = 0;
	f13 < f14 + 256;
	f13 += 64, f13_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (f, 2) (64 / 32)
	for (f12 = f13, f12_p_1 = f13_p_0, f12_p_0 = 0;
		f12 < f13 + 64;
		f12 += 32, f12_p_1 += 32, f12_p_0 += 32){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (x, 2) (68 / 34)
		for (x9 = x10, x9_p_0 = 0;
			x9 < x10 + 68;
			x9 += 34, x9_p_0 += 34){
				for (y = y6, yp_0 = 0;
					y < y6 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f12, fp_2 = f12_p_1, fp_1 = f12_p_0, fp_0 = 0;
						f < f12 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c9 = c10, c9_p_0 = 0;
							c9 < c10 + 128;
							c9 += 16, c9_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w6, wp_0 = 0;
								w < w6 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x9, xp_1 = x9_p_0, xp_0 = 0;
									x < x9 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h6, hp_0 = 0;
										h < h6 + 3;
										h += 1, hp_0 += 1){
												mem_vec_138 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_139 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c9, cp_1 = c9_p_0, cp_0 = 0;
													c < c9 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_138);
													mem_vec_138 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_139);
													mem_vec_139 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_140);
													mem_vec_140 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_141);
													mem_vec_141 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_142);
													mem_vec_142 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_143);
													mem_vec_143 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_144);
													mem_vec_144 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_145);
													mem_vec_145 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_146);
													mem_vec_146 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_147);
													mem_vec_147 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_148);
													mem_vec_148 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_149);
													mem_vec_149 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_150);
													mem_vec_150 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_151);
													mem_vec_151 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_152);
													mem_vec_152 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_153);
													mem_vec_153 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_138);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_139);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_140);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_141);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_142);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_143);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_144);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_145);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_146);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_147);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_148);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_149);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_150);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_151);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_152);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_153);
									}
								}
							}
						}
					}
				}
				for (y = y6 + 8, yp_0 = 0;
					y < y6 + 8 + 60;
					y += 15, yp_0 += 15){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f12, fp_2 = f12_p_1, fp_1 = f12_p_0, fp_0 = 0;
						f < f12 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c9 = c10, c9_p_0 = 0;
							c9 < c10 + 128;
							c9 += 16, c9_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w6, wp_0 = 0;
								w < w6 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x9, xp_1 = x9_p_0, xp_0 = 0;
									x < x9 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h6, hp_0 = 0;
										h < h6 + 3;
										h += 1, hp_0 += 1){
												mem_vec_154 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_155 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												mem_vec_182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
												mem_vec_183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c9, cp_1 = c9_p_0, cp_0 = 0;
													c < c9 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_154);
													mem_vec_154 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_155);
													mem_vec_155 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_156);
													mem_vec_156 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_157);
													mem_vec_157 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_158);
													mem_vec_158 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_159);
													mem_vec_159 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_160);
													mem_vec_160 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_161);
													mem_vec_161 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_162);
													mem_vec_162 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_163);
													mem_vec_163 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_164);
													mem_vec_164 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_165);
													mem_vec_165 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_166);
													mem_vec_166 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_167);
													mem_vec_167 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_168);
													mem_vec_168 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_169);
													mem_vec_169 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_170);
													mem_vec_170 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_171);
													mem_vec_171 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_172);
													mem_vec_172 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_173);
													mem_vec_173 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_174);
													mem_vec_174 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_175);
													mem_vec_175 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_176);
													mem_vec_176 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_177);
													mem_vec_177 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_178);
													mem_vec_178 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_179);
													mem_vec_179 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_180);
													mem_vec_180 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_181);
													mem_vec_181 = vec_43;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
													vec_45 = _mm512_set1_ps(scal_14);


													vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_182);
													mem_vec_182 = vec_44;



													vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_183);
													mem_vec_183 = vec_46;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_154);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_155);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_156);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_157);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_158);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_159);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_160);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_161);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_162);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_163);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_164);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_165);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_166);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_167);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_168);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_169);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_170);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_171);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_172);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_173);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_174);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_175);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_176);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_177);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_178);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_179);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_180);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_181);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_182);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_183);
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