#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (1, c); T (1, x); T (17, y); T (272, x);
  Lambda_apply y [((Iter 4), (Arg 3)); ((Iter 1), (Arg 4))]]
*/
IND_TYPE c, cp_0, c141_p_0, cp_1, c141, h, hp_0, x, xp_0, x188_p_0, x189_p_0, xp_1, x188_p_1, xp_2, x188, x189, y, yp_0, y165_p_0, yp_1, y165;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y166 = 0;
IND_TYPE x190 = 0;
IND_TYPE h63 = 0;
IND_TYPE w = 0;
IND_TYPE c142 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1648 ,mem_vec_1649 ,mem_vec_1650 ,mem_vec_1651 ,mem_vec_1652 ,mem_vec_1653 ,mem_vec_1654 ,mem_vec_1655 ,mem_vec_1656 ,mem_vec_1657 ,mem_vec_1658 ,mem_vec_1659 ,mem_vec_1660 ,mem_vec_1661 ,mem_vec_1662 ,mem_vec_1663 ,mem_vec_1664 ,mem_vec_1665 ,mem_vec_1666 ,mem_vec_1667 ,mem_vec_1668 ,mem_vec_1669 ,mem_vec_1670 ,mem_vec_1671 ,mem_vec_1672 ,mem_vec_1673 ,mem_vec_1674 ,mem_vec_1675 ,mem_vec_1676 ,mem_vec_1677 ,mem_vec_1678 ,mem_vec_1679 ,mem_vec_1680 ,mem_vec_1681 ,mem_vec_1682 ,mem_vec_1683 ,mem_vec_1684 ,mem_vec_1685 ,mem_vec_1686 ,mem_vec_1687 ,mem_vec_1688 ,mem_vec_1689 ,mem_vec_1690 ,mem_vec_1691 ,mem_vec_1692 ,mem_vec_1693 ,mem_vec_1694 ,mem_vec_1695 ,mem_vec_1696 ,mem_vec_1697 ,mem_vec_1698 ,mem_vec_1699 ,mem_vec_1700 ,mem_vec_1701 ,mem_vec_1702 ,mem_vec_1703 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
	for (y165 = y166, y165_p_0 = 0;
		y165 < y166 + 204;
		y165 += 51, y165_p_0 += 51){
		// y = 17 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
		// T (x, 272) (272 / 1)
		for (x189 = x190, x189_p_0 = 0;
			x189 < x190 + 272;
			x189 += 1, x189_p_0 += 1){
			// y = 17 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
			// T (y, 17) (17 * ph_y / ph_y)
			for (y = y165, yp_1 = y165_p_0, yp_0 = 0;
				y < y165 + 51;
				y += 3, yp_1 += 3, yp_0 += 3){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (x, 1) (1 / 1)
				for (x188 = x189, x188_p_1 = x189_p_0, x188_p_0 = 0;
					x188 < x189 + 1;
					x188 += 1, x188_p_1 += 1, x188_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (c, 1) (32 / 32)
					for (c141 = c142, c141_p_0 = 0;
						c141 < c142 + 32;
						c141 += 32, c141_p_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h63, hp_0 = 0;
							h < h63 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
							// T (x, 1) (1 / 1)
							for (x = x188, xp_2 = x188_p_1, xp_1 = x188_p_0, xp_0 = 0;
								x < x188 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1648 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1649 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_1650 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1651 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_1652 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_1653 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
										mem_vec_1654 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_1655 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
										mem_vec_1656 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1657 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_1658 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1659 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_1660 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_1661 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
										mem_vec_1662 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_1663 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
										mem_vec_1664 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1665 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_1666 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1667 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_1668 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_1669 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
										mem_vec_1670 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_1671 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c141, cp_1 = c141_p_0, cp_0 = 0;
											c < c141 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1648);
											mem_vec_1648 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1649);
											mem_vec_1649 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1650);
											mem_vec_1650 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1651);
											mem_vec_1651 = vec_7;

											vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_1652);
											mem_vec_1652 = vec_9;

											vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

											vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_1653);
											mem_vec_1653 = vec_11;

											vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_1654);
											mem_vec_1654 = vec_13;

											vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

											vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_1655);
											mem_vec_1655 = vec_15;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_18 = _mm256_set1_ps(scal_1);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_1656);
											mem_vec_1656 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_1657);
											mem_vec_1657 = vec_19;



											vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_1658);
											mem_vec_1658 = vec_20;



											vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_1659);
											mem_vec_1659 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_1660);
											mem_vec_1660 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_1661);
											mem_vec_1661 = vec_23;



											vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_1662);
											mem_vec_1662 = vec_24;



											vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_1663);
											mem_vec_1663 = vec_25;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_27 = _mm256_set1_ps(scal_2);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_1664);
											mem_vec_1664 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_1665);
											mem_vec_1665 = vec_28;



											vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_1666);
											mem_vec_1666 = vec_29;



											vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_1667);
											mem_vec_1667 = vec_30;



											vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_1668);
											mem_vec_1668 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_1669);
											mem_vec_1669 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_1670);
											mem_vec_1670 = vec_33;



											vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_1671);
											mem_vec_1671 = vec_34;
											scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_36 = _mm256_set1_ps(scal_3);
											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_1648);
											mem_vec_1648 = vec_35;

											vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_1649);
											mem_vec_1649 = vec_38;

											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_40 = _mm256_fmadd_ps(vec_36, vec_41, mem_vec_1650);
											mem_vec_1650 = vec_40;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_42 = _mm256_fmadd_ps(vec_36, vec_43, mem_vec_1651);
											mem_vec_1651 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_44 = _mm256_fmadd_ps(vec_36, vec_45, mem_vec_1652);
											mem_vec_1652 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

											vec_46 = _mm256_fmadd_ps(vec_36, vec_47, mem_vec_1653);
											mem_vec_1653 = vec_46;

											vec_49 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_48 = _mm256_fmadd_ps(vec_36, vec_49, mem_vec_1654);
											mem_vec_1654 = vec_48;

											vec_51 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

											vec_50 = _mm256_fmadd_ps(vec_36, vec_51, mem_vec_1655);
											mem_vec_1655 = vec_50;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_53 = _mm256_set1_ps(scal_4);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_1656);
											mem_vec_1656 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_1657);
											mem_vec_1657 = vec_54;



											vec_55 = _mm256_fmadd_ps(vec_53, vec_41, mem_vec_1658);
											mem_vec_1658 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_1659);
											mem_vec_1659 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_1660);
											mem_vec_1660 = vec_57;



											vec_58 = _mm256_fmadd_ps(vec_53, vec_47, mem_vec_1661);
											mem_vec_1661 = vec_58;



											vec_59 = _mm256_fmadd_ps(vec_53, vec_49, mem_vec_1662);
											mem_vec_1662 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_53, vec_51, mem_vec_1663);
											mem_vec_1663 = vec_60;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_62 = _mm256_set1_ps(scal_5);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_1664);
											mem_vec_1664 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_1665);
											mem_vec_1665 = vec_63;



											vec_64 = _mm256_fmadd_ps(vec_62, vec_41, mem_vec_1666);
											mem_vec_1666 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_1667);
											mem_vec_1667 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_1668);
											mem_vec_1668 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_62, vec_47, mem_vec_1669);
											mem_vec_1669 = vec_67;



											vec_68 = _mm256_fmadd_ps(vec_62, vec_49, mem_vec_1670);
											mem_vec_1670 = vec_68;



											vec_69 = _mm256_fmadd_ps(vec_62, vec_51, mem_vec_1671);
											mem_vec_1671 = vec_69;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_71 = _mm256_set1_ps(scal_6);
											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_1648);
											mem_vec_1648 = vec_70;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_1649);
											mem_vec_1649 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_75 = _mm256_fmadd_ps(vec_71, vec_76, mem_vec_1650);
											mem_vec_1650 = vec_75;

											vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_77 = _mm256_fmadd_ps(vec_71, vec_78, mem_vec_1651);
											mem_vec_1651 = vec_77;

											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_79 = _mm256_fmadd_ps(vec_71, vec_80, mem_vec_1652);
											mem_vec_1652 = vec_79;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

											vec_81 = _mm256_fmadd_ps(vec_71, vec_82, mem_vec_1653);
											mem_vec_1653 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_83 = _mm256_fmadd_ps(vec_71, vec_84, mem_vec_1654);
											mem_vec_1654 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

											vec_85 = _mm256_fmadd_ps(vec_71, vec_86, mem_vec_1655);
											mem_vec_1655 = vec_85;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_88 = _mm256_set1_ps(scal_7);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_1656);
											mem_vec_1656 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_1657);
											mem_vec_1657 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_1658);
											mem_vec_1658 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_1659);
											mem_vec_1659 = vec_91;



											vec_92 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_1660);
											mem_vec_1660 = vec_92;



											vec_93 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_1661);
											mem_vec_1661 = vec_93;



											vec_94 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_1662);
											mem_vec_1662 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_1663);
											mem_vec_1663 = vec_95;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_97 = _mm256_set1_ps(scal_8);


											vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_1664);
											mem_vec_1664 = vec_96;



											vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_1665);
											mem_vec_1665 = vec_98;



											vec_99 = _mm256_fmadd_ps(vec_97, vec_76, mem_vec_1666);
											mem_vec_1666 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_1667);
											mem_vec_1667 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_1668);
											mem_vec_1668 = vec_101;



											vec_102 = _mm256_fmadd_ps(vec_97, vec_82, mem_vec_1669);
											mem_vec_1669 = vec_102;



											vec_103 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_1670);
											mem_vec_1670 = vec_103;



											vec_104 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_1671);
											mem_vec_1671 = vec_104;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1648);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1649);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1650);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1651);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1652);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_1653);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1654);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_1655);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1656);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1657);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1658);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1659);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1660);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_1661);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1662);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_1663);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1664);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1665);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1666);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1667);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1668);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_1669);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1670);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_1671);
							}
						}
					}
				}
			}
		}
	}
	for (y165 = y166 + 204, y165_p_0 = 0;
		y165 < y166 + 204 + 68;
		y165 += 68, y165_p_0 += 68){
		// y = 17 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
		// T (x, 272) (272 / 1)
		for (x189 = x190, x189_p_0 = 0;
			x189 < x190 + 272;
			x189 += 1, x189_p_0 += 1){
			// y = 17 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
			// T (y, 17) (17 * ph_y / ph_y)
			for (y = y165, yp_1 = y165_p_0, yp_0 = 0;
				y < y165 + 68;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (x, 1) (1 / 1)
				for (x188 = x189, x188_p_1 = x189_p_0, x188_p_0 = 0;
					x188 < x189 + 1;
					x188 += 1, x188_p_1 += 1, x188_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (c, 1) (32 / 32)
					for (c141 = c142, c141_p_0 = 0;
						c141 < c142 + 32;
						c141 += 32, c141_p_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h63, hp_0 = 0;
							h < h63 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
							// T (x, 1) (1 / 1)
							for (x = x188, xp_2 = x188_p_1, xp_1 = x188_p_0, xp_0 = 0;
								x < x188 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1672 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1673 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_1674 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1675 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_1676 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_1677 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
										mem_vec_1678 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_1679 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
										mem_vec_1680 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1681 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_1682 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1683 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_1684 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_1685 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
										mem_vec_1686 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_1687 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
										mem_vec_1688 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1689 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_1690 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1691 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_1692 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_1693 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
										mem_vec_1694 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_1695 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
										mem_vec_1696 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1697 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_1698 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1699 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_1700 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_1701 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
										mem_vec_1702 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_1703 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c141, cp_1 = c141_p_0, cp_0 = 0;
											c < c141 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1672);
											mem_vec_1672 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1673);
											mem_vec_1673 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1674);
											mem_vec_1674 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1675);
											mem_vec_1675 = vec_7;

											vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_1676);
											mem_vec_1676 = vec_9;

											vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

											vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_1677);
											mem_vec_1677 = vec_11;

											vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_1678);
											mem_vec_1678 = vec_13;

											vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

											vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_1679);
											mem_vec_1679 = vec_15;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_18 = _mm256_set1_ps(scal_1);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_1680);
											mem_vec_1680 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_1681);
											mem_vec_1681 = vec_19;



											vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_1682);
											mem_vec_1682 = vec_20;



											vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_1683);
											mem_vec_1683 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_1684);
											mem_vec_1684 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_1685);
											mem_vec_1685 = vec_23;



											vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_1686);
											mem_vec_1686 = vec_24;



											vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_1687);
											mem_vec_1687 = vec_25;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_27 = _mm256_set1_ps(scal_2);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_1688);
											mem_vec_1688 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_1689);
											mem_vec_1689 = vec_28;



											vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_1690);
											mem_vec_1690 = vec_29;



											vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_1691);
											mem_vec_1691 = vec_30;



											vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_1692);
											mem_vec_1692 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_1693);
											mem_vec_1693 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_1694);
											mem_vec_1694 = vec_33;



											vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_1695);
											mem_vec_1695 = vec_34;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_36 = _mm256_set1_ps(scal_3);


											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_1696);
											mem_vec_1696 = vec_35;



											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_1697);
											mem_vec_1697 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_1698);
											mem_vec_1698 = vec_38;



											vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_1699);
											mem_vec_1699 = vec_39;



											vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_1700);
											mem_vec_1700 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_1701);
											mem_vec_1701 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_1702);
											mem_vec_1702 = vec_42;



											vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_1703);
											mem_vec_1703 = vec_43;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_45 = _mm256_set1_ps(scal_4);
											vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_1672);
											mem_vec_1672 = vec_44;

											vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_1673);
											mem_vec_1673 = vec_47;

											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_1674);
											mem_vec_1674 = vec_49;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_1675);
											mem_vec_1675 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_1676);
											mem_vec_1676 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

											vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_1677);
											mem_vec_1677 = vec_55;

											vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_1678);
											mem_vec_1678 = vec_57;

											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

											vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_1679);
											mem_vec_1679 = vec_59;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_62 = _mm256_set1_ps(scal_5);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_1680);
											mem_vec_1680 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_1681);
											mem_vec_1681 = vec_63;



											vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_1682);
											mem_vec_1682 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_1683);
											mem_vec_1683 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_1684);
											mem_vec_1684 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_1685);
											mem_vec_1685 = vec_67;



											vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_1686);
											mem_vec_1686 = vec_68;



											vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_1687);
											mem_vec_1687 = vec_69;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_71 = _mm256_set1_ps(scal_6);


											vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_1688);
											mem_vec_1688 = vec_70;



											vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_1689);
											mem_vec_1689 = vec_72;



											vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_1690);
											mem_vec_1690 = vec_73;



											vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_1691);
											mem_vec_1691 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_1692);
											mem_vec_1692 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_1693);
											mem_vec_1693 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_1694);
											mem_vec_1694 = vec_77;



											vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_1695);
											mem_vec_1695 = vec_78;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_80 = _mm256_set1_ps(scal_7);


											vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_1696);
											mem_vec_1696 = vec_79;



											vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_1697);
											mem_vec_1697 = vec_81;



											vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_1698);
											mem_vec_1698 = vec_82;



											vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_1699);
											mem_vec_1699 = vec_83;



											vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_1700);
											mem_vec_1700 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_1701);
											mem_vec_1701 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_1702);
											mem_vec_1702 = vec_86;



											vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_1703);
											mem_vec_1703 = vec_87;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_89 = _mm256_set1_ps(scal_8);
											vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_1672);
											mem_vec_1672 = vec_88;

											vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_1673);
											mem_vec_1673 = vec_91;

											vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_1674);
											mem_vec_1674 = vec_93;

											vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_1675);
											mem_vec_1675 = vec_95;

											vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_1676);
											mem_vec_1676 = vec_97;

											vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

											vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_1677);
											mem_vec_1677 = vec_99;

											vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_1678);
											mem_vec_1678 = vec_101;

											vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

											vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_1679);
											mem_vec_1679 = vec_103;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_106 = _mm256_set1_ps(scal_9);


											vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_1680);
											mem_vec_1680 = vec_105;



											vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_1681);
											mem_vec_1681 = vec_107;



											vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_1682);
											mem_vec_1682 = vec_108;



											vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_1683);
											mem_vec_1683 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_1684);
											mem_vec_1684 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_1685);
											mem_vec_1685 = vec_111;



											vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_1686);
											mem_vec_1686 = vec_112;



											vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_1687);
											mem_vec_1687 = vec_113;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_115 = _mm256_set1_ps(scal_10);


											vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_1688);
											mem_vec_1688 = vec_114;



											vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_1689);
											mem_vec_1689 = vec_116;



											vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_1690);
											mem_vec_1690 = vec_117;



											vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_1691);
											mem_vec_1691 = vec_118;



											vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_1692);
											mem_vec_1692 = vec_119;



											vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_1693);
											mem_vec_1693 = vec_120;



											vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_1694);
											mem_vec_1694 = vec_121;



											vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_1695);
											mem_vec_1695 = vec_122;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_124 = _mm256_set1_ps(scal_11);


											vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_1696);
											mem_vec_1696 = vec_123;



											vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_1697);
											mem_vec_1697 = vec_125;



											vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_1698);
											mem_vec_1698 = vec_126;



											vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_1699);
											mem_vec_1699 = vec_127;



											vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_1700);
											mem_vec_1700 = vec_128;



											vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_1701);
											mem_vec_1701 = vec_129;



											vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_1702);
											mem_vec_1702 = vec_130;



											vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_1703);
											mem_vec_1703 = vec_131;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1672);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1673);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1674);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1675);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1676);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_1677);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1678);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_1679);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1680);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1681);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1682);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1683);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1684);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_1685);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1686);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_1687);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1688);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1689);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1690);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1691);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1692);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_1693);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1694);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_1695);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1696);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1697);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1698);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1699);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1700);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_1701);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1702);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_1703);
							}
						}
					}
				}
			}
		}
	}


}