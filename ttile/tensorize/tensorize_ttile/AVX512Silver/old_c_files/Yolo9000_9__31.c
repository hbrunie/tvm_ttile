#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (256, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (2, f); T (1, x); T (17, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c6_p_0, cp_1, c6, f, fp_0, x, xp_0, x8_p_0, x9_p_0, xp_1, x8_p_1, xp_2, x8, x9, y, yp_0, y6_p_0, yp_1, y6;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y7 = 0;
IND_TYPE x10 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c7 = 0;
IND_TYPE f4 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_104 ,mem_vec_105 ,mem_vec_106 ,mem_vec_107 ,mem_vec_108 ,mem_vec_109 ,mem_vec_110 ,mem_vec_111 ,mem_vec_112 ,mem_vec_113 ,mem_vec_114 ,mem_vec_115 ,mem_vec_116 ,mem_vec_117 ,mem_vec_118 ,mem_vec_119 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 1) (68 / 68)
for (y6 = y7, y6_p_0 = 0;
	y6 < y7 + 68;
	y6 += 68, y6_p_0 += 68){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 1) (68 / 68)
	for (x9 = x10, x9_p_0 = 0;
		x9 < x10 + 68;
		x9 += 68, x9_p_0 += 68){
		// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (y, 17) (68 / 4)
		for (y = y6, yp_1 = y6_p_0, yp_0 = 0;
			y < y6 + 68;
			y += 4, yp_1 += 4, yp_0 += 4){
			// y = 4, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (x, 1) (68 / 68)
			for (x8 = x9, x8_p_1 = x9_p_0, x8_p_0 = 0;
				x8 < x9 + 68;
				x8 += 68, x8_p_1 += 68, x8_p_0 += 68){
				// y = 4, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (f, 2) (128 / 64)
				for (f = f4, fp_0 = 0;
					f < f4 + 128;
					f += 64, fp_0 += 64){
					// y = 4, x = 68, h = 1, w = 1, c = 256, f = 64
					// T (c, 1) (256 / 256)
					for (c6 = c7, c6_p_0 = 0;
						c6 < c7 + 256;
						c6 += 256, c6_p_0 += 256){
						// y = 4, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (x, 68) (68 / 1)
						for (x = x8, xp_2 = x8_p_1, xp_1 = x8_p_0, xp_0 = 0;
							x < x8 + 68;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_104 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_105 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_106 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_107 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = 4, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c6, cp_1 = c6_p_0, cp_0 = 0;
										c < c6 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_104);
										mem_vec_104 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_105);
										mem_vec_105 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_106);
										mem_vec_106 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_107);
										mem_vec_107 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_108);
										mem_vec_108 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_109);
										mem_vec_109 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_110);
										mem_vec_110 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_111);
										mem_vec_111 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_112);
										mem_vec_112 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_113);
										mem_vec_113 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_114);
										mem_vec_114 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_115);
										mem_vec_115 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_116);
										mem_vec_116 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_117);
										mem_vec_117 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_118);
										mem_vec_118 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_119);
										mem_vec_119 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_104);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_105);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_106);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_107);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_108);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_109);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_110);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_111);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_112);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_113);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_114);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_115);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_116);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_117);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_118);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_119);
						}
					}
				}
			}
		}
	}
}


}