#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (8, c); Hoist_vars [c]; T (3, h); T (1, x);
  T (3, w); T (4, c); T (1, x); T (1, y); T (17, y); T (272, x); T (4, y)]
*/
IND_TYPE c, cp_0, c276_p_0, cp_1, c276, h, hp_0, w, wp_0, x, xp_0, x371_p_0, x372_p_0, xp_1, x371_p_1, xp_2, x371, x372, y, yp_0, y365_p_0, y366_p_0, yp_1, y365_p_1, yp_2, y365, y366;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y367 = 0;
IND_TYPE x373 = 0;
IND_TYPE h142 = 0;
IND_TYPE w139 = 0;
IND_TYPE c277 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_764 ,mem_vec_765 ,mem_vec_766 ,mem_vec_767 ,mem_vec_768 ,mem_vec_769 ,mem_vec_770 ,mem_vec_771 ,mem_vec_772 ,mem_vec_773 ,mem_vec_774 ,mem_vec_775 ,mem_vec_776 ,mem_vec_777 ,mem_vec_778 ,mem_vec_779 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 4) (272 / 68)
for (y366 = y367, y366_p_0 = 0;
	y366 < y367 + 272;
	y366 += 68, y366_p_0 += 68){
	// y = 68, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 272) (272 / 1)
	for (x372 = x373, x372_p_0 = 0;
		x372 < x373 + 272;
		x372 += 1, x372_p_0 += 1){
		// y = 68, x = 1, h = 3, w = 3, c = 32, f = 64
		// T (y, 17) (68 / 4)
		for (y365 = y366, y365_p_1 = y366_p_0, y365_p_0 = 0;
			y365 < y366 + 68;
			y365 += 4, y365_p_1 += 4, y365_p_0 += 4){
			// y = 4, x = 1, h = 3, w = 3, c = 32, f = 64
			// T (y, 1) (4 / 4)
			for (y = y365, yp_2 = y365_p_1, yp_1 = y365_p_0, yp_0 = 0;
				y < y365 + 4;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (x, 1) (1 / 1)
				for (x371 = x372, x371_p_1 = x372_p_0, x371_p_0 = 0;
					x371 < x372 + 1;
					x371 += 1, x371_p_1 += 1, x371_p_0 += 1){
					// y = 4, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (c, 4) (32 / 8)
					for (c276 = c277, c276_p_0 = 0;
						c276 < c277 + 32;
						c276 += 8, c276_p_0 += 8){
						// y = 4, x = 1, h = 3, w = 3, c = 8, f = 64
						// T (w, 3) (3 / 1)
						for (w = w139, wp_0 = 0;
							w < w139 + 3;
							w += 1, wp_0 += 1){
							// y = 4, x = 1, h = 3, w = 1, c = 8, f = 64
							// T (x, 1) (1 / 1)
							for (x = x371, xp_2 = x371_p_1, xp_1 = x371_p_0, xp_0 = 0;
								x < x371 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 3, w = 1, c = 8, f = 64
								// T (h, 3) (3 / 1)
								for (h = h142, hp_0 = 0;
									h < h142 + 3;
									h += 1, hp_0 += 1){
											mem_vec_764 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_765 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_766 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_767 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = 4, x = 1, h = 1, w = 1, c = 8, f = 64
											// T (c, 8) (8 / 1)
											for (c = c276, cp_1 = c276_p_0, cp_0 = 0;
												c < c276 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_764);
												mem_vec_764 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_765);
												mem_vec_765 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_766);
												mem_vec_766 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_767);
												mem_vec_767 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_768);
												mem_vec_768 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_769);
												mem_vec_769 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_770);
												mem_vec_770 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_771);
												mem_vec_771 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_772);
												mem_vec_772 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_773);
												mem_vec_773 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_774);
												mem_vec_774 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_775);
												mem_vec_775 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_776);
												mem_vec_776 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_777);
												mem_vec_777 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_778);
												mem_vec_778 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_779);
												mem_vec_779 = vec_23;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_764);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_765);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_766);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_767);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_768);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_769);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_770);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_771);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_772);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_773);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_774);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_775);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_776);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_777);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_778);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_779);
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