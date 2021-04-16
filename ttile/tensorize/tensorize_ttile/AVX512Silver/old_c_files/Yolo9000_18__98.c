#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 1), (Arg 10))]; T (2, f);
  T (64, c); T (16, f)]
*/
IND_TYPE c, cp_0, c20_p_0, c21_p_0, cp_1, c20_p_1, cp_2, c20, c21, f, fp_0, f15_p_0, fp_1, f15, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y10 = 0;
IND_TYPE x10 = 0;
IND_TYPE h8 = 0;
IND_TYPE w10 = 0;
IND_TYPE c22 = 0;
IND_TYPE f16 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_153 ,mem_vec_154 ,mem_vec_155 ,mem_vec_156 ,mem_vec_157 ,mem_vec_158 ,mem_vec_159 ,mem_vec_160 ,mem_vec_161 ,mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,mem_vec_168 ,mem_vec_169 ,mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,mem_vec_176 ,mem_vec_177 ,mem_vec_178 ,mem_vec_179 ,mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,mem_vec_184 ,mem_vec_185 ,mem_vec_186 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 16) (1024 / 64)
for (f15 = f16, f15_p_0 = 0;
	f15 < f16 + 1024;
	f15 += 64, f15_p_0 += 64){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 64
	// T (c, 64) (512 / 8)
	for (c21 = c22, c21_p_0 = 0;
		c21 < c22 + 512;
		c21 += 8, c21_p_0 += 8){
		// y = 17, x = 17, h = 3, w = 3, c = 8, f = 64
		// T (f, 2) (64 / 32)
		for (f = f15, fp_1 = f15_p_0, fp_0 = 0;
			f < f15 + 64;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y10, yp_0 = 0;
					y < y10 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 32
					// T (c, 1) (8 / 8)
					for (c20 = c21, c20_p_1 = c21_p_0, c20_p_0 = 0;
						c20 < c21 + 8;
						c20 += 8, c20_p_1 += 8, c20_p_0 += 8){
						// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 32
						// T (x, 17) (17 / 1)
						for (x = x10, xp_0 = 0;
							x < x10 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h8, hp_0 = 0;
								h < h8 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w10, wp_0 = 0;
									w < w10 + 3;
									w += 1, wp_0 += 1){
											mem_vec_153 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_154 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c20, cp_2 = c20_p_1, cp_1 = c20_p_0, cp_0 = 0;
												c < c20 + 8;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_153);
												mem_vec_153 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_154);
												mem_vec_154 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_155);
												mem_vec_155 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_156);
												mem_vec_156 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_157);
												mem_vec_157 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_158);
												mem_vec_158 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_159);
												mem_vec_159 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_160);
												mem_vec_160 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_161);
												mem_vec_161 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_162);
												mem_vec_162 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_163);
												mem_vec_163 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_164);
												mem_vec_164 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_165);
												mem_vec_165 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_166);
												mem_vec_166 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_153);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_154);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_155);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_156);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_157);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_158);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_159);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_160);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_161);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_162);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_163);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_164);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_165);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_166);
								}
							}
						}
					}
				}
				for (y = y10 + 7, yp_0 = 0;
					y < y10 + 7 + 10;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 32
					// T (c, 1) (8 / 8)
					for (c20 = c21, c20_p_1 = c21_p_0, c20_p_0 = 0;
						c20 < c21 + 8;
						c20 += 8, c20_p_1 += 8, c20_p_0 += 8){
						// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 32
						// T (x, 17) (17 / 1)
						for (x = x10, xp_0 = 0;
							x < x10 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h8, hp_0 = 0;
								h < h8 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w10, wp_0 = 0;
									w < w10 + 3;
									w += 1, wp_0 += 1){
											mem_vec_167 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_168 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c20, cp_2 = c20_p_1, cp_1 = c20_p_0, cp_0 = 0;
												c < c20 + 8;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_167);
												mem_vec_167 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_168);
												mem_vec_168 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_169);
												mem_vec_169 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_170);
												mem_vec_170 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_171);
												mem_vec_171 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_172);
												mem_vec_172 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_173);
												mem_vec_173 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_174);
												mem_vec_174 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_175);
												mem_vec_175 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_176);
												mem_vec_176 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_177);
												mem_vec_177 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_178);
												mem_vec_178 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_179);
												mem_vec_179 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_180);
												mem_vec_180 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_181);
												mem_vec_181 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_182);
												mem_vec_182 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_183);
												mem_vec_183 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_184);
												mem_vec_184 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_185);
												mem_vec_185 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_186);
												mem_vec_186 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_167);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_168);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_169);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_170);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_171);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_172);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_173);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_174);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_175);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_176);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_177);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_178);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_179);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_180);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_181);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_182);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_183);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_184);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_185);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_186);
								}
							}
						}
					}
				}
		}
	}
}


}