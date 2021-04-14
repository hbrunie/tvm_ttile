#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (8, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (28, x); T (8, y); T (4, c); T (4, x)]
*/
IND_TYPE c, cp_0, c96_p_0, cp_1, c96, h, hp_0, w, wp_0, x, xp_0, x128_p_0, x129_p_0, xp_1, x128_p_1, xp_2, x128, x129, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y64 = 0;
IND_TYPE x130 = 0;
IND_TYPE h64 = 0;
IND_TYPE w64 = 0;
IND_TYPE c97 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_632 ,mem_vec_633 ,mem_vec_634 ,mem_vec_635 ,mem_vec_636 ,mem_vec_637 ,mem_vec_638 ,mem_vec_639 ,mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 4) (112 / 28)
for (x129 = x130, x129_p_0 = 0;
	x129 < x130 + 112;
	x129 += 28, x129_p_0 += 28){
	// y = 112, x = 28, h = 3, w = 3, c = 32, f = 32
	// T (c, 4) (32 / 8)
	for (c96 = c97, c96_p_0 = 0;
		c96 < c97 + 32;
		c96 += 8, c96_p_0 += 8){
		// y = 112, x = 28, h = 3, w = 3, c = 8, f = 32
		// T (y, 8) (112 / 14)
		for (y = y64, yp_0 = 0;
			y < y64 + 112;
			y += 14, yp_0 += 14){
			// y = 14, x = 28, h = 3, w = 3, c = 8, f = 32
			// T (x, 28) (28 / 1)
			for (x128 = x129, x128_p_1 = x129_p_0, x128_p_0 = 0;
				x128 < x129 + 28;
				x128 += 1, x128_p_1 += 1, x128_p_0 += 1){
				// y = 14, x = 1, h = 3, w = 3, c = 8, f = 32
				// T (h, 3) (3 / 1)
				for (h = h64, hp_0 = 0;
					h < h64 + 3;
					h += 1, hp_0 += 1){
					// y = 14, x = 1, h = 1, w = 3, c = 8, f = 32
					// T (w, 3) (3 / 1)
					for (w = w64, wp_0 = 0;
						w < w64 + 3;
						w += 1, wp_0 += 1){
						// y = 14, x = 1, h = 1, w = 1, c = 8, f = 32
						// T (x, 1) (1 / 1)
						for (x = x128, xp_2 = x128_p_1, xp_1 = x128_p_0, xp_0 = 0;
							x < x128 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_632 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_633 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = 14, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c96, cp_1 = c96_p_0, cp_0 = 0;
										c < c96 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_632);
										mem_vec_632 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_633);
										mem_vec_633 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_634);
										mem_vec_634 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_635);
										mem_vec_635 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_636);
										mem_vec_636 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_637);
										mem_vec_637 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_638);
										mem_vec_638 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_639);
										mem_vec_639 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_640);
										mem_vec_640 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_641);
										mem_vec_641 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_642);
										mem_vec_642 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_643);
										mem_vec_643 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_644);
										mem_vec_644 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_645);
										mem_vec_645 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_646);
										mem_vec_646 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_647);
										mem_vec_647 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_648);
										mem_vec_648 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_649);
										mem_vec_649 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_650);
										mem_vec_650 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_651);
										mem_vec_651 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_652);
										mem_vec_652 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_653);
										mem_vec_653 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_654);
										mem_vec_654 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_655);
										mem_vec_655 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_656);
										mem_vec_656 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_657);
										mem_vec_657 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_658);
										mem_vec_658 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_659);
										mem_vec_659 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_632);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_633);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_634);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_635);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_636);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_637);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_638);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_639);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_640);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_641);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_642);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_643);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_644);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_645);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_646);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_647);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_648);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_649);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_650);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_651);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_652);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_653);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_654);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_655);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_656);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_657);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_658);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_659);
						}
					}
				}
			}
		}
	}
}


}