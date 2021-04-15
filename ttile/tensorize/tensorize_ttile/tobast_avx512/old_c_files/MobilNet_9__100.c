#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (1, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 2)); ((Iter 1), (Arg 5))]; T (8, c);
  T (16, f); T (16, c)]
*/
IND_TYPE c, cp_0, c1708_p_0, c1709_p_0, c1710_p_0, cp_1, c1708_p_1, c1709_p_1, cp_2, c1708_p_2, cp_3, c1708, c1709, c1710, f, fp_0, f1140_p_0, fp_1, f1140, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y566 = 0;
IND_TYPE x712 = 0;
IND_TYPE h530 = 0;
IND_TYPE w = 0;
IND_TYPE c1711 = 0;
IND_TYPE f1141 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6748 ,mem_vec_6749 ,mem_vec_6750 ,mem_vec_6751 ,mem_vec_6752 ,mem_vec_6753 ,mem_vec_6754 ,mem_vec_6755 ,mem_vec_6756 ,mem_vec_6757 ,mem_vec_6758 ,mem_vec_6759 ,mem_vec_6760 ,mem_vec_6761 ,mem_vec_6762 ,mem_vec_6763 ,mem_vec_6764 ,mem_vec_6765 ,mem_vec_6766 ,mem_vec_6767 ,mem_vec_6768 ,mem_vec_6769 ,mem_vec_6770 ,mem_vec_6771 ,mem_vec_6772 ,mem_vec_6773 ,mem_vec_6774 ,mem_vec_6775 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 16) (1024 / 64)
for (c1710 = c1711, c1710_p_0 = 0;
	c1710 < c1711 + 1024;
	c1710 += 64, c1710_p_0 += 64){
	// y = 7, x = 7, h = 3, w = 3, c = 64, f = 1024
	// T (f, 16) (1024 / 64)
	for (f1140 = f1141, f1140_p_0 = 0;
		f1140 < f1141 + 1024;
		f1140 += 64, f1140_p_0 += 64){
		// y = 7, x = 7, h = 3, w = 3, c = 64, f = 64
		// T (c, 8) (64 / 8)
		for (c1709 = c1710, c1709_p_1 = c1710_p_0, c1709_p_0 = 0;
			c1709 < c1710 + 64;
			c1709 += 8, c1709_p_1 += 8, c1709_p_0 += 8){
				for (y = y566, yp_0 = 0;
					y < y566 + 2;
					y += 2, yp_0 += 2){
					// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1140, fp_1 = f1140_p_0, fp_0 = 0;
						f < f1140 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
						// T (c, 1) (8 / 8)
						for (c1708 = c1709, c1708_p_2 = c1709_p_1, c1708_p_1 = c1709_p_0, c1708_p_0 = 0;
							c1708 < c1709 + 8;
							c1708 += 8, c1708_p_2 += 8, c1708_p_1 += 8, c1708_p_0 += 8){
							// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
							// T (h, 3) (3 / 1)
							for (h = h530, hp_0 = 0;
								h < h530 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 8, f = 64
								// T (x, 7) (7 / 1)
								for (x = x712, xp_0 = 0;
									x < x712 + 7;
									x += 1, xp_0 += 1){
											mem_vec_6748 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6749 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6750 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_6751 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_6752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_6755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 64
											// T (c, 8) (8 / 1)
											for (c = c1708, cp_3 = c1708_p_2, cp_2 = c1708_p_1, cp_1 = c1708_p_0, cp_0 = 0;
												c < c1708 + 8;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6748);
												mem_vec_6748 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6749);
												mem_vec_6749 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6750);
												mem_vec_6750 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6751);
												mem_vec_6751 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6752);
												mem_vec_6752 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6753);
												mem_vec_6753 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6754);
												mem_vec_6754 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6755);
												mem_vec_6755 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_6748);
												mem_vec_6748 = vec_14;

												vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_6749);
												mem_vec_6749 = vec_17;

												vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_6750);
												mem_vec_6750 = vec_19;

												vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_6751);
												mem_vec_6751 = vec_21;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_24 = _mm512_set1_ps(scal_3);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_6752);
												mem_vec_6752 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_6753);
												mem_vec_6753 = vec_25;



												vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_6754);
												mem_vec_6754 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_6755);
												mem_vec_6755 = vec_27;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_29 = _mm512_set1_ps(scal_4);
												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_6748);
												mem_vec_6748 = vec_28;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_6749);
												mem_vec_6749 = vec_31;

												vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_6750);
												mem_vec_6750 = vec_33;

												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_6751);
												mem_vec_6751 = vec_35;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_38 = _mm512_set1_ps(scal_5);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_6752);
												mem_vec_6752 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_6753);
												mem_vec_6753 = vec_39;



												vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_6754);
												mem_vec_6754 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_6755);
												mem_vec_6755 = vec_41;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6748);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6749);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6750);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6751);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6752);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6753);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6754);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6755);
								}
							}
						}
					}
				}
				for (y = y566 + 2, yp_0 = 0;
					y < y566 + 2 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1140, fp_1 = f1140_p_0, fp_0 = 0;
						f < f1140 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
						// T (c, 1) (8 / 8)
						for (c1708 = c1709, c1708_p_2 = c1709_p_1, c1708_p_1 = c1709_p_0, c1708_p_0 = 0;
							c1708 < c1709 + 8;
							c1708 += 8, c1708_p_2 += 8, c1708_p_1 += 8, c1708_p_0 += 8){
							// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
							// T (h, 3) (3 / 1)
							for (h = h530, hp_0 = 0;
								h < h530 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 8, f = 64
								// T (x, 7) (7 / 1)
								for (x = x712, xp_0 = 0;
									x < x712 + 7;
									x += 1, xp_0 += 1){
											mem_vec_6756 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6757 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6758 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_6759 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_6760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_6763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_6764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_6767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_6768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_6771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_6772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_6775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 64
											// T (c, 8) (8 / 1)
											for (c = c1708, cp_3 = c1708_p_2, cp_2 = c1708_p_1, cp_1 = c1708_p_0, cp_0 = 0;
												c < c1708 + 8;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6756);
												mem_vec_6756 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6757);
												mem_vec_6757 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6758);
												mem_vec_6758 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6759);
												mem_vec_6759 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6760);
												mem_vec_6760 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6761);
												mem_vec_6761 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6762);
												mem_vec_6762 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6763);
												mem_vec_6763 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6764);
												mem_vec_6764 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6765);
												mem_vec_6765 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6766);
												mem_vec_6766 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6767);
												mem_vec_6767 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6768);
												mem_vec_6768 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6769);
												mem_vec_6769 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6770);
												mem_vec_6770 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6771);
												mem_vec_6771 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6772);
												mem_vec_6772 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6773);
												mem_vec_6773 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6774);
												mem_vec_6774 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6775);
												mem_vec_6775 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);
												vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_6756);
												mem_vec_6756 = vec_29;

												vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_6757);
												mem_vec_6757 = vec_32;

												vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_6758);
												mem_vec_6758 = vec_34;

												vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_6759);
												mem_vec_6759 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_6760);
												mem_vec_6760 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_6761);
												mem_vec_6761 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_6762);
												mem_vec_6762 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_6763);
												mem_vec_6763 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_6764);
												mem_vec_6764 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_6765);
												mem_vec_6765 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_6766);
												mem_vec_6766 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_6767);
												mem_vec_6767 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_6768);
												mem_vec_6768 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_6769);
												mem_vec_6769 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_6770);
												mem_vec_6770 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_6771);
												mem_vec_6771 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_6772);
												mem_vec_6772 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_6773);
												mem_vec_6773 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_6774);
												mem_vec_6774 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_6775);
												mem_vec_6775 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);
												vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_6756);
												mem_vec_6756 = vec_58;

												vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_6757);
												mem_vec_6757 = vec_61;

												vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_6758);
												mem_vec_6758 = vec_63;

												vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_6759);
												mem_vec_6759 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_6760);
												mem_vec_6760 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_6761);
												mem_vec_6761 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_6762);
												mem_vec_6762 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_6763);
												mem_vec_6763 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_73 = _mm512_set1_ps(scal_12);


												vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_6764);
												mem_vec_6764 = vec_72;



												vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_6765);
												mem_vec_6765 = vec_74;



												vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_6766);
												mem_vec_6766 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_6767);
												mem_vec_6767 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_6768);
												mem_vec_6768 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_6769);
												mem_vec_6769 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_6770);
												mem_vec_6770 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_6771);
												mem_vec_6771 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_6772);
												mem_vec_6772 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_6773);
												mem_vec_6773 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_6774);
												mem_vec_6774 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_6775);
												mem_vec_6775 = vec_86;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6756);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6757);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6758);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6759);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6760);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6761);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6762);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6763);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6764);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6765);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6766);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6767);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6768);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6769);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6770);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6771);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6772);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6773);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6774);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6775);
								}
							}
						}
					}
				}
		}
	}
}


}