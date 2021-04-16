#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (16, f);
  T (64, c); T (17, x); T (1, y)]
*/
IND_TYPE c, cp_0, c51_p_0, cp_1, c51, f, fp_0, x, xp_0, x51_p_0, xp_1, x51, y, yp_0, y51_p_0, yp_1, y51;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y52 = 0;
IND_TYPE x52 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c52 = 0;
IND_TYPE f34 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_612 ,mem_vec_613 ,mem_vec_614 ,mem_vec_615 ,mem_vec_616 ,mem_vec_617 ,mem_vec_618 ,mem_vec_619 ,mem_vec_620 ,mem_vec_621 ,mem_vec_622 ,mem_vec_623 ,mem_vec_624 ,mem_vec_625 ,mem_vec_626 ,mem_vec_627 ,mem_vec_628 ,mem_vec_629 ,mem_vec_630 ,mem_vec_631 ,mem_vec_632 ,mem_vec_633 ,mem_vec_634 ,mem_vec_635 ,mem_vec_636 ,mem_vec_637 ,mem_vec_638 ,mem_vec_639 ,mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y51 = y52, y51_p_0 = 0;
	y51 < y52 + 17;
	y51 += 17, y51_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (x, 17) (17 / 1)
	for (x51 = x52, x51_p_0 = 0;
		x51 < x52 + 17;
		x51 += 1, x51_p_0 += 1){
		// y = 17, x = 1, h = 1, w = 1, c = 1024, f = 512
		// T (c, 64) (1024 / 16)
		for (c51 = c52, c51_p_0 = 0;
			c51 < c52 + 1024;
			c51 += 16, c51_p_0 += 16){
			// y = 17, x = 1, h = 1, w = 1, c = 16, f = 512
			// T (f, 16) (512 / 32)
			for (f = f34, fp_0 = 0;
				f < f34 + 512;
				f += 32, fp_0 += 32){
					for (y = y51, yp_1 = y51_p_0, yp_0 = 0;
						y < y51 + 12;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
						// T (x, 1) (1 / 1)
						for (x = x51, xp_1 = x51_p_0, xp_0 = 0;
							x < x51 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_612 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_613 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_614 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_615 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_616 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_617 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_618 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_619 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_624 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_625 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_626 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_627 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c51, cp_1 = c51_p_0, cp_0 = 0;
										c < c51 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_612);
										mem_vec_612 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_613);
										mem_vec_613 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_614);
										mem_vec_614 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_615);
										mem_vec_615 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_616);
										mem_vec_616 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_617);
										mem_vec_617 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_618);
										mem_vec_618 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_619);
										mem_vec_619 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_620);
										mem_vec_620 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_621);
										mem_vec_621 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_622);
										mem_vec_622 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_623);
										mem_vec_623 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_624);
										mem_vec_624 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_625);
										mem_vec_625 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_626);
										mem_vec_626 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_627);
										mem_vec_627 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_612);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_613);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_614);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_615);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_616);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_617);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_618);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_619);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_620);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_621);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_622);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_623);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_624);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_625);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_626);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_627);
						}
					}
					for (y = y51 + 12, yp_1 = y51_p_0, yp_0 = 0;
						y < y51 + 12 + 5;
						y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
						// T (x, 1) (1 / 1)
						for (x = x51, xp_1 = x51_p_0, xp_0 = 0;
							x < x51 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_628 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_629 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_630 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_631 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_632 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_633 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_634 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_635 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_636 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_637 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_638 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_639 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_640 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_641 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_642 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_643 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_644 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_645 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_646 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_647 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c51, cp_1 = c51_p_0, cp_0 = 0;
										c < c51 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_628);
										mem_vec_628 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_629);
										mem_vec_629 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_630);
										mem_vec_630 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_631);
										mem_vec_631 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_632);
										mem_vec_632 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_633);
										mem_vec_633 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_634);
										mem_vec_634 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_635);
										mem_vec_635 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_636);
										mem_vec_636 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_637);
										mem_vec_637 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_638);
										mem_vec_638 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_639);
										mem_vec_639 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_640);
										mem_vec_640 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_641);
										mem_vec_641 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_642);
										mem_vec_642 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_643);
										mem_vec_643 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_644);
										mem_vec_644 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_645);
										mem_vec_645 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_646);
										mem_vec_646 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_647);
										mem_vec_647 = vec_28;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_628);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_629);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_630);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_631);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_632);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_633);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_634);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_635);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_636);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_637);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_638);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_639);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_640);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_641);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_642);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_643);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_644);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_645);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_646);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_647);
						}
					}
			}
		}
	}
}


}