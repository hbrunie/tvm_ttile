#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (512, c); Hoist_vars [c]; T (34, x); T (1, c);
  T (1, x); T (1, y); T (8, f); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]]
*/
IND_TYPE c, cp_0, c303_p_0, cp_1, c303, f, fp_0, x, xp_0, x404_p_0, x405_p_0, xp_1, x404_p_1, xp_2, x404, x405, y, yp_0, y295_p_0, yp_1, y295;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y296 = 0;
IND_TYPE x406 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c304 = 0;
IND_TYPE f202 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4372 ,mem_vec_4373 ,mem_vec_4374 ,mem_vec_4375 ,mem_vec_4376 ,mem_vec_4377 ,mem_vec_4378 ,mem_vec_4379 ,mem_vec_4380 ,mem_vec_4381 ,mem_vec_4382 ,mem_vec_4383 ,mem_vec_4384 ,mem_vec_4385 ,mem_vec_4386 ,mem_vec_4387 ,mem_vec_4388 ,mem_vec_4389 ,mem_vec_4390 ,mem_vec_4391 ,mem_vec_4392 ,mem_vec_4393 ,mem_vec_4394 ,mem_vec_4395 ,mem_vec_4396 ,mem_vec_4397 ,mem_vec_4398 ,mem_vec_4399 ,mem_vec_4400 ,mem_vec_4401 ,mem_vec_4402 ,mem_vec_4403 ,mem_vec_4404 ,mem_vec_4405 ,mem_vec_4406 ,mem_vec_4407 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y295 = y296, y295_p_0 = 0;
		y295 < y296 + 24;
		y295 += 8, y295_p_0 += 8){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x405 = x406, x405_p_0 = 0;
			x405 < x406 + 34;
			x405 += 34, x405_p_0 += 34){
			// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (f, 8) (256 / 32)
			for (f = f202, fp_0 = 0;
				f < f202 + 256;
				f += 32, fp_0 += 32){
				// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
				// T (y, 1) (ph_y / ph_y)
				for (y = y295, yp_1 = y295_p_0, yp_0 = 0;
					y < y295 + 8;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 1) (34 / 34)
					for (x404 = x405, x404_p_1 = x405_p_0, x404_p_0 = 0;
						x404 < x405 + 34;
						x404 += 34, x404_p_1 += 34, x404_p_0 += 34){
						// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
						// T (c, 1) (512 / 512)
						for (c303 = c304, c303_p_0 = 0;
							c303 < c304 + 512;
							c303 += 512, c303_p_0 += 512){
							// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
							// T (x, 34) (34 / 1)
							for (x = x404, xp_2 = x404_p_1, xp_1 = x404_p_0, xp_0 = 0;
								x < x404 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4372 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4373 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_4387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
										// T (c, 512) (512 / 1)
										for (c = c303, cp_1 = c303_p_0, cp_0 = 0;
											c < c303 + 512;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4372);
											mem_vec_4372 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4373);
											mem_vec_4373 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4374);
											mem_vec_4374 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4375);
											mem_vec_4375 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4376);
											mem_vec_4376 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4377);
											mem_vec_4377 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4378);
											mem_vec_4378 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4379);
											mem_vec_4379 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4380);
											mem_vec_4380 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4381);
											mem_vec_4381 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4382);
											mem_vec_4382 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4383);
											mem_vec_4383 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4384);
											mem_vec_4384 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4385);
											mem_vec_4385 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4386);
											mem_vec_4386 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4387);
											mem_vec_4387 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4372);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4373);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4374);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4375);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4376);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4377);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4378);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4379);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4380);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4381);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4382);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4383);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4384);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4385);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4386);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4387);
							}
						}
					}
				}
			}
		}
	}
	for (y295 = y296 + 24, y295_p_0 = 0;
		y295 < y296 + 24 + 10;
		y295 += 10, y295_p_0 += 10){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x405 = x406, x405_p_0 = 0;
			x405 < x406 + 34;
			x405 += 34, x405_p_0 += 34){
			// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (f, 8) (256 / 32)
			for (f = f202, fp_0 = 0;
				f < f202 + 256;
				f += 32, fp_0 += 32){
				// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
				// T (y, 1) (ph_y / ph_y)
				for (y = y295, yp_1 = y295_p_0, yp_0 = 0;
					y < y295 + 10;
					y += 10, yp_1 += 10, yp_0 += 10){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 1) (34 / 34)
					for (x404 = x405, x404_p_1 = x405_p_0, x404_p_0 = 0;
						x404 < x405 + 34;
						x404 += 34, x404_p_1 += 34, x404_p_0 += 34){
						// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
						// T (c, 1) (512 / 512)
						for (c303 = c304, c303_p_0 = 0;
							c303 < c304 + 512;
							c303 += 512, c303_p_0 += 512){
							// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
							// T (x, 34) (34 / 1)
							for (x = x404, xp_2 = x404_p_1, xp_1 = x404_p_0, xp_0 = 0;
								x < x404 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4388 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4389 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_4403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_4404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_4405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_4406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_4407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
										// T (c, 512) (512 / 1)
										for (c = c303, cp_1 = c303_p_0, cp_0 = 0;
											c < c303 + 512;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4388);
											mem_vec_4388 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4389);
											mem_vec_4389 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4390);
											mem_vec_4390 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4391);
											mem_vec_4391 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4392);
											mem_vec_4392 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4393);
											mem_vec_4393 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4394);
											mem_vec_4394 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4395);
											mem_vec_4395 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4396);
											mem_vec_4396 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4397);
											mem_vec_4397 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4398);
											mem_vec_4398 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4399);
											mem_vec_4399 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4400);
											mem_vec_4400 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4401);
											mem_vec_4401 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4402);
											mem_vec_4402 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4403);
											mem_vec_4403 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4404);
											mem_vec_4404 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4405);
											mem_vec_4405 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4406);
											mem_vec_4406 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4407);
											mem_vec_4407 = vec_31;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4388);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4389);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4390);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4391);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4392);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4393);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4394);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4395);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4396);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4397);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4398);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4399);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4400);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4401);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4402);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4403);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4404);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4405);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4406);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4407);
							}
						}
					}
				}
			}
		}
	}


}