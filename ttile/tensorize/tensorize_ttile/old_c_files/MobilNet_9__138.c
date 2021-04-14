#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); U (3, h); T (4, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (256, c); T (4, f); T (1, y); T (1, c); T (4, f)]
*/
IND_TYPE c, cp_0, c640_p_0, c641_p_0, cp_1, c640_p_1, cp_2, c640, c641, f, fp_0, f480_p_0, fp_1, f480, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y320 = 0;
IND_TYPE x320 = 0;
IND_TYPE h = 0;
IND_TYPE w320 = 0;
IND_TYPE c642 = 0;
IND_TYPE f481 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4480 ,mem_vec_4481 ,mem_vec_4482 ,mem_vec_4483 ,mem_vec_4484 ,mem_vec_4485 ,mem_vec_4486 ,mem_vec_4487 ,mem_vec_4488 ,mem_vec_4489 ,mem_vec_4490 ,mem_vec_4491 ,mem_vec_4492 ,mem_vec_4493 ,mem_vec_4494 ,mem_vec_4495 ,mem_vec_4496 ,mem_vec_4497 ,mem_vec_4498 ,mem_vec_4499 ,mem_vec_4500 ,mem_vec_4501 ,mem_vec_4502 ,mem_vec_4503 ,mem_vec_4504 ,mem_vec_4505 ,mem_vec_4506 ,mem_vec_4507 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (f, 4) (1024 / 256)
for (f480 = f481, f480_p_0 = 0;
	f480 < f481 + 1024;
	f480 += 256, f480_p_0 += 256){
	// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 256
	// T (c, 1) (1024 / 1024)
	for (c641 = c642, c641_p_0 = 0;
		c641 < c642 + 1024;
		c641 += 1024, c641_p_0 += 1024){
		// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 256
		// T (y, 1) (7 / 7)
		for (y = y320, yp_0 = 0;
			y < y320 + 7;
			y += 7, yp_0 += 7){
			// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 256
			// T (f, 4) (256 / 64)
			for (f = f480, fp_1 = f480_p_0, fp_0 = 0;
				f < f480 + 256;
				f += 64, fp_1 += 64, fp_0 += 64){
				// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 64
				// T (c, 256) (1024 / 4)
				for (c640 = c641, c640_p_1 = c641_p_0, c640_p_0 = 0;
					c640 < c641 + 1024;
					c640 += 4, c640_p_1 += 4, c640_p_0 += 4){
					// y = 7, x = 7, h = 3, w = 3, c = 4, f = 64
					// T (w, 3) (3 / 1)
					for (w = w320, wp_0 = 0;
						w < w320 + 3;
						w += 1, wp_0 += 1){
						// y = 7, x = 7, h = 3, w = 1, c = 4, f = 64
						// T (x, 7) (7 / 1)
						for (x = x320, xp_0 = 0;
							x < x320 + 7;
							x += 1, xp_0 += 1){
									mem_vec_4480 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4481 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4482 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_4483 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_4484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_4487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_4488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_4491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_4492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_4493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_4494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_4495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_4496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_4497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_4498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_4499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_4500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_4501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_4502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_4503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_4504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_4505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_4506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_4507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = 7, x = 1, h = 3, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c640, cp_2 = c640_p_1, cp_1 = c640_p_0, cp_0 = 0;
										c < c640 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4480);
										mem_vec_4480 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4481);
										mem_vec_4481 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4482);
										mem_vec_4482 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4483);
										mem_vec_4483 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4484);
										mem_vec_4484 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4485);
										mem_vec_4485 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4486);
										mem_vec_4486 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4487);
										mem_vec_4487 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4488);
										mem_vec_4488 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4489);
										mem_vec_4489 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4490);
										mem_vec_4490 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4491);
										mem_vec_4491 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4492);
										mem_vec_4492 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4493);
										mem_vec_4493 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4494);
										mem_vec_4494 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4495);
										mem_vec_4495 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_4496);
										mem_vec_4496 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_4497);
										mem_vec_4497 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_4498);
										mem_vec_4498 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_4499);
										mem_vec_4499 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4500);
										mem_vec_4500 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4501);
										mem_vec_4501 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_4502);
										mem_vec_4502 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_4503);
										mem_vec_4503 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_4504);
										mem_vec_4504 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_4505);
										mem_vec_4505 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_4506);
										mem_vec_4506 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_4507);
										mem_vec_4507 = vec_38;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_40 = _mm512_set1_ps(scal_7);
										vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_4480);
										mem_vec_4480 = vec_39;

										vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_4481);
										mem_vec_4481 = vec_42;

										vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_4482);
										mem_vec_4482 = vec_44;

										vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_4483);
										mem_vec_4483 = vec_46;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_8);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_4484);
										mem_vec_4484 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_4485);
										mem_vec_4485 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_4486);
										mem_vec_4486 = vec_51;



										vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_4487);
										mem_vec_4487 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_54 = _mm512_set1_ps(scal_9);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_4488);
										mem_vec_4488 = vec_53;



										vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_4489);
										mem_vec_4489 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_4490);
										mem_vec_4490 = vec_56;



										vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_4491);
										mem_vec_4491 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_59 = _mm512_set1_ps(scal_10);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_4492);
										mem_vec_4492 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_4493);
										mem_vec_4493 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_4494);
										mem_vec_4494 = vec_61;



										vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_4495);
										mem_vec_4495 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_64 = _mm512_set1_ps(scal_11);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_4496);
										mem_vec_4496 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_4497);
										mem_vec_4497 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_4498);
										mem_vec_4498 = vec_66;



										vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_4499);
										mem_vec_4499 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_69 = _mm512_set1_ps(scal_12);


										vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_4500);
										mem_vec_4500 = vec_68;



										vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_4501);
										mem_vec_4501 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_4502);
										mem_vec_4502 = vec_71;



										vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_4503);
										mem_vec_4503 = vec_72;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_74 = _mm512_set1_ps(scal_13);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_4504);
										mem_vec_4504 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_4505);
										mem_vec_4505 = vec_75;



										vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_4506);
										mem_vec_4506 = vec_76;



										vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_4507);
										mem_vec_4507 = vec_77;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_79 = _mm512_set1_ps(scal_14);
										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_4480);
										mem_vec_4480 = vec_78;

										vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_4481);
										mem_vec_4481 = vec_81;

										vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_4482);
										mem_vec_4482 = vec_83;

										vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_4483);
										mem_vec_4483 = vec_85;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_88 = _mm512_set1_ps(scal_15);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_4484);
										mem_vec_4484 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_4485);
										mem_vec_4485 = vec_89;



										vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_4486);
										mem_vec_4486 = vec_90;



										vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_4487);
										mem_vec_4487 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_93 = _mm512_set1_ps(scal_16);


										vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_4488);
										mem_vec_4488 = vec_92;



										vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_4489);
										mem_vec_4489 = vec_94;



										vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_4490);
										mem_vec_4490 = vec_95;



										vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_4491);
										mem_vec_4491 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_98 = _mm512_set1_ps(scal_17);


										vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_4492);
										mem_vec_4492 = vec_97;



										vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_4493);
										mem_vec_4493 = vec_99;



										vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_4494);
										mem_vec_4494 = vec_100;



										vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_4495);
										mem_vec_4495 = vec_101;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_103 = _mm512_set1_ps(scal_18);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_4496);
										mem_vec_4496 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_4497);
										mem_vec_4497 = vec_104;



										vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_4498);
										mem_vec_4498 = vec_105;



										vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_4499);
										mem_vec_4499 = vec_106;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_108 = _mm512_set1_ps(scal_19);


										vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_4500);
										mem_vec_4500 = vec_107;



										vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_4501);
										mem_vec_4501 = vec_109;



										vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_4502);
										mem_vec_4502 = vec_110;



										vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_4503);
										mem_vec_4503 = vec_111;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_113 = _mm512_set1_ps(scal_20);


										vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_4504);
										mem_vec_4504 = vec_112;



										vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_4505);
										mem_vec_4505 = vec_114;



										vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_4506);
										mem_vec_4506 = vec_115;



										vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_4507);
										mem_vec_4507 = vec_116;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4480);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4481);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4482);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4483);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4484);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4485);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4486);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4487);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4488);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4489);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4490);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4491);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4492);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4493);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4494);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4495);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4496);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4497);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_4498);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_4499);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4500);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4501);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_4502);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_4503);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4504);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4505);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_4506);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_4507);
						}
					}
				}
			}
		}
	}
}


}