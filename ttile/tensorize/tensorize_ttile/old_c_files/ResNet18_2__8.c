#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, c); T (56, x);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (8, c)]
*/
IND_TYPE c, cp_0, c1168_p_0, c1169_p_0, cp_1, c1168_p_1, cp_2, c1168, c1169, w, wp_0, x, xp_0, x1268_p_0, xp_1, x1268, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y696 = 0;
IND_TYPE x1269 = 0;
IND_TYPE h = 0;
IND_TYPE w662 = 0;
IND_TYPE c1170 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11990 ,mem_vec_11991 ,mem_vec_11992 ,mem_vec_11993 ,mem_vec_11994 ,mem_vec_11995 ,mem_vec_11996 ,mem_vec_11997 ,mem_vec_11998 ,mem_vec_11999 ,mem_vec_12000 ,mem_vec_12001 ,mem_vec_12002 ,mem_vec_12003 ,mem_vec_12004 ,mem_vec_12005 ,mem_vec_12006 ,mem_vec_12007 ,mem_vec_12008 ,mem_vec_12009 ,mem_vec_12010 ,mem_vec_12011 ,mem_vec_12012 ,mem_vec_12013 ,mem_vec_12014 ,mem_vec_12015 ,mem_vec_12016 ,mem_vec_12017 ,mem_vec_12018 ,mem_vec_12019 ,mem_vec_12020 ,mem_vec_12021 ,mem_vec_12022 ,mem_vec_12023 ,mem_vec_12024 ,mem_vec_12025 ,mem_vec_12026 ,mem_vec_12027 ,mem_vec_12028 ,mem_vec_12029 ,mem_vec_12030 ,mem_vec_12031 ,mem_vec_12032 ,mem_vec_12033 ,mem_vec_12034 ,mem_vec_12035 ,mem_vec_12036 ,mem_vec_12037 ,mem_vec_12038 ,mem_vec_12039 ,mem_vec_12040 ,mem_vec_12041 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 8) (64 / 8)
for (c1169 = c1170, c1169_p_0 = 0;
	c1169 < c1170 + 64;
	c1169 += 8, c1169_p_0 += 8){
		for (y = y696, yp_0 = 0;
			y < y696 + 42;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 56, h = 3, w = 3, c = 8, f = 64
			// T (x, 56) (56 / 1)
			for (x1268 = x1269, x1268_p_0 = 0;
				x1268 < x1269 + 56;
				x1268 += 1, x1268_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 64
				// T (c, 2) (8 / 4)
				for (c1168 = c1169, c1168_p_1 = c1169_p_0, c1168_p_0 = 0;
					c1168 < c1169 + 8;
					c1168 += 4, c1168_p_1 += 4, c1168_p_0 += 4){
					// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
					// T (w, 3) (3 / 1)
					for (w = w662, wp_0 = 0;
						w < w662 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1268, xp_1 = x1268_p_0, xp_0 = 0;
							x < x1268 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_11990 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_11991 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_11992 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_11993 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_11994 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_11995 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_11996 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_11997 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_11998 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_11999 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_12000 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_12001 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_12002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_12003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_12004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_12005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_12006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_12007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_12008 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_12009 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_12010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_12011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_12012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_12013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c1168, cp_2 = c1168_p_1, cp_1 = c1168_p_0, cp_0 = 0;
										c < c1168 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11990);
										mem_vec_11990 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11991);
										mem_vec_11991 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11992);
										mem_vec_11992 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11993);
										mem_vec_11993 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11994);
										mem_vec_11994 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11995);
										mem_vec_11995 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11996);
										mem_vec_11996 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11997);
										mem_vec_11997 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11998);
										mem_vec_11998 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11999);
										mem_vec_11999 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_12000);
										mem_vec_12000 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_12001);
										mem_vec_12001 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_12002);
										mem_vec_12002 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_12003);
										mem_vec_12003 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_12004);
										mem_vec_12004 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_12005);
										mem_vec_12005 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_12006);
										mem_vec_12006 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_12007);
										mem_vec_12007 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_12008);
										mem_vec_12008 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_12009);
										mem_vec_12009 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_12010);
										mem_vec_12010 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_12011);
										mem_vec_12011 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_12012);
										mem_vec_12012 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_12013);
										mem_vec_12013 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_11990);
										mem_vec_11990 = vec_34;

										vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_11991);
										mem_vec_11991 = vec_37;

										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_11992);
										mem_vec_11992 = vec_39;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_11993);
										mem_vec_11993 = vec_41;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_11994);
										mem_vec_11994 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_11995);
										mem_vec_11995 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_11996);
										mem_vec_11996 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_11997);
										mem_vec_11997 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_11998);
										mem_vec_11998 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_11999);
										mem_vec_11999 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_12000);
										mem_vec_12000 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_12001);
										mem_vec_12001 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_12002);
										mem_vec_12002 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_12003);
										mem_vec_12003 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_12004);
										mem_vec_12004 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_12005);
										mem_vec_12005 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_12006);
										mem_vec_12006 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_12007);
										mem_vec_12007 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_12008);
										mem_vec_12008 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_12009);
										mem_vec_12009 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_12010);
										mem_vec_12010 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_12011);
										mem_vec_12011 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_12012);
										mem_vec_12012 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_12013);
										mem_vec_12013 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_69 = _mm512_set1_ps(scal_12);
										vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_11990);
										mem_vec_11990 = vec_68;

										vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_11991);
										mem_vec_11991 = vec_71;

										vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_11992);
										mem_vec_11992 = vec_73;

										vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_11993);
										mem_vec_11993 = vec_75;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_78 = _mm512_set1_ps(scal_13);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_11994);
										mem_vec_11994 = vec_77;



										vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_11995);
										mem_vec_11995 = vec_79;



										vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_11996);
										mem_vec_11996 = vec_80;



										vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_11997);
										mem_vec_11997 = vec_81;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_83 = _mm512_set1_ps(scal_14);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_11998);
										mem_vec_11998 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_11999);
										mem_vec_11999 = vec_84;



										vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_12000);
										mem_vec_12000 = vec_85;



										vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_12001);
										mem_vec_12001 = vec_86;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_12002);
										mem_vec_12002 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_12003);
										mem_vec_12003 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_12004);
										mem_vec_12004 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_12005);
										mem_vec_12005 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_12006);
										mem_vec_12006 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_12007);
										mem_vec_12007 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_12008);
										mem_vec_12008 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_12009);
										mem_vec_12009 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_12010);
										mem_vec_12010 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_12011);
										mem_vec_12011 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_12012);
										mem_vec_12012 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_12013);
										mem_vec_12013 = vec_101;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11990);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11991);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11992);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11993);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11994);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11995);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11996);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11997);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11998);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11999);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_12000);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_12001);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12002);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12003);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_12004);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_12005);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12006);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12007);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_12008);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_12009);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12010);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12011);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_12012);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_12013);
						}
					}
				}
			}
		}
		for (y = y696 + 42, yp_0 = 0;
			y < y696 + 42 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 8, f = 64
			// T (x, 56) (56 / 1)
			for (x1268 = x1269, x1268_p_0 = 0;
				x1268 < x1269 + 56;
				x1268 += 1, x1268_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 64
				// T (c, 2) (8 / 4)
				for (c1168 = c1169, c1168_p_1 = c1169_p_0, c1168_p_0 = 0;
					c1168 < c1169 + 8;
					c1168 += 4, c1168_p_1 += 4, c1168_p_0 += 4){
					// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
					// T (w, 3) (3 / 1)
					for (w = w662, wp_0 = 0;
						w < w662 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1268, xp_1 = x1268_p_0, xp_0 = 0;
							x < x1268 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_12014 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_12015 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_12016 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_12017 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_12018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_12019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_12020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_12021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_12022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_12023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_12024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_12025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_12026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_12027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_12028 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_12029 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_12030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_12031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_12032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_12033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_12034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_12035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_12036 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_12037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_12038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_12039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_12040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_12041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c1168, cp_2 = c1168_p_1, cp_1 = c1168_p_0, cp_0 = 0;
										c < c1168 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12014);
										mem_vec_12014 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12015);
										mem_vec_12015 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_12016);
										mem_vec_12016 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_12017);
										mem_vec_12017 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_12018);
										mem_vec_12018 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_12019);
										mem_vec_12019 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_12020);
										mem_vec_12020 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_12021);
										mem_vec_12021 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12022);
										mem_vec_12022 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12023);
										mem_vec_12023 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_12024);
										mem_vec_12024 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_12025);
										mem_vec_12025 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_12026);
										mem_vec_12026 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_12027);
										mem_vec_12027 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_12028);
										mem_vec_12028 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_12029);
										mem_vec_12029 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_12030);
										mem_vec_12030 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_12031);
										mem_vec_12031 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_12032);
										mem_vec_12032 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_12033);
										mem_vec_12033 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_12034);
										mem_vec_12034 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_12035);
										mem_vec_12035 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_12036);
										mem_vec_12036 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_12037);
										mem_vec_12037 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_12038);
										mem_vec_12038 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_12039);
										mem_vec_12039 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_12040);
										mem_vec_12040 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_12041);
										mem_vec_12041 = vec_38;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_12014);
										mem_vec_12014 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_12015);
										mem_vec_12015 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_12016);
										mem_vec_12016 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_12017);
										mem_vec_12017 = vec_46;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_12018);
										mem_vec_12018 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_12019);
										mem_vec_12019 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_12020);
										mem_vec_12020 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_12021);
										mem_vec_12021 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_12022);
										mem_vec_12022 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_12023);
										mem_vec_12023 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_12024);
										mem_vec_12024 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_12025);
										mem_vec_12025 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_12026);
										mem_vec_12026 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_12027);
										mem_vec_12027 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_12028);
										mem_vec_12028 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_12029);
										mem_vec_12029 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_12030);
										mem_vec_12030 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_12031);
										mem_vec_12031 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_12032);
										mem_vec_12032 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_12033);
										mem_vec_12033 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_12034);
										mem_vec_12034 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_12035);
										mem_vec_12035 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_12036);
										mem_vec_12036 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_12037);
										mem_vec_12037 = vec_72;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_12038);
										mem_vec_12038 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_12039);
										mem_vec_12039 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_12040);
										mem_vec_12040 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_12041);
										mem_vec_12041 = vec_77;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_12014);
										mem_vec_12014 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_12015);
										mem_vec_12015 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_12016);
										mem_vec_12016 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_12017);
										mem_vec_12017 = vec_85;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_12018);
										mem_vec_12018 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_12019);
										mem_vec_12019 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_12020);
										mem_vec_12020 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_12021);
										mem_vec_12021 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_12022);
										mem_vec_12022 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_12023);
										mem_vec_12023 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_12024);
										mem_vec_12024 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_12025);
										mem_vec_12025 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_12026);
										mem_vec_12026 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_12027);
										mem_vec_12027 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_12028);
										mem_vec_12028 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_12029);
										mem_vec_12029 = vec_101;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_12030);
										mem_vec_12030 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_12031);
										mem_vec_12031 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_12032);
										mem_vec_12032 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_12033);
										mem_vec_12033 = vec_106;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_12034);
										mem_vec_12034 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_12035);
										mem_vec_12035 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_12036);
										mem_vec_12036 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_12037);
										mem_vec_12037 = vec_111;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_12038);
										mem_vec_12038 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_12039);
										mem_vec_12039 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_12040);
										mem_vec_12040 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_12041);
										mem_vec_12041 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12014);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12015);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_12016);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_12017);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12018);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12019);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_12020);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_12021);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12022);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12023);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_12024);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_12025);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12026);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12027);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_12028);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_12029);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12030);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12031);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_12032);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_12033);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12034);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12035);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_12036);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_12037);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_12038);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_12039);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_12040);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_12041);
						}
					}
				}
			}
		}
}


}