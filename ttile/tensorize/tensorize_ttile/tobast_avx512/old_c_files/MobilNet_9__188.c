#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (128, c); T (4, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 1), (Arg 3))]; T (2, c);
  T (4, f); T (1, c)]
*/
IND_TYPE c, cp_0, c1278_p_0, c1279_p_0, c1280_p_0, cp_1, c1278_p_1, c1279_p_1, cp_2, c1278_p_2, cp_3, c1278, c1279, c1280, f, fp_0, f882_p_0, fp_1, f882, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y394 = 0;
IND_TYPE x540 = 0;
IND_TYPE h = 0;
IND_TYPE w420 = 0;
IND_TYPE c1281 = 0;
IND_TYPE f883 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_4676 ,mem_vec_4677 ,mem_vec_4678 ,mem_vec_4679 ,mem_vec_4680 ,mem_vec_4681 ,mem_vec_4682 ,mem_vec_4683 ,mem_vec_4684 ,mem_vec_4685 ,mem_vec_4686 ,mem_vec_4687 ,mem_vec_4688 ,mem_vec_4689 ,mem_vec_4690 ,mem_vec_4691 ,mem_vec_4692 ,mem_vec_4693 ,mem_vec_4694 ,mem_vec_4695 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 1) (1024 / 1024)
for (c1280 = c1281, c1280_p_0 = 0;
	c1280 < c1281 + 1024;
	c1280 += 1024, c1280_p_0 += 1024){
	// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
	// T (f, 4) (1024 / 256)
	for (f882 = f883, f882_p_0 = 0;
		f882 < f883 + 1024;
		f882 += 256, f882_p_0 += 256){
		// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 256
		// T (c, 2) (1024 / 512)
		for (c1279 = c1280, c1279_p_1 = c1280_p_0, c1279_p_0 = 0;
			c1279 < c1280 + 1024;
			c1279 += 512, c1279_p_1 += 512, c1279_p_0 += 512){
				for (y = y394, yp_0 = 0;
					y < y394 + 4;
					y += 2, yp_0 += 2){
					// y = ph_y, x = 7, h = 3, w = 3, c = 512, f = 256
					// T (f, 4) (256 / 64)
					for (f = f882, fp_1 = f882_p_0, fp_0 = 0;
						f < f882 + 256;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 512, f = 64
						// T (c, 128) (512 / 4)
						for (c1278 = c1279, c1278_p_2 = c1279_p_1, c1278_p_1 = c1279_p_0, c1278_p_0 = 0;
							c1278 < c1279 + 512;
							c1278 += 4, c1278_p_2 += 4, c1278_p_1 += 4, c1278_p_0 += 4){
							// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
							// T (w, 3) (3 / 1)
							for (w = w420, wp_0 = 0;
								w < w420 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 4, f = 64
								// T (x, 7) (7 / 1)
								for (x = x540, xp_0 = 0;
									x < x540 + 7;
									x += 1, xp_0 += 1){
											mem_vec_4676 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4677 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4678 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_4679 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_4680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_4683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
											// T (c, 4) (4 / 1)
											for (c = c1278, cp_3 = c1278_p_2, cp_2 = c1278_p_1, cp_1 = c1278_p_0, cp_0 = 0;
												c < c1278 + 4;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4676);
												mem_vec_4676 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4677);
												mem_vec_4677 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4678);
												mem_vec_4678 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4679);
												mem_vec_4679 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4680);
												mem_vec_4680 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4681);
												mem_vec_4681 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4682);
												mem_vec_4682 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4683);
												mem_vec_4683 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_4676);
												mem_vec_4676 = vec_14;

												vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_4677);
												mem_vec_4677 = vec_17;

												vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

												vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_4678);
												mem_vec_4678 = vec_19;

												vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

												vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_4679);
												mem_vec_4679 = vec_21;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_24 = _mm512_set1_ps(scal_3);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_4680);
												mem_vec_4680 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_4681);
												mem_vec_4681 = vec_25;



												vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_4682);
												mem_vec_4682 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_4683);
												mem_vec_4683 = vec_27;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_29 = _mm512_set1_ps(scal_4);
												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_4676);
												mem_vec_4676 = vec_28;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_4677);
												mem_vec_4677 = vec_31;

												vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

												vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_4678);
												mem_vec_4678 = vec_33;

												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

												vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_4679);
												mem_vec_4679 = vec_35;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_38 = _mm512_set1_ps(scal_5);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_4680);
												mem_vec_4680 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_4681);
												mem_vec_4681 = vec_39;



												vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_4682);
												mem_vec_4682 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_4683);
												mem_vec_4683 = vec_41;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4676);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4677);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4678);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4679);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4680);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4681);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4682);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4683);
								}
							}
						}
					}
				}
				for (y = y394 + 4, yp_0 = 0;
					y < y394 + 4 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 512, f = 256
					// T (f, 4) (256 / 64)
					for (f = f882, fp_1 = f882_p_0, fp_0 = 0;
						f < f882 + 256;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 512, f = 64
						// T (c, 128) (512 / 4)
						for (c1278 = c1279, c1278_p_2 = c1279_p_1, c1278_p_1 = c1279_p_0, c1278_p_0 = 0;
							c1278 < c1279 + 512;
							c1278 += 4, c1278_p_2 += 4, c1278_p_1 += 4, c1278_p_0 += 4){
							// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
							// T (w, 3) (3 / 1)
							for (w = w420, wp_0 = 0;
								w < w420 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 4, f = 64
								// T (x, 7) (7 / 1)
								for (x = x540, xp_0 = 0;
									x < x540 + 7;
									x += 1, xp_0 += 1){
											mem_vec_4684 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4685 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4686 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_4687 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_4688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_4691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_4692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_4695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
											// T (c, 4) (4 / 1)
											for (c = c1278, cp_3 = c1278_p_2, cp_2 = c1278_p_1, cp_1 = c1278_p_0, cp_0 = 0;
												c < c1278 + 4;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4684);
												mem_vec_4684 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4685);
												mem_vec_4685 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4686);
												mem_vec_4686 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4687);
												mem_vec_4687 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4688);
												mem_vec_4688 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4689);
												mem_vec_4689 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4690);
												mem_vec_4690 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4691);
												mem_vec_4691 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4692);
												mem_vec_4692 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4693);
												mem_vec_4693 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4694);
												mem_vec_4694 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4695);
												mem_vec_4695 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_4684);
												mem_vec_4684 = vec_19;

												vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_4685);
												mem_vec_4685 = vec_22;

												vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

												vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_4686);
												mem_vec_4686 = vec_24;

												vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

												vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_4687);
												mem_vec_4687 = vec_26;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_29 = _mm512_set1_ps(scal_4);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_4688);
												mem_vec_4688 = vec_28;



												vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_4689);
												mem_vec_4689 = vec_30;



												vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_4690);
												mem_vec_4690 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_4691);
												mem_vec_4691 = vec_32;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_4692);
												mem_vec_4692 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_4693);
												mem_vec_4693 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_4694);
												mem_vec_4694 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_4695);
												mem_vec_4695 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_4684);
												mem_vec_4684 = vec_38;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_4685);
												mem_vec_4685 = vec_41;

												vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

												vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_4686);
												mem_vec_4686 = vec_43;

												vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

												vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_4687);
												mem_vec_4687 = vec_45;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_48 = _mm512_set1_ps(scal_7);


												vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_4688);
												mem_vec_4688 = vec_47;



												vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_4689);
												mem_vec_4689 = vec_49;



												vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_4690);
												mem_vec_4690 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_4691);
												mem_vec_4691 = vec_51;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_53 = _mm512_set1_ps(scal_8);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_4692);
												mem_vec_4692 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_4693);
												mem_vec_4693 = vec_54;



												vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_4694);
												mem_vec_4694 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_4695);
												mem_vec_4695 = vec_56;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4684);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4685);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4686);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4687);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4688);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4689);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4690);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4691);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4692);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4693);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4694);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4695);
								}
							}
						}
					}
				}
		}
	}
}


}