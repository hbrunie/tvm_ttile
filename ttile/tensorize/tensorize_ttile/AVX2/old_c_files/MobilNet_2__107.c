#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, h); T (32, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, c); T (1, f); T (14, y); T (56, x); T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c192_p_0, cp_1, c192, f, fp_0, f247_p_0, f248_p_0, fp_1, f247_p_1, fp_2, f247, f248, w, wp_0, x, xp_0, x193_p_0, xp_1, x193, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y131 = 0;
IND_TYPE x194 = 0;
IND_TYPE h = 0;
IND_TYPE w102 = 0;
IND_TYPE c193 = 0;
IND_TYPE f249 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_2840 ,mem_vec_2841 ,mem_vec_2842 ,mem_vec_2843 ,mem_vec_2844 ,mem_vec_2845 ,mem_vec_2846 ,mem_vec_2847 ,mem_vec_2848 ,mem_vec_2849 ,mem_vec_2850 ,mem_vec_2851 ,mem_vec_2852 ,mem_vec_2853 ,mem_vec_2854 ,mem_vec_2855 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f248 = f249, f248_p_0 = 0;
	f248 < f249 + 64;
	f248 += 64, f248_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (f, 2) (64 / 32)
	for (f247 = f248, f247_p_1 = f248_p_0, f247_p_0 = 0;
		f247 < f248 + 64;
		f247 += 32, f247_p_1 += 32, f247_p_0 += 32){
		// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
		// T (x, 56) (56 / 1)
		for (x193 = x194, x193_p_0 = 0;
			x193 < x194 + 56;
			x193 += 1, x193_p_0 += 1){
			// y = 56, x = 1, h = 3, w = 3, c = 64, f = 32
			// T (y, 14) (56 / 4)
			for (y = y131, yp_0 = 0;
				y < y131 + 56;
				y += 4, yp_0 += 4){
				// y = 4, x = 1, h = 3, w = 3, c = 64, f = 32
				// T (f, 1) (32 / 32)
				for (f = f247, fp_2 = f247_p_1, fp_1 = f247_p_0, fp_0 = 0;
					f < f247 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 4, x = 1, h = 3, w = 3, c = 64, f = 32
					// T (c, 2) (64 / 32)
					for (c192 = c193, c192_p_0 = 0;
						c192 < c193 + 64;
						c192 += 32, c192_p_0 += 32){
						// y = 4, x = 1, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w102, wp_0 = 0;
							w < w102 + 3;
							w += 1, wp_0 += 1){
							// y = 4, x = 1, h = 3, w = 1, c = 32, f = 32
							// T (x, 1) (1 / 1)
							for (x = x193, xp_1 = x193_p_0, xp_0 = 0;
								x < x193 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2840 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2841 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_2842 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2843 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_2844 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2845 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_2846 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2847 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_2848 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2849 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_2850 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2851 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_2852 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2853 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_2854 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2855 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c192, cp_1 = c192_p_0, cp_0 = 0;
											c < c192 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2840);
											mem_vec_2840 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2841);
											mem_vec_2841 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2842);
											mem_vec_2842 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2843);
											mem_vec_2843 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2844);
											mem_vec_2844 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2845);
											mem_vec_2845 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2846);
											mem_vec_2846 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2847);
											mem_vec_2847 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2848);
											mem_vec_2848 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2849);
											mem_vec_2849 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2850);
											mem_vec_2850 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2851);
											mem_vec_2851 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2852);
											mem_vec_2852 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2853);
											mem_vec_2853 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2854);
											mem_vec_2854 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2855);
											mem_vec_2855 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_2840);
											mem_vec_2840 = vec_24;

											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_2841);
											mem_vec_2841 = vec_27;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_2842);
											mem_vec_2842 = vec_29;

											vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_2843);
											mem_vec_2843 = vec_31;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_34 = _mm256_set1_ps(scal_5);


											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_2844);
											mem_vec_2844 = vec_33;



											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_2845);
											mem_vec_2845 = vec_35;



											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_2846);
											mem_vec_2846 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_2847);
											mem_vec_2847 = vec_37;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_2848);
											mem_vec_2848 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_2849);
											mem_vec_2849 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_2850);
											mem_vec_2850 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_2851);
											mem_vec_2851 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_2852);
											mem_vec_2852 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_2853);
											mem_vec_2853 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_2854);
											mem_vec_2854 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_2855);
											mem_vec_2855 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_2840);
											mem_vec_2840 = vec_48;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_2841);
											mem_vec_2841 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_2842);
											mem_vec_2842 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_2843);
											mem_vec_2843 = vec_55;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_58 = _mm256_set1_ps(scal_9);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_2844);
											mem_vec_2844 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_2845);
											mem_vec_2845 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_2846);
											mem_vec_2846 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_2847);
											mem_vec_2847 = vec_61;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_63 = _mm256_set1_ps(scal_10);


											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_2848);
											mem_vec_2848 = vec_62;



											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_2849);
											mem_vec_2849 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_2850);
											mem_vec_2850 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_2851);
											mem_vec_2851 = vec_66;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_2852);
											mem_vec_2852 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_2853);
											mem_vec_2853 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_2854);
											mem_vec_2854 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_2855);
											mem_vec_2855 = vec_71;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2840);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2841);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2842);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2843);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2844);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2845);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2846);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2847);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2848);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2849);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2850);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2851);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2852);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2853);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2854);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2855);
							}
						}
					}
				}
			}
		}
	}
}


}