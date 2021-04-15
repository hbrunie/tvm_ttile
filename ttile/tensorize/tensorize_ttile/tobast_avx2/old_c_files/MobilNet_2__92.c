#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, h); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (14, y); T (2, f); T (16, c); T (1, f); T (2, c); T (56, x);
  T (1, f)]
*/
IND_TYPE c, cp_0, c164_p_0, c165_p_0, cp_1, c164_p_1, cp_2, c164, c165, f, fp_0, f136_p_0, f137_p_0, fp_1, f136_p_1, fp_2, f136, f137, w, wp_0, x, xp_0, x172_p_0, xp_1, x172, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y96 = 0;
IND_TYPE x173 = 0;
IND_TYPE h = 0;
IND_TYPE w96 = 0;
IND_TYPE c166 = 0;
IND_TYPE f138 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_768 ,mem_vec_769 ,mem_vec_770 ,mem_vec_771 ,mem_vec_772 ,mem_vec_773 ,mem_vec_774 ,mem_vec_775 ,mem_vec_776 ,mem_vec_777 ,mem_vec_778 ,mem_vec_779 ,mem_vec_780 ,mem_vec_781 ,mem_vec_782 ,mem_vec_783 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f137 = f138, f137_p_0 = 0;
	f137 < f138 + 64;
	f137 += 64, f137_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (x, 56) (56 / 1)
	for (x172 = x173, x172_p_0 = 0;
		x172 < x173 + 56;
		x172 += 1, x172_p_0 += 1){
		// y = 56, x = 1, h = 3, w = 3, c = 64, f = 64
		// T (c, 2) (64 / 32)
		for (c165 = c166, c165_p_0 = 0;
			c165 < c166 + 64;
			c165 += 32, c165_p_0 += 32){
			// y = 56, x = 1, h = 3, w = 3, c = 32, f = 64
			// T (f, 1) (64 / 64)
			for (f136 = f137, f136_p_1 = f137_p_0, f136_p_0 = 0;
				f136 < f137 + 64;
				f136 += 64, f136_p_1 += 64, f136_p_0 += 64){
				// y = 56, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (c, 16) (32 / 2)
				for (c164 = c165, c164_p_1 = c165_p_0, c164_p_0 = 0;
					c164 < c165 + 32;
					c164 += 2, c164_p_1 += 2, c164_p_0 += 2){
					// y = 56, x = 1, h = 3, w = 3, c = 2, f = 64
					// T (f, 2) (64 / 32)
					for (f = f136, fp_2 = f136_p_1, fp_1 = f136_p_0, fp_0 = 0;
						f < f136 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = 56, x = 1, h = 3, w = 3, c = 2, f = 32
						// T (y, 14) (56 / 4)
						for (y = y96, yp_0 = 0;
							y < y96 + 56;
							y += 4, yp_0 += 4){
							// y = 4, x = 1, h = 3, w = 3, c = 2, f = 32
							// T (w, 3) (3 / 1)
							for (w = w96, wp_0 = 0;
								w < w96 + 3;
								w += 1, wp_0 += 1){
								// y = 4, x = 1, h = 3, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x172, xp_1 = x172_p_0, xp_0 = 0;
									x < x172 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_768 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_769 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_770 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_771 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_772 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_773 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_774 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_775 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_776 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_777 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_778 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_779 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_780 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_781 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_782 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_783 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 3, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c164, cp_2 = c164_p_1, cp_1 = c164_p_0, cp_0 = 0;
												c < c164 + 2;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_768);
												mem_vec_768 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_769);
												mem_vec_769 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_770);
												mem_vec_770 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_771);
												mem_vec_771 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_772);
												mem_vec_772 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_773);
												mem_vec_773 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_774);
												mem_vec_774 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_775);
												mem_vec_775 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_776);
												mem_vec_776 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_777);
												mem_vec_777 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_778);
												mem_vec_778 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_779);
												mem_vec_779 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_780);
												mem_vec_780 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_781);
												mem_vec_781 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_782);
												mem_vec_782 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_783);
												mem_vec_783 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_768);
												mem_vec_768 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_769);
												mem_vec_769 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_770);
												mem_vec_770 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_771);
												mem_vec_771 = vec_31;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_772);
												mem_vec_772 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_773);
												mem_vec_773 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_774);
												mem_vec_774 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_775);
												mem_vec_775 = vec_37;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_776);
												mem_vec_776 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_777);
												mem_vec_777 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_778);
												mem_vec_778 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_779);
												mem_vec_779 = vec_42;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_780);
												mem_vec_780 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_781);
												mem_vec_781 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_782);
												mem_vec_782 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_783);
												mem_vec_783 = vec_47;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_768);
												mem_vec_768 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_769);
												mem_vec_769 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_770);
												mem_vec_770 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_771);
												mem_vec_771 = vec_55;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_772);
												mem_vec_772 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_773);
												mem_vec_773 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_774);
												mem_vec_774 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_775);
												mem_vec_775 = vec_61;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_776);
												mem_vec_776 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_777);
												mem_vec_777 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_778);
												mem_vec_778 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_779);
												mem_vec_779 = vec_66;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_780);
												mem_vec_780 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_781);
												mem_vec_781 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_782);
												mem_vec_782 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_783);
												mem_vec_783 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_768);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_769);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_770);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_771);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_772);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_773);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_774);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_775);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_776);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_777);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_778);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_779);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_780);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_781);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_782);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_783);
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