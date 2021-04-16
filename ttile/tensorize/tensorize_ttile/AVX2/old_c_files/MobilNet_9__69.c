#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); U (3, w); T (16, c); Hoist_vars [c]; T (3, h);
  T (7, x); T (1, y); T (1, f); T (8, c); T (32, f); T (8, c)]
*/
IND_TYPE c, cp_0, c480_p_0, c481_p_0, cp_1, c480_p_1, cp_2, c480, c481, f, fp_0, f360_p_0, fp_1, f360, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y240 = 0;
IND_TYPE x240 = 0;
IND_TYPE h179 = 0;
IND_TYPE w = 0;
IND_TYPE c482 = 0;
IND_TYPE f361 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3360 ,mem_vec_3361 ,mem_vec_3362 ,mem_vec_3363 ,mem_vec_3364 ,mem_vec_3365 ,mem_vec_3366 ,mem_vec_3367 ,mem_vec_3368 ,mem_vec_3369 ,mem_vec_3370 ,mem_vec_3371 ,mem_vec_3372 ,mem_vec_3373 ,mem_vec_3374 ,mem_vec_3375 ,mem_vec_3376 ,mem_vec_3377 ,mem_vec_3378 ,mem_vec_3379 ,mem_vec_3380 ,mem_vec_3381 ,mem_vec_3382 ,mem_vec_3383 ,mem_vec_3384 ,mem_vec_3385 ,mem_vec_3386 ,mem_vec_3387 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 8) (1024 / 128)
for (c481 = c482, c481_p_0 = 0;
	c481 < c482 + 1024;
	c481 += 128, c481_p_0 += 128){
	// y = 7, x = 7, h = 3, w = 3, c = 128, f = 1024
	// T (f, 32) (1024 / 32)
	for (f360 = f361, f360_p_0 = 0;
		f360 < f361 + 1024;
		f360 += 32, f360_p_0 += 32){
		// y = 7, x = 7, h = 3, w = 3, c = 128, f = 32
		// T (c, 8) (128 / 16)
		for (c480 = c481, c480_p_1 = c481_p_0, c480_p_0 = 0;
			c480 < c481 + 128;
			c480 += 16, c480_p_1 += 16, c480_p_0 += 16){
			// y = 7, x = 7, h = 3, w = 3, c = 16, f = 32
			// T (f, 1) (32 / 32)
			for (f = f360, fp_1 = f360_p_0, fp_0 = 0;
				f < f360 + 32;
				f += 32, fp_1 += 32, fp_0 += 32){
				// y = 7, x = 7, h = 3, w = 3, c = 16, f = 32
				// T (y, 1) (7 / 7)
				for (y = y240, yp_0 = 0;
					y < y240 + 7;
					y += 7, yp_0 += 7){
					// y = 7, x = 7, h = 3, w = 3, c = 16, f = 32
					// T (x, 7) (7 / 1)
					for (x = x240, xp_0 = 0;
						x < x240 + 7;
						x += 1, xp_0 += 1){
						// y = 7, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h179, hp_0 = 0;
							h < h179 + 3;
							h += 1, hp_0 += 1){
									mem_vec_3360 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3361 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_3362 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3363 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_3364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_3366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_3368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_3370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_3372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_3374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_3376 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_3377 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_3378 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_3379 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									mem_vec_3380 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_3381 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
									mem_vec_3382 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_3383 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
									mem_vec_3384 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_3385 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
									mem_vec_3386 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_3387 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
									// y = 7, x = 1, h = 1, w = 3, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c480, cp_2 = c480_p_1, cp_1 = c480_p_0, cp_0 = 0;
										c < c480 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3360);
										mem_vec_3360 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3361);
										mem_vec_3361 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3362);
										mem_vec_3362 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3363);
										mem_vec_3363 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3364);
										mem_vec_3364 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3365);
										mem_vec_3365 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3366);
										mem_vec_3366 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3367);
										mem_vec_3367 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3368);
										mem_vec_3368 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3369);
										mem_vec_3369 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3370);
										mem_vec_3370 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3371);
										mem_vec_3371 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3372);
										mem_vec_3372 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3373);
										mem_vec_3373 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3374);
										mem_vec_3374 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3375);
										mem_vec_3375 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_3376);
										mem_vec_3376 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_3377);
										mem_vec_3377 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_3378);
										mem_vec_3378 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_3379);
										mem_vec_3379 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm256_set1_ps(scal_5);


										vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_3380);
										mem_vec_3380 = vec_29;



										vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_3381);
										mem_vec_3381 = vec_31;



										vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_3382);
										mem_vec_3382 = vec_32;



										vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_3383);
										mem_vec_3383 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm256_set1_ps(scal_6);


										vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_3384);
										mem_vec_3384 = vec_34;



										vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_3385);
										mem_vec_3385 = vec_36;



										vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_3386);
										mem_vec_3386 = vec_37;



										vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_3387);
										mem_vec_3387 = vec_38;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_40 = _mm256_set1_ps(scal_7);
										vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_3360);
										mem_vec_3360 = vec_39;

										vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

										vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_3361);
										mem_vec_3361 = vec_42;

										vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_3362);
										mem_vec_3362 = vec_44;

										vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

										vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_3363);
										mem_vec_3363 = vec_46;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_49 = _mm256_set1_ps(scal_8);


										vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_3364);
										mem_vec_3364 = vec_48;



										vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_3365);
										mem_vec_3365 = vec_50;



										vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_3366);
										mem_vec_3366 = vec_51;



										vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_3367);
										mem_vec_3367 = vec_52;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_54 = _mm256_set1_ps(scal_9);


										vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_3368);
										mem_vec_3368 = vec_53;



										vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_3369);
										mem_vec_3369 = vec_55;



										vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_3370);
										mem_vec_3370 = vec_56;



										vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_3371);
										mem_vec_3371 = vec_57;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_59 = _mm256_set1_ps(scal_10);


										vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_3372);
										mem_vec_3372 = vec_58;



										vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_3373);
										mem_vec_3373 = vec_60;



										vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_3374);
										mem_vec_3374 = vec_61;



										vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_3375);
										mem_vec_3375 = vec_62;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_64 = _mm256_set1_ps(scal_11);


										vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_3376);
										mem_vec_3376 = vec_63;



										vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_3377);
										mem_vec_3377 = vec_65;



										vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_3378);
										mem_vec_3378 = vec_66;



										vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_3379);
										mem_vec_3379 = vec_67;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_69 = _mm256_set1_ps(scal_12);


										vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_3380);
										mem_vec_3380 = vec_68;



										vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_3381);
										mem_vec_3381 = vec_70;



										vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_3382);
										mem_vec_3382 = vec_71;



										vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_3383);
										mem_vec_3383 = vec_72;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_74 = _mm256_set1_ps(scal_13);


										vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_3384);
										mem_vec_3384 = vec_73;



										vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_3385);
										mem_vec_3385 = vec_75;



										vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_3386);
										mem_vec_3386 = vec_76;



										vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_3387);
										mem_vec_3387 = vec_77;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_79 = _mm256_set1_ps(scal_14);
										vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_3360);
										mem_vec_3360 = vec_78;

										vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

										vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_3361);
										mem_vec_3361 = vec_81;

										vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_3362);
										mem_vec_3362 = vec_83;

										vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

										vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_3363);
										mem_vec_3363 = vec_85;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_88 = _mm256_set1_ps(scal_15);


										vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_3364);
										mem_vec_3364 = vec_87;



										vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_3365);
										mem_vec_3365 = vec_89;



										vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_3366);
										mem_vec_3366 = vec_90;



										vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_3367);
										mem_vec_3367 = vec_91;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_93 = _mm256_set1_ps(scal_16);


										vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_3368);
										mem_vec_3368 = vec_92;



										vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_3369);
										mem_vec_3369 = vec_94;



										vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_3370);
										mem_vec_3370 = vec_95;



										vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_3371);
										mem_vec_3371 = vec_96;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_98 = _mm256_set1_ps(scal_17);


										vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_3372);
										mem_vec_3372 = vec_97;



										vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_3373);
										mem_vec_3373 = vec_99;



										vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_3374);
										mem_vec_3374 = vec_100;



										vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_3375);
										mem_vec_3375 = vec_101;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_103 = _mm256_set1_ps(scal_18);


										vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_3376);
										mem_vec_3376 = vec_102;



										vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_3377);
										mem_vec_3377 = vec_104;



										vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_3378);
										mem_vec_3378 = vec_105;



										vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_3379);
										mem_vec_3379 = vec_106;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_108 = _mm256_set1_ps(scal_19);


										vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_3380);
										mem_vec_3380 = vec_107;



										vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_3381);
										mem_vec_3381 = vec_109;



										vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_3382);
										mem_vec_3382 = vec_110;



										vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_3383);
										mem_vec_3383 = vec_111;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_113 = _mm256_set1_ps(scal_20);


										vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_3384);
										mem_vec_3384 = vec_112;



										vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_3385);
										mem_vec_3385 = vec_114;



										vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_3386);
										mem_vec_3386 = vec_115;



										vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_3387);
										mem_vec_3387 = vec_116;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3360);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3361);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3362);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3363);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3364);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3365);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3366);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3367);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3368);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3369);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3370);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3371);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3372);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3373);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3374);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3375);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3376);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3377);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3378);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_3379);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3380);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3381);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3382);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_3383);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3384);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3385);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3386);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_3387);
						}
					}
				}
			}
		}
	}
}


}