#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (64, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (1, x); T (1, y); T (2, f); T (1, x); T (7, y); T (56, x); T (1, y)]
*/
IND_TYPE c, cp_0, c90_p_0, cp_1, c90, f, fp_0, x, xp_0, x150_p_0, x151_p_0, x152_p_0, xp_1, x150_p_1, x151_p_1, xp_2, x150_p_2, xp_3, x150, x151, x152, y, yp_0, y120_p_0, y121_p_0, yp_1, y120_p_1, yp_2, y120, y121;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y122 = 0;
IND_TYPE x153 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c91 = 0;
IND_TYPE f60 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_480 ,mem_vec_481 ,mem_vec_482 ,mem_vec_483 ,mem_vec_484 ,mem_vec_485 ,mem_vec_486 ,mem_vec_487 ,mem_vec_488 ,mem_vec_489 ,mem_vec_490 ,mem_vec_491 ,mem_vec_492 ,mem_vec_493 ,mem_vec_494 ,mem_vec_495 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y121 = y122, y121_p_0 = 0;
	y121 < y122 + 56;
	y121 += 56, y121_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 56) (56 / 1)
	for (x152 = x153, x152_p_0 = 0;
		x152 < x153 + 56;
		x152 += 1, x152_p_0 += 1){
		// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
		// T (y, 7) (56 / 8)
		for (y120 = y121, y120_p_1 = y121_p_0, y120_p_0 = 0;
			y120 < y121 + 56;
			y120 += 8, y120_p_1 += 8, y120_p_0 += 8){
			// y = 8, x = 1, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (1 / 1)
			for (x151 = x152, x151_p_1 = x152_p_0, x151_p_0 = 0;
				x151 < x152 + 1;
				x151 += 1, x151_p_1 += 1, x151_p_0 += 1){
				// y = 8, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f60, fp_0 = 0;
					f < f60 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
					// T (y, 1) (8 / 8)
					for (y = y120, yp_2 = y120_p_1, yp_1 = y120_p_0, yp_0 = 0;
						y < y120 + 8;
						y += 8, yp_2 += 8, yp_1 += 8, yp_0 += 8){
						// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x150 = x151, x150_p_2 = x151_p_1, x150_p_1 = x151_p_0, x150_p_0 = 0;
							x150 < x151 + 1;
							x150 += 1, x150_p_2 += 1, x150_p_1 += 1, x150_p_0 += 1){
							// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 1) (64 / 64)
							for (c90 = c91, c90_p_0 = 0;
								c90 < c91 + 64;
								c90 += 64, c90_p_0 += 64){
								// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x150, xp_3 = x150_p_2, xp_2 = x150_p_1, xp_1 = x150_p_0, xp_0 = 0;
									x < x150 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_480 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_481 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c90, cp_1 = c90_p_0, cp_0 = 0;
												c < c90 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_480);
												mem_vec_480 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_481);
												mem_vec_481 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_482);
												mem_vec_482 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_483);
												mem_vec_483 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_484);
												mem_vec_484 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_485);
												mem_vec_485 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_486);
												mem_vec_486 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_487);
												mem_vec_487 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_488);
												mem_vec_488 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_489);
												mem_vec_489 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_490);
												mem_vec_490 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_491);
												mem_vec_491 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_492);
												mem_vec_492 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_493);
												mem_vec_493 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_494);
												mem_vec_494 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_495);
												mem_vec_495 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_480);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_481);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_482);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_483);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_484);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_485);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_486);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_487);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_488);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_489);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_490);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_491);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_492);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_493);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_494);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_495);
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