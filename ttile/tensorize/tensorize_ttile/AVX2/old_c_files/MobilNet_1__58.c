#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (28, x); T (28, y); T (1, c); T (1, y); T (4, x)]
*/
IND_TYPE c, cp_0, c543_p_0, cp_1, c543, h, hp_0, w, wp_0, x, xp_0, x552_p_0, xp_1, x552, y, yp_0, y534_p_0, yp_1, y534;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y535 = 0;
IND_TYPE x553 = 0;
IND_TYPE h287 = 0;
IND_TYPE w296 = 0;
IND_TYPE c544 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_3616 ,mem_vec_3617 ,mem_vec_3618 ,mem_vec_3619 ,mem_vec_3620 ,mem_vec_3621 ,mem_vec_3622 ,mem_vec_3623 ,mem_vec_3624 ,mem_vec_3625 ,mem_vec_3626 ,mem_vec_3627 ,mem_vec_3628 ,mem_vec_3629 ,mem_vec_3630 ,mem_vec_3631 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 4) (112 / 28)
for (x552 = x553, x552_p_0 = 0;
	x552 < x553 + 112;
	x552 += 28, x552_p_0 += 28){
	// y = 112, x = 28, h = 3, w = 3, c = 32, f = 32
	// T (y, 1) (112 / 112)
	for (y534 = y535, y534_p_0 = 0;
		y534 < y535 + 112;
		y534 += 112, y534_p_0 += 112){
		// y = 112, x = 28, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c543 = c544, c543_p_0 = 0;
			c543 < c544 + 32;
			c543 += 32, c543_p_0 += 32){
			// y = 112, x = 28, h = 3, w = 3, c = 32, f = 32
			// T (y, 28) (112 / 4)
			for (y = y534, yp_1 = y534_p_0, yp_0 = 0;
				y < y534 + 112;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 28, h = 3, w = 3, c = 32, f = 32
				// T (x, 28) (28 / 1)
				for (x = x552, xp_1 = x552_p_0, xp_0 = 0;
					x < x552 + 28;
					x += 1, xp_1 += 1, xp_0 += 1){
					// y = 4, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h287, hp_0 = 0;
						h < h287 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w296, wp_0 = 0;
							w < w296 + 3;
							w += 1, wp_0 += 1){
									mem_vec_3616 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3617 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_3618 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3619 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_3620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_3622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_3624 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3625 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_3626 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3627 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_3628 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3629 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_3630 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3631 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c543, cp_1 = c543_p_0, cp_0 = 0;
										c < c543 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3616);
										mem_vec_3616 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3617);
										mem_vec_3617 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3618);
										mem_vec_3618 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3619);
										mem_vec_3619 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3620);
										mem_vec_3620 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3621);
										mem_vec_3621 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3622);
										mem_vec_3622 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3623);
										mem_vec_3623 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3624);
										mem_vec_3624 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3625);
										mem_vec_3625 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3626);
										mem_vec_3626 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3627);
										mem_vec_3627 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3628);
										mem_vec_3628 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3629);
										mem_vec_3629 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3630);
										mem_vec_3630 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3631);
										mem_vec_3631 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3616);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3617);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3618);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3619);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3620);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3621);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3622);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3623);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3624);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3625);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3626);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3627);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3628);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3629);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3630);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3631);
						}
					}
				}
			}
		}
	}
}


}