#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (34, x);
  T (3, w); T (4, c); T (2, f); T (4, x); T (4, y);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]]
*/
IND_TYPE c, cp_0, c171_p_0, cp_1, c171, f, fp_0, w, wp_0, x, xp_0, x227_p_0, xp_1, x227, y, yp_0, y115_p_0, yp_1, y115;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y116 = 0;
IND_TYPE x228 = 0;
IND_TYPE h = 0;
IND_TYPE w74 = 0;
IND_TYPE c172 = 0;
IND_TYPE f114 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2726 ,mem_vec_2727 ,mem_vec_2728 ,mem_vec_2729 ,mem_vec_2730 ,mem_vec_2731 ,mem_vec_2732 ,mem_vec_2733 ,mem_vec_2734 ,mem_vec_2735 ,mem_vec_2736 ,mem_vec_2737 ,mem_vec_2738 ,mem_vec_2739 ,mem_vec_2740 ,mem_vec_2741 ,mem_vec_2742 ,mem_vec_2743 ,mem_vec_2744 ,mem_vec_2745 ,mem_vec_2746 ,mem_vec_2747 ,mem_vec_2748 ,mem_vec_2749 ,mem_vec_2750 ,mem_vec_2751 ,mem_vec_2752 ,mem_vec_2753 ,mem_vec_2754 ,mem_vec_2755 ,mem_vec_2756 ,mem_vec_2757 ,mem_vec_2758 ,mem_vec_2759 ,mem_vec_2760 ,mem_vec_2761 ,mem_vec_2762 ,mem_vec_2763 ,mem_vec_2764 ,mem_vec_2765 ,mem_vec_2766 ,mem_vec_2767 ,mem_vec_2768 ,mem_vec_2769 ,mem_vec_2770 ,mem_vec_2771 ,mem_vec_2772 ,mem_vec_2773 ,mem_vec_2774 ,mem_vec_2775 ,mem_vec_2776 ,mem_vec_2777 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
	for (y115 = y116, y115_p_0 = 0;
		y115 < y116 + 24;
		y115 += 24, y115_p_0 += 24){
		// y = 4 * ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
		// T (y, 4) (4 * ph_y / ph_y)
		for (y = y115, yp_1 = y115_p_0, yp_0 = 0;
			y < y115 + 24;
			y += 6, yp_1 += 6, yp_0 += 6){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 4) (136 / 34)
			for (x227 = x228, x227_p_0 = 0;
				x227 < x228 + 136;
				x227 += 34, x227_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 2) (128 / 64)
				for (f = f114, fp_0 = 0;
					f < f114 + 128;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 64
					// T (c, 4) (64 / 16)
					for (c171 = c172, c171_p_0 = 0;
						c171 < c172 + 64;
						c171 += 16, c171_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 64
						// T (w, 3) (3 / 1)
						for (w = w74, wp_0 = 0;
							w < w74 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 64
							// T (x, 34) (34 / 1)
							for (x = x227, xp_1 = x227_p_0, xp_0 = 0;
								x < x227 + 34;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2726 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2727 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2728 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_2729 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_2730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_2733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_2734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_2737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_2738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_2741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_2742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_2745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_2746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_2749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c171, cp_1 = c171_p_0, cp_0 = 0;
											c < c171 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2726);
											mem_vec_2726 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2727);
											mem_vec_2727 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2728);
											mem_vec_2728 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2729);
											mem_vec_2729 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2730);
											mem_vec_2730 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2731);
											mem_vec_2731 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2732);
											mem_vec_2732 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2733);
											mem_vec_2733 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2734);
											mem_vec_2734 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2735);
											mem_vec_2735 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2736);
											mem_vec_2736 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2737);
											mem_vec_2737 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2738);
											mem_vec_2738 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2739);
											mem_vec_2739 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2740);
											mem_vec_2740 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2741);
											mem_vec_2741 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2742);
											mem_vec_2742 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2743);
											mem_vec_2743 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2744);
											mem_vec_2744 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2745);
											mem_vec_2745 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2746);
											mem_vec_2746 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2747);
											mem_vec_2747 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2748);
											mem_vec_2748 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2749);
											mem_vec_2749 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_2726);
											mem_vec_2726 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_2727);
											mem_vec_2727 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_2728);
											mem_vec_2728 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_2729);
											mem_vec_2729 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_2730);
											mem_vec_2730 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_2731);
											mem_vec_2731 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_2732);
											mem_vec_2732 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_2733);
											mem_vec_2733 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_2734);
											mem_vec_2734 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_2735);
											mem_vec_2735 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_2736);
											mem_vec_2736 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_2737);
											mem_vec_2737 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_2738);
											mem_vec_2738 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_2739);
											mem_vec_2739 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_2740);
											mem_vec_2740 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_2741);
											mem_vec_2741 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_2742);
											mem_vec_2742 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_2743);
											mem_vec_2743 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_2744);
											mem_vec_2744 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_2745);
											mem_vec_2745 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_2746);
											mem_vec_2746 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_2747);
											mem_vec_2747 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_2748);
											mem_vec_2748 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_2749);
											mem_vec_2749 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_2726);
											mem_vec_2726 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_2727);
											mem_vec_2727 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_2728);
											mem_vec_2728 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_2729);
											mem_vec_2729 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_2730);
											mem_vec_2730 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_2731);
											mem_vec_2731 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_2732);
											mem_vec_2732 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_2733);
											mem_vec_2733 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_2734);
											mem_vec_2734 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_2735);
											mem_vec_2735 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_2736);
											mem_vec_2736 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_2737);
											mem_vec_2737 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_2738);
											mem_vec_2738 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_2739);
											mem_vec_2739 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_2740);
											mem_vec_2740 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_2741);
											mem_vec_2741 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_2742);
											mem_vec_2742 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_2743);
											mem_vec_2743 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_2744);
											mem_vec_2744 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_2745);
											mem_vec_2745 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_2746);
											mem_vec_2746 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_2747);
											mem_vec_2747 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_2748);
											mem_vec_2748 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_2749);
											mem_vec_2749 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2726);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2727);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2728);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2729);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2730);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2731);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2732);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2733);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2734);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2735);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2736);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2737);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2738);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2739);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2740);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2741);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2742);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2743);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2744);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2745);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2746);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2747);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_2748);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_2749);
							}
						}
					}
				}
			}
		}
	}
	for (y115 = y116 + 24, y115_p_0 = 0;
		y115 < y116 + 24 + 112;
		y115 += 28, y115_p_0 += 28){
		// y = 4 * ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
		// T (y, 4) (4 * ph_y / ph_y)
		for (y = y115, yp_1 = y115_p_0, yp_0 = 0;
			y < y115 + 28;
			y += 7, yp_1 += 7, yp_0 += 7){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 4) (136 / 34)
			for (x227 = x228, x227_p_0 = 0;
				x227 < x228 + 136;
				x227 += 34, x227_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 2) (128 / 64)
				for (f = f114, fp_0 = 0;
					f < f114 + 128;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 64
					// T (c, 4) (64 / 16)
					for (c171 = c172, c171_p_0 = 0;
						c171 < c172 + 64;
						c171 += 16, c171_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 64
						// T (w, 3) (3 / 1)
						for (w = w74, wp_0 = 0;
							w < w74 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 64
							// T (x, 34) (34 / 1)
							for (x = x227, xp_1 = x227_p_0, xp_0 = 0;
								x < x227 + 34;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2750 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2751 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2752 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_2753 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_2754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_2757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_2758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_2761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_2762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_2765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_2766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_2769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_2770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_2773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_2774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_2776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_2777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c171, cp_1 = c171_p_0, cp_0 = 0;
											c < c171 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2750);
											mem_vec_2750 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2751);
											mem_vec_2751 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2752);
											mem_vec_2752 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2753);
											mem_vec_2753 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2754);
											mem_vec_2754 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2755);
											mem_vec_2755 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2756);
											mem_vec_2756 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2757);
											mem_vec_2757 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2758);
											mem_vec_2758 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2759);
											mem_vec_2759 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2760);
											mem_vec_2760 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2761);
											mem_vec_2761 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2762);
											mem_vec_2762 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2763);
											mem_vec_2763 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2764);
											mem_vec_2764 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2765);
											mem_vec_2765 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2766);
											mem_vec_2766 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2767);
											mem_vec_2767 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2768);
											mem_vec_2768 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2769);
											mem_vec_2769 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2770);
											mem_vec_2770 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2771);
											mem_vec_2771 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2772);
											mem_vec_2772 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2773);
											mem_vec_2773 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_2774);
											mem_vec_2774 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_2775);
											mem_vec_2775 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_2776);
											mem_vec_2776 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_2777);
											mem_vec_2777 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_40 = _mm512_set1_ps(scal_7);
											vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_2750);
											mem_vec_2750 = vec_39;

											vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_2751);
											mem_vec_2751 = vec_42;

											vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_2752);
											mem_vec_2752 = vec_44;

											vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_2753);
											mem_vec_2753 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_2754);
											mem_vec_2754 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_2755);
											mem_vec_2755 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_2756);
											mem_vec_2756 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_2757);
											mem_vec_2757 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_2758);
											mem_vec_2758 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_2759);
											mem_vec_2759 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_2760);
											mem_vec_2760 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_2761);
											mem_vec_2761 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_2762);
											mem_vec_2762 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_2763);
											mem_vec_2763 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_2764);
											mem_vec_2764 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_2765);
											mem_vec_2765 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_2766);
											mem_vec_2766 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_2767);
											mem_vec_2767 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_2768);
											mem_vec_2768 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_2769);
											mem_vec_2769 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_69 = _mm512_set1_ps(scal_12);


											vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_2770);
											mem_vec_2770 = vec_68;



											vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_2771);
											mem_vec_2771 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_2772);
											mem_vec_2772 = vec_71;



											vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_2773);
											mem_vec_2773 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_74 = _mm512_set1_ps(scal_13);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_2774);
											mem_vec_2774 = vec_73;



											vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_2775);
											mem_vec_2775 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_2776);
											mem_vec_2776 = vec_76;



											vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_2777);
											mem_vec_2777 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_14);
											vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_2750);
											mem_vec_2750 = vec_78;

											vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_2751);
											mem_vec_2751 = vec_81;

											vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_2752);
											mem_vec_2752 = vec_83;

											vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_2753);
											mem_vec_2753 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_2754);
											mem_vec_2754 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_2755);
											mem_vec_2755 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_2756);
											mem_vec_2756 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_2757);
											mem_vec_2757 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_2758);
											mem_vec_2758 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_2759);
											mem_vec_2759 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_2760);
											mem_vec_2760 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_2761);
											mem_vec_2761 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_2762);
											mem_vec_2762 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_2763);
											mem_vec_2763 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_2764);
											mem_vec_2764 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_2765);
											mem_vec_2765 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_18);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_2766);
											mem_vec_2766 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_2767);
											mem_vec_2767 = vec_104;



											vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_2768);
											mem_vec_2768 = vec_105;



											vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_2769);
											mem_vec_2769 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_108 = _mm512_set1_ps(scal_19);


											vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_2770);
											mem_vec_2770 = vec_107;



											vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_2771);
											mem_vec_2771 = vec_109;



											vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_2772);
											mem_vec_2772 = vec_110;



											vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_2773);
											mem_vec_2773 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_113 = _mm512_set1_ps(scal_20);


											vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_2774);
											mem_vec_2774 = vec_112;



											vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_2775);
											mem_vec_2775 = vec_114;



											vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_2776);
											mem_vec_2776 = vec_115;



											vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_2777);
											mem_vec_2777 = vec_116;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2750);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2751);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2752);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2753);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2754);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2755);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2756);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2757);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2758);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2759);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2760);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2761);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2762);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2763);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2764);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2765);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2766);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2767);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2768);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2769);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2770);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2771);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_2772);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_2773);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2774);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2775);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_2776);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_2777);
							}
						}
					}
				}
			}
		}
	}


}