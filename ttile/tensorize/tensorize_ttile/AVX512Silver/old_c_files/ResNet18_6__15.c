#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (4, y); U (3, w); T (32, c); Hoist_vars [c]; T (3, h);
  T (28, x); T (7, y); T (4, f); T (4, c); T (2, f)]
*/
IND_TYPE c, cp_0, c372_p_0, cp_1, c372, f, fp_0, f372_p_0, fp_1, f372, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y248 = 0;
IND_TYPE x306 = 0;
IND_TYPE h179 = 0;
IND_TYPE w = 0;
IND_TYPE c373 = 0;
IND_TYPE f373 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2264 ,mem_vec_2265 ,mem_vec_2266 ,mem_vec_2267 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f372 = f373, f372_p_0 = 0;
	f372 < f373 + 128;
	f372 += 64, f372_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 64
	// T (c, 4) (128 / 32)
	for (c372 = c373, c372_p_0 = 0;
		c372 < c373 + 128;
		c372 += 32, c372_p_0 += 32){
		// y = 28, x = 28, h = 3, w = 3, c = 32, f = 64
		// T (f, 4) (64 / 16)
		for (f = f372, fp_1 = f372_p_0, fp_0 = 0;
			f < f372 + 64;
			f += 16, fp_1 += 16, fp_0 += 16){
			// y = 28, x = 28, h = 3, w = 3, c = 32, f = 16
			// T (y, 7) (28 / 4)
			for (y = y248, yp_0 = 0;
				y < y248 + 28;
				y += 4, yp_0 += 4){
				// y = 4, x = 28, h = 3, w = 3, c = 32, f = 16
				// T (x, 28) (28 / 1)
				for (x = x306, xp_0 = 0;
					x < x306 + 28;
					x += 1, xp_0 += 1){
					// y = 4, x = 1, h = 3, w = 3, c = 32, f = 16
					// T (h, 3) (3 / 1)
					for (h = h179, hp_0 = 0;
						h < h179 + 3;
						h += 1, hp_0 += 1){
								mem_vec_2264 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_2265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_2266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_2267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								// y = 4, x = 1, h = 1, w = 3, c = 32, f = 16
								// T (c, 32) (32 / 1)
								for (c = c372, cp_1 = c372_p_0, cp_0 = 0;
									c < c372 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2264);
									mem_vec_2264 = vec_0;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_4 = _mm512_set1_ps(scal_1);


									vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_2265);
									mem_vec_2265 = vec_3;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_6 = _mm512_set1_ps(scal_2);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2266);
									mem_vec_2266 = vec_5;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_8 = _mm512_set1_ps(scal_3);


									vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_2267);
									mem_vec_2267 = vec_7;
									scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
									vec_10 = _mm512_set1_ps(scal_4);
									vec_11 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

									vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_2264);
									mem_vec_2264 = vec_9;
									scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
									vec_13 = _mm512_set1_ps(scal_5);


									vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_2265);
									mem_vec_2265 = vec_12;
									scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_6);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_2266);
									mem_vec_2266 = vec_14;
									scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
									vec_17 = _mm512_set1_ps(scal_7);


									vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_2267);
									mem_vec_2267 = vec_16;
									scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
									vec_19 = _mm512_set1_ps(scal_8);
									vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

									vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_2264);
									mem_vec_2264 = vec_18;
									scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
									vec_22 = _mm512_set1_ps(scal_9);


									vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_2265);
									mem_vec_2265 = vec_21;
									scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
									vec_24 = _mm512_set1_ps(scal_10);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_2266);
									mem_vec_2266 = vec_23;
									scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
									vec_26 = _mm512_set1_ps(scal_11);


									vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_2267);
									mem_vec_2267 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2264);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2265);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2266);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2267);
					}
				}
			}
		}
	}
}


}