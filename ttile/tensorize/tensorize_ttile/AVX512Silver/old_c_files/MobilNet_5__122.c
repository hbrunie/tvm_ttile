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
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]]
*/
IND_TYPE c, cp_0, c571_p_0, cp_1, c571, f, fp_0, h, hp_0, x, xp_0, y, yp_0, y503_p_0, yp_1, y503;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y504 = 0;
IND_TYPE x505 = 0;
IND_TYPE h283 = 0;
IND_TYPE w = 0;
IND_TYPE c572 = 0;
IND_TYPE f442 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3675 ,mem_vec_3676 ,mem_vec_3677 ,mem_vec_3678 ,mem_vec_3679 ,mem_vec_3680 ,mem_vec_3681 ,mem_vec_3682 ,mem_vec_3683 ,mem_vec_3684 ,mem_vec_3685 ,mem_vec_3686 ,mem_vec_3687 ,mem_vec_3688 ,mem_vec_3689 ,mem_vec_3690 ,mem_vec_3691 ,mem_vec_3692 ,mem_vec_3693 ,mem_vec_3694 ,mem_vec_3695 ,mem_vec_3696 ,mem_vec_3697 ,mem_vec_3698 ,mem_vec_3699 ,mem_vec_3700 ,mem_vec_3701 ,mem_vec_3702 ,mem_vec_3703 ,mem_vec_3704 ,mem_vec_3705 ,mem_vec_3706 ,mem_vec_3707 ,mem_vec_3708 ,mem_vec_3709 ,mem_vec_3710 ,mem_vec_3711 ,mem_vec_3712 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
	for (y503 = y504, y503_p_0 = 0;
		y503 < y504 + 18;
		y503 += 9, y503_p_0 += 9){
		// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f = f442, fp_0 = 0;
			f < f442 + 256;
			f += 32, fp_0 += 32){
			// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y503, yp_1 = y503_p_0, yp_0 = 0;
				y < y503 + 9;
				y += 9, yp_1 += 9, yp_0 += 9){
				// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
				// T (c, 4) (256 / 64)
				for (c571 = c572, c571_p_0 = 0;
					c571 < c572 + 256;
					c571 += 64, c571_p_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
					// T (x, 28) (28 / 1)
					for (x = x505, xp_0 = 0;
						x < x505 + 28;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h283, hp_0 = 0;
							h < h283 + 3;
							h += 1, hp_0 += 1){
									mem_vec_3675 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3676 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_3684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_3685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_3686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_3687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_3688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_3689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_3690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_3691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_3692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c571, cp_1 = c571_p_0, cp_0 = 0;
										c < c571 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3675);
										mem_vec_3675 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3676);
										mem_vec_3676 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3677);
										mem_vec_3677 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3678);
										mem_vec_3678 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3679);
										mem_vec_3679 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3680);
										mem_vec_3680 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3681);
										mem_vec_3681 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3682);
										mem_vec_3682 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3683);
										mem_vec_3683 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3684);
										mem_vec_3684 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3685);
										mem_vec_3685 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3686);
										mem_vec_3686 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3687);
										mem_vec_3687 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3688);
										mem_vec_3688 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3689);
										mem_vec_3689 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3690);
										mem_vec_3690 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3691);
										mem_vec_3691 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3692);
										mem_vec_3692 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);
										vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_3675);
										mem_vec_3675 = vec_29;

										vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_3676);
										mem_vec_3676 = vec_32;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_3677);
										mem_vec_3677 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_3678);
										mem_vec_3678 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_3679);
										mem_vec_3679 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_3680);
										mem_vec_3680 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_3681);
										mem_vec_3681 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_3682);
										mem_vec_3682 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_3683);
										mem_vec_3683 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_3684);
										mem_vec_3684 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_3685);
										mem_vec_3685 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_3686);
										mem_vec_3686 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_3687);
										mem_vec_3687 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_3688);
										mem_vec_3688 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_53 = _mm512_set1_ps(scal_16);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_3689);
										mem_vec_3689 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_3690);
										mem_vec_3690 = vec_54;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
										vec_56 = _mm512_set1_ps(scal_17);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_3691);
										mem_vec_3691 = vec_55;



										vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_3692);
										mem_vec_3692 = vec_57;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_59 = _mm512_set1_ps(scal_18);
										vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_3675);
										mem_vec_3675 = vec_58;

										vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_3676);
										mem_vec_3676 = vec_61;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_64 = _mm512_set1_ps(scal_19);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_3677);
										mem_vec_3677 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_3678);
										mem_vec_3678 = vec_65;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_67 = _mm512_set1_ps(scal_20);


										vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_3679);
										mem_vec_3679 = vec_66;



										vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_3680);
										mem_vec_3680 = vec_68;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_70 = _mm512_set1_ps(scal_21);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_3681);
										mem_vec_3681 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_3682);
										mem_vec_3682 = vec_71;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_73 = _mm512_set1_ps(scal_22);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_3683);
										mem_vec_3683 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_3684);
										mem_vec_3684 = vec_74;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_3685);
										mem_vec_3685 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_3686);
										mem_vec_3686 = vec_77;
										scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_79 = _mm512_set1_ps(scal_24);


										vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_3687);
										mem_vec_3687 = vec_78;



										vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_3688);
										mem_vec_3688 = vec_80;
										scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_82 = _mm512_set1_ps(scal_25);


										vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_3689);
										mem_vec_3689 = vec_81;



										vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_3690);
										mem_vec_3690 = vec_83;
										scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
										vec_85 = _mm512_set1_ps(scal_26);


										vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_3691);
										mem_vec_3691 = vec_84;



										vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_3692);
										mem_vec_3692 = vec_86;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3675);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3676);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3677);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3678);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3679);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3680);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3681);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3682);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3683);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3684);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3685);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3686);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3687);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3688);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3689);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3690);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3691);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3692);
						}
					}
				}
			}
		}
	}
	for (y503 = y504 + 18, y503_p_0 = 0;
		y503 < y504 + 18 + 10;
		y503 += 10, y503_p_0 += 10){
		// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f = f442, fp_0 = 0;
			f < f442 + 256;
			f += 32, fp_0 += 32){
			// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y503, yp_1 = y503_p_0, yp_0 = 0;
				y < y503 + 10;
				y += 10, yp_1 += 10, yp_0 += 10){
				// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
				// T (c, 4) (256 / 64)
				for (c571 = c572, c571_p_0 = 0;
					c571 < c572 + 256;
					c571 += 64, c571_p_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
					// T (x, 28) (28 / 1)
					for (x = x505, xp_0 = 0;
						x < x505 + 28;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h283, hp_0 = 0;
							h < h283 + 3;
							h += 1, hp_0 += 1){
									mem_vec_3693 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3694 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_3702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_3703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_3704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_3705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_3706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_3707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_3708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_3709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_3710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_3711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_3712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c571, cp_1 = c571_p_0, cp_0 = 0;
										c < c571 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3693);
										mem_vec_3693 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3694);
										mem_vec_3694 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3695);
										mem_vec_3695 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3696);
										mem_vec_3696 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3697);
										mem_vec_3697 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3698);
										mem_vec_3698 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3699);
										mem_vec_3699 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3700);
										mem_vec_3700 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3701);
										mem_vec_3701 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3702);
										mem_vec_3702 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3703);
										mem_vec_3703 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3704);
										mem_vec_3704 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3705);
										mem_vec_3705 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3706);
										mem_vec_3706 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3707);
										mem_vec_3707 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3708);
										mem_vec_3708 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3709);
										mem_vec_3709 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3710);
										mem_vec_3710 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3711);
										mem_vec_3711 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3712);
										mem_vec_3712 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);
										vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_3693);
										mem_vec_3693 = vec_32;

										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_3694);
										mem_vec_3694 = vec_35;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_3695);
										mem_vec_3695 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_3696);
										mem_vec_3696 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_3697);
										mem_vec_3697 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_3698);
										mem_vec_3698 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_3699);
										mem_vec_3699 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_3700);
										mem_vec_3700 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_3701);
										mem_vec_3701 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_3702);
										mem_vec_3702 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_3703);
										mem_vec_3703 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_3704);
										mem_vec_3704 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_53 = _mm512_set1_ps(scal_16);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_3705);
										mem_vec_3705 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_3706);
										mem_vec_3706 = vec_54;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_56 = _mm512_set1_ps(scal_17);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_3707);
										mem_vec_3707 = vec_55;



										vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_3708);
										mem_vec_3708 = vec_57;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
										vec_59 = _mm512_set1_ps(scal_18);


										vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_3709);
										mem_vec_3709 = vec_58;



										vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_3710);
										mem_vec_3710 = vec_60;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
										vec_62 = _mm512_set1_ps(scal_19);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_3711);
										mem_vec_3711 = vec_61;



										vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_3712);
										mem_vec_3712 = vec_63;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_65 = _mm512_set1_ps(scal_20);
										vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_3693);
										mem_vec_3693 = vec_64;

										vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_3694);
										mem_vec_3694 = vec_67;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_70 = _mm512_set1_ps(scal_21);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_3695);
										mem_vec_3695 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_3696);
										mem_vec_3696 = vec_71;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_73 = _mm512_set1_ps(scal_22);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_3697);
										mem_vec_3697 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_3698);
										mem_vec_3698 = vec_74;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_3699);
										mem_vec_3699 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_3700);
										mem_vec_3700 = vec_77;
										scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_79 = _mm512_set1_ps(scal_24);


										vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_3701);
										mem_vec_3701 = vec_78;



										vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_3702);
										mem_vec_3702 = vec_80;
										scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_82 = _mm512_set1_ps(scal_25);


										vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_3703);
										mem_vec_3703 = vec_81;



										vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_3704);
										mem_vec_3704 = vec_83;
										scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_85 = _mm512_set1_ps(scal_26);


										vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_3705);
										mem_vec_3705 = vec_84;



										vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_3706);
										mem_vec_3706 = vec_86;
										scal_27 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_88 = _mm512_set1_ps(scal_27);


										vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_3707);
										mem_vec_3707 = vec_87;



										vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_3708);
										mem_vec_3708 = vec_89;
										scal_28 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
										vec_91 = _mm512_set1_ps(scal_28);


										vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_3709);
										mem_vec_3709 = vec_90;



										vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_3710);
										mem_vec_3710 = vec_92;
										scal_29 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
										vec_94 = _mm512_set1_ps(scal_29);


										vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_3711);
										mem_vec_3711 = vec_93;



										vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_3712);
										mem_vec_3712 = vec_95;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3693);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3694);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3695);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3696);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3697);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3698);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3699);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3700);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3701);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3702);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3703);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3704);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3705);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3706);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3707);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3708);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3709);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3710);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3711);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3712);
						}
					}
				}
			}
		}
	}


}