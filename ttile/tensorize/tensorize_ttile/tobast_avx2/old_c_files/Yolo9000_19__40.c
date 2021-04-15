#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (1, f);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (512, c); T (1, x); T (16, f)]
*/
IND_TYPE c, cp_0, c810_p_0, cp_1, c810, f, fp_0, f1080_p_0, f1081_p_0, fp_1, f1080_p_1, fp_2, f1080, f1081, x, xp_0, x1080_p_0, x1081_p_0, xp_1, x1080_p_1, xp_2, x1080, x1081, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y540 = 0;
IND_TYPE x1082 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c811 = 0;
IND_TYPE f1082 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_9720 ,mem_vec_9721 ,mem_vec_9722 ,mem_vec_9723 ,mem_vec_9724 ,mem_vec_9725 ,mem_vec_9726 ,mem_vec_9727 ,mem_vec_9728 ,mem_vec_9729 ,mem_vec_9730 ,mem_vec_9731 ,mem_vec_9732 ,mem_vec_9733 ,mem_vec_9734 ,mem_vec_9735 ,mem_vec_9736 ,mem_vec_9737 ,mem_vec_9738 ,mem_vec_9739 ,mem_vec_9740 ,mem_vec_9741 ,mem_vec_9742 ,mem_vec_9743 ,mem_vec_9744 ,mem_vec_9745 ,mem_vec_9746 ,mem_vec_9747 ,mem_vec_9748 ,mem_vec_9749 ,mem_vec_9750 ,mem_vec_9751 ,mem_vec_9752 ,mem_vec_9753 ,mem_vec_9754 ,mem_vec_9755 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 16) (512 / 32)
for (f1081 = f1082, f1081_p_0 = 0;
	f1081 < f1082 + 512;
	f1081 += 32, f1081_p_0 += 32){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 32
	// T (x, 1) (17 / 17)
	for (x1081 = x1082, x1081_p_0 = 0;
		x1081 < x1082 + 17;
		x1081 += 17, x1081_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 32
		// T (c, 512) (1024 / 2)
		for (c810 = c811, c810_p_0 = 0;
			c810 < c811 + 1024;
			c810 += 2, c810_p_0 += 2){
			// y = 17, x = 17, h = 1, w = 1, c = 2, f = 32
			// T (f, 1) (32 / 32)
			for (f1080 = f1081, f1080_p_1 = f1081_p_0, f1080_p_0 = 0;
				f1080 < f1081 + 32;
				f1080 += 32, f1080_p_1 += 32, f1080_p_0 += 32){
					for (y = y540, yp_0 = 0;
						y < y540 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 32
						// T (x, 17) (17 / 1)
						for (x1080 = x1081, x1080_p_1 = x1081_p_0, x1080_p_0 = 0;
							x1080 < x1081 + 17;
							x1080 += 1, x1080_p_1 += 1, x1080_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1080, fp_2 = f1080_p_1, fp_1 = f1080_p_0, fp_0 = 0;
								f < f1080 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1080, xp_2 = x1080_p_1, xp_1 = x1080_p_0, xp_0 = 0;
									x < x1080 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9720 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9721 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_9722 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9723 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_9724 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9725 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_9726 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9727 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_9728 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9729 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_9730 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9731 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_9732 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9733 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_9734 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9735 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c810, cp_1 = c810_p_0, cp_0 = 0;
												c < c810 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9720);
												mem_vec_9720 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9721);
												mem_vec_9721 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9722);
												mem_vec_9722 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9723);
												mem_vec_9723 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9724);
												mem_vec_9724 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9725);
												mem_vec_9725 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9726);
												mem_vec_9726 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9727);
												mem_vec_9727 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9728);
												mem_vec_9728 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9729);
												mem_vec_9729 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9730);
												mem_vec_9730 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9731);
												mem_vec_9731 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9732);
												mem_vec_9732 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9733);
												mem_vec_9733 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9734);
												mem_vec_9734 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9735);
												mem_vec_9735 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9720);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9721);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9722);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9723);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9724);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9725);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9726);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9727);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9728);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9729);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9730);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9731);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9732);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9733);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9734);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9735);
								}
							}
						}
					}
					for (y = y540 + 12, yp_0 = 0;
						y < y540 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 32
						// T (x, 17) (17 / 1)
						for (x1080 = x1081, x1080_p_1 = x1081_p_0, x1080_p_0 = 0;
							x1080 < x1081 + 17;
							x1080 += 1, x1080_p_1 += 1, x1080_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1080, fp_2 = f1080_p_1, fp_1 = f1080_p_0, fp_0 = 0;
								f < f1080 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1080, xp_2 = x1080_p_1, xp_1 = x1080_p_0, xp_0 = 0;
									x < x1080 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9736 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9737 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_9738 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9739 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_9740 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9741 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_9742 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9743 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_9744 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9745 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_9746 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9747 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_9748 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9749 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_9750 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9751 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_9752 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_9753 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_9754 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_9755 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c810, cp_1 = c810_p_0, cp_0 = 0;
												c < c810 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9736);
												mem_vec_9736 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9737);
												mem_vec_9737 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9738);
												mem_vec_9738 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9739);
												mem_vec_9739 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9740);
												mem_vec_9740 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9741);
												mem_vec_9741 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9742);
												mem_vec_9742 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9743);
												mem_vec_9743 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9744);
												mem_vec_9744 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9745);
												mem_vec_9745 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9746);
												mem_vec_9746 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9747);
												mem_vec_9747 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9748);
												mem_vec_9748 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9749);
												mem_vec_9749 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9750);
												mem_vec_9750 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9751);
												mem_vec_9751 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_9752);
												mem_vec_9752 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_9753);
												mem_vec_9753 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_9754);
												mem_vec_9754 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_9755);
												mem_vec_9755 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9736);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9737);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9738);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9739);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9740);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9741);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9742);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9743);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9744);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9745);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9746);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9747);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9748);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9749);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9750);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9751);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9752);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9753);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9754);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_9755);
								}
							}
						}
					}
			}
		}
	}
}


}