#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (4, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (2, x);
  T (1, f); T (8, f)]
*/
IND_TYPE c, cp_0, c447_p_0, cp_1, c447, f, fp_0, f542_p_0, f543_p_0, fp_1, f542_p_1, fp_2, f542, f543, h, hp_0, x, xp_0, x454_p_0, xp_1, x454, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y325 = 0;
IND_TYPE x455 = 0;
IND_TYPE h278 = 0;
IND_TYPE w = 0;
IND_TYPE c448 = 0;
IND_TYPE f544 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6671 ,mem_vec_6672 ,mem_vec_6673 ,mem_vec_6674 ,mem_vec_6675 ,mem_vec_6676 ,mem_vec_6677 ,mem_vec_6678 ,mem_vec_6679 ,mem_vec_6680 ,mem_vec_6681 ,mem_vec_6682 ,mem_vec_6683 ,mem_vec_6684 ,mem_vec_6685 ,mem_vec_6686 ,mem_vec_6687 ,mem_vec_6688 ,mem_vec_6689 ,mem_vec_6690 ,mem_vec_6691 ,mem_vec_6692 ,mem_vec_6693 ,mem_vec_6694 ,mem_vec_6695 ,mem_vec_6696 ,mem_vec_6697 ,mem_vec_6698 ,mem_vec_6699 ,mem_vec_6700 ,mem_vec_6701 ,mem_vec_6702 ,mem_vec_6703 ,mem_vec_6704 ,mem_vec_6705 ,mem_vec_6706 ,mem_vec_6707 ,mem_vec_6708 ,mem_vec_6709 ,mem_vec_6710 ,mem_vec_6711 ,mem_vec_6712 ,mem_vec_6713 ,mem_vec_6714 ,mem_vec_6715 ,mem_vec_6716 ,mem_vec_6717 ,mem_vec_6718 ,mem_vec_6719 ,mem_vec_6720 ,mem_vec_6721 ,mem_vec_6722 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 8) (512 / 64)
for (f543 = f544, f543_p_0 = 0;
	f543 < f544 + 512;
	f543 += 64, f543_p_0 += 64){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 64
	// T (f, 1) (64 / 64)
	for (f542 = f543, f542_p_1 = f543_p_0, f542_p_0 = 0;
		f542 < f543 + 64;
		f542 += 64, f542_p_1 += 64, f542_p_0 += 64){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 64
		// T (x, 2) (34 / 17)
		for (x454 = x455, x454_p_0 = 0;
			x454 < x455 + 34;
			x454 += 17, x454_p_0 += 17){
				for (y = y325, yp_0 = 0;
					y < y325 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
					// T (f, 1) (64 / 64)
					for (f = f542, fp_2 = f542_p_1, fp_1 = f542_p_0, fp_0 = 0;
						f < f542 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
						// T (c, 4) (256 / 64)
						for (c447 = c448, c447_p_0 = 0;
							c447 < c448 + 256;
							c447 += 64, c447_p_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 64
							// T (h, 3) (3 / 1)
							for (h = h278, hp_0 = 0;
								h < h278 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 64, f = 64
								// T (x, 17) (17 / 1)
								for (x = x454, xp_1 = x454_p_0, xp_0 = 0;
									x < x454 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6671 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6672 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6673 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_6674 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_6675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_6678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_6679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_6682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_6683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_6686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_6687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_6690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_6691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_6694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
											// T (c, 64) (64 / 1)
											for (c = c447, cp_1 = c447_p_0, cp_0 = 0;
												c < c447 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6671);
												mem_vec_6671 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6672);
												mem_vec_6672 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6673);
												mem_vec_6673 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6674);
												mem_vec_6674 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6675);
												mem_vec_6675 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6676);
												mem_vec_6676 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6677);
												mem_vec_6677 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6678);
												mem_vec_6678 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6679);
												mem_vec_6679 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6680);
												mem_vec_6680 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6681);
												mem_vec_6681 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6682);
												mem_vec_6682 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6683);
												mem_vec_6683 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6684);
												mem_vec_6684 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6685);
												mem_vec_6685 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6686);
												mem_vec_6686 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6687);
												mem_vec_6687 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6688);
												mem_vec_6688 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6689);
												mem_vec_6689 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6690);
												mem_vec_6690 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6691);
												mem_vec_6691 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6692);
												mem_vec_6692 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_6693);
												mem_vec_6693 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_6694);
												mem_vec_6694 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_6671);
												mem_vec_6671 = vec_34;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_6672);
												mem_vec_6672 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_6673);
												mem_vec_6673 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_6674);
												mem_vec_6674 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_6675);
												mem_vec_6675 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_6676);
												mem_vec_6676 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_6677);
												mem_vec_6677 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_6678);
												mem_vec_6678 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_6679);
												mem_vec_6679 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_6680);
												mem_vec_6680 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_6681);
												mem_vec_6681 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_6682);
												mem_vec_6682 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_6683);
												mem_vec_6683 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_6684);
												mem_vec_6684 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_6685);
												mem_vec_6685 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_6686);
												mem_vec_6686 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_6687);
												mem_vec_6687 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_6688);
												mem_vec_6688 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_6689);
												mem_vec_6689 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_6690);
												mem_vec_6690 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_6691);
												mem_vec_6691 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_6692);
												mem_vec_6692 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_6693);
												mem_vec_6693 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_6694);
												mem_vec_6694 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_6671);
												mem_vec_6671 = vec_68;

												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_6672);
												mem_vec_6672 = vec_71;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_6673);
												mem_vec_6673 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_6674);
												mem_vec_6674 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_6675);
												mem_vec_6675 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_6676);
												mem_vec_6676 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_6677);
												mem_vec_6677 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_6678);
												mem_vec_6678 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_6679);
												mem_vec_6679 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_6680);
												mem_vec_6680 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_6681);
												mem_vec_6681 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_6682);
												mem_vec_6682 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_6683);
												mem_vec_6683 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_6684);
												mem_vec_6684 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_6685);
												mem_vec_6685 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_6686);
												mem_vec_6686 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_6687);
												mem_vec_6687 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_6688);
												mem_vec_6688 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_6689);
												mem_vec_6689 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_6690);
												mem_vec_6690 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_6691);
												mem_vec_6691 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_6692);
												mem_vec_6692 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_6693);
												mem_vec_6693 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_6694);
												mem_vec_6694 = vec_101;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6671);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6672);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6673);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6674);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6675);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6676);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6677);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6678);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6679);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6680);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6681);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6682);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6683);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6684);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6685);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6686);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6687);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6688);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6689);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6690);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6691);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6692);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_6693);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_6694);
								}
							}
						}
					}
				}
				for (y = y325 + 6, yp_0 = 0;
					y < y325 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
					// T (f, 1) (64 / 64)
					for (f = f542, fp_2 = f542_p_1, fp_1 = f542_p_0, fp_0 = 0;
						f < f542 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
						// T (c, 4) (256 / 64)
						for (c447 = c448, c447_p_0 = 0;
							c447 < c448 + 256;
							c447 += 64, c447_p_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 64
							// T (h, 3) (3 / 1)
							for (h = h278, hp_0 = 0;
								h < h278 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 64, f = 64
								// T (x, 17) (17 / 1)
								for (x = x454, xp_1 = x454_p_0, xp_0 = 0;
									x < x454 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6695 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6696 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6697 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_6698 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_6699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_6702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_6703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_6706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_6707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_6710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_6711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_6714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_6715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_6718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											mem_vec_6719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
											mem_vec_6722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
											// T (c, 64) (64 / 1)
											for (c = c447, cp_1 = c447_p_0, cp_0 = 0;
												c < c447 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6695);
												mem_vec_6695 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6696);
												mem_vec_6696 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6697);
												mem_vec_6697 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6698);
												mem_vec_6698 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6699);
												mem_vec_6699 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6700);
												mem_vec_6700 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6701);
												mem_vec_6701 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6702);
												mem_vec_6702 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6703);
												mem_vec_6703 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6704);
												mem_vec_6704 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6705);
												mem_vec_6705 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6706);
												mem_vec_6706 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6707);
												mem_vec_6707 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6708);
												mem_vec_6708 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6709);
												mem_vec_6709 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6710);
												mem_vec_6710 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6711);
												mem_vec_6711 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6712);
												mem_vec_6712 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6713);
												mem_vec_6713 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6714);
												mem_vec_6714 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6715);
												mem_vec_6715 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6716);
												mem_vec_6716 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_6717);
												mem_vec_6717 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_6718);
												mem_vec_6718 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_6719);
												mem_vec_6719 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_6720);
												mem_vec_6720 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_6721);
												mem_vec_6721 = vec_37;



												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_6722);
												mem_vec_6722 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_40 = _mm512_set1_ps(scal_7);
												vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_6695);
												mem_vec_6695 = vec_39;

												vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_6696);
												mem_vec_6696 = vec_42;

												vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_6697);
												mem_vec_6697 = vec_44;

												vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_6698);
												mem_vec_6698 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_6699);
												mem_vec_6699 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_6700);
												mem_vec_6700 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_6701);
												mem_vec_6701 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_6702);
												mem_vec_6702 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_6703);
												mem_vec_6703 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_6704);
												mem_vec_6704 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_6705);
												mem_vec_6705 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_6706);
												mem_vec_6706 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_6707);
												mem_vec_6707 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_6708);
												mem_vec_6708 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_6709);
												mem_vec_6709 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_6710);
												mem_vec_6710 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_6711);
												mem_vec_6711 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_6712);
												mem_vec_6712 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_6713);
												mem_vec_6713 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_6714);
												mem_vec_6714 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);


												vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_6715);
												mem_vec_6715 = vec_68;



												vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_6716);
												mem_vec_6716 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_6717);
												mem_vec_6717 = vec_71;



												vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_6718);
												mem_vec_6718 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_74 = _mm512_set1_ps(scal_13);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_6719);
												mem_vec_6719 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_6720);
												mem_vec_6720 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_6721);
												mem_vec_6721 = vec_76;



												vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_6722);
												mem_vec_6722 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_79 = _mm512_set1_ps(scal_14);
												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_6695);
												mem_vec_6695 = vec_78;

												vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_6696);
												mem_vec_6696 = vec_81;

												vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_6697);
												mem_vec_6697 = vec_83;

												vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_6698);
												mem_vec_6698 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_6699);
												mem_vec_6699 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_6700);
												mem_vec_6700 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_6701);
												mem_vec_6701 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_6702);
												mem_vec_6702 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_6703);
												mem_vec_6703 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_6704);
												mem_vec_6704 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_6705);
												mem_vec_6705 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_6706);
												mem_vec_6706 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_6707);
												mem_vec_6707 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_6708);
												mem_vec_6708 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_6709);
												mem_vec_6709 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_6710);
												mem_vec_6710 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_103 = _mm512_set1_ps(scal_18);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_6711);
												mem_vec_6711 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_6712);
												mem_vec_6712 = vec_104;



												vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_6713);
												mem_vec_6713 = vec_105;



												vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_6714);
												mem_vec_6714 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_108 = _mm512_set1_ps(scal_19);


												vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_6715);
												mem_vec_6715 = vec_107;



												vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_6716);
												mem_vec_6716 = vec_109;



												vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_6717);
												mem_vec_6717 = vec_110;



												vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_6718);
												mem_vec_6718 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_113 = _mm512_set1_ps(scal_20);


												vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_6719);
												mem_vec_6719 = vec_112;



												vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_6720);
												mem_vec_6720 = vec_114;



												vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_6721);
												mem_vec_6721 = vec_115;



												vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_6722);
												mem_vec_6722 = vec_116;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6695);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6696);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6697);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6698);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6699);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6700);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6701);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6702);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6703);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6704);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6705);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6706);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6707);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6708);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6709);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6710);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6711);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6712);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6713);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6714);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6715);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6716);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_6717);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_6718);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6719);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6720);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_6721);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_6722);
								}
							}
						}
					}
				}
		}
	}
}


}