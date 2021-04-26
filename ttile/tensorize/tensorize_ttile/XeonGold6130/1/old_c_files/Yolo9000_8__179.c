#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (8, c); T (2, f);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 4), (Arg 11))]; T (2, x);
  T (2, f); T (2, f)]
*/
IND_TYPE c, cp_0, c33_p_0, cp_1, c33, f, fp_0, f44_p_0, f45_p_0, fp_1, f44_p_1, fp_2, f44, f45, h, hp_0, w, wp_0, x, xp_0, x33_p_0, xp_1, x33, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y22 = 0;
IND_TYPE x34 = 0;
IND_TYPE h22 = 0;
IND_TYPE w22 = 0;
IND_TYPE c34 = 0;
IND_TYPE f46 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_430 ,mem_vec_431 ,mem_vec_432 ,mem_vec_433 ,mem_vec_434 ,mem_vec_435 ,mem_vec_436 ,mem_vec_437 ,mem_vec_438 ,mem_vec_439 ,mem_vec_440 ,mem_vec_441 ,mem_vec_442 ,mem_vec_443 ,mem_vec_444 ,mem_vec_445 ,mem_vec_446 ,mem_vec_447 ,mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,mem_vec_453 ,mem_vec_454 ,mem_vec_455 ,mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,mem_vec_464 ,mem_vec_465 ,mem_vec_466 ,mem_vec_467 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f45 = f46, f45_p_0 = 0;
	f45 < f46 + 256;
	f45 += 128, f45_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (f, 2) (128 / 64)
	for (f44 = f45, f44_p_1 = f45_p_0, f44_p_0 = 0;
		f44 < f45 + 128;
		f44 += 64, f44_p_1 += 64, f44_p_0 += 64){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
		// T (x, 2) (68 / 34)
		for (x33 = x34, x33_p_0 = 0;
			x33 < x34 + 68;
			x33 += 34, x33_p_0 += 34){
				for (y = y22, yp_0 = 0;
					y < y22 + 24;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f44, fp_2 = f44_p_1, fp_1 = f44_p_0, fp_0 = 0;
						f < f44 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c33 = c34, c33_p_0 = 0;
							c33 < c34 + 128;
							c33 += 16, c33_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w22, wp_0 = 0;
								w < w22 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x33, xp_1 = x33_p_0, xp_0 = 0;
									x < x33 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h22, hp_0 = 0;
										h < h22 + 3;
										h += 1, hp_0 += 1){
												mem_vec_430 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_431 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c33, cp_1 = c33_p_0, cp_0 = 0;
													c < c33 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_430);
													mem_vec_430 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_431);
													mem_vec_431 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_432);
													mem_vec_432 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_433);
													mem_vec_433 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_434);
													mem_vec_434 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_435);
													mem_vec_435 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_436);
													mem_vec_436 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_437);
													mem_vec_437 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_438);
													mem_vec_438 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_439);
													mem_vec_439 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_440);
													mem_vec_440 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_441);
													mem_vec_441 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_442);
													mem_vec_442 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_443);
													mem_vec_443 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_444);
													mem_vec_444 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_445);
													mem_vec_445 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_430);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_431);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_432);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_433);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_434);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_435);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_436);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_437);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_438);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_439);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_440);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_441);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_442);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_443);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_444);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_445);
									}
								}
							}
						}
					}
				}
				for (y = y22 + 24, yp_0 = 0;
					y < y22 + 24 + 44;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f44, fp_2 = f44_p_1, fp_1 = f44_p_0, fp_0 = 0;
						f < f44 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c33 = c34, c33_p_0 = 0;
							c33 < c34 + 128;
							c33 += 16, c33_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w22, wp_0 = 0;
								w < w22 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x33, xp_1 = x33_p_0, xp_0 = 0;
									x < x33 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h22, hp_0 = 0;
										h < h22 + 3;
										h += 1, hp_0 += 1){
												mem_vec_446 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_447 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c33, cp_1 = c33_p_0, cp_0 = 0;
													c < c33 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_446);
													mem_vec_446 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_447);
													mem_vec_447 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_448);
													mem_vec_448 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_449);
													mem_vec_449 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_450);
													mem_vec_450 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_451);
													mem_vec_451 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_452);
													mem_vec_452 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_453);
													mem_vec_453 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_454);
													mem_vec_454 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_455);
													mem_vec_455 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_456);
													mem_vec_456 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_457);
													mem_vec_457 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_458);
													mem_vec_458 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_459);
													mem_vec_459 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_460);
													mem_vec_460 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_461);
													mem_vec_461 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_462);
													mem_vec_462 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_463);
													mem_vec_463 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_464);
													mem_vec_464 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_465);
													mem_vec_465 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_466);
													mem_vec_466 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_467);
													mem_vec_467 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_446);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_447);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_448);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_449);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_450);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_451);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_452);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_453);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_454);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_455);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_456);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_457);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_458);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_459);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_460);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_461);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_462);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_463);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_464);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_465);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_466);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_467);
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