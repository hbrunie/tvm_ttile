#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; T (128, c); Hoist_vars [c]; T (17, x); T (57, f);
  T (1, x); Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))];
  T (8, c); T (31, f); T (1, x); T (1, y); T (1, f)]
*/
IND_TYPE c, cp_0, c30_p_0, cp_1, c30, f, fp_0, f40_p_0, f41_p_0, fp_1, f40_p_1, fp_2, f40, f41, x, xp_0, x40_p_0, x41_p_0, xp_1, x40_p_1, xp_2, x40, x41, y, yp_0, y30_p_0, yp_1, y30;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 28272));
IND_TYPE y31 = 0;
IND_TYPE x42 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c31 = 0;
IND_TYPE f42 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,mem_vec_176 ,mem_vec_177 ,mem_vec_178 ,mem_vec_179 ,mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,mem_vec_184 ,mem_vec_185 ,mem_vec_186 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_2 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
// T (f, 1) (28272 / 28272)
for (f41 = f42, f41_p_0 = 0;
	f41 < f42 + 28272;
	f41 += 28272, f41_p_0 += 28272){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
	// T (y, 1) (17 / 17)
	for (y30 = y31, y30_p_0 = 0;
		y30 < y31 + 17;
		y30 += 17, y30_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
		// T (x, 1) (17 / 17)
		for (x41 = x42, x41_p_0 = 0;
			x41 < x42 + 17;
			x41 += 17, x41_p_0 += 17){
			// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
			// T (f, 31) (28272 / 912)
			for (f40 = f41, f40_p_1 = f41_p_0, f40_p_0 = 0;
				f40 < f41 + 28272;
				f40 += 912, f40_p_1 += 912, f40_p_0 += 912){
				// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 912
				// T (c, 8) (1024 / 128)
				for (c30 = c31, c30_p_0 = 0;
					c30 < c31 + 1024;
					c30 += 128, c30_p_0 += 128){
						for (y = y30, yp_1 = y30_p_0, yp_0 = 0;
							y < y30 + 8;
							y += 8, yp_1 += 8, yp_0 += 8){
							// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 912
							// T (x, 1) (17 / 17)
							for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
								x40 < x41 + 17;
								x40 += 17, x40_p_1 += 17, x40_p_0 += 17){
								// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 912
								// T (f, 57) (912 / 16)
								for (f = f40, fp_2 = f40_p_1, fp_1 = f40_p_0, fp_0 = 0;
									f < f40 + 912;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 16
									// T (x, 17) (17 / 1)
									for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
										x < x40 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_170 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 16
												// T (c, 128) (128 / 1)
												for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
													c < c30 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_170);
													mem_vec_170 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_171);
													mem_vec_171 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_172);
													mem_vec_172 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_173);
													mem_vec_173 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_174);
													mem_vec_174 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_175);
													mem_vec_175 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_176);
													mem_vec_176 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_177);
													mem_vec_177 = vec_15;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_170);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_171);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_172);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_173);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_174);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_175);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_176);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_177);
									}
								}
							}
						}
						for (y = y30 + 8, yp_1 = y30_p_0, yp_0 = 0;
							y < y30 + 8 + 9;
							y += 9, yp_1 += 9, yp_0 += 9){
							// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 912
							// T (x, 1) (17 / 17)
							for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
								x40 < x41 + 17;
								x40 += 17, x40_p_1 += 17, x40_p_0 += 17){
								// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 912
								// T (f, 57) (912 / 16)
								for (f = f40, fp_2 = f40_p_1, fp_1 = f40_p_0, fp_0 = 0;
									f < f40 + 912;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 16
									// T (x, 17) (17 / 1)
									for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
										x < x40 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_178 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 16
												// T (c, 128) (128 / 1)
												for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
													c < c30 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_178);
													mem_vec_178 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_179);
													mem_vec_179 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_180);
													mem_vec_180 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_181);
													mem_vec_181 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_182);
													mem_vec_182 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_183);
													mem_vec_183 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_184);
													mem_vec_184 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_185);
													mem_vec_185 = vec_15;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_18 = _mm512_set1_ps(scal_8);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_186);
													mem_vec_186 = vec_17;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_178);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_179);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_180);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_181);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_182);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_183);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_184);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_185);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_186);
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