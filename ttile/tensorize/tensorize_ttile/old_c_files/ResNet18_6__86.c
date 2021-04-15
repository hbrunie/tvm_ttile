#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (1, f); T (64, c); T (14, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (2, f)]
*/
IND_TYPE c, cp_0, c1182_p_0, cp_1, c1182, f, fp_0, f1182_p_0, fp_1, f1182, h, hp_0, x, xp_0, x1182_p_0, xp_1, x1182, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y788 = 0;
IND_TYPE x1183 = 0;
IND_TYPE h616 = 0;
IND_TYPE w = 0;
IND_TYPE c1183 = 0;
IND_TYPE f1183 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_12130 ,mem_vec_12131 ,mem_vec_12132 ,mem_vec_12133 ,mem_vec_12134 ,mem_vec_12135 ,mem_vec_12136 ,mem_vec_12137 ,mem_vec_12138 ,mem_vec_12139 ,mem_vec_12140 ,mem_vec_12141 ,mem_vec_12142 ,mem_vec_12143 ,mem_vec_12144 ,mem_vec_12145 ,mem_vec_12146 ,mem_vec_12147 ,mem_vec_12148 ,mem_vec_12149 ,mem_vec_12150 ,mem_vec_12151 ,mem_vec_12152 ,mem_vec_12153 ,mem_vec_12154 ,mem_vec_12155 ,mem_vec_12156 ,mem_vec_12157 ,mem_vec_12158 ,mem_vec_12159 ,mem_vec_12160 ,mem_vec_12161 ,mem_vec_12162 ,mem_vec_12163 ,mem_vec_12164 ,mem_vec_12165 ,mem_vec_12166 ,mem_vec_12167 ,mem_vec_12168 ,mem_vec_12169 ,mem_vec_12170 ,mem_vec_12171 ,mem_vec_12172 ,mem_vec_12173 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f1182 = f1183, f1182_p_0 = 0;
	f1182 < f1183 + 128;
	f1182 += 64, f1182_p_0 += 64){
		for (y = y788, yp_0 = 0;
			y < y788 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 14) (28 / 2)
			for (x1182 = x1183, x1182_p_0 = 0;
				x1182 < x1183 + 28;
				x1182 += 2, x1182_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 64
				// T (c, 64) (128 / 2)
				for (c1182 = c1183, c1182_p_0 = 0;
					c1182 < c1183 + 128;
					c1182 += 2, c1182_p_0 += 2){
					// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1182, fp_1 = f1182_p_0, fp_0 = 0;
						f < f1182 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 64
						// T (h, 3) (3 / 1)
						for (h = h616, hp_0 = 0;
							h < h616 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 2, f = 64
							// T (x, 2) (2 / 1)
							for (x = x1182, xp_1 = x1182_p_0, xp_0 = 0;
								x < x1182 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_12130 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_12131 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_12132 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_12133 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_12134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_12135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_12136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_12137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_12138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_12139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_12140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_12141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_12142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_12143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_12144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_12145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_12146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_12147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_12148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_12149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c1182, cp_1 = c1182_p_0, cp_0 = 0;
											c < c1182 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12130);
											mem_vec_12130 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12131);
											mem_vec_12131 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_12132);
											mem_vec_12132 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_12133);
											mem_vec_12133 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_12134);
											mem_vec_12134 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_12135);
											mem_vec_12135 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_12136);
											mem_vec_12136 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_12137);
											mem_vec_12137 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12138);
											mem_vec_12138 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12139);
											mem_vec_12139 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_12140);
											mem_vec_12140 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_12141);
											mem_vec_12141 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_12142);
											mem_vec_12142 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_12143);
											mem_vec_12143 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_12144);
											mem_vec_12144 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_12145);
											mem_vec_12145 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_12146);
											mem_vec_12146 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_12147);
											mem_vec_12147 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_12148);
											mem_vec_12148 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_12149);
											mem_vec_12149 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_12130);
											mem_vec_12130 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_12131);
											mem_vec_12131 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_12132);
											mem_vec_12132 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_12133);
											mem_vec_12133 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_12134);
											mem_vec_12134 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_12135);
											mem_vec_12135 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_12136);
											mem_vec_12136 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_12137);
											mem_vec_12137 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_12138);
											mem_vec_12138 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_12139);
											mem_vec_12139 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_12140);
											mem_vec_12140 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_12141);
											mem_vec_12141 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_12142);
											mem_vec_12142 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_12143);
											mem_vec_12143 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_12144);
											mem_vec_12144 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_12145);
											mem_vec_12145 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_12146);
											mem_vec_12146 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_12147);
											mem_vec_12147 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_12148);
											mem_vec_12148 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_12149);
											mem_vec_12149 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_12130);
											mem_vec_12130 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_12131);
											mem_vec_12131 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_12132);
											mem_vec_12132 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_12133);
											mem_vec_12133 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_12134);
											mem_vec_12134 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_12135);
											mem_vec_12135 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_12136);
											mem_vec_12136 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_12137);
											mem_vec_12137 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_12138);
											mem_vec_12138 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_12139);
											mem_vec_12139 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_12140);
											mem_vec_12140 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_12141);
											mem_vec_12141 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_12142);
											mem_vec_12142 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_12143);
											mem_vec_12143 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_12144);
											mem_vec_12144 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_12145);
											mem_vec_12145 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_12146);
											mem_vec_12146 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_12147);
											mem_vec_12147 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_12148);
											mem_vec_12148 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_12149);
											mem_vec_12149 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12130);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12131);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_12132);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_12133);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12134);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12135);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_12136);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_12137);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12138);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12139);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_12140);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_12141);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12142);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12143);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_12144);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_12145);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12146);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12147);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_12148);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_12149);
							}
						}
					}
				}
			}
		}
		for (y = y788 + 10, yp_0 = 0;
			y < y788 + 10 + 18;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 14) (28 / 2)
			for (x1182 = x1183, x1182_p_0 = 0;
				x1182 < x1183 + 28;
				x1182 += 2, x1182_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 64
				// T (c, 64) (128 / 2)
				for (c1182 = c1183, c1182_p_0 = 0;
					c1182 < c1183 + 128;
					c1182 += 2, c1182_p_0 += 2){
					// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1182, fp_1 = f1182_p_0, fp_0 = 0;
						f < f1182 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 64
						// T (h, 3) (3 / 1)
						for (h = h616, hp_0 = 0;
							h < h616 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 2, f = 64
							// T (x, 2) (2 / 1)
							for (x = x1182, xp_1 = x1182_p_0, xp_0 = 0;
								x < x1182 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_12150 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_12151 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_12152 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_12153 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_12154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_12155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_12156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_12157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_12158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_12159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_12160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_12161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_12162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_12163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_12164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_12165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_12166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_12167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_12168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_12169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_12170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_12171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_12172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_12173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c1182, cp_1 = c1182_p_0, cp_0 = 0;
											c < c1182 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12150);
											mem_vec_12150 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12151);
											mem_vec_12151 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_12152);
											mem_vec_12152 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_12153);
											mem_vec_12153 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_12154);
											mem_vec_12154 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_12155);
											mem_vec_12155 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_12156);
											mem_vec_12156 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_12157);
											mem_vec_12157 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12158);
											mem_vec_12158 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12159);
											mem_vec_12159 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_12160);
											mem_vec_12160 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_12161);
											mem_vec_12161 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_12162);
											mem_vec_12162 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_12163);
											mem_vec_12163 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_12164);
											mem_vec_12164 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_12165);
											mem_vec_12165 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_12166);
											mem_vec_12166 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_12167);
											mem_vec_12167 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_12168);
											mem_vec_12168 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_12169);
											mem_vec_12169 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_12170);
											mem_vec_12170 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_12171);
											mem_vec_12171 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_12172);
											mem_vec_12172 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_12173);
											mem_vec_12173 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_12150);
											mem_vec_12150 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_12151);
											mem_vec_12151 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_12152);
											mem_vec_12152 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_12153);
											mem_vec_12153 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_12154);
											mem_vec_12154 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_12155);
											mem_vec_12155 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_12156);
											mem_vec_12156 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_12157);
											mem_vec_12157 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_12158);
											mem_vec_12158 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_12159);
											mem_vec_12159 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_12160);
											mem_vec_12160 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_12161);
											mem_vec_12161 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_12162);
											mem_vec_12162 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_12163);
											mem_vec_12163 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_12164);
											mem_vec_12164 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_12165);
											mem_vec_12165 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_12166);
											mem_vec_12166 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_12167);
											mem_vec_12167 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_12168);
											mem_vec_12168 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_12169);
											mem_vec_12169 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_12170);
											mem_vec_12170 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_12171);
											mem_vec_12171 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_12172);
											mem_vec_12172 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_12173);
											mem_vec_12173 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_12150);
											mem_vec_12150 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_12151);
											mem_vec_12151 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_12152);
											mem_vec_12152 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_12153);
											mem_vec_12153 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_12154);
											mem_vec_12154 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_12155);
											mem_vec_12155 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_12156);
											mem_vec_12156 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_12157);
											mem_vec_12157 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_12158);
											mem_vec_12158 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_12159);
											mem_vec_12159 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_12160);
											mem_vec_12160 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_12161);
											mem_vec_12161 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_12162);
											mem_vec_12162 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_12163);
											mem_vec_12163 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_12164);
											mem_vec_12164 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_12165);
											mem_vec_12165 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_12166);
											mem_vec_12166 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_12167);
											mem_vec_12167 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_12168);
											mem_vec_12168 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_12169);
											mem_vec_12169 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_12170);
											mem_vec_12170 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_12171);
											mem_vec_12171 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_12172);
											mem_vec_12172 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_12173);
											mem_vec_12173 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12150);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12151);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_12152);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_12153);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12154);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12155);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_12156);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_12157);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12158);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12159);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_12160);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_12161);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12162);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12163);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_12164);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_12165);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12166);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12167);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_12168);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_12169);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12170);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12171);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_12172);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_12173);
							}
						}
					}
				}
			}
		}
}


}