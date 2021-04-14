#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (1, c); T (28, x);
  Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))]; T (2, c)]
*/
IND_TYPE c, cp_0, c1064_p_0, c1065_p_0, cp_1, c1064_p_1, cp_2, c1064, c1065, w, wp_0, x, xp_0, x1190_p_0, xp_1, x1190, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y644 = 0;
IND_TYPE x1191 = 0;
IND_TYPE h = 0;
IND_TYPE w610 = 0;
IND_TYPE c1066 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10662 ,mem_vec_10663 ,mem_vec_10664 ,mem_vec_10665 ,mem_vec_10666 ,mem_vec_10667 ,mem_vec_10668 ,mem_vec_10669 ,mem_vec_10670 ,mem_vec_10671 ,mem_vec_10672 ,mem_vec_10673 ,mem_vec_10674 ,mem_vec_10675 ,mem_vec_10676 ,mem_vec_10677 ,mem_vec_10678 ,mem_vec_10679 ,mem_vec_10680 ,mem_vec_10681 ,mem_vec_10682 ,mem_vec_10683 ,mem_vec_10684 ,mem_vec_10685 ,mem_vec_10686 ,mem_vec_10687 ,mem_vec_10688 ,mem_vec_10689 ,mem_vec_10690 ,mem_vec_10691 ,mem_vec_10692 ,mem_vec_10693 ,mem_vec_10694 ,mem_vec_10695 ,mem_vec_10696 ,mem_vec_10697 ,mem_vec_10698 ,mem_vec_10699 ,mem_vec_10700 ,mem_vec_10701 ,mem_vec_10702 ,mem_vec_10703 ,mem_vec_10704 ,mem_vec_10705 ,mem_vec_10706 ,mem_vec_10707 ,mem_vec_10708 ,mem_vec_10709 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 2) (64 / 32)
for (c1065 = c1066, c1065_p_0 = 0;
	c1065 < c1066 + 64;
	c1065 += 32, c1065_p_0 += 32){
		for (y = y644, yp_0 = 0;
			y < y644 + 35;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 64
			// T (x, 28) (56 / 2)
			for (x1190 = x1191, x1190_p_0 = 0;
				x1190 < x1191 + 56;
				x1190 += 2, x1190_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 64
				// T (c, 1) (32 / 32)
				for (c1064 = c1065, c1064_p_1 = c1065_p_0, c1064_p_0 = 0;
					c1064 < c1065 + 32;
					c1064 += 32, c1064_p_1 += 32, c1064_p_0 += 32){
					// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 64
					// T (w, 3) (3 / 1)
					for (w = w610, wp_0 = 0;
						w < w610 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 2, h = 3, w = 1, c = 32, f = 64
						// T (x, 2) (2 / 1)
						for (x = x1190, xp_1 = x1190_p_0, xp_0 = 0;
							x < x1190 + 2;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10662 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10663 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10664 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10665 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_10678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_10681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c1064, cp_2 = c1064_p_1, cp_1 = c1064_p_0, cp_0 = 0;
										c < c1064 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10662);
										mem_vec_10662 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10663);
										mem_vec_10663 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10664);
										mem_vec_10664 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10665);
										mem_vec_10665 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10666);
										mem_vec_10666 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10667);
										mem_vec_10667 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10668);
										mem_vec_10668 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10669);
										mem_vec_10669 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10670);
										mem_vec_10670 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10671);
										mem_vec_10671 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10672);
										mem_vec_10672 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10673);
										mem_vec_10673 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10674);
										mem_vec_10674 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10675);
										mem_vec_10675 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10676);
										mem_vec_10676 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10677);
										mem_vec_10677 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10678);
										mem_vec_10678 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10679);
										mem_vec_10679 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10680);
										mem_vec_10680 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10681);
										mem_vec_10681 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_10662);
										mem_vec_10662 = vec_29;

										vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_10663);
										mem_vec_10663 = vec_32;

										vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_10664);
										mem_vec_10664 = vec_34;

										vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_10665);
										mem_vec_10665 = vec_36;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_6);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_10666);
										mem_vec_10666 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_10667);
										mem_vec_10667 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_10668);
										mem_vec_10668 = vec_41;



										vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_10669);
										mem_vec_10669 = vec_42;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_10670);
										mem_vec_10670 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_10671);
										mem_vec_10671 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_10672);
										mem_vec_10672 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_10673);
										mem_vec_10673 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_10674);
										mem_vec_10674 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_10675);
										mem_vec_10675 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_10676);
										mem_vec_10676 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_10677);
										mem_vec_10677 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_10678);
										mem_vec_10678 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_10679);
										mem_vec_10679 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_10680);
										mem_vec_10680 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_10681);
										mem_vec_10681 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_59 = _mm512_set1_ps(scal_10);
										vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_10662);
										mem_vec_10662 = vec_58;

										vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_10663);
										mem_vec_10663 = vec_61;

										vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_10664);
										mem_vec_10664 = vec_63;

										vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_10665);
										mem_vec_10665 = vec_65;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_68 = _mm512_set1_ps(scal_11);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_10666);
										mem_vec_10666 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_10667);
										mem_vec_10667 = vec_69;



										vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_10668);
										mem_vec_10668 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_10669);
										mem_vec_10669 = vec_71;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_73 = _mm512_set1_ps(scal_12);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_10670);
										mem_vec_10670 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_10671);
										mem_vec_10671 = vec_74;



										vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_10672);
										mem_vec_10672 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_10673);
										mem_vec_10673 = vec_76;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_78 = _mm512_set1_ps(scal_13);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_10674);
										mem_vec_10674 = vec_77;



										vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_10675);
										mem_vec_10675 = vec_79;



										vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_10676);
										mem_vec_10676 = vec_80;



										vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_10677);
										mem_vec_10677 = vec_81;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_83 = _mm512_set1_ps(scal_14);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_10678);
										mem_vec_10678 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_10679);
										mem_vec_10679 = vec_84;



										vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_10680);
										mem_vec_10680 = vec_85;



										vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_10681);
										mem_vec_10681 = vec_86;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10662);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10663);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10664);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10665);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10666);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10667);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10668);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10669);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10670);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10671);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10672);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10673);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10674);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10675);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10676);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10677);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10678);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10679);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10680);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10681);
						}
					}
				}
			}
		}
		for (y = y644 + 35, yp_0 = 0;
			y < y644 + 35 + 21;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 64
			// T (x, 28) (56 / 2)
			for (x1190 = x1191, x1190_p_0 = 0;
				x1190 < x1191 + 56;
				x1190 += 2, x1190_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 64
				// T (c, 1) (32 / 32)
				for (c1064 = c1065, c1064_p_1 = c1065_p_0, c1064_p_0 = 0;
					c1064 < c1065 + 32;
					c1064 += 32, c1064_p_1 += 32, c1064_p_0 += 32){
					// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 64
					// T (w, 3) (3 / 1)
					for (w = w610, wp_0 = 0;
						w < w610 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 2, h = 3, w = 1, c = 32, f = 64
						// T (x, 2) (2 / 1)
						for (x = x1190, xp_1 = x1190_p_0, xp_0 = 0;
							x < x1190 + 2;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10682 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10683 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10684 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10685 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_10698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_10701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_10702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_10705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_10706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_10707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_10708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_10709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c1064, cp_2 = c1064_p_1, cp_1 = c1064_p_0, cp_0 = 0;
										c < c1064 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10682);
										mem_vec_10682 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10683);
										mem_vec_10683 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10684);
										mem_vec_10684 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10685);
										mem_vec_10685 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10686);
										mem_vec_10686 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10687);
										mem_vec_10687 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10688);
										mem_vec_10688 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10689);
										mem_vec_10689 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10690);
										mem_vec_10690 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10691);
										mem_vec_10691 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10692);
										mem_vec_10692 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10693);
										mem_vec_10693 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10694);
										mem_vec_10694 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10695);
										mem_vec_10695 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10696);
										mem_vec_10696 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10697);
										mem_vec_10697 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10698);
										mem_vec_10698 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10699);
										mem_vec_10699 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10700);
										mem_vec_10700 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10701);
										mem_vec_10701 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10702);
										mem_vec_10702 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10703);
										mem_vec_10703 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_10704);
										mem_vec_10704 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_10705);
										mem_vec_10705 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_10706);
										mem_vec_10706 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_10707);
										mem_vec_10707 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_10708);
										mem_vec_10708 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_10709);
										mem_vec_10709 = vec_38;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_10682);
										mem_vec_10682 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_10683);
										mem_vec_10683 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_10684);
										mem_vec_10684 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_10685);
										mem_vec_10685 = vec_46;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_10686);
										mem_vec_10686 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_10687);
										mem_vec_10687 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_10688);
										mem_vec_10688 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_10689);
										mem_vec_10689 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_10690);
										mem_vec_10690 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_10691);
										mem_vec_10691 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_10692);
										mem_vec_10692 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_10693);
										mem_vec_10693 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_10694);
										mem_vec_10694 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_10695);
										mem_vec_10695 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_10696);
										mem_vec_10696 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_10697);
										mem_vec_10697 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_10698);
										mem_vec_10698 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_10699);
										mem_vec_10699 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_10700);
										mem_vec_10700 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_10701);
										mem_vec_10701 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_10702);
										mem_vec_10702 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_10703);
										mem_vec_10703 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_10704);
										mem_vec_10704 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_10705);
										mem_vec_10705 = vec_72;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_10706);
										mem_vec_10706 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_10707);
										mem_vec_10707 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_10708);
										mem_vec_10708 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_10709);
										mem_vec_10709 = vec_77;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_10682);
										mem_vec_10682 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_10683);
										mem_vec_10683 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_10684);
										mem_vec_10684 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_10685);
										mem_vec_10685 = vec_85;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_10686);
										mem_vec_10686 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_10687);
										mem_vec_10687 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_10688);
										mem_vec_10688 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_10689);
										mem_vec_10689 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_10690);
										mem_vec_10690 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_10691);
										mem_vec_10691 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_10692);
										mem_vec_10692 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_10693);
										mem_vec_10693 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_10694);
										mem_vec_10694 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_10695);
										mem_vec_10695 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_10696);
										mem_vec_10696 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_10697);
										mem_vec_10697 = vec_101;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_10698);
										mem_vec_10698 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_10699);
										mem_vec_10699 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_10700);
										mem_vec_10700 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_10701);
										mem_vec_10701 = vec_106;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_10702);
										mem_vec_10702 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_10703);
										mem_vec_10703 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_10704);
										mem_vec_10704 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_10705);
										mem_vec_10705 = vec_111;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_10706);
										mem_vec_10706 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_10707);
										mem_vec_10707 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_10708);
										mem_vec_10708 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_10709);
										mem_vec_10709 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10682);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10683);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10684);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10685);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10686);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10687);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10688);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10689);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10690);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10691);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10692);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10693);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10694);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10695);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10696);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10697);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10698);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10699);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10700);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10701);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10702);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10703);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_10704);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_10705);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10706);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10707);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_10708);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_10709);
						}
					}
				}
			}
		}
}


}