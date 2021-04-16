#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (17, x); T (8, c);
  T (1, y); T (8, f); T (1, c);
  Lambda_apply y [((Iter 4), (Arg 3)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c632_p_0, c633_p_0, cp_1, c632_p_1, cp_2, c632, c633, f, fp_0, x, xp_0, y, yp_0, y474_p_0, yp_1, y474;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y475 = 0;
IND_TYPE x316 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c634 = 0;
IND_TYPE f316 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_6176 ,mem_vec_6177 ,mem_vec_6178 ,mem_vec_6179 ,mem_vec_6180 ,mem_vec_6181 ,mem_vec_6182 ,mem_vec_6183 ,mem_vec_6184 ,mem_vec_6185 ,mem_vec_6186 ,mem_vec_6187 ,mem_vec_6188 ,mem_vec_6189 ,mem_vec_6190 ,mem_vec_6191 ,mem_vec_6192 ,mem_vec_6193 ,mem_vec_6194 ,mem_vec_6195 ,mem_vec_6196 ,mem_vec_6197 ,mem_vec_6198 ,mem_vec_6199 ,mem_vec_6200 ,mem_vec_6201 ,mem_vec_6202 ,mem_vec_6203 ,mem_vec_6204 ,mem_vec_6205 ,mem_vec_6206 ,mem_vec_6207 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y474 = y475, y474_p_0 = 0;
		y474 < y475 + 12;
		y474 += 3, y474_p_0 += 3){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 1) (1024 / 1024)
		for (c633 = c634, c633_p_0 = 0;
			c633 < c634 + 1024;
			c633 += 1024, c633_p_0 += 1024){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (f, 8) (512 / 64)
			for (f = f316, fp_0 = 0;
				f < f316 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y474, yp_1 = y474_p_0, yp_0 = 0;
					y < y474 + 3;
					y += 3, yp_1 += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 8) (1024 / 128)
					for (c632 = c633, c632_p_1 = c633_p_0, c632_p_0 = 0;
						c632 < c633 + 1024;
						c632 += 128, c632_p_1 += 128, c632_p_0 += 128){
						// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
						// T (x, 17) (17 / 1)
						for (x = x316, xp_0 = 0;
							x < x316 + 17;
							x += 1, xp_0 += 1){
									mem_vec_6176 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6177 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_6178 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_6179 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_6180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_6183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_6184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_6186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_6187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
									// T (c, 128) (128 / 1)
									for (c = c632, cp_2 = c632_p_1, cp_1 = c632_p_0, cp_0 = 0;
										c < c632 + 128;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6176);
										mem_vec_6176 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6177);
										mem_vec_6177 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6178);
										mem_vec_6178 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6179);
										mem_vec_6179 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6180);
										mem_vec_6180 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6181);
										mem_vec_6181 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6182);
										mem_vec_6182 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6183);
										mem_vec_6183 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6184);
										mem_vec_6184 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6185);
										mem_vec_6185 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6186);
										mem_vec_6186 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6187);
										mem_vec_6187 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6176);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6177);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6178);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6179);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6180);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6181);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6182);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6183);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6184);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6185);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6186);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6187);
						}
					}
				}
			}
		}
	}
	for (y474 = y475 + 12, y474_p_0 = 0;
		y474 < y475 + 12 + 5;
		y474 += 5, y474_p_0 += 5){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 1) (1024 / 1024)
		for (c633 = c634, c633_p_0 = 0;
			c633 < c634 + 1024;
			c633 += 1024, c633_p_0 += 1024){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (f, 8) (512 / 64)
			for (f = f316, fp_0 = 0;
				f < f316 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y474, yp_1 = y474_p_0, yp_0 = 0;
					y < y474 + 5;
					y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 8) (1024 / 128)
					for (c632 = c633, c632_p_1 = c633_p_0, c632_p_0 = 0;
						c632 < c633 + 1024;
						c632 += 128, c632_p_1 += 128, c632_p_0 += 128){
						// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
						// T (x, 17) (17 / 1)
						for (x = x316, xp_0 = 0;
							x < x316 + 17;
							x += 1, xp_0 += 1){
									mem_vec_6188 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6189 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_6190 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_6191 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_6192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_6195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_6196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_6198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_6199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_6200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_6202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_6203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_6204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_6205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_6206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_6207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
									// T (c, 128) (128 / 1)
									for (c = c632, cp_2 = c632_p_1, cp_1 = c632_p_0, cp_0 = 0;
										c < c632 + 128;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6188);
										mem_vec_6188 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6189);
										mem_vec_6189 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6190);
										mem_vec_6190 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6191);
										mem_vec_6191 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6192);
										mem_vec_6192 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6193);
										mem_vec_6193 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6194);
										mem_vec_6194 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6195);
										mem_vec_6195 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6196);
										mem_vec_6196 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6197);
										mem_vec_6197 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6198);
										mem_vec_6198 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6199);
										mem_vec_6199 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6200);
										mem_vec_6200 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6201);
										mem_vec_6201 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6202);
										mem_vec_6202 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6203);
										mem_vec_6203 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6204);
										mem_vec_6204 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6205);
										mem_vec_6205 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6206);
										mem_vec_6206 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6207);
										mem_vec_6207 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6188);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6189);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6190);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6191);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6192);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6193);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6194);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6195);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6196);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6197);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6198);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6199);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6200);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6201);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6202);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6203);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6204);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6205);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6206);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6207);
						}
					}
				}
			}
		}
	}


}