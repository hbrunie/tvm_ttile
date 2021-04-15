#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, h); T (4, c); Hoist_vars [c]; T (28, x);
  T (3, w); T (2, f); T (32, c); T (1, x); T (14, y); T (1, f)]
*/
IND_TYPE c, cp_0, c84_p_0, cp_1, c84, f, fp_0, f84_p_0, fp_1, f84, w, wp_0, x, xp_0, x84_p_0, xp_1, x84, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y56 = 0;
IND_TYPE x85 = 0;
IND_TYPE h = 0;
IND_TYPE w56 = 0;
IND_TYPE c85 = 0;
IND_TYPE f85 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_432 ,mem_vec_433 ,mem_vec_434 ,mem_vec_435 ,mem_vec_436 ,mem_vec_437 ,mem_vec_438 ,mem_vec_439 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
for (f84 = f85, f84_p_0 = 0;
	f84 < f85 + 128;
	f84 += 128, f84_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (y, 14) (28 / 2)
	for (y = y56, yp_0 = 0;
		y < y56 + 28;
		y += 2, yp_0 += 2){
		// y = 2, x = 28, h = 3, w = 3, c = 128, f = 128
		// T (x, 1) (28 / 28)
		for (x84 = x85, x84_p_0 = 0;
			x84 < x85 + 28;
			x84 += 28, x84_p_0 += 28){
			// y = 2, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (c, 32) (128 / 4)
			for (c84 = c85, c84_p_0 = 0;
				c84 < c85 + 128;
				c84 += 4, c84_p_0 += 4){
				// y = 2, x = 28, h = 3, w = 3, c = 4, f = 128
				// T (f, 2) (128 / 64)
				for (f = f84, fp_1 = f84_p_0, fp_0 = 0;
					f < f84 + 128;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = 2, x = 28, h = 3, w = 3, c = 4, f = 64
					// T (w, 3) (3 / 1)
					for (w = w56, wp_0 = 0;
						w < w56 + 3;
						w += 1, wp_0 += 1){
						// y = 2, x = 28, h = 3, w = 1, c = 4, f = 64
						// T (x, 28) (28 / 1)
						for (x = x84, xp_1 = x84_p_0, xp_0 = 0;
							x < x84 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_432 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_433 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_434 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_435 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									// y = 2, x = 1, h = 3, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c84, cp_1 = c84_p_0, cp_0 = 0;
										c < c84 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_432);
										mem_vec_432 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_433);
										mem_vec_433 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_434);
										mem_vec_434 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_435);
										mem_vec_435 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_436);
										mem_vec_436 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_437);
										mem_vec_437 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_438);
										mem_vec_438 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_439);
										mem_vec_439 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_432);
										mem_vec_432 = vec_14;

										vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_433);
										mem_vec_433 = vec_17;

										vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_434);
										mem_vec_434 = vec_19;

										vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_435);
										mem_vec_435 = vec_21;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_24 = _mm512_set1_ps(scal_3);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_436);
										mem_vec_436 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_437);
										mem_vec_437 = vec_25;



										vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_438);
										mem_vec_438 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_439);
										mem_vec_439 = vec_27;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_29 = _mm512_set1_ps(scal_4);
										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_432);
										mem_vec_432 = vec_28;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_433);
										mem_vec_433 = vec_31;

										vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_434);
										mem_vec_434 = vec_33;

										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_435);
										mem_vec_435 = vec_35;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_38 = _mm512_set1_ps(scal_5);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_436);
										mem_vec_436 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_437);
										mem_vec_437 = vec_39;



										vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_438);
										mem_vec_438 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_439);
										mem_vec_439 = vec_41;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_432);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_433);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_434);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_435);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_436);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_437);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_438);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_439);
						}
					}
				}
			}
		}
	}
}


}