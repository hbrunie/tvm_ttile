#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (4, y); U (3, w); T (8, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (4, x); T (14, y); T (4, f); T (8, c); T (1, x)]
*/
IND_TYPE c, cp_0, c190_p_0, cp_1, c190, f, fp_0, h, hp_0, x, xp_0, x202_p_0, x203_p_0, xp_1, x202_p_1, xp_2, x202, x203, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y112 = 0;
IND_TYPE x204 = 0;
IND_TYPE h72 = 0;
IND_TYPE w = 0;
IND_TYPE c191 = 0;
IND_TYPE f90 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_858 ,mem_vec_859 ,mem_vec_860 ,mem_vec_861 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 1) (56 / 56)
for (x203 = x204, x203_p_0 = 0;
	x203 < x204 + 56;
	x203 += 56, x203_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (c, 8) (64 / 8)
	for (c190 = c191, c190_p_0 = 0;
		c190 < c191 + 64;
		c190 += 8, c190_p_0 += 8){
		// y = 56, x = 56, h = 3, w = 3, c = 8, f = 64
		// T (f, 4) (64 / 16)
		for (f = f90, fp_0 = 0;
			f < f90 + 64;
			f += 16, fp_0 += 16){
			// y = 56, x = 56, h = 3, w = 3, c = 8, f = 16
			// T (y, 14) (56 / 4)
			for (y = y112, yp_0 = 0;
				y < y112 + 56;
				y += 4, yp_0 += 4){
				// y = 4, x = 56, h = 3, w = 3, c = 8, f = 16
				// T (x, 4) (56 / 14)
				for (x202 = x203, x202_p_1 = x203_p_0, x202_p_0 = 0;
					x202 < x203 + 56;
					x202 += 14, x202_p_1 += 14, x202_p_0 += 14){
					// y = 4, x = 14, h = 3, w = 3, c = 8, f = 16
					// T (h, 3) (3 / 1)
					for (h = h72, hp_0 = 0;
						h < h72 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 14, h = 1, w = 3, c = 8, f = 16
						// T (x, 14) (14 / 1)
						for (x = x202, xp_2 = x202_p_1, xp_1 = x202_p_0, xp_0 = 0;
							x < x202 + 14;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_858 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									// y = 4, x = 1, h = 1, w = 3, c = 8, f = 16
									// T (c, 8) (8 / 1)
									for (c = c190, cp_1 = c190_p_0, cp_0 = 0;
										c < c190 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_858);
										mem_vec_858 = vec_0;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_859);
										mem_vec_859 = vec_3;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_860);
										mem_vec_860 = vec_5;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_861);
										mem_vec_861 = vec_7;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);
										vec_11 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_858);
										mem_vec_858 = vec_9;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_13 = _mm512_set1_ps(scal_5);


										vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_859);
										mem_vec_859 = vec_12;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_6);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_860);
										mem_vec_860 = vec_14;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_17 = _mm512_set1_ps(scal_7);


										vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_861);
										mem_vec_861 = vec_16;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_19 = _mm512_set1_ps(scal_8);
										vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_858);
										mem_vec_858 = vec_18;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_22 = _mm512_set1_ps(scal_9);


										vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_859);
										mem_vec_859 = vec_21;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_24 = _mm512_set1_ps(scal_10);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_860);
										mem_vec_860 = vec_23;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_26 = _mm512_set1_ps(scal_11);


										vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_861);
										mem_vec_861 = vec_25;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_858);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_859);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_860);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_861);
						}
					}
				}
			}
		}
	}
}


}