#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (3, h);
  T (28, x); T (4, c); T (1, y); T (8, f);
  Lambda_apply y [((Iter 2), (Arg 8)); ((Iter 1), (Arg 12))]]
*/
IND_TYPE c, cp_0, c565_p_0, cp_1, c565, f, fp_0, h, hp_0, x, xp_0, y, yp_0, y497_p_0, yp_1, y497;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y498 = 0;
IND_TYPE x501 = 0;
IND_TYPE h279 = 0;
IND_TYPE w = 0;
IND_TYPE c566 = 0;
IND_TYPE f438 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3597 ,mem_vec_3598 ,mem_vec_3599 ,mem_vec_3600 ,mem_vec_3601 ,mem_vec_3602 ,mem_vec_3603 ,mem_vec_3604 ,mem_vec_3605 ,mem_vec_3606 ,mem_vec_3607 ,mem_vec_3608 ,mem_vec_3609 ,mem_vec_3610 ,mem_vec_3611 ,mem_vec_3612 ,mem_vec_3613 ,mem_vec_3614 ,mem_vec_3615 ,mem_vec_3616 ,mem_vec_3617 ,mem_vec_3618 ,mem_vec_3619 ,mem_vec_3620 ,mem_vec_3621 ,mem_vec_3622 ,mem_vec_3623 ,mem_vec_3624 ,mem_vec_3625 ,mem_vec_3626 ,mem_vec_3627 ,mem_vec_3628 ,mem_vec_3629 ,mem_vec_3630 ,mem_vec_3631 ,mem_vec_3632 ,mem_vec_3633 ,mem_vec_3634 ,mem_vec_3635 ,mem_vec_3636 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
	for (y497 = y498, y497_p_0 = 0;
		y497 < y498 + 16;
		y497 += 8, y497_p_0 += 8){
		// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f = f438, fp_0 = 0;
			f < f438 + 256;
			f += 32, fp_0 += 32){
			// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y497, yp_1 = y497_p_0, yp_0 = 0;
				y < y497 + 8;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
				// T (c, 4) (256 / 64)
				for (c565 = c566, c565_p_0 = 0;
					c565 < c566 + 256;
					c565 += 64, c565_p_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
					// T (x, 28) (28 / 1)
					for (x = x501, xp_0 = 0;
						x < x501 + 28;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h279, hp_0 = 0;
							h < h279 + 3;
							h += 1, hp_0 += 1){
									mem_vec_3597 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3598 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3599 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3600 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3601 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3602 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3603 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3604 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3605 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_3606 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_3607 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_3608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_3609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_3610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_3611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_3612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c565, cp_1 = c565_p_0, cp_0 = 0;
										c < c565 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3597);
										mem_vec_3597 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3598);
										mem_vec_3598 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3599);
										mem_vec_3599 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3600);
										mem_vec_3600 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3601);
										mem_vec_3601 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3602);
										mem_vec_3602 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3603);
										mem_vec_3603 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3604);
										mem_vec_3604 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3605);
										mem_vec_3605 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3606);
										mem_vec_3606 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3607);
										mem_vec_3607 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3608);
										mem_vec_3608 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3609);
										mem_vec_3609 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3610);
										mem_vec_3610 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3611);
										mem_vec_3611 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3612);
										mem_vec_3612 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);
										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_3597);
										mem_vec_3597 = vec_26;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_3598);
										mem_vec_3598 = vec_29;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_32 = _mm512_set1_ps(scal_9);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_3599);
										mem_vec_3599 = vec_31;



										vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_3600);
										mem_vec_3600 = vec_33;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_3601);
										mem_vec_3601 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_3602);
										mem_vec_3602 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_3603);
										mem_vec_3603 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_3604);
										mem_vec_3604 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_3605);
										mem_vec_3605 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_3606);
										mem_vec_3606 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_3607);
										mem_vec_3607 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_3608);
										mem_vec_3608 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_3609);
										mem_vec_3609 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_3610);
										mem_vec_3610 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_3611);
										mem_vec_3611 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_3612);
										mem_vec_3612 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_53 = _mm512_set1_ps(scal_16);
										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_3597);
										mem_vec_3597 = vec_52;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_3598);
										mem_vec_3598 = vec_55;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_58 = _mm512_set1_ps(scal_17);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_3599);
										mem_vec_3599 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_3600);
										mem_vec_3600 = vec_59;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_61 = _mm512_set1_ps(scal_18);


										vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_3601);
										mem_vec_3601 = vec_60;



										vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_3602);
										mem_vec_3602 = vec_62;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_64 = _mm512_set1_ps(scal_19);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_3603);
										mem_vec_3603 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_3604);
										mem_vec_3604 = vec_65;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_67 = _mm512_set1_ps(scal_20);


										vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_3605);
										mem_vec_3605 = vec_66;



										vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_3606);
										mem_vec_3606 = vec_68;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_70 = _mm512_set1_ps(scal_21);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_3607);
										mem_vec_3607 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_3608);
										mem_vec_3608 = vec_71;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_73 = _mm512_set1_ps(scal_22);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_3609);
										mem_vec_3609 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_3610);
										mem_vec_3610 = vec_74;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_3611);
										mem_vec_3611 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_3612);
										mem_vec_3612 = vec_77;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3597);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3598);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3599);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3600);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3601);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3602);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3603);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3604);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3605);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3606);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3607);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3608);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3609);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3610);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3611);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3612);
						}
					}
				}
			}
		}
	}
	for (y497 = y498 + 16, y497_p_0 = 0;
		y497 < y498 + 16 + 12;
		y497 += 12, y497_p_0 += 12){
		// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f = f438, fp_0 = 0;
			f < f438 + 256;
			f += 32, fp_0 += 32){
			// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y497, yp_1 = y497_p_0, yp_0 = 0;
				y < y497 + 12;
				y += 12, yp_1 += 12, yp_0 += 12){
				// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
				// T (c, 4) (256 / 64)
				for (c565 = c566, c565_p_0 = 0;
					c565 < c566 + 256;
					c565 += 64, c565_p_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
					// T (x, 28) (28 / 1)
					for (x = x501, xp_0 = 0;
						x < x501 + 28;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h279, hp_0 = 0;
							h < h279 + 3;
							h += 1, hp_0 += 1){
									mem_vec_3613 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3614 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_3622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_3623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_3624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_3625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_3626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_3627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_3628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_3629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_3630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_3631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_3632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_3633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_3634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_3635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_3636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c565, cp_1 = c565_p_0, cp_0 = 0;
										c < c565 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3613);
										mem_vec_3613 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3614);
										mem_vec_3614 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3615);
										mem_vec_3615 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3616);
										mem_vec_3616 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3617);
										mem_vec_3617 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3618);
										mem_vec_3618 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3619);
										mem_vec_3619 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3620);
										mem_vec_3620 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3621);
										mem_vec_3621 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3622);
										mem_vec_3622 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3623);
										mem_vec_3623 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3624);
										mem_vec_3624 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3625);
										mem_vec_3625 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3626);
										mem_vec_3626 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3627);
										mem_vec_3627 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3628);
										mem_vec_3628 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3629);
										mem_vec_3629 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3630);
										mem_vec_3630 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3631);
										mem_vec_3631 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3632);
										mem_vec_3632 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3633);
										mem_vec_3633 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3634);
										mem_vec_3634 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3635);
										mem_vec_3635 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3636);
										mem_vec_3636 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);
										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_3613);
										mem_vec_3613 = vec_38;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_3614);
										mem_vec_3614 = vec_41;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_3615);
										mem_vec_3615 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_3616);
										mem_vec_3616 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_40, mem_vec_3617);
										mem_vec_3617 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_42, mem_vec_3618);
										mem_vec_3618 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_3619);
										mem_vec_3619 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_42, mem_vec_3620);
										mem_vec_3620 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_53 = _mm512_set1_ps(scal_16);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_3621);
										mem_vec_3621 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_3622);
										mem_vec_3622 = vec_54;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_56 = _mm512_set1_ps(scal_17);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_3623);
										mem_vec_3623 = vec_55;



										vec_57 = _mm512_fmadd_ps(vec_56, vec_42, mem_vec_3624);
										mem_vec_3624 = vec_57;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_59 = _mm512_set1_ps(scal_18);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_3625);
										mem_vec_3625 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_3626);
										mem_vec_3626 = vec_60;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_62 = _mm512_set1_ps(scal_19);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_40, mem_vec_3627);
										mem_vec_3627 = vec_61;



										vec_63 = _mm512_fmadd_ps(vec_62, vec_42, mem_vec_3628);
										mem_vec_3628 = vec_63;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
										vec_65 = _mm512_set1_ps(scal_20);


										vec_64 = _mm512_fmadd_ps(vec_65, vec_40, mem_vec_3629);
										mem_vec_3629 = vec_64;



										vec_66 = _mm512_fmadd_ps(vec_65, vec_42, mem_vec_3630);
										mem_vec_3630 = vec_66;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
										vec_68 = _mm512_set1_ps(scal_21);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_40, mem_vec_3631);
										mem_vec_3631 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_42, mem_vec_3632);
										mem_vec_3632 = vec_69;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
										vec_71 = _mm512_set1_ps(scal_22);


										vec_70 = _mm512_fmadd_ps(vec_71, vec_40, mem_vec_3633);
										mem_vec_3633 = vec_70;



										vec_72 = _mm512_fmadd_ps(vec_71, vec_42, mem_vec_3634);
										mem_vec_3634 = vec_72;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h) + c];
										vec_74 = _mm512_set1_ps(scal_23);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_40, mem_vec_3635);
										mem_vec_3635 = vec_73;



										vec_75 = _mm512_fmadd_ps(vec_74, vec_42, mem_vec_3636);
										mem_vec_3636 = vec_75;
										scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_77 = _mm512_set1_ps(scal_24);
										vec_78 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_76 = _mm512_fmadd_ps(vec_77, vec_78, mem_vec_3613);
										mem_vec_3613 = vec_76;

										vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_79 = _mm512_fmadd_ps(vec_77, vec_80, mem_vec_3614);
										mem_vec_3614 = vec_79;
										scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_82 = _mm512_set1_ps(scal_25);


										vec_81 = _mm512_fmadd_ps(vec_82, vec_78, mem_vec_3615);
										mem_vec_3615 = vec_81;



										vec_83 = _mm512_fmadd_ps(vec_82, vec_80, mem_vec_3616);
										mem_vec_3616 = vec_83;
										scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_85 = _mm512_set1_ps(scal_26);


										vec_84 = _mm512_fmadd_ps(vec_85, vec_78, mem_vec_3617);
										mem_vec_3617 = vec_84;



										vec_86 = _mm512_fmadd_ps(vec_85, vec_80, mem_vec_3618);
										mem_vec_3618 = vec_86;
										scal_27 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_88 = _mm512_set1_ps(scal_27);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_3619);
										mem_vec_3619 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_3620);
										mem_vec_3620 = vec_89;
										scal_28 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_91 = _mm512_set1_ps(scal_28);


										vec_90 = _mm512_fmadd_ps(vec_91, vec_78, mem_vec_3621);
										mem_vec_3621 = vec_90;



										vec_92 = _mm512_fmadd_ps(vec_91, vec_80, mem_vec_3622);
										mem_vec_3622 = vec_92;
										scal_29 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_94 = _mm512_set1_ps(scal_29);


										vec_93 = _mm512_fmadd_ps(vec_94, vec_78, mem_vec_3623);
										mem_vec_3623 = vec_93;



										vec_95 = _mm512_fmadd_ps(vec_94, vec_80, mem_vec_3624);
										mem_vec_3624 = vec_95;
										scal_30 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_97 = _mm512_set1_ps(scal_30);


										vec_96 = _mm512_fmadd_ps(vec_97, vec_78, mem_vec_3625);
										mem_vec_3625 = vec_96;



										vec_98 = _mm512_fmadd_ps(vec_97, vec_80, mem_vec_3626);
										mem_vec_3626 = vec_98;
										scal_31 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_100 = _mm512_set1_ps(scal_31);


										vec_99 = _mm512_fmadd_ps(vec_100, vec_78, mem_vec_3627);
										mem_vec_3627 = vec_99;



										vec_101 = _mm512_fmadd_ps(vec_100, vec_80, mem_vec_3628);
										mem_vec_3628 = vec_101;
										scal_32 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
										vec_103 = _mm512_set1_ps(scal_32);


										vec_102 = _mm512_fmadd_ps(vec_103, vec_78, mem_vec_3629);
										mem_vec_3629 = vec_102;



										vec_104 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_3630);
										mem_vec_3630 = vec_104;
										scal_33 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
										vec_106 = _mm512_set1_ps(scal_33);


										vec_105 = _mm512_fmadd_ps(vec_106, vec_78, mem_vec_3631);
										mem_vec_3631 = vec_105;



										vec_107 = _mm512_fmadd_ps(vec_106, vec_80, mem_vec_3632);
										mem_vec_3632 = vec_107;
										scal_34 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
										vec_109 = _mm512_set1_ps(scal_34);


										vec_108 = _mm512_fmadd_ps(vec_109, vec_78, mem_vec_3633);
										mem_vec_3633 = vec_108;



										vec_110 = _mm512_fmadd_ps(vec_109, vec_80, mem_vec_3634);
										mem_vec_3634 = vec_110;
										scal_35 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h) + c];
										vec_112 = _mm512_set1_ps(scal_35);


										vec_111 = _mm512_fmadd_ps(vec_112, vec_78, mem_vec_3635);
										mem_vec_3635 = vec_111;



										vec_113 = _mm512_fmadd_ps(vec_112, vec_80, mem_vec_3636);
										mem_vec_3636 = vec_113;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3613);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3614);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3615);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3616);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3617);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3618);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3619);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3620);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3621);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3622);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3623);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3624);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3625);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3626);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3627);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3628);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3629);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3630);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3631);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3632);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3633);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3634);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3635);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3636);
						}
					}
				}
			}
		}
	}


}