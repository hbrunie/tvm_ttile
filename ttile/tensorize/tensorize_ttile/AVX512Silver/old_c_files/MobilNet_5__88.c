#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (3, h);
  T (28, x); T (4, c);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 2), (Arg 11))]; T (8, f);
  T (1, y)]
*/
IND_TYPE c, cp_0, c550_p_0, cp_1, c550, f, fp_0, h, hp_0, x, xp_0, y, yp_0, y482_p_0, yp_1, y482;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y483 = 0;
IND_TYPE x491 = 0;
IND_TYPE h269 = 0;
IND_TYPE w = 0;
IND_TYPE c551 = 0;
IND_TYPE f428 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3417 ,mem_vec_3418 ,mem_vec_3419 ,mem_vec_3420 ,mem_vec_3421 ,mem_vec_3422 ,mem_vec_3423 ,mem_vec_3424 ,mem_vec_3425 ,mem_vec_3426 ,mem_vec_3427 ,mem_vec_3428 ,mem_vec_3429 ,mem_vec_3430 ,mem_vec_3431 ,mem_vec_3432 ,mem_vec_3433 ,mem_vec_3434 ,mem_vec_3435 ,mem_vec_3436 ,mem_vec_3437 ,mem_vec_3438 ,mem_vec_3439 ,mem_vec_3440 ,mem_vec_3441 ,mem_vec_3442 ,mem_vec_3443 ,mem_vec_3444 ,mem_vec_3445 ,mem_vec_3446 ,mem_vec_3447 ,mem_vec_3448 ,mem_vec_3449 ,mem_vec_3450 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (y, 1) (28 / 28)
for (y482 = y483, y482_p_0 = 0;
	y482 < y483 + 28;
	y482 += 28, y482_p_0 += 28){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (f, 8) (256 / 32)
	for (f = f428, fp_0 = 0;
		f < f428 + 256;
		f += 32, fp_0 += 32){
			for (y = y482, yp_1 = y482_p_0, yp_0 = 0;
				y < y482 + 6;
				y += 6, yp_1 += 6, yp_0 += 6){
				// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
				// T (c, 4) (256 / 64)
				for (c550 = c551, c550_p_0 = 0;
					c550 < c551 + 256;
					c550 += 64, c550_p_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
					// T (x, 28) (28 / 1)
					for (x = x491, xp_0 = 0;
						x < x491 + 28;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h269, hp_0 = 0;
							h < h269 + 3;
							h += 1, hp_0 += 1){
									mem_vec_3417 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3418 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_3426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_3427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_3428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c550, cp_1 = c550_p_0, cp_0 = 0;
										c < c550 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3417);
										mem_vec_3417 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3418);
										mem_vec_3418 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3419);
										mem_vec_3419 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3420);
										mem_vec_3420 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3421);
										mem_vec_3421 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3422);
										mem_vec_3422 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3423);
										mem_vec_3423 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3424);
										mem_vec_3424 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3425);
										mem_vec_3425 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3426);
										mem_vec_3426 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3427);
										mem_vec_3427 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3428);
										mem_vec_3428 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);
										vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_3417);
										mem_vec_3417 = vec_20;

										vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_3418);
										mem_vec_3418 = vec_23;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_26 = _mm512_set1_ps(scal_7);


										vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_3419);
										mem_vec_3419 = vec_25;



										vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_3420);
										mem_vec_3420 = vec_27;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_29 = _mm512_set1_ps(scal_8);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_3421);
										mem_vec_3421 = vec_28;



										vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_3422);
										mem_vec_3422 = vec_30;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_32 = _mm512_set1_ps(scal_9);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_3423);
										mem_vec_3423 = vec_31;



										vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_3424);
										mem_vec_3424 = vec_33;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_3425);
										mem_vec_3425 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_3426);
										mem_vec_3426 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_3427);
										mem_vec_3427 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_3428);
										mem_vec_3428 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);
										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_3417);
										mem_vec_3417 = vec_40;

										vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_3418);
										mem_vec_3418 = vec_43;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_46 = _mm512_set1_ps(scal_13);


										vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_3419);
										mem_vec_3419 = vec_45;



										vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_3420);
										mem_vec_3420 = vec_47;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_49 = _mm512_set1_ps(scal_14);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_3421);
										mem_vec_3421 = vec_48;



										vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_3422);
										mem_vec_3422 = vec_50;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_52 = _mm512_set1_ps(scal_15);


										vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_3423);
										mem_vec_3423 = vec_51;



										vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_3424);
										mem_vec_3424 = vec_53;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_55 = _mm512_set1_ps(scal_16);


										vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_3425);
										mem_vec_3425 = vec_54;



										vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_3426);
										mem_vec_3426 = vec_56;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_58 = _mm512_set1_ps(scal_17);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_3427);
										mem_vec_3427 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_3428);
										mem_vec_3428 = vec_59;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3417);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3418);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3419);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3420);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3421);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3422);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3423);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3424);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3425);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3426);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3427);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3428);
						}
					}
				}
			}
			for (y = y482 + 6, yp_1 = y482_p_0, yp_0 = 0;
				y < y482 + 6 + 22;
				y += 11, yp_1 += 11, yp_0 += 11){
				// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
				// T (c, 4) (256 / 64)
				for (c550 = c551, c550_p_0 = 0;
					c550 < c551 + 256;
					c550 += 64, c550_p_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
					// T (x, 28) (28 / 1)
					for (x = x491, xp_0 = 0;
						x < x491 + 28;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h269, hp_0 = 0;
							h < h269 + 3;
							h += 1, hp_0 += 1){
									mem_vec_3429 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3430 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_3438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_3439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_3440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_3441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_3442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_3443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_3444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_3445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_3446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_3447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_3448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_3449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_3450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c550, cp_1 = c550_p_0, cp_0 = 0;
										c < c550 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3429);
										mem_vec_3429 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3430);
										mem_vec_3430 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3431);
										mem_vec_3431 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3432);
										mem_vec_3432 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3433);
										mem_vec_3433 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3434);
										mem_vec_3434 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3435);
										mem_vec_3435 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3436);
										mem_vec_3436 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3437);
										mem_vec_3437 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3438);
										mem_vec_3438 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3439);
										mem_vec_3439 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3440);
										mem_vec_3440 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3441);
										mem_vec_3441 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3442);
										mem_vec_3442 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3443);
										mem_vec_3443 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3444);
										mem_vec_3444 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3445);
										mem_vec_3445 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3446);
										mem_vec_3446 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3447);
										mem_vec_3447 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3448);
										mem_vec_3448 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3449);
										mem_vec_3449 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3450);
										mem_vec_3450 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);
										vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_3429);
										mem_vec_3429 = vec_35;

										vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_3430);
										mem_vec_3430 = vec_38;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_3431);
										mem_vec_3431 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_3432);
										mem_vec_3432 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_3433);
										mem_vec_3433 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_3434);
										mem_vec_3434 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_3435);
										mem_vec_3435 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_3436);
										mem_vec_3436 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_3437);
										mem_vec_3437 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_3438);
										mem_vec_3438 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_53 = _mm512_set1_ps(scal_16);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_3439);
										mem_vec_3439 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_3440);
										mem_vec_3440 = vec_54;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_56 = _mm512_set1_ps(scal_17);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_3441);
										mem_vec_3441 = vec_55;



										vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_3442);
										mem_vec_3442 = vec_57;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_59 = _mm512_set1_ps(scal_18);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_3443);
										mem_vec_3443 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_3444);
										mem_vec_3444 = vec_60;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
										vec_62 = _mm512_set1_ps(scal_19);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_3445);
										mem_vec_3445 = vec_61;



										vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_3446);
										mem_vec_3446 = vec_63;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
										vec_65 = _mm512_set1_ps(scal_20);


										vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_3447);
										mem_vec_3447 = vec_64;



										vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_3448);
										mem_vec_3448 = vec_66;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
										vec_68 = _mm512_set1_ps(scal_21);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_3449);
										mem_vec_3449 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_3450);
										mem_vec_3450 = vec_69;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_71 = _mm512_set1_ps(scal_22);
										vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_3429);
										mem_vec_3429 = vec_70;

										vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_3430);
										mem_vec_3430 = vec_73;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_3431);
										mem_vec_3431 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_3432);
										mem_vec_3432 = vec_77;
										scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_79 = _mm512_set1_ps(scal_24);


										vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_3433);
										mem_vec_3433 = vec_78;



										vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_3434);
										mem_vec_3434 = vec_80;
										scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_82 = _mm512_set1_ps(scal_25);


										vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_3435);
										mem_vec_3435 = vec_81;



										vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_3436);
										mem_vec_3436 = vec_83;
										scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_85 = _mm512_set1_ps(scal_26);


										vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_3437);
										mem_vec_3437 = vec_84;



										vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_3438);
										mem_vec_3438 = vec_86;
										scal_27 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_88 = _mm512_set1_ps(scal_27);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_3439);
										mem_vec_3439 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_3440);
										mem_vec_3440 = vec_89;
										scal_28 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_91 = _mm512_set1_ps(scal_28);


										vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_3441);
										mem_vec_3441 = vec_90;



										vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_3442);
										mem_vec_3442 = vec_92;
										scal_29 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_94 = _mm512_set1_ps(scal_29);


										vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_3443);
										mem_vec_3443 = vec_93;



										vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_3444);
										mem_vec_3444 = vec_95;
										scal_30 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
										vec_97 = _mm512_set1_ps(scal_30);


										vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_3445);
										mem_vec_3445 = vec_96;



										vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_3446);
										mem_vec_3446 = vec_98;
										scal_31 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
										vec_100 = _mm512_set1_ps(scal_31);


										vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_3447);
										mem_vec_3447 = vec_99;



										vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_3448);
										mem_vec_3448 = vec_101;
										scal_32 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
										vec_103 = _mm512_set1_ps(scal_32);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_3449);
										mem_vec_3449 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_3450);
										mem_vec_3450 = vec_104;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3429);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3430);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3431);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3432);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3433);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3434);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3435);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3436);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3437);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3438);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3439);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3440);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3441);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3442);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3443);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3444);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3445);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3446);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3447);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3448);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3449);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3450);
						}
					}
				}
			}
	}
}


}