#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (8, c); T (4, f); T (4, f)]
*/
IND_TYPE c, cp_0, c576_p_0, cp_1, c576, f, fp_0, f628_p_0, f629_p_0, fp_1, f628_p_1, fp_2, f628, f629, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y374 = 0;
IND_TYPE x344 = 0;
IND_TYPE h238 = 0;
IND_TYPE w305 = 0;
IND_TYPE c577 = 0;
IND_TYPE f630 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_6784 ,mem_vec_6785 ,mem_vec_6786 ,mem_vec_6787 ,mem_vec_6788 ,mem_vec_6789 ,mem_vec_6790 ,mem_vec_6791 ,mem_vec_6792 ,mem_vec_6793 ,mem_vec_6794 ,mem_vec_6795 ,mem_vec_6796 ,mem_vec_6797 ,mem_vec_6798 ,mem_vec_6799 ,mem_vec_6800 ,mem_vec_6801 ,mem_vec_6802 ,mem_vec_6803 ,mem_vec_6804 ,mem_vec_6805 ,mem_vec_6806 ,mem_vec_6807 ,mem_vec_6808 ,mem_vec_6809 ,mem_vec_6810 ,mem_vec_6811 ,mem_vec_6812 ,mem_vec_6813 ,mem_vec_6814 ,mem_vec_6815 ,mem_vec_6816 ,mem_vec_6817 ,mem_vec_6818 ,mem_vec_6819 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 4) (1024 / 256)
for (f629 = f630, f629_p_0 = 0;
	f629 < f630 + 1024;
	f629 += 256, f629_p_0 += 256){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 256
	// T (f, 4) (256 / 64)
	for (f628 = f629, f628_p_1 = f629_p_0, f628_p_0 = 0;
		f628 < f629 + 256;
		f628 += 64, f628_p_1 += 64, f628_p_0 += 64){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 64
		// T (c, 8) (512 / 64)
		for (c576 = c577, c576_p_0 = 0;
			c576 < c577 + 512;
			c576 += 64, c576_p_0 += 64){
			// y = 17, x = 17, h = 3, w = 3, c = 64, f = 64
			// T (f, 2) (64 / 32)
			for (f = f628, fp_2 = f628_p_1, fp_1 = f628_p_0, fp_0 = 0;
				f < f628 + 64;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y374, yp_0 = 0;
						y < y374 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
						// T (x, 17) (17 / 1)
						for (x = x344, xp_0 = 0;
							x < x344 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h238, hp_0 = 0;
								h < h238 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w305, wp_0 = 0;
									w < w305 + 3;
									w += 1, wp_0 += 1){
											mem_vec_6784 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6785 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6786 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6787 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_6788 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6789 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6790 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6791 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_6792 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6793 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6794 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6795 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_6796 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6797 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6798 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6799 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c576, cp_1 = c576_p_0, cp_0 = 0;
												c < c576 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6784);
												mem_vec_6784 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6785);
												mem_vec_6785 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6786);
												mem_vec_6786 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6787);
												mem_vec_6787 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6788);
												mem_vec_6788 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6789);
												mem_vec_6789 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6790);
												mem_vec_6790 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6791);
												mem_vec_6791 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6792);
												mem_vec_6792 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6793);
												mem_vec_6793 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6794);
												mem_vec_6794 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6795);
												mem_vec_6795 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6796);
												mem_vec_6796 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6797);
												mem_vec_6797 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6798);
												mem_vec_6798 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6799);
												mem_vec_6799 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6784);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6785);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6786);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6787);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6788);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6789);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6790);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6791);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6792);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6793);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6794);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6795);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6796);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6797);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6798);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6799);
								}
							}
						}
					}
					for (y = y374 + 12, yp_0 = 0;
						y < y374 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
						// T (x, 17) (17 / 1)
						for (x = x344, xp_0 = 0;
							x < x344 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h238, hp_0 = 0;
								h < h238 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w305, wp_0 = 0;
									w < w305 + 3;
									w += 1, wp_0 += 1){
											mem_vec_6800 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6801 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6802 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6803 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_6804 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6805 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6806 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6807 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_6808 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6809 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6810 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6811 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_6812 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6813 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6814 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6815 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_6816 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6817 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_6818 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6819 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c576, cp_1 = c576_p_0, cp_0 = 0;
												c < c576 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6800);
												mem_vec_6800 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6801);
												mem_vec_6801 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6802);
												mem_vec_6802 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6803);
												mem_vec_6803 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6804);
												mem_vec_6804 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6805);
												mem_vec_6805 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6806);
												mem_vec_6806 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6807);
												mem_vec_6807 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6808);
												mem_vec_6808 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6809);
												mem_vec_6809 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6810);
												mem_vec_6810 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6811);
												mem_vec_6811 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6812);
												mem_vec_6812 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6813);
												mem_vec_6813 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6814);
												mem_vec_6814 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6815);
												mem_vec_6815 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6816);
												mem_vec_6816 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6817);
												mem_vec_6817 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6818);
												mem_vec_6818 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6819);
												mem_vec_6819 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6800);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6801);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6802);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6803);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6804);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6805);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6806);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6807);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6808);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6809);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6810);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6811);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6812);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6813);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6814);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6815);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6816);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6817);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6818);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6819);
								}
							}
						}
					}
			}
		}
	}
}


}