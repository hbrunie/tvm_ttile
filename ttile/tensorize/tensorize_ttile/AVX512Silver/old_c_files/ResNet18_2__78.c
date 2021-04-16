#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); U (3, h); U (3, w); T (32, c); Hoist_vars [c];
  T (28, x); T (2, c); T (2, f); T (2, x); T (8, y); T (1, x)]
*/
IND_TYPE c, cp_0, c552_p_0, cp_1, c552, f, fp_0, x, xp_0, x630_p_0, x631_p_0, xp_1, x630_p_1, xp_2, x630, x631, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y468 = 0;
IND_TYPE x632 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c553 = 0;
IND_TYPE f345 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_45 ,scal_46 ,scal_47 ,scal_48 ,scal_49 ,scal_5 ,scal_50 ,scal_51 ,scal_52 ,scal_53 ,scal_54 ,scal_55 ,scal_56 ,scal_57 ,scal_58 ,scal_59 ,scal_6 ,scal_60 ,scal_61 ,scal_62 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4473 ,mem_vec_4474 ,mem_vec_4475 ,mem_vec_4476 ,mem_vec_4477 ,mem_vec_4478 ,mem_vec_4479 ,mem_vec_4480 ,mem_vec_4481 ,mem_vec_4482 ,mem_vec_4483 ,mem_vec_4484 ,mem_vec_4485 ,mem_vec_4486 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_132 ,vec_133 ,vec_134 ,vec_135 ,vec_136 ,vec_137 ,vec_138 ,vec_139 ,vec_14 ,vec_140 ,vec_141 ,vec_142 ,vec_143 ,vec_144 ,vec_145 ,vec_146 ,vec_147 ,vec_148 ,vec_149 ,vec_15 ,vec_150 ,vec_151 ,vec_152 ,vec_153 ,vec_154 ,vec_155 ,vec_156 ,vec_157 ,vec_158 ,vec_159 ,vec_16 ,vec_160 ,vec_161 ,vec_162 ,vec_163 ,vec_164 ,vec_165 ,vec_166 ,vec_167 ,vec_168 ,vec_169 ,vec_17 ,vec_170 ,vec_171 ,vec_172 ,vec_173 ,vec_174 ,vec_175 ,vec_176 ,vec_177 ,vec_178 ,vec_179 ,vec_18 ,vec_180 ,vec_181 ,vec_182 ,vec_183 ,vec_184 ,vec_185 ,vec_186 ,vec_187 ,vec_188 ,vec_189 ,vec_19 ,vec_190 ,vec_191 ,vec_192 ,vec_193 ,vec_194 ,vec_195 ,vec_196 ,vec_197 ,vec_198 ,vec_199 ,vec_2 ,vec_20 ,vec_200 ,vec_201 ,vec_202 ,vec_203 ,vec_204 ,vec_205 ,vec_206 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 1) (56 / 56)
for (x631 = x632, x631_p_0 = 0;
	x631 < x632 + 56;
	x631 += 56, x631_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (y, 8) (56 / 7)
	for (y = y468, yp_0 = 0;
		y < y468 + 56;
		y += 7, yp_0 += 7){
		// y = 7, x = 56, h = 3, w = 3, c = 64, f = 64
		// T (x, 2) (56 / 28)
		for (x630 = x631, x630_p_1 = x631_p_0, x630_p_0 = 0;
			x630 < x631 + 56;
			x630 += 28, x630_p_1 += 28, x630_p_0 += 28){
			// y = 7, x = 28, h = 3, w = 3, c = 64, f = 64
			// T (f, 2) (64 / 32)
			for (f = f345, fp_0 = 0;
				f < f345 + 64;
				f += 32, fp_0 += 32){
				// y = 7, x = 28, h = 3, w = 3, c = 64, f = 32
				// T (c, 2) (64 / 32)
				for (c552 = c553, c552_p_0 = 0;
					c552 < c553 + 64;
					c552 += 32, c552_p_0 += 32){
					// y = 7, x = 28, h = 3, w = 3, c = 32, f = 32
					// T (x, 28) (28 / 1)
					for (x = x630, xp_2 = x630_p_1, xp_1 = x630_p_0, xp_0 = 0;
						x < x630 + 28;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_4473 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_4474 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_4475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_4476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_4477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_4478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_4479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_4480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_4481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_4482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_4483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_4484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_4485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_4486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								// y = 7, x = 1, h = 3, w = 3, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c552, cp_1 = c552_p_0, cp_0 = 0;
									c < c552 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4473);
									mem_vec_4473 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4474);
									mem_vec_4474 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4475);
									mem_vec_4475 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4476);
									mem_vec_4476 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4477);
									mem_vec_4477 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4478);
									mem_vec_4478 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4479);
									mem_vec_4479 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4480);
									mem_vec_4480 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4481);
									mem_vec_4481 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4482);
									mem_vec_4482 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4483);
									mem_vec_4483 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4484);
									mem_vec_4484 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4485);
									mem_vec_4485 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4486);
									mem_vec_4486 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
									vec_24 = _mm512_set1_ps(scal_7);
									vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

									vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_4473);
									mem_vec_4473 = vec_23;

									vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

									vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_4474);
									mem_vec_4474 = vec_26;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
									vec_29 = _mm512_set1_ps(scal_8);


									vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_4475);
									mem_vec_4475 = vec_28;



									vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_4476);
									mem_vec_4476 = vec_30;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
									vec_32 = _mm512_set1_ps(scal_9);


									vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_4477);
									mem_vec_4477 = vec_31;



									vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_4478);
									mem_vec_4478 = vec_33;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
									vec_35 = _mm512_set1_ps(scal_10);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_4479);
									mem_vec_4479 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_4480);
									mem_vec_4480 = vec_36;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
									vec_38 = _mm512_set1_ps(scal_11);


									vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_4481);
									mem_vec_4481 = vec_37;



									vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_4482);
									mem_vec_4482 = vec_39;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
									vec_41 = _mm512_set1_ps(scal_12);


									vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_4483);
									mem_vec_4483 = vec_40;



									vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_4484);
									mem_vec_4484 = vec_42;
									scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
									vec_44 = _mm512_set1_ps(scal_13);


									vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_4485);
									mem_vec_4485 = vec_43;



									vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_4486);
									mem_vec_4486 = vec_45;
									scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
									vec_47 = _mm512_set1_ps(scal_14);
									vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

									vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_4473);
									mem_vec_4473 = vec_46;

									vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

									vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_4474);
									mem_vec_4474 = vec_49;
									scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
									vec_52 = _mm512_set1_ps(scal_15);


									vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_4475);
									mem_vec_4475 = vec_51;



									vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_4476);
									mem_vec_4476 = vec_53;
									scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
									vec_55 = _mm512_set1_ps(scal_16);


									vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_4477);
									mem_vec_4477 = vec_54;



									vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_4478);
									mem_vec_4478 = vec_56;
									scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
									vec_58 = _mm512_set1_ps(scal_17);


									vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_4479);
									mem_vec_4479 = vec_57;



									vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_4480);
									mem_vec_4480 = vec_59;
									scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
									vec_61 = _mm512_set1_ps(scal_18);


									vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_4481);
									mem_vec_4481 = vec_60;



									vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_4482);
									mem_vec_4482 = vec_62;
									scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
									vec_64 = _mm512_set1_ps(scal_19);


									vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_4483);
									mem_vec_4483 = vec_63;



									vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_4484);
									mem_vec_4484 = vec_65;
									scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
									vec_67 = _mm512_set1_ps(scal_20);


									vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_4485);
									mem_vec_4485 = vec_66;



									vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_4486);
									mem_vec_4486 = vec_68;
									scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
									vec_70 = _mm512_set1_ps(scal_21);
									vec_71 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

									vec_69 = _mm512_fmadd_ps(vec_70, vec_71, mem_vec_4473);
									mem_vec_4473 = vec_69;

									vec_73 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

									vec_72 = _mm512_fmadd_ps(vec_70, vec_73, mem_vec_4474);
									mem_vec_4474 = vec_72;
									scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
									vec_75 = _mm512_set1_ps(scal_22);


									vec_74 = _mm512_fmadd_ps(vec_75, vec_71, mem_vec_4475);
									mem_vec_4475 = vec_74;



									vec_76 = _mm512_fmadd_ps(vec_75, vec_73, mem_vec_4476);
									mem_vec_4476 = vec_76;
									scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
									vec_78 = _mm512_set1_ps(scal_23);


									vec_77 = _mm512_fmadd_ps(vec_78, vec_71, mem_vec_4477);
									mem_vec_4477 = vec_77;



									vec_79 = _mm512_fmadd_ps(vec_78, vec_73, mem_vec_4478);
									mem_vec_4478 = vec_79;
									scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
									vec_81 = _mm512_set1_ps(scal_24);


									vec_80 = _mm512_fmadd_ps(vec_81, vec_71, mem_vec_4479);
									mem_vec_4479 = vec_80;



									vec_82 = _mm512_fmadd_ps(vec_81, vec_73, mem_vec_4480);
									mem_vec_4480 = vec_82;
									scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
									vec_84 = _mm512_set1_ps(scal_25);


									vec_83 = _mm512_fmadd_ps(vec_84, vec_71, mem_vec_4481);
									mem_vec_4481 = vec_83;



									vec_85 = _mm512_fmadd_ps(vec_84, vec_73, mem_vec_4482);
									mem_vec_4482 = vec_85;
									scal_26 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
									vec_87 = _mm512_set1_ps(scal_26);


									vec_86 = _mm512_fmadd_ps(vec_87, vec_71, mem_vec_4483);
									mem_vec_4483 = vec_86;



									vec_88 = _mm512_fmadd_ps(vec_87, vec_73, mem_vec_4484);
									mem_vec_4484 = vec_88;
									scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
									vec_90 = _mm512_set1_ps(scal_27);


									vec_89 = _mm512_fmadd_ps(vec_90, vec_71, mem_vec_4485);
									mem_vec_4485 = vec_89;



									vec_91 = _mm512_fmadd_ps(vec_90, vec_73, mem_vec_4486);
									mem_vec_4486 = vec_91;
									scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
									vec_93 = _mm512_set1_ps(scal_28);
									vec_94 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

									vec_92 = _mm512_fmadd_ps(vec_93, vec_94, mem_vec_4473);
									mem_vec_4473 = vec_92;

									vec_96 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f + 16]);

									vec_95 = _mm512_fmadd_ps(vec_93, vec_96, mem_vec_4474);
									mem_vec_4474 = vec_95;
									scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
									vec_98 = _mm512_set1_ps(scal_29);


									vec_97 = _mm512_fmadd_ps(vec_98, vec_94, mem_vec_4475);
									mem_vec_4475 = vec_97;



									vec_99 = _mm512_fmadd_ps(vec_98, vec_96, mem_vec_4476);
									mem_vec_4476 = vec_99;
									scal_30 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
									vec_101 = _mm512_set1_ps(scal_30);


									vec_100 = _mm512_fmadd_ps(vec_101, vec_94, mem_vec_4477);
									mem_vec_4477 = vec_100;



									vec_102 = _mm512_fmadd_ps(vec_101, vec_96, mem_vec_4478);
									mem_vec_4478 = vec_102;
									scal_31 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
									vec_104 = _mm512_set1_ps(scal_31);


									vec_103 = _mm512_fmadd_ps(vec_104, vec_94, mem_vec_4479);
									mem_vec_4479 = vec_103;



									vec_105 = _mm512_fmadd_ps(vec_104, vec_96, mem_vec_4480);
									mem_vec_4480 = vec_105;
									scal_32 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
									vec_107 = _mm512_set1_ps(scal_32);


									vec_106 = _mm512_fmadd_ps(vec_107, vec_94, mem_vec_4481);
									mem_vec_4481 = vec_106;



									vec_108 = _mm512_fmadd_ps(vec_107, vec_96, mem_vec_4482);
									mem_vec_4482 = vec_108;
									scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
									vec_110 = _mm512_set1_ps(scal_33);


									vec_109 = _mm512_fmadd_ps(vec_110, vec_94, mem_vec_4483);
									mem_vec_4483 = vec_109;



									vec_111 = _mm512_fmadd_ps(vec_110, vec_96, mem_vec_4484);
									mem_vec_4484 = vec_111;
									scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
									vec_113 = _mm512_set1_ps(scal_34);


									vec_112 = _mm512_fmadd_ps(vec_113, vec_94, mem_vec_4485);
									mem_vec_4485 = vec_112;



									vec_114 = _mm512_fmadd_ps(vec_113, vec_96, mem_vec_4486);
									mem_vec_4486 = vec_114;
									scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
									vec_116 = _mm512_set1_ps(scal_35);
									vec_117 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

									vec_115 = _mm512_fmadd_ps(vec_116, vec_117, mem_vec_4473);
									mem_vec_4473 = vec_115;

									vec_119 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f + 16]);

									vec_118 = _mm512_fmadd_ps(vec_116, vec_119, mem_vec_4474);
									mem_vec_4474 = vec_118;
									scal_36 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
									vec_121 = _mm512_set1_ps(scal_36);


									vec_120 = _mm512_fmadd_ps(vec_121, vec_117, mem_vec_4475);
									mem_vec_4475 = vec_120;



									vec_122 = _mm512_fmadd_ps(vec_121, vec_119, mem_vec_4476);
									mem_vec_4476 = vec_122;
									scal_37 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
									vec_124 = _mm512_set1_ps(scal_37);


									vec_123 = _mm512_fmadd_ps(vec_124, vec_117, mem_vec_4477);
									mem_vec_4477 = vec_123;



									vec_125 = _mm512_fmadd_ps(vec_124, vec_119, mem_vec_4478);
									mem_vec_4478 = vec_125;
									scal_38 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
									vec_127 = _mm512_set1_ps(scal_38);


									vec_126 = _mm512_fmadd_ps(vec_127, vec_117, mem_vec_4479);
									mem_vec_4479 = vec_126;



									vec_128 = _mm512_fmadd_ps(vec_127, vec_119, mem_vec_4480);
									mem_vec_4480 = vec_128;
									scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
									vec_130 = _mm512_set1_ps(scal_39);


									vec_129 = _mm512_fmadd_ps(vec_130, vec_117, mem_vec_4481);
									mem_vec_4481 = vec_129;



									vec_131 = _mm512_fmadd_ps(vec_130, vec_119, mem_vec_4482);
									mem_vec_4482 = vec_131;
									scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
									vec_133 = _mm512_set1_ps(scal_40);


									vec_132 = _mm512_fmadd_ps(vec_133, vec_117, mem_vec_4483);
									mem_vec_4483 = vec_132;



									vec_134 = _mm512_fmadd_ps(vec_133, vec_119, mem_vec_4484);
									mem_vec_4484 = vec_134;
									scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
									vec_136 = _mm512_set1_ps(scal_41);


									vec_135 = _mm512_fmadd_ps(vec_136, vec_117, mem_vec_4485);
									mem_vec_4485 = vec_135;



									vec_137 = _mm512_fmadd_ps(vec_136, vec_119, mem_vec_4486);
									mem_vec_4486 = vec_137;
									scal_42 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
									vec_139 = _mm512_set1_ps(scal_42);
									vec_140 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

									vec_138 = _mm512_fmadd_ps(vec_139, vec_140, mem_vec_4473);
									mem_vec_4473 = vec_138;

									vec_142 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

									vec_141 = _mm512_fmadd_ps(vec_139, vec_142, mem_vec_4474);
									mem_vec_4474 = vec_141;
									scal_43 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
									vec_144 = _mm512_set1_ps(scal_43);


									vec_143 = _mm512_fmadd_ps(vec_144, vec_140, mem_vec_4475);
									mem_vec_4475 = vec_143;



									vec_145 = _mm512_fmadd_ps(vec_144, vec_142, mem_vec_4476);
									mem_vec_4476 = vec_145;
									scal_44 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
									vec_147 = _mm512_set1_ps(scal_44);


									vec_146 = _mm512_fmadd_ps(vec_147, vec_140, mem_vec_4477);
									mem_vec_4477 = vec_146;



									vec_148 = _mm512_fmadd_ps(vec_147, vec_142, mem_vec_4478);
									mem_vec_4478 = vec_148;
									scal_45 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
									vec_150 = _mm512_set1_ps(scal_45);


									vec_149 = _mm512_fmadd_ps(vec_150, vec_140, mem_vec_4479);
									mem_vec_4479 = vec_149;



									vec_151 = _mm512_fmadd_ps(vec_150, vec_142, mem_vec_4480);
									mem_vec_4480 = vec_151;
									scal_46 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
									vec_153 = _mm512_set1_ps(scal_46);


									vec_152 = _mm512_fmadd_ps(vec_153, vec_140, mem_vec_4481);
									mem_vec_4481 = vec_152;



									vec_154 = _mm512_fmadd_ps(vec_153, vec_142, mem_vec_4482);
									mem_vec_4482 = vec_154;
									scal_47 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
									vec_156 = _mm512_set1_ps(scal_47);


									vec_155 = _mm512_fmadd_ps(vec_156, vec_140, mem_vec_4483);
									mem_vec_4483 = vec_155;



									vec_157 = _mm512_fmadd_ps(vec_156, vec_142, mem_vec_4484);
									mem_vec_4484 = vec_157;
									scal_48 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
									vec_159 = _mm512_set1_ps(scal_48);


									vec_158 = _mm512_fmadd_ps(vec_159, vec_140, mem_vec_4485);
									mem_vec_4485 = vec_158;



									vec_160 = _mm512_fmadd_ps(vec_159, vec_142, mem_vec_4486);
									mem_vec_4486 = vec_160;
									scal_49 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
									vec_162 = _mm512_set1_ps(scal_49);
									vec_163 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

									vec_161 = _mm512_fmadd_ps(vec_162, vec_163, mem_vec_4473);
									mem_vec_4473 = vec_161;

									vec_165 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f + 16]);

									vec_164 = _mm512_fmadd_ps(vec_162, vec_165, mem_vec_4474);
									mem_vec_4474 = vec_164;
									scal_50 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
									vec_167 = _mm512_set1_ps(scal_50);


									vec_166 = _mm512_fmadd_ps(vec_167, vec_163, mem_vec_4475);
									mem_vec_4475 = vec_166;



									vec_168 = _mm512_fmadd_ps(vec_167, vec_165, mem_vec_4476);
									mem_vec_4476 = vec_168;
									scal_51 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
									vec_170 = _mm512_set1_ps(scal_51);


									vec_169 = _mm512_fmadd_ps(vec_170, vec_163, mem_vec_4477);
									mem_vec_4477 = vec_169;



									vec_171 = _mm512_fmadd_ps(vec_170, vec_165, mem_vec_4478);
									mem_vec_4478 = vec_171;
									scal_52 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
									vec_173 = _mm512_set1_ps(scal_52);


									vec_172 = _mm512_fmadd_ps(vec_173, vec_163, mem_vec_4479);
									mem_vec_4479 = vec_172;



									vec_174 = _mm512_fmadd_ps(vec_173, vec_165, mem_vec_4480);
									mem_vec_4480 = vec_174;
									scal_53 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
									vec_176 = _mm512_set1_ps(scal_53);


									vec_175 = _mm512_fmadd_ps(vec_176, vec_163, mem_vec_4481);
									mem_vec_4481 = vec_175;



									vec_177 = _mm512_fmadd_ps(vec_176, vec_165, mem_vec_4482);
									mem_vec_4482 = vec_177;
									scal_54 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
									vec_179 = _mm512_set1_ps(scal_54);


									vec_178 = _mm512_fmadd_ps(vec_179, vec_163, mem_vec_4483);
									mem_vec_4483 = vec_178;



									vec_180 = _mm512_fmadd_ps(vec_179, vec_165, mem_vec_4484);
									mem_vec_4484 = vec_180;
									scal_55 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
									vec_182 = _mm512_set1_ps(scal_55);


									vec_181 = _mm512_fmadd_ps(vec_182, vec_163, mem_vec_4485);
									mem_vec_4485 = vec_181;



									vec_183 = _mm512_fmadd_ps(vec_182, vec_165, mem_vec_4486);
									mem_vec_4486 = vec_183;
									scal_56 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
									vec_185 = _mm512_set1_ps(scal_56);
									vec_186 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

									vec_184 = _mm512_fmadd_ps(vec_185, vec_186, mem_vec_4473);
									mem_vec_4473 = vec_184;

									vec_188 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f + 16]);

									vec_187 = _mm512_fmadd_ps(vec_185, vec_188, mem_vec_4474);
									mem_vec_4474 = vec_187;
									scal_57 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
									vec_190 = _mm512_set1_ps(scal_57);


									vec_189 = _mm512_fmadd_ps(vec_190, vec_186, mem_vec_4475);
									mem_vec_4475 = vec_189;



									vec_191 = _mm512_fmadd_ps(vec_190, vec_188, mem_vec_4476);
									mem_vec_4476 = vec_191;
									scal_58 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
									vec_193 = _mm512_set1_ps(scal_58);


									vec_192 = _mm512_fmadd_ps(vec_193, vec_186, mem_vec_4477);
									mem_vec_4477 = vec_192;



									vec_194 = _mm512_fmadd_ps(vec_193, vec_188, mem_vec_4478);
									mem_vec_4478 = vec_194;
									scal_59 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
									vec_196 = _mm512_set1_ps(scal_59);


									vec_195 = _mm512_fmadd_ps(vec_196, vec_186, mem_vec_4479);
									mem_vec_4479 = vec_195;



									vec_197 = _mm512_fmadd_ps(vec_196, vec_188, mem_vec_4480);
									mem_vec_4480 = vec_197;
									scal_60 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
									vec_199 = _mm512_set1_ps(scal_60);


									vec_198 = _mm512_fmadd_ps(vec_199, vec_186, mem_vec_4481);
									mem_vec_4481 = vec_198;



									vec_200 = _mm512_fmadd_ps(vec_199, vec_188, mem_vec_4482);
									mem_vec_4482 = vec_200;
									scal_61 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
									vec_202 = _mm512_set1_ps(scal_61);


									vec_201 = _mm512_fmadd_ps(vec_202, vec_186, mem_vec_4483);
									mem_vec_4483 = vec_201;



									vec_203 = _mm512_fmadd_ps(vec_202, vec_188, mem_vec_4484);
									mem_vec_4484 = vec_203;
									scal_62 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
									vec_205 = _mm512_set1_ps(scal_62);


									vec_204 = _mm512_fmadd_ps(vec_205, vec_186, mem_vec_4485);
									mem_vec_4485 = vec_204;



									vec_206 = _mm512_fmadd_ps(vec_205, vec_188, mem_vec_4486);
									mem_vec_4486 = vec_206;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4473);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4474);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4475);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4476);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4477);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4478);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4479);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4480);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4481);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4482);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4483);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4484);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4485);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4486);
					}
				}
			}
		}
	}
}


}