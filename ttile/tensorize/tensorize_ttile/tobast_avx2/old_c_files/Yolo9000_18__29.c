#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (8, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]; T (2, f);
  T (8, c); T (2, f)]
*/
IND_TYPE c, cp_0, c576_p_0, cp_1, c576, f, fp_0, f768_p_0, f769_p_0, fp_1, f768_p_1, fp_2, f768, f769, w, wp_0, x, xp_0, x576_p_0, xp_1, x576, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y384 = 0;
IND_TYPE x577 = 0;
IND_TYPE h = 0;
IND_TYPE w384 = 0;
IND_TYPE c577 = 0;
IND_TYPE f770 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7060 ,mem_vec_7061 ,mem_vec_7062 ,mem_vec_7063 ,mem_vec_7064 ,mem_vec_7065 ,mem_vec_7066 ,mem_vec_7067 ,mem_vec_7068 ,mem_vec_7069 ,mem_vec_7070 ,mem_vec_7071 ,mem_vec_7072 ,mem_vec_7073 ,mem_vec_7074 ,mem_vec_7075 ,mem_vec_7076 ,mem_vec_7077 ,mem_vec_7078 ,mem_vec_7079 ,mem_vec_7080 ,mem_vec_7081 ,mem_vec_7082 ,mem_vec_7083 ,mem_vec_7084 ,mem_vec_7085 ,mem_vec_7086 ,mem_vec_7087 ,mem_vec_7088 ,mem_vec_7089 ,mem_vec_7090 ,mem_vec_7091 ,mem_vec_7092 ,mem_vec_7093 ,mem_vec_7094 ,mem_vec_7095 ,mem_vec_7096 ,mem_vec_7097 ,mem_vec_7098 ,mem_vec_7099 ,mem_vec_7100 ,mem_vec_7101 ,mem_vec_7102 ,mem_vec_7103 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
for (f769 = f770, f769_p_0 = 0;
	f769 < f770 + 1024;
	f769 += 512, f769_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
	// T (c, 8) (512 / 64)
	for (c576 = c577, c576_p_0 = 0;
		c576 < c577 + 512;
		c576 += 64, c576_p_0 += 64){
		// y = 17, x = 17, h = 3, w = 3, c = 64, f = 512
		// T (f, 2) (512 / 256)
		for (f768 = f769, f768_p_1 = f769_p_0, f768_p_0 = 0;
			f768 < f769 + 512;
			f768 += 256, f768_p_1 += 256, f768_p_0 += 256){
				for (y = y384, yp_0 = 0;
					y < y384 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 256
					// T (x, 17) (17 / 1)
					for (x576 = x577, x576_p_0 = 0;
						x576 < x577 + 17;
						x576 += 1, x576_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 256
						// T (f, 8) (256 / 32)
						for (f = f768, fp_2 = f768_p_1, fp_1 = f768_p_0, fp_0 = 0;
							f < f768 + 256;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w384, wp_0 = 0;
								w < w384 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x576, xp_1 = x576_p_0, xp_0 = 0;
									x < x576 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7060 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7061 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7062 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7063 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_7064 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7065 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7066 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7067 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_7068 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7069 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7070 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7071 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_7072 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7073 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_7074 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7075 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_7076 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7077 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_7078 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7079 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c576, cp_1 = c576_p_0, cp_0 = 0;
												c < c576 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7060);
												mem_vec_7060 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7061);
												mem_vec_7061 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7062);
												mem_vec_7062 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7063);
												mem_vec_7063 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7064);
												mem_vec_7064 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7065);
												mem_vec_7065 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7066);
												mem_vec_7066 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7067);
												mem_vec_7067 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7068);
												mem_vec_7068 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7069);
												mem_vec_7069 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7070);
												mem_vec_7070 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7071);
												mem_vec_7071 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7072);
												mem_vec_7072 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7073);
												mem_vec_7073 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7074);
												mem_vec_7074 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7075);
												mem_vec_7075 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_7076);
												mem_vec_7076 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_7077);
												mem_vec_7077 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_7078);
												mem_vec_7078 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_7079);
												mem_vec_7079 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_7060);
												mem_vec_7060 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_7061);
												mem_vec_7061 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_7062);
												mem_vec_7062 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_7063);
												mem_vec_7063 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_7064);
												mem_vec_7064 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_7065);
												mem_vec_7065 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_7066);
												mem_vec_7066 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_7067);
												mem_vec_7067 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_7068);
												mem_vec_7068 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_7069);
												mem_vec_7069 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_7070);
												mem_vec_7070 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_7071);
												mem_vec_7071 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_7072);
												mem_vec_7072 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_7073);
												mem_vec_7073 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_7074);
												mem_vec_7074 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_7075);
												mem_vec_7075 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_7076);
												mem_vec_7076 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_7077);
												mem_vec_7077 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_7078);
												mem_vec_7078 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_7079);
												mem_vec_7079 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_7060);
												mem_vec_7060 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_7061);
												mem_vec_7061 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_7062);
												mem_vec_7062 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_7063);
												mem_vec_7063 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_7064);
												mem_vec_7064 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_7065);
												mem_vec_7065 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_7066);
												mem_vec_7066 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_7067);
												mem_vec_7067 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_7068);
												mem_vec_7068 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_7069);
												mem_vec_7069 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_7070);
												mem_vec_7070 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_7071);
												mem_vec_7071 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_7072);
												mem_vec_7072 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_7073);
												mem_vec_7073 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_7074);
												mem_vec_7074 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_7075);
												mem_vec_7075 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_7076);
												mem_vec_7076 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_7077);
												mem_vec_7077 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_7078);
												mem_vec_7078 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_7079);
												mem_vec_7079 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7060);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7061);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7062);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7063);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7064);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7065);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7066);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7067);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7068);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7069);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7070);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7071);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7072);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7073);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7074);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7075);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7076);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7077);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7078);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_7079);
								}
							}
						}
					}
				}
				for (y = y384 + 5, yp_0 = 0;
					y < y384 + 5 + 12;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 256
					// T (x, 17) (17 / 1)
					for (x576 = x577, x576_p_0 = 0;
						x576 < x577 + 17;
						x576 += 1, x576_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 256
						// T (f, 8) (256 / 32)
						for (f = f768, fp_2 = f768_p_1, fp_1 = f768_p_0, fp_0 = 0;
							f < f768 + 256;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w384, wp_0 = 0;
								w < w384 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x576, xp_1 = x576_p_0, xp_0 = 0;
									x < x576 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7080 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7081 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7082 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7083 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_7084 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7085 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7086 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7087 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_7088 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7089 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7090 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7091 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_7092 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7093 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_7094 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7095 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_7096 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7097 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_7098 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7099 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_7100 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7101 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_7102 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_7103 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c576, cp_1 = c576_p_0, cp_0 = 0;
												c < c576 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7080);
												mem_vec_7080 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7081);
												mem_vec_7081 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7082);
												mem_vec_7082 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7083);
												mem_vec_7083 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7084);
												mem_vec_7084 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7085);
												mem_vec_7085 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7086);
												mem_vec_7086 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7087);
												mem_vec_7087 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7088);
												mem_vec_7088 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7089);
												mem_vec_7089 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7090);
												mem_vec_7090 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7091);
												mem_vec_7091 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7092);
												mem_vec_7092 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7093);
												mem_vec_7093 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7094);
												mem_vec_7094 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7095);
												mem_vec_7095 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_7096);
												mem_vec_7096 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_7097);
												mem_vec_7097 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_7098);
												mem_vec_7098 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_7099);
												mem_vec_7099 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_7100);
												mem_vec_7100 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_7101);
												mem_vec_7101 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_7102);
												mem_vec_7102 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_7103);
												mem_vec_7103 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_7080);
												mem_vec_7080 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_7081);
												mem_vec_7081 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_7082);
												mem_vec_7082 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_7083);
												mem_vec_7083 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_7084);
												mem_vec_7084 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_7085);
												mem_vec_7085 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_7086);
												mem_vec_7086 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_7087);
												mem_vec_7087 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_7088);
												mem_vec_7088 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_7089);
												mem_vec_7089 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_7090);
												mem_vec_7090 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_7091);
												mem_vec_7091 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_7092);
												mem_vec_7092 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_7093);
												mem_vec_7093 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_7094);
												mem_vec_7094 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_7095);
												mem_vec_7095 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_7096);
												mem_vec_7096 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_7097);
												mem_vec_7097 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_7098);
												mem_vec_7098 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_7099);
												mem_vec_7099 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_7100);
												mem_vec_7100 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_7101);
												mem_vec_7101 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_7102);
												mem_vec_7102 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_7103);
												mem_vec_7103 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_7080);
												mem_vec_7080 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_7081);
												mem_vec_7081 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_7082);
												mem_vec_7082 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_7083);
												mem_vec_7083 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_7084);
												mem_vec_7084 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_7085);
												mem_vec_7085 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_7086);
												mem_vec_7086 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_7087);
												mem_vec_7087 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_7088);
												mem_vec_7088 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_7089);
												mem_vec_7089 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_7090);
												mem_vec_7090 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_7091);
												mem_vec_7091 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_7092);
												mem_vec_7092 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_7093);
												mem_vec_7093 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_7094);
												mem_vec_7094 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_7095);
												mem_vec_7095 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_7096);
												mem_vec_7096 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_7097);
												mem_vec_7097 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_7098);
												mem_vec_7098 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_7099);
												mem_vec_7099 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_7100);
												mem_vec_7100 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_7101);
												mem_vec_7101 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_7102);
												mem_vec_7102 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_7103);
												mem_vec_7103 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7080);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7081);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7082);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7083);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7084);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7085);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7086);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7087);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7088);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7089);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7090);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7091);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7092);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7093);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7094);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7095);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7096);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7097);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7098);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_7099);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7100);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_7101);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7102);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_7103);
								}
							}
						}
					}
				}
		}
	}
}


}