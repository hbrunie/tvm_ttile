#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (8, f); T (16, c); T (4, f); T (1, f)]
*/
IND_TYPE c, cp_0, c84_p_0, cp_1, c84, f, fp_0, f112_p_0, f113_p_0, fp_1, f112_p_1, fp_2, f112, f113, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y56 = 0;
IND_TYPE x56 = 0;
IND_TYPE h = 0;
IND_TYPE w48 = 0;
IND_TYPE c85 = 0;
IND_TYPE f114 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1096 ,mem_vec_1097 ,mem_vec_1098 ,mem_vec_1099 ,mem_vec_1100 ,mem_vec_1101 ,mem_vec_1102 ,mem_vec_1103 ,mem_vec_1104 ,mem_vec_1105 ,mem_vec_1106 ,mem_vec_1107 ,mem_vec_1108 ,mem_vec_1109 ,mem_vec_1110 ,mem_vec_1111 ,mem_vec_1112 ,mem_vec_1113 ,mem_vec_1114 ,mem_vec_1115 ,mem_vec_1116 ,mem_vec_1117 ,mem_vec_1118 ,mem_vec_1119 ,mem_vec_1120 ,mem_vec_1121 ,mem_vec_1122 ,mem_vec_1123 ,mem_vec_1124 ,mem_vec_1125 ,mem_vec_1126 ,mem_vec_1127 ,mem_vec_1128 ,mem_vec_1129 ,mem_vec_1130 ,mem_vec_1131 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 1) (1024 / 1024)
for (f113 = f114, f113_p_0 = 0;
	f113 < f114 + 1024;
	f113 += 1024, f113_p_0 += 1024){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (f, 4) (1024 / 256)
	for (f112 = f113, f112_p_1 = f113_p_0, f112_p_0 = 0;
		f112 < f113 + 1024;
		f112 += 256, f112_p_1 += 256, f112_p_0 += 256){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 256
		// T (c, 16) (512 / 32)
		for (c84 = c85, c84_p_0 = 0;
			c84 < c85 + 512;
			c84 += 32, c84_p_0 += 32){
			// y = 17, x = 17, h = 3, w = 3, c = 32, f = 256
			// T (f, 8) (256 / 32)
			for (f = f112, fp_2 = f112_p_1, fp_1 = f112_p_0, fp_0 = 0;
				f < f112 + 256;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y56, yp_0 = 0;
						y < y56 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x56, xp_0 = 0;
							x < x56 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w48, wp_0 = 0;
								w < w48 + 3;
								w += 1, wp_0 += 1){
										mem_vec_1096 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1097 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_1098 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1099 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_1100 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1101 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_1102 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1103 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_1104 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1105 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_1106 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1107 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_1108 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1109 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_1110 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1111 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c84, cp_1 = c84_p_0, cp_0 = 0;
											c < c84 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1096);
											mem_vec_1096 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1097);
											mem_vec_1097 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1098);
											mem_vec_1098 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1099);
											mem_vec_1099 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1100);
											mem_vec_1100 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1101);
											mem_vec_1101 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1102);
											mem_vec_1102 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1103);
											mem_vec_1103 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1104);
											mem_vec_1104 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1105);
											mem_vec_1105 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1106);
											mem_vec_1106 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1107);
											mem_vec_1107 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1108);
											mem_vec_1108 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1109);
											mem_vec_1109 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1110);
											mem_vec_1110 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1111);
											mem_vec_1111 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_1096);
											mem_vec_1096 = vec_24;

											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_1097);
											mem_vec_1097 = vec_27;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_1098);
											mem_vec_1098 = vec_29;

											vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_1099);
											mem_vec_1099 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_34 = _mm256_set1_ps(scal_5);


											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_1100);
											mem_vec_1100 = vec_33;



											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_1101);
											mem_vec_1101 = vec_35;



											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_1102);
											mem_vec_1102 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_1103);
											mem_vec_1103 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_1104);
											mem_vec_1104 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_1105);
											mem_vec_1105 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_1106);
											mem_vec_1106 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_1107);
											mem_vec_1107 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_1108);
											mem_vec_1108 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_1109);
											mem_vec_1109 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_1110);
											mem_vec_1110 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_1111);
											mem_vec_1111 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_1096);
											mem_vec_1096 = vec_48;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_1097);
											mem_vec_1097 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_1098);
											mem_vec_1098 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_1099);
											mem_vec_1099 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_58 = _mm256_set1_ps(scal_9);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_1100);
											mem_vec_1100 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_1101);
											mem_vec_1101 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_1102);
											mem_vec_1102 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_1103);
											mem_vec_1103 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_63 = _mm256_set1_ps(scal_10);


											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_1104);
											mem_vec_1104 = vec_62;



											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_1105);
											mem_vec_1105 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_1106);
											mem_vec_1106 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_1107);
											mem_vec_1107 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_1108);
											mem_vec_1108 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_1109);
											mem_vec_1109 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_1110);
											mem_vec_1110 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_1111);
											mem_vec_1111 = vec_71;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1096);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1097);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1098);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1099);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1100);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1101);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1102);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1103);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1104);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1105);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1106);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1107);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1108);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1109);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1110);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1111);
							}
						}
					}
					for (y = y56 + 12, yp_0 = 0;
						y < y56 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x56, xp_0 = 0;
							x < x56 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w48, wp_0 = 0;
								w < w48 + 3;
								w += 1, wp_0 += 1){
										mem_vec_1112 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1113 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_1114 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1115 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_1116 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1117 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_1118 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1119 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_1120 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1121 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_1122 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1123 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_1124 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1125 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_1126 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1127 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_1128 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1129 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_1130 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1131 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c84, cp_1 = c84_p_0, cp_0 = 0;
											c < c84 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1112);
											mem_vec_1112 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1113);
											mem_vec_1113 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1114);
											mem_vec_1114 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1115);
											mem_vec_1115 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1116);
											mem_vec_1116 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1117);
											mem_vec_1117 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1118);
											mem_vec_1118 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1119);
											mem_vec_1119 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1120);
											mem_vec_1120 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1121);
											mem_vec_1121 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1122);
											mem_vec_1122 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1123);
											mem_vec_1123 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1124);
											mem_vec_1124 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1125);
											mem_vec_1125 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1126);
											mem_vec_1126 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1127);
											mem_vec_1127 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1128);
											mem_vec_1128 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1129);
											mem_vec_1129 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1130);
											mem_vec_1130 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1131);
											mem_vec_1131 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_1112);
											mem_vec_1112 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_1113);
											mem_vec_1113 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_1114);
											mem_vec_1114 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_1115);
											mem_vec_1115 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_1116);
											mem_vec_1116 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_1117);
											mem_vec_1117 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_1118);
											mem_vec_1118 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_1119);
											mem_vec_1119 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_1120);
											mem_vec_1120 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_1121);
											mem_vec_1121 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_1122);
											mem_vec_1122 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_1123);
											mem_vec_1123 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_1124);
											mem_vec_1124 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_1125);
											mem_vec_1125 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_1126);
											mem_vec_1126 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_1127);
											mem_vec_1127 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_1128);
											mem_vec_1128 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_1129);
											mem_vec_1129 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_1130);
											mem_vec_1130 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_1131);
											mem_vec_1131 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_1112);
											mem_vec_1112 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_1113);
											mem_vec_1113 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_1114);
											mem_vec_1114 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_1115);
											mem_vec_1115 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_1116);
											mem_vec_1116 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_1117);
											mem_vec_1117 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_1118);
											mem_vec_1118 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_1119);
											mem_vec_1119 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_1120);
											mem_vec_1120 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_1121);
											mem_vec_1121 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_1122);
											mem_vec_1122 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_1123);
											mem_vec_1123 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_1124);
											mem_vec_1124 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_1125);
											mem_vec_1125 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_1126);
											mem_vec_1126 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_1127);
											mem_vec_1127 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_1128);
											mem_vec_1128 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_1129);
											mem_vec_1129 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_1130);
											mem_vec_1130 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_1131);
											mem_vec_1131 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1112);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1113);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1114);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1115);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1116);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1117);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1118);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1119);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1120);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1121);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1122);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1123);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1124);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1125);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1126);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1127);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1128);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1129);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1130);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1131);
							}
						}
					}
			}
		}
	}
}


}