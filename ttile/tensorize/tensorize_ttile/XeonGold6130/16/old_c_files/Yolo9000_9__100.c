#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (4, f); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 8)); ((Iter 2), (Arg 14))]; T (1, x);
  T (1, y)]
*/
IND_TYPE c, cp_0, c516_p_0, cp_1, c516, f, fp_0, x, xp_0, x688_p_0, x689_p_0, xp_1, x688_p_1, xp_2, x688, x689, y, yp_0, y516_p_0, yp_1, y516;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y517 = 0;
IND_TYPE x690 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c517 = 0;
IND_TYPE f344 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8116 ,mem_vec_8117 ,mem_vec_8118 ,mem_vec_8119 ,mem_vec_8120 ,mem_vec_8121 ,mem_vec_8122 ,mem_vec_8123 ,mem_vec_8124 ,mem_vec_8125 ,mem_vec_8126 ,mem_vec_8127 ,mem_vec_8128 ,mem_vec_8129 ,mem_vec_8130 ,mem_vec_8131 ,mem_vec_8132 ,mem_vec_8133 ,mem_vec_8134 ,mem_vec_8135 ,mem_vec_8136 ,mem_vec_8137 ,mem_vec_8138 ,mem_vec_8139 ,mem_vec_8140 ,mem_vec_8141 ,mem_vec_8142 ,mem_vec_8143 ,mem_vec_8144 ,mem_vec_8145 ,mem_vec_8146 ,mem_vec_8147 ,mem_vec_8148 ,mem_vec_8149 ,mem_vec_8150 ,mem_vec_8151 ,mem_vec_8152 ,mem_vec_8153 ,mem_vec_8154 ,mem_vec_8155 ,mem_vec_8156 ,mem_vec_8157 ,mem_vec_8158 ,mem_vec_8159 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 1) (68 / 68)
for (y516 = y517, y516_p_0 = 0;
	y516 < y517 + 68;
	y516 += 68, y516_p_0 += 68){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 1) (68 / 68)
	for (x689 = x690, x689_p_0 = 0;
		x689 < x690 + 68;
		x689 += 68, x689_p_0 += 68){
			for (y = y516, yp_1 = y516_p_0, yp_0 = 0;
				y < y516 + 40;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x688 = x689, x688_p_1 = x689_p_0, x688_p_0 = 0;
					x688 < x689 + 68;
					x688 += 68, x688_p_1 += 68, x688_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f344, fp_0 = 0;
						f < f344 + 128;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 32
						// T (c, 1) (256 / 256)
						for (c516 = c517, c516_p_0 = 0;
							c516 < c517 + 256;
							c516 += 256, c516_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 32
							// T (x, 68) (68 / 1)
							for (x = x688, xp_2 = x688_p_1, xp_1 = x688_p_0, xp_0 = 0;
								x < x688 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8116 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8117 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_8128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_8130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c516, cp_1 = c516_p_0, cp_0 = 0;
											c < c516 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8116);
											mem_vec_8116 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8117);
											mem_vec_8117 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8118);
											mem_vec_8118 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8119);
											mem_vec_8119 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8120);
											mem_vec_8120 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8121);
											mem_vec_8121 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8122);
											mem_vec_8122 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8123);
											mem_vec_8123 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8124);
											mem_vec_8124 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8125);
											mem_vec_8125 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8126);
											mem_vec_8126 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8127);
											mem_vec_8127 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8128);
											mem_vec_8128 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8129);
											mem_vec_8129 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8130);
											mem_vec_8130 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8131);
											mem_vec_8131 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8116);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8117);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8118);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8119);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8120);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8121);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8122);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8123);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8124);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8125);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8126);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8127);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8128);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8129);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8130);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8131);
							}
						}
					}
				}
			}
			for (y = y516 + 40, yp_1 = y516_p_0, yp_0 = 0;
				y < y516 + 40 + 28;
				y += 14, yp_1 += 14, yp_0 += 14){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x688 = x689, x688_p_1 = x689_p_0, x688_p_0 = 0;
					x688 < x689 + 68;
					x688 += 68, x688_p_1 += 68, x688_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f344, fp_0 = 0;
						f < f344 + 128;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 32
						// T (c, 1) (256 / 256)
						for (c516 = c517, c516_p_0 = 0;
							c516 < c517 + 256;
							c516 += 256, c516_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 32
							// T (x, 68) (68 / 1)
							for (x = x688, xp_2 = x688_p_1, xp_1 = x688_p_0, xp_0 = 0;
								x < x688 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8132 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8133 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_8144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_8146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_8148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_8150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_8152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_8153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_8154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_8155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_8156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_8157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_8158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_8159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c516, cp_1 = c516_p_0, cp_0 = 0;
											c < c516 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8132);
											mem_vec_8132 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8133);
											mem_vec_8133 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8134);
											mem_vec_8134 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8135);
											mem_vec_8135 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8136);
											mem_vec_8136 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8137);
											mem_vec_8137 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8138);
											mem_vec_8138 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8139);
											mem_vec_8139 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8140);
											mem_vec_8140 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8141);
											mem_vec_8141 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8142);
											mem_vec_8142 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8143);
											mem_vec_8143 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8144);
											mem_vec_8144 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8145);
											mem_vec_8145 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8146);
											mem_vec_8146 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8147);
											mem_vec_8147 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8148);
											mem_vec_8148 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8149);
											mem_vec_8149 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8150);
											mem_vec_8150 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8151);
											mem_vec_8151 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8152);
											mem_vec_8152 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8153);
											mem_vec_8153 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8154);
											mem_vec_8154 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8155);
											mem_vec_8155 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8156);
											mem_vec_8156 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8157);
											mem_vec_8157 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_8158);
											mem_vec_8158 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_8159);
											mem_vec_8159 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8132);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8133);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8134);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8135);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8136);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8137);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8138);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8139);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8140);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8141);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8142);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8143);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8144);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8145);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8146);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8147);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8148);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8149);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8150);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8151);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8152);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8153);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8154);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8155);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_8156);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_8157);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_8158);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_8159);
							}
						}
					}
				}
			}
	}
}


}