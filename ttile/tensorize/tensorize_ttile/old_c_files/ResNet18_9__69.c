#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (2, f); T (128, c); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (2, f)]
*/
IND_TYPE c, cp_0, c900_p_0, cp_1, c900, f, fp_0, f900_p_0, fp_1, f900, h, hp_0, x, xp_0, x900_p_0, xp_1, x900, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y600 = 0;
IND_TYPE x901 = 0;
IND_TYPE h462 = 0;
IND_TYPE w = 0;
IND_TYPE c901 = 0;
IND_TYPE f901 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7168 ,mem_vec_7169 ,mem_vec_7170 ,mem_vec_7171 ,mem_vec_7172 ,mem_vec_7173 ,mem_vec_7174 ,mem_vec_7175 ,mem_vec_7176 ,mem_vec_7177 ,mem_vec_7178 ,mem_vec_7179 ,mem_vec_7180 ,mem_vec_7181 ,mem_vec_7182 ,mem_vec_7183 ,mem_vec_7184 ,mem_vec_7185 ,mem_vec_7186 ,mem_vec_7187 ,mem_vec_7188 ,mem_vec_7189 ,mem_vec_7190 ,mem_vec_7191 ,mem_vec_7192 ,mem_vec_7193 ,mem_vec_7194 ,mem_vec_7195 ,mem_vec_7196 ,mem_vec_7197 ,mem_vec_7198 ,mem_vec_7199 ,mem_vec_7200 ,mem_vec_7201 ,mem_vec_7202 ,mem_vec_7203 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f900 = f901, f900_p_0 = 0;
	f900 < f901 + 256;
	f900 += 128, f900_p_0 += 128){
		for (y = y600, yp_0 = 0;
			y < y600 + 4;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 128
			// T (x, 1) (14 / 14)
			for (x900 = x901, x900_p_0 = 0;
				x900 < x901 + 14;
				x900 += 14, x900_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 128
				// T (c, 128) (256 / 2)
				for (c900 = c901, c900_p_0 = 0;
					c900 < c901 + 256;
					c900 += 2, c900_p_0 += 2){
					// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 128
					// T (f, 2) (128 / 64)
					for (f = f900, fp_1 = f900_p_0, fp_0 = 0;
						f < f900 + 128;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 64
						// T (h, 3) (3 / 1)
						for (h = h462, hp_0 = 0;
							h < h462 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 2, f = 64
							// T (x, 14) (14 / 1)
							for (x = x900, xp_1 = x900_p_0, xp_0 = 0;
								x < x900 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7168 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7169 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7170 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_7171 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_7172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_7176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_7179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_7180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_7183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c900, cp_1 = c900_p_0, cp_0 = 0;
											c < c900 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7168);
											mem_vec_7168 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7169);
											mem_vec_7169 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7170);
											mem_vec_7170 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7171);
											mem_vec_7171 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7172);
											mem_vec_7172 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7173);
											mem_vec_7173 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7174);
											mem_vec_7174 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7175);
											mem_vec_7175 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7176);
											mem_vec_7176 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7177);
											mem_vec_7177 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7178);
											mem_vec_7178 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7179);
											mem_vec_7179 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7180);
											mem_vec_7180 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7181);
											mem_vec_7181 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7182);
											mem_vec_7182 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7183);
											mem_vec_7183 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_7168);
											mem_vec_7168 = vec_24;

											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_7169);
											mem_vec_7169 = vec_27;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_7170);
											mem_vec_7170 = vec_29;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_7171);
											mem_vec_7171 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_7172);
											mem_vec_7172 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_7173);
											mem_vec_7173 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_7174);
											mem_vec_7174 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_7175);
											mem_vec_7175 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_7176);
											mem_vec_7176 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_7177);
											mem_vec_7177 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_7178);
											mem_vec_7178 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_7179);
											mem_vec_7179 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_7180);
											mem_vec_7180 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_7181);
											mem_vec_7181 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_7182);
											mem_vec_7182 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_7183);
											mem_vec_7183 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_7168);
											mem_vec_7168 = vec_48;

											vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_7169);
											mem_vec_7169 = vec_51;

											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_7170);
											mem_vec_7170 = vec_53;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_7171);
											mem_vec_7171 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm512_set1_ps(scal_9);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_7172);
											mem_vec_7172 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_7173);
											mem_vec_7173 = vec_59;



											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_7174);
											mem_vec_7174 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_7175);
											mem_vec_7175 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm512_set1_ps(scal_10);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_7176);
											mem_vec_7176 = vec_62;



											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_7177);
											mem_vec_7177 = vec_64;



											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_7178);
											mem_vec_7178 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_7179);
											mem_vec_7179 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_7180);
											mem_vec_7180 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_7181);
											mem_vec_7181 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_7182);
											mem_vec_7182 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_7183);
											mem_vec_7183 = vec_71;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7168);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7169);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7170);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7171);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7172);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7173);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7174);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7175);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7176);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7177);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7178);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7179);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7180);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7181);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7182);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7183);
							}
						}
					}
				}
			}
		}
		for (y = y600 + 4, yp_0 = 0;
			y < y600 + 4 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 128
			// T (x, 1) (14 / 14)
			for (x900 = x901, x900_p_0 = 0;
				x900 < x901 + 14;
				x900 += 14, x900_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 128
				// T (c, 128) (256 / 2)
				for (c900 = c901, c900_p_0 = 0;
					c900 < c901 + 256;
					c900 += 2, c900_p_0 += 2){
					// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 128
					// T (f, 2) (128 / 64)
					for (f = f900, fp_1 = f900_p_0, fp_0 = 0;
						f < f900 + 128;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 64
						// T (h, 3) (3 / 1)
						for (h = h462, hp_0 = 0;
							h < h462 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 2, f = 64
							// T (x, 14) (14 / 1)
							for (x = x900, xp_1 = x900_p_0, xp_0 = 0;
								x < x900 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7184 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7185 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7186 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_7187 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_7188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_7192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_7195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_7196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_7199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_7200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_7203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c900, cp_1 = c900_p_0, cp_0 = 0;
											c < c900 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7184);
											mem_vec_7184 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7185);
											mem_vec_7185 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7186);
											mem_vec_7186 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7187);
											mem_vec_7187 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7188);
											mem_vec_7188 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7189);
											mem_vec_7189 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7190);
											mem_vec_7190 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7191);
											mem_vec_7191 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7192);
											mem_vec_7192 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7193);
											mem_vec_7193 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7194);
											mem_vec_7194 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7195);
											mem_vec_7195 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7196);
											mem_vec_7196 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7197);
											mem_vec_7197 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7198);
											mem_vec_7198 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7199);
											mem_vec_7199 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7200);
											mem_vec_7200 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7201);
											mem_vec_7201 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7202);
											mem_vec_7202 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7203);
											mem_vec_7203 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_7184);
											mem_vec_7184 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_7185);
											mem_vec_7185 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_7186);
											mem_vec_7186 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_7187);
											mem_vec_7187 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_7188);
											mem_vec_7188 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_7189);
											mem_vec_7189 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_7190);
											mem_vec_7190 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_7191);
											mem_vec_7191 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_7192);
											mem_vec_7192 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_7193);
											mem_vec_7193 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_7194);
											mem_vec_7194 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_7195);
											mem_vec_7195 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_7196);
											mem_vec_7196 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_7197);
											mem_vec_7197 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_7198);
											mem_vec_7198 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_7199);
											mem_vec_7199 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_7200);
											mem_vec_7200 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_7201);
											mem_vec_7201 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_7202);
											mem_vec_7202 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_7203);
											mem_vec_7203 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_7184);
											mem_vec_7184 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_7185);
											mem_vec_7185 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_7186);
											mem_vec_7186 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_7187);
											mem_vec_7187 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_7188);
											mem_vec_7188 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_7189);
											mem_vec_7189 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_7190);
											mem_vec_7190 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_7191);
											mem_vec_7191 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_7192);
											mem_vec_7192 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_7193);
											mem_vec_7193 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_7194);
											mem_vec_7194 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_7195);
											mem_vec_7195 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_7196);
											mem_vec_7196 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_7197);
											mem_vec_7197 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_7198);
											mem_vec_7198 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_7199);
											mem_vec_7199 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_7200);
											mem_vec_7200 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_7201);
											mem_vec_7201 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_7202);
											mem_vec_7202 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_7203);
											mem_vec_7203 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7184);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7185);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7186);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7187);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7188);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7189);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7190);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7191);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7192);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7193);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7194);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7195);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7196);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7197);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7198);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7199);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7200);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7201);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_7202);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_7203);
							}
						}
					}
				}
			}
		}
}


}