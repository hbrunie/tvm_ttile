#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (3, w);
  T (68, x); T (16, c); T (16, f); T (1, c); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 4), (Arg 11))]; T (1, c)]
*/
IND_TYPE c, cp_0, c83_p_0, c84_p_0, c85_p_0, cp_1, c83_p_1, c84_p_1, cp_2, c83_p_2, cp_3, c83, c84, c85, f, fp_0, w, wp_0, x, xp_0, x57_p_0, xp_1, x57, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y38 = 0;
IND_TYPE x58 = 0;
IND_TYPE h = 0;
IND_TYPE w26 = 0;
IND_TYPE c86 = 0;
IND_TYPE f50 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_676 ,mem_vec_677 ,mem_vec_678 ,mem_vec_679 ,mem_vec_680 ,mem_vec_681 ,mem_vec_682 ,mem_vec_683 ,mem_vec_684 ,mem_vec_685 ,mem_vec_686 ,mem_vec_687 ,mem_vec_688 ,mem_vec_689 ,mem_vec_690 ,mem_vec_691 ,mem_vec_692 ,mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (c, 1) (128 / 128)
for (c85 = c86, c85_p_0 = 0;
	c85 < c86 + 128;
	c85 += 128, c85_p_0 += 128){
		for (y = y38, yp_0 = 0;
			y < y38 + 24;
			y += 8, yp_0 += 8){
			// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
			// T (x, 1) (68 / 68)
			for (x57 = x58, x57_p_0 = 0;
				x57 < x58 + 68;
				x57 += 68, x57_p_0 += 68){
				// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
				// T (c, 1) (128 / 128)
				for (c84 = c85, c84_p_1 = c85_p_0, c84_p_0 = 0;
					c84 < c85 + 128;
					c84 += 128, c84_p_1 += 128, c84_p_0 += 128){
					// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
					// T (f, 16) (256 / 16)
					for (f = f50, fp_0 = 0;
						f < f50 + 256;
						f += 16, fp_0 += 16){
						// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 16
						// T (c, 16) (128 / 8)
						for (c83 = c84, c83_p_2 = c84_p_1, c83_p_1 = c84_p_0, c83_p_0 = 0;
							c83 < c84 + 128;
							c83 += 8, c83_p_2 += 8, c83_p_1 += 8, c83_p_0 += 8){
							// y = ph_y, x = 68, h = 3, w = 3, c = 8, f = 16
							// T (x, 68) (68 / 1)
							for (x = x57, xp_1 = x57_p_0, xp_0 = 0;
								x < x57 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
								// T (w, 3) (3 / 1)
								for (w = w26, wp_0 = 0;
									w < w26 + 3;
									w += 1, wp_0 += 1){
											mem_vec_676 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_677 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_678 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_679 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_680 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_681 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_682 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_683 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_684 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_685 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_686 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_687 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_688 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_689 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_690 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_691 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
											// T (c, 8) (8 / 1)
											for (c = c83, cp_3 = c83_p_2, cp_2 = c83_p_1, cp_1 = c83_p_0, cp_0 = 0;
												c < c83 + 8;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_676);
												mem_vec_676 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_677);
												mem_vec_677 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_678);
												mem_vec_678 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_679);
												mem_vec_679 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_680);
												mem_vec_680 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_681);
												mem_vec_681 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_682);
												mem_vec_682 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_683);
												mem_vec_683 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_684);
												mem_vec_684 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_685);
												mem_vec_685 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_686);
												mem_vec_686 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_687);
												mem_vec_687 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_688);
												mem_vec_688 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_689);
												mem_vec_689 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_690);
												mem_vec_690 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_691);
												mem_vec_691 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_676);
												mem_vec_676 = vec_26;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_677);
												mem_vec_677 = vec_29;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_32 = _mm256_set1_ps(scal_9);


												vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_678);
												mem_vec_678 = vec_31;



												vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_679);
												mem_vec_679 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_680);
												mem_vec_680 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_681);
												mem_vec_681 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_682);
												mem_vec_682 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_683);
												mem_vec_683 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_684);
												mem_vec_684 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_685);
												mem_vec_685 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_686);
												mem_vec_686 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_687);
												mem_vec_687 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_688);
												mem_vec_688 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_689);
												mem_vec_689 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_690);
												mem_vec_690 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_691);
												mem_vec_691 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_676);
												mem_vec_676 = vec_52;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_677);
												mem_vec_677 = vec_55;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_17);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_678);
												mem_vec_678 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_679);
												mem_vec_679 = vec_59;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_61 = _mm256_set1_ps(scal_18);


												vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_680);
												mem_vec_680 = vec_60;



												vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_681);
												mem_vec_681 = vec_62;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_682);
												mem_vec_682 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_683);
												mem_vec_683 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_684);
												mem_vec_684 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_685);
												mem_vec_685 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_686);
												mem_vec_686 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_687);
												mem_vec_687 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_688);
												mem_vec_688 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_689);
												mem_vec_689 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_690);
												mem_vec_690 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_691);
												mem_vec_691 = vec_77;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_676);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_677);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_678);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_679);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_680);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_681);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_682);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_683);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_684);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_685);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_686);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_687);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_688);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_689);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_690);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_691);
								}
							}
						}
					}
				}
			}
		}
		for (y = y38 + 24, yp_0 = 0;
			y < y38 + 24 + 44;
			y += 11, yp_0 += 11){
			// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
			// T (x, 1) (68 / 68)
			for (x57 = x58, x57_p_0 = 0;
				x57 < x58 + 68;
				x57 += 68, x57_p_0 += 68){
				// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
				// T (c, 1) (128 / 128)
				for (c84 = c85, c84_p_1 = c85_p_0, c84_p_0 = 0;
					c84 < c85 + 128;
					c84 += 128, c84_p_1 += 128, c84_p_0 += 128){
					// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
					// T (f, 16) (256 / 16)
					for (f = f50, fp_0 = 0;
						f < f50 + 256;
						f += 16, fp_0 += 16){
						// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 16
						// T (c, 16) (128 / 8)
						for (c83 = c84, c83_p_2 = c84_p_1, c83_p_1 = c84_p_0, c83_p_0 = 0;
							c83 < c84 + 128;
							c83 += 8, c83_p_2 += 8, c83_p_1 += 8, c83_p_0 += 8){
							// y = ph_y, x = 68, h = 3, w = 3, c = 8, f = 16
							// T (x, 68) (68 / 1)
							for (x = x57, xp_1 = x57_p_0, xp_0 = 0;
								x < x57 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
								// T (w, 3) (3 / 1)
								for (w = w26, wp_0 = 0;
									w < w26 + 3;
									w += 1, wp_0 += 1){
											mem_vec_692 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_693 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_694 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_695 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_696 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_697 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_698 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_699 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_700 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_701 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_702 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_703 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_704 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_705 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_706 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_707 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_708 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_709 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_710 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_711 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_712 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_713 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
											// T (c, 8) (8 / 1)
											for (c = c83, cp_3 = c83_p_2, cp_2 = c83_p_1, cp_1 = c83_p_0, cp_0 = 0;
												c < c83 + 8;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_692);
												mem_vec_692 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_693);
												mem_vec_693 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_694);
												mem_vec_694 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_695);
												mem_vec_695 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_696);
												mem_vec_696 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_697);
												mem_vec_697 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_698);
												mem_vec_698 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_699);
												mem_vec_699 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_700);
												mem_vec_700 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_701);
												mem_vec_701 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_702);
												mem_vec_702 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_703);
												mem_vec_703 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_704);
												mem_vec_704 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_705);
												mem_vec_705 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_706);
												mem_vec_706 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_707);
												mem_vec_707 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_708);
												mem_vec_708 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_709);
												mem_vec_709 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_710);
												mem_vec_710 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_711);
												mem_vec_711 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_712);
												mem_vec_712 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_713);
												mem_vec_713 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_36 = _mm256_set1_ps(scal_11);
												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_692);
												mem_vec_692 = vec_35;

												vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_693);
												mem_vec_693 = vec_38;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_37, mem_vec_694);
												mem_vec_694 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_39, mem_vec_695);
												mem_vec_695 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_696);
												mem_vec_696 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_39, mem_vec_697);
												mem_vec_697 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_37, mem_vec_698);
												mem_vec_698 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_39, mem_vec_699);
												mem_vec_699 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_37, mem_vec_700);
												mem_vec_700 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_39, mem_vec_701);
												mem_vec_701 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_702);
												mem_vec_702 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_703);
												mem_vec_703 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_37, mem_vec_704);
												mem_vec_704 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_39, mem_vec_705);
												mem_vec_705 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_37, mem_vec_706);
												mem_vec_706 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_39, mem_vec_707);
												mem_vec_707 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_708);
												mem_vec_708 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_709);
												mem_vec_709 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_37, mem_vec_710);
												mem_vec_710 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_39, mem_vec_711);
												mem_vec_711 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_37, mem_vec_712);
												mem_vec_712 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_39, mem_vec_713);
												mem_vec_713 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_71 = _mm256_set1_ps(scal_22);
												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_692);
												mem_vec_692 = vec_70;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_693);
												mem_vec_693 = vec_73;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_72, mem_vec_694);
												mem_vec_694 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_74, mem_vec_695);
												mem_vec_695 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_72, mem_vec_696);
												mem_vec_696 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_74, mem_vec_697);
												mem_vec_697 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_72, mem_vec_698);
												mem_vec_698 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_74, mem_vec_699);
												mem_vec_699 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_72, mem_vec_700);
												mem_vec_700 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_74, mem_vec_701);
												mem_vec_701 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_702);
												mem_vec_702 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_703);
												mem_vec_703 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_72, mem_vec_704);
												mem_vec_704 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_74, mem_vec_705);
												mem_vec_705 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_72, mem_vec_706);
												mem_vec_706 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_74, mem_vec_707);
												mem_vec_707 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_708);
												mem_vec_708 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_709);
												mem_vec_709 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_72, mem_vec_710);
												mem_vec_710 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_74, mem_vec_711);
												mem_vec_711 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_72, mem_vec_712);
												mem_vec_712 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_74, mem_vec_713);
												mem_vec_713 = vec_104;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_692);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_693);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_694);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_695);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_696);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_697);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_698);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_699);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_700);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_701);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_702);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_703);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_704);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_705);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_706);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_707);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_708);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_709);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_710);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_711);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_712);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_713);
								}
							}
						}
					}
				}
			}
		}
}


}