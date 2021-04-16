#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (17, x);
  T (3, w); T (4, c); T (1, y); T (8, f); T (8, x);
  Lambda_apply y [((Iter 9), (Arg 9)); ((Iter 5), (Arg 11))]; T (1, x)]
*/
IND_TYPE c, cp_0, c513_p_0, cp_1, c513, f, fp_0, w, wp_0, x, xp_0, x684_p_0, x685_p_0, xp_1, x684_p_1, xp_2, x684, x685, y, yp_0, y470_p_0, yp_1, y470;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y471 = 0;
IND_TYPE x686 = 0;
IND_TYPE h = 0;
IND_TYPE w327 = 0;
IND_TYPE c514 = 0;
IND_TYPE f385 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_5920 ,mem_vec_5921 ,mem_vec_5922 ,mem_vec_5923 ,mem_vec_5924 ,mem_vec_5925 ,mem_vec_5926 ,mem_vec_5927 ,mem_vec_5928 ,mem_vec_5929 ,mem_vec_5930 ,mem_vec_5931 ,mem_vec_5932 ,mem_vec_5933 ,mem_vec_5934 ,mem_vec_5935 ,mem_vec_5936 ,mem_vec_5937 ,mem_vec_5938 ,mem_vec_5939 ,mem_vec_5940 ,mem_vec_5941 ,mem_vec_5942 ,mem_vec_5943 ,mem_vec_5944 ,mem_vec_5945 ,mem_vec_5946 ,mem_vec_5947 ,mem_vec_5948 ,mem_vec_5949 ,mem_vec_5950 ,mem_vec_5951 ,mem_vec_5952 ,mem_vec_5953 ,mem_vec_5954 ,mem_vec_5955 ,mem_vec_5956 ,mem_vec_5957 ,mem_vec_5958 ,mem_vec_5959 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
for (x685 = x686, x685_p_0 = 0;
	x685 < x686 + 136;
	x685 += 136, x685_p_0 += 136){
		for (y470 = y471, y470_p_0 = 0;
			y470 < y471 + 81;
			y470 += 9, y470_p_0 += 9){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 8) (136 / 17)
			for (x684 = x685, x684_p_1 = x685_p_0, x684_p_0 = 0;
				x684 < x685 + 136;
				x684 += 17, x684_p_1 += 17, x684_p_0 += 17){
				// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 128
				// T (f, 8) (128 / 16)
				for (f = f385, fp_0 = 0;
					f < f385 + 128;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
					// T (y, 1) (ph_y / ph_y)
					for (y = y470, yp_1 = y470_p_0, yp_0 = 0;
						y < y470 + 9;
						y += 9, yp_1 += 9, yp_0 += 9){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
						// T (c, 4) (64 / 16)
						for (c513 = c514, c513_p_0 = 0;
							c513 < c514 + 64;
							c513 += 16, c513_p_0 += 16){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w327, wp_0 = 0;
								w < w327 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 16
								// T (x, 17) (17 / 1)
								for (x = x684, xp_2 = x684_p_1, xp_1 = x684_p_0, xp_0 = 0;
									x < x684 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5920 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5921 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5922 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5923 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5924 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5925 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5926 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5927 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5928 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5929 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_5930 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5931 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_5932 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5933 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_5934 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5935 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_5936 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_5937 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c513, cp_1 = c513_p_0, cp_0 = 0;
												c < c513 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5920);
												mem_vec_5920 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5921);
												mem_vec_5921 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_5922);
												mem_vec_5922 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_5923);
												mem_vec_5923 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_5924);
												mem_vec_5924 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_5925);
												mem_vec_5925 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_5926);
												mem_vec_5926 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_5927);
												mem_vec_5927 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5928);
												mem_vec_5928 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5929);
												mem_vec_5929 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_5930);
												mem_vec_5930 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_5931);
												mem_vec_5931 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_5932);
												mem_vec_5932 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_5933);
												mem_vec_5933 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_5934);
												mem_vec_5934 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_5935);
												mem_vec_5935 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_5936);
												mem_vec_5936 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_5937);
												mem_vec_5937 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_5920);
												mem_vec_5920 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_5921);
												mem_vec_5921 = vec_32;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_31, mem_vec_5922);
												mem_vec_5922 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_33, mem_vec_5923);
												mem_vec_5923 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_31, mem_vec_5924);
												mem_vec_5924 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_33, mem_vec_5925);
												mem_vec_5925 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_31, mem_vec_5926);
												mem_vec_5926 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_33, mem_vec_5927);
												mem_vec_5927 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_5928);
												mem_vec_5928 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_5929);
												mem_vec_5929 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_31, mem_vec_5930);
												mem_vec_5930 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_33, mem_vec_5931);
												mem_vec_5931 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_31, mem_vec_5932);
												mem_vec_5932 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_33, mem_vec_5933);
												mem_vec_5933 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_31, mem_vec_5934);
												mem_vec_5934 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_33, mem_vec_5935);
												mem_vec_5935 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_31, mem_vec_5936);
												mem_vec_5936 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_33, mem_vec_5937);
												mem_vec_5937 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_5920);
												mem_vec_5920 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_5921);
												mem_vec_5921 = vec_61;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_60, mem_vec_5922);
												mem_vec_5922 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_62, mem_vec_5923);
												mem_vec_5923 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_60, mem_vec_5924);
												mem_vec_5924 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_62, mem_vec_5925);
												mem_vec_5925 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_60, mem_vec_5926);
												mem_vec_5926 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_62, mem_vec_5927);
												mem_vec_5927 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_5928);
												mem_vec_5928 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_5929);
												mem_vec_5929 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_60, mem_vec_5930);
												mem_vec_5930 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_62, mem_vec_5931);
												mem_vec_5931 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_60, mem_vec_5932);
												mem_vec_5932 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_62, mem_vec_5933);
												mem_vec_5933 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_60, mem_vec_5934);
												mem_vec_5934 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_62, mem_vec_5935);
												mem_vec_5935 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_60, mem_vec_5936);
												mem_vec_5936 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_62, mem_vec_5937);
												mem_vec_5937 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5920);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5921);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5922);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5923);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5924);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5925);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5926);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5927);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5928);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5929);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5930);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_5931);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5932);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_5933);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5934);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_5935);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5936);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_5937);
								}
							}
						}
					}
				}
			}
		}
		for (y470 = y471 + 81, y470_p_0 = 0;
			y470 < y471 + 81 + 55;
			y470 += 11, y470_p_0 += 11){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 8) (136 / 17)
			for (x684 = x685, x684_p_1 = x685_p_0, x684_p_0 = 0;
				x684 < x685 + 136;
				x684 += 17, x684_p_1 += 17, x684_p_0 += 17){
				// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 128
				// T (f, 8) (128 / 16)
				for (f = f385, fp_0 = 0;
					f < f385 + 128;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
					// T (y, 1) (ph_y / ph_y)
					for (y = y470, yp_1 = y470_p_0, yp_0 = 0;
						y < y470 + 11;
						y += 11, yp_1 += 11, yp_0 += 11){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
						// T (c, 4) (64 / 16)
						for (c513 = c514, c513_p_0 = 0;
							c513 < c514 + 64;
							c513 += 16, c513_p_0 += 16){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w327, wp_0 = 0;
								w < w327 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 16
								// T (x, 17) (17 / 1)
								for (x = x684, xp_2 = x684_p_1, xp_1 = x684_p_0, xp_0 = 0;
									x < x684 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5938 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5939 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5940 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5941 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5942 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5943 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5944 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5945 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5946 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5947 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_5948 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5949 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_5950 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5951 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_5952 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5953 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_5954 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_5955 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_5956 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_5957 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_5958 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_5959 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c513, cp_1 = c513_p_0, cp_0 = 0;
												c < c513 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5938);
												mem_vec_5938 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5939);
												mem_vec_5939 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_5940);
												mem_vec_5940 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_5941);
												mem_vec_5941 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_5942);
												mem_vec_5942 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_5943);
												mem_vec_5943 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_5944);
												mem_vec_5944 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_5945);
												mem_vec_5945 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5946);
												mem_vec_5946 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5947);
												mem_vec_5947 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_5948);
												mem_vec_5948 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_5949);
												mem_vec_5949 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_5950);
												mem_vec_5950 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_5951);
												mem_vec_5951 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_5952);
												mem_vec_5952 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_5953);
												mem_vec_5953 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_5954);
												mem_vec_5954 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_5955);
												mem_vec_5955 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_5956);
												mem_vec_5956 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_5957);
												mem_vec_5957 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_5958);
												mem_vec_5958 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_5959);
												mem_vec_5959 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_36 = _mm256_set1_ps(scal_11);
												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_5938);
												mem_vec_5938 = vec_35;

												vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_5939);
												mem_vec_5939 = vec_38;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_37, mem_vec_5940);
												mem_vec_5940 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_39, mem_vec_5941);
												mem_vec_5941 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_5942);
												mem_vec_5942 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_39, mem_vec_5943);
												mem_vec_5943 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_37, mem_vec_5944);
												mem_vec_5944 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_39, mem_vec_5945);
												mem_vec_5945 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_37, mem_vec_5946);
												mem_vec_5946 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_39, mem_vec_5947);
												mem_vec_5947 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_5948);
												mem_vec_5948 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_5949);
												mem_vec_5949 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_37, mem_vec_5950);
												mem_vec_5950 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_39, mem_vec_5951);
												mem_vec_5951 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_37, mem_vec_5952);
												mem_vec_5952 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_39, mem_vec_5953);
												mem_vec_5953 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_5954);
												mem_vec_5954 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_5955);
												mem_vec_5955 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_37, mem_vec_5956);
												mem_vec_5956 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_39, mem_vec_5957);
												mem_vec_5957 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_37, mem_vec_5958);
												mem_vec_5958 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_39, mem_vec_5959);
												mem_vec_5959 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_71 = _mm256_set1_ps(scal_22);
												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_5938);
												mem_vec_5938 = vec_70;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_5939);
												mem_vec_5939 = vec_73;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_72, mem_vec_5940);
												mem_vec_5940 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_74, mem_vec_5941);
												mem_vec_5941 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_72, mem_vec_5942);
												mem_vec_5942 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_74, mem_vec_5943);
												mem_vec_5943 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_72, mem_vec_5944);
												mem_vec_5944 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_74, mem_vec_5945);
												mem_vec_5945 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_72, mem_vec_5946);
												mem_vec_5946 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_74, mem_vec_5947);
												mem_vec_5947 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_5948);
												mem_vec_5948 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_5949);
												mem_vec_5949 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_72, mem_vec_5950);
												mem_vec_5950 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_74, mem_vec_5951);
												mem_vec_5951 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_72, mem_vec_5952);
												mem_vec_5952 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_74, mem_vec_5953);
												mem_vec_5953 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_5954);
												mem_vec_5954 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_5955);
												mem_vec_5955 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_72, mem_vec_5956);
												mem_vec_5956 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_74, mem_vec_5957);
												mem_vec_5957 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_72, mem_vec_5958);
												mem_vec_5958 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_74, mem_vec_5959);
												mem_vec_5959 = vec_104;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5938);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5939);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5940);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5941);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5942);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5943);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5944);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5945);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5946);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5947);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5948);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_5949);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5950);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_5951);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5952);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_5953);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5954);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_5955);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5956);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_5957);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5958);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_5959);
								}
							}
						}
					}
				}
			}
		}
}


}