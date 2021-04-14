#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (56, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 9), (Arg 11)); ((Iter 1), (Arg 13))]; T (1, c);
  T (2, x)]
*/
IND_TYPE c, cp_0, c618_p_0, cp_1, c618, h, hp_0, w, wp_0, x, xp_0, x824_p_0, x825_p_0, xp_1, x824_p_1, xp_2, x824, x825, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y412 = 0;
IND_TYPE x826 = 0;
IND_TYPE h392 = 0;
IND_TYPE w412 = 0;
IND_TYPE c619 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7348 ,mem_vec_7349 ,mem_vec_7350 ,mem_vec_7351 ,mem_vec_7352 ,mem_vec_7353 ,mem_vec_7354 ,mem_vec_7355 ,mem_vec_7356 ,mem_vec_7357 ,mem_vec_7358 ,mem_vec_7359 ,mem_vec_7360 ,mem_vec_7361 ,mem_vec_7362 ,mem_vec_7363 ,mem_vec_7364 ,mem_vec_7365 ,mem_vec_7366 ,mem_vec_7367 ,mem_vec_7368 ,mem_vec_7369 ,mem_vec_7370 ,mem_vec_7371 ,mem_vec_7372 ,mem_vec_7373 ,mem_vec_7374 ,mem_vec_7375 ,mem_vec_7376 ,mem_vec_7377 ,mem_vec_7378 ,mem_vec_7379 ,mem_vec_7380 ,mem_vec_7381 ,mem_vec_7382 ,mem_vec_7383 ,mem_vec_7384 ,mem_vec_7385 ,mem_vec_7386 ,mem_vec_7387 ,mem_vec_7388 ,mem_vec_7389 ,mem_vec_7390 ,mem_vec_7391 ,mem_vec_7392 ,mem_vec_7393 ,mem_vec_7394 ,mem_vec_7395 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 2) (112 / 56)
for (x825 = x826, x825_p_0 = 0;
	x825 < x826 + 112;
	x825 += 56, x825_p_0 += 56){
	// y = 112, x = 56, h = 3, w = 3, c = 32, f = 32
	// T (c, 1) (32 / 32)
	for (c618 = c619, c618_p_0 = 0;
		c618 < c619 + 32;
		c618 += 32, c618_p_0 += 32){
			for (y = y412, yp_0 = 0;
				y < y412 + 99;
				y += 11, yp_0 += 11){
				// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 32
				// T (x, 1) (56 / 56)
				for (x824 = x825, x824_p_1 = x825_p_0, x824_p_0 = 0;
					x824 < x825 + 56;
					x824 += 56, x824_p_1 += 56, x824_p_0 += 56){
					// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h392, hp_0 = 0;
						h < h392 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 56, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w412, wp_0 = 0;
							w < w412 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 56, h = 1, w = 1, c = 32, f = 32
							// T (x, 56) (56 / 1)
							for (x = x824, xp_2 = x824_p_1, xp_1 = x824_p_0, xp_0 = 0;
								x < x824 + 56;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7348 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7349 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_7360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_7362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_7363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_7364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_7365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_7366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_7367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_7368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_7369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c618, cp_1 = c618_p_0, cp_0 = 0;
											c < c618 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7348);
											mem_vec_7348 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7349);
											mem_vec_7349 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7350);
											mem_vec_7350 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7351);
											mem_vec_7351 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7352);
											mem_vec_7352 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7353);
											mem_vec_7353 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7354);
											mem_vec_7354 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7355);
											mem_vec_7355 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7356);
											mem_vec_7356 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7357);
											mem_vec_7357 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7358);
											mem_vec_7358 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7359);
											mem_vec_7359 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7360);
											mem_vec_7360 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7361);
											mem_vec_7361 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7362);
											mem_vec_7362 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7363);
											mem_vec_7363 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7364);
											mem_vec_7364 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7365);
											mem_vec_7365 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7366);
											mem_vec_7366 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7367);
											mem_vec_7367 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7368);
											mem_vec_7368 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7369);
											mem_vec_7369 = vec_34;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7348);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7349);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7350);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7351);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7352);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7353);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7354);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7355);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7356);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7357);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7358);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7359);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7360);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7361);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7362);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7363);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7364);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7365);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7366);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7367);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7368);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7369);
							}
						}
					}
				}
			}
			for (y = y412 + 99, yp_0 = 0;
				y < y412 + 99 + 13;
				y += 13, yp_0 += 13){
				// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 32
				// T (x, 1) (56 / 56)
				for (x824 = x825, x824_p_1 = x825_p_0, x824_p_0 = 0;
					x824 < x825 + 56;
					x824 += 56, x824_p_1 += 56, x824_p_0 += 56){
					// y = ph_y, x = 56, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h392, hp_0 = 0;
						h < h392 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 56, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w412, wp_0 = 0;
							w < w412 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 56, h = 1, w = 1, c = 32, f = 32
							// T (x, 56) (56 / 1)
							for (x = x824, xp_2 = x824_p_1, xp_1 = x824_p_0, xp_0 = 0;
								x < x824 + 56;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7370 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7371 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_7382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_7384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_7385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_7386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_7387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_7388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_7389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_7390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_7391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_7392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_7393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_7394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_7395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c618, cp_1 = c618_p_0, cp_0 = 0;
											c < c618 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7370);
											mem_vec_7370 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7371);
											mem_vec_7371 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7372);
											mem_vec_7372 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7373);
											mem_vec_7373 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7374);
											mem_vec_7374 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7375);
											mem_vec_7375 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7376);
											mem_vec_7376 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7377);
											mem_vec_7377 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7378);
											mem_vec_7378 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7379);
											mem_vec_7379 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7380);
											mem_vec_7380 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7381);
											mem_vec_7381 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7382);
											mem_vec_7382 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7383);
											mem_vec_7383 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7384);
											mem_vec_7384 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7385);
											mem_vec_7385 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7386);
											mem_vec_7386 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7387);
											mem_vec_7387 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7388);
											mem_vec_7388 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7389);
											mem_vec_7389 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7390);
											mem_vec_7390 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7391);
											mem_vec_7391 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_7392);
											mem_vec_7392 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_7393);
											mem_vec_7393 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_7394);
											mem_vec_7394 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_7395);
											mem_vec_7395 = vec_40;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7370);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7371);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7372);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7373);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7374);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7375);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7376);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7377);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7378);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7379);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7380);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7381);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7382);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7383);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7384);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7385);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7386);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7387);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7388);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7389);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7390);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7391);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_7392);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_7393);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_7394);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_7395);
							}
						}
					}
				}
			}
	}
}


}