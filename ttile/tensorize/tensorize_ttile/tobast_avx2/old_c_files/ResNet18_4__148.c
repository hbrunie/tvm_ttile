#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (8, c); T (4, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (4, f);
  T (7, x)]
*/
IND_TYPE c, cp_0, c1142_p_0, cp_1, c1142, f, fp_0, w, wp_0, x, xp_0, x1350_p_0, x1351_p_0, xp_1, x1350_p_1, xp_2, x1350, x1351, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y712 = 0;
IND_TYPE x1352 = 0;
IND_TYPE h = 0;
IND_TYPE w576 = 0;
IND_TYPE c1143 = 0;
IND_TYPE f786 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10524 ,mem_vec_10525 ,mem_vec_10526 ,mem_vec_10527 ,mem_vec_10528 ,mem_vec_10529 ,mem_vec_10530 ,mem_vec_10531 ,mem_vec_10532 ,mem_vec_10533 ,mem_vec_10534 ,mem_vec_10535 ,mem_vec_10536 ,mem_vec_10537 ,mem_vec_10538 ,mem_vec_10539 ,mem_vec_10540 ,mem_vec_10541 ,mem_vec_10542 ,mem_vec_10543 ,mem_vec_10544 ,mem_vec_10545 ,mem_vec_10546 ,mem_vec_10547 ,mem_vec_10548 ,mem_vec_10549 ,mem_vec_10550 ,mem_vec_10551 ,mem_vec_10552 ,mem_vec_10553 ,mem_vec_10554 ,mem_vec_10555 ,mem_vec_10556 ,mem_vec_10557 ,mem_vec_10558 ,mem_vec_10559 ,mem_vec_10560 ,mem_vec_10561 ,mem_vec_10562 ,mem_vec_10563 ,mem_vec_10564 ,mem_vec_10565 ,mem_vec_10566 ,mem_vec_10567 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (x, 7) (28 / 4)
for (x1351 = x1352, x1351_p_0 = 0;
	x1351 < x1352 + 28;
	x1351 += 4, x1351_p_0 += 4){
	// y = 28, x = 4, h = 3, w = 3, c = 64, f = 128
	// T (f, 4) (128 / 32)
	for (f = f786, fp_0 = 0;
		f < f786 + 128;
		f += 32, fp_0 += 32){
			for (y = y712, yp_0 = 0;
				y < y712 + 10;
				y += 5, yp_0 += 5){
				// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
				// T (x, 4) (4 / 1)
				for (x1350 = x1351, x1350_p_1 = x1351_p_0, x1350_p_0 = 0;
					x1350 < x1351 + 4;
					x1350 += 1, x1350_p_1 += 1, x1350_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
					// T (c, 8) (64 / 8)
					for (c1142 = c1143, c1142_p_0 = 0;
						c1142 < c1143 + 64;
						c1142 += 8, c1142_p_0 += 8){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (w, 3) (3 / 1)
						for (w = w576, wp_0 = 0;
							w < w576 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
							// T (x, 1) (1 / 1)
							for (x = x1350, xp_2 = x1350_p_1, xp_1 = x1350_p_0, xp_0 = 0;
								x < x1350 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10524 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10525 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_10526 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10527 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_10528 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10529 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_10530 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10531 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_10532 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10533 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_10534 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10535 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_10536 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10537 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_10538 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10539 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_10540 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_10541 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_10542 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_10543 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c1142, cp_1 = c1142_p_0, cp_0 = 0;
											c < c1142 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10524);
											mem_vec_10524 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10525);
											mem_vec_10525 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10526);
											mem_vec_10526 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10527);
											mem_vec_10527 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10528);
											mem_vec_10528 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10529);
											mem_vec_10529 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10530);
											mem_vec_10530 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10531);
											mem_vec_10531 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10532);
											mem_vec_10532 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10533);
											mem_vec_10533 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10534);
											mem_vec_10534 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10535);
											mem_vec_10535 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10536);
											mem_vec_10536 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10537);
											mem_vec_10537 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10538);
											mem_vec_10538 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10539);
											mem_vec_10539 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10540);
											mem_vec_10540 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10541);
											mem_vec_10541 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10542);
											mem_vec_10542 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10543);
											mem_vec_10543 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_10524);
											mem_vec_10524 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_10525);
											mem_vec_10525 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_10526);
											mem_vec_10526 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_10527);
											mem_vec_10527 = vec_36;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_10528);
											mem_vec_10528 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_10529);
											mem_vec_10529 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_10530);
											mem_vec_10530 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_10531);
											mem_vec_10531 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_10532);
											mem_vec_10532 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_10533);
											mem_vec_10533 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_10534);
											mem_vec_10534 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_10535);
											mem_vec_10535 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_10536);
											mem_vec_10536 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_10537);
											mem_vec_10537 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_10538);
											mem_vec_10538 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_10539);
											mem_vec_10539 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_10540);
											mem_vec_10540 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_10541);
											mem_vec_10541 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_10542);
											mem_vec_10542 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_10543);
											mem_vec_10543 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_10524);
											mem_vec_10524 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_10525);
											mem_vec_10525 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_10526);
											mem_vec_10526 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_10527);
											mem_vec_10527 = vec_65;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_10528);
											mem_vec_10528 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_10529);
											mem_vec_10529 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_10530);
											mem_vec_10530 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_10531);
											mem_vec_10531 = vec_71;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_10532);
											mem_vec_10532 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_10533);
											mem_vec_10533 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_10534);
											mem_vec_10534 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_10535);
											mem_vec_10535 = vec_76;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_10536);
											mem_vec_10536 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_10537);
											mem_vec_10537 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_10538);
											mem_vec_10538 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_10539);
											mem_vec_10539 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_10540);
											mem_vec_10540 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_10541);
											mem_vec_10541 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_10542);
											mem_vec_10542 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_10543);
											mem_vec_10543 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10524);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10525);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10526);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10527);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10528);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10529);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10530);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10531);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10532);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10533);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10534);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10535);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10536);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10537);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10538);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10539);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10540);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10541);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10542);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10543);
							}
						}
					}
				}
			}
			for (y = y712 + 10, yp_0 = 0;
				y < y712 + 10 + 18;
				y += 6, yp_0 += 6){
				// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
				// T (x, 4) (4 / 1)
				for (x1350 = x1351, x1350_p_1 = x1351_p_0, x1350_p_0 = 0;
					x1350 < x1351 + 4;
					x1350 += 1, x1350_p_1 += 1, x1350_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
					// T (c, 8) (64 / 8)
					for (c1142 = c1143, c1142_p_0 = 0;
						c1142 < c1143 + 64;
						c1142 += 8, c1142_p_0 += 8){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (w, 3) (3 / 1)
						for (w = w576, wp_0 = 0;
							w < w576 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
							// T (x, 1) (1 / 1)
							for (x = x1350, xp_2 = x1350_p_1, xp_1 = x1350_p_0, xp_0 = 0;
								x < x1350 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10544 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10545 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_10546 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10547 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_10548 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10549 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_10550 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10551 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_10552 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10553 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_10554 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10555 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_10556 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10557 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_10558 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10559 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_10560 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_10561 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_10562 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_10563 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_10564 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_10565 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_10566 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_10567 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c1142, cp_1 = c1142_p_0, cp_0 = 0;
											c < c1142 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10544);
											mem_vec_10544 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10545);
											mem_vec_10545 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10546);
											mem_vec_10546 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10547);
											mem_vec_10547 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10548);
											mem_vec_10548 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10549);
											mem_vec_10549 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10550);
											mem_vec_10550 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10551);
											mem_vec_10551 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10552);
											mem_vec_10552 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10553);
											mem_vec_10553 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10554);
											mem_vec_10554 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10555);
											mem_vec_10555 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10556);
											mem_vec_10556 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10557);
											mem_vec_10557 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10558);
											mem_vec_10558 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10559);
											mem_vec_10559 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10560);
											mem_vec_10560 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10561);
											mem_vec_10561 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10562);
											mem_vec_10562 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10563);
											mem_vec_10563 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_10564);
											mem_vec_10564 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_10565);
											mem_vec_10565 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_10566);
											mem_vec_10566 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_10567);
											mem_vec_10567 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_10544);
											mem_vec_10544 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_10545);
											mem_vec_10545 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_10546);
											mem_vec_10546 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_10547);
											mem_vec_10547 = vec_41;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_10548);
											mem_vec_10548 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_10549);
											mem_vec_10549 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_10550);
											mem_vec_10550 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_10551);
											mem_vec_10551 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_10552);
											mem_vec_10552 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_10553);
											mem_vec_10553 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_10554);
											mem_vec_10554 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_10555);
											mem_vec_10555 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_10556);
											mem_vec_10556 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_10557);
											mem_vec_10557 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_10558);
											mem_vec_10558 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_10559);
											mem_vec_10559 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_10560);
											mem_vec_10560 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_10561);
											mem_vec_10561 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_10562);
											mem_vec_10562 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_10563);
											mem_vec_10563 = vec_62;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_10564);
											mem_vec_10564 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_10565);
											mem_vec_10565 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_10566);
											mem_vec_10566 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_10567);
											mem_vec_10567 = vec_67;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_10544);
											mem_vec_10544 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_10545);
											mem_vec_10545 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_10546);
											mem_vec_10546 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_10547);
											mem_vec_10547 = vec_75;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_10548);
											mem_vec_10548 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_10549);
											mem_vec_10549 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_10550);
											mem_vec_10550 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_10551);
											mem_vec_10551 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_10552);
											mem_vec_10552 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_10553);
											mem_vec_10553 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_10554);
											mem_vec_10554 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_10555);
											mem_vec_10555 = vec_86;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_10556);
											mem_vec_10556 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_10557);
											mem_vec_10557 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_10558);
											mem_vec_10558 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_10559);
											mem_vec_10559 = vec_91;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_10560);
											mem_vec_10560 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_10561);
											mem_vec_10561 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_10562);
											mem_vec_10562 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_10563);
											mem_vec_10563 = vec_96;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_10564);
											mem_vec_10564 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_10565);
											mem_vec_10565 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_10566);
											mem_vec_10566 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_10567);
											mem_vec_10567 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10544);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10545);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10546);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10547);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10548);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10549);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10550);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10551);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10552);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10553);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10554);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10555);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10556);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10557);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10558);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10559);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10560);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10561);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10562);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10563);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10564);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_10565);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10566);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_10567);
							}
						}
					}
				}
			}
	}
}


}