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
  Lambda_apply y [((Iter 2), (Arg 8)); ((Iter 1), (Arg 12))]; T (8, f);
  T (1, y)]
*/
IND_TYPE c, cp_0, c562_p_0, cp_1, c562, f, fp_0, h, hp_0, x, xp_0, y, yp_0, y494_p_0, yp_1, y494;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y495 = 0;
IND_TYPE x499 = 0;
IND_TYPE h277 = 0;
IND_TYPE w = 0;
IND_TYPE c563 = 0;
IND_TYPE f436 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3557 ,mem_vec_3558 ,mem_vec_3559 ,mem_vec_3560 ,mem_vec_3561 ,mem_vec_3562 ,mem_vec_3563 ,mem_vec_3564 ,mem_vec_3565 ,mem_vec_3566 ,mem_vec_3567 ,mem_vec_3568 ,mem_vec_3569 ,mem_vec_3570 ,mem_vec_3571 ,mem_vec_3572 ,mem_vec_3573 ,mem_vec_3574 ,mem_vec_3575 ,mem_vec_3576 ,mem_vec_3577 ,mem_vec_3578 ,mem_vec_3579 ,mem_vec_3580 ,mem_vec_3581 ,mem_vec_3582 ,mem_vec_3583 ,mem_vec_3584 ,mem_vec_3585 ,mem_vec_3586 ,mem_vec_3587 ,mem_vec_3588 ,mem_vec_3589 ,mem_vec_3590 ,mem_vec_3591 ,mem_vec_3592 ,mem_vec_3593 ,mem_vec_3594 ,mem_vec_3595 ,mem_vec_3596 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (y, 1) (28 / 28)
for (y494 = y495, y494_p_0 = 0;
	y494 < y495 + 28;
	y494 += 28, y494_p_0 += 28){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (f, 8) (256 / 32)
	for (f = f436, fp_0 = 0;
		f < f436 + 256;
		f += 32, fp_0 += 32){
			for (y = y494, yp_1 = y494_p_0, yp_0 = 0;
				y < y494 + 16;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
				// T (c, 4) (256 / 64)
				for (c562 = c563, c562_p_0 = 0;
					c562 < c563 + 256;
					c562 += 64, c562_p_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
					// T (x, 28) (28 / 1)
					for (x = x499, xp_0 = 0;
						x < x499 + 28;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h277, hp_0 = 0;
							h < h277 + 3;
							h += 1, hp_0 += 1){
									mem_vec_3557 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3558 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_3566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_3567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_3568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_3569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_3570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_3571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_3572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c562, cp_1 = c562_p_0, cp_0 = 0;
										c < c562 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3557);
										mem_vec_3557 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3558);
										mem_vec_3558 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3559);
										mem_vec_3559 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3560);
										mem_vec_3560 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3561);
										mem_vec_3561 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3562);
										mem_vec_3562 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3563);
										mem_vec_3563 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3564);
										mem_vec_3564 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3565);
										mem_vec_3565 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3566);
										mem_vec_3566 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3567);
										mem_vec_3567 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3568);
										mem_vec_3568 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3569);
										mem_vec_3569 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3570);
										mem_vec_3570 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3571);
										mem_vec_3571 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3572);
										mem_vec_3572 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);
										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_3557);
										mem_vec_3557 = vec_26;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_3558);
										mem_vec_3558 = vec_29;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_32 = _mm512_set1_ps(scal_9);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_3559);
										mem_vec_3559 = vec_31;



										vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_3560);
										mem_vec_3560 = vec_33;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_3561);
										mem_vec_3561 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_3562);
										mem_vec_3562 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_3563);
										mem_vec_3563 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_3564);
										mem_vec_3564 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_3565);
										mem_vec_3565 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_3566);
										mem_vec_3566 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_3567);
										mem_vec_3567 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_3568);
										mem_vec_3568 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_3569);
										mem_vec_3569 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_3570);
										mem_vec_3570 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_3571);
										mem_vec_3571 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_3572);
										mem_vec_3572 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_53 = _mm512_set1_ps(scal_16);
										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_3557);
										mem_vec_3557 = vec_52;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_3558);
										mem_vec_3558 = vec_55;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_58 = _mm512_set1_ps(scal_17);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_3559);
										mem_vec_3559 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_3560);
										mem_vec_3560 = vec_59;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_61 = _mm512_set1_ps(scal_18);


										vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_3561);
										mem_vec_3561 = vec_60;



										vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_3562);
										mem_vec_3562 = vec_62;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_64 = _mm512_set1_ps(scal_19);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_3563);
										mem_vec_3563 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_3564);
										mem_vec_3564 = vec_65;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_67 = _mm512_set1_ps(scal_20);


										vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_3565);
										mem_vec_3565 = vec_66;



										vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_3566);
										mem_vec_3566 = vec_68;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_70 = _mm512_set1_ps(scal_21);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_3567);
										mem_vec_3567 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_3568);
										mem_vec_3568 = vec_71;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_73 = _mm512_set1_ps(scal_22);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_3569);
										mem_vec_3569 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_3570);
										mem_vec_3570 = vec_74;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_3571);
										mem_vec_3571 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_3572);
										mem_vec_3572 = vec_77;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3557);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3558);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3559);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3560);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3561);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3562);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3563);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3564);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3565);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3566);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3567);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3568);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3569);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3570);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3571);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3572);
						}
					}
				}
			}
			for (y = y494 + 16, yp_1 = y494_p_0, yp_0 = 0;
				y < y494 + 16 + 12;
				y += 12, yp_1 += 12, yp_0 += 12){
				// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
				// T (c, 4) (256 / 64)
				for (c562 = c563, c562_p_0 = 0;
					c562 < c563 + 256;
					c562 += 64, c562_p_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
					// T (x, 28) (28 / 1)
					for (x = x499, xp_0 = 0;
						x < x499 + 28;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h277, hp_0 = 0;
							h < h277 + 3;
							h += 1, hp_0 += 1){
									mem_vec_3573 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3574 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_3582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_3583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_3584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_3585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_3586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_3587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_3588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_3589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_3590 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_3591 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_3592 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_3593 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_3594 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_3595 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_3596 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c562, cp_1 = c562_p_0, cp_0 = 0;
										c < c562 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3573);
										mem_vec_3573 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3574);
										mem_vec_3574 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3575);
										mem_vec_3575 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3576);
										mem_vec_3576 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3577);
										mem_vec_3577 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3578);
										mem_vec_3578 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3579);
										mem_vec_3579 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3580);
										mem_vec_3580 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3581);
										mem_vec_3581 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3582);
										mem_vec_3582 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3583);
										mem_vec_3583 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3584);
										mem_vec_3584 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3585);
										mem_vec_3585 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3586);
										mem_vec_3586 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3587);
										mem_vec_3587 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3588);
										mem_vec_3588 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3589);
										mem_vec_3589 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3590);
										mem_vec_3590 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3591);
										mem_vec_3591 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3592);
										mem_vec_3592 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3593);
										mem_vec_3593 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3594);
										mem_vec_3594 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3595);
										mem_vec_3595 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3596);
										mem_vec_3596 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);
										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_3573);
										mem_vec_3573 = vec_38;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_3574);
										mem_vec_3574 = vec_41;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_3575);
										mem_vec_3575 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_3576);
										mem_vec_3576 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_40, mem_vec_3577);
										mem_vec_3577 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_42, mem_vec_3578);
										mem_vec_3578 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_3579);
										mem_vec_3579 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_42, mem_vec_3580);
										mem_vec_3580 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_53 = _mm512_set1_ps(scal_16);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_3581);
										mem_vec_3581 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_3582);
										mem_vec_3582 = vec_54;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_56 = _mm512_set1_ps(scal_17);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_3583);
										mem_vec_3583 = vec_55;



										vec_57 = _mm512_fmadd_ps(vec_56, vec_42, mem_vec_3584);
										mem_vec_3584 = vec_57;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_59 = _mm512_set1_ps(scal_18);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_3585);
										mem_vec_3585 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_3586);
										mem_vec_3586 = vec_60;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_62 = _mm512_set1_ps(scal_19);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_40, mem_vec_3587);
										mem_vec_3587 = vec_61;



										vec_63 = _mm512_fmadd_ps(vec_62, vec_42, mem_vec_3588);
										mem_vec_3588 = vec_63;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
										vec_65 = _mm512_set1_ps(scal_20);


										vec_64 = _mm512_fmadd_ps(vec_65, vec_40, mem_vec_3589);
										mem_vec_3589 = vec_64;



										vec_66 = _mm512_fmadd_ps(vec_65, vec_42, mem_vec_3590);
										mem_vec_3590 = vec_66;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
										vec_68 = _mm512_set1_ps(scal_21);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_40, mem_vec_3591);
										mem_vec_3591 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_42, mem_vec_3592);
										mem_vec_3592 = vec_69;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
										vec_71 = _mm512_set1_ps(scal_22);


										vec_70 = _mm512_fmadd_ps(vec_71, vec_40, mem_vec_3593);
										mem_vec_3593 = vec_70;



										vec_72 = _mm512_fmadd_ps(vec_71, vec_42, mem_vec_3594);
										mem_vec_3594 = vec_72;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h) + c];
										vec_74 = _mm512_set1_ps(scal_23);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_40, mem_vec_3595);
										mem_vec_3595 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_42, mem_vec_3596);
										mem_vec_3596 = vec_75;
										scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_77 = _mm512_set1_ps(scal_24);
										vec_78 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_76 = _mm512_fmadd_ps(vec_77, vec_78, mem_vec_3573);
										mem_vec_3573 = vec_76;

										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_79 = _mm512_fmadd_ps(vec_77, vec_80, mem_vec_3574);
										mem_vec_3574 = vec_79;
										scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_82 = _mm512_set1_ps(scal_25);


										vec_81 = _mm512_fmadd_ps(vec_82, vec_78, mem_vec_3575);
										mem_vec_3575 = vec_81;



										vec_83 = _mm512_fmadd_ps(vec_82, vec_80, mem_vec_3576);
										mem_vec_3576 = vec_83;
										scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_85 = _mm512_set1_ps(scal_26);


										vec_84 = _mm512_fmadd_ps(vec_85, vec_78, mem_vec_3577);
										mem_vec_3577 = vec_84;



										vec_86 = _mm512_fmadd_ps(vec_85, vec_80, mem_vec_3578);
										mem_vec_3578 = vec_86;
										scal_27 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_88 = _mm512_set1_ps(scal_27);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_3579);
										mem_vec_3579 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_3580);
										mem_vec_3580 = vec_89;
										scal_28 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_91 = _mm512_set1_ps(scal_28);


										vec_90 = _mm512_fmadd_ps(vec_91, vec_78, mem_vec_3581);
										mem_vec_3581 = vec_90;



										vec_92 = _mm512_fmadd_ps(vec_91, vec_80, mem_vec_3582);
										mem_vec_3582 = vec_92;
										scal_29 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_94 = _mm512_set1_ps(scal_29);


										vec_93 = _mm512_fmadd_ps(vec_94, vec_78, mem_vec_3583);
										mem_vec_3583 = vec_93;



										vec_95 = _mm512_fmadd_ps(vec_94, vec_80, mem_vec_3584);
										mem_vec_3584 = vec_95;
										scal_30 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_97 = _mm512_set1_ps(scal_30);


										vec_96 = _mm512_fmadd_ps(vec_97, vec_78, mem_vec_3585);
										mem_vec_3585 = vec_96;



										vec_98 = _mm512_fmadd_ps(vec_97, vec_80, mem_vec_3586);
										mem_vec_3586 = vec_98;
										scal_31 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_100 = _mm512_set1_ps(scal_31);


										vec_99 = _mm512_fmadd_ps(vec_100, vec_78, mem_vec_3587);
										mem_vec_3587 = vec_99;



										vec_101 = _mm512_fmadd_ps(vec_100, vec_80, mem_vec_3588);
										mem_vec_3588 = vec_101;
										scal_32 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
										vec_103 = _mm512_set1_ps(scal_32);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_78, mem_vec_3589);
										mem_vec_3589 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_3590);
										mem_vec_3590 = vec_104;
										scal_33 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
										vec_106 = _mm512_set1_ps(scal_33);


										vec_105 = _mm512_fmadd_ps(vec_106, vec_78, mem_vec_3591);
										mem_vec_3591 = vec_105;



										vec_107 = _mm512_fmadd_ps(vec_106, vec_80, mem_vec_3592);
										mem_vec_3592 = vec_107;
										scal_34 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
										vec_109 = _mm512_set1_ps(scal_34);


										vec_108 = _mm512_fmadd_ps(vec_109, vec_78, mem_vec_3593);
										mem_vec_3593 = vec_108;



										vec_110 = _mm512_fmadd_ps(vec_109, vec_80, mem_vec_3594);
										mem_vec_3594 = vec_110;
										scal_35 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h) + c];
										vec_112 = _mm512_set1_ps(scal_35);


										vec_111 = _mm512_fmadd_ps(vec_112, vec_78, mem_vec_3595);
										mem_vec_3595 = vec_111;



										vec_113 = _mm512_fmadd_ps(vec_112, vec_80, mem_vec_3596);
										mem_vec_3596 = vec_113;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3573);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3574);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3575);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3576);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3577);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3578);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3579);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3580);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3581);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3582);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3583);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3584);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3585);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3586);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3587);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3588);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3589);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3590);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3591);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3592);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3593);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3594);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3595);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3596);
						}
					}
				}
			}
	}
}


}