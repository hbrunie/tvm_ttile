#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (7, x);
  Lambda_apply y [((Iter 5), (Arg 12)); ((Iter 4), (Arg 13))]; T (8, c);
  T (4, x)]
*/
IND_TYPE c, cp_0, c708_p_0, cp_1, c708, h, hp_0, w, wp_0, x, xp_0, x944_p_0, x945_p_0, xp_1, x944_p_1, xp_2, x944, x945, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y472 = 0;
IND_TYPE x946 = 0;
IND_TYPE h452 = 0;
IND_TYPE w472 = 0;
IND_TYPE c709 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8812 ,mem_vec_8813 ,mem_vec_8814 ,mem_vec_8815 ,mem_vec_8816 ,mem_vec_8817 ,mem_vec_8818 ,mem_vec_8819 ,mem_vec_8820 ,mem_vec_8821 ,mem_vec_8822 ,mem_vec_8823 ,mem_vec_8824 ,mem_vec_8825 ,mem_vec_8826 ,mem_vec_8827 ,mem_vec_8828 ,mem_vec_8829 ,mem_vec_8830 ,mem_vec_8831 ,mem_vec_8832 ,mem_vec_8833 ,mem_vec_8834 ,mem_vec_8835 ,mem_vec_8836 ,mem_vec_8837 ,mem_vec_8838 ,mem_vec_8839 ,mem_vec_8840 ,mem_vec_8841 ,mem_vec_8842 ,mem_vec_8843 ,mem_vec_8844 ,mem_vec_8845 ,mem_vec_8846 ,mem_vec_8847 ,mem_vec_8848 ,mem_vec_8849 ,mem_vec_8850 ,mem_vec_8851 ,mem_vec_8852 ,mem_vec_8853 ,mem_vec_8854 ,mem_vec_8855 ,mem_vec_8856 ,mem_vec_8857 ,mem_vec_8858 ,mem_vec_8859 ,mem_vec_8860 ,mem_vec_8861 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 4) (112 / 28)
for (x945 = x946, x945_p_0 = 0;
	x945 < x946 + 112;
	x945 += 28, x945_p_0 += 28){
	// y = 112, x = 28, h = 3, w = 3, c = 32, f = 32
	// T (c, 8) (32 / 4)
	for (c708 = c709, c708_p_0 = 0;
		c708 < c709 + 32;
		c708 += 4, c708_p_0 += 4){
			for (y = y472, yp_0 = 0;
				y < y472 + 60;
				y += 12, yp_0 += 12){
				// y = ph_y, x = 28, h = 3, w = 3, c = 4, f = 32
				// T (x, 7) (28 / 4)
				for (x944 = x945, x944_p_1 = x945_p_0, x944_p_0 = 0;
					x944 < x945 + 28;
					x944 += 4, x944_p_1 += 4, x944_p_0 += 4){
					// y = ph_y, x = 4, h = 3, w = 3, c = 4, f = 32
					// T (h, 3) (3 / 1)
					for (h = h452, hp_0 = 0;
						h < h452 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 4, h = 1, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w472, wp_0 = 0;
							w < w472 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 1, c = 4, f = 32
							// T (x, 4) (4 / 1)
							for (x = x944, xp_2 = x944_p_1, xp_1 = x944_p_0, xp_0 = 0;
								x < x944 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8812 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8813 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_8824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_8826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_8828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_8830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_8832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_8833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_8834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_8835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c708, cp_1 = c708_p_0, cp_0 = 0;
											c < c708 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8812);
											mem_vec_8812 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8813);
											mem_vec_8813 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8814);
											mem_vec_8814 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8815);
											mem_vec_8815 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8816);
											mem_vec_8816 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8817);
											mem_vec_8817 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8818);
											mem_vec_8818 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8819);
											mem_vec_8819 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8820);
											mem_vec_8820 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8821);
											mem_vec_8821 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8822);
											mem_vec_8822 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8823);
											mem_vec_8823 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8824);
											mem_vec_8824 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8825);
											mem_vec_8825 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8826);
											mem_vec_8826 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8827);
											mem_vec_8827 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8828);
											mem_vec_8828 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8829);
											mem_vec_8829 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8830);
											mem_vec_8830 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8831);
											mem_vec_8831 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8832);
											mem_vec_8832 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8833);
											mem_vec_8833 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8834);
											mem_vec_8834 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8835);
											mem_vec_8835 = vec_37;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8812);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8813);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8814);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8815);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8816);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8817);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8818);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8819);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8820);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8821);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8822);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8823);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8824);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8825);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8826);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8827);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8828);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8829);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8830);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8831);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8832);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8833);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8834);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8835);
							}
						}
					}
				}
			}
			for (y = y472 + 60, yp_0 = 0;
				y < y472 + 60 + 52;
				y += 13, yp_0 += 13){
				// y = ph_y, x = 28, h = 3, w = 3, c = 4, f = 32
				// T (x, 7) (28 / 4)
				for (x944 = x945, x944_p_1 = x945_p_0, x944_p_0 = 0;
					x944 < x945 + 28;
					x944 += 4, x944_p_1 += 4, x944_p_0 += 4){
					// y = ph_y, x = 4, h = 3, w = 3, c = 4, f = 32
					// T (h, 3) (3 / 1)
					for (h = h452, hp_0 = 0;
						h < h452 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 4, h = 1, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w472, wp_0 = 0;
							w < w472 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 1, c = 4, f = 32
							// T (x, 4) (4 / 1)
							for (x = x944, xp_2 = x944_p_1, xp_1 = x944_p_0, xp_0 = 0;
								x < x944 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8836 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8837 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_8848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_8850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_8852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_8854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_8856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_8857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_8858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_8859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_8860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_8861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c708, cp_1 = c708_p_0, cp_0 = 0;
											c < c708 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8836);
											mem_vec_8836 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8837);
											mem_vec_8837 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8838);
											mem_vec_8838 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8839);
											mem_vec_8839 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8840);
											mem_vec_8840 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8841);
											mem_vec_8841 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8842);
											mem_vec_8842 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8843);
											mem_vec_8843 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8844);
											mem_vec_8844 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8845);
											mem_vec_8845 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8846);
											mem_vec_8846 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8847);
											mem_vec_8847 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8848);
											mem_vec_8848 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8849);
											mem_vec_8849 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8850);
											mem_vec_8850 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8851);
											mem_vec_8851 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8852);
											mem_vec_8852 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8853);
											mem_vec_8853 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8854);
											mem_vec_8854 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8855);
											mem_vec_8855 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8856);
											mem_vec_8856 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8857);
											mem_vec_8857 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8858);
											mem_vec_8858 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8859);
											mem_vec_8859 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8860);
											mem_vec_8860 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8861);
											mem_vec_8861 = vec_40;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8836);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8837);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8838);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8839);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8840);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8841);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8842);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8843);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8844);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8845);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8846);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8847);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8848);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8849);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8850);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8851);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8852);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8853);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8854);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8855);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8856);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8857);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8858);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8859);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_8860);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_8861);
							}
						}
					}
				}
			}
	}
}


}