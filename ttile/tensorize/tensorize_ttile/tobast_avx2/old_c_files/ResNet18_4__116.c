#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); U (4, y); U (3, w); T (16, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (7, y); T (2, c); T (1, f); T (2, c); T (2, x); T (2, f)]
*/
IND_TYPE c, cp_0, c552_p_0, c553_p_0, cp_1, c552_p_1, cp_2, c552, c553, f, fp_0, f374_p_0, fp_1, f374, h, hp_0, x, xp_0, x694_p_0, xp_1, x694, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y356 = 0;
IND_TYPE x695 = 0;
IND_TYPE h282 = 0;
IND_TYPE w = 0;
IND_TYPE c554 = 0;
IND_TYPE f375 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_4000 ,mem_vec_4001 ,mem_vec_4002 ,mem_vec_4003 ,mem_vec_4004 ,mem_vec_4005 ,mem_vec_4006 ,mem_vec_4007 ,mem_vec_4008 ,mem_vec_4009 ,mem_vec_4010 ,mem_vec_4011 ,mem_vec_4012 ,mem_vec_4013 ,mem_vec_4014 ,mem_vec_4015 ,mem_vec_4016 ,mem_vec_4017 ,mem_vec_4018 ,mem_vec_4019 ,mem_vec_4020 ,mem_vec_4021 ,mem_vec_4022 ,mem_vec_4023 ,mem_vec_4024 ,mem_vec_4025 ,mem_vec_4026 ,mem_vec_4027 ,mem_vec_4028 ,mem_vec_4029 ,mem_vec_4030 ,mem_vec_4031 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f374 = f375, f374_p_0 = 0;
	f374 < f375 + 128;
	f374 += 64, f374_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 64, f = 64
	// T (x, 2) (28 / 14)
	for (x694 = x695, x694_p_0 = 0;
		x694 < x695 + 28;
		x694 += 14, x694_p_0 += 14){
		// y = 28, x = 14, h = 3, w = 3, c = 64, f = 64
		// T (c, 2) (64 / 32)
		for (c553 = c554, c553_p_0 = 0;
			c553 < c554 + 64;
			c553 += 32, c553_p_0 += 32){
			// y = 28, x = 14, h = 3, w = 3, c = 32, f = 64
			// T (f, 1) (64 / 64)
			for (f = f374, fp_1 = f374_p_0, fp_0 = 0;
				f < f374 + 64;
				f += 64, fp_1 += 64, fp_0 += 64){
				// y = 28, x = 14, h = 3, w = 3, c = 32, f = 64
				// T (c, 2) (32 / 16)
				for (c552 = c553, c552_p_1 = c553_p_0, c552_p_0 = 0;
					c552 < c553 + 32;
					c552 += 16, c552_p_1 += 16, c552_p_0 += 16){
					// y = 28, x = 14, h = 3, w = 3, c = 16, f = 64
					// T (y, 7) (28 / 4)
					for (y = y356, yp_0 = 0;
						y < y356 + 28;
						y += 4, yp_0 += 4){
						// y = 4, x = 14, h = 3, w = 3, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h282, hp_0 = 0;
							h < h282 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 14, h = 1, w = 3, c = 16, f = 64
							// T (x, 14) (14 / 1)
							for (x = x694, xp_1 = x694_p_0, xp_0 = 0;
								x < x694 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4000 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4001 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_4002 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4003 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_4004 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_4005 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
										mem_vec_4006 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_4007 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
										mem_vec_4008 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4009 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_4010 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4011 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_4012 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_4013 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
										mem_vec_4014 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_4015 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
										mem_vec_4016 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4017 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_4018 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4019 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_4020 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_4021 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
										mem_vec_4022 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_4023 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
										mem_vec_4024 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4025 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_4026 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4027 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_4028 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_4029 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
										mem_vec_4030 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_4031 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
										// y = 4, x = 1, h = 1, w = 3, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c552, cp_2 = c552_p_1, cp_1 = c552_p_0, cp_0 = 0;
											c < c552 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4000);
											mem_vec_4000 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4001);
											mem_vec_4001 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4002);
											mem_vec_4002 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4003);
											mem_vec_4003 = vec_7;

											vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_4004);
											mem_vec_4004 = vec_9;

											vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

											vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_4005);
											mem_vec_4005 = vec_11;

											vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_4006);
											mem_vec_4006 = vec_13;

											vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

											vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_4007);
											mem_vec_4007 = vec_15;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_18 = _mm256_set1_ps(scal_1);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_4008);
											mem_vec_4008 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_4009);
											mem_vec_4009 = vec_19;



											vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_4010);
											mem_vec_4010 = vec_20;



											vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_4011);
											mem_vec_4011 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_4012);
											mem_vec_4012 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_4013);
											mem_vec_4013 = vec_23;



											vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_4014);
											mem_vec_4014 = vec_24;



											vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_4015);
											mem_vec_4015 = vec_25;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_27 = _mm256_set1_ps(scal_2);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_4016);
											mem_vec_4016 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_4017);
											mem_vec_4017 = vec_28;



											vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_4018);
											mem_vec_4018 = vec_29;



											vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_4019);
											mem_vec_4019 = vec_30;



											vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_4020);
											mem_vec_4020 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_4021);
											mem_vec_4021 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_4022);
											mem_vec_4022 = vec_33;



											vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_4023);
											mem_vec_4023 = vec_34;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_36 = _mm256_set1_ps(scal_3);


											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_4024);
											mem_vec_4024 = vec_35;



											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_4025);
											mem_vec_4025 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_4026);
											mem_vec_4026 = vec_38;



											vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_4027);
											mem_vec_4027 = vec_39;



											vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_4028);
											mem_vec_4028 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_4029);
											mem_vec_4029 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_4030);
											mem_vec_4030 = vec_42;



											vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_4031);
											mem_vec_4031 = vec_43;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_45 = _mm256_set1_ps(scal_4);
											vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_4000);
											mem_vec_4000 = vec_44;

											vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_4001);
											mem_vec_4001 = vec_47;

											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_4002);
											mem_vec_4002 = vec_49;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_4003);
											mem_vec_4003 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_4004);
											mem_vec_4004 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

											vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_4005);
											mem_vec_4005 = vec_55;

											vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_4006);
											mem_vec_4006 = vec_57;

											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

											vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_4007);
											mem_vec_4007 = vec_59;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_62 = _mm256_set1_ps(scal_5);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_4008);
											mem_vec_4008 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_4009);
											mem_vec_4009 = vec_63;



											vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_4010);
											mem_vec_4010 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_4011);
											mem_vec_4011 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_4012);
											mem_vec_4012 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_4013);
											mem_vec_4013 = vec_67;



											vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_4014);
											mem_vec_4014 = vec_68;



											vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_4015);
											mem_vec_4015 = vec_69;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_71 = _mm256_set1_ps(scal_6);


											vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_4016);
											mem_vec_4016 = vec_70;



											vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_4017);
											mem_vec_4017 = vec_72;



											vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_4018);
											mem_vec_4018 = vec_73;



											vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_4019);
											mem_vec_4019 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_4020);
											mem_vec_4020 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_4021);
											mem_vec_4021 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_4022);
											mem_vec_4022 = vec_77;



											vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_4023);
											mem_vec_4023 = vec_78;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_80 = _mm256_set1_ps(scal_7);


											vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_4024);
											mem_vec_4024 = vec_79;



											vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_4025);
											mem_vec_4025 = vec_81;



											vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_4026);
											mem_vec_4026 = vec_82;



											vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_4027);
											mem_vec_4027 = vec_83;



											vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_4028);
											mem_vec_4028 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_4029);
											mem_vec_4029 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_4030);
											mem_vec_4030 = vec_86;



											vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_4031);
											mem_vec_4031 = vec_87;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_89 = _mm256_set1_ps(scal_8);
											vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_4000);
											mem_vec_4000 = vec_88;

											vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_4001);
											mem_vec_4001 = vec_91;

											vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_4002);
											mem_vec_4002 = vec_93;

											vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_4003);
											mem_vec_4003 = vec_95;

											vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_4004);
											mem_vec_4004 = vec_97;

											vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

											vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_4005);
											mem_vec_4005 = vec_99;

											vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_4006);
											mem_vec_4006 = vec_101;

											vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

											vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_4007);
											mem_vec_4007 = vec_103;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_106 = _mm256_set1_ps(scal_9);


											vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_4008);
											mem_vec_4008 = vec_105;



											vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_4009);
											mem_vec_4009 = vec_107;



											vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_4010);
											mem_vec_4010 = vec_108;



											vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_4011);
											mem_vec_4011 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_4012);
											mem_vec_4012 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_4013);
											mem_vec_4013 = vec_111;



											vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_4014);
											mem_vec_4014 = vec_112;



											vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_4015);
											mem_vec_4015 = vec_113;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_115 = _mm256_set1_ps(scal_10);


											vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_4016);
											mem_vec_4016 = vec_114;



											vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_4017);
											mem_vec_4017 = vec_116;



											vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_4018);
											mem_vec_4018 = vec_117;



											vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_4019);
											mem_vec_4019 = vec_118;



											vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_4020);
											mem_vec_4020 = vec_119;



											vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_4021);
											mem_vec_4021 = vec_120;



											vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_4022);
											mem_vec_4022 = vec_121;



											vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_4023);
											mem_vec_4023 = vec_122;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_124 = _mm256_set1_ps(scal_11);


											vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_4024);
											mem_vec_4024 = vec_123;



											vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_4025);
											mem_vec_4025 = vec_125;



											vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_4026);
											mem_vec_4026 = vec_126;



											vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_4027);
											mem_vec_4027 = vec_127;



											vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_4028);
											mem_vec_4028 = vec_128;



											vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_4029);
											mem_vec_4029 = vec_129;



											vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_4030);
											mem_vec_4030 = vec_130;



											vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_4031);
											mem_vec_4031 = vec_131;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4000);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4001);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4002);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4003);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4004);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_4005);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4006);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_4007);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4008);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4009);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4010);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4011);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4012);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_4013);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4014);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_4015);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4016);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4017);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4018);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4019);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4020);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_4021);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4022);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_4023);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4024);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4025);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4026);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4027);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4028);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_4029);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4030);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_4031);
							}
						}
					}
				}
			}
		}
	}
}


}