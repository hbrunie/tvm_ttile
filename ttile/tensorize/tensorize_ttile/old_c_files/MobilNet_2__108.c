#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (2, c); T (28, x);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (4, c)]
*/
IND_TYPE c, cp_0, c724_p_0, c725_p_0, cp_1, c724_p_1, cp_2, c724, c725, h, hp_0, w, wp_0, x, xp_0, x788_p_0, xp_1, x788, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y432 = 0;
IND_TYPE x789 = 0;
IND_TYPE h396 = 0;
IND_TYPE w408 = 0;
IND_TYPE c726 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_7356 ,mem_vec_7357 ,mem_vec_7358 ,mem_vec_7359 ,mem_vec_7360 ,mem_vec_7361 ,mem_vec_7362 ,mem_vec_7363 ,mem_vec_7364 ,mem_vec_7365 ,mem_vec_7366 ,mem_vec_7367 ,mem_vec_7368 ,mem_vec_7369 ,mem_vec_7370 ,mem_vec_7371 ,mem_vec_7372 ,mem_vec_7373 ,mem_vec_7374 ,mem_vec_7375 ,mem_vec_7376 ,mem_vec_7377 ,mem_vec_7378 ,mem_vec_7379 ,mem_vec_7380 ,mem_vec_7381 ,mem_vec_7382 ,mem_vec_7383 ,mem_vec_7384 ,mem_vec_7385 ,mem_vec_7386 ,mem_vec_7387 ,mem_vec_7388 ,mem_vec_7389 ,mem_vec_7390 ,mem_vec_7391 ,mem_vec_7392 ,mem_vec_7393 ,mem_vec_7394 ,mem_vec_7395 ,mem_vec_7396 ,mem_vec_7397 ,mem_vec_7398 ,mem_vec_7399 ,mem_vec_7400 ,mem_vec_7401 ,mem_vec_7402 ,mem_vec_7403 ,mem_vec_7404 ,mem_vec_7405 ,mem_vec_7406 ,mem_vec_7407 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 4) (64 / 16)
for (c725 = c726, c725_p_0 = 0;
	c725 < c726 + 64;
	c725 += 16, c725_p_0 += 16){
		for (y = y432, yp_0 = 0;
			y < y432 + 42;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 56, h = 3, w = 3, c = 16, f = 64
			// T (x, 28) (56 / 2)
			for (x788 = x789, x788_p_0 = 0;
				x788 < x789 + 56;
				x788 += 2, x788_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 64
				// T (c, 2) (16 / 8)
				for (c724 = c725, c724_p_1 = c725_p_0, c724_p_0 = 0;
					c724 < c725 + 16;
					c724 += 8, c724_p_1 += 8, c724_p_0 += 8){
					// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 64
					// T (h, 3) (3 / 1)
					for (h = h396, hp_0 = 0;
						h < h396 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 64
						// T (w, 3) (3 / 1)
						for (w = w408, wp_0 = 0;
							w < w408 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 1, c = 8, f = 64
							// T (x, 2) (2 / 1)
							for (x = x788, xp_1 = x788_p_0, xp_0 = 0;
								x < x788 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7356 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7357 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7358 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_7359 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_7360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_7364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_7367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_7368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_7371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_7372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_7375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_7376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_7378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_7379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
										// T (c, 8) (8 / 1)
										for (c = c724, cp_2 = c724_p_1, cp_1 = c724_p_0, cp_0 = 0;
											c < c724 + 8;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7356);
											mem_vec_7356 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7357);
											mem_vec_7357 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7358);
											mem_vec_7358 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7359);
											mem_vec_7359 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7360);
											mem_vec_7360 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7361);
											mem_vec_7361 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7362);
											mem_vec_7362 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7363);
											mem_vec_7363 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7364);
											mem_vec_7364 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7365);
											mem_vec_7365 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7366);
											mem_vec_7366 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7367);
											mem_vec_7367 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7368);
											mem_vec_7368 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7369);
											mem_vec_7369 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7370);
											mem_vec_7370 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7371);
											mem_vec_7371 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7372);
											mem_vec_7372 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7373);
											mem_vec_7373 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7374);
											mem_vec_7374 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7375);
											mem_vec_7375 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7376);
											mem_vec_7376 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7377);
											mem_vec_7377 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_7378);
											mem_vec_7378 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_7379);
											mem_vec_7379 = vec_33;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7356);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7357);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7358);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7359);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7360);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7361);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7362);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7363);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7364);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7365);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7366);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7367);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7368);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7369);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7370);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7371);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7372);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7373);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_7374);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_7375);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7376);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7377);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_7378);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_7379);
							}
						}
					}
				}
			}
		}
		for (y = y432 + 42, yp_0 = 0;
			y < y432 + 42 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 16, f = 64
			// T (x, 28) (56 / 2)
			for (x788 = x789, x788_p_0 = 0;
				x788 < x789 + 56;
				x788 += 2, x788_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 64
				// T (c, 2) (16 / 8)
				for (c724 = c725, c724_p_1 = c725_p_0, c724_p_0 = 0;
					c724 < c725 + 16;
					c724 += 8, c724_p_1 += 8, c724_p_0 += 8){
					// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 64
					// T (h, 3) (3 / 1)
					for (h = h396, hp_0 = 0;
						h < h396 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 64
						// T (w, 3) (3 / 1)
						for (w = w408, wp_0 = 0;
							w < w408 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 1, c = 8, f = 64
							// T (x, 2) (2 / 1)
							for (x = x788, xp_1 = x788_p_0, xp_0 = 0;
								x < x788 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7380 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7381 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7382 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_7383 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_7384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_7388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_7391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_7392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_7395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_7396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_7399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_7400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_7402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_7403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_7404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_7406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_7407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
										// T (c, 8) (8 / 1)
										for (c = c724, cp_2 = c724_p_1, cp_1 = c724_p_0, cp_0 = 0;
											c < c724 + 8;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7380);
											mem_vec_7380 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7381);
											mem_vec_7381 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7382);
											mem_vec_7382 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7383);
											mem_vec_7383 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7384);
											mem_vec_7384 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7385);
											mem_vec_7385 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7386);
											mem_vec_7386 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7387);
											mem_vec_7387 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7388);
											mem_vec_7388 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7389);
											mem_vec_7389 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7390);
											mem_vec_7390 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7391);
											mem_vec_7391 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7392);
											mem_vec_7392 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7393);
											mem_vec_7393 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7394);
											mem_vec_7394 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7395);
											mem_vec_7395 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7396);
											mem_vec_7396 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7397);
											mem_vec_7397 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7398);
											mem_vec_7398 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7399);
											mem_vec_7399 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7400);
											mem_vec_7400 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7401);
											mem_vec_7401 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_7402);
											mem_vec_7402 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_7403);
											mem_vec_7403 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_7404);
											mem_vec_7404 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_7405);
											mem_vec_7405 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_7406);
											mem_vec_7406 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_7407);
											mem_vec_7407 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7380);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7381);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7382);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7383);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7384);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7385);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7386);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7387);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7388);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7389);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7390);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7391);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7392);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7393);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7394);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7395);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7396);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7397);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_7398);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_7399);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7400);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7401);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_7402);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_7403);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7404);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7405);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_7406);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_7407);
							}
						}
					}
				}
			}
		}
}


}