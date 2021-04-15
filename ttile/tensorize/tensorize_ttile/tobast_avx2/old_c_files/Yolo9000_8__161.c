#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (2, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (2, f); T (17, x); T (17, y); T (4, f); T (64, c); T (1, x);
  T (1, f)]
*/
IND_TYPE c, cp_0, c24_p_0, cp_1, c24, f, fp_0, f32_p_0, f33_p_0, fp_1, f32_p_1, fp_2, f32, f33, h, hp_0, w, wp_0, x, xp_0, x32_p_0, x33_p_0, xp_1, x32_p_1, xp_2, x32, x33, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y16 = 0;
IND_TYPE x34 = 0;
IND_TYPE h16 = 0;
IND_TYPE w16 = 0;
IND_TYPE c25 = 0;
IND_TYPE f34 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_128 ,mem_vec_129 ,mem_vec_130 ,mem_vec_131 ,mem_vec_132 ,mem_vec_133 ,mem_vec_134 ,mem_vec_135 ,mem_vec_136 ,mem_vec_137 ,mem_vec_138 ,mem_vec_139 ,mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f33 = f34, f33_p_0 = 0;
	f33 < f34 + 256;
	f33 += 256, f33_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (x, 1) (68 / 68)
	for (x33 = x34, x33_p_0 = 0;
		x33 < x34 + 68;
		x33 += 68, x33_p_0 += 68){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
		// T (c, 64) (128 / 2)
		for (c24 = c25, c24_p_0 = 0;
			c24 < c25 + 128;
			c24 += 2, c24_p_0 += 2){
			// y = 68, x = 68, h = 3, w = 3, c = 2, f = 256
			// T (f, 4) (256 / 64)
			for (f32 = f33, f32_p_1 = f33_p_0, f32_p_0 = 0;
				f32 < f33 + 256;
				f32 += 64, f32_p_1 += 64, f32_p_0 += 64){
				// y = 68, x = 68, h = 3, w = 3, c = 2, f = 64
				// T (y, 17) (68 / 4)
				for (y = y16, yp_0 = 0;
					y < y16 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 68, h = 3, w = 3, c = 2, f = 64
					// T (x, 17) (68 / 4)
					for (x32 = x33, x32_p_1 = x33_p_0, x32_p_0 = 0;
						x32 < x33 + 68;
						x32 += 4, x32_p_1 += 4, x32_p_0 += 4){
						// y = 4, x = 4, h = 3, w = 3, c = 2, f = 64
						// T (f, 2) (64 / 32)
						for (f = f32, fp_2 = f32_p_1, fp_1 = f32_p_0, fp_0 = 0;
							f < f32 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = 4, x = 4, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h16, hp_0 = 0;
								h < h16 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 4, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w16, wp_0 = 0;
									w < w16 + 3;
									w += 1, wp_0 += 1){
									// y = 4, x = 4, h = 1, w = 1, c = 2, f = 32
									// T (x, 4) (4 / 1)
									for (x = x32, xp_2 = x32_p_1, xp_1 = x32_p_0, xp_0 = 0;
										x < x32 + 4;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_128 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_129 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_130 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_131 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_132 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_133 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_134 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_135 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_136 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_137 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_138 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_139 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_140 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_141 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_142 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_143 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = 4, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c24, cp_1 = c24_p_0, cp_0 = 0;
													c < c24 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_128);
													mem_vec_128 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_129);
													mem_vec_129 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_130);
													mem_vec_130 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_131);
													mem_vec_131 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_132);
													mem_vec_132 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_133);
													mem_vec_133 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_134);
													mem_vec_134 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_135);
													mem_vec_135 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_136);
													mem_vec_136 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_137);
													mem_vec_137 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_138);
													mem_vec_138 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_139);
													mem_vec_139 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_140);
													mem_vec_140 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_141);
													mem_vec_141 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_142);
													mem_vec_142 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_143);
													mem_vec_143 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_128);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_129);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_130);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_131);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_132);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_133);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_134);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_135);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_136);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_137);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_138);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_139);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_140);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_141);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_142);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_143);
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