#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (3, h);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (4, f); T (16, c); T (2, f); T (4, f)]
*/
IND_TYPE c, cp_0, c352_p_0, cp_1, c352, f, fp_0, f376_p_0, f377_p_0, fp_1, f376_p_1, fp_2, f376, f377, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y228 = 0;
IND_TYPE x208 = 0;
IND_TYPE h144 = 0;
IND_TYPE w = 0;
IND_TYPE c353 = 0;
IND_TYPE f378 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_4068 ,mem_vec_4069 ,mem_vec_4070 ,mem_vec_4071 ,mem_vec_4072 ,mem_vec_4073 ,mem_vec_4074 ,mem_vec_4075 ,mem_vec_4076 ,mem_vec_4077 ,mem_vec_4078 ,mem_vec_4079 ,mem_vec_4080 ,mem_vec_4081 ,mem_vec_4082 ,mem_vec_4083 ,mem_vec_4084 ,mem_vec_4085 ,mem_vec_4086 ,mem_vec_4087 ,mem_vec_4088 ,mem_vec_4089 ,mem_vec_4090 ,mem_vec_4091 ,mem_vec_4092 ,mem_vec_4093 ,mem_vec_4094 ,mem_vec_4095 ,mem_vec_4096 ,mem_vec_4097 ,mem_vec_4098 ,mem_vec_4099 ,mem_vec_4100 ,mem_vec_4101 ,mem_vec_4102 ,mem_vec_4103 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 4) (1024 / 256)
for (f377 = f378, f377_p_0 = 0;
	f377 < f378 + 1024;
	f377 += 256, f377_p_0 += 256){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 256
	// T (f, 2) (256 / 128)
	for (f376 = f377, f376_p_1 = f377_p_0, f376_p_0 = 0;
		f376 < f377 + 256;
		f376 += 128, f376_p_1 += 128, f376_p_0 += 128){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 128
		// T (c, 16) (512 / 32)
		for (c352 = c353, c352_p_0 = 0;
			c352 < c353 + 512;
			c352 += 32, c352_p_0 += 32){
			// y = 17, x = 17, h = 3, w = 3, c = 32, f = 128
			// T (f, 4) (128 / 32)
			for (f = f376, fp_2 = f376_p_1, fp_1 = f376_p_0, fp_0 = 0;
				f < f376 + 128;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y228, yp_0 = 0;
						y < y228 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x208, xp_0 = 0;
							x < x208 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h144, hp_0 = 0;
								h < h144 + 3;
								h += 1, hp_0 += 1){
										mem_vec_4068 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4069 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_4070 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4071 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_4072 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4073 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_4074 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4075 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_4076 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4077 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_4078 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4079 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_4080 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4081 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_4082 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4083 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c352, cp_1 = c352_p_0, cp_0 = 0;
											c < c352 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4068);
											mem_vec_4068 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4069);
											mem_vec_4069 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4070);
											mem_vec_4070 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4071);
											mem_vec_4071 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4072);
											mem_vec_4072 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4073);
											mem_vec_4073 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4074);
											mem_vec_4074 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4075);
											mem_vec_4075 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4076);
											mem_vec_4076 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4077);
											mem_vec_4077 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4078);
											mem_vec_4078 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4079);
											mem_vec_4079 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4080);
											mem_vec_4080 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4081);
											mem_vec_4081 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4082);
											mem_vec_4082 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4083);
											mem_vec_4083 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_4068);
											mem_vec_4068 = vec_24;

											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_4069);
											mem_vec_4069 = vec_27;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_4070);
											mem_vec_4070 = vec_29;

											vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_4071);
											mem_vec_4071 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm256_set1_ps(scal_5);


											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_4072);
											mem_vec_4072 = vec_33;



											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_4073);
											mem_vec_4073 = vec_35;



											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_4074);
											mem_vec_4074 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_4075);
											mem_vec_4075 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_4076);
											mem_vec_4076 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_4077);
											mem_vec_4077 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_4078);
											mem_vec_4078 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_4079);
											mem_vec_4079 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_4080);
											mem_vec_4080 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_4081);
											mem_vec_4081 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_4082);
											mem_vec_4082 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_4083);
											mem_vec_4083 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_4068);
											mem_vec_4068 = vec_48;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_4069);
											mem_vec_4069 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_4070);
											mem_vec_4070 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_4071);
											mem_vec_4071 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm256_set1_ps(scal_9);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_4072);
											mem_vec_4072 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_4073);
											mem_vec_4073 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_4074);
											mem_vec_4074 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_4075);
											mem_vec_4075 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm256_set1_ps(scal_10);


											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_4076);
											mem_vec_4076 = vec_62;



											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_4077);
											mem_vec_4077 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_4078);
											mem_vec_4078 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_4079);
											mem_vec_4079 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_4080);
											mem_vec_4080 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_4081);
											mem_vec_4081 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_4082);
											mem_vec_4082 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_4083);
											mem_vec_4083 = vec_71;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4068);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4069);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4070);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4071);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4072);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4073);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4074);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4075);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4076);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4077);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4078);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4079);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4080);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4081);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4082);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4083);
							}
						}
					}
					for (y = y228 + 12, yp_0 = 0;
						y < y228 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x208, xp_0 = 0;
							x < x208 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h144, hp_0 = 0;
								h < h144 + 3;
								h += 1, hp_0 += 1){
										mem_vec_4084 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4085 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_4086 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4087 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_4088 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4089 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_4090 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4091 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_4092 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4093 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_4094 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4095 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_4096 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4097 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_4098 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4099 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_4100 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4101 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_4102 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4103 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c352, cp_1 = c352_p_0, cp_0 = 0;
											c < c352 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4084);
											mem_vec_4084 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4085);
											mem_vec_4085 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4086);
											mem_vec_4086 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4087);
											mem_vec_4087 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4088);
											mem_vec_4088 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4089);
											mem_vec_4089 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4090);
											mem_vec_4090 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4091);
											mem_vec_4091 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4092);
											mem_vec_4092 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4093);
											mem_vec_4093 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4094);
											mem_vec_4094 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4095);
											mem_vec_4095 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4096);
											mem_vec_4096 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4097);
											mem_vec_4097 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4098);
											mem_vec_4098 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4099);
											mem_vec_4099 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_4100);
											mem_vec_4100 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_4101);
											mem_vec_4101 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_4102);
											mem_vec_4102 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_4103);
											mem_vec_4103 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_4084);
											mem_vec_4084 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_4085);
											mem_vec_4085 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_4086);
											mem_vec_4086 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_4087);
											mem_vec_4087 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_4088);
											mem_vec_4088 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_4089);
											mem_vec_4089 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_4090);
											mem_vec_4090 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_4091);
											mem_vec_4091 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_4092);
											mem_vec_4092 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_4093);
											mem_vec_4093 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_4094);
											mem_vec_4094 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_4095);
											mem_vec_4095 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_4096);
											mem_vec_4096 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_4097);
											mem_vec_4097 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_4098);
											mem_vec_4098 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_4099);
											mem_vec_4099 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_4100);
											mem_vec_4100 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_4101);
											mem_vec_4101 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_4102);
											mem_vec_4102 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_4103);
											mem_vec_4103 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_4084);
											mem_vec_4084 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_4085);
											mem_vec_4085 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_4086);
											mem_vec_4086 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_4087);
											mem_vec_4087 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_4088);
											mem_vec_4088 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_4089);
											mem_vec_4089 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_4090);
											mem_vec_4090 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_4091);
											mem_vec_4091 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_4092);
											mem_vec_4092 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_4093);
											mem_vec_4093 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_4094);
											mem_vec_4094 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_4095);
											mem_vec_4095 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_4096);
											mem_vec_4096 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_4097);
											mem_vec_4097 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_4098);
											mem_vec_4098 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_4099);
											mem_vec_4099 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_4100);
											mem_vec_4100 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_4101);
											mem_vec_4101 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_4102);
											mem_vec_4102 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_4103);
											mem_vec_4103 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4084);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4085);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4086);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4087);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4088);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4089);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4090);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4091);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4092);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4093);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4094);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4095);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4096);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4097);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4098);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4099);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4100);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_4101);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4102);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_4103);
							}
						}
					}
			}
		}
	}
}


}