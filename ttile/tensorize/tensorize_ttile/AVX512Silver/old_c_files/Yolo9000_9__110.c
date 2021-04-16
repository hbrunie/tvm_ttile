#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (256, c); Hoist_vars [c]; T (34, x); T (1, c);
  T (2, f); T (1, x); T (17, y); T (2, x); T (1, y)]
*/
IND_TYPE c, cp_0, c168_p_0, cp_1, c168, f, fp_0, x, xp_0, x224_p_0, x225_p_0, xp_1, x224_p_1, xp_2, x224, x225, y, yp_0, y168_p_0, yp_1, y168;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y169 = 0;
IND_TYPE x226 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c169 = 0;
IND_TYPE f112 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_2120 ,mem_vec_2121 ,mem_vec_2122 ,mem_vec_2123 ,mem_vec_2124 ,mem_vec_2125 ,mem_vec_2126 ,mem_vec_2127 ,mem_vec_2128 ,mem_vec_2129 ,mem_vec_2130 ,mem_vec_2131 ,mem_vec_2132 ,mem_vec_2133 ,mem_vec_2134 ,mem_vec_2135 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 1) (68 / 68)
for (y168 = y169, y168_p_0 = 0;
	y168 < y169 + 68;
	y168 += 68, y168_p_0 += 68){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 2) (68 / 34)
	for (x225 = x226, x225_p_0 = 0;
		x225 < x226 + 68;
		x225 += 34, x225_p_0 += 34){
		// y = 68, x = 34, h = 1, w = 1, c = 256, f = 128
		// T (y, 17) (68 / 4)
		for (y = y168, yp_1 = y168_p_0, yp_0 = 0;
			y < y168 + 68;
			y += 4, yp_1 += 4, yp_0 += 4){
			// y = 4, x = 34, h = 1, w = 1, c = 256, f = 128
			// T (x, 1) (34 / 34)
			for (x224 = x225, x224_p_1 = x225_p_0, x224_p_0 = 0;
				x224 < x225 + 34;
				x224 += 34, x224_p_1 += 34, x224_p_0 += 34){
				// y = 4, x = 34, h = 1, w = 1, c = 256, f = 128
				// T (f, 2) (128 / 64)
				for (f = f112, fp_0 = 0;
					f < f112 + 128;
					f += 64, fp_0 += 64){
					// y = 4, x = 34, h = 1, w = 1, c = 256, f = 64
					// T (c, 1) (256 / 256)
					for (c168 = c169, c168_p_0 = 0;
						c168 < c169 + 256;
						c168 += 256, c168_p_0 += 256){
						// y = 4, x = 34, h = 1, w = 1, c = 256, f = 64
						// T (x, 34) (34 / 1)
						for (x = x224, xp_2 = x224_p_1, xp_1 = x224_p_0, xp_0 = 0;
							x < x224 + 34;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_2120 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2121 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2122 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_2123 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_2124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_2126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_2127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_2128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_2129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_2130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_2131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_2132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_2133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_2134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_2135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = 4, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c168, cp_1 = c168_p_0, cp_0 = 0;
										c < c168 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2120);
										mem_vec_2120 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2121);
										mem_vec_2121 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2122);
										mem_vec_2122 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2123);
										mem_vec_2123 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2124);
										mem_vec_2124 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2125);
										mem_vec_2125 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2126);
										mem_vec_2126 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2127);
										mem_vec_2127 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2128);
										mem_vec_2128 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2129);
										mem_vec_2129 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2130);
										mem_vec_2130 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2131);
										mem_vec_2131 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2132);
										mem_vec_2132 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2133);
										mem_vec_2133 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2134);
										mem_vec_2134 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2135);
										mem_vec_2135 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2120);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2121);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2122);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2123);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2124);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2125);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2126);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2127);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2128);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2129);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2130);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2131);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2132);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2133);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2134);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2135);
						}
					}
				}
			}
		}
	}
}


}