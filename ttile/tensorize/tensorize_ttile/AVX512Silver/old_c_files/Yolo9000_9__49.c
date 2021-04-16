#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (34, x); T (1, c);
  T (2, f); T (2, x); T (4, y); T (1, x);
  Lambda_apply y [((Iter 4), (Arg 3)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c252_p_0, cp_1, c252, f, fp_0, x, xp_0, x336_p_0, x337_p_0, xp_1, x336_p_1, xp_2, x336, x337, y, yp_0, y252_p_0, yp_1, y252;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y253 = 0;
IND_TYPE x338 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c253 = 0;
IND_TYPE f168 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_2968 ,mem_vec_2969 ,mem_vec_2970 ,mem_vec_2971 ,mem_vec_2972 ,mem_vec_2973 ,mem_vec_2974 ,mem_vec_2975 ,mem_vec_2976 ,mem_vec_2977 ,mem_vec_2978 ,mem_vec_2979 ,mem_vec_2980 ,mem_vec_2981 ,mem_vec_2982 ,mem_vec_2983 ,mem_vec_2984 ,mem_vec_2985 ,mem_vec_2986 ,mem_vec_2987 ,mem_vec_2988 ,mem_vec_2989 ,mem_vec_2990 ,mem_vec_2991 ,mem_vec_2992 ,mem_vec_2993 ,mem_vec_2994 ,mem_vec_2995 ,mem_vec_2996 ,mem_vec_2997 ,mem_vec_2998 ,mem_vec_2999 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y252 = y253, y252_p_0 = 0;
		y252 < y253 + 48;
		y252 += 12, y252_p_0 += 12){
		// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x337 = x338, x337_p_0 = 0;
			x337 < x338 + 68;
			x337 += 68, x337_p_0 += 68){
			// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y252, yp_1 = y252_p_0, yp_0 = 0;
				y < y252 + 12;
				y += 3, yp_1 += 3, yp_0 += 3){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 2) (68 / 34)
				for (x336 = x337, x336_p_1 = x337_p_0, x336_p_0 = 0;
					x336 < x337 + 68;
					x336 += 34, x336_p_1 += 34, x336_p_0 += 34){
					// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f168, fp_0 = 0;
						f < f168 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c252 = c253, c252_p_0 = 0;
							c252 < c253 + 256;
							c252 += 256, c252_p_0 += 256){
							// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
							// T (x, 34) (34 / 1)
							for (x = x336, xp_2 = x336_p_1, xp_1 = x336_p_0, xp_0 = 0;
								x < x336 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2968 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2969 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2970 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_2971 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_2972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_2975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_2976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_2979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c252, cp_1 = c252_p_0, cp_0 = 0;
											c < c252 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2968);
											mem_vec_2968 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2969);
											mem_vec_2969 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2970);
											mem_vec_2970 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2971);
											mem_vec_2971 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2972);
											mem_vec_2972 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2973);
											mem_vec_2973 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2974);
											mem_vec_2974 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2975);
											mem_vec_2975 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2976);
											mem_vec_2976 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2977);
											mem_vec_2977 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2978);
											mem_vec_2978 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2979);
											mem_vec_2979 = vec_18;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2968);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2969);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2970);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2971);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2972);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2973);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2974);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2975);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2976);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2977);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2978);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2979);
							}
						}
					}
				}
			}
		}
	}
	for (y252 = y253 + 48, y252_p_0 = 0;
		y252 < y253 + 48 + 20;
		y252 += 20, y252_p_0 += 20){
		// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x337 = x338, x337_p_0 = 0;
			x337 < x338 + 68;
			x337 += 68, x337_p_0 += 68){
			// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y252, yp_1 = y252_p_0, yp_0 = 0;
				y < y252 + 20;
				y += 5, yp_1 += 5, yp_0 += 5){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 2) (68 / 34)
				for (x336 = x337, x336_p_1 = x337_p_0, x336_p_0 = 0;
					x336 < x337 + 68;
					x336 += 34, x336_p_1 += 34, x336_p_0 += 34){
					// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f168, fp_0 = 0;
						f < f168 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c252 = c253, c252_p_0 = 0;
							c252 < c253 + 256;
							c252 += 256, c252_p_0 += 256){
							// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
							// T (x, 34) (34 / 1)
							for (x = x336, xp_2 = x336_p_1, xp_1 = x336_p_0, xp_0 = 0;
								x < x336 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2980 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2981 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2982 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_2983 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_2984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_2987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_2988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_2991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_2992 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2993 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2994 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_2995 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_2996 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2997 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2998 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_2999 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c252, cp_1 = c252_p_0, cp_0 = 0;
											c < c252 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2980);
											mem_vec_2980 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2981);
											mem_vec_2981 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2982);
											mem_vec_2982 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2983);
											mem_vec_2983 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2984);
											mem_vec_2984 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2985);
											mem_vec_2985 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2986);
											mem_vec_2986 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2987);
											mem_vec_2987 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2988);
											mem_vec_2988 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2989);
											mem_vec_2989 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2990);
											mem_vec_2990 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2991);
											mem_vec_2991 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2992);
											mem_vec_2992 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2993);
											mem_vec_2993 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2994);
											mem_vec_2994 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2995);
											mem_vec_2995 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2996);
											mem_vec_2996 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2997);
											mem_vec_2997 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2998);
											mem_vec_2998 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2999);
											mem_vec_2999 = vec_28;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2980);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2981);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2982);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2983);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2984);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2985);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2986);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2987);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2988);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2989);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2990);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2991);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2992);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2993);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2994);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2995);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2996);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2997);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2998);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2999);
							}
						}
					}
				}
			}
		}
	}


}