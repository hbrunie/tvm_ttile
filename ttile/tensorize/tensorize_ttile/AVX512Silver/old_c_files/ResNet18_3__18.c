#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (32, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (2, x); T (4, y); T (2, f); T (1, x); T (2, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c75_p_0, cp_1, c75, f, fp_0, x, xp_0, x125_p_0, x126_p_0, x127_p_0, xp_1, x125_p_1, x126_p_1, xp_2, x125_p_2, xp_3, x125, x126, x127, y, yp_0, y100_p_0, y101_p_0, yp_1, y100_p_1, yp_2, y100, y101;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y102 = 0;
IND_TYPE x128 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c76 = 0;
IND_TYPE f50 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_350 ,mem_vec_351 ,mem_vec_352 ,mem_vec_353 ,mem_vec_354 ,mem_vec_355 ,mem_vec_356 ,mem_vec_357 ,mem_vec_358 ,mem_vec_359 ,mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y101 = y102, y101_p_0 = 0;
	y101 < y102 + 56;
	y101 += 56, y101_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x127 = x128, x127_p_0 = 0;
		x127 < x128 + 56;
		x127 += 2, x127_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 2) (56 / 28)
		for (y100 = y101, y100_p_1 = y101_p_0, y100_p_0 = 0;
			y100 < y101 + 56;
			y100 += 28, y100_p_1 += 28, y100_p_0 += 28){
			// y = 28, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (2 / 2)
			for (x126 = x127, x126_p_1 = x127_p_0, x126_p_0 = 0;
				x126 < x127 + 2;
				x126 += 2, x126_p_1 += 2, x126_p_0 += 2){
				// y = 28, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f50, fp_0 = 0;
					f < f50 + 64;
					f += 32, fp_0 += 32){
					// y = 28, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 4) (28 / 7)
					for (y = y100, yp_2 = y100_p_1, yp_1 = y100_p_0, yp_0 = 0;
						y < y100 + 28;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 2) (2 / 1)
						for (x125 = x126, x125_p_2 = x126_p_1, x125_p_1 = x126_p_0, x125_p_0 = 0;
							x125 < x126 + 2;
							x125 += 1, x125_p_2 += 1, x125_p_1 += 1, x125_p_0 += 1){
							// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 2) (64 / 32)
							for (c75 = c76, c75_p_0 = 0;
								c75 < c76 + 64;
								c75 += 32, c75_p_0 += 32){
								// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x125, xp_3 = x125_p_2, xp_2 = x125_p_1, xp_1 = x125_p_0, xp_0 = 0;
									x < x125 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_350 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_351 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c75, cp_1 = c75_p_0, cp_0 = 0;
												c < c75 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_350);
												mem_vec_350 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_351);
												mem_vec_351 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_352);
												mem_vec_352 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_353);
												mem_vec_353 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_354);
												mem_vec_354 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_355);
												mem_vec_355 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_356);
												mem_vec_356 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_357);
												mem_vec_357 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_358);
												mem_vec_358 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_359);
												mem_vec_359 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_360);
												mem_vec_360 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_361);
												mem_vec_361 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_362);
												mem_vec_362 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_363);
												mem_vec_363 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_350);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_351);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_352);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_353);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_354);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_355);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_356);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_357);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_358);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_359);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_360);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_361);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_362);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_363);
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