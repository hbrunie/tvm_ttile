#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (56, x);
  T (3, w); Lambda_apply y [((Iter 5), (Arg 9)); ((Iter 1), (Arg 11))];
  T (2, f); T (8, c); T (4, f); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c546_p_0, cp_1, c546, f, fp_0, f432_p_0, f433_p_0, fp_1, f432_p_1, fp_2, f432, f433, w, wp_0, x, xp_0, x694_p_0, xp_1, x694, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y364 = 0;
IND_TYPE x695 = 0;
IND_TYPE h = 0;
IND_TYPE w334 = 0;
IND_TYPE c547 = 0;
IND_TYPE f434 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5580 ,mem_vec_5581 ,mem_vec_5582 ,mem_vec_5583 ,mem_vec_5584 ,mem_vec_5585 ,mem_vec_5586 ,mem_vec_5587 ,mem_vec_5588 ,mem_vec_5589 ,mem_vec_5590 ,mem_vec_5591 ,mem_vec_5592 ,mem_vec_5593 ,mem_vec_5594 ,mem_vec_5595 ,mem_vec_5596 ,mem_vec_5597 ,mem_vec_5598 ,mem_vec_5599 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
for (f433 = f434, f433_p_0 = 0;
	f433 < f434 + 128;
	f433 += 128, f433_p_0 += 128){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
	// T (x, 1) (56 / 56)
	for (x694 = x695, x694_p_0 = 0;
		x694 < x695 + 56;
		x694 += 56, x694_p_0 += 56){
		// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
		// T (f, 4) (128 / 32)
		for (f432 = f433, f432_p_1 = f433_p_0, f432_p_0 = 0;
			f432 < f433 + 128;
			f432 += 32, f432_p_1 += 32, f432_p_0 += 32){
			// y = 56, x = 56, h = 3, w = 3, c = 128, f = 32
			// T (c, 8) (128 / 16)
			for (c546 = c547, c546_p_0 = 0;
				c546 < c547 + 128;
				c546 += 16, c546_p_0 += 16){
				// y = 56, x = 56, h = 3, w = 3, c = 16, f = 32
				// T (f, 2) (32 / 16)
				for (f = f432, fp_2 = f432_p_1, fp_1 = f432_p_0, fp_0 = 0;
					f < f432 + 32;
					f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
						for (y = y364, yp_0 = 0;
							y < y364 + 45;
							y += 9, yp_0 += 9){
							// y = ph_y, x = 56, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w334, wp_0 = 0;
								w < w334 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 56, h = 3, w = 1, c = 16, f = 16
								// T (x, 56) (56 / 1)
								for (x = x694, xp_1 = x694_p_0, xp_0 = 0;
									x < x694 + 56;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5580 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c546, cp_1 = c546_p_0, cp_0 = 0;
												c < c546 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5580);
												mem_vec_5580 = vec_0;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);


												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_5581);
												mem_vec_5581 = vec_3;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5582);
												mem_vec_5582 = vec_5;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);


												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_5583);
												mem_vec_5583 = vec_7;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5584);
												mem_vec_5584 = vec_9;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_12 = _mm512_set1_ps(scal_5);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5585);
												mem_vec_5585 = vec_11;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_14 = _mm512_set1_ps(scal_6);


												vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_5586);
												mem_vec_5586 = vec_13;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_16 = _mm512_set1_ps(scal_7);


												vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_5587);
												mem_vec_5587 = vec_15;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_18 = _mm512_set1_ps(scal_8);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5588);
												mem_vec_5588 = vec_17;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_20 = _mm512_set1_ps(scal_9);
												vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_5580);
												mem_vec_5580 = vec_19;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_23 = _mm512_set1_ps(scal_10);


												vec_22 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_5581);
												mem_vec_5581 = vec_22;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_25 = _mm512_set1_ps(scal_11);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_21, mem_vec_5582);
												mem_vec_5582 = vec_24;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_27 = _mm512_set1_ps(scal_12);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_21, mem_vec_5583);
												mem_vec_5583 = vec_26;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_29 = _mm512_set1_ps(scal_13);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_5584);
												mem_vec_5584 = vec_28;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_31 = _mm512_set1_ps(scal_14);


												vec_30 = _mm512_fmadd_ps(vec_31, vec_21, mem_vec_5585);
												mem_vec_5585 = vec_30;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_33 = _mm512_set1_ps(scal_15);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_21, mem_vec_5586);
												mem_vec_5586 = vec_32;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_35 = _mm512_set1_ps(scal_16);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_21, mem_vec_5587);
												mem_vec_5587 = vec_34;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_37 = _mm512_set1_ps(scal_17);


												vec_36 = _mm512_fmadd_ps(vec_37, vec_21, mem_vec_5588);
												mem_vec_5588 = vec_36;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_39 = _mm512_set1_ps(scal_18);
												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_5580);
												mem_vec_5580 = vec_38;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_42 = _mm512_set1_ps(scal_19);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_40, mem_vec_5581);
												mem_vec_5581 = vec_41;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_44 = _mm512_set1_ps(scal_20);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_5582);
												mem_vec_5582 = vec_43;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_46 = _mm512_set1_ps(scal_21);


												vec_45 = _mm512_fmadd_ps(vec_46, vec_40, mem_vec_5583);
												mem_vec_5583 = vec_45;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_48 = _mm512_set1_ps(scal_22);


												vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_5584);
												mem_vec_5584 = vec_47;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_50 = _mm512_set1_ps(scal_23);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_5585);
												mem_vec_5585 = vec_49;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_52 = _mm512_set1_ps(scal_24);


												vec_51 = _mm512_fmadd_ps(vec_52, vec_40, mem_vec_5586);
												mem_vec_5586 = vec_51;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_54 = _mm512_set1_ps(scal_25);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_5587);
												mem_vec_5587 = vec_53;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_56 = _mm512_set1_ps(scal_26);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_5588);
												mem_vec_5588 = vec_55;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5580);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5581);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5582);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5583);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5584);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5585);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5586);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5587);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5588);
								}
							}
						}
						for (y = y364 + 45, yp_0 = 0;
							y < y364 + 45 + 11;
							y += 11, yp_0 += 11){
							// y = ph_y, x = 56, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w334, wp_0 = 0;
								w < w334 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 56, h = 3, w = 1, c = 16, f = 16
								// T (x, 56) (56 / 1)
								for (x = x694, xp_1 = x694_p_0, xp_0 = 0;
									x < x694 + 56;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5589 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5590 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5591 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5592 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5593 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5594 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5595 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5596 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5597 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_5598 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_5599 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c546, cp_1 = c546_p_0, cp_0 = 0;
												c < c546 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5589);
												mem_vec_5589 = vec_0;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);


												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_5590);
												mem_vec_5590 = vec_3;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5591);
												mem_vec_5591 = vec_5;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);


												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_5592);
												mem_vec_5592 = vec_7;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5593);
												mem_vec_5593 = vec_9;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_12 = _mm512_set1_ps(scal_5);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5594);
												mem_vec_5594 = vec_11;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_14 = _mm512_set1_ps(scal_6);


												vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_5595);
												mem_vec_5595 = vec_13;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_16 = _mm512_set1_ps(scal_7);


												vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_5596);
												mem_vec_5596 = vec_15;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_18 = _mm512_set1_ps(scal_8);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5597);
												mem_vec_5597 = vec_17;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_20 = _mm512_set1_ps(scal_9);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5598);
												mem_vec_5598 = vec_19;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_22 = _mm512_set1_ps(scal_10);


												vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_5599);
												mem_vec_5599 = vec_21;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_24 = _mm512_set1_ps(scal_11);
												vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_5589);
												mem_vec_5589 = vec_23;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_27 = _mm512_set1_ps(scal_12);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_25, mem_vec_5590);
												mem_vec_5590 = vec_26;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_29 = _mm512_set1_ps(scal_13);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_5591);
												mem_vec_5591 = vec_28;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_31 = _mm512_set1_ps(scal_14);


												vec_30 = _mm512_fmadd_ps(vec_31, vec_25, mem_vec_5592);
												mem_vec_5592 = vec_30;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_33 = _mm512_set1_ps(scal_15);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_25, mem_vec_5593);
												mem_vec_5593 = vec_32;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_35 = _mm512_set1_ps(scal_16);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_5594);
												mem_vec_5594 = vec_34;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_37 = _mm512_set1_ps(scal_17);


												vec_36 = _mm512_fmadd_ps(vec_37, vec_25, mem_vec_5595);
												mem_vec_5595 = vec_36;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_39 = _mm512_set1_ps(scal_18);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_25, mem_vec_5596);
												mem_vec_5596 = vec_38;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_19);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_5597);
												mem_vec_5597 = vec_40;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_43 = _mm512_set1_ps(scal_20);


												vec_42 = _mm512_fmadd_ps(vec_43, vec_25, mem_vec_5598);
												mem_vec_5598 = vec_42;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_45 = _mm512_set1_ps(scal_21);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_25, mem_vec_5599);
												mem_vec_5599 = vec_44;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_47 = _mm512_set1_ps(scal_22);
												vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_5589);
												mem_vec_5589 = vec_46;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_50 = _mm512_set1_ps(scal_23);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_48, mem_vec_5590);
												mem_vec_5590 = vec_49;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_52 = _mm512_set1_ps(scal_24);


												vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_5591);
												mem_vec_5591 = vec_51;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_54 = _mm512_set1_ps(scal_25);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_48, mem_vec_5592);
												mem_vec_5592 = vec_53;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_56 = _mm512_set1_ps(scal_26);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_48, mem_vec_5593);
												mem_vec_5593 = vec_55;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_58 = _mm512_set1_ps(scal_27);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_5594);
												mem_vec_5594 = vec_57;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_60 = _mm512_set1_ps(scal_28);


												vec_59 = _mm512_fmadd_ps(vec_60, vec_48, mem_vec_5595);
												mem_vec_5595 = vec_59;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_62 = _mm512_set1_ps(scal_29);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_48, mem_vec_5596);
												mem_vec_5596 = vec_61;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_64 = _mm512_set1_ps(scal_30);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_5597);
												mem_vec_5597 = vec_63;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_66 = _mm512_set1_ps(scal_31);


												vec_65 = _mm512_fmadd_ps(vec_66, vec_48, mem_vec_5598);
												mem_vec_5598 = vec_65;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_68 = _mm512_set1_ps(scal_32);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_48, mem_vec_5599);
												mem_vec_5599 = vec_67;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5589);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5590);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5591);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5592);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5593);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5594);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5595);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5596);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5597);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5598);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5599);
								}
							}
						}
				}
			}
		}
	}
}


}