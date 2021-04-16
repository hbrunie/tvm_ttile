#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (34, x); T (8, c);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (2, f);
  T (2, c); T (8, f)]
*/
IND_TYPE c, cp_0, c339_p_0, c340_p_0, cp_1, c339_p_1, cp_2, c339, c340, f, fp_0, f277_p_0, fp_1, f277, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y201 = 0;
IND_TYPE x176 = 0;
IND_TYPE h = 0;
IND_TYPE w154 = 0;
IND_TYPE c341 = 0;
IND_TYPE f278 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3760 ,mem_vec_3761 ,mem_vec_3762 ,mem_vec_3763 ,mem_vec_3764 ,mem_vec_3765 ,mem_vec_3766 ,mem_vec_3767 ,mem_vec_3768 ,mem_vec_3769 ,mem_vec_3770 ,mem_vec_3771 ,mem_vec_3772 ,mem_vec_3773 ,mem_vec_3774 ,mem_vec_3775 ,mem_vec_3776 ,mem_vec_3777 ,mem_vec_3778 ,mem_vec_3779 ,mem_vec_3780 ,mem_vec_3781 ,mem_vec_3782 ,mem_vec_3783 ,mem_vec_3784 ,mem_vec_3785 ,mem_vec_3786 ,mem_vec_3787 ,mem_vec_3788 ,mem_vec_3789 ,mem_vec_3790 ,mem_vec_3791 ,mem_vec_3792 ,mem_vec_3793 ,mem_vec_3794 ,mem_vec_3795 ,mem_vec_3796 ,mem_vec_3797 ,mem_vec_3798 ,mem_vec_3799 ,mem_vec_3800 ,mem_vec_3801 ,mem_vec_3802 ,mem_vec_3803 ,mem_vec_3804 ,mem_vec_3805 ,mem_vec_3806 ,mem_vec_3807 ,mem_vec_3808 ,mem_vec_3809 ,mem_vec_3810 ,mem_vec_3811 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 8) (512 / 64)
for (f277 = f278, f277_p_0 = 0;
	f277 < f278 + 512;
	f277 += 64, f277_p_0 += 64){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 64
	// T (c, 2) (256 / 128)
	for (c340 = c341, c340_p_0 = 0;
		c340 < c341 + 256;
		c340 += 128, c340_p_0 += 128){
		// y = 34, x = 34, h = 3, w = 3, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f277, fp_1 = f277_p_0, fp_0 = 0;
			f < f277 + 64;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y201, yp_0 = 0;
					y < y201 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (c, 8) (128 / 16)
					for (c339 = c340, c339_p_1 = c340_p_0, c339_p_0 = 0;
						c339 < c340 + 128;
						c339 += 16, c339_p_1 += 16, c339_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (x, 34) (34 / 1)
						for (x = x176, xp_0 = 0;
							x < x176 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w154, wp_0 = 0;
								w < w154 + 3;
								w += 1, wp_0 += 1){
										mem_vec_3760 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3761 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_3762 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3763 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_3764 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3765 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_3766 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3767 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_3768 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3769 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_3770 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3771 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_3772 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3773 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_3774 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3775 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_3776 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3777 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_3778 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3779 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_3780 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3781 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_3782 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3783 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c339, cp_2 = c339_p_1, cp_1 = c339_p_0, cp_0 = 0;
											c < c339 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3760);
											mem_vec_3760 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3761);
											mem_vec_3761 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3762);
											mem_vec_3762 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3763);
											mem_vec_3763 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3764);
											mem_vec_3764 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3765);
											mem_vec_3765 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3766);
											mem_vec_3766 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3767);
											mem_vec_3767 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3768);
											mem_vec_3768 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3769);
											mem_vec_3769 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3770);
											mem_vec_3770 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3771);
											mem_vec_3771 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3772);
											mem_vec_3772 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3773);
											mem_vec_3773 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3774);
											mem_vec_3774 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3775);
											mem_vec_3775 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_3776);
											mem_vec_3776 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_3777);
											mem_vec_3777 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_3778);
											mem_vec_3778 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_3779);
											mem_vec_3779 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_3780);
											mem_vec_3780 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_3781);
											mem_vec_3781 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_3782);
											mem_vec_3782 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_3783);
											mem_vec_3783 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_3760);
											mem_vec_3760 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_3761);
											mem_vec_3761 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_3762);
											mem_vec_3762 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_3763);
											mem_vec_3763 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_3764);
											mem_vec_3764 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_3765);
											mem_vec_3765 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_3766);
											mem_vec_3766 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_3767);
											mem_vec_3767 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_3768);
											mem_vec_3768 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_3769);
											mem_vec_3769 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_3770);
											mem_vec_3770 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_3771);
											mem_vec_3771 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_3772);
											mem_vec_3772 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_3773);
											mem_vec_3773 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_3774);
											mem_vec_3774 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_3775);
											mem_vec_3775 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_3776);
											mem_vec_3776 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_3777);
											mem_vec_3777 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_3778);
											mem_vec_3778 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_3779);
											mem_vec_3779 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_3780);
											mem_vec_3780 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_3781);
											mem_vec_3781 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_3782);
											mem_vec_3782 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_3783);
											mem_vec_3783 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_3760);
											mem_vec_3760 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_3761);
											mem_vec_3761 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_3762);
											mem_vec_3762 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_3763);
											mem_vec_3763 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_3764);
											mem_vec_3764 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_3765);
											mem_vec_3765 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_3766);
											mem_vec_3766 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_3767);
											mem_vec_3767 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_3768);
											mem_vec_3768 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_3769);
											mem_vec_3769 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_3770);
											mem_vec_3770 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_3771);
											mem_vec_3771 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_3772);
											mem_vec_3772 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_3773);
											mem_vec_3773 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_3774);
											mem_vec_3774 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_3775);
											mem_vec_3775 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_3776);
											mem_vec_3776 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_3777);
											mem_vec_3777 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_3778);
											mem_vec_3778 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_3779);
											mem_vec_3779 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_3780);
											mem_vec_3780 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_3781);
											mem_vec_3781 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_3782);
											mem_vec_3782 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_3783);
											mem_vec_3783 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3760);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3761);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3762);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3763);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3764);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3765);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3766);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3767);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3768);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3769);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3770);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3771);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3772);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3773);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3774);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3775);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3776);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3777);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3778);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_3779);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3780);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3781);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3782);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_3783);
							}
						}
					}
				}
				for (y = y201 + 6, yp_0 = 0;
					y < y201 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (c, 8) (128 / 16)
					for (c339 = c340, c339_p_1 = c340_p_0, c339_p_0 = 0;
						c339 < c340 + 128;
						c339 += 16, c339_p_1 += 16, c339_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (x, 34) (34 / 1)
						for (x = x176, xp_0 = 0;
							x < x176 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w154, wp_0 = 0;
								w < w154 + 3;
								w += 1, wp_0 += 1){
										mem_vec_3784 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3785 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_3786 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3787 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_3788 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3789 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_3790 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3791 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_3792 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3793 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_3794 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3795 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_3796 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3797 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_3798 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3799 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_3800 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3801 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_3802 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3803 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_3804 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3805 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_3806 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3807 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										mem_vec_3808 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3809 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_3810 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3811 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c339, cp_2 = c339_p_1, cp_1 = c339_p_0, cp_0 = 0;
											c < c339 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3784);
											mem_vec_3784 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3785);
											mem_vec_3785 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3786);
											mem_vec_3786 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3787);
											mem_vec_3787 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3788);
											mem_vec_3788 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3789);
											mem_vec_3789 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3790);
											mem_vec_3790 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3791);
											mem_vec_3791 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3792);
											mem_vec_3792 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3793);
											mem_vec_3793 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3794);
											mem_vec_3794 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3795);
											mem_vec_3795 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3796);
											mem_vec_3796 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3797);
											mem_vec_3797 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3798);
											mem_vec_3798 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3799);
											mem_vec_3799 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_3800);
											mem_vec_3800 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_3801);
											mem_vec_3801 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_3802);
											mem_vec_3802 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_3803);
											mem_vec_3803 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_3804);
											mem_vec_3804 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_3805);
											mem_vec_3805 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_3806);
											mem_vec_3806 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_3807);
											mem_vec_3807 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_3808);
											mem_vec_3808 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_3809);
											mem_vec_3809 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_3810);
											mem_vec_3810 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_3811);
											mem_vec_3811 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_40 = _mm256_set1_ps(scal_7);
											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_3784);
											mem_vec_3784 = vec_39;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_3785);
											mem_vec_3785 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_3786);
											mem_vec_3786 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_3787);
											mem_vec_3787 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_3788);
											mem_vec_3788 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_3789);
											mem_vec_3789 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_3790);
											mem_vec_3790 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_3791);
											mem_vec_3791 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_3792);
											mem_vec_3792 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_3793);
											mem_vec_3793 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_3794);
											mem_vec_3794 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_3795);
											mem_vec_3795 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_3796);
											mem_vec_3796 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_3797);
											mem_vec_3797 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_3798);
											mem_vec_3798 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_3799);
											mem_vec_3799 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_3800);
											mem_vec_3800 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_3801);
											mem_vec_3801 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_3802);
											mem_vec_3802 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_3803);
											mem_vec_3803 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_69 = _mm256_set1_ps(scal_12);


											vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_3804);
											mem_vec_3804 = vec_68;



											vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_3805);
											mem_vec_3805 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_3806);
											mem_vec_3806 = vec_71;



											vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_3807);
											mem_vec_3807 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_13);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_3808);
											mem_vec_3808 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_3809);
											mem_vec_3809 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_3810);
											mem_vec_3810 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_3811);
											mem_vec_3811 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_14);
											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_3784);
											mem_vec_3784 = vec_78;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_3785);
											mem_vec_3785 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_3786);
											mem_vec_3786 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_3787);
											mem_vec_3787 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_3788);
											mem_vec_3788 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_3789);
											mem_vec_3789 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_3790);
											mem_vec_3790 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_3791);
											mem_vec_3791 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_3792);
											mem_vec_3792 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_3793);
											mem_vec_3793 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_3794);
											mem_vec_3794 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_3795);
											mem_vec_3795 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_3796);
											mem_vec_3796 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_3797);
											mem_vec_3797 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_3798);
											mem_vec_3798 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_3799);
											mem_vec_3799 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_18);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_3800);
											mem_vec_3800 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_3801);
											mem_vec_3801 = vec_104;



											vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_3802);
											mem_vec_3802 = vec_105;



											vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_3803);
											mem_vec_3803 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_108 = _mm256_set1_ps(scal_19);


											vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_3804);
											mem_vec_3804 = vec_107;



											vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_3805);
											mem_vec_3805 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_3806);
											mem_vec_3806 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_3807);
											mem_vec_3807 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_113 = _mm256_set1_ps(scal_20);


											vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_3808);
											mem_vec_3808 = vec_112;



											vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_3809);
											mem_vec_3809 = vec_114;



											vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_3810);
											mem_vec_3810 = vec_115;



											vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_3811);
											mem_vec_3811 = vec_116;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3784);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3785);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3786);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3787);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3788);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3789);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3790);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3791);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3792);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3793);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3794);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3795);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3796);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3797);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3798);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3799);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3800);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3801);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3802);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_3803);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3804);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3805);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3806);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_3807);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3808);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3809);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3810);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_3811);
							}
						}
					}
				}
		}
	}
}


}