#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (1, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]; T (2, f);
  T (256, c); T (16, f)]
*/
IND_TYPE c, cp_0, c996_p_0, cp_1, c996, f, fp_0, f1328_p_0, f1329_p_0, fp_1, f1328_p_1, fp_2, f1328, f1329, h, hp_0, x, xp_0, x996_p_0, xp_1, x996, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y664 = 0;
IND_TYPE x997 = 0;
IND_TYPE h464 = 0;
IND_TYPE w = 0;
IND_TYPE c997 = 0;
IND_TYPE f1330 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_13132 ,mem_vec_13133 ,mem_vec_13134 ,mem_vec_13135 ,mem_vec_13136 ,mem_vec_13137 ,mem_vec_13138 ,mem_vec_13139 ,mem_vec_13140 ,mem_vec_13141 ,mem_vec_13142 ,mem_vec_13143 ,mem_vec_13144 ,mem_vec_13145 ,mem_vec_13146 ,mem_vec_13147 ,mem_vec_13148 ,mem_vec_13149 ,mem_vec_13150 ,mem_vec_13151 ,mem_vec_13152 ,mem_vec_13153 ,mem_vec_13154 ,mem_vec_13155 ,mem_vec_13156 ,mem_vec_13157 ,mem_vec_13158 ,mem_vec_13159 ,mem_vec_13160 ,mem_vec_13161 ,mem_vec_13162 ,mem_vec_13163 ,mem_vec_13164 ,mem_vec_13165 ,mem_vec_13166 ,mem_vec_13167 ,mem_vec_13168 ,mem_vec_13169 ,mem_vec_13170 ,mem_vec_13171 ,mem_vec_13172 ,mem_vec_13173 ,mem_vec_13174 ,mem_vec_13175 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 16) (1024 / 64)
for (f1329 = f1330, f1329_p_0 = 0;
	f1329 < f1330 + 1024;
	f1329 += 64, f1329_p_0 += 64){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 64
	// T (c, 256) (512 / 2)
	for (c996 = c997, c996_p_0 = 0;
		c996 < c997 + 512;
		c996 += 2, c996_p_0 += 2){
		// y = 17, x = 17, h = 3, w = 3, c = 2, f = 64
		// T (f, 2) (64 / 32)
		for (f1328 = f1329, f1328_p_1 = f1329_p_0, f1328_p_0 = 0;
			f1328 < f1329 + 64;
			f1328 += 32, f1328_p_1 += 32, f1328_p_0 += 32){
				for (y = y664, yp_0 = 0;
					y < y664 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 32
					// T (x, 17) (17 / 1)
					for (x996 = x997, x996_p_0 = 0;
						x996 < x997 + 17;
						x996 += 1, x996_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
						// T (f, 1) (32 / 32)
						for (f = f1328, fp_2 = f1328_p_1, fp_1 = f1328_p_0, fp_0 = 0;
							f < f1328 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h464, hp_0 = 0;
								h < h464 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x996, xp_1 = x996_p_0, xp_0 = 0;
									x < x996 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13132 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13133 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_13134 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13135 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_13136 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13137 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_13138 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13139 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_13140 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13141 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_13142 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13143 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_13144 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13145 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_13146 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13147 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_13148 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_13149 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_13150 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_13151 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c996, cp_1 = c996_p_0, cp_0 = 0;
												c < c996 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13132);
												mem_vec_13132 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13133);
												mem_vec_13133 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13134);
												mem_vec_13134 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13135);
												mem_vec_13135 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13136);
												mem_vec_13136 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13137);
												mem_vec_13137 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13138);
												mem_vec_13138 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13139);
												mem_vec_13139 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13140);
												mem_vec_13140 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13141);
												mem_vec_13141 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13142);
												mem_vec_13142 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13143);
												mem_vec_13143 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13144);
												mem_vec_13144 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13145);
												mem_vec_13145 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13146);
												mem_vec_13146 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13147);
												mem_vec_13147 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_13148);
												mem_vec_13148 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_13149);
												mem_vec_13149 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_13150);
												mem_vec_13150 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_13151);
												mem_vec_13151 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_13132);
												mem_vec_13132 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_13133);
												mem_vec_13133 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_13134);
												mem_vec_13134 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_13135);
												mem_vec_13135 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_13136);
												mem_vec_13136 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_13137);
												mem_vec_13137 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_13138);
												mem_vec_13138 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_13139);
												mem_vec_13139 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_13140);
												mem_vec_13140 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_13141);
												mem_vec_13141 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_13142);
												mem_vec_13142 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_13143);
												mem_vec_13143 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_13144);
												mem_vec_13144 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_13145);
												mem_vec_13145 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_13146);
												mem_vec_13146 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_13147);
												mem_vec_13147 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_13148);
												mem_vec_13148 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_13149);
												mem_vec_13149 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_13150);
												mem_vec_13150 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_13151);
												mem_vec_13151 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_13132);
												mem_vec_13132 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_13133);
												mem_vec_13133 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_13134);
												mem_vec_13134 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_13135);
												mem_vec_13135 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_13136);
												mem_vec_13136 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_13137);
												mem_vec_13137 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_13138);
												mem_vec_13138 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_13139);
												mem_vec_13139 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_13140);
												mem_vec_13140 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_13141);
												mem_vec_13141 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_13142);
												mem_vec_13142 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_13143);
												mem_vec_13143 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_13144);
												mem_vec_13144 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_13145);
												mem_vec_13145 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_13146);
												mem_vec_13146 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_13147);
												mem_vec_13147 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_13148);
												mem_vec_13148 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_13149);
												mem_vec_13149 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_13150);
												mem_vec_13150 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_13151);
												mem_vec_13151 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13132);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13133);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13134);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13135);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13136);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13137);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13138);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13139);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13140);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13141);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13142);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13143);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13144);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13145);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13146);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13147);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13148);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_13149);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13150);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_13151);
								}
							}
						}
					}
				}
				for (y = y664 + 5, yp_0 = 0;
					y < y664 + 5 + 12;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 32
					// T (x, 17) (17 / 1)
					for (x996 = x997, x996_p_0 = 0;
						x996 < x997 + 17;
						x996 += 1, x996_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
						// T (f, 1) (32 / 32)
						for (f = f1328, fp_2 = f1328_p_1, fp_1 = f1328_p_0, fp_0 = 0;
							f < f1328 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h464, hp_0 = 0;
								h < h464 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x996, xp_1 = x996_p_0, xp_0 = 0;
									x < x996 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13152 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13153 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_13154 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13155 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_13156 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13157 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_13158 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13159 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_13160 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13161 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_13162 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13163 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_13164 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13165 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_13166 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13167 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_13168 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_13169 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_13170 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_13171 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_13172 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_13173 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_13174 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_13175 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c996, cp_1 = c996_p_0, cp_0 = 0;
												c < c996 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13152);
												mem_vec_13152 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13153);
												mem_vec_13153 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13154);
												mem_vec_13154 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13155);
												mem_vec_13155 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13156);
												mem_vec_13156 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13157);
												mem_vec_13157 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13158);
												mem_vec_13158 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13159);
												mem_vec_13159 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13160);
												mem_vec_13160 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13161);
												mem_vec_13161 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13162);
												mem_vec_13162 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13163);
												mem_vec_13163 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13164);
												mem_vec_13164 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13165);
												mem_vec_13165 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13166);
												mem_vec_13166 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13167);
												mem_vec_13167 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_13168);
												mem_vec_13168 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_13169);
												mem_vec_13169 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_13170);
												mem_vec_13170 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_13171);
												mem_vec_13171 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_13172);
												mem_vec_13172 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_13173);
												mem_vec_13173 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_13174);
												mem_vec_13174 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_13175);
												mem_vec_13175 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_13152);
												mem_vec_13152 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_13153);
												mem_vec_13153 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_13154);
												mem_vec_13154 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_13155);
												mem_vec_13155 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_13156);
												mem_vec_13156 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_13157);
												mem_vec_13157 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_13158);
												mem_vec_13158 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_13159);
												mem_vec_13159 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_13160);
												mem_vec_13160 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_13161);
												mem_vec_13161 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_13162);
												mem_vec_13162 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_13163);
												mem_vec_13163 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_13164);
												mem_vec_13164 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_13165);
												mem_vec_13165 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_13166);
												mem_vec_13166 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_13167);
												mem_vec_13167 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_13168);
												mem_vec_13168 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_13169);
												mem_vec_13169 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_13170);
												mem_vec_13170 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_13171);
												mem_vec_13171 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_13172);
												mem_vec_13172 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_13173);
												mem_vec_13173 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_13174);
												mem_vec_13174 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_13175);
												mem_vec_13175 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_13152);
												mem_vec_13152 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_13153);
												mem_vec_13153 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_13154);
												mem_vec_13154 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_13155);
												mem_vec_13155 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_13156);
												mem_vec_13156 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_13157);
												mem_vec_13157 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_13158);
												mem_vec_13158 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_13159);
												mem_vec_13159 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_13160);
												mem_vec_13160 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_13161);
												mem_vec_13161 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_13162);
												mem_vec_13162 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_13163);
												mem_vec_13163 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_13164);
												mem_vec_13164 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_13165);
												mem_vec_13165 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_13166);
												mem_vec_13166 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_13167);
												mem_vec_13167 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_13168);
												mem_vec_13168 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_13169);
												mem_vec_13169 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_13170);
												mem_vec_13170 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_13171);
												mem_vec_13171 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_13172);
												mem_vec_13172 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_13173);
												mem_vec_13173 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_13174);
												mem_vec_13174 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_13175);
												mem_vec_13175 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13152);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13153);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13154);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13155);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13156);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13157);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13158);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13159);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13160);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13161);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13162);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13163);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13164);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13165);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13166);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13167);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13168);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_13169);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13170);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_13171);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13172);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_13173);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13174);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_13175);
								}
							}
						}
					}
				}
		}
	}
}


}