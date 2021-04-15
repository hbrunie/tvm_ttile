#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (17, x); T (4, x);
  Lambda_apply y [((Iter 4), (Arg 7)); ((Iter 5), (Arg 8))]; T (4, f);
  T (64, c); T (1, x)]
*/
IND_TYPE c, cp_0, c102_p_0, cp_1, c102, f, fp_0, x, xp_0, x136_p_0, x137_p_0, xp_1, x136_p_1, xp_2, x136, x137, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y68 = 0;
IND_TYPE x138 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c103 = 0;
IND_TYPE f68 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_572 ,mem_vec_573 ,mem_vec_574 ,mem_vec_575 ,mem_vec_576 ,mem_vec_577 ,mem_vec_578 ,mem_vec_579 ,mem_vec_580 ,mem_vec_581 ,mem_vec_582 ,mem_vec_583 ,mem_vec_584 ,mem_vec_585 ,mem_vec_586 ,mem_vec_587 ,mem_vec_588 ,mem_vec_589 ,mem_vec_590 ,mem_vec_591 ,mem_vec_592 ,mem_vec_593 ,mem_vec_594 ,mem_vec_595 ,mem_vec_596 ,mem_vec_597 ,mem_vec_598 ,mem_vec_599 ,mem_vec_600 ,mem_vec_601 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 1) (68 / 68)
for (x137 = x138, x137_p_0 = 0;
	x137 < x138 + 68;
	x137 += 68, x137_p_0 += 68){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (c, 64) (256 / 4)
	for (c102 = c103, c102_p_0 = 0;
		c102 < c103 + 256;
		c102 += 4, c102_p_0 += 4){
		// y = 68, x = 68, h = 1, w = 1, c = 4, f = 128
		// T (f, 4) (128 / 32)
		for (f = f68, fp_0 = 0;
			f < f68 + 128;
			f += 32, fp_0 += 32){
				for (y = y68, yp_0 = 0;
					y < y68 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 68, h = 1, w = 1, c = 4, f = 32
					// T (x, 4) (68 / 17)
					for (x136 = x137, x136_p_1 = x137_p_0, x136_p_0 = 0;
						x136 < x137 + 68;
						x136 += 17, x136_p_1 += 17, x136_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
						// T (x, 17) (17 / 1)
						for (x = x136, xp_2 = x136_p_1, xp_1 = x136_p_0, xp_0 = 0;
							x < x136 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_572 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_573 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c102, cp_1 = c102_p_0, cp_0 = 0;
										c < c102 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_572);
										mem_vec_572 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_573);
										mem_vec_573 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_574);
										mem_vec_574 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_575);
										mem_vec_575 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_576);
										mem_vec_576 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_577);
										mem_vec_577 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_578);
										mem_vec_578 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_579);
										mem_vec_579 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_580);
										mem_vec_580 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_581);
										mem_vec_581 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_582);
										mem_vec_582 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_583);
										mem_vec_583 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_584);
										mem_vec_584 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_585);
										mem_vec_585 = vec_22;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_572);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_573);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_574);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_575);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_576);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_577);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_578);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_579);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_580);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_581);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_582);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_583);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_584);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_585);
						}
					}
				}
				for (y = y68 + 28, yp_0 = 0;
					y < y68 + 28 + 40;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 68, h = 1, w = 1, c = 4, f = 32
					// T (x, 4) (68 / 17)
					for (x136 = x137, x136_p_1 = x137_p_0, x136_p_0 = 0;
						x136 < x137 + 68;
						x136 += 17, x136_p_1 += 17, x136_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
						// T (x, 17) (17 / 1)
						for (x = x136, xp_2 = x136_p_1, xp_1 = x136_p_0, xp_0 = 0;
							x < x136 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_586 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_587 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_590 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_591 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_592 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_593 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_594 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_595 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_596 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_597 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_598 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_599 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_600 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_601 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c102, cp_1 = c102_p_0, cp_0 = 0;
										c < c102 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_586);
										mem_vec_586 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_587);
										mem_vec_587 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_588);
										mem_vec_588 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_589);
										mem_vec_589 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_590);
										mem_vec_590 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_591);
										mem_vec_591 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_592);
										mem_vec_592 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_593);
										mem_vec_593 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_594);
										mem_vec_594 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_595);
										mem_vec_595 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_596);
										mem_vec_596 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_597);
										mem_vec_597 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_598);
										mem_vec_598 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_599);
										mem_vec_599 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_600);
										mem_vec_600 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_601);
										mem_vec_601 = vec_25;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_586);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_587);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_588);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_589);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_590);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_591);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_592);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_593);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_594);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_595);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_596);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_597);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_598);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_599);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_600);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_601);
						}
					}
				}
		}
	}
}


}