#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (128, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (2, c); T (2, f);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (2, x);
  T (2, f); T (2, f)]
*/
IND_TYPE c, cp_0, c528_p_0, cp_1, c528, f, fp_0, f638_p_0, f639_p_0, fp_1, f638_p_1, fp_2, f638, f639, h, hp_0, x, xp_0, x529_p_0, xp_1, x529, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y385 = 0;
IND_TYPE x530 = 0;
IND_TYPE h326 = 0;
IND_TYPE w = 0;
IND_TYPE c529 = 0;
IND_TYPE f640 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7745 ,mem_vec_7746 ,mem_vec_7747 ,mem_vec_7748 ,mem_vec_7749 ,mem_vec_7750 ,mem_vec_7751 ,mem_vec_7752 ,mem_vec_7753 ,mem_vec_7754 ,mem_vec_7755 ,mem_vec_7756 ,mem_vec_7757 ,mem_vec_7758 ,mem_vec_7759 ,mem_vec_7760 ,mem_vec_7761 ,mem_vec_7762 ,mem_vec_7763 ,mem_vec_7764 ,mem_vec_7765 ,mem_vec_7766 ,mem_vec_7767 ,mem_vec_7768 ,mem_vec_7769 ,mem_vec_7770 ,mem_vec_7771 ,mem_vec_7772 ,mem_vec_7773 ,mem_vec_7774 ,mem_vec_7775 ,mem_vec_7776 ,mem_vec_7777 ,mem_vec_7778 ,mem_vec_7779 ,mem_vec_7780 ,mem_vec_7781 ,mem_vec_7782 ,mem_vec_7783 ,mem_vec_7784 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f639 = f640, f639_p_0 = 0;
	f639 < f640 + 512;
	f639 += 256, f639_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (f, 2) (256 / 128)
	for (f638 = f639, f638_p_1 = f639_p_0, f638_p_0 = 0;
		f638 < f639 + 256;
		f638 += 128, f638_p_1 += 128, f638_p_0 += 128){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
		// T (x, 2) (34 / 17)
		for (x529 = x530, x529_p_0 = 0;
			x529 < x530 + 34;
			x529 += 17, x529_p_0 += 17){
				for (y = y385, yp_0 = 0;
					y < y385 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f638, fp_2 = f638_p_1, fp_1 = f638_p_0, fp_0 = 0;
						f < f638 + 128;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
						// T (c, 2) (256 / 128)
						for (c528 = c529, c528_p_0 = 0;
							c528 < c529 + 256;
							c528 += 128, c528_p_0 += 128){
							// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
							// T (h, 3) (3 / 1)
							for (h = h326, hp_0 = 0;
								h < h326 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 128, f = 64
								// T (x, 17) (17 / 1)
								for (x = x529, xp_1 = x529_p_0, xp_0 = 0;
									x < x529 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7745 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7746 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7747 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_7748 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_7749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_7752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_7753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_7756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_7757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_7760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 64
											// T (c, 128) (128 / 1)
											for (c = c528, cp_1 = c528_p_0, cp_0 = 0;
												c < c528 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7745);
												mem_vec_7745 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7746);
												mem_vec_7746 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7747);
												mem_vec_7747 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7748);
												mem_vec_7748 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7749);
												mem_vec_7749 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7750);
												mem_vec_7750 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7751);
												mem_vec_7751 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7752);
												mem_vec_7752 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7753);
												mem_vec_7753 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7754);
												mem_vec_7754 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7755);
												mem_vec_7755 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7756);
												mem_vec_7756 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7757);
												mem_vec_7757 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7758);
												mem_vec_7758 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7759);
												mem_vec_7759 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7760);
												mem_vec_7760 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_7745);
												mem_vec_7745 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_7746);
												mem_vec_7746 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_7747);
												mem_vec_7747 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_7748);
												mem_vec_7748 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_7749);
												mem_vec_7749 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_7750);
												mem_vec_7750 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_7751);
												mem_vec_7751 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_7752);
												mem_vec_7752 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_7753);
												mem_vec_7753 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_7754);
												mem_vec_7754 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_7755);
												mem_vec_7755 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_7756);
												mem_vec_7756 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_7757);
												mem_vec_7757 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_7758);
												mem_vec_7758 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_7759);
												mem_vec_7759 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_7760);
												mem_vec_7760 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_7745);
												mem_vec_7745 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_7746);
												mem_vec_7746 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_7747);
												mem_vec_7747 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_7748);
												mem_vec_7748 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_7749);
												mem_vec_7749 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_7750);
												mem_vec_7750 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_7751);
												mem_vec_7751 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_7752);
												mem_vec_7752 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_7753);
												mem_vec_7753 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_7754);
												mem_vec_7754 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_7755);
												mem_vec_7755 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_7756);
												mem_vec_7756 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_7757);
												mem_vec_7757 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_7758);
												mem_vec_7758 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_7759);
												mem_vec_7759 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_7760);
												mem_vec_7760 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7745);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7746);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7747);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7748);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7749);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7750);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7751);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7752);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7753);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7754);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7755);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7756);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7757);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7758);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7759);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7760);
								}
							}
						}
					}
				}
				for (y = y385 + 4, yp_0 = 0;
					y < y385 + 4 + 30;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f638, fp_2 = f638_p_1, fp_1 = f638_p_0, fp_0 = 0;
						f < f638 + 128;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
						// T (c, 2) (256 / 128)
						for (c528 = c529, c528_p_0 = 0;
							c528 < c529 + 256;
							c528 += 128, c528_p_0 += 128){
							// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
							// T (h, 3) (3 / 1)
							for (h = h326, hp_0 = 0;
								h < h326 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 128, f = 64
								// T (x, 17) (17 / 1)
								for (x = x529, xp_1 = x529_p_0, xp_0 = 0;
									x < x529 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7761 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7762 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7763 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_7764 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_7765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_7768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_7769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_7772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_7773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_7776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_7777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_7780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_7781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_7783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_7784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 64
											// T (c, 128) (128 / 1)
											for (c = c528, cp_1 = c528_p_0, cp_0 = 0;
												c < c528 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7761);
												mem_vec_7761 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7762);
												mem_vec_7762 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7763);
												mem_vec_7763 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7764);
												mem_vec_7764 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7765);
												mem_vec_7765 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7766);
												mem_vec_7766 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7767);
												mem_vec_7767 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7768);
												mem_vec_7768 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7769);
												mem_vec_7769 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7770);
												mem_vec_7770 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7771);
												mem_vec_7771 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7772);
												mem_vec_7772 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7773);
												mem_vec_7773 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7774);
												mem_vec_7774 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7775);
												mem_vec_7775 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7776);
												mem_vec_7776 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7777);
												mem_vec_7777 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7778);
												mem_vec_7778 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7779);
												mem_vec_7779 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7780);
												mem_vec_7780 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7781);
												mem_vec_7781 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7782);
												mem_vec_7782 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_7783);
												mem_vec_7783 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_7784);
												mem_vec_7784 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_7761);
												mem_vec_7761 = vec_34;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_7762);
												mem_vec_7762 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_7763);
												mem_vec_7763 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_7764);
												mem_vec_7764 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_7765);
												mem_vec_7765 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_7766);
												mem_vec_7766 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_7767);
												mem_vec_7767 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_7768);
												mem_vec_7768 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_7769);
												mem_vec_7769 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_7770);
												mem_vec_7770 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_7771);
												mem_vec_7771 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_7772);
												mem_vec_7772 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_7773);
												mem_vec_7773 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_7774);
												mem_vec_7774 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_7775);
												mem_vec_7775 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_7776);
												mem_vec_7776 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_7777);
												mem_vec_7777 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_7778);
												mem_vec_7778 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_7779);
												mem_vec_7779 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_7780);
												mem_vec_7780 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_7781);
												mem_vec_7781 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_7782);
												mem_vec_7782 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_7783);
												mem_vec_7783 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_7784);
												mem_vec_7784 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_7761);
												mem_vec_7761 = vec_68;

												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_7762);
												mem_vec_7762 = vec_71;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_7763);
												mem_vec_7763 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_7764);
												mem_vec_7764 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_7765);
												mem_vec_7765 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_7766);
												mem_vec_7766 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_7767);
												mem_vec_7767 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_7768);
												mem_vec_7768 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_7769);
												mem_vec_7769 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_7770);
												mem_vec_7770 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_7771);
												mem_vec_7771 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_7772);
												mem_vec_7772 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_7773);
												mem_vec_7773 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_7774);
												mem_vec_7774 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_7775);
												mem_vec_7775 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_7776);
												mem_vec_7776 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_7777);
												mem_vec_7777 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_7778);
												mem_vec_7778 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_7779);
												mem_vec_7779 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_7780);
												mem_vec_7780 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_7781);
												mem_vec_7781 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_7782);
												mem_vec_7782 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_7783);
												mem_vec_7783 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_7784);
												mem_vec_7784 = vec_101;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7761);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7762);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7763);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7764);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7765);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7766);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7767);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7768);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7769);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7770);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7771);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7772);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7773);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7774);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7775);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7776);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7777);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7778);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_7779);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_7780);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7781);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7782);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_7783);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_7784);
								}
							}
						}
					}
				}
		}
	}
}


}