#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (8, x);
  Lambda_apply y [((Iter 7), (Arg 12)); ((Iter 2), (Arg 14))]; T (16, c);
  T (7, x)]
*/
IND_TYPE c, cp_0, c768_p_0, cp_1, c768, h, hp_0, w, wp_0, x, xp_0, x1024_p_0, x1025_p_0, xp_1, x1024_p_1, xp_2, x1024, x1025, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y512 = 0;
IND_TYPE x1026 = 0;
IND_TYPE h492 = 0;
IND_TYPE w512 = 0;
IND_TYPE c769 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9836 ,mem_vec_9837 ,mem_vec_9838 ,mem_vec_9839 ,mem_vec_9840 ,mem_vec_9841 ,mem_vec_9842 ,mem_vec_9843 ,mem_vec_9844 ,mem_vec_9845 ,mem_vec_9846 ,mem_vec_9847 ,mem_vec_9848 ,mem_vec_9849 ,mem_vec_9850 ,mem_vec_9851 ,mem_vec_9852 ,mem_vec_9853 ,mem_vec_9854 ,mem_vec_9855 ,mem_vec_9856 ,mem_vec_9857 ,mem_vec_9858 ,mem_vec_9859 ,mem_vec_9860 ,mem_vec_9861 ,mem_vec_9862 ,mem_vec_9863 ,mem_vec_9864 ,mem_vec_9865 ,mem_vec_9866 ,mem_vec_9867 ,mem_vec_9868 ,mem_vec_9869 ,mem_vec_9870 ,mem_vec_9871 ,mem_vec_9872 ,mem_vec_9873 ,mem_vec_9874 ,mem_vec_9875 ,mem_vec_9876 ,mem_vec_9877 ,mem_vec_9878 ,mem_vec_9879 ,mem_vec_9880 ,mem_vec_9881 ,mem_vec_9882 ,mem_vec_9883 ,mem_vec_9884 ,mem_vec_9885 ,mem_vec_9886 ,mem_vec_9887 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 7) (112 / 16)
for (x1025 = x1026, x1025_p_0 = 0;
	x1025 < x1026 + 112;
	x1025 += 16, x1025_p_0 += 16){
	// y = 112, x = 16, h = 3, w = 3, c = 32, f = 32
	// T (c, 16) (32 / 2)
	for (c768 = c769, c768_p_0 = 0;
		c768 < c769 + 32;
		c768 += 2, c768_p_0 += 2){
			for (y = y512, yp_0 = 0;
				y < y512 + 84;
				y += 12, yp_0 += 12){
				// y = ph_y, x = 16, h = 3, w = 3, c = 2, f = 32
				// T (x, 8) (16 / 2)
				for (x1024 = x1025, x1024_p_1 = x1025_p_0, x1024_p_0 = 0;
					x1024 < x1025 + 16;
					x1024 += 2, x1024_p_1 += 2, x1024_p_0 += 2){
					// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 32
					// T (h, 3) (3 / 1)
					for (h = h492, hp_0 = 0;
						h < h492 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 2, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w512, wp_0 = 0;
							w < w512 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 1, c = 2, f = 32
							// T (x, 2) (2 / 1)
							for (x = x1024, xp_2 = x1024_p_1, xp_1 = x1024_p_0, xp_0 = 0;
								x < x1024 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9836 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9837 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_9850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_9852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_9854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_9855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_9856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_9857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_9858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_9859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c768, cp_1 = c768_p_0, cp_0 = 0;
											c < c768 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9836);
											mem_vec_9836 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9837);
											mem_vec_9837 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9838);
											mem_vec_9838 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9839);
											mem_vec_9839 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9840);
											mem_vec_9840 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9841);
											mem_vec_9841 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9842);
											mem_vec_9842 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9843);
											mem_vec_9843 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9844);
											mem_vec_9844 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9845);
											mem_vec_9845 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9846);
											mem_vec_9846 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9847);
											mem_vec_9847 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9848);
											mem_vec_9848 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9849);
											mem_vec_9849 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9850);
											mem_vec_9850 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9851);
											mem_vec_9851 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9852);
											mem_vec_9852 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9853);
											mem_vec_9853 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9854);
											mem_vec_9854 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9855);
											mem_vec_9855 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9856);
											mem_vec_9856 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9857);
											mem_vec_9857 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9858);
											mem_vec_9858 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9859);
											mem_vec_9859 = vec_37;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9836);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9837);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9838);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9839);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9840);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9841);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9842);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9843);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9844);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9845);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9846);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9847);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9848);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9849);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9850);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9851);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9852);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9853);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9854);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9855);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9856);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9857);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9858);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9859);
							}
						}
					}
				}
			}
			for (y = y512 + 84, yp_0 = 0;
				y < y512 + 84 + 28;
				y += 14, yp_0 += 14){
				// y = ph_y, x = 16, h = 3, w = 3, c = 2, f = 32
				// T (x, 8) (16 / 2)
				for (x1024 = x1025, x1024_p_1 = x1025_p_0, x1024_p_0 = 0;
					x1024 < x1025 + 16;
					x1024 += 2, x1024_p_1 += 2, x1024_p_0 += 2){
					// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 32
					// T (h, 3) (3 / 1)
					for (h = h492, hp_0 = 0;
						h < h492 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 2, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w512, wp_0 = 0;
							w < w512 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 1, c = 2, f = 32
							// T (x, 2) (2 / 1)
							for (x = x1024, xp_2 = x1024_p_1, xp_1 = x1024_p_0, xp_0 = 0;
								x < x1024 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9860 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9861 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_9874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_9876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_9878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_9879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_9880 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_9881 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_9882 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_9883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_9884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_9885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_9886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_9887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c768, cp_1 = c768_p_0, cp_0 = 0;
											c < c768 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9860);
											mem_vec_9860 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9861);
											mem_vec_9861 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9862);
											mem_vec_9862 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9863);
											mem_vec_9863 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9864);
											mem_vec_9864 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9865);
											mem_vec_9865 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9866);
											mem_vec_9866 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9867);
											mem_vec_9867 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9868);
											mem_vec_9868 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9869);
											mem_vec_9869 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9870);
											mem_vec_9870 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9871);
											mem_vec_9871 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9872);
											mem_vec_9872 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9873);
											mem_vec_9873 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9874);
											mem_vec_9874 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9875);
											mem_vec_9875 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9876);
											mem_vec_9876 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9877);
											mem_vec_9877 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9878);
											mem_vec_9878 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9879);
											mem_vec_9879 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9880);
											mem_vec_9880 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9881);
											mem_vec_9881 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9882);
											mem_vec_9882 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9883);
											mem_vec_9883 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_9884);
											mem_vec_9884 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_9885);
											mem_vec_9885 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_9886);
											mem_vec_9886 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_9887);
											mem_vec_9887 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9860);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9861);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9862);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9863);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9864);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9865);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9866);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9867);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9868);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9869);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9870);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9871);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9872);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9873);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9874);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9875);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9876);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9877);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9878);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9879);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9880);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9881);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9882);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9883);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_9884);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_9885);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_9886);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_9887);
							}
						}
					}
				}
			}
	}
}


}