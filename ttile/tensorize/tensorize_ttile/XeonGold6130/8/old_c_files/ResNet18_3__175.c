#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (64, c); Hoist_vars [c]; T (4, x); T (1, c);
  T (1, x); T (1, y); T (2, f); T (1, x); T (2, y); T (14, x); T (2, y)]
*/
IND_TYPE c, cp_0, c522_p_0, cp_1, c522, f, fp_0, x, xp_0, x861_p_0, x862_p_0, x863_p_0, xp_1, x861_p_1, x862_p_1, xp_2, x861_p_2, xp_3, x861, x862, x863, y, yp_0, y687_p_0, y688_p_0, yp_1, y687_p_1, yp_2, y687, y688;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y689 = 0;
IND_TYPE x864 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c523 = 0;
IND_TYPE f339 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4368 ,mem_vec_4369 ,mem_vec_4370 ,mem_vec_4371 ,mem_vec_4372 ,mem_vec_4373 ,mem_vec_4374 ,mem_vec_4375 ,mem_vec_4376 ,mem_vec_4377 ,mem_vec_4378 ,mem_vec_4379 ,mem_vec_4380 ,mem_vec_4381 ,mem_vec_4382 ,mem_vec_4383 ,mem_vec_4384 ,mem_vec_4385 ,mem_vec_4386 ,mem_vec_4387 ,mem_vec_4388 ,mem_vec_4389 ,mem_vec_4390 ,mem_vec_4391 ,mem_vec_4392 ,mem_vec_4393 ,mem_vec_4394 ,mem_vec_4395 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 2) (56 / 28)
for (y688 = y689, y688_p_0 = 0;
	y688 < y689 + 56;
	y688 += 28, y688_p_0 += 28){
	// y = 28, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 14) (56 / 4)
	for (x863 = x864, x863_p_0 = 0;
		x863 < x864 + 56;
		x863 += 4, x863_p_0 += 4){
		// y = 28, x = 4, h = 1, w = 1, c = 64, f = 64
		// T (y, 2) (28 / 14)
		for (y687 = y688, y687_p_1 = y688_p_0, y687_p_0 = 0;
			y687 < y688 + 28;
			y687 += 14, y687_p_1 += 14, y687_p_0 += 14){
			// y = 14, x = 4, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (4 / 4)
			for (x862 = x863, x862_p_1 = x863_p_0, x862_p_0 = 0;
				x862 < x863 + 4;
				x862 += 4, x862_p_1 += 4, x862_p_0 += 4){
				// y = 14, x = 4, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f339, fp_0 = 0;
					f < f339 + 64;
					f += 32, fp_0 += 32){
					// y = 14, x = 4, h = 1, w = 1, c = 64, f = 32
					// T (y, 1) (14 / 14)
					for (y = y687, yp_2 = y687_p_1, yp_1 = y687_p_0, yp_0 = 0;
						y < y687 + 14;
						y += 14, yp_2 += 14, yp_1 += 14, yp_0 += 14){
						// y = 14, x = 4, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (4 / 4)
						for (x861 = x862, x861_p_2 = x862_p_1, x861_p_1 = x862_p_0, x861_p_0 = 0;
							x861 < x862 + 4;
							x861 += 4, x861_p_2 += 4, x861_p_1 += 4, x861_p_0 += 4){
							// y = 14, x = 4, h = 1, w = 1, c = 64, f = 32
							// T (c, 1) (64 / 64)
							for (c522 = c523, c522_p_0 = 0;
								c522 < c523 + 64;
								c522 += 64, c522_p_0 += 64){
								// y = 14, x = 4, h = 1, w = 1, c = 64, f = 32
								// T (x, 4) (4 / 1)
								for (x = x861, xp_3 = x861_p_2, xp_2 = x861_p_1, xp_1 = x861_p_0, xp_0 = 0;
									x < x861 + 4;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4368 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4369 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_4380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_4381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_4382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_4383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_4384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_4385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_4386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_4387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_4388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_4389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_4390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_4391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_4392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_4393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_4394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_4395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											// y = 14, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c522, cp_1 = c522_p_0, cp_0 = 0;
												c < c522 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4368);
												mem_vec_4368 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4369);
												mem_vec_4369 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4370);
												mem_vec_4370 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4371);
												mem_vec_4371 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4372);
												mem_vec_4372 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4373);
												mem_vec_4373 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4374);
												mem_vec_4374 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4375);
												mem_vec_4375 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4376);
												mem_vec_4376 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4377);
												mem_vec_4377 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4378);
												mem_vec_4378 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4379);
												mem_vec_4379 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4380);
												mem_vec_4380 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4381);
												mem_vec_4381 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4382);
												mem_vec_4382 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4383);
												mem_vec_4383 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4384);
												mem_vec_4384 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4385);
												mem_vec_4385 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4386);
												mem_vec_4386 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4387);
												mem_vec_4387 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4388);
												mem_vec_4388 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4389);
												mem_vec_4389 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4390);
												mem_vec_4390 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4391);
												mem_vec_4391 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_4392);
												mem_vec_4392 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_4393);
												mem_vec_4393 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_4394);
												mem_vec_4394 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_4395);
												mem_vec_4395 = vec_43;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4368);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4369);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4370);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4371);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4372);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4373);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4374);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4375);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4376);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4377);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4378);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4379);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4380);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4381);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4382);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4383);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4384);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4385);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4386);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4387);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4388);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4389);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_4390);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_4391);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_4392);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_4393);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_4394);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_4395);
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