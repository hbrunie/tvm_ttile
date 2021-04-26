#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (8, c); T (8, f);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 4), (Arg 11))]; T (4, x);
  T (1, f); T (1, f)]
*/
IND_TYPE c, cp_0, c348_p_0, cp_1, c348, f, fp_0, f458_p_0, f459_p_0, fp_1, f458_p_1, fp_2, f458, f459, h, hp_0, w, wp_0, x, xp_0, x348_p_0, xp_1, x348, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y235 = 0;
IND_TYPE x349 = 0;
IND_TYPE h229 = 0;
IND_TYPE w209 = 0;
IND_TYPE c349 = 0;
IND_TYPE f460 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4408 ,mem_vec_4409 ,mem_vec_4410 ,mem_vec_4411 ,mem_vec_4412 ,mem_vec_4413 ,mem_vec_4414 ,mem_vec_4415 ,mem_vec_4416 ,mem_vec_4417 ,mem_vec_4418 ,mem_vec_4419 ,mem_vec_4420 ,mem_vec_4421 ,mem_vec_4422 ,mem_vec_4423 ,mem_vec_4424 ,mem_vec_4425 ,mem_vec_4426 ,mem_vec_4427 ,mem_vec_4428 ,mem_vec_4429 ,mem_vec_4430 ,mem_vec_4431 ,mem_vec_4432 ,mem_vec_4433 ,mem_vec_4434 ,mem_vec_4435 ,mem_vec_4436 ,mem_vec_4437 ,mem_vec_4438 ,mem_vec_4439 ,mem_vec_4440 ,mem_vec_4441 ,mem_vec_4442 ,mem_vec_4443 ,mem_vec_4444 ,mem_vec_4445 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f459 = f460, f459_p_0 = 0;
	f459 < f460 + 256;
	f459 += 256, f459_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (f, 1) (256 / 256)
	for (f458 = f459, f458_p_1 = f459_p_0, f458_p_0 = 0;
		f458 < f459 + 256;
		f458 += 256, f458_p_1 += 256, f458_p_0 += 256){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
		// T (x, 4) (68 / 17)
		for (x348 = x349, x348_p_0 = 0;
			x348 < x349 + 68;
			x348 += 17, x348_p_0 += 17){
				for (y = y235, yp_0 = 0;
					y < y235 + 24;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 256
					// T (f, 8) (256 / 32)
					for (f = f458, fp_2 = f458_p_1, fp_1 = f458_p_0, fp_0 = 0;
						f < f458 + 256;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c348 = c349, c348_p_0 = 0;
							c348 < c349 + 128;
							c348 += 16, c348_p_0 += 16){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w209, wp_0 = 0;
								w < w209 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 32
								// T (x, 17) (17 / 1)
								for (x = x348, xp_1 = x348_p_0, xp_0 = 0;
									x < x348 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h229, hp_0 = 0;
										h < h229 + 3;
										h += 1, hp_0 += 1){
												mem_vec_4408 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4409 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_4417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_4418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_4419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_4420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_4421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_4422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_4423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c348, cp_1 = c348_p_0, cp_0 = 0;
													c < c348 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4408);
													mem_vec_4408 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4409);
													mem_vec_4409 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4410);
													mem_vec_4410 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4411);
													mem_vec_4411 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4412);
													mem_vec_4412 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4413);
													mem_vec_4413 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4414);
													mem_vec_4414 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4415);
													mem_vec_4415 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4416);
													mem_vec_4416 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4417);
													mem_vec_4417 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4418);
													mem_vec_4418 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4419);
													mem_vec_4419 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4420);
													mem_vec_4420 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4421);
													mem_vec_4421 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4422);
													mem_vec_4422 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4423);
													mem_vec_4423 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4408);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4409);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4410);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4411);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4412);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4413);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4414);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4415);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4416);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4417);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4418);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4419);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4420);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4421);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4422);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4423);
									}
								}
							}
						}
					}
				}
				for (y = y235 + 24, yp_0 = 0;
					y < y235 + 24 + 44;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 256
					// T (f, 8) (256 / 32)
					for (f = f458, fp_2 = f458_p_1, fp_1 = f458_p_0, fp_0 = 0;
						f < f458 + 256;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c348 = c349, c348_p_0 = 0;
							c348 < c349 + 128;
							c348 += 16, c348_p_0 += 16){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w209, wp_0 = 0;
								w < w209 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 32
								// T (x, 17) (17 / 1)
								for (x = x348, xp_1 = x348_p_0, xp_0 = 0;
									x < x348 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h229, hp_0 = 0;
										h < h229 + 3;
										h += 1, hp_0 += 1){
												mem_vec_4424 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4425 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_4433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_4434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_4435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_4436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_4437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_4438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_4439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_4440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_4441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_4442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_4443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_4444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_4445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c348, cp_1 = c348_p_0, cp_0 = 0;
													c < c348 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4424);
													mem_vec_4424 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4425);
													mem_vec_4425 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4426);
													mem_vec_4426 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4427);
													mem_vec_4427 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4428);
													mem_vec_4428 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4429);
													mem_vec_4429 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4430);
													mem_vec_4430 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4431);
													mem_vec_4431 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4432);
													mem_vec_4432 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4433);
													mem_vec_4433 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4434);
													mem_vec_4434 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4435);
													mem_vec_4435 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4436);
													mem_vec_4436 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4437);
													mem_vec_4437 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4438);
													mem_vec_4438 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4439);
													mem_vec_4439 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4440);
													mem_vec_4440 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4441);
													mem_vec_4441 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4442);
													mem_vec_4442 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4443);
													mem_vec_4443 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4444);
													mem_vec_4444 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4445);
													mem_vec_4445 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4424);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4425);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4426);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4427);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4428);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4429);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4430);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4431);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4432);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4433);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4434);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4435);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4436);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4437);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4438);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4439);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4440);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4441);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4442);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4443);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4444);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4445);
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