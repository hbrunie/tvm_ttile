#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (8, c); T (1, f); T (7, y); T (1, x); T (4, f); T (1, f)]
*/
IND_TYPE c, cp_0, c84_p_0, cp_1, c84, f, fp_0, f60_p_0, f61_p_0, fp_1, f60_p_1, fp_2, f60, f61, h, hp_0, w, wp_0, x, xp_0, x84_p_0, xp_1, x84, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y82 = 0;
IND_TYPE x85 = 0;
IND_TYPE h40 = 0;
IND_TYPE w44 = 0;
IND_TYPE c85 = 0;
IND_TYPE f62 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_536 ,mem_vec_537 ,mem_vec_538 ,mem_vec_539 ,mem_vec_540 ,mem_vec_541 ,mem_vec_542 ,mem_vec_543 ,mem_vec_544 ,mem_vec_545 ,mem_vec_546 ,mem_vec_547 ,mem_vec_548 ,mem_vec_549 ,mem_vec_550 ,mem_vec_551 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f61 = f62, f61_p_0 = 0;
	f61 < f62 + 256;
	f61 += 256, f61_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (f, 4) (256 / 64)
	for (f60 = f61, f60_p_1 = f61_p_0, f60_p_0 = 0;
		f60 < f61 + 256;
		f60 += 64, f60_p_1 += 64, f60_p_0 += 64){
		// y = 28, x = 28, h = 3, w = 3, c = 256, f = 64
		// T (x, 1) (28 / 28)
		for (x84 = x85, x84_p_0 = 0;
			x84 < x85 + 28;
			x84 += 28, x84_p_0 += 28){
			// y = 28, x = 28, h = 3, w = 3, c = 256, f = 64
			// T (y, 7) (28 / 4)
			for (y = y82, yp_0 = 0;
				y < y82 + 28;
				y += 4, yp_0 += 4){
				// y = 4, x = 28, h = 3, w = 3, c = 256, f = 64
				// T (f, 1) (64 / 64)
				for (f = f60, fp_2 = f60_p_1, fp_1 = f60_p_0, fp_0 = 0;
					f < f60 + 64;
					f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
					// y = 4, x = 28, h = 3, w = 3, c = 256, f = 64
					// T (c, 8) (256 / 32)
					for (c84 = c85, c84_p_0 = 0;
						c84 < c85 + 256;
						c84 += 32, c84_p_0 += 32){
						// y = 4, x = 28, h = 3, w = 3, c = 32, f = 64
						// T (w, 3) (3 / 1)
						for (w = w44, wp_0 = 0;
							w < w44 + 3;
							w += 1, wp_0 += 1){
							// y = 4, x = 28, h = 3, w = 1, c = 32, f = 64
							// T (x, 28) (28 / 1)
							for (x = x84, xp_1 = x84_p_0, xp_0 = 0;
								x < x84 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 3, w = 1, c = 32, f = 64
								// T (h, 3) (3 / 1)
								for (h = h40, hp_0 = 0;
									h < h40 + 3;
									h += 1, hp_0 += 1){
											mem_vec_536 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_537 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_538 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_539 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_542 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_543 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_544 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_545 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = 4, x = 1, h = 1, w = 1, c = 32, f = 64
											// T (c, 32) (32 / 1)
											for (c = c84, cp_1 = c84_p_0, cp_0 = 0;
												c < c84 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_536);
												mem_vec_536 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_537);
												mem_vec_537 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_538);
												mem_vec_538 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_539);
												mem_vec_539 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_540);
												mem_vec_540 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_541);
												mem_vec_541 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_542);
												mem_vec_542 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_543);
												mem_vec_543 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_544);
												mem_vec_544 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_545);
												mem_vec_545 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_546);
												mem_vec_546 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_547);
												mem_vec_547 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_548);
												mem_vec_548 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_549);
												mem_vec_549 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_550);
												mem_vec_550 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_551);
												mem_vec_551 = vec_23;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_536);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_537);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_538);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_539);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_540);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_541);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_542);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_543);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_544);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_545);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_546);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_547);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_548);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_549);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_550);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_551);
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