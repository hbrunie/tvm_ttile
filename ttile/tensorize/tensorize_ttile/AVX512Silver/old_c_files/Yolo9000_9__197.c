#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (2, f); T (1, x); T (2, y); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]]
*/
IND_TYPE c, cp_0, c45_p_0, cp_1, c45, f, fp_0, x, xp_0, x60_p_0, x61_p_0, xp_1, x60_p_1, xp_2, x60, x61, y, yp_0, y45_p_0, yp_1, y45;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y46 = 0;
IND_TYPE x62 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c46 = 0;
IND_TYPE f30 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_556 ,mem_vec_557 ,mem_vec_558 ,mem_vec_559 ,mem_vec_560 ,mem_vec_561 ,mem_vec_562 ,mem_vec_563 ,mem_vec_564 ,mem_vec_565 ,mem_vec_566 ,mem_vec_567 ,mem_vec_568 ,mem_vec_569 ,mem_vec_570 ,mem_vec_571 ,mem_vec_572 ,mem_vec_573 ,mem_vec_574 ,mem_vec_575 ,mem_vec_576 ,mem_vec_577 ,mem_vec_578 ,mem_vec_579 ,mem_vec_580 ,mem_vec_581 ,mem_vec_582 ,mem_vec_583 ,mem_vec_584 ,mem_vec_585 ,mem_vec_586 ,mem_vec_587 ,mem_vec_588 ,mem_vec_589 ,mem_vec_590 ,mem_vec_591 ,mem_vec_592 ,mem_vec_593 ,mem_vec_594 ,mem_vec_595 ,mem_vec_596 ,mem_vec_597 ,mem_vec_598 ,mem_vec_599 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y45 = y46, y45_p_0 = 0;
		y45 < y46 + 40;
		y45 += 8, y45_p_0 += 8){
		// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x61 = x62, x61_p_0 = 0;
			x61 < x62 + 68;
			x61 += 68, x61_p_0 += 68){
			// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y45, yp_1 = y45_p_0, yp_0 = 0;
				y < y45 + 8;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x60 = x61, x60_p_1 = x61_p_0, x60_p_0 = 0;
					x60 < x61 + 68;
					x60 += 68, x60_p_1 += 68, x60_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f30, fp_0 = 0;
						f < f30 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c45 = c46, c45_p_0 = 0;
							c45 < c46 + 256;
							c45 += 256, c45_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x60, xp_2 = x60_p_1, xp_1 = x60_p_0, xp_0 = 0;
								x < x60 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_556 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_557 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_558 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_559 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
											c < c45 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_556);
											mem_vec_556 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_557);
											mem_vec_557 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_558);
											mem_vec_558 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_559);
											mem_vec_559 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_560);
											mem_vec_560 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_561);
											mem_vec_561 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_562);
											mem_vec_562 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_563);
											mem_vec_563 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_564);
											mem_vec_564 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_565);
											mem_vec_565 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_566);
											mem_vec_566 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_567);
											mem_vec_567 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_568);
											mem_vec_568 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_569);
											mem_vec_569 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_570);
											mem_vec_570 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_571);
											mem_vec_571 = vec_23;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_556);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_557);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_558);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_559);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_560);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_561);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_562);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_563);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_564);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_565);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_566);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_567);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_568);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_569);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_570);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_571);
							}
						}
					}
				}
			}
		}
	}
	for (y45 = y46 + 40, y45_p_0 = 0;
		y45 < y46 + 40 + 28;
		y45 += 14, y45_p_0 += 14){
		// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x61 = x62, x61_p_0 = 0;
			x61 < x62 + 68;
			x61 += 68, x61_p_0 += 68){
			// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y45, yp_1 = y45_p_0, yp_0 = 0;
				y < y45 + 14;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x60 = x61, x60_p_1 = x61_p_0, x60_p_0 = 0;
					x60 < x61 + 68;
					x60 += 68, x60_p_1 += 68, x60_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f30, fp_0 = 0;
						f < f30 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c45 = c46, c45_p_0 = 0;
							c45 < c46 + 256;
							c45 += 256, c45_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x60, xp_2 = x60_p_1, xp_1 = x60_p_0, xp_0 = 0;
								x < x60 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_572 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_573 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_574 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_575 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_590 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_591 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_592 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_593 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_594 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_595 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_596 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_597 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_598 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_599 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
											c < c45 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_572);
											mem_vec_572 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_573);
											mem_vec_573 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_574);
											mem_vec_574 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_575);
											mem_vec_575 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_576);
											mem_vec_576 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_577);
											mem_vec_577 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_578);
											mem_vec_578 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_579);
											mem_vec_579 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_580);
											mem_vec_580 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_581);
											mem_vec_581 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_582);
											mem_vec_582 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_583);
											mem_vec_583 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_584);
											mem_vec_584 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_585);
											mem_vec_585 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_586);
											mem_vec_586 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_587);
											mem_vec_587 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_588);
											mem_vec_588 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_589);
											mem_vec_589 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_590);
											mem_vec_590 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_591);
											mem_vec_591 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_592);
											mem_vec_592 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_593);
											mem_vec_593 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_594);
											mem_vec_594 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_595);
											mem_vec_595 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_596);
											mem_vec_596 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_597);
											mem_vec_597 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_598);
											mem_vec_598 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_599);
											mem_vec_599 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_572);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_573);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_574);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_575);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_576);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_577);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_578);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_579);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_580);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_581);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_582);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_583);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_584);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_585);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_586);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_587);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_588);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_589);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_590);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_591);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_592);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_593);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_594);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_595);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_596);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_597);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_598);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_599);
							}
						}
					}
				}
			}
		}
	}


}