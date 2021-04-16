#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (256, c); Hoist_vars [c]; T (7, x); T (1, c);
  T (2, f); T (1, y); T (4, f)]
*/
IND_TYPE c, cp_0, c48_p_0, cp_1, c48, f, fp_0, f47_p_0, fp_1, f47, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 512));
IND_TYPE y31 = 0;
IND_TYPE x33 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c49 = 0;
IND_TYPE f48 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_434 ,mem_vec_435 ,mem_vec_436 ,mem_vec_437 ,mem_vec_438 ,mem_vec_439 ,mem_vec_440 ,mem_vec_441 ,mem_vec_442 ,mem_vec_443 ,mem_vec_444 ,mem_vec_445 ,mem_vec_446 ,mem_vec_447 ,mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,mem_vec_453 ,mem_vec_454 ,mem_vec_455 ,mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 1, w = 1, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f47 = f48, f47_p_0 = 0;
	f47 < f48 + 512;
	f47 += 128, f47_p_0 += 128){
	// y = 7, x = 7, h = 1, w = 1, c = 256, f = 128
	// T (y, 1) (7 / 7)
	for (y = y31, yp_0 = 0;
		y < y31 + 7;
		y += 7, yp_0 += 7){
		// y = 7, x = 7, h = 1, w = 1, c = 256, f = 128
		// T (f, 2) (128 / 64)
		for (f = f47, fp_1 = f47_p_0, fp_0 = 0;
			f < f47 + 128;
			f += 64, fp_1 += 64, fp_0 += 64){
			// y = 7, x = 7, h = 1, w = 1, c = 256, f = 64
			// T (c, 1) (256 / 256)
			for (c48 = c49, c48_p_0 = 0;
				c48 < c49 + 256;
				c48 += 256, c48_p_0 += 256){
				// y = 7, x = 7, h = 1, w = 1, c = 256, f = 64
				// T (x, 7) (7 / 1)
				for (x = x33, xp_0 = 0;
					x < x33 + 7;
					x += 1, xp_0 += 1){
							mem_vec_434 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_435 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_436 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
							mem_vec_437 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
							mem_vec_438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
							mem_vec_441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
							mem_vec_442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
							mem_vec_445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
							mem_vec_446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
							mem_vec_449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
							mem_vec_450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
							mem_vec_451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
							mem_vec_452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
							mem_vec_453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
							mem_vec_454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
							mem_vec_455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
							mem_vec_456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
							mem_vec_457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
							mem_vec_458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
							mem_vec_459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
							mem_vec_460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
							mem_vec_461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
							// y = 7, x = 1, h = 1, w = 1, c = 256, f = 64
							// T (c, 256) (256 / 1)
							for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
								c < c48 + 256;
								c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_434);
								mem_vec_434 = vec_0;

								vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_435);
								mem_vec_435 = vec_3;

								vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

								vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_436);
								mem_vec_436 = vec_5;

								vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

								vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_437);
								mem_vec_437 = vec_7;
								scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
								vec_10 = _mm512_set1_ps(scal_1);


								vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_438);
								mem_vec_438 = vec_9;



								vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_439);
								mem_vec_439 = vec_11;



								vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_440);
								mem_vec_440 = vec_12;



								vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_441);
								mem_vec_441 = vec_13;
								scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
								vec_15 = _mm512_set1_ps(scal_2);


								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_442);
								mem_vec_442 = vec_14;



								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_443);
								mem_vec_443 = vec_16;



								vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_444);
								mem_vec_444 = vec_17;



								vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_445);
								mem_vec_445 = vec_18;
								scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
								vec_20 = _mm512_set1_ps(scal_3);


								vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_446);
								mem_vec_446 = vec_19;



								vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_447);
								mem_vec_447 = vec_21;



								vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_448);
								mem_vec_448 = vec_22;



								vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_449);
								mem_vec_449 = vec_23;
								scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
								vec_25 = _mm512_set1_ps(scal_4);


								vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_450);
								mem_vec_450 = vec_24;



								vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_451);
								mem_vec_451 = vec_26;



								vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_452);
								mem_vec_452 = vec_27;



								vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_453);
								mem_vec_453 = vec_28;
								scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
								vec_30 = _mm512_set1_ps(scal_5);


								vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_454);
								mem_vec_454 = vec_29;



								vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_455);
								mem_vec_455 = vec_31;



								vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_456);
								mem_vec_456 = vec_32;



								vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_457);
								mem_vec_457 = vec_33;
								scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
								vec_35 = _mm512_set1_ps(scal_6);


								vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_458);
								mem_vec_458 = vec_34;



								vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_459);
								mem_vec_459 = vec_36;



								vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_460);
								mem_vec_460 = vec_37;



								vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_461);
								mem_vec_461 = vec_38;
							}
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_434);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_435);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_436);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_437);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_438);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_439);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_440);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_441);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_442);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_443);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_444);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_445);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_446);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_447);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_448);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_449);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_450);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_451);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_452);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_453);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_454);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_455);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_456);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_457);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_458);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_459);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_460);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_461);
				}
			}
		}
	}
}


}