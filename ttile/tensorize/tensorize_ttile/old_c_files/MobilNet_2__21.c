#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (4, c); Hoist_vars [c]; T (56, x); T (3, w);
  T (3, h); T (8, c); T (1, x); T (8, y); T (2, c)]
*/
IND_TYPE c, cp_0, c90_p_0, c91_p_0, cp_1, c90_p_1, cp_2, c90, c91, h, hp_0, w, wp_0, x, xp_0, x120_p_0, xp_1, x120, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y60 = 0;
IND_TYPE x121 = 0;
IND_TYPE h60 = 0;
IND_TYPE w60 = 0;
IND_TYPE c92 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_672 ,mem_vec_673 ,mem_vec_674 ,mem_vec_675 ,mem_vec_676 ,mem_vec_677 ,mem_vec_678 ,mem_vec_679 ,mem_vec_680 ,mem_vec_681 ,mem_vec_682 ,mem_vec_683 ,mem_vec_684 ,mem_vec_685 ,mem_vec_686 ,mem_vec_687 ,mem_vec_688 ,mem_vec_689 ,mem_vec_690 ,mem_vec_691 ,mem_vec_692 ,mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 2) (64 / 32)
for (c91 = c92, c91_p_0 = 0;
	c91 < c92 + 64;
	c91 += 32, c91_p_0 += 32){
	// y = 56, x = 56, h = 3, w = 3, c = 32, f = 64
	// T (y, 8) (56 / 7)
	for (y = y60, yp_0 = 0;
		y < y60 + 56;
		y += 7, yp_0 += 7){
		// y = 7, x = 56, h = 3, w = 3, c = 32, f = 64
		// T (x, 1) (56 / 56)
		for (x120 = x121, x120_p_0 = 0;
			x120 < x121 + 56;
			x120 += 56, x120_p_0 += 56){
			// y = 7, x = 56, h = 3, w = 3, c = 32, f = 64
			// T (c, 8) (32 / 4)
			for (c90 = c91, c90_p_1 = c91_p_0, c90_p_0 = 0;
				c90 < c91 + 32;
				c90 += 4, c90_p_1 += 4, c90_p_0 += 4){
				// y = 7, x = 56, h = 3, w = 3, c = 4, f = 64
				// T (h, 3) (3 / 1)
				for (h = h60, hp_0 = 0;
					h < h60 + 3;
					h += 1, hp_0 += 1){
					// y = 7, x = 56, h = 1, w = 3, c = 4, f = 64
					// T (w, 3) (3 / 1)
					for (w = w60, wp_0 = 0;
						w < w60 + 3;
						w += 1, wp_0 += 1){
						// y = 7, x = 56, h = 1, w = 1, c = 4, f = 64
						// T (x, 56) (56 / 1)
						for (x = x120, xp_1 = x120_p_0, xp_0 = 0;
							x < x120 + 56;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_672 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_673 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_674 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_675 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = 7, x = 1, h = 1, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c90, cp_2 = c90_p_1, cp_1 = c90_p_0, cp_0 = 0;
										c < c90 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_672);
										mem_vec_672 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_673);
										mem_vec_673 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_674);
										mem_vec_674 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_675);
										mem_vec_675 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_676);
										mem_vec_676 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_677);
										mem_vec_677 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_678);
										mem_vec_678 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_679);
										mem_vec_679 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_680);
										mem_vec_680 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_681);
										mem_vec_681 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_682);
										mem_vec_682 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_683);
										mem_vec_683 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_684);
										mem_vec_684 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_685);
										mem_vec_685 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_686);
										mem_vec_686 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_687);
										mem_vec_687 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_688);
										mem_vec_688 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_689);
										mem_vec_689 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_690);
										mem_vec_690 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_691);
										mem_vec_691 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_692);
										mem_vec_692 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_693);
										mem_vec_693 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_694);
										mem_vec_694 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_695);
										mem_vec_695 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_696);
										mem_vec_696 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_697);
										mem_vec_697 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_698);
										mem_vec_698 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_699);
										mem_vec_699 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_672);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_673);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_674);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_675);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_676);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_677);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_678);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_679);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_680);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_681);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_682);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_683);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_684);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_685);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_686);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_687);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_688);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_689);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_690);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_691);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_692);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_693);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_694);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_695);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_696);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_697);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_698);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_699);
						}
					}
				}
			}
		}
	}
}


}