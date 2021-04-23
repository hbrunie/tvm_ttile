#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (112, x); T (1, y); T (1, c);
  Lambda_apply y [((Iter 9), (Arg 11)); ((Iter 1), (Arg 13))]]
*/
IND_TYPE c, cp_0, c81_p_0, cp_1, c81, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y81_p_0, yp_1, y81;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y82 = 0;
IND_TYPE x54 = 0;
IND_TYPE h54 = 0;
IND_TYPE w54 = 0;
IND_TYPE c82 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1096 ,mem_vec_1097 ,mem_vec_1098 ,mem_vec_1099 ,mem_vec_1100 ,mem_vec_1101 ,mem_vec_1102 ,mem_vec_1103 ,mem_vec_1104 ,mem_vec_1105 ,mem_vec_1106 ,mem_vec_1107 ,mem_vec_1108 ,mem_vec_1109 ,mem_vec_1110 ,mem_vec_1111 ,mem_vec_1112 ,mem_vec_1113 ,mem_vec_1114 ,mem_vec_1115 ,mem_vec_1116 ,mem_vec_1117 ,mem_vec_1118 ,mem_vec_1119 ,mem_vec_1120 ,mem_vec_1121 ,mem_vec_1122 ,mem_vec_1123 ,mem_vec_1124 ,mem_vec_1125 ,mem_vec_1126 ,mem_vec_1127 ,mem_vec_1128 ,mem_vec_1129 ,mem_vec_1130 ,mem_vec_1131 ,mem_vec_1132 ,mem_vec_1133 ,mem_vec_1134 ,mem_vec_1135 ,mem_vec_1136 ,mem_vec_1137 ,mem_vec_1138 ,mem_vec_1139 ,mem_vec_1140 ,mem_vec_1141 ,mem_vec_1142 ,mem_vec_1143 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y81 = y82, y81_p_0 = 0;
		y81 < y82 + 99;
		y81 += 11, y81_p_0 += 11){
		// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c81 = c82, c81_p_0 = 0;
			c81 < c82 + 32;
			c81 += 32, c81_p_0 += 32){
			// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y81, yp_1 = y81_p_0, yp_0 = 0;
				y < y81 + 11;
				y += 11, yp_1 += 11, yp_0 += 11){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x54, xp_0 = 0;
					x < x54 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h54, hp_0 = 0;
						h < h54 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w54, wp_0 = 0;
							w < w54 + 3;
							w += 1, wp_0 += 1){
									mem_vec_1096 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1097 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1098 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1099 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_1107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_1108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_1109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_1110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_1111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_1112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_1113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_1114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_1115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_1116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_1117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c81, cp_1 = c81_p_0, cp_0 = 0;
										c < c81 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1096);
										mem_vec_1096 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1097);
										mem_vec_1097 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1098);
										mem_vec_1098 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1099);
										mem_vec_1099 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1100);
										mem_vec_1100 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1101);
										mem_vec_1101 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1102);
										mem_vec_1102 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1103);
										mem_vec_1103 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1104);
										mem_vec_1104 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1105);
										mem_vec_1105 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1106);
										mem_vec_1106 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1107);
										mem_vec_1107 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1108);
										mem_vec_1108 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1109);
										mem_vec_1109 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1110);
										mem_vec_1110 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1111);
										mem_vec_1111 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1112);
										mem_vec_1112 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1113);
										mem_vec_1113 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1114);
										mem_vec_1114 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1115);
										mem_vec_1115 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1116);
										mem_vec_1116 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1117);
										mem_vec_1117 = vec_34;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1096);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1097);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1098);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1099);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1100);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1101);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1102);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1103);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1104);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1105);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1106);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1107);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1108);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1109);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1110);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1111);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1112);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1113);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1114);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1115);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1116);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1117);
						}
					}
				}
			}
		}
	}
	for (y81 = y82 + 99, y81_p_0 = 0;
		y81 < y82 + 99 + 13;
		y81 += 13, y81_p_0 += 13){
		// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c81 = c82, c81_p_0 = 0;
			c81 < c82 + 32;
			c81 += 32, c81_p_0 += 32){
			// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y81, yp_1 = y81_p_0, yp_0 = 0;
				y < y81 + 13;
				y += 13, yp_1 += 13, yp_0 += 13){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x54, xp_0 = 0;
					x < x54 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h54, hp_0 = 0;
						h < h54 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w54, wp_0 = 0;
							w < w54 + 3;
							w += 1, wp_0 += 1){
									mem_vec_1118 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1119 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_1129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_1130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_1131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_1132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_1133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_1134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_1135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_1136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_1137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_1138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_1139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_1140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_1141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_1142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_1143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c81, cp_1 = c81_p_0, cp_0 = 0;
										c < c81 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1118);
										mem_vec_1118 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1119);
										mem_vec_1119 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1120);
										mem_vec_1120 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1121);
										mem_vec_1121 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1122);
										mem_vec_1122 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1123);
										mem_vec_1123 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1124);
										mem_vec_1124 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1125);
										mem_vec_1125 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1126);
										mem_vec_1126 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1127);
										mem_vec_1127 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1128);
										mem_vec_1128 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1129);
										mem_vec_1129 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1130);
										mem_vec_1130 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1131);
										mem_vec_1131 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1132);
										mem_vec_1132 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1133);
										mem_vec_1133 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1134);
										mem_vec_1134 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1135);
										mem_vec_1135 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1136);
										mem_vec_1136 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1137);
										mem_vec_1137 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1138);
										mem_vec_1138 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1139);
										mem_vec_1139 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1140);
										mem_vec_1140 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1141);
										mem_vec_1141 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_1142);
										mem_vec_1142 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_1143);
										mem_vec_1143 = vec_40;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1118);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1119);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1120);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1121);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1122);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1123);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1124);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1125);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1126);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1127);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1128);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1129);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1130);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1131);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1132);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1133);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1134);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1135);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1136);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1137);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1138);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1139);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1140);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_1141);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_1142);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_1143);
						}
					}
				}
			}
		}
	}


}