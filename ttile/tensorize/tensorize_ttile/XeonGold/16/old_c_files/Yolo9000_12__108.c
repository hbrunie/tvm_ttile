#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (1, c); T (4, f);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (1, x);
  T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c45_p_0, cp_1, c45, f, fp_0, f58_p_0, f59_p_0, fp_1, f58_p_1, fp_2, f58, f59, h, hp_0, x, xp_0, x46_p_0, xp_1, x46, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y31 = 0;
IND_TYPE x47 = 0;
IND_TYPE h30 = 0;
IND_TYPE w = 0;
IND_TYPE c46 = 0;
IND_TYPE f60 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,mem_vec_736 ,mem_vec_737 ,mem_vec_738 ,mem_vec_739 ,mem_vec_740 ,mem_vec_741 ,mem_vec_742 ,mem_vec_743 ,mem_vec_744 ,mem_vec_745 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f59 = f60, f59_p_0 = 0;
	f59 < f60 + 512;
	f59 += 512, f59_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (f, 2) (512 / 256)
	for (f58 = f59, f58_p_1 = f59_p_0, f58_p_0 = 0;
		f58 < f59 + 512;
		f58 += 256, f58_p_1 += 256, f58_p_0 += 256){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
		// T (x, 1) (34 / 34)
		for (x46 = x47, x46_p_0 = 0;
			x46 < x47 + 34;
			x46 += 34, x46_p_0 += 34){
				for (y = y31, yp_0 = 0;
					y < y31 + 20;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 256
					// T (f, 4) (256 / 64)
					for (f = f58, fp_2 = f58_p_1, fp_1 = f58_p_0, fp_0 = 0;
						f < f58 + 256;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c45 = c46, c45_p_0 = 0;
							c45 < c46 + 256;
							c45 += 256, c45_p_0 += 256){
							// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h30, hp_0 = 0;
								h < h30 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 256, f = 64
								// T (x, 34) (34 / 1)
								for (x = x46, xp_1 = x46_p_0, xp_0 = 0;
									x < x46 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_702 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_703 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_704 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_705 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
												c < c45 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_702);
												mem_vec_702 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_703);
												mem_vec_703 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_704);
												mem_vec_704 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_705);
												mem_vec_705 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_706);
												mem_vec_706 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_707);
												mem_vec_707 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_708);
												mem_vec_708 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_709);
												mem_vec_709 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_710);
												mem_vec_710 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_711);
												mem_vec_711 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_712);
												mem_vec_712 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_713);
												mem_vec_713 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_714);
												mem_vec_714 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_715);
												mem_vec_715 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_716);
												mem_vec_716 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_717);
												mem_vec_717 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_702);
												mem_vec_702 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_703);
												mem_vec_703 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_704);
												mem_vec_704 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_705);
												mem_vec_705 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_706);
												mem_vec_706 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_707);
												mem_vec_707 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_708);
												mem_vec_708 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_709);
												mem_vec_709 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_710);
												mem_vec_710 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_711);
												mem_vec_711 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_712);
												mem_vec_712 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_713);
												mem_vec_713 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_714);
												mem_vec_714 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_715);
												mem_vec_715 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_716);
												mem_vec_716 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_717);
												mem_vec_717 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_702);
												mem_vec_702 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_703);
												mem_vec_703 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_704);
												mem_vec_704 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_705);
												mem_vec_705 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_706);
												mem_vec_706 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_707);
												mem_vec_707 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_708);
												mem_vec_708 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_709);
												mem_vec_709 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_710);
												mem_vec_710 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_711);
												mem_vec_711 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_712);
												mem_vec_712 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_713);
												mem_vec_713 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_714);
												mem_vec_714 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_715);
												mem_vec_715 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_716);
												mem_vec_716 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_717);
												mem_vec_717 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_702);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_703);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_704);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_705);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_706);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_707);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_708);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_709);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_710);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_711);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_712);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_713);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_714);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_715);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_716);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_717);
								}
							}
						}
					}
				}
				for (y = y31 + 20, yp_0 = 0;
					y < y31 + 20 + 14;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 256
					// T (f, 4) (256 / 64)
					for (f = f58, fp_2 = f58_p_1, fp_1 = f58_p_0, fp_0 = 0;
						f < f58 + 256;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c45 = c46, c45_p_0 = 0;
							c45 < c46 + 256;
							c45 += 256, c45_p_0 += 256){
							// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h30, hp_0 = 0;
								h < h30 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 256, f = 64
								// T (x, 34) (34 / 1)
								for (x = x46, xp_1 = x46_p_0, xp_0 = 0;
									x < x46 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_718 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_719 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_720 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_721 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											mem_vec_742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
											mem_vec_745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
												c < c45 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_718);
												mem_vec_718 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_719);
												mem_vec_719 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_720);
												mem_vec_720 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_721);
												mem_vec_721 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_722);
												mem_vec_722 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_723);
												mem_vec_723 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_724);
												mem_vec_724 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_725);
												mem_vec_725 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_726);
												mem_vec_726 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_727);
												mem_vec_727 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_728);
												mem_vec_728 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_729);
												mem_vec_729 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_730);
												mem_vec_730 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_731);
												mem_vec_731 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_732);
												mem_vec_732 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_733);
												mem_vec_733 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_734);
												mem_vec_734 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_735);
												mem_vec_735 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_736);
												mem_vec_736 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_737);
												mem_vec_737 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_738);
												mem_vec_738 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_739);
												mem_vec_739 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_740);
												mem_vec_740 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_741);
												mem_vec_741 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_742);
												mem_vec_742 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_743);
												mem_vec_743 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_744);
												mem_vec_744 = vec_37;



												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_745);
												mem_vec_745 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_40 = _mm512_set1_ps(scal_7);
												vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_718);
												mem_vec_718 = vec_39;

												vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_719);
												mem_vec_719 = vec_42;

												vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_720);
												mem_vec_720 = vec_44;

												vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_721);
												mem_vec_721 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_722);
												mem_vec_722 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_723);
												mem_vec_723 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_724);
												mem_vec_724 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_725);
												mem_vec_725 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_726);
												mem_vec_726 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_727);
												mem_vec_727 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_728);
												mem_vec_728 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_729);
												mem_vec_729 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_730);
												mem_vec_730 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_731);
												mem_vec_731 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_732);
												mem_vec_732 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_733);
												mem_vec_733 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_734);
												mem_vec_734 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_735);
												mem_vec_735 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_736);
												mem_vec_736 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_737);
												mem_vec_737 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);


												vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_738);
												mem_vec_738 = vec_68;



												vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_739);
												mem_vec_739 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_740);
												mem_vec_740 = vec_71;



												vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_741);
												mem_vec_741 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_74 = _mm512_set1_ps(scal_13);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_742);
												mem_vec_742 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_743);
												mem_vec_743 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_744);
												mem_vec_744 = vec_76;



												vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_745);
												mem_vec_745 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_79 = _mm512_set1_ps(scal_14);
												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_718);
												mem_vec_718 = vec_78;

												vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_719);
												mem_vec_719 = vec_81;

												vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_720);
												mem_vec_720 = vec_83;

												vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_721);
												mem_vec_721 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_722);
												mem_vec_722 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_723);
												mem_vec_723 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_724);
												mem_vec_724 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_725);
												mem_vec_725 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_726);
												mem_vec_726 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_727);
												mem_vec_727 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_728);
												mem_vec_728 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_729);
												mem_vec_729 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_730);
												mem_vec_730 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_731);
												mem_vec_731 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_732);
												mem_vec_732 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_733);
												mem_vec_733 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_103 = _mm512_set1_ps(scal_18);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_734);
												mem_vec_734 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_735);
												mem_vec_735 = vec_104;



												vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_736);
												mem_vec_736 = vec_105;



												vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_737);
												mem_vec_737 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_108 = _mm512_set1_ps(scal_19);


												vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_738);
												mem_vec_738 = vec_107;



												vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_739);
												mem_vec_739 = vec_109;



												vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_740);
												mem_vec_740 = vec_110;



												vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_741);
												mem_vec_741 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_113 = _mm512_set1_ps(scal_20);


												vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_742);
												mem_vec_742 = vec_112;



												vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_743);
												mem_vec_743 = vec_114;



												vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_744);
												mem_vec_744 = vec_115;



												vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_745);
												mem_vec_745 = vec_116;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_718);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_719);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_720);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_721);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_722);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_723);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_724);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_725);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_726);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_727);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_728);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_729);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_730);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_731);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_732);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_733);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_734);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_735);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_736);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_737);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_738);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_739);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_740);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_741);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_742);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_743);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_744);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_745);
								}
							}
						}
					}
				}
		}
	}
}


}