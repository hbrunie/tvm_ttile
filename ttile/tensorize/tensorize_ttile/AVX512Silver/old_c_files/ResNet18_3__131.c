#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (2, x); T (1, c);
  T (1, x); T (8, y); T (2, f); T (1, x); T (1, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c27_p_0, cp_1, c27, f, fp_0, x, xp_0, x45_p_0, x46_p_0, x47_p_0, xp_1, x45_p_1, x46_p_1, xp_2, x45_p_2, xp_3, x45, x46, x47, y, yp_0, y36_p_0, y37_p_0, yp_1, y36_p_1, yp_2, y36, y37;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y38 = 0;
IND_TYPE x48 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c28 = 0;
IND_TYPE f18 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_126 ,mem_vec_127 ,mem_vec_128 ,mem_vec_129 ,mem_vec_130 ,mem_vec_131 ,mem_vec_132 ,mem_vec_133 ,mem_vec_134 ,mem_vec_135 ,mem_vec_136 ,mem_vec_137 ,mem_vec_138 ,mem_vec_139 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y37 = y38, y37_p_0 = 0;
	y37 < y38 + 56;
	y37 += 56, y37_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x47 = x48, x47_p_0 = 0;
		x47 < x48 + 56;
		x47 += 2, x47_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y36 = y37, y36_p_1 = y37_p_0, y36_p_0 = 0;
			y36 < y37 + 56;
			y36 += 56, y36_p_1 += 56, y36_p_0 += 56){
			// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (2 / 2)
			for (x46 = x47, x46_p_1 = x47_p_0, x46_p_0 = 0;
				x46 < x47 + 2;
				x46 += 2, x46_p_1 += 2, x46_p_0 += 2){
				// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f18, fp_0 = 0;
					f < f18 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 8) (56 / 7)
					for (y = y36, yp_2 = y36_p_1, yp_1 = y36_p_0, yp_0 = 0;
						y < y36 + 56;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (2 / 2)
						for (x45 = x46, x45_p_2 = x46_p_1, x45_p_1 = x46_p_0, x45_p_0 = 0;
							x45 < x46 + 2;
							x45 += 2, x45_p_2 += 2, x45_p_1 += 2, x45_p_0 += 2){
							// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
							// T (c, 1) (64 / 64)
							for (c27 = c28, c27_p_0 = 0;
								c27 < c28 + 64;
								c27 += 64, c27_p_0 += 64){
								// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
								// T (x, 2) (2 / 1)
								for (x = x45, xp_3 = x45_p_2, xp_2 = x45_p_1, xp_1 = x45_p_0, xp_0 = 0;
									x < x45 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_126 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_127 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c27, cp_1 = c27_p_0, cp_0 = 0;
												c < c27 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_126);
												mem_vec_126 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_127);
												mem_vec_127 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_128);
												mem_vec_128 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_129);
												mem_vec_129 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_130);
												mem_vec_130 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_131);
												mem_vec_131 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_132);
												mem_vec_132 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_133);
												mem_vec_133 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_134);
												mem_vec_134 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_135);
												mem_vec_135 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_136);
												mem_vec_136 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_137);
												mem_vec_137 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_138);
												mem_vec_138 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_139);
												mem_vec_139 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_126);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_127);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_128);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_129);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_130);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_131);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_132);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_133);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_134);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_135);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_136);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_137);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_138);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_139);
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