#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (2, f); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (2, f);
  T (32, c); T (2, f)]
*/
IND_TYPE c, cp_0, c1178_p_0, cp_1, c1178, f, fp_0, f1264_p_0, f1265_p_0, fp_1, f1264_p_1, fp_2, f1264, f1265, h, hp_0, x, xp_0, x1178_p_0, xp_1, x1178, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y724 = 0;
IND_TYPE x1179 = 0;
IND_TYPE h564 = 0;
IND_TYPE w = 0;
IND_TYPE c1179 = 0;
IND_TYPE f1266 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14118 ,mem_vec_14119 ,mem_vec_14120 ,mem_vec_14121 ,mem_vec_14122 ,mem_vec_14123 ,mem_vec_14124 ,mem_vec_14125 ,mem_vec_14126 ,mem_vec_14127 ,mem_vec_14128 ,mem_vec_14129 ,mem_vec_14130 ,mem_vec_14131 ,mem_vec_14132 ,mem_vec_14133 ,mem_vec_14134 ,mem_vec_14135 ,mem_vec_14136 ,mem_vec_14137 ,mem_vec_14138 ,mem_vec_14139 ,mem_vec_14140 ,mem_vec_14141 ,mem_vec_14142 ,mem_vec_14143 ,mem_vec_14144 ,mem_vec_14145 ,mem_vec_14146 ,mem_vec_14147 ,mem_vec_14148 ,mem_vec_14149 ,mem_vec_14150 ,mem_vec_14151 ,mem_vec_14152 ,mem_vec_14153 ,mem_vec_14154 ,mem_vec_14155 ,mem_vec_14156 ,mem_vec_14157 ,mem_vec_14158 ,mem_vec_14159 ,mem_vec_14160 ,mem_vec_14161 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f1265 = f1266, f1265_p_0 = 0;
	f1265 < f1266 + 512;
	f1265 += 256, f1265_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (c, 32) (256 / 8)
	for (c1178 = c1179, c1178_p_0 = 0;
		c1178 < c1179 + 256;
		c1178 += 8, c1178_p_0 += 8){
		// y = 34, x = 34, h = 3, w = 3, c = 8, f = 256
		// T (f, 2) (256 / 128)
		for (f1264 = f1265, f1264_p_1 = f1265_p_0, f1264_p_0 = 0;
			f1264 < f1265 + 256;
			f1264 += 128, f1264_p_1 += 128, f1264_p_0 += 128){
				for (y = y724, yp_0 = 0;
					y < y724 + 20;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 128
					// T (x, 1) (34 / 34)
					for (x1178 = x1179, x1178_p_0 = 0;
						x1178 < x1179 + 34;
						x1178 += 34, x1178_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 128
						// T (f, 2) (128 / 64)
						for (f = f1264, fp_2 = f1264_p_1, fp_1 = f1264_p_0, fp_0 = 0;
							f < f1264 + 128;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 64
							// T (h, 3) (3 / 1)
							for (h = h564, hp_0 = 0;
								h < h564 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 8, f = 64
								// T (x, 34) (34 / 1)
								for (x = x1178, xp_1 = x1178_p_0, xp_0 = 0;
									x < x1178 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14118 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14119 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14120 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_14121 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_14122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_14125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_14126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_14129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_14130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_14133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 64
											// T (c, 8) (8 / 1)
											for (c = c1178, cp_1 = c1178_p_0, cp_0 = 0;
												c < c1178 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14118);
												mem_vec_14118 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14119);
												mem_vec_14119 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14120);
												mem_vec_14120 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14121);
												mem_vec_14121 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14122);
												mem_vec_14122 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14123);
												mem_vec_14123 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14124);
												mem_vec_14124 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14125);
												mem_vec_14125 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14126);
												mem_vec_14126 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14127);
												mem_vec_14127 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14128);
												mem_vec_14128 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14129);
												mem_vec_14129 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14130);
												mem_vec_14130 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14131);
												mem_vec_14131 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14132);
												mem_vec_14132 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14133);
												mem_vec_14133 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_14118);
												mem_vec_14118 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_14119);
												mem_vec_14119 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_14120);
												mem_vec_14120 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_14121);
												mem_vec_14121 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_14122);
												mem_vec_14122 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_14123);
												mem_vec_14123 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_14124);
												mem_vec_14124 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_14125);
												mem_vec_14125 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_14126);
												mem_vec_14126 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_14127);
												mem_vec_14127 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_14128);
												mem_vec_14128 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_14129);
												mem_vec_14129 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_14130);
												mem_vec_14130 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_14131);
												mem_vec_14131 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_14132);
												mem_vec_14132 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_14133);
												mem_vec_14133 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_14118);
												mem_vec_14118 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_14119);
												mem_vec_14119 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_14120);
												mem_vec_14120 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_14121);
												mem_vec_14121 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_14122);
												mem_vec_14122 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_14123);
												mem_vec_14123 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_14124);
												mem_vec_14124 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_14125);
												mem_vec_14125 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_14126);
												mem_vec_14126 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_14127);
												mem_vec_14127 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_14128);
												mem_vec_14128 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_14129);
												mem_vec_14129 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_14130);
												mem_vec_14130 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_14131);
												mem_vec_14131 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_14132);
												mem_vec_14132 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_14133);
												mem_vec_14133 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14118);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14119);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14120);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14121);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14122);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14123);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14124);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14125);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14126);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14127);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14128);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14129);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14130);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14131);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14132);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14133);
								}
							}
						}
					}
				}
				for (y = y724 + 20, yp_0 = 0;
					y < y724 + 20 + 14;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 128
					// T (x, 1) (34 / 34)
					for (x1178 = x1179, x1178_p_0 = 0;
						x1178 < x1179 + 34;
						x1178 += 34, x1178_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 128
						// T (f, 2) (128 / 64)
						for (f = f1264, fp_2 = f1264_p_1, fp_1 = f1264_p_0, fp_0 = 0;
							f < f1264 + 128;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 64
							// T (h, 3) (3 / 1)
							for (h = h564, hp_0 = 0;
								h < h564 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 8, f = 64
								// T (x, 34) (34 / 1)
								for (x = x1178, xp_1 = x1178_p_0, xp_0 = 0;
									x < x1178 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14134 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14135 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14136 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_14137 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_14138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_14141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_14142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_14145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_14146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_14149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_14150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_14151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_14152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_14153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_14154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_14155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_14156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_14157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											mem_vec_14158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_14159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_14160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
											mem_vec_14161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 64
											// T (c, 8) (8 / 1)
											for (c = c1178, cp_1 = c1178_p_0, cp_0 = 0;
												c < c1178 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14134);
												mem_vec_14134 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14135);
												mem_vec_14135 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14136);
												mem_vec_14136 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14137);
												mem_vec_14137 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14138);
												mem_vec_14138 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14139);
												mem_vec_14139 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14140);
												mem_vec_14140 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14141);
												mem_vec_14141 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14142);
												mem_vec_14142 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14143);
												mem_vec_14143 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14144);
												mem_vec_14144 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14145);
												mem_vec_14145 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14146);
												mem_vec_14146 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14147);
												mem_vec_14147 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14148);
												mem_vec_14148 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14149);
												mem_vec_14149 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14150);
												mem_vec_14150 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14151);
												mem_vec_14151 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14152);
												mem_vec_14152 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14153);
												mem_vec_14153 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14154);
												mem_vec_14154 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14155);
												mem_vec_14155 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14156);
												mem_vec_14156 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14157);
												mem_vec_14157 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_14158);
												mem_vec_14158 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_14159);
												mem_vec_14159 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_14160);
												mem_vec_14160 = vec_37;



												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_14161);
												mem_vec_14161 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_40 = _mm512_set1_ps(scal_7);
												vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_14134);
												mem_vec_14134 = vec_39;

												vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_14135);
												mem_vec_14135 = vec_42;

												vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_14136);
												mem_vec_14136 = vec_44;

												vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_14137);
												mem_vec_14137 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_14138);
												mem_vec_14138 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_14139);
												mem_vec_14139 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_14140);
												mem_vec_14140 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_14141);
												mem_vec_14141 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_14142);
												mem_vec_14142 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_14143);
												mem_vec_14143 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_14144);
												mem_vec_14144 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_14145);
												mem_vec_14145 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_14146);
												mem_vec_14146 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_14147);
												mem_vec_14147 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_14148);
												mem_vec_14148 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_14149);
												mem_vec_14149 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_14150);
												mem_vec_14150 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_14151);
												mem_vec_14151 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_14152);
												mem_vec_14152 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_14153);
												mem_vec_14153 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);


												vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_14154);
												mem_vec_14154 = vec_68;



												vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_14155);
												mem_vec_14155 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_14156);
												mem_vec_14156 = vec_71;



												vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_14157);
												mem_vec_14157 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_74 = _mm512_set1_ps(scal_13);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_14158);
												mem_vec_14158 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_14159);
												mem_vec_14159 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_14160);
												mem_vec_14160 = vec_76;



												vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_14161);
												mem_vec_14161 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_79 = _mm512_set1_ps(scal_14);
												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_14134);
												mem_vec_14134 = vec_78;

												vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_14135);
												mem_vec_14135 = vec_81;

												vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_14136);
												mem_vec_14136 = vec_83;

												vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_14137);
												mem_vec_14137 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_14138);
												mem_vec_14138 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_14139);
												mem_vec_14139 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_14140);
												mem_vec_14140 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_14141);
												mem_vec_14141 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_14142);
												mem_vec_14142 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_14143);
												mem_vec_14143 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_14144);
												mem_vec_14144 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_14145);
												mem_vec_14145 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_14146);
												mem_vec_14146 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_14147);
												mem_vec_14147 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_14148);
												mem_vec_14148 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_14149);
												mem_vec_14149 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_103 = _mm512_set1_ps(scal_18);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_14150);
												mem_vec_14150 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_14151);
												mem_vec_14151 = vec_104;



												vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_14152);
												mem_vec_14152 = vec_105;



												vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_14153);
												mem_vec_14153 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_108 = _mm512_set1_ps(scal_19);


												vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_14154);
												mem_vec_14154 = vec_107;



												vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_14155);
												mem_vec_14155 = vec_109;



												vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_14156);
												mem_vec_14156 = vec_110;



												vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_14157);
												mem_vec_14157 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_113 = _mm512_set1_ps(scal_20);


												vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_14158);
												mem_vec_14158 = vec_112;



												vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_14159);
												mem_vec_14159 = vec_114;



												vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_14160);
												mem_vec_14160 = vec_115;



												vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_14161);
												mem_vec_14161 = vec_116;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14134);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14135);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14136);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14137);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14138);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14139);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14140);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14141);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14142);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14143);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14144);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14145);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14146);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14147);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14148);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14149);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14150);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14151);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14152);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14153);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14154);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14155);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_14156);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_14157);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14158);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14159);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_14160);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_14161);
								}
							}
						}
					}
				}
		}
	}
}


}