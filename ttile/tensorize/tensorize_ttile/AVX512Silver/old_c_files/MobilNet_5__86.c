#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (3, h); T (14, x);
  T (3, w); T (4, c); T (2, x); T (1, y); T (8, f); T (1, x); T (4, y)]
*/
IND_TYPE c, cp_0, c318_p_0, cp_1, c318, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x261_p_0, x262_p_0, xp_1, x261_p_1, xp_2, x261, x262, y, yp_0, y270_p_0, yp_1, y270;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y271 = 0;
IND_TYPE x263 = 0;
IND_TYPE h153 = 0;
IND_TYPE w156 = 0;
IND_TYPE c319 = 0;
IND_TYPE f280 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1793 ,mem_vec_1794 ,mem_vec_1795 ,mem_vec_1796 ,mem_vec_1797 ,mem_vec_1798 ,mem_vec_1799 ,mem_vec_1800 ,mem_vec_1801 ,mem_vec_1802 ,mem_vec_1803 ,mem_vec_1804 ,mem_vec_1805 ,mem_vec_1806 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (y, 4) (28 / 7)
for (y270 = y271, y270_p_0 = 0;
	y270 < y271 + 28;
	y270 += 7, y270_p_0 += 7){
	// y = 7, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (x, 1) (28 / 28)
	for (x262 = x263, x262_p_0 = 0;
		x262 < x263 + 28;
		x262 += 28, x262_p_0 += 28){
		// y = 7, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f = f280, fp_0 = 0;
			f < f280 + 256;
			f += 32, fp_0 += 32){
			// y = 7, x = 28, h = 3, w = 3, c = 256, f = 32
			// T (y, 1) (7 / 7)
			for (y = y270, yp_1 = y270_p_0, yp_0 = 0;
				y < y270 + 7;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = 7, x = 28, h = 3, w = 3, c = 256, f = 32
				// T (x, 2) (28 / 14)
				for (x261 = x262, x261_p_1 = x262_p_0, x261_p_0 = 0;
					x261 < x262 + 28;
					x261 += 14, x261_p_1 += 14, x261_p_0 += 14){
					// y = 7, x = 14, h = 3, w = 3, c = 256, f = 32
					// T (c, 4) (256 / 64)
					for (c318 = c319, c318_p_0 = 0;
						c318 < c319 + 256;
						c318 += 64, c318_p_0 += 64){
						// y = 7, x = 14, h = 3, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w156, wp_0 = 0;
							w < w156 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 14, h = 3, w = 1, c = 64, f = 32
							// T (x, 14) (14 / 1)
							for (x = x261, xp_2 = x261_p_1, xp_1 = x261_p_0, xp_0 = 0;
								x < x261 + 14;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = 7, x = 1, h = 3, w = 1, c = 64, f = 32
								// T (h, 3) (3 / 1)
								for (h = h153, hp_0 = 0;
									h < h153 + 3;
									h += 1, hp_0 += 1){
											mem_vec_1793 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1794 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_1805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_1806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c318, cp_1 = c318_p_0, cp_0 = 0;
												c < c318 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1793);
												mem_vec_1793 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1794);
												mem_vec_1794 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1795);
												mem_vec_1795 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1796);
												mem_vec_1796 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1797);
												mem_vec_1797 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1798);
												mem_vec_1798 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1799);
												mem_vec_1799 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1800);
												mem_vec_1800 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1801);
												mem_vec_1801 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1802);
												mem_vec_1802 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1803);
												mem_vec_1803 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1804);
												mem_vec_1804 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1805);
												mem_vec_1805 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1806);
												mem_vec_1806 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1793);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1794);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1795);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1796);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1797);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1798);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1799);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1800);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1801);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1802);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1803);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1804);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1805);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1806);
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