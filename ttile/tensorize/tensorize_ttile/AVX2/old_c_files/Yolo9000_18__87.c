#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (16, c); T (4, f); T (8, f)]
*/
IND_TYPE c, cp_0, c645_p_0, cp_1, c645, f, fp_0, f720_p_0, f721_p_0, fp_1, f720_p_1, fp_2, f720, f721, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y420 = 0;
IND_TYPE x390 = 0;
IND_TYPE h274 = 0;
IND_TYPE w341 = 0;
IND_TYPE c646 = 0;
IND_TYPE f722 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_7692 ,mem_vec_7693 ,mem_vec_7694 ,mem_vec_7695 ,mem_vec_7696 ,mem_vec_7697 ,mem_vec_7698 ,mem_vec_7699 ,mem_vec_7700 ,mem_vec_7701 ,mem_vec_7702 ,mem_vec_7703 ,mem_vec_7704 ,mem_vec_7705 ,mem_vec_7706 ,mem_vec_7707 ,mem_vec_7708 ,mem_vec_7709 ,mem_vec_7710 ,mem_vec_7711 ,mem_vec_7712 ,mem_vec_7713 ,mem_vec_7714 ,mem_vec_7715 ,mem_vec_7716 ,mem_vec_7717 ,mem_vec_7718 ,mem_vec_7719 ,mem_vec_7720 ,mem_vec_7721 ,mem_vec_7722 ,mem_vec_7723 ,mem_vec_7724 ,mem_vec_7725 ,mem_vec_7726 ,mem_vec_7727 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 8) (1024 / 128)
for (f721 = f722, f721_p_0 = 0;
	f721 < f722 + 1024;
	f721 += 128, f721_p_0 += 128){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 128
	// T (f, 4) (128 / 32)
	for (f720 = f721, f720_p_1 = f721_p_0, f720_p_0 = 0;
		f720 < f721 + 128;
		f720 += 32, f720_p_1 += 32, f720_p_0 += 32){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 32
		// T (c, 16) (512 / 32)
		for (c645 = c646, c645_p_0 = 0;
			c645 < c646 + 512;
			c645 += 32, c645_p_0 += 32){
			// y = 17, x = 17, h = 3, w = 3, c = 32, f = 32
			// T (f, 1) (32 / 32)
			for (f = f720, fp_2 = f720_p_1, fp_1 = f720_p_0, fp_0 = 0;
				f < f720 + 32;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y420, yp_0 = 0;
						y < y420 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x390, xp_0 = 0;
							x < x390 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h274, hp_0 = 0;
								h < h274 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w341, wp_0 = 0;
									w < w341 + 3;
									w += 1, wp_0 += 1){
											mem_vec_7692 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7693 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7694 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7695 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_7696 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7697 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7698 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7699 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_7700 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7701 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7702 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7703 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_7704 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7705 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_7706 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7707 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c645, cp_1 = c645_p_0, cp_0 = 0;
												c < c645 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7692);
												mem_vec_7692 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7693);
												mem_vec_7693 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7694);
												mem_vec_7694 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7695);
												mem_vec_7695 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7696);
												mem_vec_7696 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7697);
												mem_vec_7697 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7698);
												mem_vec_7698 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7699);
												mem_vec_7699 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7700);
												mem_vec_7700 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7701);
												mem_vec_7701 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7702);
												mem_vec_7702 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7703);
												mem_vec_7703 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7704);
												mem_vec_7704 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7705);
												mem_vec_7705 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7706);
												mem_vec_7706 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7707);
												mem_vec_7707 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7692);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7693);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7694);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7695);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7696);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7697);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7698);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7699);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7700);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7701);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7702);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7703);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7704);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7705);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7706);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7707);
								}
							}
						}
					}
					for (y = y420 + 12, yp_0 = 0;
						y < y420 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x390, xp_0 = 0;
							x < x390 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h274, hp_0 = 0;
								h < h274 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w341, wp_0 = 0;
									w < w341 + 3;
									w += 1, wp_0 += 1){
											mem_vec_7708 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7709 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7710 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7711 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_7712 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7713 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7714 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7715 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_7716 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7717 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7718 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7719 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_7720 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7721 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_7722 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7723 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_7724 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7725 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_7726 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7727 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c645, cp_1 = c645_p_0, cp_0 = 0;
												c < c645 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7708);
												mem_vec_7708 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7709);
												mem_vec_7709 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7710);
												mem_vec_7710 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7711);
												mem_vec_7711 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7712);
												mem_vec_7712 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7713);
												mem_vec_7713 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7714);
												mem_vec_7714 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7715);
												mem_vec_7715 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7716);
												mem_vec_7716 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7717);
												mem_vec_7717 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7718);
												mem_vec_7718 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7719);
												mem_vec_7719 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7720);
												mem_vec_7720 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7721);
												mem_vec_7721 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7722);
												mem_vec_7722 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7723);
												mem_vec_7723 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_7724);
												mem_vec_7724 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_7725);
												mem_vec_7725 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_7726);
												mem_vec_7726 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_7727);
												mem_vec_7727 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7708);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7709);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7710);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7711);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7712);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7713);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7714);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7715);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7716);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7717);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7718);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7719);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7720);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7721);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7722);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7723);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7724);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7725);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7726);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_7727);
								}
							}
						}
					}
			}
		}
	}
}


}