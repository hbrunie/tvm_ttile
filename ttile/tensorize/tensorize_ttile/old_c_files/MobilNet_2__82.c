#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (1, x);
  Lambda_apply y [((Iter 4), (Arg 11)); ((Iter 1), (Arg 12))]; T (2, f);
  T (8, c); T (28, x)]
*/
IND_TYPE c, cp_0, c1058_p_0, cp_1, c1058, f, fp_0, w, wp_0, x, xp_0, x1224_p_0, x1225_p_0, xp_1, x1224_p_1, xp_2, x1224, x1225, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y652 = 0;
IND_TYPE x1226 = 0;
IND_TYPE h = 0;
IND_TYPE w628 = 0;
IND_TYPE c1059 = 0;
IND_TYPE f572 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10752 ,mem_vec_10753 ,mem_vec_10754 ,mem_vec_10755 ,mem_vec_10756 ,mem_vec_10757 ,mem_vec_10758 ,mem_vec_10759 ,mem_vec_10760 ,mem_vec_10761 ,mem_vec_10762 ,mem_vec_10763 ,mem_vec_10764 ,mem_vec_10765 ,mem_vec_10766 ,mem_vec_10767 ,mem_vec_10768 ,mem_vec_10769 ,mem_vec_10770 ,mem_vec_10771 ,mem_vec_10772 ,mem_vec_10773 ,mem_vec_10774 ,mem_vec_10775 ,mem_vec_10776 ,mem_vec_10777 ,mem_vec_10778 ,mem_vec_10779 ,mem_vec_10780 ,mem_vec_10781 ,mem_vec_10782 ,mem_vec_10783 ,mem_vec_10784 ,mem_vec_10785 ,mem_vec_10786 ,mem_vec_10787 ,mem_vec_10788 ,mem_vec_10789 ,mem_vec_10790 ,mem_vec_10791 ,mem_vec_10792 ,mem_vec_10793 ,mem_vec_10794 ,mem_vec_10795 ,mem_vec_10796 ,mem_vec_10797 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 28) (56 / 2)
for (x1225 = x1226, x1225_p_0 = 0;
	x1225 < x1226 + 56;
	x1225 += 2, x1225_p_0 += 2){
	// y = 56, x = 2, h = 3, w = 3, c = 64, f = 64
	// T (c, 8) (64 / 8)
	for (c1058 = c1059, c1058_p_0 = 0;
		c1058 < c1059 + 64;
		c1058 += 8, c1058_p_0 += 8){
		// y = 56, x = 2, h = 3, w = 3, c = 8, f = 64
		// T (f, 2) (64 / 32)
		for (f = f572, fp_0 = 0;
			f < f572 + 64;
			f += 32, fp_0 += 32){
				for (y = y652, yp_0 = 0;
					y < y652 + 44;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
					// T (x, 1) (2 / 2)
					for (x1224 = x1225, x1224_p_1 = x1225_p_0, x1224_p_0 = 0;
						x1224 < x1225 + 2;
						x1224 += 2, x1224_p_1 += 2, x1224_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
						// T (w, 3) (3 / 1)
						for (w = w628, wp_0 = 0;
							w < w628 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 3, w = 1, c = 8, f = 32
							// T (x, 2) (2 / 1)
							for (x = x1224, xp_2 = x1224_p_1, xp_1 = x1224_p_0, xp_0 = 0;
								x < x1224 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10752 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10753 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_10761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_10762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_10763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_10764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_10765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_10766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_10767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_10768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_10769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_10770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_10771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_10772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_10773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c1058, cp_1 = c1058_p_0, cp_0 = 0;
											c < c1058 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10752);
											mem_vec_10752 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10753);
											mem_vec_10753 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10754);
											mem_vec_10754 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10755);
											mem_vec_10755 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10756);
											mem_vec_10756 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10757);
											mem_vec_10757 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10758);
											mem_vec_10758 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10759);
											mem_vec_10759 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10760);
											mem_vec_10760 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10761);
											mem_vec_10761 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10762);
											mem_vec_10762 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10763);
											mem_vec_10763 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10764);
											mem_vec_10764 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10765);
											mem_vec_10765 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10766);
											mem_vec_10766 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10767);
											mem_vec_10767 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10768);
											mem_vec_10768 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10769);
											mem_vec_10769 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10770);
											mem_vec_10770 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10771);
											mem_vec_10771 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10772);
											mem_vec_10772 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10773);
											mem_vec_10773 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_10752);
											mem_vec_10752 = vec_35;

											vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_10753);
											mem_vec_10753 = vec_38;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_10754);
											mem_vec_10754 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_10755);
											mem_vec_10755 = vec_42;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_10756);
											mem_vec_10756 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_10757);
											mem_vec_10757 = vec_45;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_10758);
											mem_vec_10758 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_10759);
											mem_vec_10759 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_10760);
											mem_vec_10760 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_10761);
											mem_vec_10761 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_10762);
											mem_vec_10762 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_10763);
											mem_vec_10763 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_10764);
											mem_vec_10764 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_10765);
											mem_vec_10765 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_10766);
											mem_vec_10766 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_10767);
											mem_vec_10767 = vec_60;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_10768);
											mem_vec_10768 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_10769);
											mem_vec_10769 = vec_63;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_10770);
											mem_vec_10770 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_10771);
											mem_vec_10771 = vec_66;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_10772);
											mem_vec_10772 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_10773);
											mem_vec_10773 = vec_69;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_71 = _mm512_set1_ps(scal_22);
											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_10752);
											mem_vec_10752 = vec_70;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_10753);
											mem_vec_10753 = vec_73;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_10754);
											mem_vec_10754 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_10755);
											mem_vec_10755 = vec_77;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_10756);
											mem_vec_10756 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_10757);
											mem_vec_10757 = vec_80;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_10758);
											mem_vec_10758 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_10759);
											mem_vec_10759 = vec_83;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_10760);
											mem_vec_10760 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_10761);
											mem_vec_10761 = vec_86;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_10762);
											mem_vec_10762 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_10763);
											mem_vec_10763 = vec_89;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_10764);
											mem_vec_10764 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_10765);
											mem_vec_10765 = vec_92;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_10766);
											mem_vec_10766 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_10767);
											mem_vec_10767 = vec_95;
											scal_30 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_97 = _mm512_set1_ps(scal_30);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_10768);
											mem_vec_10768 = vec_96;



											vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_10769);
											mem_vec_10769 = vec_98;
											scal_31 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_10770);
											mem_vec_10770 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_10771);
											mem_vec_10771 = vec_101;
											scal_32 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_10772);
											mem_vec_10772 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_10773);
											mem_vec_10773 = vec_104;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10752);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10753);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10754);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10755);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10756);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10757);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10758);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10759);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10760);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10761);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10762);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10763);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10764);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10765);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10766);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10767);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10768);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10769);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10770);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10771);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10772);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10773);
							}
						}
					}
				}
				for (y = y652 + 44, yp_0 = 0;
					y < y652 + 44 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
					// T (x, 1) (2 / 2)
					for (x1224 = x1225, x1224_p_1 = x1225_p_0, x1224_p_0 = 0;
						x1224 < x1225 + 2;
						x1224 += 2, x1224_p_1 += 2, x1224_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
						// T (w, 3) (3 / 1)
						for (w = w628, wp_0 = 0;
							w < w628 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 3, w = 1, c = 8, f = 32
							// T (x, 2) (2 / 1)
							for (x = x1224, xp_2 = x1224_p_1, xp_1 = x1224_p_0, xp_0 = 0;
								x < x1224 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10774 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10775 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_10783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_10784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_10785 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_10786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_10787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_10788 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_10789 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_10790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_10791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_10792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_10793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_10794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_10795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_10796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_10797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c1058, cp_1 = c1058_p_0, cp_0 = 0;
											c < c1058 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10774);
											mem_vec_10774 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10775);
											mem_vec_10775 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10776);
											mem_vec_10776 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10777);
											mem_vec_10777 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10778);
											mem_vec_10778 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10779);
											mem_vec_10779 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10780);
											mem_vec_10780 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10781);
											mem_vec_10781 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10782);
											mem_vec_10782 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10783);
											mem_vec_10783 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10784);
											mem_vec_10784 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10785);
											mem_vec_10785 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10786);
											mem_vec_10786 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10787);
											mem_vec_10787 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10788);
											mem_vec_10788 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10789);
											mem_vec_10789 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10790);
											mem_vec_10790 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10791);
											mem_vec_10791 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10792);
											mem_vec_10792 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10793);
											mem_vec_10793 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10794);
											mem_vec_10794 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10795);
											mem_vec_10795 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_10796);
											mem_vec_10796 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_10797);
											mem_vec_10797 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_12);
											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_10774);
											mem_vec_10774 = vec_38;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_10775);
											mem_vec_10775 = vec_41;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_10776);
											mem_vec_10776 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_10777);
											mem_vec_10777 = vec_45;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_40, mem_vec_10778);
											mem_vec_10778 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_42, mem_vec_10779);
											mem_vec_10779 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_10780);
											mem_vec_10780 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_42, mem_vec_10781);
											mem_vec_10781 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_10782);
											mem_vec_10782 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_10783);
											mem_vec_10783 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_10784);
											mem_vec_10784 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_42, mem_vec_10785);
											mem_vec_10785 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_10786);
											mem_vec_10786 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_10787);
											mem_vec_10787 = vec_60;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_40, mem_vec_10788);
											mem_vec_10788 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_42, mem_vec_10789);
											mem_vec_10789 = vec_63;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_40, mem_vec_10790);
											mem_vec_10790 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_42, mem_vec_10791);
											mem_vec_10791 = vec_66;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_40, mem_vec_10792);
											mem_vec_10792 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_42, mem_vec_10793);
											mem_vec_10793 = vec_69;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 1) + c];
											vec_71 = _mm512_set1_ps(scal_22);


											vec_70 = _mm512_fmadd_ps(vec_71, vec_40, mem_vec_10794);
											mem_vec_10794 = vec_70;



											vec_72 = _mm512_fmadd_ps(vec_71, vec_42, mem_vec_10795);
											mem_vec_10795 = vec_72;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h + 1) + c];
											vec_74 = _mm512_set1_ps(scal_23);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_40, mem_vec_10796);
											mem_vec_10796 = vec_73;



											vec_75 = _mm512_fmadd_ps(vec_74, vec_42, mem_vec_10797);
											mem_vec_10797 = vec_75;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_77 = _mm512_set1_ps(scal_24);
											vec_78 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_76 = _mm512_fmadd_ps(vec_77, vec_78, mem_vec_10774);
											mem_vec_10774 = vec_76;

											vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_79 = _mm512_fmadd_ps(vec_77, vec_80, mem_vec_10775);
											mem_vec_10775 = vec_79;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_78, mem_vec_10776);
											mem_vec_10776 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_80, mem_vec_10777);
											mem_vec_10777 = vec_83;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_78, mem_vec_10778);
											mem_vec_10778 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_80, mem_vec_10779);
											mem_vec_10779 = vec_86;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_10780);
											mem_vec_10780 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_10781);
											mem_vec_10781 = vec_89;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_78, mem_vec_10782);
											mem_vec_10782 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_80, mem_vec_10783);
											mem_vec_10783 = vec_92;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_78, mem_vec_10784);
											mem_vec_10784 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_80, mem_vec_10785);
											mem_vec_10785 = vec_95;
											scal_30 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_97 = _mm512_set1_ps(scal_30);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_78, mem_vec_10786);
											mem_vec_10786 = vec_96;



											vec_98 = _mm512_fmadd_ps(vec_97, vec_80, mem_vec_10787);
											mem_vec_10787 = vec_98;
											scal_31 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_78, mem_vec_10788);
											mem_vec_10788 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_80, mem_vec_10789);
											mem_vec_10789 = vec_101;
											scal_32 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_78, mem_vec_10790);
											mem_vec_10790 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_10791);
											mem_vec_10791 = vec_104;
											scal_33 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
											vec_106 = _mm512_set1_ps(scal_33);


											vec_105 = _mm512_fmadd_ps(vec_106, vec_78, mem_vec_10792);
											mem_vec_10792 = vec_105;



											vec_107 = _mm512_fmadd_ps(vec_106, vec_80, mem_vec_10793);
											mem_vec_10793 = vec_107;
											scal_34 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 2) + c];
											vec_109 = _mm512_set1_ps(scal_34);


											vec_108 = _mm512_fmadd_ps(vec_109, vec_78, mem_vec_10794);
											mem_vec_10794 = vec_108;



											vec_110 = _mm512_fmadd_ps(vec_109, vec_80, mem_vec_10795);
											mem_vec_10795 = vec_110;
											scal_35 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h + 2) + c];
											vec_112 = _mm512_set1_ps(scal_35);


											vec_111 = _mm512_fmadd_ps(vec_112, vec_78, mem_vec_10796);
											mem_vec_10796 = vec_111;



											vec_113 = _mm512_fmadd_ps(vec_112, vec_80, mem_vec_10797);
											mem_vec_10797 = vec_113;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10774);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10775);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10776);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10777);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10778);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10779);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10780);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10781);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10782);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10783);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10784);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10785);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10786);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10787);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10788);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10789);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10790);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10791);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10792);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10793);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10794);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10795);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_10796);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_10797);
							}
						}
					}
				}
		}
	}
}


}