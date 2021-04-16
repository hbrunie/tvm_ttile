#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (3, h);
  T (17, x); Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))];
  T (8, c); T (8, f); T (8, c); T (8, f)]
*/
IND_TYPE c, cp_0, c736_p_0, c737_p_0, cp_1, c736_p_1, cp_2, c736, c737, f, fp_0, f552_p_0, fp_1, f552, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y368 = 0;
IND_TYPE x368 = 0;
IND_TYPE h246 = 0;
IND_TYPE w = 0;
IND_TYPE c738 = 0;
IND_TYPE f553 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3136 ,mem_vec_3137 ,mem_vec_3138 ,mem_vec_3139 ,mem_vec_3140 ,mem_vec_3141 ,mem_vec_3142 ,mem_vec_3143 ,mem_vec_3144 ,mem_vec_3145 ,mem_vec_3146 ,mem_vec_3147 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 8) (1024 / 128)
for (f552 = f553, f552_p_0 = 0;
	f552 < f553 + 1024;
	f552 += 128, f552_p_0 += 128){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 128
	// T (c, 8) (512 / 64)
	for (c737 = c738, c737_p_0 = 0;
		c737 < c738 + 512;
		c737 += 64, c737_p_0 += 64){
		// y = 17, x = 17, h = 3, w = 3, c = 64, f = 128
		// T (f, 8) (128 / 16)
		for (f = f552, fp_1 = f552_p_0, fp_0 = 0;
			f < f552 + 128;
			f += 16, fp_1 += 16, fp_0 += 16){
			// y = 17, x = 17, h = 3, w = 3, c = 64, f = 16
			// T (c, 8) (64 / 8)
			for (c736 = c737, c736_p_1 = c737_p_0, c736_p_0 = 0;
				c736 < c737 + 64;
				c736 += 8, c736_p_1 += 8, c736_p_0 += 8){
					for (y = y368, yp_0 = 0;
						y < y368 + 10;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 16
						// T (x, 17) (17 / 1)
						for (x = x368, xp_0 = 0;
							x < x368 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
							// T (h, 3) (3 / 1)
							for (h = h246, hp_0 = 0;
								h < h246 + 3;
								h += 1, hp_0 += 1){
										mem_vec_3136 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 16
										// T (c, 8) (8 / 1)
										for (c = c736, cp_2 = c736_p_1, cp_1 = c736_p_0, cp_0 = 0;
											c < c736 + 8;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3136);
											mem_vec_3136 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_3137);
											mem_vec_3137 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3138);
											mem_vec_3138 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_3139);
											mem_vec_3139 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3140);
											mem_vec_3140 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);
											vec_13 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_11 = _mm512_fmadd_ps(vec_12, vec_13, mem_vec_3136);
											mem_vec_3136 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_15 = _mm512_set1_ps(scal_6);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_13, mem_vec_3137);
											mem_vec_3137 = vec_14;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_17 = _mm512_set1_ps(scal_7);


											vec_16 = _mm512_fmadd_ps(vec_17, vec_13, mem_vec_3138);
											mem_vec_3138 = vec_16;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_19 = _mm512_set1_ps(scal_8);


											vec_18 = _mm512_fmadd_ps(vec_19, vec_13, mem_vec_3139);
											mem_vec_3139 = vec_18;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_21 = _mm512_set1_ps(scal_9);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_13, mem_vec_3140);
											mem_vec_3140 = vec_20;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_23 = _mm512_set1_ps(scal_10);
											vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_22 = _mm512_fmadd_ps(vec_23, vec_24, mem_vec_3136);
											mem_vec_3136 = vec_22;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_26 = _mm512_set1_ps(scal_11);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_3137);
											mem_vec_3137 = vec_25;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_28 = _mm512_set1_ps(scal_12);


											vec_27 = _mm512_fmadd_ps(vec_28, vec_24, mem_vec_3138);
											mem_vec_3138 = vec_27;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_30 = _mm512_set1_ps(scal_13);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_24, mem_vec_3139);
											mem_vec_3139 = vec_29;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_32 = _mm512_set1_ps(scal_14);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_3140);
											mem_vec_3140 = vec_31;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3136);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3137);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3138);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3139);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3140);
							}
						}
					}
					for (y = y368 + 10, yp_0 = 0;
						y < y368 + 10 + 7;
						y += 7, yp_0 += 7){
						// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 16
						// T (x, 17) (17 / 1)
						for (x = x368, xp_0 = 0;
							x < x368 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
							// T (h, 3) (3 / 1)
							for (h = h246, hp_0 = 0;
								h < h246 + 3;
								h += 1, hp_0 += 1){
										mem_vec_3141 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 16
										// T (c, 8) (8 / 1)
										for (c = c736, cp_2 = c736_p_1, cp_1 = c736_p_0, cp_0 = 0;
											c < c736 + 8;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3141);
											mem_vec_3141 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_3142);
											mem_vec_3142 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3143);
											mem_vec_3143 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_3144);
											mem_vec_3144 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3145);
											mem_vec_3145 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3146);
											mem_vec_3146 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);


											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_3147);
											mem_vec_3147 = vec_13;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);
											vec_17 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_15 = _mm512_fmadd_ps(vec_16, vec_17, mem_vec_3141);
											mem_vec_3141 = vec_15;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_19 = _mm512_set1_ps(scal_8);


											vec_18 = _mm512_fmadd_ps(vec_19, vec_17, mem_vec_3142);
											mem_vec_3142 = vec_18;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_21 = _mm512_set1_ps(scal_9);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_17, mem_vec_3143);
											mem_vec_3143 = vec_20;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_23 = _mm512_set1_ps(scal_10);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_17, mem_vec_3144);
											mem_vec_3144 = vec_22;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_11);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_17, mem_vec_3145);
											mem_vec_3145 = vec_24;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_27 = _mm512_set1_ps(scal_12);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_17, mem_vec_3146);
											mem_vec_3146 = vec_26;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_29 = _mm512_set1_ps(scal_13);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_17, mem_vec_3147);
											mem_vec_3147 = vec_28;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_31 = _mm512_set1_ps(scal_14);
											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_30 = _mm512_fmadd_ps(vec_31, vec_32, mem_vec_3141);
											mem_vec_3141 = vec_30;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_15);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_3142);
											mem_vec_3142 = vec_33;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_36 = _mm512_set1_ps(scal_16);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_32, mem_vec_3143);
											mem_vec_3143 = vec_35;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_38 = _mm512_set1_ps(scal_17);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_3144);
											mem_vec_3144 = vec_37;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_40 = _mm512_set1_ps(scal_18);


											vec_39 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_3145);
											mem_vec_3145 = vec_39;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_42 = _mm512_set1_ps(scal_19);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_32, mem_vec_3146);
											mem_vec_3146 = vec_41;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_44 = _mm512_set1_ps(scal_20);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_3147);
											mem_vec_3147 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3141);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3142);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3143);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3144);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3145);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3146);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3147);
							}
						}
					}
			}
		}
	}
}


}