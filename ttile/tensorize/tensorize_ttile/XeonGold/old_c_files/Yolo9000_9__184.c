#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (17, x); T (2, c);
  T (2, f); T (4, x); T (2, y); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]]
*/
IND_TYPE c, cp_0, c30_p_0, cp_1, c30, f, fp_0, x, xp_0, x40_p_0, x41_p_0, xp_1, x40_p_1, xp_2, x40, x41, y, yp_0, y30_p_0, yp_1, y30;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y31 = 0;
IND_TYPE x42 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c31 = 0;
IND_TYPE f20 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_520 ,mem_vec_521 ,mem_vec_522 ,mem_vec_523 ,mem_vec_524 ,mem_vec_525 ,mem_vec_526 ,mem_vec_527 ,mem_vec_528 ,mem_vec_529 ,mem_vec_530 ,mem_vec_531 ,mem_vec_532 ,mem_vec_533 ,mem_vec_534 ,mem_vec_535 ,mem_vec_536 ,mem_vec_537 ,mem_vec_538 ,mem_vec_539 ,mem_vec_540 ,mem_vec_541 ,mem_vec_542 ,mem_vec_543 ,mem_vec_544 ,mem_vec_545 ,mem_vec_546 ,mem_vec_547 ,mem_vec_548 ,mem_vec_549 ,mem_vec_550 ,mem_vec_551 ,mem_vec_552 ,mem_vec_553 ,mem_vec_554 ,mem_vec_555 ,mem_vec_556 ,mem_vec_557 ,mem_vec_558 ,mem_vec_559 ,mem_vec_560 ,mem_vec_561 ,mem_vec_562 ,mem_vec_563 ,mem_vec_564 ,mem_vec_565 ,mem_vec_566 ,mem_vec_567 ,mem_vec_568 ,mem_vec_569 ,mem_vec_570 ,mem_vec_571 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y30 = y31, y30_p_0 = 0;
		y30 < y31 + 12;
		y30 += 12, y30_p_0 += 12){
		// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x41 = x42, x41_p_0 = 0;
			x41 < x42 + 68;
			x41 += 68, x41_p_0 += 68){
			// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y30, yp_1 = y30_p_0, yp_0 = 0;
				y < y30 + 12;
				y += 6, yp_1 += 6, yp_0 += 6){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 4) (68 / 17)
				for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
					x40 < x41 + 68;
					x40 += 17, x40_p_1 += 17, x40_p_0 += 17){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f20, fp_0 = 0;
						f < f20 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (c, 2) (256 / 128)
						for (c30 = c31, c30_p_0 = 0;
							c30 < c31 + 256;
							c30 += 128, c30_p_0 += 128){
							// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
							// T (x, 17) (17 / 1)
							for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
								x < x40 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_520 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_521 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_522 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_523 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_524 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_525 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_526 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_527 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_528 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_529 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_532 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_533 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_534 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_535 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_536 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_537 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_542 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_543 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
										// T (c, 128) (128 / 1)
										for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
											c < c30 + 128;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_520);
											mem_vec_520 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_521);
											mem_vec_521 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_522);
											mem_vec_522 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_523);
											mem_vec_523 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_524);
											mem_vec_524 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_525);
											mem_vec_525 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_526);
											mem_vec_526 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_527);
											mem_vec_527 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_528);
											mem_vec_528 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_529);
											mem_vec_529 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_530);
											mem_vec_530 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_531);
											mem_vec_531 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_532);
											mem_vec_532 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_533);
											mem_vec_533 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_534);
											mem_vec_534 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_535);
											mem_vec_535 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_536);
											mem_vec_536 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_537);
											mem_vec_537 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_538);
											mem_vec_538 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_539);
											mem_vec_539 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_540);
											mem_vec_540 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_541);
											mem_vec_541 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_542);
											mem_vec_542 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_543);
											mem_vec_543 = vec_33;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_520);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_521);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_522);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_523);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_524);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_525);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_526);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_527);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_528);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_529);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_530);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_531);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_532);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_533);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_534);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_535);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_536);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_537);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_538);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_539);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_540);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_541);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_542);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_543);
							}
						}
					}
				}
			}
		}
	}
	for (y30 = y31 + 12, y30_p_0 = 0;
		y30 < y31 + 12 + 56;
		y30 += 14, y30_p_0 += 14){
		// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x41 = x42, x41_p_0 = 0;
			x41 < x42 + 68;
			x41 += 68, x41_p_0 += 68){
			// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y30, yp_1 = y30_p_0, yp_0 = 0;
				y < y30 + 14;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 4) (68 / 17)
				for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
					x40 < x41 + 68;
					x40 += 17, x40_p_1 += 17, x40_p_0 += 17){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f20, fp_0 = 0;
						f < f20 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (c, 2) (256 / 128)
						for (c30 = c31, c30_p_0 = 0;
							c30 < c31 + 256;
							c30 += 128, c30_p_0 += 128){
							// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
							// T (x, 17) (17 / 1)
							for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
								x < x40 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_544 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_545 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_546 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_547 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_552 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_553 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
										// T (c, 128) (128 / 1)
										for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
											c < c30 + 128;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_544);
											mem_vec_544 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_545);
											mem_vec_545 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_546);
											mem_vec_546 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_547);
											mem_vec_547 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_548);
											mem_vec_548 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_549);
											mem_vec_549 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_550);
											mem_vec_550 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_551);
											mem_vec_551 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_552);
											mem_vec_552 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_553);
											mem_vec_553 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_554);
											mem_vec_554 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_555);
											mem_vec_555 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_556);
											mem_vec_556 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_557);
											mem_vec_557 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_558);
											mem_vec_558 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_559);
											mem_vec_559 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_560);
											mem_vec_560 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_561);
											mem_vec_561 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_562);
											mem_vec_562 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_563);
											mem_vec_563 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_564);
											mem_vec_564 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_565);
											mem_vec_565 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_566);
											mem_vec_566 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_567);
											mem_vec_567 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_568);
											mem_vec_568 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_569);
											mem_vec_569 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_570);
											mem_vec_570 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_571);
											mem_vec_571 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_544);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_545);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_546);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_547);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_548);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_549);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_550);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_551);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_552);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_553);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_554);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_555);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_556);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_557);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_558);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_559);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_560);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_561);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_562);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_563);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_564);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_565);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_566);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_567);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_568);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_569);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_570);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_571);
							}
						}
					}
				}
			}
		}
	}


}