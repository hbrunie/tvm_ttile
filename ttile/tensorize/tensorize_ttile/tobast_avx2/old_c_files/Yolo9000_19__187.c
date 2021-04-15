#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (1, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (8, f); T (256, c); T (17, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1146_p_0, cp_1, c1146, f, fp_0, f1528_p_0, f1529_p_0, fp_1, f1528_p_1, fp_2, f1528, f1529, x, xp_0, x1528_p_0, x1529_p_0, xp_1, x1528_p_1, xp_2, x1528, x1529, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y764 = 0;
IND_TYPE x1530 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1147 = 0;
IND_TYPE f1530 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_13752 ,mem_vec_13753 ,mem_vec_13754 ,mem_vec_13755 ,mem_vec_13756 ,mem_vec_13757 ,mem_vec_13758 ,mem_vec_13759 ,mem_vec_13760 ,mem_vec_13761 ,mem_vec_13762 ,mem_vec_13763 ,mem_vec_13764 ,mem_vec_13765 ,mem_vec_13766 ,mem_vec_13767 ,mem_vec_13768 ,mem_vec_13769 ,mem_vec_13770 ,mem_vec_13771 ,mem_vec_13772 ,mem_vec_13773 ,mem_vec_13774 ,mem_vec_13775 ,mem_vec_13776 ,mem_vec_13777 ,mem_vec_13778 ,mem_vec_13779 ,mem_vec_13780 ,mem_vec_13781 ,mem_vec_13782 ,mem_vec_13783 ,mem_vec_13784 ,mem_vec_13785 ,mem_vec_13786 ,mem_vec_13787 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 2) (512 / 256)
for (f1529 = f1530, f1529_p_0 = 0;
	f1529 < f1530 + 512;
	f1529 += 256, f1529_p_0 += 256){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 256
	// T (x, 17) (17 / 1)
	for (x1529 = x1530, x1529_p_0 = 0;
		x1529 < x1530 + 17;
		x1529 += 1, x1529_p_0 += 1){
		// y = 17, x = 1, h = 1, w = 1, c = 1024, f = 256
		// T (c, 256) (1024 / 4)
		for (c1146 = c1147, c1146_p_0 = 0;
			c1146 < c1147 + 1024;
			c1146 += 4, c1146_p_0 += 4){
			// y = 17, x = 1, h = 1, w = 1, c = 4, f = 256
			// T (f, 8) (256 / 32)
			for (f1528 = f1529, f1528_p_1 = f1529_p_0, f1528_p_0 = 0;
				f1528 < f1529 + 256;
				f1528 += 32, f1528_p_1 += 32, f1528_p_0 += 32){
					for (y = y764, yp_0 = 0;
						y < y764 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
						// T (x, 1) (1 / 1)
						for (x1528 = x1529, x1528_p_1 = x1529_p_0, x1528_p_0 = 0;
							x1528 < x1529 + 1;
							x1528 += 1, x1528_p_1 += 1, x1528_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1528, fp_2 = f1528_p_1, fp_1 = f1528_p_0, fp_0 = 0;
								f < f1528 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1528, xp_2 = x1528_p_1, xp_1 = x1528_p_0, xp_0 = 0;
									x < x1528 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13752 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13753 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_13754 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13755 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_13756 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13757 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_13758 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13759 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_13760 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13761 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_13762 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13763 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_13764 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13765 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_13766 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13767 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c1146, cp_1 = c1146_p_0, cp_0 = 0;
												c < c1146 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13752);
												mem_vec_13752 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13753);
												mem_vec_13753 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13754);
												mem_vec_13754 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13755);
												mem_vec_13755 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13756);
												mem_vec_13756 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13757);
												mem_vec_13757 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13758);
												mem_vec_13758 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13759);
												mem_vec_13759 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13760);
												mem_vec_13760 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13761);
												mem_vec_13761 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13762);
												mem_vec_13762 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13763);
												mem_vec_13763 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13764);
												mem_vec_13764 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13765);
												mem_vec_13765 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13766);
												mem_vec_13766 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13767);
												mem_vec_13767 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13752);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13753);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13754);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13755);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13756);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13757);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13758);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13759);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13760);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13761);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13762);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13763);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13764);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13765);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13766);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13767);
								}
							}
						}
					}
					for (y = y764 + 12, yp_0 = 0;
						y < y764 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
						// T (x, 1) (1 / 1)
						for (x1528 = x1529, x1528_p_1 = x1529_p_0, x1528_p_0 = 0;
							x1528 < x1529 + 1;
							x1528 += 1, x1528_p_1 += 1, x1528_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1528, fp_2 = f1528_p_1, fp_1 = f1528_p_0, fp_0 = 0;
								f < f1528 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1528, xp_2 = x1528_p_1, xp_1 = x1528_p_0, xp_0 = 0;
									x < x1528 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13768 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13769 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_13770 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13771 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_13772 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13773 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_13774 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13775 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_13776 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13777 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_13778 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13779 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_13780 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13781 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_13782 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13783 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_13784 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_13785 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_13786 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_13787 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c1146, cp_1 = c1146_p_0, cp_0 = 0;
												c < c1146 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13768);
												mem_vec_13768 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13769);
												mem_vec_13769 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13770);
												mem_vec_13770 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13771);
												mem_vec_13771 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13772);
												mem_vec_13772 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13773);
												mem_vec_13773 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13774);
												mem_vec_13774 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13775);
												mem_vec_13775 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13776);
												mem_vec_13776 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13777);
												mem_vec_13777 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13778);
												mem_vec_13778 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13779);
												mem_vec_13779 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13780);
												mem_vec_13780 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13781);
												mem_vec_13781 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13782);
												mem_vec_13782 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13783);
												mem_vec_13783 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_13784);
												mem_vec_13784 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_13785);
												mem_vec_13785 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_13786);
												mem_vec_13786 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_13787);
												mem_vec_13787 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13768);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13769);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13770);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13771);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13772);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13773);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13774);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13775);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13776);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13777);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13778);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13779);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13780);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13781);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13782);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13783);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13784);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_13785);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13786);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_13787);
								}
							}
						}
					}
			}
		}
	}
}


}