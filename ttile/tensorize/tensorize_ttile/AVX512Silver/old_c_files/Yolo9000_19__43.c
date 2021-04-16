#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (17, x); T (32, c);
  T (1, y); T (8, f); T (1, c);
  Lambda_apply y [((Iter 4), (Arg 3)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c640_p_0, c641_p_0, cp_1, c640_p_1, cp_2, c640, c641, f, fp_0, x, xp_0, y, yp_0, y480_p_0, yp_1, y480;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y481 = 0;
IND_TYPE x320 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c642 = 0;
IND_TYPE f320 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_6240 ,mem_vec_6241 ,mem_vec_6242 ,mem_vec_6243 ,mem_vec_6244 ,mem_vec_6245 ,mem_vec_6246 ,mem_vec_6247 ,mem_vec_6248 ,mem_vec_6249 ,mem_vec_6250 ,mem_vec_6251 ,mem_vec_6252 ,mem_vec_6253 ,mem_vec_6254 ,mem_vec_6255 ,mem_vec_6256 ,mem_vec_6257 ,mem_vec_6258 ,mem_vec_6259 ,mem_vec_6260 ,mem_vec_6261 ,mem_vec_6262 ,mem_vec_6263 ,mem_vec_6264 ,mem_vec_6265 ,mem_vec_6266 ,mem_vec_6267 ,mem_vec_6268 ,mem_vec_6269 ,mem_vec_6270 ,mem_vec_6271 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y480 = y481, y480_p_0 = 0;
		y480 < y481 + 12;
		y480 += 3, y480_p_0 += 3){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 1) (1024 / 1024)
		for (c641 = c642, c641_p_0 = 0;
			c641 < c642 + 1024;
			c641 += 1024, c641_p_0 += 1024){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (f, 8) (512 / 64)
			for (f = f320, fp_0 = 0;
				f < f320 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y480, yp_1 = y480_p_0, yp_0 = 0;
					y < y480 + 3;
					y += 3, yp_1 += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 32) (1024 / 32)
					for (c640 = c641, c640_p_1 = c641_p_0, c640_p_0 = 0;
						c640 < c641 + 1024;
						c640 += 32, c640_p_1 += 32, c640_p_0 += 32){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x320, xp_0 = 0;
							x < x320 + 17;
							x += 1, xp_0 += 1){
									mem_vec_6240 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6241 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_6242 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_6243 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_6244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_6247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_6248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_6250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_6251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c640, cp_2 = c640_p_1, cp_1 = c640_p_0, cp_0 = 0;
										c < c640 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6240);
										mem_vec_6240 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6241);
										mem_vec_6241 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6242);
										mem_vec_6242 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6243);
										mem_vec_6243 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6244);
										mem_vec_6244 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6245);
										mem_vec_6245 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6246);
										mem_vec_6246 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6247);
										mem_vec_6247 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6248);
										mem_vec_6248 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6249);
										mem_vec_6249 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6250);
										mem_vec_6250 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6251);
										mem_vec_6251 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6240);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6241);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6242);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6243);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6244);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6245);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6246);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6247);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6248);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6249);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6250);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6251);
						}
					}
				}
			}
		}
	}
	for (y480 = y481 + 12, y480_p_0 = 0;
		y480 < y481 + 12 + 5;
		y480 += 5, y480_p_0 += 5){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 1) (1024 / 1024)
		for (c641 = c642, c641_p_0 = 0;
			c641 < c642 + 1024;
			c641 += 1024, c641_p_0 += 1024){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (f, 8) (512 / 64)
			for (f = f320, fp_0 = 0;
				f < f320 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y480, yp_1 = y480_p_0, yp_0 = 0;
					y < y480 + 5;
					y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 32) (1024 / 32)
					for (c640 = c641, c640_p_1 = c641_p_0, c640_p_0 = 0;
						c640 < c641 + 1024;
						c640 += 32, c640_p_1 += 32, c640_p_0 += 32){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x320, xp_0 = 0;
							x < x320 + 17;
							x += 1, xp_0 += 1){
									mem_vec_6252 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6253 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_6254 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_6255 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_6256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_6259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_6260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_6262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_6263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_6264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_6266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_6267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_6268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_6269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_6270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_6271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c640, cp_2 = c640_p_1, cp_1 = c640_p_0, cp_0 = 0;
										c < c640 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6252);
										mem_vec_6252 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6253);
										mem_vec_6253 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6254);
										mem_vec_6254 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6255);
										mem_vec_6255 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6256);
										mem_vec_6256 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6257);
										mem_vec_6257 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6258);
										mem_vec_6258 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6259);
										mem_vec_6259 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6260);
										mem_vec_6260 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6261);
										mem_vec_6261 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6262);
										mem_vec_6262 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6263);
										mem_vec_6263 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6264);
										mem_vec_6264 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6265);
										mem_vec_6265 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6266);
										mem_vec_6266 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6267);
										mem_vec_6267 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6268);
										mem_vec_6268 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6269);
										mem_vec_6269 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6270);
										mem_vec_6270 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6271);
										mem_vec_6271 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6252);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6253);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6254);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6255);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6256);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6257);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6258);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6259);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6260);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6261);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6262);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6263);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6264);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6265);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6266);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6267);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6268);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6269);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6270);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6271);
						}
					}
				}
			}
		}
	}


}