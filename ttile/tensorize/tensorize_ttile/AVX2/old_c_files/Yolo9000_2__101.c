#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (3, h);
  T (1, x); T (16, y); T (2, c); T (2, f); T (136, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (2, x)]
*/
IND_TYPE c, cp_0, c384_p_0, cp_1, c384, f, fp_0, h, hp_0, x, xp_0, x512_p_0, x513_p_0, xp_1, x512_p_1, xp_2, x512, x513, y, yp_0, y472_p_0, yp_1, y472;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y473 = 0;
IND_TYPE x514 = 0;
IND_TYPE h156 = 0;
IND_TYPE w = 0;
IND_TYPE c385 = 0;
IND_TYPE f251 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_4920 ,mem_vec_4921 ,mem_vec_4922 ,mem_vec_4923 ,mem_vec_4924 ,mem_vec_4925 ,mem_vec_4926 ,mem_vec_4927 ,mem_vec_4928 ,mem_vec_4929 ,mem_vec_4930 ,mem_vec_4931 ,mem_vec_4932 ,mem_vec_4933 ,mem_vec_4934 ,mem_vec_4935 ,mem_vec_4936 ,mem_vec_4937 ,mem_vec_4938 ,mem_vec_4939 ,mem_vec_4940 ,mem_vec_4941 ,mem_vec_4942 ,mem_vec_4943 ,mem_vec_4944 ,mem_vec_4945 ,mem_vec_4946 ,mem_vec_4947 ,mem_vec_4948 ,mem_vec_4949 ,mem_vec_4950 ,mem_vec_4951 ,mem_vec_4952 ,mem_vec_4953 ,mem_vec_4954 ,mem_vec_4955 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
for (x513 = x514, x513_p_0 = 0;
	x513 < x514 + 272;
	x513 += 136, x513_p_0 += 136){
		for (y472 = y473, y472_p_0 = 0;
			y472 < y473 + 192;
			y472 += 64, y472_p_0 += 64){
			// y = 16 * ph_y, x = 136, h = 3, w = 3, c = 32, f = 64
			// T (x, 136) (136 / 1)
			for (x512 = x513, x512_p_1 = x513_p_0, x512_p_0 = 0;
				x512 < x513 + 136;
				x512 += 1, x512_p_1 += 1, x512_p_0 += 1){
				// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f251, fp_0 = 0;
					f < f251 + 64;
					f += 32, fp_0 += 32){
					// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c384 = c385, c384_p_0 = 0;
						c384 < c385 + 32;
						c384 += 16, c384_p_0 += 16){
						// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (y, 16) (16 * ph_y / ph_y)
						for (y = y472, yp_1 = y472_p_0, yp_0 = 0;
							y < y472 + 64;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (x, 1) (1 / 1)
							for (x = x512, xp_2 = x512_p_1, xp_1 = x512_p_0, xp_0 = 0;
								x < x512 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h156, hp_0 = 0;
									h < h156 + 3;
									h += 1, hp_0 += 1){
											mem_vec_4920 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4921 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4922 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4923 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4924 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4925 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4926 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4927 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4928 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4929 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4930 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4931 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4932 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4933 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4934 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4935 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c384, cp_1 = c384_p_0, cp_0 = 0;
												c < c384 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4920);
												mem_vec_4920 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4921);
												mem_vec_4921 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4922);
												mem_vec_4922 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4923);
												mem_vec_4923 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4924);
												mem_vec_4924 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4925);
												mem_vec_4925 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4926);
												mem_vec_4926 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4927);
												mem_vec_4927 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4928);
												mem_vec_4928 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4929);
												mem_vec_4929 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4930);
												mem_vec_4930 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4931);
												mem_vec_4931 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4932);
												mem_vec_4932 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4933);
												mem_vec_4933 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4934);
												mem_vec_4934 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4935);
												mem_vec_4935 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_4920);
												mem_vec_4920 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_4921);
												mem_vec_4921 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_4922);
												mem_vec_4922 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_4923);
												mem_vec_4923 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_4924);
												mem_vec_4924 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_4925);
												mem_vec_4925 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_4926);
												mem_vec_4926 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_4927);
												mem_vec_4927 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_4928);
												mem_vec_4928 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_4929);
												mem_vec_4929 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_4930);
												mem_vec_4930 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_4931);
												mem_vec_4931 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_4932);
												mem_vec_4932 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_4933);
												mem_vec_4933 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_4934);
												mem_vec_4934 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_4935);
												mem_vec_4935 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_4920);
												mem_vec_4920 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_4921);
												mem_vec_4921 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_4922);
												mem_vec_4922 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_4923);
												mem_vec_4923 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_4924);
												mem_vec_4924 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_4925);
												mem_vec_4925 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_4926);
												mem_vec_4926 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_4927);
												mem_vec_4927 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_4928);
												mem_vec_4928 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_4929);
												mem_vec_4929 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_4930);
												mem_vec_4930 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_4931);
												mem_vec_4931 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_4932);
												mem_vec_4932 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_4933);
												mem_vec_4933 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_4934);
												mem_vec_4934 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_4935);
												mem_vec_4935 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4920);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4921);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4922);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4923);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4924);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4925);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4926);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4927);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4928);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4929);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4930);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4931);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4932);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4933);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4934);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4935);
								}
							}
						}
					}
				}
			}
		}
		for (y472 = y473 + 192, y472_p_0 = 0;
			y472 < y473 + 192 + 80;
			y472 += 80, y472_p_0 += 80){
			// y = 16 * ph_y, x = 136, h = 3, w = 3, c = 32, f = 64
			// T (x, 136) (136 / 1)
			for (x512 = x513, x512_p_1 = x513_p_0, x512_p_0 = 0;
				x512 < x513 + 136;
				x512 += 1, x512_p_1 += 1, x512_p_0 += 1){
				// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f251, fp_0 = 0;
					f < f251 + 64;
					f += 32, fp_0 += 32){
					// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c384 = c385, c384_p_0 = 0;
						c384 < c385 + 32;
						c384 += 16, c384_p_0 += 16){
						// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (y, 16) (16 * ph_y / ph_y)
						for (y = y472, yp_1 = y472_p_0, yp_0 = 0;
							y < y472 + 80;
							y += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (x, 1) (1 / 1)
							for (x = x512, xp_2 = x512_p_1, xp_1 = x512_p_0, xp_0 = 0;
								x < x512 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h156, hp_0 = 0;
									h < h156 + 3;
									h += 1, hp_0 += 1){
											mem_vec_4936 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4937 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4938 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4939 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4940 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4941 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4942 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4943 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4944 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4945 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4946 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4947 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4948 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4949 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4950 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4951 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_4952 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4953 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_4954 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4955 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c384, cp_1 = c384_p_0, cp_0 = 0;
												c < c384 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4936);
												mem_vec_4936 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4937);
												mem_vec_4937 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4938);
												mem_vec_4938 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4939);
												mem_vec_4939 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4940);
												mem_vec_4940 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4941);
												mem_vec_4941 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4942);
												mem_vec_4942 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4943);
												mem_vec_4943 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4944);
												mem_vec_4944 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4945);
												mem_vec_4945 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4946);
												mem_vec_4946 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4947);
												mem_vec_4947 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4948);
												mem_vec_4948 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4949);
												mem_vec_4949 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4950);
												mem_vec_4950 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4951);
												mem_vec_4951 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_4952);
												mem_vec_4952 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_4953);
												mem_vec_4953 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_4954);
												mem_vec_4954 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_4955);
												mem_vec_4955 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_4936);
												mem_vec_4936 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_4937);
												mem_vec_4937 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_4938);
												mem_vec_4938 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_4939);
												mem_vec_4939 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_4940);
												mem_vec_4940 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_4941);
												mem_vec_4941 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_4942);
												mem_vec_4942 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_4943);
												mem_vec_4943 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_4944);
												mem_vec_4944 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_4945);
												mem_vec_4945 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_4946);
												mem_vec_4946 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_4947);
												mem_vec_4947 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_4948);
												mem_vec_4948 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_4949);
												mem_vec_4949 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_4950);
												mem_vec_4950 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_4951);
												mem_vec_4951 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_4952);
												mem_vec_4952 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_4953);
												mem_vec_4953 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_4954);
												mem_vec_4954 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_4955);
												mem_vec_4955 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_4936);
												mem_vec_4936 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_4937);
												mem_vec_4937 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_4938);
												mem_vec_4938 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_4939);
												mem_vec_4939 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_4940);
												mem_vec_4940 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_4941);
												mem_vec_4941 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_4942);
												mem_vec_4942 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_4943);
												mem_vec_4943 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_4944);
												mem_vec_4944 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_4945);
												mem_vec_4945 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_4946);
												mem_vec_4946 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_4947);
												mem_vec_4947 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_4948);
												mem_vec_4948 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_4949);
												mem_vec_4949 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_4950);
												mem_vec_4950 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_4951);
												mem_vec_4951 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_4952);
												mem_vec_4952 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_4953);
												mem_vec_4953 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_4954);
												mem_vec_4954 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_4955);
												mem_vec_4955 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4936);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4937);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4938);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4939);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4940);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4941);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4942);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4943);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4944);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4945);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4946);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4947);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4948);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4949);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4950);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4951);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4952);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_4953);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4954);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_4955);
								}
							}
						}
					}
				}
			}
		}
}


}