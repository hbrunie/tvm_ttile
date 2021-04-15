#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (512, c); Hoist_vars [c]; T (17, x); T (1, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (2, c); T (1, x); T (8, f)]
*/
IND_TYPE c, cp_0, c66_p_0, cp_1, c66, f, fp_0, f88_p_0, f89_p_0, fp_1, f88_p_1, fp_2, f88, f89, x, xp_0, x88_p_0, x89_p_0, xp_1, x88_p_1, xp_2, x88, x89, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y44 = 0;
IND_TYPE x90 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c67 = 0;
IND_TYPE f90 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_792 ,mem_vec_793 ,mem_vec_794 ,mem_vec_795 ,mem_vec_796 ,mem_vec_797 ,mem_vec_798 ,mem_vec_799 ,mem_vec_800 ,mem_vec_801 ,mem_vec_802 ,mem_vec_803 ,mem_vec_804 ,mem_vec_805 ,mem_vec_806 ,mem_vec_807 ,mem_vec_808 ,mem_vec_809 ,mem_vec_810 ,mem_vec_811 ,mem_vec_812 ,mem_vec_813 ,mem_vec_814 ,mem_vec_815 ,mem_vec_816 ,mem_vec_817 ,mem_vec_818 ,mem_vec_819 ,mem_vec_820 ,mem_vec_821 ,mem_vec_822 ,mem_vec_823 ,mem_vec_824 ,mem_vec_825 ,mem_vec_826 ,mem_vec_827 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 8) (512 / 64)
for (f89 = f90, f89_p_0 = 0;
	f89 < f90 + 512;
	f89 += 64, f89_p_0 += 64){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 64
	// T (x, 1) (17 / 17)
	for (x89 = x90, x89_p_0 = 0;
		x89 < x90 + 17;
		x89 += 17, x89_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 64
		// T (c, 2) (1024 / 512)
		for (c66 = c67, c66_p_0 = 0;
			c66 < c67 + 1024;
			c66 += 512, c66_p_0 += 512){
			// y = 17, x = 17, h = 1, w = 1, c = 512, f = 64
			// T (f, 2) (64 / 32)
			for (f88 = f89, f88_p_1 = f89_p_0, f88_p_0 = 0;
				f88 < f89 + 64;
				f88 += 32, f88_p_1 += 32, f88_p_0 += 32){
					for (y = y44, yp_0 = 0;
						y < y44 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
						// T (x, 1) (17 / 17)
						for (x88 = x89, x88_p_1 = x89_p_0, x88_p_0 = 0;
							x88 < x89 + 17;
							x88 += 17, x88_p_1 += 17, x88_p_0 += 17){
							// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
							// T (f, 1) (32 / 32)
							for (f = f88, fp_2 = f88_p_1, fp_1 = f88_p_0, fp_0 = 0;
								f < f88 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
								// T (x, 17) (17 / 1)
								for (x = x88, xp_2 = x88_p_1, xp_1 = x88_p_0, xp_0 = 0;
									x < x88 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_792 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_793 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_794 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_795 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_796 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_797 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_798 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_799 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_800 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_801 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_802 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_803 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_804 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_805 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_806 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_807 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
											// T (c, 512) (512 / 1)
											for (c = c66, cp_1 = c66_p_0, cp_0 = 0;
												c < c66 + 512;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_792);
												mem_vec_792 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_793);
												mem_vec_793 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_794);
												mem_vec_794 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_795);
												mem_vec_795 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_796);
												mem_vec_796 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_797);
												mem_vec_797 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_798);
												mem_vec_798 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_799);
												mem_vec_799 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_800);
												mem_vec_800 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_801);
												mem_vec_801 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_802);
												mem_vec_802 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_803);
												mem_vec_803 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_804);
												mem_vec_804 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_805);
												mem_vec_805 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_806);
												mem_vec_806 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_807);
												mem_vec_807 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_792);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_793);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_794);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_795);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_796);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_797);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_798);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_799);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_800);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_801);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_802);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_803);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_804);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_805);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_806);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_807);
								}
							}
						}
					}
					for (y = y44 + 12, yp_0 = 0;
						y < y44 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
						// T (x, 1) (17 / 17)
						for (x88 = x89, x88_p_1 = x89_p_0, x88_p_0 = 0;
							x88 < x89 + 17;
							x88 += 17, x88_p_1 += 17, x88_p_0 += 17){
							// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
							// T (f, 1) (32 / 32)
							for (f = f88, fp_2 = f88_p_1, fp_1 = f88_p_0, fp_0 = 0;
								f < f88 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
								// T (x, 17) (17 / 1)
								for (x = x88, xp_2 = x88_p_1, xp_1 = x88_p_0, xp_0 = 0;
									x < x88 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_808 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_809 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_810 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_811 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_812 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_813 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_814 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_815 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_816 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_817 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_818 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_819 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_820 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_821 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_822 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_823 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_824 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_825 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_826 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_827 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
											// T (c, 512) (512 / 1)
											for (c = c66, cp_1 = c66_p_0, cp_0 = 0;
												c < c66 + 512;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_808);
												mem_vec_808 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_809);
												mem_vec_809 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_810);
												mem_vec_810 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_811);
												mem_vec_811 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_812);
												mem_vec_812 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_813);
												mem_vec_813 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_814);
												mem_vec_814 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_815);
												mem_vec_815 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_816);
												mem_vec_816 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_817);
												mem_vec_817 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_818);
												mem_vec_818 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_819);
												mem_vec_819 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_820);
												mem_vec_820 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_821);
												mem_vec_821 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_822);
												mem_vec_822 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_823);
												mem_vec_823 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_824);
												mem_vec_824 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_825);
												mem_vec_825 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_826);
												mem_vec_826 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_827);
												mem_vec_827 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_808);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_809);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_810);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_811);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_812);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_813);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_814);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_815);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_816);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_817);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_818);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_819);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_820);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_821);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_822);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_823);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_824);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_825);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_826);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_827);
								}
							}
						}
					}
			}
		}
	}
}


}