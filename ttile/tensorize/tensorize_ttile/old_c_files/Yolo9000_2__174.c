#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (32, c); Hoist_vars [c]; T (68, x); T (3, w);
  T (3, h); T (1, x); T (34, y); T (2, f); T (1, c); T (2, x); T (2, x)]
*/
IND_TYPE c, cp_0, c168_p_0, cp_1, c168, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x280_p_0, x281_p_0, x282_p_0, xp_1, x280_p_1, x281_p_1, xp_2, x280_p_2, xp_3, x280, x281, x282, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y112 = 0;
IND_TYPE x283 = 0;
IND_TYPE h112 = 0;
IND_TYPE w112 = 0;
IND_TYPE c169 = 0;
IND_TYPE f112 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,mem_vec_904 ,mem_vec_905 ,mem_vec_906 ,mem_vec_907 ,mem_vec_908 ,mem_vec_909 ,mem_vec_910 ,mem_vec_911 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
for (x282 = x283, x282_p_0 = 0;
	x282 < x283 + 272;
	x282 += 136, x282_p_0 += 136){
	// y = 272, x = 136, h = 3, w = 3, c = 32, f = 64
	// T (x, 2) (136 / 68)
	for (x281 = x282, x281_p_1 = x282_p_0, x281_p_0 = 0;
		x281 < x282 + 136;
		x281 += 68, x281_p_1 += 68, x281_p_0 += 68){
		// y = 272, x = 68, h = 3, w = 3, c = 32, f = 64
		// T (c, 1) (32 / 32)
		for (c168 = c169, c168_p_0 = 0;
			c168 < c169 + 32;
			c168 += 32, c168_p_0 += 32){
			// y = 272, x = 68, h = 3, w = 3, c = 32, f = 64
			// T (f, 2) (64 / 32)
			for (f = f112, fp_0 = 0;
				f < f112 + 64;
				f += 32, fp_0 += 32){
				// y = 272, x = 68, h = 3, w = 3, c = 32, f = 32
				// T (y, 34) (272 / 8)
				for (y = y112, yp_0 = 0;
					y < y112 + 272;
					y += 8, yp_0 += 8){
					// y = 8, x = 68, h = 3, w = 3, c = 32, f = 32
					// T (x, 1) (68 / 68)
					for (x280 = x281, x280_p_2 = x281_p_1, x280_p_1 = x281_p_0, x280_p_0 = 0;
						x280 < x281 + 68;
						x280 += 68, x280_p_2 += 68, x280_p_1 += 68, x280_p_0 += 68){
						// y = 8, x = 68, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h112, hp_0 = 0;
							h < h112 + 3;
							h += 1, hp_0 += 1){
							// y = 8, x = 68, h = 1, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w112, wp_0 = 0;
								w < w112 + 3;
								w += 1, wp_0 += 1){
								// y = 8, x = 68, h = 1, w = 1, c = 32, f = 32
								// T (x, 68) (68 / 1)
								for (x = x280, xp_3 = x280_p_2, xp_2 = x280_p_1, xp_1 = x280_p_0, xp_0 = 0;
									x < x280 + 68;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_896 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_897 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_910 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_911 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c168, cp_1 = c168_p_0, cp_0 = 0;
												c < c168 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_896);
												mem_vec_896 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_897);
												mem_vec_897 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_898);
												mem_vec_898 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_899);
												mem_vec_899 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_900);
												mem_vec_900 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_901);
												mem_vec_901 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_902);
												mem_vec_902 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_903);
												mem_vec_903 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_904);
												mem_vec_904 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_905);
												mem_vec_905 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_906);
												mem_vec_906 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_907);
												mem_vec_907 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_908);
												mem_vec_908 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_909);
												mem_vec_909 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_910);
												mem_vec_910 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_911);
												mem_vec_911 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_896);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_897);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_898);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_899);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_900);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_901);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_902);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_903);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_904);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_905);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_906);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_907);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_908);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_909);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_910);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_911);
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