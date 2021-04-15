#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (2, f); T (7, x); T (7, y); T (2, f); T (128, c); T (4, x);
  T (2, f)]
*/
IND_TYPE c, cp_0, c456_p_0, cp_1, c456, f, fp_0, f608_p_0, f609_p_0, fp_1, f608_p_1, fp_2, f608, f609, h, hp_0, x, xp_0, x608_p_0, x609_p_0, xp_1, x608_p_1, xp_2, x608, x609, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y304 = 0;
IND_TYPE x610 = 0;
IND_TYPE h214 = 0;
IND_TYPE w = 0;
IND_TYPE c457 = 0;
IND_TYPE f610 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3056 ,mem_vec_3057 ,mem_vec_3058 ,mem_vec_3059 ,mem_vec_3060 ,mem_vec_3061 ,mem_vec_3062 ,mem_vec_3063 ,mem_vec_3064 ,mem_vec_3065 ,mem_vec_3066 ,mem_vec_3067 ,mem_vec_3068 ,mem_vec_3069 ,mem_vec_3070 ,mem_vec_3071 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f609 = f610, f609_p_0 = 0;
	f609 < f610 + 256;
	f609 += 128, f609_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 128
	// T (x, 4) (28 / 7)
	for (x609 = x610, x609_p_0 = 0;
		x609 < x610 + 28;
		x609 += 7, x609_p_0 += 7){
		// y = 28, x = 7, h = 3, w = 3, c = 256, f = 128
		// T (c, 128) (256 / 2)
		for (c456 = c457, c456_p_0 = 0;
			c456 < c457 + 256;
			c456 += 2, c456_p_0 += 2){
			// y = 28, x = 7, h = 3, w = 3, c = 2, f = 128
			// T (f, 2) (128 / 64)
			for (f608 = f609, f608_p_1 = f609_p_0, f608_p_0 = 0;
				f608 < f609 + 128;
				f608 += 64, f608_p_1 += 64, f608_p_0 += 64){
				// y = 28, x = 7, h = 3, w = 3, c = 2, f = 64
				// T (y, 7) (28 / 4)
				for (y = y304, yp_0 = 0;
					y < y304 + 28;
					y += 4, yp_0 += 4){
					// y = 4, x = 7, h = 3, w = 3, c = 2, f = 64
					// T (x, 7) (7 / 1)
					for (x608 = x609, x608_p_1 = x609_p_0, x608_p_0 = 0;
						x608 < x609 + 7;
						x608 += 1, x608_p_1 += 1, x608_p_0 += 1){
						// y = 4, x = 1, h = 3, w = 3, c = 2, f = 64
						// T (f, 2) (64 / 32)
						for (f = f608, fp_2 = f608_p_1, fp_1 = f608_p_0, fp_0 = 0;
							f < f608 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = 4, x = 1, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h214, hp_0 = 0;
								h < h214 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x608, xp_2 = x608_p_1, xp_1 = x608_p_0, xp_0 = 0;
									x < x608 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3056 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3057 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_3058 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3059 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_3060 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3061 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_3062 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3063 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_3064 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3065 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_3066 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3067 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_3068 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3069 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_3070 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3071 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 3, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c456, cp_1 = c456_p_0, cp_0 = 0;
												c < c456 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3056);
												mem_vec_3056 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3057);
												mem_vec_3057 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3058);
												mem_vec_3058 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3059);
												mem_vec_3059 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3060);
												mem_vec_3060 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3061);
												mem_vec_3061 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3062);
												mem_vec_3062 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3063);
												mem_vec_3063 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3064);
												mem_vec_3064 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3065);
												mem_vec_3065 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3066);
												mem_vec_3066 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3067);
												mem_vec_3067 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3068);
												mem_vec_3068 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3069);
												mem_vec_3069 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3070);
												mem_vec_3070 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3071);
												mem_vec_3071 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_3056);
												mem_vec_3056 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_3057);
												mem_vec_3057 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_3058);
												mem_vec_3058 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_3059);
												mem_vec_3059 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_3060);
												mem_vec_3060 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_3061);
												mem_vec_3061 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_3062);
												mem_vec_3062 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_3063);
												mem_vec_3063 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_3064);
												mem_vec_3064 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_3065);
												mem_vec_3065 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_3066);
												mem_vec_3066 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_3067);
												mem_vec_3067 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_3068);
												mem_vec_3068 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_3069);
												mem_vec_3069 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_3070);
												mem_vec_3070 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_3071);
												mem_vec_3071 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_3056);
												mem_vec_3056 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_3057);
												mem_vec_3057 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_3058);
												mem_vec_3058 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_3059);
												mem_vec_3059 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_3060);
												mem_vec_3060 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_3061);
												mem_vec_3061 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_3062);
												mem_vec_3062 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_3063);
												mem_vec_3063 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_3064);
												mem_vec_3064 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_3065);
												mem_vec_3065 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_3066);
												mem_vec_3066 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_3067);
												mem_vec_3067 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_3068);
												mem_vec_3068 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_3069);
												mem_vec_3069 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_3070);
												mem_vec_3070 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_3071);
												mem_vec_3071 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3056);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3057);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3058);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3059);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3060);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3061);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3062);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3063);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3064);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3065);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3066);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3067);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3068);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3069);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3070);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3071);
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