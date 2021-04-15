#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (3, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 3), (Arg 7)); ((Iter 1), (Arg 11))];
  T (1, x); T (17, y); T (136, x)]
*/
IND_TYPE c, cp_0, h, hp_0, w, wp_0, x, xp_0, x186_p_0, x187_p_0, xp_1, x186_p_1, xp_2, x186, x187, y, yp_0, y150_p_0, yp_1, y150;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y151 = 0;
IND_TYPE x188 = 0;
IND_TYPE h76 = 0;
IND_TYPE w62 = 0;
IND_TYPE c96 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_532 ,mem_vec_533 ,mem_vec_534 ,mem_vec_535 ,mem_vec_536 ,mem_vec_537 ,mem_vec_538 ,mem_vec_539 ,mem_vec_540 ,mem_vec_541 ,mem_vec_542 ,mem_vec_543 ,mem_vec_544 ,mem_vec_545 ,mem_vec_546 ,mem_vec_547 ,mem_vec_548 ,mem_vec_549 ,mem_vec_550 ,mem_vec_551 ,mem_vec_552 ,mem_vec_553 ,mem_vec_554 ,mem_vec_555 ,mem_vec_556 ,mem_vec_557 ,mem_vec_558 ,mem_vec_559 ,mem_vec_560 ,mem_vec_561 ,mem_vec_562 ,mem_vec_563 ,mem_vec_564 ,mem_vec_565 ,mem_vec_566 ,mem_vec_567 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (x, 136) (544 / 4)
for (x187 = x188, x187_p_0 = 0;
	x187 < x188 + 544;
	x187 += 4, x187_p_0 += 4){
	// y = 544, x = 4, h = 3, w = 3, c = 3, f = 32
	// T (y, 17) (544 / 32)
	for (y150 = y151, y150_p_0 = 0;
		y150 < y151 + 544;
		y150 += 32, y150_p_0 += 32){
		// y = 32, x = 4, h = 3, w = 3, c = 3, f = 32
		// T (x, 1) (4 / 4)
		for (x186 = x187, x186_p_1 = x187_p_0, x186_p_0 = 0;
			x186 < x187 + 4;
			x186 += 4, x186_p_1 += 4, x186_p_0 += 4){
				for (y = y150, yp_1 = y150_p_0, yp_0 = 0;
					y < y150 + 21;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 4, h = 3, w = 3, c = 3, f = 32
					// T (h, 3) (3 / 1)
					for (h = h76, hp_0 = 0;
						h < h76 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 4, h = 1, w = 3, c = 3, f = 32
						// T (w, 3) (3 / 1)
						for (w = w62, wp_0 = 0;
							w < w62 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 1, c = 3, f = 32
							// T (x, 4) (4 / 1)
							for (x = x186, xp_2 = x186_p_1, xp_1 = x186_p_0, xp_0 = 0;
								x < x186 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_532 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_533 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_534 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_535 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_536 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_537 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_542 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_543 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_544 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_545 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c96, cp_0 = 0;
											c < c96 + 3;
											c += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_532);
											mem_vec_532 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_533);
											mem_vec_533 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_534);
											mem_vec_534 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_535);
											mem_vec_535 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_536);
											mem_vec_536 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_537);
											mem_vec_537 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_538);
											mem_vec_538 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_539);
											mem_vec_539 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_540);
											mem_vec_540 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_541);
											mem_vec_541 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_542);
											mem_vec_542 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_543);
											mem_vec_543 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_544);
											mem_vec_544 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_545);
											mem_vec_545 = vec_22;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_532);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_533);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_534);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_535);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_536);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_537);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_538);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_539);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_540);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_541);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_542);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_543);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_544);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_545);
							}
						}
					}
				}
				for (y = y150 + 21, yp_1 = y150_p_0, yp_0 = 0;
					y < y150 + 21 + 11;
					y += 11, yp_1 += 11, yp_0 += 11){
					// y = ph_y, x = 4, h = 3, w = 3, c = 3, f = 32
					// T (h, 3) (3 / 1)
					for (h = h76, hp_0 = 0;
						h < h76 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 4, h = 1, w = 3, c = 3, f = 32
						// T (w, 3) (3 / 1)
						for (w = w62, wp_0 = 0;
							w < w62 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 1, c = 3, f = 32
							// T (x, 4) (4 / 1)
							for (x = x186, xp_2 = x186_p_1, xp_1 = x186_p_0, xp_0 = 0;
								x < x186 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_546 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_547 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_552 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_553 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c96, cp_0 = 0;
											c < c96 + 3;
											c += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_546);
											mem_vec_546 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_547);
											mem_vec_547 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_548);
											mem_vec_548 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_549);
											mem_vec_549 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_550);
											mem_vec_550 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_551);
											mem_vec_551 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_552);
											mem_vec_552 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_553);
											mem_vec_553 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_554);
											mem_vec_554 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_555);
											mem_vec_555 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_556);
											mem_vec_556 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_557);
											mem_vec_557 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_558);
											mem_vec_558 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_559);
											mem_vec_559 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_560);
											mem_vec_560 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_561);
											mem_vec_561 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_562);
											mem_vec_562 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_563);
											mem_vec_563 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_564);
											mem_vec_564 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_565);
											mem_vec_565 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_566);
											mem_vec_566 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_567);
											mem_vec_567 = vec_34;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_546);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_547);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_548);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_549);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_550);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_551);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_552);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_553);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_554);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_555);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_556);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_557);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_558);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_559);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_560);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_561);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_562);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_563);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_564);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_565);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_566);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_567);
							}
						}
					}
				}
		}
	}
}


}