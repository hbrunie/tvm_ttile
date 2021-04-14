#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (16, c); T (28, x);
  Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))]; T (1, c)]
*/
IND_TYPE c, cp_0, c1304_p_0, c1305_p_0, cp_1, c1304_p_1, cp_2, c1304, c1305, h, hp_0, x, xp_0, x1412_p_0, xp_1, x1412, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y776 = 0;
IND_TYPE x1413 = 0;
IND_TYPE h600 = 0;
IND_TYPE w = 0;
IND_TYPE c1306 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_13708 ,mem_vec_13709 ,mem_vec_13710 ,mem_vec_13711 ,mem_vec_13712 ,mem_vec_13713 ,mem_vec_13714 ,mem_vec_13715 ,mem_vec_13716 ,mem_vec_13717 ,mem_vec_13718 ,mem_vec_13719 ,mem_vec_13720 ,mem_vec_13721 ,mem_vec_13722 ,mem_vec_13723 ,mem_vec_13724 ,mem_vec_13725 ,mem_vec_13726 ,mem_vec_13727 ,mem_vec_13728 ,mem_vec_13729 ,mem_vec_13730 ,mem_vec_13731 ,mem_vec_13732 ,mem_vec_13733 ,mem_vec_13734 ,mem_vec_13735 ,mem_vec_13736 ,mem_vec_13737 ,mem_vec_13738 ,mem_vec_13739 ,mem_vec_13740 ,mem_vec_13741 ,mem_vec_13742 ,mem_vec_13743 ,mem_vec_13744 ,mem_vec_13745 ,mem_vec_13746 ,mem_vec_13747 ,mem_vec_13748 ,mem_vec_13749 ,mem_vec_13750 ,mem_vec_13751 ,mem_vec_13752 ,mem_vec_13753 ,mem_vec_13754 ,mem_vec_13755 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 1) (64 / 64)
for (c1305 = c1306, c1305_p_0 = 0;
	c1305 < c1306 + 64;
	c1305 += 64, c1305_p_0 += 64){
		for (y = y776, yp_0 = 0;
			y < y776 + 35;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 28) (56 / 2)
			for (x1412 = x1413, x1412_p_0 = 0;
				x1412 < x1413 + 56;
				x1412 += 2, x1412_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 64
				// T (c, 16) (64 / 4)
				for (c1304 = c1305, c1304_p_1 = c1305_p_0, c1304_p_0 = 0;
					c1304 < c1305 + 64;
					c1304 += 4, c1304_p_1 += 4, c1304_p_0 += 4){
					// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 64
					// T (h, 3) (3 / 1)
					for (h = h600, hp_0 = 0;
						h < h600 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 2, h = 1, w = 3, c = 4, f = 64
						// T (x, 2) (2 / 1)
						for (x = x1412, xp_1 = x1412_p_0, xp_0 = 0;
							x < x1412 + 2;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_13708 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_13709 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_13710 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_13711 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_13712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_13713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_13714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_13715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_13716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_13717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_13718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_13719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_13720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_13721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_13722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_13723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_13724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_13725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_13726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_13727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c1304, cp_2 = c1304_p_1, cp_1 = c1304_p_0, cp_0 = 0;
										c < c1304 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13708);
										mem_vec_13708 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13709);
										mem_vec_13709 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13710);
										mem_vec_13710 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13711);
										mem_vec_13711 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13712);
										mem_vec_13712 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13713);
										mem_vec_13713 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13714);
										mem_vec_13714 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13715);
										mem_vec_13715 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13716);
										mem_vec_13716 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13717);
										mem_vec_13717 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13718);
										mem_vec_13718 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13719);
										mem_vec_13719 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13720);
										mem_vec_13720 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13721);
										mem_vec_13721 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13722);
										mem_vec_13722 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13723);
										mem_vec_13723 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_13724);
										mem_vec_13724 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_13725);
										mem_vec_13725 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_13726);
										mem_vec_13726 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_13727);
										mem_vec_13727 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_13708);
										mem_vec_13708 = vec_29;

										vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_13709);
										mem_vec_13709 = vec_32;

										vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_13710);
										mem_vec_13710 = vec_34;

										vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_13711);
										mem_vec_13711 = vec_36;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_39 = _mm512_set1_ps(scal_6);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_13712);
										mem_vec_13712 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_13713);
										mem_vec_13713 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_13714);
										mem_vec_13714 = vec_41;



										vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_13715);
										mem_vec_13715 = vec_42;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_13716);
										mem_vec_13716 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_13717);
										mem_vec_13717 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_13718);
										mem_vec_13718 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_13719);
										mem_vec_13719 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_13720);
										mem_vec_13720 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_13721);
										mem_vec_13721 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_13722);
										mem_vec_13722 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_13723);
										mem_vec_13723 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_13724);
										mem_vec_13724 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_13725);
										mem_vec_13725 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_13726);
										mem_vec_13726 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_13727);
										mem_vec_13727 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_59 = _mm512_set1_ps(scal_10);
										vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_13708);
										mem_vec_13708 = vec_58;

										vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_13709);
										mem_vec_13709 = vec_61;

										vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_13710);
										mem_vec_13710 = vec_63;

										vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_13711);
										mem_vec_13711 = vec_65;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_68 = _mm512_set1_ps(scal_11);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_13712);
										mem_vec_13712 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_13713);
										mem_vec_13713 = vec_69;



										vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_13714);
										mem_vec_13714 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_13715);
										mem_vec_13715 = vec_71;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_73 = _mm512_set1_ps(scal_12);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_13716);
										mem_vec_13716 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_13717);
										mem_vec_13717 = vec_74;



										vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_13718);
										mem_vec_13718 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_13719);
										mem_vec_13719 = vec_76;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_78 = _mm512_set1_ps(scal_13);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_13720);
										mem_vec_13720 = vec_77;



										vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_13721);
										mem_vec_13721 = vec_79;



										vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_13722);
										mem_vec_13722 = vec_80;



										vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_13723);
										mem_vec_13723 = vec_81;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
										vec_83 = _mm512_set1_ps(scal_14);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_13724);
										mem_vec_13724 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_13725);
										mem_vec_13725 = vec_84;



										vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_13726);
										mem_vec_13726 = vec_85;



										vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_13727);
										mem_vec_13727 = vec_86;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13708);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13709);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13710);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13711);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13712);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13713);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13714);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13715);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13716);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13717);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13718);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13719);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13720);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13721);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_13722);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_13723);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13724);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13725);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_13726);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_13727);
						}
					}
				}
			}
		}
		for (y = y776 + 35, yp_0 = 0;
			y < y776 + 35 + 21;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 28) (56 / 2)
			for (x1412 = x1413, x1412_p_0 = 0;
				x1412 < x1413 + 56;
				x1412 += 2, x1412_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 64
				// T (c, 16) (64 / 4)
				for (c1304 = c1305, c1304_p_1 = c1305_p_0, c1304_p_0 = 0;
					c1304 < c1305 + 64;
					c1304 += 4, c1304_p_1 += 4, c1304_p_0 += 4){
					// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 64
					// T (h, 3) (3 / 1)
					for (h = h600, hp_0 = 0;
						h < h600 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 2, h = 1, w = 3, c = 4, f = 64
						// T (x, 2) (2 / 1)
						for (x = x1412, xp_1 = x1412_p_0, xp_0 = 0;
							x < x1412 + 2;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_13728 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_13729 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_13730 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_13731 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_13732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_13733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_13734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_13735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_13736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_13737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_13738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_13739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_13740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_13741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_13742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_13743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_13744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_13745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_13746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_13747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_13748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_13749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_13750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_13751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_13752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_13753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_13754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_13755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c1304, cp_2 = c1304_p_1, cp_1 = c1304_p_0, cp_0 = 0;
										c < c1304 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13728);
										mem_vec_13728 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13729);
										mem_vec_13729 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13730);
										mem_vec_13730 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13731);
										mem_vec_13731 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13732);
										mem_vec_13732 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13733);
										mem_vec_13733 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13734);
										mem_vec_13734 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13735);
										mem_vec_13735 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13736);
										mem_vec_13736 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13737);
										mem_vec_13737 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13738);
										mem_vec_13738 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13739);
										mem_vec_13739 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13740);
										mem_vec_13740 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13741);
										mem_vec_13741 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13742);
										mem_vec_13742 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13743);
										mem_vec_13743 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_13744);
										mem_vec_13744 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_13745);
										mem_vec_13745 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_13746);
										mem_vec_13746 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_13747);
										mem_vec_13747 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13748);
										mem_vec_13748 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13749);
										mem_vec_13749 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_13750);
										mem_vec_13750 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_13751);
										mem_vec_13751 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_13752);
										mem_vec_13752 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_13753);
										mem_vec_13753 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_13754);
										mem_vec_13754 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_13755);
										mem_vec_13755 = vec_38;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_13728);
										mem_vec_13728 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_13729);
										mem_vec_13729 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_13730);
										mem_vec_13730 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_13731);
										mem_vec_13731 = vec_46;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_13732);
										mem_vec_13732 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_13733);
										mem_vec_13733 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_13734);
										mem_vec_13734 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_13735);
										mem_vec_13735 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_13736);
										mem_vec_13736 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_13737);
										mem_vec_13737 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_13738);
										mem_vec_13738 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_13739);
										mem_vec_13739 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_13740);
										mem_vec_13740 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_13741);
										mem_vec_13741 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_13742);
										mem_vec_13742 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_13743);
										mem_vec_13743 = vec_62;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_13744);
										mem_vec_13744 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_13745);
										mem_vec_13745 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_13746);
										mem_vec_13746 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_13747);
										mem_vec_13747 = vec_67;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_13748);
										mem_vec_13748 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_13749);
										mem_vec_13749 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_13750);
										mem_vec_13750 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_13751);
										mem_vec_13751 = vec_72;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_13752);
										mem_vec_13752 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_13753);
										mem_vec_13753 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_13754);
										mem_vec_13754 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_13755);
										mem_vec_13755 = vec_77;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_13728);
										mem_vec_13728 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_13729);
										mem_vec_13729 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_13730);
										mem_vec_13730 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_13731);
										mem_vec_13731 = vec_85;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_13732);
										mem_vec_13732 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_13733);
										mem_vec_13733 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_13734);
										mem_vec_13734 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_13735);
										mem_vec_13735 = vec_91;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_13736);
										mem_vec_13736 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_13737);
										mem_vec_13737 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_13738);
										mem_vec_13738 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_13739);
										mem_vec_13739 = vec_96;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_13740);
										mem_vec_13740 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_13741);
										mem_vec_13741 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_13742);
										mem_vec_13742 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_13743);
										mem_vec_13743 = vec_101;
										scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_13744);
										mem_vec_13744 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_13745);
										mem_vec_13745 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_13746);
										mem_vec_13746 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_13747);
										mem_vec_13747 = vec_106;
										scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_13748);
										mem_vec_13748 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_13749);
										mem_vec_13749 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_13750);
										mem_vec_13750 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_13751);
										mem_vec_13751 = vec_111;
										scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_13752);
										mem_vec_13752 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_13753);
										mem_vec_13753 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_13754);
										mem_vec_13754 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_13755);
										mem_vec_13755 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13728);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13729);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13730);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13731);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13732);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13733);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13734);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13735);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13736);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13737);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13738);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13739);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13740);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13741);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_13742);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_13743);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13744);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13745);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_13746);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_13747);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13748);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13749);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_13750);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_13751);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13752);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13753);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_13754);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_13755);
						}
					}
				}
			}
		}
}


}