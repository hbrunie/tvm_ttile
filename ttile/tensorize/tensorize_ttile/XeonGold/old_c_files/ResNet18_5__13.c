#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (4, x); T (2, c);
  T (7, x); T (4, y); T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c52_p_0, cp_1, c52, f, fp_0, f52_p_0, fp_1, f52, x, xp_0, x57_p_0, xp_1, x57, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y38 = 0;
IND_TYPE x58 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c53 = 0;
IND_TYPE f53 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_532 ,mem_vec_533 ,mem_vec_534 ,mem_vec_535 ,mem_vec_536 ,mem_vec_537 ,mem_vec_538 ,mem_vec_539 ,mem_vec_540 ,mem_vec_541 ,mem_vec_542 ,mem_vec_543 ,mem_vec_544 ,mem_vec_545 ,mem_vec_546 ,mem_vec_547 ,mem_vec_548 ,mem_vec_549 ,mem_vec_550 ,mem_vec_551 ,mem_vec_552 ,mem_vec_553 ,mem_vec_554 ,mem_vec_555 ,mem_vec_556 ,mem_vec_557 ,mem_vec_558 ,mem_vec_559 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 1) (128 / 128)
for (f52 = f53, f52_p_0 = 0;
	f52 < f53 + 128;
	f52 += 128, f52_p_0 += 128){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
	// T (f, 2) (128 / 64)
	for (f = f52, fp_1 = f52_p_0, fp_0 = 0;
		f < f52 + 128;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 4) (28 / 7)
		for (y = y38, yp_0 = 0;
			y < y38 + 28;
			y += 7, yp_0 += 7){
			// y = 7, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 7) (28 / 4)
			for (x57 = x58, x57_p_0 = 0;
				x57 < x58 + 28;
				x57 += 4, x57_p_0 += 4){
				// y = 7, x = 4, h = 1, w = 1, c = 64, f = 64
				// T (c, 2) (64 / 32)
				for (c52 = c53, c52_p_0 = 0;
					c52 < c53 + 64;
					c52 += 32, c52_p_0 += 32){
					// y = 7, x = 4, h = 1, w = 1, c = 32, f = 64
					// T (x, 4) (4 / 1)
					for (x = x57, xp_1 = x57_p_0, xp_0 = 0;
						x < x57 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_532 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_533 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_534 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_535 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_536 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_537 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_542 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_543 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_544 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_545 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_552 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_553 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								mem_vec_556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
								mem_vec_559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
								// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
								// T (c, 32) (32 / 1)
								for (c = c52, cp_1 = c52_p_0, cp_0 = 0;
									c < c52 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_532);
									mem_vec_532 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_533);
									mem_vec_533 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_534);
									mem_vec_534 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_535);
									mem_vec_535 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_536);
									mem_vec_536 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_537);
									mem_vec_537 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_538);
									mem_vec_538 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_539);
									mem_vec_539 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_540);
									mem_vec_540 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_541);
									mem_vec_541 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_542);
									mem_vec_542 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_543);
									mem_vec_543 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_544);
									mem_vec_544 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_545);
									mem_vec_545 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_546);
									mem_vec_546 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_547);
									mem_vec_547 = vec_23;
									scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_548);
									mem_vec_548 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_549);
									mem_vec_549 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_550);
									mem_vec_550 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_551);
									mem_vec_551 = vec_28;
									scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_552);
									mem_vec_552 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_553);
									mem_vec_553 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_554);
									mem_vec_554 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_555);
									mem_vec_555 = vec_33;
									scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
									vec_35 = _mm512_set1_ps(scal_6);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_556);
									mem_vec_556 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_557);
									mem_vec_557 = vec_36;



									vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_558);
									mem_vec_558 = vec_37;



									vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_559);
									mem_vec_559 = vec_38;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_532);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_533);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_534);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_535);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_536);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_537);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_538);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_539);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_540);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_541);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_542);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_543);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_544);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_545);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_546);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_547);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_548);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_549);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_550);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_551);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_552);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_553);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_554);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_555);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_556);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_557);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_558);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_559);
					}
				}
			}
		}
	}
}


}