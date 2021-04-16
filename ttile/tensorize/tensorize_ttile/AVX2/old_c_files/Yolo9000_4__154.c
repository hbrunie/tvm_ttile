#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (17, x);
  T (3, w); T (1, c); T (1, y); T (8, f); T (1, x);
  Lambda_apply y [((Iter 7), (Arg 12)); ((Iter 4), (Arg 13))]; T (8, x)]
*/
IND_TYPE c, cp_0, c81_p_0, cp_1, c81, f, fp_0, w, wp_0, x, xp_0, x108_p_0, x109_p_0, xp_1, x108_p_1, xp_2, x108, x109, y, yp_0, y63_p_0, yp_1, y63;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y64 = 0;
IND_TYPE x110 = 0;
IND_TYPE h = 0;
IND_TYPE w48 = 0;
IND_TYPE c82 = 0;
IND_TYPE f72 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,mem_vec_736 ,mem_vec_737 ,mem_vec_738 ,mem_vec_739 ,mem_vec_740 ,mem_vec_741 ,mem_vec_742 ,mem_vec_743 ,mem_vec_744 ,mem_vec_745 ,mem_vec_746 ,mem_vec_747 ,mem_vec_748 ,mem_vec_749 ,mem_vec_750 ,mem_vec_751 ,mem_vec_752 ,mem_vec_753 ,mem_vec_754 ,mem_vec_755 ,mem_vec_756 ,mem_vec_757 ,mem_vec_758 ,mem_vec_759 ,mem_vec_760 ,mem_vec_761 ,mem_vec_762 ,mem_vec_763 ,mem_vec_764 ,mem_vec_765 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 8) (136 / 17)
for (x109 = x110, x109_p_0 = 0;
	x109 < x110 + 136;
	x109 += 17, x109_p_0 += 17){
		for (y63 = y64, y63_p_0 = 0;
			y63 < y64 + 84;
			y63 += 12, y63_p_0 += 12){
			// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 128
			// T (x, 1) (17 / 17)
			for (x108 = x109, x108_p_1 = x109_p_0, x108_p_0 = 0;
				x108 < x109 + 17;
				x108 += 17, x108_p_1 += 17, x108_p_0 += 17){
				// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 128
				// T (f, 8) (128 / 16)
				for (f = f72, fp_0 = 0;
					f < f72 + 128;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
					// T (y, 1) (ph_y / ph_y)
					for (y = y63, yp_1 = y63_p_0, yp_0 = 0;
						y < y63 + 12;
						y += 12, yp_1 += 12, yp_0 += 12){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
						// T (c, 1) (64 / 64)
						for (c81 = c82, c81_p_0 = 0;
							c81 < c82 + 64;
							c81 += 64, c81_p_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
							// T (w, 3) (3 / 1)
							for (w = w48, wp_0 = 0;
								w < w48 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 64, f = 16
								// T (x, 17) (17 / 1)
								for (x = x108, xp_2 = x108_p_1, xp_1 = x108_p_0, xp_0 = 0;
									x < x108 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_716 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_717 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_718 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_719 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_720 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_721 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_722 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_723 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_724 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_725 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_726 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_727 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_728 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_729 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_730 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_731 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_732 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_733 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_734 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_735 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_736 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_737 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											mem_vec_738 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_739 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
											// T (c, 64) (64 / 1)
											for (c = c81, cp_1 = c81_p_0, cp_0 = 0;
												c < c81 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_716);
												mem_vec_716 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_717);
												mem_vec_717 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_718);
												mem_vec_718 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_719);
												mem_vec_719 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_720);
												mem_vec_720 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_721);
												mem_vec_721 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_722);
												mem_vec_722 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_723);
												mem_vec_723 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_724);
												mem_vec_724 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_725);
												mem_vec_725 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_726);
												mem_vec_726 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_727);
												mem_vec_727 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_728);
												mem_vec_728 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_729);
												mem_vec_729 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_730);
												mem_vec_730 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_731);
												mem_vec_731 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_732);
												mem_vec_732 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_733);
												mem_vec_733 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_734);
												mem_vec_734 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_735);
												mem_vec_735 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_736);
												mem_vec_736 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_737);
												mem_vec_737 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm256_set1_ps(scal_11);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_738);
												mem_vec_738 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_739);
												mem_vec_739 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_12);
												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_38 = _mm256_fmadd_ps(vec_39, vec_40, mem_vec_716);
												mem_vec_716 = vec_38;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_41 = _mm256_fmadd_ps(vec_39, vec_42, mem_vec_717);
												mem_vec_717 = vec_41;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_718);
												mem_vec_718 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_719);
												mem_vec_719 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_40, mem_vec_720);
												mem_vec_720 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_42, mem_vec_721);
												mem_vec_721 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_40, mem_vec_722);
												mem_vec_722 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_42, mem_vec_723);
												mem_vec_723 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_40, mem_vec_724);
												mem_vec_724 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_42, mem_vec_725);
												mem_vec_725 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_40, mem_vec_726);
												mem_vec_726 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_42, mem_vec_727);
												mem_vec_727 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_728);
												mem_vec_728 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_729);
												mem_vec_729 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_40, mem_vec_730);
												mem_vec_730 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_42, mem_vec_731);
												mem_vec_731 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_40, mem_vec_732);
												mem_vec_732 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_42, mem_vec_733);
												mem_vec_733 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_40, mem_vec_734);
												mem_vec_734 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_42, mem_vec_735);
												mem_vec_735 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_71 = _mm256_set1_ps(scal_22);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_40, mem_vec_736);
												mem_vec_736 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_42, mem_vec_737);
												mem_vec_737 = vec_72;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_23);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_40, mem_vec_738);
												mem_vec_738 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_42, mem_vec_739);
												mem_vec_739 = vec_75;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_77 = _mm256_set1_ps(scal_24);
												vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_76 = _mm256_fmadd_ps(vec_77, vec_78, mem_vec_716);
												mem_vec_716 = vec_76;

												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_79 = _mm256_fmadd_ps(vec_77, vec_80, mem_vec_717);
												mem_vec_717 = vec_79;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_78, mem_vec_718);
												mem_vec_718 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_80, mem_vec_719);
												mem_vec_719 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_78, mem_vec_720);
												mem_vec_720 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_80, mem_vec_721);
												mem_vec_721 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_722);
												mem_vec_722 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_723);
												mem_vec_723 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_78, mem_vec_724);
												mem_vec_724 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_80, mem_vec_725);
												mem_vec_725 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_78, mem_vec_726);
												mem_vec_726 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_80, mem_vec_727);
												mem_vec_727 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_728);
												mem_vec_728 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_729);
												mem_vec_729 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_78, mem_vec_730);
												mem_vec_730 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_80, mem_vec_731);
												mem_vec_731 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_78, mem_vec_732);
												mem_vec_732 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_733);
												mem_vec_733 = vec_104;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_106 = _mm256_set1_ps(scal_33);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_78, mem_vec_734);
												mem_vec_734 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_80, mem_vec_735);
												mem_vec_735 = vec_107;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_109 = _mm256_set1_ps(scal_34);


												vec_108 = _mm256_fmadd_ps(vec_109, vec_78, mem_vec_736);
												mem_vec_736 = vec_108;



												vec_110 = _mm256_fmadd_ps(vec_109, vec_80, mem_vec_737);
												mem_vec_737 = vec_110;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_112 = _mm256_set1_ps(scal_35);


												vec_111 = _mm256_fmadd_ps(vec_112, vec_78, mem_vec_738);
												mem_vec_738 = vec_111;



												vec_113 = _mm256_fmadd_ps(vec_112, vec_80, mem_vec_739);
												mem_vec_739 = vec_113;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_716);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_717);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_718);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_719);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_720);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_721);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_722);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_723);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_724);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_725);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_726);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_727);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_728);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_729);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_730);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_731);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_732);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_733);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_734);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_735);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_736);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_737);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_738);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_739);
								}
							}
						}
					}
				}
			}
		}
		for (y63 = y64 + 84, y63_p_0 = 0;
			y63 < y64 + 84 + 52;
			y63 += 13, y63_p_0 += 13){
			// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 128
			// T (x, 1) (17 / 17)
			for (x108 = x109, x108_p_1 = x109_p_0, x108_p_0 = 0;
				x108 < x109 + 17;
				x108 += 17, x108_p_1 += 17, x108_p_0 += 17){
				// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 128
				// T (f, 8) (128 / 16)
				for (f = f72, fp_0 = 0;
					f < f72 + 128;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
					// T (y, 1) (ph_y / ph_y)
					for (y = y63, yp_1 = y63_p_0, yp_0 = 0;
						y < y63 + 13;
						y += 13, yp_1 += 13, yp_0 += 13){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
						// T (c, 1) (64 / 64)
						for (c81 = c82, c81_p_0 = 0;
							c81 < c82 + 64;
							c81 += 64, c81_p_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
							// T (w, 3) (3 / 1)
							for (w = w48, wp_0 = 0;
								w < w48 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 64, f = 16
								// T (x, 17) (17 / 1)
								for (x = x108, xp_2 = x108_p_1, xp_1 = x108_p_0, xp_0 = 0;
									x < x108 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_740 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_741 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_742 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_743 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_744 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_745 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_746 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_747 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_748 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_749 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_750 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_751 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_752 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_753 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_754 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_755 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_756 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_757 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_758 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_759 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_760 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_761 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											mem_vec_762 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_763 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
											mem_vec_764 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_765 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
											// T (c, 64) (64 / 1)
											for (c = c81, cp_1 = c81_p_0, cp_0 = 0;
												c < c81 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_740);
												mem_vec_740 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_741);
												mem_vec_741 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_742);
												mem_vec_742 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_743);
												mem_vec_743 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_744);
												mem_vec_744 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_745);
												mem_vec_745 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_746);
												mem_vec_746 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_747);
												mem_vec_747 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_748);
												mem_vec_748 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_749);
												mem_vec_749 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_750);
												mem_vec_750 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_751);
												mem_vec_751 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_752);
												mem_vec_752 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_753);
												mem_vec_753 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_754);
												mem_vec_754 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_755);
												mem_vec_755 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_756);
												mem_vec_756 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_757);
												mem_vec_757 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_758);
												mem_vec_758 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_759);
												mem_vec_759 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_760);
												mem_vec_760 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_761);
												mem_vec_761 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm256_set1_ps(scal_11);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_762);
												mem_vec_762 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_763);
												mem_vec_763 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm256_set1_ps(scal_12);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_2, mem_vec_764);
												mem_vec_764 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_4, mem_vec_765);
												mem_vec_765 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_42 = _mm256_set1_ps(scal_13);
												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_41 = _mm256_fmadd_ps(vec_42, vec_43, mem_vec_740);
												mem_vec_740 = vec_41;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_44 = _mm256_fmadd_ps(vec_42, vec_45, mem_vec_741);
												mem_vec_741 = vec_44;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_43, mem_vec_742);
												mem_vec_742 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_45, mem_vec_743);
												mem_vec_743 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_43, mem_vec_744);
												mem_vec_744 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_45, mem_vec_745);
												mem_vec_745 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_746);
												mem_vec_746 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_747);
												mem_vec_747 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_43, mem_vec_748);
												mem_vec_748 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_45, mem_vec_749);
												mem_vec_749 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_750);
												mem_vec_750 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_751);
												mem_vec_751 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_752);
												mem_vec_752 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_753);
												mem_vec_753 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_43, mem_vec_754);
												mem_vec_754 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_45, mem_vec_755);
												mem_vec_755 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_43, mem_vec_756);
												mem_vec_756 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_45, mem_vec_757);
												mem_vec_757 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_71 = _mm256_set1_ps(scal_22);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_43, mem_vec_758);
												mem_vec_758 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_45, mem_vec_759);
												mem_vec_759 = vec_72;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_23);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_760);
												mem_vec_760 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_761);
												mem_vec_761 = vec_75;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_77 = _mm256_set1_ps(scal_24);


												vec_76 = _mm256_fmadd_ps(vec_77, vec_43, mem_vec_762);
												mem_vec_762 = vec_76;



												vec_78 = _mm256_fmadd_ps(vec_77, vec_45, mem_vec_763);
												mem_vec_763 = vec_78;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
												vec_80 = _mm256_set1_ps(scal_25);


												vec_79 = _mm256_fmadd_ps(vec_80, vec_43, mem_vec_764);
												mem_vec_764 = vec_79;



												vec_81 = _mm256_fmadd_ps(vec_80, vec_45, mem_vec_765);
												mem_vec_765 = vec_81;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_26);
												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_82 = _mm256_fmadd_ps(vec_83, vec_84, mem_vec_740);
												mem_vec_740 = vec_82;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_85 = _mm256_fmadd_ps(vec_83, vec_86, mem_vec_741);
												mem_vec_741 = vec_85;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_742);
												mem_vec_742 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_743);
												mem_vec_743 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_84, mem_vec_744);
												mem_vec_744 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_86, mem_vec_745);
												mem_vec_745 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_84, mem_vec_746);
												mem_vec_746 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_86, mem_vec_747);
												mem_vec_747 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_748);
												mem_vec_748 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_749);
												mem_vec_749 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_84, mem_vec_750);
												mem_vec_750 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_86, mem_vec_751);
												mem_vec_751 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_752);
												mem_vec_752 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_753);
												mem_vec_753 = vec_104;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_106 = _mm256_set1_ps(scal_33);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_84, mem_vec_754);
												mem_vec_754 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_86, mem_vec_755);
												mem_vec_755 = vec_107;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_109 = _mm256_set1_ps(scal_34);


												vec_108 = _mm256_fmadd_ps(vec_109, vec_84, mem_vec_756);
												mem_vec_756 = vec_108;



												vec_110 = _mm256_fmadd_ps(vec_109, vec_86, mem_vec_757);
												mem_vec_757 = vec_110;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_112 = _mm256_set1_ps(scal_35);


												vec_111 = _mm256_fmadd_ps(vec_112, vec_84, mem_vec_758);
												mem_vec_758 = vec_111;



												vec_113 = _mm256_fmadd_ps(vec_112, vec_86, mem_vec_759);
												mem_vec_759 = vec_113;
												scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_115 = _mm256_set1_ps(scal_36);


												vec_114 = _mm256_fmadd_ps(vec_115, vec_84, mem_vec_760);
												mem_vec_760 = vec_114;



												vec_116 = _mm256_fmadd_ps(vec_115, vec_86, mem_vec_761);
												mem_vec_761 = vec_116;
												scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_118 = _mm256_set1_ps(scal_37);


												vec_117 = _mm256_fmadd_ps(vec_118, vec_84, mem_vec_762);
												mem_vec_762 = vec_117;



												vec_119 = _mm256_fmadd_ps(vec_118, vec_86, mem_vec_763);
												mem_vec_763 = vec_119;
												scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
												vec_121 = _mm256_set1_ps(scal_38);


												vec_120 = _mm256_fmadd_ps(vec_121, vec_84, mem_vec_764);
												mem_vec_764 = vec_120;



												vec_122 = _mm256_fmadd_ps(vec_121, vec_86, mem_vec_765);
												mem_vec_765 = vec_122;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_740);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_741);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_742);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_743);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_744);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_745);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_746);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_747);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_748);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_749);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_750);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_751);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_752);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_753);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_754);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_755);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_756);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_757);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_758);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_759);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_760);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_761);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_762);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_763);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_764);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8], mem_vec_765);
								}
							}
						}
					}
				}
			}
		}
}


}