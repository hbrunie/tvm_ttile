#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (17, x); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 3), (Arg 9))]; T (8, f);
  T (64, c); T (1, x)]
*/
IND_TYPE c, cp_0, c18_p_0, cp_1, c18, f, fp_0, x, xp_0, x24_p_0, x25_p_0, xp_1, x24_p_1, xp_2, x24, x25, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y12 = 0;
IND_TYPE x26 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c19 = 0;
IND_TYPE f12 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_192 ,mem_vec_193 ,mem_vec_194 ,mem_vec_195 ,mem_vec_196 ,mem_vec_197 ,mem_vec_198 ,mem_vec_199 ,mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,mem_vec_208 ,mem_vec_209 ,mem_vec_210 ,mem_vec_211 ,mem_vec_212 ,mem_vec_213 ,mem_vec_214 ,mem_vec_215 ,mem_vec_216 ,mem_vec_217 ,mem_vec_218 ,mem_vec_219 ,mem_vec_220 ,mem_vec_221 ,mem_vec_222 ,mem_vec_223 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 1) (34 / 34)
for (x25 = x26, x25_p_0 = 0;
	x25 < x26 + 34;
	x25 += 34, x25_p_0 += 34){
	// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
	// T (c, 64) (512 / 8)
	for (c18 = c19, c18_p_0 = 0;
		c18 < c19 + 512;
		c18 += 8, c18_p_0 += 8){
		// y = 34, x = 34, h = 1, w = 1, c = 8, f = 256
		// T (f, 8) (256 / 32)
		for (f = f12, fp_0 = 0;
			f < f12 + 256;
			f += 32, fp_0 += 32){
				for (y = y12, yp_0 = 0;
					y < y12 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 1, w = 1, c = 8, f = 32
					// T (x, 2) (34 / 17)
					for (x24 = x25, x24_p_1 = x25_p_0, x24_p_0 = 0;
						x24 < x25 + 34;
						x24 += 17, x24_p_1 += 17, x24_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 32
						// T (x, 17) (17 / 1)
						for (x = x24, xp_2 = x24_p_1, xp_1 = x24_p_0, xp_0 = 0;
							x < x24 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_192 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_193 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c18, cp_1 = c18_p_0, cp_0 = 0;
										c < c18 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_192);
										mem_vec_192 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_193);
										mem_vec_193 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_194);
										mem_vec_194 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_195);
										mem_vec_195 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_196);
										mem_vec_196 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_197);
										mem_vec_197 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_198);
										mem_vec_198 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_199);
										mem_vec_199 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_200);
										mem_vec_200 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_201);
										mem_vec_201 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_202);
										mem_vec_202 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_203);
										mem_vec_203 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_204);
										mem_vec_204 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_205);
										mem_vec_205 = vec_22;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_192);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_193);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_194);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_195);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_196);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_197);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_198);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_199);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_200);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_201);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_202);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_203);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_204);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_205);
						}
					}
				}
				for (y = y12 + 7, yp_0 = 0;
					y < y12 + 7 + 27;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 1, w = 1, c = 8, f = 32
					// T (x, 2) (34 / 17)
					for (x24 = x25, x24_p_1 = x25_p_0, x24_p_0 = 0;
						x24 < x25 + 34;
						x24 += 17, x24_p_1 += 17, x24_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 32
						// T (x, 17) (17 / 1)
						for (x = x24, xp_2 = x24_p_1, xp_1 = x24_p_0, xp_0 = 0;
							x < x24 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_206 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_207 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c18, cp_1 = c18_p_0, cp_0 = 0;
										c < c18 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_206);
										mem_vec_206 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_207);
										mem_vec_207 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_208);
										mem_vec_208 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_209);
										mem_vec_209 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_210);
										mem_vec_210 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_211);
										mem_vec_211 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_212);
										mem_vec_212 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_213);
										mem_vec_213 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_214);
										mem_vec_214 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_215);
										mem_vec_215 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_216);
										mem_vec_216 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_217);
										mem_vec_217 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_218);
										mem_vec_218 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_219);
										mem_vec_219 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_220);
										mem_vec_220 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_221);
										mem_vec_221 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_222);
										mem_vec_222 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_223);
										mem_vec_223 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_206);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_207);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_208);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_209);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_210);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_211);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_212);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_213);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_214);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_215);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_216);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_217);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_218);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_219);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_220);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_221);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_222);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_223);
						}
					}
				}
		}
	}
}


}