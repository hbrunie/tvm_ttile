#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (7, y); U (3, h); T (32, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (32, f); T (1, c); T (16, c)]
*/
IND_TYPE c, cp_0, c380_p_0, c381_p_0, cp_1, c380_p_1, cp_2, c380, c381, f, fp_0, w, wp_0, x, xp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y = 0;
IND_TYPE x220 = 0;
IND_TYPE h = 0;
IND_TYPE w168 = 0;
IND_TYPE c382 = 0;
IND_TYPE f280 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1736 ,mem_vec_1737 ,mem_vec_1738 ,mem_vec_1739 ,mem_vec_1740 ,mem_vec_1741 ,mem_vec_1742 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (c, 16) (512 / 32)
for (c381 = c382, c381_p_0 = 0;
	c381 < c382 + 512;
	c381 += 32, c381_p_0 += 32){
	// y = 7, x = 7, h = 3, w = 3, c = 32, f = 512
	// T (c, 1) (32 / 32)
	for (c380 = c381, c380_p_1 = c381_p_0, c380_p_0 = 0;
		c380 < c381 + 32;
		c380 += 32, c380_p_1 += 32, c380_p_0 += 32){
		// y = 7, x = 7, h = 3, w = 3, c = 32, f = 512
		// T (f, 32) (512 / 16)
		for (f = f280, fp_0 = 0;
			f < f280 + 512;
			f += 16, fp_0 += 16){
			// y = 7, x = 7, h = 3, w = 3, c = 32, f = 16
			// T (w, 3) (3 / 1)
			for (w = w168, wp_0 = 0;
				w < w168 + 3;
				w += 1, wp_0 += 1){
				// y = 7, x = 7, h = 3, w = 1, c = 32, f = 16
				// T (x, 7) (7 / 1)
				for (x = x220, xp_0 = 0;
					x < x220 + 7;
					x += 1, xp_0 += 1){
							mem_vec_1736 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_1737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_1738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_1739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_1740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
							mem_vec_1741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
							mem_vec_1742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
							// y = 7, x = 1, h = 3, w = 1, c = 32, f = 16
							// T (c, 32) (32 / 1)
							for (c = c380, cp_2 = c380_p_1, cp_1 = c380_p_0, cp_0 = 0;
								c < c380 + 32;
								c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1736);
								mem_vec_1736 = vec_0;
								scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
								vec_4 = _mm512_set1_ps(scal_1);


								vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1737);
								mem_vec_1737 = vec_3;
								scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
								vec_6 = _mm512_set1_ps(scal_2);


								vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1738);
								mem_vec_1738 = vec_5;
								scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
								vec_8 = _mm512_set1_ps(scal_3);


								vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1739);
								mem_vec_1739 = vec_7;
								scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
								vec_10 = _mm512_set1_ps(scal_4);


								vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1740);
								mem_vec_1740 = vec_9;
								scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
								vec_12 = _mm512_set1_ps(scal_5);


								vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1741);
								mem_vec_1741 = vec_11;
								scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
								vec_14 = _mm512_set1_ps(scal_6);


								vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_1742);
								mem_vec_1742 = vec_13;
								scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
								vec_16 = _mm512_set1_ps(scal_7);
								vec_17 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

								vec_15 = _mm512_fmadd_ps(vec_16, vec_17, mem_vec_1736);
								mem_vec_1736 = vec_15;
								scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
								vec_19 = _mm512_set1_ps(scal_8);


								vec_18 = _mm512_fmadd_ps(vec_19, vec_17, mem_vec_1737);
								mem_vec_1737 = vec_18;
								scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
								vec_21 = _mm512_set1_ps(scal_9);


								vec_20 = _mm512_fmadd_ps(vec_21, vec_17, mem_vec_1738);
								mem_vec_1738 = vec_20;
								scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
								vec_23 = _mm512_set1_ps(scal_10);


								vec_22 = _mm512_fmadd_ps(vec_23, vec_17, mem_vec_1739);
								mem_vec_1739 = vec_22;
								scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
								vec_25 = _mm512_set1_ps(scal_11);


								vec_24 = _mm512_fmadd_ps(vec_25, vec_17, mem_vec_1740);
								mem_vec_1740 = vec_24;
								scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
								vec_27 = _mm512_set1_ps(scal_12);


								vec_26 = _mm512_fmadd_ps(vec_27, vec_17, mem_vec_1741);
								mem_vec_1741 = vec_26;
								scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
								vec_29 = _mm512_set1_ps(scal_13);


								vec_28 = _mm512_fmadd_ps(vec_29, vec_17, mem_vec_1742);
								mem_vec_1742 = vec_28;
								scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
								vec_31 = _mm512_set1_ps(scal_14);
								vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

								vec_30 = _mm512_fmadd_ps(vec_31, vec_32, mem_vec_1736);
								mem_vec_1736 = vec_30;
								scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
								vec_34 = _mm512_set1_ps(scal_15);


								vec_33 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_1737);
								mem_vec_1737 = vec_33;
								scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
								vec_36 = _mm512_set1_ps(scal_16);


								vec_35 = _mm512_fmadd_ps(vec_36, vec_32, mem_vec_1738);
								mem_vec_1738 = vec_35;
								scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
								vec_38 = _mm512_set1_ps(scal_17);


								vec_37 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_1739);
								mem_vec_1739 = vec_37;
								scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
								vec_40 = _mm512_set1_ps(scal_18);


								vec_39 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_1740);
								mem_vec_1740 = vec_39;
								scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
								vec_42 = _mm512_set1_ps(scal_19);


								vec_41 = _mm512_fmadd_ps(vec_42, vec_32, mem_vec_1741);
								mem_vec_1741 = vec_41;
								scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
								vec_44 = _mm512_set1_ps(scal_20);


								vec_43 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_1742);
								mem_vec_1742 = vec_43;
							}
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1736);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1737);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1738);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1739);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1740);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1741);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1742);
				}
			}
		}
	}
}


}