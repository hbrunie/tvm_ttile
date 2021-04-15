#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (512, c); Hoist_vars [c]; T (2, x); T (1, c);
  T (17, x); Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 13))];
  T (8, f); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c30_p_0, cp_1, c30, f, fp_0, x, xp_0, x40_p_0, x41_p_0, xp_1, x40_p_1, xp_2, x40, x41, y, yp_0, y22_p_0, yp_1, y22;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y23 = 0;
IND_TYPE x42 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c31 = 0;
IND_TYPE f20 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_500 ,mem_vec_501 ,mem_vec_502 ,mem_vec_503 ,mem_vec_504 ,mem_vec_505 ,mem_vec_506 ,mem_vec_507 ,mem_vec_508 ,mem_vec_509 ,mem_vec_510 ,mem_vec_511 ,mem_vec_512 ,mem_vec_513 ,mem_vec_514 ,mem_vec_515 ,mem_vec_516 ,mem_vec_517 ,mem_vec_518 ,mem_vec_519 ,mem_vec_520 ,mem_vec_521 ,mem_vec_522 ,mem_vec_523 ,mem_vec_524 ,mem_vec_525 ,mem_vec_526 ,mem_vec_527 ,mem_vec_528 ,mem_vec_529 ,mem_vec_530 ,mem_vec_531 ,mem_vec_532 ,mem_vec_533 ,mem_vec_534 ,mem_vec_535 ,mem_vec_536 ,mem_vec_537 ,mem_vec_538 ,mem_vec_539 ,mem_vec_540 ,mem_vec_541 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (y, 1) (34 / 34)
for (y22 = y23, y22_p_0 = 0;
	y22 < y23 + 34;
	y22 += 34, y22_p_0 += 34){
	// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
	// T (x, 1) (34 / 34)
	for (x41 = x42, x41_p_0 = 0;
		x41 < x42 + 34;
		x41 += 34, x41_p_0 += 34){
		// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (f, 8) (256 / 32)
		for (f = f20, fp_0 = 0;
			f < f20 + 256;
			f += 32, fp_0 += 32){
				for (y = y22, yp_1 = y22_p_0, yp_0 = 0;
					y < y22 + 8;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 17) (34 / 2)
					for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
						x40 < x41 + 34;
						x40 += 2, x40_p_1 += 2, x40_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 512, f = 32
						// T (c, 1) (512 / 512)
						for (c30 = c31, c30_p_0 = 0;
							c30 < c31 + 512;
							c30 += 512, c30_p_0 += 512){
							// y = ph_y, x = 2, h = 1, w = 1, c = 512, f = 32
							// T (x, 2) (2 / 1)
							for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
								x < x40 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_500 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_501 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_512 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
										// T (c, 512) (512 / 1)
										for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
											c < c30 + 512;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_500);
											mem_vec_500 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_501);
											mem_vec_501 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_502);
											mem_vec_502 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_503);
											mem_vec_503 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_504);
											mem_vec_504 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_505);
											mem_vec_505 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_506);
											mem_vec_506 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_507);
											mem_vec_507 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_508);
											mem_vec_508 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_509);
											mem_vec_509 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_510);
											mem_vec_510 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_511);
											mem_vec_511 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_512);
											mem_vec_512 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_513);
											mem_vec_513 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_514);
											mem_vec_514 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_515);
											mem_vec_515 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_500);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_501);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_502);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_503);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_504);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_505);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_506);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_507);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_508);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_509);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_510);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_511);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_512);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_513);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_514);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_515);
							}
						}
					}
				}
				for (y = y22 + 8, yp_1 = y22_p_0, yp_0 = 0;
					y < y22 + 8 + 26;
					y += 13, yp_1 += 13, yp_0 += 13){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 17) (34 / 2)
					for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
						x40 < x41 + 34;
						x40 += 2, x40_p_1 += 2, x40_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 512, f = 32
						// T (c, 1) (512 / 512)
						for (c30 = c31, c30_p_0 = 0;
							c30 < c31 + 512;
							c30 += 512, c30_p_0 += 512){
							// y = ph_y, x = 2, h = 1, w = 1, c = 512, f = 32
							// T (x, 2) (2 / 1)
							for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
								x < x40 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_516 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_517 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_522 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_523 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_524 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_525 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_526 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_527 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_528 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_529 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_532 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_533 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_534 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_535 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_536 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_537 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
										// T (c, 512) (512 / 1)
										for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
											c < c30 + 512;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_516);
											mem_vec_516 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_517);
											mem_vec_517 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_518);
											mem_vec_518 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_519);
											mem_vec_519 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_520);
											mem_vec_520 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_521);
											mem_vec_521 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_522);
											mem_vec_522 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_523);
											mem_vec_523 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_524);
											mem_vec_524 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_525);
											mem_vec_525 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_526);
											mem_vec_526 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_527);
											mem_vec_527 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_528);
											mem_vec_528 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_529);
											mem_vec_529 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_530);
											mem_vec_530 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_531);
											mem_vec_531 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_532);
											mem_vec_532 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_533);
											mem_vec_533 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_534);
											mem_vec_534 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_535);
											mem_vec_535 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_536);
											mem_vec_536 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_537);
											mem_vec_537 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_538);
											mem_vec_538 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_539);
											mem_vec_539 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_540);
											mem_vec_540 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_541);
											mem_vec_541 = vec_40;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_516);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_517);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_518);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_519);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_520);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_521);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_522);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_523);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_524);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_525);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_526);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_527);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_528);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_529);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_530);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_531);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_532);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_533);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_534);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_535);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_536);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_537);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_538);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_539);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_540);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_541);
							}
						}
					}
				}
		}
	}
}


}