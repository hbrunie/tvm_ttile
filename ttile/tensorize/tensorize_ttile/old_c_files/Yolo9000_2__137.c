#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (8, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); T (4, x); T (34, y); T (2, f); T (4, c); T (2, x); T (1, x)]
*/
IND_TYPE c, cp_0, c18_p_0, cp_1, c18, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x30_p_0, x31_p_0, x32_p_0, xp_1, x30_p_1, x31_p_1, xp_2, x30_p_2, xp_3, x30, x31, x32, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y12 = 0;
IND_TYPE x33 = 0;
IND_TYPE h12 = 0;
IND_TYPE w12 = 0;
IND_TYPE c19 = 0;
IND_TYPE f12 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_100 ,mem_vec_101 ,mem_vec_102 ,mem_vec_103 ,mem_vec_104 ,mem_vec_105 ,mem_vec_106 ,mem_vec_107 ,mem_vec_108 ,mem_vec_109 ,mem_vec_110 ,mem_vec_111 ,mem_vec_96 ,mem_vec_97 ,mem_vec_98 ,mem_vec_99 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 1) (272 / 272)
for (x32 = x33, x32_p_0 = 0;
	x32 < x33 + 272;
	x32 += 272, x32_p_0 += 272){
	// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 2) (272 / 136)
	for (x31 = x32, x31_p_1 = x32_p_0, x31_p_0 = 0;
		x31 < x32 + 272;
		x31 += 136, x31_p_1 += 136, x31_p_0 += 136){
		// y = 272, x = 136, h = 3, w = 3, c = 32, f = 64
		// T (c, 4) (32 / 8)
		for (c18 = c19, c18_p_0 = 0;
			c18 < c19 + 32;
			c18 += 8, c18_p_0 += 8){
			// y = 272, x = 136, h = 3, w = 3, c = 8, f = 64
			// T (f, 2) (64 / 32)
			for (f = f12, fp_0 = 0;
				f < f12 + 64;
				f += 32, fp_0 += 32){
				// y = 272, x = 136, h = 3, w = 3, c = 8, f = 32
				// T (y, 34) (272 / 8)
				for (y = y12, yp_0 = 0;
					y < y12 + 272;
					y += 8, yp_0 += 8){
					// y = 8, x = 136, h = 3, w = 3, c = 8, f = 32
					// T (x, 4) (136 / 34)
					for (x30 = x31, x30_p_2 = x31_p_1, x30_p_1 = x31_p_0, x30_p_0 = 0;
						x30 < x31 + 136;
						x30 += 34, x30_p_2 += 34, x30_p_1 += 34, x30_p_0 += 34){
						// y = 8, x = 34, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h12, hp_0 = 0;
							h < h12 + 3;
							h += 1, hp_0 += 1){
							// y = 8, x = 34, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w12, wp_0 = 0;
								w < w12 + 3;
								w += 1, wp_0 += 1){
								// y = 8, x = 34, h = 1, w = 1, c = 8, f = 32
								// T (x, 34) (34 / 1)
								for (x = x30, xp_3 = x30_p_2, xp_2 = x30_p_1, xp_1 = x30_p_0, xp_0 = 0;
									x < x30 + 34;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_96 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_97 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_98 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_99 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c18, cp_1 = c18_p_0, cp_0 = 0;
												c < c18 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_96);
												mem_vec_96 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_97);
												mem_vec_97 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_98);
												mem_vec_98 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_99);
												mem_vec_99 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_100);
												mem_vec_100 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_101);
												mem_vec_101 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_102);
												mem_vec_102 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_103);
												mem_vec_103 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_104);
												mem_vec_104 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_105);
												mem_vec_105 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_106);
												mem_vec_106 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_107);
												mem_vec_107 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_108);
												mem_vec_108 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_109);
												mem_vec_109 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_110);
												mem_vec_110 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_111);
												mem_vec_111 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_96);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_97);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_98);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_99);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_100);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_101);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_102);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_103);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_104);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_105);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_106);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_107);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_108);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_109);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_110);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_111);
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