#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (128, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (1, f); T (1, x); T (17, y); T (4, f); T (1, c); T (34, x);
  T (1, f)]
*/
IND_TYPE c, cp_0, c114_p_0, cp_1, c114, f, fp_0, f152_p_0, f153_p_0, fp_1, f152_p_1, fp_2, f152, f153, h, hp_0, x, xp_0, x152_p_0, x153_p_0, xp_1, x152_p_1, xp_2, x152, x153, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y76 = 0;
IND_TYPE x154 = 0;
IND_TYPE h76 = 0;
IND_TYPE w = 0;
IND_TYPE c115 = 0;
IND_TYPE f154 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_608 ,mem_vec_609 ,mem_vec_610 ,mem_vec_611 ,mem_vec_612 ,mem_vec_613 ,mem_vec_614 ,mem_vec_615 ,mem_vec_616 ,mem_vec_617 ,mem_vec_618 ,mem_vec_619 ,mem_vec_620 ,mem_vec_621 ,mem_vec_622 ,mem_vec_623 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f153 = f154, f153_p_0 = 0;
	f153 < f154 + 256;
	f153 += 256, f153_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (x, 34) (68 / 2)
	for (x153 = x154, x153_p_0 = 0;
		x153 < x154 + 68;
		x153 += 2, x153_p_0 += 2){
		// y = 68, x = 2, h = 3, w = 3, c = 128, f = 256
		// T (c, 1) (128 / 128)
		for (c114 = c115, c114_p_0 = 0;
			c114 < c115 + 128;
			c114 += 128, c114_p_0 += 128){
			// y = 68, x = 2, h = 3, w = 3, c = 128, f = 256
			// T (f, 4) (256 / 64)
			for (f152 = f153, f152_p_1 = f153_p_0, f152_p_0 = 0;
				f152 < f153 + 256;
				f152 += 64, f152_p_1 += 64, f152_p_0 += 64){
				// y = 68, x = 2, h = 3, w = 3, c = 128, f = 64
				// T (y, 17) (68 / 4)
				for (y = y76, yp_0 = 0;
					y < y76 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 2, h = 3, w = 3, c = 128, f = 64
					// T (x, 1) (2 / 2)
					for (x152 = x153, x152_p_1 = x153_p_0, x152_p_0 = 0;
						x152 < x153 + 2;
						x152 += 2, x152_p_1 += 2, x152_p_0 += 2){
						// y = 4, x = 2, h = 3, w = 3, c = 128, f = 64
						// T (f, 1) (64 / 64)
						for (f = f152, fp_2 = f152_p_1, fp_1 = f152_p_0, fp_0 = 0;
							f < f152 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = 4, x = 2, h = 3, w = 3, c = 128, f = 64
							// T (h, 3) (3 / 1)
							for (h = h76, hp_0 = 0;
								h < h76 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 2, h = 1, w = 3, c = 128, f = 64
								// T (x, 2) (2 / 1)
								for (x = x152, xp_2 = x152_p_1, xp_1 = x152_p_0, xp_0 = 0;
									x < x152 + 2;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_608 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_609 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_610 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_611 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = 4, x = 1, h = 1, w = 3, c = 128, f = 64
											// T (c, 128) (128 / 1)
											for (c = c114, cp_1 = c114_p_0, cp_0 = 0;
												c < c114 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_608);
												mem_vec_608 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_609);
												mem_vec_609 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_610);
												mem_vec_610 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_611);
												mem_vec_611 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_612);
												mem_vec_612 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_613);
												mem_vec_613 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_614);
												mem_vec_614 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_615);
												mem_vec_615 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_616);
												mem_vec_616 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_617);
												mem_vec_617 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_618);
												mem_vec_618 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_619);
												mem_vec_619 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_620);
												mem_vec_620 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_621);
												mem_vec_621 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_622);
												mem_vec_622 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_623);
												mem_vec_623 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_608);
												mem_vec_608 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_609);
												mem_vec_609 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_610);
												mem_vec_610 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_611);
												mem_vec_611 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_612);
												mem_vec_612 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_613);
												mem_vec_613 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_614);
												mem_vec_614 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_615);
												mem_vec_615 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_616);
												mem_vec_616 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_617);
												mem_vec_617 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_618);
												mem_vec_618 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_619);
												mem_vec_619 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_620);
												mem_vec_620 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_621);
												mem_vec_621 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_622);
												mem_vec_622 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_623);
												mem_vec_623 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_608);
												mem_vec_608 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_609);
												mem_vec_609 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_610);
												mem_vec_610 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_611);
												mem_vec_611 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_612);
												mem_vec_612 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_613);
												mem_vec_613 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_614);
												mem_vec_614 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_615);
												mem_vec_615 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_616);
												mem_vec_616 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_617);
												mem_vec_617 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_618);
												mem_vec_618 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_619);
												mem_vec_619 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_620);
												mem_vec_620 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_621);
												mem_vec_621 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_622);
												mem_vec_622 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_623);
												mem_vec_623 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_608);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_609);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_610);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_611);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_612);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_613);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_614);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_615);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_616);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_617);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_618);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_619);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_620);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_621);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_622);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_623);
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