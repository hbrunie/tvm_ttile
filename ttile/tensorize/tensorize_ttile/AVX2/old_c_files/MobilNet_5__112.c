#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (28, x); T (2, c); T (2, f); T (7, y); T (1, f); T (8, c); T (4, f)]
*/
IND_TYPE c, cp_0, c46_p_0, c47_p_0, cp_1, c46_p_1, cp_2, c46, c47, f, fp_0, f46_p_0, f47_p_0, fp_1, f46_p_1, fp_2, f46, f47, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y26 = 0;
IND_TYPE x24 = 0;
IND_TYPE h = 0;
IND_TYPE w20 = 0;
IND_TYPE c48 = 0;
IND_TYPE f48 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,mem_vec_232 ,mem_vec_233 ,mem_vec_234 ,mem_vec_235 ,mem_vec_236 ,mem_vec_237 ,mem_vec_238 ,mem_vec_239 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 4) (256 / 64)
for (f47 = f48, f47_p_0 = 0;
	f47 < f48 + 256;
	f47 += 64, f47_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 64
	// T (c, 8) (256 / 32)
	for (c47 = c48, c47_p_0 = 0;
		c47 < c48 + 256;
		c47 += 32, c47_p_0 += 32){
		// y = 28, x = 28, h = 3, w = 3, c = 32, f = 64
		// T (f, 1) (64 / 64)
		for (f46 = f47, f46_p_1 = f47_p_0, f46_p_0 = 0;
			f46 < f47 + 64;
			f46 += 64, f46_p_1 += 64, f46_p_0 += 64){
			// y = 28, x = 28, h = 3, w = 3, c = 32, f = 64
			// T (y, 7) (28 / 4)
			for (y = y26, yp_0 = 0;
				y < y26 + 28;
				y += 4, yp_0 += 4){
				// y = 4, x = 28, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f46, fp_2 = f46_p_1, fp_1 = f46_p_0, fp_0 = 0;
					f < f46 + 64;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 4, x = 28, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c46 = c47, c46_p_1 = c47_p_0, c46_p_0 = 0;
						c46 < c47 + 32;
						c46 += 16, c46_p_1 += 16, c46_p_0 += 16){
						// y = 4, x = 28, h = 3, w = 3, c = 16, f = 32
						// T (x, 28) (28 / 1)
						for (x = x24, xp_0 = 0;
							x < x24 + 28;
							x += 1, xp_0 += 1){
							// y = 4, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w20, wp_0 = 0;
								w < w20 + 3;
								w += 1, wp_0 += 1){
										mem_vec_224 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_225 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_226 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_227 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_228 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_229 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_230 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_231 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_232 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_233 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_234 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_235 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_236 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_237 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 3, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c46, cp_2 = c46_p_1, cp_1 = c46_p_0, cp_0 = 0;
											c < c46 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_224);
											mem_vec_224 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_225);
											mem_vec_225 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_226);
											mem_vec_226 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_227);
											mem_vec_227 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_228);
											mem_vec_228 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_229);
											mem_vec_229 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_230);
											mem_vec_230 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_231);
											mem_vec_231 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_232);
											mem_vec_232 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_233);
											mem_vec_233 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_234);
											mem_vec_234 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_235);
											mem_vec_235 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_236);
											mem_vec_236 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_237);
											mem_vec_237 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_238);
											mem_vec_238 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_239);
											mem_vec_239 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_224);
											mem_vec_224 = vec_24;

											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_225);
											mem_vec_225 = vec_27;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_226);
											mem_vec_226 = vec_29;

											vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_227);
											mem_vec_227 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_34 = _mm256_set1_ps(scal_5);


											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_228);
											mem_vec_228 = vec_33;



											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_229);
											mem_vec_229 = vec_35;



											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_230);
											mem_vec_230 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_231);
											mem_vec_231 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_232);
											mem_vec_232 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_233);
											mem_vec_233 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_234);
											mem_vec_234 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_235);
											mem_vec_235 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_236);
											mem_vec_236 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_237);
											mem_vec_237 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_238);
											mem_vec_238 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_239);
											mem_vec_239 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_224);
											mem_vec_224 = vec_48;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_225);
											mem_vec_225 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_226);
											mem_vec_226 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_227);
											mem_vec_227 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_58 = _mm256_set1_ps(scal_9);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_228);
											mem_vec_228 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_229);
											mem_vec_229 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_230);
											mem_vec_230 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_231);
											mem_vec_231 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_63 = _mm256_set1_ps(scal_10);


											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_232);
											mem_vec_232 = vec_62;



											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_233);
											mem_vec_233 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_234);
											mem_vec_234 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_235);
											mem_vec_235 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_236);
											mem_vec_236 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_237);
											mem_vec_237 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_238);
											mem_vec_238 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_239);
											mem_vec_239 = vec_71;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_224);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_225);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_226);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_227);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_228);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_229);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_230);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_231);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_232);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_233);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_234);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_235);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_236);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_237);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_238);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_239);
							}
						}
					}
				}
			}
		}
	}
}


}