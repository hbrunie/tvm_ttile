#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (512, c); Hoist_vars [c]; T (1, x); T (8, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (2, c); T (17, x); T (1, f)]
*/
IND_TYPE c, cp_0, c900_p_0, cp_1, c900, f, fp_0, f1200_p_0, f1201_p_0, fp_1, f1200_p_1, fp_2, f1200, f1201, x, xp_0, x1200_p_0, x1201_p_0, xp_1, x1200_p_1, xp_2, x1200, x1201, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y600 = 0;
IND_TYPE x1202 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c901 = 0;
IND_TYPE f1202 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_10800 ,mem_vec_10801 ,mem_vec_10802 ,mem_vec_10803 ,mem_vec_10804 ,mem_vec_10805 ,mem_vec_10806 ,mem_vec_10807 ,mem_vec_10808 ,mem_vec_10809 ,mem_vec_10810 ,mem_vec_10811 ,mem_vec_10812 ,mem_vec_10813 ,mem_vec_10814 ,mem_vec_10815 ,mem_vec_10816 ,mem_vec_10817 ,mem_vec_10818 ,mem_vec_10819 ,mem_vec_10820 ,mem_vec_10821 ,mem_vec_10822 ,mem_vec_10823 ,mem_vec_10824 ,mem_vec_10825 ,mem_vec_10826 ,mem_vec_10827 ,mem_vec_10828 ,mem_vec_10829 ,mem_vec_10830 ,mem_vec_10831 ,mem_vec_10832 ,mem_vec_10833 ,mem_vec_10834 ,mem_vec_10835 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 1) (512 / 512)
for (f1201 = f1202, f1201_p_0 = 0;
	f1201 < f1202 + 512;
	f1201 += 512, f1201_p_0 += 512){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (x, 17) (17 / 1)
	for (x1201 = x1202, x1201_p_0 = 0;
		x1201 < x1202 + 17;
		x1201 += 1, x1201_p_0 += 1){
		// y = 17, x = 1, h = 1, w = 1, c = 1024, f = 512
		// T (c, 2) (1024 / 512)
		for (c900 = c901, c900_p_0 = 0;
			c900 < c901 + 1024;
			c900 += 512, c900_p_0 += 512){
			// y = 17, x = 1, h = 1, w = 1, c = 512, f = 512
			// T (f, 2) (512 / 256)
			for (f1200 = f1201, f1200_p_1 = f1201_p_0, f1200_p_0 = 0;
				f1200 < f1201 + 512;
				f1200 += 256, f1200_p_1 += 256, f1200_p_0 += 256){
					for (y = y600, yp_0 = 0;
						y < y600 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 256
						// T (x, 1) (1 / 1)
						for (x1200 = x1201, x1200_p_1 = x1201_p_0, x1200_p_0 = 0;
							x1200 < x1201 + 1;
							x1200 += 1, x1200_p_1 += 1, x1200_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1200, fp_2 = f1200_p_1, fp_1 = f1200_p_0, fp_0 = 0;
								f < f1200 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1200, xp_2 = x1200_p_1, xp_1 = x1200_p_0, xp_0 = 0;
									x < x1200 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_10800 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_10801 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_10802 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_10803 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_10804 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_10805 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_10806 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_10807 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_10808 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_10809 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_10810 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_10811 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_10812 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_10813 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_10814 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_10815 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
											// T (c, 512) (512 / 1)
											for (c = c900, cp_1 = c900_p_0, cp_0 = 0;
												c < c900 + 512;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10800);
												mem_vec_10800 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10801);
												mem_vec_10801 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10802);
												mem_vec_10802 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10803);
												mem_vec_10803 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10804);
												mem_vec_10804 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10805);
												mem_vec_10805 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10806);
												mem_vec_10806 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10807);
												mem_vec_10807 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10808);
												mem_vec_10808 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10809);
												mem_vec_10809 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10810);
												mem_vec_10810 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10811);
												mem_vec_10811 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10812);
												mem_vec_10812 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10813);
												mem_vec_10813 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10814);
												mem_vec_10814 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10815);
												mem_vec_10815 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10800);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10801);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10802);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10803);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10804);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10805);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10806);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10807);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10808);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10809);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10810);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10811);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10812);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10813);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10814);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10815);
								}
							}
						}
					}
					for (y = y600 + 12, yp_0 = 0;
						y < y600 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 256
						// T (x, 1) (1 / 1)
						for (x1200 = x1201, x1200_p_1 = x1201_p_0, x1200_p_0 = 0;
							x1200 < x1201 + 1;
							x1200 += 1, x1200_p_1 += 1, x1200_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1200, fp_2 = f1200_p_1, fp_1 = f1200_p_0, fp_0 = 0;
								f < f1200 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1200, xp_2 = x1200_p_1, xp_1 = x1200_p_0, xp_0 = 0;
									x < x1200 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_10816 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_10817 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_10818 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_10819 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_10820 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_10821 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_10822 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_10823 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_10824 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_10825 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_10826 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_10827 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_10828 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_10829 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_10830 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_10831 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_10832 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_10833 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_10834 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_10835 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
											// T (c, 512) (512 / 1)
											for (c = c900, cp_1 = c900_p_0, cp_0 = 0;
												c < c900 + 512;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10816);
												mem_vec_10816 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10817);
												mem_vec_10817 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10818);
												mem_vec_10818 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10819);
												mem_vec_10819 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10820);
												mem_vec_10820 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10821);
												mem_vec_10821 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10822);
												mem_vec_10822 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10823);
												mem_vec_10823 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10824);
												mem_vec_10824 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10825);
												mem_vec_10825 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10826);
												mem_vec_10826 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10827);
												mem_vec_10827 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10828);
												mem_vec_10828 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10829);
												mem_vec_10829 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10830);
												mem_vec_10830 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10831);
												mem_vec_10831 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10832);
												mem_vec_10832 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10833);
												mem_vec_10833 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10834);
												mem_vec_10834 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10835);
												mem_vec_10835 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10816);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10817);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10818);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10819);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10820);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10821);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10822);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10823);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10824);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10825);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10826);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10827);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10828);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10829);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10830);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10831);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10832);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10833);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10834);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10835);
								}
							}
						}
					}
			}
		}
	}
}


}