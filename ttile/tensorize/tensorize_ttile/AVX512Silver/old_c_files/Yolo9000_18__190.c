#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (3, h);
  T (17, x); Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))];
  T (2, c); T (8, f); T (8, c); T (8, f)]
*/
IND_TYPE c, cp_0, c712_p_0, c713_p_0, cp_1, c712_p_1, cp_2, c712, c713, f, fp_0, f534_p_0, fp_1, f534, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y356 = 0;
IND_TYPE x356 = 0;
IND_TYPE h234 = 0;
IND_TYPE w = 0;
IND_TYPE c714 = 0;
IND_TYPE f535 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3067 ,mem_vec_3068 ,mem_vec_3069 ,mem_vec_3070 ,mem_vec_3071 ,mem_vec_3072 ,mem_vec_3073 ,mem_vec_3074 ,mem_vec_3075 ,mem_vec_3076 ,mem_vec_3077 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 8) (1024 / 128)
for (f534 = f535, f534_p_0 = 0;
	f534 < f535 + 1024;
	f534 += 128, f534_p_0 += 128){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 128
	// T (c, 8) (512 / 64)
	for (c713 = c714, c713_p_0 = 0;
		c713 < c714 + 512;
		c713 += 64, c713_p_0 += 64){
		// y = 17, x = 17, h = 3, w = 3, c = 64, f = 128
		// T (f, 8) (128 / 16)
		for (f = f534, fp_1 = f534_p_0, fp_0 = 0;
			f < f534 + 128;
			f += 16, fp_1 += 16, fp_0 += 16){
			// y = 17, x = 17, h = 3, w = 3, c = 64, f = 16
			// T (c, 2) (64 / 32)
			for (c712 = c713, c712_p_1 = c713_p_0, c712_p_0 = 0;
				c712 < c713 + 64;
				c712 += 32, c712_p_1 += 32, c712_p_0 += 32){
					for (y = y356, yp_0 = 0;
						y < y356 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 16
						// T (x, 17) (17 / 1)
						for (x = x356, xp_0 = 0;
							x < x356 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
							// T (h, 3) (3 / 1)
							for (h = h234, hp_0 = 0;
								h < h234 + 3;
								h += 1, hp_0 += 1){
										mem_vec_3067 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 16
										// T (c, 32) (32 / 1)
										for (c = c712, cp_2 = c712_p_1, cp_1 = c712_p_0, cp_0 = 0;
											c < c712 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3067);
											mem_vec_3067 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_3068);
											mem_vec_3068 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3069);
											mem_vec_3069 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_3070);
											mem_vec_3070 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3071);
											mem_vec_3071 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);
											vec_13 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_11 = _mm512_fmadd_ps(vec_12, vec_13, mem_vec_3067);
											mem_vec_3067 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_15 = _mm512_set1_ps(scal_6);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_13, mem_vec_3068);
											mem_vec_3068 = vec_14;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_17 = _mm512_set1_ps(scal_7);


											vec_16 = _mm512_fmadd_ps(vec_17, vec_13, mem_vec_3069);
											mem_vec_3069 = vec_16;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_19 = _mm512_set1_ps(scal_8);


											vec_18 = _mm512_fmadd_ps(vec_19, vec_13, mem_vec_3070);
											mem_vec_3070 = vec_18;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_21 = _mm512_set1_ps(scal_9);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_13, mem_vec_3071);
											mem_vec_3071 = vec_20;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_23 = _mm512_set1_ps(scal_10);
											vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_22 = _mm512_fmadd_ps(vec_23, vec_24, mem_vec_3067);
											mem_vec_3067 = vec_22;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_26 = _mm512_set1_ps(scal_11);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_3068);
											mem_vec_3068 = vec_25;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_28 = _mm512_set1_ps(scal_12);


											vec_27 = _mm512_fmadd_ps(vec_28, vec_24, mem_vec_3069);
											mem_vec_3069 = vec_27;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_30 = _mm512_set1_ps(scal_13);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_24, mem_vec_3070);
											mem_vec_3070 = vec_29;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_32 = _mm512_set1_ps(scal_14);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_3071);
											mem_vec_3071 = vec_31;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3067);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3068);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3069);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3070);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3071);
							}
						}
					}
					for (y = y356 + 5, yp_0 = 0;
						y < y356 + 5 + 12;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 16
						// T (x, 17) (17 / 1)
						for (x = x356, xp_0 = 0;
							x < x356 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
							// T (h, 3) (3 / 1)
							for (h = h234, hp_0 = 0;
								h < h234 + 3;
								h += 1, hp_0 += 1){
										mem_vec_3072 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 16
										// T (c, 32) (32 / 1)
										for (c = c712, cp_2 = c712_p_1, cp_1 = c712_p_0, cp_0 = 0;
											c < c712 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3072);
											mem_vec_3072 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_3073);
											mem_vec_3073 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3074);
											mem_vec_3074 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_3075);
											mem_vec_3075 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3076);
											mem_vec_3076 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3077);
											mem_vec_3077 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);
											vec_15 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_13 = _mm512_fmadd_ps(vec_14, vec_15, mem_vec_3072);
											mem_vec_3072 = vec_13;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_17 = _mm512_set1_ps(scal_7);


											vec_16 = _mm512_fmadd_ps(vec_17, vec_15, mem_vec_3073);
											mem_vec_3073 = vec_16;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_19 = _mm512_set1_ps(scal_8);


											vec_18 = _mm512_fmadd_ps(vec_19, vec_15, mem_vec_3074);
											mem_vec_3074 = vec_18;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_21 = _mm512_set1_ps(scal_9);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_15, mem_vec_3075);
											mem_vec_3075 = vec_20;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_23 = _mm512_set1_ps(scal_10);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_15, mem_vec_3076);
											mem_vec_3076 = vec_22;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_25 = _mm512_set1_ps(scal_11);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_15, mem_vec_3077);
											mem_vec_3077 = vec_24;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_27 = _mm512_set1_ps(scal_12);
											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_3072);
											mem_vec_3072 = vec_26;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_30 = _mm512_set1_ps(scal_13);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_28, mem_vec_3073);
											mem_vec_3073 = vec_29;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_32 = _mm512_set1_ps(scal_14);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_3074);
											mem_vec_3074 = vec_31;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_34 = _mm512_set1_ps(scal_15);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_3075);
											mem_vec_3075 = vec_33;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_36 = _mm512_set1_ps(scal_16);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_28, mem_vec_3076);
											mem_vec_3076 = vec_35;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_38 = _mm512_set1_ps(scal_17);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_3077);
											mem_vec_3077 = vec_37;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3072);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3073);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3074);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3075);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3076);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3077);
							}
						}
					}
			}
		}
	}
}


}