#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (4, c);
  T (2, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, x);
  T (2, y)]
*/
IND_TYPE c, cp_0, c60_p_0, cp_1, c60, f, fp_0, x, xp_0, x80_p_0, x81_p_0, xp_1, x80_p_1, xp_2, x80, x81, y, yp_0, y60_p_0, yp_1, y60;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y61 = 0;
IND_TYPE x82 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c61 = 0;
IND_TYPE f40 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1040 ,mem_vec_1041 ,mem_vec_1042 ,mem_vec_1043 ,mem_vec_1044 ,mem_vec_1045 ,mem_vec_1046 ,mem_vec_1047 ,mem_vec_1048 ,mem_vec_1049 ,mem_vec_1050 ,mem_vec_1051 ,mem_vec_1052 ,mem_vec_1053 ,mem_vec_1054 ,mem_vec_1055 ,mem_vec_1056 ,mem_vec_1057 ,mem_vec_1058 ,mem_vec_1059 ,mem_vec_1060 ,mem_vec_1061 ,mem_vec_1062 ,mem_vec_1063 ,mem_vec_1064 ,mem_vec_1065 ,mem_vec_1066 ,mem_vec_1067 ,mem_vec_1068 ,mem_vec_1069 ,mem_vec_1070 ,mem_vec_1071 ,mem_vec_1072 ,mem_vec_1073 ,mem_vec_1074 ,mem_vec_1075 ,mem_vec_1076 ,mem_vec_1077 ,mem_vec_1078 ,mem_vec_1079 ,mem_vec_1080 ,mem_vec_1081 ,mem_vec_1082 ,mem_vec_1083 ,mem_vec_1084 ,mem_vec_1085 ,mem_vec_1086 ,mem_vec_1087 ,mem_vec_1088 ,mem_vec_1089 ,mem_vec_1090 ,mem_vec_1091 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 2) (68 / 34)
for (y60 = y61, y60_p_0 = 0;
	y60 < y61 + 68;
	y60 += 34, y60_p_0 += 34){
	// y = 34, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 4) (68 / 17)
	for (x81 = x82, x81_p_0 = 0;
		x81 < x82 + 68;
		x81 += 17, x81_p_0 += 17){
			for (y = y60, yp_1 = y60_p_0, yp_0 = 0;
				y < y60 + 6;
				y += 6, yp_1 += 6, yp_0 += 6){
				// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (17 / 17)
				for (x80 = x81, x80_p_1 = x81_p_0, x80_p_0 = 0;
					x80 < x81 + 17;
					x80 += 17, x80_p_1 += 17, x80_p_0 += 17){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f40, fp_0 = 0;
						f < f40 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (c, 4) (256 / 64)
						for (c60 = c61, c60_p_0 = 0;
							c60 < c61 + 256;
							c60 += 64, c60_p_0 += 64){
							// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
							// T (x, 17) (17 / 1)
							for (x = x80, xp_2 = x80_p_1, xp_1 = x80_p_0, xp_0 = 0;
								x < x80 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1040 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1041 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1042 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_1043 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_1044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_1047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_1048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_1051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_1052 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1053 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_1055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_1056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1057 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1058 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_1059 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_1060 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1061 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1062 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_1063 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c60, cp_1 = c60_p_0, cp_0 = 0;
											c < c60 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1040);
											mem_vec_1040 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1041);
											mem_vec_1041 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1042);
											mem_vec_1042 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1043);
											mem_vec_1043 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1044);
											mem_vec_1044 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1045);
											mem_vec_1045 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1046);
											mem_vec_1046 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1047);
											mem_vec_1047 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1048);
											mem_vec_1048 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1049);
											mem_vec_1049 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1050);
											mem_vec_1050 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1051);
											mem_vec_1051 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1052);
											mem_vec_1052 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1053);
											mem_vec_1053 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1054);
											mem_vec_1054 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1055);
											mem_vec_1055 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1056);
											mem_vec_1056 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1057);
											mem_vec_1057 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1058);
											mem_vec_1058 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1059);
											mem_vec_1059 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1060);
											mem_vec_1060 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1061);
											mem_vec_1061 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1062);
											mem_vec_1062 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1063);
											mem_vec_1063 = vec_33;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1040);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1041);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1042);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1043);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1044);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1045);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1046);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1047);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1048);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1049);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1050);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1051);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1052);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1053);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1054);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1055);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1056);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1057);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1058);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1059);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1060);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1061);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_1062);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_1063);
							}
						}
					}
				}
			}
			for (y = y60 + 6, yp_1 = y60_p_0, yp_0 = 0;
				y < y60 + 6 + 28;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (17 / 17)
				for (x80 = x81, x80_p_1 = x81_p_0, x80_p_0 = 0;
					x80 < x81 + 17;
					x80 += 17, x80_p_1 += 17, x80_p_0 += 17){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f40, fp_0 = 0;
						f < f40 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (c, 4) (256 / 64)
						for (c60 = c61, c60_p_0 = 0;
							c60 < c61 + 256;
							c60 += 64, c60_p_0 += 64){
							// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
							// T (x, 17) (17 / 1)
							for (x = x80, xp_2 = x80_p_1, xp_1 = x80_p_0, xp_0 = 0;
								x < x80 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1064 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1065 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1066 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_1067 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_1068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_1071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_1072 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_1075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_1076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_1079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_1080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1082 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_1083 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_1084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_1087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_1088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_1089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_1090 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_1091 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c60, cp_1 = c60_p_0, cp_0 = 0;
											c < c60 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1064);
											mem_vec_1064 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1065);
											mem_vec_1065 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1066);
											mem_vec_1066 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1067);
											mem_vec_1067 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1068);
											mem_vec_1068 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1069);
											mem_vec_1069 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1070);
											mem_vec_1070 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1071);
											mem_vec_1071 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1072);
											mem_vec_1072 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1073);
											mem_vec_1073 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1074);
											mem_vec_1074 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1075);
											mem_vec_1075 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1076);
											mem_vec_1076 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1077);
											mem_vec_1077 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1078);
											mem_vec_1078 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1079);
											mem_vec_1079 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1080);
											mem_vec_1080 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1081);
											mem_vec_1081 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1082);
											mem_vec_1082 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1083);
											mem_vec_1083 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1084);
											mem_vec_1084 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1085);
											mem_vec_1085 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1086);
											mem_vec_1086 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1087);
											mem_vec_1087 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_1088);
											mem_vec_1088 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_1089);
											mem_vec_1089 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_1090);
											mem_vec_1090 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_1091);
											mem_vec_1091 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1064);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1065);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1066);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1067);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1068);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1069);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1070);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1071);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1072);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1073);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1074);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1075);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1076);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1077);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1078);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1079);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1080);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1081);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1082);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1083);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1084);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1085);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_1086);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_1087);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1088);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1089);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_1090);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_1091);
							}
						}
					}
				}
			}
	}
}


}