#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (17, x);
  Lambda_apply y [((Iter 11), (Arg 11)); ((Iter 1), (Arg 15))]; T (4, f);
  T (8, c); T (1, x)]
*/
IND_TYPE c, cp_0, c600_p_0, cp_1, c600, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x800_p_0, x801_p_0, xp_1, x800_p_1, xp_2, x800, x801, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y400 = 0;
IND_TYPE x802 = 0;
IND_TYPE h400 = 0;
IND_TYPE w370 = 0;
IND_TYPE c601 = 0;
IND_TYPE f400 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7360 ,mem_vec_7361 ,mem_vec_7362 ,mem_vec_7363 ,mem_vec_7364 ,mem_vec_7365 ,mem_vec_7366 ,mem_vec_7367 ,mem_vec_7368 ,mem_vec_7369 ,mem_vec_7370 ,mem_vec_7371 ,mem_vec_7372 ,mem_vec_7373 ,mem_vec_7374 ,mem_vec_7375 ,mem_vec_7376 ,mem_vec_7377 ,mem_vec_7378 ,mem_vec_7379 ,mem_vec_7380 ,mem_vec_7381 ,mem_vec_7382 ,mem_vec_7383 ,mem_vec_7384 ,mem_vec_7385 ,mem_vec_7386 ,mem_vec_7387 ,mem_vec_7388 ,mem_vec_7389 ,mem_vec_7390 ,mem_vec_7391 ,mem_vec_7392 ,mem_vec_7393 ,mem_vec_7394 ,mem_vec_7395 ,mem_vec_7396 ,mem_vec_7397 ,mem_vec_7398 ,mem_vec_7399 ,mem_vec_7400 ,mem_vec_7401 ,mem_vec_7402 ,mem_vec_7403 ,mem_vec_7404 ,mem_vec_7405 ,mem_vec_7406 ,mem_vec_7407 ,mem_vec_7408 ,mem_vec_7409 ,mem_vec_7410 ,mem_vec_7411 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
for (x801 = x802, x801_p_0 = 0;
	x801 < x802 + 136;
	x801 += 136, x801_p_0 += 136){
	// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
	// T (c, 8) (64 / 8)
	for (c600 = c601, c600_p_0 = 0;
		c600 < c601 + 64;
		c600 += 8, c600_p_0 += 8){
		// y = 136, x = 136, h = 3, w = 3, c = 8, f = 128
		// T (f, 4) (128 / 32)
		for (f = f400, fp_0 = 0;
			f < f400 + 128;
			f += 32, fp_0 += 32){
				for (y = y400, yp_0 = 0;
					y < y400 + 121;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 136, h = 3, w = 3, c = 8, f = 32
					// T (x, 17) (136 / 8)
					for (x800 = x801, x800_p_1 = x801_p_0, x800_p_0 = 0;
						x800 < x801 + 136;
						x800 += 8, x800_p_1 += 8, x800_p_0 += 8){
						// y = ph_y, x = 8, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h400, hp_0 = 0;
							h < h400 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w370, wp_0 = 0;
								w < w370 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 1, w = 1, c = 8, f = 32
								// T (x, 8) (8 / 1)
								for (x = x800, xp_2 = x800_p_1, xp_1 = x800_p_0, xp_0 = 0;
									x < x800 + 8;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7360 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7361 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_7372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_7373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_7374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_7375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_7376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_7377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_7378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_7379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_7380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_7381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c600, cp_1 = c600_p_0, cp_0 = 0;
												c < c600 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7360);
												mem_vec_7360 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7361);
												mem_vec_7361 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7362);
												mem_vec_7362 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7363);
												mem_vec_7363 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7364);
												mem_vec_7364 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7365);
												mem_vec_7365 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7366);
												mem_vec_7366 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7367);
												mem_vec_7367 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7368);
												mem_vec_7368 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7369);
												mem_vec_7369 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7370);
												mem_vec_7370 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7371);
												mem_vec_7371 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7372);
												mem_vec_7372 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7373);
												mem_vec_7373 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7374);
												mem_vec_7374 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7375);
												mem_vec_7375 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7376);
												mem_vec_7376 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7377);
												mem_vec_7377 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7378);
												mem_vec_7378 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7379);
												mem_vec_7379 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7380);
												mem_vec_7380 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7381);
												mem_vec_7381 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7360);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7361);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7362);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7363);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7364);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7365);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7366);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7367);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7368);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7369);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7370);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7371);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7372);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7373);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7374);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7375);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7376);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7377);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7378);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7379);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7380);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7381);
								}
							}
						}
					}
				}
				for (y = y400 + 121, yp_0 = 0;
					y < y400 + 121 + 15;
					y += 15, yp_0 += 15){
					// y = ph_y, x = 136, h = 3, w = 3, c = 8, f = 32
					// T (x, 17) (136 / 8)
					for (x800 = x801, x800_p_1 = x801_p_0, x800_p_0 = 0;
						x800 < x801 + 136;
						x800 += 8, x800_p_1 += 8, x800_p_0 += 8){
						// y = ph_y, x = 8, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h400, hp_0 = 0;
							h < h400 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w370, wp_0 = 0;
								w < w370 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 1, w = 1, c = 8, f = 32
								// T (x, 8) (8 / 1)
								for (x = x800, xp_2 = x800_p_1, xp_1 = x800_p_0, xp_0 = 0;
									x < x800 + 8;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7382 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7383 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_7394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_7395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_7396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_7397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_7398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_7399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_7400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_7401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_7402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_7403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_7404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_7405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_7406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_7407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_7408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_7409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_7410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_7411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c600, cp_1 = c600_p_0, cp_0 = 0;
												c < c600 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7382);
												mem_vec_7382 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7383);
												mem_vec_7383 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7384);
												mem_vec_7384 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7385);
												mem_vec_7385 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7386);
												mem_vec_7386 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7387);
												mem_vec_7387 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7388);
												mem_vec_7388 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7389);
												mem_vec_7389 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7390);
												mem_vec_7390 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7391);
												mem_vec_7391 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7392);
												mem_vec_7392 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7393);
												mem_vec_7393 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7394);
												mem_vec_7394 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7395);
												mem_vec_7395 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7396);
												mem_vec_7396 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7397);
												mem_vec_7397 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7398);
												mem_vec_7398 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7399);
												mem_vec_7399 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7400);
												mem_vec_7400 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7401);
												mem_vec_7401 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7402);
												mem_vec_7402 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7403);
												mem_vec_7403 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_7404);
												mem_vec_7404 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_7405);
												mem_vec_7405 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_7406);
												mem_vec_7406 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_7407);
												mem_vec_7407 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_7408);
												mem_vec_7408 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_7409);
												mem_vec_7409 = vec_43;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_7410);
												mem_vec_7410 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_7411);
												mem_vec_7411 = vec_46;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7382);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7383);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7384);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7385);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7386);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7387);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7388);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7389);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7390);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7391);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7392);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7393);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7394);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7395);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7396);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7397);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7398);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7399);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7400);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7401);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7402);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7403);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_7404);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_7405);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_7406);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_7407);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_7408);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_7409);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_7410);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_7411);
								}
							}
						}
					}
				}
		}
	}
}


}