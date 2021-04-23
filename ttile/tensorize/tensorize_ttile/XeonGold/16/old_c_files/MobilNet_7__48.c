#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (14, x); T (1, c); T (2, y); T (8, f); T (16, c)]
*/
IND_TYPE c, cp_0, c80_p_0, c81_p_0, cp_1, c80_p_1, cp_2, c80, c81, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y40 = 0;
IND_TYPE x40 = 0;
IND_TYPE h38 = 0;
IND_TYPE w38 = 0;
IND_TYPE c82 = 0;
IND_TYPE f40 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_560 ,mem_vec_561 ,mem_vec_562 ,mem_vec_563 ,mem_vec_564 ,mem_vec_565 ,mem_vec_566 ,mem_vec_567 ,mem_vec_568 ,mem_vec_569 ,mem_vec_570 ,mem_vec_571 ,mem_vec_572 ,mem_vec_573 ,mem_vec_574 ,mem_vec_575 ,mem_vec_576 ,mem_vec_577 ,mem_vec_578 ,mem_vec_579 ,mem_vec_580 ,mem_vec_581 ,mem_vec_582 ,mem_vec_583 ,mem_vec_584 ,mem_vec_585 ,mem_vec_586 ,mem_vec_587 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (c, 16) (512 / 32)
for (c81 = c82, c81_p_0 = 0;
	c81 < c82 + 512;
	c81 += 32, c81_p_0 += 32){
	// y = 14, x = 14, h = 3, w = 3, c = 32, f = 512
	// T (f, 8) (512 / 64)
	for (f = f40, fp_0 = 0;
		f < f40 + 512;
		f += 64, fp_0 += 64){
		// y = 14, x = 14, h = 3, w = 3, c = 32, f = 64
		// T (y, 2) (14 / 7)
		for (y = y40, yp_0 = 0;
			y < y40 + 14;
			y += 7, yp_0 += 7){
			// y = 7, x = 14, h = 3, w = 3, c = 32, f = 64
			// T (c, 1) (32 / 32)
			for (c80 = c81, c80_p_1 = c81_p_0, c80_p_0 = 0;
				c80 < c81 + 32;
				c80 += 32, c80_p_1 += 32, c80_p_0 += 32){
				// y = 7, x = 14, h = 3, w = 3, c = 32, f = 64
				// T (x, 14) (14 / 1)
				for (x = x40, xp_0 = 0;
					x < x40 + 14;
					x += 1, xp_0 += 1){
					// y = 7, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (h, 3) (3 / 1)
					for (h = h38, hp_0 = 0;
						h < h38 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 1, h = 1, w = 3, c = 32, f = 64
						// T (w, 3) (3 / 1)
						for (w = w38, wp_0 = 0;
							w < w38 + 3;
							w += 1, wp_0 += 1){
									mem_vec_560 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_561 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_562 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_563 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c80, cp_2 = c80_p_1, cp_1 = c80_p_0, cp_0 = 0;
										c < c80 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_560);
										mem_vec_560 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_561);
										mem_vec_561 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_562);
										mem_vec_562 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_563);
										mem_vec_563 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_564);
										mem_vec_564 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_565);
										mem_vec_565 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_566);
										mem_vec_566 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_567);
										mem_vec_567 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_568);
										mem_vec_568 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_569);
										mem_vec_569 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_570);
										mem_vec_570 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_571);
										mem_vec_571 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_572);
										mem_vec_572 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_573);
										mem_vec_573 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_574);
										mem_vec_574 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_575);
										mem_vec_575 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_576);
										mem_vec_576 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_577);
										mem_vec_577 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_578);
										mem_vec_578 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_579);
										mem_vec_579 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_580);
										mem_vec_580 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_581);
										mem_vec_581 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_582);
										mem_vec_582 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_583);
										mem_vec_583 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_584);
										mem_vec_584 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_585);
										mem_vec_585 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_586);
										mem_vec_586 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_587);
										mem_vec_587 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_560);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_561);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_562);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_563);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_564);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_565);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_566);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_567);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_568);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_569);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_570);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_571);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_572);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_573);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_574);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_575);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_576);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_577);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_578);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_579);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_580);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_581);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_582);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_583);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_584);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_585);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_586);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_587);
						}
					}
				}
			}
		}
	}
}


}