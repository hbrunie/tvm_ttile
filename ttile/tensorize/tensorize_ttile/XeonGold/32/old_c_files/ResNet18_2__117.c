#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (16, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (4, c); T (2, f); T (1, x); T (4, y); T (2, x)]
*/
IND_TYPE c, cp_0, c6_p_0, cp_1, c6, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x8_p_0, x9_p_0, xp_1, x8_p_1, xp_2, x8, x9, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y4 = 0;
IND_TYPE x10 = 0;
IND_TYPE h4 = 0;
IND_TYPE w4 = 0;
IND_TYPE c7 = 0;
IND_TYPE f4 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_44 ,mem_vec_45 ,mem_vec_46 ,mem_vec_47 ,mem_vec_48 ,mem_vec_49 ,mem_vec_50 ,mem_vec_51 ,mem_vec_52 ,mem_vec_53 ,mem_vec_54 ,mem_vec_55 ,mem_vec_56 ,mem_vec_57 ,mem_vec_58 ,mem_vec_59 ,mem_vec_60 ,mem_vec_61 ,mem_vec_62 ,mem_vec_63 ,mem_vec_64 ,mem_vec_65 ,mem_vec_66 ,mem_vec_67 ,mem_vec_68 ,mem_vec_69 ,mem_vec_70 ,mem_vec_71 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 2) (56 / 28)
for (x9 = x10, x9_p_0 = 0;
	x9 < x10 + 56;
	x9 += 28, x9_p_0 += 28){
	// y = 56, x = 28, h = 3, w = 3, c = 64, f = 64
	// T (y, 4) (56 / 14)
	for (y = y4, yp_0 = 0;
		y < y4 + 56;
		y += 14, yp_0 += 14){
		// y = 14, x = 28, h = 3, w = 3, c = 64, f = 64
		// T (x, 1) (28 / 28)
		for (x8 = x9, x8_p_1 = x9_p_0, x8_p_0 = 0;
			x8 < x9 + 28;
			x8 += 28, x8_p_1 += 28, x8_p_0 += 28){
			// y = 14, x = 28, h = 3, w = 3, c = 64, f = 64
			// T (f, 2) (64 / 32)
			for (f = f4, fp_0 = 0;
				f < f4 + 64;
				f += 32, fp_0 += 32){
				// y = 14, x = 28, h = 3, w = 3, c = 64, f = 32
				// T (c, 4) (64 / 16)
				for (c6 = c7, c6_p_0 = 0;
					c6 < c7 + 64;
					c6 += 16, c6_p_0 += 16){
					// y = 14, x = 28, h = 3, w = 3, c = 16, f = 32
					// T (w, 3) (3 / 1)
					for (w = w4, wp_0 = 0;
						w < w4 + 3;
						w += 1, wp_0 += 1){
						// y = 14, x = 28, h = 3, w = 1, c = 16, f = 32
						// T (x, 28) (28 / 1)
						for (x = x8, xp_2 = x8_p_1, xp_1 = x8_p_0, xp_0 = 0;
							x < x8 + 28;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
							// y = 14, x = 1, h = 3, w = 1, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h4, hp_0 = 0;
								h < h4 + 3;
								h += 1, hp_0 += 1){
										mem_vec_44 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_45 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_46 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_47 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_48 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_49 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_50 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_51 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_52 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_53 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_54 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_55 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_56 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_57 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_58 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_59 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_60 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_61 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_62 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_63 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_64 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_65 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_66 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_67 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_68 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_69 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_70 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_71 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c6, cp_1 = c6_p_0, cp_0 = 0;
											c < c6 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_44);
											mem_vec_44 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_45);
											mem_vec_45 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_46);
											mem_vec_46 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_47);
											mem_vec_47 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_48);
											mem_vec_48 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_49);
											mem_vec_49 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_50);
											mem_vec_50 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_51);
											mem_vec_51 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_52);
											mem_vec_52 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_53);
											mem_vec_53 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_54);
											mem_vec_54 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_55);
											mem_vec_55 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_56);
											mem_vec_56 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_57);
											mem_vec_57 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_58);
											mem_vec_58 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_59);
											mem_vec_59 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_60);
											mem_vec_60 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_61);
											mem_vec_61 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_62);
											mem_vec_62 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_63);
											mem_vec_63 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_64);
											mem_vec_64 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_65);
											mem_vec_65 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_66);
											mem_vec_66 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_67);
											mem_vec_67 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_68);
											mem_vec_68 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_69);
											mem_vec_69 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_70);
											mem_vec_70 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_71);
											mem_vec_71 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_44);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_45);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_46);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_47);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_48);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_49);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_50);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_51);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_52);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_53);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_54);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_55);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_56);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_57);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_58);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_59);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_60);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_61);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_62);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_63);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_64);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_65);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_66);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_67);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_68);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_69);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_70);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_71);
							}
						}
					}
				}
			}
		}
	}
}


}