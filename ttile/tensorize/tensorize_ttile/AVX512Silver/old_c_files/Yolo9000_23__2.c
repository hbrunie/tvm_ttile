#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (31, f);
  T (1, x); T (1, y); T (16, c); T (57, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (1, f)]
*/
IND_TYPE c, cp_0, c213_p_0, cp_1, c213, f, fp_0, f284_p_0, f285_p_0, fp_1, f284_p_1, fp_2, f284, f285, x, xp_0, x284_p_0, x285_p_0, xp_1, x284_p_1, xp_2, x284, x285, y, yp_0, y213_p_0, yp_1, y213;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 28272));
IND_TYPE y214 = 0;
IND_TYPE x286 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c214 = 0;
IND_TYPE f286 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_1207 ,mem_vec_1208 ,mem_vec_1209 ,mem_vec_1210 ,mem_vec_1211 ,mem_vec_1212 ,mem_vec_1213 ,mem_vec_1214 ,mem_vec_1215 ,mem_vec_1216 ,mem_vec_1217 ,mem_vec_1218 ,mem_vec_1219 ,mem_vec_1220 ,mem_vec_1221 ,mem_vec_1222 ,mem_vec_1223 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_2 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
// T (f, 1) (28272 / 28272)
for (f285 = f286, f285_p_0 = 0;
	f285 < f286 + 28272;
	f285 += 28272, f285_p_0 += 28272){
		for (y213 = y214, y213_p_0 = 0;
			y213 < y214 + 8;
			y213 += 8, y213_p_0 += 8){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 28272
			// T (x, 1) (17 / 17)
			for (x285 = x286, x285_p_0 = 0;
				x285 < x286 + 17;
				x285 += 17, x285_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 28272
				// T (f, 57) (28272 / 496)
				for (f284 = f285, f284_p_1 = f285_p_0, f284_p_0 = 0;
					f284 < f285 + 28272;
					f284 += 496, f284_p_1 += 496, f284_p_0 += 496){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 496
					// T (c, 16) (1024 / 64)
					for (c213 = c214, c213_p_0 = 0;
						c213 < c214 + 1024;
						c213 += 64, c213_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 496
						// T (y, 1) (ph_y / ph_y)
						for (y = y213, yp_1 = y213_p_0, yp_0 = 0;
							y < y213 + 8;
							y += 8, yp_1 += 8, yp_0 += 8){
							// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 496
							// T (x, 1) (17 / 17)
							for (x284 = x285, x284_p_1 = x285_p_0, x284_p_0 = 0;
								x284 < x285 + 17;
								x284 += 17, x284_p_1 += 17, x284_p_0 += 17){
								// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 496
								// T (f, 31) (496 / 16)
								for (f = f284, fp_2 = f284_p_1, fp_1 = f284_p_0, fp_0 = 0;
									f < f284 + 496;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 16
									// T (x, 17) (17 / 1)
									for (x = x284, xp_2 = x284_p_1, xp_1 = x284_p_0, xp_0 = 0;
										x < x284 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1207 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 16
												// T (c, 64) (64 / 1)
												for (c = c213, cp_1 = c213_p_0, cp_0 = 0;
													c < c213 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1207);
													mem_vec_1207 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1208);
													mem_vec_1208 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1209);
													mem_vec_1209 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1210);
													mem_vec_1210 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1211);
													mem_vec_1211 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1212);
													mem_vec_1212 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_1213);
													mem_vec_1213 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_1214);
													mem_vec_1214 = vec_15;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1207);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1208);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1209);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1210);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1211);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1212);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1213);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1214);
									}
								}
							}
						}
					}
				}
			}
		}
		for (y213 = y214 + 8, y213_p_0 = 0;
			y213 < y214 + 8 + 9;
			y213 += 9, y213_p_0 += 9){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 28272
			// T (x, 1) (17 / 17)
			for (x285 = x286, x285_p_0 = 0;
				x285 < x286 + 17;
				x285 += 17, x285_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 28272
				// T (f, 57) (28272 / 496)
				for (f284 = f285, f284_p_1 = f285_p_0, f284_p_0 = 0;
					f284 < f285 + 28272;
					f284 += 496, f284_p_1 += 496, f284_p_0 += 496){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 496
					// T (c, 16) (1024 / 64)
					for (c213 = c214, c213_p_0 = 0;
						c213 < c214 + 1024;
						c213 += 64, c213_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 496
						// T (y, 1) (ph_y / ph_y)
						for (y = y213, yp_1 = y213_p_0, yp_0 = 0;
							y < y213 + 9;
							y += 9, yp_1 += 9, yp_0 += 9){
							// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 496
							// T (x, 1) (17 / 17)
							for (x284 = x285, x284_p_1 = x285_p_0, x284_p_0 = 0;
								x284 < x285 + 17;
								x284 += 17, x284_p_1 += 17, x284_p_0 += 17){
								// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 496
								// T (f, 31) (496 / 16)
								for (f = f284, fp_2 = f284_p_1, fp_1 = f284_p_0, fp_0 = 0;
									f < f284 + 496;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 16
									// T (x, 17) (17 / 1)
									for (x = x284, xp_2 = x284_p_1, xp_1 = x284_p_0, xp_0 = 0;
										x < x284 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1215 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 16
												// T (c, 64) (64 / 1)
												for (c = c213, cp_1 = c213_p_0, cp_0 = 0;
													c < c213 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1215);
													mem_vec_1215 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1216);
													mem_vec_1216 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1217);
													mem_vec_1217 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1218);
													mem_vec_1218 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1219);
													mem_vec_1219 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1220);
													mem_vec_1220 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_1221);
													mem_vec_1221 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_1222);
													mem_vec_1222 = vec_15;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_18 = _mm512_set1_ps(scal_8);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1223);
													mem_vec_1223 = vec_17;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1215);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1216);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1217);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1218);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1219);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1220);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1221);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1222);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1223);
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