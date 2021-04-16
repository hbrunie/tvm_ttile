#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (56, x);
  T (3, h); T (4, c); T (2, f); T (1, x); T (4, y);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 1), (Arg 8))]]
*/
IND_TYPE c, cp_0, c252_p_0, cp_1, c252, f, fp_0, h, hp_0, x, xp_0, x299_p_0, xp_1, x299, y, yp_0, y205_p_0, yp_1, y205;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y206 = 0;
IND_TYPE x300 = 0;
IND_TYPE h126 = 0;
IND_TYPE w = 0;
IND_TYPE c253 = 0;
IND_TYPE f145 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2054 ,mem_vec_2055 ,mem_vec_2056 ,mem_vec_2057 ,mem_vec_2058 ,mem_vec_2059 ,mem_vec_2060 ,mem_vec_2061 ,mem_vec_2062 ,mem_vec_2063 ,mem_vec_2064 ,mem_vec_2065 ,mem_vec_2066 ,mem_vec_2067 ,mem_vec_2068 ,mem_vec_2069 ,mem_vec_2070 ,mem_vec_2071 ,mem_vec_2072 ,mem_vec_2073 ,mem_vec_2074 ,mem_vec_2075 ,mem_vec_2076 ,mem_vec_2077 ,mem_vec_2078 ,mem_vec_2079 ,mem_vec_2080 ,mem_vec_2081 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
	for (y205 = y206, y205_p_0 = 0;
		y205 < y206 + 24;
		y205 += 24, y205_p_0 += 24){
		// y = 4 * ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
		// T (y, 4) (4 * ph_y / ph_y)
		for (y = y205, yp_1 = y205_p_0, yp_0 = 0;
			y < y205 + 24;
			y += 6, yp_1 += 6, yp_0 += 6){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 1) (56 / 56)
			for (x299 = x300, x299_p_0 = 0;
				x299 < x300 + 56;
				x299 += 56, x299_p_0 += 56){
				// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f145, fp_0 = 0;
					f < f145 + 64;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c252 = c253, c252_p_0 = 0;
						c252 < c253 + 64;
						c252 += 16, c252_p_0 += 16){
						// y = ph_y, x = 56, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h126, hp_0 = 0;
							h < h126 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 56, h = 1, w = 3, c = 16, f = 32
							// T (x, 56) (56 / 1)
							for (x = x299, xp_1 = x299_p_0, xp_0 = 0;
								x < x299 + 56;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2054 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2055 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2057 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2058 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2059 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2060 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2061 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2062 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2063 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c252, cp_1 = c252_p_0, cp_0 = 0;
											c < c252 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2054);
											mem_vec_2054 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2055);
											mem_vec_2055 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2056);
											mem_vec_2056 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2057);
											mem_vec_2057 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2058);
											mem_vec_2058 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2059);
											mem_vec_2059 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2060);
											mem_vec_2060 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2061);
											mem_vec_2061 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2062);
											mem_vec_2062 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2063);
											mem_vec_2063 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2064);
											mem_vec_2064 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2065);
											mem_vec_2065 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_2054);
											mem_vec_2054 = vec_20;

											vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_2055);
											mem_vec_2055 = vec_23;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_26 = _mm512_set1_ps(scal_7);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_2056);
											mem_vec_2056 = vec_25;



											vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_2057);
											mem_vec_2057 = vec_27;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_29 = _mm512_set1_ps(scal_8);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_2058);
											mem_vec_2058 = vec_28;



											vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_2059);
											mem_vec_2059 = vec_30;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_2060);
											mem_vec_2060 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_2061);
											mem_vec_2061 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_2062);
											mem_vec_2062 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_2063);
											mem_vec_2063 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_2064);
											mem_vec_2064 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_2065);
											mem_vec_2065 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_41 = _mm512_set1_ps(scal_12);
											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_2054);
											mem_vec_2054 = vec_40;

											vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_2055);
											mem_vec_2055 = vec_43;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_46 = _mm512_set1_ps(scal_13);


											vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_2056);
											mem_vec_2056 = vec_45;



											vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_2057);
											mem_vec_2057 = vec_47;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_49 = _mm512_set1_ps(scal_14);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_2058);
											mem_vec_2058 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_2059);
											mem_vec_2059 = vec_50;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_52 = _mm512_set1_ps(scal_15);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_2060);
											mem_vec_2060 = vec_51;



											vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_2061);
											mem_vec_2061 = vec_53;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_55 = _mm512_set1_ps(scal_16);


											vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_2062);
											mem_vec_2062 = vec_54;



											vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_2063);
											mem_vec_2063 = vec_56;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_58 = _mm512_set1_ps(scal_17);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_2064);
											mem_vec_2064 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_2065);
											mem_vec_2065 = vec_59;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2054);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2055);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2056);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2057);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2058);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2059);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2060);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2061);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2062);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2063);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2064);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2065);
							}
						}
					}
				}
			}
		}
	}
	for (y205 = y206 + 24, y205_p_0 = 0;
		y205 < y206 + 24 + 32;
		y205 += 32, y205_p_0 += 32){
		// y = 4 * ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
		// T (y, 4) (4 * ph_y / ph_y)
		for (y = y205, yp_1 = y205_p_0, yp_0 = 0;
			y < y205 + 32;
			y += 8, yp_1 += 8, yp_0 += 8){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 1) (56 / 56)
			for (x299 = x300, x299_p_0 = 0;
				x299 < x300 + 56;
				x299 += 56, x299_p_0 += 56){
				// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f145, fp_0 = 0;
					f < f145 + 64;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c252 = c253, c252_p_0 = 0;
						c252 < c253 + 64;
						c252 += 16, c252_p_0 += 16){
						// y = ph_y, x = 56, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h126, hp_0 = 0;
							h < h126 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 56, h = 1, w = 3, c = 16, f = 32
							// T (x, 56) (56 / 1)
							for (x = x299, xp_1 = x299_p_0, xp_0 = 0;
								x < x299 + 56;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2066 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2067 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2072 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_2080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_2081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c252, cp_1 = c252_p_0, cp_0 = 0;
											c < c252 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2066);
											mem_vec_2066 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2067);
											mem_vec_2067 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2068);
											mem_vec_2068 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2069);
											mem_vec_2069 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2070);
											mem_vec_2070 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2071);
											mem_vec_2071 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2072);
											mem_vec_2072 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2073);
											mem_vec_2073 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2074);
											mem_vec_2074 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2075);
											mem_vec_2075 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2076);
											mem_vec_2076 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2077);
											mem_vec_2077 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2078);
											mem_vec_2078 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2079);
											mem_vec_2079 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2080);
											mem_vec_2080 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2081);
											mem_vec_2081 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_2066);
											mem_vec_2066 = vec_26;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_2067);
											mem_vec_2067 = vec_29;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_2068);
											mem_vec_2068 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_2069);
											mem_vec_2069 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_2070);
											mem_vec_2070 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_2071);
											mem_vec_2071 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_2072);
											mem_vec_2072 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_2073);
											mem_vec_2073 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_2074);
											mem_vec_2074 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_2075);
											mem_vec_2075 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_2076);
											mem_vec_2076 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_2077);
											mem_vec_2077 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_2078);
											mem_vec_2078 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_2079);
											mem_vec_2079 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_2080);
											mem_vec_2080 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_2081);
											mem_vec_2081 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_53 = _mm512_set1_ps(scal_16);
											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_2066);
											mem_vec_2066 = vec_52;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_2067);
											mem_vec_2067 = vec_55;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm512_set1_ps(scal_17);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_2068);
											mem_vec_2068 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_2069);
											mem_vec_2069 = vec_59;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_61 = _mm512_set1_ps(scal_18);


											vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_2070);
											mem_vec_2070 = vec_60;



											vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_2071);
											mem_vec_2071 = vec_62;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_2072);
											mem_vec_2072 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_2073);
											mem_vec_2073 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_2074);
											mem_vec_2074 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_2075);
											mem_vec_2075 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_2076);
											mem_vec_2076 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_2077);
											mem_vec_2077 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_2078);
											mem_vec_2078 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_2079);
											mem_vec_2079 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_2080);
											mem_vec_2080 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_2081);
											mem_vec_2081 = vec_77;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2066);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2067);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2068);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2069);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2070);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2071);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2072);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2073);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2074);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2075);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2076);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2077);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2078);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2079);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2080);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2081);
							}
						}
					}
				}
			}
		}
	}


}