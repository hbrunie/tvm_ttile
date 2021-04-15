#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); U (3, w); T (16, c); Hoist_vars [c];
  T (1, x); Lambda_apply y [((Iter 5), (Arg 11)); ((Iter 1), (Arg 13))];
  T (2, f); T (8, c); T (8, f); T (68, x); T (1, f)]
*/
IND_TYPE c, cp_0, c978_p_0, cp_1, c978, f, fp_0, f1276_p_0, f1277_p_0, fp_1, f1276_p_1, fp_2, f1276, f1277, x, xp_0, x1010_p_0, xp_1, x1010, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y652 = 0;
IND_TYPE x1011 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c979 = 0;
IND_TYPE f1278 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_100 ,scal_101 ,scal_102 ,scal_103 ,scal_104 ,scal_105 ,scal_106 ,scal_107 ,scal_108 ,scal_109 ,scal_11 ,scal_110 ,scal_111 ,scal_112 ,scal_113 ,scal_114 ,scal_115 ,scal_116 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_45 ,scal_46 ,scal_47 ,scal_48 ,scal_49 ,scal_5 ,scal_50 ,scal_51 ,scal_52 ,scal_53 ,scal_54 ,scal_55 ,scal_56 ,scal_57 ,scal_58 ,scal_59 ,scal_6 ,scal_60 ,scal_61 ,scal_62 ,scal_63 ,scal_64 ,scal_65 ,scal_66 ,scal_67 ,scal_68 ,scal_69 ,scal_7 ,scal_70 ,scal_71 ,scal_72 ,scal_73 ,scal_74 ,scal_75 ,scal_76 ,scal_77 ,scal_78 ,scal_79 ,scal_8 ,scal_80 ,scal_81 ,scal_82 ,scal_83 ,scal_84 ,scal_85 ,scal_86 ,scal_87 ,scal_88 ,scal_89 ,scal_9 ,scal_90 ,scal_91 ,scal_92 ,scal_93 ,scal_94 ,scal_95 ,scal_96 ,scal_97 ,scal_98 ,scal_99;
__m512 mem_vec_8902 ,mem_vec_8903 ,mem_vec_8904 ,mem_vec_8905 ,mem_vec_8906 ,mem_vec_8907 ,mem_vec_8908 ,mem_vec_8909 ,mem_vec_8910 ,mem_vec_8911 ,mem_vec_8912 ,mem_vec_8913 ,mem_vec_8914 ,mem_vec_8915 ,mem_vec_8916 ,mem_vec_8917 ,mem_vec_8918 ,mem_vec_8919 ,mem_vec_8920 ,mem_vec_8921 ,mem_vec_8922 ,mem_vec_8923 ,mem_vec_8924 ,mem_vec_8925 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_132 ,vec_133 ,vec_134 ,vec_135 ,vec_136 ,vec_137 ,vec_138 ,vec_139 ,vec_14 ,vec_140 ,vec_141 ,vec_142 ,vec_143 ,vec_144 ,vec_145 ,vec_146 ,vec_147 ,vec_148 ,vec_149 ,vec_15 ,vec_150 ,vec_151 ,vec_152 ,vec_153 ,vec_154 ,vec_155 ,vec_156 ,vec_157 ,vec_158 ,vec_159 ,vec_16 ,vec_160 ,vec_161 ,vec_162 ,vec_163 ,vec_164 ,vec_165 ,vec_166 ,vec_167 ,vec_168 ,vec_169 ,vec_17 ,vec_170 ,vec_171 ,vec_172 ,vec_173 ,vec_174 ,vec_175 ,vec_176 ,vec_177 ,vec_178 ,vec_179 ,vec_18 ,vec_180 ,vec_181 ,vec_182 ,vec_183 ,vec_184 ,vec_185 ,vec_186 ,vec_187 ,vec_188 ,vec_189 ,vec_19 ,vec_190 ,vec_191 ,vec_192 ,vec_193 ,vec_194 ,vec_195 ,vec_196 ,vec_197 ,vec_198 ,vec_199 ,vec_2 ,vec_20 ,vec_200 ,vec_201 ,vec_202 ,vec_203 ,vec_204 ,vec_205 ,vec_206 ,vec_207 ,vec_208 ,vec_209 ,vec_21 ,vec_210 ,vec_211 ,vec_212 ,vec_213 ,vec_214 ,vec_215 ,vec_216 ,vec_217 ,vec_218 ,vec_219 ,vec_22 ,vec_220 ,vec_221 ,vec_222 ,vec_223 ,vec_224 ,vec_225 ,vec_226 ,vec_227 ,vec_228 ,vec_229 ,vec_23 ,vec_230 ,vec_231 ,vec_232 ,vec_233 ,vec_234 ,vec_235 ,vec_236 ,vec_237 ,vec_238 ,vec_239 ,vec_24 ,vec_240 ,vec_241 ,vec_242 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f1277 = f1278, f1277_p_0 = 0;
	f1277 < f1278 + 256;
	f1277 += 256, f1277_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (x, 68) (68 / 1)
	for (x1010 = x1011, x1010_p_0 = 0;
		x1010 < x1011 + 68;
		x1010 += 1, x1010_p_0 += 1){
		// y = 68, x = 1, h = 3, w = 3, c = 128, f = 256
		// T (f, 8) (256 / 32)
		for (f1276 = f1277, f1276_p_1 = f1277_p_0, f1276_p_0 = 0;
			f1276 < f1277 + 256;
			f1276 += 32, f1276_p_1 += 32, f1276_p_0 += 32){
			// y = 68, x = 1, h = 3, w = 3, c = 128, f = 32
			// T (c, 8) (128 / 16)
			for (c978 = c979, c978_p_0 = 0;
				c978 < c979 + 128;
				c978 += 16, c978_p_0 += 16){
				// y = 68, x = 1, h = 3, w = 3, c = 16, f = 32
				// T (f, 2) (32 / 16)
				for (f = f1276, fp_2 = f1276_p_1, fp_1 = f1276_p_0, fp_0 = 0;
					f < f1276 + 32;
					f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
						for (y = y652, yp_0 = 0;
							y < y652 + 55;
							y += 11, yp_0 += 11){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
							// T (x, 1) (1 / 1)
							for (x = x1010, xp_1 = x1010_p_0, xp_0 = 0;
								x < x1010 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8902 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8910 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8911 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
										// T (c, 16) (16 / 1)
										for (c = c978, cp_1 = c978_p_0, cp_0 = 0;
											c < c978 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8902);
											mem_vec_8902 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_8903);
											mem_vec_8903 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8904);
											mem_vec_8904 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_8905);
											mem_vec_8905 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8906);
											mem_vec_8906 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8907);
											mem_vec_8907 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);


											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_8908);
											mem_vec_8908 = vec_13;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_8909);
											mem_vec_8909 = vec_15;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8910);
											mem_vec_8910 = vec_17;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_20 = _mm512_set1_ps(scal_9);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8911);
											mem_vec_8911 = vec_19;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_22 = _mm512_set1_ps(scal_10);


											vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_8912);
											mem_vec_8912 = vec_21;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_24 = _mm512_set1_ps(scal_11);
											vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_8902);
											mem_vec_8902 = vec_23;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_27 = _mm512_set1_ps(scal_12);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_25, mem_vec_8903);
											mem_vec_8903 = vec_26;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_13);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_8904);
											mem_vec_8904 = vec_28;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);


											vec_30 = _mm512_fmadd_ps(vec_31, vec_25, mem_vec_8905);
											mem_vec_8905 = vec_30;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_25, mem_vec_8906);
											mem_vec_8906 = vec_32;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_8907);
											mem_vec_8907 = vec_34;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_25, mem_vec_8908);
											mem_vec_8908 = vec_36;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_18);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_25, mem_vec_8909);
											mem_vec_8909 = vec_38;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_19);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_8910);
											mem_vec_8910 = vec_40;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_43 = _mm512_set1_ps(scal_20);


											vec_42 = _mm512_fmadd_ps(vec_43, vec_25, mem_vec_8911);
											mem_vec_8911 = vec_42;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_45 = _mm512_set1_ps(scal_21);


											vec_44 = _mm512_fmadd_ps(vec_45, vec_25, mem_vec_8912);
											mem_vec_8912 = vec_44;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_47 = _mm512_set1_ps(scal_22);
											vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_8902);
											mem_vec_8902 = vec_46;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_50 = _mm512_set1_ps(scal_23);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_48, mem_vec_8903);
											mem_vec_8903 = vec_49;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_52 = _mm512_set1_ps(scal_24);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_8904);
											mem_vec_8904 = vec_51;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_54 = _mm512_set1_ps(scal_25);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_48, mem_vec_8905);
											mem_vec_8905 = vec_53;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_56 = _mm512_set1_ps(scal_26);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_48, mem_vec_8906);
											mem_vec_8906 = vec_55;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_27);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_8907);
											mem_vec_8907 = vec_57;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_60 = _mm512_set1_ps(scal_28);


											vec_59 = _mm512_fmadd_ps(vec_60, vec_48, mem_vec_8908);
											mem_vec_8908 = vec_59;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_62 = _mm512_set1_ps(scal_29);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_48, mem_vec_8909);
											mem_vec_8909 = vec_61;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_30);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_8910);
											mem_vec_8910 = vec_63;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_66 = _mm512_set1_ps(scal_31);


											vec_65 = _mm512_fmadd_ps(vec_66, vec_48, mem_vec_8911);
											mem_vec_8911 = vec_65;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_32);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_48, mem_vec_8912);
											mem_vec_8912 = vec_67;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_70 = _mm512_set1_ps(scal_33);
											vec_71 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_69 = _mm512_fmadd_ps(vec_70, vec_71, mem_vec_8902);
											mem_vec_8902 = vec_69;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_73 = _mm512_set1_ps(scal_34);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_71, mem_vec_8903);
											mem_vec_8903 = vec_72;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_75 = _mm512_set1_ps(scal_35);


											vec_74 = _mm512_fmadd_ps(vec_75, vec_71, mem_vec_8904);
											mem_vec_8904 = vec_74;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_77 = _mm512_set1_ps(scal_36);


											vec_76 = _mm512_fmadd_ps(vec_77, vec_71, mem_vec_8905);
											mem_vec_8905 = vec_76;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_79 = _mm512_set1_ps(scal_37);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_71, mem_vec_8906);
											mem_vec_8906 = vec_78;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_81 = _mm512_set1_ps(scal_38);


											vec_80 = _mm512_fmadd_ps(vec_81, vec_71, mem_vec_8907);
											mem_vec_8907 = vec_80;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_83 = _mm512_set1_ps(scal_39);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_71, mem_vec_8908);
											mem_vec_8908 = vec_82;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
											vec_85 = _mm512_set1_ps(scal_40);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_71, mem_vec_8909);
											mem_vec_8909 = vec_84;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
											vec_87 = _mm512_set1_ps(scal_41);


											vec_86 = _mm512_fmadd_ps(vec_87, vec_71, mem_vec_8910);
											mem_vec_8910 = vec_86;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
											vec_89 = _mm512_set1_ps(scal_42);


											vec_88 = _mm512_fmadd_ps(vec_89, vec_71, mem_vec_8911);
											mem_vec_8911 = vec_88;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
											vec_91 = _mm512_set1_ps(scal_43);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_71, mem_vec_8912);
											mem_vec_8912 = vec_90;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_93 = _mm512_set1_ps(scal_44);
											vec_94 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_92 = _mm512_fmadd_ps(vec_93, vec_94, mem_vec_8902);
											mem_vec_8902 = vec_92;
											scal_45 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_96 = _mm512_set1_ps(scal_45);


											vec_95 = _mm512_fmadd_ps(vec_96, vec_94, mem_vec_8903);
											mem_vec_8903 = vec_95;
											scal_46 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_98 = _mm512_set1_ps(scal_46);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_94, mem_vec_8904);
											mem_vec_8904 = vec_97;
											scal_47 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_100 = _mm512_set1_ps(scal_47);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_94, mem_vec_8905);
											mem_vec_8905 = vec_99;
											scal_48 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_102 = _mm512_set1_ps(scal_48);


											vec_101 = _mm512_fmadd_ps(vec_102, vec_94, mem_vec_8906);
											mem_vec_8906 = vec_101;
											scal_49 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
											vec_104 = _mm512_set1_ps(scal_49);


											vec_103 = _mm512_fmadd_ps(vec_104, vec_94, mem_vec_8907);
											mem_vec_8907 = vec_103;
											scal_50 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
											vec_106 = _mm512_set1_ps(scal_50);


											vec_105 = _mm512_fmadd_ps(vec_106, vec_94, mem_vec_8908);
											mem_vec_8908 = vec_105;
											scal_51 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 1) + c];
											vec_108 = _mm512_set1_ps(scal_51);


											vec_107 = _mm512_fmadd_ps(vec_108, vec_94, mem_vec_8909);
											mem_vec_8909 = vec_107;
											scal_52 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 1) + c];
											vec_110 = _mm512_set1_ps(scal_52);


											vec_109 = _mm512_fmadd_ps(vec_110, vec_94, mem_vec_8910);
											mem_vec_8910 = vec_109;
											scal_53 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 1) + c];
											vec_112 = _mm512_set1_ps(scal_53);


											vec_111 = _mm512_fmadd_ps(vec_112, vec_94, mem_vec_8911);
											mem_vec_8911 = vec_111;
											scal_54 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 1) + c];
											vec_114 = _mm512_set1_ps(scal_54);


											vec_113 = _mm512_fmadd_ps(vec_114, vec_94, mem_vec_8912);
											mem_vec_8912 = vec_113;
											scal_55 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_116 = _mm512_set1_ps(scal_55);
											vec_117 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_115 = _mm512_fmadd_ps(vec_116, vec_117, mem_vec_8902);
											mem_vec_8902 = vec_115;
											scal_56 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_119 = _mm512_set1_ps(scal_56);


											vec_118 = _mm512_fmadd_ps(vec_119, vec_117, mem_vec_8903);
											mem_vec_8903 = vec_118;
											scal_57 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_121 = _mm512_set1_ps(scal_57);


											vec_120 = _mm512_fmadd_ps(vec_121, vec_117, mem_vec_8904);
											mem_vec_8904 = vec_120;
											scal_58 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_123 = _mm512_set1_ps(scal_58);


											vec_122 = _mm512_fmadd_ps(vec_123, vec_117, mem_vec_8905);
											mem_vec_8905 = vec_122;
											scal_59 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_125 = _mm512_set1_ps(scal_59);


											vec_124 = _mm512_fmadd_ps(vec_125, vec_117, mem_vec_8906);
											mem_vec_8906 = vec_124;
											scal_60 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
											vec_127 = _mm512_set1_ps(scal_60);


											vec_126 = _mm512_fmadd_ps(vec_127, vec_117, mem_vec_8907);
											mem_vec_8907 = vec_126;
											scal_61 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
											vec_129 = _mm512_set1_ps(scal_61);


											vec_128 = _mm512_fmadd_ps(vec_129, vec_117, mem_vec_8908);
											mem_vec_8908 = vec_128;
											scal_62 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 2) + c];
											vec_131 = _mm512_set1_ps(scal_62);


											vec_130 = _mm512_fmadd_ps(vec_131, vec_117, mem_vec_8909);
											mem_vec_8909 = vec_130;
											scal_63 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 2) + c];
											vec_133 = _mm512_set1_ps(scal_63);


											vec_132 = _mm512_fmadd_ps(vec_133, vec_117, mem_vec_8910);
											mem_vec_8910 = vec_132;
											scal_64 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 2) + c];
											vec_135 = _mm512_set1_ps(scal_64);


											vec_134 = _mm512_fmadd_ps(vec_135, vec_117, mem_vec_8911);
											mem_vec_8911 = vec_134;
											scal_65 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 2) + c];
											vec_137 = _mm512_set1_ps(scal_65);


											vec_136 = _mm512_fmadd_ps(vec_137, vec_117, mem_vec_8912);
											mem_vec_8912 = vec_136;
											scal_66 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_139 = _mm512_set1_ps(scal_66);
											vec_140 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_138 = _mm512_fmadd_ps(vec_139, vec_140, mem_vec_8902);
											mem_vec_8902 = vec_138;
											scal_67 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_142 = _mm512_set1_ps(scal_67);


											vec_141 = _mm512_fmadd_ps(vec_142, vec_140, mem_vec_8903);
											mem_vec_8903 = vec_141;
											scal_68 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_144 = _mm512_set1_ps(scal_68);


											vec_143 = _mm512_fmadd_ps(vec_144, vec_140, mem_vec_8904);
											mem_vec_8904 = vec_143;
											scal_69 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_146 = _mm512_set1_ps(scal_69);


											vec_145 = _mm512_fmadd_ps(vec_146, vec_140, mem_vec_8905);
											mem_vec_8905 = vec_145;
											scal_70 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_148 = _mm512_set1_ps(scal_70);


											vec_147 = _mm512_fmadd_ps(vec_148, vec_140, mem_vec_8906);
											mem_vec_8906 = vec_147;
											scal_71 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_150 = _mm512_set1_ps(scal_71);


											vec_149 = _mm512_fmadd_ps(vec_150, vec_140, mem_vec_8907);
											mem_vec_8907 = vec_149;
											scal_72 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_152 = _mm512_set1_ps(scal_72);


											vec_151 = _mm512_fmadd_ps(vec_152, vec_140, mem_vec_8908);
											mem_vec_8908 = vec_151;
											scal_73 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
											vec_154 = _mm512_set1_ps(scal_73);


											vec_153 = _mm512_fmadd_ps(vec_154, vec_140, mem_vec_8909);
											mem_vec_8909 = vec_153;
											scal_74 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
											vec_156 = _mm512_set1_ps(scal_74);


											vec_155 = _mm512_fmadd_ps(vec_156, vec_140, mem_vec_8910);
											mem_vec_8910 = vec_155;
											scal_75 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
											vec_158 = _mm512_set1_ps(scal_75);


											vec_157 = _mm512_fmadd_ps(vec_158, vec_140, mem_vec_8911);
											mem_vec_8911 = vec_157;
											scal_76 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
											vec_160 = _mm512_set1_ps(scal_76);


											vec_159 = _mm512_fmadd_ps(vec_160, vec_140, mem_vec_8912);
											mem_vec_8912 = vec_159;
											scal_77 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_162 = _mm512_set1_ps(scal_77);
											vec_163 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_161 = _mm512_fmadd_ps(vec_162, vec_163, mem_vec_8902);
											mem_vec_8902 = vec_161;
											scal_78 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_165 = _mm512_set1_ps(scal_78);


											vec_164 = _mm512_fmadd_ps(vec_165, vec_163, mem_vec_8903);
											mem_vec_8903 = vec_164;
											scal_79 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_167 = _mm512_set1_ps(scal_79);


											vec_166 = _mm512_fmadd_ps(vec_167, vec_163, mem_vec_8904);
											mem_vec_8904 = vec_166;
											scal_80 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_169 = _mm512_set1_ps(scal_80);


											vec_168 = _mm512_fmadd_ps(vec_169, vec_163, mem_vec_8905);
											mem_vec_8905 = vec_168;
											scal_81 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_171 = _mm512_set1_ps(scal_81);


											vec_170 = _mm512_fmadd_ps(vec_171, vec_163, mem_vec_8906);
											mem_vec_8906 = vec_170;
											scal_82 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
											vec_173 = _mm512_set1_ps(scal_82);


											vec_172 = _mm512_fmadd_ps(vec_173, vec_163, mem_vec_8907);
											mem_vec_8907 = vec_172;
											scal_83 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
											vec_175 = _mm512_set1_ps(scal_83);


											vec_174 = _mm512_fmadd_ps(vec_175, vec_163, mem_vec_8908);
											mem_vec_8908 = vec_174;
											scal_84 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 1) + c];
											vec_177 = _mm512_set1_ps(scal_84);


											vec_176 = _mm512_fmadd_ps(vec_177, vec_163, mem_vec_8909);
											mem_vec_8909 = vec_176;
											scal_85 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 1) + c];
											vec_179 = _mm512_set1_ps(scal_85);


											vec_178 = _mm512_fmadd_ps(vec_179, vec_163, mem_vec_8910);
											mem_vec_8910 = vec_178;
											scal_86 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 1) + c];
											vec_181 = _mm512_set1_ps(scal_86);


											vec_180 = _mm512_fmadd_ps(vec_181, vec_163, mem_vec_8911);
											mem_vec_8911 = vec_180;
											scal_87 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 1) + c];
											vec_183 = _mm512_set1_ps(scal_87);


											vec_182 = _mm512_fmadd_ps(vec_183, vec_163, mem_vec_8912);
											mem_vec_8912 = vec_182;
											scal_88 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_185 = _mm512_set1_ps(scal_88);
											vec_186 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_184 = _mm512_fmadd_ps(vec_185, vec_186, mem_vec_8902);
											mem_vec_8902 = vec_184;
											scal_89 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_188 = _mm512_set1_ps(scal_89);


											vec_187 = _mm512_fmadd_ps(vec_188, vec_186, mem_vec_8903);
											mem_vec_8903 = vec_187;
											scal_90 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_190 = _mm512_set1_ps(scal_90);


											vec_189 = _mm512_fmadd_ps(vec_190, vec_186, mem_vec_8904);
											mem_vec_8904 = vec_189;
											scal_91 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_192 = _mm512_set1_ps(scal_91);


											vec_191 = _mm512_fmadd_ps(vec_192, vec_186, mem_vec_8905);
											mem_vec_8905 = vec_191;
											scal_92 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_194 = _mm512_set1_ps(scal_92);


											vec_193 = _mm512_fmadd_ps(vec_194, vec_186, mem_vec_8906);
											mem_vec_8906 = vec_193;
											scal_93 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
											vec_196 = _mm512_set1_ps(scal_93);


											vec_195 = _mm512_fmadd_ps(vec_196, vec_186, mem_vec_8907);
											mem_vec_8907 = vec_195;
											scal_94 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
											vec_198 = _mm512_set1_ps(scal_94);


											vec_197 = _mm512_fmadd_ps(vec_198, vec_186, mem_vec_8908);
											mem_vec_8908 = vec_197;
											scal_95 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 2) + c];
											vec_200 = _mm512_set1_ps(scal_95);


											vec_199 = _mm512_fmadd_ps(vec_200, vec_186, mem_vec_8909);
											mem_vec_8909 = vec_199;
											scal_96 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 2) + c];
											vec_202 = _mm512_set1_ps(scal_96);


											vec_201 = _mm512_fmadd_ps(vec_202, vec_186, mem_vec_8910);
											mem_vec_8910 = vec_201;
											scal_97 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 2) + c];
											vec_204 = _mm512_set1_ps(scal_97);


											vec_203 = _mm512_fmadd_ps(vec_204, vec_186, mem_vec_8911);
											mem_vec_8911 = vec_203;
											scal_98 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 2) + c];
											vec_206 = _mm512_set1_ps(scal_98);


											vec_205 = _mm512_fmadd_ps(vec_206, vec_186, mem_vec_8912);
											mem_vec_8912 = vec_205;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8902);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8903);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8904);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8905);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8906);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8907);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8908);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8909);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8910);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8911);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8912);
							}
						}
						for (y = y652 + 55, yp_0 = 0;
							y < y652 + 55 + 13;
							y += 13, yp_0 += 13){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
							// T (x, 1) (1 / 1)
							for (x = x1010, xp_1 = x1010_p_0, xp_0 = 0;
								x < x1010 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8913 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_8924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_8925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
										// T (c, 16) (16 / 1)
										for (c = c978, cp_1 = c978_p_0, cp_0 = 0;
											c < c978 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8913);
											mem_vec_8913 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_8914);
											mem_vec_8914 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8915);
											mem_vec_8915 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_8916);
											mem_vec_8916 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8917);
											mem_vec_8917 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8918);
											mem_vec_8918 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);


											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_8919);
											mem_vec_8919 = vec_13;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_8920);
											mem_vec_8920 = vec_15;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8921);
											mem_vec_8921 = vec_17;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_20 = _mm512_set1_ps(scal_9);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8922);
											mem_vec_8922 = vec_19;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_22 = _mm512_set1_ps(scal_10);


											vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_8923);
											mem_vec_8923 = vec_21;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_24 = _mm512_set1_ps(scal_11);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8924);
											mem_vec_8924 = vec_23;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_26 = _mm512_set1_ps(scal_12);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_2, mem_vec_8925);
											mem_vec_8925 = vec_25;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_28 = _mm512_set1_ps(scal_13);
											vec_29 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_27 = _mm512_fmadd_ps(vec_28, vec_29, mem_vec_8913);
											mem_vec_8913 = vec_27;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);


											vec_30 = _mm512_fmadd_ps(vec_31, vec_29, mem_vec_8914);
											mem_vec_8914 = vec_30;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_29, mem_vec_8915);
											mem_vec_8915 = vec_32;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_29, mem_vec_8916);
											mem_vec_8916 = vec_34;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_29, mem_vec_8917);
											mem_vec_8917 = vec_36;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_18);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_29, mem_vec_8918);
											mem_vec_8918 = vec_38;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_19);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_29, mem_vec_8919);
											mem_vec_8919 = vec_40;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_43 = _mm512_set1_ps(scal_20);


											vec_42 = _mm512_fmadd_ps(vec_43, vec_29, mem_vec_8920);
											mem_vec_8920 = vec_42;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_45 = _mm512_set1_ps(scal_21);


											vec_44 = _mm512_fmadd_ps(vec_45, vec_29, mem_vec_8921);
											mem_vec_8921 = vec_44;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_22);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_29, mem_vec_8922);
											mem_vec_8922 = vec_46;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_23);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_29, mem_vec_8923);
											mem_vec_8923 = vec_48;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
											vec_51 = _mm512_set1_ps(scal_24);


											vec_50 = _mm512_fmadd_ps(vec_51, vec_29, mem_vec_8924);
											mem_vec_8924 = vec_50;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_25);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_29, mem_vec_8925);
											mem_vec_8925 = vec_52;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_55 = _mm512_set1_ps(scal_26);
											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_54 = _mm512_fmadd_ps(vec_55, vec_56, mem_vec_8913);
											mem_vec_8913 = vec_54;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_27);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_8914);
											mem_vec_8914 = vec_57;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_60 = _mm512_set1_ps(scal_28);


											vec_59 = _mm512_fmadd_ps(vec_60, vec_56, mem_vec_8915);
											mem_vec_8915 = vec_59;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_62 = _mm512_set1_ps(scal_29);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_56, mem_vec_8916);
											mem_vec_8916 = vec_61;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_30);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_8917);
											mem_vec_8917 = vec_63;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_66 = _mm512_set1_ps(scal_31);


											vec_65 = _mm512_fmadd_ps(vec_66, vec_56, mem_vec_8918);
											mem_vec_8918 = vec_65;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_32);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_8919);
											mem_vec_8919 = vec_67;
											scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_33);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_8920);
											mem_vec_8920 = vec_69;
											scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_72 = _mm512_set1_ps(scal_34);


											vec_71 = _mm512_fmadd_ps(vec_72, vec_56, mem_vec_8921);
											mem_vec_8921 = vec_71;
											scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_74 = _mm512_set1_ps(scal_35);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_56, mem_vec_8922);
											mem_vec_8922 = vec_73;
											scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_36);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_8923);
											mem_vec_8923 = vec_75;
											scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_37);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_56, mem_vec_8924);
											mem_vec_8924 = vec_77;
											scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
											vec_80 = _mm512_set1_ps(scal_38);


											vec_79 = _mm512_fmadd_ps(vec_80, vec_56, mem_vec_8925);
											mem_vec_8925 = vec_79;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_82 = _mm512_set1_ps(scal_39);
											vec_83 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_81 = _mm512_fmadd_ps(vec_82, vec_83, mem_vec_8913);
											mem_vec_8913 = vec_81;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_85 = _mm512_set1_ps(scal_40);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_83, mem_vec_8914);
											mem_vec_8914 = vec_84;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_87 = _mm512_set1_ps(scal_41);


											vec_86 = _mm512_fmadd_ps(vec_87, vec_83, mem_vec_8915);
											mem_vec_8915 = vec_86;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_89 = _mm512_set1_ps(scal_42);


											vec_88 = _mm512_fmadd_ps(vec_89, vec_83, mem_vec_8916);
											mem_vec_8916 = vec_88;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_91 = _mm512_set1_ps(scal_43);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_83, mem_vec_8917);
											mem_vec_8917 = vec_90;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_93 = _mm512_set1_ps(scal_44);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_83, mem_vec_8918);
											mem_vec_8918 = vec_92;
											scal_45 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_95 = _mm512_set1_ps(scal_45);


											vec_94 = _mm512_fmadd_ps(vec_95, vec_83, mem_vec_8919);
											mem_vec_8919 = vec_94;
											scal_46 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
											vec_97 = _mm512_set1_ps(scal_46);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_83, mem_vec_8920);
											mem_vec_8920 = vec_96;
											scal_47 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
											vec_99 = _mm512_set1_ps(scal_47);


											vec_98 = _mm512_fmadd_ps(vec_99, vec_83, mem_vec_8921);
											mem_vec_8921 = vec_98;
											scal_48 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
											vec_101 = _mm512_set1_ps(scal_48);


											vec_100 = _mm512_fmadd_ps(vec_101, vec_83, mem_vec_8922);
											mem_vec_8922 = vec_100;
											scal_49 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
											vec_103 = _mm512_set1_ps(scal_49);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_83, mem_vec_8923);
											mem_vec_8923 = vec_102;
											scal_50 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h) + c];
											vec_105 = _mm512_set1_ps(scal_50);


											vec_104 = _mm512_fmadd_ps(vec_105, vec_83, mem_vec_8924);
											mem_vec_8924 = vec_104;
											scal_51 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 12 + h) + c];
											vec_107 = _mm512_set1_ps(scal_51);


											vec_106 = _mm512_fmadd_ps(vec_107, vec_83, mem_vec_8925);
											mem_vec_8925 = vec_106;
											scal_52 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_109 = _mm512_set1_ps(scal_52);
											vec_110 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_108 = _mm512_fmadd_ps(vec_109, vec_110, mem_vec_8913);
											mem_vec_8913 = vec_108;
											scal_53 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_112 = _mm512_set1_ps(scal_53);


											vec_111 = _mm512_fmadd_ps(vec_112, vec_110, mem_vec_8914);
											mem_vec_8914 = vec_111;
											scal_54 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_114 = _mm512_set1_ps(scal_54);


											vec_113 = _mm512_fmadd_ps(vec_114, vec_110, mem_vec_8915);
											mem_vec_8915 = vec_113;
											scal_55 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_116 = _mm512_set1_ps(scal_55);


											vec_115 = _mm512_fmadd_ps(vec_116, vec_110, mem_vec_8916);
											mem_vec_8916 = vec_115;
											scal_56 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_118 = _mm512_set1_ps(scal_56);


											vec_117 = _mm512_fmadd_ps(vec_118, vec_110, mem_vec_8917);
											mem_vec_8917 = vec_117;
											scal_57 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
											vec_120 = _mm512_set1_ps(scal_57);


											vec_119 = _mm512_fmadd_ps(vec_120, vec_110, mem_vec_8918);
											mem_vec_8918 = vec_119;
											scal_58 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
											vec_122 = _mm512_set1_ps(scal_58);


											vec_121 = _mm512_fmadd_ps(vec_122, vec_110, mem_vec_8919);
											mem_vec_8919 = vec_121;
											scal_59 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 1) + c];
											vec_124 = _mm512_set1_ps(scal_59);


											vec_123 = _mm512_fmadd_ps(vec_124, vec_110, mem_vec_8920);
											mem_vec_8920 = vec_123;
											scal_60 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 1) + c];
											vec_126 = _mm512_set1_ps(scal_60);


											vec_125 = _mm512_fmadd_ps(vec_126, vec_110, mem_vec_8921);
											mem_vec_8921 = vec_125;
											scal_61 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 1) + c];
											vec_128 = _mm512_set1_ps(scal_61);


											vec_127 = _mm512_fmadd_ps(vec_128, vec_110, mem_vec_8922);
											mem_vec_8922 = vec_127;
											scal_62 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 1) + c];
											vec_130 = _mm512_set1_ps(scal_62);


											vec_129 = _mm512_fmadd_ps(vec_130, vec_110, mem_vec_8923);
											mem_vec_8923 = vec_129;
											scal_63 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h + 1) + c];
											vec_132 = _mm512_set1_ps(scal_63);


											vec_131 = _mm512_fmadd_ps(vec_132, vec_110, mem_vec_8924);
											mem_vec_8924 = vec_131;
											scal_64 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 12 + h + 1) + c];
											vec_134 = _mm512_set1_ps(scal_64);


											vec_133 = _mm512_fmadd_ps(vec_134, vec_110, mem_vec_8925);
											mem_vec_8925 = vec_133;
											scal_65 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_136 = _mm512_set1_ps(scal_65);
											vec_137 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_135 = _mm512_fmadd_ps(vec_136, vec_137, mem_vec_8913);
											mem_vec_8913 = vec_135;
											scal_66 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_139 = _mm512_set1_ps(scal_66);


											vec_138 = _mm512_fmadd_ps(vec_139, vec_137, mem_vec_8914);
											mem_vec_8914 = vec_138;
											scal_67 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_141 = _mm512_set1_ps(scal_67);


											vec_140 = _mm512_fmadd_ps(vec_141, vec_137, mem_vec_8915);
											mem_vec_8915 = vec_140;
											scal_68 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_143 = _mm512_set1_ps(scal_68);


											vec_142 = _mm512_fmadd_ps(vec_143, vec_137, mem_vec_8916);
											mem_vec_8916 = vec_142;
											scal_69 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_145 = _mm512_set1_ps(scal_69);


											vec_144 = _mm512_fmadd_ps(vec_145, vec_137, mem_vec_8917);
											mem_vec_8917 = vec_144;
											scal_70 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
											vec_147 = _mm512_set1_ps(scal_70);


											vec_146 = _mm512_fmadd_ps(vec_147, vec_137, mem_vec_8918);
											mem_vec_8918 = vec_146;
											scal_71 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
											vec_149 = _mm512_set1_ps(scal_71);


											vec_148 = _mm512_fmadd_ps(vec_149, vec_137, mem_vec_8919);
											mem_vec_8919 = vec_148;
											scal_72 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 2) + c];
											vec_151 = _mm512_set1_ps(scal_72);


											vec_150 = _mm512_fmadd_ps(vec_151, vec_137, mem_vec_8920);
											mem_vec_8920 = vec_150;
											scal_73 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 2) + c];
											vec_153 = _mm512_set1_ps(scal_73);


											vec_152 = _mm512_fmadd_ps(vec_153, vec_137, mem_vec_8921);
											mem_vec_8921 = vec_152;
											scal_74 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h + 2) + c];
											vec_155 = _mm512_set1_ps(scal_74);


											vec_154 = _mm512_fmadd_ps(vec_155, vec_137, mem_vec_8922);
											mem_vec_8922 = vec_154;
											scal_75 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h + 2) + c];
											vec_157 = _mm512_set1_ps(scal_75);


											vec_156 = _mm512_fmadd_ps(vec_157, vec_137, mem_vec_8923);
											mem_vec_8923 = vec_156;
											scal_76 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h + 2) + c];
											vec_159 = _mm512_set1_ps(scal_76);


											vec_158 = _mm512_fmadd_ps(vec_159, vec_137, mem_vec_8924);
											mem_vec_8924 = vec_158;
											scal_77 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 12 + h + 2) + c];
											vec_161 = _mm512_set1_ps(scal_77);


											vec_160 = _mm512_fmadd_ps(vec_161, vec_137, mem_vec_8925);
											mem_vec_8925 = vec_160;
											scal_78 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_163 = _mm512_set1_ps(scal_78);
											vec_164 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_162 = _mm512_fmadd_ps(vec_163, vec_164, mem_vec_8913);
											mem_vec_8913 = vec_162;
											scal_79 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_166 = _mm512_set1_ps(scal_79);


											vec_165 = _mm512_fmadd_ps(vec_166, vec_164, mem_vec_8914);
											mem_vec_8914 = vec_165;
											scal_80 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_168 = _mm512_set1_ps(scal_80);


											vec_167 = _mm512_fmadd_ps(vec_168, vec_164, mem_vec_8915);
											mem_vec_8915 = vec_167;
											scal_81 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_170 = _mm512_set1_ps(scal_81);


											vec_169 = _mm512_fmadd_ps(vec_170, vec_164, mem_vec_8916);
											mem_vec_8916 = vec_169;
											scal_82 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_172 = _mm512_set1_ps(scal_82);


											vec_171 = _mm512_fmadd_ps(vec_172, vec_164, mem_vec_8917);
											mem_vec_8917 = vec_171;
											scal_83 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_174 = _mm512_set1_ps(scal_83);


											vec_173 = _mm512_fmadd_ps(vec_174, vec_164, mem_vec_8918);
											mem_vec_8918 = vec_173;
											scal_84 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_176 = _mm512_set1_ps(scal_84);


											vec_175 = _mm512_fmadd_ps(vec_176, vec_164, mem_vec_8919);
											mem_vec_8919 = vec_175;
											scal_85 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
											vec_178 = _mm512_set1_ps(scal_85);


											vec_177 = _mm512_fmadd_ps(vec_178, vec_164, mem_vec_8920);
											mem_vec_8920 = vec_177;
											scal_86 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
											vec_180 = _mm512_set1_ps(scal_86);


											vec_179 = _mm512_fmadd_ps(vec_180, vec_164, mem_vec_8921);
											mem_vec_8921 = vec_179;
											scal_87 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
											vec_182 = _mm512_set1_ps(scal_87);


											vec_181 = _mm512_fmadd_ps(vec_182, vec_164, mem_vec_8922);
											mem_vec_8922 = vec_181;
											scal_88 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
											vec_184 = _mm512_set1_ps(scal_88);


											vec_183 = _mm512_fmadd_ps(vec_184, vec_164, mem_vec_8923);
											mem_vec_8923 = vec_183;
											scal_89 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h) + c];
											vec_186 = _mm512_set1_ps(scal_89);


											vec_185 = _mm512_fmadd_ps(vec_186, vec_164, mem_vec_8924);
											mem_vec_8924 = vec_185;
											scal_90 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 12 + h) + c];
											vec_188 = _mm512_set1_ps(scal_90);


											vec_187 = _mm512_fmadd_ps(vec_188, vec_164, mem_vec_8925);
											mem_vec_8925 = vec_187;
											scal_91 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_190 = _mm512_set1_ps(scal_91);
											vec_191 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_189 = _mm512_fmadd_ps(vec_190, vec_191, mem_vec_8913);
											mem_vec_8913 = vec_189;
											scal_92 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_193 = _mm512_set1_ps(scal_92);


											vec_192 = _mm512_fmadd_ps(vec_193, vec_191, mem_vec_8914);
											mem_vec_8914 = vec_192;
											scal_93 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_195 = _mm512_set1_ps(scal_93);


											vec_194 = _mm512_fmadd_ps(vec_195, vec_191, mem_vec_8915);
											mem_vec_8915 = vec_194;
											scal_94 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_197 = _mm512_set1_ps(scal_94);


											vec_196 = _mm512_fmadd_ps(vec_197, vec_191, mem_vec_8916);
											mem_vec_8916 = vec_196;
											scal_95 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_199 = _mm512_set1_ps(scal_95);


											vec_198 = _mm512_fmadd_ps(vec_199, vec_191, mem_vec_8917);
											mem_vec_8917 = vec_198;
											scal_96 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
											vec_201 = _mm512_set1_ps(scal_96);


											vec_200 = _mm512_fmadd_ps(vec_201, vec_191, mem_vec_8918);
											mem_vec_8918 = vec_200;
											scal_97 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
											vec_203 = _mm512_set1_ps(scal_97);


											vec_202 = _mm512_fmadd_ps(vec_203, vec_191, mem_vec_8919);
											mem_vec_8919 = vec_202;
											scal_98 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 1) + c];
											vec_205 = _mm512_set1_ps(scal_98);


											vec_204 = _mm512_fmadd_ps(vec_205, vec_191, mem_vec_8920);
											mem_vec_8920 = vec_204;
											scal_99 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 1) + c];
											vec_207 = _mm512_set1_ps(scal_99);


											vec_206 = _mm512_fmadd_ps(vec_207, vec_191, mem_vec_8921);
											mem_vec_8921 = vec_206;
											scal_100 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 1) + c];
											vec_209 = _mm512_set1_ps(scal_100);


											vec_208 = _mm512_fmadd_ps(vec_209, vec_191, mem_vec_8922);
											mem_vec_8922 = vec_208;
											scal_101 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 1) + c];
											vec_211 = _mm512_set1_ps(scal_101);


											vec_210 = _mm512_fmadd_ps(vec_211, vec_191, mem_vec_8923);
											mem_vec_8923 = vec_210;
											scal_102 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h + 1) + c];
											vec_213 = _mm512_set1_ps(scal_102);


											vec_212 = _mm512_fmadd_ps(vec_213, vec_191, mem_vec_8924);
											mem_vec_8924 = vec_212;
											scal_103 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 12 + h + 1) + c];
											vec_215 = _mm512_set1_ps(scal_103);


											vec_214 = _mm512_fmadd_ps(vec_215, vec_191, mem_vec_8925);
											mem_vec_8925 = vec_214;
											scal_104 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_217 = _mm512_set1_ps(scal_104);
											vec_218 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_216 = _mm512_fmadd_ps(vec_217, vec_218, mem_vec_8913);
											mem_vec_8913 = vec_216;
											scal_105 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_220 = _mm512_set1_ps(scal_105);


											vec_219 = _mm512_fmadd_ps(vec_220, vec_218, mem_vec_8914);
											mem_vec_8914 = vec_219;
											scal_106 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_222 = _mm512_set1_ps(scal_106);


											vec_221 = _mm512_fmadd_ps(vec_222, vec_218, mem_vec_8915);
											mem_vec_8915 = vec_221;
											scal_107 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_224 = _mm512_set1_ps(scal_107);


											vec_223 = _mm512_fmadd_ps(vec_224, vec_218, mem_vec_8916);
											mem_vec_8916 = vec_223;
											scal_108 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_226 = _mm512_set1_ps(scal_108);


											vec_225 = _mm512_fmadd_ps(vec_226, vec_218, mem_vec_8917);
											mem_vec_8917 = vec_225;
											scal_109 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
											vec_228 = _mm512_set1_ps(scal_109);


											vec_227 = _mm512_fmadd_ps(vec_228, vec_218, mem_vec_8918);
											mem_vec_8918 = vec_227;
											scal_110 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
											vec_230 = _mm512_set1_ps(scal_110);


											vec_229 = _mm512_fmadd_ps(vec_230, vec_218, mem_vec_8919);
											mem_vec_8919 = vec_229;
											scal_111 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 2) + c];
											vec_232 = _mm512_set1_ps(scal_111);


											vec_231 = _mm512_fmadd_ps(vec_232, vec_218, mem_vec_8920);
											mem_vec_8920 = vec_231;
											scal_112 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 2) + c];
											vec_234 = _mm512_set1_ps(scal_112);


											vec_233 = _mm512_fmadd_ps(vec_234, vec_218, mem_vec_8921);
											mem_vec_8921 = vec_233;
											scal_113 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h + 2) + c];
											vec_236 = _mm512_set1_ps(scal_113);


											vec_235 = _mm512_fmadd_ps(vec_236, vec_218, mem_vec_8922);
											mem_vec_8922 = vec_235;
											scal_114 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h + 2) + c];
											vec_238 = _mm512_set1_ps(scal_114);


											vec_237 = _mm512_fmadd_ps(vec_238, vec_218, mem_vec_8923);
											mem_vec_8923 = vec_237;
											scal_115 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h + 2) + c];
											vec_240 = _mm512_set1_ps(scal_115);


											vec_239 = _mm512_fmadd_ps(vec_240, vec_218, mem_vec_8924);
											mem_vec_8924 = vec_239;
											scal_116 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 12 + h + 2) + c];
											vec_242 = _mm512_set1_ps(scal_116);


											vec_241 = _mm512_fmadd_ps(vec_242, vec_218, mem_vec_8925);
											mem_vec_8925 = vec_241;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8913);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8914);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8915);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8916);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8917);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8918);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8919);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8920);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8921);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8922);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8923);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8924);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_8925);
							}
						}
				}
			}
		}
	}
}


}