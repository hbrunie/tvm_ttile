#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); U (4, y); U (3, w); T (16, c); Hoist_vars [c]; T (3, h);
  T (28, x); T (2, c); T (7, y); T (1, f); T (8, c); T (4, f)]
*/
IND_TYPE c, cp_0, c98_p_0, c99_p_0, cp_1, c98_p_1, cp_2, c98, c99, f, fp_0, f97_p_0, fp_1, f97, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y52 = 0;
IND_TYPE x50 = 0;
IND_TYPE h38 = 0;
IND_TYPE w = 0;
IND_TYPE c100 = 0;
IND_TYPE f98 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_508 ,mem_vec_509 ,mem_vec_510 ,mem_vec_511 ,mem_vec_512 ,mem_vec_513 ,mem_vec_514 ,mem_vec_515 ,mem_vec_516 ,mem_vec_517 ,mem_vec_518 ,mem_vec_519 ,mem_vec_520 ,mem_vec_521 ,mem_vec_522 ,mem_vec_523 ,mem_vec_524 ,mem_vec_525 ,mem_vec_526 ,mem_vec_527 ,mem_vec_528 ,mem_vec_529 ,mem_vec_530 ,mem_vec_531 ,mem_vec_532 ,mem_vec_533 ,mem_vec_534 ,mem_vec_535 ,mem_vec_536 ,mem_vec_537 ,mem_vec_538 ,mem_vec_539 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 4) (256 / 64)
for (f97 = f98, f97_p_0 = 0;
	f97 < f98 + 256;
	f97 += 64, f97_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 64
	// T (c, 8) (256 / 32)
	for (c99 = c100, c99_p_0 = 0;
		c99 < c100 + 256;
		c99 += 32, c99_p_0 += 32){
		// y = 28, x = 28, h = 3, w = 3, c = 32, f = 64
		// T (f, 1) (64 / 64)
		for (f = f97, fp_1 = f97_p_0, fp_0 = 0;
			f < f97 + 64;
			f += 64, fp_1 += 64, fp_0 += 64){
			// y = 28, x = 28, h = 3, w = 3, c = 32, f = 64
			// T (y, 7) (28 / 4)
			for (y = y52, yp_0 = 0;
				y < y52 + 28;
				y += 4, yp_0 += 4){
				// y = 4, x = 28, h = 3, w = 3, c = 32, f = 64
				// T (c, 2) (32 / 16)
				for (c98 = c99, c98_p_1 = c99_p_0, c98_p_0 = 0;
					c98 < c99 + 32;
					c98 += 16, c98_p_1 += 16, c98_p_0 += 16){
					// y = 4, x = 28, h = 3, w = 3, c = 16, f = 64
					// T (x, 28) (28 / 1)
					for (x = x50, xp_0 = 0;
						x < x50 + 28;
						x += 1, xp_0 += 1){
						// y = 4, x = 1, h = 3, w = 3, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h38, hp_0 = 0;
							h < h38 + 3;
							h += 1, hp_0 += 1){
									mem_vec_508 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_509 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_510 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_511 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_512 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_513 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
									mem_vec_514 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_515 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
									mem_vec_516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_520 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_521 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
									mem_vec_522 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_523 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
									mem_vec_524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_528 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_529 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
									mem_vec_530 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_531 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
									mem_vec_532 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_533 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_534 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_535 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_536 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_537 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
									mem_vec_538 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_539 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
									// y = 4, x = 1, h = 1, w = 3, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c98, cp_2 = c98_p_1, cp_1 = c98_p_0, cp_0 = 0;
										c < c98 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_508);
										mem_vec_508 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_509);
										mem_vec_509 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_510);
										mem_vec_510 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_511);
										mem_vec_511 = vec_7;

										vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_512);
										mem_vec_512 = vec_9;

										vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

										vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_513);
										mem_vec_513 = vec_11;

										vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_514);
										mem_vec_514 = vec_13;

										vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

										vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_515);
										mem_vec_515 = vec_15;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_18 = _mm256_set1_ps(scal_1);


										vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_516);
										mem_vec_516 = vec_17;



										vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_517);
										mem_vec_517 = vec_19;



										vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_518);
										mem_vec_518 = vec_20;



										vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_519);
										mem_vec_519 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_520);
										mem_vec_520 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_521);
										mem_vec_521 = vec_23;



										vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_522);
										mem_vec_522 = vec_24;



										vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_523);
										mem_vec_523 = vec_25;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_27 = _mm256_set1_ps(scal_2);


										vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_524);
										mem_vec_524 = vec_26;



										vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_525);
										mem_vec_525 = vec_28;



										vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_526);
										mem_vec_526 = vec_29;



										vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_527);
										mem_vec_527 = vec_30;



										vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_528);
										mem_vec_528 = vec_31;



										vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_529);
										mem_vec_529 = vec_32;



										vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_530);
										mem_vec_530 = vec_33;



										vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_531);
										mem_vec_531 = vec_34;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_36 = _mm256_set1_ps(scal_3);


										vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_532);
										mem_vec_532 = vec_35;



										vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_533);
										mem_vec_533 = vec_37;



										vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_534);
										mem_vec_534 = vec_38;



										vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_535);
										mem_vec_535 = vec_39;



										vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_536);
										mem_vec_536 = vec_40;



										vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_537);
										mem_vec_537 = vec_41;



										vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_538);
										mem_vec_538 = vec_42;



										vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_539);
										mem_vec_539 = vec_43;
										scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_45 = _mm256_set1_ps(scal_4);
										vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_508);
										mem_vec_508 = vec_44;

										vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

										vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_509);
										mem_vec_509 = vec_47;

										vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_510);
										mem_vec_510 = vec_49;

										vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

										vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_511);
										mem_vec_511 = vec_51;

										vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_512);
										mem_vec_512 = vec_53;

										vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

										vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_513);
										mem_vec_513 = vec_55;

										vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_514);
										mem_vec_514 = vec_57;

										vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

										vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_515);
										mem_vec_515 = vec_59;
										scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_62 = _mm256_set1_ps(scal_5);


										vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_516);
										mem_vec_516 = vec_61;



										vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_517);
										mem_vec_517 = vec_63;



										vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_518);
										mem_vec_518 = vec_64;



										vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_519);
										mem_vec_519 = vec_65;



										vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_520);
										mem_vec_520 = vec_66;



										vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_521);
										mem_vec_521 = vec_67;



										vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_522);
										mem_vec_522 = vec_68;



										vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_523);
										mem_vec_523 = vec_69;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_71 = _mm256_set1_ps(scal_6);


										vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_524);
										mem_vec_524 = vec_70;



										vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_525);
										mem_vec_525 = vec_72;



										vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_526);
										mem_vec_526 = vec_73;



										vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_527);
										mem_vec_527 = vec_74;



										vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_528);
										mem_vec_528 = vec_75;



										vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_529);
										mem_vec_529 = vec_76;



										vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_530);
										mem_vec_530 = vec_77;



										vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_531);
										mem_vec_531 = vec_78;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_80 = _mm256_set1_ps(scal_7);


										vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_532);
										mem_vec_532 = vec_79;



										vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_533);
										mem_vec_533 = vec_81;



										vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_534);
										mem_vec_534 = vec_82;



										vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_535);
										mem_vec_535 = vec_83;



										vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_536);
										mem_vec_536 = vec_84;



										vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_537);
										mem_vec_537 = vec_85;



										vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_538);
										mem_vec_538 = vec_86;



										vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_539);
										mem_vec_539 = vec_87;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_89 = _mm256_set1_ps(scal_8);
										vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_508);
										mem_vec_508 = vec_88;

										vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

										vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_509);
										mem_vec_509 = vec_91;

										vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_510);
										mem_vec_510 = vec_93;

										vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

										vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_511);
										mem_vec_511 = vec_95;

										vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_512);
										mem_vec_512 = vec_97;

										vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

										vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_513);
										mem_vec_513 = vec_99;

										vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_514);
										mem_vec_514 = vec_101;

										vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

										vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_515);
										mem_vec_515 = vec_103;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_106 = _mm256_set1_ps(scal_9);


										vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_516);
										mem_vec_516 = vec_105;



										vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_517);
										mem_vec_517 = vec_107;



										vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_518);
										mem_vec_518 = vec_108;



										vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_519);
										mem_vec_519 = vec_109;



										vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_520);
										mem_vec_520 = vec_110;



										vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_521);
										mem_vec_521 = vec_111;



										vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_522);
										mem_vec_522 = vec_112;



										vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_523);
										mem_vec_523 = vec_113;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_115 = _mm256_set1_ps(scal_10);


										vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_524);
										mem_vec_524 = vec_114;



										vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_525);
										mem_vec_525 = vec_116;



										vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_526);
										mem_vec_526 = vec_117;



										vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_527);
										mem_vec_527 = vec_118;



										vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_528);
										mem_vec_528 = vec_119;



										vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_529);
										mem_vec_529 = vec_120;



										vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_530);
										mem_vec_530 = vec_121;



										vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_531);
										mem_vec_531 = vec_122;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_124 = _mm256_set1_ps(scal_11);


										vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_532);
										mem_vec_532 = vec_123;



										vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_533);
										mem_vec_533 = vec_125;



										vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_534);
										mem_vec_534 = vec_126;



										vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_535);
										mem_vec_535 = vec_127;



										vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_536);
										mem_vec_536 = vec_128;



										vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_537);
										mem_vec_537 = vec_129;



										vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_538);
										mem_vec_538 = vec_130;



										vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_539);
										mem_vec_539 = vec_131;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_508);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_509);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_510);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_511);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_512);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_513);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_514);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_515);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_516);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_517);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_518);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_519);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_520);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_521);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_522);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_523);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_524);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_525);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_526);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_527);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_528);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_529);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_530);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_531);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_532);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_533);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_534);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_535);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_536);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_537);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_538);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_539);
						}
					}
				}
			}
		}
	}
}


}