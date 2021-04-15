#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (2, c); T (16, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (64, c);
  T (1, f); T (4, c)]
*/
IND_TYPE c, cp_0, c1218_p_0, c1219_p_0, c1220_p_0, cp_1, c1218_p_1, c1219_p_1, cp_2, c1218_p_2, cp_3, c1218, c1219, c1220, f, fp_0, f846_p_0, fp_1, f846, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y370 = 0;
IND_TYPE x516 = 0;
IND_TYPE h392 = 0;
IND_TYPE w396 = 0;
IND_TYPE c1221 = 0;
IND_TYPE f847 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_4340 ,mem_vec_4341 ,mem_vec_4342 ,mem_vec_4343 ,mem_vec_4344 ,mem_vec_4345 ,mem_vec_4346 ,mem_vec_4347 ,mem_vec_4348 ,mem_vec_4349 ,mem_vec_4350 ,mem_vec_4351 ,mem_vec_4352 ,mem_vec_4353 ,mem_vec_4354 ,mem_vec_4355 ,mem_vec_4356 ,mem_vec_4357 ,mem_vec_4358 ,mem_vec_4359 ,mem_vec_4360 ,mem_vec_4361 ,mem_vec_4362 ,mem_vec_4363 ,mem_vec_4364 ,mem_vec_4365 ,mem_vec_4366 ,mem_vec_4367 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 4) (1024 / 256)
for (c1220 = c1221, c1220_p_0 = 0;
	c1220 < c1221 + 1024;
	c1220 += 256, c1220_p_0 += 256){
	// y = 7, x = 7, h = 3, w = 3, c = 256, f = 1024
	// T (f, 1) (1024 / 1024)
	for (f846 = f847, f846_p_0 = 0;
		f846 < f847 + 1024;
		f846 += 1024, f846_p_0 += 1024){
		// y = 7, x = 7, h = 3, w = 3, c = 256, f = 1024
		// T (c, 64) (256 / 4)
		for (c1219 = c1220, c1219_p_1 = c1220_p_0, c1219_p_0 = 0;
			c1219 < c1220 + 256;
			c1219 += 4, c1219_p_1 += 4, c1219_p_0 += 4){
				for (y = y370, yp_0 = 0;
					y < y370 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 1024
					// T (f, 16) (1024 / 64)
					for (f = f846, fp_1 = f846_p_0, fp_0 = 0;
						f < f846 + 1024;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
						// T (c, 2) (4 / 2)
						for (c1218 = c1219, c1218_p_2 = c1219_p_1, c1218_p_1 = c1219_p_0, c1218_p_0 = 0;
							c1218 < c1219 + 4;
							c1218 += 2, c1218_p_2 += 2, c1218_p_1 += 2, c1218_p_0 += 2){
							// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
							// T (h, 3) (3 / 1)
							for (h = h392, hp_0 = 0;
								h < h392 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 2, f = 64
								// T (w, 3) (3 / 1)
								for (w = w396, wp_0 = 0;
									w < w396 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 1, c = 2, f = 64
									// T (x, 7) (7 / 1)
									for (x = x516, xp_0 = 0;
										x < x516 + 7;
										x += 1, xp_0 += 1){
												mem_vec_4340 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4341 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4342 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_4343 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_4344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_4347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_4348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_4351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
												// T (c, 2) (2 / 1)
												for (c = c1218, cp_3 = c1218_p_2, cp_2 = c1218_p_1, cp_1 = c1218_p_0, cp_0 = 0;
													c < c1218 + 2;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4340);
													mem_vec_4340 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4341);
													mem_vec_4341 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4342);
													mem_vec_4342 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4343);
													mem_vec_4343 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4344);
													mem_vec_4344 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4345);
													mem_vec_4345 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4346);
													mem_vec_4346 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4347);
													mem_vec_4347 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4348);
													mem_vec_4348 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4349);
													mem_vec_4349 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4350);
													mem_vec_4350 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4351);
													mem_vec_4351 = vec_18;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4340);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4341);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4342);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4343);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4344);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4345);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4346);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4347);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4348);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4349);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4350);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4351);
									}
								}
							}
						}
					}
				}
				for (y = y370 + 3, yp_0 = 0;
					y < y370 + 3 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 1024
					// T (f, 16) (1024 / 64)
					for (f = f846, fp_1 = f846_p_0, fp_0 = 0;
						f < f846 + 1024;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
						// T (c, 2) (4 / 2)
						for (c1218 = c1219, c1218_p_2 = c1219_p_1, c1218_p_1 = c1219_p_0, c1218_p_0 = 0;
							c1218 < c1219 + 4;
							c1218 += 2, c1218_p_2 += 2, c1218_p_1 += 2, c1218_p_0 += 2){
							// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
							// T (h, 3) (3 / 1)
							for (h = h392, hp_0 = 0;
								h < h392 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 2, f = 64
								// T (w, 3) (3 / 1)
								for (w = w396, wp_0 = 0;
									w < w396 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 1, c = 2, f = 64
									// T (x, 7) (7 / 1)
									for (x = x516, xp_0 = 0;
										x < x516 + 7;
										x += 1, xp_0 += 1){
												mem_vec_4352 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4353 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4354 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_4355 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_4356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_4359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_4360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_4363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_4364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_4367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
												// T (c, 2) (2 / 1)
												for (c = c1218, cp_3 = c1218_p_2, cp_2 = c1218_p_1, cp_1 = c1218_p_0, cp_0 = 0;
													c < c1218 + 2;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4352);
													mem_vec_4352 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4353);
													mem_vec_4353 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4354);
													mem_vec_4354 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4355);
													mem_vec_4355 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4356);
													mem_vec_4356 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4357);
													mem_vec_4357 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4358);
													mem_vec_4358 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4359);
													mem_vec_4359 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4360);
													mem_vec_4360 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4361);
													mem_vec_4361 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4362);
													mem_vec_4362 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4363);
													mem_vec_4363 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4364);
													mem_vec_4364 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4365);
													mem_vec_4365 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4366);
													mem_vec_4366 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4367);
													mem_vec_4367 = vec_23;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4352);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4353);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4354);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4355);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4356);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4357);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4358);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4359);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4360);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4361);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4362);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4363);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4364);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4365);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4366);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4367);
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