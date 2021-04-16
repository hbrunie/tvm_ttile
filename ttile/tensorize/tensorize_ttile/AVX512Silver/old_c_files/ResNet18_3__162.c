#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (32, c); Hoist_vars [c]; T (2, x); T (2, c);
  T (1, x); T (8, y); T (2, f); T (1, x); T (1, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c30_p_0, cp_1, c30, f, fp_0, x, xp_0, x50_p_0, x51_p_0, x52_p_0, xp_1, x50_p_1, x51_p_1, xp_2, x50_p_2, xp_3, x50, x51, x52, y, yp_0, y40_p_0, y41_p_0, yp_1, y40_p_1, yp_2, y40, y41;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y42 = 0;
IND_TYPE x53 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c31 = 0;
IND_TYPE f20 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,mem_vec_144 ,mem_vec_145 ,mem_vec_146 ,mem_vec_147 ,mem_vec_148 ,mem_vec_149 ,mem_vec_150 ,mem_vec_151 ,mem_vec_152 ,mem_vec_153 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y41 = y42, y41_p_0 = 0;
	y41 < y42 + 56;
	y41 += 56, y41_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x52 = x53, x52_p_0 = 0;
		x52 < x53 + 56;
		x52 += 2, x52_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y40 = y41, y40_p_1 = y41_p_0, y40_p_0 = 0;
			y40 < y41 + 56;
			y40 += 56, y40_p_1 += 56, y40_p_0 += 56){
			// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (2 / 2)
			for (x51 = x52, x51_p_1 = x52_p_0, x51_p_0 = 0;
				x51 < x52 + 2;
				x51 += 2, x51_p_1 += 2, x51_p_0 += 2){
				// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f20, fp_0 = 0;
					f < f20 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 8) (56 / 7)
					for (y = y40, yp_2 = y40_p_1, yp_1 = y40_p_0, yp_0 = 0;
						y < y40 + 56;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (2 / 2)
						for (x50 = x51, x50_p_2 = x51_p_1, x50_p_1 = x51_p_0, x50_p_0 = 0;
							x50 < x51 + 2;
							x50 += 2, x50_p_2 += 2, x50_p_1 += 2, x50_p_0 += 2){
							// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
							// T (c, 2) (64 / 32)
							for (c30 = c31, c30_p_0 = 0;
								c30 < c31 + 64;
								c30 += 32, c30_p_0 += 32){
								// y = 7, x = 2, h = 1, w = 1, c = 32, f = 32
								// T (x, 2) (2 / 1)
								for (x = x50, xp_3 = x50_p_2, xp_2 = x50_p_1, xp_1 = x50_p_0, xp_0 = 0;
									x < x50 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_140 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_141 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
												c < c30 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_140);
												mem_vec_140 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_141);
												mem_vec_141 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_142);
												mem_vec_142 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_143);
												mem_vec_143 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_144);
												mem_vec_144 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_145);
												mem_vec_145 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_146);
												mem_vec_146 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_147);
												mem_vec_147 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_148);
												mem_vec_148 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_149);
												mem_vec_149 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_150);
												mem_vec_150 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_151);
												mem_vec_151 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_152);
												mem_vec_152 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_153);
												mem_vec_153 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_140);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_141);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_142);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_143);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_144);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_145);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_146);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_147);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_148);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_149);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_150);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_151);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_152);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_153);
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