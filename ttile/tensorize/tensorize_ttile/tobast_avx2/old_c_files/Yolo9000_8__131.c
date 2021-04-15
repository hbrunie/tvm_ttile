#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (1, c);
  Lambda_apply y [((Iter 5), (Arg 11)); ((Iter 1), (Arg 13))]; T (4, c);
  T (16, f); T (34, x); T (2, c)]
*/
IND_TYPE c, cp_0, c1416_p_0, c1417_p_0, c1418_p_0, cp_1, c1416_p_1, c1417_p_1, cp_2, c1416_p_2, cp_3, c1416, c1417, c1418, f, fp_0, w, wp_0, x, xp_0, x1426_p_0, xp_1, x1426, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y776 = 0;
IND_TYPE x1427 = 0;
IND_TYPE h = 0;
IND_TYPE w656 = 0;
IND_TYPE c1419 = 0;
IND_TYPE f1300 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10140 ,mem_vec_10141 ,mem_vec_10142 ,mem_vec_10143 ,mem_vec_10144 ,mem_vec_10145 ,mem_vec_10146 ,mem_vec_10147 ,mem_vec_10148 ,mem_vec_10149 ,mem_vec_10150 ,mem_vec_10151 ,mem_vec_10152 ,mem_vec_10153 ,mem_vec_10154 ,mem_vec_10155 ,mem_vec_10156 ,mem_vec_10157 ,mem_vec_10158 ,mem_vec_10159 ,mem_vec_10160 ,mem_vec_10161 ,mem_vec_10162 ,mem_vec_10163 ,mem_vec_10164 ,mem_vec_10165 ,mem_vec_10166 ,mem_vec_10167 ,mem_vec_10168 ,mem_vec_10169 ,mem_vec_10170 ,mem_vec_10171 ,mem_vec_10172 ,mem_vec_10173 ,mem_vec_10174 ,mem_vec_10175 ,mem_vec_10176 ,mem_vec_10177 ,mem_vec_10178 ,mem_vec_10179 ,mem_vec_10180 ,mem_vec_10181 ,mem_vec_10182 ,mem_vec_10183 ,mem_vec_10184 ,mem_vec_10185 ,mem_vec_10186 ,mem_vec_10187 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (c, 2) (128 / 64)
for (c1418 = c1419, c1418_p_0 = 0;
	c1418 < c1419 + 128;
	c1418 += 64, c1418_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 64, f = 256
	// T (x, 34) (68 / 2)
	for (x1426 = x1427, x1426_p_0 = 0;
		x1426 < x1427 + 68;
		x1426 += 2, x1426_p_0 += 2){
		// y = 68, x = 2, h = 3, w = 3, c = 64, f = 256
		// T (f, 16) (256 / 16)
		for (f = f1300, fp_0 = 0;
			f < f1300 + 256;
			f += 16, fp_0 += 16){
			// y = 68, x = 2, h = 3, w = 3, c = 64, f = 16
			// T (c, 4) (64 / 16)
			for (c1417 = c1418, c1417_p_1 = c1418_p_0, c1417_p_0 = 0;
				c1417 < c1418 + 64;
				c1417 += 16, c1417_p_1 += 16, c1417_p_0 += 16){
					for (y = y776, yp_0 = 0;
						y < y776 + 55;
						y += 11, yp_0 += 11){
						// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 16
						// T (c, 1) (16 / 16)
						for (c1416 = c1417, c1416_p_2 = c1417_p_1, c1416_p_1 = c1417_p_0, c1416_p_0 = 0;
							c1416 < c1417 + 16;
							c1416 += 16, c1416_p_2 += 16, c1416_p_1 += 16, c1416_p_0 += 16){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w656, wp_0 = 0;
								w < w656 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 16, f = 16
								// T (x, 2) (2 / 1)
								for (x = x1426, xp_1 = x1426_p_0, xp_0 = 0;
									x < x1426 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_10140 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_10141 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_10142 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_10143 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_10144 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_10145 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_10146 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_10147 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_10148 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_10149 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_10150 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_10151 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_10152 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_10153 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_10154 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_10155 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_10156 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_10157 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_10158 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_10159 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_10160 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_10161 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c1416, cp_3 = c1416_p_2, cp_2 = c1416_p_1, cp_1 = c1416_p_0, cp_0 = 0;
												c < c1416 + 16;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10140);
												mem_vec_10140 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10141);
												mem_vec_10141 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_10142);
												mem_vec_10142 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_10143);
												mem_vec_10143 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_10144);
												mem_vec_10144 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_10145);
												mem_vec_10145 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_10146);
												mem_vec_10146 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_10147);
												mem_vec_10147 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10148);
												mem_vec_10148 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10149);
												mem_vec_10149 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_10150);
												mem_vec_10150 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_10151);
												mem_vec_10151 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_10152);
												mem_vec_10152 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_10153);
												mem_vec_10153 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_10154);
												mem_vec_10154 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_10155);
												mem_vec_10155 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_10156);
												mem_vec_10156 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_10157);
												mem_vec_10157 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_10158);
												mem_vec_10158 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_10159);
												mem_vec_10159 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_10160);
												mem_vec_10160 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_10161);
												mem_vec_10161 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_36 = _mm256_set1_ps(scal_11);
												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_10140);
												mem_vec_10140 = vec_35;

												vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_10141);
												mem_vec_10141 = vec_38;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_37, mem_vec_10142);
												mem_vec_10142 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_39, mem_vec_10143);
												mem_vec_10143 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_10144);
												mem_vec_10144 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_39, mem_vec_10145);
												mem_vec_10145 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_37, mem_vec_10146);
												mem_vec_10146 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_39, mem_vec_10147);
												mem_vec_10147 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_37, mem_vec_10148);
												mem_vec_10148 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_39, mem_vec_10149);
												mem_vec_10149 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_10150);
												mem_vec_10150 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_10151);
												mem_vec_10151 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_37, mem_vec_10152);
												mem_vec_10152 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_39, mem_vec_10153);
												mem_vec_10153 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_37, mem_vec_10154);
												mem_vec_10154 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_39, mem_vec_10155);
												mem_vec_10155 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_10156);
												mem_vec_10156 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_10157);
												mem_vec_10157 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_37, mem_vec_10158);
												mem_vec_10158 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_39, mem_vec_10159);
												mem_vec_10159 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_37, mem_vec_10160);
												mem_vec_10160 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_39, mem_vec_10161);
												mem_vec_10161 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_71 = _mm256_set1_ps(scal_22);
												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_10140);
												mem_vec_10140 = vec_70;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_10141);
												mem_vec_10141 = vec_73;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_72, mem_vec_10142);
												mem_vec_10142 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_74, mem_vec_10143);
												mem_vec_10143 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_72, mem_vec_10144);
												mem_vec_10144 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_74, mem_vec_10145);
												mem_vec_10145 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_72, mem_vec_10146);
												mem_vec_10146 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_74, mem_vec_10147);
												mem_vec_10147 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_72, mem_vec_10148);
												mem_vec_10148 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_74, mem_vec_10149);
												mem_vec_10149 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_10150);
												mem_vec_10150 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_10151);
												mem_vec_10151 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_72, mem_vec_10152);
												mem_vec_10152 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_74, mem_vec_10153);
												mem_vec_10153 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_72, mem_vec_10154);
												mem_vec_10154 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_74, mem_vec_10155);
												mem_vec_10155 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_10156);
												mem_vec_10156 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_10157);
												mem_vec_10157 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_72, mem_vec_10158);
												mem_vec_10158 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_74, mem_vec_10159);
												mem_vec_10159 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_72, mem_vec_10160);
												mem_vec_10160 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_74, mem_vec_10161);
												mem_vec_10161 = vec_104;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10140);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10141);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10142);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10143);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10144);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10145);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10146);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10147);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10148);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10149);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10150);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_10151);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10152);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_10153);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10154);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_10155);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10156);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_10157);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10158);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_10159);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10160);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_10161);
								}
							}
						}
					}
					for (y = y776 + 55, yp_0 = 0;
						y < y776 + 55 + 13;
						y += 13, yp_0 += 13){
						// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 16
						// T (c, 1) (16 / 16)
						for (c1416 = c1417, c1416_p_2 = c1417_p_1, c1416_p_1 = c1417_p_0, c1416_p_0 = 0;
							c1416 < c1417 + 16;
							c1416 += 16, c1416_p_2 += 16, c1416_p_1 += 16, c1416_p_0 += 16){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w656, wp_0 = 0;
								w < w656 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 16, f = 16
								// T (x, 2) (2 / 1)
								for (x = x1426, xp_1 = x1426_p_0, xp_0 = 0;
									x < x1426 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_10162 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_10163 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_10164 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_10165 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_10166 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_10167 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_10168 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_10169 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_10170 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_10171 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_10172 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_10173 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_10174 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_10175 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_10176 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_10177 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_10178 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_10179 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_10180 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_10181 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_10182 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_10183 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											mem_vec_10184 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_10185 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
											mem_vec_10186 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_10187 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c1416, cp_3 = c1416_p_2, cp_2 = c1416_p_1, cp_1 = c1416_p_0, cp_0 = 0;
												c < c1416 + 16;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10162);
												mem_vec_10162 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10163);
												mem_vec_10163 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_10164);
												mem_vec_10164 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_10165);
												mem_vec_10165 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_10166);
												mem_vec_10166 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_10167);
												mem_vec_10167 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_10168);
												mem_vec_10168 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_10169);
												mem_vec_10169 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10170);
												mem_vec_10170 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10171);
												mem_vec_10171 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_10172);
												mem_vec_10172 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_10173);
												mem_vec_10173 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_10174);
												mem_vec_10174 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_10175);
												mem_vec_10175 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_10176);
												mem_vec_10176 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_10177);
												mem_vec_10177 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_10178);
												mem_vec_10178 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_10179);
												mem_vec_10179 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_10180);
												mem_vec_10180 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_10181);
												mem_vec_10181 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_10182);
												mem_vec_10182 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_10183);
												mem_vec_10183 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm256_set1_ps(scal_11);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_10184);
												mem_vec_10184 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_10185);
												mem_vec_10185 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm256_set1_ps(scal_12);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_2, mem_vec_10186);
												mem_vec_10186 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_4, mem_vec_10187);
												mem_vec_10187 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_42 = _mm256_set1_ps(scal_13);
												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_41 = _mm256_fmadd_ps(vec_42, vec_43, mem_vec_10162);
												mem_vec_10162 = vec_41;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_44 = _mm256_fmadd_ps(vec_42, vec_45, mem_vec_10163);
												mem_vec_10163 = vec_44;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_43, mem_vec_10164);
												mem_vec_10164 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_45, mem_vec_10165);
												mem_vec_10165 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_43, mem_vec_10166);
												mem_vec_10166 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_45, mem_vec_10167);
												mem_vec_10167 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_10168);
												mem_vec_10168 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_10169);
												mem_vec_10169 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_43, mem_vec_10170);
												mem_vec_10170 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_45, mem_vec_10171);
												mem_vec_10171 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_10172);
												mem_vec_10172 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_10173);
												mem_vec_10173 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_10174);
												mem_vec_10174 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_10175);
												mem_vec_10175 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_43, mem_vec_10176);
												mem_vec_10176 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_45, mem_vec_10177);
												mem_vec_10177 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_43, mem_vec_10178);
												mem_vec_10178 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_45, mem_vec_10179);
												mem_vec_10179 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_71 = _mm256_set1_ps(scal_22);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_43, mem_vec_10180);
												mem_vec_10180 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_45, mem_vec_10181);
												mem_vec_10181 = vec_72;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_23);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_10182);
												mem_vec_10182 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_10183);
												mem_vec_10183 = vec_75;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_77 = _mm256_set1_ps(scal_24);


												vec_76 = _mm256_fmadd_ps(vec_77, vec_43, mem_vec_10184);
												mem_vec_10184 = vec_76;



												vec_78 = _mm256_fmadd_ps(vec_77, vec_45, mem_vec_10185);
												mem_vec_10185 = vec_78;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
												vec_80 = _mm256_set1_ps(scal_25);


												vec_79 = _mm256_fmadd_ps(vec_80, vec_43, mem_vec_10186);
												mem_vec_10186 = vec_79;



												vec_81 = _mm256_fmadd_ps(vec_80, vec_45, mem_vec_10187);
												mem_vec_10187 = vec_81;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_26);
												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_82 = _mm256_fmadd_ps(vec_83, vec_84, mem_vec_10162);
												mem_vec_10162 = vec_82;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_85 = _mm256_fmadd_ps(vec_83, vec_86, mem_vec_10163);
												mem_vec_10163 = vec_85;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_10164);
												mem_vec_10164 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_10165);
												mem_vec_10165 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_84, mem_vec_10166);
												mem_vec_10166 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_86, mem_vec_10167);
												mem_vec_10167 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_84, mem_vec_10168);
												mem_vec_10168 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_86, mem_vec_10169);
												mem_vec_10169 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_10170);
												mem_vec_10170 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_10171);
												mem_vec_10171 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_84, mem_vec_10172);
												mem_vec_10172 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_86, mem_vec_10173);
												mem_vec_10173 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_10174);
												mem_vec_10174 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_10175);
												mem_vec_10175 = vec_104;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_106 = _mm256_set1_ps(scal_33);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_84, mem_vec_10176);
												mem_vec_10176 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_86, mem_vec_10177);
												mem_vec_10177 = vec_107;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_109 = _mm256_set1_ps(scal_34);


												vec_108 = _mm256_fmadd_ps(vec_109, vec_84, mem_vec_10178);
												mem_vec_10178 = vec_108;



												vec_110 = _mm256_fmadd_ps(vec_109, vec_86, mem_vec_10179);
												mem_vec_10179 = vec_110;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_112 = _mm256_set1_ps(scal_35);


												vec_111 = _mm256_fmadd_ps(vec_112, vec_84, mem_vec_10180);
												mem_vec_10180 = vec_111;



												vec_113 = _mm256_fmadd_ps(vec_112, vec_86, mem_vec_10181);
												mem_vec_10181 = vec_113;
												scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_115 = _mm256_set1_ps(scal_36);


												vec_114 = _mm256_fmadd_ps(vec_115, vec_84, mem_vec_10182);
												mem_vec_10182 = vec_114;



												vec_116 = _mm256_fmadd_ps(vec_115, vec_86, mem_vec_10183);
												mem_vec_10183 = vec_116;
												scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_118 = _mm256_set1_ps(scal_37);


												vec_117 = _mm256_fmadd_ps(vec_118, vec_84, mem_vec_10184);
												mem_vec_10184 = vec_117;



												vec_119 = _mm256_fmadd_ps(vec_118, vec_86, mem_vec_10185);
												mem_vec_10185 = vec_119;
												scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
												vec_121 = _mm256_set1_ps(scal_38);


												vec_120 = _mm256_fmadd_ps(vec_121, vec_84, mem_vec_10186);
												mem_vec_10186 = vec_120;



												vec_122 = _mm256_fmadd_ps(vec_121, vec_86, mem_vec_10187);
												mem_vec_10187 = vec_122;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10162);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10163);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10164);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10165);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10166);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10167);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10168);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10169);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10170);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10171);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10172);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_10173);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10174);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_10175);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10176);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_10177);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10178);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_10179);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10180);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_10181);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10182);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_10183);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_10184);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_10185);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_10186);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8], mem_vec_10187);
								}
							}
						}
					}
			}
		}
	}
}


}