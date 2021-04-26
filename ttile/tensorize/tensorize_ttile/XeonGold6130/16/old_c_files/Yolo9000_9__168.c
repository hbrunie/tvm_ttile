#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (2, f); T (1, x); T (2, y); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]]
*/
IND_TYPE c, cp_0, c3_p_0, cp_1, c3, f, fp_0, x, xp_0, x4_p_0, x5_p_0, xp_1, x4_p_1, xp_2, x4, x5, y, yp_0, y3_p_0, yp_1, y3;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y4 = 0;
IND_TYPE x6 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c4 = 0;
IND_TYPE f2 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_100 ,mem_vec_101 ,mem_vec_102 ,mem_vec_103 ,mem_vec_52 ,mem_vec_53 ,mem_vec_54 ,mem_vec_55 ,mem_vec_56 ,mem_vec_57 ,mem_vec_58 ,mem_vec_59 ,mem_vec_60 ,mem_vec_61 ,mem_vec_62 ,mem_vec_63 ,mem_vec_64 ,mem_vec_65 ,mem_vec_66 ,mem_vec_67 ,mem_vec_68 ,mem_vec_69 ,mem_vec_70 ,mem_vec_71 ,mem_vec_72 ,mem_vec_73 ,mem_vec_74 ,mem_vec_75 ,mem_vec_76 ,mem_vec_77 ,mem_vec_78 ,mem_vec_79 ,mem_vec_80 ,mem_vec_81 ,mem_vec_82 ,mem_vec_83 ,mem_vec_84 ,mem_vec_85 ,mem_vec_86 ,mem_vec_87 ,mem_vec_88 ,mem_vec_89 ,mem_vec_90 ,mem_vec_91 ,mem_vec_92 ,mem_vec_93 ,mem_vec_94 ,mem_vec_95 ,mem_vec_96 ,mem_vec_97 ,mem_vec_98 ,mem_vec_99 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y3 = y4, y3_p_0 = 0;
		y3 < y4 + 12;
		y3 += 12, y3_p_0 += 12){
		// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x5 = x6, x5_p_0 = 0;
			x5 < x6 + 68;
			x5 += 68, x5_p_0 += 68){
			// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y3, yp_1 = y3_p_0, yp_0 = 0;
				y < y3 + 12;
				y += 6, yp_1 += 6, yp_0 += 6){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x4 = x5, x4_p_1 = x5_p_0, x4_p_0 = 0;
					x4 < x5 + 68;
					x4 += 68, x4_p_1 += 68, x4_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f2, fp_0 = 0;
						f < f2 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c3 = c4, c3_p_0 = 0;
							c3 < c4 + 256;
							c3 += 256, c3_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x4, xp_2 = x4_p_1, xp_1 = x4_p_0, xp_0 = 0;
								x < x4 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_52 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_53 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_54 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_55 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_56 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_57 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_58 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_59 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_60 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_61 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_62 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_63 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_64 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_65 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_66 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_67 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_68 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_69 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_70 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_71 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_72 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_73 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_74 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_75 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c3, cp_1 = c3_p_0, cp_0 = 0;
											c < c3 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_52);
											mem_vec_52 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_53);
											mem_vec_53 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_54);
											mem_vec_54 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_55);
											mem_vec_55 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_56);
											mem_vec_56 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_57);
											mem_vec_57 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_58);
											mem_vec_58 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_59);
											mem_vec_59 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_60);
											mem_vec_60 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_61);
											mem_vec_61 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_62);
											mem_vec_62 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_63);
											mem_vec_63 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_64);
											mem_vec_64 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_65);
											mem_vec_65 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_66);
											mem_vec_66 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_67);
											mem_vec_67 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_68);
											mem_vec_68 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_69);
											mem_vec_69 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_70);
											mem_vec_70 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_71);
											mem_vec_71 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_72);
											mem_vec_72 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_73);
											mem_vec_73 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_74);
											mem_vec_74 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_75);
											mem_vec_75 = vec_33;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_52);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_53);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_54);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_55);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_56);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_57);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_58);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_59);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_60);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_61);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_62);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_63);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_64);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_65);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_66);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_67);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_68);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_69);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_70);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_71);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_72);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_73);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_74);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_75);
							}
						}
					}
				}
			}
		}
	}
	for (y3 = y4 + 12, y3_p_0 = 0;
		y3 < y4 + 12 + 56;
		y3 += 14, y3_p_0 += 14){
		// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x5 = x6, x5_p_0 = 0;
			x5 < x6 + 68;
			x5 += 68, x5_p_0 += 68){
			// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y3, yp_1 = y3_p_0, yp_0 = 0;
				y < y3 + 14;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x4 = x5, x4_p_1 = x5_p_0, x4_p_0 = 0;
					x4 < x5 + 68;
					x4 += 68, x4_p_1 += 68, x4_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f2, fp_0 = 0;
						f < f2 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c3 = c4, c3_p_0 = 0;
							c3 < c4 + 256;
							c3 += 256, c3_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x4, xp_2 = x4_p_1, xp_1 = x4_p_0, xp_0 = 0;
								x < x4 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_76 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_77 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_78 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_79 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_80 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_81 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_82 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_83 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_84 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_85 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_86 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_87 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_88 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_89 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_90 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_91 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_92 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_93 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_94 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_95 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_96 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_97 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_98 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_99 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c3, cp_1 = c3_p_0, cp_0 = 0;
											c < c3 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_76);
											mem_vec_76 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_77);
											mem_vec_77 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_78);
											mem_vec_78 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_79);
											mem_vec_79 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_80);
											mem_vec_80 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_81);
											mem_vec_81 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_82);
											mem_vec_82 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_83);
											mem_vec_83 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_84);
											mem_vec_84 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_85);
											mem_vec_85 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_86);
											mem_vec_86 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_87);
											mem_vec_87 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_88);
											mem_vec_88 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_89);
											mem_vec_89 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_90);
											mem_vec_90 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_91);
											mem_vec_91 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_92);
											mem_vec_92 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_93);
											mem_vec_93 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_94);
											mem_vec_94 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_95);
											mem_vec_95 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_96);
											mem_vec_96 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_97);
											mem_vec_97 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_98);
											mem_vec_98 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_99);
											mem_vec_99 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_100);
											mem_vec_100 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_101);
											mem_vec_101 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_102);
											mem_vec_102 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_103);
											mem_vec_103 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_76);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_77);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_78);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_79);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_80);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_81);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_82);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_83);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_84);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_85);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_86);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_87);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_88);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_89);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_90);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_91);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_92);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_93);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_94);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_95);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_96);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_97);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_98);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_99);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_100);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_101);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_102);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_103);
							}
						}
					}
				}
			}
		}
	}


}