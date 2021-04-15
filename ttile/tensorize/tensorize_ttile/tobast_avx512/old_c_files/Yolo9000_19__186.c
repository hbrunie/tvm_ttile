#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (1, x); T (64, c);
  T (8, f); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (16, c)]
*/
IND_TYPE c, cp_0, c1208_p_0, c1209_p_0, cp_1, c1208_p_1, cp_2, c1208, c1209, f, fp_0, x, xp_0, x906_p_0, xp_1, x906, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y604 = 0;
IND_TYPE x907 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1210 = 0;
IND_TYPE f604 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_10176 ,mem_vec_10177 ,mem_vec_10178 ,mem_vec_10179 ,mem_vec_10180 ,mem_vec_10181 ,mem_vec_10182 ,mem_vec_10183 ,mem_vec_10184 ,mem_vec_10185 ,mem_vec_10186 ,mem_vec_10187 ,mem_vec_10188 ,mem_vec_10189 ,mem_vec_10190 ,mem_vec_10191 ,mem_vec_10192 ,mem_vec_10193 ,mem_vec_10194 ,mem_vec_10195 ,mem_vec_10196 ,mem_vec_10197 ,mem_vec_10198 ,mem_vec_10199 ,mem_vec_10200 ,mem_vec_10201 ,mem_vec_10202 ,mem_vec_10203 ,mem_vec_10204 ,mem_vec_10205 ,mem_vec_10206 ,mem_vec_10207 ,mem_vec_10208 ,mem_vec_10209 ,mem_vec_10210 ,mem_vec_10211 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 16) (1024 / 64)
for (c1209 = c1210, c1209_p_0 = 0;
	c1209 < c1210 + 1024;
	c1209 += 64, c1209_p_0 += 64){
		for (y = y604, yp_0 = 0;
			y < y604 + 12;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 512
			// T (x, 17) (17 / 1)
			for (x906 = x907, x906_p_0 = 0;
				x906 < x907 + 17;
				x906 += 1, x906_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 512
				// T (f, 8) (512 / 64)
				for (f = f604, fp_0 = 0;
					f < f604 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
					// T (c, 64) (64 / 1)
					for (c1208 = c1209, c1208_p_1 = c1209_p_0, c1208_p_0 = 0;
						c1208 < c1209 + 64;
						c1208 += 1, c1208_p_1 += 1, c1208_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
						// T (x, 1) (1 / 1)
						for (x = x906, xp_1 = x906_p_0, xp_0 = 0;
							x < x906 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10176 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10177 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10178 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10179 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c1208, cp_2 = c1208_p_1, cp_1 = c1208_p_0, cp_0 = 0;
										c < c1208 + 1;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10176);
										mem_vec_10176 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10177);
										mem_vec_10177 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10178);
										mem_vec_10178 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10179);
										mem_vec_10179 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10180);
										mem_vec_10180 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10181);
										mem_vec_10181 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10182);
										mem_vec_10182 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10183);
										mem_vec_10183 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10184);
										mem_vec_10184 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10185);
										mem_vec_10185 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10186);
										mem_vec_10186 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10187);
										mem_vec_10187 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10188);
										mem_vec_10188 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10189);
										mem_vec_10189 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10190);
										mem_vec_10190 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10191);
										mem_vec_10191 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10176);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10177);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10178);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10179);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10180);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10181);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10182);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10183);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10184);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10185);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10186);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10187);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10188);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10189);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10190);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10191);
						}
					}
				}
			}
		}
		for (y = y604 + 12, yp_0 = 0;
			y < y604 + 12 + 5;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 512
			// T (x, 17) (17 / 1)
			for (x906 = x907, x906_p_0 = 0;
				x906 < x907 + 17;
				x906 += 1, x906_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 512
				// T (f, 8) (512 / 64)
				for (f = f604, fp_0 = 0;
					f < f604 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
					// T (c, 64) (64 / 1)
					for (c1208 = c1209, c1208_p_1 = c1209_p_0, c1208_p_0 = 0;
						c1208 < c1209 + 64;
						c1208 += 1, c1208_p_1 += 1, c1208_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
						// T (x, 1) (1 / 1)
						for (x = x906, xp_1 = x906_p_0, xp_0 = 0;
							x < x906 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10192 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10193 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10194 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10195 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_10208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_10211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c1208, cp_2 = c1208_p_1, cp_1 = c1208_p_0, cp_0 = 0;
										c < c1208 + 1;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10192);
										mem_vec_10192 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10193);
										mem_vec_10193 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10194);
										mem_vec_10194 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10195);
										mem_vec_10195 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10196);
										mem_vec_10196 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10197);
										mem_vec_10197 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10198);
										mem_vec_10198 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10199);
										mem_vec_10199 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10200);
										mem_vec_10200 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10201);
										mem_vec_10201 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10202);
										mem_vec_10202 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10203);
										mem_vec_10203 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10204);
										mem_vec_10204 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10205);
										mem_vec_10205 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10206);
										mem_vec_10206 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10207);
										mem_vec_10207 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10208);
										mem_vec_10208 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10209);
										mem_vec_10209 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10210);
										mem_vec_10210 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10211);
										mem_vec_10211 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10192);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10193);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10194);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10195);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10196);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10197);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10198);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10199);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10200);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10201);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10202);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10203);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10204);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10205);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10206);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10207);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10208);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10209);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10210);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10211);
						}
					}
				}
			}
		}
}


}