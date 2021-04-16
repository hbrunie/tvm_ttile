#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (3, h); T (14, x);
  T (3, w); T (4, c); T (1, x); T (2, y); T (8, f); T (2, x); T (2, y)]
*/
IND_TYPE c, cp_0, c330_p_0, cp_1, c330, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x277_p_0, x278_p_0, xp_1, x277_p_1, xp_2, x277, x278, y, yp_0, y282_p_0, yp_1, y282;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y283 = 0;
IND_TYPE x279 = 0;
IND_TYPE h161 = 0;
IND_TYPE w164 = 0;
IND_TYPE c331 = 0;
IND_TYPE f288 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1849 ,mem_vec_1850 ,mem_vec_1851 ,mem_vec_1852 ,mem_vec_1853 ,mem_vec_1854 ,mem_vec_1855 ,mem_vec_1856 ,mem_vec_1857 ,mem_vec_1858 ,mem_vec_1859 ,mem_vec_1860 ,mem_vec_1861 ,mem_vec_1862 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (y, 2) (28 / 14)
for (y282 = y283, y282_p_0 = 0;
	y282 < y283 + 28;
	y282 += 14, y282_p_0 += 14){
	// y = 14, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (x, 2) (28 / 14)
	for (x278 = x279, x278_p_0 = 0;
		x278 < x279 + 28;
		x278 += 14, x278_p_0 += 14){
		// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f = f288, fp_0 = 0;
			f < f288 + 256;
			f += 32, fp_0 += 32){
			// y = 14, x = 14, h = 3, w = 3, c = 256, f = 32
			// T (y, 2) (14 / 7)
			for (y = y282, yp_1 = y282_p_0, yp_0 = 0;
				y < y282 + 14;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = 7, x = 14, h = 3, w = 3, c = 256, f = 32
				// T (x, 1) (14 / 14)
				for (x277 = x278, x277_p_1 = x278_p_0, x277_p_0 = 0;
					x277 < x278 + 14;
					x277 += 14, x277_p_1 += 14, x277_p_0 += 14){
					// y = 7, x = 14, h = 3, w = 3, c = 256, f = 32
					// T (c, 4) (256 / 64)
					for (c330 = c331, c330_p_0 = 0;
						c330 < c331 + 256;
						c330 += 64, c330_p_0 += 64){
						// y = 7, x = 14, h = 3, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w164, wp_0 = 0;
							w < w164 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 14, h = 3, w = 1, c = 64, f = 32
							// T (x, 14) (14 / 1)
							for (x = x277, xp_2 = x277_p_1, xp_1 = x277_p_0, xp_0 = 0;
								x < x277 + 14;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = 7, x = 1, h = 3, w = 1, c = 64, f = 32
								// T (h, 3) (3 / 1)
								for (h = h161, hp_0 = 0;
									h < h161 + 3;
									h += 1, hp_0 += 1){
											mem_vec_1849 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1850 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_1861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_1862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c330, cp_1 = c330_p_0, cp_0 = 0;
												c < c330 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1849);
												mem_vec_1849 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1850);
												mem_vec_1850 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1851);
												mem_vec_1851 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1852);
												mem_vec_1852 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1853);
												mem_vec_1853 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1854);
												mem_vec_1854 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1855);
												mem_vec_1855 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1856);
												mem_vec_1856 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1857);
												mem_vec_1857 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1858);
												mem_vec_1858 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1859);
												mem_vec_1859 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1860);
												mem_vec_1860 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1861);
												mem_vec_1861 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1862);
												mem_vec_1862 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1849);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1850);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1851);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1852);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1853);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1854);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1855);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1856);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1857);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1858);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1859);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1860);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1861);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1862);
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