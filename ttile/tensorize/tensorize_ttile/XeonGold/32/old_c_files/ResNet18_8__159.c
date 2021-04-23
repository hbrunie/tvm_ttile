#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (28, x);
  T (3, h); T (2, c); T (2, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (2, f)]
*/
IND_TYPE c, cp_0, c315_p_0, cp_1, c315, f, fp_0, f315_p_0, fp_1, f315, h, hp_0, x, xp_0, x295_p_0, xp_1, x295, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y210 = 0;
IND_TYPE x296 = 0;
IND_TYPE h178 = 0;
IND_TYPE w = 0;
IND_TYPE c316 = 0;
IND_TYPE f316 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2792 ,mem_vec_2793 ,mem_vec_2794 ,mem_vec_2795 ,mem_vec_2796 ,mem_vec_2797 ,mem_vec_2798 ,mem_vec_2799 ,mem_vec_2800 ,mem_vec_2801 ,mem_vec_2802 ,mem_vec_2803 ,mem_vec_2804 ,mem_vec_2805 ,mem_vec_2806 ,mem_vec_2807 ,mem_vec_2808 ,mem_vec_2809 ,mem_vec_2810 ,mem_vec_2811 ,mem_vec_2812 ,mem_vec_2813 ,mem_vec_2814 ,mem_vec_2815 ,mem_vec_2816 ,mem_vec_2817 ,mem_vec_2818 ,mem_vec_2819 ,mem_vec_2820 ,mem_vec_2821 ,mem_vec_2822 ,mem_vec_2823 ,mem_vec_2824 ,mem_vec_2825 ,mem_vec_2826 ,mem_vec_2827 ,mem_vec_2828 ,mem_vec_2829 ,mem_vec_2830 ,mem_vec_2831 ,mem_vec_2832 ,mem_vec_2833 ,mem_vec_2834 ,mem_vec_2835 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f315 = f316, f315_p_0 = 0;
	f315 < f316 + 256;
	f315 += 128, f315_p_0 += 128){
		for (y = y210, yp_0 = 0;
			y < y210 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 1) (28 / 28)
			for (x295 = x296, x295_p_0 = 0;
				x295 < x296 + 28;
				x295 += 28, x295_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
				// T (f, 2) (128 / 64)
				for (f = f315, fp_1 = f315_p_0, fp_0 = 0;
					f < f315 + 128;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
					// T (c, 2) (128 / 64)
					for (c315 = c316, c315_p_0 = 0;
						c315 < c316 + 128;
						c315 += 64, c315_p_0 += 64){
						// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 64
						// T (h, 3) (3 / 1)
						for (h = h178, hp_0 = 0;
							h < h178 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 64, f = 64
							// T (x, 28) (28 / 1)
							for (x = x295, xp_1 = x295_p_0, xp_0 = 0;
								x < x295 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2792 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2793 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2794 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_2795 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_2796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_2799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_2800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_2803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_2804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_2807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_2808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_2811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c315, cp_1 = c315_p_0, cp_0 = 0;
											c < c315 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2792);
											mem_vec_2792 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2793);
											mem_vec_2793 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2794);
											mem_vec_2794 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2795);
											mem_vec_2795 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2796);
											mem_vec_2796 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2797);
											mem_vec_2797 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2798);
											mem_vec_2798 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2799);
											mem_vec_2799 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2800);
											mem_vec_2800 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2801);
											mem_vec_2801 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2802);
											mem_vec_2802 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2803);
											mem_vec_2803 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2804);
											mem_vec_2804 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2805);
											mem_vec_2805 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2806);
											mem_vec_2806 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2807);
											mem_vec_2807 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2808);
											mem_vec_2808 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2809);
											mem_vec_2809 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2810);
											mem_vec_2810 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2811);
											mem_vec_2811 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_2792);
											mem_vec_2792 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_2793);
											mem_vec_2793 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_2794);
											mem_vec_2794 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_2795);
											mem_vec_2795 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_2796);
											mem_vec_2796 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_2797);
											mem_vec_2797 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_2798);
											mem_vec_2798 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_2799);
											mem_vec_2799 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_2800);
											mem_vec_2800 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_2801);
											mem_vec_2801 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_2802);
											mem_vec_2802 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_2803);
											mem_vec_2803 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_2804);
											mem_vec_2804 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_2805);
											mem_vec_2805 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_2806);
											mem_vec_2806 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_2807);
											mem_vec_2807 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_2808);
											mem_vec_2808 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_2809);
											mem_vec_2809 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_2810);
											mem_vec_2810 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_2811);
											mem_vec_2811 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_2792);
											mem_vec_2792 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_2793);
											mem_vec_2793 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_2794);
											mem_vec_2794 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_2795);
											mem_vec_2795 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_2796);
											mem_vec_2796 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_2797);
											mem_vec_2797 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_2798);
											mem_vec_2798 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_2799);
											mem_vec_2799 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_2800);
											mem_vec_2800 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_2801);
											mem_vec_2801 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_2802);
											mem_vec_2802 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_2803);
											mem_vec_2803 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_2804);
											mem_vec_2804 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_2805);
											mem_vec_2805 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_2806);
											mem_vec_2806 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_2807);
											mem_vec_2807 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_2808);
											mem_vec_2808 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_2809);
											mem_vec_2809 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_2810);
											mem_vec_2810 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_2811);
											mem_vec_2811 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2792);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2793);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2794);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2795);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2796);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2797);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2798);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2799);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2800);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2801);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2802);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2803);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2804);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2805);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2806);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2807);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2808);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2809);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2810);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2811);
							}
						}
					}
				}
			}
		}
		for (y = y210 + 10, yp_0 = 0;
			y < y210 + 10 + 18;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 1) (28 / 28)
			for (x295 = x296, x295_p_0 = 0;
				x295 < x296 + 28;
				x295 += 28, x295_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
				// T (f, 2) (128 / 64)
				for (f = f315, fp_1 = f315_p_0, fp_0 = 0;
					f < f315 + 128;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
					// T (c, 2) (128 / 64)
					for (c315 = c316, c315_p_0 = 0;
						c315 < c316 + 128;
						c315 += 64, c315_p_0 += 64){
						// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 64
						// T (h, 3) (3 / 1)
						for (h = h178, hp_0 = 0;
							h < h178 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 64, f = 64
							// T (x, 28) (28 / 1)
							for (x = x295, xp_1 = x295_p_0, xp_0 = 0;
								x < x295 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2812 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2813 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2814 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_2815 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_2816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_2819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_2820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_2823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_2824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_2827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_2828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_2831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_2832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_2835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c315, cp_1 = c315_p_0, cp_0 = 0;
											c < c315 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2812);
											mem_vec_2812 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2813);
											mem_vec_2813 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2814);
											mem_vec_2814 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2815);
											mem_vec_2815 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2816);
											mem_vec_2816 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2817);
											mem_vec_2817 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2818);
											mem_vec_2818 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2819);
											mem_vec_2819 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2820);
											mem_vec_2820 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2821);
											mem_vec_2821 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2822);
											mem_vec_2822 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2823);
											mem_vec_2823 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2824);
											mem_vec_2824 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2825);
											mem_vec_2825 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2826);
											mem_vec_2826 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2827);
											mem_vec_2827 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2828);
											mem_vec_2828 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2829);
											mem_vec_2829 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2830);
											mem_vec_2830 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2831);
											mem_vec_2831 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2832);
											mem_vec_2832 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2833);
											mem_vec_2833 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2834);
											mem_vec_2834 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2835);
											mem_vec_2835 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_2812);
											mem_vec_2812 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_2813);
											mem_vec_2813 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_2814);
											mem_vec_2814 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_2815);
											mem_vec_2815 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_2816);
											mem_vec_2816 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_2817);
											mem_vec_2817 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_2818);
											mem_vec_2818 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_2819);
											mem_vec_2819 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_2820);
											mem_vec_2820 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_2821);
											mem_vec_2821 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_2822);
											mem_vec_2822 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_2823);
											mem_vec_2823 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_2824);
											mem_vec_2824 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_2825);
											mem_vec_2825 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_2826);
											mem_vec_2826 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_2827);
											mem_vec_2827 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_2828);
											mem_vec_2828 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_2829);
											mem_vec_2829 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_2830);
											mem_vec_2830 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_2831);
											mem_vec_2831 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_2832);
											mem_vec_2832 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_2833);
											mem_vec_2833 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_2834);
											mem_vec_2834 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_2835);
											mem_vec_2835 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_2812);
											mem_vec_2812 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_2813);
											mem_vec_2813 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_2814);
											mem_vec_2814 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_2815);
											mem_vec_2815 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_2816);
											mem_vec_2816 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_2817);
											mem_vec_2817 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_2818);
											mem_vec_2818 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_2819);
											mem_vec_2819 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_2820);
											mem_vec_2820 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_2821);
											mem_vec_2821 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_2822);
											mem_vec_2822 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_2823);
											mem_vec_2823 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_2824);
											mem_vec_2824 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_2825);
											mem_vec_2825 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_2826);
											mem_vec_2826 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_2827);
											mem_vec_2827 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_2828);
											mem_vec_2828 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_2829);
											mem_vec_2829 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_2830);
											mem_vec_2830 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_2831);
											mem_vec_2831 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_2832);
											mem_vec_2832 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_2833);
											mem_vec_2833 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_2834);
											mem_vec_2834 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_2835);
											mem_vec_2835 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2812);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2813);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2814);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2815);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2816);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2817);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2818);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2819);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2820);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2821);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2822);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2823);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2824);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2825);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2826);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2827);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2828);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2829);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2830);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2831);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2832);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2833);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_2834);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_2835);
							}
						}
					}
				}
			}
		}
}


}