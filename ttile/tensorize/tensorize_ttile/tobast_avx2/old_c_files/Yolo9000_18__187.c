#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (17, x);
  T (3, w); T (16, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (1, f);
  T (16, c); T (2, f)]
*/
IND_TYPE c, cp_0, c648_p_0, cp_1, c648, f, fp_0, f864_p_0, f865_p_0, fp_1, f864_p_1, fp_2, f864, f865, w, wp_0, x, xp_0, x648_p_0, xp_1, x648, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y432 = 0;
IND_TYPE x649 = 0;
IND_TYPE h = 0;
IND_TYPE w432 = 0;
IND_TYPE c649 = 0;
IND_TYPE f866 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8164 ,mem_vec_8165 ,mem_vec_8166 ,mem_vec_8167 ,mem_vec_8168 ,mem_vec_8169 ,mem_vec_8170 ,mem_vec_8171 ,mem_vec_8172 ,mem_vec_8173 ,mem_vec_8174 ,mem_vec_8175 ,mem_vec_8176 ,mem_vec_8177 ,mem_vec_8178 ,mem_vec_8179 ,mem_vec_8180 ,mem_vec_8181 ,mem_vec_8182 ,mem_vec_8183 ,mem_vec_8184 ,mem_vec_8185 ,mem_vec_8186 ,mem_vec_8187 ,mem_vec_8188 ,mem_vec_8189 ,mem_vec_8190 ,mem_vec_8191 ,mem_vec_8192 ,mem_vec_8193 ,mem_vec_8194 ,mem_vec_8195 ,mem_vec_8196 ,mem_vec_8197 ,mem_vec_8198 ,mem_vec_8199 ,mem_vec_8200 ,mem_vec_8201 ,mem_vec_8202 ,mem_vec_8203 ,mem_vec_8204 ,mem_vec_8205 ,mem_vec_8206 ,mem_vec_8207 ,mem_vec_8208 ,mem_vec_8209 ,mem_vec_8210 ,mem_vec_8211 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
for (f865 = f866, f865_p_0 = 0;
	f865 < f866 + 1024;
	f865 += 512, f865_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
	// T (c, 16) (512 / 32)
	for (c648 = c649, c648_p_0 = 0;
		c648 < c649 + 512;
		c648 += 32, c648_p_0 += 32){
		// y = 17, x = 17, h = 3, w = 3, c = 32, f = 512
		// T (f, 1) (512 / 512)
		for (f864 = f865, f864_p_1 = f865_p_0, f864_p_0 = 0;
			f864 < f865 + 512;
			f864 += 512, f864_p_1 += 512, f864_p_0 += 512){
				for (y = y432, yp_0 = 0;
					y < y432 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 512
					// T (x, 1) (17 / 17)
					for (x648 = x649, x648_p_0 = 0;
						x648 < x649 + 17;
						x648 += 17, x648_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 512
						// T (f, 16) (512 / 32)
						for (f = f864, fp_2 = f864_p_1, fp_1 = f864_p_0, fp_0 = 0;
							f < f864 + 512;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w432, wp_0 = 0;
								w < w432 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x648, xp_1 = x648_p_0, xp_0 = 0;
									x < x648 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8164 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8165 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_8166 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8167 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_8168 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8169 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_8170 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8171 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_8172 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8173 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_8174 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8175 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_8176 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8177 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_8178 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8179 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_8180 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8181 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_8182 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_8183 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c648, cp_1 = c648_p_0, cp_0 = 0;
												c < c648 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8164);
												mem_vec_8164 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8165);
												mem_vec_8165 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8166);
												mem_vec_8166 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8167);
												mem_vec_8167 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8168);
												mem_vec_8168 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8169);
												mem_vec_8169 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8170);
												mem_vec_8170 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8171);
												mem_vec_8171 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8172);
												mem_vec_8172 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8173);
												mem_vec_8173 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8174);
												mem_vec_8174 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8175);
												mem_vec_8175 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8176);
												mem_vec_8176 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8177);
												mem_vec_8177 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8178);
												mem_vec_8178 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8179);
												mem_vec_8179 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8180);
												mem_vec_8180 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8181);
												mem_vec_8181 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8182);
												mem_vec_8182 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8183);
												mem_vec_8183 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_8164);
												mem_vec_8164 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_8165);
												mem_vec_8165 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_8166);
												mem_vec_8166 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_8167);
												mem_vec_8167 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_8168);
												mem_vec_8168 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_8169);
												mem_vec_8169 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_8170);
												mem_vec_8170 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_8171);
												mem_vec_8171 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_8172);
												mem_vec_8172 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_8173);
												mem_vec_8173 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_8174);
												mem_vec_8174 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_8175);
												mem_vec_8175 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_8176);
												mem_vec_8176 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_8177);
												mem_vec_8177 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_8178);
												mem_vec_8178 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_8179);
												mem_vec_8179 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_8180);
												mem_vec_8180 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_8181);
												mem_vec_8181 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_8182);
												mem_vec_8182 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_8183);
												mem_vec_8183 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_8164);
												mem_vec_8164 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_8165);
												mem_vec_8165 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_8166);
												mem_vec_8166 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_8167);
												mem_vec_8167 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_8168);
												mem_vec_8168 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_8169);
												mem_vec_8169 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_8170);
												mem_vec_8170 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_8171);
												mem_vec_8171 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_8172);
												mem_vec_8172 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_8173);
												mem_vec_8173 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_8174);
												mem_vec_8174 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_8175);
												mem_vec_8175 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_8176);
												mem_vec_8176 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_8177);
												mem_vec_8177 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_8178);
												mem_vec_8178 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_8179);
												mem_vec_8179 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_8180);
												mem_vec_8180 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_8181);
												mem_vec_8181 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_8182);
												mem_vec_8182 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_8183);
												mem_vec_8183 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8164);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8165);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8166);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8167);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8168);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8169);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8170);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8171);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8172);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8173);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8174);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8175);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8176);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8177);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8178);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8179);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8180);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8181);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8182);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_8183);
								}
							}
						}
					}
				}
				for (y = y432 + 10, yp_0 = 0;
					y < y432 + 10 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 512
					// T (x, 1) (17 / 17)
					for (x648 = x649, x648_p_0 = 0;
						x648 < x649 + 17;
						x648 += 17, x648_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 512
						// T (f, 16) (512 / 32)
						for (f = f864, fp_2 = f864_p_1, fp_1 = f864_p_0, fp_0 = 0;
							f < f864 + 512;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w432, wp_0 = 0;
								w < w432 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x648, xp_1 = x648_p_0, xp_0 = 0;
									x < x648 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8184 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8185 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_8186 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8187 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_8188 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8189 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_8190 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8191 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_8192 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8193 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_8194 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8195 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_8196 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8197 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_8198 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8199 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_8200 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8201 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_8202 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_8203 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_8204 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8205 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_8206 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_8207 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											mem_vec_8208 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_8209 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_8210 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_8211 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c648, cp_1 = c648_p_0, cp_0 = 0;
												c < c648 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8184);
												mem_vec_8184 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8185);
												mem_vec_8185 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8186);
												mem_vec_8186 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8187);
												mem_vec_8187 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8188);
												mem_vec_8188 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8189);
												mem_vec_8189 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8190);
												mem_vec_8190 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8191);
												mem_vec_8191 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8192);
												mem_vec_8192 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8193);
												mem_vec_8193 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8194);
												mem_vec_8194 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8195);
												mem_vec_8195 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8196);
												mem_vec_8196 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8197);
												mem_vec_8197 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8198);
												mem_vec_8198 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8199);
												mem_vec_8199 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8200);
												mem_vec_8200 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8201);
												mem_vec_8201 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8202);
												mem_vec_8202 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8203);
												mem_vec_8203 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8204);
												mem_vec_8204 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8205);
												mem_vec_8205 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_8206);
												mem_vec_8206 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_8207);
												mem_vec_8207 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_8208);
												mem_vec_8208 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_8209);
												mem_vec_8209 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_8210);
												mem_vec_8210 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_8211);
												mem_vec_8211 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_40 = _mm256_set1_ps(scal_7);
												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_8184);
												mem_vec_8184 = vec_39;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_8185);
												mem_vec_8185 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_8186);
												mem_vec_8186 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_8187);
												mem_vec_8187 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_8188);
												mem_vec_8188 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_8189);
												mem_vec_8189 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_8190);
												mem_vec_8190 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_8191);
												mem_vec_8191 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_8192);
												mem_vec_8192 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_8193);
												mem_vec_8193 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_8194);
												mem_vec_8194 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_8195);
												mem_vec_8195 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_8196);
												mem_vec_8196 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_8197);
												mem_vec_8197 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_8198);
												mem_vec_8198 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_8199);
												mem_vec_8199 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_8200);
												mem_vec_8200 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_8201);
												mem_vec_8201 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_8202);
												mem_vec_8202 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_8203);
												mem_vec_8203 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_69 = _mm256_set1_ps(scal_12);


												vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_8204);
												mem_vec_8204 = vec_68;



												vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_8205);
												mem_vec_8205 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_8206);
												mem_vec_8206 = vec_71;



												vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_8207);
												mem_vec_8207 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_13);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_8208);
												mem_vec_8208 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_8209);
												mem_vec_8209 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_8210);
												mem_vec_8210 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_8211);
												mem_vec_8211 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_14);
												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_8184);
												mem_vec_8184 = vec_78;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_8185);
												mem_vec_8185 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_8186);
												mem_vec_8186 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_8187);
												mem_vec_8187 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_8188);
												mem_vec_8188 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_8189);
												mem_vec_8189 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_8190);
												mem_vec_8190 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_8191);
												mem_vec_8191 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_8192);
												mem_vec_8192 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_8193);
												mem_vec_8193 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_8194);
												mem_vec_8194 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_8195);
												mem_vec_8195 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_8196);
												mem_vec_8196 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_8197);
												mem_vec_8197 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_8198);
												mem_vec_8198 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_8199);
												mem_vec_8199 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_18);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_8200);
												mem_vec_8200 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_8201);
												mem_vec_8201 = vec_104;



												vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_8202);
												mem_vec_8202 = vec_105;



												vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_8203);
												mem_vec_8203 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_108 = _mm256_set1_ps(scal_19);


												vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_8204);
												mem_vec_8204 = vec_107;



												vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_8205);
												mem_vec_8205 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_8206);
												mem_vec_8206 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_8207);
												mem_vec_8207 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_113 = _mm256_set1_ps(scal_20);


												vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_8208);
												mem_vec_8208 = vec_112;



												vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_8209);
												mem_vec_8209 = vec_114;



												vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_8210);
												mem_vec_8210 = vec_115;



												vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_8211);
												mem_vec_8211 = vec_116;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8184);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8185);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8186);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8187);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8188);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8189);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8190);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8191);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8192);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8193);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8194);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8195);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8196);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8197);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8198);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8199);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8200);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8201);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8202);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_8203);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8204);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8205);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8206);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_8207);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8208);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8209);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8210);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_8211);
								}
							}
						}
					}
				}
		}
	}
}


}