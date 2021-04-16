#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (1, x); T (8, y); T (2, c); T (2, f); T (272, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (1, x)]
*/
IND_TYPE c, cp_0, c132_p_0, cp_1, c132, f, fp_0, w, wp_0, x, xp_0, x176_p_0, x177_p_0, xp_1, x176_p_1, xp_2, x176, x177, y, yp_0, y156_p_0, yp_1, y156;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y157 = 0;
IND_TYPE x178 = 0;
IND_TYPE h = 0;
IND_TYPE w80 = 0;
IND_TYPE c133 = 0;
IND_TYPE f85 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1492 ,mem_vec_1493 ,mem_vec_1494 ,mem_vec_1495 ,mem_vec_1496 ,mem_vec_1497 ,mem_vec_1498 ,mem_vec_1499 ,mem_vec_1500 ,mem_vec_1501 ,mem_vec_1502 ,mem_vec_1503 ,mem_vec_1504 ,mem_vec_1505 ,mem_vec_1506 ,mem_vec_1507 ,mem_vec_1508 ,mem_vec_1509 ,mem_vec_1510 ,mem_vec_1511 ,mem_vec_1512 ,mem_vec_1513 ,mem_vec_1514 ,mem_vec_1515 ,mem_vec_1516 ,mem_vec_1517 ,mem_vec_1518 ,mem_vec_1519 ,mem_vec_1520 ,mem_vec_1521 ,mem_vec_1522 ,mem_vec_1523 ,mem_vec_1524 ,mem_vec_1525 ,mem_vec_1526 ,mem_vec_1527 ,mem_vec_1528 ,mem_vec_1529 ,mem_vec_1530 ,mem_vec_1531 ,mem_vec_1532 ,mem_vec_1533 ,mem_vec_1534 ,mem_vec_1535 ,mem_vec_1536 ,mem_vec_1537 ,mem_vec_1538 ,mem_vec_1539 ,mem_vec_1540 ,mem_vec_1541 ,mem_vec_1542 ,mem_vec_1543 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 1) (272 / 272)
for (x177 = x178, x177_p_0 = 0;
	x177 < x178 + 272;
	x177 += 272, x177_p_0 += 272){
		for (y156 = y157, y156_p_0 = 0;
			y156 < y157 + 48;
			y156 += 48, y156_p_0 += 48){
			// y = 8 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
			// T (x, 272) (272 / 1)
			for (x176 = x177, x176_p_1 = x177_p_0, x176_p_0 = 0;
				x176 < x177 + 272;
				x176 += 1, x176_p_1 += 1, x176_p_0 += 1){
				// y = 8 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f85, fp_0 = 0;
					f < f85 + 64;
					f += 32, fp_0 += 32){
					// y = 8 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c132 = c133, c132_p_0 = 0;
						c132 < c133 + 32;
						c132 += 16, c132_p_0 += 16){
						// y = 8 * ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y156, yp_1 = y156_p_0, yp_0 = 0;
							y < y156 + 48;
							y += 6, yp_1 += 6, yp_0 += 6){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (x, 1) (1 / 1)
							for (x = x176, xp_2 = x176_p_1, xp_1 = x176_p_0, xp_0 = 0;
								x < x176 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w80, wp_0 = 0;
									w < w80 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1492 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1493 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1494 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1495 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_1496 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1497 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1498 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1499 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_1500 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1501 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1502 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1503 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_1504 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1505 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1506 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1507 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_1508 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1509 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_1510 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1511 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_1512 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1513 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_1514 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_1515 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c132, cp_1 = c132_p_0, cp_0 = 0;
												c < c132 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1492);
												mem_vec_1492 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1493);
												mem_vec_1493 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1494);
												mem_vec_1494 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1495);
												mem_vec_1495 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1496);
												mem_vec_1496 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1497);
												mem_vec_1497 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1498);
												mem_vec_1498 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1499);
												mem_vec_1499 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1500);
												mem_vec_1500 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1501);
												mem_vec_1501 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1502);
												mem_vec_1502 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1503);
												mem_vec_1503 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1504);
												mem_vec_1504 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1505);
												mem_vec_1505 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1506);
												mem_vec_1506 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1507);
												mem_vec_1507 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1508);
												mem_vec_1508 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1509);
												mem_vec_1509 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1510);
												mem_vec_1510 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1511);
												mem_vec_1511 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_1512);
												mem_vec_1512 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_1513);
												mem_vec_1513 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_1514);
												mem_vec_1514 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_1515);
												mem_vec_1515 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_1492);
												mem_vec_1492 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_1493);
												mem_vec_1493 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_1494);
												mem_vec_1494 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_1495);
												mem_vec_1495 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_1496);
												mem_vec_1496 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_1497);
												mem_vec_1497 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_1498);
												mem_vec_1498 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_1499);
												mem_vec_1499 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_1500);
												mem_vec_1500 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_1501);
												mem_vec_1501 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_1502);
												mem_vec_1502 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_1503);
												mem_vec_1503 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_1504);
												mem_vec_1504 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_1505);
												mem_vec_1505 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_1506);
												mem_vec_1506 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_1507);
												mem_vec_1507 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_1508);
												mem_vec_1508 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_1509);
												mem_vec_1509 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_1510);
												mem_vec_1510 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_1511);
												mem_vec_1511 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_1512);
												mem_vec_1512 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_1513);
												mem_vec_1513 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_1514);
												mem_vec_1514 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_1515);
												mem_vec_1515 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_1492);
												mem_vec_1492 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_1493);
												mem_vec_1493 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_1494);
												mem_vec_1494 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_1495);
												mem_vec_1495 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_1496);
												mem_vec_1496 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_1497);
												mem_vec_1497 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_1498);
												mem_vec_1498 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_1499);
												mem_vec_1499 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_1500);
												mem_vec_1500 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_1501);
												mem_vec_1501 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_1502);
												mem_vec_1502 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_1503);
												mem_vec_1503 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_1504);
												mem_vec_1504 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_1505);
												mem_vec_1505 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_1506);
												mem_vec_1506 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_1507);
												mem_vec_1507 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_1508);
												mem_vec_1508 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_1509);
												mem_vec_1509 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_1510);
												mem_vec_1510 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_1511);
												mem_vec_1511 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_1512);
												mem_vec_1512 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_1513);
												mem_vec_1513 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_1514);
												mem_vec_1514 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_1515);
												mem_vec_1515 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1492);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1493);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1494);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1495);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1496);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1497);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1498);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1499);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1500);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1501);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1502);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1503);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1504);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1505);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1506);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1507);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1508);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1509);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1510);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1511);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1512);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_1513);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1514);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_1515);
								}
							}
						}
					}
				}
			}
		}
		for (y156 = y157 + 48, y156_p_0 = 0;
			y156 < y157 + 48 + 224;
			y156 += 56, y156_p_0 += 56){
			// y = 8 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
			// T (x, 272) (272 / 1)
			for (x176 = x177, x176_p_1 = x177_p_0, x176_p_0 = 0;
				x176 < x177 + 272;
				x176 += 1, x176_p_1 += 1, x176_p_0 += 1){
				// y = 8 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f85, fp_0 = 0;
					f < f85 + 64;
					f += 32, fp_0 += 32){
					// y = 8 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c132 = c133, c132_p_0 = 0;
						c132 < c133 + 32;
						c132 += 16, c132_p_0 += 16){
						// y = 8 * ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y156, yp_1 = y156_p_0, yp_0 = 0;
							y < y156 + 56;
							y += 7, yp_1 += 7, yp_0 += 7){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (x, 1) (1 / 1)
							for (x = x176, xp_2 = x176_p_1, xp_1 = x176_p_0, xp_0 = 0;
								x < x176 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w80, wp_0 = 0;
									w < w80 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1516 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1517 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1518 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1519 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_1520 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1521 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1522 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1523 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_1524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_1528 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1529 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1530 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1531 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_1532 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1533 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_1534 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1535 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_1536 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1537 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_1538 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_1539 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											mem_vec_1540 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_1541 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_1542 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_1543 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c132, cp_1 = c132_p_0, cp_0 = 0;
												c < c132 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1516);
												mem_vec_1516 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1517);
												mem_vec_1517 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1518);
												mem_vec_1518 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1519);
												mem_vec_1519 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1520);
												mem_vec_1520 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1521);
												mem_vec_1521 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1522);
												mem_vec_1522 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1523);
												mem_vec_1523 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1524);
												mem_vec_1524 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1525);
												mem_vec_1525 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1526);
												mem_vec_1526 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1527);
												mem_vec_1527 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1528);
												mem_vec_1528 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1529);
												mem_vec_1529 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1530);
												mem_vec_1530 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1531);
												mem_vec_1531 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1532);
												mem_vec_1532 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1533);
												mem_vec_1533 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1534);
												mem_vec_1534 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1535);
												mem_vec_1535 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_1536);
												mem_vec_1536 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_1537);
												mem_vec_1537 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_1538);
												mem_vec_1538 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_1539);
												mem_vec_1539 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_1540);
												mem_vec_1540 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_1541);
												mem_vec_1541 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_1542);
												mem_vec_1542 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_1543);
												mem_vec_1543 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_40 = _mm256_set1_ps(scal_7);
												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_1516);
												mem_vec_1516 = vec_39;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_1517);
												mem_vec_1517 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_1518);
												mem_vec_1518 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_1519);
												mem_vec_1519 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_1520);
												mem_vec_1520 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_1521);
												mem_vec_1521 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_1522);
												mem_vec_1522 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_1523);
												mem_vec_1523 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_1524);
												mem_vec_1524 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_1525);
												mem_vec_1525 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_1526);
												mem_vec_1526 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_1527);
												mem_vec_1527 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_1528);
												mem_vec_1528 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_1529);
												mem_vec_1529 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_1530);
												mem_vec_1530 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_1531);
												mem_vec_1531 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_1532);
												mem_vec_1532 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_1533);
												mem_vec_1533 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_1534);
												mem_vec_1534 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_1535);
												mem_vec_1535 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_69 = _mm256_set1_ps(scal_12);


												vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_1536);
												mem_vec_1536 = vec_68;



												vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_1537);
												mem_vec_1537 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_1538);
												mem_vec_1538 = vec_71;



												vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_1539);
												mem_vec_1539 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_13);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_1540);
												mem_vec_1540 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_1541);
												mem_vec_1541 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_1542);
												mem_vec_1542 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_1543);
												mem_vec_1543 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_14);
												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_1516);
												mem_vec_1516 = vec_78;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_1517);
												mem_vec_1517 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_1518);
												mem_vec_1518 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_1519);
												mem_vec_1519 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_1520);
												mem_vec_1520 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_1521);
												mem_vec_1521 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_1522);
												mem_vec_1522 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_1523);
												mem_vec_1523 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_1524);
												mem_vec_1524 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_1525);
												mem_vec_1525 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_1526);
												mem_vec_1526 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_1527);
												mem_vec_1527 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_1528);
												mem_vec_1528 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_1529);
												mem_vec_1529 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_1530);
												mem_vec_1530 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_1531);
												mem_vec_1531 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_18);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_1532);
												mem_vec_1532 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_1533);
												mem_vec_1533 = vec_104;



												vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_1534);
												mem_vec_1534 = vec_105;



												vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_1535);
												mem_vec_1535 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_108 = _mm256_set1_ps(scal_19);


												vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_1536);
												mem_vec_1536 = vec_107;



												vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_1537);
												mem_vec_1537 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_1538);
												mem_vec_1538 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_1539);
												mem_vec_1539 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_113 = _mm256_set1_ps(scal_20);


												vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_1540);
												mem_vec_1540 = vec_112;



												vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_1541);
												mem_vec_1541 = vec_114;



												vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_1542);
												mem_vec_1542 = vec_115;



												vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_1543);
												mem_vec_1543 = vec_116;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1516);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1517);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1518);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1519);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1520);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1521);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1522);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1523);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1524);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1525);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1526);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1527);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1528);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1529);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1530);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1531);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1532);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1533);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1534);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1535);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1536);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_1537);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1538);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_1539);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1540);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_1541);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1542);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_1543);
								}
							}
						}
					}
				}
			}
		}
}


}