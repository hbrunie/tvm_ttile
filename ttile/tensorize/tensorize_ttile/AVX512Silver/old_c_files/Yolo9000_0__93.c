#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (8, y); U (3, h); T (3, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (2, f); T (2, x); T (1, y); T (17, y); T (136, x); T (4, y)]
*/
IND_TYPE c, cp_0, f, fp_0, w, wp_0, x, xp_0, x596_p_0, x597_p_0, xp_1, x596_p_1, xp_2, x596, x597, y, yp_0, y558_p_0, y559_p_0, yp_1, y558_p_1, yp_2, y558, y559;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y560 = 0;
IND_TYPE x598 = 0;
IND_TYPE h = 0;
IND_TYPE w265 = 0;
IND_TYPE c336 = 0;
IND_TYPE f260 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2612 ,mem_vec_2613 ,mem_vec_2614 ,mem_vec_2615 ,mem_vec_2616 ,mem_vec_2617 ,mem_vec_2618 ,mem_vec_2619 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 4) (544 / 136)
for (y559 = y560, y559_p_0 = 0;
	y559 < y560 + 544;
	y559 += 136, y559_p_0 += 136){
	// y = 136, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (x, 136) (544 / 4)
	for (x597 = x598, x597_p_0 = 0;
		x597 < x598 + 544;
		x597 += 4, x597_p_0 += 4){
		// y = 136, x = 4, h = 3, w = 3, c = 3, f = 32
		// T (y, 17) (136 / 8)
		for (y558 = y559, y558_p_1 = y559_p_0, y558_p_0 = 0;
			y558 < y559 + 136;
			y558 += 8, y558_p_1 += 8, y558_p_0 += 8){
			// y = 8, x = 4, h = 3, w = 3, c = 3, f = 32
			// T (y, 1) (8 / 8)
			for (y = y558, yp_2 = y558_p_1, yp_1 = y558_p_0, yp_0 = 0;
				y < y558 + 8;
				y += 8, yp_2 += 8, yp_1 += 8, yp_0 += 8){
				// y = 8, x = 4, h = 3, w = 3, c = 3, f = 32
				// T (x, 2) (4 / 2)
				for (x596 = x597, x596_p_1 = x597_p_0, x596_p_0 = 0;
					x596 < x597 + 4;
					x596 += 2, x596_p_1 += 2, x596_p_0 += 2){
					// y = 8, x = 2, h = 3, w = 3, c = 3, f = 32
					// T (f, 2) (32 / 16)
					for (f = f260, fp_0 = 0;
						f < f260 + 32;
						f += 16, fp_0 += 16){
						// y = 8, x = 2, h = 3, w = 3, c = 3, f = 16
						// T (w, 3) (3 / 1)
						for (w = w265, wp_0 = 0;
							w < w265 + 3;
							w += 1, wp_0 += 1){
							// y = 8, x = 2, h = 3, w = 1, c = 3, f = 16
							// T (x, 2) (2 / 1)
							for (x = x596, xp_2 = x596_p_1, xp_1 = x596_p_0, xp_0 = 0;
								x < x596 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2612 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										// y = 8, x = 1, h = 3, w = 1, c = 3, f = 16
										// T (c, 3) (3 / 1)
										for (c = c336, cp_0 = 0;
											c < c336 + 3;
											c += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2612);
											mem_vec_2612 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_2613);
											mem_vec_2613 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2614);
											mem_vec_2614 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_2615);
											mem_vec_2615 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2616);
											mem_vec_2616 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2617);
											mem_vec_2617 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);


											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_2618);
											mem_vec_2618 = vec_13;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_2619);
											mem_vec_2619 = vec_15;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_18 = _mm512_set1_ps(scal_8);
											vec_19 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_17 = _mm512_fmadd_ps(vec_18, vec_19, mem_vec_2612);
											mem_vec_2612 = vec_17;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_21 = _mm512_set1_ps(scal_9);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_19, mem_vec_2613);
											mem_vec_2613 = vec_20;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_23 = _mm512_set1_ps(scal_10);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_19, mem_vec_2614);
											mem_vec_2614 = vec_22;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_25 = _mm512_set1_ps(scal_11);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_19, mem_vec_2615);
											mem_vec_2615 = vec_24;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_27 = _mm512_set1_ps(scal_12);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_19, mem_vec_2616);
											mem_vec_2616 = vec_26;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_13);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_19, mem_vec_2617);
											mem_vec_2617 = vec_28;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);


											vec_30 = _mm512_fmadd_ps(vec_31, vec_19, mem_vec_2618);
											mem_vec_2618 = vec_30;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_19, mem_vec_2619);
											mem_vec_2619 = vec_32;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_35 = _mm512_set1_ps(scal_16);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_2612);
											mem_vec_2612 = vec_34;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_38 = _mm512_set1_ps(scal_17);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_2613);
											mem_vec_2613 = vec_37;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_40 = _mm512_set1_ps(scal_18);


											vec_39 = _mm512_fmadd_ps(vec_40, vec_36, mem_vec_2614);
											mem_vec_2614 = vec_39;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_42 = _mm512_set1_ps(scal_19);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_36, mem_vec_2615);
											mem_vec_2615 = vec_41;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_44 = _mm512_set1_ps(scal_20);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_2616);
											mem_vec_2616 = vec_43;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_46 = _mm512_set1_ps(scal_21);


											vec_45 = _mm512_fmadd_ps(vec_46, vec_36, mem_vec_2617);
											mem_vec_2617 = vec_45;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_48 = _mm512_set1_ps(scal_22);


											vec_47 = _mm512_fmadd_ps(vec_48, vec_36, mem_vec_2618);
											mem_vec_2618 = vec_47;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_50 = _mm512_set1_ps(scal_23);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_2619);
											mem_vec_2619 = vec_49;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2612);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2613);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2614);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2615);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2616);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2617);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2618);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2619);
							}
						}
					}
				}
			}
		}
	}
}


}