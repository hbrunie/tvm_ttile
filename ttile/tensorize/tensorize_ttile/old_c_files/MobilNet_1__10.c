#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 9), (Arg 10)); ((Iter 2), (Arg 11))]; T (16, c);
  T (7, x)]
*/
IND_TYPE c, cp_0, c492_p_0, cp_1, c492, h, hp_0, w, wp_0, x, xp_0, x656_p_0, x657_p_0, xp_1, x656_p_1, xp_2, x656, x657, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y328 = 0;
IND_TYPE x658 = 0;
IND_TYPE h308 = 0;
IND_TYPE w328 = 0;
IND_TYPE c493 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5380 ,mem_vec_5381 ,mem_vec_5382 ,mem_vec_5383 ,mem_vec_5384 ,mem_vec_5385 ,mem_vec_5386 ,mem_vec_5387 ,mem_vec_5388 ,mem_vec_5389 ,mem_vec_5390 ,mem_vec_5391 ,mem_vec_5392 ,mem_vec_5393 ,mem_vec_5394 ,mem_vec_5395 ,mem_vec_5396 ,mem_vec_5397 ,mem_vec_5398 ,mem_vec_5399 ,mem_vec_5400 ,mem_vec_5401 ,mem_vec_5402 ,mem_vec_5403 ,mem_vec_5404 ,mem_vec_5405 ,mem_vec_5406 ,mem_vec_5407 ,mem_vec_5408 ,mem_vec_5409 ,mem_vec_5410 ,mem_vec_5411 ,mem_vec_5412 ,mem_vec_5413 ,mem_vec_5414 ,mem_vec_5415 ,mem_vec_5416 ,mem_vec_5417 ,mem_vec_5418 ,mem_vec_5419 ,mem_vec_5420 ,mem_vec_5421 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 7) (112 / 16)
for (x657 = x658, x657_p_0 = 0;
	x657 < x658 + 112;
	x657 += 16, x657_p_0 += 16){
	// y = 112, x = 16, h = 3, w = 3, c = 32, f = 32
	// T (c, 16) (32 / 2)
	for (c492 = c493, c492_p_0 = 0;
		c492 < c493 + 32;
		c492 += 2, c492_p_0 += 2){
			for (y = y328, yp_0 = 0;
				y < y328 + 90;
				y += 10, yp_0 += 10){
				// y = ph_y, x = 16, h = 3, w = 3, c = 2, f = 32
				// T (x, 2) (16 / 8)
				for (x656 = x657, x656_p_1 = x657_p_0, x656_p_0 = 0;
					x656 < x657 + 16;
					x656 += 8, x656_p_1 += 8, x656_p_0 += 8){
					// y = ph_y, x = 8, h = 3, w = 3, c = 2, f = 32
					// T (h, 3) (3 / 1)
					for (h = h308, hp_0 = 0;
						h < h308 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w328, wp_0 = 0;
							w < w328 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 2, f = 32
							// T (x, 8) (8 / 1)
							for (x = x656, xp_2 = x656_p_1, xp_1 = x656_p_0, xp_0 = 0;
								x < x656 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5380 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5381 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_5393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_5394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_5395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_5396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_5397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_5398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_5399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c492, cp_1 = c492_p_0, cp_0 = 0;
											c < c492 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5380);
											mem_vec_5380 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5381);
											mem_vec_5381 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5382);
											mem_vec_5382 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5383);
											mem_vec_5383 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5384);
											mem_vec_5384 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5385);
											mem_vec_5385 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5386);
											mem_vec_5386 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5387);
											mem_vec_5387 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5388);
											mem_vec_5388 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5389);
											mem_vec_5389 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5390);
											mem_vec_5390 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5391);
											mem_vec_5391 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5392);
											mem_vec_5392 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5393);
											mem_vec_5393 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5394);
											mem_vec_5394 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5395);
											mem_vec_5395 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5396);
											mem_vec_5396 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5397);
											mem_vec_5397 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5398);
											mem_vec_5398 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5399);
											mem_vec_5399 = vec_31;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5380);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5381);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5382);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5383);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5384);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5385);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5386);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5387);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5388);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5389);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5390);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5391);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5392);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5393);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5394);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5395);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5396);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5397);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5398);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5399);
							}
						}
					}
				}
			}
			for (y = y328 + 90, yp_0 = 0;
				y < y328 + 90 + 22;
				y += 11, yp_0 += 11){
				// y = ph_y, x = 16, h = 3, w = 3, c = 2, f = 32
				// T (x, 2) (16 / 8)
				for (x656 = x657, x656_p_1 = x657_p_0, x656_p_0 = 0;
					x656 < x657 + 16;
					x656 += 8, x656_p_1 += 8, x656_p_0 += 8){
					// y = ph_y, x = 8, h = 3, w = 3, c = 2, f = 32
					// T (h, 3) (3 / 1)
					for (h = h308, hp_0 = 0;
						h < h308 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w328, wp_0 = 0;
							w < w328 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 2, f = 32
							// T (x, 8) (8 / 1)
							for (x = x656, xp_2 = x656_p_1, xp_1 = x656_p_0, xp_0 = 0;
								x < x656 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5400 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5401 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_5413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_5414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_5415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_5416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_5417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_5418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_5419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_5420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_5421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c492, cp_1 = c492_p_0, cp_0 = 0;
											c < c492 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5400);
											mem_vec_5400 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5401);
											mem_vec_5401 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5402);
											mem_vec_5402 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5403);
											mem_vec_5403 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5404);
											mem_vec_5404 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5405);
											mem_vec_5405 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5406);
											mem_vec_5406 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5407);
											mem_vec_5407 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5408);
											mem_vec_5408 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5409);
											mem_vec_5409 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5410);
											mem_vec_5410 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5411);
											mem_vec_5411 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5412);
											mem_vec_5412 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5413);
											mem_vec_5413 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5414);
											mem_vec_5414 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5415);
											mem_vec_5415 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5416);
											mem_vec_5416 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5417);
											mem_vec_5417 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5418);
											mem_vec_5418 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5419);
											mem_vec_5419 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5420);
											mem_vec_5420 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5421);
											mem_vec_5421 = vec_34;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5400);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5401);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5402);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5403);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5404);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5405);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5406);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5407);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5408);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5409);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5410);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5411);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5412);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5413);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5414);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5415);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5416);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5417);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5418);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5419);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5420);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_5421);
							}
						}
					}
				}
			}
	}
}


}