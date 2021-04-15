#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (128, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (4, f); T (7, x);
  Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))]; T (1, f);
  T (2, c); T (2, f)]
*/
IND_TYPE c, cp_0, c1134_p_0, cp_1, c1134, f, fp_0, f1512_p_0, f1513_p_0, fp_1, f1512_p_1, fp_2, f1512, f1513, h, hp_0, x, xp_0, x1134_p_0, xp_1, x1134, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y756 = 0;
IND_TYPE x1135 = 0;
IND_TYPE h568 = 0;
IND_TYPE w = 0;
IND_TYPE c1135 = 0;
IND_TYPE f1514 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_13112 ,mem_vec_13113 ,mem_vec_13114 ,mem_vec_13115 ,mem_vec_13116 ,mem_vec_13117 ,mem_vec_13118 ,mem_vec_13119 ,mem_vec_13120 ,mem_vec_13121 ,mem_vec_13122 ,mem_vec_13123 ,mem_vec_13124 ,mem_vec_13125 ,mem_vec_13126 ,mem_vec_13127 ,mem_vec_13128 ,mem_vec_13129 ,mem_vec_13130 ,mem_vec_13131 ,mem_vec_13132 ,mem_vec_13133 ,mem_vec_13134 ,mem_vec_13135 ,mem_vec_13136 ,mem_vec_13137 ,mem_vec_13138 ,mem_vec_13139 ,mem_vec_13140 ,mem_vec_13141 ,mem_vec_13142 ,mem_vec_13143 ,mem_vec_13144 ,mem_vec_13145 ,mem_vec_13146 ,mem_vec_13147 ,mem_vec_13148 ,mem_vec_13149 ,mem_vec_13150 ,mem_vec_13151 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f1513 = f1514, f1513_p_0 = 0;
	f1513 < f1514 + 256;
	f1513 += 128, f1513_p_0 += 128){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 128
	// T (c, 2) (256 / 128)
	for (c1134 = c1135, c1134_p_0 = 0;
		c1134 < c1135 + 256;
		c1134 += 128, c1134_p_0 += 128){
		// y = 14, x = 14, h = 3, w = 3, c = 128, f = 128
		// T (f, 1) (128 / 128)
		for (f1512 = f1513, f1512_p_1 = f1513_p_0, f1512_p_0 = 0;
			f1512 < f1513 + 128;
			f1512 += 128, f1512_p_1 += 128, f1512_p_0 += 128){
				for (y = y756, yp_0 = 0;
					y < y756 + 8;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 128
					// T (x, 7) (14 / 2)
					for (x1134 = x1135, x1134_p_0 = 0;
						x1134 < x1135 + 14;
						x1134 += 2, x1134_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 128
						// T (f, 4) (128 / 32)
						for (f = f1512, fp_2 = f1512_p_1, fp_1 = f1512_p_0, fp_0 = 0;
							f < f1512 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 32
							// T (h, 3) (3 / 1)
							for (h = h568, hp_0 = 0;
								h < h568 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 128, f = 32
								// T (x, 2) (2 / 1)
								for (x = x1134, xp_1 = x1134_p_0, xp_0 = 0;
									x < x1134 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13112 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13113 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_13114 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13115 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_13116 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13117 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_13118 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13119 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_13120 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13121 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_13122 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13123 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_13124 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13125 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_13126 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13127 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c1134, cp_1 = c1134_p_0, cp_0 = 0;
												c < c1134 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13112);
												mem_vec_13112 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13113);
												mem_vec_13113 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13114);
												mem_vec_13114 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13115);
												mem_vec_13115 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13116);
												mem_vec_13116 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13117);
												mem_vec_13117 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13118);
												mem_vec_13118 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13119);
												mem_vec_13119 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13120);
												mem_vec_13120 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13121);
												mem_vec_13121 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13122);
												mem_vec_13122 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13123);
												mem_vec_13123 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13124);
												mem_vec_13124 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13125);
												mem_vec_13125 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13126);
												mem_vec_13126 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13127);
												mem_vec_13127 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_13112);
												mem_vec_13112 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_13113);
												mem_vec_13113 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_13114);
												mem_vec_13114 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_13115);
												mem_vec_13115 = vec_31;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_13116);
												mem_vec_13116 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_13117);
												mem_vec_13117 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_13118);
												mem_vec_13118 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_13119);
												mem_vec_13119 = vec_37;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_13120);
												mem_vec_13120 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_13121);
												mem_vec_13121 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_13122);
												mem_vec_13122 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_13123);
												mem_vec_13123 = vec_42;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_13124);
												mem_vec_13124 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_13125);
												mem_vec_13125 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_13126);
												mem_vec_13126 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_13127);
												mem_vec_13127 = vec_47;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_13112);
												mem_vec_13112 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_13113);
												mem_vec_13113 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_13114);
												mem_vec_13114 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_13115);
												mem_vec_13115 = vec_55;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_13116);
												mem_vec_13116 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_13117);
												mem_vec_13117 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_13118);
												mem_vec_13118 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_13119);
												mem_vec_13119 = vec_61;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_13120);
												mem_vec_13120 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_13121);
												mem_vec_13121 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_13122);
												mem_vec_13122 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_13123);
												mem_vec_13123 = vec_66;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_13124);
												mem_vec_13124 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_13125);
												mem_vec_13125 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_13126);
												mem_vec_13126 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_13127);
												mem_vec_13127 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13112);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13113);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13114);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13115);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13116);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13117);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13118);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13119);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13120);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13121);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13122);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13123);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13124);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13125);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13126);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13127);
								}
							}
						}
					}
				}
				for (y = y756 + 8, yp_0 = 0;
					y < y756 + 8 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 128
					// T (x, 7) (14 / 2)
					for (x1134 = x1135, x1134_p_0 = 0;
						x1134 < x1135 + 14;
						x1134 += 2, x1134_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 128
						// T (f, 4) (128 / 32)
						for (f = f1512, fp_2 = f1512_p_1, fp_1 = f1512_p_0, fp_0 = 0;
							f < f1512 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 32
							// T (h, 3) (3 / 1)
							for (h = h568, hp_0 = 0;
								h < h568 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 128, f = 32
								// T (x, 2) (2 / 1)
								for (x = x1134, xp_1 = x1134_p_0, xp_0 = 0;
									x < x1134 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13128 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13129 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_13130 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13131 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_13132 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13133 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_13134 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13135 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_13136 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13137 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_13138 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13139 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_13140 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13141 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_13142 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13143 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_13144 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_13145 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_13146 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_13147 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_13148 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_13149 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_13150 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_13151 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c1134, cp_1 = c1134_p_0, cp_0 = 0;
												c < c1134 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13128);
												mem_vec_13128 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13129);
												mem_vec_13129 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13130);
												mem_vec_13130 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13131);
												mem_vec_13131 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13132);
												mem_vec_13132 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13133);
												mem_vec_13133 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13134);
												mem_vec_13134 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13135);
												mem_vec_13135 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13136);
												mem_vec_13136 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13137);
												mem_vec_13137 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13138);
												mem_vec_13138 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13139);
												mem_vec_13139 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13140);
												mem_vec_13140 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13141);
												mem_vec_13141 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13142);
												mem_vec_13142 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13143);
												mem_vec_13143 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_13144);
												mem_vec_13144 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_13145);
												mem_vec_13145 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_13146);
												mem_vec_13146 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_13147);
												mem_vec_13147 = vec_28;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_13148);
												mem_vec_13148 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_13149);
												mem_vec_13149 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_13150);
												mem_vec_13150 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_13151);
												mem_vec_13151 = vec_33;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_13128);
												mem_vec_13128 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_13129);
												mem_vec_13129 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_13130);
												mem_vec_13130 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_13131);
												mem_vec_13131 = vec_41;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_13132);
												mem_vec_13132 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_13133);
												mem_vec_13133 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_13134);
												mem_vec_13134 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_13135);
												mem_vec_13135 = vec_47;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_13136);
												mem_vec_13136 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_13137);
												mem_vec_13137 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_13138);
												mem_vec_13138 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_13139);
												mem_vec_13139 = vec_52;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_13140);
												mem_vec_13140 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_13141);
												mem_vec_13141 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_13142);
												mem_vec_13142 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_13143);
												mem_vec_13143 = vec_57;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_13144);
												mem_vec_13144 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_13145);
												mem_vec_13145 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_13146);
												mem_vec_13146 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_13147);
												mem_vec_13147 = vec_62;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_13148);
												mem_vec_13148 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_13149);
												mem_vec_13149 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_13150);
												mem_vec_13150 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_13151);
												mem_vec_13151 = vec_67;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_13128);
												mem_vec_13128 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_13129);
												mem_vec_13129 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_13130);
												mem_vec_13130 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_13131);
												mem_vec_13131 = vec_75;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_13132);
												mem_vec_13132 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_13133);
												mem_vec_13133 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_13134);
												mem_vec_13134 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_13135);
												mem_vec_13135 = vec_81;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_13136);
												mem_vec_13136 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_13137);
												mem_vec_13137 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_13138);
												mem_vec_13138 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_13139);
												mem_vec_13139 = vec_86;
												scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_13140);
												mem_vec_13140 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_13141);
												mem_vec_13141 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_13142);
												mem_vec_13142 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_13143);
												mem_vec_13143 = vec_91;
												scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_13144);
												mem_vec_13144 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_13145);
												mem_vec_13145 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_13146);
												mem_vec_13146 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_13147);
												mem_vec_13147 = vec_96;
												scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_13148);
												mem_vec_13148 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_13149);
												mem_vec_13149 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_13150);
												mem_vec_13150 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_13151);
												mem_vec_13151 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13128);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13129);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13130);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13131);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13132);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13133);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13134);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13135);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13136);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13137);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13138);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13139);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13140);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13141);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13142);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13143);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13144);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_13145);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13146);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_13147);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13148);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_13149);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13150);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_13151);
								}
							}
						}
					}
				}
		}
	}
}


}