#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (16, c); Hoist_vars [c]; T (2, x); T (4, c);
  T (1, x); T (7, y); T (2, f); T (1, x); T (1, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c33_p_0, cp_1, c33, f, fp_0, x, xp_0, x55_p_0, x56_p_0, x57_p_0, xp_1, x55_p_1, x56_p_1, xp_2, x55_p_2, xp_3, x55, x56, x57, y, yp_0, y44_p_0, y45_p_0, yp_1, y44_p_1, yp_2, y44, y45;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y46 = 0;
IND_TYPE x58 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c34 = 0;
IND_TYPE f22 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_176 ,mem_vec_177 ,mem_vec_178 ,mem_vec_179 ,mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,mem_vec_184 ,mem_vec_185 ,mem_vec_186 ,mem_vec_187 ,mem_vec_188 ,mem_vec_189 ,mem_vec_190 ,mem_vec_191 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y45 = y46, y45_p_0 = 0;
	y45 < y46 + 56;
	y45 += 56, y45_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x57 = x58, x57_p_0 = 0;
		x57 < x58 + 56;
		x57 += 2, x57_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y44 = y45, y44_p_1 = y45_p_0, y44_p_0 = 0;
			y44 < y45 + 56;
			y44 += 56, y44_p_1 += 56, y44_p_0 += 56){
			// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (2 / 2)
			for (x56 = x57, x56_p_1 = x57_p_0, x56_p_0 = 0;
				x56 < x57 + 2;
				x56 += 2, x56_p_1 += 2, x56_p_0 += 2){
				// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f22, fp_0 = 0;
					f < f22 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 7) (56 / 8)
					for (y = y44, yp_2 = y44_p_1, yp_1 = y44_p_0, yp_0 = 0;
						y < y44 + 56;
						y += 8, yp_2 += 8, yp_1 += 8, yp_0 += 8){
						// y = 8, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (2 / 2)
						for (x55 = x56, x55_p_2 = x56_p_1, x55_p_1 = x56_p_0, x55_p_0 = 0;
							x55 < x56 + 2;
							x55 += 2, x55_p_2 += 2, x55_p_1 += 2, x55_p_0 += 2){
							// y = 8, x = 2, h = 1, w = 1, c = 64, f = 32
							// T (c, 4) (64 / 16)
							for (c33 = c34, c33_p_0 = 0;
								c33 < c34 + 64;
								c33 += 16, c33_p_0 += 16){
								// y = 8, x = 2, h = 1, w = 1, c = 16, f = 32
								// T (x, 2) (2 / 1)
								for (x = x55, xp_3 = x55_p_2, xp_2 = x55_p_1, xp_1 = x55_p_0, xp_0 = 0;
									x < x55 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_176 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_177 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c33, cp_1 = c33_p_0, cp_0 = 0;
												c < c33 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_176);
												mem_vec_176 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_177);
												mem_vec_177 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_178);
												mem_vec_178 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_179);
												mem_vec_179 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_180);
												mem_vec_180 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_181);
												mem_vec_181 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_182);
												mem_vec_182 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_183);
												mem_vec_183 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_184);
												mem_vec_184 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_185);
												mem_vec_185 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_186);
												mem_vec_186 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_187);
												mem_vec_187 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_188);
												mem_vec_188 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_189);
												mem_vec_189 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_190);
												mem_vec_190 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_191);
												mem_vec_191 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_176);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_177);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_178);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_179);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_180);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_181);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_182);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_183);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_184);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_185);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_186);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_187);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_188);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_189);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_190);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_191);
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