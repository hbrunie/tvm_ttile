#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (1, f); T (14, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (8, f);
  T (64, c); T (1, f)]
*/
IND_TYPE c, cp_0, c552_p_0, cp_1, c552, f, fp_0, f736_p_0, f737_p_0, fp_1, f736_p_1, fp_2, f736, f737, h, hp_0, w, wp_0, x, xp_0, x552_p_0, xp_1, x552, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y368 = 0;
IND_TYPE x553 = 0;
IND_TYPE h322 = 0;
IND_TYPE w304 = 0;
IND_TYPE c553 = 0;
IND_TYPE f738 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_5744 ,mem_vec_5745 ,mem_vec_5746 ,mem_vec_5747 ,mem_vec_5748 ,mem_vec_5749 ,mem_vec_5750 ,mem_vec_5751 ,mem_vec_5752 ,mem_vec_5753 ,mem_vec_5754 ,mem_vec_5755 ,mem_vec_5756 ,mem_vec_5757 ,mem_vec_5758 ,mem_vec_5759 ,mem_vec_5760 ,mem_vec_5761 ,mem_vec_5762 ,mem_vec_5763 ,mem_vec_5764 ,mem_vec_5765 ,mem_vec_5766 ,mem_vec_5767 ,mem_vec_5768 ,mem_vec_5769 ,mem_vec_5770 ,mem_vec_5771 ,mem_vec_5772 ,mem_vec_5773 ,mem_vec_5774 ,mem_vec_5775 ,mem_vec_5776 ,mem_vec_5777 ,mem_vec_5778 ,mem_vec_5779 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f737 = f738, f737_p_0 = 0;
	f737 < f738 + 256;
	f737 += 256, f737_p_0 += 256){
	// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
	// T (c, 64) (128 / 2)
	for (c552 = c553, c552_p_0 = 0;
		c552 < c553 + 128;
		c552 += 2, c552_p_0 += 2){
		// y = 14, x = 14, h = 3, w = 3, c = 2, f = 256
		// T (f, 8) (256 / 32)
		for (f736 = f737, f736_p_1 = f737_p_0, f736_p_0 = 0;
			f736 < f737 + 256;
			f736 += 32, f736_p_1 += 32, f736_p_0 += 32){
				for (y = y368, yp_0 = 0;
					y < y368 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 32
					// T (x, 14) (14 / 1)
					for (x552 = x553, x552_p_0 = 0;
						x552 < x553 + 14;
						x552 += 1, x552_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
						// T (f, 1) (32 / 32)
						for (f = f736, fp_2 = f736_p_1, fp_1 = f736_p_0, fp_0 = 0;
							f < f736 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h322, hp_0 = 0;
								h < h322 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w304, wp_0 = 0;
									w < w304 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x552, xp_1 = x552_p_0, xp_0 = 0;
										x < x552 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5744 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5745 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_5746 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5747 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_5748 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5749 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_5750 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5751 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_5752 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5753 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_5754 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5755 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_5756 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5757 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_5758 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5759 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c552, cp_1 = c552_p_0, cp_0 = 0;
													c < c552 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5744);
													mem_vec_5744 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5745);
													mem_vec_5745 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5746);
													mem_vec_5746 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5747);
													mem_vec_5747 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5748);
													mem_vec_5748 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5749);
													mem_vec_5749 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5750);
													mem_vec_5750 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5751);
													mem_vec_5751 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5752);
													mem_vec_5752 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5753);
													mem_vec_5753 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5754);
													mem_vec_5754 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5755);
													mem_vec_5755 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5756);
													mem_vec_5756 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5757);
													mem_vec_5757 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5758);
													mem_vec_5758 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5759);
													mem_vec_5759 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5744);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5745);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5746);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5747);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5748);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5749);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5750);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5751);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5752);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5753);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5754);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5755);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5756);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5757);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5758);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5759);
									}
								}
							}
						}
					}
				}
				for (y = y368 + 4, yp_0 = 0;
					y < y368 + 4 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 32
					// T (x, 14) (14 / 1)
					for (x552 = x553, x552_p_0 = 0;
						x552 < x553 + 14;
						x552 += 1, x552_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
						// T (f, 1) (32 / 32)
						for (f = f736, fp_2 = f736_p_1, fp_1 = f736_p_0, fp_0 = 0;
							f < f736 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h322, hp_0 = 0;
								h < h322 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w304, wp_0 = 0;
									w < w304 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x552, xp_1 = x552_p_0, xp_0 = 0;
										x < x552 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5760 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5761 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_5762 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5763 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_5764 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5765 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_5766 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5767 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_5768 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5769 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_5770 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5771 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_5772 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5773 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_5774 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5775 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_5776 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5777 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_5778 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5779 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c552, cp_1 = c552_p_0, cp_0 = 0;
													c < c552 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5760);
													mem_vec_5760 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5761);
													mem_vec_5761 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5762);
													mem_vec_5762 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5763);
													mem_vec_5763 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5764);
													mem_vec_5764 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5765);
													mem_vec_5765 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5766);
													mem_vec_5766 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5767);
													mem_vec_5767 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5768);
													mem_vec_5768 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5769);
													mem_vec_5769 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5770);
													mem_vec_5770 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5771);
													mem_vec_5771 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5772);
													mem_vec_5772 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5773);
													mem_vec_5773 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5774);
													mem_vec_5774 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5775);
													mem_vec_5775 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5776);
													mem_vec_5776 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5777);
													mem_vec_5777 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5778);
													mem_vec_5778 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5779);
													mem_vec_5779 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5760);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5761);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5762);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5763);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5764);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5765);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5766);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5767);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5768);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5769);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5770);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5771);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5772);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5773);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5774);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5775);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5776);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5777);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5778);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5779);
									}
								}
							}
						}
					}
				}
		}
	}
}


}