#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); U (3, w); T (64, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (1, c); T (4, x); T (8, y); T (1, x)]
*/
IND_TYPE c, cp_0, c357_p_0, cp_1, c357, h, hp_0, x, xp_0, x450_p_0, x451_p_0, xp_1, x450_p_1, xp_2, x450, x451, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y251 = 0;
IND_TYPE x452 = 0;
IND_TYPE h207 = 0;
IND_TYPE w = 0;
IND_TYPE c358 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3632 ,mem_vec_3633 ,mem_vec_3634 ,mem_vec_3635 ,mem_vec_3636 ,mem_vec_3637 ,mem_vec_3638 ,mem_vec_3639 ,mem_vec_3640 ,mem_vec_3641 ,mem_vec_3642 ,mem_vec_3643 ,mem_vec_3644 ,mem_vec_3645 ,mem_vec_3646 ,mem_vec_3647 ,mem_vec_3648 ,mem_vec_3649 ,mem_vec_3650 ,mem_vec_3651 ,mem_vec_3652 ,mem_vec_3653 ,mem_vec_3654 ,mem_vec_3655 ,mem_vec_3656 ,mem_vec_3657 ,mem_vec_3658 ,mem_vec_3659 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 1) (56 / 56)
for (x451 = x452, x451_p_0 = 0;
	x451 < x452 + 56;
	x451 += 56, x451_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (y, 8) (56 / 7)
	for (y = y251, yp_0 = 0;
		y < y251 + 56;
		y += 7, yp_0 += 7){
		// y = 7, x = 56, h = 3, w = 3, c = 64, f = 64
		// T (x, 4) (56 / 14)
		for (x450 = x451, x450_p_1 = x451_p_0, x450_p_0 = 0;
			x450 < x451 + 56;
			x450 += 14, x450_p_1 += 14, x450_p_0 += 14){
			// y = 7, x = 14, h = 3, w = 3, c = 64, f = 64
			// T (c, 1) (64 / 64)
			for (c357 = c358, c357_p_0 = 0;
				c357 < c358 + 64;
				c357 += 64, c357_p_0 += 64){
				// y = 7, x = 14, h = 3, w = 3, c = 64, f = 64
				// T (h, 3) (3 / 1)
				for (h = h207, hp_0 = 0;
					h < h207 + 3;
					h += 1, hp_0 += 1){
					// y = 7, x = 14, h = 1, w = 3, c = 64, f = 64
					// T (x, 14) (14 / 1)
					for (x = x450, xp_2 = x450_p_1, xp_1 = x450_p_0, xp_0 = 0;
						x < x450 + 14;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_3632 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_3633 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_3634 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_3635 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_3636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_3637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_3638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_3639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_3640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_3641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_3642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_3643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_3644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_3645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_3646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_3647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_3648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_3649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_3650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_3651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_3652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_3653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_3654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_3655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								mem_vec_3656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_3657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_3658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
								mem_vec_3659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
								// y = 7, x = 1, h = 1, w = 3, c = 64, f = 64
								// T (c, 64) (64 / 1)
								for (c = c357, cp_1 = c357_p_0, cp_0 = 0;
									c < c357 + 64;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3632);
									mem_vec_3632 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3633);
									mem_vec_3633 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3634);
									mem_vec_3634 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3635);
									mem_vec_3635 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3636);
									mem_vec_3636 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3637);
									mem_vec_3637 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3638);
									mem_vec_3638 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3639);
									mem_vec_3639 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3640);
									mem_vec_3640 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3641);
									mem_vec_3641 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3642);
									mem_vec_3642 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3643);
									mem_vec_3643 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3644);
									mem_vec_3644 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3645);
									mem_vec_3645 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3646);
									mem_vec_3646 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3647);
									mem_vec_3647 = vec_23;
									scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3648);
									mem_vec_3648 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3649);
									mem_vec_3649 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3650);
									mem_vec_3650 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3651);
									mem_vec_3651 = vec_28;
									scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3652);
									mem_vec_3652 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3653);
									mem_vec_3653 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_3654);
									mem_vec_3654 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_3655);
									mem_vec_3655 = vec_33;
									scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
									vec_35 = _mm512_set1_ps(scal_6);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_3656);
									mem_vec_3656 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_3657);
									mem_vec_3657 = vec_36;



									vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_3658);
									mem_vec_3658 = vec_37;



									vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_3659);
									mem_vec_3659 = vec_38;
									scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
									vec_40 = _mm512_set1_ps(scal_7);
									vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

									vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_3632);
									mem_vec_3632 = vec_39;

									vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

									vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_3633);
									mem_vec_3633 = vec_42;

									vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

									vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_3634);
									mem_vec_3634 = vec_44;

									vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

									vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_3635);
									mem_vec_3635 = vec_46;
									scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
									vec_49 = _mm512_set1_ps(scal_8);


									vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_3636);
									mem_vec_3636 = vec_48;



									vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_3637);
									mem_vec_3637 = vec_50;



									vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_3638);
									mem_vec_3638 = vec_51;



									vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_3639);
									mem_vec_3639 = vec_52;
									scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
									vec_54 = _mm512_set1_ps(scal_9);


									vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_3640);
									mem_vec_3640 = vec_53;



									vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_3641);
									mem_vec_3641 = vec_55;



									vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_3642);
									mem_vec_3642 = vec_56;



									vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_3643);
									mem_vec_3643 = vec_57;
									scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
									vec_59 = _mm512_set1_ps(scal_10);


									vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_3644);
									mem_vec_3644 = vec_58;



									vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_3645);
									mem_vec_3645 = vec_60;



									vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_3646);
									mem_vec_3646 = vec_61;



									vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_3647);
									mem_vec_3647 = vec_62;
									scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
									vec_64 = _mm512_set1_ps(scal_11);


									vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_3648);
									mem_vec_3648 = vec_63;



									vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_3649);
									mem_vec_3649 = vec_65;



									vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_3650);
									mem_vec_3650 = vec_66;



									vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_3651);
									mem_vec_3651 = vec_67;
									scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
									vec_69 = _mm512_set1_ps(scal_12);


									vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_3652);
									mem_vec_3652 = vec_68;



									vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_3653);
									mem_vec_3653 = vec_70;



									vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_3654);
									mem_vec_3654 = vec_71;



									vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_3655);
									mem_vec_3655 = vec_72;
									scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
									vec_74 = _mm512_set1_ps(scal_13);


									vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_3656);
									mem_vec_3656 = vec_73;



									vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_3657);
									mem_vec_3657 = vec_75;



									vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_3658);
									mem_vec_3658 = vec_76;



									vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_3659);
									mem_vec_3659 = vec_77;
									scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
									vec_79 = _mm512_set1_ps(scal_14);
									vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

									vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_3632);
									mem_vec_3632 = vec_78;

									vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

									vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_3633);
									mem_vec_3633 = vec_81;

									vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

									vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_3634);
									mem_vec_3634 = vec_83;

									vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

									vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_3635);
									mem_vec_3635 = vec_85;
									scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
									vec_88 = _mm512_set1_ps(scal_15);


									vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_3636);
									mem_vec_3636 = vec_87;



									vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_3637);
									mem_vec_3637 = vec_89;



									vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_3638);
									mem_vec_3638 = vec_90;



									vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_3639);
									mem_vec_3639 = vec_91;
									scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
									vec_93 = _mm512_set1_ps(scal_16);


									vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_3640);
									mem_vec_3640 = vec_92;



									vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_3641);
									mem_vec_3641 = vec_94;



									vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_3642);
									mem_vec_3642 = vec_95;



									vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_3643);
									mem_vec_3643 = vec_96;
									scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
									vec_98 = _mm512_set1_ps(scal_17);


									vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_3644);
									mem_vec_3644 = vec_97;



									vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_3645);
									mem_vec_3645 = vec_99;



									vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_3646);
									mem_vec_3646 = vec_100;



									vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_3647);
									mem_vec_3647 = vec_101;
									scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
									vec_103 = _mm512_set1_ps(scal_18);


									vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_3648);
									mem_vec_3648 = vec_102;



									vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_3649);
									mem_vec_3649 = vec_104;



									vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_3650);
									mem_vec_3650 = vec_105;



									vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_3651);
									mem_vec_3651 = vec_106;
									scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
									vec_108 = _mm512_set1_ps(scal_19);


									vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_3652);
									mem_vec_3652 = vec_107;



									vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_3653);
									mem_vec_3653 = vec_109;



									vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_3654);
									mem_vec_3654 = vec_110;



									vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_3655);
									mem_vec_3655 = vec_111;
									scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
									vec_113 = _mm512_set1_ps(scal_20);


									vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_3656);
									mem_vec_3656 = vec_112;



									vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_3657);
									mem_vec_3657 = vec_114;



									vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_3658);
									mem_vec_3658 = vec_115;



									vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_3659);
									mem_vec_3659 = vec_116;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3632);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3633);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3634);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3635);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3636);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3637);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3638);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3639);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3640);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3641);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3642);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3643);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3644);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3645);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3646);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3647);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3648);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3649);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_3650);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_3651);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3652);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3653);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_3654);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_3655);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3656);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3657);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_3658);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_3659);
					}
				}
			}
		}
	}
}


}