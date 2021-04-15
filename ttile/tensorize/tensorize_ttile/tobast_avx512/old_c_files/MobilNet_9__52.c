#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (1, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (2, c);
  T (16, f); T (32, c)]
*/
IND_TYPE c, cp_0, c1238_p_0, c1239_p_0, c1240_p_0, cp_1, c1238_p_1, c1239_p_1, cp_2, c1238_p_2, cp_3, c1238, c1239, c1240, f, fp_0, f858_p_0, fp_1, f858, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y378 = 0;
IND_TYPE x524 = 0;
IND_TYPE h400 = 0;
IND_TYPE w404 = 0;
IND_TYPE c1241 = 0;
IND_TYPE f859 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_4452 ,mem_vec_4453 ,mem_vec_4454 ,mem_vec_4455 ,mem_vec_4456 ,mem_vec_4457 ,mem_vec_4458 ,mem_vec_4459 ,mem_vec_4460 ,mem_vec_4461 ,mem_vec_4462 ,mem_vec_4463 ,mem_vec_4464 ,mem_vec_4465 ,mem_vec_4466 ,mem_vec_4467 ,mem_vec_4468 ,mem_vec_4469 ,mem_vec_4470 ,mem_vec_4471 ,mem_vec_4472 ,mem_vec_4473 ,mem_vec_4474 ,mem_vec_4475 ,mem_vec_4476 ,mem_vec_4477 ,mem_vec_4478 ,mem_vec_4479 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 32) (1024 / 32)
for (c1240 = c1241, c1240_p_0 = 0;
	c1240 < c1241 + 1024;
	c1240 += 32, c1240_p_0 += 32){
	// y = 7, x = 7, h = 3, w = 3, c = 32, f = 1024
	// T (f, 16) (1024 / 64)
	for (f858 = f859, f858_p_0 = 0;
		f858 < f859 + 1024;
		f858 += 64, f858_p_0 += 64){
		// y = 7, x = 7, h = 3, w = 3, c = 32, f = 64
		// T (c, 2) (32 / 16)
		for (c1239 = c1240, c1239_p_1 = c1240_p_0, c1239_p_0 = 0;
			c1239 < c1240 + 32;
			c1239 += 16, c1239_p_1 += 16, c1239_p_0 += 16){
				for (y = y378, yp_0 = 0;
					y < y378 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
					// T (f, 1) (64 / 64)
					for (f = f858, fp_1 = f858_p_0, fp_0 = 0;
						f < f858 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
						// T (c, 1) (16 / 16)
						for (c1238 = c1239, c1238_p_2 = c1239_p_1, c1238_p_1 = c1239_p_0, c1238_p_0 = 0;
							c1238 < c1239 + 16;
							c1238 += 16, c1238_p_2 += 16, c1238_p_1 += 16, c1238_p_0 += 16){
							// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
							// T (h, 3) (3 / 1)
							for (h = h400, hp_0 = 0;
								h < h400 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 64
								// T (w, 3) (3 / 1)
								for (w = w404, wp_0 = 0;
									w < w404 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 1, c = 16, f = 64
									// T (x, 7) (7 / 1)
									for (x = x524, xp_0 = 0;
										x < x524 + 7;
										x += 1, xp_0 += 1){
												mem_vec_4452 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4453 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4454 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_4455 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_4456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_4459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_4460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_4463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
												// T (c, 16) (16 / 1)
												for (c = c1238, cp_3 = c1238_p_2, cp_2 = c1238_p_1, cp_1 = c1238_p_0, cp_0 = 0;
													c < c1238 + 16;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4452);
													mem_vec_4452 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4453);
													mem_vec_4453 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4454);
													mem_vec_4454 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4455);
													mem_vec_4455 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4456);
													mem_vec_4456 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4457);
													mem_vec_4457 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4458);
													mem_vec_4458 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4459);
													mem_vec_4459 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4460);
													mem_vec_4460 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4461);
													mem_vec_4461 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4462);
													mem_vec_4462 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4463);
													mem_vec_4463 = vec_18;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4452);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4453);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4454);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4455);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4456);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4457);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4458);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4459);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4460);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4461);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4462);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4463);
									}
								}
							}
						}
					}
				}
				for (y = y378 + 3, yp_0 = 0;
					y < y378 + 3 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
					// T (f, 1) (64 / 64)
					for (f = f858, fp_1 = f858_p_0, fp_0 = 0;
						f < f858 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
						// T (c, 1) (16 / 16)
						for (c1238 = c1239, c1238_p_2 = c1239_p_1, c1238_p_1 = c1239_p_0, c1238_p_0 = 0;
							c1238 < c1239 + 16;
							c1238 += 16, c1238_p_2 += 16, c1238_p_1 += 16, c1238_p_0 += 16){
							// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
							// T (h, 3) (3 / 1)
							for (h = h400, hp_0 = 0;
								h < h400 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 64
								// T (w, 3) (3 / 1)
								for (w = w404, wp_0 = 0;
									w < w404 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 1, c = 16, f = 64
									// T (x, 7) (7 / 1)
									for (x = x524, xp_0 = 0;
										x < x524 + 7;
										x += 1, xp_0 += 1){
												mem_vec_4464 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4465 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4466 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_4467 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_4468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_4471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_4472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_4475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_4476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_4479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
												// T (c, 16) (16 / 1)
												for (c = c1238, cp_3 = c1238_p_2, cp_2 = c1238_p_1, cp_1 = c1238_p_0, cp_0 = 0;
													c < c1238 + 16;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4464);
													mem_vec_4464 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4465);
													mem_vec_4465 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4466);
													mem_vec_4466 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4467);
													mem_vec_4467 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4468);
													mem_vec_4468 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4469);
													mem_vec_4469 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4470);
													mem_vec_4470 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4471);
													mem_vec_4471 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4472);
													mem_vec_4472 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4473);
													mem_vec_4473 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4474);
													mem_vec_4474 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4475);
													mem_vec_4475 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4476);
													mem_vec_4476 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4477);
													mem_vec_4477 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4478);
													mem_vec_4478 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4479);
													mem_vec_4479 = vec_23;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4464);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4465);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4466);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4467);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4468);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4469);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4470);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4471);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4472);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4473);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4474);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4475);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4476);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4477);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4478);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4479);
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