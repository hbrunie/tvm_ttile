#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (3, c); Hoist_vars [c]; T (136, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 13), (Arg 7)); ((Iter 3), (Arg 15))];
  T (1, x); T (4, y); T (4, x)]
*/
IND_TYPE c, cp_0, h, hp_0, w, wp_0, x, xp_0, x218_p_0, x219_p_0, xp_1, x218_p_1, xp_2, x218, x219, y, yp_0, y174_p_0, yp_1, y174;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y175 = 0;
IND_TYPE x220 = 0;
IND_TYPE h92 = 0;
IND_TYPE w78 = 0;
IND_TYPE c112 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_828 ,mem_vec_829 ,mem_vec_830 ,mem_vec_831 ,mem_vec_832 ,mem_vec_833 ,mem_vec_834 ,mem_vec_835 ,mem_vec_836 ,mem_vec_837 ,mem_vec_838 ,mem_vec_839 ,mem_vec_840 ,mem_vec_841 ,mem_vec_842 ,mem_vec_843 ,mem_vec_844 ,mem_vec_845 ,mem_vec_846 ,mem_vec_847 ,mem_vec_848 ,mem_vec_849 ,mem_vec_850 ,mem_vec_851 ,mem_vec_852 ,mem_vec_853 ,mem_vec_854 ,mem_vec_855 ,mem_vec_856 ,mem_vec_857 ,mem_vec_858 ,mem_vec_859 ,mem_vec_860 ,mem_vec_861 ,mem_vec_862 ,mem_vec_863 ,mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,mem_vec_868 ,mem_vec_869 ,mem_vec_870 ,mem_vec_871 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (x, 4) (544 / 136)
for (x219 = x220, x219_p_0 = 0;
	x219 < x220 + 544;
	x219 += 136, x219_p_0 += 136){
	// y = 544, x = 136, h = 3, w = 3, c = 3, f = 32
	// T (y, 4) (544 / 136)
	for (y174 = y175, y174_p_0 = 0;
		y174 < y175 + 544;
		y174 += 136, y174_p_0 += 136){
		// y = 136, x = 136, h = 3, w = 3, c = 3, f = 32
		// T (x, 1) (136 / 136)
		for (x218 = x219, x218_p_1 = x219_p_0, x218_p_0 = 0;
			x218 < x219 + 136;
			x218 += 136, x218_p_1 += 136, x218_p_0 += 136){
				for (y = y174, yp_1 = y174_p_0, yp_0 = 0;
					y < y174 + 91;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 136, h = 3, w = 3, c = 3, f = 32
					// T (h, 3) (3 / 1)
					for (h = h92, hp_0 = 0;
						h < h92 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 136, h = 1, w = 3, c = 3, f = 32
						// T (w, 3) (3 / 1)
						for (w = w78, wp_0 = 0;
							w < w78 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 136, h = 1, w = 1, c = 3, f = 32
							// T (x, 136) (136 / 1)
							for (x = x218, xp_2 = x218_p_1, xp_1 = x218_p_0, xp_0 = 0;
								x < x218 + 136;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_828 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_829 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c112, cp_0 = 0;
											c < c112 + 3;
											c += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_828);
											mem_vec_828 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_829);
											mem_vec_829 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_830);
											mem_vec_830 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_831);
											mem_vec_831 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_832);
											mem_vec_832 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_833);
											mem_vec_833 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_834);
											mem_vec_834 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_835);
											mem_vec_835 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_836);
											mem_vec_836 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_837);
											mem_vec_837 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_838);
											mem_vec_838 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_839);
											mem_vec_839 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_840);
											mem_vec_840 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_841);
											mem_vec_841 = vec_22;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_828);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_829);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_830);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_831);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_832);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_833);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_834);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_835);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_836);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_837);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_838);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_839);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_840);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_841);
							}
						}
					}
				}
				for (y = y174 + 91, yp_1 = y174_p_0, yp_0 = 0;
					y < y174 + 91 + 45;
					y += 15, yp_1 += 15, yp_0 += 15){
					// y = ph_y, x = 136, h = 3, w = 3, c = 3, f = 32
					// T (h, 3) (3 / 1)
					for (h = h92, hp_0 = 0;
						h < h92 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 136, h = 1, w = 3, c = 3, f = 32
						// T (w, 3) (3 / 1)
						for (w = w78, wp_0 = 0;
							w < w78 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 136, h = 1, w = 1, c = 3, f = 32
							// T (x, 136) (136 / 1)
							for (x = x218, xp_2 = x218_p_1, xp_1 = x218_p_0, xp_0 = 0;
								x < x218 + 136;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_842 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_843 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										mem_vec_870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
										mem_vec_871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c112, cp_0 = 0;
											c < c112 + 3;
											c += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_842);
											mem_vec_842 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_843);
											mem_vec_843 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_844);
											mem_vec_844 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_845);
											mem_vec_845 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_846);
											mem_vec_846 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_847);
											mem_vec_847 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_848);
											mem_vec_848 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_849);
											mem_vec_849 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_850);
											mem_vec_850 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_851);
											mem_vec_851 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_852);
											mem_vec_852 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_853);
											mem_vec_853 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_854);
											mem_vec_854 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_855);
											mem_vec_855 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_856);
											mem_vec_856 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_857);
											mem_vec_857 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_858);
											mem_vec_858 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_859);
											mem_vec_859 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_860);
											mem_vec_860 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_861);
											mem_vec_861 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_862);
											mem_vec_862 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_863);
											mem_vec_863 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_864);
											mem_vec_864 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_865);
											mem_vec_865 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_866);
											mem_vec_866 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_867);
											mem_vec_867 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_868);
											mem_vec_868 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_869);
											mem_vec_869 = vec_43;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
											vec_45 = _mm512_set1_ps(scal_14);


											vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_870);
											mem_vec_870 = vec_44;



											vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_871);
											mem_vec_871 = vec_46;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_842);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_843);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_844);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_845);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_846);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_847);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_848);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_849);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_850);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_851);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_852);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_853);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_854);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_855);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_856);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_857);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_858);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_859);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_860);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_861);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_862);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_863);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_864);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_865);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_866);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_867);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_868);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_869);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_870);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_871);
							}
						}
					}
				}
		}
	}
}


}