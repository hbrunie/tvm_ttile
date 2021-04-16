#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (8, y); U (3, h); T (3, c); Hoist_vars [c]; T (4, x);
  T (3, w); T (2, f); T (1, x); T (1, y); T (17, y); T (136, x); T (4, y)]
*/
IND_TYPE c, cp_0, f, fp_0, w, wp_0, x, xp_0, x588_p_0, x589_p_0, xp_1, x588_p_1, xp_2, x588, x589, y, yp_0, y550_p_0, y551_p_0, yp_1, y550_p_1, yp_2, y550, y551;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y552 = 0;
IND_TYPE x590 = 0;
IND_TYPE h = 0;
IND_TYPE w261 = 0;
IND_TYPE c332 = 0;
IND_TYPE f256 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2596 ,mem_vec_2597 ,mem_vec_2598 ,mem_vec_2599 ,mem_vec_2600 ,mem_vec_2601 ,mem_vec_2602 ,mem_vec_2603 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 4) (544 / 136)
for (y551 = y552, y551_p_0 = 0;
	y551 < y552 + 544;
	y551 += 136, y551_p_0 += 136){
	// y = 136, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (x, 136) (544 / 4)
	for (x589 = x590, x589_p_0 = 0;
		x589 < x590 + 544;
		x589 += 4, x589_p_0 += 4){
		// y = 136, x = 4, h = 3, w = 3, c = 3, f = 32
		// T (y, 17) (136 / 8)
		for (y550 = y551, y550_p_1 = y551_p_0, y550_p_0 = 0;
			y550 < y551 + 136;
			y550 += 8, y550_p_1 += 8, y550_p_0 += 8){
			// y = 8, x = 4, h = 3, w = 3, c = 3, f = 32
			// T (y, 1) (8 / 8)
			for (y = y550, yp_2 = y550_p_1, yp_1 = y550_p_0, yp_0 = 0;
				y < y550 + 8;
				y += 8, yp_2 += 8, yp_1 += 8, yp_0 += 8){
				// y = 8, x = 4, h = 3, w = 3, c = 3, f = 32
				// T (x, 1) (4 / 4)
				for (x588 = x589, x588_p_1 = x589_p_0, x588_p_0 = 0;
					x588 < x589 + 4;
					x588 += 4, x588_p_1 += 4, x588_p_0 += 4){
					// y = 8, x = 4, h = 3, w = 3, c = 3, f = 32
					// T (f, 2) (32 / 16)
					for (f = f256, fp_0 = 0;
						f < f256 + 32;
						f += 16, fp_0 += 16){
						// y = 8, x = 4, h = 3, w = 3, c = 3, f = 16
						// T (w, 3) (3 / 1)
						for (w = w261, wp_0 = 0;
							w < w261 + 3;
							w += 1, wp_0 += 1){
							// y = 8, x = 4, h = 3, w = 1, c = 3, f = 16
							// T (x, 4) (4 / 1)
							for (x = x588, xp_2 = x588_p_1, xp_1 = x588_p_0, xp_0 = 0;
								x < x588 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2596 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2597 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2598 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2599 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2600 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2601 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2602 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2603 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										// y = 8, x = 1, h = 3, w = 1, c = 3, f = 16
										// T (c, 3) (3 / 1)
										for (c = c332, cp_0 = 0;
											c < c332 + 3;
											c += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2596);
											mem_vec_2596 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_2597);
											mem_vec_2597 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2598);
											mem_vec_2598 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_2599);
											mem_vec_2599 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2600);
											mem_vec_2600 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2601);
											mem_vec_2601 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);


											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_2602);
											mem_vec_2602 = vec_13;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_2603);
											mem_vec_2603 = vec_15;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_18 = _mm512_set1_ps(scal_8);
											vec_19 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_17 = _mm512_fmadd_ps(vec_18, vec_19, mem_vec_2596);
											mem_vec_2596 = vec_17;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_21 = _mm512_set1_ps(scal_9);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_19, mem_vec_2597);
											mem_vec_2597 = vec_20;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_23 = _mm512_set1_ps(scal_10);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_19, mem_vec_2598);
											mem_vec_2598 = vec_22;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_25 = _mm512_set1_ps(scal_11);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_19, mem_vec_2599);
											mem_vec_2599 = vec_24;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_27 = _mm512_set1_ps(scal_12);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_19, mem_vec_2600);
											mem_vec_2600 = vec_26;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_13);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_19, mem_vec_2601);
											mem_vec_2601 = vec_28;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);


											vec_30 = _mm512_fmadd_ps(vec_31, vec_19, mem_vec_2602);
											mem_vec_2602 = vec_30;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_19, mem_vec_2603);
											mem_vec_2603 = vec_32;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_35 = _mm512_set1_ps(scal_16);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_2596);
											mem_vec_2596 = vec_34;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_38 = _mm512_set1_ps(scal_17);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_2597);
											mem_vec_2597 = vec_37;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_40 = _mm512_set1_ps(scal_18);


											vec_39 = _mm512_fmadd_ps(vec_40, vec_36, mem_vec_2598);
											mem_vec_2598 = vec_39;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_42 = _mm512_set1_ps(scal_19);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_36, mem_vec_2599);
											mem_vec_2599 = vec_41;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_44 = _mm512_set1_ps(scal_20);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_2600);
											mem_vec_2600 = vec_43;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_46 = _mm512_set1_ps(scal_21);


											vec_45 = _mm512_fmadd_ps(vec_46, vec_36, mem_vec_2601);
											mem_vec_2601 = vec_45;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_48 = _mm512_set1_ps(scal_22);


											vec_47 = _mm512_fmadd_ps(vec_48, vec_36, mem_vec_2602);
											mem_vec_2602 = vec_47;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_50 = _mm512_set1_ps(scal_23);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_2603);
											mem_vec_2603 = vec_49;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2596);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2597);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2598);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2599);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2600);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2601);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2602);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2603);
							}
						}
					}
				}
			}
		}
	}
}


}