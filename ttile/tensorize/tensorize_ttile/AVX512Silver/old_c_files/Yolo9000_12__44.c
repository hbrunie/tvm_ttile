#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); U (2, y); U (3, w); T (128, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (1, c); T (17, y); T (1, x); T (2, f); T (2, c); T (2, f)]
*/
IND_TYPE c, cp_0, c43_p_0, c44_p_0, cp_1, c43_p_1, cp_2, c43, c44, f, fp_0, f48_p_0, fp_1, f48, h, hp_0, x, xp_0, x39_p_0, xp_1, x39, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y26 = 0;
IND_TYPE x40 = 0;
IND_TYPE h26 = 0;
IND_TYPE w = 0;
IND_TYPE c45 = 0;
IND_TYPE f49 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_136 ,mem_vec_137 ,mem_vec_138 ,mem_vec_139 ,mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,mem_vec_144 ,mem_vec_145 ,mem_vec_146 ,mem_vec_147 ,mem_vec_148 ,mem_vec_149 ,mem_vec_150 ,mem_vec_151 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f48 = f49, f48_p_0 = 0;
	f48 < f49 + 512;
	f48 += 256, f48_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (c, 2) (256 / 128)
	for (c44 = c45, c44_p_0 = 0;
		c44 < c45 + 256;
		c44 += 128, c44_p_0 += 128){
		// y = 34, x = 34, h = 3, w = 3, c = 128, f = 256
		// T (f, 2) (256 / 128)
		for (f = f48, fp_1 = f48_p_0, fp_0 = 0;
			f < f48 + 256;
			f += 128, fp_1 += 128, fp_0 += 128){
			// y = 34, x = 34, h = 3, w = 3, c = 128, f = 128
			// T (x, 1) (34 / 34)
			for (x39 = x40, x39_p_0 = 0;
				x39 < x40 + 34;
				x39 += 34, x39_p_0 += 34){
				// y = 34, x = 34, h = 3, w = 3, c = 128, f = 128
				// T (y, 17) (34 / 2)
				for (y = y26, yp_0 = 0;
					y < y26 + 34;
					y += 2, yp_0 += 2){
					// y = 2, x = 34, h = 3, w = 3, c = 128, f = 128
					// T (c, 1) (128 / 128)
					for (c43 = c44, c43_p_1 = c44_p_0, c43_p_0 = 0;
						c43 < c44 + 128;
						c43 += 128, c43_p_1 += 128, c43_p_0 += 128){
						// y = 2, x = 34, h = 3, w = 3, c = 128, f = 128
						// T (h, 3) (3 / 1)
						for (h = h26, hp_0 = 0;
							h < h26 + 3;
							h += 1, hp_0 += 1){
							// y = 2, x = 34, h = 1, w = 3, c = 128, f = 128
							// T (x, 34) (34 / 1)
							for (x = x39, xp_1 = x39_p_0, xp_0 = 0;
								x < x39 + 34;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_136 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_137 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_138 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_139 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_140 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 64]);
										mem_vec_141 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 80]);
										mem_vec_142 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 96]);
										mem_vec_143 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 112]);
										mem_vec_144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64]);
										mem_vec_149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80]);
										mem_vec_150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96]);
										mem_vec_151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112]);
										// y = 2, x = 1, h = 1, w = 3, c = 128, f = 128
										// T (c, 128) (128 / 1)
										for (c = c43, cp_2 = c43_p_1, cp_1 = c43_p_0, cp_0 = 0;
											c < c43 + 128;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_136);
											mem_vec_136 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_137);
											mem_vec_137 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_138);
											mem_vec_138 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_139);
											mem_vec_139 = vec_7;

											vec_10 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 64]);

											vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_140);
											mem_vec_140 = vec_9;

											vec_12 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 80]);

											vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_141);
											mem_vec_141 = vec_11;

											vec_14 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 96]);

											vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_142);
											mem_vec_142 = vec_13;

											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 112]);

											vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_143);
											mem_vec_143 = vec_15;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_18 = _mm512_set1_ps(scal_1);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_144);
											mem_vec_144 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_145);
											mem_vec_145 = vec_19;



											vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_146);
											mem_vec_146 = vec_20;



											vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_147);
											mem_vec_147 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_148);
											mem_vec_148 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_149);
											mem_vec_149 = vec_23;



											vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_150);
											mem_vec_150 = vec_24;



											vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_151);
											mem_vec_151 = vec_25;
											scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_27 = _mm512_set1_ps(scal_2);
											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_136);
											mem_vec_136 = vec_26;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_137);
											mem_vec_137 = vec_29;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_31 = _mm512_fmadd_ps(vec_27, vec_32, mem_vec_138);
											mem_vec_138 = vec_31;

											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_33 = _mm512_fmadd_ps(vec_27, vec_34, mem_vec_139);
											mem_vec_139 = vec_33;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 64]);

											vec_35 = _mm512_fmadd_ps(vec_27, vec_36, mem_vec_140);
											mem_vec_140 = vec_35;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 80]);

											vec_37 = _mm512_fmadd_ps(vec_27, vec_38, mem_vec_141);
											mem_vec_141 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 96]);

											vec_39 = _mm512_fmadd_ps(vec_27, vec_40, mem_vec_142);
											mem_vec_142 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 112]);

											vec_41 = _mm512_fmadd_ps(vec_27, vec_42, mem_vec_143);
											mem_vec_143 = vec_41;
											scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_44 = _mm512_set1_ps(scal_3);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_144);
											mem_vec_144 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_145);
											mem_vec_145 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_146);
											mem_vec_146 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_147);
											mem_vec_147 = vec_47;



											vec_48 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_148);
											mem_vec_148 = vec_48;



											vec_49 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_149);
											mem_vec_149 = vec_49;



											vec_50 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_150);
											mem_vec_150 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_151);
											mem_vec_151 = vec_51;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_53 = _mm512_set1_ps(scal_4);
											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_136);
											mem_vec_136 = vec_52;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_137);
											mem_vec_137 = vec_55;

											vec_58 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_57 = _mm512_fmadd_ps(vec_53, vec_58, mem_vec_138);
											mem_vec_138 = vec_57;

											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_59 = _mm512_fmadd_ps(vec_53, vec_60, mem_vec_139);
											mem_vec_139 = vec_59;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 64]);

											vec_61 = _mm512_fmadd_ps(vec_53, vec_62, mem_vec_140);
											mem_vec_140 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 80]);

											vec_63 = _mm512_fmadd_ps(vec_53, vec_64, mem_vec_141);
											mem_vec_141 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 96]);

											vec_65 = _mm512_fmadd_ps(vec_53, vec_66, mem_vec_142);
											mem_vec_142 = vec_65;

											vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 112]);

											vec_67 = _mm512_fmadd_ps(vec_53, vec_68, mem_vec_143);
											mem_vec_143 = vec_67;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_70 = _mm512_set1_ps(scal_5);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_144);
											mem_vec_144 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_145);
											mem_vec_145 = vec_71;



											vec_72 = _mm512_fmadd_ps(vec_70, vec_58, mem_vec_146);
											mem_vec_146 = vec_72;



											vec_73 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_147);
											mem_vec_147 = vec_73;



											vec_74 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_148);
											mem_vec_148 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_70, vec_64, mem_vec_149);
											mem_vec_149 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_150);
											mem_vec_150 = vec_76;



											vec_77 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_151);
											mem_vec_151 = vec_77;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_136);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_137);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_138);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_139);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 64], mem_vec_140);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 80], mem_vec_141);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 96], mem_vec_142);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 112], mem_vec_143);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_144);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_145);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_146);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_147);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64], mem_vec_148);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80], mem_vec_149);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96], mem_vec_150);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112], mem_vec_151);
							}
						}
					}
				}
			}
		}
	}
}


}