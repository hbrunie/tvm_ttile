#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (64, c); Hoist_vars [c]; T (4, x); T (1, c);
  T (7, x); T (4, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c49_p_0, cp_1, c49, f, fp_0, f49_p_0, fp_1, f49, x, xp_0, x54_p_0, xp_1, x54, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y36 = 0;
IND_TYPE x55 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c50 = 0;
IND_TYPE f50 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_504 ,mem_vec_505 ,mem_vec_506 ,mem_vec_507 ,mem_vec_508 ,mem_vec_509 ,mem_vec_510 ,mem_vec_511 ,mem_vec_512 ,mem_vec_513 ,mem_vec_514 ,mem_vec_515 ,mem_vec_516 ,mem_vec_517 ,mem_vec_518 ,mem_vec_519 ,mem_vec_520 ,mem_vec_521 ,mem_vec_522 ,mem_vec_523 ,mem_vec_524 ,mem_vec_525 ,mem_vec_526 ,mem_vec_527 ,mem_vec_528 ,mem_vec_529 ,mem_vec_530 ,mem_vec_531 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f49 = f50, f49_p_0 = 0;
	f49 < f50 + 128;
	f49 += 64, f49_p_0 += 64){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
	// T (f, 1) (64 / 64)
	for (f = f49, fp_1 = f49_p_0, fp_0 = 0;
		f < f49 + 64;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 4) (28 / 7)
		for (y = y36, yp_0 = 0;
			y < y36 + 28;
			y += 7, yp_0 += 7){
			// y = 7, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 7) (28 / 4)
			for (x54 = x55, x54_p_0 = 0;
				x54 < x55 + 28;
				x54 += 4, x54_p_0 += 4){
				// y = 7, x = 4, h = 1, w = 1, c = 64, f = 64
				// T (c, 1) (64 / 64)
				for (c49 = c50, c49_p_0 = 0;
					c49 < c50 + 64;
					c49 += 64, c49_p_0 += 64){
					// y = 7, x = 4, h = 1, w = 1, c = 64, f = 64
					// T (x, 4) (4 / 1)
					for (x = x54, xp_1 = x54_p_0, xp_0 = 0;
						x < x54 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_504 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_505 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_506 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_507 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_512 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_522 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_523 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_524 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_525 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_526 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_527 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								mem_vec_528 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_529 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
								mem_vec_531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
								// y = 7, x = 1, h = 1, w = 1, c = 64, f = 64
								// T (c, 64) (64 / 1)
								for (c = c49, cp_1 = c49_p_0, cp_0 = 0;
									c < c49 + 64;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_504);
									mem_vec_504 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_505);
									mem_vec_505 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_506);
									mem_vec_506 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_507);
									mem_vec_507 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_508);
									mem_vec_508 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_509);
									mem_vec_509 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_510);
									mem_vec_510 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_511);
									mem_vec_511 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_512);
									mem_vec_512 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_513);
									mem_vec_513 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_514);
									mem_vec_514 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_515);
									mem_vec_515 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_516);
									mem_vec_516 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_517);
									mem_vec_517 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_518);
									mem_vec_518 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_519);
									mem_vec_519 = vec_23;
									scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_520);
									mem_vec_520 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_521);
									mem_vec_521 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_522);
									mem_vec_522 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_523);
									mem_vec_523 = vec_28;
									scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_524);
									mem_vec_524 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_525);
									mem_vec_525 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_526);
									mem_vec_526 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_527);
									mem_vec_527 = vec_33;
									scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
									vec_35 = _mm512_set1_ps(scal_6);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_528);
									mem_vec_528 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_529);
									mem_vec_529 = vec_36;



									vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_530);
									mem_vec_530 = vec_37;



									vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_531);
									mem_vec_531 = vec_38;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_504);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_505);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_506);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_507);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_508);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_509);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_510);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_511);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_512);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_513);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_514);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_515);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_516);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_517);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_518);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_519);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_520);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_521);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_522);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_523);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_524);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_525);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_526);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_527);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_528);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_529);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_530);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_531);
					}
				}
			}
		}
	}
}


}