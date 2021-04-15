#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (4, x);
  T (3, w); Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))];
  T (1, f); T (16, c); T (2, f); T (1, c); T (14, x); T (1, f)]
*/
IND_TYPE c, cp_0, c860_p_0, c861_p_0, cp_1, c860_p_1, cp_2, c860, c861, f, fp_0, f764_p_0, f765_p_0, fp_1, f764_p_1, fp_2, f764, f765, w, wp_0, x, xp_0, x792_p_0, xp_1, x792, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y472 = 0;
IND_TYPE x793 = 0;
IND_TYPE h = 0;
IND_TYPE w386 = 0;
IND_TYPE c862 = 0;
IND_TYPE f766 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6600 ,mem_vec_6601 ,mem_vec_6602 ,mem_vec_6603 ,mem_vec_6604 ,mem_vec_6605 ,mem_vec_6606 ,mem_vec_6607 ,mem_vec_6608 ,mem_vec_6609 ,mem_vec_6610 ,mem_vec_6611 ,mem_vec_6612 ,mem_vec_6613 ,mem_vec_6614 ,mem_vec_6615 ,mem_vec_6616 ,mem_vec_6617 ,mem_vec_6618 ,mem_vec_6619 ,mem_vec_6620 ,mem_vec_6621 ,mem_vec_6622 ,mem_vec_6623 ,mem_vec_6624 ,mem_vec_6625 ,mem_vec_6626 ,mem_vec_6627 ,mem_vec_6628 ,mem_vec_6629 ,mem_vec_6630 ,mem_vec_6631 ,mem_vec_6632 ,mem_vec_6633 ,mem_vec_6634 ,mem_vec_6635 ,mem_vec_6636 ,mem_vec_6637 ,mem_vec_6638 ,mem_vec_6639 ,mem_vec_6640 ,mem_vec_6641 ,mem_vec_6642 ,mem_vec_6643 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f765 = f766, f765_p_0 = 0;
	f765 < f766 + 64;
	f765 += 64, f765_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (x, 14) (56 / 4)
	for (x792 = x793, x792_p_0 = 0;
		x792 < x793 + 56;
		x792 += 4, x792_p_0 += 4){
		// y = 56, x = 4, h = 3, w = 3, c = 64, f = 64
		// T (c, 1) (64 / 64)
		for (c861 = c862, c861_p_0 = 0;
			c861 < c862 + 64;
			c861 += 64, c861_p_0 += 64){
			// y = 56, x = 4, h = 3, w = 3, c = 64, f = 64
			// T (f, 2) (64 / 32)
			for (f764 = f765, f764_p_1 = f765_p_0, f764_p_0 = 0;
				f764 < f765 + 64;
				f764 += 32, f764_p_1 += 32, f764_p_0 += 32){
				// y = 56, x = 4, h = 3, w = 3, c = 64, f = 32
				// T (c, 16) (64 / 4)
				for (c860 = c861, c860_p_1 = c861_p_0, c860_p_0 = 0;
					c860 < c861 + 64;
					c860 += 4, c860_p_1 += 4, c860_p_0 += 4){
					// y = 56, x = 4, h = 3, w = 3, c = 4, f = 32
					// T (f, 1) (32 / 32)
					for (f = f764, fp_2 = f764_p_1, fp_1 = f764_p_0, fp_0 = 0;
						f < f764 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y472, yp_0 = 0;
								y < y472 + 28;
								y += 4, yp_0 += 4){
								// y = ph_y, x = 4, h = 3, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w386, wp_0 = 0;
									w < w386 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 3, w = 1, c = 4, f = 32
									// T (x, 4) (4 / 1)
									for (x = x792, xp_1 = x792_p_0, xp_0 = 0;
										x < x792 + 4;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6600 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6601 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_6602 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6603 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_6604 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6605 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_6606 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6607 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_6608 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6609 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_6610 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6611 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_6612 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6613 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_6614 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6615 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c860, cp_2 = c860_p_1, cp_1 = c860_p_0, cp_0 = 0;
													c < c860 + 4;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6600);
													mem_vec_6600 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6601);
													mem_vec_6601 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6602);
													mem_vec_6602 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6603);
													mem_vec_6603 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6604);
													mem_vec_6604 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6605);
													mem_vec_6605 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6606);
													mem_vec_6606 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6607);
													mem_vec_6607 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6608);
													mem_vec_6608 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6609);
													mem_vec_6609 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6610);
													mem_vec_6610 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6611);
													mem_vec_6611 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6612);
													mem_vec_6612 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6613);
													mem_vec_6613 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6614);
													mem_vec_6614 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6615);
													mem_vec_6615 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_6600);
													mem_vec_6600 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_6601);
													mem_vec_6601 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_6602);
													mem_vec_6602 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_6603);
													mem_vec_6603 = vec_31;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_6604);
													mem_vec_6604 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_6605);
													mem_vec_6605 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_6606);
													mem_vec_6606 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_6607);
													mem_vec_6607 = vec_37;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_6608);
													mem_vec_6608 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_6609);
													mem_vec_6609 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_6610);
													mem_vec_6610 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_6611);
													mem_vec_6611 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_6612);
													mem_vec_6612 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_6613);
													mem_vec_6613 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_6614);
													mem_vec_6614 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_6615);
													mem_vec_6615 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_6600);
													mem_vec_6600 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_6601);
													mem_vec_6601 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_6602);
													mem_vec_6602 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_6603);
													mem_vec_6603 = vec_55;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_6604);
													mem_vec_6604 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_6605);
													mem_vec_6605 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_6606);
													mem_vec_6606 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_6607);
													mem_vec_6607 = vec_61;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_6608);
													mem_vec_6608 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_6609);
													mem_vec_6609 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_6610);
													mem_vec_6610 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_6611);
													mem_vec_6611 = vec_66;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_6612);
													mem_vec_6612 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_6613);
													mem_vec_6613 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_6614);
													mem_vec_6614 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_6615);
													mem_vec_6615 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6600);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6601);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6602);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6603);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6604);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6605);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6606);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6607);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6608);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6609);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6610);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6611);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6612);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6613);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6614);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6615);
									}
								}
							}
							for (y = y472 + 28, yp_0 = 0;
								y < y472 + 28 + 28;
								y += 7, yp_0 += 7){
								// y = ph_y, x = 4, h = 3, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w386, wp_0 = 0;
									w < w386 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 3, w = 1, c = 4, f = 32
									// T (x, 4) (4 / 1)
									for (x = x792, xp_1 = x792_p_0, xp_0 = 0;
										x < x792 + 4;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6616 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6617 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_6618 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6619 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_6620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_6622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_6624 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6625 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_6626 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6627 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_6628 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6629 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_6630 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6631 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_6632 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6633 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_6634 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6635 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_6636 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6637 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_6638 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_6639 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_6640 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6641 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_6642 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_6643 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c860, cp_2 = c860_p_1, cp_1 = c860_p_0, cp_0 = 0;
													c < c860 + 4;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6616);
													mem_vec_6616 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6617);
													mem_vec_6617 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6618);
													mem_vec_6618 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6619);
													mem_vec_6619 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6620);
													mem_vec_6620 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6621);
													mem_vec_6621 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6622);
													mem_vec_6622 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6623);
													mem_vec_6623 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6624);
													mem_vec_6624 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6625);
													mem_vec_6625 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6626);
													mem_vec_6626 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6627);
													mem_vec_6627 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6628);
													mem_vec_6628 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6629);
													mem_vec_6629 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6630);
													mem_vec_6630 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6631);
													mem_vec_6631 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6632);
													mem_vec_6632 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6633);
													mem_vec_6633 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6634);
													mem_vec_6634 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6635);
													mem_vec_6635 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6636);
													mem_vec_6636 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6637);
													mem_vec_6637 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_6638);
													mem_vec_6638 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_6639);
													mem_vec_6639 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_6640);
													mem_vec_6640 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_6641);
													mem_vec_6641 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_6642);
													mem_vec_6642 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_6643);
													mem_vec_6643 = vec_38;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_6616);
													mem_vec_6616 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_6617);
													mem_vec_6617 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_6618);
													mem_vec_6618 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_6619);
													mem_vec_6619 = vec_46;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_6620);
													mem_vec_6620 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_6621);
													mem_vec_6621 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_6622);
													mem_vec_6622 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_6623);
													mem_vec_6623 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_6624);
													mem_vec_6624 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_6625);
													mem_vec_6625 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_6626);
													mem_vec_6626 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_6627);
													mem_vec_6627 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_6628);
													mem_vec_6628 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_6629);
													mem_vec_6629 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_6630);
													mem_vec_6630 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_6631);
													mem_vec_6631 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_6632);
													mem_vec_6632 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_6633);
													mem_vec_6633 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_6634);
													mem_vec_6634 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_6635);
													mem_vec_6635 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_6636);
													mem_vec_6636 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_6637);
													mem_vec_6637 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_6638);
													mem_vec_6638 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_6639);
													mem_vec_6639 = vec_72;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_6640);
													mem_vec_6640 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_6641);
													mem_vec_6641 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_6642);
													mem_vec_6642 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_6643);
													mem_vec_6643 = vec_77;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_6616);
													mem_vec_6616 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_6617);
													mem_vec_6617 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_6618);
													mem_vec_6618 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_6619);
													mem_vec_6619 = vec_85;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_6620);
													mem_vec_6620 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_6621);
													mem_vec_6621 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_6622);
													mem_vec_6622 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_6623);
													mem_vec_6623 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_6624);
													mem_vec_6624 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_6625);
													mem_vec_6625 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_6626);
													mem_vec_6626 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_6627);
													mem_vec_6627 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_6628);
													mem_vec_6628 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_6629);
													mem_vec_6629 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_6630);
													mem_vec_6630 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_6631);
													mem_vec_6631 = vec_101;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_6632);
													mem_vec_6632 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_6633);
													mem_vec_6633 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_6634);
													mem_vec_6634 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_6635);
													mem_vec_6635 = vec_106;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_6636);
													mem_vec_6636 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_6637);
													mem_vec_6637 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_6638);
													mem_vec_6638 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_6639);
													mem_vec_6639 = vec_111;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_6640);
													mem_vec_6640 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_6641);
													mem_vec_6641 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_6642);
													mem_vec_6642 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_6643);
													mem_vec_6643 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6616);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6617);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6618);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6619);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6620);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6621);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6622);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6623);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6624);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6625);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6626);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6627);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6628);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6629);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6630);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6631);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6632);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6633);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6634);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6635);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6636);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6637);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6638);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_6639);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6640);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6641);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6642);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_6643);
									}
								}
							}
					}
				}
			}
		}
	}
}


}