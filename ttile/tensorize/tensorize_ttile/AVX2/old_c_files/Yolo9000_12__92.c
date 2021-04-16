#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (3, h);
  T (34, x); T (16, c);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (8, f);
  T (1, c); T (2, f)]
*/
IND_TYPE c, cp_0, c524_p_0, c525_p_0, cp_1, c524_p_1, cp_2, c524, c525, f, fp_0, f421_p_0, fp_1, f421, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y298 = 0;
IND_TYPE x270 = 0;
IND_TYPE h206 = 0;
IND_TYPE w = 0;
IND_TYPE c526 = 0;
IND_TYPE f422 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6008 ,mem_vec_6009 ,mem_vec_6010 ,mem_vec_6011 ,mem_vec_6012 ,mem_vec_6013 ,mem_vec_6014 ,mem_vec_6015 ,mem_vec_6016 ,mem_vec_6017 ,mem_vec_6018 ,mem_vec_6019 ,mem_vec_6020 ,mem_vec_6021 ,mem_vec_6022 ,mem_vec_6023 ,mem_vec_6024 ,mem_vec_6025 ,mem_vec_6026 ,mem_vec_6027 ,mem_vec_6028 ,mem_vec_6029 ,mem_vec_6030 ,mem_vec_6031 ,mem_vec_6032 ,mem_vec_6033 ,mem_vec_6034 ,mem_vec_6035 ,mem_vec_6036 ,mem_vec_6037 ,mem_vec_6038 ,mem_vec_6039 ,mem_vec_6040 ,mem_vec_6041 ,mem_vec_6042 ,mem_vec_6043 ,mem_vec_6044 ,mem_vec_6045 ,mem_vec_6046 ,mem_vec_6047 ,mem_vec_6048 ,mem_vec_6049 ,mem_vec_6050 ,mem_vec_6051 ,mem_vec_6052 ,mem_vec_6053 ,mem_vec_6054 ,mem_vec_6055 ,mem_vec_6056 ,mem_vec_6057 ,mem_vec_6058 ,mem_vec_6059 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f421 = f422, f421_p_0 = 0;
	f421 < f422 + 512;
	f421 += 256, f421_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (c, 1) (256 / 256)
	for (c525 = c526, c525_p_0 = 0;
		c525 < c526 + 256;
		c525 += 256, c525_p_0 += 256){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f = f421, fp_1 = f421_p_0, fp_0 = 0;
			f < f421 + 256;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y298, yp_0 = 0;
					y < y298 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (c, 16) (256 / 16)
					for (c524 = c525, c524_p_1 = c525_p_0, c524_p_0 = 0;
						c524 < c525 + 256;
						c524 += 16, c524_p_1 += 16, c524_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (x, 34) (34 / 1)
						for (x = x270, xp_0 = 0;
							x < x270 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h206, hp_0 = 0;
								h < h206 + 3;
								h += 1, hp_0 += 1){
										mem_vec_6008 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6009 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_6010 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6011 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_6012 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6013 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_6014 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6015 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_6016 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6017 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_6018 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6019 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_6020 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6021 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_6022 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6023 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_6024 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6025 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_6026 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6027 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_6028 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6029 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_6030 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6031 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c524, cp_2 = c524_p_1, cp_1 = c524_p_0, cp_0 = 0;
											c < c524 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6008);
											mem_vec_6008 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6009);
											mem_vec_6009 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6010);
											mem_vec_6010 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6011);
											mem_vec_6011 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6012);
											mem_vec_6012 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6013);
											mem_vec_6013 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6014);
											mem_vec_6014 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6015);
											mem_vec_6015 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6016);
											mem_vec_6016 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6017);
											mem_vec_6017 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6018);
											mem_vec_6018 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6019);
											mem_vec_6019 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6020);
											mem_vec_6020 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6021);
											mem_vec_6021 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6022);
											mem_vec_6022 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6023);
											mem_vec_6023 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6024);
											mem_vec_6024 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6025);
											mem_vec_6025 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6026);
											mem_vec_6026 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6027);
											mem_vec_6027 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6028);
											mem_vec_6028 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6029);
											mem_vec_6029 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_6030);
											mem_vec_6030 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_6031);
											mem_vec_6031 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_6008);
											mem_vec_6008 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_6009);
											mem_vec_6009 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_6010);
											mem_vec_6010 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_6011);
											mem_vec_6011 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_6012);
											mem_vec_6012 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_6013);
											mem_vec_6013 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_6014);
											mem_vec_6014 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_6015);
											mem_vec_6015 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_6016);
											mem_vec_6016 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_6017);
											mem_vec_6017 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_6018);
											mem_vec_6018 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_6019);
											mem_vec_6019 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_6020);
											mem_vec_6020 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_6021);
											mem_vec_6021 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_6022);
											mem_vec_6022 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_6023);
											mem_vec_6023 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_6024);
											mem_vec_6024 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_6025);
											mem_vec_6025 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_6026);
											mem_vec_6026 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_6027);
											mem_vec_6027 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_6028);
											mem_vec_6028 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_6029);
											mem_vec_6029 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_6030);
											mem_vec_6030 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_6031);
											mem_vec_6031 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_6008);
											mem_vec_6008 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_6009);
											mem_vec_6009 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_6010);
											mem_vec_6010 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_6011);
											mem_vec_6011 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_6012);
											mem_vec_6012 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_6013);
											mem_vec_6013 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_6014);
											mem_vec_6014 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_6015);
											mem_vec_6015 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_6016);
											mem_vec_6016 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_6017);
											mem_vec_6017 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_6018);
											mem_vec_6018 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_6019);
											mem_vec_6019 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_6020);
											mem_vec_6020 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_6021);
											mem_vec_6021 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_6022);
											mem_vec_6022 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_6023);
											mem_vec_6023 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_6024);
											mem_vec_6024 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_6025);
											mem_vec_6025 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_6026);
											mem_vec_6026 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_6027);
											mem_vec_6027 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_6028);
											mem_vec_6028 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_6029);
											mem_vec_6029 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_6030);
											mem_vec_6030 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_6031);
											mem_vec_6031 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6008);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6009);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6010);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6011);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6012);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6013);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6014);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6015);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6016);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6017);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6018);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6019);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6020);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6021);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6022);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6023);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6024);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6025);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6026);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6027);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6028);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6029);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6030);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_6031);
							}
						}
					}
				}
				for (y = y298 + 6, yp_0 = 0;
					y < y298 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (c, 16) (256 / 16)
					for (c524 = c525, c524_p_1 = c525_p_0, c524_p_0 = 0;
						c524 < c525 + 256;
						c524 += 16, c524_p_1 += 16, c524_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (x, 34) (34 / 1)
						for (x = x270, xp_0 = 0;
							x < x270 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h206, hp_0 = 0;
								h < h206 + 3;
								h += 1, hp_0 += 1){
										mem_vec_6032 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6033 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_6034 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6035 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_6036 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6037 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_6038 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6039 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_6040 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6041 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_6042 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6043 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_6044 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6045 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_6046 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6047 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_6048 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6049 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_6050 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6051 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_6052 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6053 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_6054 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6055 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										mem_vec_6056 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6057 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_6058 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_6059 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c524, cp_2 = c524_p_1, cp_1 = c524_p_0, cp_0 = 0;
											c < c524 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6032);
											mem_vec_6032 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6033);
											mem_vec_6033 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6034);
											mem_vec_6034 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6035);
											mem_vec_6035 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6036);
											mem_vec_6036 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6037);
											mem_vec_6037 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6038);
											mem_vec_6038 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6039);
											mem_vec_6039 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6040);
											mem_vec_6040 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6041);
											mem_vec_6041 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6042);
											mem_vec_6042 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6043);
											mem_vec_6043 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6044);
											mem_vec_6044 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6045);
											mem_vec_6045 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6046);
											mem_vec_6046 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6047);
											mem_vec_6047 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6048);
											mem_vec_6048 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6049);
											mem_vec_6049 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6050);
											mem_vec_6050 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6051);
											mem_vec_6051 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6052);
											mem_vec_6052 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6053);
											mem_vec_6053 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_6054);
											mem_vec_6054 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_6055);
											mem_vec_6055 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_6056);
											mem_vec_6056 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_6057);
											mem_vec_6057 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_6058);
											mem_vec_6058 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_6059);
											mem_vec_6059 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_40 = _mm256_set1_ps(scal_7);
											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_6032);
											mem_vec_6032 = vec_39;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_6033);
											mem_vec_6033 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_6034);
											mem_vec_6034 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_6035);
											mem_vec_6035 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_6036);
											mem_vec_6036 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_6037);
											mem_vec_6037 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_6038);
											mem_vec_6038 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_6039);
											mem_vec_6039 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_6040);
											mem_vec_6040 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_6041);
											mem_vec_6041 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_6042);
											mem_vec_6042 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_6043);
											mem_vec_6043 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_6044);
											mem_vec_6044 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_6045);
											mem_vec_6045 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_6046);
											mem_vec_6046 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_6047);
											mem_vec_6047 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_6048);
											mem_vec_6048 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_6049);
											mem_vec_6049 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_6050);
											mem_vec_6050 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_6051);
											mem_vec_6051 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_69 = _mm256_set1_ps(scal_12);


											vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_6052);
											mem_vec_6052 = vec_68;



											vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_6053);
											mem_vec_6053 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_6054);
											mem_vec_6054 = vec_71;



											vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_6055);
											mem_vec_6055 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_74 = _mm256_set1_ps(scal_13);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_6056);
											mem_vec_6056 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_6057);
											mem_vec_6057 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_6058);
											mem_vec_6058 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_6059);
											mem_vec_6059 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_79 = _mm256_set1_ps(scal_14);
											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_6032);
											mem_vec_6032 = vec_78;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_6033);
											mem_vec_6033 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_6034);
											mem_vec_6034 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_6035);
											mem_vec_6035 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_6036);
											mem_vec_6036 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_6037);
											mem_vec_6037 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_6038);
											mem_vec_6038 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_6039);
											mem_vec_6039 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_6040);
											mem_vec_6040 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_6041);
											mem_vec_6041 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_6042);
											mem_vec_6042 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_6043);
											mem_vec_6043 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_6044);
											mem_vec_6044 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_6045);
											mem_vec_6045 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_6046);
											mem_vec_6046 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_6047);
											mem_vec_6047 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_103 = _mm256_set1_ps(scal_18);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_6048);
											mem_vec_6048 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_6049);
											mem_vec_6049 = vec_104;



											vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_6050);
											mem_vec_6050 = vec_105;



											vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_6051);
											mem_vec_6051 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_108 = _mm256_set1_ps(scal_19);


											vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_6052);
											mem_vec_6052 = vec_107;



											vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_6053);
											mem_vec_6053 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_6054);
											mem_vec_6054 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_6055);
											mem_vec_6055 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_113 = _mm256_set1_ps(scal_20);


											vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_6056);
											mem_vec_6056 = vec_112;



											vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_6057);
											mem_vec_6057 = vec_114;



											vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_6058);
											mem_vec_6058 = vec_115;



											vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_6059);
											mem_vec_6059 = vec_116;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6032);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6033);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6034);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6035);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6036);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6037);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6038);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6039);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6040);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6041);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6042);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6043);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6044);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6045);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6046);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6047);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6048);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6049);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6050);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6051);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6052);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6053);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6054);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_6055);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6056);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6057);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6058);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_6059);
							}
						}
					}
				}
		}
	}
}


}