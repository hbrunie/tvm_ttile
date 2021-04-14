#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (7, x);
  Lambda_apply y [((Iter 7), (Arg 12)); ((Iter 2), (Arg 14))]; T (8, c);
  T (2, x)]
*/
IND_TYPE c, cp_0, c750_p_0, cp_1, c750, h, hp_0, w, wp_0, x, xp_0, x1000_p_0, x1001_p_0, xp_1, x1000_p_1, xp_2, x1000, x1001, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y500 = 0;
IND_TYPE x1002 = 0;
IND_TYPE h480 = 0;
IND_TYPE w500 = 0;
IND_TYPE c751 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9524 ,mem_vec_9525 ,mem_vec_9526 ,mem_vec_9527 ,mem_vec_9528 ,mem_vec_9529 ,mem_vec_9530 ,mem_vec_9531 ,mem_vec_9532 ,mem_vec_9533 ,mem_vec_9534 ,mem_vec_9535 ,mem_vec_9536 ,mem_vec_9537 ,mem_vec_9538 ,mem_vec_9539 ,mem_vec_9540 ,mem_vec_9541 ,mem_vec_9542 ,mem_vec_9543 ,mem_vec_9544 ,mem_vec_9545 ,mem_vec_9546 ,mem_vec_9547 ,mem_vec_9548 ,mem_vec_9549 ,mem_vec_9550 ,mem_vec_9551 ,mem_vec_9552 ,mem_vec_9553 ,mem_vec_9554 ,mem_vec_9555 ,mem_vec_9556 ,mem_vec_9557 ,mem_vec_9558 ,mem_vec_9559 ,mem_vec_9560 ,mem_vec_9561 ,mem_vec_9562 ,mem_vec_9563 ,mem_vec_9564 ,mem_vec_9565 ,mem_vec_9566 ,mem_vec_9567 ,mem_vec_9568 ,mem_vec_9569 ,mem_vec_9570 ,mem_vec_9571 ,mem_vec_9572 ,mem_vec_9573 ,mem_vec_9574 ,mem_vec_9575 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 2) (112 / 56)
for (x1001 = x1002, x1001_p_0 = 0;
	x1001 < x1002 + 112;
	x1001 += 56, x1001_p_0 += 56){
	// y = 112, x = 56, h = 3, w = 3, c = 32, f = 32
	// T (c, 8) (32 / 4)
	for (c750 = c751, c750_p_0 = 0;
		c750 < c751 + 32;
		c750 += 4, c750_p_0 += 4){
			for (y = y500, yp_0 = 0;
				y < y500 + 84;
				y += 12, yp_0 += 12){
				// y = ph_y, x = 56, h = 3, w = 3, c = 4, f = 32
				// T (x, 7) (56 / 8)
				for (x1000 = x1001, x1000_p_1 = x1001_p_0, x1000_p_0 = 0;
					x1000 < x1001 + 56;
					x1000 += 8, x1000_p_1 += 8, x1000_p_0 += 8){
					// y = ph_y, x = 8, h = 3, w = 3, c = 4, f = 32
					// T (h, 3) (3 / 1)
					for (h = h480, hp_0 = 0;
						h < h480 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w500, wp_0 = 0;
							w < w500 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 4, f = 32
							// T (x, 8) (8 / 1)
							for (x = x1000, xp_2 = x1000_p_1, xp_1 = x1000_p_0, xp_0 = 0;
								x < x1000 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9524 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9525 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9526 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9527 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9528 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9529 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9532 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9533 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9534 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9535 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9536 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9537 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_9538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_9540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_9542 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_9543 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_9544 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_9545 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_9546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_9547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c750, cp_1 = c750_p_0, cp_0 = 0;
											c < c750 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9524);
											mem_vec_9524 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9525);
											mem_vec_9525 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9526);
											mem_vec_9526 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9527);
											mem_vec_9527 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9528);
											mem_vec_9528 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9529);
											mem_vec_9529 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9530);
											mem_vec_9530 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9531);
											mem_vec_9531 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9532);
											mem_vec_9532 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9533);
											mem_vec_9533 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9534);
											mem_vec_9534 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9535);
											mem_vec_9535 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9536);
											mem_vec_9536 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9537);
											mem_vec_9537 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9538);
											mem_vec_9538 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9539);
											mem_vec_9539 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9540);
											mem_vec_9540 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9541);
											mem_vec_9541 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9542);
											mem_vec_9542 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9543);
											mem_vec_9543 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9544);
											mem_vec_9544 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9545);
											mem_vec_9545 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9546);
											mem_vec_9546 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9547);
											mem_vec_9547 = vec_37;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9524);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9525);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9526);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9527);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9528);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9529);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9530);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9531);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9532);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9533);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9534);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9535);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9536);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9537);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9538);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9539);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9540);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9541);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9542);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9543);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9544);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9545);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9546);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9547);
							}
						}
					}
				}
			}
			for (y = y500 + 84, yp_0 = 0;
				y < y500 + 84 + 28;
				y += 14, yp_0 += 14){
				// y = ph_y, x = 56, h = 3, w = 3, c = 4, f = 32
				// T (x, 7) (56 / 8)
				for (x1000 = x1001, x1000_p_1 = x1001_p_0, x1000_p_0 = 0;
					x1000 < x1001 + 56;
					x1000 += 8, x1000_p_1 += 8, x1000_p_0 += 8){
					// y = ph_y, x = 8, h = 3, w = 3, c = 4, f = 32
					// T (h, 3) (3 / 1)
					for (h = h480, hp_0 = 0;
						h < h480 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w500, wp_0 = 0;
							w < w500 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 4, f = 32
							// T (x, 8) (8 / 1)
							for (x = x1000, xp_2 = x1000_p_1, xp_1 = x1000_p_0, xp_0 = 0;
								x < x1000 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9548 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9549 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9552 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9553 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_9562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_9564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_9566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_9567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_9568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_9569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_9570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_9571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_9572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_9573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_9574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_9575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c750, cp_1 = c750_p_0, cp_0 = 0;
											c < c750 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9548);
											mem_vec_9548 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9549);
											mem_vec_9549 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9550);
											mem_vec_9550 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9551);
											mem_vec_9551 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9552);
											mem_vec_9552 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9553);
											mem_vec_9553 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9554);
											mem_vec_9554 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9555);
											mem_vec_9555 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9556);
											mem_vec_9556 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9557);
											mem_vec_9557 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9558);
											mem_vec_9558 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9559);
											mem_vec_9559 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9560);
											mem_vec_9560 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9561);
											mem_vec_9561 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9562);
											mem_vec_9562 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9563);
											mem_vec_9563 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9564);
											mem_vec_9564 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9565);
											mem_vec_9565 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9566);
											mem_vec_9566 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9567);
											mem_vec_9567 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9568);
											mem_vec_9568 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9569);
											mem_vec_9569 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9570);
											mem_vec_9570 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9571);
											mem_vec_9571 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_9572);
											mem_vec_9572 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_9573);
											mem_vec_9573 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_9574);
											mem_vec_9574 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_9575);
											mem_vec_9575 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9548);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9549);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9550);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9551);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9552);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9553);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9554);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9555);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9556);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9557);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9558);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9559);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9560);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9561);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9562);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9563);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9564);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9565);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9566);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9567);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9568);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9569);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9570);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9571);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_9572);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_9573);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_9574);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_9575);
							}
						}
					}
				}
			}
	}
}


}