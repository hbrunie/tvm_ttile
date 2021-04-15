#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); U (3, w); T (8, c); Hoist_vars [c];
  T (68, x); Lambda_apply y [((Iter 4), (Arg 7)); ((Iter 5), (Arg 8))];
  T (4, f); T (16, c); T (2, f); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1056_p_0, cp_1, c1056, f, fp_0, f1380_p_0, f1381_p_0, fp_1, f1380_p_1, fp_2, f1380, f1381, x, xp_0, x1088_p_0, xp_1, x1088, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y704 = 0;
IND_TYPE x1089 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1057 = 0;
IND_TYPE f1382 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_45 ,scal_46 ,scal_47 ,scal_48 ,scal_49 ,scal_5 ,scal_50 ,scal_51 ,scal_52 ,scal_53 ,scal_54 ,scal_55 ,scal_56 ,scal_57 ,scal_58 ,scal_59 ,scal_6 ,scal_60 ,scal_61 ,scal_62 ,scal_63 ,scal_64 ,scal_65 ,scal_66 ,scal_67 ,scal_68 ,scal_69 ,scal_7 ,scal_70 ,scal_71 ,scal_8 ,scal_9;
__m512 mem_vec_9704 ,mem_vec_9705 ,mem_vec_9706 ,mem_vec_9707 ,mem_vec_9708 ,mem_vec_9709 ,mem_vec_9710 ,mem_vec_9711 ,mem_vec_9712 ,mem_vec_9713 ,mem_vec_9714 ,mem_vec_9715 ,mem_vec_9716 ,mem_vec_9717 ,mem_vec_9718 ,mem_vec_9719 ,mem_vec_9720 ,mem_vec_9721 ,mem_vec_9722 ,mem_vec_9723 ,mem_vec_9724 ,mem_vec_9725 ,mem_vec_9726 ,mem_vec_9727 ,mem_vec_9728 ,mem_vec_9729 ,mem_vec_9730 ,mem_vec_9731 ,mem_vec_9732 ,mem_vec_9733 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_132 ,vec_133 ,vec_134 ,vec_135 ,vec_136 ,vec_137 ,vec_138 ,vec_139 ,vec_14 ,vec_140 ,vec_141 ,vec_142 ,vec_143 ,vec_144 ,vec_145 ,vec_146 ,vec_147 ,vec_148 ,vec_149 ,vec_15 ,vec_150 ,vec_151 ,vec_152 ,vec_153 ,vec_154 ,vec_155 ,vec_156 ,vec_157 ,vec_158 ,vec_159 ,vec_16 ,vec_160 ,vec_161 ,vec_162 ,vec_163 ,vec_164 ,vec_165 ,vec_166 ,vec_167 ,vec_168 ,vec_169 ,vec_17 ,vec_170 ,vec_171 ,vec_172 ,vec_173 ,vec_174 ,vec_175 ,vec_176 ,vec_177 ,vec_178 ,vec_179 ,vec_18 ,vec_180 ,vec_181 ,vec_182 ,vec_183 ,vec_184 ,vec_185 ,vec_186 ,vec_187 ,vec_188 ,vec_189 ,vec_19 ,vec_190 ,vec_191 ,vec_192 ,vec_193 ,vec_194 ,vec_195 ,vec_196 ,vec_197 ,vec_198 ,vec_199 ,vec_2 ,vec_20 ,vec_200 ,vec_201 ,vec_202 ,vec_203 ,vec_204 ,vec_205 ,vec_206 ,vec_207 ,vec_208 ,vec_209 ,vec_21 ,vec_210 ,vec_211 ,vec_212 ,vec_213 ,vec_214 ,vec_215 ,vec_216 ,vec_217 ,vec_218 ,vec_219 ,vec_22 ,vec_220 ,vec_221 ,vec_222 ,vec_223 ,vec_224 ,vec_225 ,vec_226 ,vec_227 ,vec_228 ,vec_229 ,vec_23 ,vec_230 ,vec_231 ,vec_232 ,vec_233 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f1381 = f1382, f1381_p_0 = 0;
	f1381 < f1382 + 256;
	f1381 += 256, f1381_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (x, 1) (68 / 68)
	for (x1088 = x1089, x1088_p_0 = 0;
		x1088 < x1089 + 68;
		x1088 += 68, x1088_p_0 += 68){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
		// T (f, 2) (256 / 128)
		for (f1380 = f1381, f1380_p_1 = f1381_p_0, f1380_p_0 = 0;
			f1380 < f1381 + 256;
			f1380 += 128, f1380_p_1 += 128, f1380_p_0 += 128){
			// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
			// T (c, 16) (128 / 8)
			for (c1056 = c1057, c1056_p_0 = 0;
				c1056 < c1057 + 128;
				c1056 += 8, c1056_p_0 += 8){
				// y = 68, x = 68, h = 3, w = 3, c = 8, f = 128
				// T (f, 4) (128 / 32)
				for (f = f1380, fp_2 = f1380_p_1, fp_1 = f1380_p_0, fp_0 = 0;
					f < f1380 + 128;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y704, yp_0 = 0;
							y < y704 + 28;
							y += 7, yp_0 += 7){
							// y = ph_y, x = 68, h = 3, w = 3, c = 8, f = 32
							// T (x, 68) (68 / 1)
							for (x = x1088, xp_1 = x1088_p_0, xp_0 = 0;
								x < x1088 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9704 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9705 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c1056, cp_1 = c1056_p_0, cp_0 = 0;
											c < c1056 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9704);
											mem_vec_9704 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9705);
											mem_vec_9705 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9706);
											mem_vec_9706 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9707);
											mem_vec_9707 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9708);
											mem_vec_9708 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9709);
											mem_vec_9709 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9710);
											mem_vec_9710 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9711);
											mem_vec_9711 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9712);
											mem_vec_9712 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9713);
											mem_vec_9713 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9714);
											mem_vec_9714 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9715);
											mem_vec_9715 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9716);
											mem_vec_9716 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9717);
											mem_vec_9717 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_9704);
											mem_vec_9704 = vec_23;

											vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_9705);
											mem_vec_9705 = vec_26;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_8);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_9706);
											mem_vec_9706 = vec_28;



											vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_9707);
											mem_vec_9707 = vec_30;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_9708);
											mem_vec_9708 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_9709);
											mem_vec_9709 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_9710);
											mem_vec_9710 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_9711);
											mem_vec_9711 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_9712);
											mem_vec_9712 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_9713);
											mem_vec_9713 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_9714);
											mem_vec_9714 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_9715);
											mem_vec_9715 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_9716);
											mem_vec_9716 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_9717);
											mem_vec_9717 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_47 = _mm512_set1_ps(scal_14);
											vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_9704);
											mem_vec_9704 = vec_46;

											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_9705);
											mem_vec_9705 = vec_49;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_52 = _mm512_set1_ps(scal_15);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_9706);
											mem_vec_9706 = vec_51;



											vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_9707);
											mem_vec_9707 = vec_53;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_55 = _mm512_set1_ps(scal_16);


											vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_9708);
											mem_vec_9708 = vec_54;



											vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_9709);
											mem_vec_9709 = vec_56;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_17);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_9710);
											mem_vec_9710 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_9711);
											mem_vec_9711 = vec_59;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_61 = _mm512_set1_ps(scal_18);


											vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_9712);
											mem_vec_9712 = vec_60;



											vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_9713);
											mem_vec_9713 = vec_62;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_9714);
											mem_vec_9714 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_9715);
											mem_vec_9715 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_9716);
											mem_vec_9716 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_9717);
											mem_vec_9717 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_70 = _mm512_set1_ps(scal_21);
											vec_71 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_69 = _mm512_fmadd_ps(vec_70, vec_71, mem_vec_9704);
											mem_vec_9704 = vec_69;

											vec_73 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_72 = _mm512_fmadd_ps(vec_70, vec_73, mem_vec_9705);
											mem_vec_9705 = vec_72;
											scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_75 = _mm512_set1_ps(scal_22);


											vec_74 = _mm512_fmadd_ps(vec_75, vec_71, mem_vec_9706);
											mem_vec_9706 = vec_74;



											vec_76 = _mm512_fmadd_ps(vec_75, vec_73, mem_vec_9707);
											mem_vec_9707 = vec_76;
											scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_78 = _mm512_set1_ps(scal_23);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_71, mem_vec_9708);
											mem_vec_9708 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_73, mem_vec_9709);
											mem_vec_9709 = vec_79;
											scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_81 = _mm512_set1_ps(scal_24);


											vec_80 = _mm512_fmadd_ps(vec_81, vec_71, mem_vec_9710);
											mem_vec_9710 = vec_80;



											vec_82 = _mm512_fmadd_ps(vec_81, vec_73, mem_vec_9711);
											mem_vec_9711 = vec_82;
											scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_84 = _mm512_set1_ps(scal_25);


											vec_83 = _mm512_fmadd_ps(vec_84, vec_71, mem_vec_9712);
											mem_vec_9712 = vec_83;



											vec_85 = _mm512_fmadd_ps(vec_84, vec_73, mem_vec_9713);
											mem_vec_9713 = vec_85;
											scal_26 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_87 = _mm512_set1_ps(scal_26);


											vec_86 = _mm512_fmadd_ps(vec_87, vec_71, mem_vec_9714);
											mem_vec_9714 = vec_86;



											vec_88 = _mm512_fmadd_ps(vec_87, vec_73, mem_vec_9715);
											mem_vec_9715 = vec_88;
											scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_90 = _mm512_set1_ps(scal_27);


											vec_89 = _mm512_fmadd_ps(vec_90, vec_71, mem_vec_9716);
											mem_vec_9716 = vec_89;



											vec_91 = _mm512_fmadd_ps(vec_90, vec_73, mem_vec_9717);
											mem_vec_9717 = vec_91;
											scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_93 = _mm512_set1_ps(scal_28);
											vec_94 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_92 = _mm512_fmadd_ps(vec_93, vec_94, mem_vec_9704);
											mem_vec_9704 = vec_92;

											vec_96 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_95 = _mm512_fmadd_ps(vec_93, vec_96, mem_vec_9705);
											mem_vec_9705 = vec_95;
											scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_98 = _mm512_set1_ps(scal_29);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_94, mem_vec_9706);
											mem_vec_9706 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_96, mem_vec_9707);
											mem_vec_9707 = vec_99;
											scal_30 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_101 = _mm512_set1_ps(scal_30);


											vec_100 = _mm512_fmadd_ps(vec_101, vec_94, mem_vec_9708);
											mem_vec_9708 = vec_100;



											vec_102 = _mm512_fmadd_ps(vec_101, vec_96, mem_vec_9709);
											mem_vec_9709 = vec_102;
											scal_31 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_104 = _mm512_set1_ps(scal_31);


											vec_103 = _mm512_fmadd_ps(vec_104, vec_94, mem_vec_9710);
											mem_vec_9710 = vec_103;



											vec_105 = _mm512_fmadd_ps(vec_104, vec_96, mem_vec_9711);
											mem_vec_9711 = vec_105;
											scal_32 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_107 = _mm512_set1_ps(scal_32);


											vec_106 = _mm512_fmadd_ps(vec_107, vec_94, mem_vec_9712);
											mem_vec_9712 = vec_106;



											vec_108 = _mm512_fmadd_ps(vec_107, vec_96, mem_vec_9713);
											mem_vec_9713 = vec_108;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
											vec_110 = _mm512_set1_ps(scal_33);


											vec_109 = _mm512_fmadd_ps(vec_110, vec_94, mem_vec_9714);
											mem_vec_9714 = vec_109;



											vec_111 = _mm512_fmadd_ps(vec_110, vec_96, mem_vec_9715);
											mem_vec_9715 = vec_111;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
											vec_113 = _mm512_set1_ps(scal_34);


											vec_112 = _mm512_fmadd_ps(vec_113, vec_94, mem_vec_9716);
											mem_vec_9716 = vec_112;



											vec_114 = _mm512_fmadd_ps(vec_113, vec_96, mem_vec_9717);
											mem_vec_9717 = vec_114;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_116 = _mm512_set1_ps(scal_35);
											vec_117 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_115 = _mm512_fmadd_ps(vec_116, vec_117, mem_vec_9704);
											mem_vec_9704 = vec_115;

											vec_119 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_118 = _mm512_fmadd_ps(vec_116, vec_119, mem_vec_9705);
											mem_vec_9705 = vec_118;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_121 = _mm512_set1_ps(scal_36);


											vec_120 = _mm512_fmadd_ps(vec_121, vec_117, mem_vec_9706);
											mem_vec_9706 = vec_120;



											vec_122 = _mm512_fmadd_ps(vec_121, vec_119, mem_vec_9707);
											mem_vec_9707 = vec_122;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_124 = _mm512_set1_ps(scal_37);


											vec_123 = _mm512_fmadd_ps(vec_124, vec_117, mem_vec_9708);
											mem_vec_9708 = vec_123;



											vec_125 = _mm512_fmadd_ps(vec_124, vec_119, mem_vec_9709);
											mem_vec_9709 = vec_125;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_127 = _mm512_set1_ps(scal_38);


											vec_126 = _mm512_fmadd_ps(vec_127, vec_117, mem_vec_9710);
											mem_vec_9710 = vec_126;



											vec_128 = _mm512_fmadd_ps(vec_127, vec_119, mem_vec_9711);
											mem_vec_9711 = vec_128;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_130 = _mm512_set1_ps(scal_39);


											vec_129 = _mm512_fmadd_ps(vec_130, vec_117, mem_vec_9712);
											mem_vec_9712 = vec_129;



											vec_131 = _mm512_fmadd_ps(vec_130, vec_119, mem_vec_9713);
											mem_vec_9713 = vec_131;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
											vec_133 = _mm512_set1_ps(scal_40);


											vec_132 = _mm512_fmadd_ps(vec_133, vec_117, mem_vec_9714);
											mem_vec_9714 = vec_132;



											vec_134 = _mm512_fmadd_ps(vec_133, vec_119, mem_vec_9715);
											mem_vec_9715 = vec_134;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
											vec_136 = _mm512_set1_ps(scal_41);


											vec_135 = _mm512_fmadd_ps(vec_136, vec_117, mem_vec_9716);
											mem_vec_9716 = vec_135;



											vec_137 = _mm512_fmadd_ps(vec_136, vec_119, mem_vec_9717);
											mem_vec_9717 = vec_137;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_139 = _mm512_set1_ps(scal_42);
											vec_140 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_138 = _mm512_fmadd_ps(vec_139, vec_140, mem_vec_9704);
											mem_vec_9704 = vec_138;

											vec_142 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_141 = _mm512_fmadd_ps(vec_139, vec_142, mem_vec_9705);
											mem_vec_9705 = vec_141;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_144 = _mm512_set1_ps(scal_43);


											vec_143 = _mm512_fmadd_ps(vec_144, vec_140, mem_vec_9706);
											mem_vec_9706 = vec_143;



											vec_145 = _mm512_fmadd_ps(vec_144, vec_142, mem_vec_9707);
											mem_vec_9707 = vec_145;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_147 = _mm512_set1_ps(scal_44);


											vec_146 = _mm512_fmadd_ps(vec_147, vec_140, mem_vec_9708);
											mem_vec_9708 = vec_146;



											vec_148 = _mm512_fmadd_ps(vec_147, vec_142, mem_vec_9709);
											mem_vec_9709 = vec_148;
											scal_45 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_150 = _mm512_set1_ps(scal_45);


											vec_149 = _mm512_fmadd_ps(vec_150, vec_140, mem_vec_9710);
											mem_vec_9710 = vec_149;



											vec_151 = _mm512_fmadd_ps(vec_150, vec_142, mem_vec_9711);
											mem_vec_9711 = vec_151;
											scal_46 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_153 = _mm512_set1_ps(scal_46);


											vec_152 = _mm512_fmadd_ps(vec_153, vec_140, mem_vec_9712);
											mem_vec_9712 = vec_152;



											vec_154 = _mm512_fmadd_ps(vec_153, vec_142, mem_vec_9713);
											mem_vec_9713 = vec_154;
											scal_47 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_156 = _mm512_set1_ps(scal_47);


											vec_155 = _mm512_fmadd_ps(vec_156, vec_140, mem_vec_9714);
											mem_vec_9714 = vec_155;



											vec_157 = _mm512_fmadd_ps(vec_156, vec_142, mem_vec_9715);
											mem_vec_9715 = vec_157;
											scal_48 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_159 = _mm512_set1_ps(scal_48);


											vec_158 = _mm512_fmadd_ps(vec_159, vec_140, mem_vec_9716);
											mem_vec_9716 = vec_158;



											vec_160 = _mm512_fmadd_ps(vec_159, vec_142, mem_vec_9717);
											mem_vec_9717 = vec_160;
											scal_49 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_162 = _mm512_set1_ps(scal_49);
											vec_163 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_161 = _mm512_fmadd_ps(vec_162, vec_163, mem_vec_9704);
											mem_vec_9704 = vec_161;

											vec_165 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_164 = _mm512_fmadd_ps(vec_162, vec_165, mem_vec_9705);
											mem_vec_9705 = vec_164;
											scal_50 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_167 = _mm512_set1_ps(scal_50);


											vec_166 = _mm512_fmadd_ps(vec_167, vec_163, mem_vec_9706);
											mem_vec_9706 = vec_166;



											vec_168 = _mm512_fmadd_ps(vec_167, vec_165, mem_vec_9707);
											mem_vec_9707 = vec_168;
											scal_51 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_170 = _mm512_set1_ps(scal_51);


											vec_169 = _mm512_fmadd_ps(vec_170, vec_163, mem_vec_9708);
											mem_vec_9708 = vec_169;



											vec_171 = _mm512_fmadd_ps(vec_170, vec_165, mem_vec_9709);
											mem_vec_9709 = vec_171;
											scal_52 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_173 = _mm512_set1_ps(scal_52);


											vec_172 = _mm512_fmadd_ps(vec_173, vec_163, mem_vec_9710);
											mem_vec_9710 = vec_172;



											vec_174 = _mm512_fmadd_ps(vec_173, vec_165, mem_vec_9711);
											mem_vec_9711 = vec_174;
											scal_53 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_176 = _mm512_set1_ps(scal_53);


											vec_175 = _mm512_fmadd_ps(vec_176, vec_163, mem_vec_9712);
											mem_vec_9712 = vec_175;



											vec_177 = _mm512_fmadd_ps(vec_176, vec_165, mem_vec_9713);
											mem_vec_9713 = vec_177;
											scal_54 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
											vec_179 = _mm512_set1_ps(scal_54);


											vec_178 = _mm512_fmadd_ps(vec_179, vec_163, mem_vec_9714);
											mem_vec_9714 = vec_178;



											vec_180 = _mm512_fmadd_ps(vec_179, vec_165, mem_vec_9715);
											mem_vec_9715 = vec_180;
											scal_55 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
											vec_182 = _mm512_set1_ps(scal_55);


											vec_181 = _mm512_fmadd_ps(vec_182, vec_163, mem_vec_9716);
											mem_vec_9716 = vec_181;



											vec_183 = _mm512_fmadd_ps(vec_182, vec_165, mem_vec_9717);
											mem_vec_9717 = vec_183;
											scal_56 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_185 = _mm512_set1_ps(scal_56);
											vec_186 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_184 = _mm512_fmadd_ps(vec_185, vec_186, mem_vec_9704);
											mem_vec_9704 = vec_184;

											vec_188 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_187 = _mm512_fmadd_ps(vec_185, vec_188, mem_vec_9705);
											mem_vec_9705 = vec_187;
											scal_57 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_190 = _mm512_set1_ps(scal_57);


											vec_189 = _mm512_fmadd_ps(vec_190, vec_186, mem_vec_9706);
											mem_vec_9706 = vec_189;



											vec_191 = _mm512_fmadd_ps(vec_190, vec_188, mem_vec_9707);
											mem_vec_9707 = vec_191;
											scal_58 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_193 = _mm512_set1_ps(scal_58);


											vec_192 = _mm512_fmadd_ps(vec_193, vec_186, mem_vec_9708);
											mem_vec_9708 = vec_192;



											vec_194 = _mm512_fmadd_ps(vec_193, vec_188, mem_vec_9709);
											mem_vec_9709 = vec_194;
											scal_59 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_196 = _mm512_set1_ps(scal_59);


											vec_195 = _mm512_fmadd_ps(vec_196, vec_186, mem_vec_9710);
											mem_vec_9710 = vec_195;



											vec_197 = _mm512_fmadd_ps(vec_196, vec_188, mem_vec_9711);
											mem_vec_9711 = vec_197;
											scal_60 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_199 = _mm512_set1_ps(scal_60);


											vec_198 = _mm512_fmadd_ps(vec_199, vec_186, mem_vec_9712);
											mem_vec_9712 = vec_198;



											vec_200 = _mm512_fmadd_ps(vec_199, vec_188, mem_vec_9713);
											mem_vec_9713 = vec_200;
											scal_61 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
											vec_202 = _mm512_set1_ps(scal_61);


											vec_201 = _mm512_fmadd_ps(vec_202, vec_186, mem_vec_9714);
											mem_vec_9714 = vec_201;



											vec_203 = _mm512_fmadd_ps(vec_202, vec_188, mem_vec_9715);
											mem_vec_9715 = vec_203;
											scal_62 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
											vec_205 = _mm512_set1_ps(scal_62);


											vec_204 = _mm512_fmadd_ps(vec_205, vec_186, mem_vec_9716);
											mem_vec_9716 = vec_204;



											vec_206 = _mm512_fmadd_ps(vec_205, vec_188, mem_vec_9717);
											mem_vec_9717 = vec_206;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9704);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9705);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9706);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9707);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9708);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9709);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9710);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9711);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9712);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9713);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9714);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9715);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9716);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9717);
							}
						}
						for (y = y704 + 28, yp_0 = 0;
							y < y704 + 28 + 40;
							y += 8, yp_0 += 8){
							// y = ph_y, x = 68, h = 3, w = 3, c = 8, f = 32
							// T (x, 68) (68 / 1)
							for (x = x1088, xp_1 = x1088_p_0, xp_0 = 0;
								x < x1088 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9718 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9719 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_9732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c1056, cp_1 = c1056_p_0, cp_0 = 0;
											c < c1056 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9718);
											mem_vec_9718 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9719);
											mem_vec_9719 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9720);
											mem_vec_9720 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9721);
											mem_vec_9721 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9722);
											mem_vec_9722 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9723);
											mem_vec_9723 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9724);
											mem_vec_9724 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9725);
											mem_vec_9725 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9726);
											mem_vec_9726 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9727);
											mem_vec_9727 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9728);
											mem_vec_9728 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9729);
											mem_vec_9729 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9730);
											mem_vec_9730 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9731);
											mem_vec_9731 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9732);
											mem_vec_9732 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9733);
											mem_vec_9733 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_9718);
											mem_vec_9718 = vec_26;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_9719);
											mem_vec_9719 = vec_29;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_9720);
											mem_vec_9720 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_9721);
											mem_vec_9721 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_9722);
											mem_vec_9722 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_9723);
											mem_vec_9723 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_9724);
											mem_vec_9724 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_9725);
											mem_vec_9725 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_9726);
											mem_vec_9726 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_9727);
											mem_vec_9727 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_9728);
											mem_vec_9728 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_9729);
											mem_vec_9729 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_9730);
											mem_vec_9730 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_9731);
											mem_vec_9731 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_9732);
											mem_vec_9732 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_9733);
											mem_vec_9733 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_53 = _mm512_set1_ps(scal_16);
											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_9718);
											mem_vec_9718 = vec_52;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_9719);
											mem_vec_9719 = vec_55;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_17);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_9720);
											mem_vec_9720 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_9721);
											mem_vec_9721 = vec_59;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_61 = _mm512_set1_ps(scal_18);


											vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_9722);
											mem_vec_9722 = vec_60;



											vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_9723);
											mem_vec_9723 = vec_62;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_9724);
											mem_vec_9724 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_9725);
											mem_vec_9725 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_9726);
											mem_vec_9726 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_9727);
											mem_vec_9727 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_9728);
											mem_vec_9728 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_9729);
											mem_vec_9729 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_9730);
											mem_vec_9730 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_9731);
											mem_vec_9731 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_9732);
											mem_vec_9732 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_9733);
											mem_vec_9733 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_79 = _mm512_set1_ps(scal_24);
											vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_9718);
											mem_vec_9718 = vec_78;

											vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_9719);
											mem_vec_9719 = vec_81;
											scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_84 = _mm512_set1_ps(scal_25);


											vec_83 = _mm512_fmadd_ps(vec_84, vec_80, mem_vec_9720);
											mem_vec_9720 = vec_83;



											vec_85 = _mm512_fmadd_ps(vec_84, vec_82, mem_vec_9721);
											mem_vec_9721 = vec_85;
											scal_26 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_87 = _mm512_set1_ps(scal_26);


											vec_86 = _mm512_fmadd_ps(vec_87, vec_80, mem_vec_9722);
											mem_vec_9722 = vec_86;



											vec_88 = _mm512_fmadd_ps(vec_87, vec_82, mem_vec_9723);
											mem_vec_9723 = vec_88;
											scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_90 = _mm512_set1_ps(scal_27);


											vec_89 = _mm512_fmadd_ps(vec_90, vec_80, mem_vec_9724);
											mem_vec_9724 = vec_89;



											vec_91 = _mm512_fmadd_ps(vec_90, vec_82, mem_vec_9725);
											mem_vec_9725 = vec_91;
											scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_93 = _mm512_set1_ps(scal_28);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_9726);
											mem_vec_9726 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_9727);
											mem_vec_9727 = vec_94;
											scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_96 = _mm512_set1_ps(scal_29);


											vec_95 = _mm512_fmadd_ps(vec_96, vec_80, mem_vec_9728);
											mem_vec_9728 = vec_95;



											vec_97 = _mm512_fmadd_ps(vec_96, vec_82, mem_vec_9729);
											mem_vec_9729 = vec_97;
											scal_30 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_99 = _mm512_set1_ps(scal_30);


											vec_98 = _mm512_fmadd_ps(vec_99, vec_80, mem_vec_9730);
											mem_vec_9730 = vec_98;



											vec_100 = _mm512_fmadd_ps(vec_99, vec_82, mem_vec_9731);
											mem_vec_9731 = vec_100;
											scal_31 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
											vec_102 = _mm512_set1_ps(scal_31);


											vec_101 = _mm512_fmadd_ps(vec_102, vec_80, mem_vec_9732);
											mem_vec_9732 = vec_101;



											vec_103 = _mm512_fmadd_ps(vec_102, vec_82, mem_vec_9733);
											mem_vec_9733 = vec_103;
											scal_32 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_105 = _mm512_set1_ps(scal_32);
											vec_106 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_104 = _mm512_fmadd_ps(vec_105, vec_106, mem_vec_9718);
											mem_vec_9718 = vec_104;

											vec_108 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_107 = _mm512_fmadd_ps(vec_105, vec_108, mem_vec_9719);
											mem_vec_9719 = vec_107;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_110 = _mm512_set1_ps(scal_33);


											vec_109 = _mm512_fmadd_ps(vec_110, vec_106, mem_vec_9720);
											mem_vec_9720 = vec_109;



											vec_111 = _mm512_fmadd_ps(vec_110, vec_108, mem_vec_9721);
											mem_vec_9721 = vec_111;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_113 = _mm512_set1_ps(scal_34);


											vec_112 = _mm512_fmadd_ps(vec_113, vec_106, mem_vec_9722);
											mem_vec_9722 = vec_112;



											vec_114 = _mm512_fmadd_ps(vec_113, vec_108, mem_vec_9723);
											mem_vec_9723 = vec_114;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_116 = _mm512_set1_ps(scal_35);


											vec_115 = _mm512_fmadd_ps(vec_116, vec_106, mem_vec_9724);
											mem_vec_9724 = vec_115;



											vec_117 = _mm512_fmadd_ps(vec_116, vec_108, mem_vec_9725);
											mem_vec_9725 = vec_117;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_119 = _mm512_set1_ps(scal_36);


											vec_118 = _mm512_fmadd_ps(vec_119, vec_106, mem_vec_9726);
											mem_vec_9726 = vec_118;



											vec_120 = _mm512_fmadd_ps(vec_119, vec_108, mem_vec_9727);
											mem_vec_9727 = vec_120;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
											vec_122 = _mm512_set1_ps(scal_37);


											vec_121 = _mm512_fmadd_ps(vec_122, vec_106, mem_vec_9728);
											mem_vec_9728 = vec_121;



											vec_123 = _mm512_fmadd_ps(vec_122, vec_108, mem_vec_9729);
											mem_vec_9729 = vec_123;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
											vec_125 = _mm512_set1_ps(scal_38);


											vec_124 = _mm512_fmadd_ps(vec_125, vec_106, mem_vec_9730);
											mem_vec_9730 = vec_124;



											vec_126 = _mm512_fmadd_ps(vec_125, vec_108, mem_vec_9731);
											mem_vec_9731 = vec_126;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 1) + c];
											vec_128 = _mm512_set1_ps(scal_39);


											vec_127 = _mm512_fmadd_ps(vec_128, vec_106, mem_vec_9732);
											mem_vec_9732 = vec_127;



											vec_129 = _mm512_fmadd_ps(vec_128, vec_108, mem_vec_9733);
											mem_vec_9733 = vec_129;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_131 = _mm512_set1_ps(scal_40);
											vec_132 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_130 = _mm512_fmadd_ps(vec_131, vec_132, mem_vec_9718);
											mem_vec_9718 = vec_130;

											vec_134 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_133 = _mm512_fmadd_ps(vec_131, vec_134, mem_vec_9719);
											mem_vec_9719 = vec_133;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_136 = _mm512_set1_ps(scal_41);


											vec_135 = _mm512_fmadd_ps(vec_136, vec_132, mem_vec_9720);
											mem_vec_9720 = vec_135;



											vec_137 = _mm512_fmadd_ps(vec_136, vec_134, mem_vec_9721);
											mem_vec_9721 = vec_137;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_139 = _mm512_set1_ps(scal_42);


											vec_138 = _mm512_fmadd_ps(vec_139, vec_132, mem_vec_9722);
											mem_vec_9722 = vec_138;



											vec_140 = _mm512_fmadd_ps(vec_139, vec_134, mem_vec_9723);
											mem_vec_9723 = vec_140;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_142 = _mm512_set1_ps(scal_43);


											vec_141 = _mm512_fmadd_ps(vec_142, vec_132, mem_vec_9724);
											mem_vec_9724 = vec_141;



											vec_143 = _mm512_fmadd_ps(vec_142, vec_134, mem_vec_9725);
											mem_vec_9725 = vec_143;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_145 = _mm512_set1_ps(scal_44);


											vec_144 = _mm512_fmadd_ps(vec_145, vec_132, mem_vec_9726);
											mem_vec_9726 = vec_144;



											vec_146 = _mm512_fmadd_ps(vec_145, vec_134, mem_vec_9727);
											mem_vec_9727 = vec_146;
											scal_45 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
											vec_148 = _mm512_set1_ps(scal_45);


											vec_147 = _mm512_fmadd_ps(vec_148, vec_132, mem_vec_9728);
											mem_vec_9728 = vec_147;



											vec_149 = _mm512_fmadd_ps(vec_148, vec_134, mem_vec_9729);
											mem_vec_9729 = vec_149;
											scal_46 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
											vec_151 = _mm512_set1_ps(scal_46);


											vec_150 = _mm512_fmadd_ps(vec_151, vec_132, mem_vec_9730);
											mem_vec_9730 = vec_150;



											vec_152 = _mm512_fmadd_ps(vec_151, vec_134, mem_vec_9731);
											mem_vec_9731 = vec_152;
											scal_47 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 2) + c];
											vec_154 = _mm512_set1_ps(scal_47);


											vec_153 = _mm512_fmadd_ps(vec_154, vec_132, mem_vec_9732);
											mem_vec_9732 = vec_153;



											vec_155 = _mm512_fmadd_ps(vec_154, vec_134, mem_vec_9733);
											mem_vec_9733 = vec_155;
											scal_48 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_157 = _mm512_set1_ps(scal_48);
											vec_158 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_156 = _mm512_fmadd_ps(vec_157, vec_158, mem_vec_9718);
											mem_vec_9718 = vec_156;

											vec_160 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_159 = _mm512_fmadd_ps(vec_157, vec_160, mem_vec_9719);
											mem_vec_9719 = vec_159;
											scal_49 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_162 = _mm512_set1_ps(scal_49);


											vec_161 = _mm512_fmadd_ps(vec_162, vec_158, mem_vec_9720);
											mem_vec_9720 = vec_161;



											vec_163 = _mm512_fmadd_ps(vec_162, vec_160, mem_vec_9721);
											mem_vec_9721 = vec_163;
											scal_50 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_165 = _mm512_set1_ps(scal_50);


											vec_164 = _mm512_fmadd_ps(vec_165, vec_158, mem_vec_9722);
											mem_vec_9722 = vec_164;



											vec_166 = _mm512_fmadd_ps(vec_165, vec_160, mem_vec_9723);
											mem_vec_9723 = vec_166;
											scal_51 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_168 = _mm512_set1_ps(scal_51);


											vec_167 = _mm512_fmadd_ps(vec_168, vec_158, mem_vec_9724);
											mem_vec_9724 = vec_167;



											vec_169 = _mm512_fmadd_ps(vec_168, vec_160, mem_vec_9725);
											mem_vec_9725 = vec_169;
											scal_52 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_171 = _mm512_set1_ps(scal_52);


											vec_170 = _mm512_fmadd_ps(vec_171, vec_158, mem_vec_9726);
											mem_vec_9726 = vec_170;



											vec_172 = _mm512_fmadd_ps(vec_171, vec_160, mem_vec_9727);
											mem_vec_9727 = vec_172;
											scal_53 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_174 = _mm512_set1_ps(scal_53);


											vec_173 = _mm512_fmadd_ps(vec_174, vec_158, mem_vec_9728);
											mem_vec_9728 = vec_173;



											vec_175 = _mm512_fmadd_ps(vec_174, vec_160, mem_vec_9729);
											mem_vec_9729 = vec_175;
											scal_54 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_177 = _mm512_set1_ps(scal_54);


											vec_176 = _mm512_fmadd_ps(vec_177, vec_158, mem_vec_9730);
											mem_vec_9730 = vec_176;



											vec_178 = _mm512_fmadd_ps(vec_177, vec_160, mem_vec_9731);
											mem_vec_9731 = vec_178;
											scal_55 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
											vec_180 = _mm512_set1_ps(scal_55);


											vec_179 = _mm512_fmadd_ps(vec_180, vec_158, mem_vec_9732);
											mem_vec_9732 = vec_179;



											vec_181 = _mm512_fmadd_ps(vec_180, vec_160, mem_vec_9733);
											mem_vec_9733 = vec_181;
											scal_56 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_183 = _mm512_set1_ps(scal_56);
											vec_184 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_182 = _mm512_fmadd_ps(vec_183, vec_184, mem_vec_9718);
											mem_vec_9718 = vec_182;

											vec_186 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_185 = _mm512_fmadd_ps(vec_183, vec_186, mem_vec_9719);
											mem_vec_9719 = vec_185;
											scal_57 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_188 = _mm512_set1_ps(scal_57);


											vec_187 = _mm512_fmadd_ps(vec_188, vec_184, mem_vec_9720);
											mem_vec_9720 = vec_187;



											vec_189 = _mm512_fmadd_ps(vec_188, vec_186, mem_vec_9721);
											mem_vec_9721 = vec_189;
											scal_58 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_191 = _mm512_set1_ps(scal_58);


											vec_190 = _mm512_fmadd_ps(vec_191, vec_184, mem_vec_9722);
											mem_vec_9722 = vec_190;



											vec_192 = _mm512_fmadd_ps(vec_191, vec_186, mem_vec_9723);
											mem_vec_9723 = vec_192;
											scal_59 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_194 = _mm512_set1_ps(scal_59);


											vec_193 = _mm512_fmadd_ps(vec_194, vec_184, mem_vec_9724);
											mem_vec_9724 = vec_193;



											vec_195 = _mm512_fmadd_ps(vec_194, vec_186, mem_vec_9725);
											mem_vec_9725 = vec_195;
											scal_60 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_197 = _mm512_set1_ps(scal_60);


											vec_196 = _mm512_fmadd_ps(vec_197, vec_184, mem_vec_9726);
											mem_vec_9726 = vec_196;



											vec_198 = _mm512_fmadd_ps(vec_197, vec_186, mem_vec_9727);
											mem_vec_9727 = vec_198;
											scal_61 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
											vec_200 = _mm512_set1_ps(scal_61);


											vec_199 = _mm512_fmadd_ps(vec_200, vec_184, mem_vec_9728);
											mem_vec_9728 = vec_199;



											vec_201 = _mm512_fmadd_ps(vec_200, vec_186, mem_vec_9729);
											mem_vec_9729 = vec_201;
											scal_62 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
											vec_203 = _mm512_set1_ps(scal_62);


											vec_202 = _mm512_fmadd_ps(vec_203, vec_184, mem_vec_9730);
											mem_vec_9730 = vec_202;



											vec_204 = _mm512_fmadd_ps(vec_203, vec_186, mem_vec_9731);
											mem_vec_9731 = vec_204;
											scal_63 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 1) + c];
											vec_206 = _mm512_set1_ps(scal_63);


											vec_205 = _mm512_fmadd_ps(vec_206, vec_184, mem_vec_9732);
											mem_vec_9732 = vec_205;



											vec_207 = _mm512_fmadd_ps(vec_206, vec_186, mem_vec_9733);
											mem_vec_9733 = vec_207;
											scal_64 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_209 = _mm512_set1_ps(scal_64);
											vec_210 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_208 = _mm512_fmadd_ps(vec_209, vec_210, mem_vec_9718);
											mem_vec_9718 = vec_208;

											vec_212 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_211 = _mm512_fmadd_ps(vec_209, vec_212, mem_vec_9719);
											mem_vec_9719 = vec_211;
											scal_65 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_214 = _mm512_set1_ps(scal_65);


											vec_213 = _mm512_fmadd_ps(vec_214, vec_210, mem_vec_9720);
											mem_vec_9720 = vec_213;



											vec_215 = _mm512_fmadd_ps(vec_214, vec_212, mem_vec_9721);
											mem_vec_9721 = vec_215;
											scal_66 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_217 = _mm512_set1_ps(scal_66);


											vec_216 = _mm512_fmadd_ps(vec_217, vec_210, mem_vec_9722);
											mem_vec_9722 = vec_216;



											vec_218 = _mm512_fmadd_ps(vec_217, vec_212, mem_vec_9723);
											mem_vec_9723 = vec_218;
											scal_67 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_220 = _mm512_set1_ps(scal_67);


											vec_219 = _mm512_fmadd_ps(vec_220, vec_210, mem_vec_9724);
											mem_vec_9724 = vec_219;



											vec_221 = _mm512_fmadd_ps(vec_220, vec_212, mem_vec_9725);
											mem_vec_9725 = vec_221;
											scal_68 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_223 = _mm512_set1_ps(scal_68);


											vec_222 = _mm512_fmadd_ps(vec_223, vec_210, mem_vec_9726);
											mem_vec_9726 = vec_222;



											vec_224 = _mm512_fmadd_ps(vec_223, vec_212, mem_vec_9727);
											mem_vec_9727 = vec_224;
											scal_69 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
											vec_226 = _mm512_set1_ps(scal_69);


											vec_225 = _mm512_fmadd_ps(vec_226, vec_210, mem_vec_9728);
											mem_vec_9728 = vec_225;



											vec_227 = _mm512_fmadd_ps(vec_226, vec_212, mem_vec_9729);
											mem_vec_9729 = vec_227;
											scal_70 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
											vec_229 = _mm512_set1_ps(scal_70);


											vec_228 = _mm512_fmadd_ps(vec_229, vec_210, mem_vec_9730);
											mem_vec_9730 = vec_228;



											vec_230 = _mm512_fmadd_ps(vec_229, vec_212, mem_vec_9731);
											mem_vec_9731 = vec_230;
											scal_71 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 2) + c];
											vec_232 = _mm512_set1_ps(scal_71);


											vec_231 = _mm512_fmadd_ps(vec_232, vec_210, mem_vec_9732);
											mem_vec_9732 = vec_231;



											vec_233 = _mm512_fmadd_ps(vec_232, vec_212, mem_vec_9733);
											mem_vec_9733 = vec_233;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9718);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9719);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9720);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9721);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9722);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9723);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9724);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9725);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9726);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9727);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9728);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9729);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9730);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9731);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9732);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9733);
							}
						}
				}
			}
		}
	}
}


}