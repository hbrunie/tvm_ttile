#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (4, c); T (56, x);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (8, c)]
*/
IND_TYPE c, cp_0, c1368_p_0, c1369_p_0, cp_1, c1368_p_1, cp_2, c1368, c1369, h, hp_0, x, xp_0, x1418_p_0, xp_1, x1418, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y796 = 0;
IND_TYPE x1419 = 0;
IND_TYPE h634 = 0;
IND_TYPE w = 0;
IND_TYPE c1370 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14374 ,mem_vec_14375 ,mem_vec_14376 ,mem_vec_14377 ,mem_vec_14378 ,mem_vec_14379 ,mem_vec_14380 ,mem_vec_14381 ,mem_vec_14382 ,mem_vec_14383 ,mem_vec_14384 ,mem_vec_14385 ,mem_vec_14386 ,mem_vec_14387 ,mem_vec_14388 ,mem_vec_14389 ,mem_vec_14390 ,mem_vec_14391 ,mem_vec_14392 ,mem_vec_14393 ,mem_vec_14394 ,mem_vec_14395 ,mem_vec_14396 ,mem_vec_14397 ,mem_vec_14398 ,mem_vec_14399 ,mem_vec_14400 ,mem_vec_14401 ,mem_vec_14402 ,mem_vec_14403 ,mem_vec_14404 ,mem_vec_14405 ,mem_vec_14406 ,mem_vec_14407 ,mem_vec_14408 ,mem_vec_14409 ,mem_vec_14410 ,mem_vec_14411 ,mem_vec_14412 ,mem_vec_14413 ,mem_vec_14414 ,mem_vec_14415 ,mem_vec_14416 ,mem_vec_14417 ,mem_vec_14418 ,mem_vec_14419 ,mem_vec_14420 ,mem_vec_14421 ,mem_vec_14422 ,mem_vec_14423 ,mem_vec_14424 ,mem_vec_14425 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 8) (64 / 8)
for (c1369 = c1370, c1369_p_0 = 0;
	c1369 < c1370 + 64;
	c1369 += 8, c1369_p_0 += 8){
		for (y = y796, yp_0 = 0;
			y < y796 + 42;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 56, h = 3, w = 3, c = 8, f = 64
			// T (x, 56) (56 / 1)
			for (x1418 = x1419, x1418_p_0 = 0;
				x1418 < x1419 + 56;
				x1418 += 1, x1418_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 64
				// T (c, 4) (8 / 2)
				for (c1368 = c1369, c1368_p_1 = c1369_p_0, c1368_p_0 = 0;
					c1368 < c1369 + 8;
					c1368 += 2, c1368_p_1 += 2, c1368_p_0 += 2){
					// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 64
					// T (h, 3) (3 / 1)
					for (h = h634, hp_0 = 0;
						h < h634 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1418, xp_1 = x1418_p_0, xp_0 = 0;
							x < x1418 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14374 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14375 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14376 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_14377 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_14378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_14381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_14382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_14385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_14386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_14389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_14390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_14393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_14394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_14397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1368, cp_2 = c1368_p_1, cp_1 = c1368_p_0, cp_0 = 0;
										c < c1368 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14374);
										mem_vec_14374 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14375);
										mem_vec_14375 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14376);
										mem_vec_14376 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14377);
										mem_vec_14377 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14378);
										mem_vec_14378 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14379);
										mem_vec_14379 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14380);
										mem_vec_14380 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14381);
										mem_vec_14381 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14382);
										mem_vec_14382 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14383);
										mem_vec_14383 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14384);
										mem_vec_14384 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14385);
										mem_vec_14385 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14386);
										mem_vec_14386 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14387);
										mem_vec_14387 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14388);
										mem_vec_14388 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14389);
										mem_vec_14389 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14390);
										mem_vec_14390 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14391);
										mem_vec_14391 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14392);
										mem_vec_14392 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14393);
										mem_vec_14393 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14394);
										mem_vec_14394 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14395);
										mem_vec_14395 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14396);
										mem_vec_14396 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14397);
										mem_vec_14397 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_14374);
										mem_vec_14374 = vec_34;

										vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_14375);
										mem_vec_14375 = vec_37;

										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_14376);
										mem_vec_14376 = vec_39;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_14377);
										mem_vec_14377 = vec_41;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_14378);
										mem_vec_14378 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_14379);
										mem_vec_14379 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_14380);
										mem_vec_14380 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_14381);
										mem_vec_14381 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_14382);
										mem_vec_14382 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_14383);
										mem_vec_14383 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_14384);
										mem_vec_14384 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_14385);
										mem_vec_14385 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_14386);
										mem_vec_14386 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_14387);
										mem_vec_14387 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_14388);
										mem_vec_14388 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_14389);
										mem_vec_14389 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_14390);
										mem_vec_14390 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_14391);
										mem_vec_14391 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_14392);
										mem_vec_14392 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_14393);
										mem_vec_14393 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_14394);
										mem_vec_14394 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_14395);
										mem_vec_14395 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_14396);
										mem_vec_14396 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_14397);
										mem_vec_14397 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_69 = _mm512_set1_ps(scal_12);
										vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_14374);
										mem_vec_14374 = vec_68;

										vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_14375);
										mem_vec_14375 = vec_71;

										vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_14376);
										mem_vec_14376 = vec_73;

										vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_14377);
										mem_vec_14377 = vec_75;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_78 = _mm512_set1_ps(scal_13);


										vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_14378);
										mem_vec_14378 = vec_77;



										vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_14379);
										mem_vec_14379 = vec_79;



										vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_14380);
										mem_vec_14380 = vec_80;



										vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_14381);
										mem_vec_14381 = vec_81;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_83 = _mm512_set1_ps(scal_14);


										vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_14382);
										mem_vec_14382 = vec_82;



										vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_14383);
										mem_vec_14383 = vec_84;



										vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_14384);
										mem_vec_14384 = vec_85;



										vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_14385);
										mem_vec_14385 = vec_86;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_14386);
										mem_vec_14386 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_14387);
										mem_vec_14387 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_14388);
										mem_vec_14388 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_14389);
										mem_vec_14389 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_14390);
										mem_vec_14390 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_14391);
										mem_vec_14391 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_14392);
										mem_vec_14392 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_14393);
										mem_vec_14393 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_14394);
										mem_vec_14394 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_14395);
										mem_vec_14395 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_14396);
										mem_vec_14396 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_14397);
										mem_vec_14397 = vec_101;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14374);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14375);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14376);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14377);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14378);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14379);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14380);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14381);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14382);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14383);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14384);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14385);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14386);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14387);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14388);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14389);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14390);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14391);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14392);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14393);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14394);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14395);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_14396);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_14397);
						}
					}
				}
			}
		}
		for (y = y796 + 42, yp_0 = 0;
			y < y796 + 42 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 8, f = 64
			// T (x, 56) (56 / 1)
			for (x1418 = x1419, x1418_p_0 = 0;
				x1418 < x1419 + 56;
				x1418 += 1, x1418_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 64
				// T (c, 4) (8 / 2)
				for (c1368 = c1369, c1368_p_1 = c1369_p_0, c1368_p_0 = 0;
					c1368 < c1369 + 8;
					c1368 += 2, c1368_p_1 += 2, c1368_p_0 += 2){
					// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 64
					// T (h, 3) (3 / 1)
					for (h = h634, hp_0 = 0;
						h < h634 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1418, xp_1 = x1418_p_0, xp_0 = 0;
							x < x1418 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14398 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14399 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14400 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_14401 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_14402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_14405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_14406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_14409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_14410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_14413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_14414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_14417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_14418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_14421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_14422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_14423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_14424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_14425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1368, cp_2 = c1368_p_1, cp_1 = c1368_p_0, cp_0 = 0;
										c < c1368 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14398);
										mem_vec_14398 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14399);
										mem_vec_14399 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14400);
										mem_vec_14400 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14401);
										mem_vec_14401 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14402);
										mem_vec_14402 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14403);
										mem_vec_14403 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14404);
										mem_vec_14404 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14405);
										mem_vec_14405 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14406);
										mem_vec_14406 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14407);
										mem_vec_14407 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14408);
										mem_vec_14408 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14409);
										mem_vec_14409 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14410);
										mem_vec_14410 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14411);
										mem_vec_14411 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14412);
										mem_vec_14412 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14413);
										mem_vec_14413 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14414);
										mem_vec_14414 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14415);
										mem_vec_14415 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14416);
										mem_vec_14416 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14417);
										mem_vec_14417 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14418);
										mem_vec_14418 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14419);
										mem_vec_14419 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14420);
										mem_vec_14420 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14421);
										mem_vec_14421 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_14422);
										mem_vec_14422 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_14423);
										mem_vec_14423 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_14424);
										mem_vec_14424 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_14425);
										mem_vec_14425 = vec_38;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_14398);
										mem_vec_14398 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_14399);
										mem_vec_14399 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_14400);
										mem_vec_14400 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_14401);
										mem_vec_14401 = vec_46;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_14402);
										mem_vec_14402 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_14403);
										mem_vec_14403 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_14404);
										mem_vec_14404 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_14405);
										mem_vec_14405 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_14406);
										mem_vec_14406 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_14407);
										mem_vec_14407 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_14408);
										mem_vec_14408 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_14409);
										mem_vec_14409 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_14410);
										mem_vec_14410 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_14411);
										mem_vec_14411 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_14412);
										mem_vec_14412 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_14413);
										mem_vec_14413 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_14414);
										mem_vec_14414 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_14415);
										mem_vec_14415 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_14416);
										mem_vec_14416 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_14417);
										mem_vec_14417 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_14418);
										mem_vec_14418 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_14419);
										mem_vec_14419 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_14420);
										mem_vec_14420 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_14421);
										mem_vec_14421 = vec_72;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_14422);
										mem_vec_14422 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_14423);
										mem_vec_14423 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_14424);
										mem_vec_14424 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_14425);
										mem_vec_14425 = vec_77;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_14398);
										mem_vec_14398 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_14399);
										mem_vec_14399 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_14400);
										mem_vec_14400 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_14401);
										mem_vec_14401 = vec_85;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_14402);
										mem_vec_14402 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_14403);
										mem_vec_14403 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_14404);
										mem_vec_14404 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_14405);
										mem_vec_14405 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_14406);
										mem_vec_14406 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_14407);
										mem_vec_14407 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_14408);
										mem_vec_14408 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_14409);
										mem_vec_14409 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_14410);
										mem_vec_14410 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_14411);
										mem_vec_14411 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_14412);
										mem_vec_14412 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_14413);
										mem_vec_14413 = vec_101;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_14414);
										mem_vec_14414 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_14415);
										mem_vec_14415 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_14416);
										mem_vec_14416 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_14417);
										mem_vec_14417 = vec_106;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_14418);
										mem_vec_14418 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_14419);
										mem_vec_14419 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_14420);
										mem_vec_14420 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_14421);
										mem_vec_14421 = vec_111;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_14422);
										mem_vec_14422 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_14423);
										mem_vec_14423 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_14424);
										mem_vec_14424 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_14425);
										mem_vec_14425 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14398);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14399);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14400);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14401);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14402);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14403);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14404);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14405);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14406);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14407);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14408);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14409);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14410);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14411);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14412);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14413);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14414);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14415);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14416);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14417);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14418);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14419);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_14420);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_14421);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14422);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14423);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_14424);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_14425);
						}
					}
				}
			}
		}
}


}