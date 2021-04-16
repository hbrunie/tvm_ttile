#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (3, h);
  T (34, x); T (8, c);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (1, c); T (4, f)]
*/
IND_TYPE c, cp_0, c593_p_0, c594_p_0, cp_1, c593_p_1, cp_2, c593, c594, f, fp_0, f478_p_0, fp_1, f478, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y337 = 0;
IND_TYPE x306 = 0;
IND_TYPE h233 = 0;
IND_TYPE w = 0;
IND_TYPE c595 = 0;
IND_TYPE f479 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6800 ,mem_vec_6801 ,mem_vec_6802 ,mem_vec_6803 ,mem_vec_6804 ,mem_vec_6805 ,mem_vec_6806 ,mem_vec_6807 ,mem_vec_6808 ,mem_vec_6809 ,mem_vec_6810 ,mem_vec_6811 ,mem_vec_6812 ,mem_vec_6813 ,mem_vec_6814 ,mem_vec_6815 ,mem_vec_6816 ,mem_vec_6817 ,mem_vec_6818 ,mem_vec_6819 ,mem_vec_6820 ,mem_vec_6821 ,mem_vec_6822 ,mem_vec_6823 ,mem_vec_6824 ,mem_vec_6825 ,mem_vec_6826 ,mem_vec_6827 ,mem_vec_6828 ,mem_vec_6829 ,mem_vec_6830 ,mem_vec_6831 ,mem_vec_6832 ,mem_vec_6833 ,mem_vec_6834 ,mem_vec_6835 ,mem_vec_6836 ,mem_vec_6837 ,mem_vec_6838 ,mem_vec_6839 ,mem_vec_6840 ,mem_vec_6841 ,mem_vec_6842 ,mem_vec_6843 ,mem_vec_6844 ,mem_vec_6845 ,mem_vec_6846 ,mem_vec_6847 ,mem_vec_6848 ,mem_vec_6849 ,mem_vec_6850 ,mem_vec_6851 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f478 = f479, f478_p_0 = 0;
	f478 < f479 + 512;
	f478 += 128, f478_p_0 += 128){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
	// T (c, 1) (256 / 256)
	for (c594 = c595, c594_p_0 = 0;
		c594 < c595 + 256;
		c594 += 256, c594_p_0 += 256){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
		// T (f, 4) (128 / 32)
		for (f = f478, fp_1 = f478_p_0, fp_0 = 0;
			f < f478 + 128;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y337, yp_0 = 0;
					y < y337 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (c, 8) (256 / 32)
					for (c593 = c594, c593_p_1 = c594_p_0, c593_p_0 = 0;
						c593 < c594 + 256;
						c593 += 32, c593_p_1 += 32, c593_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (x, 34) (34 / 1)
						for (x = x306, xp_0 = 0;
							x < x306 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h233, hp_0 = 0;
								h < h233 + 3;
								h += 1, hp_0 += 1){
										mem_vec_6800 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6801 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_6802 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6803 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_6804 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6805 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_6806 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6807 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_6808 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6809 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_6810 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6811 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_6812 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6813 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_6814 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6815 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_6816 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6817 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_6818 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6819 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_6820 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6821 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_6822 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6823 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c593, cp_2 = c593_p_1, cp_1 = c593_p_0, cp_0 = 0;
											c < c593 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6800);
											mem_vec_6800 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6801);
											mem_vec_6801 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6802);
											mem_vec_6802 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6803);
											mem_vec_6803 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6804);
											mem_vec_6804 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6805);
											mem_vec_6805 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6806);
											mem_vec_6806 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6807);
											mem_vec_6807 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6808);
											mem_vec_6808 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6809);
											mem_vec_6809 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6810);
											mem_vec_6810 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6811);
											mem_vec_6811 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6812);
											mem_vec_6812 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6813);
											mem_vec_6813 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6814);
											mem_vec_6814 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6815);
											mem_vec_6815 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6816);
											mem_vec_6816 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6817);
											mem_vec_6817 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6818);
											mem_vec_6818 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6819);
											mem_vec_6819 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6820);
											mem_vec_6820 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6821);
											mem_vec_6821 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_6822);
											mem_vec_6822 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_6823);
											mem_vec_6823 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_6800);
											mem_vec_6800 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_6801);
											mem_vec_6801 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_6802);
											mem_vec_6802 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_6803);
											mem_vec_6803 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_6804);
											mem_vec_6804 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_6805);
											mem_vec_6805 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_6806);
											mem_vec_6806 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_6807);
											mem_vec_6807 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_6808);
											mem_vec_6808 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_6809);
											mem_vec_6809 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_6810);
											mem_vec_6810 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_6811);
											mem_vec_6811 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_6812);
											mem_vec_6812 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_6813);
											mem_vec_6813 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_6814);
											mem_vec_6814 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_6815);
											mem_vec_6815 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_6816);
											mem_vec_6816 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_6817);
											mem_vec_6817 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_6818);
											mem_vec_6818 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_6819);
											mem_vec_6819 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_6820);
											mem_vec_6820 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_6821);
											mem_vec_6821 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_6822);
											mem_vec_6822 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_6823);
											mem_vec_6823 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_6800);
											mem_vec_6800 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_6801);
											mem_vec_6801 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_6802);
											mem_vec_6802 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_6803);
											mem_vec_6803 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_6804);
											mem_vec_6804 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_6805);
											mem_vec_6805 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_6806);
											mem_vec_6806 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_6807);
											mem_vec_6807 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_6808);
											mem_vec_6808 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_6809);
											mem_vec_6809 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_6810);
											mem_vec_6810 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_6811);
											mem_vec_6811 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_6812);
											mem_vec_6812 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_6813);
											mem_vec_6813 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_6814);
											mem_vec_6814 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_6815);
											mem_vec_6815 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_6816);
											mem_vec_6816 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_6817);
											mem_vec_6817 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_6818);
											mem_vec_6818 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_6819);
											mem_vec_6819 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_6820);
											mem_vec_6820 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_6821);
											mem_vec_6821 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_6822);
											mem_vec_6822 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_6823);
											mem_vec_6823 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6800);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6801);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6802);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6803);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6804);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6805);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6806);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6807);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6808);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6809);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6810);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6811);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6812);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6813);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6814);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6815);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6816);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6817);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6818);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6819);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6820);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6821);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6822);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_6823);
							}
						}
					}
				}
				for (y = y337 + 6, yp_0 = 0;
					y < y337 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (c, 8) (256 / 32)
					for (c593 = c594, c593_p_1 = c594_p_0, c593_p_0 = 0;
						c593 < c594 + 256;
						c593 += 32, c593_p_1 += 32, c593_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (x, 34) (34 / 1)
						for (x = x306, xp_0 = 0;
							x < x306 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h233, hp_0 = 0;
								h < h233 + 3;
								h += 1, hp_0 += 1){
										mem_vec_6824 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6825 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_6826 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6827 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_6828 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6829 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_6830 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6831 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_6832 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6833 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_6834 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6835 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_6836 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6837 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_6838 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6839 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_6840 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6841 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_6842 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6843 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_6844 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6845 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_6846 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6847 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										mem_vec_6848 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6849 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_6850 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_6851 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c593, cp_2 = c593_p_1, cp_1 = c593_p_0, cp_0 = 0;
											c < c593 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6824);
											mem_vec_6824 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6825);
											mem_vec_6825 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6826);
											mem_vec_6826 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6827);
											mem_vec_6827 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6828);
											mem_vec_6828 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6829);
											mem_vec_6829 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6830);
											mem_vec_6830 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6831);
											mem_vec_6831 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6832);
											mem_vec_6832 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6833);
											mem_vec_6833 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6834);
											mem_vec_6834 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6835);
											mem_vec_6835 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6836);
											mem_vec_6836 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6837);
											mem_vec_6837 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6838);
											mem_vec_6838 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6839);
											mem_vec_6839 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6840);
											mem_vec_6840 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6841);
											mem_vec_6841 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6842);
											mem_vec_6842 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6843);
											mem_vec_6843 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6844);
											mem_vec_6844 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6845);
											mem_vec_6845 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_6846);
											mem_vec_6846 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_6847);
											mem_vec_6847 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_6848);
											mem_vec_6848 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_6849);
											mem_vec_6849 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_6850);
											mem_vec_6850 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_6851);
											mem_vec_6851 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_40 = _mm256_set1_ps(scal_7);
											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_6824);
											mem_vec_6824 = vec_39;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_6825);
											mem_vec_6825 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_6826);
											mem_vec_6826 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_6827);
											mem_vec_6827 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_6828);
											mem_vec_6828 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_6829);
											mem_vec_6829 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_6830);
											mem_vec_6830 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_6831);
											mem_vec_6831 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_6832);
											mem_vec_6832 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_6833);
											mem_vec_6833 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_6834);
											mem_vec_6834 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_6835);
											mem_vec_6835 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_6836);
											mem_vec_6836 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_6837);
											mem_vec_6837 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_6838);
											mem_vec_6838 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_6839);
											mem_vec_6839 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_6840);
											mem_vec_6840 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_6841);
											mem_vec_6841 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_6842);
											mem_vec_6842 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_6843);
											mem_vec_6843 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_69 = _mm256_set1_ps(scal_12);


											vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_6844);
											mem_vec_6844 = vec_68;



											vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_6845);
											mem_vec_6845 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_6846);
											mem_vec_6846 = vec_71;



											vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_6847);
											mem_vec_6847 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_74 = _mm256_set1_ps(scal_13);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_6848);
											mem_vec_6848 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_6849);
											mem_vec_6849 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_6850);
											mem_vec_6850 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_6851);
											mem_vec_6851 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_79 = _mm256_set1_ps(scal_14);
											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_6824);
											mem_vec_6824 = vec_78;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_6825);
											mem_vec_6825 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_6826);
											mem_vec_6826 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_6827);
											mem_vec_6827 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_6828);
											mem_vec_6828 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_6829);
											mem_vec_6829 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_6830);
											mem_vec_6830 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_6831);
											mem_vec_6831 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_6832);
											mem_vec_6832 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_6833);
											mem_vec_6833 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_6834);
											mem_vec_6834 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_6835);
											mem_vec_6835 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_6836);
											mem_vec_6836 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_6837);
											mem_vec_6837 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_6838);
											mem_vec_6838 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_6839);
											mem_vec_6839 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_103 = _mm256_set1_ps(scal_18);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_6840);
											mem_vec_6840 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_6841);
											mem_vec_6841 = vec_104;



											vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_6842);
											mem_vec_6842 = vec_105;



											vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_6843);
											mem_vec_6843 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_108 = _mm256_set1_ps(scal_19);


											vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_6844);
											mem_vec_6844 = vec_107;



											vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_6845);
											mem_vec_6845 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_6846);
											mem_vec_6846 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_6847);
											mem_vec_6847 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_113 = _mm256_set1_ps(scal_20);


											vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_6848);
											mem_vec_6848 = vec_112;



											vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_6849);
											mem_vec_6849 = vec_114;



											vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_6850);
											mem_vec_6850 = vec_115;



											vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_6851);
											mem_vec_6851 = vec_116;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6824);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6825);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6826);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6827);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6828);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6829);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6830);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6831);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6832);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6833);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6834);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6835);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6836);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6837);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6838);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6839);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6840);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6841);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6842);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6843);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6844);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6845);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6846);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_6847);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6848);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6849);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6850);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_6851);
							}
						}
					}
				}
		}
	}
}


}