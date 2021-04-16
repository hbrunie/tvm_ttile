#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (8, x);
  T (3, w); T (4, c); T (1, f);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (7, x);
  T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c444_p_0, cp_1, c444, f, fp_0, f577_p_0, f578_p_0, fp_1, f577_p_1, fp_2, f577, f578, w, wp_0, x, xp_0, x445_p_0, xp_1, x445, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y302 = 0;
IND_TYPE x446 = 0;
IND_TYPE h = 0;
IND_TYPE w234 = 0;
IND_TYPE c445 = 0;
IND_TYPE f579 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_5612 ,mem_vec_5613 ,mem_vec_5614 ,mem_vec_5615 ,mem_vec_5616 ,mem_vec_5617 ,mem_vec_5618 ,mem_vec_5619 ,mem_vec_5620 ,mem_vec_5621 ,mem_vec_5622 ,mem_vec_5623 ,mem_vec_5624 ,mem_vec_5625 ,mem_vec_5626 ,mem_vec_5627 ,mem_vec_5628 ,mem_vec_5629 ,mem_vec_5630 ,mem_vec_5631 ,mem_vec_5632 ,mem_vec_5633 ,mem_vec_5634 ,mem_vec_5635 ,mem_vec_5636 ,mem_vec_5637 ,mem_vec_5638 ,mem_vec_5639 ,mem_vec_5640 ,mem_vec_5641 ,mem_vec_5642 ,mem_vec_5643 ,mem_vec_5644 ,mem_vec_5645 ,mem_vec_5646 ,mem_vec_5647 ,mem_vec_5648 ,mem_vec_5649 ,mem_vec_5650 ,mem_vec_5651 ,mem_vec_5652 ,mem_vec_5653 ,mem_vec_5654 ,mem_vec_5655 ,mem_vec_5656 ,mem_vec_5657 ,mem_vec_5658 ,mem_vec_5659 ,mem_vec_5660 ,mem_vec_5661 ,mem_vec_5662 ,mem_vec_5663 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 2) (64 / 32)
for (f578 = f579, f578_p_0 = 0;
	f578 < f579 + 64;
	f578 += 32, f578_p_0 += 32){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
	// T (f, 1) (32 / 32)
	for (f577 = f578, f577_p_1 = f578_p_0, f577_p_0 = 0;
		f577 < f578 + 32;
		f577 += 32, f577_p_1 += 32, f577_p_0 += 32){
		// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
		// T (x, 7) (56 / 8)
		for (x445 = x446, x445_p_0 = 0;
			x445 < x446 + 56;
			x445 += 8, x445_p_0 += 8){
				for (y = y302, yp_0 = 0;
					y < y302 + 42;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 32
					// T (f, 1) (32 / 32)
					for (f = f577, fp_2 = f577_p_1, fp_1 = f577_p_0, fp_0 = 0;
						f < f577 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 32
						// T (c, 4) (64 / 16)
						for (c444 = c445, c444_p_0 = 0;
							c444 < c445 + 64;
							c444 += 16, c444_p_0 += 16){
							// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w234, wp_0 = 0;
								w < w234 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 3, w = 1, c = 16, f = 32
								// T (x, 8) (8 / 1)
								for (x = x445, xp_1 = x445_p_0, xp_0 = 0;
									x < x445 + 8;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5612 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5613 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5614 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5615 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_5616 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5617 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5618 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5619 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_5620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_5624 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5625 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5626 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5627 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_5628 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5629 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_5630 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5631 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_5632 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5633 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_5634 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5635 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c444, cp_1 = c444_p_0, cp_0 = 0;
												c < c444 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5612);
												mem_vec_5612 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5613);
												mem_vec_5613 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5614);
												mem_vec_5614 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5615);
												mem_vec_5615 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5616);
												mem_vec_5616 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5617);
												mem_vec_5617 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5618);
												mem_vec_5618 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5619);
												mem_vec_5619 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5620);
												mem_vec_5620 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5621);
												mem_vec_5621 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5622);
												mem_vec_5622 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5623);
												mem_vec_5623 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5624);
												mem_vec_5624 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5625);
												mem_vec_5625 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5626);
												mem_vec_5626 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5627);
												mem_vec_5627 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5628);
												mem_vec_5628 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5629);
												mem_vec_5629 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5630);
												mem_vec_5630 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5631);
												mem_vec_5631 = vec_28;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_5632);
												mem_vec_5632 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_5633);
												mem_vec_5633 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_5634);
												mem_vec_5634 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_5635);
												mem_vec_5635 = vec_33;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_5612);
												mem_vec_5612 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_5613);
												mem_vec_5613 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_5614);
												mem_vec_5614 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_5615);
												mem_vec_5615 = vec_41;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_5616);
												mem_vec_5616 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_5617);
												mem_vec_5617 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_5618);
												mem_vec_5618 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_5619);
												mem_vec_5619 = vec_47;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_5620);
												mem_vec_5620 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_5621);
												mem_vec_5621 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_5622);
												mem_vec_5622 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_5623);
												mem_vec_5623 = vec_52;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_5624);
												mem_vec_5624 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_5625);
												mem_vec_5625 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_5626);
												mem_vec_5626 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_5627);
												mem_vec_5627 = vec_57;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_5628);
												mem_vec_5628 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_5629);
												mem_vec_5629 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_5630);
												mem_vec_5630 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_5631);
												mem_vec_5631 = vec_62;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_5632);
												mem_vec_5632 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_5633);
												mem_vec_5633 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_5634);
												mem_vec_5634 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_5635);
												mem_vec_5635 = vec_67;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_5612);
												mem_vec_5612 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_5613);
												mem_vec_5613 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_5614);
												mem_vec_5614 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_5615);
												mem_vec_5615 = vec_75;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_5616);
												mem_vec_5616 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_5617);
												mem_vec_5617 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_5618);
												mem_vec_5618 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_5619);
												mem_vec_5619 = vec_81;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_5620);
												mem_vec_5620 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_5621);
												mem_vec_5621 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_5622);
												mem_vec_5622 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_5623);
												mem_vec_5623 = vec_86;
												scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_5624);
												mem_vec_5624 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_5625);
												mem_vec_5625 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_5626);
												mem_vec_5626 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_5627);
												mem_vec_5627 = vec_91;
												scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_5628);
												mem_vec_5628 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_5629);
												mem_vec_5629 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_5630);
												mem_vec_5630 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_5631);
												mem_vec_5631 = vec_96;
												scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_5632);
												mem_vec_5632 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_5633);
												mem_vec_5633 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_5634);
												mem_vec_5634 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_5635);
												mem_vec_5635 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5612);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5613);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5614);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5615);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5616);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5617);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5618);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5619);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5620);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5621);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5622);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5623);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5624);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5625);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5626);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5627);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5628);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5629);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5630);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5631);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5632);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_5633);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5634);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_5635);
								}
							}
						}
					}
				}
				for (y = y302 + 42, yp_0 = 0;
					y < y302 + 42 + 14;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 32
					// T (f, 1) (32 / 32)
					for (f = f577, fp_2 = f577_p_1, fp_1 = f577_p_0, fp_0 = 0;
						f < f577 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 32
						// T (c, 4) (64 / 16)
						for (c444 = c445, c444_p_0 = 0;
							c444 < c445 + 64;
							c444 += 16, c444_p_0 += 16){
							// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w234, wp_0 = 0;
								w < w234 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 3, w = 1, c = 16, f = 32
								// T (x, 8) (8 / 1)
								for (x = x445, xp_1 = x445_p_0, xp_0 = 0;
									x < x445 + 8;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5636 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5637 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5638 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5639 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_5640 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5641 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5642 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5643 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_5644 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5645 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5646 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5647 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_5648 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5649 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5650 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5651 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_5652 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5653 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_5654 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5655 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_5656 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5657 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_5658 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5659 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											mem_vec_5660 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5661 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_5662 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_5663 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c444, cp_1 = c444_p_0, cp_0 = 0;
												c < c444 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5636);
												mem_vec_5636 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5637);
												mem_vec_5637 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5638);
												mem_vec_5638 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5639);
												mem_vec_5639 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5640);
												mem_vec_5640 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5641);
												mem_vec_5641 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5642);
												mem_vec_5642 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5643);
												mem_vec_5643 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5644);
												mem_vec_5644 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5645);
												mem_vec_5645 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5646);
												mem_vec_5646 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5647);
												mem_vec_5647 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5648);
												mem_vec_5648 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5649);
												mem_vec_5649 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5650);
												mem_vec_5650 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5651);
												mem_vec_5651 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5652);
												mem_vec_5652 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5653);
												mem_vec_5653 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5654);
												mem_vec_5654 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5655);
												mem_vec_5655 = vec_28;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_5656);
												mem_vec_5656 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_5657);
												mem_vec_5657 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_5658);
												mem_vec_5658 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_5659);
												mem_vec_5659 = vec_33;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_5660);
												mem_vec_5660 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_5661);
												mem_vec_5661 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_5662);
												mem_vec_5662 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_5663);
												mem_vec_5663 = vec_38;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
												vec_40 = _mm256_set1_ps(scal_7);
												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_5636);
												mem_vec_5636 = vec_39;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_5637);
												mem_vec_5637 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_5638);
												mem_vec_5638 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_5639);
												mem_vec_5639 = vec_46;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_5640);
												mem_vec_5640 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_5641);
												mem_vec_5641 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_5642);
												mem_vec_5642 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_5643);
												mem_vec_5643 = vec_52;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_5644);
												mem_vec_5644 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_5645);
												mem_vec_5645 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_5646);
												mem_vec_5646 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_5647);
												mem_vec_5647 = vec_57;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_5648);
												mem_vec_5648 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_5649);
												mem_vec_5649 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_5650);
												mem_vec_5650 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_5651);
												mem_vec_5651 = vec_62;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_5652);
												mem_vec_5652 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_5653);
												mem_vec_5653 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_5654);
												mem_vec_5654 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_5655);
												mem_vec_5655 = vec_67;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
												vec_69 = _mm256_set1_ps(scal_12);


												vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_5656);
												mem_vec_5656 = vec_68;



												vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_5657);
												mem_vec_5657 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_5658);
												mem_vec_5658 = vec_71;



												vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_5659);
												mem_vec_5659 = vec_72;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_13);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_5660);
												mem_vec_5660 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_5661);
												mem_vec_5661 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_5662);
												mem_vec_5662 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_5663);
												mem_vec_5663 = vec_77;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_14);
												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_5636);
												mem_vec_5636 = vec_78;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_5637);
												mem_vec_5637 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_5638);
												mem_vec_5638 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_5639);
												mem_vec_5639 = vec_85;
												scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_5640);
												mem_vec_5640 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_5641);
												mem_vec_5641 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_5642);
												mem_vec_5642 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_5643);
												mem_vec_5643 = vec_91;
												scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_5644);
												mem_vec_5644 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_5645);
												mem_vec_5645 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_5646);
												mem_vec_5646 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_5647);
												mem_vec_5647 = vec_96;
												scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_5648);
												mem_vec_5648 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_5649);
												mem_vec_5649 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_5650);
												mem_vec_5650 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_5651);
												mem_vec_5651 = vec_101;
												scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_18);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_5652);
												mem_vec_5652 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_5653);
												mem_vec_5653 = vec_104;



												vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_5654);
												mem_vec_5654 = vec_105;



												vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_5655);
												mem_vec_5655 = vec_106;
												scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
												vec_108 = _mm256_set1_ps(scal_19);


												vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_5656);
												mem_vec_5656 = vec_107;



												vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_5657);
												mem_vec_5657 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_5658);
												mem_vec_5658 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_5659);
												mem_vec_5659 = vec_111;
												scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
												vec_113 = _mm256_set1_ps(scal_20);


												vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_5660);
												mem_vec_5660 = vec_112;



												vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_5661);
												mem_vec_5661 = vec_114;



												vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_5662);
												mem_vec_5662 = vec_115;



												vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_5663);
												mem_vec_5663 = vec_116;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5636);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5637);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5638);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5639);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5640);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5641);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5642);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5643);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5644);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5645);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5646);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5647);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5648);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5649);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5650);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5651);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5652);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5653);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5654);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5655);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5656);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_5657);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5658);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_5659);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5660);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_5661);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5662);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_5663);
								}
							}
						}
					}
				}
		}
	}
}


}