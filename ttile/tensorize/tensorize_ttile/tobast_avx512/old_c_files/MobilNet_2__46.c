#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (14, x);
  T (3, w); T (2, c); T (4, x);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (32, c)]
*/
IND_TYPE c, cp_0, c724_p_0, c725_p_0, cp_1, c724_p_1, cp_2, c724, c725, w, wp_0, x, xp_0, x816_p_0, xp_1, x816, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y440 = 0;
IND_TYPE x817 = 0;
IND_TYPE h = 0;
IND_TYPE w376 = 0;
IND_TYPE c726 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5690 ,mem_vec_5691 ,mem_vec_5692 ,mem_vec_5693 ,mem_vec_5694 ,mem_vec_5695 ,mem_vec_5696 ,mem_vec_5697 ,mem_vec_5698 ,mem_vec_5699 ,mem_vec_5700 ,mem_vec_5701 ,mem_vec_5702 ,mem_vec_5703 ,mem_vec_5704 ,mem_vec_5705 ,mem_vec_5706 ,mem_vec_5707 ,mem_vec_5708 ,mem_vec_5709 ,mem_vec_5710 ,mem_vec_5711 ,mem_vec_5712 ,mem_vec_5713 ,mem_vec_5714 ,mem_vec_5715 ,mem_vec_5716 ,mem_vec_5717 ,mem_vec_5718 ,mem_vec_5719 ,mem_vec_5720 ,mem_vec_5721 ,mem_vec_5722 ,mem_vec_5723 ,mem_vec_5724 ,mem_vec_5725 ,mem_vec_5726 ,mem_vec_5727 ,mem_vec_5728 ,mem_vec_5729 ,mem_vec_5730 ,mem_vec_5731 ,mem_vec_5732 ,mem_vec_5733 ,mem_vec_5734 ,mem_vec_5735 ,mem_vec_5736 ,mem_vec_5737 ,mem_vec_5738 ,mem_vec_5739 ,mem_vec_5740 ,mem_vec_5741 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 32) (64 / 2)
for (c725 = c726, c725_p_0 = 0;
	c725 < c726 + 64;
	c725 += 2, c725_p_0 += 2){
		for (y = y440, yp_0 = 0;
			y < y440 + 42;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 56, h = 3, w = 3, c = 2, f = 64
			// T (x, 4) (56 / 14)
			for (x816 = x817, x816_p_0 = 0;
				x816 < x817 + 56;
				x816 += 14, x816_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 64
				// T (c, 2) (2 / 1)
				for (c724 = c725, c724_p_1 = c725_p_0, c724_p_0 = 0;
					c724 < c725 + 2;
					c724 += 1, c724_p_1 += 1, c724_p_0 += 1){
					// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 64
					// T (w, 3) (3 / 1)
					for (w = w376, wp_0 = 0;
						w < w376 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 14, h = 3, w = 1, c = 1, f = 64
						// T (x, 14) (14 / 1)
						for (x = x816, xp_1 = x816_p_0, xp_0 = 0;
							x < x816 + 14;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_5690 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5691 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_5692 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_5693 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_5694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_5696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_5697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_5698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_5700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_5701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_5702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_5703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_5704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_5705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_5706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_5707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_5708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_5709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_5710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_5711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_5712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_5713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c724, cp_2 = c724_p_1, cp_1 = c724_p_0, cp_0 = 0;
										c < c724 + 1;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5690);
										mem_vec_5690 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5691);
										mem_vec_5691 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5692);
										mem_vec_5692 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5693);
										mem_vec_5693 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5694);
										mem_vec_5694 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5695);
										mem_vec_5695 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5696);
										mem_vec_5696 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5697);
										mem_vec_5697 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5698);
										mem_vec_5698 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5699);
										mem_vec_5699 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5700);
										mem_vec_5700 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5701);
										mem_vec_5701 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5702);
										mem_vec_5702 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5703);
										mem_vec_5703 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5704);
										mem_vec_5704 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5705);
										mem_vec_5705 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5706);
										mem_vec_5706 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5707);
										mem_vec_5707 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5708);
										mem_vec_5708 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5709);
										mem_vec_5709 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5710);
										mem_vec_5710 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5711);
										mem_vec_5711 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5712);
										mem_vec_5712 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5713);
										mem_vec_5713 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_5690);
										mem_vec_5690 = vec_34;

										vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_5691);
										mem_vec_5691 = vec_37;

										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_5692);
										mem_vec_5692 = vec_39;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_5693);
										mem_vec_5693 = vec_41;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_5694);
										mem_vec_5694 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_5695);
										mem_vec_5695 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_5696);
										mem_vec_5696 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_5697);
										mem_vec_5697 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_5698);
										mem_vec_5698 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_5699);
										mem_vec_5699 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_5700);
										mem_vec_5700 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_5701);
										mem_vec_5701 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_5702);
										mem_vec_5702 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_5703);
										mem_vec_5703 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_5704);
										mem_vec_5704 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_5705);
										mem_vec_5705 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_5706);
										mem_vec_5706 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_5707);
										mem_vec_5707 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_5708);
										mem_vec_5708 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_5709);
										mem_vec_5709 = vec_62;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_5710);
										mem_vec_5710 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_5711);
										mem_vec_5711 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_5712);
										mem_vec_5712 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_5713);
										mem_vec_5713 = vec_67;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_69 = _mm512_set1_ps(scal_12);
										vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_5690);
										mem_vec_5690 = vec_68;

										vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_5691);
										mem_vec_5691 = vec_71;

										vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_5692);
										mem_vec_5692 = vec_73;

										vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_5693);
										mem_vec_5693 = vec_75;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_78 = _mm512_set1_ps(scal_13);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_5694);
										mem_vec_5694 = vec_77;



										vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_5695);
										mem_vec_5695 = vec_79;



										vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_5696);
										mem_vec_5696 = vec_80;



										vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_5697);
										mem_vec_5697 = vec_81;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_83 = _mm512_set1_ps(scal_14);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_5698);
										mem_vec_5698 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_5699);
										mem_vec_5699 = vec_84;



										vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_5700);
										mem_vec_5700 = vec_85;



										vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_5701);
										mem_vec_5701 = vec_86;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_5702);
										mem_vec_5702 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_5703);
										mem_vec_5703 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_5704);
										mem_vec_5704 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_5705);
										mem_vec_5705 = vec_91;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_5706);
										mem_vec_5706 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_5707);
										mem_vec_5707 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_5708);
										mem_vec_5708 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_5709);
										mem_vec_5709 = vec_96;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_5710);
										mem_vec_5710 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_5711);
										mem_vec_5711 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_5712);
										mem_vec_5712 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_5713);
										mem_vec_5713 = vec_101;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5690);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5691);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5692);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5693);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5694);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5695);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5696);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5697);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5698);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5699);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5700);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5701);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5702);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5703);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5704);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5705);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5706);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5707);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5708);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5709);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5710);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5711);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_5712);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_5713);
						}
					}
				}
			}
		}
		for (y = y440 + 42, yp_0 = 0;
			y < y440 + 42 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 2, f = 64
			// T (x, 4) (56 / 14)
			for (x816 = x817, x816_p_0 = 0;
				x816 < x817 + 56;
				x816 += 14, x816_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 64
				// T (c, 2) (2 / 1)
				for (c724 = c725, c724_p_1 = c725_p_0, c724_p_0 = 0;
					c724 < c725 + 2;
					c724 += 1, c724_p_1 += 1, c724_p_0 += 1){
					// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 64
					// T (w, 3) (3 / 1)
					for (w = w376, wp_0 = 0;
						w < w376 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 14, h = 3, w = 1, c = 1, f = 64
						// T (x, 14) (14 / 1)
						for (x = x816, xp_1 = x816_p_0, xp_0 = 0;
							x < x816 + 14;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_5714 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5715 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_5716 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_5717 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_5718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_5720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_5721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_5722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_5724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_5725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_5726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_5727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_5728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_5729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_5730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_5731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_5732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_5733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_5734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_5735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_5736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_5737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_5738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_5739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_5740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_5741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c724, cp_2 = c724_p_1, cp_1 = c724_p_0, cp_0 = 0;
										c < c724 + 1;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5714);
										mem_vec_5714 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5715);
										mem_vec_5715 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5716);
										mem_vec_5716 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5717);
										mem_vec_5717 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5718);
										mem_vec_5718 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5719);
										mem_vec_5719 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5720);
										mem_vec_5720 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5721);
										mem_vec_5721 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5722);
										mem_vec_5722 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5723);
										mem_vec_5723 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5724);
										mem_vec_5724 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5725);
										mem_vec_5725 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5726);
										mem_vec_5726 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5727);
										mem_vec_5727 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5728);
										mem_vec_5728 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5729);
										mem_vec_5729 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5730);
										mem_vec_5730 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5731);
										mem_vec_5731 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5732);
										mem_vec_5732 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5733);
										mem_vec_5733 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5734);
										mem_vec_5734 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5735);
										mem_vec_5735 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5736);
										mem_vec_5736 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5737);
										mem_vec_5737 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_5738);
										mem_vec_5738 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_5739);
										mem_vec_5739 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_5740);
										mem_vec_5740 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_5741);
										mem_vec_5741 = vec_38;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_5714);
										mem_vec_5714 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_5715);
										mem_vec_5715 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_5716);
										mem_vec_5716 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_5717);
										mem_vec_5717 = vec_46;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_5718);
										mem_vec_5718 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_5719);
										mem_vec_5719 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_5720);
										mem_vec_5720 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_5721);
										mem_vec_5721 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_5722);
										mem_vec_5722 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_5723);
										mem_vec_5723 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_5724);
										mem_vec_5724 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_5725);
										mem_vec_5725 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_5726);
										mem_vec_5726 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_5727);
										mem_vec_5727 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_5728);
										mem_vec_5728 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_5729);
										mem_vec_5729 = vec_62;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_5730);
										mem_vec_5730 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_5731);
										mem_vec_5731 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_5732);
										mem_vec_5732 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_5733);
										mem_vec_5733 = vec_67;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_5734);
										mem_vec_5734 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_5735);
										mem_vec_5735 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_5736);
										mem_vec_5736 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_5737);
										mem_vec_5737 = vec_72;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_5738);
										mem_vec_5738 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_5739);
										mem_vec_5739 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_5740);
										mem_vec_5740 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_5741);
										mem_vec_5741 = vec_77;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_5714);
										mem_vec_5714 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_5715);
										mem_vec_5715 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_5716);
										mem_vec_5716 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_5717);
										mem_vec_5717 = vec_85;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_5718);
										mem_vec_5718 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_5719);
										mem_vec_5719 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_5720);
										mem_vec_5720 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_5721);
										mem_vec_5721 = vec_91;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_5722);
										mem_vec_5722 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_5723);
										mem_vec_5723 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_5724);
										mem_vec_5724 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_5725);
										mem_vec_5725 = vec_96;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_5726);
										mem_vec_5726 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_5727);
										mem_vec_5727 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_5728);
										mem_vec_5728 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_5729);
										mem_vec_5729 = vec_101;
										scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_5730);
										mem_vec_5730 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_5731);
										mem_vec_5731 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_5732);
										mem_vec_5732 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_5733);
										mem_vec_5733 = vec_106;
										scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_5734);
										mem_vec_5734 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_5735);
										mem_vec_5735 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_5736);
										mem_vec_5736 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_5737);
										mem_vec_5737 = vec_111;
										scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_5738);
										mem_vec_5738 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_5739);
										mem_vec_5739 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_5740);
										mem_vec_5740 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_5741);
										mem_vec_5741 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5714);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5715);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5716);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5717);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5718);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5719);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5720);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5721);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5722);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5723);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5724);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5725);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5726);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5727);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5728);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5729);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5730);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5731);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5732);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5733);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5734);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5735);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_5736);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_5737);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5738);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5739);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_5740);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_5741);
						}
					}
				}
			}
		}
}


}