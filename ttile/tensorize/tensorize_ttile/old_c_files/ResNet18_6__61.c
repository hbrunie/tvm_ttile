#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (1, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (1, f); T (128, c); T (28, x); T (2, y); T (4, f)]
*/
IND_TYPE c, cp_0, c84_p_0, cp_1, c84, f, fp_0, f84_p_0, fp_1, f84, h, hp_0, w, wp_0, x, xp_0, x84_p_0, xp_1, x84, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y56 = 0;
IND_TYPE x85 = 0;
IND_TYPE h56 = 0;
IND_TYPE w56 = 0;
IND_TYPE c85 = 0;
IND_TYPE f85 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_784 ,mem_vec_785 ,mem_vec_786 ,mem_vec_787 ,mem_vec_788 ,mem_vec_789 ,mem_vec_790 ,mem_vec_791 ,mem_vec_792 ,mem_vec_793 ,mem_vec_794 ,mem_vec_795 ,mem_vec_796 ,mem_vec_797 ,mem_vec_798 ,mem_vec_799 ,mem_vec_800 ,mem_vec_801 ,mem_vec_802 ,mem_vec_803 ,mem_vec_804 ,mem_vec_805 ,mem_vec_806 ,mem_vec_807 ,mem_vec_808 ,mem_vec_809 ,mem_vec_810 ,mem_vec_811 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 4) (128 / 32)
for (f84 = f85, f84_p_0 = 0;
	f84 < f85 + 128;
	f84 += 32, f84_p_0 += 32){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 32
	// T (y, 2) (28 / 14)
	for (y = y56, yp_0 = 0;
		y < y56 + 28;
		y += 14, yp_0 += 14){
		// y = 14, x = 28, h = 3, w = 3, c = 128, f = 32
		// T (x, 28) (28 / 1)
		for (x84 = x85, x84_p_0 = 0;
			x84 < x85 + 28;
			x84 += 1, x84_p_0 += 1){
			// y = 14, x = 1, h = 3, w = 3, c = 128, f = 32
			// T (c, 128) (128 / 1)
			for (c84 = c85, c84_p_0 = 0;
				c84 < c85 + 128;
				c84 += 1, c84_p_0 += 1){
				// y = 14, x = 1, h = 3, w = 3, c = 1, f = 32
				// T (f, 1) (32 / 32)
				for (f = f84, fp_1 = f84_p_0, fp_0 = 0;
					f < f84 + 32;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = 14, x = 1, h = 3, w = 3, c = 1, f = 32
					// T (h, 3) (3 / 1)
					for (h = h56, hp_0 = 0;
						h < h56 + 3;
						h += 1, hp_0 += 1){
						// y = 14, x = 1, h = 1, w = 3, c = 1, f = 32
						// T (w, 3) (3 / 1)
						for (w = w56, wp_0 = 0;
							w < w56 + 3;
							w += 1, wp_0 += 1){
							// y = 14, x = 1, h = 1, w = 1, c = 1, f = 32
							// T (x, 1) (1 / 1)
							for (x = x84, xp_1 = x84_p_0, xp_0 = 0;
								x < x84 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_784 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_785 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_788 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_789 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 1, f = 32
										// T (c, 1) (1 / 1)
										for (c = c84, cp_1 = c84_p_0, cp_0 = 0;
											c < c84 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_784);
											mem_vec_784 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_785);
											mem_vec_785 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_786);
											mem_vec_786 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_787);
											mem_vec_787 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_788);
											mem_vec_788 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_789);
											mem_vec_789 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_790);
											mem_vec_790 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_791);
											mem_vec_791 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_792);
											mem_vec_792 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_793);
											mem_vec_793 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_794);
											mem_vec_794 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_795);
											mem_vec_795 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_796);
											mem_vec_796 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_797);
											mem_vec_797 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_798);
											mem_vec_798 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_799);
											mem_vec_799 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_800);
											mem_vec_800 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_801);
											mem_vec_801 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_802);
											mem_vec_802 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_803);
											mem_vec_803 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_804);
											mem_vec_804 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_805);
											mem_vec_805 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_806);
											mem_vec_806 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_807);
											mem_vec_807 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_808);
											mem_vec_808 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_809);
											mem_vec_809 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_810);
											mem_vec_810 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_811);
											mem_vec_811 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_784);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_785);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_786);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_787);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_788);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_789);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_790);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_791);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_792);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_793);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_794);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_795);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_796);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_797);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_798);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_799);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_800);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_801);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_802);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_803);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_804);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_805);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_806);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_807);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_808);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_809);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_810);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_811);
							}
						}
					}
				}
			}
		}
	}
}


}