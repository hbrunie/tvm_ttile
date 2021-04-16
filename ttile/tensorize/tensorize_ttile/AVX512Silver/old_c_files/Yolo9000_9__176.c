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
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (4, x);
  T (4, y)]
*/
IND_TYPE c, cp_0, c540_p_0, cp_1, c540, f, fp_0, x, xp_0, x720_p_0, x721_p_0, xp_1, x720_p_1, xp_2, x720, x721, y, yp_0, y540_p_0, yp_1, y540;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y541 = 0;
IND_TYPE x722 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c541 = 0;
IND_TYPE f360 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_7136 ,mem_vec_7137 ,mem_vec_7138 ,mem_vec_7139 ,mem_vec_7140 ,mem_vec_7141 ,mem_vec_7142 ,mem_vec_7143 ,mem_vec_7144 ,mem_vec_7145 ,mem_vec_7146 ,mem_vec_7147 ,mem_vec_7148 ,mem_vec_7149 ,mem_vec_7150 ,mem_vec_7151 ,mem_vec_7152 ,mem_vec_7153 ,mem_vec_7154 ,mem_vec_7155 ,mem_vec_7156 ,mem_vec_7157 ,mem_vec_7158 ,mem_vec_7159 ,mem_vec_7160 ,mem_vec_7161 ,mem_vec_7162 ,mem_vec_7163 ,mem_vec_7164 ,mem_vec_7165 ,mem_vec_7166 ,mem_vec_7167 ,mem_vec_7168 ,mem_vec_7169 ,mem_vec_7170 ,mem_vec_7171 ,mem_vec_7172 ,mem_vec_7173 ,mem_vec_7174 ,mem_vec_7175 ,mem_vec_7176 ,mem_vec_7177 ,mem_vec_7178 ,mem_vec_7179 ,mem_vec_7180 ,mem_vec_7181 ,mem_vec_7182 ,mem_vec_7183 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 4) (68 / 17)
for (y540 = y541, y540_p_0 = 0;
	y540 < y541 + 68;
	y540 += 17, y540_p_0 += 17){
	// y = 17, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 4) (68 / 17)
	for (x721 = x722, x721_p_0 = 0;
		x721 < x722 + 68;
		x721 += 17, x721_p_0 += 17){
			for (y = y540, yp_1 = y540_p_0, yp_0 = 0;
				y < y540 + 10;
				y += 5, yp_1 += 5, yp_0 += 5){
				// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (17 / 17)
				for (x720 = x721, x720_p_1 = x721_p_0, x720_p_0 = 0;
					x720 < x721 + 17;
					x720 += 17, x720_p_1 += 17, x720_p_0 += 17){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f360, fp_0 = 0;
						f < f360 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (c, 4) (256 / 64)
						for (c540 = c541, c540_p_0 = 0;
							c540 < c541 + 256;
							c540 += 64, c540_p_0 += 64){
							// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
							// T (x, 17) (17 / 1)
							for (x = x720, xp_2 = x720_p_1, xp_1 = x720_p_0, xp_0 = 0;
								x < x720 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7136 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7137 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7138 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_7139 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_7140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_7144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_7147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_7148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_7151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_7152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_7155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c540, cp_1 = c540_p_0, cp_0 = 0;
											c < c540 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7136);
											mem_vec_7136 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7137);
											mem_vec_7137 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7138);
											mem_vec_7138 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7139);
											mem_vec_7139 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7140);
											mem_vec_7140 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7141);
											mem_vec_7141 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7142);
											mem_vec_7142 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7143);
											mem_vec_7143 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7144);
											mem_vec_7144 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7145);
											mem_vec_7145 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7146);
											mem_vec_7146 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7147);
											mem_vec_7147 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7148);
											mem_vec_7148 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7149);
											mem_vec_7149 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7150);
											mem_vec_7150 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7151);
											mem_vec_7151 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7152);
											mem_vec_7152 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7153);
											mem_vec_7153 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7154);
											mem_vec_7154 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7155);
											mem_vec_7155 = vec_28;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7136);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7137);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7138);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7139);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7140);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7141);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7142);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7143);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7144);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7145);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7146);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7147);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7148);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7149);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7150);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7151);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7152);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7153);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_7154);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_7155);
							}
						}
					}
				}
			}
			for (y = y540 + 10, yp_1 = y540_p_0, yp_0 = 0;
				y < y540 + 10 + 7;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (17 / 17)
				for (x720 = x721, x720_p_1 = x721_p_0, x720_p_0 = 0;
					x720 < x721 + 17;
					x720 += 17, x720_p_1 += 17, x720_p_0 += 17){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f360, fp_0 = 0;
						f < f360 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (c, 4) (256 / 64)
						for (c540 = c541, c540_p_0 = 0;
							c540 < c541 + 256;
							c540 += 64, c540_p_0 += 64){
							// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
							// T (x, 17) (17 / 1)
							for (x = x720, xp_2 = x720_p_1, xp_1 = x720_p_0, xp_0 = 0;
								x < x720 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7156 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7157 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7158 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_7159 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_7160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_7164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_7167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_7168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_7171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_7172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_7175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_7176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_7178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_7179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_7180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_7182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_7183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c540, cp_1 = c540_p_0, cp_0 = 0;
											c < c540 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7156);
											mem_vec_7156 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7157);
											mem_vec_7157 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7158);
											mem_vec_7158 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7159);
											mem_vec_7159 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7160);
											mem_vec_7160 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7161);
											mem_vec_7161 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7162);
											mem_vec_7162 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7163);
											mem_vec_7163 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7164);
											mem_vec_7164 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7165);
											mem_vec_7165 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7166);
											mem_vec_7166 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7167);
											mem_vec_7167 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7168);
											mem_vec_7168 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7169);
											mem_vec_7169 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7170);
											mem_vec_7170 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7171);
											mem_vec_7171 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7172);
											mem_vec_7172 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7173);
											mem_vec_7173 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7174);
											mem_vec_7174 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7175);
											mem_vec_7175 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7176);
											mem_vec_7176 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7177);
											mem_vec_7177 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_7178);
											mem_vec_7178 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_7179);
											mem_vec_7179 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_7180);
											mem_vec_7180 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_7181);
											mem_vec_7181 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_7182);
											mem_vec_7182 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_7183);
											mem_vec_7183 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7156);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7157);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7158);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7159);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7160);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7161);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7162);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7163);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7164);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7165);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7166);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7167);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7168);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7169);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7170);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7171);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7172);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7173);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_7174);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_7175);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7176);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7177);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_7178);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_7179);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7180);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7181);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_7182);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_7183);
							}
						}
					}
				}
			}
	}
}


}