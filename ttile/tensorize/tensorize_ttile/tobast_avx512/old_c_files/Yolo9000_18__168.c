#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (4, f); T (1, x);
  Lambda_apply y [((Iter 4), (Arg 3)); ((Iter 1), (Arg 5))]; T (4, f);
  T (16, c); T (1, f)]
*/
IND_TYPE c, cp_0, c818_p_0, cp_1, c818, f, fp_0, f904_p_0, f905_p_0, fp_1, f904_p_1, fp_2, f904, f905, h, hp_0, x, xp_0, x738_p_0, xp_1, x738, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y492 = 0;
IND_TYPE x739 = 0;
IND_TYPE h378 = 0;
IND_TYPE w = 0;
IND_TYPE c819 = 0;
IND_TYPE f906 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6654 ,mem_vec_6655 ,mem_vec_6656 ,mem_vec_6657 ,mem_vec_6658 ,mem_vec_6659 ,mem_vec_6660 ,mem_vec_6661 ,mem_vec_6662 ,mem_vec_6663 ,mem_vec_6664 ,mem_vec_6665 ,mem_vec_6666 ,mem_vec_6667 ,mem_vec_6668 ,mem_vec_6669 ,mem_vec_6670 ,mem_vec_6671 ,mem_vec_6672 ,mem_vec_6673 ,mem_vec_6674 ,mem_vec_6675 ,mem_vec_6676 ,mem_vec_6677 ,mem_vec_6678 ,mem_vec_6679 ,mem_vec_6680 ,mem_vec_6681 ,mem_vec_6682 ,mem_vec_6683 ,mem_vec_6684 ,mem_vec_6685 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 1) (1024 / 1024)
for (f905 = f906, f905_p_0 = 0;
	f905 < f906 + 1024;
	f905 += 1024, f905_p_0 += 1024){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 16) (512 / 32)
	for (c818 = c819, c818_p_0 = 0;
		c818 < c819 + 512;
		c818 += 32, c818_p_0 += 32){
		// y = 17, x = 17, h = 3, w = 3, c = 32, f = 1024
		// T (f, 4) (1024 / 256)
		for (f904 = f905, f904_p_1 = f905_p_0, f904_p_0 = 0;
			f904 < f905 + 1024;
			f904 += 256, f904_p_1 += 256, f904_p_0 += 256){
				for (y = y492, yp_0 = 0;
					y < y492 + 12;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 256
					// T (x, 1) (17 / 17)
					for (x738 = x739, x738_p_0 = 0;
						x738 < x739 + 17;
						x738 += 17, x738_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 256
						// T (f, 4) (256 / 64)
						for (f = f904, fp_2 = f904_p_1, fp_1 = f904_p_0, fp_0 = 0;
							f < f904 + 256;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
							// T (h, 3) (3 / 1)
							for (h = h378, hp_0 = 0;
								h < h378 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 32, f = 64
								// T (x, 17) (17 / 1)
								for (x = x738, xp_1 = x738_p_0, xp_0 = 0;
									x < x738 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6654 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6655 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6656 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_6657 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_6658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_6661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_6662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_6665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
											// T (c, 32) (32 / 1)
											for (c = c818, cp_1 = c818_p_0, cp_0 = 0;
												c < c818 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6654);
												mem_vec_6654 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6655);
												mem_vec_6655 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6656);
												mem_vec_6656 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6657);
												mem_vec_6657 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6658);
												mem_vec_6658 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6659);
												mem_vec_6659 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6660);
												mem_vec_6660 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6661);
												mem_vec_6661 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6662);
												mem_vec_6662 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6663);
												mem_vec_6663 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6664);
												mem_vec_6664 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6665);
												mem_vec_6665 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_6654);
												mem_vec_6654 = vec_19;

												vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_6655);
												mem_vec_6655 = vec_22;

												vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_6656);
												mem_vec_6656 = vec_24;

												vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_6657);
												mem_vec_6657 = vec_26;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_29 = _mm512_set1_ps(scal_4);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_6658);
												mem_vec_6658 = vec_28;



												vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_6659);
												mem_vec_6659 = vec_30;



												vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_6660);
												mem_vec_6660 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_6661);
												mem_vec_6661 = vec_32;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_6662);
												mem_vec_6662 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_6663);
												mem_vec_6663 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_6664);
												mem_vec_6664 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_6665);
												mem_vec_6665 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_6654);
												mem_vec_6654 = vec_38;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_6655);
												mem_vec_6655 = vec_41;

												vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_6656);
												mem_vec_6656 = vec_43;

												vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_6657);
												mem_vec_6657 = vec_45;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_48 = _mm512_set1_ps(scal_7);


												vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_6658);
												mem_vec_6658 = vec_47;



												vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_6659);
												mem_vec_6659 = vec_49;



												vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_6660);
												mem_vec_6660 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_6661);
												mem_vec_6661 = vec_51;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_53 = _mm512_set1_ps(scal_8);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_6662);
												mem_vec_6662 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_6663);
												mem_vec_6663 = vec_54;



												vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_6664);
												mem_vec_6664 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_6665);
												mem_vec_6665 = vec_56;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6654);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6655);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6656);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6657);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6658);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6659);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6660);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6661);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6662);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6663);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6664);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6665);
								}
							}
						}
					}
				}
				for (y = y492 + 12, yp_0 = 0;
					y < y492 + 12 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 256
					// T (x, 1) (17 / 17)
					for (x738 = x739, x738_p_0 = 0;
						x738 < x739 + 17;
						x738 += 17, x738_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 256
						// T (f, 4) (256 / 64)
						for (f = f904, fp_2 = f904_p_1, fp_1 = f904_p_0, fp_0 = 0;
							f < f904 + 256;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
							// T (h, 3) (3 / 1)
							for (h = h378, hp_0 = 0;
								h < h378 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 32, f = 64
								// T (x, 17) (17 / 1)
								for (x = x738, xp_1 = x738_p_0, xp_0 = 0;
									x < x738 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6666 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6667 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6668 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_6669 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_6670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_6673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_6674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_6677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_6678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_6681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_6682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_6685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
											// T (c, 32) (32 / 1)
											for (c = c818, cp_1 = c818_p_0, cp_0 = 0;
												c < c818 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6666);
												mem_vec_6666 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6667);
												mem_vec_6667 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6668);
												mem_vec_6668 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6669);
												mem_vec_6669 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6670);
												mem_vec_6670 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6671);
												mem_vec_6671 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6672);
												mem_vec_6672 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6673);
												mem_vec_6673 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6674);
												mem_vec_6674 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6675);
												mem_vec_6675 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6676);
												mem_vec_6676 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6677);
												mem_vec_6677 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6678);
												mem_vec_6678 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6679);
												mem_vec_6679 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6680);
												mem_vec_6680 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6681);
												mem_vec_6681 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6682);
												mem_vec_6682 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6683);
												mem_vec_6683 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6684);
												mem_vec_6684 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6685);
												mem_vec_6685 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);
												vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_6666);
												mem_vec_6666 = vec_29;

												vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_6667);
												mem_vec_6667 = vec_32;

												vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_6668);
												mem_vec_6668 = vec_34;

												vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_6669);
												mem_vec_6669 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_6670);
												mem_vec_6670 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_6671);
												mem_vec_6671 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_6672);
												mem_vec_6672 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_6673);
												mem_vec_6673 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_6674);
												mem_vec_6674 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_6675);
												mem_vec_6675 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_6676);
												mem_vec_6676 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_6677);
												mem_vec_6677 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_6678);
												mem_vec_6678 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_6679);
												mem_vec_6679 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_6680);
												mem_vec_6680 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_6681);
												mem_vec_6681 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_6682);
												mem_vec_6682 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_6683);
												mem_vec_6683 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_6684);
												mem_vec_6684 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_6685);
												mem_vec_6685 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);
												vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_6666);
												mem_vec_6666 = vec_58;

												vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_6667);
												mem_vec_6667 = vec_61;

												vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_6668);
												mem_vec_6668 = vec_63;

												vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_6669);
												mem_vec_6669 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_6670);
												mem_vec_6670 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_6671);
												mem_vec_6671 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_6672);
												mem_vec_6672 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_6673);
												mem_vec_6673 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_73 = _mm512_set1_ps(scal_12);


												vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_6674);
												mem_vec_6674 = vec_72;



												vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_6675);
												mem_vec_6675 = vec_74;



												vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_6676);
												mem_vec_6676 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_6677);
												mem_vec_6677 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_6678);
												mem_vec_6678 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_6679);
												mem_vec_6679 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_6680);
												mem_vec_6680 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_6681);
												mem_vec_6681 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_6682);
												mem_vec_6682 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_6683);
												mem_vec_6683 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_6684);
												mem_vec_6684 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_6685);
												mem_vec_6685 = vec_86;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6666);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6667);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6668);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6669);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6670);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6671);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6672);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6673);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6674);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6675);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6676);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6677);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6678);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6679);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6680);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6681);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6682);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6683);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6684);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6685);
								}
							}
						}
					}
				}
		}
	}
}


}