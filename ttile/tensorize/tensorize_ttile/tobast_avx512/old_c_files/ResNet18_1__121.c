#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (3, c); Hoist_vars [c]; T (56, x); T (7, w);
  T (7, h); T (2, x); T (8, y); T (2, f); T (1, x)]
*/
IND_TYPE c, cp_0, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x160_p_0, x161_p_0, xp_1, x160_p_1, xp_2, x160, x161, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 7));
assert((W == 7));
assert((C == 3));
assert((F == 64));
IND_TYPE y80 = 0;
IND_TYPE x162 = 0;
IND_TYPE h80 = 0;
IND_TYPE w80 = 0;
IND_TYPE c80 = 0;
IND_TYPE f80 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_608 ,mem_vec_609 ,mem_vec_610 ,mem_vec_611 ,mem_vec_612 ,mem_vec_613 ,mem_vec_614 ,mem_vec_615 ,mem_vec_616 ,mem_vec_617 ,mem_vec_618 ,mem_vec_619 ,mem_vec_620 ,mem_vec_621 ,mem_vec_622 ,mem_vec_623 ,mem_vec_624 ,mem_vec_625 ,mem_vec_626 ,mem_vec_627 ,mem_vec_628 ,mem_vec_629 ,mem_vec_630 ,mem_vec_631 ,mem_vec_632 ,mem_vec_633 ,mem_vec_634 ,mem_vec_635 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (x, 1) (112 / 112)
for (x161 = x162, x161_p_0 = 0;
	x161 < x162 + 112;
	x161 += 112, x161_p_0 += 112){
	// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
	// T (f, 2) (64 / 32)
	for (f = f80, fp_0 = 0;
		f < f80 + 64;
		f += 32, fp_0 += 32){
		// y = 112, x = 112, h = 7, w = 7, c = 3, f = 32
		// T (y, 8) (112 / 14)
		for (y = y80, yp_0 = 0;
			y < y80 + 112;
			y += 14, yp_0 += 14){
			// y = 14, x = 112, h = 7, w = 7, c = 3, f = 32
			// T (x, 2) (112 / 56)
			for (x160 = x161, x160_p_1 = x161_p_0, x160_p_0 = 0;
				x160 < x161 + 112;
				x160 += 56, x160_p_1 += 56, x160_p_0 += 56){
				// y = 14, x = 56, h = 7, w = 7, c = 3, f = 32
				// T (h, 7) (7 / 1)
				for (h = h80, hp_0 = 0;
					h < h80 + 7;
					h += 1, hp_0 += 1){
					// y = 14, x = 56, h = 1, w = 7, c = 3, f = 32
					// T (w, 7) (7 / 1)
					for (w = w80, wp_0 = 0;
						w < w80 + 7;
						w += 1, wp_0 += 1){
						// y = 14, x = 56, h = 1, w = 1, c = 3, f = 32
						// T (x, 56) (56 / 1)
						for (x = x160, xp_2 = x160_p_1, xp_1 = x160_p_0, xp_0 = 0;
							x < x160 + 56;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_608 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_609 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = 14, x = 1, h = 1, w = 1, c = 3, f = 32
									// T (c, 3) (3 / 1)
									for (c = c80, cp_0 = 0;
										c < c80 + 3;
										c += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_608);
										mem_vec_608 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_609);
										mem_vec_609 = vec_3;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_610);
										mem_vec_610 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_611);
										mem_vec_611 = vec_7;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_612);
										mem_vec_612 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_613);
										mem_vec_613 = vec_10;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_614);
										mem_vec_614 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_615);
										mem_vec_615 = vec_13;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_616);
										mem_vec_616 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_617);
										mem_vec_617 = vec_16;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_618);
										mem_vec_618 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_619);
										mem_vec_619 = vec_19;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_620);
										mem_vec_620 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_621);
										mem_vec_621 = vec_22;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_622);
										mem_vec_622 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_623);
										mem_vec_623 = vec_25;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_624);
										mem_vec_624 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_625);
										mem_vec_625 = vec_28;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_626);
										mem_vec_626 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_627);
										mem_vec_627 = vec_31;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_628);
										mem_vec_628 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_629);
										mem_vec_629 = vec_34;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_630);
										mem_vec_630 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_631);
										mem_vec_631 = vec_37;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_632);
										mem_vec_632 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_633);
										mem_vec_633 = vec_40;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_634);
										mem_vec_634 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_635);
										mem_vec_635 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_608);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_609);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_610);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_611);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_612);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_613);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_614);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_615);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_616);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_617);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_618);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_619);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_620);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_621);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_622);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_623);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_624);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_625);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_626);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_627);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_628);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_629);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_630);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_631);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_632);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_633);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_634);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_635);
						}
					}
				}
			}
		}
	}
}


}