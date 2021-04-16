#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (1, x); T (17, y);
  T (2, c); T (136, x); T (2, y)]
*/
IND_TYPE c, cp_0, c3_p_0, cp_1, c3, x, xp_0, x3_p_0, xp_1, x3, y, yp_0, y3_p_0, yp_1, y3;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y4 = 0;
IND_TYPE x4 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c4 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_16 ,mem_vec_17 ,mem_vec_18 ,mem_vec_19 ,mem_vec_20 ,mem_vec_21 ,mem_vec_22 ,mem_vec_23 ,mem_vec_24 ,mem_vec_25 ,mem_vec_26 ,mem_vec_27 ,mem_vec_28 ,mem_vec_29 ,mem_vec_30 ,mem_vec_31 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 2) (136 / 68)
for (y3 = y4, y3_p_0 = 0;
	y3 < y4 + 136;
	y3 += 68, y3_p_0 += 68){
	// y = 68, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 136) (136 / 1)
	for (x3 = x4, x3_p_0 = 0;
		x3 < x4 + 136;
		x3 += 1, x3_p_0 += 1){
		// y = 68, x = 1, h = 1, w = 1, c = 128, f = 64
		// T (c, 2) (128 / 64)
		for (c3 = c4, c3_p_0 = 0;
			c3 < c4 + 128;
			c3 += 64, c3_p_0 += 64){
			// y = 68, x = 1, h = 1, w = 1, c = 64, f = 64
			// T (y, 17) (68 / 4)
			for (y = y3, yp_1 = y3_p_0, yp_0 = 0;
				y < y3 + 68;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (x, 1) (1 / 1)
				for (x = x3, xp_1 = x3_p_0, xp_0 = 0;
					x < x3 + 1;
					x += 1, xp_1 += 1, xp_0 += 1){
							mem_vec_16 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_17 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_18 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
							mem_vec_19 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
							mem_vec_20 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_21 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_22 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
							mem_vec_23 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
							mem_vec_24 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_25 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_26 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
							mem_vec_27 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
							mem_vec_28 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_29 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_30 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
							mem_vec_31 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
							// y = 4, x = 1, h = 1, w = 1, c = 64, f = 64
							// T (c, 64) (64 / 1)
							for (c = c3, cp_1 = c3_p_0, cp_0 = 0;
								c < c3 + 64;
								c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_16);
								mem_vec_16 = vec_0;

								vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_17);
								mem_vec_17 = vec_3;

								vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

								vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_18);
								mem_vec_18 = vec_5;

								vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

								vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_19);
								mem_vec_19 = vec_7;
								scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
								vec_10 = _mm512_set1_ps(scal_1);


								vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_20);
								mem_vec_20 = vec_9;



								vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_21);
								mem_vec_21 = vec_11;



								vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_22);
								mem_vec_22 = vec_12;



								vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_23);
								mem_vec_23 = vec_13;
								scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
								vec_15 = _mm512_set1_ps(scal_2);


								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_24);
								mem_vec_24 = vec_14;



								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_25);
								mem_vec_25 = vec_16;



								vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_26);
								mem_vec_26 = vec_17;



								vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_27);
								mem_vec_27 = vec_18;
								scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
								vec_20 = _mm512_set1_ps(scal_3);


								vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_28);
								mem_vec_28 = vec_19;



								vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_29);
								mem_vec_29 = vec_21;



								vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_30);
								mem_vec_30 = vec_22;



								vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_31);
								mem_vec_31 = vec_23;
							}
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_17);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_18);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_19);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_20);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_21);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_22);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_23);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_24);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_25);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_26);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_27);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_28);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_29);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_30);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_31);
				}
			}
		}
	}
}


}