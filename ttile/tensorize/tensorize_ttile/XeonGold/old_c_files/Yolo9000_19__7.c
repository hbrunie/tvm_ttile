#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (17, x); T (128, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (16, f);
  T (1, y)]
*/
IND_TYPE c, cp_0, c12_p_0, cp_1, c12, f, fp_0, x, xp_0, y, yp_0, y12_p_0, yp_1, y12;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y13 = 0;
IND_TYPE x8 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c13 = 0;
IND_TYPE f8 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_136 ,mem_vec_137 ,mem_vec_138 ,mem_vec_139 ,mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,mem_vec_144 ,mem_vec_145 ,mem_vec_146 ,mem_vec_147 ,mem_vec_148 ,mem_vec_149 ,mem_vec_150 ,mem_vec_151 ,mem_vec_152 ,mem_vec_153 ,mem_vec_154 ,mem_vec_155 ,mem_vec_156 ,mem_vec_157 ,mem_vec_158 ,mem_vec_159 ,mem_vec_160 ,mem_vec_161 ,mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,mem_vec_168 ,mem_vec_169 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y12 = y13, y12_p_0 = 0;
	y12 < y13 + 17;
	y12 += 17, y12_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (f, 16) (512 / 32)
	for (f = f8, fp_0 = 0;
		f < f8 + 512;
		f += 32, fp_0 += 32){
			for (y = y12, yp_1 = y12_p_0, yp_0 = 0;
				y < y12 + 8;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 128) (1024 / 8)
				for (c12 = c13, c12_p_0 = 0;
					c12 < c13 + 1024;
					c12 += 8, c12_p_0 += 8){
					// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 32
					// T (x, 17) (17 / 1)
					for (x = x8, xp_0 = 0;
						x < x8 + 17;
						x += 1, xp_0 += 1){
								mem_vec_136 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_137 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
								// T (c, 8) (8 / 1)
								for (c = c12, cp_1 = c12_p_0, cp_0 = 0;
									c < c12 + 8;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_136);
									mem_vec_136 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_137);
									mem_vec_137 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_138);
									mem_vec_138 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_139);
									mem_vec_139 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_140);
									mem_vec_140 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_141);
									mem_vec_141 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_142);
									mem_vec_142 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_143);
									mem_vec_143 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_144);
									mem_vec_144 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_145);
									mem_vec_145 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_146);
									mem_vec_146 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_147);
									mem_vec_147 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_148);
									mem_vec_148 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_149);
									mem_vec_149 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_150);
									mem_vec_150 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_151);
									mem_vec_151 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_136);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_137);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_138);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_139);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_140);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_141);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_142);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_143);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_144);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_145);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_146);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_147);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_148);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_149);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_150);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_151);
					}
				}
			}
			for (y = y12 + 8, yp_1 = y12_p_0, yp_0 = 0;
				y < y12 + 8 + 9;
				y += 9, yp_1 += 9, yp_0 += 9){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 128) (1024 / 8)
				for (c12 = c13, c12_p_0 = 0;
					c12 < c13 + 1024;
					c12 += 8, c12_p_0 += 8){
					// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 32
					// T (x, 17) (17 / 1)
					for (x = x8, xp_0 = 0;
						x < x8 + 17;
						x += 1, xp_0 += 1){
								mem_vec_152 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_153 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
								// T (c, 8) (8 / 1)
								for (c = c12, cp_1 = c12_p_0, cp_0 = 0;
									c < c12 + 8;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_152);
									mem_vec_152 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_153);
									mem_vec_153 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_154);
									mem_vec_154 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_155);
									mem_vec_155 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_156);
									mem_vec_156 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_157);
									mem_vec_157 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_158);
									mem_vec_158 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_159);
									mem_vec_159 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_160);
									mem_vec_160 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_161);
									mem_vec_161 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_162);
									mem_vec_162 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_163);
									mem_vec_163 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_164);
									mem_vec_164 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_165);
									mem_vec_165 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_166);
									mem_vec_166 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_167);
									mem_vec_167 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_168);
									mem_vec_168 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_169);
									mem_vec_169 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_152);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_153);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_154);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_155);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_156);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_157);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_158);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_159);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_160);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_161);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_162);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_163);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_164);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_165);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_166);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_167);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_168);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_169);
					}
				}
			}
	}
}


}