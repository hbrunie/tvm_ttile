#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 7), (Arg 8)); ((Iter 4), (Arg 14))]; T (4, c);
  T (4, x)]
*/
IND_TYPE c, cp_0, c366_p_0, cp_1, c366, h, hp_0, w, wp_0, x, xp_0, x488_p_0, x489_p_0, xp_1, x488_p_1, xp_2, x488, x489, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y244 = 0;
IND_TYPE x490 = 0;
IND_TYPE h224 = 0;
IND_TYPE w244 = 0;
IND_TYPE c367 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3552 ,mem_vec_3553 ,mem_vec_3554 ,mem_vec_3555 ,mem_vec_3556 ,mem_vec_3557 ,mem_vec_3558 ,mem_vec_3559 ,mem_vec_3560 ,mem_vec_3561 ,mem_vec_3562 ,mem_vec_3563 ,mem_vec_3564 ,mem_vec_3565 ,mem_vec_3566 ,mem_vec_3567 ,mem_vec_3568 ,mem_vec_3569 ,mem_vec_3570 ,mem_vec_3571 ,mem_vec_3572 ,mem_vec_3573 ,mem_vec_3574 ,mem_vec_3575 ,mem_vec_3576 ,mem_vec_3577 ,mem_vec_3578 ,mem_vec_3579 ,mem_vec_3580 ,mem_vec_3581 ,mem_vec_3582 ,mem_vec_3583 ,mem_vec_3584 ,mem_vec_3585 ,mem_vec_3586 ,mem_vec_3587 ,mem_vec_3588 ,mem_vec_3589 ,mem_vec_3590 ,mem_vec_3591 ,mem_vec_3592 ,mem_vec_3593 ,mem_vec_3594 ,mem_vec_3595 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 4) (112 / 28)
for (x489 = x490, x489_p_0 = 0;
	x489 < x490 + 112;
	x489 += 28, x489_p_0 += 28){
	// y = 112, x = 28, h = 3, w = 3, c = 32, f = 32
	// T (c, 4) (32 / 8)
	for (c366 = c367, c366_p_0 = 0;
		c366 < c367 + 32;
		c366 += 8, c366_p_0 += 8){
			for (y = y244, yp_0 = 0;
				y < y244 + 56;
				y += 8, yp_0 += 8){
				// y = ph_y, x = 28, h = 3, w = 3, c = 8, f = 32
				// T (x, 2) (28 / 14)
				for (x488 = x489, x488_p_1 = x489_p_0, x488_p_0 = 0;
					x488 < x489 + 28;
					x488 += 14, x488_p_1 += 14, x488_p_0 += 14){
					// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 32
					// T (h, 3) (3 / 1)
					for (h = h224, hp_0 = 0;
						h < h224 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 14, h = 1, w = 3, c = 8, f = 32
						// T (w, 3) (3 / 1)
						for (w = w244, wp_0 = 0;
							w < w244 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 1, c = 8, f = 32
							// T (x, 14) (14 / 1)
							for (x = x488, xp_2 = x488_p_1, xp_1 = x488_p_0, xp_0 = 0;
								x < x488 + 14;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3552 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3553 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c366, cp_1 = c366_p_0, cp_0 = 0;
											c < c366 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3552);
											mem_vec_3552 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3553);
											mem_vec_3553 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3554);
											mem_vec_3554 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3555);
											mem_vec_3555 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3556);
											mem_vec_3556 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3557);
											mem_vec_3557 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3558);
											mem_vec_3558 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3559);
											mem_vec_3559 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3560);
											mem_vec_3560 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3561);
											mem_vec_3561 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3562);
											mem_vec_3562 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3563);
											mem_vec_3563 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3564);
											mem_vec_3564 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3565);
											mem_vec_3565 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3566);
											mem_vec_3566 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3567);
											mem_vec_3567 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3552);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3553);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3554);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3555);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3556);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3557);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3558);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3559);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3560);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3561);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3562);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3563);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3564);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3565);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3566);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3567);
							}
						}
					}
				}
			}
			for (y = y244 + 56, yp_0 = 0;
				y < y244 + 56 + 56;
				y += 14, yp_0 += 14){
				// y = ph_y, x = 28, h = 3, w = 3, c = 8, f = 32
				// T (x, 2) (28 / 14)
				for (x488 = x489, x488_p_1 = x489_p_0, x488_p_0 = 0;
					x488 < x489 + 28;
					x488 += 14, x488_p_1 += 14, x488_p_0 += 14){
					// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 32
					// T (h, 3) (3 / 1)
					for (h = h224, hp_0 = 0;
						h < h224 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 14, h = 1, w = 3, c = 8, f = 32
						// T (w, 3) (3 / 1)
						for (w = w244, wp_0 = 0;
							w < w244 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 1, c = 8, f = 32
							// T (x, 14) (14 / 1)
							for (x = x488, xp_2 = x488_p_1, xp_1 = x488_p_0, xp_0 = 0;
								x < x488 + 14;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3568 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3569 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_3584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_3585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_3586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_3587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_3588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_3589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_3590 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_3591 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_3592 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_3593 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_3594 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_3595 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c366, cp_1 = c366_p_0, cp_0 = 0;
											c < c366 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3568);
											mem_vec_3568 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3569);
											mem_vec_3569 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3570);
											mem_vec_3570 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3571);
											mem_vec_3571 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3572);
											mem_vec_3572 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3573);
											mem_vec_3573 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3574);
											mem_vec_3574 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3575);
											mem_vec_3575 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3576);
											mem_vec_3576 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3577);
											mem_vec_3577 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3578);
											mem_vec_3578 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3579);
											mem_vec_3579 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3580);
											mem_vec_3580 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3581);
											mem_vec_3581 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3582);
											mem_vec_3582 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3583);
											mem_vec_3583 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3584);
											mem_vec_3584 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3585);
											mem_vec_3585 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3586);
											mem_vec_3586 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3587);
											mem_vec_3587 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3588);
											mem_vec_3588 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3589);
											mem_vec_3589 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3590);
											mem_vec_3590 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3591);
											mem_vec_3591 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3592);
											mem_vec_3592 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3593);
											mem_vec_3593 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_3594);
											mem_vec_3594 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_3595);
											mem_vec_3595 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3568);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3569);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3570);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3571);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3572);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3573);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3574);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3575);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3576);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3577);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3578);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3579);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3580);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3581);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3582);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3583);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3584);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3585);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3586);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3587);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3588);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3589);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3590);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3591);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3592);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_3593);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_3594);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_3595);
							}
						}
					}
				}
			}
	}
}


}