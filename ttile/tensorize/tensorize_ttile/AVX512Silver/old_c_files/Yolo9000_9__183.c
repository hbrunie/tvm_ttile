#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (68, x); T (8, c);
  T (2, f); T (1, x); T (1, y); T (1, x); T (17, y)]
*/
IND_TYPE c, cp_0, c15_p_0, cp_1, c15, f, fp_0, x, xp_0, x20_p_0, x21_p_0, xp_1, x20_p_1, xp_2, x20, x21, y, yp_0, y15_p_0, yp_1, y15;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y16 = 0;
IND_TYPE x22 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c16 = 0;
IND_TYPE f10 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_152 ,mem_vec_153 ,mem_vec_154 ,mem_vec_155 ,mem_vec_156 ,mem_vec_157 ,mem_vec_158 ,mem_vec_159 ,mem_vec_160 ,mem_vec_161 ,mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 17) (68 / 4)
for (y15 = y16, y15_p_0 = 0;
	y15 < y16 + 68;
	y15 += 4, y15_p_0 += 4){
	// y = 4, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 1) (68 / 68)
	for (x21 = x22, x21_p_0 = 0;
		x21 < x22 + 68;
		x21 += 68, x21_p_0 += 68){
		// y = 4, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (y, 1) (4 / 4)
		for (y = y15, yp_1 = y15_p_0, yp_0 = 0;
			y < y15 + 4;
			y += 4, yp_1 += 4, yp_0 += 4){
			// y = 4, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (x, 1) (68 / 68)
			for (x20 = x21, x20_p_1 = x21_p_0, x20_p_0 = 0;
				x20 < x21 + 68;
				x20 += 68, x20_p_1 += 68, x20_p_0 += 68){
				// y = 4, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (f, 2) (128 / 64)
				for (f = f10, fp_0 = 0;
					f < f10 + 128;
					f += 64, fp_0 += 64){
					// y = 4, x = 68, h = 1, w = 1, c = 256, f = 64
					// T (c, 8) (256 / 32)
					for (c15 = c16, c15_p_0 = 0;
						c15 < c16 + 256;
						c15 += 32, c15_p_0 += 32){
						// y = 4, x = 68, h = 1, w = 1, c = 32, f = 64
						// T (x, 68) (68 / 1)
						for (x = x20, xp_2 = x20_p_1, xp_1 = x20_p_0, xp_0 = 0;
							x < x20 + 68;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_152 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_153 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_154 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_155 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = 4, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c15, cp_1 = c15_p_0, cp_0 = 0;
										c < c15 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_152);
										mem_vec_152 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_153);
										mem_vec_153 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_154);
										mem_vec_154 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_155);
										mem_vec_155 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_156);
										mem_vec_156 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_157);
										mem_vec_157 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_158);
										mem_vec_158 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_159);
										mem_vec_159 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_160);
										mem_vec_160 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_161);
										mem_vec_161 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_162);
										mem_vec_162 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_163);
										mem_vec_163 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_164);
										mem_vec_164 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_165);
										mem_vec_165 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_166);
										mem_vec_166 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_167);
										mem_vec_167 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_152);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_153);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_154);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_155);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_156);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_157);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_158);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_159);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_160);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_161);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_162);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_163);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_164);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_165);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_166);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_167);
						}
					}
				}
			}
		}
	}
}


}