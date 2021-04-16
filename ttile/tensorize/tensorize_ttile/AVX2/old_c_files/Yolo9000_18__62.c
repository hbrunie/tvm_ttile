#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (17, x); Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))];
  T (16, f); T (16, c); T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c12_p_0, cp_1, c12, f, fp_0, f16_p_0, f17_p_0, fp_1, f16_p_1, fp_2, f16, f17, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y8 = 0;
IND_TYPE x8 = 0;
IND_TYPE h = 0;
IND_TYPE w8 = 0;
IND_TYPE c13 = 0;
IND_TYPE f18 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_144 ,mem_vec_145 ,mem_vec_146 ,mem_vec_147 ,mem_vec_148 ,mem_vec_149 ,mem_vec_150 ,mem_vec_151 ,mem_vec_152 ,mem_vec_153 ,mem_vec_154 ,mem_vec_155 ,mem_vec_156 ,mem_vec_157 ,mem_vec_158 ,mem_vec_159 ,mem_vec_160 ,mem_vec_161 ,mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,mem_vec_168 ,mem_vec_169 ,mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,mem_vec_176 ,mem_vec_177 ,mem_vec_178 ,mem_vec_179 ,mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,mem_vec_184 ,mem_vec_185 ,mem_vec_186 ,mem_vec_187 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 1) (1024 / 1024)
for (f17 = f18, f17_p_0 = 0;
	f17 < f18 + 1024;
	f17 += 1024, f17_p_0 += 1024){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (f, 2) (1024 / 512)
	for (f16 = f17, f16_p_1 = f17_p_0, f16_p_0 = 0;
		f16 < f17 + 1024;
		f16 += 512, f16_p_1 += 512, f16_p_0 += 512){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
		// T (c, 16) (512 / 32)
		for (c12 = c13, c12_p_0 = 0;
			c12 < c13 + 512;
			c12 += 32, c12_p_0 += 32){
			// y = 17, x = 17, h = 3, w = 3, c = 32, f = 512
			// T (f, 16) (512 / 32)
			for (f = f16, fp_2 = f16_p_1, fp_1 = f16_p_0, fp_0 = 0;
				f < f16 + 512;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y8, yp_0 = 0;
						y < y8 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x8, xp_0 = 0;
							x < x8 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w8, wp_0 = 0;
								w < w8 + 3;
								w += 1, wp_0 += 1){
										mem_vec_144 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_145 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_146 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_147 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_148 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_149 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_150 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_151 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_152 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_153 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_154 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_155 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_156 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_157 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_158 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_159 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_160 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_161 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_162 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_163 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c12, cp_1 = c12_p_0, cp_0 = 0;
											c < c12 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_144);
											mem_vec_144 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_145);
											mem_vec_145 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_146);
											mem_vec_146 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_147);
											mem_vec_147 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_148);
											mem_vec_148 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_149);
											mem_vec_149 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_150);
											mem_vec_150 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_151);
											mem_vec_151 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_152);
											mem_vec_152 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_153);
											mem_vec_153 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_154);
											mem_vec_154 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_155);
											mem_vec_155 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_156);
											mem_vec_156 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_157);
											mem_vec_157 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_158);
											mem_vec_158 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_159);
											mem_vec_159 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_160);
											mem_vec_160 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_161);
											mem_vec_161 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_162);
											mem_vec_162 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_163);
											mem_vec_163 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_144);
											mem_vec_144 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_145);
											mem_vec_145 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_146);
											mem_vec_146 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_147);
											mem_vec_147 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_148);
											mem_vec_148 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_149);
											mem_vec_149 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_150);
											mem_vec_150 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_151);
											mem_vec_151 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_152);
											mem_vec_152 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_153);
											mem_vec_153 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_154);
											mem_vec_154 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_155);
											mem_vec_155 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_156);
											mem_vec_156 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_157);
											mem_vec_157 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_158);
											mem_vec_158 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_159);
											mem_vec_159 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_160);
											mem_vec_160 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_161);
											mem_vec_161 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_162);
											mem_vec_162 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_163);
											mem_vec_163 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_144);
											mem_vec_144 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_145);
											mem_vec_145 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_146);
											mem_vec_146 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_147);
											mem_vec_147 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_148);
											mem_vec_148 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_149);
											mem_vec_149 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_150);
											mem_vec_150 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_151);
											mem_vec_151 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_152);
											mem_vec_152 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_153);
											mem_vec_153 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_154);
											mem_vec_154 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_155);
											mem_vec_155 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_156);
											mem_vec_156 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_157);
											mem_vec_157 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_158);
											mem_vec_158 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_159);
											mem_vec_159 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_160);
											mem_vec_160 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_161);
											mem_vec_161 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_162);
											mem_vec_162 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_163);
											mem_vec_163 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_144);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_145);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_146);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_147);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_148);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_149);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_150);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_151);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_152);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_153);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_154);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_155);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_156);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_157);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_158);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_159);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_160);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_161);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_162);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_163);
							}
						}
					}
					for (y = y8 + 5, yp_0 = 0;
						y < y8 + 5 + 12;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x8, xp_0 = 0;
							x < x8 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w8, wp_0 = 0;
								w < w8 + 3;
								w += 1, wp_0 += 1){
										mem_vec_164 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_165 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_166 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_167 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_168 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_169 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_170 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_171 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_172 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_173 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_174 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_175 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_176 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_177 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_178 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_179 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_180 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_181 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_182 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_183 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_184 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_185 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_186 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_187 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c12, cp_1 = c12_p_0, cp_0 = 0;
											c < c12 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_164);
											mem_vec_164 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_165);
											mem_vec_165 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_166);
											mem_vec_166 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_167);
											mem_vec_167 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_168);
											mem_vec_168 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_169);
											mem_vec_169 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_170);
											mem_vec_170 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_171);
											mem_vec_171 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_172);
											mem_vec_172 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_173);
											mem_vec_173 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_174);
											mem_vec_174 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_175);
											mem_vec_175 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_176);
											mem_vec_176 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_177);
											mem_vec_177 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_178);
											mem_vec_178 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_179);
											mem_vec_179 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_180);
											mem_vec_180 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_181);
											mem_vec_181 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_182);
											mem_vec_182 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_183);
											mem_vec_183 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_184);
											mem_vec_184 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_185);
											mem_vec_185 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_186);
											mem_vec_186 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_187);
											mem_vec_187 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_164);
											mem_vec_164 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_165);
											mem_vec_165 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_166);
											mem_vec_166 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_167);
											mem_vec_167 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_168);
											mem_vec_168 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_169);
											mem_vec_169 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_170);
											mem_vec_170 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_171);
											mem_vec_171 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_172);
											mem_vec_172 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_173);
											mem_vec_173 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_174);
											mem_vec_174 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_175);
											mem_vec_175 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_176);
											mem_vec_176 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_177);
											mem_vec_177 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_178);
											mem_vec_178 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_179);
											mem_vec_179 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_180);
											mem_vec_180 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_181);
											mem_vec_181 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_182);
											mem_vec_182 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_183);
											mem_vec_183 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_184);
											mem_vec_184 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_185);
											mem_vec_185 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_186);
											mem_vec_186 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_187);
											mem_vec_187 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_164);
											mem_vec_164 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_165);
											mem_vec_165 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_166);
											mem_vec_166 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_167);
											mem_vec_167 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_168);
											mem_vec_168 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_169);
											mem_vec_169 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_170);
											mem_vec_170 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_171);
											mem_vec_171 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_172);
											mem_vec_172 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_173);
											mem_vec_173 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_174);
											mem_vec_174 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_175);
											mem_vec_175 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_176);
											mem_vec_176 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_177);
											mem_vec_177 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_178);
											mem_vec_178 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_179);
											mem_vec_179 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_180);
											mem_vec_180 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_181);
											mem_vec_181 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_182);
											mem_vec_182 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_183);
											mem_vec_183 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_184);
											mem_vec_184 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_185);
											mem_vec_185 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_186);
											mem_vec_186 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_187);
											mem_vec_187 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_164);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_165);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_166);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_167);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_168);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_169);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_170);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_171);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_172);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_173);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_174);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_175);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_176);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_177);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_178);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_179);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_180);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_181);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_182);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_183);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_184);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_185);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_186);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_187);
							}
						}
					}
			}
		}
	}
}


}