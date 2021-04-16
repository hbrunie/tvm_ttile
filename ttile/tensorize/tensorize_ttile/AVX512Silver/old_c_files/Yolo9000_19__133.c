#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (17, x); T (16, c);
  Lambda_apply y [((Iter 3), (Arg 3)); ((Iter 2), (Arg 4))]; T (8, f);
  T (4, c); T (1, y)]
*/
IND_TYPE c, cp_0, c424_p_0, c425_p_0, cp_1, c424_p_1, cp_2, c424, c425, f, fp_0, x, xp_0, y, yp_0, y318_p_0, yp_1, y318;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y319 = 0;
IND_TYPE x212 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c426 = 0;
IND_TYPE f212 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_4176 ,mem_vec_4177 ,mem_vec_4178 ,mem_vec_4179 ,mem_vec_4180 ,mem_vec_4181 ,mem_vec_4182 ,mem_vec_4183 ,mem_vec_4184 ,mem_vec_4185 ,mem_vec_4186 ,mem_vec_4187 ,mem_vec_4188 ,mem_vec_4189 ,mem_vec_4190 ,mem_vec_4191 ,mem_vec_4192 ,mem_vec_4193 ,mem_vec_4194 ,mem_vec_4195 ,mem_vec_4196 ,mem_vec_4197 ,mem_vec_4198 ,mem_vec_4199 ,mem_vec_4200 ,mem_vec_4201 ,mem_vec_4202 ,mem_vec_4203 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y318 = y319, y318_p_0 = 0;
	y318 < y319 + 17;
	y318 += 17, y318_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (c, 4) (1024 / 256)
	for (c425 = c426, c425_p_0 = 0;
		c425 < c426 + 1024;
		c425 += 256, c425_p_0 += 256){
		// y = 17, x = 17, h = 1, w = 1, c = 256, f = 512
		// T (f, 8) (512 / 64)
		for (f = f212, fp_0 = 0;
			f < f212 + 512;
			f += 64, fp_0 += 64){
				for (y = y318, yp_1 = y318_p_0, yp_0 = 0;
					y < y318 + 9;
					y += 3, yp_1 += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (c, 16) (256 / 16)
					for (c424 = c425, c424_p_1 = c425_p_0, c424_p_0 = 0;
						c424 < c425 + 256;
						c424 += 16, c424_p_1 += 16, c424_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x212, xp_0 = 0;
							x < x212 + 17;
							x += 1, xp_0 += 1){
									mem_vec_4176 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4177 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4178 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_4179 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_4180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_4183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_4184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_4187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c424, cp_2 = c424_p_1, cp_1 = c424_p_0, cp_0 = 0;
										c < c424 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4176);
										mem_vec_4176 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4177);
										mem_vec_4177 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4178);
										mem_vec_4178 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4179);
										mem_vec_4179 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4180);
										mem_vec_4180 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4181);
										mem_vec_4181 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4182);
										mem_vec_4182 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4183);
										mem_vec_4183 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4184);
										mem_vec_4184 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4185);
										mem_vec_4185 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4186);
										mem_vec_4186 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4187);
										mem_vec_4187 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4176);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4177);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4178);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4179);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4180);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4181);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4182);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4183);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4184);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4185);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4186);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4187);
						}
					}
				}
				for (y = y318 + 9, yp_1 = y318_p_0, yp_0 = 0;
					y < y318 + 9 + 8;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (c, 16) (256 / 16)
					for (c424 = c425, c424_p_1 = c425_p_0, c424_p_0 = 0;
						c424 < c425 + 256;
						c424 += 16, c424_p_1 += 16, c424_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x212, xp_0 = 0;
							x < x212 + 17;
							x += 1, xp_0 += 1){
									mem_vec_4188 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4189 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4190 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_4191 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_4192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_4195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_4196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_4199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_4200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_4201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_4202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_4203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c424, cp_2 = c424_p_1, cp_1 = c424_p_0, cp_0 = 0;
										c < c424 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4188);
										mem_vec_4188 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4189);
										mem_vec_4189 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4190);
										mem_vec_4190 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4191);
										mem_vec_4191 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4192);
										mem_vec_4192 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4193);
										mem_vec_4193 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4194);
										mem_vec_4194 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4195);
										mem_vec_4195 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4196);
										mem_vec_4196 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4197);
										mem_vec_4197 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4198);
										mem_vec_4198 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4199);
										mem_vec_4199 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4200);
										mem_vec_4200 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4201);
										mem_vec_4201 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4202);
										mem_vec_4202 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4203);
										mem_vec_4203 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4188);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4189);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4190);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4191);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4192);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4193);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4194);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4195);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4196);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4197);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4198);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4199);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4200);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4201);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4202);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4203);
						}
					}
				}
		}
	}
}


}