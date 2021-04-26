#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (4, x); T (4, c);
  T (4, f); T (1, x); T (2, y); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 10)); ((Iter 2), (Arg 12))]]
*/
IND_TYPE c, cp_0, c345_p_0, cp_1, c345, f, fp_0, x, xp_0, x460_p_0, x461_p_0, xp_1, x460_p_1, xp_2, x460, x461, y, yp_0, y345_p_0, yp_1, y345;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y346 = 0;
IND_TYPE x462 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c346 = 0;
IND_TYPE f230 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5452 ,mem_vec_5453 ,mem_vec_5454 ,mem_vec_5455 ,mem_vec_5456 ,mem_vec_5457 ,mem_vec_5458 ,mem_vec_5459 ,mem_vec_5460 ,mem_vec_5461 ,mem_vec_5462 ,mem_vec_5463 ,mem_vec_5464 ,mem_vec_5465 ,mem_vec_5466 ,mem_vec_5467 ,mem_vec_5468 ,mem_vec_5469 ,mem_vec_5470 ,mem_vec_5471 ,mem_vec_5472 ,mem_vec_5473 ,mem_vec_5474 ,mem_vec_5475 ,mem_vec_5476 ,mem_vec_5477 ,mem_vec_5478 ,mem_vec_5479 ,mem_vec_5480 ,mem_vec_5481 ,mem_vec_5482 ,mem_vec_5483 ,mem_vec_5484 ,mem_vec_5485 ,mem_vec_5486 ,mem_vec_5487 ,mem_vec_5488 ,mem_vec_5489 ,mem_vec_5490 ,mem_vec_5491 ,mem_vec_5492 ,mem_vec_5493 ,mem_vec_5494 ,mem_vec_5495 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y345 = y346, y345_p_0 = 0;
		y345 < y346 + 20;
		y345 += 20, y345_p_0 += 20){
		// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 17) (68 / 4)
		for (x461 = x462, x461_p_0 = 0;
			x461 < x462 + 68;
			x461 += 4, x461_p_0 += 4){
			// y = 2 * ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y345, yp_1 = y345_p_0, yp_0 = 0;
				y < y345 + 20;
				y += 10, yp_1 += 10, yp_0 += 10){
				// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (4 / 4)
				for (x460 = x461, x460_p_1 = x461_p_0, x460_p_0 = 0;
					x460 < x461 + 4;
					x460 += 4, x460_p_1 += 4, x460_p_0 += 4){
					// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f230, fp_0 = 0;
						f < f230 + 128;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 32
						// T (c, 4) (256 / 64)
						for (c345 = c346, c345_p_0 = 0;
							c345 < c346 + 256;
							c345 += 64, c345_p_0 += 64){
							// y = ph_y, x = 4, h = 1, w = 1, c = 64, f = 32
							// T (x, 4) (4 / 1)
							for (x = x460, xp_2 = x460_p_1, xp_1 = x460_p_0, xp_0 = 0;
								x < x460 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5452 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5453 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_5465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_5466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_5467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_5468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_5469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_5470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_5471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c345, cp_1 = c345_p_0, cp_0 = 0;
											c < c345 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5452);
											mem_vec_5452 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5453);
											mem_vec_5453 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5454);
											mem_vec_5454 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5455);
											mem_vec_5455 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5456);
											mem_vec_5456 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5457);
											mem_vec_5457 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5458);
											mem_vec_5458 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5459);
											mem_vec_5459 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5460);
											mem_vec_5460 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5461);
											mem_vec_5461 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5462);
											mem_vec_5462 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5463);
											mem_vec_5463 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5464);
											mem_vec_5464 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5465);
											mem_vec_5465 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5466);
											mem_vec_5466 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5467);
											mem_vec_5467 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5468);
											mem_vec_5468 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5469);
											mem_vec_5469 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5470);
											mem_vec_5470 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5471);
											mem_vec_5471 = vec_31;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5452);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5453);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5454);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5455);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5456);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5457);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5458);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5459);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5460);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5461);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5462);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5463);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5464);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5465);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5466);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5467);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5468);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5469);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5470);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5471);
							}
						}
					}
				}
			}
		}
	}
	for (y345 = y346 + 20, y345_p_0 = 0;
		y345 < y346 + 20 + 48;
		y345 += 24, y345_p_0 += 24){
		// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 17) (68 / 4)
		for (x461 = x462, x461_p_0 = 0;
			x461 < x462 + 68;
			x461 += 4, x461_p_0 += 4){
			// y = 2 * ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y345, yp_1 = y345_p_0, yp_0 = 0;
				y < y345 + 24;
				y += 12, yp_1 += 12, yp_0 += 12){
				// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (4 / 4)
				for (x460 = x461, x460_p_1 = x461_p_0, x460_p_0 = 0;
					x460 < x461 + 4;
					x460 += 4, x460_p_1 += 4, x460_p_0 += 4){
					// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f230, fp_0 = 0;
						f < f230 + 128;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 32
						// T (c, 4) (256 / 64)
						for (c345 = c346, c345_p_0 = 0;
							c345 < c346 + 256;
							c345 += 64, c345_p_0 += 64){
							// y = ph_y, x = 4, h = 1, w = 1, c = 64, f = 32
							// T (x, 4) (4 / 1)
							for (x = x460, xp_2 = x460_p_1, xp_1 = x460_p_0, xp_0 = 0;
								x < x460 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5472 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5473 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_5485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_5486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_5487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_5488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_5489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_5490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_5491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_5492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_5493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_5494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_5495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c345, cp_1 = c345_p_0, cp_0 = 0;
											c < c345 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5472);
											mem_vec_5472 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5473);
											mem_vec_5473 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5474);
											mem_vec_5474 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5475);
											mem_vec_5475 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5476);
											mem_vec_5476 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5477);
											mem_vec_5477 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5478);
											mem_vec_5478 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5479);
											mem_vec_5479 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5480);
											mem_vec_5480 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5481);
											mem_vec_5481 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5482);
											mem_vec_5482 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5483);
											mem_vec_5483 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5484);
											mem_vec_5484 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5485);
											mem_vec_5485 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5486);
											mem_vec_5486 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5487);
											mem_vec_5487 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5488);
											mem_vec_5488 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5489);
											mem_vec_5489 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5490);
											mem_vec_5490 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5491);
											mem_vec_5491 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5492);
											mem_vec_5492 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5493);
											mem_vec_5493 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_5494);
											mem_vec_5494 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_5495);
											mem_vec_5495 = vec_37;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5472);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5473);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5474);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5475);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5476);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5477);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5478);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5479);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5480);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5481);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5482);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5483);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5484);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5485);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5486);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5487);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5488);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5489);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5490);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5491);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5492);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_5493);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_5494);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_5495);
							}
						}
					}
				}
			}
		}
	}


}