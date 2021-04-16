#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (1, c);
  Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))]; T (56, x);
  T (2, f); T (2, c); T (2, f)]
*/
IND_TYPE c, cp_0, c64_p_0, c65_p_0, cp_1, c64_p_1, cp_2, c64, c65, f, fp_0, f48_p_0, fp_1, f48, h, hp_0, x, xp_0, x48_p_0, xp_1, x48, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y32 = 0;
IND_TYPE x49 = 0;
IND_TYPE h24 = 0;
IND_TYPE w = 0;
IND_TYPE c66 = 0;
IND_TYPE f49 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,mem_vec_664 ,mem_vec_665 ,mem_vec_666 ,mem_vec_667 ,mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,mem_vec_672 ,mem_vec_673 ,mem_vec_674 ,mem_vec_675 ,mem_vec_676 ,mem_vec_677 ,mem_vec_678 ,mem_vec_679 ,mem_vec_680 ,mem_vec_681 ,mem_vec_682 ,mem_vec_683 ,mem_vec_684 ,mem_vec_685 ,mem_vec_686 ,mem_vec_687 ,mem_vec_688 ,mem_vec_689 ,mem_vec_690 ,mem_vec_691 ,mem_vec_692 ,mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f48 = f49, f48_p_0 = 0;
	f48 < f49 + 128;
	f48 += 64, f48_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 64
	// T (c, 2) (128 / 64)
	for (c65 = c66, c65_p_0 = 0;
		c65 < c66 + 128;
		c65 += 64, c65_p_0 += 64){
		// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
		// T (f, 2) (64 / 32)
		for (f = f48, fp_1 = f48_p_0, fp_0 = 0;
			f < f48 + 64;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
			// T (x, 56) (56 / 1)
			for (x48 = x49, x48_p_0 = 0;
				x48 < x49 + 56;
				x48 += 1, x48_p_0 += 1){
					for (y = y32, yp_0 = 0;
						y < y32 + 28;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (c, 1) (64 / 64)
						for (c64 = c65, c64_p_1 = c65_p_0, c64_p_0 = 0;
							c64 < c65 + 64;
							c64 += 64, c64_p_1 += 64, c64_p_0 += 64){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h24, hp_0 = 0;
								h < h24 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x48, xp_1 = x48_p_0, xp_0 = 0;
									x < x48 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_656 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_657 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_658 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_659 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_660 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_661 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_662 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_663 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_664 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_665 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_666 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_667 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_668 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_669 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_670 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_671 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c64, cp_2 = c64_p_1, cp_1 = c64_p_0, cp_0 = 0;
												c < c64 + 64;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_656);
												mem_vec_656 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_657);
												mem_vec_657 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_658);
												mem_vec_658 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_659);
												mem_vec_659 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_660);
												mem_vec_660 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_661);
												mem_vec_661 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_662);
												mem_vec_662 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_663);
												mem_vec_663 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_664);
												mem_vec_664 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_665);
												mem_vec_665 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_666);
												mem_vec_666 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_667);
												mem_vec_667 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_668);
												mem_vec_668 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_669);
												mem_vec_669 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_670);
												mem_vec_670 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_671);
												mem_vec_671 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_656);
												mem_vec_656 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_657);
												mem_vec_657 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_658);
												mem_vec_658 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_659);
												mem_vec_659 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_660);
												mem_vec_660 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_661);
												mem_vec_661 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_662);
												mem_vec_662 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_663);
												mem_vec_663 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_664);
												mem_vec_664 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_665);
												mem_vec_665 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_666);
												mem_vec_666 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_667);
												mem_vec_667 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_668);
												mem_vec_668 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_669);
												mem_vec_669 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_670);
												mem_vec_670 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_671);
												mem_vec_671 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_656);
												mem_vec_656 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_657);
												mem_vec_657 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_658);
												mem_vec_658 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_659);
												mem_vec_659 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_660);
												mem_vec_660 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_661);
												mem_vec_661 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_662);
												mem_vec_662 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_663);
												mem_vec_663 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_664);
												mem_vec_664 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_665);
												mem_vec_665 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_666);
												mem_vec_666 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_667);
												mem_vec_667 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_668);
												mem_vec_668 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_669);
												mem_vec_669 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_670);
												mem_vec_670 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_671);
												mem_vec_671 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_656);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_657);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_658);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_659);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_660);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_661);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_662);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_663);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_664);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_665);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_666);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_667);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_668);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_669);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_670);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_671);
								}
							}
						}
					}
					for (y = y32 + 28, yp_0 = 0;
						y < y32 + 28 + 28;
						y += 7, yp_0 += 7){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (c, 1) (64 / 64)
						for (c64 = c65, c64_p_1 = c65_p_0, c64_p_0 = 0;
							c64 < c65 + 64;
							c64 += 64, c64_p_1 += 64, c64_p_0 += 64){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h24, hp_0 = 0;
								h < h24 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x48, xp_1 = x48_p_0, xp_0 = 0;
									x < x48 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_672 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_673 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_674 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_675 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_676 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_677 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_678 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_679 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_680 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_681 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_682 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_683 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_684 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_685 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_686 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_687 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_688 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_689 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_690 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_691 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_692 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_693 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_694 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_695 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											mem_vec_696 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_697 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_698 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_699 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c64, cp_2 = c64_p_1, cp_1 = c64_p_0, cp_0 = 0;
												c < c64 + 64;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_672);
												mem_vec_672 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_673);
												mem_vec_673 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_674);
												mem_vec_674 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_675);
												mem_vec_675 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_676);
												mem_vec_676 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_677);
												mem_vec_677 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_678);
												mem_vec_678 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_679);
												mem_vec_679 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_680);
												mem_vec_680 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_681);
												mem_vec_681 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_682);
												mem_vec_682 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_683);
												mem_vec_683 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_684);
												mem_vec_684 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_685);
												mem_vec_685 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_686);
												mem_vec_686 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_687);
												mem_vec_687 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_688);
												mem_vec_688 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_689);
												mem_vec_689 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_690);
												mem_vec_690 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_691);
												mem_vec_691 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_692);
												mem_vec_692 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_693);
												mem_vec_693 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_694);
												mem_vec_694 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_695);
												mem_vec_695 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_696);
												mem_vec_696 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_697);
												mem_vec_697 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_698);
												mem_vec_698 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_699);
												mem_vec_699 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_40 = _mm256_set1_ps(scal_7);
												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_672);
												mem_vec_672 = vec_39;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_673);
												mem_vec_673 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_674);
												mem_vec_674 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_675);
												mem_vec_675 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_676);
												mem_vec_676 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_677);
												mem_vec_677 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_678);
												mem_vec_678 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_679);
												mem_vec_679 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_680);
												mem_vec_680 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_681);
												mem_vec_681 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_682);
												mem_vec_682 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_683);
												mem_vec_683 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_684);
												mem_vec_684 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_685);
												mem_vec_685 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_686);
												mem_vec_686 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_687);
												mem_vec_687 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_688);
												mem_vec_688 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_689);
												mem_vec_689 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_690);
												mem_vec_690 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_691);
												mem_vec_691 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);


												vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_692);
												mem_vec_692 = vec_68;



												vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_693);
												mem_vec_693 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_694);
												mem_vec_694 = vec_71;



												vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_695);
												mem_vec_695 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_74 = _mm256_set1_ps(scal_13);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_696);
												mem_vec_696 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_697);
												mem_vec_697 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_698);
												mem_vec_698 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_699);
												mem_vec_699 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_79 = _mm256_set1_ps(scal_14);
												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_672);
												mem_vec_672 = vec_78;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_673);
												mem_vec_673 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_674);
												mem_vec_674 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_675);
												mem_vec_675 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_676);
												mem_vec_676 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_677);
												mem_vec_677 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_678);
												mem_vec_678 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_679);
												mem_vec_679 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_680);
												mem_vec_680 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_681);
												mem_vec_681 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_682);
												mem_vec_682 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_683);
												mem_vec_683 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_684);
												mem_vec_684 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_685);
												mem_vec_685 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_686);
												mem_vec_686 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_687);
												mem_vec_687 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_103 = _mm256_set1_ps(scal_18);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_688);
												mem_vec_688 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_689);
												mem_vec_689 = vec_104;



												vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_690);
												mem_vec_690 = vec_105;



												vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_691);
												mem_vec_691 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_108 = _mm256_set1_ps(scal_19);


												vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_692);
												mem_vec_692 = vec_107;



												vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_693);
												mem_vec_693 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_694);
												mem_vec_694 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_695);
												mem_vec_695 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_113 = _mm256_set1_ps(scal_20);


												vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_696);
												mem_vec_696 = vec_112;



												vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_697);
												mem_vec_697 = vec_114;



												vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_698);
												mem_vec_698 = vec_115;



												vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_699);
												mem_vec_699 = vec_116;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_672);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_673);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_674);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_675);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_676);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_677);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_678);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_679);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_680);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_681);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_682);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_683);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_684);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_685);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_686);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_687);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_688);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_689);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_690);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_691);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_692);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_693);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_694);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_695);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_696);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_697);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_698);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_699);
								}
							}
						}
					}
			}
		}
	}
}


}