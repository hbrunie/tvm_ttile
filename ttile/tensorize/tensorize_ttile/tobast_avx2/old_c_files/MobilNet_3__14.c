#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, h); T (8, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (1, f); T (28, x); T (14, y); T (1, f); T (16, c); T (2, x);
  T (4, f)]
*/
IND_TYPE c, cp_0, c172_p_0, cp_1, c172, f, fp_0, f156_p_0, f157_p_0, fp_1, f156_p_1, fp_2, f156, f157, w, wp_0, x, xp_0, x200_p_0, x201_p_0, xp_1, x200_p_1, xp_2, x200, x201, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y100 = 0;
IND_TYPE x202 = 0;
IND_TYPE h = 0;
IND_TYPE w100 = 0;
IND_TYPE c173 = 0;
IND_TYPE f158 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_800 ,mem_vec_801 ,mem_vec_802 ,mem_vec_803 ,mem_vec_804 ,mem_vec_805 ,mem_vec_806 ,mem_vec_807 ,mem_vec_808 ,mem_vec_809 ,mem_vec_810 ,mem_vec_811 ,mem_vec_812 ,mem_vec_813 ,mem_vec_814 ,mem_vec_815 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 4) (128 / 32)
for (f157 = f158, f157_p_0 = 0;
	f157 < f158 + 128;
	f157 += 32, f157_p_0 += 32){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 32
	// T (x, 2) (56 / 28)
	for (x201 = x202, x201_p_0 = 0;
		x201 < x202 + 56;
		x201 += 28, x201_p_0 += 28){
		// y = 56, x = 28, h = 3, w = 3, c = 128, f = 32
		// T (c, 16) (128 / 8)
		for (c172 = c173, c172_p_0 = 0;
			c172 < c173 + 128;
			c172 += 8, c172_p_0 += 8){
			// y = 56, x = 28, h = 3, w = 3, c = 8, f = 32
			// T (f, 1) (32 / 32)
			for (f156 = f157, f156_p_1 = f157_p_0, f156_p_0 = 0;
				f156 < f157 + 32;
				f156 += 32, f156_p_1 += 32, f156_p_0 += 32){
				// y = 56, x = 28, h = 3, w = 3, c = 8, f = 32
				// T (y, 14) (56 / 4)
				for (y = y100, yp_0 = 0;
					y < y100 + 56;
					y += 4, yp_0 += 4){
					// y = 4, x = 28, h = 3, w = 3, c = 8, f = 32
					// T (x, 28) (28 / 1)
					for (x200 = x201, x200_p_1 = x201_p_0, x200_p_0 = 0;
						x200 < x201 + 28;
						x200 += 1, x200_p_1 += 1, x200_p_0 += 1){
						// y = 4, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (f, 1) (32 / 32)
						for (f = f156, fp_2 = f156_p_1, fp_1 = f156_p_0, fp_0 = 0;
							f < f156 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = 4, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w100, wp_0 = 0;
								w < w100 + 3;
								w += 1, wp_0 += 1){
								// y = 4, x = 1, h = 3, w = 1, c = 8, f = 32
								// T (x, 1) (1 / 1)
								for (x = x200, xp_2 = x200_p_1, xp_1 = x200_p_0, xp_0 = 0;
									x < x200 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_800 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_801 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_802 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_803 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_804 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_805 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_806 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_807 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_808 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_809 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_810 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_811 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_812 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_813 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_814 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_815 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 3, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c172, cp_1 = c172_p_0, cp_0 = 0;
												c < c172 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_800);
												mem_vec_800 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_801);
												mem_vec_801 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_802);
												mem_vec_802 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_803);
												mem_vec_803 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_804);
												mem_vec_804 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_805);
												mem_vec_805 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_806);
												mem_vec_806 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_807);
												mem_vec_807 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_808);
												mem_vec_808 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_809);
												mem_vec_809 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_810);
												mem_vec_810 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_811);
												mem_vec_811 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_812);
												mem_vec_812 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_813);
												mem_vec_813 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_814);
												mem_vec_814 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_815);
												mem_vec_815 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_800);
												mem_vec_800 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_801);
												mem_vec_801 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_802);
												mem_vec_802 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_803);
												mem_vec_803 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_804);
												mem_vec_804 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_805);
												mem_vec_805 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_806);
												mem_vec_806 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_807);
												mem_vec_807 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_808);
												mem_vec_808 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_809);
												mem_vec_809 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_810);
												mem_vec_810 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_811);
												mem_vec_811 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_812);
												mem_vec_812 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_813);
												mem_vec_813 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_814);
												mem_vec_814 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_815);
												mem_vec_815 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_800);
												mem_vec_800 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_801);
												mem_vec_801 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_802);
												mem_vec_802 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_803);
												mem_vec_803 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_804);
												mem_vec_804 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_805);
												mem_vec_805 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_806);
												mem_vec_806 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_807);
												mem_vec_807 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_808);
												mem_vec_808 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_809);
												mem_vec_809 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_810);
												mem_vec_810 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_811);
												mem_vec_811 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_812);
												mem_vec_812 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_813);
												mem_vec_813 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_814);
												mem_vec_814 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_815);
												mem_vec_815 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_800);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_801);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_802);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_803);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_804);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_805);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_806);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_807);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_808);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_809);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_810);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_811);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_812);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_813);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_814);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_815);
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