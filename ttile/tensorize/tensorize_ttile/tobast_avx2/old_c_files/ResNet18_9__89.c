#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (2, f); T (14, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (2, f);
  T (128, c); T (2, f)]
*/
IND_TYPE c, cp_0, c570_p_0, cp_1, c570, f, fp_0, f760_p_0, f761_p_0, fp_1, f760_p_1, fp_2, f760, f761, h, hp_0, w, wp_0, x, xp_0, x570_p_0, xp_1, x570, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y380 = 0;
IND_TYPE x571 = 0;
IND_TYPE h306 = 0;
IND_TYPE w320 = 0;
IND_TYPE c571 = 0;
IND_TYPE f762 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_5768 ,mem_vec_5769 ,mem_vec_5770 ,mem_vec_5771 ,mem_vec_5772 ,mem_vec_5773 ,mem_vec_5774 ,mem_vec_5775 ,mem_vec_5776 ,mem_vec_5777 ,mem_vec_5778 ,mem_vec_5779 ,mem_vec_5780 ,mem_vec_5781 ,mem_vec_5782 ,mem_vec_5783 ,mem_vec_5784 ,mem_vec_5785 ,mem_vec_5786 ,mem_vec_5787 ,mem_vec_5788 ,mem_vec_5789 ,mem_vec_5790 ,mem_vec_5791 ,mem_vec_5792 ,mem_vec_5793 ,mem_vec_5794 ,mem_vec_5795 ,mem_vec_5796 ,mem_vec_5797 ,mem_vec_5798 ,mem_vec_5799 ,mem_vec_5800 ,mem_vec_5801 ,mem_vec_5802 ,mem_vec_5803 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f761 = f762, f761_p_0 = 0;
	f761 < f762 + 256;
	f761 += 128, f761_p_0 += 128){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 128
	// T (c, 128) (256 / 2)
	for (c570 = c571, c570_p_0 = 0;
		c570 < c571 + 256;
		c570 += 2, c570_p_0 += 2){
		// y = 14, x = 14, h = 3, w = 3, c = 2, f = 128
		// T (f, 2) (128 / 64)
		for (f760 = f761, f760_p_1 = f761_p_0, f760_p_0 = 0;
			f760 < f761 + 128;
			f760 += 64, f760_p_1 += 64, f760_p_0 += 64){
				for (y = y380, yp_0 = 0;
					y < y380 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 64
					// T (x, 14) (14 / 1)
					for (x570 = x571, x570_p_0 = 0;
						x570 < x571 + 14;
						x570 += 1, x570_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 64
						// T (f, 2) (64 / 32)
						for (f = f760, fp_2 = f760_p_1, fp_1 = f760_p_0, fp_0 = 0;
							f < f760 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h306, hp_0 = 0;
								h < h306 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w320, wp_0 = 0;
									w < w320 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x570, xp_1 = x570_p_0, xp_0 = 0;
										x < x570 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5768 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5769 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_5770 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5771 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_5772 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5773 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_5774 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5775 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_5776 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5777 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_5778 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5779 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_5780 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5781 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_5782 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5783 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c570, cp_1 = c570_p_0, cp_0 = 0;
													c < c570 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5768);
													mem_vec_5768 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5769);
													mem_vec_5769 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5770);
													mem_vec_5770 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5771);
													mem_vec_5771 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5772);
													mem_vec_5772 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5773);
													mem_vec_5773 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5774);
													mem_vec_5774 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5775);
													mem_vec_5775 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5776);
													mem_vec_5776 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5777);
													mem_vec_5777 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5778);
													mem_vec_5778 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5779);
													mem_vec_5779 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5780);
													mem_vec_5780 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5781);
													mem_vec_5781 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5782);
													mem_vec_5782 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5783);
													mem_vec_5783 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5768);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5769);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5770);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5771);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5772);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5773);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5774);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5775);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5776);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5777);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5778);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5779);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5780);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5781);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5782);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5783);
									}
								}
							}
						}
					}
				}
				for (y = y380 + 4, yp_0 = 0;
					y < y380 + 4 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 64
					// T (x, 14) (14 / 1)
					for (x570 = x571, x570_p_0 = 0;
						x570 < x571 + 14;
						x570 += 1, x570_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 64
						// T (f, 2) (64 / 32)
						for (f = f760, fp_2 = f760_p_1, fp_1 = f760_p_0, fp_0 = 0;
							f < f760 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h306, hp_0 = 0;
								h < h306 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w320, wp_0 = 0;
									w < w320 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x570, xp_1 = x570_p_0, xp_0 = 0;
										x < x570 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5784 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5785 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_5786 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5787 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_5788 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5789 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_5790 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5791 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_5792 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5793 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_5794 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5795 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_5796 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5797 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_5798 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5799 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_5800 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5801 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_5802 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5803 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c570, cp_1 = c570_p_0, cp_0 = 0;
													c < c570 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5784);
													mem_vec_5784 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5785);
													mem_vec_5785 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5786);
													mem_vec_5786 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5787);
													mem_vec_5787 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5788);
													mem_vec_5788 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5789);
													mem_vec_5789 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5790);
													mem_vec_5790 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5791);
													mem_vec_5791 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5792);
													mem_vec_5792 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5793);
													mem_vec_5793 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5794);
													mem_vec_5794 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5795);
													mem_vec_5795 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5796);
													mem_vec_5796 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5797);
													mem_vec_5797 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5798);
													mem_vec_5798 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5799);
													mem_vec_5799 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5800);
													mem_vec_5800 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5801);
													mem_vec_5801 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5802);
													mem_vec_5802 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5803);
													mem_vec_5803 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5784);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5785);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5786);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5787);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5788);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5789);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5790);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5791);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5792);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5793);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5794);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5795);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5796);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5797);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5798);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5799);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5800);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5801);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5802);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5803);
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