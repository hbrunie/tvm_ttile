#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (28, x);
  T (3, h); T (4, c); T (2, f); T (2, x); T (1, y);
  Lambda_apply y [((Iter 3), (Arg 10)); ((Iter 2), (Arg 13))]]
*/
IND_TYPE c, cp_0, c462_p_0, cp_1, c462, f, fp_0, h, hp_0, x, xp_0, x525_p_0, xp_1, x525, y, yp_0, y393_p_0, yp_1, y393;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y394 = 0;
IND_TYPE x526 = 0;
IND_TYPE h227 = 0;
IND_TYPE w = 0;
IND_TYPE c463 = 0;
IND_TYPE f285 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3769 ,mem_vec_3770 ,mem_vec_3771 ,mem_vec_3772 ,mem_vec_3773 ,mem_vec_3774 ,mem_vec_3775 ,mem_vec_3776 ,mem_vec_3777 ,mem_vec_3778 ,mem_vec_3779 ,mem_vec_3780 ,mem_vec_3781 ,mem_vec_3782 ,mem_vec_3783 ,mem_vec_3784 ,mem_vec_3785 ,mem_vec_3786 ,mem_vec_3787 ,mem_vec_3788 ,mem_vec_3789 ,mem_vec_3790 ,mem_vec_3791 ,mem_vec_3792 ,mem_vec_3793 ,mem_vec_3794 ,mem_vec_3795 ,mem_vec_3796 ,mem_vec_3797 ,mem_vec_3798 ,mem_vec_3799 ,mem_vec_3800 ,mem_vec_3801 ,mem_vec_3802 ,mem_vec_3803 ,mem_vec_3804 ,mem_vec_3805 ,mem_vec_3806 ,mem_vec_3807 ,mem_vec_3808 ,mem_vec_3809 ,mem_vec_3810 ,mem_vec_3811 ,mem_vec_3812 ,mem_vec_3813 ,mem_vec_3814 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
	for (y393 = y394, y393_p_0 = 0;
		y393 < y394 + 30;
		y393 += 10, y393_p_0 += 10){
		// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
		// T (y, 1) (ph_y / ph_y)
		for (y = y393, yp_1 = y393_p_0, yp_0 = 0;
			y < y393 + 10;
			y += 10, yp_1 += 10, yp_0 += 10){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 2) (56 / 28)
			for (x525 = x526, x525_p_0 = 0;
				x525 < x526 + 56;
				x525 += 28, x525_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f285, fp_0 = 0;
					f < f285 + 64;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c462 = c463, c462_p_0 = 0;
						c462 < c463 + 64;
						c462 += 16, c462_p_0 += 16){
						// y = ph_y, x = 28, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h227, hp_0 = 0;
							h < h227 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 16, f = 32
							// T (x, 28) (28 / 1)
							for (x = x525, xp_1 = x525_p_0, xp_0 = 0;
								x < x525 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3769 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3770 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_3785 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_3786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_3787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_3788 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c462, cp_1 = c462_p_0, cp_0 = 0;
											c < c462 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3769);
											mem_vec_3769 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3770);
											mem_vec_3770 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3771);
											mem_vec_3771 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3772);
											mem_vec_3772 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3773);
											mem_vec_3773 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3774);
											mem_vec_3774 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3775);
											mem_vec_3775 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3776);
											mem_vec_3776 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3777);
											mem_vec_3777 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3778);
											mem_vec_3778 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3779);
											mem_vec_3779 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3780);
											mem_vec_3780 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3781);
											mem_vec_3781 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3782);
											mem_vec_3782 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3783);
											mem_vec_3783 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3784);
											mem_vec_3784 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3785);
											mem_vec_3785 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3786);
											mem_vec_3786 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3787);
											mem_vec_3787 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3788);
											mem_vec_3788 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_3769);
											mem_vec_3769 = vec_32;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_3770);
											mem_vec_3770 = vec_35;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_3771);
											mem_vec_3771 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_3772);
											mem_vec_3772 = vec_39;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_3773);
											mem_vec_3773 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_3774);
											mem_vec_3774 = vec_42;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_3775);
											mem_vec_3775 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_3776);
											mem_vec_3776 = vec_45;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_3777);
											mem_vec_3777 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_3778);
											mem_vec_3778 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_3779);
											mem_vec_3779 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_3780);
											mem_vec_3780 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_3781);
											mem_vec_3781 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_3782);
											mem_vec_3782 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 7) + h) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_3783);
											mem_vec_3783 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_3784);
											mem_vec_3784 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 8) + h) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_3785);
											mem_vec_3785 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_3786);
											mem_vec_3786 = vec_60;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 9) + h) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_3787);
											mem_vec_3787 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_3788);
											mem_vec_3788 = vec_63;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_65 = _mm512_set1_ps(scal_20);
											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_3769);
											mem_vec_3769 = vec_64;

											vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_3770);
											mem_vec_3770 = vec_67;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_3771);
											mem_vec_3771 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_3772);
											mem_vec_3772 = vec_71;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_3773);
											mem_vec_3773 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_3774);
											mem_vec_3774 = vec_74;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_3775);
											mem_vec_3775 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_3776);
											mem_vec_3776 = vec_77;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_3777);
											mem_vec_3777 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_3778);
											mem_vec_3778 = vec_80;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_3779);
											mem_vec_3779 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_3780);
											mem_vec_3780 = vec_83;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_3781);
											mem_vec_3781 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_3782);
											mem_vec_3782 = vec_86;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 7) + h) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_3783);
											mem_vec_3783 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_3784);
											mem_vec_3784 = vec_89;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 8) + h) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_3785);
											mem_vec_3785 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_3786);
											mem_vec_3786 = vec_92;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 9) + h) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_3787);
											mem_vec_3787 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_3788);
											mem_vec_3788 = vec_95;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3769);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3770);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3771);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3772);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3773);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3774);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3775);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3776);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3777);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3778);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3779);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3780);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3781);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3782);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3783);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3784);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3785);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3786);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3787);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3788);
							}
						}
					}
				}
			}
		}
	}
	for (y393 = y394 + 30, y393_p_0 = 0;
		y393 < y394 + 30 + 26;
		y393 += 13, y393_p_0 += 13){
		// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
		// T (y, 1) (ph_y / ph_y)
		for (y = y393, yp_1 = y393_p_0, yp_0 = 0;
			y < y393 + 13;
			y += 13, yp_1 += 13, yp_0 += 13){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 2) (56 / 28)
			for (x525 = x526, x525_p_0 = 0;
				x525 < x526 + 56;
				x525 += 28, x525_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f285, fp_0 = 0;
					f < f285 + 64;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c462 = c463, c462_p_0 = 0;
						c462 < c463 + 64;
						c462 += 16, c462_p_0 += 16){
						// y = ph_y, x = 28, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h227, hp_0 = 0;
							h < h227 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 16, f = 32
							// T (x, 28) (28 / 1)
							for (x = x525, xp_1 = x525_p_0, xp_0 = 0;
								x < x525 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3789 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3790 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_3805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_3806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_3807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_3808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_3809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_3810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_3811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_3812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_3813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_3814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c462, cp_1 = c462_p_0, cp_0 = 0;
											c < c462 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3789);
											mem_vec_3789 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3790);
											mem_vec_3790 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3791);
											mem_vec_3791 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3792);
											mem_vec_3792 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3793);
											mem_vec_3793 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3794);
											mem_vec_3794 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3795);
											mem_vec_3795 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3796);
											mem_vec_3796 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3797);
											mem_vec_3797 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3798);
											mem_vec_3798 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3799);
											mem_vec_3799 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3800);
											mem_vec_3800 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3801);
											mem_vec_3801 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3802);
											mem_vec_3802 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3803);
											mem_vec_3803 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3804);
											mem_vec_3804 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3805);
											mem_vec_3805 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3806);
											mem_vec_3806 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3807);
											mem_vec_3807 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3808);
											mem_vec_3808 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3809);
											mem_vec_3809 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3810);
											mem_vec_3810 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3811);
											mem_vec_3811 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3812);
											mem_vec_3812 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3813);
											mem_vec_3813 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3814);
											mem_vec_3814 = vec_40;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);
											vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_41 = _mm512_fmadd_ps(vec_42, vec_43, mem_vec_3789);
											mem_vec_3789 = vec_41;

											vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_44 = _mm512_fmadd_ps(vec_42, vec_45, mem_vec_3790);
											mem_vec_3790 = vec_44;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_43, mem_vec_3791);
											mem_vec_3791 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_45, mem_vec_3792);
											mem_vec_3792 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_43, mem_vec_3793);
											mem_vec_3793 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_45, mem_vec_3794);
											mem_vec_3794 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_43, mem_vec_3795);
											mem_vec_3795 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_45, mem_vec_3796);
											mem_vec_3796 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_43, mem_vec_3797);
											mem_vec_3797 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_45, mem_vec_3798);
											mem_vec_3798 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_3799);
											mem_vec_3799 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_3800);
											mem_vec_3800 = vec_60;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_43, mem_vec_3801);
											mem_vec_3801 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_45, mem_vec_3802);
											mem_vec_3802 = vec_63;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 7) + h) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_43, mem_vec_3803);
											mem_vec_3803 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_45, mem_vec_3804);
											mem_vec_3804 = vec_66;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 8) + h) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_43, mem_vec_3805);
											mem_vec_3805 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_45, mem_vec_3806);
											mem_vec_3806 = vec_69;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 9) + h) + c];
											vec_71 = _mm512_set1_ps(scal_22);


											vec_70 = _mm512_fmadd_ps(vec_71, vec_43, mem_vec_3807);
											mem_vec_3807 = vec_70;



											vec_72 = _mm512_fmadd_ps(vec_71, vec_45, mem_vec_3808);
											mem_vec_3808 = vec_72;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 10) + h) + c];
											vec_74 = _mm512_set1_ps(scal_23);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_3809);
											mem_vec_3809 = vec_73;



											vec_75 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_3810);
											mem_vec_3810 = vec_75;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 11) + h) + c];
											vec_77 = _mm512_set1_ps(scal_24);


											vec_76 = _mm512_fmadd_ps(vec_77, vec_43, mem_vec_3811);
											mem_vec_3811 = vec_76;



											vec_78 = _mm512_fmadd_ps(vec_77, vec_45, mem_vec_3812);
											mem_vec_3812 = vec_78;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 12) + h) + c];
											vec_80 = _mm512_set1_ps(scal_25);


											vec_79 = _mm512_fmadd_ps(vec_80, vec_43, mem_vec_3813);
											mem_vec_3813 = vec_79;



											vec_81 = _mm512_fmadd_ps(vec_80, vec_45, mem_vec_3814);
											mem_vec_3814 = vec_81;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_83 = _mm512_set1_ps(scal_26);
											vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_82 = _mm512_fmadd_ps(vec_83, vec_84, mem_vec_3789);
											mem_vec_3789 = vec_82;

											vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_85 = _mm512_fmadd_ps(vec_83, vec_86, mem_vec_3790);
											mem_vec_3790 = vec_85;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_3791);
											mem_vec_3791 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_3792);
											mem_vec_3792 = vec_89;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_84, mem_vec_3793);
											mem_vec_3793 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_86, mem_vec_3794);
											mem_vec_3794 = vec_92;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_84, mem_vec_3795);
											mem_vec_3795 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_86, mem_vec_3796);
											mem_vec_3796 = vec_95;
											scal_30 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_97 = _mm512_set1_ps(scal_30);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_84, mem_vec_3797);
											mem_vec_3797 = vec_96;



											vec_98 = _mm512_fmadd_ps(vec_97, vec_86, mem_vec_3798);
											mem_vec_3798 = vec_98;
											scal_31 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_84, mem_vec_3799);
											mem_vec_3799 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_86, mem_vec_3800);
											mem_vec_3800 = vec_101;
											scal_32 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_3801);
											mem_vec_3801 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_3802);
											mem_vec_3802 = vec_104;
											scal_33 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 7) + h) + c];
											vec_106 = _mm512_set1_ps(scal_33);


											vec_105 = _mm512_fmadd_ps(vec_106, vec_84, mem_vec_3803);
											mem_vec_3803 = vec_105;



											vec_107 = _mm512_fmadd_ps(vec_106, vec_86, mem_vec_3804);
											mem_vec_3804 = vec_107;
											scal_34 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 8) + h) + c];
											vec_109 = _mm512_set1_ps(scal_34);


											vec_108 = _mm512_fmadd_ps(vec_109, vec_84, mem_vec_3805);
											mem_vec_3805 = vec_108;



											vec_110 = _mm512_fmadd_ps(vec_109, vec_86, mem_vec_3806);
											mem_vec_3806 = vec_110;
											scal_35 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 9) + h) + c];
											vec_112 = _mm512_set1_ps(scal_35);


											vec_111 = _mm512_fmadd_ps(vec_112, vec_84, mem_vec_3807);
											mem_vec_3807 = vec_111;



											vec_113 = _mm512_fmadd_ps(vec_112, vec_86, mem_vec_3808);
											mem_vec_3808 = vec_113;
											scal_36 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 10) + h) + c];
											vec_115 = _mm512_set1_ps(scal_36);


											vec_114 = _mm512_fmadd_ps(vec_115, vec_84, mem_vec_3809);
											mem_vec_3809 = vec_114;



											vec_116 = _mm512_fmadd_ps(vec_115, vec_86, mem_vec_3810);
											mem_vec_3810 = vec_116;
											scal_37 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 11) + h) + c];
											vec_118 = _mm512_set1_ps(scal_37);


											vec_117 = _mm512_fmadd_ps(vec_118, vec_84, mem_vec_3811);
											mem_vec_3811 = vec_117;



											vec_119 = _mm512_fmadd_ps(vec_118, vec_86, mem_vec_3812);
											mem_vec_3812 = vec_119;
											scal_38 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 12) + h) + c];
											vec_121 = _mm512_set1_ps(scal_38);


											vec_120 = _mm512_fmadd_ps(vec_121, vec_84, mem_vec_3813);
											mem_vec_3813 = vec_120;



											vec_122 = _mm512_fmadd_ps(vec_121, vec_86, mem_vec_3814);
											mem_vec_3814 = vec_122;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3789);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3790);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3791);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3792);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3793);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3794);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3795);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3796);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3797);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3798);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3799);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3800);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3801);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3802);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3803);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3804);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3805);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3806);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3807);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3808);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3809);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3810);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3811);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3812);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3813);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_3814);
							}
						}
					}
				}
			}
		}
	}


}