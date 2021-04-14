#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (1, c); T (8, x);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (64, c)]
*/
IND_TYPE c, cp_0, c1336_p_0, c1337_p_0, cp_1, c1336_p_1, cp_2, c1336, c1337, h, hp_0, x, xp_0, x1436_p_0, xp_1, x1436, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y792 = 0;
IND_TYPE x1437 = 0;
IND_TYPE h616 = 0;
IND_TYPE w = 0;
IND_TYPE c1338 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14116 ,mem_vec_14117 ,mem_vec_14118 ,mem_vec_14119 ,mem_vec_14120 ,mem_vec_14121 ,mem_vec_14122 ,mem_vec_14123 ,mem_vec_14124 ,mem_vec_14125 ,mem_vec_14126 ,mem_vec_14127 ,mem_vec_14128 ,mem_vec_14129 ,mem_vec_14130 ,mem_vec_14131 ,mem_vec_14132 ,mem_vec_14133 ,mem_vec_14134 ,mem_vec_14135 ,mem_vec_14136 ,mem_vec_14137 ,mem_vec_14138 ,mem_vec_14139 ,mem_vec_14140 ,mem_vec_14141 ,mem_vec_14142 ,mem_vec_14143 ,mem_vec_14144 ,mem_vec_14145 ,mem_vec_14146 ,mem_vec_14147 ,mem_vec_14148 ,mem_vec_14149 ,mem_vec_14150 ,mem_vec_14151 ,mem_vec_14152 ,mem_vec_14153 ,mem_vec_14154 ,mem_vec_14155 ,mem_vec_14156 ,mem_vec_14157 ,mem_vec_14158 ,mem_vec_14159 ,mem_vec_14160 ,mem_vec_14161 ,mem_vec_14162 ,mem_vec_14163 ,mem_vec_14164 ,mem_vec_14165 ,mem_vec_14166 ,mem_vec_14167 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 64) (64 / 1)
for (c1337 = c1338, c1337_p_0 = 0;
	c1337 < c1338 + 64;
	c1337 += 1, c1337_p_0 += 1){
		for (y = y792, yp_0 = 0;
			y < y792 + 42;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 56, h = 3, w = 3, c = 1, f = 64
			// T (x, 8) (56 / 7)
			for (x1436 = x1437, x1436_p_0 = 0;
				x1436 < x1437 + 56;
				x1436 += 7, x1436_p_0 += 7){
				// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
				// T (c, 1) (1 / 1)
				for (c1336 = c1337, c1336_p_1 = c1337_p_0, c1336_p_0 = 0;
					c1336 < c1337 + 1;
					c1336 += 1, c1336_p_1 += 1, c1336_p_0 += 1){
					// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
					// T (h, 3) (3 / 1)
					for (h = h616, hp_0 = 0;
						h < h616 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 64
						// T (x, 7) (7 / 1)
						for (x = x1436, xp_1 = x1436_p_0, xp_0 = 0;
							x < x1436 + 7;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14116 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14117 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14118 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_14119 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_14120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_14123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_14124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_14127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_14128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_14131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_14132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_14135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_14136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_14139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c1336, cp_2 = c1336_p_1, cp_1 = c1336_p_0, cp_0 = 0;
										c < c1336 + 1;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14116);
										mem_vec_14116 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14117);
										mem_vec_14117 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14118);
										mem_vec_14118 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14119);
										mem_vec_14119 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14120);
										mem_vec_14120 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14121);
										mem_vec_14121 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14122);
										mem_vec_14122 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14123);
										mem_vec_14123 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14124);
										mem_vec_14124 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14125);
										mem_vec_14125 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14126);
										mem_vec_14126 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14127);
										mem_vec_14127 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14128);
										mem_vec_14128 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14129);
										mem_vec_14129 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14130);
										mem_vec_14130 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14131);
										mem_vec_14131 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14132);
										mem_vec_14132 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14133);
										mem_vec_14133 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14134);
										mem_vec_14134 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14135);
										mem_vec_14135 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14136);
										mem_vec_14136 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14137);
										mem_vec_14137 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14138);
										mem_vec_14138 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14139);
										mem_vec_14139 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_14116);
										mem_vec_14116 = vec_34;

										vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_14117);
										mem_vec_14117 = vec_37;

										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_14118);
										mem_vec_14118 = vec_39;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_14119);
										mem_vec_14119 = vec_41;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_14120);
										mem_vec_14120 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_14121);
										mem_vec_14121 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_14122);
										mem_vec_14122 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_14123);
										mem_vec_14123 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_14124);
										mem_vec_14124 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_14125);
										mem_vec_14125 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_14126);
										mem_vec_14126 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_14127);
										mem_vec_14127 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_14128);
										mem_vec_14128 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_14129);
										mem_vec_14129 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_14130);
										mem_vec_14130 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_14131);
										mem_vec_14131 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_14132);
										mem_vec_14132 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_14133);
										mem_vec_14133 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_14134);
										mem_vec_14134 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_14135);
										mem_vec_14135 = vec_62;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_14136);
										mem_vec_14136 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_14137);
										mem_vec_14137 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_14138);
										mem_vec_14138 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_14139);
										mem_vec_14139 = vec_67;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_69 = _mm512_set1_ps(scal_12);
										vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_14116);
										mem_vec_14116 = vec_68;

										vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_14117);
										mem_vec_14117 = vec_71;

										vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_14118);
										mem_vec_14118 = vec_73;

										vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_14119);
										mem_vec_14119 = vec_75;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_78 = _mm512_set1_ps(scal_13);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_14120);
										mem_vec_14120 = vec_77;



										vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_14121);
										mem_vec_14121 = vec_79;



										vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_14122);
										mem_vec_14122 = vec_80;



										vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_14123);
										mem_vec_14123 = vec_81;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_83 = _mm512_set1_ps(scal_14);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_14124);
										mem_vec_14124 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_14125);
										mem_vec_14125 = vec_84;



										vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_14126);
										mem_vec_14126 = vec_85;



										vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_14127);
										mem_vec_14127 = vec_86;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_14128);
										mem_vec_14128 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_14129);
										mem_vec_14129 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_14130);
										mem_vec_14130 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_14131);
										mem_vec_14131 = vec_91;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_14132);
										mem_vec_14132 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_14133);
										mem_vec_14133 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_14134);
										mem_vec_14134 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_14135);
										mem_vec_14135 = vec_96;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_14136);
										mem_vec_14136 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_14137);
										mem_vec_14137 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_14138);
										mem_vec_14138 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_14139);
										mem_vec_14139 = vec_101;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14116);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14117);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14118);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14119);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14120);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14121);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14122);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14123);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14124);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14125);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14126);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14127);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14128);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14129);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14130);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14131);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14132);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14133);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14134);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14135);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14136);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14137);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_14138);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_14139);
						}
					}
				}
			}
		}
		for (y = y792 + 42, yp_0 = 0;
			y < y792 + 42 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 1, f = 64
			// T (x, 8) (56 / 7)
			for (x1436 = x1437, x1436_p_0 = 0;
				x1436 < x1437 + 56;
				x1436 += 7, x1436_p_0 += 7){
				// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
				// T (c, 1) (1 / 1)
				for (c1336 = c1337, c1336_p_1 = c1337_p_0, c1336_p_0 = 0;
					c1336 < c1337 + 1;
					c1336 += 1, c1336_p_1 += 1, c1336_p_0 += 1){
					// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
					// T (h, 3) (3 / 1)
					for (h = h616, hp_0 = 0;
						h < h616 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 64
						// T (x, 7) (7 / 1)
						for (x = x1436, xp_1 = x1436_p_0, xp_0 = 0;
							x < x1436 + 7;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14140 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14141 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14142 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_14143 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_14144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_14147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_14148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_14151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_14152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_14155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_14156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_14159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_14160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_14163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_14164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_14165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_14166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_14167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c1336, cp_2 = c1336_p_1, cp_1 = c1336_p_0, cp_0 = 0;
										c < c1336 + 1;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14140);
										mem_vec_14140 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14141);
										mem_vec_14141 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14142);
										mem_vec_14142 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14143);
										mem_vec_14143 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14144);
										mem_vec_14144 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14145);
										mem_vec_14145 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14146);
										mem_vec_14146 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14147);
										mem_vec_14147 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14148);
										mem_vec_14148 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14149);
										mem_vec_14149 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14150);
										mem_vec_14150 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14151);
										mem_vec_14151 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14152);
										mem_vec_14152 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14153);
										mem_vec_14153 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14154);
										mem_vec_14154 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14155);
										mem_vec_14155 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14156);
										mem_vec_14156 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14157);
										mem_vec_14157 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14158);
										mem_vec_14158 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14159);
										mem_vec_14159 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14160);
										mem_vec_14160 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14161);
										mem_vec_14161 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14162);
										mem_vec_14162 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14163);
										mem_vec_14163 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_14164);
										mem_vec_14164 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_14165);
										mem_vec_14165 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_14166);
										mem_vec_14166 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_14167);
										mem_vec_14167 = vec_38;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_14140);
										mem_vec_14140 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_14141);
										mem_vec_14141 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_14142);
										mem_vec_14142 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_14143);
										mem_vec_14143 = vec_46;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_14144);
										mem_vec_14144 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_14145);
										mem_vec_14145 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_14146);
										mem_vec_14146 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_14147);
										mem_vec_14147 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_14148);
										mem_vec_14148 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_14149);
										mem_vec_14149 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_14150);
										mem_vec_14150 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_14151);
										mem_vec_14151 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_14152);
										mem_vec_14152 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_14153);
										mem_vec_14153 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_14154);
										mem_vec_14154 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_14155);
										mem_vec_14155 = vec_62;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_14156);
										mem_vec_14156 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_14157);
										mem_vec_14157 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_14158);
										mem_vec_14158 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_14159);
										mem_vec_14159 = vec_67;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_14160);
										mem_vec_14160 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_14161);
										mem_vec_14161 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_14162);
										mem_vec_14162 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_14163);
										mem_vec_14163 = vec_72;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_14164);
										mem_vec_14164 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_14165);
										mem_vec_14165 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_14166);
										mem_vec_14166 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_14167);
										mem_vec_14167 = vec_77;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_14140);
										mem_vec_14140 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_14141);
										mem_vec_14141 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_14142);
										mem_vec_14142 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_14143);
										mem_vec_14143 = vec_85;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_14144);
										mem_vec_14144 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_14145);
										mem_vec_14145 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_14146);
										mem_vec_14146 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_14147);
										mem_vec_14147 = vec_91;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_14148);
										mem_vec_14148 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_14149);
										mem_vec_14149 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_14150);
										mem_vec_14150 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_14151);
										mem_vec_14151 = vec_96;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_14152);
										mem_vec_14152 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_14153);
										mem_vec_14153 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_14154);
										mem_vec_14154 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_14155);
										mem_vec_14155 = vec_101;
										scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_14156);
										mem_vec_14156 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_14157);
										mem_vec_14157 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_14158);
										mem_vec_14158 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_14159);
										mem_vec_14159 = vec_106;
										scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_14160);
										mem_vec_14160 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_14161);
										mem_vec_14161 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_14162);
										mem_vec_14162 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_14163);
										mem_vec_14163 = vec_111;
										scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_14164);
										mem_vec_14164 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_14165);
										mem_vec_14165 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_14166);
										mem_vec_14166 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_14167);
										mem_vec_14167 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14140);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14141);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14142);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14143);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14144);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14145);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14146);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14147);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14148);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14149);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14150);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14151);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14152);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14153);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14154);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14155);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14156);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14157);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14158);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14159);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14160);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14161);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_14162);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_14163);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14164);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14165);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_14166);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_14167);
						}
					}
				}
			}
		}
}


}