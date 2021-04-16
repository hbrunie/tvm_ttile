#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (32, c); Hoist_vars [c]; T (68, x);
  T (3, h); T (4, c); T (17, y); T (1, x); T (4, f); T (1, c); T (2, f)]
*/
IND_TYPE c, cp_0, c368_p_0, c369_p_0, cp_1, c368_p_1, cp_2, c368, c369, f, fp_0, f227_p_0, fp_1, f227, h, hp_0, x, xp_0, x255_p_0, xp_1, x255, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y170 = 0;
IND_TYPE x256 = 0;
IND_TYPE h126 = 0;
IND_TYPE w = 0;
IND_TYPE c370 = 0;
IND_TYPE f228 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_2492 ,mem_vec_2493 ,mem_vec_2494 ,mem_vec_2495 ,mem_vec_2496 ,mem_vec_2497 ,mem_vec_2498 ,mem_vec_2499 ,mem_vec_2500 ,mem_vec_2501 ,mem_vec_2502 ,mem_vec_2503 ,mem_vec_2504 ,mem_vec_2505 ,mem_vec_2506 ,mem_vec_2507 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f227 = f228, f227_p_0 = 0;
	f227 < f228 + 256;
	f227 += 128, f227_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (c, 1) (128 / 128)
	for (c369 = c370, c369_p_0 = 0;
		c369 < c370 + 128;
		c369 += 128, c369_p_0 += 128){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
		// T (f, 4) (128 / 32)
		for (f = f227, fp_1 = f227_p_0, fp_0 = 0;
			f < f227 + 128;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
			// T (x, 1) (68 / 68)
			for (x255 = x256, x255_p_0 = 0;
				x255 < x256 + 68;
				x255 += 68, x255_p_0 += 68){
				// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
				// T (y, 17) (68 / 4)
				for (y = y170, yp_0 = 0;
					y < y170 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 68, h = 3, w = 3, c = 128, f = 32
					// T (c, 4) (128 / 32)
					for (c368 = c369, c368_p_1 = c369_p_0, c368_p_0 = 0;
						c368 < c369 + 128;
						c368 += 32, c368_p_1 += 32, c368_p_0 += 32){
						// y = 4, x = 68, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h126, hp_0 = 0;
							h < h126 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 68, h = 1, w = 3, c = 32, f = 32
							// T (x, 68) (68 / 1)
							for (x = x255, xp_1 = x255_p_0, xp_0 = 0;
								x < x255 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2492 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2493 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_2494 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2495 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_2496 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2497 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_2498 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2499 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_2500 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2501 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_2502 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2503 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_2504 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2505 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_2506 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2507 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c368, cp_2 = c368_p_1, cp_1 = c368_p_0, cp_0 = 0;
											c < c368 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2492);
											mem_vec_2492 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2493);
											mem_vec_2493 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2494);
											mem_vec_2494 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2495);
											mem_vec_2495 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2496);
											mem_vec_2496 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2497);
											mem_vec_2497 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2498);
											mem_vec_2498 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2499);
											mem_vec_2499 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2500);
											mem_vec_2500 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2501);
											mem_vec_2501 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2502);
											mem_vec_2502 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2503);
											mem_vec_2503 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2504);
											mem_vec_2504 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2505);
											mem_vec_2505 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2506);
											mem_vec_2506 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2507);
											mem_vec_2507 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_2492);
											mem_vec_2492 = vec_24;

											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_2493);
											mem_vec_2493 = vec_27;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_2494);
											mem_vec_2494 = vec_29;

											vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_2495);
											mem_vec_2495 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm256_set1_ps(scal_5);


											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_2496);
											mem_vec_2496 = vec_33;



											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_2497);
											mem_vec_2497 = vec_35;



											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_2498);
											mem_vec_2498 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_2499);
											mem_vec_2499 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_2500);
											mem_vec_2500 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_2501);
											mem_vec_2501 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_2502);
											mem_vec_2502 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_2503);
											mem_vec_2503 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_2504);
											mem_vec_2504 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_2505);
											mem_vec_2505 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_2506);
											mem_vec_2506 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_2507);
											mem_vec_2507 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_2492);
											mem_vec_2492 = vec_48;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_2493);
											mem_vec_2493 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_2494);
											mem_vec_2494 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_2495);
											mem_vec_2495 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm256_set1_ps(scal_9);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_2496);
											mem_vec_2496 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_2497);
											mem_vec_2497 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_2498);
											mem_vec_2498 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_2499);
											mem_vec_2499 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm256_set1_ps(scal_10);


											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_2500);
											mem_vec_2500 = vec_62;



											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_2501);
											mem_vec_2501 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_2502);
											mem_vec_2502 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_2503);
											mem_vec_2503 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_2504);
											mem_vec_2504 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_2505);
											mem_vec_2505 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_2506);
											mem_vec_2506 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_2507);
											mem_vec_2507 = vec_71;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2492);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2493);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2494);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2495);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2496);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2497);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2498);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2499);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2500);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2501);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2502);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2503);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2504);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2505);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2506);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2507);
							}
						}
					}
				}
			}
		}
	}
}


}