#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (2, x); T (2, y); T (2, f); T (1, x); T (4, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c81_p_0, cp_1, c81, f, fp_0, x, xp_0, x135_p_0, x136_p_0, x137_p_0, xp_1, x135_p_1, x136_p_1, xp_2, x135_p_2, xp_3, x135, x136, x137, y, yp_0, y108_p_0, y109_p_0, yp_1, y108_p_1, yp_2, y108, y109;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y110 = 0;
IND_TYPE x138 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c82 = 0;
IND_TYPE f54 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_378 ,mem_vec_379 ,mem_vec_380 ,mem_vec_381 ,mem_vec_382 ,mem_vec_383 ,mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y109 = y110, y109_p_0 = 0;
	y109 < y110 + 56;
	y109 += 56, y109_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x137 = x138, x137_p_0 = 0;
		x137 < x138 + 56;
		x137 += 2, x137_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 4) (56 / 14)
		for (y108 = y109, y108_p_1 = y109_p_0, y108_p_0 = 0;
			y108 < y109 + 56;
			y108 += 14, y108_p_1 += 14, y108_p_0 += 14){
			// y = 14, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (2 / 2)
			for (x136 = x137, x136_p_1 = x137_p_0, x136_p_0 = 0;
				x136 < x137 + 2;
				x136 += 2, x136_p_1 += 2, x136_p_0 += 2){
				// y = 14, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f54, fp_0 = 0;
					f < f54 + 64;
					f += 32, fp_0 += 32){
					// y = 14, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 2) (14 / 7)
					for (y = y108, yp_2 = y108_p_1, yp_1 = y108_p_0, yp_0 = 0;
						y < y108 + 14;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 2) (2 / 1)
						for (x135 = x136, x135_p_2 = x136_p_1, x135_p_1 = x136_p_0, x135_p_0 = 0;
							x135 < x136 + 2;
							x135 += 1, x135_p_2 += 1, x135_p_1 += 1, x135_p_0 += 1){
							// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 1) (64 / 64)
							for (c81 = c82, c81_p_0 = 0;
								c81 < c82 + 64;
								c81 += 64, c81_p_0 += 64){
								// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x135, xp_3 = x135_p_2, xp_2 = x135_p_1, xp_1 = x135_p_0, xp_0 = 0;
									x < x135 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_378 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_379 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c81, cp_1 = c81_p_0, cp_0 = 0;
												c < c81 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_378);
												mem_vec_378 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_379);
												mem_vec_379 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_380);
												mem_vec_380 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_381);
												mem_vec_381 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_382);
												mem_vec_382 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_383);
												mem_vec_383 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_384);
												mem_vec_384 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_385);
												mem_vec_385 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_386);
												mem_vec_386 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_387);
												mem_vec_387 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_388);
												mem_vec_388 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_389);
												mem_vec_389 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_390);
												mem_vec_390 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_391);
												mem_vec_391 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_378);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_379);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_380);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_381);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_382);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_383);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_384);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_385);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_386);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_387);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_388);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_389);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_390);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_391);
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