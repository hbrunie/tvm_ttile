#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (8, f);
  T (8, c); T (1, f)]
*/
IND_TYPE c, cp_0, c984_p_0, cp_1, c984, f, fp_0, f1312_p_0, f1313_p_0, fp_1, f1312_p_1, fp_2, f1312, f1313, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y656 = 0;
IND_TYPE x656 = 0;
IND_TYPE h508 = 0;
IND_TYPE w = 0;
IND_TYPE c985 = 0;
IND_TYPE f1314 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10024 ,mem_vec_10025 ,mem_vec_10026 ,mem_vec_10027 ,mem_vec_10028 ,mem_vec_10029 ,mem_vec_10030 ,mem_vec_10031 ,mem_vec_10032 ,mem_vec_10033 ,mem_vec_10034 ,mem_vec_10035 ,mem_vec_10036 ,mem_vec_10037 ,mem_vec_10038 ,mem_vec_10039 ,mem_vec_10040 ,mem_vec_10041 ,mem_vec_10042 ,mem_vec_10043 ,mem_vec_10044 ,mem_vec_10045 ,mem_vec_10046 ,mem_vec_10047 ,mem_vec_10048 ,mem_vec_10049 ,mem_vec_10050 ,mem_vec_10051 ,mem_vec_10052 ,mem_vec_10053 ,mem_vec_10054 ,mem_vec_10055 ,mem_vec_10056 ,mem_vec_10057 ,mem_vec_10058 ,mem_vec_10059 ,mem_vec_10060 ,mem_vec_10061 ,mem_vec_10062 ,mem_vec_10063 ,mem_vec_10064 ,mem_vec_10065 ,mem_vec_10066 ,mem_vec_10067 ,mem_vec_10068 ,mem_vec_10069 ,mem_vec_10070 ,mem_vec_10071 ,mem_vec_10072 ,mem_vec_10073 ,mem_vec_10074 ,mem_vec_10075 ,mem_vec_10076 ,mem_vec_10077 ,mem_vec_10078 ,mem_vec_10079 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (f, 1) (512 / 512)
for (f1313 = f1314, f1313_p_0 = 0;
	f1313 < f1314 + 512;
	f1313 += 512, f1313_p_0 += 512){
	// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
	// T (c, 8) (512 / 64)
	for (c984 = c985, c984_p_0 = 0;
		c984 < c985 + 512;
		c984 += 64, c984_p_0 += 64){
		// y = 7, x = 7, h = 3, w = 3, c = 64, f = 512
		// T (f, 8) (512 / 64)
		for (f1312 = f1313, f1312_p_1 = f1313_p_0, f1312_p_0 = 0;
			f1312 < f1313 + 512;
			f1312 += 64, f1312_p_1 += 64, f1312_p_0 += 64){
				for (y = y656, yp_0 = 0;
					y < y656 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1312, fp_2 = f1312_p_1, fp_1 = f1312_p_0, fp_0 = 0;
						f < f1312 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
						// T (h, 3) (3 / 1)
						for (h = h508, hp_0 = 0;
							h < h508 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 64, f = 64
							// T (x, 7) (7 / 1)
							for (x = x656, xp_0 = 0;
								x < x656 + 7;
								x += 1, xp_0 += 1){
										mem_vec_10024 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10025 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_10026 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10027 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_10028 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_10029 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
										mem_vec_10030 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_10031 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
										mem_vec_10032 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10033 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_10034 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10035 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_10036 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_10037 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
										mem_vec_10038 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_10039 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
										mem_vec_10040 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10041 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_10042 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10043 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_10044 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_10045 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
										mem_vec_10046 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_10047 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c984, cp_1 = c984_p_0, cp_0 = 0;
											c < c984 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10024);
											mem_vec_10024 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10025);
											mem_vec_10025 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10026);
											mem_vec_10026 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10027);
											mem_vec_10027 = vec_7;

											vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_10028);
											mem_vec_10028 = vec_9;

											vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

											vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_10029);
											mem_vec_10029 = vec_11;

											vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_10030);
											mem_vec_10030 = vec_13;

											vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

											vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_10031);
											mem_vec_10031 = vec_15;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_18 = _mm256_set1_ps(scal_1);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_10032);
											mem_vec_10032 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_10033);
											mem_vec_10033 = vec_19;



											vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_10034);
											mem_vec_10034 = vec_20;



											vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_10035);
											mem_vec_10035 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_10036);
											mem_vec_10036 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_10037);
											mem_vec_10037 = vec_23;



											vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_10038);
											mem_vec_10038 = vec_24;



											vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_10039);
											mem_vec_10039 = vec_25;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_27 = _mm256_set1_ps(scal_2);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_10040);
											mem_vec_10040 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_10041);
											mem_vec_10041 = vec_28;



											vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_10042);
											mem_vec_10042 = vec_29;



											vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_10043);
											mem_vec_10043 = vec_30;



											vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_10044);
											mem_vec_10044 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_10045);
											mem_vec_10045 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_10046);
											mem_vec_10046 = vec_33;



											vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_10047);
											mem_vec_10047 = vec_34;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_36 = _mm256_set1_ps(scal_3);
											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_10024);
											mem_vec_10024 = vec_35;

											vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_10025);
											mem_vec_10025 = vec_38;

											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_40 = _mm256_fmadd_ps(vec_36, vec_41, mem_vec_10026);
											mem_vec_10026 = vec_40;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_42 = _mm256_fmadd_ps(vec_36, vec_43, mem_vec_10027);
											mem_vec_10027 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_44 = _mm256_fmadd_ps(vec_36, vec_45, mem_vec_10028);
											mem_vec_10028 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

											vec_46 = _mm256_fmadd_ps(vec_36, vec_47, mem_vec_10029);
											mem_vec_10029 = vec_46;

											vec_49 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_48 = _mm256_fmadd_ps(vec_36, vec_49, mem_vec_10030);
											mem_vec_10030 = vec_48;

											vec_51 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

											vec_50 = _mm256_fmadd_ps(vec_36, vec_51, mem_vec_10031);
											mem_vec_10031 = vec_50;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_53 = _mm256_set1_ps(scal_4);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_10032);
											mem_vec_10032 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_10033);
											mem_vec_10033 = vec_54;



											vec_55 = _mm256_fmadd_ps(vec_53, vec_41, mem_vec_10034);
											mem_vec_10034 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_10035);
											mem_vec_10035 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_10036);
											mem_vec_10036 = vec_57;



											vec_58 = _mm256_fmadd_ps(vec_53, vec_47, mem_vec_10037);
											mem_vec_10037 = vec_58;



											vec_59 = _mm256_fmadd_ps(vec_53, vec_49, mem_vec_10038);
											mem_vec_10038 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_53, vec_51, mem_vec_10039);
											mem_vec_10039 = vec_60;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_62 = _mm256_set1_ps(scal_5);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_10040);
											mem_vec_10040 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_10041);
											mem_vec_10041 = vec_63;



											vec_64 = _mm256_fmadd_ps(vec_62, vec_41, mem_vec_10042);
											mem_vec_10042 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_10043);
											mem_vec_10043 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_10044);
											mem_vec_10044 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_62, vec_47, mem_vec_10045);
											mem_vec_10045 = vec_67;



											vec_68 = _mm256_fmadd_ps(vec_62, vec_49, mem_vec_10046);
											mem_vec_10046 = vec_68;



											vec_69 = _mm256_fmadd_ps(vec_62, vec_51, mem_vec_10047);
											mem_vec_10047 = vec_69;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_71 = _mm256_set1_ps(scal_6);
											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_10024);
											mem_vec_10024 = vec_70;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_10025);
											mem_vec_10025 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_75 = _mm256_fmadd_ps(vec_71, vec_76, mem_vec_10026);
											mem_vec_10026 = vec_75;

											vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_77 = _mm256_fmadd_ps(vec_71, vec_78, mem_vec_10027);
											mem_vec_10027 = vec_77;

											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_79 = _mm256_fmadd_ps(vec_71, vec_80, mem_vec_10028);
											mem_vec_10028 = vec_79;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

											vec_81 = _mm256_fmadd_ps(vec_71, vec_82, mem_vec_10029);
											mem_vec_10029 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_83 = _mm256_fmadd_ps(vec_71, vec_84, mem_vec_10030);
											mem_vec_10030 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

											vec_85 = _mm256_fmadd_ps(vec_71, vec_86, mem_vec_10031);
											mem_vec_10031 = vec_85;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_88 = _mm256_set1_ps(scal_7);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_10032);
											mem_vec_10032 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_10033);
											mem_vec_10033 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_10034);
											mem_vec_10034 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_10035);
											mem_vec_10035 = vec_91;



											vec_92 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_10036);
											mem_vec_10036 = vec_92;



											vec_93 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_10037);
											mem_vec_10037 = vec_93;



											vec_94 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_10038);
											mem_vec_10038 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_10039);
											mem_vec_10039 = vec_95;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_97 = _mm256_set1_ps(scal_8);


											vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_10040);
											mem_vec_10040 = vec_96;



											vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_10041);
											mem_vec_10041 = vec_98;



											vec_99 = _mm256_fmadd_ps(vec_97, vec_76, mem_vec_10042);
											mem_vec_10042 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_10043);
											mem_vec_10043 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_10044);
											mem_vec_10044 = vec_101;



											vec_102 = _mm256_fmadd_ps(vec_97, vec_82, mem_vec_10045);
											mem_vec_10045 = vec_102;



											vec_103 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_10046);
											mem_vec_10046 = vec_103;



											vec_104 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_10047);
											mem_vec_10047 = vec_104;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10024);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10025);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10026);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10027);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10028);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_10029);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10030);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_10031);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10032);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10033);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10034);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10035);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10036);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_10037);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10038);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_10039);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10040);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10041);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10042);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10043);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10044);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_10045);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10046);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_10047);
							}
						}
					}
				}
				for (y = y656 + 3, yp_0 = 0;
					y < y656 + 3 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1312, fp_2 = f1312_p_1, fp_1 = f1312_p_0, fp_0 = 0;
						f < f1312 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
						// T (h, 3) (3 / 1)
						for (h = h508, hp_0 = 0;
							h < h508 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 64, f = 64
							// T (x, 7) (7 / 1)
							for (x = x656, xp_0 = 0;
								x < x656 + 7;
								x += 1, xp_0 += 1){
										mem_vec_10048 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10049 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_10050 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10051 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_10052 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_10053 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
										mem_vec_10054 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_10055 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
										mem_vec_10056 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10057 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_10058 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10059 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_10060 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_10061 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
										mem_vec_10062 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_10063 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
										mem_vec_10064 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10065 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_10066 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10067 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_10068 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_10069 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
										mem_vec_10070 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_10071 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
										mem_vec_10072 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10073 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_10074 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10075 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_10076 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_10077 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
										mem_vec_10078 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_10079 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c984, cp_1 = c984_p_0, cp_0 = 0;
											c < c984 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10048);
											mem_vec_10048 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10049);
											mem_vec_10049 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10050);
											mem_vec_10050 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10051);
											mem_vec_10051 = vec_7;

											vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_10052);
											mem_vec_10052 = vec_9;

											vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

											vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_10053);
											mem_vec_10053 = vec_11;

											vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_10054);
											mem_vec_10054 = vec_13;

											vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

											vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_10055);
											mem_vec_10055 = vec_15;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_18 = _mm256_set1_ps(scal_1);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_10056);
											mem_vec_10056 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_10057);
											mem_vec_10057 = vec_19;



											vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_10058);
											mem_vec_10058 = vec_20;



											vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_10059);
											mem_vec_10059 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_10060);
											mem_vec_10060 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_10061);
											mem_vec_10061 = vec_23;



											vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_10062);
											mem_vec_10062 = vec_24;



											vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_10063);
											mem_vec_10063 = vec_25;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_27 = _mm256_set1_ps(scal_2);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_10064);
											mem_vec_10064 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_10065);
											mem_vec_10065 = vec_28;



											vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_10066);
											mem_vec_10066 = vec_29;



											vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_10067);
											mem_vec_10067 = vec_30;



											vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_10068);
											mem_vec_10068 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_10069);
											mem_vec_10069 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_10070);
											mem_vec_10070 = vec_33;



											vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_10071);
											mem_vec_10071 = vec_34;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_36 = _mm256_set1_ps(scal_3);


											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_10072);
											mem_vec_10072 = vec_35;



											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_10073);
											mem_vec_10073 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_10074);
											mem_vec_10074 = vec_38;



											vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_10075);
											mem_vec_10075 = vec_39;



											vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_10076);
											mem_vec_10076 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_10077);
											mem_vec_10077 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_10078);
											mem_vec_10078 = vec_42;



											vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_10079);
											mem_vec_10079 = vec_43;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_45 = _mm256_set1_ps(scal_4);
											vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_10048);
											mem_vec_10048 = vec_44;

											vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_10049);
											mem_vec_10049 = vec_47;

											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_10050);
											mem_vec_10050 = vec_49;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_10051);
											mem_vec_10051 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_10052);
											mem_vec_10052 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

											vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_10053);
											mem_vec_10053 = vec_55;

											vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_10054);
											mem_vec_10054 = vec_57;

											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

											vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_10055);
											mem_vec_10055 = vec_59;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_62 = _mm256_set1_ps(scal_5);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_10056);
											mem_vec_10056 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_10057);
											mem_vec_10057 = vec_63;



											vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_10058);
											mem_vec_10058 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_10059);
											mem_vec_10059 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_10060);
											mem_vec_10060 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_10061);
											mem_vec_10061 = vec_67;



											vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_10062);
											mem_vec_10062 = vec_68;



											vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_10063);
											mem_vec_10063 = vec_69;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_71 = _mm256_set1_ps(scal_6);


											vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_10064);
											mem_vec_10064 = vec_70;



											vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_10065);
											mem_vec_10065 = vec_72;



											vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_10066);
											mem_vec_10066 = vec_73;



											vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_10067);
											mem_vec_10067 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_10068);
											mem_vec_10068 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_10069);
											mem_vec_10069 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_10070);
											mem_vec_10070 = vec_77;



											vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_10071);
											mem_vec_10071 = vec_78;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_80 = _mm256_set1_ps(scal_7);


											vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_10072);
											mem_vec_10072 = vec_79;



											vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_10073);
											mem_vec_10073 = vec_81;



											vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_10074);
											mem_vec_10074 = vec_82;



											vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_10075);
											mem_vec_10075 = vec_83;



											vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_10076);
											mem_vec_10076 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_10077);
											mem_vec_10077 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_10078);
											mem_vec_10078 = vec_86;



											vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_10079);
											mem_vec_10079 = vec_87;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_89 = _mm256_set1_ps(scal_8);
											vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_10048);
											mem_vec_10048 = vec_88;

											vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_10049);
											mem_vec_10049 = vec_91;

											vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_10050);
											mem_vec_10050 = vec_93;

											vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_10051);
											mem_vec_10051 = vec_95;

											vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_10052);
											mem_vec_10052 = vec_97;

											vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

											vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_10053);
											mem_vec_10053 = vec_99;

											vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_10054);
											mem_vec_10054 = vec_101;

											vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

											vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_10055);
											mem_vec_10055 = vec_103;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_106 = _mm256_set1_ps(scal_9);


											vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_10056);
											mem_vec_10056 = vec_105;



											vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_10057);
											mem_vec_10057 = vec_107;



											vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_10058);
											mem_vec_10058 = vec_108;



											vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_10059);
											mem_vec_10059 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_10060);
											mem_vec_10060 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_10061);
											mem_vec_10061 = vec_111;



											vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_10062);
											mem_vec_10062 = vec_112;



											vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_10063);
											mem_vec_10063 = vec_113;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_115 = _mm256_set1_ps(scal_10);


											vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_10064);
											mem_vec_10064 = vec_114;



											vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_10065);
											mem_vec_10065 = vec_116;



											vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_10066);
											mem_vec_10066 = vec_117;



											vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_10067);
											mem_vec_10067 = vec_118;



											vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_10068);
											mem_vec_10068 = vec_119;



											vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_10069);
											mem_vec_10069 = vec_120;



											vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_10070);
											mem_vec_10070 = vec_121;



											vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_10071);
											mem_vec_10071 = vec_122;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_124 = _mm256_set1_ps(scal_11);


											vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_10072);
											mem_vec_10072 = vec_123;



											vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_10073);
											mem_vec_10073 = vec_125;



											vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_10074);
											mem_vec_10074 = vec_126;



											vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_10075);
											mem_vec_10075 = vec_127;



											vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_10076);
											mem_vec_10076 = vec_128;



											vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_10077);
											mem_vec_10077 = vec_129;



											vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_10078);
											mem_vec_10078 = vec_130;



											vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_10079);
											mem_vec_10079 = vec_131;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10048);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10049);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10050);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10051);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10052);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_10053);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10054);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_10055);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10056);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10057);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10058);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10059);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10060);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_10061);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10062);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_10063);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10064);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10065);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10066);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10067);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10068);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_10069);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10070);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_10071);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10072);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10073);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10074);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10075);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10076);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_10077);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10078);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_10079);
							}
						}
					}
				}
		}
	}
}


}