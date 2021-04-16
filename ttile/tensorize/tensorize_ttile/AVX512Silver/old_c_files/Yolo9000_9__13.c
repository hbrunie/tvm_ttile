#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (2, f); T (1, x); T (4, y); T (1, x);
  Lambda_apply y [((Iter 4), (Arg 3)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c63_p_0, cp_1, c63, f, fp_0, x, xp_0, x84_p_0, x85_p_0, xp_1, x84_p_1, xp_2, x84, x85, y, yp_0, y63_p_0, yp_1, y63;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y64 = 0;
IND_TYPE x86 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c64 = 0;
IND_TYPE f42 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_760 ,mem_vec_761 ,mem_vec_762 ,mem_vec_763 ,mem_vec_764 ,mem_vec_765 ,mem_vec_766 ,mem_vec_767 ,mem_vec_768 ,mem_vec_769 ,mem_vec_770 ,mem_vec_771 ,mem_vec_772 ,mem_vec_773 ,mem_vec_774 ,mem_vec_775 ,mem_vec_776 ,mem_vec_777 ,mem_vec_778 ,mem_vec_779 ,mem_vec_780 ,mem_vec_781 ,mem_vec_782 ,mem_vec_783 ,mem_vec_784 ,mem_vec_785 ,mem_vec_786 ,mem_vec_787 ,mem_vec_788 ,mem_vec_789 ,mem_vec_790 ,mem_vec_791 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y63 = y64, y63_p_0 = 0;
		y63 < y64 + 48;
		y63 += 12, y63_p_0 += 12){
		// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x85 = x86, x85_p_0 = 0;
			x85 < x86 + 68;
			x85 += 68, x85_p_0 += 68){
			// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y63, yp_1 = y63_p_0, yp_0 = 0;
				y < y63 + 12;
				y += 3, yp_1 += 3, yp_0 += 3){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x84 = x85, x84_p_1 = x85_p_0, x84_p_0 = 0;
					x84 < x85 + 68;
					x84 += 68, x84_p_1 += 68, x84_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f42, fp_0 = 0;
						f < f42 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c63 = c64, c63_p_0 = 0;
							c63 < c64 + 256;
							c63 += 256, c63_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x84, xp_2 = x84_p_1, xp_1 = x84_p_0, xp_0 = 0;
								x < x84 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_760 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_761 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_762 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_763 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c63, cp_1 = c63_p_0, cp_0 = 0;
											c < c63 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_760);
											mem_vec_760 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_761);
											mem_vec_761 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_762);
											mem_vec_762 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_763);
											mem_vec_763 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_764);
											mem_vec_764 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_765);
											mem_vec_765 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_766);
											mem_vec_766 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_767);
											mem_vec_767 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_768);
											mem_vec_768 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_769);
											mem_vec_769 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_770);
											mem_vec_770 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_771);
											mem_vec_771 = vec_18;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_760);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_761);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_762);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_763);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_764);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_765);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_766);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_767);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_768);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_769);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_770);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_771);
							}
						}
					}
				}
			}
		}
	}
	for (y63 = y64 + 48, y63_p_0 = 0;
		y63 < y64 + 48 + 20;
		y63 += 20, y63_p_0 += 20){
		// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x85 = x86, x85_p_0 = 0;
			x85 < x86 + 68;
			x85 += 68, x85_p_0 += 68){
			// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y63, yp_1 = y63_p_0, yp_0 = 0;
				y < y63 + 20;
				y += 5, yp_1 += 5, yp_0 += 5){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x84 = x85, x84_p_1 = x85_p_0, x84_p_0 = 0;
					x84 < x85 + 68;
					x84 += 68, x84_p_1 += 68, x84_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f42, fp_0 = 0;
						f < f42 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c63 = c64, c63_p_0 = 0;
							c63 < c64 + 256;
							c63 += 256, c63_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x84, xp_2 = x84_p_1, xp_1 = x84_p_0, xp_0 = 0;
								x < x84 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_772 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_773 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_774 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_775 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_785 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_788 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_789 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c63, cp_1 = c63_p_0, cp_0 = 0;
											c < c63 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_772);
											mem_vec_772 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_773);
											mem_vec_773 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_774);
											mem_vec_774 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_775);
											mem_vec_775 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_776);
											mem_vec_776 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_777);
											mem_vec_777 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_778);
											mem_vec_778 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_779);
											mem_vec_779 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_780);
											mem_vec_780 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_781);
											mem_vec_781 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_782);
											mem_vec_782 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_783);
											mem_vec_783 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_784);
											mem_vec_784 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_785);
											mem_vec_785 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_786);
											mem_vec_786 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_787);
											mem_vec_787 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_788);
											mem_vec_788 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_789);
											mem_vec_789 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_790);
											mem_vec_790 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_791);
											mem_vec_791 = vec_28;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_772);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_773);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_774);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_775);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_776);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_777);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_778);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_779);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_780);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_781);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_782);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_783);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_784);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_785);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_786);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_787);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_788);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_789);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_790);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_791);
							}
						}
					}
				}
			}
		}
	}


}