#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (112, x); Lambda_apply y [((Iter 1), (Arg 11)); ((Iter 3), (Arg 15))];
  T (1, c); T (2, y)]
*/
IND_TYPE c, cp_0, c24_p_0, cp_1, c24, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y24_p_0, yp_1, y24;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y25 = 0;
IND_TYPE x16 = 0;
IND_TYPE h16 = 0;
IND_TYPE w16 = 0;
IND_TYPE c25 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_176 ,mem_vec_177 ,mem_vec_178 ,mem_vec_179 ,mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,mem_vec_184 ,mem_vec_185 ,mem_vec_186 ,mem_vec_187 ,mem_vec_188 ,mem_vec_189 ,mem_vec_190 ,mem_vec_191 ,mem_vec_192 ,mem_vec_193 ,mem_vec_194 ,mem_vec_195 ,mem_vec_196 ,mem_vec_197 ,mem_vec_198 ,mem_vec_199 ,mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,mem_vec_208 ,mem_vec_209 ,mem_vec_210 ,mem_vec_211 ,mem_vec_212 ,mem_vec_213 ,mem_vec_214 ,mem_vec_215 ,mem_vec_216 ,mem_vec_217 ,mem_vec_218 ,mem_vec_219 ,mem_vec_220 ,mem_vec_221 ,mem_vec_222 ,mem_vec_223 ,mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (y, 2) (112 / 56)
for (y24 = y25, y24_p_0 = 0;
	y24 < y25 + 112;
	y24 += 56, y24_p_0 += 56){
	// y = 56, x = 112, h = 3, w = 3, c = 32, f = 32
	// T (c, 1) (32 / 32)
	for (c24 = c25, c24_p_0 = 0;
		c24 < c25 + 32;
		c24 += 32, c24_p_0 += 32){
			for (y = y24, yp_1 = y24_p_0, yp_0 = 0;
				y < y24 + 11;
				y += 11, yp_1 += 11, yp_0 += 11){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x16, xp_0 = 0;
					x < x16 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h16, hp_0 = 0;
						h < h16 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w16, wp_0 = 0;
							w < w16 + 3;
							w += 1, wp_0 += 1){
									mem_vec_176 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_177 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c24, cp_1 = c24_p_0, cp_0 = 0;
										c < c24 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_176);
										mem_vec_176 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_177);
										mem_vec_177 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_178);
										mem_vec_178 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_179);
										mem_vec_179 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_180);
										mem_vec_180 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_181);
										mem_vec_181 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_182);
										mem_vec_182 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_183);
										mem_vec_183 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_184);
										mem_vec_184 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_185);
										mem_vec_185 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_186);
										mem_vec_186 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_187);
										mem_vec_187 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_188);
										mem_vec_188 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_189);
										mem_vec_189 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_190);
										mem_vec_190 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_191);
										mem_vec_191 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_192);
										mem_vec_192 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_193);
										mem_vec_193 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_194);
										mem_vec_194 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_195);
										mem_vec_195 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_196);
										mem_vec_196 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_197);
										mem_vec_197 = vec_34;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_176);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_177);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_178);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_179);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_180);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_181);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_182);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_183);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_184);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_185);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_186);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_187);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_188);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_189);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_190);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_191);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_192);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_193);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_194);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_195);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_196);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_197);
						}
					}
				}
			}
			for (y = y24 + 11, yp_1 = y24_p_0, yp_0 = 0;
				y < y24 + 11 + 45;
				y += 15, yp_1 += 15, yp_0 += 15){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x16, xp_0 = 0;
					x < x16 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h16, hp_0 = 0;
						h < h16 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w16, wp_0 = 0;
							w < w16 + 3;
							w += 1, wp_0 += 1){
									mem_vec_198 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_199 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									mem_vec_226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
									mem_vec_227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c24, cp_1 = c24_p_0, cp_0 = 0;
										c < c24 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_198);
										mem_vec_198 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_199);
										mem_vec_199 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_200);
										mem_vec_200 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_201);
										mem_vec_201 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_202);
										mem_vec_202 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_203);
										mem_vec_203 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_204);
										mem_vec_204 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_205);
										mem_vec_205 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_206);
										mem_vec_206 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_207);
										mem_vec_207 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_208);
										mem_vec_208 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_209);
										mem_vec_209 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_210);
										mem_vec_210 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_211);
										mem_vec_211 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_212);
										mem_vec_212 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_213);
										mem_vec_213 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_214);
										mem_vec_214 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_215);
										mem_vec_215 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_216);
										mem_vec_216 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_217);
										mem_vec_217 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_218);
										mem_vec_218 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_219);
										mem_vec_219 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_220);
										mem_vec_220 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_221);
										mem_vec_221 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_222);
										mem_vec_222 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_223);
										mem_vec_223 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_224);
										mem_vec_224 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_225);
										mem_vec_225 = vec_43;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
										vec_45 = _mm512_set1_ps(scal_14);


										vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_226);
										mem_vec_226 = vec_44;



										vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_227);
										mem_vec_227 = vec_46;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_198);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_199);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_200);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_201);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_202);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_203);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_204);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_205);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_206);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_207);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_208);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_209);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_210);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_211);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_212);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_213);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_214);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_215);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_216);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_217);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_218);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_219);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_220);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_221);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_222);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_223);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_224);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_225);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_226);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_227);
						}
					}
				}
			}
	}
}


}