#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (3, h);
  T (17, x); Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))];
  T (4, c); T (8, f); T (8, c); T (8, f)]
*/
IND_TYPE c, cp_0, c716_p_0, c717_p_0, cp_1, c716_p_1, cp_2, c716, c717, f, fp_0, f537_p_0, fp_1, f537, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y358 = 0;
IND_TYPE x358 = 0;
IND_TYPE h236 = 0;
IND_TYPE w = 0;
IND_TYPE c718 = 0;
IND_TYPE f538 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3078 ,mem_vec_3079 ,mem_vec_3080 ,mem_vec_3081 ,mem_vec_3082 ,mem_vec_3083 ,mem_vec_3084 ,mem_vec_3085 ,mem_vec_3086 ,mem_vec_3087 ,mem_vec_3088 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 8) (1024 / 128)
for (f537 = f538, f537_p_0 = 0;
	f537 < f538 + 1024;
	f537 += 128, f537_p_0 += 128){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 128
	// T (c, 8) (512 / 64)
	for (c717 = c718, c717_p_0 = 0;
		c717 < c718 + 512;
		c717 += 64, c717_p_0 += 64){
		// y = 17, x = 17, h = 3, w = 3, c = 64, f = 128
		// T (f, 8) (128 / 16)
		for (f = f537, fp_1 = f537_p_0, fp_0 = 0;
			f < f537 + 128;
			f += 16, fp_1 += 16, fp_0 += 16){
			// y = 17, x = 17, h = 3, w = 3, c = 64, f = 16
			// T (c, 4) (64 / 16)
			for (c716 = c717, c716_p_1 = c717_p_0, c716_p_0 = 0;
				c716 < c717 + 64;
				c716 += 16, c716_p_1 += 16, c716_p_0 += 16){
					for (y = y358, yp_0 = 0;
						y < y358 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 16
						// T (x, 17) (17 / 1)
						for (x = x358, xp_0 = 0;
							x < x358 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
							// T (h, 3) (3 / 1)
							for (h = h236, hp_0 = 0;
								h < h236 + 3;
								h += 1, hp_0 += 1){
										mem_vec_3078 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3082 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 16
										// T (c, 16) (16 / 1)
										for (c = c716, cp_2 = c716_p_1, cp_1 = c716_p_0, cp_0 = 0;
											c < c716 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3078);
											mem_vec_3078 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_3079);
											mem_vec_3079 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3080);
											mem_vec_3080 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_3081);
											mem_vec_3081 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3082);
											mem_vec_3082 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);
											vec_13 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_11 = _mm512_fmadd_ps(vec_12, vec_13, mem_vec_3078);
											mem_vec_3078 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_15 = _mm512_set1_ps(scal_6);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_13, mem_vec_3079);
											mem_vec_3079 = vec_14;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_17 = _mm512_set1_ps(scal_7);


											vec_16 = _mm512_fmadd_ps(vec_17, vec_13, mem_vec_3080);
											mem_vec_3080 = vec_16;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_19 = _mm512_set1_ps(scal_8);


											vec_18 = _mm512_fmadd_ps(vec_19, vec_13, mem_vec_3081);
											mem_vec_3081 = vec_18;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_21 = _mm512_set1_ps(scal_9);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_13, mem_vec_3082);
											mem_vec_3082 = vec_20;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_23 = _mm512_set1_ps(scal_10);
											vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_22 = _mm512_fmadd_ps(vec_23, vec_24, mem_vec_3078);
											mem_vec_3078 = vec_22;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_26 = _mm512_set1_ps(scal_11);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_3079);
											mem_vec_3079 = vec_25;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_28 = _mm512_set1_ps(scal_12);


											vec_27 = _mm512_fmadd_ps(vec_28, vec_24, mem_vec_3080);
											mem_vec_3080 = vec_27;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_30 = _mm512_set1_ps(scal_13);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_24, mem_vec_3081);
											mem_vec_3081 = vec_29;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_32 = _mm512_set1_ps(scal_14);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_3082);
											mem_vec_3082 = vec_31;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3078);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3079);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3080);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3081);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3082);
							}
						}
					}
					for (y = y358 + 5, yp_0 = 0;
						y < y358 + 5 + 12;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 16
						// T (x, 17) (17 / 1)
						for (x = x358, xp_0 = 0;
							x < x358 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
							// T (h, 3) (3 / 1)
							for (h = h236, hp_0 = 0;
								h < h236 + 3;
								h += 1, hp_0 += 1){
										mem_vec_3083 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 16
										// T (c, 16) (16 / 1)
										for (c = c716, cp_2 = c716_p_1, cp_1 = c716_p_0, cp_0 = 0;
											c < c716 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3083);
											mem_vec_3083 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_3084);
											mem_vec_3084 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3085);
											mem_vec_3085 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_3086);
											mem_vec_3086 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3087);
											mem_vec_3087 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3088);
											mem_vec_3088 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);
											vec_15 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_13 = _mm512_fmadd_ps(vec_14, vec_15, mem_vec_3083);
											mem_vec_3083 = vec_13;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_17 = _mm512_set1_ps(scal_7);


											vec_16 = _mm512_fmadd_ps(vec_17, vec_15, mem_vec_3084);
											mem_vec_3084 = vec_16;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_19 = _mm512_set1_ps(scal_8);


											vec_18 = _mm512_fmadd_ps(vec_19, vec_15, mem_vec_3085);
											mem_vec_3085 = vec_18;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_21 = _mm512_set1_ps(scal_9);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_15, mem_vec_3086);
											mem_vec_3086 = vec_20;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_23 = _mm512_set1_ps(scal_10);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_15, mem_vec_3087);
											mem_vec_3087 = vec_22;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_25 = _mm512_set1_ps(scal_11);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_15, mem_vec_3088);
											mem_vec_3088 = vec_24;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_27 = _mm512_set1_ps(scal_12);
											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_3083);
											mem_vec_3083 = vec_26;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_30 = _mm512_set1_ps(scal_13);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_28, mem_vec_3084);
											mem_vec_3084 = vec_29;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_32 = _mm512_set1_ps(scal_14);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_3085);
											mem_vec_3085 = vec_31;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_34 = _mm512_set1_ps(scal_15);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_3086);
											mem_vec_3086 = vec_33;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_36 = _mm512_set1_ps(scal_16);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_28, mem_vec_3087);
											mem_vec_3087 = vec_35;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_38 = _mm512_set1_ps(scal_17);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_3088);
											mem_vec_3088 = vec_37;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3083);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3084);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3085);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3086);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3087);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3088);
							}
						}
					}
			}
		}
	}
}


}