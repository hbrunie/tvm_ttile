#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (56, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 5), (Arg 12)); ((Iter 4), (Arg 13))]; T (32, c);
  T (1, x)]
*/
IND_TYPE c, cp_0, c678_p_0, cp_1, c678, h, hp_0, w, wp_0, x, xp_0, x904_p_0, x905_p_0, xp_1, x904_p_1, xp_2, x904, x905, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y452 = 0;
IND_TYPE x906 = 0;
IND_TYPE h432 = 0;
IND_TYPE w452 = 0;
IND_TYPE c679 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8312 ,mem_vec_8313 ,mem_vec_8314 ,mem_vec_8315 ,mem_vec_8316 ,mem_vec_8317 ,mem_vec_8318 ,mem_vec_8319 ,mem_vec_8320 ,mem_vec_8321 ,mem_vec_8322 ,mem_vec_8323 ,mem_vec_8324 ,mem_vec_8325 ,mem_vec_8326 ,mem_vec_8327 ,mem_vec_8328 ,mem_vec_8329 ,mem_vec_8330 ,mem_vec_8331 ,mem_vec_8332 ,mem_vec_8333 ,mem_vec_8334 ,mem_vec_8335 ,mem_vec_8336 ,mem_vec_8337 ,mem_vec_8338 ,mem_vec_8339 ,mem_vec_8340 ,mem_vec_8341 ,mem_vec_8342 ,mem_vec_8343 ,mem_vec_8344 ,mem_vec_8345 ,mem_vec_8346 ,mem_vec_8347 ,mem_vec_8348 ,mem_vec_8349 ,mem_vec_8350 ,mem_vec_8351 ,mem_vec_8352 ,mem_vec_8353 ,mem_vec_8354 ,mem_vec_8355 ,mem_vec_8356 ,mem_vec_8357 ,mem_vec_8358 ,mem_vec_8359 ,mem_vec_8360 ,mem_vec_8361 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 1) (112 / 112)
for (x905 = x906, x905_p_0 = 0;
	x905 < x906 + 112;
	x905 += 112, x905_p_0 += 112){
	// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
	// T (c, 32) (32 / 1)
	for (c678 = c679, c678_p_0 = 0;
		c678 < c679 + 32;
		c678 += 1, c678_p_0 += 1){
			for (y = y452, yp_0 = 0;
				y < y452 + 60;
				y += 12, yp_0 += 12){
				// y = ph_y, x = 112, h = 3, w = 3, c = 1, f = 32
				// T (x, 2) (112 / 56)
				for (x904 = x905, x904_p_1 = x905_p_0, x904_p_0 = 0;
					x904 < x905 + 112;
					x904 += 56, x904_p_1 += 56, x904_p_0 += 56){
					// y = ph_y, x = 56, h = 3, w = 3, c = 1, f = 32
					// T (h, 3) (3 / 1)
					for (h = h432, hp_0 = 0;
						h < h432 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 56, h = 1, w = 3, c = 1, f = 32
						// T (w, 3) (3 / 1)
						for (w = w452, wp_0 = 0;
							w < w452 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 56, h = 1, w = 1, c = 1, f = 32
							// T (x, 56) (56 / 1)
							for (x = x904, xp_2 = x904_p_1, xp_1 = x904_p_0, xp_0 = 0;
								x < x904 + 56;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8312 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8313 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_8324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_8326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_8328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_8330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_8332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_8333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_8334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_8335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
										// T (c, 1) (1 / 1)
										for (c = c678, cp_1 = c678_p_0, cp_0 = 0;
											c < c678 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8312);
											mem_vec_8312 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8313);
											mem_vec_8313 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8314);
											mem_vec_8314 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8315);
											mem_vec_8315 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8316);
											mem_vec_8316 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8317);
											mem_vec_8317 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8318);
											mem_vec_8318 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8319);
											mem_vec_8319 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8320);
											mem_vec_8320 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8321);
											mem_vec_8321 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8322);
											mem_vec_8322 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8323);
											mem_vec_8323 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8324);
											mem_vec_8324 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8325);
											mem_vec_8325 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8326);
											mem_vec_8326 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8327);
											mem_vec_8327 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8328);
											mem_vec_8328 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8329);
											mem_vec_8329 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8330);
											mem_vec_8330 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8331);
											mem_vec_8331 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8332);
											mem_vec_8332 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8333);
											mem_vec_8333 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8334);
											mem_vec_8334 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8335);
											mem_vec_8335 = vec_37;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8312);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8313);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8314);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8315);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8316);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8317);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8318);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8319);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8320);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8321);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8322);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8323);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8324);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8325);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8326);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8327);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8328);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8329);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8330);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8331);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8332);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8333);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8334);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8335);
							}
						}
					}
				}
			}
			for (y = y452 + 60, yp_0 = 0;
				y < y452 + 60 + 52;
				y += 13, yp_0 += 13){
				// y = ph_y, x = 112, h = 3, w = 3, c = 1, f = 32
				// T (x, 2) (112 / 56)
				for (x904 = x905, x904_p_1 = x905_p_0, x904_p_0 = 0;
					x904 < x905 + 112;
					x904 += 56, x904_p_1 += 56, x904_p_0 += 56){
					// y = ph_y, x = 56, h = 3, w = 3, c = 1, f = 32
					// T (h, 3) (3 / 1)
					for (h = h432, hp_0 = 0;
						h < h432 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 56, h = 1, w = 3, c = 1, f = 32
						// T (w, 3) (3 / 1)
						for (w = w452, wp_0 = 0;
							w < w452 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 56, h = 1, w = 1, c = 1, f = 32
							// T (x, 56) (56 / 1)
							for (x = x904, xp_2 = x904_p_1, xp_1 = x904_p_0, xp_0 = 0;
								x < x904 + 56;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8336 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8337 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_8348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_8350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_8351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_8352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_8353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_8354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_8355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_8356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_8357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_8358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_8359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_8360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_8361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
										// T (c, 1) (1 / 1)
										for (c = c678, cp_1 = c678_p_0, cp_0 = 0;
											c < c678 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8336);
											mem_vec_8336 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8337);
											mem_vec_8337 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8338);
											mem_vec_8338 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8339);
											mem_vec_8339 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8340);
											mem_vec_8340 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8341);
											mem_vec_8341 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8342);
											mem_vec_8342 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8343);
											mem_vec_8343 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8344);
											mem_vec_8344 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8345);
											mem_vec_8345 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8346);
											mem_vec_8346 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8347);
											mem_vec_8347 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8348);
											mem_vec_8348 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8349);
											mem_vec_8349 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8350);
											mem_vec_8350 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8351);
											mem_vec_8351 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8352);
											mem_vec_8352 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8353);
											mem_vec_8353 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8354);
											mem_vec_8354 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8355);
											mem_vec_8355 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8356);
											mem_vec_8356 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8357);
											mem_vec_8357 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8358);
											mem_vec_8358 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8359);
											mem_vec_8359 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8360);
											mem_vec_8360 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8361);
											mem_vec_8361 = vec_40;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8336);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8337);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8338);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8339);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8340);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8341);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8342);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8343);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8344);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8345);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8346);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8347);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8348);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8349);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8350);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8351);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8352);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8353);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8354);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8355);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8356);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8357);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8358);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8359);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_8360);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_8361);
							}
						}
					}
				}
			}
	}
}


}