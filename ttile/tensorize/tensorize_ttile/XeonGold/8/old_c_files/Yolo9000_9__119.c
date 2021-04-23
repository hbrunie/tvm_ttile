#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (34, x); T (2, c);
  T (2, f); T (2, x); T (2, y); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]]
*/
IND_TYPE c, cp_0, c201_p_0, cp_1, c201, f, fp_0, x, xp_0, x268_p_0, x269_p_0, xp_1, x268_p_1, xp_2, x268, x269, y, yp_0, y201_p_0, yp_1, y201;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y202 = 0;
IND_TYPE x270 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c202 = 0;
IND_TYPE f134 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_3412 ,mem_vec_3413 ,mem_vec_3414 ,mem_vec_3415 ,mem_vec_3416 ,mem_vec_3417 ,mem_vec_3418 ,mem_vec_3419 ,mem_vec_3420 ,mem_vec_3421 ,mem_vec_3422 ,mem_vec_3423 ,mem_vec_3424 ,mem_vec_3425 ,mem_vec_3426 ,mem_vec_3427 ,mem_vec_3428 ,mem_vec_3429 ,mem_vec_3430 ,mem_vec_3431 ,mem_vec_3432 ,mem_vec_3433 ,mem_vec_3434 ,mem_vec_3435 ,mem_vec_3436 ,mem_vec_3437 ,mem_vec_3438 ,mem_vec_3439 ,mem_vec_3440 ,mem_vec_3441 ,mem_vec_3442 ,mem_vec_3443 ,mem_vec_3444 ,mem_vec_3445 ,mem_vec_3446 ,mem_vec_3447 ,mem_vec_3448 ,mem_vec_3449 ,mem_vec_3450 ,mem_vec_3451 ,mem_vec_3452 ,mem_vec_3453 ,mem_vec_3454 ,mem_vec_3455 ,mem_vec_3456 ,mem_vec_3457 ,mem_vec_3458 ,mem_vec_3459 ,mem_vec_3460 ,mem_vec_3461 ,mem_vec_3462 ,mem_vec_3463 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y201 = y202, y201_p_0 = 0;
		y201 < y202 + 12;
		y201 += 12, y201_p_0 += 12){
		// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x269 = x270, x269_p_0 = 0;
			x269 < x270 + 68;
			x269 += 68, x269_p_0 += 68){
			// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y201, yp_1 = y201_p_0, yp_0 = 0;
				y < y201 + 12;
				y += 6, yp_1 += 6, yp_0 += 6){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 2) (68 / 34)
				for (x268 = x269, x268_p_1 = x269_p_0, x268_p_0 = 0;
					x268 < x269 + 68;
					x268 += 34, x268_p_1 += 34, x268_p_0 += 34){
					// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f134, fp_0 = 0;
						f < f134 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
						// T (c, 2) (256 / 128)
						for (c201 = c202, c201_p_0 = 0;
							c201 < c202 + 256;
							c201 += 128, c201_p_0 += 128){
							// y = ph_y, x = 34, h = 1, w = 1, c = 128, f = 64
							// T (x, 34) (34 / 1)
							for (x = x268, xp_2 = x268_p_1, xp_1 = x268_p_0, xp_0 = 0;
								x < x268 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3412 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3413 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3414 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_3415 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_3416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_3419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_3420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_3423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_3424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_3427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_3428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_3431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_3432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_3435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
										// T (c, 128) (128 / 1)
										for (c = c201, cp_1 = c201_p_0, cp_0 = 0;
											c < c201 + 128;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3412);
											mem_vec_3412 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3413);
											mem_vec_3413 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3414);
											mem_vec_3414 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3415);
											mem_vec_3415 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3416);
											mem_vec_3416 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3417);
											mem_vec_3417 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3418);
											mem_vec_3418 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3419);
											mem_vec_3419 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3420);
											mem_vec_3420 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3421);
											mem_vec_3421 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3422);
											mem_vec_3422 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3423);
											mem_vec_3423 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3424);
											mem_vec_3424 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3425);
											mem_vec_3425 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3426);
											mem_vec_3426 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3427);
											mem_vec_3427 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3428);
											mem_vec_3428 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3429);
											mem_vec_3429 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3430);
											mem_vec_3430 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3431);
											mem_vec_3431 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3432);
											mem_vec_3432 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3433);
											mem_vec_3433 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_3434);
											mem_vec_3434 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_3435);
											mem_vec_3435 = vec_33;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3412);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3413);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3414);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3415);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3416);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3417);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3418);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3419);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3420);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3421);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3422);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3423);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3424);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3425);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3426);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3427);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3428);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3429);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_3430);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_3431);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3432);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3433);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_3434);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_3435);
							}
						}
					}
				}
			}
		}
	}
	for (y201 = y202 + 12, y201_p_0 = 0;
		y201 < y202 + 12 + 56;
		y201 += 14, y201_p_0 += 14){
		// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x269 = x270, x269_p_0 = 0;
			x269 < x270 + 68;
			x269 += 68, x269_p_0 += 68){
			// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y201, yp_1 = y201_p_0, yp_0 = 0;
				y < y201 + 14;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 2) (68 / 34)
				for (x268 = x269, x268_p_1 = x269_p_0, x268_p_0 = 0;
					x268 < x269 + 68;
					x268 += 34, x268_p_1 += 34, x268_p_0 += 34){
					// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f134, fp_0 = 0;
						f < f134 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
						// T (c, 2) (256 / 128)
						for (c201 = c202, c201_p_0 = 0;
							c201 < c202 + 256;
							c201 += 128, c201_p_0 += 128){
							// y = ph_y, x = 34, h = 1, w = 1, c = 128, f = 64
							// T (x, 34) (34 / 1)
							for (x = x268, xp_2 = x268_p_1, xp_1 = x268_p_0, xp_0 = 0;
								x < x268 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3436 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3437 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3438 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_3439 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_3440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_3443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_3444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_3447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_3448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_3451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_3452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_3455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_3456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_3459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_3460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_3463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
										// T (c, 128) (128 / 1)
										for (c = c201, cp_1 = c201_p_0, cp_0 = 0;
											c < c201 + 128;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3436);
											mem_vec_3436 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3437);
											mem_vec_3437 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3438);
											mem_vec_3438 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3439);
											mem_vec_3439 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3440);
											mem_vec_3440 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3441);
											mem_vec_3441 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3442);
											mem_vec_3442 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3443);
											mem_vec_3443 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3444);
											mem_vec_3444 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3445);
											mem_vec_3445 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3446);
											mem_vec_3446 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3447);
											mem_vec_3447 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3448);
											mem_vec_3448 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3449);
											mem_vec_3449 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3450);
											mem_vec_3450 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3451);
											mem_vec_3451 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3452);
											mem_vec_3452 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3453);
											mem_vec_3453 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3454);
											mem_vec_3454 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3455);
											mem_vec_3455 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3456);
											mem_vec_3456 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3457);
											mem_vec_3457 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_3458);
											mem_vec_3458 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_3459);
											mem_vec_3459 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_3460);
											mem_vec_3460 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_3461);
											mem_vec_3461 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_3462);
											mem_vec_3462 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_3463);
											mem_vec_3463 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3436);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3437);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3438);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3439);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3440);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3441);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3442);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3443);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3444);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3445);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3446);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3447);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3448);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3449);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3450);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3451);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3452);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3453);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_3454);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_3455);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3456);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3457);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_3458);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_3459);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3460);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3461);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_3462);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_3463);
							}
						}
					}
				}
			}
		}
	}


}