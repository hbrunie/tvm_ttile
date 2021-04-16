#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (17, x); T (256, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (16, f);
  T (1, y)]
*/
IND_TYPE c, cp_0, c15_p_0, cp_1, c15, f, fp_0, x, xp_0, y, yp_0, y15_p_0, yp_1, y15;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y16 = 0;
IND_TYPE x10 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c16 = 0;
IND_TYPE f10 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,mem_vec_176 ,mem_vec_177 ,mem_vec_178 ,mem_vec_179 ,mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,mem_vec_184 ,mem_vec_185 ,mem_vec_186 ,mem_vec_187 ,mem_vec_188 ,mem_vec_189 ,mem_vec_190 ,mem_vec_191 ,mem_vec_192 ,mem_vec_193 ,mem_vec_194 ,mem_vec_195 ,mem_vec_196 ,mem_vec_197 ,mem_vec_198 ,mem_vec_199 ,mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y15 = y16, y15_p_0 = 0;
	y15 < y16 + 17;
	y15 += 17, y15_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (f, 16) (512 / 32)
	for (f = f10, fp_0 = 0;
		f < f10 + 512;
		f += 32, fp_0 += 32){
			for (y = y15, yp_1 = y15_p_0, yp_0 = 0;
				y < y15 + 8;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 256) (1024 / 4)
				for (c15 = c16, c15_p_0 = 0;
					c15 < c16 + 1024;
					c15 += 4, c15_p_0 += 4){
					// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
					// T (x, 17) (17 / 1)
					for (x = x10, xp_0 = 0;
						x < x10 + 17;
						x += 1, xp_0 += 1){
								mem_vec_170 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_171 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
								// T (c, 4) (4 / 1)
								for (c = c15, cp_1 = c15_p_0, cp_0 = 0;
									c < c15 + 4;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_170);
									mem_vec_170 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_171);
									mem_vec_171 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_172);
									mem_vec_172 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_173);
									mem_vec_173 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_174);
									mem_vec_174 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_175);
									mem_vec_175 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_176);
									mem_vec_176 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_177);
									mem_vec_177 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_178);
									mem_vec_178 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_179);
									mem_vec_179 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_180);
									mem_vec_180 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_181);
									mem_vec_181 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_182);
									mem_vec_182 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_183);
									mem_vec_183 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_184);
									mem_vec_184 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_185);
									mem_vec_185 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_170);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_171);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_172);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_173);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_174);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_175);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_176);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_177);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_178);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_179);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_180);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_181);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_182);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_183);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_184);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_185);
					}
				}
			}
			for (y = y15 + 8, yp_1 = y15_p_0, yp_0 = 0;
				y < y15 + 8 + 9;
				y += 9, yp_1 += 9, yp_0 += 9){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 256) (1024 / 4)
				for (c15 = c16, c15_p_0 = 0;
					c15 < c16 + 1024;
					c15 += 4, c15_p_0 += 4){
					// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
					// T (x, 17) (17 / 1)
					for (x = x10, xp_0 = 0;
						x < x10 + 17;
						x += 1, xp_0 += 1){
								mem_vec_186 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_187 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
								// T (c, 4) (4 / 1)
								for (c = c15, cp_1 = c15_p_0, cp_0 = 0;
									c < c15 + 4;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_186);
									mem_vec_186 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_187);
									mem_vec_187 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_188);
									mem_vec_188 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_189);
									mem_vec_189 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_190);
									mem_vec_190 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_191);
									mem_vec_191 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_192);
									mem_vec_192 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_193);
									mem_vec_193 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_194);
									mem_vec_194 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_195);
									mem_vec_195 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_196);
									mem_vec_196 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_197);
									mem_vec_197 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_198);
									mem_vec_198 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_199);
									mem_vec_199 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_200);
									mem_vec_200 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_201);
									mem_vec_201 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_202);
									mem_vec_202 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_203);
									mem_vec_203 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_186);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_187);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_188);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_189);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_190);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_191);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_192);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_193);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_194);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_195);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_196);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_197);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_198);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_199);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_200);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_201);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_202);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_203);
					}
				}
			}
	}
}


}