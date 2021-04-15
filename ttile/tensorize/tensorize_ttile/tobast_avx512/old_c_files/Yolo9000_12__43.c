#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); U (3, w); T (4, c); Hoist_vars [c];
  T (2, x); T (8, c); T (17, x);
  Lambda_apply y [((Iter 5), (Arg 5)); ((Iter 1), (Arg 9))]; T (32, f);
  T (8, c); T (1, x)]
*/
IND_TYPE c, cp_0, c894_p_0, c895_p_0, cp_1, c894_p_1, cp_2, c894, c895, f, fp_0, x, xp_0, x894_p_0, x895_p_0, xp_1, x894_p_1, xp_2, x894, x895, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y544 = 0;
IND_TYPE x896 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c896 = 0;
IND_TYPE f932 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_45 ,scal_46 ,scal_47 ,scal_48 ,scal_49 ,scal_5 ,scal_50 ,scal_51 ,scal_52 ,scal_53 ,scal_54 ,scal_55 ,scal_56 ,scal_57 ,scal_58 ,scal_59 ,scal_6 ,scal_60 ,scal_61 ,scal_62 ,scal_63 ,scal_64 ,scal_65 ,scal_66 ,scal_67 ,scal_68 ,scal_69 ,scal_7 ,scal_70 ,scal_71 ,scal_72 ,scal_73 ,scal_74 ,scal_75 ,scal_76 ,scal_77 ,scal_78 ,scal_79 ,scal_8 ,scal_80 ,scal_9;
__m512 mem_vec_8164 ,mem_vec_8165 ,mem_vec_8166 ,mem_vec_8167 ,mem_vec_8168 ,mem_vec_8169 ,mem_vec_8170 ,mem_vec_8171 ,mem_vec_8172 ,mem_vec_8173 ,mem_vec_8174 ,mem_vec_8175 ,mem_vec_8176 ,mem_vec_8177 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_132 ,vec_133 ,vec_134 ,vec_135 ,vec_136 ,vec_137 ,vec_138 ,vec_139 ,vec_14 ,vec_140 ,vec_141 ,vec_142 ,vec_143 ,vec_144 ,vec_145 ,vec_146 ,vec_147 ,vec_148 ,vec_149 ,vec_15 ,vec_150 ,vec_151 ,vec_152 ,vec_153 ,vec_154 ,vec_155 ,vec_156 ,vec_157 ,vec_158 ,vec_159 ,vec_16 ,vec_160 ,vec_161 ,vec_162 ,vec_163 ,vec_164 ,vec_165 ,vec_166 ,vec_167 ,vec_168 ,vec_169 ,vec_17 ,vec_170 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (x, 1) (34 / 34)
for (x895 = x896, x895_p_0 = 0;
	x895 < x896 + 34;
	x895 += 34, x895_p_0 += 34){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 8) (256 / 32)
	for (c895 = c896, c895_p_0 = 0;
		c895 < c896 + 256;
		c895 += 32, c895_p_0 += 32){
		// y = 34, x = 34, h = 3, w = 3, c = 32, f = 512
		// T (f, 32) (512 / 16)
		for (f = f932, fp_0 = 0;
			f < f932 + 512;
			f += 16, fp_0 += 16){
				for (y = y544, yp_0 = 0;
					y < y544 + 25;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 16
					// T (x, 17) (34 / 2)
					for (x894 = x895, x894_p_1 = x895_p_0, x894_p_0 = 0;
						x894 < x895 + 34;
						x894 += 2, x894_p_1 += 2, x894_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 16
						// T (c, 8) (32 / 4)
						for (c894 = c895, c894_p_1 = c895_p_0, c894_p_0 = 0;
							c894 < c895 + 32;
							c894 += 4, c894_p_1 += 4, c894_p_0 += 4){
							// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 16
							// T (x, 2) (2 / 1)
							for (x = x894, xp_2 = x894_p_1, xp_1 = x894_p_0, xp_0 = 0;
								x < x894 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8164 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 16
										// T (c, 4) (4 / 1)
										for (c = c894, cp_2 = c894_p_1, cp_1 = c894_p_0, cp_0 = 0;
											c < c894 + 4;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8164);
											mem_vec_8164 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_8165);
											mem_vec_8165 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8166);
											mem_vec_8166 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_8167);
											mem_vec_8167 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8168);
											mem_vec_8168 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_12 = _mm512_set1_ps(scal_5);
											vec_13 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_11 = _mm512_fmadd_ps(vec_12, vec_13, mem_vec_8164);
											mem_vec_8164 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_15 = _mm512_set1_ps(scal_6);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_13, mem_vec_8165);
											mem_vec_8165 = vec_14;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_17 = _mm512_set1_ps(scal_7);


											vec_16 = _mm512_fmadd_ps(vec_17, vec_13, mem_vec_8166);
											mem_vec_8166 = vec_16;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_19 = _mm512_set1_ps(scal_8);


											vec_18 = _mm512_fmadd_ps(vec_19, vec_13, mem_vec_8167);
											mem_vec_8167 = vec_18;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_21 = _mm512_set1_ps(scal_9);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_13, mem_vec_8168);
											mem_vec_8168 = vec_20;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_23 = _mm512_set1_ps(scal_10);
											vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_22 = _mm512_fmadd_ps(vec_23, vec_24, mem_vec_8164);
											mem_vec_8164 = vec_22;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_26 = _mm512_set1_ps(scal_11);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_8165);
											mem_vec_8165 = vec_25;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_28 = _mm512_set1_ps(scal_12);


											vec_27 = _mm512_fmadd_ps(vec_28, vec_24, mem_vec_8166);
											mem_vec_8166 = vec_27;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_30 = _mm512_set1_ps(scal_13);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_24, mem_vec_8167);
											mem_vec_8167 = vec_29;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_32 = _mm512_set1_ps(scal_14);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_8168);
											mem_vec_8168 = vec_31;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_34 = _mm512_set1_ps(scal_15);
											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_33 = _mm512_fmadd_ps(vec_34, vec_35, mem_vec_8164);
											mem_vec_8164 = vec_33;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_37 = _mm512_set1_ps(scal_16);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_35, mem_vec_8165);
											mem_vec_8165 = vec_36;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm512_set1_ps(scal_17);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_8166);
											mem_vec_8166 = vec_38;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_41 = _mm512_set1_ps(scal_18);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_35, mem_vec_8167);
											mem_vec_8167 = vec_40;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_43 = _mm512_set1_ps(scal_19);


											vec_42 = _mm512_fmadd_ps(vec_43, vec_35, mem_vec_8168);
											mem_vec_8168 = vec_42;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_45 = _mm512_set1_ps(scal_20);
											vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_44 = _mm512_fmadd_ps(vec_45, vec_46, mem_vec_8164);
											mem_vec_8164 = vec_44;
											scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_48 = _mm512_set1_ps(scal_21);


											vec_47 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_8165);
											mem_vec_8165 = vec_47;
											scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_22);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_46, mem_vec_8166);
											mem_vec_8166 = vec_49;
											scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_52 = _mm512_set1_ps(scal_23);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_46, mem_vec_8167);
											mem_vec_8167 = vec_51;
											scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_24);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_46, mem_vec_8168);
											mem_vec_8168 = vec_53;
											scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_56 = _mm512_set1_ps(scal_25);
											vec_57 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_55 = _mm512_fmadd_ps(vec_56, vec_57, mem_vec_8164);
											mem_vec_8164 = vec_55;
											scal_26 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_26);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_57, mem_vec_8165);
											mem_vec_8165 = vec_58;
											scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_61 = _mm512_set1_ps(scal_27);


											vec_60 = _mm512_fmadd_ps(vec_61, vec_57, mem_vec_8166);
											mem_vec_8166 = vec_60;
											scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_63 = _mm512_set1_ps(scal_28);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_57, mem_vec_8167);
											mem_vec_8167 = vec_62;
											scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_65 = _mm512_set1_ps(scal_29);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_57, mem_vec_8168);
											mem_vec_8168 = vec_64;
											scal_30 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_67 = _mm512_set1_ps(scal_30);
											vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_66 = _mm512_fmadd_ps(vec_67, vec_68, mem_vec_8164);
											mem_vec_8164 = vec_66;
											scal_31 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_70 = _mm512_set1_ps(scal_31);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_8165);
											mem_vec_8165 = vec_69;
											scal_32 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_72 = _mm512_set1_ps(scal_32);


											vec_71 = _mm512_fmadd_ps(vec_72, vec_68, mem_vec_8166);
											mem_vec_8166 = vec_71;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_74 = _mm512_set1_ps(scal_33);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_68, mem_vec_8167);
											mem_vec_8167 = vec_73;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_76 = _mm512_set1_ps(scal_34);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_8168);
											mem_vec_8168 = vec_75;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_78 = _mm512_set1_ps(scal_35);
											vec_79 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_77 = _mm512_fmadd_ps(vec_78, vec_79, mem_vec_8164);
											mem_vec_8164 = vec_77;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_81 = _mm512_set1_ps(scal_36);


											vec_80 = _mm512_fmadd_ps(vec_81, vec_79, mem_vec_8165);
											mem_vec_8165 = vec_80;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_83 = _mm512_set1_ps(scal_37);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_79, mem_vec_8166);
											mem_vec_8166 = vec_82;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_85 = _mm512_set1_ps(scal_38);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_79, mem_vec_8167);
											mem_vec_8167 = vec_84;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_87 = _mm512_set1_ps(scal_39);


											vec_86 = _mm512_fmadd_ps(vec_87, vec_79, mem_vec_8168);
											mem_vec_8168 = vec_86;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_89 = _mm512_set1_ps(scal_40);
											vec_90 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_88 = _mm512_fmadd_ps(vec_89, vec_90, mem_vec_8164);
											mem_vec_8164 = vec_88;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_92 = _mm512_set1_ps(scal_41);


											vec_91 = _mm512_fmadd_ps(vec_92, vec_90, mem_vec_8165);
											mem_vec_8165 = vec_91;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_42);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_90, mem_vec_8166);
											mem_vec_8166 = vec_93;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_96 = _mm512_set1_ps(scal_43);


											vec_95 = _mm512_fmadd_ps(vec_96, vec_90, mem_vec_8167);
											mem_vec_8167 = vec_95;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_98 = _mm512_set1_ps(scal_44);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_90, mem_vec_8168);
											mem_vec_8168 = vec_97;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8164);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8165);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8166);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8167);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8168);
							}
						}
					}
				}
				for (y = y544 + 25, yp_0 = 0;
					y < y544 + 25 + 9;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 16
					// T (x, 17) (34 / 2)
					for (x894 = x895, x894_p_1 = x895_p_0, x894_p_0 = 0;
						x894 < x895 + 34;
						x894 += 2, x894_p_1 += 2, x894_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 16
						// T (c, 8) (32 / 4)
						for (c894 = c895, c894_p_1 = c895_p_0, c894_p_0 = 0;
							c894 < c895 + 32;
							c894 += 4, c894_p_1 += 4, c894_p_0 += 4){
							// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 16
							// T (x, 2) (2 / 1)
							for (x = x894, xp_2 = x894_p_1, xp_1 = x894_p_0, xp_0 = 0;
								x < x894 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8169 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 16
										// T (c, 4) (4 / 1)
										for (c = c894, cp_2 = c894_p_1, cp_1 = c894_p_0, cp_0 = 0;
											c < c894 + 4;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8169);
											mem_vec_8169 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_8170);
											mem_vec_8170 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8171);
											mem_vec_8171 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_8172);
											mem_vec_8172 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8173);
											mem_vec_8173 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8174);
											mem_vec_8174 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);


											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_8175);
											mem_vec_8175 = vec_13;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_8176);
											mem_vec_8176 = vec_15;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8177);
											mem_vec_8177 = vec_17;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_20 = _mm512_set1_ps(scal_9);
											vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_8169);
											mem_vec_8169 = vec_19;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_23 = _mm512_set1_ps(scal_10);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_8170);
											mem_vec_8170 = vec_22;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_25 = _mm512_set1_ps(scal_11);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_21, mem_vec_8171);
											mem_vec_8171 = vec_24;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_27 = _mm512_set1_ps(scal_12);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_21, mem_vec_8172);
											mem_vec_8172 = vec_26;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_13);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_8173);
											mem_vec_8173 = vec_28;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);


											vec_30 = _mm512_fmadd_ps(vec_31, vec_21, mem_vec_8174);
											mem_vec_8174 = vec_30;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_21, mem_vec_8175);
											mem_vec_8175 = vec_32;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_21, mem_vec_8176);
											mem_vec_8176 = vec_34;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_21, mem_vec_8177);
											mem_vec_8177 = vec_36;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_39 = _mm512_set1_ps(scal_18);
											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_8169);
											mem_vec_8169 = vec_38;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_42 = _mm512_set1_ps(scal_19);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_40, mem_vec_8170);
											mem_vec_8170 = vec_41;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_44 = _mm512_set1_ps(scal_20);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_8171);
											mem_vec_8171 = vec_43;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_46 = _mm512_set1_ps(scal_21);


											vec_45 = _mm512_fmadd_ps(vec_46, vec_40, mem_vec_8172);
											mem_vec_8172 = vec_45;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_48 = _mm512_set1_ps(scal_22);


											vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_8173);
											mem_vec_8173 = vec_47;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_50 = _mm512_set1_ps(scal_23);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_8174);
											mem_vec_8174 = vec_49;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_52 = _mm512_set1_ps(scal_24);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_40, mem_vec_8175);
											mem_vec_8175 = vec_51;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_54 = _mm512_set1_ps(scal_25);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_8176);
											mem_vec_8176 = vec_53;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_56 = _mm512_set1_ps(scal_26);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_8177);
											mem_vec_8177 = vec_55;
											scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_58 = _mm512_set1_ps(scal_27);
											vec_59 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_57 = _mm512_fmadd_ps(vec_58, vec_59, mem_vec_8169);
											mem_vec_8169 = vec_57;
											scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_61 = _mm512_set1_ps(scal_28);


											vec_60 = _mm512_fmadd_ps(vec_61, vec_59, mem_vec_8170);
											mem_vec_8170 = vec_60;
											scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_63 = _mm512_set1_ps(scal_29);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_59, mem_vec_8171);
											mem_vec_8171 = vec_62;
											scal_30 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_65 = _mm512_set1_ps(scal_30);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_59, mem_vec_8172);
											mem_vec_8172 = vec_64;
											scal_31 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_67 = _mm512_set1_ps(scal_31);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_59, mem_vec_8173);
											mem_vec_8173 = vec_66;
											scal_32 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_69 = _mm512_set1_ps(scal_32);


											vec_68 = _mm512_fmadd_ps(vec_69, vec_59, mem_vec_8174);
											mem_vec_8174 = vec_68;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_71 = _mm512_set1_ps(scal_33);


											vec_70 = _mm512_fmadd_ps(vec_71, vec_59, mem_vec_8175);
											mem_vec_8175 = vec_70;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
											vec_73 = _mm512_set1_ps(scal_34);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_59, mem_vec_8176);
											mem_vec_8176 = vec_72;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
											vec_75 = _mm512_set1_ps(scal_35);


											vec_74 = _mm512_fmadd_ps(vec_75, vec_59, mem_vec_8177);
											mem_vec_8177 = vec_74;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_77 = _mm512_set1_ps(scal_36);
											vec_78 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_76 = _mm512_fmadd_ps(vec_77, vec_78, mem_vec_8169);
											mem_vec_8169 = vec_76;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_80 = _mm512_set1_ps(scal_37);


											vec_79 = _mm512_fmadd_ps(vec_80, vec_78, mem_vec_8170);
											mem_vec_8170 = vec_79;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_82 = _mm512_set1_ps(scal_38);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_78, mem_vec_8171);
											mem_vec_8171 = vec_81;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_84 = _mm512_set1_ps(scal_39);


											vec_83 = _mm512_fmadd_ps(vec_84, vec_78, mem_vec_8172);
											mem_vec_8172 = vec_83;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_86 = _mm512_set1_ps(scal_40);


											vec_85 = _mm512_fmadd_ps(vec_86, vec_78, mem_vec_8173);
											mem_vec_8173 = vec_85;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
											vec_88 = _mm512_set1_ps(scal_41);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_8174);
											mem_vec_8174 = vec_87;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
											vec_90 = _mm512_set1_ps(scal_42);


											vec_89 = _mm512_fmadd_ps(vec_90, vec_78, mem_vec_8175);
											mem_vec_8175 = vec_89;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 1) + c];
											vec_92 = _mm512_set1_ps(scal_43);


											vec_91 = _mm512_fmadd_ps(vec_92, vec_78, mem_vec_8176);
											mem_vec_8176 = vec_91;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 1) + c];
											vec_94 = _mm512_set1_ps(scal_44);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_78, mem_vec_8177);
											mem_vec_8177 = vec_93;
											scal_45 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_96 = _mm512_set1_ps(scal_45);
											vec_97 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_95 = _mm512_fmadd_ps(vec_96, vec_97, mem_vec_8169);
											mem_vec_8169 = vec_95;
											scal_46 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_99 = _mm512_set1_ps(scal_46);


											vec_98 = _mm512_fmadd_ps(vec_99, vec_97, mem_vec_8170);
											mem_vec_8170 = vec_98;
											scal_47 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_101 = _mm512_set1_ps(scal_47);


											vec_100 = _mm512_fmadd_ps(vec_101, vec_97, mem_vec_8171);
											mem_vec_8171 = vec_100;
											scal_48 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_48);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_97, mem_vec_8172);
											mem_vec_8172 = vec_102;
											scal_49 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_105 = _mm512_set1_ps(scal_49);


											vec_104 = _mm512_fmadd_ps(vec_105, vec_97, mem_vec_8173);
											mem_vec_8173 = vec_104;
											scal_50 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
											vec_107 = _mm512_set1_ps(scal_50);


											vec_106 = _mm512_fmadd_ps(vec_107, vec_97, mem_vec_8174);
											mem_vec_8174 = vec_106;
											scal_51 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
											vec_109 = _mm512_set1_ps(scal_51);


											vec_108 = _mm512_fmadd_ps(vec_109, vec_97, mem_vec_8175);
											mem_vec_8175 = vec_108;
											scal_52 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h + 2) + c];
											vec_111 = _mm512_set1_ps(scal_52);


											vec_110 = _mm512_fmadd_ps(vec_111, vec_97, mem_vec_8176);
											mem_vec_8176 = vec_110;
											scal_53 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h + 2) + c];
											vec_113 = _mm512_set1_ps(scal_53);


											vec_112 = _mm512_fmadd_ps(vec_113, vec_97, mem_vec_8177);
											mem_vec_8177 = vec_112;
											scal_54 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_115 = _mm512_set1_ps(scal_54);
											vec_116 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_114 = _mm512_fmadd_ps(vec_115, vec_116, mem_vec_8169);
											mem_vec_8169 = vec_114;
											scal_55 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_118 = _mm512_set1_ps(scal_55);


											vec_117 = _mm512_fmadd_ps(vec_118, vec_116, mem_vec_8170);
											mem_vec_8170 = vec_117;
											scal_56 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_120 = _mm512_set1_ps(scal_56);


											vec_119 = _mm512_fmadd_ps(vec_120, vec_116, mem_vec_8171);
											mem_vec_8171 = vec_119;
											scal_57 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_122 = _mm512_set1_ps(scal_57);


											vec_121 = _mm512_fmadd_ps(vec_122, vec_116, mem_vec_8172);
											mem_vec_8172 = vec_121;
											scal_58 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_124 = _mm512_set1_ps(scal_58);


											vec_123 = _mm512_fmadd_ps(vec_124, vec_116, mem_vec_8173);
											mem_vec_8173 = vec_123;
											scal_59 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_126 = _mm512_set1_ps(scal_59);


											vec_125 = _mm512_fmadd_ps(vec_126, vec_116, mem_vec_8174);
											mem_vec_8174 = vec_125;
											scal_60 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_128 = _mm512_set1_ps(scal_60);


											vec_127 = _mm512_fmadd_ps(vec_128, vec_116, mem_vec_8175);
											mem_vec_8175 = vec_127;
											scal_61 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
											vec_130 = _mm512_set1_ps(scal_61);


											vec_129 = _mm512_fmadd_ps(vec_130, vec_116, mem_vec_8176);
											mem_vec_8176 = vec_129;
											scal_62 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
											vec_132 = _mm512_set1_ps(scal_62);


											vec_131 = _mm512_fmadd_ps(vec_132, vec_116, mem_vec_8177);
											mem_vec_8177 = vec_131;
											scal_63 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_134 = _mm512_set1_ps(scal_63);
											vec_135 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_133 = _mm512_fmadd_ps(vec_134, vec_135, mem_vec_8169);
											mem_vec_8169 = vec_133;
											scal_64 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_137 = _mm512_set1_ps(scal_64);


											vec_136 = _mm512_fmadd_ps(vec_137, vec_135, mem_vec_8170);
											mem_vec_8170 = vec_136;
											scal_65 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_139 = _mm512_set1_ps(scal_65);


											vec_138 = _mm512_fmadd_ps(vec_139, vec_135, mem_vec_8171);
											mem_vec_8171 = vec_138;
											scal_66 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_141 = _mm512_set1_ps(scal_66);


											vec_140 = _mm512_fmadd_ps(vec_141, vec_135, mem_vec_8172);
											mem_vec_8172 = vec_140;
											scal_67 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_143 = _mm512_set1_ps(scal_67);


											vec_142 = _mm512_fmadd_ps(vec_143, vec_135, mem_vec_8173);
											mem_vec_8173 = vec_142;
											scal_68 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
											vec_145 = _mm512_set1_ps(scal_68);


											vec_144 = _mm512_fmadd_ps(vec_145, vec_135, mem_vec_8174);
											mem_vec_8174 = vec_144;
											scal_69 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
											vec_147 = _mm512_set1_ps(scal_69);


											vec_146 = _mm512_fmadd_ps(vec_147, vec_135, mem_vec_8175);
											mem_vec_8175 = vec_146;
											scal_70 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 1) + c];
											vec_149 = _mm512_set1_ps(scal_70);


											vec_148 = _mm512_fmadd_ps(vec_149, vec_135, mem_vec_8176);
											mem_vec_8176 = vec_148;
											scal_71 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 1) + c];
											vec_151 = _mm512_set1_ps(scal_71);


											vec_150 = _mm512_fmadd_ps(vec_151, vec_135, mem_vec_8177);
											mem_vec_8177 = vec_150;
											scal_72 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_153 = _mm512_set1_ps(scal_72);
											vec_154 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_152 = _mm512_fmadd_ps(vec_153, vec_154, mem_vec_8169);
											mem_vec_8169 = vec_152;
											scal_73 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_156 = _mm512_set1_ps(scal_73);


											vec_155 = _mm512_fmadd_ps(vec_156, vec_154, mem_vec_8170);
											mem_vec_8170 = vec_155;
											scal_74 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_158 = _mm512_set1_ps(scal_74);


											vec_157 = _mm512_fmadd_ps(vec_158, vec_154, mem_vec_8171);
											mem_vec_8171 = vec_157;
											scal_75 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_160 = _mm512_set1_ps(scal_75);


											vec_159 = _mm512_fmadd_ps(vec_160, vec_154, mem_vec_8172);
											mem_vec_8172 = vec_159;
											scal_76 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_162 = _mm512_set1_ps(scal_76);


											vec_161 = _mm512_fmadd_ps(vec_162, vec_154, mem_vec_8173);
											mem_vec_8173 = vec_161;
											scal_77 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
											vec_164 = _mm512_set1_ps(scal_77);


											vec_163 = _mm512_fmadd_ps(vec_164, vec_154, mem_vec_8174);
											mem_vec_8174 = vec_163;
											scal_78 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
											vec_166 = _mm512_set1_ps(scal_78);


											vec_165 = _mm512_fmadd_ps(vec_166, vec_154, mem_vec_8175);
											mem_vec_8175 = vec_165;
											scal_79 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h + 2) + c];
											vec_168 = _mm512_set1_ps(scal_79);


											vec_167 = _mm512_fmadd_ps(vec_168, vec_154, mem_vec_8176);
											mem_vec_8176 = vec_167;
											scal_80 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h + 2) + c];
											vec_170 = _mm512_set1_ps(scal_80);


											vec_169 = _mm512_fmadd_ps(vec_170, vec_154, mem_vec_8177);
											mem_vec_8177 = vec_169;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8169);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8170);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8171);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8172);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8173);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8174);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8175);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8176);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8177);
							}
						}
					}
				}
		}
	}
}


}