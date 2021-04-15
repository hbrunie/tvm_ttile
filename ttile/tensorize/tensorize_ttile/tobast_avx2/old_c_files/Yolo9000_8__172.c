#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (2, f); T (1, x); T (17, y); T (4, f); T (8, c); T (34, x);
  T (1, f)]
*/
IND_TYPE c, cp_0, c180_p_0, cp_1, c180, f, fp_0, f240_p_0, f241_p_0, fp_1, f240_p_1, fp_2, f240, f241, h, hp_0, w, wp_0, x, xp_0, x240_p_0, x241_p_0, xp_1, x240_p_1, xp_2, x240, x241, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y120 = 0;
IND_TYPE x242 = 0;
IND_TYPE h120 = 0;
IND_TYPE w120 = 0;
IND_TYPE c181 = 0;
IND_TYPE f242 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_960 ,mem_vec_961 ,mem_vec_962 ,mem_vec_963 ,mem_vec_964 ,mem_vec_965 ,mem_vec_966 ,mem_vec_967 ,mem_vec_968 ,mem_vec_969 ,mem_vec_970 ,mem_vec_971 ,mem_vec_972 ,mem_vec_973 ,mem_vec_974 ,mem_vec_975 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f241 = f242, f241_p_0 = 0;
	f241 < f242 + 256;
	f241 += 256, f241_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (x, 34) (68 / 2)
	for (x241 = x242, x241_p_0 = 0;
		x241 < x242 + 68;
		x241 += 2, x241_p_0 += 2){
		// y = 68, x = 2, h = 3, w = 3, c = 128, f = 256
		// T (c, 8) (128 / 16)
		for (c180 = c181, c180_p_0 = 0;
			c180 < c181 + 128;
			c180 += 16, c180_p_0 += 16){
			// y = 68, x = 2, h = 3, w = 3, c = 16, f = 256
			// T (f, 4) (256 / 64)
			for (f240 = f241, f240_p_1 = f241_p_0, f240_p_0 = 0;
				f240 < f241 + 256;
				f240 += 64, f240_p_1 += 64, f240_p_0 += 64){
				// y = 68, x = 2, h = 3, w = 3, c = 16, f = 64
				// T (y, 17) (68 / 4)
				for (y = y120, yp_0 = 0;
					y < y120 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 2, h = 3, w = 3, c = 16, f = 64
					// T (x, 1) (2 / 2)
					for (x240 = x241, x240_p_1 = x241_p_0, x240_p_0 = 0;
						x240 < x241 + 2;
						x240 += 2, x240_p_1 += 2, x240_p_0 += 2){
						// y = 4, x = 2, h = 3, w = 3, c = 16, f = 64
						// T (f, 2) (64 / 32)
						for (f = f240, fp_2 = f240_p_1, fp_1 = f240_p_0, fp_0 = 0;
							f < f240 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = 4, x = 2, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h120, hp_0 = 0;
								h < h120 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 2, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w120, wp_0 = 0;
									w < w120 + 3;
									w += 1, wp_0 += 1){
									// y = 4, x = 2, h = 1, w = 1, c = 16, f = 32
									// T (x, 2) (2 / 1)
									for (x = x240, xp_2 = x240_p_1, xp_1 = x240_p_0, xp_0 = 0;
										x < x240 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_960 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_961 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_962 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_963 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_964 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_965 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_966 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_967 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_968 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_969 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_970 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_971 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_972 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_973 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_974 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_975 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c180, cp_1 = c180_p_0, cp_0 = 0;
													c < c180 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_960);
													mem_vec_960 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_961);
													mem_vec_961 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_962);
													mem_vec_962 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_963);
													mem_vec_963 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_964);
													mem_vec_964 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_965);
													mem_vec_965 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_966);
													mem_vec_966 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_967);
													mem_vec_967 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_968);
													mem_vec_968 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_969);
													mem_vec_969 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_970);
													mem_vec_970 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_971);
													mem_vec_971 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_972);
													mem_vec_972 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_973);
													mem_vec_973 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_974);
													mem_vec_974 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_975);
													mem_vec_975 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_960);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_961);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_962);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_963);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_964);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_965);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_966);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_967);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_968);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_969);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_970);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_971);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_972);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_973);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_974);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_975);
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