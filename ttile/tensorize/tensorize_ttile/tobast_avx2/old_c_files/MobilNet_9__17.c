#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (1, c); T (8, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (1, c);
  T (2, f); T (32, c)]
*/
IND_TYPE c, cp_0, c1578_p_0, c1579_p_0, c1580_p_0, cp_1, c1578_p_1, c1579_p_1, cp_2, c1578_p_2, cp_3, c1578, c1579, c1580, f, fp_0, f1038_p_0, fp_1, f1038, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y692 = 0;
IND_TYPE x692 = 0;
IND_TYPE h618 = 0;
IND_TYPE w = 0;
IND_TYPE c1581 = 0;
IND_TYPE f1039 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_15120 ,mem_vec_15121 ,mem_vec_15122 ,mem_vec_15123 ,mem_vec_15124 ,mem_vec_15125 ,mem_vec_15126 ,mem_vec_15127 ,mem_vec_15128 ,mem_vec_15129 ,mem_vec_15130 ,mem_vec_15131 ,mem_vec_15132 ,mem_vec_15133 ,mem_vec_15134 ,mem_vec_15135 ,mem_vec_15136 ,mem_vec_15137 ,mem_vec_15138 ,mem_vec_15139 ,mem_vec_15140 ,mem_vec_15141 ,mem_vec_15142 ,mem_vec_15143 ,mem_vec_15144 ,mem_vec_15145 ,mem_vec_15146 ,mem_vec_15147 ,mem_vec_15148 ,mem_vec_15149 ,mem_vec_15150 ,mem_vec_15151 ,mem_vec_15152 ,mem_vec_15153 ,mem_vec_15154 ,mem_vec_15155 ,mem_vec_15156 ,mem_vec_15157 ,mem_vec_15158 ,mem_vec_15159 ,mem_vec_15160 ,mem_vec_15161 ,mem_vec_15162 ,mem_vec_15163 ,mem_vec_15164 ,mem_vec_15165 ,mem_vec_15166 ,mem_vec_15167 ,mem_vec_15168 ,mem_vec_15169 ,mem_vec_15170 ,mem_vec_15171 ,mem_vec_15172 ,mem_vec_15173 ,mem_vec_15174 ,mem_vec_15175 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 32) (1024 / 32)
for (c1580 = c1581, c1580_p_0 = 0;
	c1580 < c1581 + 1024;
	c1580 += 32, c1580_p_0 += 32){
	// y = 7, x = 7, h = 3, w = 3, c = 32, f = 1024
	// T (f, 2) (1024 / 512)
	for (f1038 = f1039, f1038_p_0 = 0;
		f1038 < f1039 + 1024;
		f1038 += 512, f1038_p_0 += 512){
		// y = 7, x = 7, h = 3, w = 3, c = 32, f = 512
		// T (c, 1) (32 / 32)
		for (c1579 = c1580, c1579_p_1 = c1580_p_0, c1579_p_0 = 0;
			c1579 < c1580 + 32;
			c1579 += 32, c1579_p_1 += 32, c1579_p_0 += 32){
				for (y = y692, yp_0 = 0;
					y < y692 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 512
					// T (f, 8) (512 / 64)
					for (f = f1038, fp_1 = f1038_p_0, fp_0 = 0;
						f < f1038 + 512;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 64
						// T (c, 1) (32 / 32)
						for (c1578 = c1579, c1578_p_2 = c1579_p_1, c1578_p_1 = c1579_p_0, c1578_p_0 = 0;
							c1578 < c1579 + 32;
							c1578 += 32, c1578_p_2 += 32, c1578_p_1 += 32, c1578_p_0 += 32){
							// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 64
							// T (h, 3) (3 / 1)
							for (h = h618, hp_0 = 0;
								h < h618 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 32, f = 64
								// T (x, 7) (7 / 1)
								for (x = x692, xp_0 = 0;
									x < x692 + 7;
									x += 1, xp_0 += 1){
											mem_vec_15120 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_15121 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_15122 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_15123 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_15124 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_15125 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
											mem_vec_15126 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_15127 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
											mem_vec_15128 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_15129 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_15130 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_15131 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_15132 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_15133 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
											mem_vec_15134 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_15135 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
											mem_vec_15136 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_15137 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_15138 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_15139 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_15140 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_15141 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
											mem_vec_15142 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_15143 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
											// T (c, 32) (32 / 1)
											for (c = c1578, cp_3 = c1578_p_2, cp_2 = c1578_p_1, cp_1 = c1578_p_0, cp_0 = 0;
												c < c1578 + 32;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_15120);
												mem_vec_15120 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_15121);
												mem_vec_15121 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_15122);
												mem_vec_15122 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_15123);
												mem_vec_15123 = vec_7;

												vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_15124);
												mem_vec_15124 = vec_9;

												vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

												vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_15125);
												mem_vec_15125 = vec_11;

												vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_15126);
												mem_vec_15126 = vec_13;

												vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

												vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_15127);
												mem_vec_15127 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm256_set1_ps(scal_1);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_15128);
												mem_vec_15128 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_15129);
												mem_vec_15129 = vec_19;



												vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_15130);
												mem_vec_15130 = vec_20;



												vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_15131);
												mem_vec_15131 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_15132);
												mem_vec_15132 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_15133);
												mem_vec_15133 = vec_23;



												vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_15134);
												mem_vec_15134 = vec_24;



												vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_15135);
												mem_vec_15135 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm256_set1_ps(scal_2);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_15136);
												mem_vec_15136 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_15137);
												mem_vec_15137 = vec_28;



												vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_15138);
												mem_vec_15138 = vec_29;



												vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_15139);
												mem_vec_15139 = vec_30;



												vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_15140);
												mem_vec_15140 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_15141);
												mem_vec_15141 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_15142);
												mem_vec_15142 = vec_33;



												vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_15143);
												mem_vec_15143 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_36 = _mm256_set1_ps(scal_3);
												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_15120);
												mem_vec_15120 = vec_35;

												vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_15121);
												mem_vec_15121 = vec_38;

												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_40 = _mm256_fmadd_ps(vec_36, vec_41, mem_vec_15122);
												mem_vec_15122 = vec_40;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_42 = _mm256_fmadd_ps(vec_36, vec_43, mem_vec_15123);
												mem_vec_15123 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm256_fmadd_ps(vec_36, vec_45, mem_vec_15124);
												mem_vec_15124 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

												vec_46 = _mm256_fmadd_ps(vec_36, vec_47, mem_vec_15125);
												mem_vec_15125 = vec_46;

												vec_49 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_48 = _mm256_fmadd_ps(vec_36, vec_49, mem_vec_15126);
												mem_vec_15126 = vec_48;

												vec_51 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

												vec_50 = _mm256_fmadd_ps(vec_36, vec_51, mem_vec_15127);
												mem_vec_15127 = vec_50;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_53 = _mm256_set1_ps(scal_4);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_15128);
												mem_vec_15128 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_15129);
												mem_vec_15129 = vec_54;



												vec_55 = _mm256_fmadd_ps(vec_53, vec_41, mem_vec_15130);
												mem_vec_15130 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_15131);
												mem_vec_15131 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_15132);
												mem_vec_15132 = vec_57;



												vec_58 = _mm256_fmadd_ps(vec_53, vec_47, mem_vec_15133);
												mem_vec_15133 = vec_58;



												vec_59 = _mm256_fmadd_ps(vec_53, vec_49, mem_vec_15134);
												mem_vec_15134 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_53, vec_51, mem_vec_15135);
												mem_vec_15135 = vec_60;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_62 = _mm256_set1_ps(scal_5);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_15136);
												mem_vec_15136 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_15137);
												mem_vec_15137 = vec_63;



												vec_64 = _mm256_fmadd_ps(vec_62, vec_41, mem_vec_15138);
												mem_vec_15138 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_15139);
												mem_vec_15139 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_15140);
												mem_vec_15140 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_62, vec_47, mem_vec_15141);
												mem_vec_15141 = vec_67;



												vec_68 = _mm256_fmadd_ps(vec_62, vec_49, mem_vec_15142);
												mem_vec_15142 = vec_68;



												vec_69 = _mm256_fmadd_ps(vec_62, vec_51, mem_vec_15143);
												mem_vec_15143 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_71 = _mm256_set1_ps(scal_6);
												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_15120);
												mem_vec_15120 = vec_70;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_15121);
												mem_vec_15121 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_75 = _mm256_fmadd_ps(vec_71, vec_76, mem_vec_15122);
												mem_vec_15122 = vec_75;

												vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_77 = _mm256_fmadd_ps(vec_71, vec_78, mem_vec_15123);
												mem_vec_15123 = vec_77;

												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_79 = _mm256_fmadd_ps(vec_71, vec_80, mem_vec_15124);
												mem_vec_15124 = vec_79;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

												vec_81 = _mm256_fmadd_ps(vec_71, vec_82, mem_vec_15125);
												mem_vec_15125 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_83 = _mm256_fmadd_ps(vec_71, vec_84, mem_vec_15126);
												mem_vec_15126 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

												vec_85 = _mm256_fmadd_ps(vec_71, vec_86, mem_vec_15127);
												mem_vec_15127 = vec_85;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm256_set1_ps(scal_7);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_15128);
												mem_vec_15128 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_15129);
												mem_vec_15129 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_15130);
												mem_vec_15130 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_15131);
												mem_vec_15131 = vec_91;



												vec_92 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_15132);
												mem_vec_15132 = vec_92;



												vec_93 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_15133);
												mem_vec_15133 = vec_93;



												vec_94 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_15134);
												mem_vec_15134 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_15135);
												mem_vec_15135 = vec_95;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_97 = _mm256_set1_ps(scal_8);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_15136);
												mem_vec_15136 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_15137);
												mem_vec_15137 = vec_98;



												vec_99 = _mm256_fmadd_ps(vec_97, vec_76, mem_vec_15138);
												mem_vec_15138 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_15139);
												mem_vec_15139 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_15140);
												mem_vec_15140 = vec_101;



												vec_102 = _mm256_fmadd_ps(vec_97, vec_82, mem_vec_15141);
												mem_vec_15141 = vec_102;



												vec_103 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_15142);
												mem_vec_15142 = vec_103;



												vec_104 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_15143);
												mem_vec_15143 = vec_104;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15120);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_15121);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15122);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_15123);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_15124);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_15125);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_15126);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_15127);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15128);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_15129);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15130);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_15131);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_15132);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_15133);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_15134);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_15135);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15136);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_15137);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15138);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_15139);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_15140);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_15141);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_15142);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_15143);
								}
							}
						}
					}
				}
				for (y = y692 + 3, yp_0 = 0;
					y < y692 + 3 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 512
					// T (f, 8) (512 / 64)
					for (f = f1038, fp_1 = f1038_p_0, fp_0 = 0;
						f < f1038 + 512;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 64
						// T (c, 1) (32 / 32)
						for (c1578 = c1579, c1578_p_2 = c1579_p_1, c1578_p_1 = c1579_p_0, c1578_p_0 = 0;
							c1578 < c1579 + 32;
							c1578 += 32, c1578_p_2 += 32, c1578_p_1 += 32, c1578_p_0 += 32){
							// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 64
							// T (h, 3) (3 / 1)
							for (h = h618, hp_0 = 0;
								h < h618 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 32, f = 64
								// T (x, 7) (7 / 1)
								for (x = x692, xp_0 = 0;
									x < x692 + 7;
									x += 1, xp_0 += 1){
											mem_vec_15144 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_15145 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_15146 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_15147 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_15148 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_15149 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
											mem_vec_15150 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_15151 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
											mem_vec_15152 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_15153 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_15154 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_15155 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_15156 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_15157 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
											mem_vec_15158 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_15159 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
											mem_vec_15160 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_15161 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_15162 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_15163 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_15164 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_15165 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
											mem_vec_15166 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_15167 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
											mem_vec_15168 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_15169 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_15170 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_15171 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_15172 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_15173 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
											mem_vec_15174 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_15175 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
											// T (c, 32) (32 / 1)
											for (c = c1578, cp_3 = c1578_p_2, cp_2 = c1578_p_1, cp_1 = c1578_p_0, cp_0 = 0;
												c < c1578 + 32;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_15144);
												mem_vec_15144 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_15145);
												mem_vec_15145 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_15146);
												mem_vec_15146 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_15147);
												mem_vec_15147 = vec_7;

												vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_15148);
												mem_vec_15148 = vec_9;

												vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

												vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_15149);
												mem_vec_15149 = vec_11;

												vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_15150);
												mem_vec_15150 = vec_13;

												vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

												vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_15151);
												mem_vec_15151 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm256_set1_ps(scal_1);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_15152);
												mem_vec_15152 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_15153);
												mem_vec_15153 = vec_19;



												vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_15154);
												mem_vec_15154 = vec_20;



												vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_15155);
												mem_vec_15155 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_15156);
												mem_vec_15156 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_15157);
												mem_vec_15157 = vec_23;



												vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_15158);
												mem_vec_15158 = vec_24;



												vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_15159);
												mem_vec_15159 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm256_set1_ps(scal_2);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_15160);
												mem_vec_15160 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_15161);
												mem_vec_15161 = vec_28;



												vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_15162);
												mem_vec_15162 = vec_29;



												vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_15163);
												mem_vec_15163 = vec_30;



												vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_15164);
												mem_vec_15164 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_15165);
												mem_vec_15165 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_15166);
												mem_vec_15166 = vec_33;



												vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_15167);
												mem_vec_15167 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_36 = _mm256_set1_ps(scal_3);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_15168);
												mem_vec_15168 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_15169);
												mem_vec_15169 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_15170);
												mem_vec_15170 = vec_38;



												vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_15171);
												mem_vec_15171 = vec_39;



												vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_15172);
												mem_vec_15172 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_15173);
												mem_vec_15173 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_15174);
												mem_vec_15174 = vec_42;



												vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_15175);
												mem_vec_15175 = vec_43;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_45 = _mm256_set1_ps(scal_4);
												vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_15144);
												mem_vec_15144 = vec_44;

												vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_15145);
												mem_vec_15145 = vec_47;

												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_15146);
												mem_vec_15146 = vec_49;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_15147);
												mem_vec_15147 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_15148);
												mem_vec_15148 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

												vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_15149);
												mem_vec_15149 = vec_55;

												vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_15150);
												mem_vec_15150 = vec_57;

												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

												vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_15151);
												mem_vec_15151 = vec_59;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_62 = _mm256_set1_ps(scal_5);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_15152);
												mem_vec_15152 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_15153);
												mem_vec_15153 = vec_63;



												vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_15154);
												mem_vec_15154 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_15155);
												mem_vec_15155 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_15156);
												mem_vec_15156 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_15157);
												mem_vec_15157 = vec_67;



												vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_15158);
												mem_vec_15158 = vec_68;



												vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_15159);
												mem_vec_15159 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_71 = _mm256_set1_ps(scal_6);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_15160);
												mem_vec_15160 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_15161);
												mem_vec_15161 = vec_72;



												vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_15162);
												mem_vec_15162 = vec_73;



												vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_15163);
												mem_vec_15163 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_15164);
												mem_vec_15164 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_15165);
												mem_vec_15165 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_15166);
												mem_vec_15166 = vec_77;



												vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_15167);
												mem_vec_15167 = vec_78;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_80 = _mm256_set1_ps(scal_7);


												vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_15168);
												mem_vec_15168 = vec_79;



												vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_15169);
												mem_vec_15169 = vec_81;



												vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_15170);
												mem_vec_15170 = vec_82;



												vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_15171);
												mem_vec_15171 = vec_83;



												vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_15172);
												mem_vec_15172 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_15173);
												mem_vec_15173 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_15174);
												mem_vec_15174 = vec_86;



												vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_15175);
												mem_vec_15175 = vec_87;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_89 = _mm256_set1_ps(scal_8);
												vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_15144);
												mem_vec_15144 = vec_88;

												vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_15145);
												mem_vec_15145 = vec_91;

												vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_15146);
												mem_vec_15146 = vec_93;

												vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_15147);
												mem_vec_15147 = vec_95;

												vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_15148);
												mem_vec_15148 = vec_97;

												vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

												vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_15149);
												mem_vec_15149 = vec_99;

												vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_15150);
												mem_vec_15150 = vec_101;

												vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

												vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_15151);
												mem_vec_15151 = vec_103;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_106 = _mm256_set1_ps(scal_9);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_15152);
												mem_vec_15152 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_15153);
												mem_vec_15153 = vec_107;



												vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_15154);
												mem_vec_15154 = vec_108;



												vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_15155);
												mem_vec_15155 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_15156);
												mem_vec_15156 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_15157);
												mem_vec_15157 = vec_111;



												vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_15158);
												mem_vec_15158 = vec_112;



												vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_15159);
												mem_vec_15159 = vec_113;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_115 = _mm256_set1_ps(scal_10);


												vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_15160);
												mem_vec_15160 = vec_114;



												vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_15161);
												mem_vec_15161 = vec_116;



												vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_15162);
												mem_vec_15162 = vec_117;



												vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_15163);
												mem_vec_15163 = vec_118;



												vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_15164);
												mem_vec_15164 = vec_119;



												vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_15165);
												mem_vec_15165 = vec_120;



												vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_15166);
												mem_vec_15166 = vec_121;



												vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_15167);
												mem_vec_15167 = vec_122;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_124 = _mm256_set1_ps(scal_11);


												vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_15168);
												mem_vec_15168 = vec_123;



												vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_15169);
												mem_vec_15169 = vec_125;



												vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_15170);
												mem_vec_15170 = vec_126;



												vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_15171);
												mem_vec_15171 = vec_127;



												vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_15172);
												mem_vec_15172 = vec_128;



												vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_15173);
												mem_vec_15173 = vec_129;



												vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_15174);
												mem_vec_15174 = vec_130;



												vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_15175);
												mem_vec_15175 = vec_131;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15144);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_15145);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15146);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_15147);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_15148);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_15149);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_15150);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_15151);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15152);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_15153);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15154);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_15155);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_15156);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_15157);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_15158);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_15159);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15160);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_15161);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15162);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_15163);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_15164);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_15165);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_15166);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_15167);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15168);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_15169);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15170);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_15171);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_15172);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_15173);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_15174);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_15175);
								}
							}
						}
					}
				}
		}
	}
}


}