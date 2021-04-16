#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (3, h); T (1, x);
  T (3, w); T (2, c); T (1, x); T (1, y); T (17, y); T (272, x); T (4, y)]
*/
IND_TYPE c, cp_0, c273_p_0, cp_1, c273, h, hp_0, w, wp_0, x, xp_0, x367_p_0, x368_p_0, xp_1, x367_p_1, xp_2, x367, x368, y, yp_0, y361_p_0, y362_p_0, yp_1, y361_p_1, yp_2, y361, y362;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y363 = 0;
IND_TYPE x369 = 0;
IND_TYPE h140 = 0;
IND_TYPE w137 = 0;
IND_TYPE c274 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_748 ,mem_vec_749 ,mem_vec_750 ,mem_vec_751 ,mem_vec_752 ,mem_vec_753 ,mem_vec_754 ,mem_vec_755 ,mem_vec_756 ,mem_vec_757 ,mem_vec_758 ,mem_vec_759 ,mem_vec_760 ,mem_vec_761 ,mem_vec_762 ,mem_vec_763 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 4) (272 / 68)
for (y362 = y363, y362_p_0 = 0;
	y362 < y363 + 272;
	y362 += 68, y362_p_0 += 68){
	// y = 68, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 272) (272 / 1)
	for (x368 = x369, x368_p_0 = 0;
		x368 < x369 + 272;
		x368 += 1, x368_p_0 += 1){
		// y = 68, x = 1, h = 3, w = 3, c = 32, f = 64
		// T (y, 17) (68 / 4)
		for (y361 = y362, y361_p_1 = y362_p_0, y361_p_0 = 0;
			y361 < y362 + 68;
			y361 += 4, y361_p_1 += 4, y361_p_0 += 4){
			// y = 4, x = 1, h = 3, w = 3, c = 32, f = 64
			// T (y, 1) (4 / 4)
			for (y = y361, yp_2 = y361_p_1, yp_1 = y361_p_0, yp_0 = 0;
				y < y361 + 4;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (x, 1) (1 / 1)
				for (x367 = x368, x367_p_1 = x368_p_0, x367_p_0 = 0;
					x367 < x368 + 1;
					x367 += 1, x367_p_1 += 1, x367_p_0 += 1){
					// y = 4, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (c, 2) (32 / 16)
					for (c273 = c274, c273_p_0 = 0;
						c273 < c274 + 32;
						c273 += 16, c273_p_0 += 16){
						// y = 4, x = 1, h = 3, w = 3, c = 16, f = 64
						// T (w, 3) (3 / 1)
						for (w = w137, wp_0 = 0;
							w < w137 + 3;
							w += 1, wp_0 += 1){
							// y = 4, x = 1, h = 3, w = 1, c = 16, f = 64
							// T (x, 1) (1 / 1)
							for (x = x367, xp_2 = x367_p_1, xp_1 = x367_p_0, xp_0 = 0;
								x < x367 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 3, w = 1, c = 16, f = 64
								// T (h, 3) (3 / 1)
								for (h = h140, hp_0 = 0;
									h < h140 + 3;
									h += 1, hp_0 += 1){
											mem_vec_748 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_749 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_750 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_751 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = 4, x = 1, h = 1, w = 1, c = 16, f = 64
											// T (c, 16) (16 / 1)
											for (c = c273, cp_1 = c273_p_0, cp_0 = 0;
												c < c273 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_748);
												mem_vec_748 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_749);
												mem_vec_749 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_750);
												mem_vec_750 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_751);
												mem_vec_751 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_752);
												mem_vec_752 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_753);
												mem_vec_753 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_754);
												mem_vec_754 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_755);
												mem_vec_755 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_756);
												mem_vec_756 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_757);
												mem_vec_757 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_758);
												mem_vec_758 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_759);
												mem_vec_759 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_760);
												mem_vec_760 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_761);
												mem_vec_761 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_762);
												mem_vec_762 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_763);
												mem_vec_763 = vec_23;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_748);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_749);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_750);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_751);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_752);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_753);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_754);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_755);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_756);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_757);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_758);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_759);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_760);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_761);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_762);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_763);
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