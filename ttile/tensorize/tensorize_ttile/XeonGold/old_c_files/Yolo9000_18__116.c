#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (3, h);
  T (17, x); T (2, c);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]; T (16, f);
  T (8, c); T (1, c)]
*/
IND_TYPE c, cp_0, c825_p_0, c826_p_0, c827_p_0, cp_1, c825_p_1, c826_p_1, cp_2, c825_p_2, cp_3, c825, c826, c827, f, fp_0, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y330 = 0;
IND_TYPE x330 = 0;
IND_TYPE h276 = 0;
IND_TYPE w = 0;
IND_TYPE c828 = 0;
IND_TYPE f330 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6786 ,mem_vec_6787 ,mem_vec_6788 ,mem_vec_6789 ,mem_vec_6790 ,mem_vec_6791 ,mem_vec_6792 ,mem_vec_6793 ,mem_vec_6794 ,mem_vec_6795 ,mem_vec_6796 ,mem_vec_6797 ,mem_vec_6798 ,mem_vec_6799 ,mem_vec_6800 ,mem_vec_6801 ,mem_vec_6802 ,mem_vec_6803 ,mem_vec_6804 ,mem_vec_6805 ,mem_vec_6806 ,mem_vec_6807 ,mem_vec_6808 ,mem_vec_6809 ,mem_vec_6810 ,mem_vec_6811 ,mem_vec_6812 ,mem_vec_6813 ,mem_vec_6814 ,mem_vec_6815 ,mem_vec_6816 ,mem_vec_6817 ,mem_vec_6818 ,mem_vec_6819 ,mem_vec_6820 ,mem_vec_6821 ,mem_vec_6822 ,mem_vec_6823 ,mem_vec_6824 ,mem_vec_6825 ,mem_vec_6826 ,mem_vec_6827 ,mem_vec_6828 ,mem_vec_6829 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 1) (512 / 512)
for (c827 = c828, c827_p_0 = 0;
	c827 < c828 + 512;
	c827 += 512, c827_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 8) (512 / 64)
	for (c826 = c827, c826_p_1 = c827_p_0, c826_p_0 = 0;
		c826 < c827 + 512;
		c826 += 64, c826_p_1 += 64, c826_p_0 += 64){
		// y = 17, x = 17, h = 3, w = 3, c = 64, f = 1024
		// T (f, 16) (1024 / 64)
		for (f = f330, fp_0 = 0;
			f < f330 + 1024;
			f += 64, fp_0 += 64){
				for (y = y330, yp_0 = 0;
					y < y330 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 64
					// T (c, 2) (64 / 32)
					for (c825 = c826, c825_p_2 = c826_p_1, c825_p_1 = c826_p_0, c825_p_0 = 0;
						c825 < c826 + 64;
						c825 += 32, c825_p_2 += 32, c825_p_1 += 32, c825_p_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x330, xp_0 = 0;
							x < x330 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
							// T (h, 3) (3 / 1)
							for (h = h276, hp_0 = 0;
								h < h276 + 3;
								h += 1, hp_0 += 1){
										mem_vec_6786 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6787 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6788 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_6789 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_6790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_6793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_6794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_6797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_6798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_6801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_6802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_6805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c825, cp_3 = c825_p_2, cp_2 = c825_p_1, cp_1 = c825_p_0, cp_0 = 0;
											c < c825 + 32;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6786);
											mem_vec_6786 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6787);
											mem_vec_6787 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6788);
											mem_vec_6788 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6789);
											mem_vec_6789 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6790);
											mem_vec_6790 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6791);
											mem_vec_6791 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6792);
											mem_vec_6792 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6793);
											mem_vec_6793 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6794);
											mem_vec_6794 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6795);
											mem_vec_6795 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6796);
											mem_vec_6796 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6797);
											mem_vec_6797 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6798);
											mem_vec_6798 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6799);
											mem_vec_6799 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6800);
											mem_vec_6800 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6801);
											mem_vec_6801 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6802);
											mem_vec_6802 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6803);
											mem_vec_6803 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6804);
											mem_vec_6804 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6805);
											mem_vec_6805 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_6786);
											mem_vec_6786 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_6787);
											mem_vec_6787 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_6788);
											mem_vec_6788 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_6789);
											mem_vec_6789 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_6790);
											mem_vec_6790 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_6791);
											mem_vec_6791 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_6792);
											mem_vec_6792 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_6793);
											mem_vec_6793 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_6794);
											mem_vec_6794 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_6795);
											mem_vec_6795 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_6796);
											mem_vec_6796 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_6797);
											mem_vec_6797 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_6798);
											mem_vec_6798 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_6799);
											mem_vec_6799 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_6800);
											mem_vec_6800 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_6801);
											mem_vec_6801 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_6802);
											mem_vec_6802 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_6803);
											mem_vec_6803 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_6804);
											mem_vec_6804 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_6805);
											mem_vec_6805 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_6786);
											mem_vec_6786 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_6787);
											mem_vec_6787 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_6788);
											mem_vec_6788 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_6789);
											mem_vec_6789 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_6790);
											mem_vec_6790 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_6791);
											mem_vec_6791 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_6792);
											mem_vec_6792 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_6793);
											mem_vec_6793 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_6794);
											mem_vec_6794 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_6795);
											mem_vec_6795 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_6796);
											mem_vec_6796 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_6797);
											mem_vec_6797 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_6798);
											mem_vec_6798 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_6799);
											mem_vec_6799 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_6800);
											mem_vec_6800 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_6801);
											mem_vec_6801 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_6802);
											mem_vec_6802 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_6803);
											mem_vec_6803 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_6804);
											mem_vec_6804 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_6805);
											mem_vec_6805 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6786);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6787);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6788);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6789);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6790);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6791);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6792);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6793);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6794);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6795);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6796);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6797);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6798);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6799);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6800);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6801);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6802);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6803);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6804);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6805);
							}
						}
					}
				}
				for (y = y330 + 5, yp_0 = 0;
					y < y330 + 5 + 12;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 64
					// T (c, 2) (64 / 32)
					for (c825 = c826, c825_p_2 = c826_p_1, c825_p_1 = c826_p_0, c825_p_0 = 0;
						c825 < c826 + 64;
						c825 += 32, c825_p_2 += 32, c825_p_1 += 32, c825_p_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x330, xp_0 = 0;
							x < x330 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
							// T (h, 3) (3 / 1)
							for (h = h276, hp_0 = 0;
								h < h276 + 3;
								h += 1, hp_0 += 1){
										mem_vec_6806 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6807 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6808 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_6809 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_6810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_6813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_6814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_6817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_6818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_6821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_6822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_6825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_6826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_6829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c825, cp_3 = c825_p_2, cp_2 = c825_p_1, cp_1 = c825_p_0, cp_0 = 0;
											c < c825 + 32;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6806);
											mem_vec_6806 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6807);
											mem_vec_6807 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6808);
											mem_vec_6808 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6809);
											mem_vec_6809 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6810);
											mem_vec_6810 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6811);
											mem_vec_6811 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6812);
											mem_vec_6812 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6813);
											mem_vec_6813 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6814);
											mem_vec_6814 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6815);
											mem_vec_6815 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6816);
											mem_vec_6816 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6817);
											mem_vec_6817 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6818);
											mem_vec_6818 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6819);
											mem_vec_6819 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6820);
											mem_vec_6820 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6821);
											mem_vec_6821 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6822);
											mem_vec_6822 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6823);
											mem_vec_6823 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6824);
											mem_vec_6824 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6825);
											mem_vec_6825 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6826);
											mem_vec_6826 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6827);
											mem_vec_6827 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_6828);
											mem_vec_6828 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_6829);
											mem_vec_6829 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_6806);
											mem_vec_6806 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_6807);
											mem_vec_6807 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_6808);
											mem_vec_6808 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_6809);
											mem_vec_6809 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_6810);
											mem_vec_6810 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_6811);
											mem_vec_6811 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_6812);
											mem_vec_6812 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_6813);
											mem_vec_6813 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_6814);
											mem_vec_6814 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_6815);
											mem_vec_6815 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_6816);
											mem_vec_6816 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_6817);
											mem_vec_6817 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_6818);
											mem_vec_6818 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_6819);
											mem_vec_6819 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_6820);
											mem_vec_6820 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_6821);
											mem_vec_6821 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_6822);
											mem_vec_6822 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_6823);
											mem_vec_6823 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_6824);
											mem_vec_6824 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_6825);
											mem_vec_6825 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_6826);
											mem_vec_6826 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_6827);
											mem_vec_6827 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_6828);
											mem_vec_6828 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_6829);
											mem_vec_6829 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_6806);
											mem_vec_6806 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_6807);
											mem_vec_6807 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_6808);
											mem_vec_6808 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_6809);
											mem_vec_6809 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_6810);
											mem_vec_6810 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_6811);
											mem_vec_6811 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_6812);
											mem_vec_6812 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_6813);
											mem_vec_6813 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_6814);
											mem_vec_6814 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_6815);
											mem_vec_6815 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_6816);
											mem_vec_6816 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_6817);
											mem_vec_6817 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_6818);
											mem_vec_6818 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_6819);
											mem_vec_6819 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_6820);
											mem_vec_6820 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_6821);
											mem_vec_6821 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_6822);
											mem_vec_6822 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_6823);
											mem_vec_6823 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_6824);
											mem_vec_6824 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_6825);
											mem_vec_6825 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_6826);
											mem_vec_6826 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_6827);
											mem_vec_6827 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_6828);
											mem_vec_6828 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_6829);
											mem_vec_6829 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6806);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6807);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6808);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6809);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6810);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6811);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6812);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6813);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6814);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6815);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6816);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6817);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6818);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6819);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6820);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6821);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6822);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6823);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6824);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6825);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6826);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6827);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_6828);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_6829);
							}
						}
					}
				}
		}
	}
}


}