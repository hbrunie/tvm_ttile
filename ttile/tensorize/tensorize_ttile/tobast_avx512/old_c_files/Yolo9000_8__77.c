#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (1, f); T (17, x); T (17, y); T (4, f); T (4, c); T (4, x);
  T (1, f)]
*/
IND_TYPE c, cp_0, c30_p_0, cp_1, c30, f, fp_0, f40_p_0, f41_p_0, fp_1, f40_p_1, fp_2, f40, f41, h, hp_0, w, wp_0, x, xp_0, x40_p_0, x41_p_0, xp_1, x40_p_1, xp_2, x40, x41, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y20 = 0;
IND_TYPE x42 = 0;
IND_TYPE h20 = 0;
IND_TYPE w20 = 0;
IND_TYPE c31 = 0;
IND_TYPE f42 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_160 ,mem_vec_161 ,mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,mem_vec_168 ,mem_vec_169 ,mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f41 = f42, f41_p_0 = 0;
	f41 < f42 + 256;
	f41 += 256, f41_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (x, 4) (68 / 17)
	for (x41 = x42, x41_p_0 = 0;
		x41 < x42 + 68;
		x41 += 17, x41_p_0 += 17){
		// y = 68, x = 17, h = 3, w = 3, c = 128, f = 256
		// T (c, 4) (128 / 32)
		for (c30 = c31, c30_p_0 = 0;
			c30 < c31 + 128;
			c30 += 32, c30_p_0 += 32){
			// y = 68, x = 17, h = 3, w = 3, c = 32, f = 256
			// T (f, 4) (256 / 64)
			for (f40 = f41, f40_p_1 = f41_p_0, f40_p_0 = 0;
				f40 < f41 + 256;
				f40 += 64, f40_p_1 += 64, f40_p_0 += 64){
				// y = 68, x = 17, h = 3, w = 3, c = 32, f = 64
				// T (y, 17) (68 / 4)
				for (y = y20, yp_0 = 0;
					y < y20 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 17, h = 3, w = 3, c = 32, f = 64
					// T (x, 17) (17 / 1)
					for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
						x40 < x41 + 17;
						x40 += 1, x40_p_1 += 1, x40_p_0 += 1){
						// y = 4, x = 1, h = 3, w = 3, c = 32, f = 64
						// T (f, 1) (64 / 64)
						for (f = f40, fp_2 = f40_p_1, fp_1 = f40_p_0, fp_0 = 0;
							f < f40 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = 4, x = 1, h = 3, w = 3, c = 32, f = 64
							// T (h, 3) (3 / 1)
							for (h = h20, hp_0 = 0;
								h < h20 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 32, f = 64
								// T (w, 3) (3 / 1)
								for (w = w20, wp_0 = 0;
									w < w20 + 3;
									w += 1, wp_0 += 1){
									// y = 4, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (x, 1) (1 / 1)
									for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
										x < x40 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_160 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_161 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_162 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_163 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												// y = 4, x = 1, h = 1, w = 1, c = 32, f = 64
												// T (c, 32) (32 / 1)
												for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
													c < c30 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_160);
													mem_vec_160 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_161);
													mem_vec_161 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_162);
													mem_vec_162 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_163);
													mem_vec_163 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_164);
													mem_vec_164 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_165);
													mem_vec_165 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_166);
													mem_vec_166 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_167);
													mem_vec_167 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_168);
													mem_vec_168 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_169);
													mem_vec_169 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_170);
													mem_vec_170 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_171);
													mem_vec_171 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_172);
													mem_vec_172 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_173);
													mem_vec_173 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_174);
													mem_vec_174 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_175);
													mem_vec_175 = vec_23;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_160);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_161);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_162);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_163);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_164);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_165);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_166);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_167);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_168);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_169);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_170);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_171);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_172);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_173);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_174);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_175);
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