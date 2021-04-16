#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (16, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (4, c); T (1, x); T (8, y); T (2, x)]
*/
IND_TYPE c, cp_0, c99_p_0, cp_1, c99, h, hp_0, w, wp_0, x, xp_0, x118_p_0, x119_p_0, xp_1, x118_p_1, xp_2, x118, x119, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y80 = 0;
IND_TYPE x120 = 0;
IND_TYPE h49 = 0;
IND_TYPE w47 = 0;
IND_TYPE c100 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_632 ,mem_vec_633 ,mem_vec_634 ,mem_vec_635 ,mem_vec_636 ,mem_vec_637 ,mem_vec_638 ,mem_vec_639 ,mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 2) (56 / 28)
for (x119 = x120, x119_p_0 = 0;
	x119 < x120 + 56;
	x119 += 28, x119_p_0 += 28){
	// y = 56, x = 28, h = 3, w = 3, c = 64, f = 64
	// T (y, 8) (56 / 7)
	for (y = y80, yp_0 = 0;
		y < y80 + 56;
		y += 7, yp_0 += 7){
		// y = 7, x = 28, h = 3, w = 3, c = 64, f = 64
		// T (x, 1) (28 / 28)
		for (x118 = x119, x118_p_1 = x119_p_0, x118_p_0 = 0;
			x118 < x119 + 28;
			x118 += 28, x118_p_1 += 28, x118_p_0 += 28){
			// y = 7, x = 28, h = 3, w = 3, c = 64, f = 64
			// T (c, 4) (64 / 16)
			for (c99 = c100, c99_p_0 = 0;
				c99 < c100 + 64;
				c99 += 16, c99_p_0 += 16){
				// y = 7, x = 28, h = 3, w = 3, c = 16, f = 64
				// T (w, 3) (3 / 1)
				for (w = w47, wp_0 = 0;
					w < w47 + 3;
					w += 1, wp_0 += 1){
					// y = 7, x = 28, h = 3, w = 1, c = 16, f = 64
					// T (x, 28) (28 / 1)
					for (x = x118, xp_2 = x118_p_1, xp_1 = x118_p_0, xp_0 = 0;
						x < x118 + 28;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
						// y = 7, x = 1, h = 3, w = 1, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h49, hp_0 = 0;
							h < h49 + 3;
							h += 1, hp_0 += 1){
									mem_vec_632 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_633 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_634 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_635 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = 7, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c99, cp_1 = c99_p_0, cp_0 = 0;
										c < c99 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_632);
										mem_vec_632 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_633);
										mem_vec_633 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_634);
										mem_vec_634 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_635);
										mem_vec_635 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_636);
										mem_vec_636 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_637);
										mem_vec_637 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_638);
										mem_vec_638 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_639);
										mem_vec_639 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_640);
										mem_vec_640 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_641);
										mem_vec_641 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_642);
										mem_vec_642 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_643);
										mem_vec_643 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_644);
										mem_vec_644 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_645);
										mem_vec_645 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_646);
										mem_vec_646 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_647);
										mem_vec_647 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_648);
										mem_vec_648 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_649);
										mem_vec_649 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_650);
										mem_vec_650 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_651);
										mem_vec_651 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_652);
										mem_vec_652 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_653);
										mem_vec_653 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_654);
										mem_vec_654 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_655);
										mem_vec_655 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_656);
										mem_vec_656 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_657);
										mem_vec_657 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_658);
										mem_vec_658 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_659);
										mem_vec_659 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_632);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_633);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_634);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_635);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_636);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_637);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_638);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_639);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_640);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_641);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_642);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_643);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_644);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_645);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_646);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_647);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_648);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_649);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_650);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_651);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_652);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_653);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_654);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_655);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_656);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_657);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_658);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_659);
						}
					}
				}
			}
		}
	}
}


}