#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (16, f); T (16, c); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c9_p_0, cp_1, c9, f, fp_0, f12_p_0, f13_p_0, fp_1, f12_p_1, fp_2, f12, f13, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y6 = 0;
IND_TYPE x6 = 0;
IND_TYPE h = 0;
IND_TYPE w6 = 0;
IND_TYPE c10 = 0;
IND_TYPE f14 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_108 ,mem_vec_109 ,mem_vec_110 ,mem_vec_111 ,mem_vec_112 ,mem_vec_113 ,mem_vec_114 ,mem_vec_115 ,mem_vec_116 ,mem_vec_117 ,mem_vec_118 ,mem_vec_119 ,mem_vec_120 ,mem_vec_121 ,mem_vec_122 ,mem_vec_123 ,mem_vec_124 ,mem_vec_125 ,mem_vec_126 ,mem_vec_127 ,mem_vec_128 ,mem_vec_129 ,mem_vec_130 ,mem_vec_131 ,mem_vec_132 ,mem_vec_133 ,mem_vec_134 ,mem_vec_135 ,mem_vec_136 ,mem_vec_137 ,mem_vec_138 ,mem_vec_139 ,mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
for (f13 = f14, f13_p_0 = 0;
	f13 < f14 + 1024;
	f13 += 512, f13_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
	// T (f, 1) (512 / 512)
	for (f12 = f13, f12_p_1 = f13_p_0, f12_p_0 = 0;
		f12 < f13 + 512;
		f12 += 512, f12_p_1 += 512, f12_p_0 += 512){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
		// T (c, 16) (512 / 32)
		for (c9 = c10, c9_p_0 = 0;
			c9 < c10 + 512;
			c9 += 32, c9_p_0 += 32){
			// y = 17, x = 17, h = 3, w = 3, c = 32, f = 512
			// T (f, 16) (512 / 32)
			for (f = f12, fp_2 = f12_p_1, fp_1 = f12_p_0, fp_0 = 0;
				f < f12 + 512;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y6, yp_0 = 0;
						y < y6 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x6, xp_0 = 0;
							x < x6 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w6, wp_0 = 0;
								w < w6 + 3;
								w += 1, wp_0 += 1){
										mem_vec_108 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_109 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_110 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_111 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_112 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_113 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_114 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_115 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_116 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_117 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_118 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_119 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_120 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_121 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_122 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_123 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c9, cp_1 = c9_p_0, cp_0 = 0;
											c < c9 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_108);
											mem_vec_108 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_109);
											mem_vec_109 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_110);
											mem_vec_110 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_111);
											mem_vec_111 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_112);
											mem_vec_112 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_113);
											mem_vec_113 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_114);
											mem_vec_114 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_115);
											mem_vec_115 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_116);
											mem_vec_116 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_117);
											mem_vec_117 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_118);
											mem_vec_118 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_119);
											mem_vec_119 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_120);
											mem_vec_120 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_121);
											mem_vec_121 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_122);
											mem_vec_122 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_123);
											mem_vec_123 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_108);
											mem_vec_108 = vec_24;

											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_109);
											mem_vec_109 = vec_27;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_110);
											mem_vec_110 = vec_29;

											vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_111);
											mem_vec_111 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_34 = _mm256_set1_ps(scal_5);


											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_112);
											mem_vec_112 = vec_33;



											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_113);
											mem_vec_113 = vec_35;



											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_114);
											mem_vec_114 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_115);
											mem_vec_115 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_116);
											mem_vec_116 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_117);
											mem_vec_117 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_118);
											mem_vec_118 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_119);
											mem_vec_119 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_120);
											mem_vec_120 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_121);
											mem_vec_121 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_122);
											mem_vec_122 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_123);
											mem_vec_123 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_108);
											mem_vec_108 = vec_48;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_109);
											mem_vec_109 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_110);
											mem_vec_110 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_111);
											mem_vec_111 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_58 = _mm256_set1_ps(scal_9);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_112);
											mem_vec_112 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_113);
											mem_vec_113 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_114);
											mem_vec_114 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_115);
											mem_vec_115 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_63 = _mm256_set1_ps(scal_10);


											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_116);
											mem_vec_116 = vec_62;



											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_117);
											mem_vec_117 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_118);
											mem_vec_118 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_119);
											mem_vec_119 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_120);
											mem_vec_120 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_121);
											mem_vec_121 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_122);
											mem_vec_122 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_123);
											mem_vec_123 = vec_71;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_108);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_109);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_110);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_111);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_112);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_113);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_114);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_115);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_116);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_117);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_118);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_119);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_120);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_121);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_122);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_123);
							}
						}
					}
					for (y = y6 + 12, yp_0 = 0;
						y < y6 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x6, xp_0 = 0;
							x < x6 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w6, wp_0 = 0;
								w < w6 + 3;
								w += 1, wp_0 += 1){
										mem_vec_124 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_125 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_126 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_127 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_128 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_129 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_130 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_131 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_132 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_133 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_134 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_135 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_136 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_137 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_138 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_139 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_140 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_141 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_142 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_143 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c9, cp_1 = c9_p_0, cp_0 = 0;
											c < c9 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_124);
											mem_vec_124 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_125);
											mem_vec_125 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_126);
											mem_vec_126 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_127);
											mem_vec_127 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_128);
											mem_vec_128 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_129);
											mem_vec_129 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_130);
											mem_vec_130 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_131);
											mem_vec_131 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_132);
											mem_vec_132 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_133);
											mem_vec_133 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_134);
											mem_vec_134 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_135);
											mem_vec_135 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_136);
											mem_vec_136 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_137);
											mem_vec_137 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_138);
											mem_vec_138 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_139);
											mem_vec_139 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_140);
											mem_vec_140 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_141);
											mem_vec_141 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_142);
											mem_vec_142 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_143);
											mem_vec_143 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_124);
											mem_vec_124 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_125);
											mem_vec_125 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_126);
											mem_vec_126 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_127);
											mem_vec_127 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_128);
											mem_vec_128 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_129);
											mem_vec_129 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_130);
											mem_vec_130 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_131);
											mem_vec_131 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_132);
											mem_vec_132 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_133);
											mem_vec_133 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_134);
											mem_vec_134 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_135);
											mem_vec_135 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_136);
											mem_vec_136 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_137);
											mem_vec_137 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_138);
											mem_vec_138 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_139);
											mem_vec_139 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_140);
											mem_vec_140 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_141);
											mem_vec_141 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_142);
											mem_vec_142 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_143);
											mem_vec_143 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_124);
											mem_vec_124 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_125);
											mem_vec_125 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_126);
											mem_vec_126 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_127);
											mem_vec_127 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_128);
											mem_vec_128 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_129);
											mem_vec_129 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_130);
											mem_vec_130 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_131);
											mem_vec_131 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_132);
											mem_vec_132 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_133);
											mem_vec_133 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_134);
											mem_vec_134 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_135);
											mem_vec_135 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_136);
											mem_vec_136 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_137);
											mem_vec_137 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_138);
											mem_vec_138 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_139);
											mem_vec_139 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_140);
											mem_vec_140 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_141);
											mem_vec_141 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_142);
											mem_vec_142 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_143);
											mem_vec_143 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_124);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_125);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_126);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_127);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_128);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_129);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_130);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_131);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_132);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_133);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_134);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_135);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_136);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_137);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_138);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_139);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_140);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_141);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_142);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_143);
							}
						}
					}
			}
		}
	}
}


}