#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (16, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (4, c); T (17, y); T (4, x); T (8, f); T (2, c); T (1, f)]
*/
IND_TYPE c, cp_0, c684_p_0, c685_p_0, cp_1, c684_p_1, cp_2, c684, c685, f, fp_0, f436_p_0, fp_1, f436, h, hp_0, x, xp_0, x480_p_0, xp_1, x480, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y320 = 0;
IND_TYPE x481 = 0;
IND_TYPE h240 = 0;
IND_TYPE w = 0;
IND_TYPE c686 = 0;
IND_TYPE f437 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_4044 ,mem_vec_4045 ,mem_vec_4046 ,mem_vec_4047 ,mem_vec_4048 ,mem_vec_4049 ,mem_vec_4050 ,mem_vec_4051 ,mem_vec_4052 ,mem_vec_4053 ,mem_vec_4054 ,mem_vec_4055 ,mem_vec_4056 ,mem_vec_4057 ,mem_vec_4058 ,mem_vec_4059 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f436 = f437, f436_p_0 = 0;
	f436 < f437 + 256;
	f436 += 256, f436_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (c, 2) (128 / 64)
	for (c685 = c686, c685_p_0 = 0;
		c685 < c686 + 128;
		c685 += 64, c685_p_0 += 64){
		// y = 68, x = 68, h = 3, w = 3, c = 64, f = 256
		// T (f, 8) (256 / 32)
		for (f = f436, fp_1 = f436_p_0, fp_0 = 0;
			f < f436 + 256;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 68, x = 68, h = 3, w = 3, c = 64, f = 32
			// T (x, 4) (68 / 17)
			for (x480 = x481, x480_p_0 = 0;
				x480 < x481 + 68;
				x480 += 17, x480_p_0 += 17){
				// y = 68, x = 17, h = 3, w = 3, c = 64, f = 32
				// T (y, 17) (68 / 4)
				for (y = y320, yp_0 = 0;
					y < y320 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 17, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c684 = c685, c684_p_1 = c685_p_0, c684_p_0 = 0;
						c684 < c685 + 64;
						c684 += 16, c684_p_1 += 16, c684_p_0 += 16){
						// y = 4, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h240, hp_0 = 0;
							h < h240 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 17, h = 1, w = 3, c = 16, f = 32
							// T (x, 17) (17 / 1)
							for (x = x480, xp_1 = x480_p_0, xp_0 = 0;
								x < x480 + 17;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4044 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4045 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_4046 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4047 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_4048 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4049 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_4050 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4051 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_4052 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4053 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_4054 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4055 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_4056 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4057 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_4058 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4059 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c684, cp_2 = c684_p_1, cp_1 = c684_p_0, cp_0 = 0;
											c < c684 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4044);
											mem_vec_4044 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4045);
											mem_vec_4045 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4046);
											mem_vec_4046 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4047);
											mem_vec_4047 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4048);
											mem_vec_4048 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4049);
											mem_vec_4049 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4050);
											mem_vec_4050 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4051);
											mem_vec_4051 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4052);
											mem_vec_4052 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4053);
											mem_vec_4053 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4054);
											mem_vec_4054 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4055);
											mem_vec_4055 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4056);
											mem_vec_4056 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4057);
											mem_vec_4057 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4058);
											mem_vec_4058 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4059);
											mem_vec_4059 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_4044);
											mem_vec_4044 = vec_24;

											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_4045);
											mem_vec_4045 = vec_27;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_4046);
											mem_vec_4046 = vec_29;

											vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_4047);
											mem_vec_4047 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm256_set1_ps(scal_5);


											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_4048);
											mem_vec_4048 = vec_33;



											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_4049);
											mem_vec_4049 = vec_35;



											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_4050);
											mem_vec_4050 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_4051);
											mem_vec_4051 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_4052);
											mem_vec_4052 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_4053);
											mem_vec_4053 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_4054);
											mem_vec_4054 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_4055);
											mem_vec_4055 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_4056);
											mem_vec_4056 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_4057);
											mem_vec_4057 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_4058);
											mem_vec_4058 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_4059);
											mem_vec_4059 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_4044);
											mem_vec_4044 = vec_48;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_4045);
											mem_vec_4045 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_4046);
											mem_vec_4046 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_4047);
											mem_vec_4047 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm256_set1_ps(scal_9);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_4048);
											mem_vec_4048 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_4049);
											mem_vec_4049 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_4050);
											mem_vec_4050 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_4051);
											mem_vec_4051 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm256_set1_ps(scal_10);


											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_4052);
											mem_vec_4052 = vec_62;



											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_4053);
											mem_vec_4053 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_4054);
											mem_vec_4054 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_4055);
											mem_vec_4055 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_4056);
											mem_vec_4056 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_4057);
											mem_vec_4057 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_4058);
											mem_vec_4058 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_4059);
											mem_vec_4059 = vec_71;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4044);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4045);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4046);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4047);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4048);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4049);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4050);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4051);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4052);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4053);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4054);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4055);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4056);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4057);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4058);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4059);
							}
						}
					}
				}
			}
		}
	}
}


}