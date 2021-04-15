#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (56, x);
  T (3, w); T (4, c); T (1, x);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (2, c)]
*/
IND_TYPE c, cp_0, c1088_p_0, c1089_p_0, cp_1, c1088_p_1, cp_2, c1088, c1089, w, wp_0, x, xp_0, x1208_p_0, xp_1, x1208, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y656 = 0;
IND_TYPE x1209 = 0;
IND_TYPE h = 0;
IND_TYPE w622 = 0;
IND_TYPE c1090 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10950 ,mem_vec_10951 ,mem_vec_10952 ,mem_vec_10953 ,mem_vec_10954 ,mem_vec_10955 ,mem_vec_10956 ,mem_vec_10957 ,mem_vec_10958 ,mem_vec_10959 ,mem_vec_10960 ,mem_vec_10961 ,mem_vec_10962 ,mem_vec_10963 ,mem_vec_10964 ,mem_vec_10965 ,mem_vec_10966 ,mem_vec_10967 ,mem_vec_10968 ,mem_vec_10969 ,mem_vec_10970 ,mem_vec_10971 ,mem_vec_10972 ,mem_vec_10973 ,mem_vec_10974 ,mem_vec_10975 ,mem_vec_10976 ,mem_vec_10977 ,mem_vec_10978 ,mem_vec_10979 ,mem_vec_10980 ,mem_vec_10981 ,mem_vec_10982 ,mem_vec_10983 ,mem_vec_10984 ,mem_vec_10985 ,mem_vec_10986 ,mem_vec_10987 ,mem_vec_10988 ,mem_vec_10989 ,mem_vec_10990 ,mem_vec_10991 ,mem_vec_10992 ,mem_vec_10993 ,mem_vec_10994 ,mem_vec_10995 ,mem_vec_10996 ,mem_vec_10997 ,mem_vec_10998 ,mem_vec_10999 ,mem_vec_11000 ,mem_vec_11001 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 2) (64 / 32)
for (c1089 = c1090, c1089_p_0 = 0;
	c1089 < c1090 + 64;
	c1089 += 32, c1089_p_0 += 32){
		for (y = y656, yp_0 = 0;
			y < y656 + 42;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 64
			// T (x, 1) (56 / 56)
			for (x1208 = x1209, x1208_p_0 = 0;
				x1208 < x1209 + 56;
				x1208 += 56, x1208_p_0 += 56){
				// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 64
				// T (c, 4) (32 / 8)
				for (c1088 = c1089, c1088_p_1 = c1089_p_0, c1088_p_0 = 0;
					c1088 < c1089 + 32;
					c1088 += 8, c1088_p_1 += 8, c1088_p_0 += 8){
					// y = ph_y, x = 56, h = 3, w = 3, c = 8, f = 64
					// T (w, 3) (3 / 1)
					for (w = w622, wp_0 = 0;
						w < w622 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 56, h = 3, w = 1, c = 8, f = 64
						// T (x, 56) (56 / 1)
						for (x = x1208, xp_1 = x1208_p_0, xp_0 = 0;
							x < x1208 + 56;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10950 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10951 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10952 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10953 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_10966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_10969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_10970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_10973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1088, cp_2 = c1088_p_1, cp_1 = c1088_p_0, cp_0 = 0;
										c < c1088 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10950);
										mem_vec_10950 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10951);
										mem_vec_10951 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10952);
										mem_vec_10952 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10953);
										mem_vec_10953 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10954);
										mem_vec_10954 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10955);
										mem_vec_10955 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10956);
										mem_vec_10956 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10957);
										mem_vec_10957 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10958);
										mem_vec_10958 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10959);
										mem_vec_10959 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10960);
										mem_vec_10960 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10961);
										mem_vec_10961 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10962);
										mem_vec_10962 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10963);
										mem_vec_10963 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10964);
										mem_vec_10964 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10965);
										mem_vec_10965 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10966);
										mem_vec_10966 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10967);
										mem_vec_10967 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10968);
										mem_vec_10968 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10969);
										mem_vec_10969 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10970);
										mem_vec_10970 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10971);
										mem_vec_10971 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_10972);
										mem_vec_10972 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_10973);
										mem_vec_10973 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_10950);
										mem_vec_10950 = vec_34;

										vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_10951);
										mem_vec_10951 = vec_37;

										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_10952);
										mem_vec_10952 = vec_39;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_10953);
										mem_vec_10953 = vec_41;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_10954);
										mem_vec_10954 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_10955);
										mem_vec_10955 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_10956);
										mem_vec_10956 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_10957);
										mem_vec_10957 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_10958);
										mem_vec_10958 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_10959);
										mem_vec_10959 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_10960);
										mem_vec_10960 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_10961);
										mem_vec_10961 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_10962);
										mem_vec_10962 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_10963);
										mem_vec_10963 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_10964);
										mem_vec_10964 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_10965);
										mem_vec_10965 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_10966);
										mem_vec_10966 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_10967);
										mem_vec_10967 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_10968);
										mem_vec_10968 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_10969);
										mem_vec_10969 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_10970);
										mem_vec_10970 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_10971);
										mem_vec_10971 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_10972);
										mem_vec_10972 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_10973);
										mem_vec_10973 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_69 = _mm512_set1_ps(scal_12);
										vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_10950);
										mem_vec_10950 = vec_68;

										vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_10951);
										mem_vec_10951 = vec_71;

										vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_10952);
										mem_vec_10952 = vec_73;

										vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_10953);
										mem_vec_10953 = vec_75;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_78 = _mm512_set1_ps(scal_13);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_10954);
										mem_vec_10954 = vec_77;



										vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_10955);
										mem_vec_10955 = vec_79;



										vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_10956);
										mem_vec_10956 = vec_80;



										vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_10957);
										mem_vec_10957 = vec_81;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_83 = _mm512_set1_ps(scal_14);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_10958);
										mem_vec_10958 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_10959);
										mem_vec_10959 = vec_84;



										vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_10960);
										mem_vec_10960 = vec_85;



										vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_10961);
										mem_vec_10961 = vec_86;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_10962);
										mem_vec_10962 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_10963);
										mem_vec_10963 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_10964);
										mem_vec_10964 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_10965);
										mem_vec_10965 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_10966);
										mem_vec_10966 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_10967);
										mem_vec_10967 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_10968);
										mem_vec_10968 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_10969);
										mem_vec_10969 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_10970);
										mem_vec_10970 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_10971);
										mem_vec_10971 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_10972);
										mem_vec_10972 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_10973);
										mem_vec_10973 = vec_101;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10950);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10951);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10952);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10953);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10954);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10955);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10956);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10957);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10958);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10959);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10960);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10961);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10962);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10963);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10964);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10965);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10966);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10967);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10968);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10969);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10970);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10971);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_10972);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_10973);
						}
					}
				}
			}
		}
		for (y = y656 + 42, yp_0 = 0;
			y < y656 + 42 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 64
			// T (x, 1) (56 / 56)
			for (x1208 = x1209, x1208_p_0 = 0;
				x1208 < x1209 + 56;
				x1208 += 56, x1208_p_0 += 56){
				// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 64
				// T (c, 4) (32 / 8)
				for (c1088 = c1089, c1088_p_1 = c1089_p_0, c1088_p_0 = 0;
					c1088 < c1089 + 32;
					c1088 += 8, c1088_p_1 += 8, c1088_p_0 += 8){
					// y = ph_y, x = 56, h = 3, w = 3, c = 8, f = 64
					// T (w, 3) (3 / 1)
					for (w = w622, wp_0 = 0;
						w < w622 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 56, h = 3, w = 1, c = 8, f = 64
						// T (x, 56) (56 / 1)
						for (x = x1208, xp_1 = x1208_p_0, xp_0 = 0;
							x < x1208 + 56;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10974 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10975 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10976 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10977 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_10990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10992 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_10993 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_10994 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10995 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10996 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_10997 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_10998 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_10999 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_11000 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_11001 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1088, cp_2 = c1088_p_1, cp_1 = c1088_p_0, cp_0 = 0;
										c < c1088 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10974);
										mem_vec_10974 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10975);
										mem_vec_10975 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10976);
										mem_vec_10976 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10977);
										mem_vec_10977 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10978);
										mem_vec_10978 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10979);
										mem_vec_10979 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10980);
										mem_vec_10980 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10981);
										mem_vec_10981 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10982);
										mem_vec_10982 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10983);
										mem_vec_10983 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10984);
										mem_vec_10984 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10985);
										mem_vec_10985 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10986);
										mem_vec_10986 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10987);
										mem_vec_10987 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10988);
										mem_vec_10988 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10989);
										mem_vec_10989 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10990);
										mem_vec_10990 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10991);
										mem_vec_10991 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10992);
										mem_vec_10992 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10993);
										mem_vec_10993 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10994);
										mem_vec_10994 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10995);
										mem_vec_10995 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_10996);
										mem_vec_10996 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_10997);
										mem_vec_10997 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_10998);
										mem_vec_10998 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_10999);
										mem_vec_10999 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_11000);
										mem_vec_11000 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_11001);
										mem_vec_11001 = vec_38;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_10974);
										mem_vec_10974 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_10975);
										mem_vec_10975 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_10976);
										mem_vec_10976 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_10977);
										mem_vec_10977 = vec_46;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_10978);
										mem_vec_10978 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_10979);
										mem_vec_10979 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_10980);
										mem_vec_10980 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_10981);
										mem_vec_10981 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_10982);
										mem_vec_10982 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_10983);
										mem_vec_10983 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_10984);
										mem_vec_10984 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_10985);
										mem_vec_10985 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_10986);
										mem_vec_10986 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_10987);
										mem_vec_10987 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_10988);
										mem_vec_10988 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_10989);
										mem_vec_10989 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_10990);
										mem_vec_10990 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_10991);
										mem_vec_10991 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_10992);
										mem_vec_10992 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_10993);
										mem_vec_10993 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_10994);
										mem_vec_10994 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_10995);
										mem_vec_10995 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_10996);
										mem_vec_10996 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_10997);
										mem_vec_10997 = vec_72;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_10998);
										mem_vec_10998 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_10999);
										mem_vec_10999 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_11000);
										mem_vec_11000 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_11001);
										mem_vec_11001 = vec_77;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_10974);
										mem_vec_10974 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_10975);
										mem_vec_10975 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_10976);
										mem_vec_10976 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_10977);
										mem_vec_10977 = vec_85;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_10978);
										mem_vec_10978 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_10979);
										mem_vec_10979 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_10980);
										mem_vec_10980 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_10981);
										mem_vec_10981 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_10982);
										mem_vec_10982 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_10983);
										mem_vec_10983 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_10984);
										mem_vec_10984 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_10985);
										mem_vec_10985 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_10986);
										mem_vec_10986 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_10987);
										mem_vec_10987 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_10988);
										mem_vec_10988 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_10989);
										mem_vec_10989 = vec_101;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_10990);
										mem_vec_10990 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_10991);
										mem_vec_10991 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_10992);
										mem_vec_10992 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_10993);
										mem_vec_10993 = vec_106;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_10994);
										mem_vec_10994 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_10995);
										mem_vec_10995 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_10996);
										mem_vec_10996 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_10997);
										mem_vec_10997 = vec_111;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_10998);
										mem_vec_10998 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_10999);
										mem_vec_10999 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_11000);
										mem_vec_11000 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_11001);
										mem_vec_11001 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10974);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10975);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10976);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10977);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10978);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10979);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10980);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10981);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10982);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10983);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10984);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10985);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10986);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10987);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10988);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10989);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10990);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10991);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10992);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10993);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10994);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10995);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_10996);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_10997);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10998);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10999);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_11000);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_11001);
						}
					}
				}
			}
		}
}


}