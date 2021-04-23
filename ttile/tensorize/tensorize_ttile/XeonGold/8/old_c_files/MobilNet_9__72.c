#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (7, x); T (8, c); T (1, y); T (16, f); T (2, c); T (4, c)]
*/
IND_TYPE c, cp_0, c605_p_0, c606_p_0, c607_p_0, cp_1, c605_p_1, c606_p_1, cp_2, c605_p_2, cp_3, c605, c606, c607, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y242 = 0;
IND_TYPE x242 = 0;
IND_TYPE h203 = 0;
IND_TYPE w206 = 0;
IND_TYPE c608 = 0;
IND_TYPE f242 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_3388 ,mem_vec_3389 ,mem_vec_3390 ,mem_vec_3391 ,mem_vec_3392 ,mem_vec_3393 ,mem_vec_3394 ,mem_vec_3395 ,mem_vec_3396 ,mem_vec_3397 ,mem_vec_3398 ,mem_vec_3399 ,mem_vec_3400 ,mem_vec_3401 ,mem_vec_3402 ,mem_vec_3403 ,mem_vec_3404 ,mem_vec_3405 ,mem_vec_3406 ,mem_vec_3407 ,mem_vec_3408 ,mem_vec_3409 ,mem_vec_3410 ,mem_vec_3411 ,mem_vec_3412 ,mem_vec_3413 ,mem_vec_3414 ,mem_vec_3415 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 4) (1024 / 256)
for (c607 = c608, c607_p_0 = 0;
	c607 < c608 + 1024;
	c607 += 256, c607_p_0 += 256){
	// y = 7, x = 7, h = 3, w = 3, c = 256, f = 1024
	// T (c, 2) (256 / 128)
	for (c606 = c607, c606_p_1 = c607_p_0, c606_p_0 = 0;
		c606 < c607 + 256;
		c606 += 128, c606_p_1 += 128, c606_p_0 += 128){
		// y = 7, x = 7, h = 3, w = 3, c = 128, f = 1024
		// T (f, 16) (1024 / 64)
		for (f = f242, fp_0 = 0;
			f < f242 + 1024;
			f += 64, fp_0 += 64){
			// y = 7, x = 7, h = 3, w = 3, c = 128, f = 64
			// T (y, 1) (7 / 7)
			for (y = y242, yp_0 = 0;
				y < y242 + 7;
				y += 7, yp_0 += 7){
				// y = 7, x = 7, h = 3, w = 3, c = 128, f = 64
				// T (c, 8) (128 / 16)
				for (c605 = c606, c605_p_2 = c606_p_1, c605_p_1 = c606_p_0, c605_p_0 = 0;
					c605 < c606 + 128;
					c605 += 16, c605_p_2 += 16, c605_p_1 += 16, c605_p_0 += 16){
					// y = 7, x = 7, h = 3, w = 3, c = 16, f = 64
					// T (x, 7) (7 / 1)
					for (x = x242, xp_0 = 0;
						x < x242 + 7;
						x += 1, xp_0 += 1){
						// y = 7, x = 1, h = 3, w = 3, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h203, hp_0 = 0;
							h < h203 + 3;
							h += 1, hp_0 += 1){
							// y = 7, x = 1, h = 1, w = 3, c = 16, f = 64
							// T (w, 3) (3 / 1)
							for (w = w206, wp_0 = 0;
								w < w206 + 3;
								w += 1, wp_0 += 1){
										mem_vec_3388 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3389 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3390 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_3391 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_3392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_3395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_3396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_3399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_3400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_3403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_3404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_3407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_3408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_3411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_3412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_3415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c605, cp_3 = c605_p_2, cp_2 = c605_p_1, cp_1 = c605_p_0, cp_0 = 0;
											c < c605 + 16;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3388);
											mem_vec_3388 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3389);
											mem_vec_3389 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3390);
											mem_vec_3390 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3391);
											mem_vec_3391 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3392);
											mem_vec_3392 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3393);
											mem_vec_3393 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3394);
											mem_vec_3394 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3395);
											mem_vec_3395 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3396);
											mem_vec_3396 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3397);
											mem_vec_3397 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3398);
											mem_vec_3398 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3399);
											mem_vec_3399 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3400);
											mem_vec_3400 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3401);
											mem_vec_3401 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3402);
											mem_vec_3402 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3403);
											mem_vec_3403 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3404);
											mem_vec_3404 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3405);
											mem_vec_3405 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3406);
											mem_vec_3406 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3407);
											mem_vec_3407 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3408);
											mem_vec_3408 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3409);
											mem_vec_3409 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_3410);
											mem_vec_3410 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_3411);
											mem_vec_3411 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_3412);
											mem_vec_3412 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_3413);
											mem_vec_3413 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_3414);
											mem_vec_3414 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_3415);
											mem_vec_3415 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3388);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3389);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3390);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3391);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3392);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3393);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3394);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3395);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3396);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3397);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3398);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3399);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3400);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3401);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3402);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3403);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3404);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3405);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_3406);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_3407);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3408);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3409);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_3410);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_3411);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3412);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3413);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_3414);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_3415);
							}
						}
					}
				}
			}
		}
	}
}


}