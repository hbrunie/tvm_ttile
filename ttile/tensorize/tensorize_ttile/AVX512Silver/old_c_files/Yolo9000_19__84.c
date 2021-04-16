#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (17, x); T (32, c);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]; T (8, f);
  T (1, c); T (1, y)]
*/
IND_TYPE c, cp_0, c56_p_0, c57_p_0, cp_1, c56_p_1, cp_2, c56, c57, f, fp_0, x, xp_0, y, yp_0, y42_p_0, yp_1, y42;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y43 = 0;
IND_TYPE x28 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c58 = 0;
IND_TYPE f28 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_568 ,mem_vec_569 ,mem_vec_570 ,mem_vec_571 ,mem_vec_572 ,mem_vec_573 ,mem_vec_574 ,mem_vec_575 ,mem_vec_576 ,mem_vec_577 ,mem_vec_578 ,mem_vec_579 ,mem_vec_580 ,mem_vec_581 ,mem_vec_582 ,mem_vec_583 ,mem_vec_584 ,mem_vec_585 ,mem_vec_586 ,mem_vec_587 ,mem_vec_588 ,mem_vec_589 ,mem_vec_590 ,mem_vec_591 ,mem_vec_592 ,mem_vec_593 ,mem_vec_594 ,mem_vec_595 ,mem_vec_596 ,mem_vec_597 ,mem_vec_598 ,mem_vec_599 ,mem_vec_600 ,mem_vec_601 ,mem_vec_602 ,mem_vec_603 ,mem_vec_604 ,mem_vec_605 ,mem_vec_606 ,mem_vec_607 ,mem_vec_608 ,mem_vec_609 ,mem_vec_610 ,mem_vec_611 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y42 = y43, y42_p_0 = 0;
	y42 < y43 + 17;
	y42 += 17, y42_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (c, 1) (1024 / 1024)
	for (c57 = c58, c57_p_0 = 0;
		c57 < c58 + 1024;
		c57 += 1024, c57_p_0 += 1024){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (f, 8) (512 / 64)
		for (f = f28, fp_0 = 0;
			f < f28 + 512;
			f += 64, fp_0 += 64){
				for (y = y42, yp_1 = y42_p_0, yp_0 = 0;
					y < y42 + 5;
					y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 32) (1024 / 32)
					for (c56 = c57, c56_p_1 = c57_p_0, c56_p_0 = 0;
						c56 < c57 + 1024;
						c56 += 32, c56_p_1 += 32, c56_p_0 += 32){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x28, xp_0 = 0;
							x < x28 + 17;
							x += 1, xp_0 += 1){
									mem_vec_568 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_569 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_570 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_571 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c56, cp_2 = c56_p_1, cp_1 = c56_p_0, cp_0 = 0;
										c < c56 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_568);
										mem_vec_568 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_569);
										mem_vec_569 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_570);
										mem_vec_570 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_571);
										mem_vec_571 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_572);
										mem_vec_572 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_573);
										mem_vec_573 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_574);
										mem_vec_574 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_575);
										mem_vec_575 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_576);
										mem_vec_576 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_577);
										mem_vec_577 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_578);
										mem_vec_578 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_579);
										mem_vec_579 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_580);
										mem_vec_580 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_581);
										mem_vec_581 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_582);
										mem_vec_582 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_583);
										mem_vec_583 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_584);
										mem_vec_584 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_585);
										mem_vec_585 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_586);
										mem_vec_586 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_587);
										mem_vec_587 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_568);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_569);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_570);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_571);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_572);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_573);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_574);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_575);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_576);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_577);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_578);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_579);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_580);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_581);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_582);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_583);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_584);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_585);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_586);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_587);
						}
					}
				}
				for (y = y42 + 5, yp_1 = y42_p_0, yp_0 = 0;
					y < y42 + 5 + 12;
					y += 6, yp_1 += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 32) (1024 / 32)
					for (c56 = c57, c56_p_1 = c57_p_0, c56_p_0 = 0;
						c56 < c57 + 1024;
						c56 += 32, c56_p_1 += 32, c56_p_0 += 32){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x28, xp_0 = 0;
							x < x28 + 17;
							x += 1, xp_0 += 1){
									mem_vec_588 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_589 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_590 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_591 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_592 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_593 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_594 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_595 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_596 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_597 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_598 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_599 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_600 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_601 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_602 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_603 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_604 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_605 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_606 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_607 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c56, cp_2 = c56_p_1, cp_1 = c56_p_0, cp_0 = 0;
										c < c56 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_588);
										mem_vec_588 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_589);
										mem_vec_589 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_590);
										mem_vec_590 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_591);
										mem_vec_591 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_592);
										mem_vec_592 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_593);
										mem_vec_593 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_594);
										mem_vec_594 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_595);
										mem_vec_595 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_596);
										mem_vec_596 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_597);
										mem_vec_597 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_598);
										mem_vec_598 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_599);
										mem_vec_599 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_600);
										mem_vec_600 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_601);
										mem_vec_601 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_602);
										mem_vec_602 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_603);
										mem_vec_603 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_604);
										mem_vec_604 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_605);
										mem_vec_605 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_606);
										mem_vec_606 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_607);
										mem_vec_607 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_608);
										mem_vec_608 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_609);
										mem_vec_609 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_610);
										mem_vec_610 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_611);
										mem_vec_611 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_588);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_589);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_590);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_591);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_592);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_593);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_594);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_595);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_596);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_597);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_598);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_599);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_600);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_601);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_602);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_603);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_604);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_605);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_606);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_607);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_608);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_609);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_610);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_611);
						}
					}
				}
		}
	}
}


}