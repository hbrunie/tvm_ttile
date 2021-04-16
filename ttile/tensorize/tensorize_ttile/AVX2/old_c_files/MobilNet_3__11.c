#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (14, x); T (2, c); T (8, f); T (2, c); T (4, x);
  Lambda_apply y [((Iter 3), (Arg 10)); ((Iter 2), (Arg 13))]]
*/
IND_TYPE c, cp_0, c752_p_0, c753_p_0, cp_1, c752_p_1, cp_2, c752, c753, f, fp_0, w, wp_0, x, xp_0, x564_p_0, xp_1, x564, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y376 = 0;
IND_TYPE x565 = 0;
IND_TYPE h = 0;
IND_TYPE w294 = 0;
IND_TYPE c754 = 0;
IND_TYPE f552 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8590 ,mem_vec_8591 ,mem_vec_8592 ,mem_vec_8593 ,mem_vec_8594 ,mem_vec_8595 ,mem_vec_8596 ,mem_vec_8597 ,mem_vec_8598 ,mem_vec_8599 ,mem_vec_8600 ,mem_vec_8601 ,mem_vec_8602 ,mem_vec_8603 ,mem_vec_8604 ,mem_vec_8605 ,mem_vec_8606 ,mem_vec_8607 ,mem_vec_8608 ,mem_vec_8609 ,mem_vec_8610 ,mem_vec_8611 ,mem_vec_8612 ,mem_vec_8613 ,mem_vec_8614 ,mem_vec_8615 ,mem_vec_8616 ,mem_vec_8617 ,mem_vec_8618 ,mem_vec_8619 ,mem_vec_8620 ,mem_vec_8621 ,mem_vec_8622 ,mem_vec_8623 ,mem_vec_8624 ,mem_vec_8625 ,mem_vec_8626 ,mem_vec_8627 ,mem_vec_8628 ,mem_vec_8629 ,mem_vec_8630 ,mem_vec_8631 ,mem_vec_8632 ,mem_vec_8633 ,mem_vec_8634 ,mem_vec_8635 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
	for (y = y376, yp_0 = 0;
		y < y376 + 30;
		y += 10, yp_0 += 10){
		// y = ph_y, x = 56, h = 3, w = 3, c = 128, f = 128
		// T (x, 4) (56 / 14)
		for (x564 = x565, x564_p_0 = 0;
			x564 < x565 + 56;
			x564 += 14, x564_p_0 += 14){
			// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 128
			// T (c, 2) (128 / 64)
			for (c753 = c754, c753_p_0 = 0;
				c753 < c754 + 128;
				c753 += 64, c753_p_0 += 64){
				// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 128
				// T (f, 8) (128 / 16)
				for (f = f552, fp_0 = 0;
					f < f552 + 128;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 16
					// T (c, 2) (64 / 32)
					for (c752 = c753, c752_p_1 = c753_p_0, c752_p_0 = 0;
						c752 < c753 + 64;
						c752 += 32, c752_p_1 += 32, c752_p_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 16
						// T (x, 14) (14 / 1)
						for (x = x564, xp_1 = x564_p_0, xp_0 = 0;
							x < x564 + 14;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w294, wp_0 = 0;
								w < w294 + 3;
								w += 1, wp_0 += 1){
										mem_vec_8590 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8591 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_8592 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8593 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_8594 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8595 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_8596 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8597 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_8598 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8599 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_8600 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8601 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_8602 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8603 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_8604 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8605 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_8606 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8607 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										mem_vec_8608 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8609 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
										// T (c, 32) (32 / 1)
										for (c = c752, cp_2 = c752_p_1, cp_1 = c752_p_0, cp_0 = 0;
											c < c752 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8590);
											mem_vec_8590 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8591);
											mem_vec_8591 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_8592);
											mem_vec_8592 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_8593);
											mem_vec_8593 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_8594);
											mem_vec_8594 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_8595);
											mem_vec_8595 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_8596);
											mem_vec_8596 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_8597);
											mem_vec_8597 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8598);
											mem_vec_8598 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8599);
											mem_vec_8599 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8600);
											mem_vec_8600 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8601);
											mem_vec_8601 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_8602);
											mem_vec_8602 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_8603);
											mem_vec_8603 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_8604);
											mem_vec_8604 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_8605);
											mem_vec_8605 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8606);
											mem_vec_8606 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8607);
											mem_vec_8607 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8608);
											mem_vec_8608 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8609);
											mem_vec_8609 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_33 = _mm256_set1_ps(scal_10);
											vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_8590);
											mem_vec_8590 = vec_32;

											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_8591);
											mem_vec_8591 = vec_35;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_38 = _mm256_set1_ps(scal_11);


											vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_8592);
											mem_vec_8592 = vec_37;



											vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_8593);
											mem_vec_8593 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_41 = _mm256_set1_ps(scal_12);


											vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_8594);
											mem_vec_8594 = vec_40;



											vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_8595);
											mem_vec_8595 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_8596);
											mem_vec_8596 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_8597);
											mem_vec_8597 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_8598);
											mem_vec_8598 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_8599);
											mem_vec_8599 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_8600);
											mem_vec_8600 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_8601);
											mem_vec_8601 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_8602);
											mem_vec_8602 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_8603);
											mem_vec_8603 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_8604);
											mem_vec_8604 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_8605);
											mem_vec_8605 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_8606);
											mem_vec_8606 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_8607);
											mem_vec_8607 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_8608);
											mem_vec_8608 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_8609);
											mem_vec_8609 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_65 = _mm256_set1_ps(scal_20);
											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_8590);
											mem_vec_8590 = vec_64;

											vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_8591);
											mem_vec_8591 = vec_67;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_70 = _mm256_set1_ps(scal_21);


											vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_8592);
											mem_vec_8592 = vec_69;



											vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_8593);
											mem_vec_8593 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_22);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_8594);
											mem_vec_8594 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_8595);
											mem_vec_8595 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_76 = _mm256_set1_ps(scal_23);


											vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_8596);
											mem_vec_8596 = vec_75;



											vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_8597);
											mem_vec_8597 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_24);


											vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_8598);
											mem_vec_8598 = vec_78;



											vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_8599);
											mem_vec_8599 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_82 = _mm256_set1_ps(scal_25);


											vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_8600);
											mem_vec_8600 = vec_81;



											vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_8601);
											mem_vec_8601 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_85 = _mm256_set1_ps(scal_26);


											vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_8602);
											mem_vec_8602 = vec_84;



											vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_8603);
											mem_vec_8603 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_8604);
											mem_vec_8604 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_8605);
											mem_vec_8605 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);


											vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_8606);
											mem_vec_8606 = vec_90;



											vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_8607);
											mem_vec_8607 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);


											vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_8608);
											mem_vec_8608 = vec_93;



											vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_8609);
											mem_vec_8609 = vec_95;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8590);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8591);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8592);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8593);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8594);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8595);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8596);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8597);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8598);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8599);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8600);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8601);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8602);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8603);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8604);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_8605);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8606);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_8607);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8608);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_8609);
							}
						}
					}
				}
			}
		}
	}
	for (y = y376 + 30, yp_0 = 0;
		y < y376 + 30 + 26;
		y += 13, yp_0 += 13){
		// y = ph_y, x = 56, h = 3, w = 3, c = 128, f = 128
		// T (x, 4) (56 / 14)
		for (x564 = x565, x564_p_0 = 0;
			x564 < x565 + 56;
			x564 += 14, x564_p_0 += 14){
			// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 128
			// T (c, 2) (128 / 64)
			for (c753 = c754, c753_p_0 = 0;
				c753 < c754 + 128;
				c753 += 64, c753_p_0 += 64){
				// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 128
				// T (f, 8) (128 / 16)
				for (f = f552, fp_0 = 0;
					f < f552 + 128;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 16
					// T (c, 2) (64 / 32)
					for (c752 = c753, c752_p_1 = c753_p_0, c752_p_0 = 0;
						c752 < c753 + 64;
						c752 += 32, c752_p_1 += 32, c752_p_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 16
						// T (x, 14) (14 / 1)
						for (x = x564, xp_1 = x564_p_0, xp_0 = 0;
							x < x564 + 14;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w294, wp_0 = 0;
								w < w294 + 3;
								w += 1, wp_0 += 1){
										mem_vec_8610 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8611 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_8612 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8613 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_8614 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8615 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_8616 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8617 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_8618 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8619 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_8620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_8622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_8624 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8625 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_8626 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8627 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										mem_vec_8628 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8629 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
										mem_vec_8630 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_8631 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
										mem_vec_8632 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_8633 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
										mem_vec_8634 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_8635 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
										// T (c, 32) (32 / 1)
										for (c = c752, cp_2 = c752_p_1, cp_1 = c752_p_0, cp_0 = 0;
											c < c752 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8610);
											mem_vec_8610 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8611);
											mem_vec_8611 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_8612);
											mem_vec_8612 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_8613);
											mem_vec_8613 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_8614);
											mem_vec_8614 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_8615);
											mem_vec_8615 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_8616);
											mem_vec_8616 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_8617);
											mem_vec_8617 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8618);
											mem_vec_8618 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8619);
											mem_vec_8619 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8620);
											mem_vec_8620 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8621);
											mem_vec_8621 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_8622);
											mem_vec_8622 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_8623);
											mem_vec_8623 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_8624);
											mem_vec_8624 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_8625);
											mem_vec_8625 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8626);
											mem_vec_8626 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8627);
											mem_vec_8627 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8628);
											mem_vec_8628 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8629);
											mem_vec_8629 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm256_set1_ps(scal_10);


											vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_8630);
											mem_vec_8630 = vec_32;



											vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_8631);
											mem_vec_8631 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm256_set1_ps(scal_11);


											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_8632);
											mem_vec_8632 = vec_35;



											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_8633);
											mem_vec_8633 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm256_set1_ps(scal_12);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_2, mem_vec_8634);
											mem_vec_8634 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_4, mem_vec_8635);
											mem_vec_8635 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_42 = _mm256_set1_ps(scal_13);
											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_41 = _mm256_fmadd_ps(vec_42, vec_43, mem_vec_8610);
											mem_vec_8610 = vec_41;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_44 = _mm256_fmadd_ps(vec_42, vec_45, mem_vec_8611);
											mem_vec_8611 = vec_44;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_43, mem_vec_8612);
											mem_vec_8612 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_45, mem_vec_8613);
											mem_vec_8613 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_43, mem_vec_8614);
											mem_vec_8614 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_45, mem_vec_8615);
											mem_vec_8615 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_8616);
											mem_vec_8616 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_8617);
											mem_vec_8617 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_43, mem_vec_8618);
											mem_vec_8618 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_45, mem_vec_8619);
											mem_vec_8619 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_8620);
											mem_vec_8620 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_8621);
											mem_vec_8621 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_8622);
											mem_vec_8622 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_8623);
											mem_vec_8623 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_65 = _mm256_set1_ps(scal_20);


											vec_64 = _mm256_fmadd_ps(vec_65, vec_43, mem_vec_8624);
											mem_vec_8624 = vec_64;



											vec_66 = _mm256_fmadd_ps(vec_65, vec_45, mem_vec_8625);
											mem_vec_8625 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_68 = _mm256_set1_ps(scal_21);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_43, mem_vec_8626);
											mem_vec_8626 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_45, mem_vec_8627);
											mem_vec_8627 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_71 = _mm256_set1_ps(scal_22);


											vec_70 = _mm256_fmadd_ps(vec_71, vec_43, mem_vec_8628);
											mem_vec_8628 = vec_70;



											vec_72 = _mm256_fmadd_ps(vec_71, vec_45, mem_vec_8629);
											mem_vec_8629 = vec_72;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_23);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_8630);
											mem_vec_8630 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_8631);
											mem_vec_8631 = vec_75;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
											vec_77 = _mm256_set1_ps(scal_24);


											vec_76 = _mm256_fmadd_ps(vec_77, vec_43, mem_vec_8632);
											mem_vec_8632 = vec_76;



											vec_78 = _mm256_fmadd_ps(vec_77, vec_45, mem_vec_8633);
											mem_vec_8633 = vec_78;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
											vec_80 = _mm256_set1_ps(scal_25);


											vec_79 = _mm256_fmadd_ps(vec_80, vec_43, mem_vec_8634);
											mem_vec_8634 = vec_79;



											vec_81 = _mm256_fmadd_ps(vec_80, vec_45, mem_vec_8635);
											mem_vec_8635 = vec_81;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_26);
											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_82 = _mm256_fmadd_ps(vec_83, vec_84, mem_vec_8610);
											mem_vec_8610 = vec_82;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_85 = _mm256_fmadd_ps(vec_83, vec_86, mem_vec_8611);
											mem_vec_8611 = vec_85;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_8612);
											mem_vec_8612 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_8613);
											mem_vec_8613 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);


											vec_90 = _mm256_fmadd_ps(vec_91, vec_84, mem_vec_8614);
											mem_vec_8614 = vec_90;



											vec_92 = _mm256_fmadd_ps(vec_91, vec_86, mem_vec_8615);
											mem_vec_8615 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);


											vec_93 = _mm256_fmadd_ps(vec_94, vec_84, mem_vec_8616);
											mem_vec_8616 = vec_93;



											vec_95 = _mm256_fmadd_ps(vec_94, vec_86, mem_vec_8617);
											mem_vec_8617 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_97 = _mm256_set1_ps(scal_30);


											vec_96 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_8618);
											mem_vec_8618 = vec_96;



											vec_98 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_8619);
											mem_vec_8619 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_100 = _mm256_set1_ps(scal_31);


											vec_99 = _mm256_fmadd_ps(vec_100, vec_84, mem_vec_8620);
											mem_vec_8620 = vec_99;



											vec_101 = _mm256_fmadd_ps(vec_100, vec_86, mem_vec_8621);
											mem_vec_8621 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_32);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_8622);
											mem_vec_8622 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_8623);
											mem_vec_8623 = vec_104;
											scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_106 = _mm256_set1_ps(scal_33);


											vec_105 = _mm256_fmadd_ps(vec_106, vec_84, mem_vec_8624);
											mem_vec_8624 = vec_105;



											vec_107 = _mm256_fmadd_ps(vec_106, vec_86, mem_vec_8625);
											mem_vec_8625 = vec_107;
											scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_109 = _mm256_set1_ps(scal_34);


											vec_108 = _mm256_fmadd_ps(vec_109, vec_84, mem_vec_8626);
											mem_vec_8626 = vec_108;



											vec_110 = _mm256_fmadd_ps(vec_109, vec_86, mem_vec_8627);
											mem_vec_8627 = vec_110;
											scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_112 = _mm256_set1_ps(scal_35);


											vec_111 = _mm256_fmadd_ps(vec_112, vec_84, mem_vec_8628);
											mem_vec_8628 = vec_111;



											vec_113 = _mm256_fmadd_ps(vec_112, vec_86, mem_vec_8629);
											mem_vec_8629 = vec_113;
											scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_115 = _mm256_set1_ps(scal_36);


											vec_114 = _mm256_fmadd_ps(vec_115, vec_84, mem_vec_8630);
											mem_vec_8630 = vec_114;



											vec_116 = _mm256_fmadd_ps(vec_115, vec_86, mem_vec_8631);
											mem_vec_8631 = vec_116;
											scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
											vec_118 = _mm256_set1_ps(scal_37);


											vec_117 = _mm256_fmadd_ps(vec_118, vec_84, mem_vec_8632);
											mem_vec_8632 = vec_117;



											vec_119 = _mm256_fmadd_ps(vec_118, vec_86, mem_vec_8633);
											mem_vec_8633 = vec_119;
											scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
											vec_121 = _mm256_set1_ps(scal_38);


											vec_120 = _mm256_fmadd_ps(vec_121, vec_84, mem_vec_8634);
											mem_vec_8634 = vec_120;



											vec_122 = _mm256_fmadd_ps(vec_121, vec_86, mem_vec_8635);
											mem_vec_8635 = vec_122;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8610);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8611);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8612);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8613);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8614);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8615);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8616);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8617);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8618);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8619);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8620);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8621);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8622);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8623);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8624);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_8625);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8626);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_8627);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8628);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_8629);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8630);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_8631);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8632);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_8633);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_8634);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8], mem_vec_8635);
							}
						}
					}
				}
			}
		}
	}


}