
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (1, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (2, x);
  T (2, f); T (4, f)]
*/
IND_TYPE c, cp_0, c105_p_0, cp_1, c105, f, fp_0, f130_p_0, f131_p_0, fp_1, f130_p_1, fp_2, f130, f131, h, hp_0, x, xp_0, x110_p_0, xp_1, x110, y, yp_0;
IND_TYPE y75 = 0;
IND_TYPE x111 = 0;
IND_TYPE h70 = 0;
IND_TYPE w = 0;
IND_TYPE c106 = 0;
IND_TYPE f132 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1594 ,mem_vec_1595 ,mem_vec_1596 ,mem_vec_1597 ,mem_vec_1598 ,mem_vec_1599 ,mem_vec_1600 ,mem_vec_1601 ,mem_vec_1602 ,mem_vec_1603 ,mem_vec_1604 ,mem_vec_1605 ,mem_vec_1606 ,mem_vec_1607 ,mem_vec_1608 ,mem_vec_1609 ,mem_vec_1610 ,mem_vec_1611 ,mem_vec_1612 ,mem_vec_1613 ,mem_vec_1614 ,mem_vec_1615 ,mem_vec_1616 ,mem_vec_1617 ,mem_vec_1618 ,mem_vec_1619 ,mem_vec_1620 ,mem_vec_1621 ,mem_vec_1622 ,mem_vec_1623 ,mem_vec_1624 ,mem_vec_1625 ,mem_vec_1626 ,mem_vec_1627 ,mem_vec_1628 ,mem_vec_1629 ,mem_vec_1630 ,mem_vec_1631 ,mem_vec_1632 ,mem_vec_1633 ,mem_vec_1634 ,mem_vec_1635 ,mem_vec_1636 ,mem_vec_1637 ,mem_vec_1638 ,mem_vec_1639 ,mem_vec_1640 ,mem_vec_1641 ,mem_vec_1642 ,mem_vec_1643 ,mem_vec_1644 ,mem_vec_1645 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
f131 = 0;
f131_p_0 = 0;
f130 = 0;
f130_p_1 = 0;
x110 = 0;
x110_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c105 = 0;
c105_p_0 = 0;
							for (h = h70, hp_0 = 0;h < h70 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 256, f = 64
								// T (x, 17) (17 / 1)
								for (x = x110, xp_1 = x110_p_0, xp_0 = 0;x < x110 + 17;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1594 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_1595 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_1596 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_1597 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_1598 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_1599 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_1600 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_1601 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_1602 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_1603 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_1604 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
											mem_vec_1605 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
											mem_vec_1606 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_1607 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_1608 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
											mem_vec_1609 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
											mem_vec_1610 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_1611 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_1612 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
											mem_vec_1613 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
											mem_vec_1614 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_1615 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_1616 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
											mem_vec_1617 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c105, cp_1 = c105_p_0, cp_0 = 0;c < c105 + 256;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1594);
												mem_vec_1594 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1595);
												mem_vec_1595 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1596);
												mem_vec_1596 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1597);
												mem_vec_1597 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1598);
												mem_vec_1598 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1599);
												mem_vec_1599 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1600);
												mem_vec_1600 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1601);
												mem_vec_1601 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1602);
												mem_vec_1602 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1603);
												mem_vec_1603 = vec_16;
												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1604);
												mem_vec_1604 = vec_17;
												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1605);
												mem_vec_1605 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1606);
												mem_vec_1606 = vec_19;
												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1607);
												mem_vec_1607 = vec_21;
												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1608);
												mem_vec_1608 = vec_22;
												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1609);
												mem_vec_1609 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1610);
												mem_vec_1610 = vec_24;
												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1611);
												mem_vec_1611 = vec_26;
												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1612);
												mem_vec_1612 = vec_27;
												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1613);
												mem_vec_1613 = vec_28;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1614);
												mem_vec_1614 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1615);
												mem_vec_1615 = vec_31;
												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1616);
												mem_vec_1616 = vec_32;
												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1617);
												mem_vec_1617 = vec_33;
												scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_36 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_1594);
												mem_vec_1594 = vec_34;
												vec_38 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_1595);
												mem_vec_1595 = vec_37;
												vec_40 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
												vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_1596);
												mem_vec_1596 = vec_39;
												vec_42 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
												vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_1597);
												mem_vec_1597 = vec_41;
												scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);
												vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_1598);
												mem_vec_1598 = vec_43;
												vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_1599);
												mem_vec_1599 = vec_45;
												vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_1600);
												mem_vec_1600 = vec_46;
												vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_1601);
												mem_vec_1601 = vec_47;
												scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_1602);
												mem_vec_1602 = vec_48;
												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_1603);
												mem_vec_1603 = vec_50;
												vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_1604);
												mem_vec_1604 = vec_51;
												vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_1605);
												mem_vec_1605 = vec_52;
												scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);
												vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_1606);
												mem_vec_1606 = vec_53;
												vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_1607);
												mem_vec_1607 = vec_55;
												vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_1608);
												mem_vec_1608 = vec_56;
												vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_1609);
												mem_vec_1609 = vec_57;
												scal_10 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);
												vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_1610);
												mem_vec_1610 = vec_58;
												vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_1611);
												mem_vec_1611 = vec_60;
												vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_1612);
												mem_vec_1612 = vec_61;
												vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_1613);
												mem_vec_1613 = vec_62;
												scal_11 = input[strideA1 * (x + w + 1) + strideA2 * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);
												vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_1614);
												mem_vec_1614 = vec_63;
												vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_1615);
												mem_vec_1615 = vec_65;
												vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_1616);
												mem_vec_1616 = vec_66;
												vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_1617);
												mem_vec_1617 = vec_67;
												scal_12 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_70 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_1594);
												mem_vec_1594 = vec_68;
												vec_72 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_1595);
												mem_vec_1595 = vec_71;
												vec_74 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
												vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_1596);
												mem_vec_1596 = vec_73;
												vec_76 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
												vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_1597);
												mem_vec_1597 = vec_75;
												scal_13 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);
												vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_1598);
												mem_vec_1598 = vec_77;
												vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_1599);
												mem_vec_1599 = vec_79;
												vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_1600);
												mem_vec_1600 = vec_80;
												vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_1601);
												mem_vec_1601 = vec_81;
												scal_14 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);
												vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_1602);
												mem_vec_1602 = vec_82;
												vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_1603);
												mem_vec_1603 = vec_84;
												vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_1604);
												mem_vec_1604 = vec_85;
												vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_1605);
												mem_vec_1605 = vec_86;
												scal_15 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);
												vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_1606);
												mem_vec_1606 = vec_87;
												vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_1607);
												mem_vec_1607 = vec_89;
												vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_1608);
												mem_vec_1608 = vec_90;
												vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_1609);
												mem_vec_1609 = vec_91;
												scal_16 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);
												vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_1610);
												mem_vec_1610 = vec_92;
												vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_1611);
												mem_vec_1611 = vec_94;
												vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_1612);
												mem_vec_1612 = vec_95;
												vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_1613);
												mem_vec_1613 = vec_96;
												scal_17 = input[strideA1 * (x + w + 2) + strideA2 * (y + 5 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);
												vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_1614);
												mem_vec_1614 = vec_97;
												vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_1615);
												mem_vec_1615 = vec_99;
												vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_1616);
												mem_vec_1616 = vec_100;
												vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_1617);
												mem_vec_1617 = vec_101;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1594);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1595);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_1596);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_1597);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1598);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1599);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_1600);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_1601);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1602);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1603);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_1604);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_1605);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1606);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1607);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_1608);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_1609);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1610);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1611);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_1612);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_1613);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1614);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1615);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_1616);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_1617);
								}
							}
}
