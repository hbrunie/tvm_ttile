#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (17, x); T (256, c);
  T (1, y); T (16, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]]
*/
IND_TYPE c, cp_0, c39_p_0, cp_1, c39, f, fp_0, x, xp_0, y, yp_0, y39_p_0, yp_1, y39;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y40 = 0;
IND_TYPE x26 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c40 = 0;
IND_TYPE f26 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_442 ,mem_vec_443 ,mem_vec_444 ,mem_vec_445 ,mem_vec_446 ,mem_vec_447 ,mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,mem_vec_453 ,mem_vec_454 ,mem_vec_455 ,mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,mem_vec_464 ,mem_vec_465 ,mem_vec_466 ,mem_vec_467 ,mem_vec_468 ,mem_vec_469 ,mem_vec_470 ,mem_vec_471 ,mem_vec_472 ,mem_vec_473 ,mem_vec_474 ,mem_vec_475 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y39 = y40, y39_p_0 = 0;
		y39 < y40 + 8;
		y39 += 8, y39_p_0 += 8){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (f, 16) (512 / 32)
		for (f = f26, fp_0 = 0;
			f < f26 + 512;
			f += 32, fp_0 += 32){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y39, yp_1 = y39_p_0, yp_0 = 0;
				y < y39 + 8;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 256) (1024 / 4)
				for (c39 = c40, c39_p_0 = 0;
					c39 < c40 + 1024;
					c39 += 4, c39_p_0 += 4){
					// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
					// T (x, 17) (17 / 1)
					for (x = x26, xp_0 = 0;
						x < x26 + 17;
						x += 1, xp_0 += 1){
								mem_vec_442 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_443 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
								// T (c, 4) (4 / 1)
								for (c = c39, cp_1 = c39_p_0, cp_0 = 0;
									c < c39 + 4;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_442);
									mem_vec_442 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_443);
									mem_vec_443 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_444);
									mem_vec_444 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_445);
									mem_vec_445 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_446);
									mem_vec_446 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_447);
									mem_vec_447 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_448);
									mem_vec_448 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_449);
									mem_vec_449 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_450);
									mem_vec_450 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_451);
									mem_vec_451 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_452);
									mem_vec_452 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_453);
									mem_vec_453 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_454);
									mem_vec_454 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_455);
									mem_vec_455 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_456);
									mem_vec_456 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_457);
									mem_vec_457 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_442);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_443);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_444);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_445);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_446);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_447);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_448);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_449);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_450);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_451);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_452);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_453);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_454);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_455);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_456);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_457);
					}
				}
			}
		}
	}
	for (y39 = y40 + 8, y39_p_0 = 0;
		y39 < y40 + 8 + 9;
		y39 += 9, y39_p_0 += 9){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (f, 16) (512 / 32)
		for (f = f26, fp_0 = 0;
			f < f26 + 512;
			f += 32, fp_0 += 32){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y39, yp_1 = y39_p_0, yp_0 = 0;
				y < y39 + 9;
				y += 9, yp_1 += 9, yp_0 += 9){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 256) (1024 / 4)
				for (c39 = c40, c39_p_0 = 0;
					c39 < c40 + 1024;
					c39 += 4, c39_p_0 += 4){
					// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
					// T (x, 17) (17 / 1)
					for (x = x26, xp_0 = 0;
						x < x26 + 17;
						x += 1, xp_0 += 1){
								mem_vec_458 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_459 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
								// T (c, 4) (4 / 1)
								for (c = c39, cp_1 = c39_p_0, cp_0 = 0;
									c < c39 + 4;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_458);
									mem_vec_458 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_459);
									mem_vec_459 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_460);
									mem_vec_460 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_461);
									mem_vec_461 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_462);
									mem_vec_462 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_463);
									mem_vec_463 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_464);
									mem_vec_464 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_465);
									mem_vec_465 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_466);
									mem_vec_466 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_467);
									mem_vec_467 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_468);
									mem_vec_468 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_469);
									mem_vec_469 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_470);
									mem_vec_470 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_471);
									mem_vec_471 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_472);
									mem_vec_472 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_473);
									mem_vec_473 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_474);
									mem_vec_474 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_475);
									mem_vec_475 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_458);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_459);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_460);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_461);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_462);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_463);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_464);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_465);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_466);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_467);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_468);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_469);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_470);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_471);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_472);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_473);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_474);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_475);
					}
				}
			}
		}
	}


}