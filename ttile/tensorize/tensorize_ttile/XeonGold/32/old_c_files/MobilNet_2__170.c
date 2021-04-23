#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (16, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (4, c); T (1, x); T (8, y); T (2, x)]
*/
IND_TYPE c, cp_0, c15_p_0, cp_1, c15, h, hp_0, w, wp_0, x, xp_0, x20_p_0, x21_p_0, xp_1, x20_p_1, xp_2, x20, x21, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y10 = 0;
IND_TYPE x22 = 0;
IND_TYPE h10 = 0;
IND_TYPE w9 = 0;
IND_TYPE c16 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_116 ,mem_vec_117 ,mem_vec_118 ,mem_vec_119 ,mem_vec_120 ,mem_vec_121 ,mem_vec_122 ,mem_vec_123 ,mem_vec_124 ,mem_vec_125 ,mem_vec_126 ,mem_vec_127 ,mem_vec_128 ,mem_vec_129 ,mem_vec_130 ,mem_vec_131 ,mem_vec_132 ,mem_vec_133 ,mem_vec_134 ,mem_vec_135 ,mem_vec_136 ,mem_vec_137 ,mem_vec_138 ,mem_vec_139 ,mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 2) (56 / 28)
for (x21 = x22, x21_p_0 = 0;
	x21 < x22 + 56;
	x21 += 28, x21_p_0 += 28){
	// y = 56, x = 28, h = 3, w = 3, c = 64, f = 64
	// T (y, 8) (56 / 7)
	for (y = y10, yp_0 = 0;
		y < y10 + 56;
		y += 7, yp_0 += 7){
		// y = 7, x = 28, h = 3, w = 3, c = 64, f = 64
		// T (x, 1) (28 / 28)
		for (x20 = x21, x20_p_1 = x21_p_0, x20_p_0 = 0;
			x20 < x21 + 28;
			x20 += 28, x20_p_1 += 28, x20_p_0 += 28){
			// y = 7, x = 28, h = 3, w = 3, c = 64, f = 64
			// T (c, 4) (64 / 16)
			for (c15 = c16, c15_p_0 = 0;
				c15 < c16 + 64;
				c15 += 16, c15_p_0 += 16){
				// y = 7, x = 28, h = 3, w = 3, c = 16, f = 64
				// T (w, 3) (3 / 1)
				for (w = w9, wp_0 = 0;
					w < w9 + 3;
					w += 1, wp_0 += 1){
					// y = 7, x = 28, h = 3, w = 1, c = 16, f = 64
					// T (x, 28) (28 / 1)
					for (x = x20, xp_2 = x20_p_1, xp_1 = x20_p_0, xp_0 = 0;
						x < x20 + 28;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
						// y = 7, x = 1, h = 3, w = 1, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h10, hp_0 = 0;
							h < h10 + 3;
							h += 1, hp_0 += 1){
									mem_vec_116 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_117 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_118 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_119 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = 7, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c15, cp_1 = c15_p_0, cp_0 = 0;
										c < c15 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_116);
										mem_vec_116 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_117);
										mem_vec_117 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_118);
										mem_vec_118 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_119);
										mem_vec_119 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_120);
										mem_vec_120 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_121);
										mem_vec_121 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_122);
										mem_vec_122 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_123);
										mem_vec_123 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_124);
										mem_vec_124 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_125);
										mem_vec_125 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_126);
										mem_vec_126 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_127);
										mem_vec_127 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_128);
										mem_vec_128 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_129);
										mem_vec_129 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_130);
										mem_vec_130 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_131);
										mem_vec_131 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_132);
										mem_vec_132 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_133);
										mem_vec_133 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_134);
										mem_vec_134 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_135);
										mem_vec_135 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_136);
										mem_vec_136 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_137);
										mem_vec_137 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_138);
										mem_vec_138 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_139);
										mem_vec_139 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_140);
										mem_vec_140 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_141);
										mem_vec_141 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_142);
										mem_vec_142 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_143);
										mem_vec_143 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_116);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_117);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_118);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_119);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_120);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_121);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_122);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_123);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_124);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_125);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_126);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_127);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_128);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_129);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_130);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_131);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_132);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_133);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_134);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_135);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_136);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_137);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_138);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_139);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_140);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_141);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_142);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_143);
						}
					}
				}
			}
		}
	}
}


}