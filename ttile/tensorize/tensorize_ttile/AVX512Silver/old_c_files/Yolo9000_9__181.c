#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (2, f); T (1, x); T (4, y); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]]
*/
IND_TYPE c, cp_0, c39_p_0, cp_1, c39, f, fp_0, x, xp_0, x52_p_0, x53_p_0, xp_1, x52_p_1, xp_2, x52, x53, y, yp_0, y39_p_0, yp_1, y39;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y40 = 0;
IND_TYPE x54 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c40 = 0;
IND_TYPE f26 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_464 ,mem_vec_465 ,mem_vec_466 ,mem_vec_467 ,mem_vec_468 ,mem_vec_469 ,mem_vec_470 ,mem_vec_471 ,mem_vec_472 ,mem_vec_473 ,mem_vec_474 ,mem_vec_475 ,mem_vec_476 ,mem_vec_477 ,mem_vec_478 ,mem_vec_479 ,mem_vec_480 ,mem_vec_481 ,mem_vec_482 ,mem_vec_483 ,mem_vec_484 ,mem_vec_485 ,mem_vec_486 ,mem_vec_487 ,mem_vec_488 ,mem_vec_489 ,mem_vec_490 ,mem_vec_491 ,mem_vec_492 ,mem_vec_493 ,mem_vec_494 ,mem_vec_495 ,mem_vec_496 ,mem_vec_497 ,mem_vec_498 ,mem_vec_499 ,mem_vec_500 ,mem_vec_501 ,mem_vec_502 ,mem_vec_503 ,mem_vec_504 ,mem_vec_505 ,mem_vec_506 ,mem_vec_507 ,mem_vec_508 ,mem_vec_509 ,mem_vec_510 ,mem_vec_511 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y39 = y40, y39_p_0 = 0;
		y39 < y40 + 40;
		y39 += 20, y39_p_0 += 20){
		// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x53 = x54, x53_p_0 = 0;
			x53 < x54 + 68;
			x53 += 68, x53_p_0 += 68){
			// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y39, yp_1 = y39_p_0, yp_0 = 0;
				y < y39 + 20;
				y += 5, yp_1 += 5, yp_0 += 5){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x52 = x53, x52_p_1 = x53_p_0, x52_p_0 = 0;
					x52 < x53 + 68;
					x52 += 68, x52_p_1 += 68, x52_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f26, fp_0 = 0;
						f < f26 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c39 = c40, c39_p_0 = 0;
							c39 < c40 + 256;
							c39 += 256, c39_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x52, xp_2 = x52_p_1, xp_1 = x52_p_0, xp_0 = 0;
								x < x52 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_464 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_465 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_466 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_467 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c39, cp_1 = c39_p_0, cp_0 = 0;
											c < c39 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_464);
											mem_vec_464 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_465);
											mem_vec_465 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_466);
											mem_vec_466 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_467);
											mem_vec_467 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_468);
											mem_vec_468 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_469);
											mem_vec_469 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_470);
											mem_vec_470 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_471);
											mem_vec_471 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_472);
											mem_vec_472 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_473);
											mem_vec_473 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_474);
											mem_vec_474 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_475);
											mem_vec_475 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_476);
											mem_vec_476 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_477);
											mem_vec_477 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_478);
											mem_vec_478 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_479);
											mem_vec_479 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_480);
											mem_vec_480 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_481);
											mem_vec_481 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_482);
											mem_vec_482 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_483);
											mem_vec_483 = vec_28;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_464);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_465);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_466);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_467);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_468);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_469);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_470);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_471);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_472);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_473);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_474);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_475);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_476);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_477);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_478);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_479);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_480);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_481);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_482);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_483);
							}
						}
					}
				}
			}
		}
	}
	for (y39 = y40 + 40, y39_p_0 = 0;
		y39 < y40 + 40 + 28;
		y39 += 28, y39_p_0 += 28){
		// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x53 = x54, x53_p_0 = 0;
			x53 < x54 + 68;
			x53 += 68, x53_p_0 += 68){
			// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y39, yp_1 = y39_p_0, yp_0 = 0;
				y < y39 + 28;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x52 = x53, x52_p_1 = x53_p_0, x52_p_0 = 0;
					x52 < x53 + 68;
					x52 += 68, x52_p_1 += 68, x52_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f26, fp_0 = 0;
						f < f26 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c39 = c40, c39_p_0 = 0;
							c39 < c40 + 256;
							c39 += 256, c39_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x52, xp_2 = x52_p_1, xp_1 = x52_p_0, xp_0 = 0;
								x < x52 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_484 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_485 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_486 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_487 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c39, cp_1 = c39_p_0, cp_0 = 0;
											c < c39 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_484);
											mem_vec_484 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_485);
											mem_vec_485 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_486);
											mem_vec_486 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_487);
											mem_vec_487 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_488);
											mem_vec_488 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_489);
											mem_vec_489 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_490);
											mem_vec_490 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_491);
											mem_vec_491 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_492);
											mem_vec_492 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_493);
											mem_vec_493 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_494);
											mem_vec_494 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_495);
											mem_vec_495 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_496);
											mem_vec_496 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_497);
											mem_vec_497 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_498);
											mem_vec_498 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_499);
											mem_vec_499 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_500);
											mem_vec_500 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_501);
											mem_vec_501 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_502);
											mem_vec_502 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_503);
											mem_vec_503 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_504);
											mem_vec_504 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_505);
											mem_vec_505 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_506);
											mem_vec_506 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_507);
											mem_vec_507 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_508);
											mem_vec_508 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_509);
											mem_vec_509 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_510);
											mem_vec_510 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_511);
											mem_vec_511 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_484);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_485);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_486);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_487);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_488);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_489);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_490);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_491);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_492);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_493);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_494);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_495);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_496);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_497);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_498);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_499);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_500);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_501);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_502);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_503);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_504);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_505);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_506);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_507);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_508);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_509);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_510);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_511);
							}
						}
					}
				}
			}
		}
	}


}