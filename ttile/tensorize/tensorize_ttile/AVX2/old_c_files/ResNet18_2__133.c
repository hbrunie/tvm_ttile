#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, c); T (1, f);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (56, x);
  T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c99_p_0, cp_1, c99, f, fp_0, f126_p_0, f127_p_0, fp_1, f126_p_1, fp_2, f126, f127, w, wp_0, x, xp_0, x99_p_0, xp_1, x99, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y69 = 0;
IND_TYPE x100 = 0;
IND_TYPE h = 0;
IND_TYPE w66 = 0;
IND_TYPE c100 = 0;
IND_TYPE f128 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1464 ,mem_vec_1465 ,mem_vec_1466 ,mem_vec_1467 ,mem_vec_1468 ,mem_vec_1469 ,mem_vec_1470 ,mem_vec_1471 ,mem_vec_1472 ,mem_vec_1473 ,mem_vec_1474 ,mem_vec_1475 ,mem_vec_1476 ,mem_vec_1477 ,mem_vec_1478 ,mem_vec_1479 ,mem_vec_1480 ,mem_vec_1481 ,mem_vec_1482 ,mem_vec_1483 ,mem_vec_1484 ,mem_vec_1485 ,mem_vec_1486 ,mem_vec_1487 ,mem_vec_1488 ,mem_vec_1489 ,mem_vec_1490 ,mem_vec_1491 ,mem_vec_1492 ,mem_vec_1493 ,mem_vec_1494 ,mem_vec_1495 ,mem_vec_1496 ,mem_vec_1497 ,mem_vec_1498 ,mem_vec_1499 ,mem_vec_1500 ,mem_vec_1501 ,mem_vec_1502 ,mem_vec_1503 ,mem_vec_1504 ,mem_vec_1505 ,mem_vec_1506 ,mem_vec_1507 ,mem_vec_1508 ,mem_vec_1509 ,mem_vec_1510 ,mem_vec_1511 ,mem_vec_1512 ,mem_vec_1513 ,mem_vec_1514 ,mem_vec_1515 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f127 = f128, f127_p_0 = 0;
	f127 < f128 + 64;
	f127 += 64, f127_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (f, 2) (64 / 32)
	for (f126 = f127, f126_p_1 = f127_p_0, f126_p_0 = 0;
		f126 < f127 + 64;
		f126 += 32, f126_p_1 += 32, f126_p_0 += 32){
		// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
		// T (x, 56) (56 / 1)
		for (x99 = x100, x99_p_0 = 0;
			x99 < x100 + 56;
			x99 += 1, x99_p_0 += 1){
				for (y = y69, yp_0 = 0;
					y < y69 + 42;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
					// T (f, 1) (32 / 32)
					for (f = f126, fp_2 = f126_p_1, fp_1 = f126_p_0, fp_0 = 0;
						f < f126 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (c, 2) (64 / 32)
						for (c99 = c100, c99_p_0 = 0;
							c99 < c100 + 64;
							c99 += 32, c99_p_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w66, wp_0 = 0;
								w < w66 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x99, xp_1 = x99_p_0, xp_0 = 0;
									x < x99 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1464 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1465 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1466 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1467 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_1468 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1469 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1470 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1471 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_1472 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1473 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1474 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1475 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_1476 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1477 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1478 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1479 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_1480 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1481 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_1482 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1483 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_1484 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1485 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_1486 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_1487 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c99, cp_1 = c99_p_0, cp_0 = 0;
												c < c99 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1464);
												mem_vec_1464 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1465);
												mem_vec_1465 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1466);
												mem_vec_1466 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1467);
												mem_vec_1467 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1468);
												mem_vec_1468 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1469);
												mem_vec_1469 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1470);
												mem_vec_1470 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1471);
												mem_vec_1471 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1472);
												mem_vec_1472 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1473);
												mem_vec_1473 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1474);
												mem_vec_1474 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1475);
												mem_vec_1475 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1476);
												mem_vec_1476 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1477);
												mem_vec_1477 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1478);
												mem_vec_1478 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1479);
												mem_vec_1479 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1480);
												mem_vec_1480 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1481);
												mem_vec_1481 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1482);
												mem_vec_1482 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1483);
												mem_vec_1483 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_1484);
												mem_vec_1484 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_1485);
												mem_vec_1485 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_1486);
												mem_vec_1486 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_1487);
												mem_vec_1487 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_1464);
												mem_vec_1464 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_1465);
												mem_vec_1465 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_1466);
												mem_vec_1466 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_1467);
												mem_vec_1467 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_1468);
												mem_vec_1468 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_1469);
												mem_vec_1469 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_1470);
												mem_vec_1470 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_1471);
												mem_vec_1471 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_1472);
												mem_vec_1472 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_1473);
												mem_vec_1473 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_1474);
												mem_vec_1474 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_1475);
												mem_vec_1475 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_1476);
												mem_vec_1476 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_1477);
												mem_vec_1477 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_1478);
												mem_vec_1478 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_1479);
												mem_vec_1479 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_1480);
												mem_vec_1480 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_1481);
												mem_vec_1481 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_1482);
												mem_vec_1482 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_1483);
												mem_vec_1483 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_1484);
												mem_vec_1484 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_1485);
												mem_vec_1485 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_1486);
												mem_vec_1486 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_1487);
												mem_vec_1487 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_1464);
												mem_vec_1464 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_1465);
												mem_vec_1465 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_1466);
												mem_vec_1466 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_1467);
												mem_vec_1467 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_1468);
												mem_vec_1468 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_1469);
												mem_vec_1469 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_1470);
												mem_vec_1470 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_1471);
												mem_vec_1471 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_1472);
												mem_vec_1472 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_1473);
												mem_vec_1473 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_1474);
												mem_vec_1474 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_1475);
												mem_vec_1475 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_1476);
												mem_vec_1476 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_1477);
												mem_vec_1477 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_1478);
												mem_vec_1478 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_1479);
												mem_vec_1479 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_1480);
												mem_vec_1480 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_1481);
												mem_vec_1481 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_1482);
												mem_vec_1482 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_1483);
												mem_vec_1483 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_1484);
												mem_vec_1484 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_1485);
												mem_vec_1485 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_1486);
												mem_vec_1486 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_1487);
												mem_vec_1487 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1464);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1465);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1466);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1467);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1468);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1469);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1470);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1471);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1472);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1473);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1474);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1475);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1476);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1477);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1478);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1479);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1480);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1481);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1482);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1483);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1484);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_1485);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1486);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_1487);
								}
							}
						}
					}
				}
				for (y = y69 + 42, yp_0 = 0;
					y < y69 + 42 + 14;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
					// T (f, 1) (32 / 32)
					for (f = f126, fp_2 = f126_p_1, fp_1 = f126_p_0, fp_0 = 0;
						f < f126 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (c, 2) (64 / 32)
						for (c99 = c100, c99_p_0 = 0;
							c99 < c100 + 64;
							c99 += 32, c99_p_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w66, wp_0 = 0;
								w < w66 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x99, xp_1 = x99_p_0, xp_0 = 0;
									x < x99 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1488 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1489 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1490 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1491 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_1492 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1493 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1494 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1495 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_1496 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1497 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1498 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1499 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_1500 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1501 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1502 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1503 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_1504 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1505 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_1506 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1507 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_1508 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1509 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_1510 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_1511 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											mem_vec_1512 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_1513 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_1514 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_1515 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c99, cp_1 = c99_p_0, cp_0 = 0;
												c < c99 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1488);
												mem_vec_1488 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1489);
												mem_vec_1489 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1490);
												mem_vec_1490 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1491);
												mem_vec_1491 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1492);
												mem_vec_1492 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1493);
												mem_vec_1493 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1494);
												mem_vec_1494 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1495);
												mem_vec_1495 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1496);
												mem_vec_1496 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1497);
												mem_vec_1497 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1498);
												mem_vec_1498 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1499);
												mem_vec_1499 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1500);
												mem_vec_1500 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1501);
												mem_vec_1501 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1502);
												mem_vec_1502 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1503);
												mem_vec_1503 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1504);
												mem_vec_1504 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1505);
												mem_vec_1505 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1506);
												mem_vec_1506 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1507);
												mem_vec_1507 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_1508);
												mem_vec_1508 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_1509);
												mem_vec_1509 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_1510);
												mem_vec_1510 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_1511);
												mem_vec_1511 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_1512);
												mem_vec_1512 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_1513);
												mem_vec_1513 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_1514);
												mem_vec_1514 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_1515);
												mem_vec_1515 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_40 = _mm256_set1_ps(scal_7);
												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_1488);
												mem_vec_1488 = vec_39;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_1489);
												mem_vec_1489 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_1490);
												mem_vec_1490 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_1491);
												mem_vec_1491 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_1492);
												mem_vec_1492 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_1493);
												mem_vec_1493 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_1494);
												mem_vec_1494 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_1495);
												mem_vec_1495 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_1496);
												mem_vec_1496 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_1497);
												mem_vec_1497 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_1498);
												mem_vec_1498 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_1499);
												mem_vec_1499 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_1500);
												mem_vec_1500 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_1501);
												mem_vec_1501 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_1502);
												mem_vec_1502 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_1503);
												mem_vec_1503 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_1504);
												mem_vec_1504 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_1505);
												mem_vec_1505 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_1506);
												mem_vec_1506 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_1507);
												mem_vec_1507 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_69 = _mm256_set1_ps(scal_12);


												vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_1508);
												mem_vec_1508 = vec_68;



												vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_1509);
												mem_vec_1509 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_1510);
												mem_vec_1510 = vec_71;



												vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_1511);
												mem_vec_1511 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_13);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_1512);
												mem_vec_1512 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_1513);
												mem_vec_1513 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_1514);
												mem_vec_1514 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_1515);
												mem_vec_1515 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_14);
												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_1488);
												mem_vec_1488 = vec_78;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_1489);
												mem_vec_1489 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_1490);
												mem_vec_1490 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_1491);
												mem_vec_1491 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_1492);
												mem_vec_1492 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_1493);
												mem_vec_1493 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_1494);
												mem_vec_1494 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_1495);
												mem_vec_1495 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_1496);
												mem_vec_1496 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_1497);
												mem_vec_1497 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_1498);
												mem_vec_1498 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_1499);
												mem_vec_1499 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_1500);
												mem_vec_1500 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_1501);
												mem_vec_1501 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_1502);
												mem_vec_1502 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_1503);
												mem_vec_1503 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_18);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_1504);
												mem_vec_1504 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_1505);
												mem_vec_1505 = vec_104;



												vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_1506);
												mem_vec_1506 = vec_105;



												vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_1507);
												mem_vec_1507 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_108 = _mm256_set1_ps(scal_19);


												vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_1508);
												mem_vec_1508 = vec_107;



												vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_1509);
												mem_vec_1509 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_1510);
												mem_vec_1510 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_1511);
												mem_vec_1511 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_113 = _mm256_set1_ps(scal_20);


												vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_1512);
												mem_vec_1512 = vec_112;



												vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_1513);
												mem_vec_1513 = vec_114;



												vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_1514);
												mem_vec_1514 = vec_115;



												vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_1515);
												mem_vec_1515 = vec_116;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1488);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1489);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1490);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1491);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1492);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1493);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1494);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1495);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1496);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1497);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1498);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1499);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1500);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1501);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1502);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1503);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1504);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1505);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1506);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1507);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1508);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_1509);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1510);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_1511);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1512);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_1513);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1514);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_1515);
								}
							}
						}
					}
				}
		}
	}
}


}