#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (2, c); T (28, x);
  Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))]; T (2, c)]
*/
IND_TYPE c, cp_0, c1072_p_0, c1073_p_0, cp_1, c1072_p_1, cp_2, c1072, c1073, w, wp_0, x, xp_0, x1196_p_0, xp_1, x1196, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y648 = 0;
IND_TYPE x1197 = 0;
IND_TYPE h = 0;
IND_TYPE w614 = 0;
IND_TYPE c1074 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10758 ,mem_vec_10759 ,mem_vec_10760 ,mem_vec_10761 ,mem_vec_10762 ,mem_vec_10763 ,mem_vec_10764 ,mem_vec_10765 ,mem_vec_10766 ,mem_vec_10767 ,mem_vec_10768 ,mem_vec_10769 ,mem_vec_10770 ,mem_vec_10771 ,mem_vec_10772 ,mem_vec_10773 ,mem_vec_10774 ,mem_vec_10775 ,mem_vec_10776 ,mem_vec_10777 ,mem_vec_10778 ,mem_vec_10779 ,mem_vec_10780 ,mem_vec_10781 ,mem_vec_10782 ,mem_vec_10783 ,mem_vec_10784 ,mem_vec_10785 ,mem_vec_10786 ,mem_vec_10787 ,mem_vec_10788 ,mem_vec_10789 ,mem_vec_10790 ,mem_vec_10791 ,mem_vec_10792 ,mem_vec_10793 ,mem_vec_10794 ,mem_vec_10795 ,mem_vec_10796 ,mem_vec_10797 ,mem_vec_10798 ,mem_vec_10799 ,mem_vec_10800 ,mem_vec_10801 ,mem_vec_10802 ,mem_vec_10803 ,mem_vec_10804 ,mem_vec_10805 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 2) (64 / 32)
for (c1073 = c1074, c1073_p_0 = 0;
	c1073 < c1074 + 64;
	c1073 += 32, c1073_p_0 += 32){
		for (y = y648, yp_0 = 0;
			y < y648 + 35;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 64
			// T (x, 28) (56 / 2)
			for (x1196 = x1197, x1196_p_0 = 0;
				x1196 < x1197 + 56;
				x1196 += 2, x1196_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 64
				// T (c, 2) (32 / 16)
				for (c1072 = c1073, c1072_p_1 = c1073_p_0, c1072_p_0 = 0;
					c1072 < c1073 + 32;
					c1072 += 16, c1072_p_1 += 16, c1072_p_0 += 16){
					// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 64
					// T (w, 3) (3 / 1)
					for (w = w614, wp_0 = 0;
						w < w614 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 2, h = 3, w = 1, c = 16, f = 64
						// T (x, 2) (2 / 1)
						for (x = x1196, xp_1 = x1196_p_0, xp_0 = 0;
							x < x1196 + 2;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10758 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10759 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10760 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10761 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_10774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_10777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c1072, cp_2 = c1072_p_1, cp_1 = c1072_p_0, cp_0 = 0;
										c < c1072 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10758);
										mem_vec_10758 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10759);
										mem_vec_10759 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10760);
										mem_vec_10760 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10761);
										mem_vec_10761 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10762);
										mem_vec_10762 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10763);
										mem_vec_10763 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10764);
										mem_vec_10764 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10765);
										mem_vec_10765 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10766);
										mem_vec_10766 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10767);
										mem_vec_10767 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10768);
										mem_vec_10768 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10769);
										mem_vec_10769 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10770);
										mem_vec_10770 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10771);
										mem_vec_10771 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10772);
										mem_vec_10772 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10773);
										mem_vec_10773 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10774);
										mem_vec_10774 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10775);
										mem_vec_10775 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10776);
										mem_vec_10776 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10777);
										mem_vec_10777 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_10758);
										mem_vec_10758 = vec_29;

										vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_10759);
										mem_vec_10759 = vec_32;

										vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_10760);
										mem_vec_10760 = vec_34;

										vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_10761);
										mem_vec_10761 = vec_36;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_6);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_10762);
										mem_vec_10762 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_10763);
										mem_vec_10763 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_10764);
										mem_vec_10764 = vec_41;



										vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_10765);
										mem_vec_10765 = vec_42;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_10766);
										mem_vec_10766 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_10767);
										mem_vec_10767 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_10768);
										mem_vec_10768 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_10769);
										mem_vec_10769 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_10770);
										mem_vec_10770 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_10771);
										mem_vec_10771 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_10772);
										mem_vec_10772 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_10773);
										mem_vec_10773 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_10774);
										mem_vec_10774 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_10775);
										mem_vec_10775 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_10776);
										mem_vec_10776 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_10777);
										mem_vec_10777 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_59 = _mm512_set1_ps(scal_10);
										vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_10758);
										mem_vec_10758 = vec_58;

										vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_10759);
										mem_vec_10759 = vec_61;

										vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_10760);
										mem_vec_10760 = vec_63;

										vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_10761);
										mem_vec_10761 = vec_65;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_68 = _mm512_set1_ps(scal_11);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_10762);
										mem_vec_10762 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_10763);
										mem_vec_10763 = vec_69;



										vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_10764);
										mem_vec_10764 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_10765);
										mem_vec_10765 = vec_71;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_73 = _mm512_set1_ps(scal_12);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_10766);
										mem_vec_10766 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_10767);
										mem_vec_10767 = vec_74;



										vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_10768);
										mem_vec_10768 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_10769);
										mem_vec_10769 = vec_76;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_78 = _mm512_set1_ps(scal_13);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_10770);
										mem_vec_10770 = vec_77;



										vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_10771);
										mem_vec_10771 = vec_79;



										vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_10772);
										mem_vec_10772 = vec_80;



										vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_10773);
										mem_vec_10773 = vec_81;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_83 = _mm512_set1_ps(scal_14);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_10774);
										mem_vec_10774 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_10775);
										mem_vec_10775 = vec_84;



										vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_10776);
										mem_vec_10776 = vec_85;



										vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_10777);
										mem_vec_10777 = vec_86;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10758);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10759);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10760);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10761);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10762);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10763);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10764);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10765);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10766);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10767);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10768);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10769);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10770);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10771);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10772);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10773);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10774);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10775);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10776);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10777);
						}
					}
				}
			}
		}
		for (y = y648 + 35, yp_0 = 0;
			y < y648 + 35 + 21;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 64
			// T (x, 28) (56 / 2)
			for (x1196 = x1197, x1196_p_0 = 0;
				x1196 < x1197 + 56;
				x1196 += 2, x1196_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 64
				// T (c, 2) (32 / 16)
				for (c1072 = c1073, c1072_p_1 = c1073_p_0, c1072_p_0 = 0;
					c1072 < c1073 + 32;
					c1072 += 16, c1072_p_1 += 16, c1072_p_0 += 16){
					// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 64
					// T (w, 3) (3 / 1)
					for (w = w614, wp_0 = 0;
						w < w614 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 2, h = 3, w = 1, c = 16, f = 64
						// T (x, 2) (2 / 1)
						for (x = x1196, xp_1 = x1196_p_0, xp_0 = 0;
							x < x1196 + 2;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10778 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10779 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10780 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10781 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10785 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10788 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10789 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_10794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_10797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_10798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_10801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_10802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_10803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_10804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_10805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c1072, cp_2 = c1072_p_1, cp_1 = c1072_p_0, cp_0 = 0;
										c < c1072 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10778);
										mem_vec_10778 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10779);
										mem_vec_10779 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10780);
										mem_vec_10780 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10781);
										mem_vec_10781 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10782);
										mem_vec_10782 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10783);
										mem_vec_10783 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10784);
										mem_vec_10784 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10785);
										mem_vec_10785 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10786);
										mem_vec_10786 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10787);
										mem_vec_10787 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10788);
										mem_vec_10788 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10789);
										mem_vec_10789 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10790);
										mem_vec_10790 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10791);
										mem_vec_10791 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10792);
										mem_vec_10792 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10793);
										mem_vec_10793 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10794);
										mem_vec_10794 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10795);
										mem_vec_10795 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10796);
										mem_vec_10796 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10797);
										mem_vec_10797 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10798);
										mem_vec_10798 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10799);
										mem_vec_10799 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_10800);
										mem_vec_10800 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_10801);
										mem_vec_10801 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_10802);
										mem_vec_10802 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_10803);
										mem_vec_10803 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_10804);
										mem_vec_10804 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_10805);
										mem_vec_10805 = vec_38;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_10778);
										mem_vec_10778 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_10779);
										mem_vec_10779 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_10780);
										mem_vec_10780 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_10781);
										mem_vec_10781 = vec_46;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_10782);
										mem_vec_10782 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_10783);
										mem_vec_10783 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_10784);
										mem_vec_10784 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_10785);
										mem_vec_10785 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_10786);
										mem_vec_10786 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_10787);
										mem_vec_10787 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_10788);
										mem_vec_10788 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_10789);
										mem_vec_10789 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_10790);
										mem_vec_10790 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_10791);
										mem_vec_10791 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_10792);
										mem_vec_10792 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_10793);
										mem_vec_10793 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_10794);
										mem_vec_10794 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_10795);
										mem_vec_10795 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_10796);
										mem_vec_10796 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_10797);
										mem_vec_10797 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_10798);
										mem_vec_10798 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_10799);
										mem_vec_10799 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_10800);
										mem_vec_10800 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_10801);
										mem_vec_10801 = vec_72;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_10802);
										mem_vec_10802 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_10803);
										mem_vec_10803 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_10804);
										mem_vec_10804 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_10805);
										mem_vec_10805 = vec_77;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_10778);
										mem_vec_10778 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_10779);
										mem_vec_10779 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_10780);
										mem_vec_10780 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_10781);
										mem_vec_10781 = vec_85;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_10782);
										mem_vec_10782 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_10783);
										mem_vec_10783 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_10784);
										mem_vec_10784 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_10785);
										mem_vec_10785 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_10786);
										mem_vec_10786 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_10787);
										mem_vec_10787 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_10788);
										mem_vec_10788 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_10789);
										mem_vec_10789 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_10790);
										mem_vec_10790 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_10791);
										mem_vec_10791 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_10792);
										mem_vec_10792 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_10793);
										mem_vec_10793 = vec_101;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_10794);
										mem_vec_10794 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_10795);
										mem_vec_10795 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_10796);
										mem_vec_10796 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_10797);
										mem_vec_10797 = vec_106;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_10798);
										mem_vec_10798 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_10799);
										mem_vec_10799 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_10800);
										mem_vec_10800 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_10801);
										mem_vec_10801 = vec_111;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_10802);
										mem_vec_10802 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_10803);
										mem_vec_10803 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_10804);
										mem_vec_10804 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_10805);
										mem_vec_10805 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10778);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10779);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10780);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10781);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10782);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10783);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10784);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10785);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10786);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10787);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10788);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10789);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10790);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10791);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10792);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10793);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10794);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10795);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10796);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10797);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10798);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10799);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_10800);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_10801);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10802);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10803);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_10804);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_10805);
						}
					}
				}
			}
		}
}


}