#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x); T (2, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (8, c); T (17, x); T (4, f)]
*/
IND_TYPE c, cp_0, c984_p_0, cp_1, c984, f, fp_0, f1312_p_0, f1313_p_0, fp_1, f1312_p_1, fp_2, f1312, f1313, x, xp_0, x1312_p_0, x1313_p_0, xp_1, x1312_p_1, xp_2, x1312, x1313, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y656 = 0;
IND_TYPE x1314 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c985 = 0;
IND_TYPE f1314 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_11808 ,mem_vec_11809 ,mem_vec_11810 ,mem_vec_11811 ,mem_vec_11812 ,mem_vec_11813 ,mem_vec_11814 ,mem_vec_11815 ,mem_vec_11816 ,mem_vec_11817 ,mem_vec_11818 ,mem_vec_11819 ,mem_vec_11820 ,mem_vec_11821 ,mem_vec_11822 ,mem_vec_11823 ,mem_vec_11824 ,mem_vec_11825 ,mem_vec_11826 ,mem_vec_11827 ,mem_vec_11828 ,mem_vec_11829 ,mem_vec_11830 ,mem_vec_11831 ,mem_vec_11832 ,mem_vec_11833 ,mem_vec_11834 ,mem_vec_11835 ,mem_vec_11836 ,mem_vec_11837 ,mem_vec_11838 ,mem_vec_11839 ,mem_vec_11840 ,mem_vec_11841 ,mem_vec_11842 ,mem_vec_11843 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 4) (512 / 128)
for (f1313 = f1314, f1313_p_0 = 0;
	f1313 < f1314 + 512;
	f1313 += 128, f1313_p_0 += 128){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 128
	// T (x, 17) (17 / 1)
	for (x1313 = x1314, x1313_p_0 = 0;
		x1313 < x1314 + 17;
		x1313 += 1, x1313_p_0 += 1){
		// y = 17, x = 1, h = 1, w = 1, c = 1024, f = 128
		// T (c, 8) (1024 / 128)
		for (c984 = c985, c984_p_0 = 0;
			c984 < c985 + 1024;
			c984 += 128, c984_p_0 += 128){
			// y = 17, x = 1, h = 1, w = 1, c = 128, f = 128
			// T (f, 2) (128 / 64)
			for (f1312 = f1313, f1312_p_1 = f1313_p_0, f1312_p_0 = 0;
				f1312 < f1313 + 128;
				f1312 += 64, f1312_p_1 += 64, f1312_p_0 += 64){
					for (y = y656, yp_0 = 0;
						y < y656 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
						// T (x, 1) (1 / 1)
						for (x1312 = x1313, x1312_p_1 = x1313_p_0, x1312_p_0 = 0;
							x1312 < x1313 + 1;
							x1312 += 1, x1312_p_1 += 1, x1312_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1312, fp_2 = f1312_p_1, fp_1 = f1312_p_0, fp_0 = 0;
								f < f1312 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1312, xp_2 = x1312_p_1, xp_1 = x1312_p_0, xp_0 = 0;
									x < x1312 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11808 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_11809 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_11810 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_11811 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_11812 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_11813 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_11814 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_11815 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_11816 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_11817 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_11818 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11819 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_11820 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_11821 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_11822 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_11823 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c984, cp_1 = c984_p_0, cp_0 = 0;
												c < c984 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11808);
												mem_vec_11808 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11809);
												mem_vec_11809 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11810);
												mem_vec_11810 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11811);
												mem_vec_11811 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11812);
												mem_vec_11812 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11813);
												mem_vec_11813 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11814);
												mem_vec_11814 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11815);
												mem_vec_11815 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11816);
												mem_vec_11816 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11817);
												mem_vec_11817 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11818);
												mem_vec_11818 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11819);
												mem_vec_11819 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11820);
												mem_vec_11820 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11821);
												mem_vec_11821 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11822);
												mem_vec_11822 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11823);
												mem_vec_11823 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11808);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11809);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11810);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11811);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11812);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11813);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11814);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11815);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11816);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11817);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11818);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11819);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11820);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11821);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11822);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11823);
								}
							}
						}
					}
					for (y = y656 + 12, yp_0 = 0;
						y < y656 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
						// T (x, 1) (1 / 1)
						for (x1312 = x1313, x1312_p_1 = x1313_p_0, x1312_p_0 = 0;
							x1312 < x1313 + 1;
							x1312 += 1, x1312_p_1 += 1, x1312_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1312, fp_2 = f1312_p_1, fp_1 = f1312_p_0, fp_0 = 0;
								f < f1312 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1312, xp_2 = x1312_p_1, xp_1 = x1312_p_0, xp_0 = 0;
									x < x1312 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11824 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_11825 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_11826 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_11827 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_11828 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_11829 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_11830 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_11831 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_11832 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_11833 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_11834 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11835 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_11836 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_11837 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_11838 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_11839 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_11840 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_11841 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_11842 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_11843 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c984, cp_1 = c984_p_0, cp_0 = 0;
												c < c984 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11824);
												mem_vec_11824 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11825);
												mem_vec_11825 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11826);
												mem_vec_11826 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11827);
												mem_vec_11827 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11828);
												mem_vec_11828 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11829);
												mem_vec_11829 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11830);
												mem_vec_11830 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11831);
												mem_vec_11831 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11832);
												mem_vec_11832 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11833);
												mem_vec_11833 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11834);
												mem_vec_11834 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11835);
												mem_vec_11835 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11836);
												mem_vec_11836 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11837);
												mem_vec_11837 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11838);
												mem_vec_11838 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11839);
												mem_vec_11839 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11840);
												mem_vec_11840 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11841);
												mem_vec_11841 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11842);
												mem_vec_11842 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11843);
												mem_vec_11843 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11824);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11825);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11826);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11827);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11828);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11829);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11830);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11831);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11832);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11833);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11834);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11835);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11836);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11837);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11838);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11839);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11840);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11841);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11842);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11843);
								}
							}
						}
					}
			}
		}
	}
}


}