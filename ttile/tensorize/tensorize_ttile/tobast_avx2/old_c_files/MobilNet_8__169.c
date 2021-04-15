#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (8, f);
  T (256, c); T (1, f)]
*/
IND_TYPE c, cp_0, c1122_p_0, cp_1, c1122, f, fp_0, f1496_p_0, f1497_p_0, fp_1, f1496_p_1, fp_2, f1496, f1497, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y748 = 0;
IND_TYPE x748 = 0;
IND_TYPE h600 = 0;
IND_TYPE w = 0;
IND_TYPE c1123 = 0;
IND_TYPE f1498 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_12600 ,mem_vec_12601 ,mem_vec_12602 ,mem_vec_12603 ,mem_vec_12604 ,mem_vec_12605 ,mem_vec_12606 ,mem_vec_12607 ,mem_vec_12608 ,mem_vec_12609 ,mem_vec_12610 ,mem_vec_12611 ,mem_vec_12612 ,mem_vec_12613 ,mem_vec_12614 ,mem_vec_12615 ,mem_vec_12616 ,mem_vec_12617 ,mem_vec_12618 ,mem_vec_12619 ,mem_vec_12620 ,mem_vec_12621 ,mem_vec_12622 ,mem_vec_12623 ,mem_vec_12624 ,mem_vec_12625 ,mem_vec_12626 ,mem_vec_12627 ,mem_vec_12628 ,mem_vec_12629 ,mem_vec_12630 ,mem_vec_12631 ,mem_vec_12632 ,mem_vec_12633 ,mem_vec_12634 ,mem_vec_12635 ,mem_vec_12636 ,mem_vec_12637 ,mem_vec_12638 ,mem_vec_12639 ,mem_vec_12640 ,mem_vec_12641 ,mem_vec_12642 ,mem_vec_12643 ,mem_vec_12644 ,mem_vec_12645 ,mem_vec_12646 ,mem_vec_12647 ,mem_vec_12648 ,mem_vec_12649 ,mem_vec_12650 ,mem_vec_12651 ,mem_vec_12652 ,mem_vec_12653 ,mem_vec_12654 ,mem_vec_12655 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (f, 1) (512 / 512)
for (f1497 = f1498, f1497_p_0 = 0;
	f1497 < f1498 + 512;
	f1497 += 512, f1497_p_0 += 512){
	// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
	// T (c, 256) (512 / 2)
	for (c1122 = c1123, c1122_p_0 = 0;
		c1122 < c1123 + 512;
		c1122 += 2, c1122_p_0 += 2){
		// y = 7, x = 7, h = 3, w = 3, c = 2, f = 512
		// T (f, 8) (512 / 64)
		for (f1496 = f1497, f1496_p_1 = f1497_p_0, f1496_p_0 = 0;
			f1496 < f1497 + 512;
			f1496 += 64, f1496_p_1 += 64, f1496_p_0 += 64){
				for (y = y748, yp_0 = 0;
					y < y748 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1496, fp_2 = f1496_p_1, fp_1 = f1496_p_0, fp_0 = 0;
						f < f1496 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
						// T (h, 3) (3 / 1)
						for (h = h600, hp_0 = 0;
							h < h600 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 2, f = 64
							// T (x, 7) (7 / 1)
							for (x = x748, xp_0 = 0;
								x < x748 + 7;
								x += 1, xp_0 += 1){
										mem_vec_12600 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_12601 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_12602 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_12603 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_12604 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_12605 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
										mem_vec_12606 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_12607 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
										mem_vec_12608 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_12609 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_12610 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_12611 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_12612 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_12613 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
										mem_vec_12614 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_12615 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
										mem_vec_12616 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_12617 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_12618 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_12619 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_12620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_12621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
										mem_vec_12622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_12623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c1122, cp_1 = c1122_p_0, cp_0 = 0;
											c < c1122 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12600);
											mem_vec_12600 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12601);
											mem_vec_12601 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12602);
											mem_vec_12602 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12603);
											mem_vec_12603 = vec_7;

											vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_12604);
											mem_vec_12604 = vec_9;

											vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

											vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_12605);
											mem_vec_12605 = vec_11;

											vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_12606);
											mem_vec_12606 = vec_13;

											vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

											vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_12607);
											mem_vec_12607 = vec_15;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_18 = _mm256_set1_ps(scal_1);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_12608);
											mem_vec_12608 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_12609);
											mem_vec_12609 = vec_19;



											vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_12610);
											mem_vec_12610 = vec_20;



											vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_12611);
											mem_vec_12611 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_12612);
											mem_vec_12612 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_12613);
											mem_vec_12613 = vec_23;



											vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_12614);
											mem_vec_12614 = vec_24;



											vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_12615);
											mem_vec_12615 = vec_25;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_27 = _mm256_set1_ps(scal_2);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_12616);
											mem_vec_12616 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_12617);
											mem_vec_12617 = vec_28;



											vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_12618);
											mem_vec_12618 = vec_29;



											vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_12619);
											mem_vec_12619 = vec_30;



											vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_12620);
											mem_vec_12620 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_12621);
											mem_vec_12621 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_12622);
											mem_vec_12622 = vec_33;



											vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_12623);
											mem_vec_12623 = vec_34;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_36 = _mm256_set1_ps(scal_3);
											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_12600);
											mem_vec_12600 = vec_35;

											vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_12601);
											mem_vec_12601 = vec_38;

											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_40 = _mm256_fmadd_ps(vec_36, vec_41, mem_vec_12602);
											mem_vec_12602 = vec_40;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_42 = _mm256_fmadd_ps(vec_36, vec_43, mem_vec_12603);
											mem_vec_12603 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_44 = _mm256_fmadd_ps(vec_36, vec_45, mem_vec_12604);
											mem_vec_12604 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

											vec_46 = _mm256_fmadd_ps(vec_36, vec_47, mem_vec_12605);
											mem_vec_12605 = vec_46;

											vec_49 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_48 = _mm256_fmadd_ps(vec_36, vec_49, mem_vec_12606);
											mem_vec_12606 = vec_48;

											vec_51 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

											vec_50 = _mm256_fmadd_ps(vec_36, vec_51, mem_vec_12607);
											mem_vec_12607 = vec_50;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_53 = _mm256_set1_ps(scal_4);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_12608);
											mem_vec_12608 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_12609);
											mem_vec_12609 = vec_54;



											vec_55 = _mm256_fmadd_ps(vec_53, vec_41, mem_vec_12610);
											mem_vec_12610 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_12611);
											mem_vec_12611 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_12612);
											mem_vec_12612 = vec_57;



											vec_58 = _mm256_fmadd_ps(vec_53, vec_47, mem_vec_12613);
											mem_vec_12613 = vec_58;



											vec_59 = _mm256_fmadd_ps(vec_53, vec_49, mem_vec_12614);
											mem_vec_12614 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_53, vec_51, mem_vec_12615);
											mem_vec_12615 = vec_60;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_62 = _mm256_set1_ps(scal_5);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_12616);
											mem_vec_12616 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_12617);
											mem_vec_12617 = vec_63;



											vec_64 = _mm256_fmadd_ps(vec_62, vec_41, mem_vec_12618);
											mem_vec_12618 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_12619);
											mem_vec_12619 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_12620);
											mem_vec_12620 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_62, vec_47, mem_vec_12621);
											mem_vec_12621 = vec_67;



											vec_68 = _mm256_fmadd_ps(vec_62, vec_49, mem_vec_12622);
											mem_vec_12622 = vec_68;



											vec_69 = _mm256_fmadd_ps(vec_62, vec_51, mem_vec_12623);
											mem_vec_12623 = vec_69;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_71 = _mm256_set1_ps(scal_6);
											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_12600);
											mem_vec_12600 = vec_70;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_12601);
											mem_vec_12601 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_75 = _mm256_fmadd_ps(vec_71, vec_76, mem_vec_12602);
											mem_vec_12602 = vec_75;

											vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_77 = _mm256_fmadd_ps(vec_71, vec_78, mem_vec_12603);
											mem_vec_12603 = vec_77;

											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_79 = _mm256_fmadd_ps(vec_71, vec_80, mem_vec_12604);
											mem_vec_12604 = vec_79;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

											vec_81 = _mm256_fmadd_ps(vec_71, vec_82, mem_vec_12605);
											mem_vec_12605 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_83 = _mm256_fmadd_ps(vec_71, vec_84, mem_vec_12606);
											mem_vec_12606 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

											vec_85 = _mm256_fmadd_ps(vec_71, vec_86, mem_vec_12607);
											mem_vec_12607 = vec_85;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_88 = _mm256_set1_ps(scal_7);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_12608);
											mem_vec_12608 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_12609);
											mem_vec_12609 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_12610);
											mem_vec_12610 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_12611);
											mem_vec_12611 = vec_91;



											vec_92 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_12612);
											mem_vec_12612 = vec_92;



											vec_93 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_12613);
											mem_vec_12613 = vec_93;



											vec_94 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_12614);
											mem_vec_12614 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_12615);
											mem_vec_12615 = vec_95;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_97 = _mm256_set1_ps(scal_8);


											vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_12616);
											mem_vec_12616 = vec_96;



											vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_12617);
											mem_vec_12617 = vec_98;



											vec_99 = _mm256_fmadd_ps(vec_97, vec_76, mem_vec_12618);
											mem_vec_12618 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_12619);
											mem_vec_12619 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_12620);
											mem_vec_12620 = vec_101;



											vec_102 = _mm256_fmadd_ps(vec_97, vec_82, mem_vec_12621);
											mem_vec_12621 = vec_102;



											vec_103 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_12622);
											mem_vec_12622 = vec_103;



											vec_104 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_12623);
											mem_vec_12623 = vec_104;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12600);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12601);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12602);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12603);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_12604);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_12605);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_12606);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_12607);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12608);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12609);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12610);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12611);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_12612);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_12613);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_12614);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_12615);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12616);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12617);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12618);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12619);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_12620);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_12621);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_12622);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_12623);
							}
						}
					}
				}
				for (y = y748 + 3, yp_0 = 0;
					y < y748 + 3 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1496, fp_2 = f1496_p_1, fp_1 = f1496_p_0, fp_0 = 0;
						f < f1496 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
						// T (h, 3) (3 / 1)
						for (h = h600, hp_0 = 0;
							h < h600 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 2, f = 64
							// T (x, 7) (7 / 1)
							for (x = x748, xp_0 = 0;
								x < x748 + 7;
								x += 1, xp_0 += 1){
										mem_vec_12624 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_12625 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_12626 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_12627 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_12628 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_12629 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
										mem_vec_12630 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_12631 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
										mem_vec_12632 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_12633 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_12634 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_12635 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_12636 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_12637 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
										mem_vec_12638 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_12639 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
										mem_vec_12640 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_12641 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_12642 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_12643 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_12644 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_12645 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
										mem_vec_12646 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_12647 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
										mem_vec_12648 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_12649 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_12650 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_12651 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_12652 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_12653 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
										mem_vec_12654 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_12655 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c1122, cp_1 = c1122_p_0, cp_0 = 0;
											c < c1122 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12624);
											mem_vec_12624 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12625);
											mem_vec_12625 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12626);
											mem_vec_12626 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12627);
											mem_vec_12627 = vec_7;

											vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_12628);
											mem_vec_12628 = vec_9;

											vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

											vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_12629);
											mem_vec_12629 = vec_11;

											vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_12630);
											mem_vec_12630 = vec_13;

											vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

											vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_12631);
											mem_vec_12631 = vec_15;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_18 = _mm256_set1_ps(scal_1);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_12632);
											mem_vec_12632 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_12633);
											mem_vec_12633 = vec_19;



											vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_12634);
											mem_vec_12634 = vec_20;



											vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_12635);
											mem_vec_12635 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_12636);
											mem_vec_12636 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_12637);
											mem_vec_12637 = vec_23;



											vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_12638);
											mem_vec_12638 = vec_24;



											vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_12639);
											mem_vec_12639 = vec_25;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_27 = _mm256_set1_ps(scal_2);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_12640);
											mem_vec_12640 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_12641);
											mem_vec_12641 = vec_28;



											vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_12642);
											mem_vec_12642 = vec_29;



											vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_12643);
											mem_vec_12643 = vec_30;



											vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_12644);
											mem_vec_12644 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_12645);
											mem_vec_12645 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_12646);
											mem_vec_12646 = vec_33;



											vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_12647);
											mem_vec_12647 = vec_34;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_36 = _mm256_set1_ps(scal_3);


											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_12648);
											mem_vec_12648 = vec_35;



											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_12649);
											mem_vec_12649 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_12650);
											mem_vec_12650 = vec_38;



											vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_12651);
											mem_vec_12651 = vec_39;



											vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_12652);
											mem_vec_12652 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_12653);
											mem_vec_12653 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_12654);
											mem_vec_12654 = vec_42;



											vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_12655);
											mem_vec_12655 = vec_43;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_45 = _mm256_set1_ps(scal_4);
											vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_12624);
											mem_vec_12624 = vec_44;

											vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_12625);
											mem_vec_12625 = vec_47;

											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_12626);
											mem_vec_12626 = vec_49;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_12627);
											mem_vec_12627 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_12628);
											mem_vec_12628 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

											vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_12629);
											mem_vec_12629 = vec_55;

											vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_12630);
											mem_vec_12630 = vec_57;

											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

											vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_12631);
											mem_vec_12631 = vec_59;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_62 = _mm256_set1_ps(scal_5);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_12632);
											mem_vec_12632 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_12633);
											mem_vec_12633 = vec_63;



											vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_12634);
											mem_vec_12634 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_12635);
											mem_vec_12635 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_12636);
											mem_vec_12636 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_12637);
											mem_vec_12637 = vec_67;



											vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_12638);
											mem_vec_12638 = vec_68;



											vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_12639);
											mem_vec_12639 = vec_69;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_71 = _mm256_set1_ps(scal_6);


											vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_12640);
											mem_vec_12640 = vec_70;



											vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_12641);
											mem_vec_12641 = vec_72;



											vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_12642);
											mem_vec_12642 = vec_73;



											vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_12643);
											mem_vec_12643 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_12644);
											mem_vec_12644 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_12645);
											mem_vec_12645 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_12646);
											mem_vec_12646 = vec_77;



											vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_12647);
											mem_vec_12647 = vec_78;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_80 = _mm256_set1_ps(scal_7);


											vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_12648);
											mem_vec_12648 = vec_79;



											vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_12649);
											mem_vec_12649 = vec_81;



											vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_12650);
											mem_vec_12650 = vec_82;



											vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_12651);
											mem_vec_12651 = vec_83;



											vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_12652);
											mem_vec_12652 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_12653);
											mem_vec_12653 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_12654);
											mem_vec_12654 = vec_86;



											vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_12655);
											mem_vec_12655 = vec_87;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_89 = _mm256_set1_ps(scal_8);
											vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_12624);
											mem_vec_12624 = vec_88;

											vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_12625);
											mem_vec_12625 = vec_91;

											vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_12626);
											mem_vec_12626 = vec_93;

											vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_12627);
											mem_vec_12627 = vec_95;

											vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_12628);
											mem_vec_12628 = vec_97;

											vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

											vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_12629);
											mem_vec_12629 = vec_99;

											vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_12630);
											mem_vec_12630 = vec_101;

											vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

											vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_12631);
											mem_vec_12631 = vec_103;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_106 = _mm256_set1_ps(scal_9);


											vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_12632);
											mem_vec_12632 = vec_105;



											vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_12633);
											mem_vec_12633 = vec_107;



											vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_12634);
											mem_vec_12634 = vec_108;



											vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_12635);
											mem_vec_12635 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_12636);
											mem_vec_12636 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_12637);
											mem_vec_12637 = vec_111;



											vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_12638);
											mem_vec_12638 = vec_112;



											vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_12639);
											mem_vec_12639 = vec_113;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_115 = _mm256_set1_ps(scal_10);


											vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_12640);
											mem_vec_12640 = vec_114;



											vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_12641);
											mem_vec_12641 = vec_116;



											vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_12642);
											mem_vec_12642 = vec_117;



											vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_12643);
											mem_vec_12643 = vec_118;



											vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_12644);
											mem_vec_12644 = vec_119;



											vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_12645);
											mem_vec_12645 = vec_120;



											vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_12646);
											mem_vec_12646 = vec_121;



											vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_12647);
											mem_vec_12647 = vec_122;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_124 = _mm256_set1_ps(scal_11);


											vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_12648);
											mem_vec_12648 = vec_123;



											vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_12649);
											mem_vec_12649 = vec_125;



											vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_12650);
											mem_vec_12650 = vec_126;



											vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_12651);
											mem_vec_12651 = vec_127;



											vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_12652);
											mem_vec_12652 = vec_128;



											vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_12653);
											mem_vec_12653 = vec_129;



											vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_12654);
											mem_vec_12654 = vec_130;



											vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_12655);
											mem_vec_12655 = vec_131;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12624);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12625);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12626);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12627);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_12628);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_12629);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_12630);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_12631);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12632);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12633);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12634);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12635);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_12636);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_12637);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_12638);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_12639);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12640);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12641);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12642);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12643);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_12644);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_12645);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_12646);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_12647);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12648);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12649);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12650);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12651);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_12652);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_12653);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_12654);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_12655);
							}
						}
					}
				}
		}
	}
}


}