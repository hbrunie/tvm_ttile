#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (28, x);
  T (3, w); T (32, c); T (2, x);
  Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))]; T (2, c)]
*/
IND_TYPE c, cp_0, c1088_p_0, c1089_p_0, cp_1, c1088_p_1, cp_2, c1088, c1089, w, wp_0, x, xp_0, x1250_p_0, xp_1, x1250, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y668 = 0;
IND_TYPE x1251 = 0;
IND_TYPE h = 0;
IND_TYPE w644 = 0;
IND_TYPE c1090 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11132 ,mem_vec_11133 ,mem_vec_11134 ,mem_vec_11135 ,mem_vec_11136 ,mem_vec_11137 ,mem_vec_11138 ,mem_vec_11139 ,mem_vec_11140 ,mem_vec_11141 ,mem_vec_11142 ,mem_vec_11143 ,mem_vec_11144 ,mem_vec_11145 ,mem_vec_11146 ,mem_vec_11147 ,mem_vec_11148 ,mem_vec_11149 ,mem_vec_11150 ,mem_vec_11151 ,mem_vec_11152 ,mem_vec_11153 ,mem_vec_11154 ,mem_vec_11155 ,mem_vec_11156 ,mem_vec_11157 ,mem_vec_11158 ,mem_vec_11159 ,mem_vec_11160 ,mem_vec_11161 ,mem_vec_11162 ,mem_vec_11163 ,mem_vec_11164 ,mem_vec_11165 ,mem_vec_11166 ,mem_vec_11167 ,mem_vec_11168 ,mem_vec_11169 ,mem_vec_11170 ,mem_vec_11171 ,mem_vec_11172 ,mem_vec_11173 ,mem_vec_11174 ,mem_vec_11175 ,mem_vec_11176 ,mem_vec_11177 ,mem_vec_11178 ,mem_vec_11179 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 2) (64 / 32)
for (c1089 = c1090, c1089_p_0 = 0;
	c1089 < c1090 + 64;
	c1089 += 32, c1089_p_0 += 32){
		for (y = y668, yp_0 = 0;
			y < y668 + 35;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 64
			// T (x, 2) (56 / 28)
			for (x1250 = x1251, x1250_p_0 = 0;
				x1250 < x1251 + 56;
				x1250 += 28, x1250_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 64
				// T (c, 32) (32 / 1)
				for (c1088 = c1089, c1088_p_1 = c1089_p_0, c1088_p_0 = 0;
					c1088 < c1089 + 32;
					c1088 += 1, c1088_p_1 += 1, c1088_p_0 += 1){
					// y = ph_y, x = 28, h = 3, w = 3, c = 1, f = 64
					// T (w, 3) (3 / 1)
					for (w = w644, wp_0 = 0;
						w < w644 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 28, h = 3, w = 1, c = 1, f = 64
						// T (x, 28) (28 / 1)
						for (x = x1250, xp_1 = x1250_p_0, xp_0 = 0;
							x < x1250 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_11132 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_11133 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_11134 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_11135 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_11136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_11137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_11138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_11139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_11140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_11141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_11142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_11143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_11144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_11145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_11146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_11147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_11148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_11149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_11150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_11151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c1088, cp_2 = c1088_p_1, cp_1 = c1088_p_0, cp_0 = 0;
										c < c1088 + 1;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11132);
										mem_vec_11132 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11133);
										mem_vec_11133 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11134);
										mem_vec_11134 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11135);
										mem_vec_11135 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11136);
										mem_vec_11136 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11137);
										mem_vec_11137 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11138);
										mem_vec_11138 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11139);
										mem_vec_11139 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11140);
										mem_vec_11140 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11141);
										mem_vec_11141 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11142);
										mem_vec_11142 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11143);
										mem_vec_11143 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11144);
										mem_vec_11144 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11145);
										mem_vec_11145 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11146);
										mem_vec_11146 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11147);
										mem_vec_11147 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11148);
										mem_vec_11148 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11149);
										mem_vec_11149 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11150);
										mem_vec_11150 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11151);
										mem_vec_11151 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_11132);
										mem_vec_11132 = vec_29;

										vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_11133);
										mem_vec_11133 = vec_32;

										vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_11134);
										mem_vec_11134 = vec_34;

										vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_11135);
										mem_vec_11135 = vec_36;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_6);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_11136);
										mem_vec_11136 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_11137);
										mem_vec_11137 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_11138);
										mem_vec_11138 = vec_41;



										vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_11139);
										mem_vec_11139 = vec_42;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_11140);
										mem_vec_11140 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_11141);
										mem_vec_11141 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_11142);
										mem_vec_11142 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_11143);
										mem_vec_11143 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_11144);
										mem_vec_11144 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_11145);
										mem_vec_11145 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_11146);
										mem_vec_11146 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_11147);
										mem_vec_11147 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_11148);
										mem_vec_11148 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_11149);
										mem_vec_11149 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_11150);
										mem_vec_11150 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_11151);
										mem_vec_11151 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_59 = _mm512_set1_ps(scal_10);
										vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_11132);
										mem_vec_11132 = vec_58;

										vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_11133);
										mem_vec_11133 = vec_61;

										vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_11134);
										mem_vec_11134 = vec_63;

										vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_11135);
										mem_vec_11135 = vec_65;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_68 = _mm512_set1_ps(scal_11);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_11136);
										mem_vec_11136 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_11137);
										mem_vec_11137 = vec_69;



										vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_11138);
										mem_vec_11138 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_11139);
										mem_vec_11139 = vec_71;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_73 = _mm512_set1_ps(scal_12);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_11140);
										mem_vec_11140 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_11141);
										mem_vec_11141 = vec_74;



										vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_11142);
										mem_vec_11142 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_11143);
										mem_vec_11143 = vec_76;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_78 = _mm512_set1_ps(scal_13);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_11144);
										mem_vec_11144 = vec_77;



										vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_11145);
										mem_vec_11145 = vec_79;



										vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_11146);
										mem_vec_11146 = vec_80;



										vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_11147);
										mem_vec_11147 = vec_81;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
										vec_83 = _mm512_set1_ps(scal_14);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_11148);
										mem_vec_11148 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_11149);
										mem_vec_11149 = vec_84;



										vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_11150);
										mem_vec_11150 = vec_85;



										vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_11151);
										mem_vec_11151 = vec_86;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11132);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11133);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11134);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11135);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11136);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11137);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11138);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11139);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11140);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11141);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11142);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11143);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11144);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11145);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_11146);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_11147);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11148);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11149);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_11150);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_11151);
						}
					}
				}
			}
		}
		for (y = y668 + 35, yp_0 = 0;
			y < y668 + 35 + 21;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 64
			// T (x, 2) (56 / 28)
			for (x1250 = x1251, x1250_p_0 = 0;
				x1250 < x1251 + 56;
				x1250 += 28, x1250_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 64
				// T (c, 32) (32 / 1)
				for (c1088 = c1089, c1088_p_1 = c1089_p_0, c1088_p_0 = 0;
					c1088 < c1089 + 32;
					c1088 += 1, c1088_p_1 += 1, c1088_p_0 += 1){
					// y = ph_y, x = 28, h = 3, w = 3, c = 1, f = 64
					// T (w, 3) (3 / 1)
					for (w = w644, wp_0 = 0;
						w < w644 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 28, h = 3, w = 1, c = 1, f = 64
						// T (x, 28) (28 / 1)
						for (x = x1250, xp_1 = x1250_p_0, xp_0 = 0;
							x < x1250 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_11152 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_11153 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_11154 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_11155 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_11156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_11157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_11158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_11159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_11160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_11161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_11162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_11163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_11164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_11165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_11166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_11167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_11168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_11169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_11170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_11171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_11172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_11173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_11174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_11175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_11176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_11177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_11178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_11179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c1088, cp_2 = c1088_p_1, cp_1 = c1088_p_0, cp_0 = 0;
										c < c1088 + 1;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11152);
										mem_vec_11152 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11153);
										mem_vec_11153 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11154);
										mem_vec_11154 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11155);
										mem_vec_11155 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11156);
										mem_vec_11156 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11157);
										mem_vec_11157 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11158);
										mem_vec_11158 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11159);
										mem_vec_11159 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11160);
										mem_vec_11160 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11161);
										mem_vec_11161 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11162);
										mem_vec_11162 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11163);
										mem_vec_11163 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11164);
										mem_vec_11164 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11165);
										mem_vec_11165 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11166);
										mem_vec_11166 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11167);
										mem_vec_11167 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11168);
										mem_vec_11168 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11169);
										mem_vec_11169 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11170);
										mem_vec_11170 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11171);
										mem_vec_11171 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11172);
										mem_vec_11172 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11173);
										mem_vec_11173 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_11174);
										mem_vec_11174 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_11175);
										mem_vec_11175 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_11176);
										mem_vec_11176 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_11177);
										mem_vec_11177 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_11178);
										mem_vec_11178 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_11179);
										mem_vec_11179 = vec_38;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_11152);
										mem_vec_11152 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_11153);
										mem_vec_11153 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_11154);
										mem_vec_11154 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_11155);
										mem_vec_11155 = vec_46;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_11156);
										mem_vec_11156 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_11157);
										mem_vec_11157 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_11158);
										mem_vec_11158 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_11159);
										mem_vec_11159 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_11160);
										mem_vec_11160 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_11161);
										mem_vec_11161 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_11162);
										mem_vec_11162 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_11163);
										mem_vec_11163 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_11164);
										mem_vec_11164 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_11165);
										mem_vec_11165 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_11166);
										mem_vec_11166 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_11167);
										mem_vec_11167 = vec_62;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_11168);
										mem_vec_11168 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_11169);
										mem_vec_11169 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_11170);
										mem_vec_11170 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_11171);
										mem_vec_11171 = vec_67;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_11172);
										mem_vec_11172 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_11173);
										mem_vec_11173 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_11174);
										mem_vec_11174 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_11175);
										mem_vec_11175 = vec_72;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_11176);
										mem_vec_11176 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_11177);
										mem_vec_11177 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_11178);
										mem_vec_11178 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_11179);
										mem_vec_11179 = vec_77;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_11152);
										mem_vec_11152 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_11153);
										mem_vec_11153 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_11154);
										mem_vec_11154 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_11155);
										mem_vec_11155 = vec_85;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_11156);
										mem_vec_11156 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_11157);
										mem_vec_11157 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_11158);
										mem_vec_11158 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_11159);
										mem_vec_11159 = vec_91;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_11160);
										mem_vec_11160 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_11161);
										mem_vec_11161 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_11162);
										mem_vec_11162 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_11163);
										mem_vec_11163 = vec_96;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_11164);
										mem_vec_11164 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_11165);
										mem_vec_11165 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_11166);
										mem_vec_11166 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_11167);
										mem_vec_11167 = vec_101;
										scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_11168);
										mem_vec_11168 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_11169);
										mem_vec_11169 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_11170);
										mem_vec_11170 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_11171);
										mem_vec_11171 = vec_106;
										scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_11172);
										mem_vec_11172 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_11173);
										mem_vec_11173 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_11174);
										mem_vec_11174 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_11175);
										mem_vec_11175 = vec_111;
										scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_11176);
										mem_vec_11176 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_11177);
										mem_vec_11177 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_11178);
										mem_vec_11178 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_11179);
										mem_vec_11179 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11152);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11153);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11154);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11155);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11156);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11157);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11158);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11159);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11160);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11161);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11162);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11163);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11164);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11165);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_11166);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_11167);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11168);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11169);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_11170);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_11171);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11172);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11173);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_11174);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_11175);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11176);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11177);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_11178);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_11179);
						}
					}
				}
			}
		}
}


}