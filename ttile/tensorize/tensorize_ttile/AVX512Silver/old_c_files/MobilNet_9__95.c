#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (7, x); T (1, c); T (32, f); T (1, f); T (16, c)]
*/
IND_TYPE c, cp_0, c288_p_0, c289_p_0, cp_1, c288_p_1, cp_2, c288, c289, f, fp_0, f216_p_0, fp_1, f216, h, hp_0, w, wp_0, x, xp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y = 0;
IND_TYPE x144 = 0;
IND_TYPE h107 = 0;
IND_TYPE w107 = 0;
IND_TYPE c290 = 0;
IND_TYPE f217 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1197 ,mem_vec_1198 ,mem_vec_1199 ,mem_vec_1200 ,mem_vec_1201 ,mem_vec_1202 ,mem_vec_1203 ,mem_vec_1204 ,mem_vec_1205 ,mem_vec_1206 ,mem_vec_1207 ,mem_vec_1208 ,mem_vec_1209 ,mem_vec_1210 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 16) (1024 / 64)
for (c289 = c290, c289_p_0 = 0;
	c289 < c290 + 1024;
	c289 += 64, c289_p_0 += 64){
	// y = 7, x = 7, h = 3, w = 3, c = 64, f = 1024
	// T (f, 1) (1024 / 1024)
	for (f216 = f217, f216_p_0 = 0;
		f216 < f217 + 1024;
		f216 += 1024, f216_p_0 += 1024){
		// y = 7, x = 7, h = 3, w = 3, c = 64, f = 1024
		// T (f, 32) (1024 / 32)
		for (f = f216, fp_1 = f216_p_0, fp_0 = 0;
			f < f216 + 1024;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 7, x = 7, h = 3, w = 3, c = 64, f = 32
			// T (c, 1) (64 / 64)
			for (c288 = c289, c288_p_1 = c289_p_0, c288_p_0 = 0;
				c288 < c289 + 64;
				c288 += 64, c288_p_1 += 64, c288_p_0 += 64){
				// y = 7, x = 7, h = 3, w = 3, c = 64, f = 32
				// T (x, 7) (7 / 1)
				for (x = x144, xp_0 = 0;
					x < x144 + 7;
					x += 1, xp_0 += 1){
					// y = 7, x = 1, h = 3, w = 3, c = 64, f = 32
					// T (h, 3) (3 / 1)
					for (h = h107, hp_0 = 0;
						h < h107 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 1, h = 1, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w107, wp_0 = 0;
							w < w107 + 3;
							w += 1, wp_0 += 1){
									mem_vec_1197 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1198 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_1208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_1209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_1210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c288, cp_2 = c288_p_1, cp_1 = c288_p_0, cp_0 = 0;
										c < c288 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1197);
										mem_vec_1197 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1198);
										mem_vec_1198 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1199);
										mem_vec_1199 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1200);
										mem_vec_1200 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1201);
										mem_vec_1201 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1202);
										mem_vec_1202 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1203);
										mem_vec_1203 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1204);
										mem_vec_1204 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1205);
										mem_vec_1205 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1206);
										mem_vec_1206 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1207);
										mem_vec_1207 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1208);
										mem_vec_1208 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1209);
										mem_vec_1209 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1210);
										mem_vec_1210 = vec_22;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1197);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1198);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1199);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1200);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1201);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1202);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1203);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1204);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1205);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1206);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1207);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1208);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1209);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1210);
						}
					}
				}
			}
		}
	}
}


}