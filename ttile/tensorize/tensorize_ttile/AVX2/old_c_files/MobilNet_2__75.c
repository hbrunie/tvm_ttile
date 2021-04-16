#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (16, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (4, c); T (1, f); T (14, y); T (56, x); T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c234_p_0, cp_1, c234, f, fp_0, f303_p_0, f304_p_0, fp_1, f303_p_1, fp_2, f303, f304, h, hp_0, x, xp_0, x235_p_0, xp_1, x235, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y159 = 0;
IND_TYPE x236 = 0;
IND_TYPE h108 = 0;
IND_TYPE w = 0;
IND_TYPE c235 = 0;
IND_TYPE f305 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3136 ,mem_vec_3137 ,mem_vec_3138 ,mem_vec_3139 ,mem_vec_3140 ,mem_vec_3141 ,mem_vec_3142 ,mem_vec_3143 ,mem_vec_3144 ,mem_vec_3145 ,mem_vec_3146 ,mem_vec_3147 ,mem_vec_3148 ,mem_vec_3149 ,mem_vec_3150 ,mem_vec_3151 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f304 = f305, f304_p_0 = 0;
	f304 < f305 + 64;
	f304 += 64, f304_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (f, 2) (64 / 32)
	for (f303 = f304, f303_p_1 = f304_p_0, f303_p_0 = 0;
		f303 < f304 + 64;
		f303 += 32, f303_p_1 += 32, f303_p_0 += 32){
		// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
		// T (x, 56) (56 / 1)
		for (x235 = x236, x235_p_0 = 0;
			x235 < x236 + 56;
			x235 += 1, x235_p_0 += 1){
			// y = 56, x = 1, h = 3, w = 3, c = 64, f = 32
			// T (y, 14) (56 / 4)
			for (y = y159, yp_0 = 0;
				y < y159 + 56;
				y += 4, yp_0 += 4){
				// y = 4, x = 1, h = 3, w = 3, c = 64, f = 32
				// T (f, 1) (32 / 32)
				for (f = f303, fp_2 = f303_p_1, fp_1 = f303_p_0, fp_0 = 0;
					f < f303 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 4, x = 1, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c234 = c235, c234_p_0 = 0;
						c234 < c235 + 64;
						c234 += 16, c234_p_0 += 16){
						// y = 4, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h108, hp_0 = 0;
							h < h108 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 1, h = 1, w = 3, c = 16, f = 32
							// T (x, 1) (1 / 1)
							for (x = x235, xp_1 = x235_p_0, xp_0 = 0;
								x < x235 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3136 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3137 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_3138 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3139 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_3140 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3141 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_3142 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3143 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_3144 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3145 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_3146 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3147 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_3148 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3149 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_3150 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3151 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c234, cp_1 = c234_p_0, cp_0 = 0;
											c < c234 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3136);
											mem_vec_3136 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3137);
											mem_vec_3137 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3138);
											mem_vec_3138 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3139);
											mem_vec_3139 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3140);
											mem_vec_3140 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3141);
											mem_vec_3141 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3142);
											mem_vec_3142 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3143);
											mem_vec_3143 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3144);
											mem_vec_3144 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3145);
											mem_vec_3145 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3146);
											mem_vec_3146 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3147);
											mem_vec_3147 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3148);
											mem_vec_3148 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3149);
											mem_vec_3149 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3150);
											mem_vec_3150 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3151);
											mem_vec_3151 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_3136);
											mem_vec_3136 = vec_24;

											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_3137);
											mem_vec_3137 = vec_27;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_3138);
											mem_vec_3138 = vec_29;

											vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_3139);
											mem_vec_3139 = vec_31;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_34 = _mm256_set1_ps(scal_5);


											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_3140);
											mem_vec_3140 = vec_33;



											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_3141);
											mem_vec_3141 = vec_35;



											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_3142);
											mem_vec_3142 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_3143);
											mem_vec_3143 = vec_37;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_3144);
											mem_vec_3144 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_3145);
											mem_vec_3145 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_3146);
											mem_vec_3146 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_3147);
											mem_vec_3147 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_3148);
											mem_vec_3148 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_3149);
											mem_vec_3149 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_3150);
											mem_vec_3150 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_3151);
											mem_vec_3151 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_3136);
											mem_vec_3136 = vec_48;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_3137);
											mem_vec_3137 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_3138);
											mem_vec_3138 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_3139);
											mem_vec_3139 = vec_55;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_58 = _mm256_set1_ps(scal_9);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_3140);
											mem_vec_3140 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_3141);
											mem_vec_3141 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_3142);
											mem_vec_3142 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_3143);
											mem_vec_3143 = vec_61;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_63 = _mm256_set1_ps(scal_10);


											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_3144);
											mem_vec_3144 = vec_62;



											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_3145);
											mem_vec_3145 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_3146);
											mem_vec_3146 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_3147);
											mem_vec_3147 = vec_66;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_3148);
											mem_vec_3148 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_3149);
											mem_vec_3149 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_3150);
											mem_vec_3150 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_3151);
											mem_vec_3151 = vec_71;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3136);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3137);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3138);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3139);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3140);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3141);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3142);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3143);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3144);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3145);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3146);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3147);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3148);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3149);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3150);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3151);
							}
						}
					}
				}
			}
		}
	}
}


}