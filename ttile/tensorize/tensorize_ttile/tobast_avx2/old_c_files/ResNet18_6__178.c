#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (4, f); T (28, x); T (7, y); T (1, f); T (64, c); T (1, x);
  T (1, f)]
*/
IND_TYPE c, cp_0, c408_p_0, cp_1, c408, f, fp_0, f498_p_0, f499_p_0, fp_1, f498_p_1, fp_2, f498, f499, h, hp_0, x, xp_0, x590_p_0, x591_p_0, xp_1, x590_p_1, xp_2, x590, x591, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y272 = 0;
IND_TYPE x592 = 0;
IND_TYPE h202 = 0;
IND_TYPE w = 0;
IND_TYPE c409 = 0;
IND_TYPE f500 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_2512 ,mem_vec_2513 ,mem_vec_2514 ,mem_vec_2515 ,mem_vec_2516 ,mem_vec_2517 ,mem_vec_2518 ,mem_vec_2519 ,mem_vec_2520 ,mem_vec_2521 ,mem_vec_2522 ,mem_vec_2523 ,mem_vec_2524 ,mem_vec_2525 ,mem_vec_2526 ,mem_vec_2527 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
for (f499 = f500, f499_p_0 = 0;
	f499 < f500 + 128;
	f499 += 128, f499_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (x, 1) (28 / 28)
	for (x591 = x592, x591_p_0 = 0;
		x591 < x592 + 28;
		x591 += 28, x591_p_0 += 28){
		// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
		// T (c, 64) (128 / 2)
		for (c408 = c409, c408_p_0 = 0;
			c408 < c409 + 128;
			c408 += 2, c408_p_0 += 2){
			// y = 28, x = 28, h = 3, w = 3, c = 2, f = 128
			// T (f, 1) (128 / 128)
			for (f498 = f499, f498_p_1 = f499_p_0, f498_p_0 = 0;
				f498 < f499 + 128;
				f498 += 128, f498_p_1 += 128, f498_p_0 += 128){
				// y = 28, x = 28, h = 3, w = 3, c = 2, f = 128
				// T (y, 7) (28 / 4)
				for (y = y272, yp_0 = 0;
					y < y272 + 28;
					y += 4, yp_0 += 4){
					// y = 4, x = 28, h = 3, w = 3, c = 2, f = 128
					// T (x, 28) (28 / 1)
					for (x590 = x591, x590_p_1 = x591_p_0, x590_p_0 = 0;
						x590 < x591 + 28;
						x590 += 1, x590_p_1 += 1, x590_p_0 += 1){
						// y = 4, x = 1, h = 3, w = 3, c = 2, f = 128
						// T (f, 4) (128 / 32)
						for (f = f498, fp_2 = f498_p_1, fp_1 = f498_p_0, fp_0 = 0;
							f < f498 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = 4, x = 1, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h202, hp_0 = 0;
								h < h202 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x590, xp_2 = x590_p_1, xp_1 = x590_p_0, xp_0 = 0;
									x < x590 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2512 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2513 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_2514 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2515 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_2516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_2518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_2520 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2521 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_2522 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2523 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_2524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_2526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 3, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c408, cp_1 = c408_p_0, cp_0 = 0;
												c < c408 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2512);
												mem_vec_2512 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2513);
												mem_vec_2513 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2514);
												mem_vec_2514 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2515);
												mem_vec_2515 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2516);
												mem_vec_2516 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2517);
												mem_vec_2517 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2518);
												mem_vec_2518 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2519);
												mem_vec_2519 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2520);
												mem_vec_2520 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2521);
												mem_vec_2521 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2522);
												mem_vec_2522 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2523);
												mem_vec_2523 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2524);
												mem_vec_2524 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2525);
												mem_vec_2525 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2526);
												mem_vec_2526 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2527);
												mem_vec_2527 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_2512);
												mem_vec_2512 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_2513);
												mem_vec_2513 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_2514);
												mem_vec_2514 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_2515);
												mem_vec_2515 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_2516);
												mem_vec_2516 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_2517);
												mem_vec_2517 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_2518);
												mem_vec_2518 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_2519);
												mem_vec_2519 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_2520);
												mem_vec_2520 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_2521);
												mem_vec_2521 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_2522);
												mem_vec_2522 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_2523);
												mem_vec_2523 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_2524);
												mem_vec_2524 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_2525);
												mem_vec_2525 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_2526);
												mem_vec_2526 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_2527);
												mem_vec_2527 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_2512);
												mem_vec_2512 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_2513);
												mem_vec_2513 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_2514);
												mem_vec_2514 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_2515);
												mem_vec_2515 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_2516);
												mem_vec_2516 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_2517);
												mem_vec_2517 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_2518);
												mem_vec_2518 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_2519);
												mem_vec_2519 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_2520);
												mem_vec_2520 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_2521);
												mem_vec_2521 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_2522);
												mem_vec_2522 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_2523);
												mem_vec_2523 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_2524);
												mem_vec_2524 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_2525);
												mem_vec_2525 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_2526);
												mem_vec_2526 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_2527);
												mem_vec_2527 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2512);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2513);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2514);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2515);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2516);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2517);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2518);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2519);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2520);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2521);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2522);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2523);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2524);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2525);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2526);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2527);
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