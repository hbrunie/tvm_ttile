#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (17, x); T (1024, c);
  T (1, y); T (16, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]]
*/
IND_TYPE c, cp_0, c45_p_0, cp_1, c45, f, fp_0, x, xp_0, y, yp_0, y45_p_0, yp_1, y45;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y46 = 0;
IND_TYPE x30 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c46 = 0;
IND_TYPE f30 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_510 ,mem_vec_511 ,mem_vec_512 ,mem_vec_513 ,mem_vec_514 ,mem_vec_515 ,mem_vec_516 ,mem_vec_517 ,mem_vec_518 ,mem_vec_519 ,mem_vec_520 ,mem_vec_521 ,mem_vec_522 ,mem_vec_523 ,mem_vec_524 ,mem_vec_525 ,mem_vec_526 ,mem_vec_527 ,mem_vec_528 ,mem_vec_529 ,mem_vec_530 ,mem_vec_531 ,mem_vec_532 ,mem_vec_533 ,mem_vec_534 ,mem_vec_535 ,mem_vec_536 ,mem_vec_537 ,mem_vec_538 ,mem_vec_539 ,mem_vec_540 ,mem_vec_541 ,mem_vec_542 ,mem_vec_543 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y45 = y46, y45_p_0 = 0;
		y45 < y46 + 8;
		y45 += 8, y45_p_0 += 8){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (f, 16) (512 / 32)
		for (f = f30, fp_0 = 0;
			f < f30 + 512;
			f += 32, fp_0 += 32){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y45, yp_1 = y45_p_0, yp_0 = 0;
				y < y45 + 8;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 1024) (1024 / 1)
				for (c45 = c46, c45_p_0 = 0;
					c45 < c46 + 1024;
					c45 += 1, c45_p_0 += 1){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1, f = 32
					// T (x, 17) (17 / 1)
					for (x = x30, xp_0 = 0;
						x < x30 + 17;
						x += 1, xp_0 += 1){
								mem_vec_510 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_511 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_512 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_522 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_523 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_524 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_525 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
								// T (c, 1) (1 / 1)
								for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
									c < c45 + 1;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_510);
									mem_vec_510 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_511);
									mem_vec_511 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_512);
									mem_vec_512 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_513);
									mem_vec_513 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_514);
									mem_vec_514 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_515);
									mem_vec_515 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_516);
									mem_vec_516 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_517);
									mem_vec_517 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_518);
									mem_vec_518 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_519);
									mem_vec_519 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_520);
									mem_vec_520 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_521);
									mem_vec_521 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_522);
									mem_vec_522 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_523);
									mem_vec_523 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_524);
									mem_vec_524 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_525);
									mem_vec_525 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_510);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_511);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_512);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_513);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_514);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_515);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_516);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_517);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_518);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_519);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_520);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_521);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_522);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_523);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_524);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_525);
					}
				}
			}
		}
	}
	for (y45 = y46 + 8, y45_p_0 = 0;
		y45 < y46 + 8 + 9;
		y45 += 9, y45_p_0 += 9){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (f, 16) (512 / 32)
		for (f = f30, fp_0 = 0;
			f < f30 + 512;
			f += 32, fp_0 += 32){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y45, yp_1 = y45_p_0, yp_0 = 0;
				y < y45 + 9;
				y += 9, yp_1 += 9, yp_0 += 9){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 1024) (1024 / 1)
				for (c45 = c46, c45_p_0 = 0;
					c45 < c46 + 1024;
					c45 += 1, c45_p_0 += 1){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1, f = 32
					// T (x, 17) (17 / 1)
					for (x = x30, xp_0 = 0;
						x < x30 + 17;
						x += 1, xp_0 += 1){
								mem_vec_526 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_527 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_528 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_529 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_532 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_533 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_534 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_535 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_536 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_537 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_542 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_543 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
								// T (c, 1) (1 / 1)
								for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
									c < c45 + 1;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_526);
									mem_vec_526 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_527);
									mem_vec_527 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_528);
									mem_vec_528 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_529);
									mem_vec_529 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_530);
									mem_vec_530 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_531);
									mem_vec_531 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_532);
									mem_vec_532 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_533);
									mem_vec_533 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_534);
									mem_vec_534 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_535);
									mem_vec_535 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_536);
									mem_vec_536 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_537);
									mem_vec_537 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_538);
									mem_vec_538 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_539);
									mem_vec_539 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_540);
									mem_vec_540 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_541);
									mem_vec_541 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_542);
									mem_vec_542 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_543);
									mem_vec_543 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_526);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_527);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_528);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_529);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_530);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_531);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_532);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_533);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_534);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_535);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_536);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_537);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_538);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_539);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_540);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_541);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_542);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_543);
					}
				}
			}
		}
	}


}