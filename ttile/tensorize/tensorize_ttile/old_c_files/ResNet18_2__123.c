#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 11)); ((Iter 3), (Arg 15))]; T (2, f);
  T (8, c); T (28, x)]
*/
IND_TYPE c, c0, cp_0, c0_p_0, cp_1, f, fp_0, h, hp_0, w, wp_0, x, x0, xp_0, x0_p_0, x1_p_0, x1, xp_1, x0_p_1, xp_2, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y0 = 0;
IND_TYPE x2 = 0;
IND_TYPE h0 = 0;
IND_TYPE w0 = 0;
IND_TYPE c1 = 0;
IND_TYPE f0 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_0 ,mem_vec_1 ,mem_vec_10 ,mem_vec_11 ,mem_vec_12 ,mem_vec_13 ,mem_vec_14 ,mem_vec_15 ,mem_vec_16 ,mem_vec_17 ,mem_vec_18 ,mem_vec_19 ,mem_vec_2 ,mem_vec_20 ,mem_vec_21 ,mem_vec_22 ,mem_vec_23 ,mem_vec_24 ,mem_vec_25 ,mem_vec_26 ,mem_vec_27 ,mem_vec_28 ,mem_vec_29 ,mem_vec_3 ,mem_vec_30 ,mem_vec_31 ,mem_vec_32 ,mem_vec_33 ,mem_vec_34 ,mem_vec_35 ,mem_vec_36 ,mem_vec_37 ,mem_vec_38 ,mem_vec_39 ,mem_vec_4 ,mem_vec_40 ,mem_vec_41 ,mem_vec_42 ,mem_vec_43 ,mem_vec_44 ,mem_vec_45 ,mem_vec_46 ,mem_vec_47 ,mem_vec_48 ,mem_vec_49 ,mem_vec_5 ,mem_vec_50 ,mem_vec_51 ,mem_vec_6 ,mem_vec_7 ,mem_vec_8 ,mem_vec_9 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 28) (56 / 2)
for (x1 = x2, x1_p_0 = 0;
	x1 < x2 + 56;
	x1 += 2, x1_p_0 += 2){
	// y = 56, x = 2, h = 3, w = 3, c = 64, f = 64
	// T (c, 8) (64 / 8)
	for (c0 = c1, c0_p_0 = 0;
		c0 < c1 + 64;
		c0 += 8, c0_p_0 += 8){
		// y = 56, x = 2, h = 3, w = 3, c = 8, f = 64
		// T (f, 2) (64 / 32)
		for (f = f0, fp_0 = 0;
			f < f0 + 64;
			f += 32, fp_0 += 32){
				for (y = y0, yp_0 = 0;
					y < y0 + 11;
					y += 11, yp_0 += 11){
					// y = u_y, x = 2, h = 3, w = 3, c = 8, f = 32
					// T (x, 1) (2 / 2)
					for (x0 = x1, x0_p_1 = x1_p_0, x0_p_0 = 0;
						x0 < x1 + 2;
						x0 += 2, x0_p_1 += 2, x0_p_0 += 2){
						// y = u_y, x = 2, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h0, hp_0 = 0;
							h < h0 + 3;
							h += 1, hp_0 += 1){
							// y = u_y, x = 2, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w0, wp_0 = 0;
								w < w0 + 3;
								w += 1, wp_0 += 1){
								// y = u_y, x = 2, h = 1, w = 1, c = 8, f = 32
								// T (x, 2) (2 / 1)
								for (x = x0, xp_2 = x0_p_1, xp_1 = x0_p_0, xp_0 = 0;
									x < x0 + 2;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_0 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_9 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_10 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_11 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_12 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_13 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_14 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_15 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_16 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_17 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_18 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_19 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_20 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_21 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = u_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c0, cp_1 = c0_p_0, cp_0 = 0;
												c < c0 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_0);
												mem_vec_0 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1);
												mem_vec_1 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2);
												mem_vec_2 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3);
												mem_vec_3 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4);
												mem_vec_4 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5);
												mem_vec_5 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6);
												mem_vec_6 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7);
												mem_vec_7 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8);
												mem_vec_8 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9);
												mem_vec_9 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10);
												mem_vec_10 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11);
												mem_vec_11 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_12);
												mem_vec_12 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_13);
												mem_vec_13 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14);
												mem_vec_14 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_15);
												mem_vec_15 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_16);
												mem_vec_16 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_17);
												mem_vec_17 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_18);
												mem_vec_18 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_19);
												mem_vec_19 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_20);
												mem_vec_20 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_21);
												mem_vec_21 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_0);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_12);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_15);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_16);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_17);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_18);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_19);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_20);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_21);
								}
							}
						}
					}
				}
				for (y = y0 + 11, yp_0 = 0;
					y < y0 + 11 + 45;
					y += 15, yp_0 += 15){
					// y = u_y, x = 2, h = 3, w = 3, c = 8, f = 32
					// T (x, 1) (2 / 2)
					for (x0 = x1, x0_p_1 = x1_p_0, x0_p_0 = 0;
						x0 < x1 + 2;
						x0 += 2, x0_p_1 += 2, x0_p_0 += 2){
						// y = u_y, x = 2, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h0, hp_0 = 0;
							h < h0 + 3;
							h += 1, hp_0 += 1){
							// y = u_y, x = 2, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w0, wp_0 = 0;
								w < w0 + 3;
								w += 1, wp_0 += 1){
								// y = u_y, x = 2, h = 1, w = 1, c = 8, f = 32
								// T (x, 2) (2 / 1)
								for (x = x0, xp_2 = x0_p_1, xp_1 = x0_p_0, xp_0 = 0;
									x < x0 + 2;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_22 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_23 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_24 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_25 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_26 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_27 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_28 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_29 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_30 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_31 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_32 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_33 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_34 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_35 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_36 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_37 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_38 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_39 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_40 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_41 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_42 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_43 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_44 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_45 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_46 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_47 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_48 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_49 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_50 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_51 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = u_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c0, cp_1 = c0_p_0, cp_0 = 0;
												c < c0 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_22);
												mem_vec_22 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_23);
												mem_vec_23 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_24);
												mem_vec_24 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_25);
												mem_vec_25 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_26);
												mem_vec_26 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_27);
												mem_vec_27 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_28);
												mem_vec_28 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_29);
												mem_vec_29 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_30);
												mem_vec_30 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_31);
												mem_vec_31 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_32);
												mem_vec_32 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_33);
												mem_vec_33 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_34);
												mem_vec_34 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_35);
												mem_vec_35 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_36);
												mem_vec_36 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_37);
												mem_vec_37 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_38);
												mem_vec_38 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_39);
												mem_vec_39 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_40);
												mem_vec_40 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_41);
												mem_vec_41 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_42);
												mem_vec_42 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_43);
												mem_vec_43 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_44);
												mem_vec_44 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_45);
												mem_vec_45 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_46);
												mem_vec_46 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_47);
												mem_vec_47 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_48);
												mem_vec_48 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_49);
												mem_vec_49 = vec_43;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_50);
												mem_vec_50 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_51);
												mem_vec_51 = vec_46;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_22);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_23);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_24);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_25);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_26);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_27);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_28);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_29);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_30);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_31);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_32);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_33);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_34);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_35);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_36);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_37);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_38);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_39);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_40);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_41);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_42);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_43);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_44);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_45);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_46);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_47);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_48);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_49);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_50);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_51);
								}
							}
						}
					}
				}
		}
	}
}


}