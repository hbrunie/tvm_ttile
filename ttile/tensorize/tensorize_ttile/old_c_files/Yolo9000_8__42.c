#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (128, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (2, f); T (2, x); T (17, y); T (2, f); T (1, c); T (17, x);
  T (1, f)]
*/
IND_TYPE c, cp_0, c90_p_0, cp_1, c90, f, fp_0, f120_p_0, f121_p_0, fp_1, f120_p_1, fp_2, f120, f121, h, hp_0, x, xp_0, x120_p_0, x121_p_0, xp_1, x120_p_1, xp_2, x120, x121, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y60 = 0;
IND_TYPE x122 = 0;
IND_TYPE h60 = 0;
IND_TYPE w = 0;
IND_TYPE c91 = 0;
IND_TYPE f122 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_480 ,mem_vec_481 ,mem_vec_482 ,mem_vec_483 ,mem_vec_484 ,mem_vec_485 ,mem_vec_486 ,mem_vec_487 ,mem_vec_488 ,mem_vec_489 ,mem_vec_490 ,mem_vec_491 ,mem_vec_492 ,mem_vec_493 ,mem_vec_494 ,mem_vec_495 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f121 = f122, f121_p_0 = 0;
	f121 < f122 + 256;
	f121 += 256, f121_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (x, 17) (68 / 4)
	for (x121 = x122, x121_p_0 = 0;
		x121 < x122 + 68;
		x121 += 4, x121_p_0 += 4){
		// y = 68, x = 4, h = 3, w = 3, c = 128, f = 256
		// T (c, 1) (128 / 128)
		for (c90 = c91, c90_p_0 = 0;
			c90 < c91 + 128;
			c90 += 128, c90_p_0 += 128){
			// y = 68, x = 4, h = 3, w = 3, c = 128, f = 256
			// T (f, 2) (256 / 128)
			for (f120 = f121, f120_p_1 = f121_p_0, f120_p_0 = 0;
				f120 < f121 + 256;
				f120 += 128, f120_p_1 += 128, f120_p_0 += 128){
				// y = 68, x = 4, h = 3, w = 3, c = 128, f = 128
				// T (y, 17) (68 / 4)
				for (y = y60, yp_0 = 0;
					y < y60 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 4, h = 3, w = 3, c = 128, f = 128
					// T (x, 2) (4 / 2)
					for (x120 = x121, x120_p_1 = x121_p_0, x120_p_0 = 0;
						x120 < x121 + 4;
						x120 += 2, x120_p_1 += 2, x120_p_0 += 2){
						// y = 4, x = 2, h = 3, w = 3, c = 128, f = 128
						// T (f, 2) (128 / 64)
						for (f = f120, fp_2 = f120_p_1, fp_1 = f120_p_0, fp_0 = 0;
							f < f120 + 128;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = 4, x = 2, h = 3, w = 3, c = 128, f = 64
							// T (h, 3) (3 / 1)
							for (h = h60, hp_0 = 0;
								h < h60 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 2, h = 1, w = 3, c = 128, f = 64
								// T (x, 2) (2 / 1)
								for (x = x120, xp_2 = x120_p_1, xp_1 = x120_p_0, xp_0 = 0;
									x < x120 + 2;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_480 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_481 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_482 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_483 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = 4, x = 1, h = 1, w = 3, c = 128, f = 64
											// T (c, 128) (128 / 1)
											for (c = c90, cp_1 = c90_p_0, cp_0 = 0;
												c < c90 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_480);
												mem_vec_480 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_481);
												mem_vec_481 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_482);
												mem_vec_482 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_483);
												mem_vec_483 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_484);
												mem_vec_484 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_485);
												mem_vec_485 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_486);
												mem_vec_486 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_487);
												mem_vec_487 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_488);
												mem_vec_488 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_489);
												mem_vec_489 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_490);
												mem_vec_490 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_491);
												mem_vec_491 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_492);
												mem_vec_492 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_493);
												mem_vec_493 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_494);
												mem_vec_494 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_495);
												mem_vec_495 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_480);
												mem_vec_480 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_481);
												mem_vec_481 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_482);
												mem_vec_482 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_483);
												mem_vec_483 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_484);
												mem_vec_484 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_485);
												mem_vec_485 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_486);
												mem_vec_486 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_487);
												mem_vec_487 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_488);
												mem_vec_488 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_489);
												mem_vec_489 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_490);
												mem_vec_490 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_491);
												mem_vec_491 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_492);
												mem_vec_492 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_493);
												mem_vec_493 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_494);
												mem_vec_494 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_495);
												mem_vec_495 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_480);
												mem_vec_480 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_481);
												mem_vec_481 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_482);
												mem_vec_482 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_483);
												mem_vec_483 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_484);
												mem_vec_484 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_485);
												mem_vec_485 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_486);
												mem_vec_486 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_487);
												mem_vec_487 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_488);
												mem_vec_488 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_489);
												mem_vec_489 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_490);
												mem_vec_490 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_491);
												mem_vec_491 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_492);
												mem_vec_492 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_493);
												mem_vec_493 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_494);
												mem_vec_494 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_495);
												mem_vec_495 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_480);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_481);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_482);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_483);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_484);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_485);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_486);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_487);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_488);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_489);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_490);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_491);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_492);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_493);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_494);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_495);
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