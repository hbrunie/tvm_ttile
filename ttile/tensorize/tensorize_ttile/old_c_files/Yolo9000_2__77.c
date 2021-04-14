#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (8, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (4, x); T (34, y); T (2, f); T (4, c); T (68, x); T (1, x)]
*/
IND_TYPE c, cp_0, c120_p_0, cp_1, c120, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x200_p_0, x201_p_0, x202_p_0, xp_1, x200_p_1, x201_p_1, xp_2, x200_p_2, xp_3, x200, x201, x202, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y80 = 0;
IND_TYPE x203 = 0;
IND_TYPE h80 = 0;
IND_TYPE w80 = 0;
IND_TYPE c121 = 0;
IND_TYPE f80 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 1) (272 / 272)
for (x202 = x203, x202_p_0 = 0;
	x202 < x203 + 272;
	x202 += 272, x202_p_0 += 272){
	// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 68) (272 / 4)
	for (x201 = x202, x201_p_1 = x202_p_0, x201_p_0 = 0;
		x201 < x202 + 272;
		x201 += 4, x201_p_1 += 4, x201_p_0 += 4){
		// y = 272, x = 4, h = 3, w = 3, c = 32, f = 64
		// T (c, 4) (32 / 8)
		for (c120 = c121, c120_p_0 = 0;
			c120 < c121 + 32;
			c120 += 8, c120_p_0 += 8){
			// y = 272, x = 4, h = 3, w = 3, c = 8, f = 64
			// T (f, 2) (64 / 32)
			for (f = f80, fp_0 = 0;
				f < f80 + 64;
				f += 32, fp_0 += 32){
				// y = 272, x = 4, h = 3, w = 3, c = 8, f = 32
				// T (y, 34) (272 / 8)
				for (y = y80, yp_0 = 0;
					y < y80 + 272;
					y += 8, yp_0 += 8){
					// y = 8, x = 4, h = 3, w = 3, c = 8, f = 32
					// T (x, 4) (4 / 1)
					for (x200 = x201, x200_p_2 = x201_p_1, x200_p_1 = x201_p_0, x200_p_0 = 0;
						x200 < x201 + 4;
						x200 += 1, x200_p_2 += 1, x200_p_1 += 1, x200_p_0 += 1){
						// y = 8, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h80, hp_0 = 0;
							h < h80 + 3;
							h += 1, hp_0 += 1){
							// y = 8, x = 1, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w80, wp_0 = 0;
								w < w80 + 3;
								w += 1, wp_0 += 1){
								// y = 8, x = 1, h = 1, w = 1, c = 8, f = 32
								// T (x, 1) (1 / 1)
								for (x = x200, xp_3 = x200_p_2, xp_2 = x200_p_1, xp_1 = x200_p_0, xp_0 = 0;
									x < x200 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_640 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_641 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c120, cp_1 = c120_p_0, cp_0 = 0;
												c < c120 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_640);
												mem_vec_640 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_641);
												mem_vec_641 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_642);
												mem_vec_642 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_643);
												mem_vec_643 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_644);
												mem_vec_644 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_645);
												mem_vec_645 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_646);
												mem_vec_646 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_647);
												mem_vec_647 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_648);
												mem_vec_648 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_649);
												mem_vec_649 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_650);
												mem_vec_650 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_651);
												mem_vec_651 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_652);
												mem_vec_652 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_653);
												mem_vec_653 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_654);
												mem_vec_654 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_655);
												mem_vec_655 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_640);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_641);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_642);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_643);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_644);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_645);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_646);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_647);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_648);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_649);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_650);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_651);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_652);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_653);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_654);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_655);
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