#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (2, c);
  Lambda_apply y [((Iter 3), (Arg 10)); ((Iter 2), (Arg 13))]; T (4, f);
  T (8, x); T (1, y)]
*/
IND_TYPE c, cp_0, c510_p_0, cp_1, c510, f, fp_0, w, wp_0, x, xp_0, x511_p_0, xp_1, x511, y, yp_0, y353_p_0, yp_1, y353;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y354 = 0;
IND_TYPE x512 = 0;
IND_TYPE h = 0;
IND_TYPE w270 = 0;
IND_TYPE c511 = 0;
IND_TYPE f651 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6606 ,mem_vec_6607 ,mem_vec_6608 ,mem_vec_6609 ,mem_vec_6610 ,mem_vec_6611 ,mem_vec_6612 ,mem_vec_6613 ,mem_vec_6614 ,mem_vec_6615 ,mem_vec_6616 ,mem_vec_6617 ,mem_vec_6618 ,mem_vec_6619 ,mem_vec_6620 ,mem_vec_6621 ,mem_vec_6622 ,mem_vec_6623 ,mem_vec_6624 ,mem_vec_6625 ,mem_vec_6626 ,mem_vec_6627 ,mem_vec_6628 ,mem_vec_6629 ,mem_vec_6630 ,mem_vec_6631 ,mem_vec_6632 ,mem_vec_6633 ,mem_vec_6634 ,mem_vec_6635 ,mem_vec_6636 ,mem_vec_6637 ,mem_vec_6638 ,mem_vec_6639 ,mem_vec_6640 ,mem_vec_6641 ,mem_vec_6642 ,mem_vec_6643 ,mem_vec_6644 ,mem_vec_6645 ,mem_vec_6646 ,mem_vec_6647 ,mem_vec_6648 ,mem_vec_6649 ,mem_vec_6650 ,mem_vec_6651 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y353 = y354, y353_p_0 = 0;
	y353 < y354 + 56;
	y353 += 56, y353_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (x, 8) (56 / 7)
	for (x511 = x512, x511_p_0 = 0;
		x511 < x512 + 56;
		x511 += 7, x511_p_0 += 7){
		// y = 56, x = 7, h = 3, w = 3, c = 64, f = 64
		// T (f, 4) (64 / 16)
		for (f = f651, fp_0 = 0;
			f < f651 + 64;
			f += 16, fp_0 += 16){
				for (y = y353, yp_1 = y353_p_0, yp_0 = 0;
					y < y353 + 30;
					y += 10, yp_1 += 10, yp_0 += 10){
					// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 16
					// T (c, 2) (64 / 32)
					for (c510 = c511, c510_p_0 = 0;
						c510 < c511 + 64;
						c510 += 32, c510_p_0 += 32){
						// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 16
						// T (w, 3) (3 / 1)
						for (w = w270, wp_0 = 0;
							w < w270 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 1, c = 32, f = 16
							// T (x, 7) (7 / 1)
							for (x = x511, xp_1 = x511_p_0, xp_0 = 0;
								x < x511 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6606 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6607 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_6608 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6609 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_6610 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6611 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_6612 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6613 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_6614 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6615 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_6616 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6617 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_6618 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6619 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_6620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_6621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_6622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_6623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										mem_vec_6624 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_6625 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
										// T (c, 32) (32 / 1)
										for (c = c510, cp_1 = c510_p_0, cp_0 = 0;
											c < c510 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6606);
											mem_vec_6606 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6607);
											mem_vec_6607 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_6608);
											mem_vec_6608 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_6609);
											mem_vec_6609 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_6610);
											mem_vec_6610 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_6611);
											mem_vec_6611 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_6612);
											mem_vec_6612 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_6613);
											mem_vec_6613 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6614);
											mem_vec_6614 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6615);
											mem_vec_6615 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_6616);
											mem_vec_6616 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_6617);
											mem_vec_6617 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_6618);
											mem_vec_6618 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_6619);
											mem_vec_6619 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_6620);
											mem_vec_6620 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_6621);
											mem_vec_6621 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_6622);
											mem_vec_6622 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_6623);
											mem_vec_6623 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6624);
											mem_vec_6624 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6625);
											mem_vec_6625 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_33 = _mm256_set1_ps(scal_10);
											vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_6606);
											mem_vec_6606 = vec_32;

											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_6607);
											mem_vec_6607 = vec_35;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_38 = _mm256_set1_ps(scal_11);


											vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_6608);
											mem_vec_6608 = vec_37;



											vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_6609);
											mem_vec_6609 = vec_39;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_41 = _mm256_set1_ps(scal_12);


											vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_6610);
											mem_vec_6610 = vec_40;



											vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_6611);
											mem_vec_6611 = vec_42;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_6612);
											mem_vec_6612 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_6613);
											mem_vec_6613 = vec_45;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_6614);
											mem_vec_6614 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_6615);
											mem_vec_6615 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_6616);
											mem_vec_6616 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_6617);
											mem_vec_6617 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_6618);
											mem_vec_6618 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_6619);
											mem_vec_6619 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_6620);
											mem_vec_6620 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_6621);
											mem_vec_6621 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_6622);
											mem_vec_6622 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_6623);
											mem_vec_6623 = vec_60;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_6624);
											mem_vec_6624 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_6625);
											mem_vec_6625 = vec_63;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_65 = _mm256_set1_ps(scal_20);
											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_6606);
											mem_vec_6606 = vec_64;

											vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_6607);
											mem_vec_6607 = vec_67;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_70 = _mm256_set1_ps(scal_21);


											vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_6608);
											mem_vec_6608 = vec_69;



											vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_6609);
											mem_vec_6609 = vec_71;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_22);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_6610);
											mem_vec_6610 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_6611);
											mem_vec_6611 = vec_74;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_76 = _mm256_set1_ps(scal_23);


											vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_6612);
											mem_vec_6612 = vec_75;



											vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_6613);
											mem_vec_6613 = vec_77;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_24);


											vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_6614);
											mem_vec_6614 = vec_78;



											vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_6615);
											mem_vec_6615 = vec_80;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_82 = _mm256_set1_ps(scal_25);


											vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_6616);
											mem_vec_6616 = vec_81;



											vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_6617);
											mem_vec_6617 = vec_83;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_85 = _mm256_set1_ps(scal_26);


											vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_6618);
											mem_vec_6618 = vec_84;



											vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_6619);
											mem_vec_6619 = vec_86;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_6620);
											mem_vec_6620 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_6621);
											mem_vec_6621 = vec_89;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);


											vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_6622);
											mem_vec_6622 = vec_90;



											vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_6623);
											mem_vec_6623 = vec_92;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);


											vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_6624);
											mem_vec_6624 = vec_93;



											vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_6625);
											mem_vec_6625 = vec_95;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6606);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6607);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6608);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6609);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6610);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6611);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6612);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6613);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6614);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6615);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6616);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6617);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6618);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6619);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6620);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_6621);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6622);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_6623);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6624);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_6625);
							}
						}
					}
				}
				for (y = y353 + 30, yp_1 = y353_p_0, yp_0 = 0;
					y < y353 + 30 + 26;
					y += 13, yp_1 += 13, yp_0 += 13){
					// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 16
					// T (c, 2) (64 / 32)
					for (c510 = c511, c510_p_0 = 0;
						c510 < c511 + 64;
						c510 += 32, c510_p_0 += 32){
						// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 16
						// T (w, 3) (3 / 1)
						for (w = w270, wp_0 = 0;
							w < w270 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 1, c = 32, f = 16
							// T (x, 7) (7 / 1)
							for (x = x511, xp_1 = x511_p_0, xp_0 = 0;
								x < x511 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6626 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6627 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_6628 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6629 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_6630 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6631 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_6632 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6633 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_6634 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6635 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_6636 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6637 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_6638 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6639 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_6640 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_6641 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_6642 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_6643 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										mem_vec_6644 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_6645 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
										mem_vec_6646 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_6647 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
										mem_vec_6648 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_6649 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
										mem_vec_6650 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_6651 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
										// T (c, 32) (32 / 1)
										for (c = c510, cp_1 = c510_p_0, cp_0 = 0;
											c < c510 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6626);
											mem_vec_6626 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6627);
											mem_vec_6627 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_6628);
											mem_vec_6628 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_6629);
											mem_vec_6629 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_6630);
											mem_vec_6630 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_6631);
											mem_vec_6631 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_6632);
											mem_vec_6632 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_6633);
											mem_vec_6633 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6634);
											mem_vec_6634 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6635);
											mem_vec_6635 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_6636);
											mem_vec_6636 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_6637);
											mem_vec_6637 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_6638);
											mem_vec_6638 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_6639);
											mem_vec_6639 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_6640);
											mem_vec_6640 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_6641);
											mem_vec_6641 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_6642);
											mem_vec_6642 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_6643);
											mem_vec_6643 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6644);
											mem_vec_6644 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6645);
											mem_vec_6645 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm256_set1_ps(scal_10);


											vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_6646);
											mem_vec_6646 = vec_32;



											vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_6647);
											mem_vec_6647 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm256_set1_ps(scal_11);


											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_6648);
											mem_vec_6648 = vec_35;



											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_6649);
											mem_vec_6649 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
											vec_39 = _mm256_set1_ps(scal_12);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_2, mem_vec_6650);
											mem_vec_6650 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_4, mem_vec_6651);
											mem_vec_6651 = vec_40;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_42 = _mm256_set1_ps(scal_13);
											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_41 = _mm256_fmadd_ps(vec_42, vec_43, mem_vec_6626);
											mem_vec_6626 = vec_41;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_44 = _mm256_fmadd_ps(vec_42, vec_45, mem_vec_6627);
											mem_vec_6627 = vec_44;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_43, mem_vec_6628);
											mem_vec_6628 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_45, mem_vec_6629);
											mem_vec_6629 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_43, mem_vec_6630);
											mem_vec_6630 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_45, mem_vec_6631);
											mem_vec_6631 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_6632);
											mem_vec_6632 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_6633);
											mem_vec_6633 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_43, mem_vec_6634);
											mem_vec_6634 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_45, mem_vec_6635);
											mem_vec_6635 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_6636);
											mem_vec_6636 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_6637);
											mem_vec_6637 = vec_60;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_6638);
											mem_vec_6638 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_6639);
											mem_vec_6639 = vec_63;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_65 = _mm256_set1_ps(scal_20);


											vec_64 = _mm256_fmadd_ps(vec_65, vec_43, mem_vec_6640);
											mem_vec_6640 = vec_64;



											vec_66 = _mm256_fmadd_ps(vec_65, vec_45, mem_vec_6641);
											mem_vec_6641 = vec_66;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_68 = _mm256_set1_ps(scal_21);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_43, mem_vec_6642);
											mem_vec_6642 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_45, mem_vec_6643);
											mem_vec_6643 = vec_69;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
											vec_71 = _mm256_set1_ps(scal_22);


											vec_70 = _mm256_fmadd_ps(vec_71, vec_43, mem_vec_6644);
											mem_vec_6644 = vec_70;



											vec_72 = _mm256_fmadd_ps(vec_71, vec_45, mem_vec_6645);
											mem_vec_6645 = vec_72;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_23);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_6646);
											mem_vec_6646 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_6647);
											mem_vec_6647 = vec_75;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h + 1) + c];
											vec_77 = _mm256_set1_ps(scal_24);


											vec_76 = _mm256_fmadd_ps(vec_77, vec_43, mem_vec_6648);
											mem_vec_6648 = vec_76;



											vec_78 = _mm256_fmadd_ps(vec_77, vec_45, mem_vec_6649);
											mem_vec_6649 = vec_78;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h + 1) + c];
											vec_80 = _mm256_set1_ps(scal_25);


											vec_79 = _mm256_fmadd_ps(vec_80, vec_43, mem_vec_6650);
											mem_vec_6650 = vec_79;



											vec_81 = _mm256_fmadd_ps(vec_80, vec_45, mem_vec_6651);
											mem_vec_6651 = vec_81;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_26);
											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_82 = _mm256_fmadd_ps(vec_83, vec_84, mem_vec_6626);
											mem_vec_6626 = vec_82;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_85 = _mm256_fmadd_ps(vec_83, vec_86, mem_vec_6627);
											mem_vec_6627 = vec_85;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_6628);
											mem_vec_6628 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_6629);
											mem_vec_6629 = vec_89;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);


											vec_90 = _mm256_fmadd_ps(vec_91, vec_84, mem_vec_6630);
											mem_vec_6630 = vec_90;



											vec_92 = _mm256_fmadd_ps(vec_91, vec_86, mem_vec_6631);
											mem_vec_6631 = vec_92;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);


											vec_93 = _mm256_fmadd_ps(vec_94, vec_84, mem_vec_6632);
											mem_vec_6632 = vec_93;



											vec_95 = _mm256_fmadd_ps(vec_94, vec_86, mem_vec_6633);
											mem_vec_6633 = vec_95;
											scal_30 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_97 = _mm256_set1_ps(scal_30);


											vec_96 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_6634);
											mem_vec_6634 = vec_96;



											vec_98 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_6635);
											mem_vec_6635 = vec_98;
											scal_31 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_100 = _mm256_set1_ps(scal_31);


											vec_99 = _mm256_fmadd_ps(vec_100, vec_84, mem_vec_6636);
											mem_vec_6636 = vec_99;



											vec_101 = _mm256_fmadd_ps(vec_100, vec_86, mem_vec_6637);
											mem_vec_6637 = vec_101;
											scal_32 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_32);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_6638);
											mem_vec_6638 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_6639);
											mem_vec_6639 = vec_104;
											scal_33 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_106 = _mm256_set1_ps(scal_33);


											vec_105 = _mm256_fmadd_ps(vec_106, vec_84, mem_vec_6640);
											mem_vec_6640 = vec_105;



											vec_107 = _mm256_fmadd_ps(vec_106, vec_86, mem_vec_6641);
											mem_vec_6641 = vec_107;
											scal_34 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_109 = _mm256_set1_ps(scal_34);


											vec_108 = _mm256_fmadd_ps(vec_109, vec_84, mem_vec_6642);
											mem_vec_6642 = vec_108;



											vec_110 = _mm256_fmadd_ps(vec_109, vec_86, mem_vec_6643);
											mem_vec_6643 = vec_110;
											scal_35 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
											vec_112 = _mm256_set1_ps(scal_35);


											vec_111 = _mm256_fmadd_ps(vec_112, vec_84, mem_vec_6644);
											mem_vec_6644 = vec_111;



											vec_113 = _mm256_fmadd_ps(vec_112, vec_86, mem_vec_6645);
											mem_vec_6645 = vec_113;
											scal_36 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 2) + c];
											vec_115 = _mm256_set1_ps(scal_36);


											vec_114 = _mm256_fmadd_ps(vec_115, vec_84, mem_vec_6646);
											mem_vec_6646 = vec_114;



											vec_116 = _mm256_fmadd_ps(vec_115, vec_86, mem_vec_6647);
											mem_vec_6647 = vec_116;
											scal_37 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h + 2) + c];
											vec_118 = _mm256_set1_ps(scal_37);


											vec_117 = _mm256_fmadd_ps(vec_118, vec_84, mem_vec_6648);
											mem_vec_6648 = vec_117;



											vec_119 = _mm256_fmadd_ps(vec_118, vec_86, mem_vec_6649);
											mem_vec_6649 = vec_119;
											scal_38 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h + 2) + c];
											vec_121 = _mm256_set1_ps(scal_38);


											vec_120 = _mm256_fmadd_ps(vec_121, vec_84, mem_vec_6650);
											mem_vec_6650 = vec_120;



											vec_122 = _mm256_fmadd_ps(vec_121, vec_86, mem_vec_6651);
											mem_vec_6651 = vec_122;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6626);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6627);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6628);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6629);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6630);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6631);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6632);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6633);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6634);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6635);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6636);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6637);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6638);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6639);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6640);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_6641);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6642);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_6643);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6644);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_6645);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6646);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_6647);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6648);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_6649);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_6650);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8], mem_vec_6651);
							}
						}
					}
				}
		}
	}
}


}