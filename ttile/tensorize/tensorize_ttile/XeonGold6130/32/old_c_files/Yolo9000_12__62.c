#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (1, c); T (2, f);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (1, x);
  T (1, f); T (4, f)]
*/
IND_TYPE c, cp_0, c9_p_0, cp_1, c9, f, fp_0, f10_p_0, f11_p_0, fp_1, f10_p_1, fp_2, f10, f11, h, hp_0, x, xp_0, x10_p_0, xp_1, x10, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y7 = 0;
IND_TYPE x11 = 0;
IND_TYPE h6 = 0;
IND_TYPE w = 0;
IND_TYPE c10 = 0;
IND_TYPE f12 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_138 ,mem_vec_139 ,mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,mem_vec_144 ,mem_vec_145 ,mem_vec_146 ,mem_vec_147 ,mem_vec_148 ,mem_vec_149 ,mem_vec_150 ,mem_vec_151 ,mem_vec_152 ,mem_vec_153 ,mem_vec_154 ,mem_vec_155 ,mem_vec_156 ,mem_vec_157 ,mem_vec_158 ,mem_vec_159 ,mem_vec_160 ,mem_vec_161 ,mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,mem_vec_168 ,mem_vec_169 ,mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,mem_vec_176 ,mem_vec_177 ,mem_vec_178 ,mem_vec_179 ,mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,mem_vec_184 ,mem_vec_185 ,mem_vec_186 ,mem_vec_187 ,mem_vec_188 ,mem_vec_189 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f11 = f12, f11_p_0 = 0;
	f11 < f12 + 512;
	f11 += 128, f11_p_0 += 128){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
	// T (f, 1) (128 / 128)
	for (f10 = f11, f10_p_1 = f11_p_0, f10_p_0 = 0;
		f10 < f11 + 128;
		f10 += 128, f10_p_1 += 128, f10_p_0 += 128){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
		// T (x, 1) (34 / 34)
		for (x10 = x11, x10_p_0 = 0;
			x10 < x11 + 34;
			x10 += 34, x10_p_0 += 34){
				for (y = y7, yp_0 = 0;
					y < y7 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f10, fp_2 = f10_p_1, fp_1 = f10_p_0, fp_0 = 0;
						f < f10 + 128;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c9 = c10, c9_p_0 = 0;
							c9 < c10 + 256;
							c9 += 256, c9_p_0 += 256){
							// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h6, hp_0 = 0;
								h < h6 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 256, f = 64
								// T (x, 34) (34 / 1)
								for (x = x10, xp_1 = x10_p_0, xp_0 = 0;
									x < x10 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_138 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_139 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_140 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_141 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c9, cp_1 = c9_p_0, cp_0 = 0;
												c < c9 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_138);
												mem_vec_138 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_139);
												mem_vec_139 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_140);
												mem_vec_140 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_141);
												mem_vec_141 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_142);
												mem_vec_142 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_143);
												mem_vec_143 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_144);
												mem_vec_144 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_145);
												mem_vec_145 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_146);
												mem_vec_146 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_147);
												mem_vec_147 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_148);
												mem_vec_148 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_149);
												mem_vec_149 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_150);
												mem_vec_150 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_151);
												mem_vec_151 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_152);
												mem_vec_152 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_153);
												mem_vec_153 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_154);
												mem_vec_154 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_155);
												mem_vec_155 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_156);
												mem_vec_156 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_157);
												mem_vec_157 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_158);
												mem_vec_158 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_159);
												mem_vec_159 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_160);
												mem_vec_160 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_161);
												mem_vec_161 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_138);
												mem_vec_138 = vec_34;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_139);
												mem_vec_139 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_140);
												mem_vec_140 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_141);
												mem_vec_141 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_142);
												mem_vec_142 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_143);
												mem_vec_143 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_144);
												mem_vec_144 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_145);
												mem_vec_145 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_146);
												mem_vec_146 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_147);
												mem_vec_147 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_148);
												mem_vec_148 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_149);
												mem_vec_149 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_150);
												mem_vec_150 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_151);
												mem_vec_151 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_152);
												mem_vec_152 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_153);
												mem_vec_153 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_154);
												mem_vec_154 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_155);
												mem_vec_155 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_156);
												mem_vec_156 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_157);
												mem_vec_157 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_158);
												mem_vec_158 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_159);
												mem_vec_159 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_160);
												mem_vec_160 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_161);
												mem_vec_161 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_138);
												mem_vec_138 = vec_68;

												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_139);
												mem_vec_139 = vec_71;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_140);
												mem_vec_140 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_141);
												mem_vec_141 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_142);
												mem_vec_142 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_143);
												mem_vec_143 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_144);
												mem_vec_144 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_145);
												mem_vec_145 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_146);
												mem_vec_146 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_147);
												mem_vec_147 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_148);
												mem_vec_148 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_149);
												mem_vec_149 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_150);
												mem_vec_150 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_151);
												mem_vec_151 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_152);
												mem_vec_152 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_153);
												mem_vec_153 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_154);
												mem_vec_154 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_155);
												mem_vec_155 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_156);
												mem_vec_156 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_157);
												mem_vec_157 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_158);
												mem_vec_158 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_159);
												mem_vec_159 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_160);
												mem_vec_160 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_161);
												mem_vec_161 = vec_101;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_138);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_139);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_140);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_141);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_142);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_143);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_144);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_145);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_146);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_147);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_148);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_149);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_150);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_151);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_152);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_153);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_154);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_155);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_156);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_157);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_158);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_159);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_160);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_161);
								}
							}
						}
					}
				}
				for (y = y7 + 6, yp_0 = 0;
					y < y7 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f10, fp_2 = f10_p_1, fp_1 = f10_p_0, fp_0 = 0;
						f < f10 + 128;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c9 = c10, c9_p_0 = 0;
							c9 < c10 + 256;
							c9 += 256, c9_p_0 += 256){
							// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h6, hp_0 = 0;
								h < h6 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 256, f = 64
								// T (x, 34) (34 / 1)
								for (x = x10, xp_1 = x10_p_0, xp_0 = 0;
									x < x10 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_162 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_163 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_164 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_165 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											mem_vec_186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
											mem_vec_189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c9, cp_1 = c9_p_0, cp_0 = 0;
												c < c9 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_162);
												mem_vec_162 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_163);
												mem_vec_163 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_164);
												mem_vec_164 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_165);
												mem_vec_165 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_166);
												mem_vec_166 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_167);
												mem_vec_167 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_168);
												mem_vec_168 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_169);
												mem_vec_169 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_170);
												mem_vec_170 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_171);
												mem_vec_171 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_172);
												mem_vec_172 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_173);
												mem_vec_173 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_174);
												mem_vec_174 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_175);
												mem_vec_175 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_176);
												mem_vec_176 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_177);
												mem_vec_177 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_178);
												mem_vec_178 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_179);
												mem_vec_179 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_180);
												mem_vec_180 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_181);
												mem_vec_181 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_182);
												mem_vec_182 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_183);
												mem_vec_183 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_184);
												mem_vec_184 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_185);
												mem_vec_185 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_186);
												mem_vec_186 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_187);
												mem_vec_187 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_188);
												mem_vec_188 = vec_37;



												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_189);
												mem_vec_189 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_40 = _mm512_set1_ps(scal_7);
												vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_162);
												mem_vec_162 = vec_39;

												vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_163);
												mem_vec_163 = vec_42;

												vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_164);
												mem_vec_164 = vec_44;

												vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_165);
												mem_vec_165 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_166);
												mem_vec_166 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_167);
												mem_vec_167 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_168);
												mem_vec_168 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_169);
												mem_vec_169 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_170);
												mem_vec_170 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_171);
												mem_vec_171 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_172);
												mem_vec_172 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_173);
												mem_vec_173 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_174);
												mem_vec_174 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_175);
												mem_vec_175 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_176);
												mem_vec_176 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_177);
												mem_vec_177 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_178);
												mem_vec_178 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_179);
												mem_vec_179 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_180);
												mem_vec_180 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_181);
												mem_vec_181 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);


												vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_182);
												mem_vec_182 = vec_68;



												vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_183);
												mem_vec_183 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_184);
												mem_vec_184 = vec_71;



												vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_185);
												mem_vec_185 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_74 = _mm512_set1_ps(scal_13);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_186);
												mem_vec_186 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_187);
												mem_vec_187 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_188);
												mem_vec_188 = vec_76;



												vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_189);
												mem_vec_189 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_79 = _mm512_set1_ps(scal_14);
												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_162);
												mem_vec_162 = vec_78;

												vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_163);
												mem_vec_163 = vec_81;

												vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_164);
												mem_vec_164 = vec_83;

												vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_165);
												mem_vec_165 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_166);
												mem_vec_166 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_167);
												mem_vec_167 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_168);
												mem_vec_168 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_169);
												mem_vec_169 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_170);
												mem_vec_170 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_171);
												mem_vec_171 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_172);
												mem_vec_172 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_173);
												mem_vec_173 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_174);
												mem_vec_174 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_175);
												mem_vec_175 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_176);
												mem_vec_176 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_177);
												mem_vec_177 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_103 = _mm512_set1_ps(scal_18);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_178);
												mem_vec_178 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_179);
												mem_vec_179 = vec_104;



												vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_180);
												mem_vec_180 = vec_105;



												vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_181);
												mem_vec_181 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_108 = _mm512_set1_ps(scal_19);


												vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_182);
												mem_vec_182 = vec_107;



												vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_183);
												mem_vec_183 = vec_109;



												vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_184);
												mem_vec_184 = vec_110;



												vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_185);
												mem_vec_185 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_113 = _mm512_set1_ps(scal_20);


												vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_186);
												mem_vec_186 = vec_112;



												vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_187);
												mem_vec_187 = vec_114;



												vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_188);
												mem_vec_188 = vec_115;



												vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_189);
												mem_vec_189 = vec_116;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_162);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_163);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_164);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_165);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_166);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_167);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_168);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_169);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_170);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_171);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_172);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_173);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_174);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_175);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_176);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_177);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_178);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_179);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_180);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_181);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_182);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_183);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_184);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_185);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_186);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_187);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_188);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_189);
								}
							}
						}
					}
				}
		}
	}
}


}