#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (3, h); T (1, x);
  T (3, w); T (1, c); T (1, x); T (1, y); T (17, y); T (272, x); T (4, y)]
*/
IND_TYPE c, cp_0, c270_p_0, cp_1, c270, h, hp_0, w, wp_0, x, xp_0, x363_p_0, x364_p_0, xp_1, x363_p_1, xp_2, x363, x364, y, yp_0, y357_p_0, y358_p_0, yp_1, y357_p_1, yp_2, y357, y358;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y359 = 0;
IND_TYPE x365 = 0;
IND_TYPE h138 = 0;
IND_TYPE w135 = 0;
IND_TYPE c271 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,mem_vec_736 ,mem_vec_737 ,mem_vec_738 ,mem_vec_739 ,mem_vec_740 ,mem_vec_741 ,mem_vec_742 ,mem_vec_743 ,mem_vec_744 ,mem_vec_745 ,mem_vec_746 ,mem_vec_747 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 4) (272 / 68)
for (y358 = y359, y358_p_0 = 0;
	y358 < y359 + 272;
	y358 += 68, y358_p_0 += 68){
	// y = 68, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 272) (272 / 1)
	for (x364 = x365, x364_p_0 = 0;
		x364 < x365 + 272;
		x364 += 1, x364_p_0 += 1){
		// y = 68, x = 1, h = 3, w = 3, c = 32, f = 64
		// T (y, 17) (68 / 4)
		for (y357 = y358, y357_p_1 = y358_p_0, y357_p_0 = 0;
			y357 < y358 + 68;
			y357 += 4, y357_p_1 += 4, y357_p_0 += 4){
			// y = 4, x = 1, h = 3, w = 3, c = 32, f = 64
			// T (y, 1) (4 / 4)
			for (y = y357, yp_2 = y357_p_1, yp_1 = y357_p_0, yp_0 = 0;
				y < y357 + 4;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (x, 1) (1 / 1)
				for (x363 = x364, x363_p_1 = x364_p_0, x363_p_0 = 0;
					x363 < x364 + 1;
					x363 += 1, x363_p_1 += 1, x363_p_0 += 1){
					// y = 4, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (c, 1) (32 / 32)
					for (c270 = c271, c270_p_0 = 0;
						c270 < c271 + 32;
						c270 += 32, c270_p_0 += 32){
						// y = 4, x = 1, h = 3, w = 3, c = 32, f = 64
						// T (w, 3) (3 / 1)
						for (w = w135, wp_0 = 0;
							w < w135 + 3;
							w += 1, wp_0 += 1){
							// y = 4, x = 1, h = 3, w = 1, c = 32, f = 64
							// T (x, 1) (1 / 1)
							for (x = x363, xp_2 = x363_p_1, xp_1 = x363_p_0, xp_0 = 0;
								x < x363 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 3, w = 1, c = 32, f = 64
								// T (h, 3) (3 / 1)
								for (h = h138, hp_0 = 0;
									h < h138 + 3;
									h += 1, hp_0 += 1){
											mem_vec_732 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_733 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_734 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_735 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = 4, x = 1, h = 1, w = 1, c = 32, f = 64
											// T (c, 32) (32 / 1)
											for (c = c270, cp_1 = c270_p_0, cp_0 = 0;
												c < c270 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_732);
												mem_vec_732 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_733);
												mem_vec_733 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_734);
												mem_vec_734 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_735);
												mem_vec_735 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_736);
												mem_vec_736 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_737);
												mem_vec_737 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_738);
												mem_vec_738 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_739);
												mem_vec_739 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_740);
												mem_vec_740 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_741);
												mem_vec_741 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_742);
												mem_vec_742 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_743);
												mem_vec_743 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_744);
												mem_vec_744 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_745);
												mem_vec_745 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_746);
												mem_vec_746 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_747);
												mem_vec_747 = vec_23;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_732);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_733);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_734);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_735);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_736);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_737);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_738);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_739);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_740);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_741);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_742);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_743);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_744);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_745);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_746);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_747);
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