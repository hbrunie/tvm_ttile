#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (57, f);
  T (1, x); T (1, y); T (16, c); T (1, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (31, f)]
*/
IND_TYPE c, cp_0, c234_p_0, cp_1, c234, f, fp_0, f312_p_0, f313_p_0, fp_1, f312_p_1, fp_2, f312, f313, x, xp_0, x312_p_0, x313_p_0, xp_1, x312_p_1, xp_2, x312, x313, y, yp_0, y234_p_0, yp_1, y234;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 28272));
IND_TYPE y235 = 0;
IND_TYPE x314 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c235 = 0;
IND_TYPE f314 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_1326 ,mem_vec_1327 ,mem_vec_1328 ,mem_vec_1329 ,mem_vec_1330 ,mem_vec_1331 ,mem_vec_1332 ,mem_vec_1333 ,mem_vec_1334 ,mem_vec_1335 ,mem_vec_1336 ,mem_vec_1337 ,mem_vec_1338 ,mem_vec_1339 ,mem_vec_1340 ,mem_vec_1341 ,mem_vec_1342 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_2 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
// T (f, 31) (28272 / 912)
for (f313 = f314, f313_p_0 = 0;
	f313 < f314 + 28272;
	f313 += 912, f313_p_0 += 912){
		for (y234 = y235, y234_p_0 = 0;
			y234 < y235 + 8;
			y234 += 8, y234_p_0 += 8){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 912
			// T (x, 1) (17 / 17)
			for (x313 = x314, x313_p_0 = 0;
				x313 < x314 + 17;
				x313 += 17, x313_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 912
				// T (f, 1) (912 / 912)
				for (f312 = f313, f312_p_1 = f313_p_0, f312_p_0 = 0;
					f312 < f313 + 912;
					f312 += 912, f312_p_1 += 912, f312_p_0 += 912){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 912
					// T (c, 16) (1024 / 64)
					for (c234 = c235, c234_p_0 = 0;
						c234 < c235 + 1024;
						c234 += 64, c234_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 912
						// T (y, 1) (ph_y / ph_y)
						for (y = y234, yp_1 = y234_p_0, yp_0 = 0;
							y < y234 + 8;
							y += 8, yp_1 += 8, yp_0 += 8){
							// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 912
							// T (x, 1) (17 / 17)
							for (x312 = x313, x312_p_1 = x313_p_0, x312_p_0 = 0;
								x312 < x313 + 17;
								x312 += 17, x312_p_1 += 17, x312_p_0 += 17){
								// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 912
								// T (f, 57) (912 / 16)
								for (f = f312, fp_2 = f312_p_1, fp_1 = f312_p_0, fp_0 = 0;
									f < f312 + 912;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 16
									// T (x, 17) (17 / 1)
									for (x = x312, xp_2 = x312_p_1, xp_1 = x312_p_0, xp_0 = 0;
										x < x312 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1326 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 16
												// T (c, 64) (64 / 1)
												for (c = c234, cp_1 = c234_p_0, cp_0 = 0;
													c < c234 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1326);
													mem_vec_1326 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1327);
													mem_vec_1327 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1328);
													mem_vec_1328 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1329);
													mem_vec_1329 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1330);
													mem_vec_1330 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1331);
													mem_vec_1331 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_1332);
													mem_vec_1332 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_1333);
													mem_vec_1333 = vec_15;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1326);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1327);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1328);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1329);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1330);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1331);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1332);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1333);
									}
								}
							}
						}
					}
				}
			}
		}
		for (y234 = y235 + 8, y234_p_0 = 0;
			y234 < y235 + 8 + 9;
			y234 += 9, y234_p_0 += 9){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 912
			// T (x, 1) (17 / 17)
			for (x313 = x314, x313_p_0 = 0;
				x313 < x314 + 17;
				x313 += 17, x313_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 912
				// T (f, 1) (912 / 912)
				for (f312 = f313, f312_p_1 = f313_p_0, f312_p_0 = 0;
					f312 < f313 + 912;
					f312 += 912, f312_p_1 += 912, f312_p_0 += 912){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 912
					// T (c, 16) (1024 / 64)
					for (c234 = c235, c234_p_0 = 0;
						c234 < c235 + 1024;
						c234 += 64, c234_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 912
						// T (y, 1) (ph_y / ph_y)
						for (y = y234, yp_1 = y234_p_0, yp_0 = 0;
							y < y234 + 9;
							y += 9, yp_1 += 9, yp_0 += 9){
							// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 912
							// T (x, 1) (17 / 17)
							for (x312 = x313, x312_p_1 = x313_p_0, x312_p_0 = 0;
								x312 < x313 + 17;
								x312 += 17, x312_p_1 += 17, x312_p_0 += 17){
								// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 912
								// T (f, 57) (912 / 16)
								for (f = f312, fp_2 = f312_p_1, fp_1 = f312_p_0, fp_0 = 0;
									f < f312 + 912;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 16
									// T (x, 17) (17 / 1)
									for (x = x312, xp_2 = x312_p_1, xp_1 = x312_p_0, xp_0 = 0;
										x < x312 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1334 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 16
												// T (c, 64) (64 / 1)
												for (c = c234, cp_1 = c234_p_0, cp_0 = 0;
													c < c234 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1334);
													mem_vec_1334 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1335);
													mem_vec_1335 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1336);
													mem_vec_1336 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1337);
													mem_vec_1337 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1338);
													mem_vec_1338 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1339);
													mem_vec_1339 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_1340);
													mem_vec_1340 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_1341);
													mem_vec_1341 = vec_15;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_18 = _mm512_set1_ps(scal_8);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1342);
													mem_vec_1342 = vec_17;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1334);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1335);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1336);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1337);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1338);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1339);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1340);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1341);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1342);
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