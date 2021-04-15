#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (1, f); T (14, x);
  Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))]; T (2, f);
  T (128, c); T (4, f)]
*/
IND_TYPE c, cp_0, c1194_p_0, cp_1, c1194, f, fp_0, f1592_p_0, f1593_p_0, fp_1, f1592_p_1, fp_2, f1592, f1593, h, hp_0, x, xp_0, x1194_p_0, xp_1, x1194, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y796 = 0;
IND_TYPE x1195 = 0;
IND_TYPE h640 = 0;
IND_TYPE w = 0;
IND_TYPE c1195 = 0;
IND_TYPE f1594 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_13920 ,mem_vec_13921 ,mem_vec_13922 ,mem_vec_13923 ,mem_vec_13924 ,mem_vec_13925 ,mem_vec_13926 ,mem_vec_13927 ,mem_vec_13928 ,mem_vec_13929 ,mem_vec_13930 ,mem_vec_13931 ,mem_vec_13932 ,mem_vec_13933 ,mem_vec_13934 ,mem_vec_13935 ,mem_vec_13936 ,mem_vec_13937 ,mem_vec_13938 ,mem_vec_13939 ,mem_vec_13940 ,mem_vec_13941 ,mem_vec_13942 ,mem_vec_13943 ,mem_vec_13944 ,mem_vec_13945 ,mem_vec_13946 ,mem_vec_13947 ,mem_vec_13948 ,mem_vec_13949 ,mem_vec_13950 ,mem_vec_13951 ,mem_vec_13952 ,mem_vec_13953 ,mem_vec_13954 ,mem_vec_13955 ,mem_vec_13956 ,mem_vec_13957 ,mem_vec_13958 ,mem_vec_13959 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f1593 = f1594, f1593_p_0 = 0;
	f1593 < f1594 + 256;
	f1593 += 64, f1593_p_0 += 64){
	// y = 14, x = 14, h = 3, w = 3, c = 128, f = 64
	// T (c, 128) (128 / 1)
	for (c1194 = c1195, c1194_p_0 = 0;
		c1194 < c1195 + 128;
		c1194 += 1, c1194_p_0 += 1){
		// y = 14, x = 14, h = 3, w = 3, c = 1, f = 64
		// T (f, 2) (64 / 32)
		for (f1592 = f1593, f1592_p_1 = f1593_p_0, f1592_p_0 = 0;
			f1592 < f1593 + 64;
			f1592 += 32, f1592_p_1 += 32, f1592_p_0 += 32){
				for (y = y796, yp_0 = 0;
					y < y796 + 8;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
					// T (x, 14) (14 / 1)
					for (x1194 = x1195, x1194_p_0 = 0;
						x1194 < x1195 + 14;
						x1194 += 1, x1194_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
						// T (f, 1) (32 / 32)
						for (f = f1592, fp_2 = f1592_p_1, fp_1 = f1592_p_0, fp_0 = 0;
							f < f1592 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
							// T (h, 3) (3 / 1)
							for (h = h640, hp_0 = 0;
								h < h640 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1194, xp_1 = x1194_p_0, xp_0 = 0;
									x < x1194 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13920 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13921 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_13922 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13923 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_13924 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13925 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_13926 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13927 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_13928 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13929 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_13930 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13931 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_13932 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13933 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_13934 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13935 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c1194, cp_1 = c1194_p_0, cp_0 = 0;
												c < c1194 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13920);
												mem_vec_13920 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13921);
												mem_vec_13921 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13922);
												mem_vec_13922 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13923);
												mem_vec_13923 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13924);
												mem_vec_13924 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13925);
												mem_vec_13925 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13926);
												mem_vec_13926 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13927);
												mem_vec_13927 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13928);
												mem_vec_13928 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13929);
												mem_vec_13929 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13930);
												mem_vec_13930 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13931);
												mem_vec_13931 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13932);
												mem_vec_13932 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13933);
												mem_vec_13933 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13934);
												mem_vec_13934 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13935);
												mem_vec_13935 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_13920);
												mem_vec_13920 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_13921);
												mem_vec_13921 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_13922);
												mem_vec_13922 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_13923);
												mem_vec_13923 = vec_31;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_13924);
												mem_vec_13924 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_13925);
												mem_vec_13925 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_13926);
												mem_vec_13926 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_13927);
												mem_vec_13927 = vec_37;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_13928);
												mem_vec_13928 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_13929);
												mem_vec_13929 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_13930);
												mem_vec_13930 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_13931);
												mem_vec_13931 = vec_42;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_13932);
												mem_vec_13932 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_13933);
												mem_vec_13933 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_13934);
												mem_vec_13934 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_13935);
												mem_vec_13935 = vec_47;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_13920);
												mem_vec_13920 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_13921);
												mem_vec_13921 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_13922);
												mem_vec_13922 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_13923);
												mem_vec_13923 = vec_55;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_13924);
												mem_vec_13924 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_13925);
												mem_vec_13925 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_13926);
												mem_vec_13926 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_13927);
												mem_vec_13927 = vec_61;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_13928);
												mem_vec_13928 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_13929);
												mem_vec_13929 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_13930);
												mem_vec_13930 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_13931);
												mem_vec_13931 = vec_66;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_13932);
												mem_vec_13932 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_13933);
												mem_vec_13933 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_13934);
												mem_vec_13934 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_13935);
												mem_vec_13935 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13920);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13921);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13922);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13923);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13924);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13925);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13926);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13927);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13928);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13929);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13930);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13931);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13932);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13933);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13934);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13935);
								}
							}
						}
					}
				}
				for (y = y796 + 8, yp_0 = 0;
					y < y796 + 8 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
					// T (x, 14) (14 / 1)
					for (x1194 = x1195, x1194_p_0 = 0;
						x1194 < x1195 + 14;
						x1194 += 1, x1194_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
						// T (f, 1) (32 / 32)
						for (f = f1592, fp_2 = f1592_p_1, fp_1 = f1592_p_0, fp_0 = 0;
							f < f1592 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
							// T (h, 3) (3 / 1)
							for (h = h640, hp_0 = 0;
								h < h640 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1194, xp_1 = x1194_p_0, xp_0 = 0;
									x < x1194 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13936 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13937 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_13938 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13939 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_13940 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13941 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_13942 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13943 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_13944 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13945 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_13946 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13947 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_13948 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13949 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_13950 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13951 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_13952 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_13953 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_13954 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_13955 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_13956 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_13957 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_13958 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_13959 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c1194, cp_1 = c1194_p_0, cp_0 = 0;
												c < c1194 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13936);
												mem_vec_13936 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13937);
												mem_vec_13937 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13938);
												mem_vec_13938 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13939);
												mem_vec_13939 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13940);
												mem_vec_13940 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13941);
												mem_vec_13941 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13942);
												mem_vec_13942 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13943);
												mem_vec_13943 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13944);
												mem_vec_13944 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13945);
												mem_vec_13945 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13946);
												mem_vec_13946 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13947);
												mem_vec_13947 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13948);
												mem_vec_13948 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13949);
												mem_vec_13949 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13950);
												mem_vec_13950 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13951);
												mem_vec_13951 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_13952);
												mem_vec_13952 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_13953);
												mem_vec_13953 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_13954);
												mem_vec_13954 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_13955);
												mem_vec_13955 = vec_28;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_13956);
												mem_vec_13956 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_13957);
												mem_vec_13957 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_13958);
												mem_vec_13958 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_13959);
												mem_vec_13959 = vec_33;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_13936);
												mem_vec_13936 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_13937);
												mem_vec_13937 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_13938);
												mem_vec_13938 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_13939);
												mem_vec_13939 = vec_41;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_13940);
												mem_vec_13940 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_13941);
												mem_vec_13941 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_13942);
												mem_vec_13942 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_13943);
												mem_vec_13943 = vec_47;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_13944);
												mem_vec_13944 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_13945);
												mem_vec_13945 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_13946);
												mem_vec_13946 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_13947);
												mem_vec_13947 = vec_52;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_13948);
												mem_vec_13948 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_13949);
												mem_vec_13949 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_13950);
												mem_vec_13950 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_13951);
												mem_vec_13951 = vec_57;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_13952);
												mem_vec_13952 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_13953);
												mem_vec_13953 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_13954);
												mem_vec_13954 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_13955);
												mem_vec_13955 = vec_62;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_13956);
												mem_vec_13956 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_13957);
												mem_vec_13957 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_13958);
												mem_vec_13958 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_13959);
												mem_vec_13959 = vec_67;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_13936);
												mem_vec_13936 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_13937);
												mem_vec_13937 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_13938);
												mem_vec_13938 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_13939);
												mem_vec_13939 = vec_75;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_13940);
												mem_vec_13940 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_13941);
												mem_vec_13941 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_13942);
												mem_vec_13942 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_13943);
												mem_vec_13943 = vec_81;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_13944);
												mem_vec_13944 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_13945);
												mem_vec_13945 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_13946);
												mem_vec_13946 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_13947);
												mem_vec_13947 = vec_86;
												scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_13948);
												mem_vec_13948 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_13949);
												mem_vec_13949 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_13950);
												mem_vec_13950 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_13951);
												mem_vec_13951 = vec_91;
												scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_13952);
												mem_vec_13952 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_13953);
												mem_vec_13953 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_13954);
												mem_vec_13954 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_13955);
												mem_vec_13955 = vec_96;
												scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_13956);
												mem_vec_13956 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_13957);
												mem_vec_13957 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_13958);
												mem_vec_13958 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_13959);
												mem_vec_13959 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13936);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13937);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13938);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13939);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13940);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13941);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13942);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13943);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13944);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13945);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13946);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13947);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13948);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13949);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13950);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13951);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13952);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_13953);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13954);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_13955);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13956);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_13957);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13958);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_13959);
								}
							}
						}
					}
				}
		}
	}
}


}