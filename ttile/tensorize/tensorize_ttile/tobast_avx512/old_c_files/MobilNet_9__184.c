#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (2, c); T (4, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 1), (Arg 3))]; T (4, c);
  T (2, f); T (2, c)]
*/
IND_TYPE c, cp_0, c1888_p_0, c1889_p_0, c1890_p_0, cp_1, c1888_p_1, c1889_p_1, cp_2, c1888_p_2, cp_3, c1888, c1889, c1890, f, fp_0, f1248_p_0, fp_1, f1248, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y638 = 0;
IND_TYPE x784 = 0;
IND_TYPE h602 = 0;
IND_TYPE w = 0;
IND_TYPE c1891 = 0;
IND_TYPE f1249 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_7756 ,mem_vec_7757 ,mem_vec_7758 ,mem_vec_7759 ,mem_vec_7760 ,mem_vec_7761 ,mem_vec_7762 ,mem_vec_7763 ,mem_vec_7764 ,mem_vec_7765 ,mem_vec_7766 ,mem_vec_7767 ,mem_vec_7768 ,mem_vec_7769 ,mem_vec_7770 ,mem_vec_7771 ,mem_vec_7772 ,mem_vec_7773 ,mem_vec_7774 ,mem_vec_7775 ,mem_vec_7776 ,mem_vec_7777 ,mem_vec_7778 ,mem_vec_7779 ,mem_vec_7780 ,mem_vec_7781 ,mem_vec_7782 ,mem_vec_7783 ,mem_vec_7784 ,mem_vec_7785 ,mem_vec_7786 ,mem_vec_7787 ,mem_vec_7788 ,mem_vec_7789 ,mem_vec_7790 ,mem_vec_7791 ,mem_vec_7792 ,mem_vec_7793 ,mem_vec_7794 ,mem_vec_7795 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 2) (1024 / 512)
for (c1890 = c1891, c1890_p_0 = 0;
	c1890 < c1891 + 1024;
	c1890 += 512, c1890_p_0 += 512){
	// y = 7, x = 7, h = 3, w = 3, c = 512, f = 1024
	// T (f, 2) (1024 / 512)
	for (f1248 = f1249, f1248_p_0 = 0;
		f1248 < f1249 + 1024;
		f1248 += 512, f1248_p_0 += 512){
		// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
		// T (c, 4) (512 / 128)
		for (c1889 = c1890, c1889_p_1 = c1890_p_0, c1889_p_0 = 0;
			c1889 < c1890 + 512;
			c1889 += 128, c1889_p_1 += 128, c1889_p_0 += 128){
				for (y = y638, yp_0 = 0;
					y < y638 + 4;
					y += 2, yp_0 += 2){
					// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 512
					// T (f, 4) (512 / 128)
					for (f = f1248, fp_1 = f1248_p_0, fp_0 = 0;
						f < f1248 + 512;
						f += 128, fp_1 += 128, fp_0 += 128){
						// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 128
						// T (c, 2) (128 / 64)
						for (c1888 = c1889, c1888_p_2 = c1889_p_1, c1888_p_1 = c1889_p_0, c1888_p_0 = 0;
							c1888 < c1889 + 128;
							c1888 += 64, c1888_p_2 += 64, c1888_p_1 += 64, c1888_p_0 += 64){
							// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 128
							// T (h, 3) (3 / 1)
							for (h = h602, hp_0 = 0;
								h < h602 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 64, f = 128
								// T (x, 7) (7 / 1)
								for (x = x784, xp_0 = 0;
									x < x784 + 7;
									x += 1, xp_0 += 1){
											mem_vec_7756 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7757 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7758 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_7759 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_7760 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 64]);
											mem_vec_7761 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 80]);
											mem_vec_7762 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 96]);
											mem_vec_7763 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 112]);
											mem_vec_7764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_7767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_7768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64]);
											mem_vec_7769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80]);
											mem_vec_7770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96]);
											mem_vec_7771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 128
											// T (c, 64) (64 / 1)
											for (c = c1888, cp_3 = c1888_p_2, cp_2 = c1888_p_1, cp_1 = c1888_p_0, cp_0 = 0;
												c < c1888 + 64;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7756);
												mem_vec_7756 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7757);
												mem_vec_7757 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7758);
												mem_vec_7758 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7759);
												mem_vec_7759 = vec_7;

												vec_10 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 64]);

												vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_7760);
												mem_vec_7760 = vec_9;

												vec_12 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 80]);

												vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_7761);
												mem_vec_7761 = vec_11;

												vec_14 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 96]);

												vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_7762);
												mem_vec_7762 = vec_13;

												vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 112]);

												vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_7763);
												mem_vec_7763 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm512_set1_ps(scal_1);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7764);
												mem_vec_7764 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7765);
												mem_vec_7765 = vec_19;



												vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_7766);
												mem_vec_7766 = vec_20;



												vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_7767);
												mem_vec_7767 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_7768);
												mem_vec_7768 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_7769);
												mem_vec_7769 = vec_23;



												vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_7770);
												mem_vec_7770 = vec_24;



												vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_7771);
												mem_vec_7771 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_27 = _mm512_set1_ps(scal_2);
												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_7756);
												mem_vec_7756 = vec_26;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_7757);
												mem_vec_7757 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_31 = _mm512_fmadd_ps(vec_27, vec_32, mem_vec_7758);
												mem_vec_7758 = vec_31;

												vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_33 = _mm512_fmadd_ps(vec_27, vec_34, mem_vec_7759);
												mem_vec_7759 = vec_33;

												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 64]);

												vec_35 = _mm512_fmadd_ps(vec_27, vec_36, mem_vec_7760);
												mem_vec_7760 = vec_35;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 80]);

												vec_37 = _mm512_fmadd_ps(vec_27, vec_38, mem_vec_7761);
												mem_vec_7761 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 96]);

												vec_39 = _mm512_fmadd_ps(vec_27, vec_40, mem_vec_7762);
												mem_vec_7762 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 112]);

												vec_41 = _mm512_fmadd_ps(vec_27, vec_42, mem_vec_7763);
												mem_vec_7763 = vec_41;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_3);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_7764);
												mem_vec_7764 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_7765);
												mem_vec_7765 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_7766);
												mem_vec_7766 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_7767);
												mem_vec_7767 = vec_47;



												vec_48 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_7768);
												mem_vec_7768 = vec_48;



												vec_49 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_7769);
												mem_vec_7769 = vec_49;



												vec_50 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_7770);
												mem_vec_7770 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_7771);
												mem_vec_7771 = vec_51;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_53 = _mm512_set1_ps(scal_4);
												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_7756);
												mem_vec_7756 = vec_52;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_7757);
												mem_vec_7757 = vec_55;

												vec_58 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_57 = _mm512_fmadd_ps(vec_53, vec_58, mem_vec_7758);
												mem_vec_7758 = vec_57;

												vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_59 = _mm512_fmadd_ps(vec_53, vec_60, mem_vec_7759);
												mem_vec_7759 = vec_59;

												vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 64]);

												vec_61 = _mm512_fmadd_ps(vec_53, vec_62, mem_vec_7760);
												mem_vec_7760 = vec_61;

												vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 80]);

												vec_63 = _mm512_fmadd_ps(vec_53, vec_64, mem_vec_7761);
												mem_vec_7761 = vec_63;

												vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 96]);

												vec_65 = _mm512_fmadd_ps(vec_53, vec_66, mem_vec_7762);
												mem_vec_7762 = vec_65;

												vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 112]);

												vec_67 = _mm512_fmadd_ps(vec_53, vec_68, mem_vec_7763);
												mem_vec_7763 = vec_67;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_70 = _mm512_set1_ps(scal_5);


												vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_7764);
												mem_vec_7764 = vec_69;



												vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_7765);
												mem_vec_7765 = vec_71;



												vec_72 = _mm512_fmadd_ps(vec_70, vec_58, mem_vec_7766);
												mem_vec_7766 = vec_72;



												vec_73 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_7767);
												mem_vec_7767 = vec_73;



												vec_74 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_7768);
												mem_vec_7768 = vec_74;



												vec_75 = _mm512_fmadd_ps(vec_70, vec_64, mem_vec_7769);
												mem_vec_7769 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_7770);
												mem_vec_7770 = vec_76;



												vec_77 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_7771);
												mem_vec_7771 = vec_77;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7756);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7757);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7758);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7759);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 64], mem_vec_7760);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 80], mem_vec_7761);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 96], mem_vec_7762);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 112], mem_vec_7763);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7764);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7765);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7766);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7767);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64], mem_vec_7768);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80], mem_vec_7769);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96], mem_vec_7770);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112], mem_vec_7771);
								}
							}
						}
					}
				}
				for (y = y638 + 4, yp_0 = 0;
					y < y638 + 4 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 512
					// T (f, 4) (512 / 128)
					for (f = f1248, fp_1 = f1248_p_0, fp_0 = 0;
						f < f1248 + 512;
						f += 128, fp_1 += 128, fp_0 += 128){
						// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 128
						// T (c, 2) (128 / 64)
						for (c1888 = c1889, c1888_p_2 = c1889_p_1, c1888_p_1 = c1889_p_0, c1888_p_0 = 0;
							c1888 < c1889 + 128;
							c1888 += 64, c1888_p_2 += 64, c1888_p_1 += 64, c1888_p_0 += 64){
							// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 128
							// T (h, 3) (3 / 1)
							for (h = h602, hp_0 = 0;
								h < h602 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 64, f = 128
								// T (x, 7) (7 / 1)
								for (x = x784, xp_0 = 0;
									x < x784 + 7;
									x += 1, xp_0 += 1){
											mem_vec_7772 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7773 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7774 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_7775 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_7776 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 64]);
											mem_vec_7777 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 80]);
											mem_vec_7778 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 96]);
											mem_vec_7779 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 112]);
											mem_vec_7780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_7783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_7784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64]);
											mem_vec_7785 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80]);
											mem_vec_7786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96]);
											mem_vec_7787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112]);
											mem_vec_7788 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7789 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_7791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_7792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 64]);
											mem_vec_7793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 80]);
											mem_vec_7794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 96]);
											mem_vec_7795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 112]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 128
											// T (c, 64) (64 / 1)
											for (c = c1888, cp_3 = c1888_p_2, cp_2 = c1888_p_1, cp_1 = c1888_p_0, cp_0 = 0;
												c < c1888 + 64;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7772);
												mem_vec_7772 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7773);
												mem_vec_7773 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7774);
												mem_vec_7774 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7775);
												mem_vec_7775 = vec_7;

												vec_10 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 64]);

												vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_7776);
												mem_vec_7776 = vec_9;

												vec_12 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 80]);

												vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_7777);
												mem_vec_7777 = vec_11;

												vec_14 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 96]);

												vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_7778);
												mem_vec_7778 = vec_13;

												vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 112]);

												vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_7779);
												mem_vec_7779 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm512_set1_ps(scal_1);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7780);
												mem_vec_7780 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7781);
												mem_vec_7781 = vec_19;



												vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_7782);
												mem_vec_7782 = vec_20;



												vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_7783);
												mem_vec_7783 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_7784);
												mem_vec_7784 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_7785);
												mem_vec_7785 = vec_23;



												vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_7786);
												mem_vec_7786 = vec_24;



												vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_7787);
												mem_vec_7787 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm512_set1_ps(scal_2);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7788);
												mem_vec_7788 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7789);
												mem_vec_7789 = vec_28;



												vec_29 = _mm512_fmadd_ps(vec_27, vec_6, mem_vec_7790);
												mem_vec_7790 = vec_29;



												vec_30 = _mm512_fmadd_ps(vec_27, vec_8, mem_vec_7791);
												mem_vec_7791 = vec_30;



												vec_31 = _mm512_fmadd_ps(vec_27, vec_10, mem_vec_7792);
												mem_vec_7792 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_27, vec_12, mem_vec_7793);
												mem_vec_7793 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_27, vec_14, mem_vec_7794);
												mem_vec_7794 = vec_33;



												vec_34 = _mm512_fmadd_ps(vec_27, vec_16, mem_vec_7795);
												mem_vec_7795 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_36 = _mm512_set1_ps(scal_3);
												vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_7772);
												mem_vec_7772 = vec_35;

												vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_7773);
												mem_vec_7773 = vec_38;

												vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_40 = _mm512_fmadd_ps(vec_36, vec_41, mem_vec_7774);
												mem_vec_7774 = vec_40;

												vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_42 = _mm512_fmadd_ps(vec_36, vec_43, mem_vec_7775);
												mem_vec_7775 = vec_42;

												vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 64]);

												vec_44 = _mm512_fmadd_ps(vec_36, vec_45, mem_vec_7776);
												mem_vec_7776 = vec_44;

												vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 80]);

												vec_46 = _mm512_fmadd_ps(vec_36, vec_47, mem_vec_7777);
												mem_vec_7777 = vec_46;

												vec_49 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 96]);

												vec_48 = _mm512_fmadd_ps(vec_36, vec_49, mem_vec_7778);
												mem_vec_7778 = vec_48;

												vec_51 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 112]);

												vec_50 = _mm512_fmadd_ps(vec_36, vec_51, mem_vec_7779);
												mem_vec_7779 = vec_50;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_53 = _mm512_set1_ps(scal_4);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_7780);
												mem_vec_7780 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_7781);
												mem_vec_7781 = vec_54;



												vec_55 = _mm512_fmadd_ps(vec_53, vec_41, mem_vec_7782);
												mem_vec_7782 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_53, vec_43, mem_vec_7783);
												mem_vec_7783 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_53, vec_45, mem_vec_7784);
												mem_vec_7784 = vec_57;



												vec_58 = _mm512_fmadd_ps(vec_53, vec_47, mem_vec_7785);
												mem_vec_7785 = vec_58;



												vec_59 = _mm512_fmadd_ps(vec_53, vec_49, mem_vec_7786);
												mem_vec_7786 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_53, vec_51, mem_vec_7787);
												mem_vec_7787 = vec_60;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_62 = _mm512_set1_ps(scal_5);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_7788);
												mem_vec_7788 = vec_61;



												vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_7789);
												mem_vec_7789 = vec_63;



												vec_64 = _mm512_fmadd_ps(vec_62, vec_41, mem_vec_7790);
												mem_vec_7790 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_62, vec_43, mem_vec_7791);
												mem_vec_7791 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_62, vec_45, mem_vec_7792);
												mem_vec_7792 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_62, vec_47, mem_vec_7793);
												mem_vec_7793 = vec_67;



												vec_68 = _mm512_fmadd_ps(vec_62, vec_49, mem_vec_7794);
												mem_vec_7794 = vec_68;



												vec_69 = _mm512_fmadd_ps(vec_62, vec_51, mem_vec_7795);
												mem_vec_7795 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_71 = _mm512_set1_ps(scal_6);
												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_7772);
												mem_vec_7772 = vec_70;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_7773);
												mem_vec_7773 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_75 = _mm512_fmadd_ps(vec_71, vec_76, mem_vec_7774);
												mem_vec_7774 = vec_75;

												vec_78 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_77 = _mm512_fmadd_ps(vec_71, vec_78, mem_vec_7775);
												mem_vec_7775 = vec_77;

												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 64]);

												vec_79 = _mm512_fmadd_ps(vec_71, vec_80, mem_vec_7776);
												mem_vec_7776 = vec_79;

												vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 80]);

												vec_81 = _mm512_fmadd_ps(vec_71, vec_82, mem_vec_7777);
												mem_vec_7777 = vec_81;

												vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 96]);

												vec_83 = _mm512_fmadd_ps(vec_71, vec_84, mem_vec_7778);
												mem_vec_7778 = vec_83;

												vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 112]);

												vec_85 = _mm512_fmadd_ps(vec_71, vec_86, mem_vec_7779);
												mem_vec_7779 = vec_85;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm512_set1_ps(scal_7);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_7780);
												mem_vec_7780 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_7781);
												mem_vec_7781 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_7782);
												mem_vec_7782 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_7783);
												mem_vec_7783 = vec_91;



												vec_92 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_7784);
												mem_vec_7784 = vec_92;



												vec_93 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_7785);
												mem_vec_7785 = vec_93;



												vec_94 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_7786);
												mem_vec_7786 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_7787);
												mem_vec_7787 = vec_95;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_97 = _mm512_set1_ps(scal_8);


												vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_7788);
												mem_vec_7788 = vec_96;



												vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_7789);
												mem_vec_7789 = vec_98;



												vec_99 = _mm512_fmadd_ps(vec_97, vec_76, mem_vec_7790);
												mem_vec_7790 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_97, vec_78, mem_vec_7791);
												mem_vec_7791 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_97, vec_80, mem_vec_7792);
												mem_vec_7792 = vec_101;



												vec_102 = _mm512_fmadd_ps(vec_97, vec_82, mem_vec_7793);
												mem_vec_7793 = vec_102;



												vec_103 = _mm512_fmadd_ps(vec_97, vec_84, mem_vec_7794);
												mem_vec_7794 = vec_103;



												vec_104 = _mm512_fmadd_ps(vec_97, vec_86, mem_vec_7795);
												mem_vec_7795 = vec_104;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7772);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7773);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7774);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7775);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 64], mem_vec_7776);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 80], mem_vec_7777);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 96], mem_vec_7778);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 112], mem_vec_7779);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7780);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7781);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7782);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7783);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64], mem_vec_7784);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80], mem_vec_7785);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96], mem_vec_7786);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112], mem_vec_7787);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7788);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7789);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7790);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7791);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 64], mem_vec_7792);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 80], mem_vec_7793);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 96], mem_vec_7794);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 112], mem_vec_7795);
								}
							}
						}
					}
				}
		}
	}
}


}