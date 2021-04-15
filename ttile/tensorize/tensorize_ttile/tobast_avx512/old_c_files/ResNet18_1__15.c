#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (3, c); Hoist_vars [c]; T (14, x); T (7, w);
  T (7, h); T (2, x); T (16, y); T (2, f); T (4, x)]
*/
IND_TYPE c, cp_0, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x40_p_0, x41_p_0, xp_1, x40_p_1, xp_2, x40, x41, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 7));
assert((W == 7));
assert((C == 3));
assert((F == 64));
IND_TYPE y20 = 0;
IND_TYPE x42 = 0;
IND_TYPE h20 = 0;
IND_TYPE w20 = 0;
IND_TYPE c20 = 0;
IND_TYPE f20 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,mem_vec_144 ,mem_vec_145 ,mem_vec_146 ,mem_vec_147 ,mem_vec_148 ,mem_vec_149 ,mem_vec_150 ,mem_vec_151 ,mem_vec_152 ,mem_vec_153 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (x, 4) (112 / 28)
for (x41 = x42, x41_p_0 = 0;
	x41 < x42 + 112;
	x41 += 28, x41_p_0 += 28){
	// y = 112, x = 28, h = 7, w = 7, c = 3, f = 64
	// T (f, 2) (64 / 32)
	for (f = f20, fp_0 = 0;
		f < f20 + 64;
		f += 32, fp_0 += 32){
		// y = 112, x = 28, h = 7, w = 7, c = 3, f = 32
		// T (y, 16) (112 / 7)
		for (y = y20, yp_0 = 0;
			y < y20 + 112;
			y += 7, yp_0 += 7){
			// y = 7, x = 28, h = 7, w = 7, c = 3, f = 32
			// T (x, 2) (28 / 14)
			for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
				x40 < x41 + 28;
				x40 += 14, x40_p_1 += 14, x40_p_0 += 14){
				// y = 7, x = 14, h = 7, w = 7, c = 3, f = 32
				// T (h, 7) (7 / 1)
				for (h = h20, hp_0 = 0;
					h < h20 + 7;
					h += 1, hp_0 += 1){
					// y = 7, x = 14, h = 1, w = 7, c = 3, f = 32
					// T (w, 7) (7 / 1)
					for (w = w20, wp_0 = 0;
						w < w20 + 7;
						w += 1, wp_0 += 1){
						// y = 7, x = 14, h = 1, w = 1, c = 3, f = 32
						// T (x, 14) (14 / 1)
						for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
							x < x40 + 14;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_140 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_141 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = 7, x = 1, h = 1, w = 1, c = 3, f = 32
									// T (c, 3) (3 / 1)
									for (c = c20, cp_0 = 0;
										c < c20 + 3;
										c += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_140);
										mem_vec_140 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_141);
										mem_vec_141 = vec_3;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_142);
										mem_vec_142 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_143);
										mem_vec_143 = vec_7;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_144);
										mem_vec_144 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_145);
										mem_vec_145 = vec_10;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_146);
										mem_vec_146 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_147);
										mem_vec_147 = vec_13;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_148);
										mem_vec_148 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_149);
										mem_vec_149 = vec_16;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_150);
										mem_vec_150 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_151);
										mem_vec_151 = vec_19;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_152);
										mem_vec_152 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_153);
										mem_vec_153 = vec_22;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_140);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_141);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_142);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_143);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_144);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_145);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_146);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_147);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_148);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_149);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_150);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_151);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_152);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_153);
						}
					}
				}
			}
		}
	}
}


}