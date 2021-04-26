#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (34, x); T (1, y); T (8, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 13))]]
*/
IND_TYPE c, cp_0, c69_p_0, cp_1, c69, f, fp_0, x, xp_0, x92_p_0, x93_p_0, xp_1, x92_p_1, xp_2, x92, x93, y, yp_0, y61_p_0, yp_1, y61;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y62 = 0;
IND_TYPE x94 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c70 = 0;
IND_TYPE f46 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1046 ,mem_vec_1047 ,mem_vec_1048 ,mem_vec_1049 ,mem_vec_1050 ,mem_vec_1051 ,mem_vec_1052 ,mem_vec_1053 ,mem_vec_1054 ,mem_vec_1055 ,mem_vec_1056 ,mem_vec_1057 ,mem_vec_1058 ,mem_vec_1059 ,mem_vec_1060 ,mem_vec_1061 ,mem_vec_1062 ,mem_vec_1063 ,mem_vec_1064 ,mem_vec_1065 ,mem_vec_1066 ,mem_vec_1067 ,mem_vec_1068 ,mem_vec_1069 ,mem_vec_1070 ,mem_vec_1071 ,mem_vec_1072 ,mem_vec_1073 ,mem_vec_1074 ,mem_vec_1075 ,mem_vec_1076 ,mem_vec_1077 ,mem_vec_1078 ,mem_vec_1079 ,mem_vec_1080 ,mem_vec_1081 ,mem_vec_1082 ,mem_vec_1083 ,mem_vec_1084 ,mem_vec_1085 ,mem_vec_1086 ,mem_vec_1087 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y61 = y62, y61_p_0 = 0;
		y61 < y62 + 8;
		y61 += 8, y61_p_0 += 8){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x93 = x94, x93_p_0 = 0;
			x93 < x94 + 34;
			x93 += 34, x93_p_0 += 34){
			// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (f, 8) (256 / 32)
			for (f = f46, fp_0 = 0;
				f < f46 + 256;
				f += 32, fp_0 += 32){
				// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
				// T (y, 1) (ph_y / ph_y)
				for (y = y61, yp_1 = y61_p_0, yp_0 = 0;
					y < y61 + 8;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 34) (34 / 1)
					for (x92 = x93, x92_p_1 = x93_p_0, x92_p_0 = 0;
						x92 < x93 + 34;
						x92 += 1, x92_p_1 += 1, x92_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
						// T (c, 2) (512 / 256)
						for (c69 = c70, c69_p_0 = 0;
							c69 < c70 + 512;
							c69 += 256, c69_p_0 += 256){
							// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
							// T (x, 1) (1 / 1)
							for (x = x92, xp_2 = x92_p_1, xp_1 = x92_p_0, xp_0 = 0;
								x < x92 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1046 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1047 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1052 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1053 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1057 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1058 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_1059 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_1060 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_1061 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c69, cp_1 = c69_p_0, cp_0 = 0;
											c < c69 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1046);
											mem_vec_1046 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1047);
											mem_vec_1047 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1048);
											mem_vec_1048 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1049);
											mem_vec_1049 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1050);
											mem_vec_1050 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1051);
											mem_vec_1051 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1052);
											mem_vec_1052 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1053);
											mem_vec_1053 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1054);
											mem_vec_1054 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1055);
											mem_vec_1055 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1056);
											mem_vec_1056 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1057);
											mem_vec_1057 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1058);
											mem_vec_1058 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1059);
											mem_vec_1059 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1060);
											mem_vec_1060 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1061);
											mem_vec_1061 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1046);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1047);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1048);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1049);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1050);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1051);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1052);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1053);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1054);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1055);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1056);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1057);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1058);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1059);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1060);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1061);
							}
						}
					}
				}
			}
		}
	}
	for (y61 = y62 + 8, y61_p_0 = 0;
		y61 < y62 + 8 + 26;
		y61 += 13, y61_p_0 += 13){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x93 = x94, x93_p_0 = 0;
			x93 < x94 + 34;
			x93 += 34, x93_p_0 += 34){
			// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (f, 8) (256 / 32)
			for (f = f46, fp_0 = 0;
				f < f46 + 256;
				f += 32, fp_0 += 32){
				// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
				// T (y, 1) (ph_y / ph_y)
				for (y = y61, yp_1 = y61_p_0, yp_0 = 0;
					y < y61 + 13;
					y += 13, yp_1 += 13, yp_0 += 13){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 34) (34 / 1)
					for (x92 = x93, x92_p_1 = x93_p_0, x92_p_0 = 0;
						x92 < x93 + 34;
						x92 += 1, x92_p_1 += 1, x92_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
						// T (c, 2) (512 / 256)
						for (c69 = c70, c69_p_0 = 0;
							c69 < c70 + 512;
							c69 += 256, c69_p_0 += 256){
							// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
							// T (x, 1) (1 / 1)
							for (x = x92, xp_2 = x92_p_1, xp_1 = x92_p_0, xp_0 = 0;
								x < x92 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1062 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1063 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1066 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1067 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1072 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_1075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_1076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_1077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_1078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_1079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_1080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_1081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_1082 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_1083 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_1084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_1085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_1086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_1087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c69, cp_1 = c69_p_0, cp_0 = 0;
											c < c69 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1062);
											mem_vec_1062 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1063);
											mem_vec_1063 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1064);
											mem_vec_1064 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1065);
											mem_vec_1065 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1066);
											mem_vec_1066 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1067);
											mem_vec_1067 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1068);
											mem_vec_1068 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1069);
											mem_vec_1069 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1070);
											mem_vec_1070 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1071);
											mem_vec_1071 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1072);
											mem_vec_1072 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1073);
											mem_vec_1073 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1074);
											mem_vec_1074 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1075);
											mem_vec_1075 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1076);
											mem_vec_1076 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1077);
											mem_vec_1077 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1078);
											mem_vec_1078 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1079);
											mem_vec_1079 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1080);
											mem_vec_1080 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1081);
											mem_vec_1081 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1082);
											mem_vec_1082 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1083);
											mem_vec_1083 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1084);
											mem_vec_1084 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1085);
											mem_vec_1085 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_1086);
											mem_vec_1086 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_1087);
											mem_vec_1087 = vec_40;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1062);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1063);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1064);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1065);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1066);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1067);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1068);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1069);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1070);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1071);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1072);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1073);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1074);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1075);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1076);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1077);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1078);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1079);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1080);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1081);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1082);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1083);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1084);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_1085);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_1086);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_1087);
							}
						}
					}
				}
			}
		}
	}


}