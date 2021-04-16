#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (16, c); Hoist_vars [c]; T (2, x); T (4, c);
  T (1, x); T (4, y); T (2, f); T (1, x); T (2, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c42_p_0, cp_1, c42, f, fp_0, x, xp_0, x70_p_0, x71_p_0, x72_p_0, xp_1, x70_p_1, x71_p_1, xp_2, x70_p_2, xp_3, x70, x71, x72, y, yp_0, y56_p_0, y57_p_0, yp_1, y56_p_1, yp_2, y56, y57;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y58 = 0;
IND_TYPE x73 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c43 = 0;
IND_TYPE f28 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_196 ,mem_vec_197 ,mem_vec_198 ,mem_vec_199 ,mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,mem_vec_208 ,mem_vec_209 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y57 = y58, y57_p_0 = 0;
	y57 < y58 + 56;
	y57 += 56, y57_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x72 = x73, x72_p_0 = 0;
		x72 < x73 + 56;
		x72 += 2, x72_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 2) (56 / 28)
		for (y56 = y57, y56_p_1 = y57_p_0, y56_p_0 = 0;
			y56 < y57 + 56;
			y56 += 28, y56_p_1 += 28, y56_p_0 += 28){
			// y = 28, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (2 / 2)
			for (x71 = x72, x71_p_1 = x72_p_0, x71_p_0 = 0;
				x71 < x72 + 2;
				x71 += 2, x71_p_1 += 2, x71_p_0 += 2){
				// y = 28, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f28, fp_0 = 0;
					f < f28 + 64;
					f += 32, fp_0 += 32){
					// y = 28, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 4) (28 / 7)
					for (y = y56, yp_2 = y56_p_1, yp_1 = y56_p_0, yp_0 = 0;
						y < y56 + 28;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (2 / 2)
						for (x70 = x71, x70_p_2 = x71_p_1, x70_p_1 = x71_p_0, x70_p_0 = 0;
							x70 < x71 + 2;
							x70 += 2, x70_p_2 += 2, x70_p_1 += 2, x70_p_0 += 2){
							// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
							// T (c, 4) (64 / 16)
							for (c42 = c43, c42_p_0 = 0;
								c42 < c43 + 64;
								c42 += 16, c42_p_0 += 16){
								// y = 7, x = 2, h = 1, w = 1, c = 16, f = 32
								// T (x, 2) (2 / 1)
								for (x = x70, xp_3 = x70_p_2, xp_2 = x70_p_1, xp_1 = x70_p_0, xp_0 = 0;
									x < x70 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_196 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_197 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c42, cp_1 = c42_p_0, cp_0 = 0;
												c < c42 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_196);
												mem_vec_196 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_197);
												mem_vec_197 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_198);
												mem_vec_198 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_199);
												mem_vec_199 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_200);
												mem_vec_200 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_201);
												mem_vec_201 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_202);
												mem_vec_202 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_203);
												mem_vec_203 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_204);
												mem_vec_204 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_205);
												mem_vec_205 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_206);
												mem_vec_206 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_207);
												mem_vec_207 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_208);
												mem_vec_208 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_209);
												mem_vec_209 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_196);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_197);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_198);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_199);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_200);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_201);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_202);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_203);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_204);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_205);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_206);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_207);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_208);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_209);
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