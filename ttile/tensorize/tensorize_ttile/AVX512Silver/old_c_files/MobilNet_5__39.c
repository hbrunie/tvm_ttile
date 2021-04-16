#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (8, c); T (2, f); T (7, y); T (1, x); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c87_p_0, cp_1, c87, f, fp_0, f64_p_0, f65_p_0, fp_1, f64_p_1, fp_2, f64, f65, h, hp_0, w, wp_0, x, xp_0, x87_p_0, xp_1, x87, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y84 = 0;
IND_TYPE x88 = 0;
IND_TYPE h42 = 0;
IND_TYPE w46 = 0;
IND_TYPE c88 = 0;
IND_TYPE f66 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_552 ,mem_vec_553 ,mem_vec_554 ,mem_vec_555 ,mem_vec_556 ,mem_vec_557 ,mem_vec_558 ,mem_vec_559 ,mem_vec_560 ,mem_vec_561 ,mem_vec_562 ,mem_vec_563 ,mem_vec_564 ,mem_vec_565 ,mem_vec_566 ,mem_vec_567 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f65 = f66, f65_p_0 = 0;
	f65 < f66 + 256;
	f65 += 128, f65_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 128
	// T (f, 1) (128 / 128)
	for (f64 = f65, f64_p_1 = f65_p_0, f64_p_0 = 0;
		f64 < f65 + 128;
		f64 += 128, f64_p_1 += 128, f64_p_0 += 128){
		// y = 28, x = 28, h = 3, w = 3, c = 256, f = 128
		// T (x, 1) (28 / 28)
		for (x87 = x88, x87_p_0 = 0;
			x87 < x88 + 28;
			x87 += 28, x87_p_0 += 28){
			// y = 28, x = 28, h = 3, w = 3, c = 256, f = 128
			// T (y, 7) (28 / 4)
			for (y = y84, yp_0 = 0;
				y < y84 + 28;
				y += 4, yp_0 += 4){
				// y = 4, x = 28, h = 3, w = 3, c = 256, f = 128
				// T (f, 2) (128 / 64)
				for (f = f64, fp_2 = f64_p_1, fp_1 = f64_p_0, fp_0 = 0;
					f < f64 + 128;
					f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
					// y = 4, x = 28, h = 3, w = 3, c = 256, f = 64
					// T (c, 8) (256 / 32)
					for (c87 = c88, c87_p_0 = 0;
						c87 < c88 + 256;
						c87 += 32, c87_p_0 += 32){
						// y = 4, x = 28, h = 3, w = 3, c = 32, f = 64
						// T (w, 3) (3 / 1)
						for (w = w46, wp_0 = 0;
							w < w46 + 3;
							w += 1, wp_0 += 1){
							// y = 4, x = 28, h = 3, w = 1, c = 32, f = 64
							// T (x, 28) (28 / 1)
							for (x = x87, xp_1 = x87_p_0, xp_0 = 0;
								x < x87 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 3, w = 1, c = 32, f = 64
								// T (h, 3) (3 / 1)
								for (h = h42, hp_0 = 0;
									h < h42 + 3;
									h += 1, hp_0 += 1){
											mem_vec_552 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_553 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_554 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_555 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = 4, x = 1, h = 1, w = 1, c = 32, f = 64
											// T (c, 32) (32 / 1)
											for (c = c87, cp_1 = c87_p_0, cp_0 = 0;
												c < c87 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_552);
												mem_vec_552 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_553);
												mem_vec_553 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_554);
												mem_vec_554 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_555);
												mem_vec_555 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_556);
												mem_vec_556 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_557);
												mem_vec_557 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_558);
												mem_vec_558 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_559);
												mem_vec_559 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_560);
												mem_vec_560 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_561);
												mem_vec_561 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_562);
												mem_vec_562 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_563);
												mem_vec_563 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_564);
												mem_vec_564 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_565);
												mem_vec_565 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_566);
												mem_vec_566 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_567);
												mem_vec_567 = vec_23;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_552);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_553);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_554);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_555);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_556);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_557);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_558);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_559);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_560);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_561);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_562);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_563);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_564);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_565);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_566);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_567);
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