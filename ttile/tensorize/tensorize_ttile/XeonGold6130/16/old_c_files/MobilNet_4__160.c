#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, h); T (14, x);
  T (3, w); T (4, c); T (2, f); T (2, x); T (4, y); T (1, f)]
*/
IND_TYPE c, cp_0, c105_p_0, cp_1, c105, f, fp_0, f105_p_0, fp_1, f105, h, hp_0, w, wp_0, x, xp_0, x93_p_0, xp_1, x93, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y70 = 0;
IND_TYPE x94 = 0;
IND_TYPE h56 = 0;
IND_TYPE w60 = 0;
IND_TYPE c106 = 0;
IND_TYPE f106 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_764 ,mem_vec_765 ,mem_vec_766 ,mem_vec_767 ,mem_vec_768 ,mem_vec_769 ,mem_vec_770 ,mem_vec_771 ,mem_vec_772 ,mem_vec_773 ,mem_vec_774 ,mem_vec_775 ,mem_vec_776 ,mem_vec_777 ,mem_vec_778 ,mem_vec_779 ,mem_vec_780 ,mem_vec_781 ,mem_vec_782 ,mem_vec_783 ,mem_vec_784 ,mem_vec_785 ,mem_vec_786 ,mem_vec_787 ,mem_vec_788 ,mem_vec_789 ,mem_vec_790 ,mem_vec_791 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
for (f105 = f106, f105_p_0 = 0;
	f105 < f106 + 128;
	f105 += 128, f105_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (y, 4) (28 / 7)
	for (y = y70, yp_0 = 0;
		y < y70 + 28;
		y += 7, yp_0 += 7){
		// y = 7, x = 28, h = 3, w = 3, c = 128, f = 128
		// T (x, 2) (28 / 14)
		for (x93 = x94, x93_p_0 = 0;
			x93 < x94 + 28;
			x93 += 14, x93_p_0 += 14){
			// y = 7, x = 14, h = 3, w = 3, c = 128, f = 128
			// T (f, 2) (128 / 64)
			for (f = f105, fp_1 = f105_p_0, fp_0 = 0;
				f < f105 + 128;
				f += 64, fp_1 += 64, fp_0 += 64){
				// y = 7, x = 14, h = 3, w = 3, c = 128, f = 64
				// T (c, 4) (128 / 32)
				for (c105 = c106, c105_p_0 = 0;
					c105 < c106 + 128;
					c105 += 32, c105_p_0 += 32){
					// y = 7, x = 14, h = 3, w = 3, c = 32, f = 64
					// T (w, 3) (3 / 1)
					for (w = w60, wp_0 = 0;
						w < w60 + 3;
						w += 1, wp_0 += 1){
						// y = 7, x = 14, h = 3, w = 1, c = 32, f = 64
						// T (x, 14) (14 / 1)
						for (x = x93, xp_1 = x93_p_0, xp_0 = 0;
							x < x93 + 14;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = 7, x = 1, h = 3, w = 1, c = 32, f = 64
							// T (h, 3) (3 / 1)
							for (h = h56, hp_0 = 0;
								h < h56 + 3;
								h += 1, hp_0 += 1){
										mem_vec_764 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_765 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_766 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_767 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_785 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_788 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_789 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c105, cp_1 = c105_p_0, cp_0 = 0;
											c < c105 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_764);
											mem_vec_764 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_765);
											mem_vec_765 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_766);
											mem_vec_766 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_767);
											mem_vec_767 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_768);
											mem_vec_768 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_769);
											mem_vec_769 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_770);
											mem_vec_770 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_771);
											mem_vec_771 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_772);
											mem_vec_772 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_773);
											mem_vec_773 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_774);
											mem_vec_774 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_775);
											mem_vec_775 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_776);
											mem_vec_776 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_777);
											mem_vec_777 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_778);
											mem_vec_778 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_779);
											mem_vec_779 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_780);
											mem_vec_780 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_781);
											mem_vec_781 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_782);
											mem_vec_782 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_783);
											mem_vec_783 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_784);
											mem_vec_784 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_785);
											mem_vec_785 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_786);
											mem_vec_786 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_787);
											mem_vec_787 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_788);
											mem_vec_788 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_789);
											mem_vec_789 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_790);
											mem_vec_790 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_791);
											mem_vec_791 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_764);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_765);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_766);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_767);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_768);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_769);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_770);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_771);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_772);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_773);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_774);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_775);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_776);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_777);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_778);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_779);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_780);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_781);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_782);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_783);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_784);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_785);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_786);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_787);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_788);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_789);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_790);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_791);
							}
						}
					}
				}
			}
		}
	}
}


}