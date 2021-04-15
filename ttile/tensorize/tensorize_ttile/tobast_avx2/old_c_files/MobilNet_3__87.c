#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (128, c); Hoist_vars [c]; T (4, x);
  T (3, h); T (2, f); T (7, x);
  Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))]; T (1, f);
  T (1, c); T (2, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1166_p_0, cp_1, c1166, f, fp_0, f1208_p_0, f1209_p_0, fp_1, f1208_p_1, fp_2, f1208, f1209, h, hp_0, x, xp_0, x1416_p_0, x1417_p_0, xp_1, x1416_p_1, xp_2, x1416, x1417, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y708 = 0;
IND_TYPE x1418 = 0;
IND_TYPE h470 = 0;
IND_TYPE w = 0;
IND_TYPE c1167 = 0;
IND_TYPE f1210 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_12592 ,mem_vec_12593 ,mem_vec_12594 ,mem_vec_12595 ,mem_vec_12596 ,mem_vec_12597 ,mem_vec_12598 ,mem_vec_12599 ,mem_vec_12600 ,mem_vec_12601 ,mem_vec_12602 ,mem_vec_12603 ,mem_vec_12604 ,mem_vec_12605 ,mem_vec_12606 ,mem_vec_12607 ,mem_vec_12608 ,mem_vec_12609 ,mem_vec_12610 ,mem_vec_12611 ,mem_vec_12612 ,mem_vec_12613 ,mem_vec_12614 ,mem_vec_12615 ,mem_vec_12616 ,mem_vec_12617 ,mem_vec_12618 ,mem_vec_12619 ,mem_vec_12620 ,mem_vec_12621 ,mem_vec_12622 ,mem_vec_12623 ,mem_vec_12624 ,mem_vec_12625 ,mem_vec_12626 ,mem_vec_12627 ,mem_vec_12628 ,mem_vec_12629 ,mem_vec_12630 ,mem_vec_12631 ,mem_vec_12632 ,mem_vec_12633 ,mem_vec_12634 ,mem_vec_12635 ,mem_vec_12636 ,mem_vec_12637 ,mem_vec_12638 ,mem_vec_12639 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f1209 = f1210, f1209_p_0 = 0;
	f1209 < f1210 + 128;
	f1209 += 64, f1209_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 64
	// T (x, 2) (56 / 28)
	for (x1417 = x1418, x1417_p_0 = 0;
		x1417 < x1418 + 56;
		x1417 += 28, x1417_p_0 += 28){
		// y = 56, x = 28, h = 3, w = 3, c = 128, f = 64
		// T (c, 1) (128 / 128)
		for (c1166 = c1167, c1166_p_0 = 0;
			c1166 < c1167 + 128;
			c1166 += 128, c1166_p_0 += 128){
			// y = 56, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (f, 1) (64 / 64)
			for (f1208 = f1209, f1208_p_1 = f1209_p_0, f1208_p_0 = 0;
				f1208 < f1209 + 64;
				f1208 += 64, f1208_p_1 += 64, f1208_p_0 += 64){
					for (y = y708, yp_0 = 0;
						y < y708 + 35;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
						// T (x, 7) (28 / 4)
						for (x1416 = x1417, x1416_p_1 = x1417_p_0, x1416_p_0 = 0;
							x1416 < x1417 + 28;
							x1416 += 4, x1416_p_1 += 4, x1416_p_0 += 4){
							// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1208, fp_2 = f1208_p_1, fp_1 = f1208_p_0, fp_0 = 0;
								f < f1208 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 32
								// T (h, 3) (3 / 1)
								for (h = h470, hp_0 = 0;
									h < h470 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 3, c = 128, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1416, xp_2 = x1416_p_1, xp_1 = x1416_p_0, xp_0 = 0;
										x < x1416 + 4;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_12592 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_12593 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_12594 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_12595 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_12596 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_12597 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_12598 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_12599 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_12600 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_12601 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_12602 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_12603 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_12604 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_12605 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_12606 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_12607 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_12608 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_12609 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_12610 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_12611 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c1166, cp_1 = c1166_p_0, cp_0 = 0;
													c < c1166 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12592);
													mem_vec_12592 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12593);
													mem_vec_12593 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12594);
													mem_vec_12594 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12595);
													mem_vec_12595 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12596);
													mem_vec_12596 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12597);
													mem_vec_12597 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12598);
													mem_vec_12598 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12599);
													mem_vec_12599 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12600);
													mem_vec_12600 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12601);
													mem_vec_12601 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12602);
													mem_vec_12602 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12603);
													mem_vec_12603 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12604);
													mem_vec_12604 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12605);
													mem_vec_12605 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12606);
													mem_vec_12606 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12607);
													mem_vec_12607 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12608);
													mem_vec_12608 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12609);
													mem_vec_12609 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12610);
													mem_vec_12610 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12611);
													mem_vec_12611 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_12592);
													mem_vec_12592 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_12593);
													mem_vec_12593 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_12594);
													mem_vec_12594 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_12595);
													mem_vec_12595 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_12596);
													mem_vec_12596 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_12597);
													mem_vec_12597 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_12598);
													mem_vec_12598 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_12599);
													mem_vec_12599 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_12600);
													mem_vec_12600 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_12601);
													mem_vec_12601 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_12602);
													mem_vec_12602 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_12603);
													mem_vec_12603 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_12604);
													mem_vec_12604 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_12605);
													mem_vec_12605 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_12606);
													mem_vec_12606 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_12607);
													mem_vec_12607 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_12608);
													mem_vec_12608 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_12609);
													mem_vec_12609 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_12610);
													mem_vec_12610 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_12611);
													mem_vec_12611 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_12592);
													mem_vec_12592 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_12593);
													mem_vec_12593 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_12594);
													mem_vec_12594 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_12595);
													mem_vec_12595 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_12596);
													mem_vec_12596 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_12597);
													mem_vec_12597 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_12598);
													mem_vec_12598 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_12599);
													mem_vec_12599 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_12600);
													mem_vec_12600 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_12601);
													mem_vec_12601 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_12602);
													mem_vec_12602 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_12603);
													mem_vec_12603 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_12604);
													mem_vec_12604 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_12605);
													mem_vec_12605 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_12606);
													mem_vec_12606 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_12607);
													mem_vec_12607 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_12608);
													mem_vec_12608 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_12609);
													mem_vec_12609 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_12610);
													mem_vec_12610 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_12611);
													mem_vec_12611 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12592);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12593);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12594);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12595);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12596);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12597);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12598);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12599);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12600);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12601);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12602);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12603);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12604);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12605);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12606);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12607);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12608);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12609);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12610);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12611);
									}
								}
							}
						}
					}
					for (y = y708 + 35, yp_0 = 0;
						y < y708 + 35 + 21;
						y += 7, yp_0 += 7){
						// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
						// T (x, 7) (28 / 4)
						for (x1416 = x1417, x1416_p_1 = x1417_p_0, x1416_p_0 = 0;
							x1416 < x1417 + 28;
							x1416 += 4, x1416_p_1 += 4, x1416_p_0 += 4){
							// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1208, fp_2 = f1208_p_1, fp_1 = f1208_p_0, fp_0 = 0;
								f < f1208 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 32
								// T (h, 3) (3 / 1)
								for (h = h470, hp_0 = 0;
									h < h470 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 3, c = 128, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1416, xp_2 = x1416_p_1, xp_1 = x1416_p_0, xp_0 = 0;
										x < x1416 + 4;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_12612 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_12613 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_12614 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_12615 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_12616 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_12617 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_12618 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_12619 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_12620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_12621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_12622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_12623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_12624 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_12625 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_12626 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_12627 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_12628 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_12629 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_12630 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_12631 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_12632 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_12633 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_12634 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_12635 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_12636 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_12637 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_12638 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_12639 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c1166, cp_1 = c1166_p_0, cp_0 = 0;
													c < c1166 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12612);
													mem_vec_12612 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12613);
													mem_vec_12613 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12614);
													mem_vec_12614 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12615);
													mem_vec_12615 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12616);
													mem_vec_12616 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12617);
													mem_vec_12617 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12618);
													mem_vec_12618 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12619);
													mem_vec_12619 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12620);
													mem_vec_12620 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12621);
													mem_vec_12621 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12622);
													mem_vec_12622 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12623);
													mem_vec_12623 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12624);
													mem_vec_12624 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12625);
													mem_vec_12625 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12626);
													mem_vec_12626 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12627);
													mem_vec_12627 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12628);
													mem_vec_12628 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12629);
													mem_vec_12629 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12630);
													mem_vec_12630 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12631);
													mem_vec_12631 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_12632);
													mem_vec_12632 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_12633);
													mem_vec_12633 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_12634);
													mem_vec_12634 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_12635);
													mem_vec_12635 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_12636);
													mem_vec_12636 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_12637);
													mem_vec_12637 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_12638);
													mem_vec_12638 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_12639);
													mem_vec_12639 = vec_38;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_12612);
													mem_vec_12612 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_12613);
													mem_vec_12613 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_12614);
													mem_vec_12614 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_12615);
													mem_vec_12615 = vec_46;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_12616);
													mem_vec_12616 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_12617);
													mem_vec_12617 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_12618);
													mem_vec_12618 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_12619);
													mem_vec_12619 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_12620);
													mem_vec_12620 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_12621);
													mem_vec_12621 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_12622);
													mem_vec_12622 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_12623);
													mem_vec_12623 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_12624);
													mem_vec_12624 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_12625);
													mem_vec_12625 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_12626);
													mem_vec_12626 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_12627);
													mem_vec_12627 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_12628);
													mem_vec_12628 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_12629);
													mem_vec_12629 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_12630);
													mem_vec_12630 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_12631);
													mem_vec_12631 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_12632);
													mem_vec_12632 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_12633);
													mem_vec_12633 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_12634);
													mem_vec_12634 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_12635);
													mem_vec_12635 = vec_72;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_12636);
													mem_vec_12636 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_12637);
													mem_vec_12637 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_12638);
													mem_vec_12638 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_12639);
													mem_vec_12639 = vec_77;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_12612);
													mem_vec_12612 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_12613);
													mem_vec_12613 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_12614);
													mem_vec_12614 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_12615);
													mem_vec_12615 = vec_85;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_12616);
													mem_vec_12616 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_12617);
													mem_vec_12617 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_12618);
													mem_vec_12618 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_12619);
													mem_vec_12619 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_12620);
													mem_vec_12620 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_12621);
													mem_vec_12621 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_12622);
													mem_vec_12622 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_12623);
													mem_vec_12623 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_12624);
													mem_vec_12624 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_12625);
													mem_vec_12625 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_12626);
													mem_vec_12626 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_12627);
													mem_vec_12627 = vec_101;
													scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_12628);
													mem_vec_12628 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_12629);
													mem_vec_12629 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_12630);
													mem_vec_12630 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_12631);
													mem_vec_12631 = vec_106;
													scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_12632);
													mem_vec_12632 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_12633);
													mem_vec_12633 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_12634);
													mem_vec_12634 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_12635);
													mem_vec_12635 = vec_111;
													scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_12636);
													mem_vec_12636 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_12637);
													mem_vec_12637 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_12638);
													mem_vec_12638 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_12639);
													mem_vec_12639 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12612);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12613);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12614);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12615);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12616);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12617);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12618);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12619);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12620);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12621);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12622);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12623);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12624);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12625);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12626);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12627);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12628);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12629);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12630);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12631);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12632);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_12633);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12634);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_12635);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_12636);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_12637);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_12638);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_12639);
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