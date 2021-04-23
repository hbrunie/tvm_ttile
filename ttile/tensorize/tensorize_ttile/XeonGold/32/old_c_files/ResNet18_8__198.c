#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (14, x);
  T (3, w); T (4, c); T (1, f); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (4, f)]
*/
IND_TYPE c, cp_0, c534_p_0, cp_1, c534, f, fp_0, f534_p_0, fp_1, f534, w, wp_0, x, xp_0, x499_p_0, xp_1, x499, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y356 = 0;
IND_TYPE x500 = 0;
IND_TYPE h = 0;
IND_TYPE w305 = 0;
IND_TYPE c535 = 0;
IND_TYPE f535 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5137 ,mem_vec_5138 ,mem_vec_5139 ,mem_vec_5140 ,mem_vec_5141 ,mem_vec_5142 ,mem_vec_5143 ,mem_vec_5144 ,mem_vec_5145 ,mem_vec_5146 ,mem_vec_5147 ,mem_vec_5148 ,mem_vec_5149 ,mem_vec_5150 ,mem_vec_5151 ,mem_vec_5152 ,mem_vec_5153 ,mem_vec_5154 ,mem_vec_5155 ,mem_vec_5156 ,mem_vec_5157 ,mem_vec_5158 ,mem_vec_5159 ,mem_vec_5160 ,mem_vec_5161 ,mem_vec_5162 ,mem_vec_5163 ,mem_vec_5164 ,mem_vec_5165 ,mem_vec_5166 ,mem_vec_5167 ,mem_vec_5168 ,mem_vec_5169 ,mem_vec_5170 ,mem_vec_5171 ,mem_vec_5172 ,mem_vec_5173 ,mem_vec_5174 ,mem_vec_5175 ,mem_vec_5176 ,mem_vec_5177 ,mem_vec_5178 ,mem_vec_5179 ,mem_vec_5180 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f534 = f535, f534_p_0 = 0;
	f534 < f535 + 256;
	f534 += 64, f534_p_0 += 64){
		for (y = y356, yp_0 = 0;
			y < y356 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 2) (28 / 14)
			for (x499 = x500, x499_p_0 = 0;
				x499 < x500 + 28;
				x499 += 14, x499_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
				// T (f, 1) (64 / 64)
				for (f = f534, fp_1 = f534_p_0, fp_0 = 0;
					f < f534 + 64;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
					// T (c, 4) (128 / 32)
					for (c534 = c535, c534_p_0 = 0;
						c534 < c535 + 128;
						c534 += 32, c534_p_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 64
						// T (w, 3) (3 / 1)
						for (w = w305, wp_0 = 0;
							w < w305 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 32, f = 64
							// T (x, 14) (14 / 1)
							for (x = x499, xp_1 = x499_p_0, xp_0 = 0;
								x < x499 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5137 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5138 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5139 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_5140 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_5141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_5144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_5145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_5148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_5149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_5152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_5153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_5156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c534, cp_1 = c534_p_0, cp_0 = 0;
											c < c534 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5137);
											mem_vec_5137 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5138);
											mem_vec_5138 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5139);
											mem_vec_5139 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5140);
											mem_vec_5140 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5141);
											mem_vec_5141 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5142);
											mem_vec_5142 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5143);
											mem_vec_5143 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5144);
											mem_vec_5144 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5145);
											mem_vec_5145 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5146);
											mem_vec_5146 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5147);
											mem_vec_5147 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5148);
											mem_vec_5148 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5149);
											mem_vec_5149 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5150);
											mem_vec_5150 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5151);
											mem_vec_5151 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5152);
											mem_vec_5152 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5153);
											mem_vec_5153 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5154);
											mem_vec_5154 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5155);
											mem_vec_5155 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5156);
											mem_vec_5156 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_5137);
											mem_vec_5137 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_5138);
											mem_vec_5138 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_5139);
											mem_vec_5139 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_5140);
											mem_vec_5140 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_5141);
											mem_vec_5141 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_5142);
											mem_vec_5142 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_5143);
											mem_vec_5143 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_5144);
											mem_vec_5144 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_5145);
											mem_vec_5145 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_5146);
											mem_vec_5146 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_5147);
											mem_vec_5147 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_5148);
											mem_vec_5148 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_5149);
											mem_vec_5149 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_5150);
											mem_vec_5150 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_5151);
											mem_vec_5151 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_5152);
											mem_vec_5152 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_5153);
											mem_vec_5153 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_5154);
											mem_vec_5154 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_5155);
											mem_vec_5155 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_5156);
											mem_vec_5156 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_5137);
											mem_vec_5137 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_5138);
											mem_vec_5138 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_5139);
											mem_vec_5139 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_5140);
											mem_vec_5140 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_5141);
											mem_vec_5141 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_5142);
											mem_vec_5142 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_5143);
											mem_vec_5143 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_5144);
											mem_vec_5144 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_5145);
											mem_vec_5145 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_5146);
											mem_vec_5146 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_5147);
											mem_vec_5147 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_5148);
											mem_vec_5148 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_5149);
											mem_vec_5149 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_5150);
											mem_vec_5150 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_5151);
											mem_vec_5151 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_5152);
											mem_vec_5152 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_5153);
											mem_vec_5153 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_5154);
											mem_vec_5154 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_5155);
											mem_vec_5155 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_5156);
											mem_vec_5156 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5137);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5138);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5139);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5140);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5141);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5142);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5143);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5144);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5145);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5146);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5147);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5148);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5149);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5150);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5151);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5152);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5153);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5154);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5155);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5156);
							}
						}
					}
				}
			}
		}
		for (y = y356 + 10, yp_0 = 0;
			y < y356 + 10 + 18;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 2) (28 / 14)
			for (x499 = x500, x499_p_0 = 0;
				x499 < x500 + 28;
				x499 += 14, x499_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
				// T (f, 1) (64 / 64)
				for (f = f534, fp_1 = f534_p_0, fp_0 = 0;
					f < f534 + 64;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
					// T (c, 4) (128 / 32)
					for (c534 = c535, c534_p_0 = 0;
						c534 < c535 + 128;
						c534 += 32, c534_p_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 64
						// T (w, 3) (3 / 1)
						for (w = w305, wp_0 = 0;
							w < w305 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 32, f = 64
							// T (x, 14) (14 / 1)
							for (x = x499, xp_1 = x499_p_0, xp_0 = 0;
								x < x499 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5157 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5158 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5159 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_5160 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_5161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_5164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_5165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_5168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_5169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_5172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_5173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_5176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_5177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_5180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c534, cp_1 = c534_p_0, cp_0 = 0;
											c < c534 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5157);
											mem_vec_5157 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5158);
											mem_vec_5158 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5159);
											mem_vec_5159 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5160);
											mem_vec_5160 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5161);
											mem_vec_5161 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5162);
											mem_vec_5162 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5163);
											mem_vec_5163 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5164);
											mem_vec_5164 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5165);
											mem_vec_5165 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5166);
											mem_vec_5166 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5167);
											mem_vec_5167 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5168);
											mem_vec_5168 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5169);
											mem_vec_5169 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5170);
											mem_vec_5170 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5171);
											mem_vec_5171 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5172);
											mem_vec_5172 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5173);
											mem_vec_5173 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5174);
											mem_vec_5174 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5175);
											mem_vec_5175 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5176);
											mem_vec_5176 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5177);
											mem_vec_5177 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5178);
											mem_vec_5178 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5179);
											mem_vec_5179 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5180);
											mem_vec_5180 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_5157);
											mem_vec_5157 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_5158);
											mem_vec_5158 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_5159);
											mem_vec_5159 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_5160);
											mem_vec_5160 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_5161);
											mem_vec_5161 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_5162);
											mem_vec_5162 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_5163);
											mem_vec_5163 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_5164);
											mem_vec_5164 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_5165);
											mem_vec_5165 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_5166);
											mem_vec_5166 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_5167);
											mem_vec_5167 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_5168);
											mem_vec_5168 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_5169);
											mem_vec_5169 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_5170);
											mem_vec_5170 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_5171);
											mem_vec_5171 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_5172);
											mem_vec_5172 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_5173);
											mem_vec_5173 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_5174);
											mem_vec_5174 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_5175);
											mem_vec_5175 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_5176);
											mem_vec_5176 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_5177);
											mem_vec_5177 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_5178);
											mem_vec_5178 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_5179);
											mem_vec_5179 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_5180);
											mem_vec_5180 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_5157);
											mem_vec_5157 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_5158);
											mem_vec_5158 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_5159);
											mem_vec_5159 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_5160);
											mem_vec_5160 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_5161);
											mem_vec_5161 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_5162);
											mem_vec_5162 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_5163);
											mem_vec_5163 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_5164);
											mem_vec_5164 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_5165);
											mem_vec_5165 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_5166);
											mem_vec_5166 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_5167);
											mem_vec_5167 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_5168);
											mem_vec_5168 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_5169);
											mem_vec_5169 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_5170);
											mem_vec_5170 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_5171);
											mem_vec_5171 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_5172);
											mem_vec_5172 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_5173);
											mem_vec_5173 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_5174);
											mem_vec_5174 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_5175);
											mem_vec_5175 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_5176);
											mem_vec_5176 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_5177);
											mem_vec_5177 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_5178);
											mem_vec_5178 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_5179);
											mem_vec_5179 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_5180);
											mem_vec_5180 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5157);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5158);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5159);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5160);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5161);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5162);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5163);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5164);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5165);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5166);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5167);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5168);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5169);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5170);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5171);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5172);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5173);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5174);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5175);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5176);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5177);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5178);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_5179);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_5180);
							}
						}
					}
				}
			}
		}
}


}