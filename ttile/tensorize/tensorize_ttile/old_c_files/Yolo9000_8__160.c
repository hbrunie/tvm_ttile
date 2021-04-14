#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 5), (Arg 11)); ((Iter 1), (Arg 13))];
  T (1, f); T (4, c); T (1, f); T (34, x); T (8, f)]
*/
IND_TYPE c, cp_0, c834_p_0, cp_1, c834, f, fp_0, f1112_p_0, f1113_p_0, fp_1, f1112_p_1, fp_2, f1112, f1113, h, hp_0, w, wp_0, x, xp_0, x886_p_0, xp_1, x886, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y556 = 0;
IND_TYPE x887 = 0;
IND_TYPE h556 = 0;
IND_TYPE w504 = 0;
IND_TYPE c835 = 0;
IND_TYPE f1114 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10428 ,mem_vec_10429 ,mem_vec_10430 ,mem_vec_10431 ,mem_vec_10432 ,mem_vec_10433 ,mem_vec_10434 ,mem_vec_10435 ,mem_vec_10436 ,mem_vec_10437 ,mem_vec_10438 ,mem_vec_10439 ,mem_vec_10440 ,mem_vec_10441 ,mem_vec_10442 ,mem_vec_10443 ,mem_vec_10444 ,mem_vec_10445 ,mem_vec_10446 ,mem_vec_10447 ,mem_vec_10448 ,mem_vec_10449 ,mem_vec_10450 ,mem_vec_10451 ,mem_vec_10452 ,mem_vec_10453 ,mem_vec_10454 ,mem_vec_10455 ,mem_vec_10456 ,mem_vec_10457 ,mem_vec_10458 ,mem_vec_10459 ,mem_vec_10460 ,mem_vec_10461 ,mem_vec_10462 ,mem_vec_10463 ,mem_vec_10464 ,mem_vec_10465 ,mem_vec_10466 ,mem_vec_10467 ,mem_vec_10468 ,mem_vec_10469 ,mem_vec_10470 ,mem_vec_10471 ,mem_vec_10472 ,mem_vec_10473 ,mem_vec_10474 ,mem_vec_10475 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
for (f1113 = f1114, f1113_p_0 = 0;
	f1113 < f1114 + 256;
	f1113 += 32, f1113_p_0 += 32){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
	// T (x, 34) (68 / 2)
	for (x886 = x887, x886_p_0 = 0;
		x886 < x887 + 68;
		x886 += 2, x886_p_0 += 2){
		// y = 68, x = 2, h = 3, w = 3, c = 128, f = 32
		// T (f, 1) (32 / 32)
		for (f1112 = f1113, f1112_p_1 = f1113_p_0, f1112_p_0 = 0;
			f1112 < f1113 + 32;
			f1112 += 32, f1112_p_1 += 32, f1112_p_0 += 32){
			// y = 68, x = 2, h = 3, w = 3, c = 128, f = 32
			// T (c, 4) (128 / 32)
			for (c834 = c835, c834_p_0 = 0;
				c834 < c835 + 128;
				c834 += 32, c834_p_0 += 32){
				// y = 68, x = 2, h = 3, w = 3, c = 32, f = 32
				// T (f, 1) (32 / 32)
				for (f = f1112, fp_2 = f1112_p_1, fp_1 = f1112_p_0, fp_0 = 0;
					f < f1112 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y556, yp_0 = 0;
							y < y556 + 55;
							y += 11, yp_0 += 11){
							// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h556, hp_0 = 0;
								h < h556 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w504, wp_0 = 0;
									w < w504 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 32
									// T (x, 2) (2 / 1)
									for (x = x886, xp_1 = x886_p_0, xp_0 = 0;
										x < x886 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10428 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10429 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_10439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_10440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_10441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_10442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_10443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_10444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_10445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_10446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_10447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_10448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_10449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c834, cp_1 = c834_p_0, cp_0 = 0;
													c < c834 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10428);
													mem_vec_10428 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10429);
													mem_vec_10429 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10430);
													mem_vec_10430 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10431);
													mem_vec_10431 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10432);
													mem_vec_10432 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10433);
													mem_vec_10433 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10434);
													mem_vec_10434 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10435);
													mem_vec_10435 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10436);
													mem_vec_10436 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10437);
													mem_vec_10437 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10438);
													mem_vec_10438 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10439);
													mem_vec_10439 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10440);
													mem_vec_10440 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10441);
													mem_vec_10441 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10442);
													mem_vec_10442 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10443);
													mem_vec_10443 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10444);
													mem_vec_10444 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10445);
													mem_vec_10445 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10446);
													mem_vec_10446 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10447);
													mem_vec_10447 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10448);
													mem_vec_10448 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10449);
													mem_vec_10449 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10428);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10429);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10430);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10431);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10432);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10433);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10434);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10435);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10436);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10437);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10438);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10439);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10440);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10441);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10442);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10443);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10444);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10445);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10446);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10447);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10448);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10449);
									}
								}
							}
						}
						for (y = y556 + 55, yp_0 = 0;
							y < y556 + 55 + 13;
							y += 13, yp_0 += 13){
							// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h556, hp_0 = 0;
								h < h556 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w504, wp_0 = 0;
									w < w504 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 32
									// T (x, 2) (2 / 1)
									for (x = x886, xp_1 = x886_p_0, xp_0 = 0;
										x < x886 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10450 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10451 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_10461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_10462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_10463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_10464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_10465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_10466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_10467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_10468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_10469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_10470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_10471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_10472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_10473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_10474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_10475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c834, cp_1 = c834_p_0, cp_0 = 0;
													c < c834 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10450);
													mem_vec_10450 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10451);
													mem_vec_10451 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10452);
													mem_vec_10452 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10453);
													mem_vec_10453 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10454);
													mem_vec_10454 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10455);
													mem_vec_10455 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10456);
													mem_vec_10456 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10457);
													mem_vec_10457 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10458);
													mem_vec_10458 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10459);
													mem_vec_10459 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10460);
													mem_vec_10460 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10461);
													mem_vec_10461 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10462);
													mem_vec_10462 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10463);
													mem_vec_10463 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10464);
													mem_vec_10464 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10465);
													mem_vec_10465 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10466);
													mem_vec_10466 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10467);
													mem_vec_10467 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10468);
													mem_vec_10468 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10469);
													mem_vec_10469 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10470);
													mem_vec_10470 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10471);
													mem_vec_10471 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_10472);
													mem_vec_10472 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_10473);
													mem_vec_10473 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_10474);
													mem_vec_10474 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_10475);
													mem_vec_10475 = vec_40;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10450);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10451);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10452);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10453);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10454);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10455);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10456);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10457);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10458);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10459);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10460);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10461);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10462);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10463);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10464);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10465);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10466);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10467);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10468);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10469);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10470);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10471);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_10472);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_10473);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_10474);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_10475);
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