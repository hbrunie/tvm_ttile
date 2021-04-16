#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (28, x); T (1, c); T (1, f); T (7, y); T (4, f); T (8, c); T (2, f)]
*/
IND_TYPE c, cp_0, c34_p_0, c35_p_0, cp_1, c34_p_1, cp_2, c34, c35, f, fp_0, f34_p_0, f35_p_0, fp_1, f34_p_1, fp_2, f34, f35, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y20 = 0;
IND_TYPE x18 = 0;
IND_TYPE h = 0;
IND_TYPE w14 = 0;
IND_TYPE c36 = 0;
IND_TYPE f36 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_176 ,mem_vec_177 ,mem_vec_178 ,mem_vec_179 ,mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,mem_vec_184 ,mem_vec_185 ,mem_vec_186 ,mem_vec_187 ,mem_vec_188 ,mem_vec_189 ,mem_vec_190 ,mem_vec_191 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f35 = f36, f35_p_0 = 0;
	f35 < f36 + 256;
	f35 += 128, f35_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 128
	// T (c, 8) (256 / 32)
	for (c35 = c36, c35_p_0 = 0;
		c35 < c36 + 256;
		c35 += 32, c35_p_0 += 32){
		// y = 28, x = 28, h = 3, w = 3, c = 32, f = 128
		// T (f, 4) (128 / 32)
		for (f34 = f35, f34_p_1 = f35_p_0, f34_p_0 = 0;
			f34 < f35 + 128;
			f34 += 32, f34_p_1 += 32, f34_p_0 += 32){
			// y = 28, x = 28, h = 3, w = 3, c = 32, f = 32
			// T (y, 7) (28 / 4)
			for (y = y20, yp_0 = 0;
				y < y20 + 28;
				y += 4, yp_0 += 4){
				// y = 4, x = 28, h = 3, w = 3, c = 32, f = 32
				// T (f, 1) (32 / 32)
				for (f = f34, fp_2 = f34_p_1, fp_1 = f34_p_0, fp_0 = 0;
					f < f34 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 4, x = 28, h = 3, w = 3, c = 32, f = 32
					// T (c, 1) (32 / 32)
					for (c34 = c35, c34_p_1 = c35_p_0, c34_p_0 = 0;
						c34 < c35 + 32;
						c34 += 32, c34_p_1 += 32, c34_p_0 += 32){
						// y = 4, x = 28, h = 3, w = 3, c = 32, f = 32
						// T (x, 28) (28 / 1)
						for (x = x18, xp_0 = 0;
							x < x18 + 28;
							x += 1, xp_0 += 1){
							// y = 4, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w14, wp_0 = 0;
								w < w14 + 3;
								w += 1, wp_0 += 1){
										mem_vec_176 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_177 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_178 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_179 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_180 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_181 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_182 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_183 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_184 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_185 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_186 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_187 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_188 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_189 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_190 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_191 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c34, cp_2 = c34_p_1, cp_1 = c34_p_0, cp_0 = 0;
											c < c34 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_176);
											mem_vec_176 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_177);
											mem_vec_177 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_178);
											mem_vec_178 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_179);
											mem_vec_179 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_180);
											mem_vec_180 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_181);
											mem_vec_181 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_182);
											mem_vec_182 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_183);
											mem_vec_183 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_184);
											mem_vec_184 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_185);
											mem_vec_185 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_186);
											mem_vec_186 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_187);
											mem_vec_187 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_188);
											mem_vec_188 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_189);
											mem_vec_189 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_190);
											mem_vec_190 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_191);
											mem_vec_191 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_176);
											mem_vec_176 = vec_24;

											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_177);
											mem_vec_177 = vec_27;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_178);
											mem_vec_178 = vec_29;

											vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_179);
											mem_vec_179 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_34 = _mm256_set1_ps(scal_5);


											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_180);
											mem_vec_180 = vec_33;



											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_181);
											mem_vec_181 = vec_35;



											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_182);
											mem_vec_182 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_183);
											mem_vec_183 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_184);
											mem_vec_184 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_185);
											mem_vec_185 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_186);
											mem_vec_186 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_187);
											mem_vec_187 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_188);
											mem_vec_188 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_189);
											mem_vec_189 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_190);
											mem_vec_190 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_191);
											mem_vec_191 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_176);
											mem_vec_176 = vec_48;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_177);
											mem_vec_177 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_178);
											mem_vec_178 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_179);
											mem_vec_179 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_58 = _mm256_set1_ps(scal_9);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_180);
											mem_vec_180 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_181);
											mem_vec_181 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_182);
											mem_vec_182 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_183);
											mem_vec_183 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_63 = _mm256_set1_ps(scal_10);


											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_184);
											mem_vec_184 = vec_62;



											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_185);
											mem_vec_185 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_186);
											mem_vec_186 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_187);
											mem_vec_187 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_188);
											mem_vec_188 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_189);
											mem_vec_189 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_190);
											mem_vec_190 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_191);
											mem_vec_191 = vec_71;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_176);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_177);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_178);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_179);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_180);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_181);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_182);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_183);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_184);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_185);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_186);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_187);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_188);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_189);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_190);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_191);
							}
						}
					}
				}
			}
		}
	}
}


}