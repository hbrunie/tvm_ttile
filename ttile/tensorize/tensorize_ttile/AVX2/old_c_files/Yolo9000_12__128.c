#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (34, x); T (2, c);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (8, c); T (4, f)]
*/
IND_TYPE c, cp_0, c86_p_0, c87_p_0, cp_1, c86_p_1, cp_2, c86, c87, f, fp_0, f82_p_0, fp_1, f82, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y58 = 0;
IND_TYPE x48 = 0;
IND_TYPE h = 0;
IND_TYPE w42 = 0;
IND_TYPE c88 = 0;
IND_TYPE f83 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1028 ,mem_vec_1029 ,mem_vec_1030 ,mem_vec_1031 ,mem_vec_1032 ,mem_vec_1033 ,mem_vec_1034 ,mem_vec_1035 ,mem_vec_1036 ,mem_vec_1037 ,mem_vec_1038 ,mem_vec_1039 ,mem_vec_1040 ,mem_vec_1041 ,mem_vec_1042 ,mem_vec_1043 ,mem_vec_1044 ,mem_vec_1045 ,mem_vec_1046 ,mem_vec_1047 ,mem_vec_1048 ,mem_vec_1049 ,mem_vec_1050 ,mem_vec_1051 ,mem_vec_1052 ,mem_vec_1053 ,mem_vec_1054 ,mem_vec_1055 ,mem_vec_1056 ,mem_vec_1057 ,mem_vec_1058 ,mem_vec_1059 ,mem_vec_1060 ,mem_vec_1061 ,mem_vec_1062 ,mem_vec_1063 ,mem_vec_1064 ,mem_vec_1065 ,mem_vec_1066 ,mem_vec_1067 ,mem_vec_1068 ,mem_vec_1069 ,mem_vec_1070 ,mem_vec_1071 ,mem_vec_1072 ,mem_vec_1073 ,mem_vec_1074 ,mem_vec_1075 ,mem_vec_1076 ,mem_vec_1077 ,mem_vec_1078 ,mem_vec_1079 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f82 = f83, f82_p_0 = 0;
	f82 < f83 + 512;
	f82 += 128, f82_p_0 += 128){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
	// T (c, 8) (256 / 32)
	for (c87 = c88, c87_p_0 = 0;
		c87 < c88 + 256;
		c87 += 32, c87_p_0 += 32){
		// y = 34, x = 34, h = 3, w = 3, c = 32, f = 128
		// T (f, 4) (128 / 32)
		for (f = f82, fp_1 = f82_p_0, fp_0 = 0;
			f < f82 + 128;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y58, yp_0 = 0;
					y < y58 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c86 = c87, c86_p_1 = c87_p_0, c86_p_0 = 0;
						c86 < c87 + 32;
						c86 += 16, c86_p_1 += 16, c86_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (x, 34) (34 / 1)
						for (x = x48, xp_0 = 0;
							x < x48 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w42, wp_0 = 0;
								w < w42 + 3;
								w += 1, wp_0 += 1){
										mem_vec_1028 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1029 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_1030 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1031 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_1032 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1033 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_1034 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1035 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_1036 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1037 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_1038 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1039 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_1040 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1041 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_1042 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1043 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_1044 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1045 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_1046 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1047 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_1048 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1049 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_1050 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1051 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c86, cp_2 = c86_p_1, cp_1 = c86_p_0, cp_0 = 0;
											c < c86 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1028);
											mem_vec_1028 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1029);
											mem_vec_1029 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1030);
											mem_vec_1030 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1031);
											mem_vec_1031 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1032);
											mem_vec_1032 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1033);
											mem_vec_1033 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1034);
											mem_vec_1034 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1035);
											mem_vec_1035 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1036);
											mem_vec_1036 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1037);
											mem_vec_1037 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1038);
											mem_vec_1038 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1039);
											mem_vec_1039 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1040);
											mem_vec_1040 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1041);
											mem_vec_1041 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1042);
											mem_vec_1042 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1043);
											mem_vec_1043 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1044);
											mem_vec_1044 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1045);
											mem_vec_1045 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1046);
											mem_vec_1046 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1047);
											mem_vec_1047 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_1048);
											mem_vec_1048 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_1049);
											mem_vec_1049 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_1050);
											mem_vec_1050 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_1051);
											mem_vec_1051 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_1028);
											mem_vec_1028 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_1029);
											mem_vec_1029 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_1030);
											mem_vec_1030 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_1031);
											mem_vec_1031 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_1032);
											mem_vec_1032 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_1033);
											mem_vec_1033 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_1034);
											mem_vec_1034 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_1035);
											mem_vec_1035 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_1036);
											mem_vec_1036 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_1037);
											mem_vec_1037 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_1038);
											mem_vec_1038 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_1039);
											mem_vec_1039 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_1040);
											mem_vec_1040 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_1041);
											mem_vec_1041 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_1042);
											mem_vec_1042 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_1043);
											mem_vec_1043 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_1044);
											mem_vec_1044 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_1045);
											mem_vec_1045 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_1046);
											mem_vec_1046 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_1047);
											mem_vec_1047 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_1048);
											mem_vec_1048 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_1049);
											mem_vec_1049 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_1050);
											mem_vec_1050 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_1051);
											mem_vec_1051 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_1028);
											mem_vec_1028 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_1029);
											mem_vec_1029 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_1030);
											mem_vec_1030 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_1031);
											mem_vec_1031 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_1032);
											mem_vec_1032 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_1033);
											mem_vec_1033 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_1034);
											mem_vec_1034 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_1035);
											mem_vec_1035 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_1036);
											mem_vec_1036 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_1037);
											mem_vec_1037 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_1038);
											mem_vec_1038 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_1039);
											mem_vec_1039 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_1040);
											mem_vec_1040 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_1041);
											mem_vec_1041 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_1042);
											mem_vec_1042 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_1043);
											mem_vec_1043 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_1044);
											mem_vec_1044 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_1045);
											mem_vec_1045 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_1046);
											mem_vec_1046 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_1047);
											mem_vec_1047 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_1048);
											mem_vec_1048 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_1049);
											mem_vec_1049 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_1050);
											mem_vec_1050 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_1051);
											mem_vec_1051 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1028);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1029);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1030);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1031);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1032);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1033);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1034);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1035);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1036);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1037);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1038);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1039);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1040);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1041);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1042);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1043);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1044);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1045);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1046);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1047);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1048);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_1049);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1050);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_1051);
							}
						}
					}
				}
				for (y = y58 + 6, yp_0 = 0;
					y < y58 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c86 = c87, c86_p_1 = c87_p_0, c86_p_0 = 0;
						c86 < c87 + 32;
						c86 += 16, c86_p_1 += 16, c86_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (x, 34) (34 / 1)
						for (x = x48, xp_0 = 0;
							x < x48 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w42, wp_0 = 0;
								w < w42 + 3;
								w += 1, wp_0 += 1){
										mem_vec_1052 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1053 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_1054 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1055 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_1056 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1057 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_1058 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1059 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_1060 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1061 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_1062 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1063 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_1064 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1065 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_1066 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1067 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_1068 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1069 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_1070 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1071 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_1072 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1073 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_1074 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1075 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										mem_vec_1076 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_1077 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_1078 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_1079 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c86, cp_2 = c86_p_1, cp_1 = c86_p_0, cp_0 = 0;
											c < c86 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1052);
											mem_vec_1052 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1053);
											mem_vec_1053 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1054);
											mem_vec_1054 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1055);
											mem_vec_1055 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1056);
											mem_vec_1056 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1057);
											mem_vec_1057 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1058);
											mem_vec_1058 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1059);
											mem_vec_1059 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1060);
											mem_vec_1060 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1061);
											mem_vec_1061 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1062);
											mem_vec_1062 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1063);
											mem_vec_1063 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1064);
											mem_vec_1064 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1065);
											mem_vec_1065 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1066);
											mem_vec_1066 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1067);
											mem_vec_1067 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1068);
											mem_vec_1068 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1069);
											mem_vec_1069 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1070);
											mem_vec_1070 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1071);
											mem_vec_1071 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_1072);
											mem_vec_1072 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_1073);
											mem_vec_1073 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_1074);
											mem_vec_1074 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_1075);
											mem_vec_1075 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_1076);
											mem_vec_1076 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_1077);
											mem_vec_1077 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_1078);
											mem_vec_1078 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_1079);
											mem_vec_1079 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_40 = _mm256_set1_ps(scal_7);
											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_1052);
											mem_vec_1052 = vec_39;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_1053);
											mem_vec_1053 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_1054);
											mem_vec_1054 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_1055);
											mem_vec_1055 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_1056);
											mem_vec_1056 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_1057);
											mem_vec_1057 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_1058);
											mem_vec_1058 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_1059);
											mem_vec_1059 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_1060);
											mem_vec_1060 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_1061);
											mem_vec_1061 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_1062);
											mem_vec_1062 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_1063);
											mem_vec_1063 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_1064);
											mem_vec_1064 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_1065);
											mem_vec_1065 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_1066);
											mem_vec_1066 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_1067);
											mem_vec_1067 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_1068);
											mem_vec_1068 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_1069);
											mem_vec_1069 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_1070);
											mem_vec_1070 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_1071);
											mem_vec_1071 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_69 = _mm256_set1_ps(scal_12);


											vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_1072);
											mem_vec_1072 = vec_68;



											vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_1073);
											mem_vec_1073 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_1074);
											mem_vec_1074 = vec_71;



											vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_1075);
											mem_vec_1075 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_13);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_1076);
											mem_vec_1076 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_1077);
											mem_vec_1077 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_1078);
											mem_vec_1078 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_1079);
											mem_vec_1079 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_14);
											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_1052);
											mem_vec_1052 = vec_78;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_1053);
											mem_vec_1053 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_1054);
											mem_vec_1054 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_1055);
											mem_vec_1055 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_1056);
											mem_vec_1056 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_1057);
											mem_vec_1057 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_1058);
											mem_vec_1058 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_1059);
											mem_vec_1059 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_1060);
											mem_vec_1060 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_1061);
											mem_vec_1061 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_1062);
											mem_vec_1062 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_1063);
											mem_vec_1063 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_1064);
											mem_vec_1064 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_1065);
											mem_vec_1065 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_1066);
											mem_vec_1066 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_1067);
											mem_vec_1067 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_18);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_1068);
											mem_vec_1068 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_1069);
											mem_vec_1069 = vec_104;



											vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_1070);
											mem_vec_1070 = vec_105;



											vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_1071);
											mem_vec_1071 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_108 = _mm256_set1_ps(scal_19);


											vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_1072);
											mem_vec_1072 = vec_107;



											vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_1073);
											mem_vec_1073 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_1074);
											mem_vec_1074 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_1075);
											mem_vec_1075 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_113 = _mm256_set1_ps(scal_20);


											vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_1076);
											mem_vec_1076 = vec_112;



											vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_1077);
											mem_vec_1077 = vec_114;



											vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_1078);
											mem_vec_1078 = vec_115;



											vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_1079);
											mem_vec_1079 = vec_116;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1052);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1053);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1054);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1055);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1056);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1057);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1058);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1059);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1060);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1061);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1062);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1063);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1064);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1065);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1066);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1067);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1068);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1069);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1070);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1071);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1072);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_1073);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1074);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_1075);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1076);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_1077);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1078);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_1079);
							}
						}
					}
				}
		}
	}
}


}