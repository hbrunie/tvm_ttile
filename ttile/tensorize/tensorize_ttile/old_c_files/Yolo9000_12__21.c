#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (1, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (2, f);
  T (256, c); T (4, f)]
*/
IND_TYPE c, cp_0, c1148_p_0, cp_1, c1148, f, fp_0, f1224_p_0, f1225_p_0, fp_1, f1224_p_1, fp_2, f1224, f1225, h, hp_0, x, xp_0, x1148_p_0, xp_1, x1148, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y704 = 0;
IND_TYPE x1149 = 0;
IND_TYPE h544 = 0;
IND_TYPE w = 0;
IND_TYPE c1149 = 0;
IND_TYPE f1226 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_13702 ,mem_vec_13703 ,mem_vec_13704 ,mem_vec_13705 ,mem_vec_13706 ,mem_vec_13707 ,mem_vec_13708 ,mem_vec_13709 ,mem_vec_13710 ,mem_vec_13711 ,mem_vec_13712 ,mem_vec_13713 ,mem_vec_13714 ,mem_vec_13715 ,mem_vec_13716 ,mem_vec_13717 ,mem_vec_13718 ,mem_vec_13719 ,mem_vec_13720 ,mem_vec_13721 ,mem_vec_13722 ,mem_vec_13723 ,mem_vec_13724 ,mem_vec_13725 ,mem_vec_13726 ,mem_vec_13727 ,mem_vec_13728 ,mem_vec_13729 ,mem_vec_13730 ,mem_vec_13731 ,mem_vec_13732 ,mem_vec_13733 ,mem_vec_13734 ,mem_vec_13735 ,mem_vec_13736 ,mem_vec_13737 ,mem_vec_13738 ,mem_vec_13739 ,mem_vec_13740 ,mem_vec_13741 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f1225 = f1226, f1225_p_0 = 0;
	f1225 < f1226 + 512;
	f1225 += 128, f1225_p_0 += 128){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
	// T (c, 256) (256 / 1)
	for (c1148 = c1149, c1148_p_0 = 0;
		c1148 < c1149 + 256;
		c1148 += 1, c1148_p_0 += 1){
		// y = 34, x = 34, h = 3, w = 3, c = 1, f = 128
		// T (f, 2) (128 / 64)
		for (f1224 = f1225, f1224_p_1 = f1225_p_0, f1224_p_0 = 0;
			f1224 < f1225 + 128;
			f1224 += 64, f1224_p_1 += 64, f1224_p_0 += 64){
				for (y = y704, yp_0 = 0;
					y < y704 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 64
					// T (x, 17) (34 / 2)
					for (x1148 = x1149, x1148_p_0 = 0;
						x1148 < x1149 + 34;
						x1148 += 2, x1148_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 1, f = 64
						// T (f, 1) (64 / 64)
						for (f = f1224, fp_2 = f1224_p_1, fp_1 = f1224_p_0, fp_0 = 0;
							f < f1224 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 2, h = 3, w = 3, c = 1, f = 64
							// T (h, 3) (3 / 1)
							for (h = h544, hp_0 = 0;
								h < h544 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 1, f = 64
								// T (x, 2) (2 / 1)
								for (x = x1148, xp_1 = x1148_p_0, xp_0 = 0;
									x < x1148 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13702 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13703 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13704 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_13705 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_13706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_13709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_13710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_13713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_13714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_13717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
											// T (c, 1) (1 / 1)
											for (c = c1148, cp_1 = c1148_p_0, cp_0 = 0;
												c < c1148 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13702);
												mem_vec_13702 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13703);
												mem_vec_13703 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13704);
												mem_vec_13704 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13705);
												mem_vec_13705 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13706);
												mem_vec_13706 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13707);
												mem_vec_13707 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13708);
												mem_vec_13708 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13709);
												mem_vec_13709 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13710);
												mem_vec_13710 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13711);
												mem_vec_13711 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13712);
												mem_vec_13712 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13713);
												mem_vec_13713 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13714);
												mem_vec_13714 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13715);
												mem_vec_13715 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13716);
												mem_vec_13716 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13717);
												mem_vec_13717 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_13702);
												mem_vec_13702 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_13703);
												mem_vec_13703 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_13704);
												mem_vec_13704 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_13705);
												mem_vec_13705 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_13706);
												mem_vec_13706 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_13707);
												mem_vec_13707 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_13708);
												mem_vec_13708 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_13709);
												mem_vec_13709 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_13710);
												mem_vec_13710 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_13711);
												mem_vec_13711 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_13712);
												mem_vec_13712 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_13713);
												mem_vec_13713 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_13714);
												mem_vec_13714 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_13715);
												mem_vec_13715 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_13716);
												mem_vec_13716 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_13717);
												mem_vec_13717 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_13702);
												mem_vec_13702 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_13703);
												mem_vec_13703 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_13704);
												mem_vec_13704 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_13705);
												mem_vec_13705 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_13706);
												mem_vec_13706 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_13707);
												mem_vec_13707 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_13708);
												mem_vec_13708 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_13709);
												mem_vec_13709 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_13710);
												mem_vec_13710 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_13711);
												mem_vec_13711 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_13712);
												mem_vec_13712 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_13713);
												mem_vec_13713 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_13714);
												mem_vec_13714 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_13715);
												mem_vec_13715 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_13716);
												mem_vec_13716 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_13717);
												mem_vec_13717 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13702);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13703);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13704);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13705);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13706);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13707);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13708);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13709);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13710);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13711);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13712);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13713);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13714);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13715);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_13716);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_13717);
								}
							}
						}
					}
				}
				for (y = y704 + 4, yp_0 = 0;
					y < y704 + 4 + 30;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 64
					// T (x, 17) (34 / 2)
					for (x1148 = x1149, x1148_p_0 = 0;
						x1148 < x1149 + 34;
						x1148 += 2, x1148_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 1, f = 64
						// T (f, 1) (64 / 64)
						for (f = f1224, fp_2 = f1224_p_1, fp_1 = f1224_p_0, fp_0 = 0;
							f < f1224 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 2, h = 3, w = 3, c = 1, f = 64
							// T (h, 3) (3 / 1)
							for (h = h544, hp_0 = 0;
								h < h544 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 1, f = 64
								// T (x, 2) (2 / 1)
								for (x = x1148, xp_1 = x1148_p_0, xp_0 = 0;
									x < x1148 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13718 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13719 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13720 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_13721 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_13722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_13725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_13726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_13729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_13730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_13733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_13734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_13735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_13736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_13737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_13738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_13739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_13740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_13741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
											// T (c, 1) (1 / 1)
											for (c = c1148, cp_1 = c1148_p_0, cp_0 = 0;
												c < c1148 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13718);
												mem_vec_13718 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13719);
												mem_vec_13719 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13720);
												mem_vec_13720 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13721);
												mem_vec_13721 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13722);
												mem_vec_13722 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13723);
												mem_vec_13723 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13724);
												mem_vec_13724 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13725);
												mem_vec_13725 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13726);
												mem_vec_13726 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13727);
												mem_vec_13727 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13728);
												mem_vec_13728 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13729);
												mem_vec_13729 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13730);
												mem_vec_13730 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13731);
												mem_vec_13731 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13732);
												mem_vec_13732 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13733);
												mem_vec_13733 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_13734);
												mem_vec_13734 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_13735);
												mem_vec_13735 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_13736);
												mem_vec_13736 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_13737);
												mem_vec_13737 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13738);
												mem_vec_13738 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13739);
												mem_vec_13739 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_13740);
												mem_vec_13740 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_13741);
												mem_vec_13741 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_13718);
												mem_vec_13718 = vec_34;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_13719);
												mem_vec_13719 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_13720);
												mem_vec_13720 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_13721);
												mem_vec_13721 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_13722);
												mem_vec_13722 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_13723);
												mem_vec_13723 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_13724);
												mem_vec_13724 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_13725);
												mem_vec_13725 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_13726);
												mem_vec_13726 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_13727);
												mem_vec_13727 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_13728);
												mem_vec_13728 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_13729);
												mem_vec_13729 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_13730);
												mem_vec_13730 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_13731);
												mem_vec_13731 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_13732);
												mem_vec_13732 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_13733);
												mem_vec_13733 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_13734);
												mem_vec_13734 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_13735);
												mem_vec_13735 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_13736);
												mem_vec_13736 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_13737);
												mem_vec_13737 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_13738);
												mem_vec_13738 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_13739);
												mem_vec_13739 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_13740);
												mem_vec_13740 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_13741);
												mem_vec_13741 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_13718);
												mem_vec_13718 = vec_68;

												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_13719);
												mem_vec_13719 = vec_71;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_13720);
												mem_vec_13720 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_13721);
												mem_vec_13721 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_13722);
												mem_vec_13722 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_13723);
												mem_vec_13723 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_13724);
												mem_vec_13724 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_13725);
												mem_vec_13725 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_13726);
												mem_vec_13726 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_13727);
												mem_vec_13727 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_13728);
												mem_vec_13728 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_13729);
												mem_vec_13729 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_13730);
												mem_vec_13730 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_13731);
												mem_vec_13731 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_13732);
												mem_vec_13732 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_13733);
												mem_vec_13733 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_13734);
												mem_vec_13734 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_13735);
												mem_vec_13735 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_13736);
												mem_vec_13736 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_13737);
												mem_vec_13737 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_13738);
												mem_vec_13738 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_13739);
												mem_vec_13739 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_13740);
												mem_vec_13740 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_13741);
												mem_vec_13741 = vec_101;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13718);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13719);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13720);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13721);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13722);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13723);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13724);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13725);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13726);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13727);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13728);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13729);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13730);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13731);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_13732);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_13733);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13734);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13735);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_13736);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_13737);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13738);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13739);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_13740);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_13741);
								}
							}
						}
					}
				}
		}
	}
}


}