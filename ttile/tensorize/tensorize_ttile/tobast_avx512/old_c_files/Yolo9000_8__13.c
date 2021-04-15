#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (4, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); T (1, f); T (2, x); T (17, y); T (2, f); T (32, c); T (1, x);
  T (2, f)]
*/
IND_TYPE c, c0, cp_0, c0_p_0, cp_1, f, f0, fp_0, f0_p_0, f1_p_0, f1, fp_1, f0_p_1, fp_2, h, hp_0, w, wp_0, x, x0, xp_0, x0_p_0, x1_p_0, x1, xp_1, x0_p_1, xp_2, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y0 = 0;
IND_TYPE x2 = 0;
IND_TYPE h0 = 0;
IND_TYPE w0 = 0;
IND_TYPE c1 = 0;
IND_TYPE f2 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_0 ,mem_vec_1 ,mem_vec_10 ,mem_vec_11 ,mem_vec_12 ,mem_vec_13 ,mem_vec_14 ,mem_vec_15 ,mem_vec_2 ,mem_vec_3 ,mem_vec_4 ,mem_vec_5 ,mem_vec_6 ,mem_vec_7 ,mem_vec_8 ,mem_vec_9 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f1 = f2, f1_p_0 = 0;
	f1 < f2 + 256;
	f1 += 128, f1_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (x, 1) (68 / 68)
	for (x1 = x2, x1_p_0 = 0;
		x1 < x2 + 68;
		x1 += 68, x1_p_0 += 68){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
		// T (c, 32) (128 / 4)
		for (c0 = c1, c0_p_0 = 0;
			c0 < c1 + 128;
			c0 += 4, c0_p_0 += 4){
			// y = 68, x = 68, h = 3, w = 3, c = 4, f = 128
			// T (f, 2) (128 / 64)
			for (f0 = f1, f0_p_1 = f1_p_0, f0_p_0 = 0;
				f0 < f1 + 128;
				f0 += 64, f0_p_1 += 64, f0_p_0 += 64){
				// y = 68, x = 68, h = 3, w = 3, c = 4, f = 64
				// T (y, 17) (68 / 4)
				for (y = y0, yp_0 = 0;
					y < y0 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 68, h = 3, w = 3, c = 4, f = 64
					// T (x, 2) (68 / 34)
					for (x0 = x1, x0_p_1 = x1_p_0, x0_p_0 = 0;
						x0 < x1 + 68;
						x0 += 34, x0_p_1 += 34, x0_p_0 += 34){
						// y = 4, x = 34, h = 3, w = 3, c = 4, f = 64
						// T (f, 1) (64 / 64)
						for (f = f0, fp_2 = f0_p_1, fp_1 = f0_p_0, fp_0 = 0;
							f < f0 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = 4, x = 34, h = 3, w = 3, c = 4, f = 64
							// T (h, 3) (3 / 1)
							for (h = h0, hp_0 = 0;
								h < h0 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 34, h = 1, w = 3, c = 4, f = 64
								// T (w, 3) (3 / 1)
								for (w = w0, wp_0 = 0;
									w < w0 + 3;
									w += 1, wp_0 += 1){
									// y = 4, x = 34, h = 1, w = 1, c = 4, f = 64
									// T (x, 34) (34 / 1)
									for (x = x0, xp_2 = x0_p_1, xp_1 = x0_p_0, xp_0 = 0;
										x < x0 + 34;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_0 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_3 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_4 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_7 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_8 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_11 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_12 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_13 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_14 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_15 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												// y = 4, x = 1, h = 1, w = 1, c = 4, f = 64
												// T (c, 4) (4 / 1)
												for (c = c0, cp_1 = c0_p_0, cp_0 = 0;
													c < c0 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_0);
													mem_vec_0 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1);
													mem_vec_1 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2);
													mem_vec_2 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3);
													mem_vec_3 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4);
													mem_vec_4 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5);
													mem_vec_5 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6);
													mem_vec_6 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7);
													mem_vec_7 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8);
													mem_vec_8 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9);
													mem_vec_9 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10);
													mem_vec_10 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11);
													mem_vec_11 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_12);
													mem_vec_12 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13);
													mem_vec_13 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14);
													mem_vec_14 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_15);
													mem_vec_15 = vec_23;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_0);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_15);
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


}