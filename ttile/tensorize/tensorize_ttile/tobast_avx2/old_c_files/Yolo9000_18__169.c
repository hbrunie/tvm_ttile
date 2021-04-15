#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (512, c); Hoist_vars [c]; T (17, x); T (3, w);
  T (3, h); T (1, f); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (32, f);
  T (1, c); T (1, f)]
*/
IND_TYPE c, c0, cp_0, c0_p_0, cp_1, f, f0, fp_0, f0_p_0, f1_p_0, f1, fp_1, f0_p_1, fp_2, h, hp_0, w, wp_0, x, x0, xp_0, x0_p_0, xp_1, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y0 = 0;
IND_TYPE x1 = 0;
IND_TYPE h0 = 0;
IND_TYPE w0 = 0;
IND_TYPE c1 = 0;
IND_TYPE f2 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_0 ,mem_vec_1 ,mem_vec_10 ,mem_vec_11 ,mem_vec_12 ,mem_vec_13 ,mem_vec_14 ,mem_vec_15 ,mem_vec_16 ,mem_vec_17 ,mem_vec_18 ,mem_vec_19 ,mem_vec_2 ,mem_vec_20 ,mem_vec_21 ,mem_vec_22 ,mem_vec_23 ,mem_vec_24 ,mem_vec_25 ,mem_vec_26 ,mem_vec_27 ,mem_vec_28 ,mem_vec_29 ,mem_vec_3 ,mem_vec_30 ,mem_vec_31 ,mem_vec_32 ,mem_vec_33 ,mem_vec_34 ,mem_vec_35 ,mem_vec_4 ,mem_vec_5 ,mem_vec_6 ,mem_vec_7 ,mem_vec_8 ,mem_vec_9 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 1) (1024 / 1024)
for (f1 = f2, f1_p_0 = 0;
	f1 < f2 + 1024;
	f1 += 1024, f1_p_0 += 1024){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 1) (512 / 512)
	for (c0 = c1, c0_p_0 = 0;
		c0 < c1 + 512;
		c0 += 512, c0_p_0 += 512){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
		// T (f, 32) (1024 / 32)
		for (f0 = f1, f0_p_1 = f1_p_0, f0_p_0 = 0;
			f0 < f1 + 1024;
			f0 += 32, f0_p_1 += 32, f0_p_0 += 32){
				for (y = y0, yp_0 = 0;
					y < y0 + 12;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 32
					// T (x, 1) (17 / 17)
					for (x0 = x1, x0_p_0 = 0;
						x0 < x1 + 17;
						x0 += 17, x0_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 32
						// T (f, 1) (32 / 32)
						for (f = f0, fp_2 = f0_p_1, fp_1 = f0_p_0, fp_0 = 0;
							f < f0 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 32
							// T (h, 3) (3 / 1)
							for (h = h0, hp_0 = 0;
								h < h0 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 512, f = 32
								// T (w, 3) (3 / 1)
								for (w = w0, wp_0 = 0;
									w < w0 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
									// T (x, 17) (17 / 1)
									for (x = x0, xp_1 = x0_p_0, xp_0 = 0;
										x < x0 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_0 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_2 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_4 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_6 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_7 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_8 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_10 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_12 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_13 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_14 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_15 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
												// T (c, 512) (512 / 1)
												for (c = c0, cp_1 = c0_p_0, cp_0 = 0;
													c < c0 + 512;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_0);
													mem_vec_0 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1);
													mem_vec_1 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2);
													mem_vec_2 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3);
													mem_vec_3 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4);
													mem_vec_4 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5);
													mem_vec_5 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6);
													mem_vec_6 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7);
													mem_vec_7 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8);
													mem_vec_8 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9);
													mem_vec_9 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10);
													mem_vec_10 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11);
													mem_vec_11 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12);
													mem_vec_12 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13);
													mem_vec_13 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14);
													mem_vec_14 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_15);
													mem_vec_15 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_0);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_15);
									}
								}
							}
						}
					}
				}
				for (y = y0 + 12, yp_0 = 0;
					y < y0 + 12 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 32
					// T (x, 1) (17 / 17)
					for (x0 = x1, x0_p_0 = 0;
						x0 < x1 + 17;
						x0 += 17, x0_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 32
						// T (f, 1) (32 / 32)
						for (f = f0, fp_2 = f0_p_1, fp_1 = f0_p_0, fp_0 = 0;
							f < f0 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 32
							// T (h, 3) (3 / 1)
							for (h = h0, hp_0 = 0;
								h < h0 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 512, f = 32
								// T (w, 3) (3 / 1)
								for (w = w0, wp_0 = 0;
									w < w0 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
									// T (x, 17) (17 / 1)
									for (x = x0, xp_1 = x0_p_0, xp_0 = 0;
										x < x0 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_16 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_17 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_18 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_19 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_20 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_21 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_22 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_23 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_24 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_25 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_26 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_27 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_28 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_29 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_30 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_31 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_32 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_33 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_34 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_35 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
												// T (c, 512) (512 / 1)
												for (c = c0, cp_1 = c0_p_0, cp_0 = 0;
													c < c0 + 512;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_16);
													mem_vec_16 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_17);
													mem_vec_17 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_18);
													mem_vec_18 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_19);
													mem_vec_19 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_20);
													mem_vec_20 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_21);
													mem_vec_21 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_22);
													mem_vec_22 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_23);
													mem_vec_23 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_24);
													mem_vec_24 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_25);
													mem_vec_25 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_26);
													mem_vec_26 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_27);
													mem_vec_27 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_28);
													mem_vec_28 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_29);
													mem_vec_29 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_30);
													mem_vec_30 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_31);
													mem_vec_31 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_32);
													mem_vec_32 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_33);
													mem_vec_33 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_34);
													mem_vec_34 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_35);
													mem_vec_35 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_17);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_18);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_19);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_20);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_21);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_22);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_23);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_24);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_25);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_26);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_27);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_28);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_29);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_30);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_31);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_32);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_33);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_34);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_35);
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