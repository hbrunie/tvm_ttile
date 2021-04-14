#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (1, c); T (4, x);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (8, c)]
*/
IND_TYPE c, cp_0, c1328_p_0, c1329_p_0, cp_1, c1328_p_1, cp_2, c1328, c1329, h, hp_0, x, xp_0, x1430_p_0, xp_1, x1430, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y788 = 0;
IND_TYPE x1431 = 0;
IND_TYPE h612 = 0;
IND_TYPE w = 0;
IND_TYPE c1330 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14012 ,mem_vec_14013 ,mem_vec_14014 ,mem_vec_14015 ,mem_vec_14016 ,mem_vec_14017 ,mem_vec_14018 ,mem_vec_14019 ,mem_vec_14020 ,mem_vec_14021 ,mem_vec_14022 ,mem_vec_14023 ,mem_vec_14024 ,mem_vec_14025 ,mem_vec_14026 ,mem_vec_14027 ,mem_vec_14028 ,mem_vec_14029 ,mem_vec_14030 ,mem_vec_14031 ,mem_vec_14032 ,mem_vec_14033 ,mem_vec_14034 ,mem_vec_14035 ,mem_vec_14036 ,mem_vec_14037 ,mem_vec_14038 ,mem_vec_14039 ,mem_vec_14040 ,mem_vec_14041 ,mem_vec_14042 ,mem_vec_14043 ,mem_vec_14044 ,mem_vec_14045 ,mem_vec_14046 ,mem_vec_14047 ,mem_vec_14048 ,mem_vec_14049 ,mem_vec_14050 ,mem_vec_14051 ,mem_vec_14052 ,mem_vec_14053 ,mem_vec_14054 ,mem_vec_14055 ,mem_vec_14056 ,mem_vec_14057 ,mem_vec_14058 ,mem_vec_14059 ,mem_vec_14060 ,mem_vec_14061 ,mem_vec_14062 ,mem_vec_14063 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 8) (64 / 8)
for (c1329 = c1330, c1329_p_0 = 0;
	c1329 < c1330 + 64;
	c1329 += 8, c1329_p_0 += 8){
		for (y = y788, yp_0 = 0;
			y < y788 + 42;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 56, h = 3, w = 3, c = 8, f = 64
			// T (x, 4) (56 / 14)
			for (x1430 = x1431, x1430_p_0 = 0;
				x1430 < x1431 + 56;
				x1430 += 14, x1430_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 64
				// T (c, 1) (8 / 8)
				for (c1328 = c1329, c1328_p_1 = c1329_p_0, c1328_p_0 = 0;
					c1328 < c1329 + 8;
					c1328 += 8, c1328_p_1 += 8, c1328_p_0 += 8){
					// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 64
					// T (h, 3) (3 / 1)
					for (h = h612, hp_0 = 0;
						h < h612 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 14, h = 1, w = 3, c = 8, f = 64
						// T (x, 14) (14 / 1)
						for (x = x1430, xp_1 = x1430_p_0, xp_0 = 0;
							x < x1430 + 14;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14012 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14013 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14014 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_14015 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_14016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_14019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_14020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_14023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_14024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_14027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_14028 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14029 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_14031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_14032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_14035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1328, cp_2 = c1328_p_1, cp_1 = c1328_p_0, cp_0 = 0;
										c < c1328 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14012);
										mem_vec_14012 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14013);
										mem_vec_14013 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14014);
										mem_vec_14014 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14015);
										mem_vec_14015 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14016);
										mem_vec_14016 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14017);
										mem_vec_14017 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14018);
										mem_vec_14018 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14019);
										mem_vec_14019 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14020);
										mem_vec_14020 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14021);
										mem_vec_14021 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14022);
										mem_vec_14022 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14023);
										mem_vec_14023 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14024);
										mem_vec_14024 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14025);
										mem_vec_14025 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14026);
										mem_vec_14026 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14027);
										mem_vec_14027 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14028);
										mem_vec_14028 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14029);
										mem_vec_14029 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14030);
										mem_vec_14030 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14031);
										mem_vec_14031 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14032);
										mem_vec_14032 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14033);
										mem_vec_14033 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14034);
										mem_vec_14034 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14035);
										mem_vec_14035 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_14012);
										mem_vec_14012 = vec_34;

										vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_14013);
										mem_vec_14013 = vec_37;

										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_14014);
										mem_vec_14014 = vec_39;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_14015);
										mem_vec_14015 = vec_41;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_14016);
										mem_vec_14016 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_14017);
										mem_vec_14017 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_14018);
										mem_vec_14018 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_14019);
										mem_vec_14019 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_14020);
										mem_vec_14020 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_14021);
										mem_vec_14021 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_14022);
										mem_vec_14022 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_14023);
										mem_vec_14023 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_14024);
										mem_vec_14024 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_14025);
										mem_vec_14025 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_14026);
										mem_vec_14026 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_14027);
										mem_vec_14027 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_14028);
										mem_vec_14028 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_14029);
										mem_vec_14029 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_14030);
										mem_vec_14030 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_14031);
										mem_vec_14031 = vec_62;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_14032);
										mem_vec_14032 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_14033);
										mem_vec_14033 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_14034);
										mem_vec_14034 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_14035);
										mem_vec_14035 = vec_67;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_69 = _mm512_set1_ps(scal_12);
										vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_14012);
										mem_vec_14012 = vec_68;

										vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_14013);
										mem_vec_14013 = vec_71;

										vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_14014);
										mem_vec_14014 = vec_73;

										vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_14015);
										mem_vec_14015 = vec_75;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_78 = _mm512_set1_ps(scal_13);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_14016);
										mem_vec_14016 = vec_77;



										vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_14017);
										mem_vec_14017 = vec_79;



										vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_14018);
										mem_vec_14018 = vec_80;



										vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_14019);
										mem_vec_14019 = vec_81;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_83 = _mm512_set1_ps(scal_14);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_14020);
										mem_vec_14020 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_14021);
										mem_vec_14021 = vec_84;



										vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_14022);
										mem_vec_14022 = vec_85;



										vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_14023);
										mem_vec_14023 = vec_86;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_14024);
										mem_vec_14024 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_14025);
										mem_vec_14025 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_14026);
										mem_vec_14026 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_14027);
										mem_vec_14027 = vec_91;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_14028);
										mem_vec_14028 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_14029);
										mem_vec_14029 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_14030);
										mem_vec_14030 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_14031);
										mem_vec_14031 = vec_96;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_14032);
										mem_vec_14032 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_14033);
										mem_vec_14033 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_14034);
										mem_vec_14034 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_14035);
										mem_vec_14035 = vec_101;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14012);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14013);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14014);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14015);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14016);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14017);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14018);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14019);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14020);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14021);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14022);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14023);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14024);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14025);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14026);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14027);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14028);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14029);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14030);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14031);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14032);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14033);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_14034);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_14035);
						}
					}
				}
			}
		}
		for (y = y788 + 42, yp_0 = 0;
			y < y788 + 42 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 8, f = 64
			// T (x, 4) (56 / 14)
			for (x1430 = x1431, x1430_p_0 = 0;
				x1430 < x1431 + 56;
				x1430 += 14, x1430_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 64
				// T (c, 1) (8 / 8)
				for (c1328 = c1329, c1328_p_1 = c1329_p_0, c1328_p_0 = 0;
					c1328 < c1329 + 8;
					c1328 += 8, c1328_p_1 += 8, c1328_p_0 += 8){
					// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 64
					// T (h, 3) (3 / 1)
					for (h = h612, hp_0 = 0;
						h < h612 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 14, h = 1, w = 3, c = 8, f = 64
						// T (x, 14) (14 / 1)
						for (x = x1430, xp_1 = x1430_p_0, xp_0 = 0;
							x < x1430 + 14;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14036 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14037 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14038 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_14039 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_14040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_14043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_14044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_14047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_14048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_14051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_14052 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14053 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_14055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_14056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14057 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14058 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_14059 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_14060 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_14061 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_14062 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_14063 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1328, cp_2 = c1328_p_1, cp_1 = c1328_p_0, cp_0 = 0;
										c < c1328 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14036);
										mem_vec_14036 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14037);
										mem_vec_14037 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14038);
										mem_vec_14038 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14039);
										mem_vec_14039 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14040);
										mem_vec_14040 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14041);
										mem_vec_14041 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14042);
										mem_vec_14042 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14043);
										mem_vec_14043 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14044);
										mem_vec_14044 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14045);
										mem_vec_14045 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14046);
										mem_vec_14046 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14047);
										mem_vec_14047 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14048);
										mem_vec_14048 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14049);
										mem_vec_14049 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14050);
										mem_vec_14050 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14051);
										mem_vec_14051 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14052);
										mem_vec_14052 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14053);
										mem_vec_14053 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14054);
										mem_vec_14054 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14055);
										mem_vec_14055 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14056);
										mem_vec_14056 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14057);
										mem_vec_14057 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14058);
										mem_vec_14058 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14059);
										mem_vec_14059 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_14060);
										mem_vec_14060 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_14061);
										mem_vec_14061 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_14062);
										mem_vec_14062 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_14063);
										mem_vec_14063 = vec_38;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_14036);
										mem_vec_14036 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_14037);
										mem_vec_14037 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_14038);
										mem_vec_14038 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_14039);
										mem_vec_14039 = vec_46;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_14040);
										mem_vec_14040 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_14041);
										mem_vec_14041 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_14042);
										mem_vec_14042 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_14043);
										mem_vec_14043 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_14044);
										mem_vec_14044 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_14045);
										mem_vec_14045 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_14046);
										mem_vec_14046 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_14047);
										mem_vec_14047 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_14048);
										mem_vec_14048 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_14049);
										mem_vec_14049 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_14050);
										mem_vec_14050 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_14051);
										mem_vec_14051 = vec_62;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_14052);
										mem_vec_14052 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_14053);
										mem_vec_14053 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_14054);
										mem_vec_14054 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_14055);
										mem_vec_14055 = vec_67;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_14056);
										mem_vec_14056 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_14057);
										mem_vec_14057 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_14058);
										mem_vec_14058 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_14059);
										mem_vec_14059 = vec_72;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_14060);
										mem_vec_14060 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_14061);
										mem_vec_14061 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_14062);
										mem_vec_14062 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_14063);
										mem_vec_14063 = vec_77;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_14036);
										mem_vec_14036 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_14037);
										mem_vec_14037 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_14038);
										mem_vec_14038 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_14039);
										mem_vec_14039 = vec_85;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_14040);
										mem_vec_14040 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_14041);
										mem_vec_14041 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_14042);
										mem_vec_14042 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_14043);
										mem_vec_14043 = vec_91;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_14044);
										mem_vec_14044 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_14045);
										mem_vec_14045 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_14046);
										mem_vec_14046 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_14047);
										mem_vec_14047 = vec_96;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_14048);
										mem_vec_14048 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_14049);
										mem_vec_14049 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_14050);
										mem_vec_14050 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_14051);
										mem_vec_14051 = vec_101;
										scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_14052);
										mem_vec_14052 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_14053);
										mem_vec_14053 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_14054);
										mem_vec_14054 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_14055);
										mem_vec_14055 = vec_106;
										scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_14056);
										mem_vec_14056 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_14057);
										mem_vec_14057 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_14058);
										mem_vec_14058 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_14059);
										mem_vec_14059 = vec_111;
										scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_14060);
										mem_vec_14060 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_14061);
										mem_vec_14061 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_14062);
										mem_vec_14062 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_14063);
										mem_vec_14063 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14036);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14037);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14038);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14039);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14040);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14041);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14042);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14043);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14044);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14045);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14046);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14047);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14048);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14049);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14050);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14051);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14052);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14053);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14054);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14055);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14056);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14057);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_14058);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_14059);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14060);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14061);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_14062);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_14063);
						}
					}
				}
			}
		}
}


}