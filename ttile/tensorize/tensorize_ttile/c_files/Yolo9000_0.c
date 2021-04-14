#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (3, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (32, y); T (272, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (2, x)]
*/
IND_TYPE c, cp_0, h, hp_0, w, wp_0, x, xp_0, x136_p_0, x137_p_0, xp_1, x136_p_1, xp_2, x136, x137, y, yp_0, y102_p_0, yp_1, y102;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y103 = 0;
IND_TYPE x138 = 0;
IND_TYPE h68 = 0;
IND_TYPE w68 = 0;
IND_TYPE c68 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_544 ,mem_vec_545 ,mem_vec_546 ,mem_vec_547 ,mem_vec_548 ,mem_vec_549 ,mem_vec_550 ,mem_vec_551 ,mem_vec_552 ,mem_vec_553 ,mem_vec_554 ,mem_vec_555 ,mem_vec_556 ,mem_vec_557 ,mem_vec_558 ,mem_vec_559 ,mem_vec_560 ,mem_vec_561 ,mem_vec_562 ,mem_vec_563 ,mem_vec_564 ,mem_vec_565 ,mem_vec_566 ,mem_vec_567 ,mem_vec_568 ,mem_vec_569 ,mem_vec_570 ,mem_vec_571 ,mem_vec_572 ,mem_vec_573 ,mem_vec_574 ,mem_vec_575 ,mem_vec_576 ,mem_vec_577 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (x, 2) (544 / 272)
for (x137 = x138, x137_p_0 = 0;
	x137 < x138 + 544;
	x137 += 272, x137_p_0 += 272){
		for (y102 = y103, y102_p_0 = 0;
			y102 < y103 + 256;
			y102 += 256, y102_p_0 += 256){
			// y = 32 * ph_y, x = 272, h = 3, w = 3, c = 3, f = 32
			// T (x, 272) (272 / 1)
			for (x136 = x137, x136_p_1 = x137_p_0, x136_p_0 = 0;
				x136 < x137 + 272;
				x136 += 1, x136_p_1 += 1, x136_p_0 += 1){
				// y = 32 * ph_y, x = 1, h = 3, w = 3, c = 3, f = 32
				// T (y, 32) (32 * ph_y / ph_y)
				for (y = y102, yp_1 = y102_p_0, yp_0 = 0;
					y < y102 + 256;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 1, h = 3, w = 3, c = 3, f = 32
					// T (h, 3) (3 / 1)
					for (h = h68, hp_0 = 0;
						h < h68 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 3, f = 32
						// T (w, 3) (3 / 1)
						for (w = w68, wp_0 = 0;
							w < w68 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
							// T (x, 1) (1 / 1)
							for (x = x136, xp_2 = x136_p_1, xp_1 = x136_p_0, xp_0 = 0;
								x < x136 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_544 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_545 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_552 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_553 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c68, cp_0 = 0;
											c < c68 + 3;
											c += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_544);
											mem_vec_544 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_545);
											mem_vec_545 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_546);
											mem_vec_546 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_547);
											mem_vec_547 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_548);
											mem_vec_548 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_549);
											mem_vec_549 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_550);
											mem_vec_550 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_551);
											mem_vec_551 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_552);
											mem_vec_552 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_553);
											mem_vec_553 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_554);
											mem_vec_554 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_555);
											mem_vec_555 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_556);
											mem_vec_556 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_557);
											mem_vec_557 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_558);
											mem_vec_558 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_559);
											mem_vec_559 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_544);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_545);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_546);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_547);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_548);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_549);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_550);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_551);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_552);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_553);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_554);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_555);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_556);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_557);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_558);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_559);
							}
						}
					}
				}
			}
		}
		for (y102 = y103 + 256, y102_p_0 = 0;
			y102 < y103 + 256 + 288;
			y102 += 288, y102_p_0 += 288){
			// y = 32 * ph_y, x = 272, h = 3, w = 3, c = 3, f = 32
			// T (x, 272) (272 / 1)
			for (x136 = x137, x136_p_1 = x137_p_0, x136_p_0 = 0;
				x136 < x137 + 272;
				x136 += 1, x136_p_1 += 1, x136_p_0 += 1){
				// y = 32 * ph_y, x = 1, h = 3, w = 3, c = 3, f = 32
				// T (y, 32) (32 * ph_y / ph_y)
				for (y = y102, yp_1 = y102_p_0, yp_0 = 0;
					y < y102 + 288;
					y += 9, yp_1 += 9, yp_0 += 9){
					// y = ph_y, x = 1, h = 3, w = 3, c = 3, f = 32
					// T (h, 3) (3 / 1)
					for (h = h68, hp_0 = 0;
						h < h68 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 3, f = 32
						// T (w, 3) (3 / 1)
						for (w = w68, wp_0 = 0;
							w < w68 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
							// T (x, 1) (1 / 1)
							for (x = x136, xp_2 = x136_p_1, xp_1 = x136_p_0, xp_0 = 0;
								x < x136 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_560 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_561 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c68, cp_0 = 0;
											c < c68 + 3;
											c += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_560);
											mem_vec_560 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_561);
											mem_vec_561 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_562);
											mem_vec_562 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_563);
											mem_vec_563 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_564);
											mem_vec_564 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_565);
											mem_vec_565 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_566);
											mem_vec_566 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_567);
											mem_vec_567 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_568);
											mem_vec_568 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_569);
											mem_vec_569 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_570);
											mem_vec_570 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_571);
											mem_vec_571 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_572);
											mem_vec_572 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_573);
											mem_vec_573 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_574);
											mem_vec_574 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_575);
											mem_vec_575 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_576);
											mem_vec_576 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_577);
											mem_vec_577 = vec_28;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_560);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_561);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_562);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_563);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_564);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_565);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_566);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_567);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_568);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_569);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_570);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_571);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_572);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_573);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_574);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_575);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_576);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_577);
							}
						}
					}
				}
			}
		}
}


}