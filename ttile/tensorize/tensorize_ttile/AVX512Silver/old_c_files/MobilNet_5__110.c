#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (8, c); T (4, f); T (7, y); T (1, x); T (1, f); T (1, f)]
*/
IND_TYPE c, cp_0, c78_p_0, cp_1, c78, f, fp_0, f52_p_0, f53_p_0, fp_1, f52_p_1, fp_2, f52, f53, h, hp_0, w, wp_0, x, xp_0, x78_p_0, xp_1, x78, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y78 = 0;
IND_TYPE x79 = 0;
IND_TYPE h36 = 0;
IND_TYPE w40 = 0;
IND_TYPE c79 = 0;
IND_TYPE f54 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_504 ,mem_vec_505 ,mem_vec_506 ,mem_vec_507 ,mem_vec_508 ,mem_vec_509 ,mem_vec_510 ,mem_vec_511 ,mem_vec_512 ,mem_vec_513 ,mem_vec_514 ,mem_vec_515 ,mem_vec_516 ,mem_vec_517 ,mem_vec_518 ,mem_vec_519 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f53 = f54, f53_p_0 = 0;
	f53 < f54 + 256;
	f53 += 256, f53_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (f, 1) (256 / 256)
	for (f52 = f53, f52_p_1 = f53_p_0, f52_p_0 = 0;
		f52 < f53 + 256;
		f52 += 256, f52_p_1 += 256, f52_p_0 += 256){
		// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (x, 1) (28 / 28)
		for (x78 = x79, x78_p_0 = 0;
			x78 < x79 + 28;
			x78 += 28, x78_p_0 += 28){
			// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
			// T (y, 7) (28 / 4)
			for (y = y78, yp_0 = 0;
				y < y78 + 28;
				y += 4, yp_0 += 4){
				// y = 4, x = 28, h = 3, w = 3, c = 256, f = 256
				// T (f, 4) (256 / 64)
				for (f = f52, fp_2 = f52_p_1, fp_1 = f52_p_0, fp_0 = 0;
					f < f52 + 256;
					f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
					// y = 4, x = 28, h = 3, w = 3, c = 256, f = 64
					// T (c, 8) (256 / 32)
					for (c78 = c79, c78_p_0 = 0;
						c78 < c79 + 256;
						c78 += 32, c78_p_0 += 32){
						// y = 4, x = 28, h = 3, w = 3, c = 32, f = 64
						// T (w, 3) (3 / 1)
						for (w = w40, wp_0 = 0;
							w < w40 + 3;
							w += 1, wp_0 += 1){
							// y = 4, x = 28, h = 3, w = 1, c = 32, f = 64
							// T (x, 28) (28 / 1)
							for (x = x78, xp_1 = x78_p_0, xp_0 = 0;
								x < x78 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 3, w = 1, c = 32, f = 64
								// T (h, 3) (3 / 1)
								for (h = h36, hp_0 = 0;
									h < h36 + 3;
									h += 1, hp_0 += 1){
											mem_vec_504 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_505 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_506 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_507 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_512 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = 4, x = 1, h = 1, w = 1, c = 32, f = 64
											// T (c, 32) (32 / 1)
											for (c = c78, cp_1 = c78_p_0, cp_0 = 0;
												c < c78 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_504);
												mem_vec_504 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_505);
												mem_vec_505 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_506);
												mem_vec_506 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_507);
												mem_vec_507 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_508);
												mem_vec_508 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_509);
												mem_vec_509 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_510);
												mem_vec_510 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_511);
												mem_vec_511 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_512);
												mem_vec_512 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_513);
												mem_vec_513 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_514);
												mem_vec_514 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_515);
												mem_vec_515 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_516);
												mem_vec_516 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_517);
												mem_vec_517 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_518);
												mem_vec_518 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_519);
												mem_vec_519 = vec_23;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_504);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_505);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_506);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_507);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_508);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_509);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_510);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_511);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_512);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_513);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_514);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_515);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_516);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_517);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_518);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_519);
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