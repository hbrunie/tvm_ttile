#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (8, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (1, f);
  T (2, c); T (1, f)]
*/
IND_TYPE c, cp_0, c918_p_0, cp_1, c918, f, fp_0, f1224_p_0, f1225_p_0, fp_1, f1224_p_1, fp_2, f1224, f1225, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y612 = 0;
IND_TYPE x612 = 0;
IND_TYPE h464 = 0;
IND_TYPE w = 0;
IND_TYPE c919 = 0;
IND_TYPE f1226 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8792 ,mem_vec_8793 ,mem_vec_8794 ,mem_vec_8795 ,mem_vec_8796 ,mem_vec_8797 ,mem_vec_8798 ,mem_vec_8799 ,mem_vec_8800 ,mem_vec_8801 ,mem_vec_8802 ,mem_vec_8803 ,mem_vec_8804 ,mem_vec_8805 ,mem_vec_8806 ,mem_vec_8807 ,mem_vec_8808 ,mem_vec_8809 ,mem_vec_8810 ,mem_vec_8811 ,mem_vec_8812 ,mem_vec_8813 ,mem_vec_8814 ,mem_vec_8815 ,mem_vec_8816 ,mem_vec_8817 ,mem_vec_8818 ,mem_vec_8819 ,mem_vec_8820 ,mem_vec_8821 ,mem_vec_8822 ,mem_vec_8823 ,mem_vec_8824 ,mem_vec_8825 ,mem_vec_8826 ,mem_vec_8827 ,mem_vec_8828 ,mem_vec_8829 ,mem_vec_8830 ,mem_vec_8831 ,mem_vec_8832 ,mem_vec_8833 ,mem_vec_8834 ,mem_vec_8835 ,mem_vec_8836 ,mem_vec_8837 ,mem_vec_8838 ,mem_vec_8839 ,mem_vec_8840 ,mem_vec_8841 ,mem_vec_8842 ,mem_vec_8843 ,mem_vec_8844 ,mem_vec_8845 ,mem_vec_8846 ,mem_vec_8847 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (f, 1) (512 / 512)
for (f1225 = f1226, f1225_p_0 = 0;
	f1225 < f1226 + 512;
	f1225 += 512, f1225_p_0 += 512){
	// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
	// T (c, 2) (512 / 256)
	for (c918 = c919, c918_p_0 = 0;
		c918 < c919 + 512;
		c918 += 256, c918_p_0 += 256){
		// y = 7, x = 7, h = 3, w = 3, c = 256, f = 512
		// T (f, 1) (512 / 512)
		for (f1224 = f1225, f1224_p_1 = f1225_p_0, f1224_p_0 = 0;
			f1224 < f1225 + 512;
			f1224 += 512, f1224_p_1 += 512, f1224_p_0 += 512){
				for (y = y612, yp_0 = 0;
					y < y612 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 512
					// T (f, 8) (512 / 64)
					for (f = f1224, fp_2 = f1224_p_1, fp_1 = f1224_p_0, fp_0 = 0;
						f < f1224 + 512;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 64
						// T (h, 3) (3 / 1)
						for (h = h464, hp_0 = 0;
							h < h464 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 256, f = 64
							// T (x, 7) (7 / 1)
							for (x = x612, xp_0 = 0;
								x < x612 + 7;
								x += 1, xp_0 += 1){
										mem_vec_8792 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8793 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_8794 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8795 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_8796 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_8797 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
										mem_vec_8798 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_8799 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
										mem_vec_8800 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8801 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_8802 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8803 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_8804 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_8805 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
										mem_vec_8806 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_8807 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
										mem_vec_8808 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8809 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_8810 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8811 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_8812 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_8813 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
										mem_vec_8814 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_8815 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c918, cp_1 = c918_p_0, cp_0 = 0;
											c < c918 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8792);
											mem_vec_8792 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8793);
											mem_vec_8793 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8794);
											mem_vec_8794 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8795);
											mem_vec_8795 = vec_7;

											vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_8796);
											mem_vec_8796 = vec_9;

											vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

											vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_8797);
											mem_vec_8797 = vec_11;

											vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_8798);
											mem_vec_8798 = vec_13;

											vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

											vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_8799);
											mem_vec_8799 = vec_15;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_18 = _mm256_set1_ps(scal_1);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8800);
											mem_vec_8800 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8801);
											mem_vec_8801 = vec_19;



											vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_8802);
											mem_vec_8802 = vec_20;



											vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_8803);
											mem_vec_8803 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_8804);
											mem_vec_8804 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_8805);
											mem_vec_8805 = vec_23;



											vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_8806);
											mem_vec_8806 = vec_24;



											vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_8807);
											mem_vec_8807 = vec_25;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_27 = _mm256_set1_ps(scal_2);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8808);
											mem_vec_8808 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8809);
											mem_vec_8809 = vec_28;



											vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_8810);
											mem_vec_8810 = vec_29;



											vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_8811);
											mem_vec_8811 = vec_30;



											vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_8812);
											mem_vec_8812 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_8813);
											mem_vec_8813 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_8814);
											mem_vec_8814 = vec_33;



											vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_8815);
											mem_vec_8815 = vec_34;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_36 = _mm256_set1_ps(scal_3);
											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_8792);
											mem_vec_8792 = vec_35;

											vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_8793);
											mem_vec_8793 = vec_38;

											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_40 = _mm256_fmadd_ps(vec_36, vec_41, mem_vec_8794);
											mem_vec_8794 = vec_40;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_42 = _mm256_fmadd_ps(vec_36, vec_43, mem_vec_8795);
											mem_vec_8795 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_44 = _mm256_fmadd_ps(vec_36, vec_45, mem_vec_8796);
											mem_vec_8796 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

											vec_46 = _mm256_fmadd_ps(vec_36, vec_47, mem_vec_8797);
											mem_vec_8797 = vec_46;

											vec_49 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_48 = _mm256_fmadd_ps(vec_36, vec_49, mem_vec_8798);
											mem_vec_8798 = vec_48;

											vec_51 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

											vec_50 = _mm256_fmadd_ps(vec_36, vec_51, mem_vec_8799);
											mem_vec_8799 = vec_50;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_53 = _mm256_set1_ps(scal_4);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_8800);
											mem_vec_8800 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_8801);
											mem_vec_8801 = vec_54;



											vec_55 = _mm256_fmadd_ps(vec_53, vec_41, mem_vec_8802);
											mem_vec_8802 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_8803);
											mem_vec_8803 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_8804);
											mem_vec_8804 = vec_57;



											vec_58 = _mm256_fmadd_ps(vec_53, vec_47, mem_vec_8805);
											mem_vec_8805 = vec_58;



											vec_59 = _mm256_fmadd_ps(vec_53, vec_49, mem_vec_8806);
											mem_vec_8806 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_53, vec_51, mem_vec_8807);
											mem_vec_8807 = vec_60;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_62 = _mm256_set1_ps(scal_5);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_8808);
											mem_vec_8808 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_8809);
											mem_vec_8809 = vec_63;



											vec_64 = _mm256_fmadd_ps(vec_62, vec_41, mem_vec_8810);
											mem_vec_8810 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_8811);
											mem_vec_8811 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_8812);
											mem_vec_8812 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_62, vec_47, mem_vec_8813);
											mem_vec_8813 = vec_67;



											vec_68 = _mm256_fmadd_ps(vec_62, vec_49, mem_vec_8814);
											mem_vec_8814 = vec_68;



											vec_69 = _mm256_fmadd_ps(vec_62, vec_51, mem_vec_8815);
											mem_vec_8815 = vec_69;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_71 = _mm256_set1_ps(scal_6);
											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_8792);
											mem_vec_8792 = vec_70;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_8793);
											mem_vec_8793 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_75 = _mm256_fmadd_ps(vec_71, vec_76, mem_vec_8794);
											mem_vec_8794 = vec_75;

											vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_77 = _mm256_fmadd_ps(vec_71, vec_78, mem_vec_8795);
											mem_vec_8795 = vec_77;

											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_79 = _mm256_fmadd_ps(vec_71, vec_80, mem_vec_8796);
											mem_vec_8796 = vec_79;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

											vec_81 = _mm256_fmadd_ps(vec_71, vec_82, mem_vec_8797);
											mem_vec_8797 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_83 = _mm256_fmadd_ps(vec_71, vec_84, mem_vec_8798);
											mem_vec_8798 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

											vec_85 = _mm256_fmadd_ps(vec_71, vec_86, mem_vec_8799);
											mem_vec_8799 = vec_85;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_88 = _mm256_set1_ps(scal_7);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_8800);
											mem_vec_8800 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_8801);
											mem_vec_8801 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_8802);
											mem_vec_8802 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_8803);
											mem_vec_8803 = vec_91;



											vec_92 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_8804);
											mem_vec_8804 = vec_92;



											vec_93 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_8805);
											mem_vec_8805 = vec_93;



											vec_94 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_8806);
											mem_vec_8806 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_8807);
											mem_vec_8807 = vec_95;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_97 = _mm256_set1_ps(scal_8);


											vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_8808);
											mem_vec_8808 = vec_96;



											vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_8809);
											mem_vec_8809 = vec_98;



											vec_99 = _mm256_fmadd_ps(vec_97, vec_76, mem_vec_8810);
											mem_vec_8810 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_8811);
											mem_vec_8811 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_8812);
											mem_vec_8812 = vec_101;



											vec_102 = _mm256_fmadd_ps(vec_97, vec_82, mem_vec_8813);
											mem_vec_8813 = vec_102;



											vec_103 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_8814);
											mem_vec_8814 = vec_103;



											vec_104 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_8815);
											mem_vec_8815 = vec_104;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8792);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8793);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8794);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8795);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8796);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_8797);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8798);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_8799);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8800);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8801);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8802);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8803);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8804);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_8805);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8806);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_8807);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8808);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8809);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8810);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8811);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8812);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_8813);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8814);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_8815);
							}
						}
					}
				}
				for (y = y612 + 3, yp_0 = 0;
					y < y612 + 3 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 512
					// T (f, 8) (512 / 64)
					for (f = f1224, fp_2 = f1224_p_1, fp_1 = f1224_p_0, fp_0 = 0;
						f < f1224 + 512;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 64
						// T (h, 3) (3 / 1)
						for (h = h464, hp_0 = 0;
							h < h464 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 256, f = 64
							// T (x, 7) (7 / 1)
							for (x = x612, xp_0 = 0;
								x < x612 + 7;
								x += 1, xp_0 += 1){
										mem_vec_8816 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8817 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_8818 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8819 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_8820 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_8821 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
										mem_vec_8822 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_8823 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
										mem_vec_8824 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8825 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_8826 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8827 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_8828 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_8829 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
										mem_vec_8830 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_8831 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
										mem_vec_8832 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8833 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_8834 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8835 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_8836 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_8837 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
										mem_vec_8838 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_8839 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
										mem_vec_8840 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8841 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_8842 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8843 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_8844 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_8845 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
										mem_vec_8846 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_8847 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c918, cp_1 = c918_p_0, cp_0 = 0;
											c < c918 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8816);
											mem_vec_8816 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8817);
											mem_vec_8817 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8818);
											mem_vec_8818 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8819);
											mem_vec_8819 = vec_7;

											vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_8820);
											mem_vec_8820 = vec_9;

											vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

											vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_8821);
											mem_vec_8821 = vec_11;

											vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_8822);
											mem_vec_8822 = vec_13;

											vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

											vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_8823);
											mem_vec_8823 = vec_15;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_18 = _mm256_set1_ps(scal_1);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8824);
											mem_vec_8824 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8825);
											mem_vec_8825 = vec_19;



											vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_8826);
											mem_vec_8826 = vec_20;



											vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_8827);
											mem_vec_8827 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_8828);
											mem_vec_8828 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_8829);
											mem_vec_8829 = vec_23;



											vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_8830);
											mem_vec_8830 = vec_24;



											vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_8831);
											mem_vec_8831 = vec_25;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_27 = _mm256_set1_ps(scal_2);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8832);
											mem_vec_8832 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8833);
											mem_vec_8833 = vec_28;



											vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_8834);
											mem_vec_8834 = vec_29;



											vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_8835);
											mem_vec_8835 = vec_30;



											vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_8836);
											mem_vec_8836 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_8837);
											mem_vec_8837 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_8838);
											mem_vec_8838 = vec_33;



											vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_8839);
											mem_vec_8839 = vec_34;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_36 = _mm256_set1_ps(scal_3);


											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_8840);
											mem_vec_8840 = vec_35;



											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_8841);
											mem_vec_8841 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_8842);
											mem_vec_8842 = vec_38;



											vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_8843);
											mem_vec_8843 = vec_39;



											vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_8844);
											mem_vec_8844 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_8845);
											mem_vec_8845 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_8846);
											mem_vec_8846 = vec_42;



											vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_8847);
											mem_vec_8847 = vec_43;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_45 = _mm256_set1_ps(scal_4);
											vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_8816);
											mem_vec_8816 = vec_44;

											vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_8817);
											mem_vec_8817 = vec_47;

											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_8818);
											mem_vec_8818 = vec_49;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_8819);
											mem_vec_8819 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_8820);
											mem_vec_8820 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

											vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_8821);
											mem_vec_8821 = vec_55;

											vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_8822);
											mem_vec_8822 = vec_57;

											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

											vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_8823);
											mem_vec_8823 = vec_59;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_62 = _mm256_set1_ps(scal_5);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_8824);
											mem_vec_8824 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_8825);
											mem_vec_8825 = vec_63;



											vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_8826);
											mem_vec_8826 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_8827);
											mem_vec_8827 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_8828);
											mem_vec_8828 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_8829);
											mem_vec_8829 = vec_67;



											vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_8830);
											mem_vec_8830 = vec_68;



											vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_8831);
											mem_vec_8831 = vec_69;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_71 = _mm256_set1_ps(scal_6);


											vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_8832);
											mem_vec_8832 = vec_70;



											vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_8833);
											mem_vec_8833 = vec_72;



											vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_8834);
											mem_vec_8834 = vec_73;



											vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_8835);
											mem_vec_8835 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_8836);
											mem_vec_8836 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_8837);
											mem_vec_8837 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_8838);
											mem_vec_8838 = vec_77;



											vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_8839);
											mem_vec_8839 = vec_78;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_80 = _mm256_set1_ps(scal_7);


											vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_8840);
											mem_vec_8840 = vec_79;



											vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_8841);
											mem_vec_8841 = vec_81;



											vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_8842);
											mem_vec_8842 = vec_82;



											vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_8843);
											mem_vec_8843 = vec_83;



											vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_8844);
											mem_vec_8844 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_8845);
											mem_vec_8845 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_8846);
											mem_vec_8846 = vec_86;



											vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_8847);
											mem_vec_8847 = vec_87;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_89 = _mm256_set1_ps(scal_8);
											vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_8816);
											mem_vec_8816 = vec_88;

											vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_8817);
											mem_vec_8817 = vec_91;

											vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_8818);
											mem_vec_8818 = vec_93;

											vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_8819);
											mem_vec_8819 = vec_95;

											vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_8820);
											mem_vec_8820 = vec_97;

											vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

											vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_8821);
											mem_vec_8821 = vec_99;

											vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_8822);
											mem_vec_8822 = vec_101;

											vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

											vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_8823);
											mem_vec_8823 = vec_103;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_106 = _mm256_set1_ps(scal_9);


											vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_8824);
											mem_vec_8824 = vec_105;



											vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_8825);
											mem_vec_8825 = vec_107;



											vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_8826);
											mem_vec_8826 = vec_108;



											vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_8827);
											mem_vec_8827 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_8828);
											mem_vec_8828 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_8829);
											mem_vec_8829 = vec_111;



											vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_8830);
											mem_vec_8830 = vec_112;



											vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_8831);
											mem_vec_8831 = vec_113;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_115 = _mm256_set1_ps(scal_10);


											vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_8832);
											mem_vec_8832 = vec_114;



											vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_8833);
											mem_vec_8833 = vec_116;



											vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_8834);
											mem_vec_8834 = vec_117;



											vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_8835);
											mem_vec_8835 = vec_118;



											vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_8836);
											mem_vec_8836 = vec_119;



											vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_8837);
											mem_vec_8837 = vec_120;



											vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_8838);
											mem_vec_8838 = vec_121;



											vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_8839);
											mem_vec_8839 = vec_122;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_124 = _mm256_set1_ps(scal_11);


											vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_8840);
											mem_vec_8840 = vec_123;



											vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_8841);
											mem_vec_8841 = vec_125;



											vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_8842);
											mem_vec_8842 = vec_126;



											vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_8843);
											mem_vec_8843 = vec_127;



											vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_8844);
											mem_vec_8844 = vec_128;



											vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_8845);
											mem_vec_8845 = vec_129;



											vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_8846);
											mem_vec_8846 = vec_130;



											vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_8847);
											mem_vec_8847 = vec_131;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8816);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8817);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8818);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8819);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8820);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_8821);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8822);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_8823);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8824);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8825);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8826);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8827);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8828);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_8829);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8830);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_8831);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8832);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8833);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8834);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8835);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8836);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_8837);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8838);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_8839);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8840);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8841);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8842);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8843);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_8844);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_8845);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_8846);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_8847);
							}
						}
					}
				}
		}
	}
}


}