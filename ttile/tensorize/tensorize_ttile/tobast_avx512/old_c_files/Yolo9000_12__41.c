#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); U (3, w); T (32, c); Hoist_vars [c];
  T (2, x); T (2, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (2, f);
  T (8, c); T (4, f)]
*/
IND_TYPE c, cp_0, c1174_p_0, cp_1, c1174, f, fp_0, f1072_p_0, f1073_p_0, fp_1, f1072_p_1, fp_2, f1072, f1073, x, xp_0, x1174_p_0, xp_1, x1174, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y684 = 0;
IND_TYPE x1175 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1175 = 0;
IND_TYPE f1074 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_45 ,scal_46 ,scal_47 ,scal_48 ,scal_49 ,scal_5 ,scal_50 ,scal_51 ,scal_52 ,scal_53 ,scal_54 ,scal_55 ,scal_56 ,scal_57 ,scal_58 ,scal_59 ,scal_6 ,scal_60 ,scal_61 ,scal_62 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9462 ,mem_vec_9463 ,mem_vec_9464 ,mem_vec_9465 ,mem_vec_9466 ,mem_vec_9467 ,mem_vec_9468 ,mem_vec_9469 ,mem_vec_9470 ,mem_vec_9471 ,mem_vec_9472 ,mem_vec_9473 ,mem_vec_9474 ,mem_vec_9475 ,mem_vec_9476 ,mem_vec_9477 ,mem_vec_9478 ,mem_vec_9479 ,mem_vec_9480 ,mem_vec_9481 ,mem_vec_9482 ,mem_vec_9483 ,mem_vec_9484 ,mem_vec_9485 ,mem_vec_9486 ,mem_vec_9487 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_132 ,vec_133 ,vec_134 ,vec_135 ,vec_136 ,vec_137 ,vec_138 ,vec_139 ,vec_14 ,vec_140 ,vec_141 ,vec_142 ,vec_143 ,vec_144 ,vec_145 ,vec_146 ,vec_147 ,vec_148 ,vec_149 ,vec_15 ,vec_150 ,vec_151 ,vec_152 ,vec_153 ,vec_154 ,vec_155 ,vec_156 ,vec_157 ,vec_158 ,vec_159 ,vec_16 ,vec_160 ,vec_161 ,vec_162 ,vec_163 ,vec_164 ,vec_165 ,vec_166 ,vec_167 ,vec_168 ,vec_169 ,vec_17 ,vec_170 ,vec_171 ,vec_172 ,vec_173 ,vec_174 ,vec_175 ,vec_176 ,vec_177 ,vec_178 ,vec_179 ,vec_18 ,vec_180 ,vec_181 ,vec_182 ,vec_183 ,vec_184 ,vec_185 ,vec_186 ,vec_187 ,vec_188 ,vec_189 ,vec_19 ,vec_190 ,vec_191 ,vec_192 ,vec_193 ,vec_194 ,vec_195 ,vec_196 ,vec_197 ,vec_198 ,vec_199 ,vec_2 ,vec_20 ,vec_200 ,vec_201 ,vec_202 ,vec_203 ,vec_204 ,vec_205 ,vec_206 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f1073 = f1074, f1073_p_0 = 0;
	f1073 < f1074 + 512;
	f1073 += 128, f1073_p_0 += 128){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
	// T (c, 8) (256 / 32)
	for (c1174 = c1175, c1174_p_0 = 0;
		c1174 < c1175 + 256;
		c1174 += 32, c1174_p_0 += 32){
		// y = 34, x = 34, h = 3, w = 3, c = 32, f = 128
		// T (f, 2) (128 / 64)
		for (f1072 = f1073, f1072_p_1 = f1073_p_0, f1072_p_0 = 0;
			f1072 < f1073 + 128;
			f1072 += 64, f1072_p_1 += 64, f1072_p_0 += 64){
				for (y = y684, yp_0 = 0;
					y < y684 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 64
					// T (x, 17) (34 / 2)
					for (x1174 = x1175, x1174_p_0 = 0;
						x1174 < x1175 + 34;
						x1174 += 2, x1174_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 64
						// T (f, 2) (64 / 32)
						for (f = f1072, fp_2 = f1072_p_1, fp_1 = f1072_p_0, fp_0 = 0;
							f < f1072 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 32
							// T (x, 2) (2 / 1)
							for (x = x1174, xp_1 = x1174_p_0, xp_0 = 0;
								x < x1174 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9462 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9463 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c1174, cp_1 = c1174_p_0, cp_0 = 0;
											c < c1174 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9462);
											mem_vec_9462 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9463);
											mem_vec_9463 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9464);
											mem_vec_9464 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9465);
											mem_vec_9465 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9466);
											mem_vec_9466 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9467);
											mem_vec_9467 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9468);
											mem_vec_9468 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9469);
											mem_vec_9469 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9470);
											mem_vec_9470 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9471);
											mem_vec_9471 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9472);
											mem_vec_9472 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9473);
											mem_vec_9473 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_9462);
											mem_vec_9462 = vec_20;

											vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_9463);
											mem_vec_9463 = vec_23;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_26 = _mm512_set1_ps(scal_7);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_9464);
											mem_vec_9464 = vec_25;



											vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_9465);
											mem_vec_9465 = vec_27;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_8);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_9466);
											mem_vec_9466 = vec_28;



											vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_9467);
											mem_vec_9467 = vec_30;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_9468);
											mem_vec_9468 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_9469);
											mem_vec_9469 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_9470);
											mem_vec_9470 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_9471);
											mem_vec_9471 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_9472);
											mem_vec_9472 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_9473);
											mem_vec_9473 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_41 = _mm512_set1_ps(scal_12);
											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_9462);
											mem_vec_9462 = vec_40;

											vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_9463);
											mem_vec_9463 = vec_43;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_46 = _mm512_set1_ps(scal_13);


											vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_9464);
											mem_vec_9464 = vec_45;



											vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_9465);
											mem_vec_9465 = vec_47;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_49 = _mm512_set1_ps(scal_14);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_9466);
											mem_vec_9466 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_9467);
											mem_vec_9467 = vec_50;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_52 = _mm512_set1_ps(scal_15);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_9468);
											mem_vec_9468 = vec_51;



											vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_9469);
											mem_vec_9469 = vec_53;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_55 = _mm512_set1_ps(scal_16);


											vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_9470);
											mem_vec_9470 = vec_54;



											vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_9471);
											mem_vec_9471 = vec_56;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_17);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_9472);
											mem_vec_9472 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_9473);
											mem_vec_9473 = vec_59;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_61 = _mm512_set1_ps(scal_18);
											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_60 = _mm512_fmadd_ps(vec_61, vec_62, mem_vec_9462);
											mem_vec_9462 = vec_60;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_63 = _mm512_fmadd_ps(vec_61, vec_64, mem_vec_9463);
											mem_vec_9463 = vec_63;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_66 = _mm512_set1_ps(scal_19);


											vec_65 = _mm512_fmadd_ps(vec_66, vec_62, mem_vec_9464);
											mem_vec_9464 = vec_65;



											vec_67 = _mm512_fmadd_ps(vec_66, vec_64, mem_vec_9465);
											mem_vec_9465 = vec_67;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_69 = _mm512_set1_ps(scal_20);


											vec_68 = _mm512_fmadd_ps(vec_69, vec_62, mem_vec_9466);
											mem_vec_9466 = vec_68;



											vec_70 = _mm512_fmadd_ps(vec_69, vec_64, mem_vec_9467);
											mem_vec_9467 = vec_70;
											scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_72 = _mm512_set1_ps(scal_21);


											vec_71 = _mm512_fmadd_ps(vec_72, vec_62, mem_vec_9468);
											mem_vec_9468 = vec_71;



											vec_73 = _mm512_fmadd_ps(vec_72, vec_64, mem_vec_9469);
											mem_vec_9469 = vec_73;
											scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_75 = _mm512_set1_ps(scal_22);


											vec_74 = _mm512_fmadd_ps(vec_75, vec_62, mem_vec_9470);
											mem_vec_9470 = vec_74;



											vec_76 = _mm512_fmadd_ps(vec_75, vec_64, mem_vec_9471);
											mem_vec_9471 = vec_76;
											scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_78 = _mm512_set1_ps(scal_23);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_9472);
											mem_vec_9472 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_9473);
											mem_vec_9473 = vec_79;
											scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_81 = _mm512_set1_ps(scal_24);
											vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_80 = _mm512_fmadd_ps(vec_81, vec_82, mem_vec_9462);
											mem_vec_9462 = vec_80;

											vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_83 = _mm512_fmadd_ps(vec_81, vec_84, mem_vec_9463);
											mem_vec_9463 = vec_83;
											scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_86 = _mm512_set1_ps(scal_25);


											vec_85 = _mm512_fmadd_ps(vec_86, vec_82, mem_vec_9464);
											mem_vec_9464 = vec_85;



											vec_87 = _mm512_fmadd_ps(vec_86, vec_84, mem_vec_9465);
											mem_vec_9465 = vec_87;
											scal_26 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_89 = _mm512_set1_ps(scal_26);


											vec_88 = _mm512_fmadd_ps(vec_89, vec_82, mem_vec_9466);
											mem_vec_9466 = vec_88;



											vec_90 = _mm512_fmadd_ps(vec_89, vec_84, mem_vec_9467);
											mem_vec_9467 = vec_90;
											scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_92 = _mm512_set1_ps(scal_27);


											vec_91 = _mm512_fmadd_ps(vec_92, vec_82, mem_vec_9468);
											mem_vec_9468 = vec_91;



											vec_93 = _mm512_fmadd_ps(vec_92, vec_84, mem_vec_9469);
											mem_vec_9469 = vec_93;
											scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_95 = _mm512_set1_ps(scal_28);


											vec_94 = _mm512_fmadd_ps(vec_95, vec_82, mem_vec_9470);
											mem_vec_9470 = vec_94;



											vec_96 = _mm512_fmadd_ps(vec_95, vec_84, mem_vec_9471);
											mem_vec_9471 = vec_96;
											scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
											vec_98 = _mm512_set1_ps(scal_29);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_9472);
											mem_vec_9472 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_9473);
											mem_vec_9473 = vec_99;
											scal_30 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_101 = _mm512_set1_ps(scal_30);
											vec_102 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_100 = _mm512_fmadd_ps(vec_101, vec_102, mem_vec_9462);
											mem_vec_9462 = vec_100;

											vec_104 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_103 = _mm512_fmadd_ps(vec_101, vec_104, mem_vec_9463);
											mem_vec_9463 = vec_103;
											scal_31 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_106 = _mm512_set1_ps(scal_31);


											vec_105 = _mm512_fmadd_ps(vec_106, vec_102, mem_vec_9464);
											mem_vec_9464 = vec_105;



											vec_107 = _mm512_fmadd_ps(vec_106, vec_104, mem_vec_9465);
											mem_vec_9465 = vec_107;
											scal_32 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_109 = _mm512_set1_ps(scal_32);


											vec_108 = _mm512_fmadd_ps(vec_109, vec_102, mem_vec_9466);
											mem_vec_9466 = vec_108;



											vec_110 = _mm512_fmadd_ps(vec_109, vec_104, mem_vec_9467);
											mem_vec_9467 = vec_110;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_112 = _mm512_set1_ps(scal_33);


											vec_111 = _mm512_fmadd_ps(vec_112, vec_102, mem_vec_9468);
											mem_vec_9468 = vec_111;



											vec_113 = _mm512_fmadd_ps(vec_112, vec_104, mem_vec_9469);
											mem_vec_9469 = vec_113;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_115 = _mm512_set1_ps(scal_34);


											vec_114 = _mm512_fmadd_ps(vec_115, vec_102, mem_vec_9470);
											mem_vec_9470 = vec_114;



											vec_116 = _mm512_fmadd_ps(vec_115, vec_104, mem_vec_9471);
											mem_vec_9471 = vec_116;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
											vec_118 = _mm512_set1_ps(scal_35);


											vec_117 = _mm512_fmadd_ps(vec_118, vec_102, mem_vec_9472);
											mem_vec_9472 = vec_117;



											vec_119 = _mm512_fmadd_ps(vec_118, vec_104, mem_vec_9473);
											mem_vec_9473 = vec_119;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_121 = _mm512_set1_ps(scal_36);
											vec_122 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_120 = _mm512_fmadd_ps(vec_121, vec_122, mem_vec_9462);
											mem_vec_9462 = vec_120;

											vec_124 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_123 = _mm512_fmadd_ps(vec_121, vec_124, mem_vec_9463);
											mem_vec_9463 = vec_123;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_126 = _mm512_set1_ps(scal_37);


											vec_125 = _mm512_fmadd_ps(vec_126, vec_122, mem_vec_9464);
											mem_vec_9464 = vec_125;



											vec_127 = _mm512_fmadd_ps(vec_126, vec_124, mem_vec_9465);
											mem_vec_9465 = vec_127;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_129 = _mm512_set1_ps(scal_38);


											vec_128 = _mm512_fmadd_ps(vec_129, vec_122, mem_vec_9466);
											mem_vec_9466 = vec_128;



											vec_130 = _mm512_fmadd_ps(vec_129, vec_124, mem_vec_9467);
											mem_vec_9467 = vec_130;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_132 = _mm512_set1_ps(scal_39);


											vec_131 = _mm512_fmadd_ps(vec_132, vec_122, mem_vec_9468);
											mem_vec_9468 = vec_131;



											vec_133 = _mm512_fmadd_ps(vec_132, vec_124, mem_vec_9469);
											mem_vec_9469 = vec_133;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_135 = _mm512_set1_ps(scal_40);


											vec_134 = _mm512_fmadd_ps(vec_135, vec_122, mem_vec_9470);
											mem_vec_9470 = vec_134;



											vec_136 = _mm512_fmadd_ps(vec_135, vec_124, mem_vec_9471);
											mem_vec_9471 = vec_136;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_138 = _mm512_set1_ps(scal_41);


											vec_137 = _mm512_fmadd_ps(vec_138, vec_122, mem_vec_9472);
											mem_vec_9472 = vec_137;



											vec_139 = _mm512_fmadd_ps(vec_138, vec_124, mem_vec_9473);
											mem_vec_9473 = vec_139;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_141 = _mm512_set1_ps(scal_42);
											vec_142 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_140 = _mm512_fmadd_ps(vec_141, vec_142, mem_vec_9462);
											mem_vec_9462 = vec_140;

											vec_144 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_143 = _mm512_fmadd_ps(vec_141, vec_144, mem_vec_9463);
											mem_vec_9463 = vec_143;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_146 = _mm512_set1_ps(scal_43);


											vec_145 = _mm512_fmadd_ps(vec_146, vec_142, mem_vec_9464);
											mem_vec_9464 = vec_145;



											vec_147 = _mm512_fmadd_ps(vec_146, vec_144, mem_vec_9465);
											mem_vec_9465 = vec_147;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_149 = _mm512_set1_ps(scal_44);


											vec_148 = _mm512_fmadd_ps(vec_149, vec_142, mem_vec_9466);
											mem_vec_9466 = vec_148;



											vec_150 = _mm512_fmadd_ps(vec_149, vec_144, mem_vec_9467);
											mem_vec_9467 = vec_150;
											scal_45 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_152 = _mm512_set1_ps(scal_45);


											vec_151 = _mm512_fmadd_ps(vec_152, vec_142, mem_vec_9468);
											mem_vec_9468 = vec_151;



											vec_153 = _mm512_fmadd_ps(vec_152, vec_144, mem_vec_9469);
											mem_vec_9469 = vec_153;
											scal_46 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_155 = _mm512_set1_ps(scal_46);


											vec_154 = _mm512_fmadd_ps(vec_155, vec_142, mem_vec_9470);
											mem_vec_9470 = vec_154;



											vec_156 = _mm512_fmadd_ps(vec_155, vec_144, mem_vec_9471);
											mem_vec_9471 = vec_156;
											scal_47 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
											vec_158 = _mm512_set1_ps(scal_47);


											vec_157 = _mm512_fmadd_ps(vec_158, vec_142, mem_vec_9472);
											mem_vec_9472 = vec_157;



											vec_159 = _mm512_fmadd_ps(vec_158, vec_144, mem_vec_9473);
											mem_vec_9473 = vec_159;
											scal_48 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_161 = _mm512_set1_ps(scal_48);
											vec_162 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_160 = _mm512_fmadd_ps(vec_161, vec_162, mem_vec_9462);
											mem_vec_9462 = vec_160;

											vec_164 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_163 = _mm512_fmadd_ps(vec_161, vec_164, mem_vec_9463);
											mem_vec_9463 = vec_163;
											scal_49 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_166 = _mm512_set1_ps(scal_49);


											vec_165 = _mm512_fmadd_ps(vec_166, vec_162, mem_vec_9464);
											mem_vec_9464 = vec_165;



											vec_167 = _mm512_fmadd_ps(vec_166, vec_164, mem_vec_9465);
											mem_vec_9465 = vec_167;
											scal_50 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_169 = _mm512_set1_ps(scal_50);


											vec_168 = _mm512_fmadd_ps(vec_169, vec_162, mem_vec_9466);
											mem_vec_9466 = vec_168;



											vec_170 = _mm512_fmadd_ps(vec_169, vec_164, mem_vec_9467);
											mem_vec_9467 = vec_170;
											scal_51 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_172 = _mm512_set1_ps(scal_51);


											vec_171 = _mm512_fmadd_ps(vec_172, vec_162, mem_vec_9468);
											mem_vec_9468 = vec_171;



											vec_173 = _mm512_fmadd_ps(vec_172, vec_164, mem_vec_9469);
											mem_vec_9469 = vec_173;
											scal_52 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_175 = _mm512_set1_ps(scal_52);


											vec_174 = _mm512_fmadd_ps(vec_175, vec_162, mem_vec_9470);
											mem_vec_9470 = vec_174;



											vec_176 = _mm512_fmadd_ps(vec_175, vec_164, mem_vec_9471);
											mem_vec_9471 = vec_176;
											scal_53 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
											vec_178 = _mm512_set1_ps(scal_53);


											vec_177 = _mm512_fmadd_ps(vec_178, vec_162, mem_vec_9472);
											mem_vec_9472 = vec_177;



											vec_179 = _mm512_fmadd_ps(vec_178, vec_164, mem_vec_9473);
											mem_vec_9473 = vec_179;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9462);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9463);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9464);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9465);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9466);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9467);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9468);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9469);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9470);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9471);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9472);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9473);
							}
						}
					}
				}
				for (y = y684 + 6, yp_0 = 0;
					y < y684 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 64
					// T (x, 17) (34 / 2)
					for (x1174 = x1175, x1174_p_0 = 0;
						x1174 < x1175 + 34;
						x1174 += 2, x1174_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 64
						// T (f, 2) (64 / 32)
						for (f = f1072, fp_2 = f1072_p_1, fp_1 = f1072_p_0, fp_0 = 0;
							f < f1072 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 32
							// T (x, 2) (2 / 1)
							for (x = x1174, xp_1 = x1174_p_0, xp_0 = 0;
								x < x1174 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9474 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9475 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c1174, cp_1 = c1174_p_0, cp_0 = 0;
											c < c1174 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9474);
											mem_vec_9474 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9475);
											mem_vec_9475 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9476);
											mem_vec_9476 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9477);
											mem_vec_9477 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9478);
											mem_vec_9478 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9479);
											mem_vec_9479 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9480);
											mem_vec_9480 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9481);
											mem_vec_9481 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9482);
											mem_vec_9482 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9483);
											mem_vec_9483 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9484);
											mem_vec_9484 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9485);
											mem_vec_9485 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9486);
											mem_vec_9486 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9487);
											mem_vec_9487 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_9474);
											mem_vec_9474 = vec_23;

											vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_9475);
											mem_vec_9475 = vec_26;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_8);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_9476);
											mem_vec_9476 = vec_28;



											vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_9477);
											mem_vec_9477 = vec_30;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_9478);
											mem_vec_9478 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_9479);
											mem_vec_9479 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_9480);
											mem_vec_9480 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_9481);
											mem_vec_9481 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_9482);
											mem_vec_9482 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_9483);
											mem_vec_9483 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_9484);
											mem_vec_9484 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_9485);
											mem_vec_9485 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_9486);
											mem_vec_9486 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_9487);
											mem_vec_9487 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_47 = _mm512_set1_ps(scal_14);
											vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_9474);
											mem_vec_9474 = vec_46;

											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_9475);
											mem_vec_9475 = vec_49;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_52 = _mm512_set1_ps(scal_15);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_9476);
											mem_vec_9476 = vec_51;



											vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_9477);
											mem_vec_9477 = vec_53;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_55 = _mm512_set1_ps(scal_16);


											vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_9478);
											mem_vec_9478 = vec_54;



											vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_9479);
											mem_vec_9479 = vec_56;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_17);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_9480);
											mem_vec_9480 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_9481);
											mem_vec_9481 = vec_59;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_61 = _mm512_set1_ps(scal_18);


											vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_9482);
											mem_vec_9482 = vec_60;



											vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_9483);
											mem_vec_9483 = vec_62;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_9484);
											mem_vec_9484 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_9485);
											mem_vec_9485 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_9486);
											mem_vec_9486 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_9487);
											mem_vec_9487 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_70 = _mm512_set1_ps(scal_21);
											vec_71 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_69 = _mm512_fmadd_ps(vec_70, vec_71, mem_vec_9474);
											mem_vec_9474 = vec_69;

											vec_73 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_72 = _mm512_fmadd_ps(vec_70, vec_73, mem_vec_9475);
											mem_vec_9475 = vec_72;
											scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_75 = _mm512_set1_ps(scal_22);


											vec_74 = _mm512_fmadd_ps(vec_75, vec_71, mem_vec_9476);
											mem_vec_9476 = vec_74;



											vec_76 = _mm512_fmadd_ps(vec_75, vec_73, mem_vec_9477);
											mem_vec_9477 = vec_76;
											scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_78 = _mm512_set1_ps(scal_23);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_71, mem_vec_9478);
											mem_vec_9478 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_73, mem_vec_9479);
											mem_vec_9479 = vec_79;
											scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_81 = _mm512_set1_ps(scal_24);


											vec_80 = _mm512_fmadd_ps(vec_81, vec_71, mem_vec_9480);
											mem_vec_9480 = vec_80;



											vec_82 = _mm512_fmadd_ps(vec_81, vec_73, mem_vec_9481);
											mem_vec_9481 = vec_82;
											scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_84 = _mm512_set1_ps(scal_25);


											vec_83 = _mm512_fmadd_ps(vec_84, vec_71, mem_vec_9482);
											mem_vec_9482 = vec_83;



											vec_85 = _mm512_fmadd_ps(vec_84, vec_73, mem_vec_9483);
											mem_vec_9483 = vec_85;
											scal_26 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_87 = _mm512_set1_ps(scal_26);


											vec_86 = _mm512_fmadd_ps(vec_87, vec_71, mem_vec_9484);
											mem_vec_9484 = vec_86;



											vec_88 = _mm512_fmadd_ps(vec_87, vec_73, mem_vec_9485);
											mem_vec_9485 = vec_88;
											scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_90 = _mm512_set1_ps(scal_27);


											vec_89 = _mm512_fmadd_ps(vec_90, vec_71, mem_vec_9486);
											mem_vec_9486 = vec_89;



											vec_91 = _mm512_fmadd_ps(vec_90, vec_73, mem_vec_9487);
											mem_vec_9487 = vec_91;
											scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_93 = _mm512_set1_ps(scal_28);
											vec_94 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_92 = _mm512_fmadd_ps(vec_93, vec_94, mem_vec_9474);
											mem_vec_9474 = vec_92;

											vec_96 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_95 = _mm512_fmadd_ps(vec_93, vec_96, mem_vec_9475);
											mem_vec_9475 = vec_95;
											scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_98 = _mm512_set1_ps(scal_29);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_94, mem_vec_9476);
											mem_vec_9476 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_96, mem_vec_9477);
											mem_vec_9477 = vec_99;
											scal_30 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_101 = _mm512_set1_ps(scal_30);


											vec_100 = _mm512_fmadd_ps(vec_101, vec_94, mem_vec_9478);
											mem_vec_9478 = vec_100;



											vec_102 = _mm512_fmadd_ps(vec_101, vec_96, mem_vec_9479);
											mem_vec_9479 = vec_102;
											scal_31 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_104 = _mm512_set1_ps(scal_31);


											vec_103 = _mm512_fmadd_ps(vec_104, vec_94, mem_vec_9480);
											mem_vec_9480 = vec_103;



											vec_105 = _mm512_fmadd_ps(vec_104, vec_96, mem_vec_9481);
											mem_vec_9481 = vec_105;
											scal_32 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_107 = _mm512_set1_ps(scal_32);


											vec_106 = _mm512_fmadd_ps(vec_107, vec_94, mem_vec_9482);
											mem_vec_9482 = vec_106;



											vec_108 = _mm512_fmadd_ps(vec_107, vec_96, mem_vec_9483);
											mem_vec_9483 = vec_108;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
											vec_110 = _mm512_set1_ps(scal_33);


											vec_109 = _mm512_fmadd_ps(vec_110, vec_94, mem_vec_9484);
											mem_vec_9484 = vec_109;



											vec_111 = _mm512_fmadd_ps(vec_110, vec_96, mem_vec_9485);
											mem_vec_9485 = vec_111;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
											vec_113 = _mm512_set1_ps(scal_34);


											vec_112 = _mm512_fmadd_ps(vec_113, vec_94, mem_vec_9486);
											mem_vec_9486 = vec_112;



											vec_114 = _mm512_fmadd_ps(vec_113, vec_96, mem_vec_9487);
											mem_vec_9487 = vec_114;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_116 = _mm512_set1_ps(scal_35);
											vec_117 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_115 = _mm512_fmadd_ps(vec_116, vec_117, mem_vec_9474);
											mem_vec_9474 = vec_115;

											vec_119 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_118 = _mm512_fmadd_ps(vec_116, vec_119, mem_vec_9475);
											mem_vec_9475 = vec_118;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_121 = _mm512_set1_ps(scal_36);


											vec_120 = _mm512_fmadd_ps(vec_121, vec_117, mem_vec_9476);
											mem_vec_9476 = vec_120;



											vec_122 = _mm512_fmadd_ps(vec_121, vec_119, mem_vec_9477);
											mem_vec_9477 = vec_122;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_124 = _mm512_set1_ps(scal_37);


											vec_123 = _mm512_fmadd_ps(vec_124, vec_117, mem_vec_9478);
											mem_vec_9478 = vec_123;



											vec_125 = _mm512_fmadd_ps(vec_124, vec_119, mem_vec_9479);
											mem_vec_9479 = vec_125;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_127 = _mm512_set1_ps(scal_38);


											vec_126 = _mm512_fmadd_ps(vec_127, vec_117, mem_vec_9480);
											mem_vec_9480 = vec_126;



											vec_128 = _mm512_fmadd_ps(vec_127, vec_119, mem_vec_9481);
											mem_vec_9481 = vec_128;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_130 = _mm512_set1_ps(scal_39);


											vec_129 = _mm512_fmadd_ps(vec_130, vec_117, mem_vec_9482);
											mem_vec_9482 = vec_129;



											vec_131 = _mm512_fmadd_ps(vec_130, vec_119, mem_vec_9483);
											mem_vec_9483 = vec_131;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
											vec_133 = _mm512_set1_ps(scal_40);


											vec_132 = _mm512_fmadd_ps(vec_133, vec_117, mem_vec_9484);
											mem_vec_9484 = vec_132;



											vec_134 = _mm512_fmadd_ps(vec_133, vec_119, mem_vec_9485);
											mem_vec_9485 = vec_134;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
											vec_136 = _mm512_set1_ps(scal_41);


											vec_135 = _mm512_fmadd_ps(vec_136, vec_117, mem_vec_9486);
											mem_vec_9486 = vec_135;



											vec_137 = _mm512_fmadd_ps(vec_136, vec_119, mem_vec_9487);
											mem_vec_9487 = vec_137;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_139 = _mm512_set1_ps(scal_42);
											vec_140 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_138 = _mm512_fmadd_ps(vec_139, vec_140, mem_vec_9474);
											mem_vec_9474 = vec_138;

											vec_142 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_141 = _mm512_fmadd_ps(vec_139, vec_142, mem_vec_9475);
											mem_vec_9475 = vec_141;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_144 = _mm512_set1_ps(scal_43);


											vec_143 = _mm512_fmadd_ps(vec_144, vec_140, mem_vec_9476);
											mem_vec_9476 = vec_143;



											vec_145 = _mm512_fmadd_ps(vec_144, vec_142, mem_vec_9477);
											mem_vec_9477 = vec_145;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_147 = _mm512_set1_ps(scal_44);


											vec_146 = _mm512_fmadd_ps(vec_147, vec_140, mem_vec_9478);
											mem_vec_9478 = vec_146;



											vec_148 = _mm512_fmadd_ps(vec_147, vec_142, mem_vec_9479);
											mem_vec_9479 = vec_148;
											scal_45 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_150 = _mm512_set1_ps(scal_45);


											vec_149 = _mm512_fmadd_ps(vec_150, vec_140, mem_vec_9480);
											mem_vec_9480 = vec_149;



											vec_151 = _mm512_fmadd_ps(vec_150, vec_142, mem_vec_9481);
											mem_vec_9481 = vec_151;
											scal_46 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_153 = _mm512_set1_ps(scal_46);


											vec_152 = _mm512_fmadd_ps(vec_153, vec_140, mem_vec_9482);
											mem_vec_9482 = vec_152;



											vec_154 = _mm512_fmadd_ps(vec_153, vec_142, mem_vec_9483);
											mem_vec_9483 = vec_154;
											scal_47 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_156 = _mm512_set1_ps(scal_47);


											vec_155 = _mm512_fmadd_ps(vec_156, vec_140, mem_vec_9484);
											mem_vec_9484 = vec_155;



											vec_157 = _mm512_fmadd_ps(vec_156, vec_142, mem_vec_9485);
											mem_vec_9485 = vec_157;
											scal_48 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_159 = _mm512_set1_ps(scal_48);


											vec_158 = _mm512_fmadd_ps(vec_159, vec_140, mem_vec_9486);
											mem_vec_9486 = vec_158;



											vec_160 = _mm512_fmadd_ps(vec_159, vec_142, mem_vec_9487);
											mem_vec_9487 = vec_160;
											scal_49 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_162 = _mm512_set1_ps(scal_49);
											vec_163 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_161 = _mm512_fmadd_ps(vec_162, vec_163, mem_vec_9474);
											mem_vec_9474 = vec_161;

											vec_165 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f + 16]);

											vec_164 = _mm512_fmadd_ps(vec_162, vec_165, mem_vec_9475);
											mem_vec_9475 = vec_164;
											scal_50 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_167 = _mm512_set1_ps(scal_50);


											vec_166 = _mm512_fmadd_ps(vec_167, vec_163, mem_vec_9476);
											mem_vec_9476 = vec_166;



											vec_168 = _mm512_fmadd_ps(vec_167, vec_165, mem_vec_9477);
											mem_vec_9477 = vec_168;
											scal_51 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_170 = _mm512_set1_ps(scal_51);


											vec_169 = _mm512_fmadd_ps(vec_170, vec_163, mem_vec_9478);
											mem_vec_9478 = vec_169;



											vec_171 = _mm512_fmadd_ps(vec_170, vec_165, mem_vec_9479);
											mem_vec_9479 = vec_171;
											scal_52 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_173 = _mm512_set1_ps(scal_52);


											vec_172 = _mm512_fmadd_ps(vec_173, vec_163, mem_vec_9480);
											mem_vec_9480 = vec_172;



											vec_174 = _mm512_fmadd_ps(vec_173, vec_165, mem_vec_9481);
											mem_vec_9481 = vec_174;
											scal_53 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_176 = _mm512_set1_ps(scal_53);


											vec_175 = _mm512_fmadd_ps(vec_176, vec_163, mem_vec_9482);
											mem_vec_9482 = vec_175;



											vec_177 = _mm512_fmadd_ps(vec_176, vec_165, mem_vec_9483);
											mem_vec_9483 = vec_177;
											scal_54 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
											vec_179 = _mm512_set1_ps(scal_54);


											vec_178 = _mm512_fmadd_ps(vec_179, vec_163, mem_vec_9484);
											mem_vec_9484 = vec_178;



											vec_180 = _mm512_fmadd_ps(vec_179, vec_165, mem_vec_9485);
											mem_vec_9485 = vec_180;
											scal_55 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
											vec_182 = _mm512_set1_ps(scal_55);


											vec_181 = _mm512_fmadd_ps(vec_182, vec_163, mem_vec_9486);
											mem_vec_9486 = vec_181;



											vec_183 = _mm512_fmadd_ps(vec_182, vec_165, mem_vec_9487);
											mem_vec_9487 = vec_183;
											scal_56 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_185 = _mm512_set1_ps(scal_56);
											vec_186 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_184 = _mm512_fmadd_ps(vec_185, vec_186, mem_vec_9474);
											mem_vec_9474 = vec_184;

											vec_188 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f + 16]);

											vec_187 = _mm512_fmadd_ps(vec_185, vec_188, mem_vec_9475);
											mem_vec_9475 = vec_187;
											scal_57 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_190 = _mm512_set1_ps(scal_57);


											vec_189 = _mm512_fmadd_ps(vec_190, vec_186, mem_vec_9476);
											mem_vec_9476 = vec_189;



											vec_191 = _mm512_fmadd_ps(vec_190, vec_188, mem_vec_9477);
											mem_vec_9477 = vec_191;
											scal_58 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_193 = _mm512_set1_ps(scal_58);


											vec_192 = _mm512_fmadd_ps(vec_193, vec_186, mem_vec_9478);
											mem_vec_9478 = vec_192;



											vec_194 = _mm512_fmadd_ps(vec_193, vec_188, mem_vec_9479);
											mem_vec_9479 = vec_194;
											scal_59 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_196 = _mm512_set1_ps(scal_59);


											vec_195 = _mm512_fmadd_ps(vec_196, vec_186, mem_vec_9480);
											mem_vec_9480 = vec_195;



											vec_197 = _mm512_fmadd_ps(vec_196, vec_188, mem_vec_9481);
											mem_vec_9481 = vec_197;
											scal_60 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_199 = _mm512_set1_ps(scal_60);


											vec_198 = _mm512_fmadd_ps(vec_199, vec_186, mem_vec_9482);
											mem_vec_9482 = vec_198;



											vec_200 = _mm512_fmadd_ps(vec_199, vec_188, mem_vec_9483);
											mem_vec_9483 = vec_200;
											scal_61 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
											vec_202 = _mm512_set1_ps(scal_61);


											vec_201 = _mm512_fmadd_ps(vec_202, vec_186, mem_vec_9484);
											mem_vec_9484 = vec_201;



											vec_203 = _mm512_fmadd_ps(vec_202, vec_188, mem_vec_9485);
											mem_vec_9485 = vec_203;
											scal_62 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
											vec_205 = _mm512_set1_ps(scal_62);


											vec_204 = _mm512_fmadd_ps(vec_205, vec_186, mem_vec_9486);
											mem_vec_9486 = vec_204;



											vec_206 = _mm512_fmadd_ps(vec_205, vec_188, mem_vec_9487);
											mem_vec_9487 = vec_206;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9474);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9475);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9476);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9477);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9478);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9479);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9480);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9481);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9482);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9483);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9484);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9485);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9486);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9487);
							}
						}
					}
				}
		}
	}
}


}