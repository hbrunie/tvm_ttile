#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (128, c); Hoist_vars [c]; T (17, x);
  T (3, h); Lambda_apply y [((Iter 5), (Arg 7)); ((Iter 3), (Arg 11))];
  T (2, f); T (1, c); T (1, f); T (4, x); T (4, f)]
*/
IND_TYPE c, cp_0, c564_p_0, cp_1, c564, f, fp_0, f724_p_0, f725_p_0, fp_1, f724_p_1, fp_2, f724, f725, h, hp_0, x, xp_0, x596_p_0, xp_1, x596, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y376 = 0;
IND_TYPE x597 = 0;
IND_TYPE h312 = 0;
IND_TYPE w = 0;
IND_TYPE c565 = 0;
IND_TYPE f726 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5604 ,mem_vec_5605 ,mem_vec_5606 ,mem_vec_5607 ,mem_vec_5608 ,mem_vec_5609 ,mem_vec_5610 ,mem_vec_5611 ,mem_vec_5612 ,mem_vec_5613 ,mem_vec_5614 ,mem_vec_5615 ,mem_vec_5616 ,mem_vec_5617 ,mem_vec_5618 ,mem_vec_5619 ,mem_vec_5620 ,mem_vec_5621 ,mem_vec_5622 ,mem_vec_5623 ,mem_vec_5624 ,mem_vec_5625 ,mem_vec_5626 ,mem_vec_5627 ,mem_vec_5628 ,mem_vec_5629 ,mem_vec_5630 ,mem_vec_5631 ,mem_vec_5632 ,mem_vec_5633 ,mem_vec_5634 ,mem_vec_5635 ,mem_vec_5636 ,mem_vec_5637 ,mem_vec_5638 ,mem_vec_5639 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f725 = f726, f725_p_0 = 0;
	f725 < f726 + 256;
	f725 += 64, f725_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (x, 4) (68 / 17)
	for (x596 = x597, x596_p_0 = 0;
		x596 < x597 + 68;
		x596 += 17, x596_p_0 += 17){
		// y = 68, x = 17, h = 3, w = 3, c = 128, f = 64
		// T (f, 1) (64 / 64)
		for (f724 = f725, f724_p_1 = f725_p_0, f724_p_0 = 0;
			f724 < f725 + 64;
			f724 += 64, f724_p_1 += 64, f724_p_0 += 64){
			// y = 68, x = 17, h = 3, w = 3, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c564 = c565, c564_p_0 = 0;
				c564 < c565 + 128;
				c564 += 128, c564_p_0 += 128){
				// y = 68, x = 17, h = 3, w = 3, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f724, fp_2 = f724_p_1, fp_1 = f724_p_0, fp_0 = 0;
					f < f724 + 64;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y376, yp_0 = 0;
							y < y376 + 35;
							y += 7, yp_0 += 7){
							// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
							// T (h, 3) (3 / 1)
							for (h = h312, hp_0 = 0;
								h < h312 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 128, f = 32
								// T (x, 17) (17 / 1)
								for (x = x596, xp_1 = x596_p_0, xp_0 = 0;
									x < x596 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5604 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5605 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5606 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5607 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c564, cp_1 = c564_p_0, cp_0 = 0;
												c < c564 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5604);
												mem_vec_5604 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5605);
												mem_vec_5605 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5606);
												mem_vec_5606 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5607);
												mem_vec_5607 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5608);
												mem_vec_5608 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5609);
												mem_vec_5609 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5610);
												mem_vec_5610 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5611);
												mem_vec_5611 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5612);
												mem_vec_5612 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5613);
												mem_vec_5613 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5614);
												mem_vec_5614 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5615);
												mem_vec_5615 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5616);
												mem_vec_5616 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5617);
												mem_vec_5617 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_5604);
												mem_vec_5604 = vec_23;

												vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_5605);
												mem_vec_5605 = vec_26;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_29 = _mm512_set1_ps(scal_8);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_5606);
												mem_vec_5606 = vec_28;



												vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_5607);
												mem_vec_5607 = vec_30;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_32 = _mm512_set1_ps(scal_9);


												vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_5608);
												mem_vec_5608 = vec_31;



												vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_5609);
												mem_vec_5609 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_35 = _mm512_set1_ps(scal_10);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_5610);
												mem_vec_5610 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_5611);
												mem_vec_5611 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_38 = _mm512_set1_ps(scal_11);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_5612);
												mem_vec_5612 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_5613);
												mem_vec_5613 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_41 = _mm512_set1_ps(scal_12);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_5614);
												mem_vec_5614 = vec_40;



												vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_5615);
												mem_vec_5615 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_44 = _mm512_set1_ps(scal_13);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_5616);
												mem_vec_5616 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_5617);
												mem_vec_5617 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_47 = _mm512_set1_ps(scal_14);
												vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_5604);
												mem_vec_5604 = vec_46;

												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_5605);
												mem_vec_5605 = vec_49;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_52 = _mm512_set1_ps(scal_15);


												vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_5606);
												mem_vec_5606 = vec_51;



												vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_5607);
												mem_vec_5607 = vec_53;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_55 = _mm512_set1_ps(scal_16);


												vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_5608);
												mem_vec_5608 = vec_54;



												vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_5609);
												mem_vec_5609 = vec_56;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_58 = _mm512_set1_ps(scal_17);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_5610);
												mem_vec_5610 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_5611);
												mem_vec_5611 = vec_59;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_61 = _mm512_set1_ps(scal_18);


												vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_5612);
												mem_vec_5612 = vec_60;



												vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_5613);
												mem_vec_5613 = vec_62;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_19);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_5614);
												mem_vec_5614 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_5615);
												mem_vec_5615 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_67 = _mm512_set1_ps(scal_20);


												vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_5616);
												mem_vec_5616 = vec_66;



												vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_5617);
												mem_vec_5617 = vec_68;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5604);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5605);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5606);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5607);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5608);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5609);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5610);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5611);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5612);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5613);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5614);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5615);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5616);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5617);
								}
							}
						}
						for (y = y376 + 35, yp_0 = 0;
							y < y376 + 35 + 33;
							y += 11, yp_0 += 11){
							// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
							// T (h, 3) (3 / 1)
							for (h = h312, hp_0 = 0;
								h < h312 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 128, f = 32
								// T (x, 17) (17 / 1)
								for (x = x596, xp_1 = x596_p_0, xp_0 = 0;
									x < x596 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5618 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5619 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_5632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_5634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_5635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_5636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_5637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_5638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_5639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c564, cp_1 = c564_p_0, cp_0 = 0;
												c < c564 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5618);
												mem_vec_5618 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5619);
												mem_vec_5619 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5620);
												mem_vec_5620 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5621);
												mem_vec_5621 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5622);
												mem_vec_5622 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5623);
												mem_vec_5623 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5624);
												mem_vec_5624 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5625);
												mem_vec_5625 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5626);
												mem_vec_5626 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5627);
												mem_vec_5627 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5628);
												mem_vec_5628 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5629);
												mem_vec_5629 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5630);
												mem_vec_5630 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5631);
												mem_vec_5631 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5632);
												mem_vec_5632 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5633);
												mem_vec_5633 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5634);
												mem_vec_5634 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5635);
												mem_vec_5635 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5636);
												mem_vec_5636 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5637);
												mem_vec_5637 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5638);
												mem_vec_5638 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5639);
												mem_vec_5639 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);
												vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_5618);
												mem_vec_5618 = vec_35;

												vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_5619);
												mem_vec_5619 = vec_38;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_41 = _mm512_set1_ps(scal_12);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_5620);
												mem_vec_5620 = vec_40;



												vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_5621);
												mem_vec_5621 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_44 = _mm512_set1_ps(scal_13);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_5622);
												mem_vec_5622 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_5623);
												mem_vec_5623 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_47 = _mm512_set1_ps(scal_14);


												vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_5624);
												mem_vec_5624 = vec_46;



												vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_5625);
												mem_vec_5625 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_50 = _mm512_set1_ps(scal_15);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_5626);
												mem_vec_5626 = vec_49;



												vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_5627);
												mem_vec_5627 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_53 = _mm512_set1_ps(scal_16);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_5628);
												mem_vec_5628 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_5629);
												mem_vec_5629 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_56 = _mm512_set1_ps(scal_17);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_5630);
												mem_vec_5630 = vec_55;



												vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_5631);
												mem_vec_5631 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
												vec_59 = _mm512_set1_ps(scal_18);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_5632);
												mem_vec_5632 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_5633);
												mem_vec_5633 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
												vec_62 = _mm512_set1_ps(scal_19);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_5634);
												mem_vec_5634 = vec_61;



												vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_5635);
												mem_vec_5635 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
												vec_65 = _mm512_set1_ps(scal_20);


												vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_5636);
												mem_vec_5636 = vec_64;



												vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_5637);
												mem_vec_5637 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
												vec_68 = _mm512_set1_ps(scal_21);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_5638);
												mem_vec_5638 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_5639);
												mem_vec_5639 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_71 = _mm512_set1_ps(scal_22);
												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_5618);
												mem_vec_5618 = vec_70;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_5619);
												mem_vec_5619 = vec_73;
												scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_76 = _mm512_set1_ps(scal_23);


												vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_5620);
												mem_vec_5620 = vec_75;



												vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_5621);
												mem_vec_5621 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_79 = _mm512_set1_ps(scal_24);


												vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_5622);
												mem_vec_5622 = vec_78;



												vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_5623);
												mem_vec_5623 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_82 = _mm512_set1_ps(scal_25);


												vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_5624);
												mem_vec_5624 = vec_81;



												vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_5625);
												mem_vec_5625 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_85 = _mm512_set1_ps(scal_26);


												vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_5626);
												mem_vec_5626 = vec_84;



												vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_5627);
												mem_vec_5627 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_88 = _mm512_set1_ps(scal_27);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_5628);
												mem_vec_5628 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_5629);
												mem_vec_5629 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_91 = _mm512_set1_ps(scal_28);


												vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_5630);
												mem_vec_5630 = vec_90;



												vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_5631);
												mem_vec_5631 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
												vec_94 = _mm512_set1_ps(scal_29);


												vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_5632);
												mem_vec_5632 = vec_93;



												vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_5633);
												mem_vec_5633 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
												vec_97 = _mm512_set1_ps(scal_30);


												vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_5634);
												mem_vec_5634 = vec_96;



												vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_5635);
												mem_vec_5635 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
												vec_100 = _mm512_set1_ps(scal_31);


												vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_5636);
												mem_vec_5636 = vec_99;



												vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_5637);
												mem_vec_5637 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
												vec_103 = _mm512_set1_ps(scal_32);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_5638);
												mem_vec_5638 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_5639);
												mem_vec_5639 = vec_104;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5618);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5619);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5620);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5621);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5622);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5623);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5624);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5625);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5626);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5627);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5628);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5629);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5630);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5631);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5632);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5633);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5634);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5635);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5636);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5637);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5638);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_5639);
								}
							}
						}
				}
			}
		}
	}
}


}