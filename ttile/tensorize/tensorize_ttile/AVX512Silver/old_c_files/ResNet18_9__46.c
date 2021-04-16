#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (14, x); T (8, c); T (1, f); T (1, y); T (8, f)]
*/
IND_TYPE c, cp_0, c15_p_0, cp_1, c15, f, fp_0, f15_p_0, fp_1, f15, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y10 = 0;
IND_TYPE x10 = 0;
IND_TYPE h10 = 0;
IND_TYPE w8 = 0;
IND_TYPE c16 = 0;
IND_TYPE f16 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_100 ,mem_vec_101 ,mem_vec_102 ,mem_vec_103 ,mem_vec_104 ,mem_vec_105 ,mem_vec_106 ,mem_vec_107 ,mem_vec_108 ,mem_vec_109 ,mem_vec_110 ,mem_vec_111 ,mem_vec_112 ,mem_vec_113 ,mem_vec_114 ,mem_vec_115 ,mem_vec_116 ,mem_vec_117 ,mem_vec_118 ,mem_vec_119 ,mem_vec_120 ,mem_vec_121 ,mem_vec_122 ,mem_vec_123 ,mem_vec_124 ,mem_vec_125 ,mem_vec_98 ,mem_vec_99 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 8) (256 / 32)
for (f15 = f16, f15_p_0 = 0;
	f15 < f16 + 256;
	f15 += 32, f15_p_0 += 32){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 32
	// T (y, 1) (14 / 14)
	for (y = y10, yp_0 = 0;
		y < y10 + 14;
		y += 14, yp_0 += 14){
		// y = 14, x = 14, h = 3, w = 3, c = 256, f = 32
		// T (f, 1) (32 / 32)
		for (f = f15, fp_1 = f15_p_0, fp_0 = 0;
			f < f15 + 32;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 14, x = 14, h = 3, w = 3, c = 256, f = 32
			// T (c, 8) (256 / 32)
			for (c15 = c16, c15_p_0 = 0;
				c15 < c16 + 256;
				c15 += 32, c15_p_0 += 32){
				// y = 14, x = 14, h = 3, w = 3, c = 32, f = 32
				// T (x, 14) (14 / 1)
				for (x = x10, xp_0 = 0;
					x < x10 + 14;
					x += 1, xp_0 += 1){
					// y = 14, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h10, hp_0 = 0;
						h < h10 + 3;
						h += 1, hp_0 += 1){
						// y = 14, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w8, wp_0 = 0;
							w < w8 + 3;
							w += 1, wp_0 += 1){
									mem_vec_98 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_99 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = 14, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c15, cp_1 = c15_p_0, cp_0 = 0;
										c < c15 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_98);
										mem_vec_98 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_99);
										mem_vec_99 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_100);
										mem_vec_100 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_101);
										mem_vec_101 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_102);
										mem_vec_102 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_103);
										mem_vec_103 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_104);
										mem_vec_104 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_105);
										mem_vec_105 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_106);
										mem_vec_106 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_107);
										mem_vec_107 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_108);
										mem_vec_108 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_109);
										mem_vec_109 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_110);
										mem_vec_110 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_111);
										mem_vec_111 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_112);
										mem_vec_112 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_113);
										mem_vec_113 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_114);
										mem_vec_114 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_115);
										mem_vec_115 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_116);
										mem_vec_116 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_117);
										mem_vec_117 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_118);
										mem_vec_118 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_119);
										mem_vec_119 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_120);
										mem_vec_120 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_121);
										mem_vec_121 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_122);
										mem_vec_122 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_123);
										mem_vec_123 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_124);
										mem_vec_124 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_125);
										mem_vec_125 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_98);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_99);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_100);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_101);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_102);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_103);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_104);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_105);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_106);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_107);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_108);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_109);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_110);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_111);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_112);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_113);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_114);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_115);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_116);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_117);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_118);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_119);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_120);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_121);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_122);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_123);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_124);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_125);
						}
					}
				}
			}
		}
	}
}


}