#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (2, c); Hoist_vars [c]; T (4, x);
  T (3, w); Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))];
  T (1, f); T (64, c); T (1, f); T (17, x); T (8, f)]
*/
IND_TYPE c, cp_0, c1152_p_0, cp_1, c1152, f, fp_0, f1460_p_0, f1461_p_0, fp_1, f1460_p_1, fp_2, f1460, f1461, w, wp_0, x, xp_0, x1242_p_0, xp_1, x1242, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y768 = 0;
IND_TYPE x1243 = 0;
IND_TYPE h = 0;
IND_TYPE w716 = 0;
IND_TYPE c1153 = 0;
IND_TYPE f1462 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14704 ,mem_vec_14705 ,mem_vec_14706 ,mem_vec_14707 ,mem_vec_14708 ,mem_vec_14709 ,mem_vec_14710 ,mem_vec_14711 ,mem_vec_14712 ,mem_vec_14713 ,mem_vec_14714 ,mem_vec_14715 ,mem_vec_14716 ,mem_vec_14717 ,mem_vec_14718 ,mem_vec_14719 ,mem_vec_14720 ,mem_vec_14721 ,mem_vec_14722 ,mem_vec_14723 ,mem_vec_14724 ,mem_vec_14725 ,mem_vec_14726 ,mem_vec_14727 ,mem_vec_14728 ,mem_vec_14729 ,mem_vec_14730 ,mem_vec_14731 ,mem_vec_14732 ,mem_vec_14733 ,mem_vec_14734 ,mem_vec_14735 ,mem_vec_14736 ,mem_vec_14737 ,mem_vec_14738 ,mem_vec_14739 ,mem_vec_14740 ,mem_vec_14741 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
for (f1461 = f1462, f1461_p_0 = 0;
	f1461 < f1462 + 256;
	f1461 += 32, f1461_p_0 += 32){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
	// T (x, 17) (68 / 4)
	for (x1242 = x1243, x1242_p_0 = 0;
		x1242 < x1243 + 68;
		x1242 += 4, x1242_p_0 += 4){
		// y = 68, x = 4, h = 3, w = 3, c = 128, f = 32
		// T (f, 1) (32 / 32)
		for (f1460 = f1461, f1460_p_1 = f1461_p_0, f1460_p_0 = 0;
			f1460 < f1461 + 32;
			f1460 += 32, f1460_p_1 += 32, f1460_p_0 += 32){
			// y = 68, x = 4, h = 3, w = 3, c = 128, f = 32
			// T (c, 64) (128 / 2)
			for (c1152 = c1153, c1152_p_0 = 0;
				c1152 < c1153 + 128;
				c1152 += 2, c1152_p_0 += 2){
				// y = 68, x = 4, h = 3, w = 3, c = 2, f = 32
				// T (f, 1) (32 / 32)
				for (f = f1460, fp_2 = f1460_p_1, fp_1 = f1460_p_0, fp_0 = 0;
					f < f1460 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y768, yp_0 = 0;
							y < y768 + 18;
							y += 9, yp_0 += 9){
							// y = ph_y, x = 4, h = 3, w = 3, c = 2, f = 32
							// T (w, 3) (3 / 1)
							for (w = w716, wp_0 = 0;
								w < w716 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 3, w = 1, c = 2, f = 32
								// T (x, 4) (4 / 1)
								for (x = x1242, xp_1 = x1242_p_0, xp_0 = 0;
									x < x1242 + 4;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14704 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14705 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_14713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_14714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_14715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_14716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_14717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_14718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_14719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_14720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_14721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c1152, cp_1 = c1152_p_0, cp_0 = 0;
												c < c1152 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14704);
												mem_vec_14704 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14705);
												mem_vec_14705 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14706);
												mem_vec_14706 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14707);
												mem_vec_14707 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14708);
												mem_vec_14708 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14709);
												mem_vec_14709 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14710);
												mem_vec_14710 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14711);
												mem_vec_14711 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14712);
												mem_vec_14712 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14713);
												mem_vec_14713 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14714);
												mem_vec_14714 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14715);
												mem_vec_14715 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14716);
												mem_vec_14716 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14717);
												mem_vec_14717 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14718);
												mem_vec_14718 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14719);
												mem_vec_14719 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14720);
												mem_vec_14720 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14721);
												mem_vec_14721 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_14704);
												mem_vec_14704 = vec_29;

												vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_14705);
												mem_vec_14705 = vec_32;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_35 = _mm512_set1_ps(scal_10);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_14706);
												mem_vec_14706 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_14707);
												mem_vec_14707 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_38 = _mm512_set1_ps(scal_11);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_14708);
												mem_vec_14708 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_14709);
												mem_vec_14709 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_12);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_14710);
												mem_vec_14710 = vec_40;



												vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_14711);
												mem_vec_14711 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_13);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_14712);
												mem_vec_14712 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_14713);
												mem_vec_14713 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_47 = _mm512_set1_ps(scal_14);


												vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_14714);
												mem_vec_14714 = vec_46;



												vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_14715);
												mem_vec_14715 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_50 = _mm512_set1_ps(scal_15);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_14716);
												mem_vec_14716 = vec_49;



												vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_14717);
												mem_vec_14717 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_53 = _mm512_set1_ps(scal_16);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_14718);
												mem_vec_14718 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_14719);
												mem_vec_14719 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_56 = _mm512_set1_ps(scal_17);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_14720);
												mem_vec_14720 = vec_55;



												vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_14721);
												mem_vec_14721 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm512_set1_ps(scal_18);
												vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_14704);
												mem_vec_14704 = vec_58;

												vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_14705);
												mem_vec_14705 = vec_61;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_64 = _mm512_set1_ps(scal_19);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_14706);
												mem_vec_14706 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_14707);
												mem_vec_14707 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_67 = _mm512_set1_ps(scal_20);


												vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_14708);
												mem_vec_14708 = vec_66;



												vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_14709);
												mem_vec_14709 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_70 = _mm512_set1_ps(scal_21);


												vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_14710);
												mem_vec_14710 = vec_69;



												vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_14711);
												mem_vec_14711 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_73 = _mm512_set1_ps(scal_22);


												vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_14712);
												mem_vec_14712 = vec_72;



												vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_14713);
												mem_vec_14713 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_76 = _mm512_set1_ps(scal_23);


												vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_14714);
												mem_vec_14714 = vec_75;



												vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_14715);
												mem_vec_14715 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_79 = _mm512_set1_ps(scal_24);


												vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_14716);
												mem_vec_14716 = vec_78;



												vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_14717);
												mem_vec_14717 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_82 = _mm512_set1_ps(scal_25);


												vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_14718);
												mem_vec_14718 = vec_81;



												vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_14719);
												mem_vec_14719 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_85 = _mm512_set1_ps(scal_26);


												vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_14720);
												mem_vec_14720 = vec_84;



												vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_14721);
												mem_vec_14721 = vec_86;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14704);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14705);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14706);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14707);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14708);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14709);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14710);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14711);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14712);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14713);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14714);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14715);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14716);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14717);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14718);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14719);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14720);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14721);
								}
							}
						}
						for (y = y768 + 18, yp_0 = 0;
							y < y768 + 18 + 50;
							y += 10, yp_0 += 10){
							// y = ph_y, x = 4, h = 3, w = 3, c = 2, f = 32
							// T (w, 3) (3 / 1)
							for (w = w716, wp_0 = 0;
								w < w716 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 3, w = 1, c = 2, f = 32
								// T (x, 4) (4 / 1)
								for (x = x1242, xp_1 = x1242_p_0, xp_0 = 0;
									x < x1242 + 4;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14722 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14723 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_14731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_14732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_14733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_14734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_14735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_14736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_14737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_14738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_14739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_14740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_14741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c1152, cp_1 = c1152_p_0, cp_0 = 0;
												c < c1152 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14722);
												mem_vec_14722 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14723);
												mem_vec_14723 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14724);
												mem_vec_14724 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14725);
												mem_vec_14725 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14726);
												mem_vec_14726 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14727);
												mem_vec_14727 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14728);
												mem_vec_14728 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14729);
												mem_vec_14729 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14730);
												mem_vec_14730 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14731);
												mem_vec_14731 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14732);
												mem_vec_14732 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14733);
												mem_vec_14733 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14734);
												mem_vec_14734 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14735);
												mem_vec_14735 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14736);
												mem_vec_14736 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14737);
												mem_vec_14737 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14738);
												mem_vec_14738 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14739);
												mem_vec_14739 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14740);
												mem_vec_14740 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14741);
												mem_vec_14741 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_14722);
												mem_vec_14722 = vec_32;

												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_14723);
												mem_vec_14723 = vec_35;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_38 = _mm512_set1_ps(scal_11);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_14724);
												mem_vec_14724 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_14725);
												mem_vec_14725 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_12);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_14726);
												mem_vec_14726 = vec_40;



												vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_14727);
												mem_vec_14727 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_13);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_14728);
												mem_vec_14728 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_14729);
												mem_vec_14729 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_47 = _mm512_set1_ps(scal_14);


												vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_14730);
												mem_vec_14730 = vec_46;



												vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_14731);
												mem_vec_14731 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_50 = _mm512_set1_ps(scal_15);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_14732);
												mem_vec_14732 = vec_49;



												vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_14733);
												mem_vec_14733 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_53 = _mm512_set1_ps(scal_16);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_14734);
												mem_vec_14734 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_14735);
												mem_vec_14735 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_56 = _mm512_set1_ps(scal_17);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_14736);
												mem_vec_14736 = vec_55;



												vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_14737);
												mem_vec_14737 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_59 = _mm512_set1_ps(scal_18);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_14738);
												mem_vec_14738 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_14739);
												mem_vec_14739 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_62 = _mm512_set1_ps(scal_19);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_14740);
												mem_vec_14740 = vec_61;



												vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_14741);
												mem_vec_14741 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_65 = _mm512_set1_ps(scal_20);
												vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_14722);
												mem_vec_14722 = vec_64;

												vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_14723);
												mem_vec_14723 = vec_67;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_70 = _mm512_set1_ps(scal_21);


												vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_14724);
												mem_vec_14724 = vec_69;



												vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_14725);
												mem_vec_14725 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm512_set1_ps(scal_22);


												vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_14726);
												mem_vec_14726 = vec_72;



												vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_14727);
												mem_vec_14727 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_76 = _mm512_set1_ps(scal_23);


												vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_14728);
												mem_vec_14728 = vec_75;



												vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_14729);
												mem_vec_14729 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_79 = _mm512_set1_ps(scal_24);


												vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_14730);
												mem_vec_14730 = vec_78;



												vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_14731);
												mem_vec_14731 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_82 = _mm512_set1_ps(scal_25);


												vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_14732);
												mem_vec_14732 = vec_81;



												vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_14733);
												mem_vec_14733 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_85 = _mm512_set1_ps(scal_26);


												vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_14734);
												mem_vec_14734 = vec_84;



												vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_14735);
												mem_vec_14735 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_88 = _mm512_set1_ps(scal_27);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_14736);
												mem_vec_14736 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_14737);
												mem_vec_14737 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_91 = _mm512_set1_ps(scal_28);


												vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_14738);
												mem_vec_14738 = vec_90;



												vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_14739);
												mem_vec_14739 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_94 = _mm512_set1_ps(scal_29);


												vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_14740);
												mem_vec_14740 = vec_93;



												vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_14741);
												mem_vec_14741 = vec_95;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14722);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14723);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14724);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14725);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14726);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14727);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14728);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14729);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14730);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14731);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14732);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14733);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14734);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14735);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14736);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14737);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14738);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14739);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14740);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14741);
								}
							}
						}
				}
			}
		}
	}
}


}