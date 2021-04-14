#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (2, f); T (32, c); T (4, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (1, f)]
*/
IND_TYPE c, cp_0, c1092_p_0, cp_1, c1092, f, fp_0, f1092_p_0, fp_1, f1092, w, wp_0, x, xp_0, x1092_p_0, xp_1, x1092, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y728 = 0;
IND_TYPE x1093 = 0;
IND_TYPE h = 0;
IND_TYPE w688 = 0;
IND_TYPE c1093 = 0;
IND_TYPE f1093 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10810 ,mem_vec_10811 ,mem_vec_10812 ,mem_vec_10813 ,mem_vec_10814 ,mem_vec_10815 ,mem_vec_10816 ,mem_vec_10817 ,mem_vec_10818 ,mem_vec_10819 ,mem_vec_10820 ,mem_vec_10821 ,mem_vec_10822 ,mem_vec_10823 ,mem_vec_10824 ,mem_vec_10825 ,mem_vec_10826 ,mem_vec_10827 ,mem_vec_10828 ,mem_vec_10829 ,mem_vec_10830 ,mem_vec_10831 ,mem_vec_10832 ,mem_vec_10833 ,mem_vec_10834 ,mem_vec_10835 ,mem_vec_10836 ,mem_vec_10837 ,mem_vec_10838 ,mem_vec_10839 ,mem_vec_10840 ,mem_vec_10841 ,mem_vec_10842 ,mem_vec_10843 ,mem_vec_10844 ,mem_vec_10845 ,mem_vec_10846 ,mem_vec_10847 ,mem_vec_10848 ,mem_vec_10849 ,mem_vec_10850 ,mem_vec_10851 ,mem_vec_10852 ,mem_vec_10853 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
for (f1092 = f1093, f1092_p_0 = 0;
	f1092 < f1093 + 128;
	f1092 += 128, f1092_p_0 += 128){
		for (y = y728, yp_0 = 0;
			y < y728 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 4) (28 / 7)
			for (x1092 = x1093, x1092_p_0 = 0;
				x1092 < x1093 + 28;
				x1092 += 7, x1092_p_0 += 7){
				// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 128
				// T (c, 32) (128 / 4)
				for (c1092 = c1093, c1092_p_0 = 0;
					c1092 < c1093 + 128;
					c1092 += 4, c1092_p_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 128
					// T (f, 2) (128 / 64)
					for (f = f1092, fp_1 = f1092_p_0, fp_0 = 0;
						f < f1092 + 128;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
						// T (w, 3) (3 / 1)
						for (w = w688, wp_0 = 0;
							w < w688 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 1, c = 4, f = 64
							// T (x, 7) (7 / 1)
							for (x = x1092, xp_1 = x1092_p_0, xp_0 = 0;
								x < x1092 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10810 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10811 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10812 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_10813 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_10814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_10817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_10818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_10821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_10822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_10825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_10826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_10827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_10828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_10829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c1092, cp_1 = c1092_p_0, cp_0 = 0;
											c < c1092 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10810);
											mem_vec_10810 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10811);
											mem_vec_10811 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10812);
											mem_vec_10812 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10813);
											mem_vec_10813 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10814);
											mem_vec_10814 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10815);
											mem_vec_10815 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10816);
											mem_vec_10816 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10817);
											mem_vec_10817 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10818);
											mem_vec_10818 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10819);
											mem_vec_10819 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10820);
											mem_vec_10820 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10821);
											mem_vec_10821 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10822);
											mem_vec_10822 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10823);
											mem_vec_10823 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10824);
											mem_vec_10824 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10825);
											mem_vec_10825 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10826);
											mem_vec_10826 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10827);
											mem_vec_10827 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10828);
											mem_vec_10828 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10829);
											mem_vec_10829 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_10810);
											mem_vec_10810 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_10811);
											mem_vec_10811 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_10812);
											mem_vec_10812 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_10813);
											mem_vec_10813 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_10814);
											mem_vec_10814 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_10815);
											mem_vec_10815 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_10816);
											mem_vec_10816 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_10817);
											mem_vec_10817 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_10818);
											mem_vec_10818 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_10819);
											mem_vec_10819 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_10820);
											mem_vec_10820 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_10821);
											mem_vec_10821 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_10822);
											mem_vec_10822 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_10823);
											mem_vec_10823 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_10824);
											mem_vec_10824 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_10825);
											mem_vec_10825 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_10826);
											mem_vec_10826 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_10827);
											mem_vec_10827 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_10828);
											mem_vec_10828 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_10829);
											mem_vec_10829 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_10810);
											mem_vec_10810 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_10811);
											mem_vec_10811 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_10812);
											mem_vec_10812 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_10813);
											mem_vec_10813 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_10814);
											mem_vec_10814 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_10815);
											mem_vec_10815 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_10816);
											mem_vec_10816 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_10817);
											mem_vec_10817 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_10818);
											mem_vec_10818 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_10819);
											mem_vec_10819 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_10820);
											mem_vec_10820 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_10821);
											mem_vec_10821 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_10822);
											mem_vec_10822 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_10823);
											mem_vec_10823 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_10824);
											mem_vec_10824 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_10825);
											mem_vec_10825 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_10826);
											mem_vec_10826 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_10827);
											mem_vec_10827 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_10828);
											mem_vec_10828 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_10829);
											mem_vec_10829 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10810);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10811);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10812);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10813);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10814);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10815);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10816);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10817);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10818);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10819);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10820);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10821);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10822);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10823);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10824);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10825);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10826);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10827);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10828);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10829);
							}
						}
					}
				}
			}
		}
		for (y = y728 + 10, yp_0 = 0;
			y < y728 + 10 + 18;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 4) (28 / 7)
			for (x1092 = x1093, x1092_p_0 = 0;
				x1092 < x1093 + 28;
				x1092 += 7, x1092_p_0 += 7){
				// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 128
				// T (c, 32) (128 / 4)
				for (c1092 = c1093, c1092_p_0 = 0;
					c1092 < c1093 + 128;
					c1092 += 4, c1092_p_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 128
					// T (f, 2) (128 / 64)
					for (f = f1092, fp_1 = f1092_p_0, fp_0 = 0;
						f < f1092 + 128;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
						// T (w, 3) (3 / 1)
						for (w = w688, wp_0 = 0;
							w < w688 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 1, c = 4, f = 64
							// T (x, 7) (7 / 1)
							for (x = x1092, xp_1 = x1092_p_0, xp_0 = 0;
								x < x1092 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10830 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10831 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10832 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_10833 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_10834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_10837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_10838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_10841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_10842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_10845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_10846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_10847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_10848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_10849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_10850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_10851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_10852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_10853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c1092, cp_1 = c1092_p_0, cp_0 = 0;
											c < c1092 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10830);
											mem_vec_10830 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10831);
											mem_vec_10831 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10832);
											mem_vec_10832 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10833);
											mem_vec_10833 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10834);
											mem_vec_10834 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10835);
											mem_vec_10835 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10836);
											mem_vec_10836 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10837);
											mem_vec_10837 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10838);
											mem_vec_10838 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10839);
											mem_vec_10839 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10840);
											mem_vec_10840 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10841);
											mem_vec_10841 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10842);
											mem_vec_10842 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10843);
											mem_vec_10843 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10844);
											mem_vec_10844 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10845);
											mem_vec_10845 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10846);
											mem_vec_10846 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10847);
											mem_vec_10847 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10848);
											mem_vec_10848 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10849);
											mem_vec_10849 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10850);
											mem_vec_10850 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10851);
											mem_vec_10851 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_10852);
											mem_vec_10852 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_10853);
											mem_vec_10853 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_10830);
											mem_vec_10830 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_10831);
											mem_vec_10831 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_10832);
											mem_vec_10832 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_10833);
											mem_vec_10833 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_10834);
											mem_vec_10834 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_10835);
											mem_vec_10835 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_10836);
											mem_vec_10836 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_10837);
											mem_vec_10837 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_10838);
											mem_vec_10838 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_10839);
											mem_vec_10839 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_10840);
											mem_vec_10840 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_10841);
											mem_vec_10841 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_10842);
											mem_vec_10842 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_10843);
											mem_vec_10843 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_10844);
											mem_vec_10844 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_10845);
											mem_vec_10845 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_10846);
											mem_vec_10846 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_10847);
											mem_vec_10847 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_10848);
											mem_vec_10848 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_10849);
											mem_vec_10849 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_10850);
											mem_vec_10850 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_10851);
											mem_vec_10851 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_10852);
											mem_vec_10852 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_10853);
											mem_vec_10853 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_10830);
											mem_vec_10830 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_10831);
											mem_vec_10831 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_10832);
											mem_vec_10832 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_10833);
											mem_vec_10833 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_10834);
											mem_vec_10834 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_10835);
											mem_vec_10835 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_10836);
											mem_vec_10836 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_10837);
											mem_vec_10837 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_10838);
											mem_vec_10838 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_10839);
											mem_vec_10839 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_10840);
											mem_vec_10840 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_10841);
											mem_vec_10841 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_10842);
											mem_vec_10842 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_10843);
											mem_vec_10843 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_10844);
											mem_vec_10844 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_10845);
											mem_vec_10845 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_10846);
											mem_vec_10846 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_10847);
											mem_vec_10847 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_10848);
											mem_vec_10848 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_10849);
											mem_vec_10849 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_10850);
											mem_vec_10850 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_10851);
											mem_vec_10851 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_10852);
											mem_vec_10852 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_10853);
											mem_vec_10853 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10830);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10831);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10832);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10833);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10834);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10835);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10836);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10837);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10838);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10839);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10840);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10841);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10842);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10843);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10844);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10845);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10846);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10847);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10848);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10849);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10850);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10851);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_10852);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_10853);
							}
						}
					}
				}
			}
		}
}


}