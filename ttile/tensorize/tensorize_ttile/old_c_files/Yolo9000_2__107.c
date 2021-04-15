#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (4, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (8, x); T (34, y); T (2, f); T (8, c); T (17, x); T (1, x)]
*/
IND_TYPE c, cp_0, c96_p_0, cp_1, c96, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x160_p_0, x161_p_0, x162_p_0, xp_1, x160_p_1, x161_p_1, xp_2, x160_p_2, xp_3, x160, x161, x162, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y64 = 0;
IND_TYPE x163 = 0;
IND_TYPE h64 = 0;
IND_TYPE w64 = 0;
IND_TYPE c97 = 0;
IND_TYPE f64 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_512 ,mem_vec_513 ,mem_vec_514 ,mem_vec_515 ,mem_vec_516 ,mem_vec_517 ,mem_vec_518 ,mem_vec_519 ,mem_vec_520 ,mem_vec_521 ,mem_vec_522 ,mem_vec_523 ,mem_vec_524 ,mem_vec_525 ,mem_vec_526 ,mem_vec_527 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 1) (272 / 272)
for (x162 = x163, x162_p_0 = 0;
	x162 < x163 + 272;
	x162 += 272, x162_p_0 += 272){
	// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 17) (272 / 16)
	for (x161 = x162, x161_p_1 = x162_p_0, x161_p_0 = 0;
		x161 < x162 + 272;
		x161 += 16, x161_p_1 += 16, x161_p_0 += 16){
		// y = 272, x = 16, h = 3, w = 3, c = 32, f = 64
		// T (c, 8) (32 / 4)
		for (c96 = c97, c96_p_0 = 0;
			c96 < c97 + 32;
			c96 += 4, c96_p_0 += 4){
			// y = 272, x = 16, h = 3, w = 3, c = 4, f = 64
			// T (f, 2) (64 / 32)
			for (f = f64, fp_0 = 0;
				f < f64 + 64;
				f += 32, fp_0 += 32){
				// y = 272, x = 16, h = 3, w = 3, c = 4, f = 32
				// T (y, 34) (272 / 8)
				for (y = y64, yp_0 = 0;
					y < y64 + 272;
					y += 8, yp_0 += 8){
					// y = 8, x = 16, h = 3, w = 3, c = 4, f = 32
					// T (x, 8) (16 / 2)
					for (x160 = x161, x160_p_2 = x161_p_1, x160_p_1 = x161_p_0, x160_p_0 = 0;
						x160 < x161 + 16;
						x160 += 2, x160_p_2 += 2, x160_p_1 += 2, x160_p_0 += 2){
						// y = 8, x = 2, h = 3, w = 3, c = 4, f = 32
						// T (h, 3) (3 / 1)
						for (h = h64, hp_0 = 0;
							h < h64 + 3;
							h += 1, hp_0 += 1){
							// y = 8, x = 2, h = 1, w = 3, c = 4, f = 32
							// T (w, 3) (3 / 1)
							for (w = w64, wp_0 = 0;
								w < w64 + 3;
								w += 1, wp_0 += 1){
								// y = 8, x = 2, h = 1, w = 1, c = 4, f = 32
								// T (x, 2) (2 / 1)
								for (x = x160, xp_3 = x160_p_2, xp_2 = x160_p_1, xp_1 = x160_p_0, xp_0 = 0;
									x < x160 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_512 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_513 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_522 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_523 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_524 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_525 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_526 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_527 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c96, cp_1 = c96_p_0, cp_0 = 0;
												c < c96 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_512);
												mem_vec_512 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_513);
												mem_vec_513 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_514);
												mem_vec_514 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_515);
												mem_vec_515 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_516);
												mem_vec_516 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_517);
												mem_vec_517 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_518);
												mem_vec_518 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_519);
												mem_vec_519 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_520);
												mem_vec_520 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_521);
												mem_vec_521 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_522);
												mem_vec_522 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_523);
												mem_vec_523 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_524);
												mem_vec_524 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_525);
												mem_vec_525 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_526);
												mem_vec_526 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_527);
												mem_vec_527 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_512);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_513);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_514);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_515);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_516);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_517);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_518);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_519);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_520);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_521);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_522);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_523);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_524);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_525);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_526);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_527);
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