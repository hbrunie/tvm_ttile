#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (2, x); T (4, y); T (2, f); T (1, x); T (2, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c72_p_0, cp_1, c72, f, fp_0, x, xp_0, x120_p_0, x121_p_0, x122_p_0, xp_1, x120_p_1, x121_p_1, xp_2, x120_p_2, xp_3, x120, x121, x122, y, yp_0, y96_p_0, y97_p_0, yp_1, y96_p_1, yp_2, y96, y97;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y98 = 0;
IND_TYPE x123 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c73 = 0;
IND_TYPE f48 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_336 ,mem_vec_337 ,mem_vec_338 ,mem_vec_339 ,mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,mem_vec_346 ,mem_vec_347 ,mem_vec_348 ,mem_vec_349 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y97 = y98, y97_p_0 = 0;
	y97 < y98 + 56;
	y97 += 56, y97_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x122 = x123, x122_p_0 = 0;
		x122 < x123 + 56;
		x122 += 2, x122_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 2) (56 / 28)
		for (y96 = y97, y96_p_1 = y97_p_0, y96_p_0 = 0;
			y96 < y97 + 56;
			y96 += 28, y96_p_1 += 28, y96_p_0 += 28){
			// y = 28, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (2 / 2)
			for (x121 = x122, x121_p_1 = x122_p_0, x121_p_0 = 0;
				x121 < x122 + 2;
				x121 += 2, x121_p_1 += 2, x121_p_0 += 2){
				// y = 28, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f48, fp_0 = 0;
					f < f48 + 64;
					f += 32, fp_0 += 32){
					// y = 28, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 4) (28 / 7)
					for (y = y96, yp_2 = y96_p_1, yp_1 = y96_p_0, yp_0 = 0;
						y < y96 + 28;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 2) (2 / 1)
						for (x120 = x121, x120_p_2 = x121_p_1, x120_p_1 = x121_p_0, x120_p_0 = 0;
							x120 < x121 + 2;
							x120 += 1, x120_p_2 += 1, x120_p_1 += 1, x120_p_0 += 1){
							// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 1) (64 / 64)
							for (c72 = c73, c72_p_0 = 0;
								c72 < c73 + 64;
								c72 += 64, c72_p_0 += 64){
								// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x120, xp_3 = x120_p_2, xp_2 = x120_p_1, xp_1 = x120_p_0, xp_0 = 0;
									x < x120 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_336 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_337 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c72, cp_1 = c72_p_0, cp_0 = 0;
												c < c72 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_336);
												mem_vec_336 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_337);
												mem_vec_337 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_338);
												mem_vec_338 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_339);
												mem_vec_339 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_340);
												mem_vec_340 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_341);
												mem_vec_341 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_342);
												mem_vec_342 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_343);
												mem_vec_343 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_344);
												mem_vec_344 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_345);
												mem_vec_345 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_346);
												mem_vec_346 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_347);
												mem_vec_347 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_348);
												mem_vec_348 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_349);
												mem_vec_349 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_336);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_337);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_338);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_339);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_340);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_341);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_342);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_343);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_344);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_345);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_346);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_347);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_348);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_349);
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