#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, h); T (32, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (2, c); T (8, x); T (28, y); T (1, c)]
*/
IND_TYPE c, cp_0, c142_p_0, c143_p_0, cp_1, c142_p_1, cp_2, c142, c143, w, wp_0, x, xp_0, x166_p_0, xp_1, x166, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y88 = 0;
IND_TYPE x167 = 0;
IND_TYPE h = 0;
IND_TYPE w88 = 0;
IND_TYPE c144 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 1) (64 / 64)
for (c143 = c144, c143_p_0 = 0;
	c143 < c144 + 64;
	c143 += 64, c143_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (y, 28) (56 / 2)
	for (y = y88, yp_0 = 0;
		y < y88 + 56;
		y += 2, yp_0 += 2){
		// y = 2, x = 56, h = 3, w = 3, c = 64, f = 64
		// T (x, 8) (56 / 7)
		for (x166 = x167, x166_p_0 = 0;
			x166 < x167 + 56;
			x166 += 7, x166_p_0 += 7){
			// y = 2, x = 7, h = 3, w = 3, c = 64, f = 64
			// T (c, 2) (64 / 32)
			for (c142 = c143, c142_p_1 = c143_p_0, c142_p_0 = 0;
				c142 < c143 + 64;
				c142 += 32, c142_p_1 += 32, c142_p_0 += 32){
				// y = 2, x = 7, h = 3, w = 3, c = 32, f = 64
				// T (w, 3) (3 / 1)
				for (w = w88, wp_0 = 0;
					w < w88 + 3;
					w += 1, wp_0 += 1){
					// y = 2, x = 7, h = 3, w = 1, c = 32, f = 64
					// T (x, 7) (7 / 1)
					for (x = x166, xp_1 = x166_p_0, xp_0 = 0;
						x < x166 + 7;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_650 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_651 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_652 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_653 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								// y = 2, x = 1, h = 3, w = 1, c = 32, f = 64
								// T (c, 32) (32 / 1)
								for (c = c142, cp_2 = c142_p_1, cp_1 = c142_p_0, cp_0 = 0;
									c < c142 + 32;
									c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_650);
									mem_vec_650 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_651);
									mem_vec_651 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_652);
									mem_vec_652 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_653);
									mem_vec_653 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_654);
									mem_vec_654 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_655);
									mem_vec_655 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_656);
									mem_vec_656 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_657);
									mem_vec_657 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
									vec_15 = _mm512_set1_ps(scal_2);
									vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

									vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_650);
									mem_vec_650 = vec_14;

									vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

									vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_651);
									mem_vec_651 = vec_17;

									vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

									vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_652);
									mem_vec_652 = vec_19;

									vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

									vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_653);
									mem_vec_653 = vec_21;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
									vec_24 = _mm512_set1_ps(scal_3);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_654);
									mem_vec_654 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_655);
									mem_vec_655 = vec_25;



									vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_656);
									mem_vec_656 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_657);
									mem_vec_657 = vec_27;
									scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
									vec_29 = _mm512_set1_ps(scal_4);
									vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

									vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_650);
									mem_vec_650 = vec_28;

									vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

									vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_651);
									mem_vec_651 = vec_31;

									vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

									vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_652);
									mem_vec_652 = vec_33;

									vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

									vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_653);
									mem_vec_653 = vec_35;
									scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
									vec_38 = _mm512_set1_ps(scal_5);


									vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_654);
									mem_vec_654 = vec_37;



									vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_655);
									mem_vec_655 = vec_39;



									vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_656);
									mem_vec_656 = vec_40;



									vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_657);
									mem_vec_657 = vec_41;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_650);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_651);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_652);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_653);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_654);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_655);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_656);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_657);
					}
				}
			}
		}
	}
}


}