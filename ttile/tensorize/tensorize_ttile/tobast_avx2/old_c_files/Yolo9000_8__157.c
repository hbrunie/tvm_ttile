#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (128, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (8, f); T (1, x); T (17, y); T (1, f); T (1, c); T (34, x);
  T (1, f)]
*/
IND_TYPE c, cp_0, c168_p_0, cp_1, c168, f, fp_0, f224_p_0, f225_p_0, fp_1, f224_p_1, fp_2, f224, f225, h, hp_0, w, wp_0, x, xp_0, x224_p_0, x225_p_0, xp_1, x224_p_1, xp_2, x224, x225, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y112 = 0;
IND_TYPE x226 = 0;
IND_TYPE h112 = 0;
IND_TYPE w112 = 0;
IND_TYPE c169 = 0;
IND_TYPE f226 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,mem_vec_904 ,mem_vec_905 ,mem_vec_906 ,mem_vec_907 ,mem_vec_908 ,mem_vec_909 ,mem_vec_910 ,mem_vec_911 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f225 = f226, f225_p_0 = 0;
	f225 < f226 + 256;
	f225 += 256, f225_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (x, 34) (68 / 2)
	for (x225 = x226, x225_p_0 = 0;
		x225 < x226 + 68;
		x225 += 2, x225_p_0 += 2){
		// y = 68, x = 2, h = 3, w = 3, c = 128, f = 256
		// T (c, 1) (128 / 128)
		for (c168 = c169, c168_p_0 = 0;
			c168 < c169 + 128;
			c168 += 128, c168_p_0 += 128){
			// y = 68, x = 2, h = 3, w = 3, c = 128, f = 256
			// T (f, 1) (256 / 256)
			for (f224 = f225, f224_p_1 = f225_p_0, f224_p_0 = 0;
				f224 < f225 + 256;
				f224 += 256, f224_p_1 += 256, f224_p_0 += 256){
				// y = 68, x = 2, h = 3, w = 3, c = 128, f = 256
				// T (y, 17) (68 / 4)
				for (y = y112, yp_0 = 0;
					y < y112 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 2, h = 3, w = 3, c = 128, f = 256
					// T (x, 1) (2 / 2)
					for (x224 = x225, x224_p_1 = x225_p_0, x224_p_0 = 0;
						x224 < x225 + 2;
						x224 += 2, x224_p_1 += 2, x224_p_0 += 2){
						// y = 4, x = 2, h = 3, w = 3, c = 128, f = 256
						// T (f, 8) (256 / 32)
						for (f = f224, fp_2 = f224_p_1, fp_1 = f224_p_0, fp_0 = 0;
							f < f224 + 256;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = 4, x = 2, h = 3, w = 3, c = 128, f = 32
							// T (h, 3) (3 / 1)
							for (h = h112, hp_0 = 0;
								h < h112 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 2, h = 1, w = 3, c = 128, f = 32
								// T (w, 3) (3 / 1)
								for (w = w112, wp_0 = 0;
									w < w112 + 3;
									w += 1, wp_0 += 1){
									// y = 4, x = 2, h = 1, w = 1, c = 128, f = 32
									// T (x, 2) (2 / 1)
									for (x = x224, xp_2 = x224_p_1, xp_1 = x224_p_0, xp_0 = 0;
										x < x224 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_896 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_897 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_898 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_899 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_900 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_901 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_902 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_903 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_904 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_905 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_906 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_907 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_908 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_909 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_910 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_911 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c168, cp_1 = c168_p_0, cp_0 = 0;
													c < c168 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_896);
													mem_vec_896 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_897);
													mem_vec_897 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_898);
													mem_vec_898 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_899);
													mem_vec_899 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_900);
													mem_vec_900 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_901);
													mem_vec_901 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_902);
													mem_vec_902 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_903);
													mem_vec_903 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_904);
													mem_vec_904 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_905);
													mem_vec_905 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_906);
													mem_vec_906 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_907);
													mem_vec_907 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_908);
													mem_vec_908 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_909);
													mem_vec_909 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_910);
													mem_vec_910 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_911);
													mem_vec_911 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_896);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_897);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_898);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_899);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_900);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_901);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_902);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_903);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_904);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_905);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_906);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_907);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_908);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_909);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_910);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_911);
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