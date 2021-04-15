#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, w); T (2, c); Hoist_vars [c]; T (8, x);
  T (3, h); T (4, c); T (7, x); T (28, y); T (8, c)]
*/
IND_TYPE c, cp_0, c250_p_0, c251_p_0, cp_1, c250_p_1, cp_2, c250, c251, h, hp_0, x, xp_0, x282_p_0, xp_1, x282, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y152 = 0;
IND_TYPE x283 = 0;
IND_TYPE h112 = 0;
IND_TYPE w = 0;
IND_TYPE c252 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_1030 ,mem_vec_1031 ,mem_vec_1032 ,mem_vec_1033 ,mem_vec_1034 ,mem_vec_1035 ,mem_vec_1036 ,mem_vec_1037 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 8) (64 / 8)
for (c251 = c252, c251_p_0 = 0;
	c251 < c252 + 64;
	c251 += 8, c251_p_0 += 8){
	// y = 56, x = 56, h = 3, w = 3, c = 8, f = 64
	// T (y, 28) (56 / 2)
	for (y = y152, yp_0 = 0;
		y < y152 + 56;
		y += 2, yp_0 += 2){
		// y = 2, x = 56, h = 3, w = 3, c = 8, f = 64
		// T (x, 7) (56 / 8)
		for (x282 = x283, x282_p_0 = 0;
			x282 < x283 + 56;
			x282 += 8, x282_p_0 += 8){
			// y = 2, x = 8, h = 3, w = 3, c = 8, f = 64
			// T (c, 4) (8 / 2)
			for (c250 = c251, c250_p_1 = c251_p_0, c250_p_0 = 0;
				c250 < c251 + 8;
				c250 += 2, c250_p_1 += 2, c250_p_0 += 2){
				// y = 2, x = 8, h = 3, w = 3, c = 2, f = 64
				// T (h, 3) (3 / 1)
				for (h = h112, hp_0 = 0;
					h < h112 + 3;
					h += 1, hp_0 += 1){
					// y = 2, x = 8, h = 1, w = 3, c = 2, f = 64
					// T (x, 8) (8 / 1)
					for (x = x282, xp_1 = x282_p_0, xp_0 = 0;
						x < x282 + 8;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_1030 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_1031 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_1032 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_1033 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_1034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_1035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_1036 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_1037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								// y = 2, x = 1, h = 1, w = 3, c = 2, f = 64
								// T (c, 2) (2 / 1)
								for (c = c250, cp_2 = c250_p_1, cp_1 = c250_p_0, cp_0 = 0;
									c < c250 + 2;
									c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1030);
									mem_vec_1030 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1031);
									mem_vec_1031 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1032);
									mem_vec_1032 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1033);
									mem_vec_1033 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1034);
									mem_vec_1034 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1035);
									mem_vec_1035 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1036);
									mem_vec_1036 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1037);
									mem_vec_1037 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);
									vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

									vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_1030);
									mem_vec_1030 = vec_14;

									vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

									vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_1031);
									mem_vec_1031 = vec_17;

									vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

									vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_1032);
									mem_vec_1032 = vec_19;

									vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

									vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_1033);
									mem_vec_1033 = vec_21;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
									vec_24 = _mm512_set1_ps(scal_3);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_1034);
									mem_vec_1034 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_1035);
									mem_vec_1035 = vec_25;



									vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_1036);
									mem_vec_1036 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_1037);
									mem_vec_1037 = vec_27;
									scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
									vec_29 = _mm512_set1_ps(scal_4);
									vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

									vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_1030);
									mem_vec_1030 = vec_28;

									vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

									vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_1031);
									mem_vec_1031 = vec_31;

									vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

									vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_1032);
									mem_vec_1032 = vec_33;

									vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

									vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_1033);
									mem_vec_1033 = vec_35;
									scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
									vec_38 = _mm512_set1_ps(scal_5);


									vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_1034);
									mem_vec_1034 = vec_37;



									vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_1035);
									mem_vec_1035 = vec_39;



									vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_1036);
									mem_vec_1036 = vec_40;



									vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_1037);
									mem_vec_1037 = vec_41;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1030);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1031);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1032);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1033);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1034);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1035);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1036);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1037);
					}
				}
			}
		}
	}
}


}