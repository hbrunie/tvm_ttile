#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (17, x); T (4, c);
  T (4, f); T (2, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]]
*/
IND_TYPE c, cp_0, c6_p_0, cp_1, c6, f, fp_0, x, xp_0, x8_p_0, x9_p_0, xp_1, x8_p_1, xp_2, x8, x9, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y4 = 0;
IND_TYPE x10 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c7 = 0;
IND_TYPE f4 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_100 ,mem_vec_101 ,mem_vec_102 ,mem_vec_103 ,mem_vec_104 ,mem_vec_105 ,mem_vec_106 ,mem_vec_107 ,mem_vec_108 ,mem_vec_109 ,mem_vec_110 ,mem_vec_111 ,mem_vec_112 ,mem_vec_113 ,mem_vec_114 ,mem_vec_115 ,mem_vec_116 ,mem_vec_117 ,mem_vec_118 ,mem_vec_119 ,mem_vec_120 ,mem_vec_121 ,mem_vec_122 ,mem_vec_123 ,mem_vec_124 ,mem_vec_125 ,mem_vec_126 ,mem_vec_127 ,mem_vec_128 ,mem_vec_129 ,mem_vec_130 ,mem_vec_131 ,mem_vec_132 ,mem_vec_133 ,mem_vec_134 ,mem_vec_135 ,mem_vec_136 ,mem_vec_137 ,mem_vec_138 ,mem_vec_139 ,mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,mem_vec_92 ,mem_vec_93 ,mem_vec_94 ,mem_vec_95 ,mem_vec_96 ,mem_vec_97 ,mem_vec_98 ,mem_vec_99 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y = y4, yp_0 = 0;
		y < y4 + 6;
		y += 6, yp_0 += 6){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x9 = x10, x9_p_0 = 0;
			x9 < x10 + 34;
			x9 += 34, x9_p_0 += 34){
			// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (x, 2) (34 / 17)
			for (x8 = x9, x8_p_1 = x9_p_0, x8_p_0 = 0;
				x8 < x9 + 34;
				x8 += 17, x8_p_1 += 17, x8_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
				// T (f, 4) (256 / 64)
				for (f = f4, fp_0 = 0;
					f < f4 + 256;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 4) (512 / 128)
					for (c6 = c7, c6_p_0 = 0;
						c6 < c7 + 512;
						c6 += 128, c6_p_0 += 128){
						// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
						// T (x, 17) (17 / 1)
						for (x = x8, xp_2 = x8_p_1, xp_1 = x8_p_0, xp_0 = 0;
							x < x8 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_92 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_93 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_94 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_95 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_96 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_97 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_98 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_99 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
									// T (c, 128) (128 / 1)
									for (c = c6, cp_1 = c6_p_0, cp_0 = 0;
										c < c6 + 128;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_92);
										mem_vec_92 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_93);
										mem_vec_93 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_94);
										mem_vec_94 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_95);
										mem_vec_95 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_96);
										mem_vec_96 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_97);
										mem_vec_97 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_98);
										mem_vec_98 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_99);
										mem_vec_99 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_100);
										mem_vec_100 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_101);
										mem_vec_101 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_102);
										mem_vec_102 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_103);
										mem_vec_103 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_104);
										mem_vec_104 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_105);
										mem_vec_105 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_106);
										mem_vec_106 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_107);
										mem_vec_107 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_108);
										mem_vec_108 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_109);
										mem_vec_109 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_110);
										mem_vec_110 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_111);
										mem_vec_111 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_112);
										mem_vec_112 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_113);
										mem_vec_113 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_114);
										mem_vec_114 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_115);
										mem_vec_115 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_92);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_93);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_94);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_95);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_96);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_97);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_98);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_99);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_100);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_101);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_102);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_103);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_104);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_105);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_106);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_107);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_108);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_109);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_110);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_111);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_112);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_113);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_114);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_115);
						}
					}
				}
			}
		}
	}
	for (y = y4 + 6, yp_0 = 0;
		y < y4 + 6 + 28;
		y += 7, yp_0 += 7){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x9 = x10, x9_p_0 = 0;
			x9 < x10 + 34;
			x9 += 34, x9_p_0 += 34){
			// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (x, 2) (34 / 17)
			for (x8 = x9, x8_p_1 = x9_p_0, x8_p_0 = 0;
				x8 < x9 + 34;
				x8 += 17, x8_p_1 += 17, x8_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
				// T (f, 4) (256 / 64)
				for (f = f4, fp_0 = 0;
					f < f4 + 256;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 4) (512 / 128)
					for (c6 = c7, c6_p_0 = 0;
						c6 < c7 + 512;
						c6 += 128, c6_p_0 += 128){
						// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
						// T (x, 17) (17 / 1)
						for (x = x8, xp_2 = x8_p_1, xp_1 = x8_p_0, xp_0 = 0;
							x < x8 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
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
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
									// T (c, 128) (128 / 1)
									for (c = c6, cp_1 = c6_p_0, cp_0 = 0;
										c < c6 + 128;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
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
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_120);
										mem_vec_120 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_121);
										mem_vec_121 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_122);
										mem_vec_122 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_123);
										mem_vec_123 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_124);
										mem_vec_124 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_125);
										mem_vec_125 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_126);
										mem_vec_126 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_127);
										mem_vec_127 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_128);
										mem_vec_128 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_129);
										mem_vec_129 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_130);
										mem_vec_130 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_131);
										mem_vec_131 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_132);
										mem_vec_132 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_133);
										mem_vec_133 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_134);
										mem_vec_134 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_135);
										mem_vec_135 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_136);
										mem_vec_136 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_137);
										mem_vec_137 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_138);
										mem_vec_138 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_139);
										mem_vec_139 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
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