#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (4, y); U (3, w); T (16, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (1, x); T (14, y); T (4, f); T (4, c); T (8, x)]
*/
IND_TYPE c, cp_0, c176_p_0, cp_1, c176, f, fp_0, h, hp_0, x, xp_0, x202_p_0, x203_p_0, xp_1, x202_p_1, xp_2, x202, x203, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y108 = 0;
IND_TYPE x204 = 0;
IND_TYPE h74 = 0;
IND_TYPE w = 0;
IND_TYPE c177 = 0;
IND_TYPE f94 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_842 ,mem_vec_843 ,mem_vec_844 ,mem_vec_845 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 8) (56 / 7)
for (x203 = x204, x203_p_0 = 0;
	x203 < x204 + 56;
	x203 += 7, x203_p_0 += 7){
	// y = 56, x = 7, h = 3, w = 3, c = 64, f = 64
	// T (c, 4) (64 / 16)
	for (c176 = c177, c176_p_0 = 0;
		c176 < c177 + 64;
		c176 += 16, c176_p_0 += 16){
		// y = 56, x = 7, h = 3, w = 3, c = 16, f = 64
		// T (f, 4) (64 / 16)
		for (f = f94, fp_0 = 0;
			f < f94 + 64;
			f += 16, fp_0 += 16){
			// y = 56, x = 7, h = 3, w = 3, c = 16, f = 16
			// T (y, 14) (56 / 4)
			for (y = y108, yp_0 = 0;
				y < y108 + 56;
				y += 4, yp_0 += 4){
				// y = 4, x = 7, h = 3, w = 3, c = 16, f = 16
				// T (x, 1) (7 / 7)
				for (x202 = x203, x202_p_1 = x203_p_0, x202_p_0 = 0;
					x202 < x203 + 7;
					x202 += 7, x202_p_1 += 7, x202_p_0 += 7){
					// y = 4, x = 7, h = 3, w = 3, c = 16, f = 16
					// T (h, 3) (3 / 1)
					for (h = h74, hp_0 = 0;
						h < h74 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 7, h = 1, w = 3, c = 16, f = 16
						// T (x, 7) (7 / 1)
						for (x = x202, xp_2 = x202_p_1, xp_1 = x202_p_0, xp_0 = 0;
							x < x202 + 7;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_842 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									// y = 4, x = 1, h = 1, w = 3, c = 16, f = 16
									// T (c, 16) (16 / 1)
									for (c = c176, cp_1 = c176_p_0, cp_0 = 0;
										c < c176 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_842);
										mem_vec_842 = vec_0;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_843);
										mem_vec_843 = vec_3;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_844);
										mem_vec_844 = vec_5;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_845);
										mem_vec_845 = vec_7;
										scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);
										vec_11 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_842);
										mem_vec_842 = vec_9;
										scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_13 = _mm512_set1_ps(scal_5);


										vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_843);
										mem_vec_843 = vec_12;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_6);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_844);
										mem_vec_844 = vec_14;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_17 = _mm512_set1_ps(scal_7);


										vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_845);
										mem_vec_845 = vec_16;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_19 = _mm512_set1_ps(scal_8);
										vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_842);
										mem_vec_842 = vec_18;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_22 = _mm512_set1_ps(scal_9);


										vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_843);
										mem_vec_843 = vec_21;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_24 = _mm512_set1_ps(scal_10);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_844);
										mem_vec_844 = vec_23;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_26 = _mm512_set1_ps(scal_11);


										vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_845);
										mem_vec_845 = vec_25;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_842);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_843);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_844);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_845);
						}
					}
				}
			}
		}
	}
}


}