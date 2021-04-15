#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (32, c); T (8, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (32, c);
  T (2, f); T (1, c)]
*/
IND_TYPE c, cp_0, c808_p_0, c809_p_0, c810_p_0, cp_1, c808_p_1, c809_p_1, cp_2, c808_p_2, cp_3, c808, c809, c810, f, fp_0, f576_p_0, fp_1, f576, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y384 = 0;
IND_TYPE x384 = 0;
IND_TYPE h310 = 0;
IND_TYPE w = 0;
IND_TYPE c811 = 0;
IND_TYPE f577 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6496 ,mem_vec_6497 ,mem_vec_6498 ,mem_vec_6499 ,mem_vec_6500 ,mem_vec_6501 ,mem_vec_6502 ,mem_vec_6503 ,mem_vec_6504 ,mem_vec_6505 ,mem_vec_6506 ,mem_vec_6507 ,mem_vec_6508 ,mem_vec_6509 ,mem_vec_6510 ,mem_vec_6511 ,mem_vec_6512 ,mem_vec_6513 ,mem_vec_6514 ,mem_vec_6515 ,mem_vec_6516 ,mem_vec_6517 ,mem_vec_6518 ,mem_vec_6519 ,mem_vec_6520 ,mem_vec_6521 ,mem_vec_6522 ,mem_vec_6523 ,mem_vec_6524 ,mem_vec_6525 ,mem_vec_6526 ,mem_vec_6527 ,mem_vec_6528 ,mem_vec_6529 ,mem_vec_6530 ,mem_vec_6531 ,mem_vec_6532 ,mem_vec_6533 ,mem_vec_6534 ,mem_vec_6535 ,mem_vec_6536 ,mem_vec_6537 ,mem_vec_6538 ,mem_vec_6539 ,mem_vec_6540 ,mem_vec_6541 ,mem_vec_6542 ,mem_vec_6543 ,mem_vec_6544 ,mem_vec_6545 ,mem_vec_6546 ,mem_vec_6547 ,mem_vec_6548 ,mem_vec_6549 ,mem_vec_6550 ,mem_vec_6551 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 1) (1024 / 1024)
for (c810 = c811, c810_p_0 = 0;
	c810 < c811 + 1024;
	c810 += 1024, c810_p_0 += 1024){
	// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
	// T (f, 2) (1024 / 512)
	for (f576 = f577, f576_p_0 = 0;
		f576 < f577 + 1024;
		f576 += 512, f576_p_0 += 512){
		// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 512
		// T (c, 32) (1024 / 32)
		for (c809 = c810, c809_p_1 = c810_p_0, c809_p_0 = 0;
			c809 < c810 + 1024;
			c809 += 32, c809_p_1 += 32, c809_p_0 += 32){
				for (y = y384, yp_0 = 0;
					y < y384 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 512
					// T (f, 8) (512 / 64)
					for (f = f576, fp_1 = f576_p_0, fp_0 = 0;
						f < f576 + 512;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 64
						// T (c, 32) (32 / 1)
						for (c808 = c809, c808_p_2 = c809_p_1, c808_p_1 = c809_p_0, c808_p_0 = 0;
							c808 < c809 + 32;
							c808 += 1, c808_p_2 += 1, c808_p_1 += 1, c808_p_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
							// T (h, 3) (3 / 1)
							for (h = h310, hp_0 = 0;
								h < h310 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 64
								// T (x, 7) (7 / 1)
								for (x = x384, xp_0 = 0;
									x < x384 + 7;
									x += 1, xp_0 += 1){
											mem_vec_6496 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6497 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6498 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6499 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_6500 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_6501 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
											mem_vec_6502 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_6503 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
											mem_vec_6504 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6505 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6506 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6507 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_6508 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_6509 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
											mem_vec_6510 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_6511 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
											mem_vec_6512 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6513 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6514 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6515 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_6516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_6517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
											mem_vec_6518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_6519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
											// T (c, 1) (1 / 1)
											for (c = c808, cp_3 = c808_p_2, cp_2 = c808_p_1, cp_1 = c808_p_0, cp_0 = 0;
												c < c808 + 1;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6496);
												mem_vec_6496 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6497);
												mem_vec_6497 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6498);
												mem_vec_6498 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6499);
												mem_vec_6499 = vec_7;

												vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_6500);
												mem_vec_6500 = vec_9;

												vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

												vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_6501);
												mem_vec_6501 = vec_11;

												vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_6502);
												mem_vec_6502 = vec_13;

												vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

												vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_6503);
												mem_vec_6503 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm256_set1_ps(scal_1);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_6504);
												mem_vec_6504 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_6505);
												mem_vec_6505 = vec_19;



												vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_6506);
												mem_vec_6506 = vec_20;



												vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_6507);
												mem_vec_6507 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_6508);
												mem_vec_6508 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_6509);
												mem_vec_6509 = vec_23;



												vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_6510);
												mem_vec_6510 = vec_24;



												vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_6511);
												mem_vec_6511 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm256_set1_ps(scal_2);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_6512);
												mem_vec_6512 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_6513);
												mem_vec_6513 = vec_28;



												vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_6514);
												mem_vec_6514 = vec_29;



												vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_6515);
												mem_vec_6515 = vec_30;



												vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_6516);
												mem_vec_6516 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_6517);
												mem_vec_6517 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_6518);
												mem_vec_6518 = vec_33;



												vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_6519);
												mem_vec_6519 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_36 = _mm256_set1_ps(scal_3);
												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_6496);
												mem_vec_6496 = vec_35;

												vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_6497);
												mem_vec_6497 = vec_38;

												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_40 = _mm256_fmadd_ps(vec_36, vec_41, mem_vec_6498);
												mem_vec_6498 = vec_40;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_42 = _mm256_fmadd_ps(vec_36, vec_43, mem_vec_6499);
												mem_vec_6499 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm256_fmadd_ps(vec_36, vec_45, mem_vec_6500);
												mem_vec_6500 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

												vec_46 = _mm256_fmadd_ps(vec_36, vec_47, mem_vec_6501);
												mem_vec_6501 = vec_46;

												vec_49 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_48 = _mm256_fmadd_ps(vec_36, vec_49, mem_vec_6502);
												mem_vec_6502 = vec_48;

												vec_51 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

												vec_50 = _mm256_fmadd_ps(vec_36, vec_51, mem_vec_6503);
												mem_vec_6503 = vec_50;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_53 = _mm256_set1_ps(scal_4);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_6504);
												mem_vec_6504 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_6505);
												mem_vec_6505 = vec_54;



												vec_55 = _mm256_fmadd_ps(vec_53, vec_41, mem_vec_6506);
												mem_vec_6506 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_6507);
												mem_vec_6507 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_6508);
												mem_vec_6508 = vec_57;



												vec_58 = _mm256_fmadd_ps(vec_53, vec_47, mem_vec_6509);
												mem_vec_6509 = vec_58;



												vec_59 = _mm256_fmadd_ps(vec_53, vec_49, mem_vec_6510);
												mem_vec_6510 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_53, vec_51, mem_vec_6511);
												mem_vec_6511 = vec_60;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_62 = _mm256_set1_ps(scal_5);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_6512);
												mem_vec_6512 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_6513);
												mem_vec_6513 = vec_63;



												vec_64 = _mm256_fmadd_ps(vec_62, vec_41, mem_vec_6514);
												mem_vec_6514 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_6515);
												mem_vec_6515 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_6516);
												mem_vec_6516 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_62, vec_47, mem_vec_6517);
												mem_vec_6517 = vec_67;



												vec_68 = _mm256_fmadd_ps(vec_62, vec_49, mem_vec_6518);
												mem_vec_6518 = vec_68;



												vec_69 = _mm256_fmadd_ps(vec_62, vec_51, mem_vec_6519);
												mem_vec_6519 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_71 = _mm256_set1_ps(scal_6);
												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_6496);
												mem_vec_6496 = vec_70;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_6497);
												mem_vec_6497 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_75 = _mm256_fmadd_ps(vec_71, vec_76, mem_vec_6498);
												mem_vec_6498 = vec_75;

												vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_77 = _mm256_fmadd_ps(vec_71, vec_78, mem_vec_6499);
												mem_vec_6499 = vec_77;

												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_79 = _mm256_fmadd_ps(vec_71, vec_80, mem_vec_6500);
												mem_vec_6500 = vec_79;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

												vec_81 = _mm256_fmadd_ps(vec_71, vec_82, mem_vec_6501);
												mem_vec_6501 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_83 = _mm256_fmadd_ps(vec_71, vec_84, mem_vec_6502);
												mem_vec_6502 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

												vec_85 = _mm256_fmadd_ps(vec_71, vec_86, mem_vec_6503);
												mem_vec_6503 = vec_85;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm256_set1_ps(scal_7);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_6504);
												mem_vec_6504 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_6505);
												mem_vec_6505 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_6506);
												mem_vec_6506 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_6507);
												mem_vec_6507 = vec_91;



												vec_92 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_6508);
												mem_vec_6508 = vec_92;



												vec_93 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_6509);
												mem_vec_6509 = vec_93;



												vec_94 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_6510);
												mem_vec_6510 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_6511);
												mem_vec_6511 = vec_95;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_97 = _mm256_set1_ps(scal_8);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_6512);
												mem_vec_6512 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_6513);
												mem_vec_6513 = vec_98;



												vec_99 = _mm256_fmadd_ps(vec_97, vec_76, mem_vec_6514);
												mem_vec_6514 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_6515);
												mem_vec_6515 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_6516);
												mem_vec_6516 = vec_101;



												vec_102 = _mm256_fmadd_ps(vec_97, vec_82, mem_vec_6517);
												mem_vec_6517 = vec_102;



												vec_103 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_6518);
												mem_vec_6518 = vec_103;



												vec_104 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_6519);
												mem_vec_6519 = vec_104;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6496);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6497);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6498);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6499);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6500);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_6501);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6502);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_6503);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6504);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6505);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6506);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6507);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6508);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_6509);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6510);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_6511);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6512);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6513);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6514);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6515);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6516);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_6517);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6518);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_6519);
								}
							}
						}
					}
				}
				for (y = y384 + 3, yp_0 = 0;
					y < y384 + 3 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 512
					// T (f, 8) (512 / 64)
					for (f = f576, fp_1 = f576_p_0, fp_0 = 0;
						f < f576 + 512;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 64
						// T (c, 32) (32 / 1)
						for (c808 = c809, c808_p_2 = c809_p_1, c808_p_1 = c809_p_0, c808_p_0 = 0;
							c808 < c809 + 32;
							c808 += 1, c808_p_2 += 1, c808_p_1 += 1, c808_p_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
							// T (h, 3) (3 / 1)
							for (h = h310, hp_0 = 0;
								h < h310 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 64
								// T (x, 7) (7 / 1)
								for (x = x384, xp_0 = 0;
									x < x384 + 7;
									x += 1, xp_0 += 1){
											mem_vec_6520 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6521 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6522 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6523 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_6524 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_6525 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
											mem_vec_6526 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_6527 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
											mem_vec_6528 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6529 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6530 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6531 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_6532 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_6533 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
											mem_vec_6534 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_6535 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
											mem_vec_6536 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6537 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6538 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6539 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_6540 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_6541 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
											mem_vec_6542 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_6543 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
											mem_vec_6544 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6545 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6546 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6547 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_6548 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_6549 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
											mem_vec_6550 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_6551 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
											// T (c, 1) (1 / 1)
											for (c = c808, cp_3 = c808_p_2, cp_2 = c808_p_1, cp_1 = c808_p_0, cp_0 = 0;
												c < c808 + 1;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6520);
												mem_vec_6520 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6521);
												mem_vec_6521 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6522);
												mem_vec_6522 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6523);
												mem_vec_6523 = vec_7;

												vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_6524);
												mem_vec_6524 = vec_9;

												vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

												vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_6525);
												mem_vec_6525 = vec_11;

												vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_6526);
												mem_vec_6526 = vec_13;

												vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

												vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_6527);
												mem_vec_6527 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm256_set1_ps(scal_1);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_6528);
												mem_vec_6528 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_6529);
												mem_vec_6529 = vec_19;



												vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_6530);
												mem_vec_6530 = vec_20;



												vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_6531);
												mem_vec_6531 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_6532);
												mem_vec_6532 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_6533);
												mem_vec_6533 = vec_23;



												vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_6534);
												mem_vec_6534 = vec_24;



												vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_6535);
												mem_vec_6535 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm256_set1_ps(scal_2);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_6536);
												mem_vec_6536 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_6537);
												mem_vec_6537 = vec_28;



												vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_6538);
												mem_vec_6538 = vec_29;



												vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_6539);
												mem_vec_6539 = vec_30;



												vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_6540);
												mem_vec_6540 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_6541);
												mem_vec_6541 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_6542);
												mem_vec_6542 = vec_33;



												vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_6543);
												mem_vec_6543 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_36 = _mm256_set1_ps(scal_3);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_6544);
												mem_vec_6544 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_6545);
												mem_vec_6545 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_6546);
												mem_vec_6546 = vec_38;



												vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_6547);
												mem_vec_6547 = vec_39;



												vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_6548);
												mem_vec_6548 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_6549);
												mem_vec_6549 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_6550);
												mem_vec_6550 = vec_42;



												vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_6551);
												mem_vec_6551 = vec_43;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_45 = _mm256_set1_ps(scal_4);
												vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_6520);
												mem_vec_6520 = vec_44;

												vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_6521);
												mem_vec_6521 = vec_47;

												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_6522);
												mem_vec_6522 = vec_49;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_6523);
												mem_vec_6523 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_6524);
												mem_vec_6524 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

												vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_6525);
												mem_vec_6525 = vec_55;

												vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_6526);
												mem_vec_6526 = vec_57;

												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

												vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_6527);
												mem_vec_6527 = vec_59;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_62 = _mm256_set1_ps(scal_5);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_6528);
												mem_vec_6528 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_6529);
												mem_vec_6529 = vec_63;



												vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_6530);
												mem_vec_6530 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_6531);
												mem_vec_6531 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_6532);
												mem_vec_6532 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_6533);
												mem_vec_6533 = vec_67;



												vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_6534);
												mem_vec_6534 = vec_68;



												vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_6535);
												mem_vec_6535 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_71 = _mm256_set1_ps(scal_6);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_6536);
												mem_vec_6536 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_6537);
												mem_vec_6537 = vec_72;



												vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_6538);
												mem_vec_6538 = vec_73;



												vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_6539);
												mem_vec_6539 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_6540);
												mem_vec_6540 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_6541);
												mem_vec_6541 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_6542);
												mem_vec_6542 = vec_77;



												vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_6543);
												mem_vec_6543 = vec_78;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_80 = _mm256_set1_ps(scal_7);


												vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_6544);
												mem_vec_6544 = vec_79;



												vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_6545);
												mem_vec_6545 = vec_81;



												vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_6546);
												mem_vec_6546 = vec_82;



												vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_6547);
												mem_vec_6547 = vec_83;



												vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_6548);
												mem_vec_6548 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_6549);
												mem_vec_6549 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_6550);
												mem_vec_6550 = vec_86;



												vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_6551);
												mem_vec_6551 = vec_87;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_89 = _mm256_set1_ps(scal_8);
												vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_6520);
												mem_vec_6520 = vec_88;

												vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_6521);
												mem_vec_6521 = vec_91;

												vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_6522);
												mem_vec_6522 = vec_93;

												vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_6523);
												mem_vec_6523 = vec_95;

												vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_6524);
												mem_vec_6524 = vec_97;

												vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

												vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_6525);
												mem_vec_6525 = vec_99;

												vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_6526);
												mem_vec_6526 = vec_101;

												vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

												vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_6527);
												mem_vec_6527 = vec_103;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_106 = _mm256_set1_ps(scal_9);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_6528);
												mem_vec_6528 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_6529);
												mem_vec_6529 = vec_107;



												vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_6530);
												mem_vec_6530 = vec_108;



												vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_6531);
												mem_vec_6531 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_6532);
												mem_vec_6532 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_6533);
												mem_vec_6533 = vec_111;



												vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_6534);
												mem_vec_6534 = vec_112;



												vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_6535);
												mem_vec_6535 = vec_113;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_115 = _mm256_set1_ps(scal_10);


												vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_6536);
												mem_vec_6536 = vec_114;



												vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_6537);
												mem_vec_6537 = vec_116;



												vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_6538);
												mem_vec_6538 = vec_117;



												vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_6539);
												mem_vec_6539 = vec_118;



												vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_6540);
												mem_vec_6540 = vec_119;



												vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_6541);
												mem_vec_6541 = vec_120;



												vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_6542);
												mem_vec_6542 = vec_121;



												vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_6543);
												mem_vec_6543 = vec_122;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_124 = _mm256_set1_ps(scal_11);


												vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_6544);
												mem_vec_6544 = vec_123;



												vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_6545);
												mem_vec_6545 = vec_125;



												vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_6546);
												mem_vec_6546 = vec_126;



												vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_6547);
												mem_vec_6547 = vec_127;



												vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_6548);
												mem_vec_6548 = vec_128;



												vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_6549);
												mem_vec_6549 = vec_129;



												vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_6550);
												mem_vec_6550 = vec_130;



												vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_6551);
												mem_vec_6551 = vec_131;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6520);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6521);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6522);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6523);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6524);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_6525);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6526);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_6527);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6528);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6529);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6530);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6531);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6532);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_6533);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6534);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_6535);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6536);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6537);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6538);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6539);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6540);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_6541);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6542);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_6543);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6544);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6545);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6546);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6547);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6548);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_6549);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6550);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_6551);
								}
							}
						}
					}
				}
		}
	}
}


}