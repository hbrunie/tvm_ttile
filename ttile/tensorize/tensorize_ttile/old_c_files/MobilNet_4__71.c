#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (28, x); T (3, w);
  T (3, h); T (1, f); T (1, c); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 13)); ((Iter 1), (Arg 15))]; T (4, f)]
*/
IND_TYPE c, cp_0, c744_p_0, cp_1, c744, f, fp_0, f744_p_0, fp_1, f744, h, hp_0, w, wp_0, x, xp_0, x744_p_0, xp_1, x744, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y496 = 0;
IND_TYPE x745 = 0;
IND_TYPE h428 = 0;
IND_TYPE w466 = 0;
IND_TYPE c745 = 0;
IND_TYPE f745 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7324 ,mem_vec_7325 ,mem_vec_7326 ,mem_vec_7327 ,mem_vec_7328 ,mem_vec_7329 ,mem_vec_7330 ,mem_vec_7331 ,mem_vec_7332 ,mem_vec_7333 ,mem_vec_7334 ,mem_vec_7335 ,mem_vec_7336 ,mem_vec_7337 ,mem_vec_7338 ,mem_vec_7339 ,mem_vec_7340 ,mem_vec_7341 ,mem_vec_7342 ,mem_vec_7343 ,mem_vec_7344 ,mem_vec_7345 ,mem_vec_7346 ,mem_vec_7347 ,mem_vec_7348 ,mem_vec_7349 ,mem_vec_7350 ,mem_vec_7351 ,mem_vec_7352 ,mem_vec_7353 ,mem_vec_7354 ,mem_vec_7355 ,mem_vec_7356 ,mem_vec_7357 ,mem_vec_7358 ,mem_vec_7359 ,mem_vec_7360 ,mem_vec_7361 ,mem_vec_7362 ,mem_vec_7363 ,mem_vec_7364 ,mem_vec_7365 ,mem_vec_7366 ,mem_vec_7367 ,mem_vec_7368 ,mem_vec_7369 ,mem_vec_7370 ,mem_vec_7371 ,mem_vec_7372 ,mem_vec_7373 ,mem_vec_7374 ,mem_vec_7375 ,mem_vec_7376 ,mem_vec_7377 ,mem_vec_7378 ,mem_vec_7379 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 4) (128 / 32)
for (f744 = f745, f744_p_0 = 0;
	f744 < f745 + 128;
	f744 += 32, f744_p_0 += 32){
		for (y = y496, yp_0 = 0;
			y < y496 + 13;
			y += 13, yp_0 += 13){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
			// T (x, 1) (28 / 28)
			for (x744 = x745, x744_p_0 = 0;
				x744 < x745 + 28;
				x744 += 28, x744_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
				// T (c, 1) (128 / 128)
				for (c744 = c745, c744_p_0 = 0;
					c744 < c745 + 128;
					c744 += 128, c744_p_0 += 128){
					// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f744, fp_1 = f744_p_0, fp_0 = 0;
						f < f744 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
						// T (h, 3) (3 / 1)
						for (h = h428, hp_0 = 0;
							h < h428 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 128, f = 32
							// T (w, 3) (3 / 1)
							for (w = w466, wp_0 = 0;
								w < w466 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 28, h = 1, w = 1, c = 128, f = 32
								// T (x, 28) (28 / 1)
								for (x = x744, xp_1 = x744_p_0, xp_0 = 0;
									x < x744 + 28;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7324 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7325 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_7336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_7337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_7338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_7339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_7340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_7341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_7342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_7343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_7344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_7345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_7346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_7347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_7348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_7349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c744, cp_1 = c744_p_0, cp_0 = 0;
												c < c744 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7324);
												mem_vec_7324 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7325);
												mem_vec_7325 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7326);
												mem_vec_7326 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7327);
												mem_vec_7327 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7328);
												mem_vec_7328 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7329);
												mem_vec_7329 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7330);
												mem_vec_7330 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7331);
												mem_vec_7331 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7332);
												mem_vec_7332 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7333);
												mem_vec_7333 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7334);
												mem_vec_7334 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7335);
												mem_vec_7335 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7336);
												mem_vec_7336 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7337);
												mem_vec_7337 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7338);
												mem_vec_7338 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7339);
												mem_vec_7339 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7340);
												mem_vec_7340 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7341);
												mem_vec_7341 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7342);
												mem_vec_7342 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7343);
												mem_vec_7343 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7344);
												mem_vec_7344 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7345);
												mem_vec_7345 = vec_34;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_7346);
												mem_vec_7346 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_7347);
												mem_vec_7347 = vec_37;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_7348);
												mem_vec_7348 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_7349);
												mem_vec_7349 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7324);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7325);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7326);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7327);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7328);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7329);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7330);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7331);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7332);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7333);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7334);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7335);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7336);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7337);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7338);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7339);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7340);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7341);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7342);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7343);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7344);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7345);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_7346);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_7347);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_7348);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_7349);
								}
							}
						}
					}
				}
			}
		}
		for (y = y496 + 13, yp_0 = 0;
			y < y496 + 13 + 15;
			y += 15, yp_0 += 15){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
			// T (x, 1) (28 / 28)
			for (x744 = x745, x744_p_0 = 0;
				x744 < x745 + 28;
				x744 += 28, x744_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
				// T (c, 1) (128 / 128)
				for (c744 = c745, c744_p_0 = 0;
					c744 < c745 + 128;
					c744 += 128, c744_p_0 += 128){
					// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f744, fp_1 = f744_p_0, fp_0 = 0;
						f < f744 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
						// T (h, 3) (3 / 1)
						for (h = h428, hp_0 = 0;
							h < h428 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 128, f = 32
							// T (w, 3) (3 / 1)
							for (w = w466, wp_0 = 0;
								w < w466 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 28, h = 1, w = 1, c = 128, f = 32
								// T (x, 28) (28 / 1)
								for (x = x744, xp_1 = x744_p_0, xp_0 = 0;
									x < x744 + 28;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7350 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7351 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_7362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_7363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_7364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_7365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_7366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_7367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_7368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_7369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_7370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_7371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_7372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_7373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_7374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_7375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_7376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_7377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_7378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_7379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c744, cp_1 = c744_p_0, cp_0 = 0;
												c < c744 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7350);
												mem_vec_7350 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7351);
												mem_vec_7351 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7352);
												mem_vec_7352 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7353);
												mem_vec_7353 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7354);
												mem_vec_7354 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7355);
												mem_vec_7355 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7356);
												mem_vec_7356 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7357);
												mem_vec_7357 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7358);
												mem_vec_7358 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7359);
												mem_vec_7359 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7360);
												mem_vec_7360 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7361);
												mem_vec_7361 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7362);
												mem_vec_7362 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7363);
												mem_vec_7363 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7364);
												mem_vec_7364 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7365);
												mem_vec_7365 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7366);
												mem_vec_7366 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7367);
												mem_vec_7367 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7368);
												mem_vec_7368 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7369);
												mem_vec_7369 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7370);
												mem_vec_7370 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7371);
												mem_vec_7371 = vec_34;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_7372);
												mem_vec_7372 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_7373);
												mem_vec_7373 = vec_37;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_7374);
												mem_vec_7374 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_7375);
												mem_vec_7375 = vec_40;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_7376);
												mem_vec_7376 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_7377);
												mem_vec_7377 = vec_43;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 14) + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_7378);
												mem_vec_7378 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_7379);
												mem_vec_7379 = vec_46;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7350);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7351);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7352);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7353);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7354);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7355);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7356);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7357);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7358);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7359);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7360);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7361);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7362);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7363);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7364);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7365);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7366);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7367);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7368);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7369);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7370);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7371);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_7372);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_7373);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_7374);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_7375);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_7376);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_7377);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_7378);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_7379);
								}
							}
						}
					}
				}
			}
		}
}


}