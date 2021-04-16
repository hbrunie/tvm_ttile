#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (14, x); T (2, c); T (7, y); T (8, f); T (16, c)]
*/
IND_TYPE c, cp_0, c317_p_0, c318_p_0, cp_1, c317_p_1, cp_2, c317, c318, f, fp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y164 = 0;
IND_TYPE x164 = 0;
IND_TYPE h = 0;
IND_TYPE w127 = 0;
IND_TYPE c319 = 0;
IND_TYPE f175 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_1765 ,mem_vec_1766 ,mem_vec_1767 ,mem_vec_1768 ,mem_vec_1769 ,mem_vec_1770 ,mem_vec_1771 ,mem_vec_1772 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (c, 16) (512 / 32)
for (c318 = c319, c318_p_0 = 0;
	c318 < c319 + 512;
	c318 += 32, c318_p_0 += 32){
	// y = 14, x = 14, h = 3, w = 3, c = 32, f = 512
	// T (f, 8) (512 / 64)
	for (f = f175, fp_0 = 0;
		f < f175 + 512;
		f += 64, fp_0 += 64){
		// y = 14, x = 14, h = 3, w = 3, c = 32, f = 64
		// T (y, 7) (14 / 2)
		for (y = y164, yp_0 = 0;
			y < y164 + 14;
			y += 2, yp_0 += 2){
			// y = 2, x = 14, h = 3, w = 3, c = 32, f = 64
			// T (c, 2) (32 / 16)
			for (c317 = c318, c317_p_1 = c318_p_0, c317_p_0 = 0;
				c317 < c318 + 32;
				c317 += 16, c317_p_1 += 16, c317_p_0 += 16){
				// y = 2, x = 14, h = 3, w = 3, c = 16, f = 64
				// T (x, 14) (14 / 1)
				for (x = x164, xp_0 = 0;
					x < x164 + 14;
					x += 1, xp_0 += 1){
					// y = 2, x = 1, h = 3, w = 3, c = 16, f = 64
					// T (w, 3) (3 / 1)
					for (w = w127, wp_0 = 0;
						w < w127 + 3;
						w += 1, wp_0 += 1){
								mem_vec_1765 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_1766 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_1767 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_1768 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_1769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_1770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_1771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_1772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								// y = 2, x = 1, h = 3, w = 1, c = 16, f = 64
								// T (c, 16) (16 / 1)
								for (c = c317, cp_2 = c317_p_1, cp_1 = c317_p_0, cp_0 = 0;
									c < c317 + 16;
									c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1765);
									mem_vec_1765 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1766);
									mem_vec_1766 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1767);
									mem_vec_1767 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1768);
									mem_vec_1768 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1769);
									mem_vec_1769 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1770);
									mem_vec_1770 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1771);
									mem_vec_1771 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1772);
									mem_vec_1772 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
									vec_15 = _mm512_set1_ps(scal_2);
									vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

									vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_1765);
									mem_vec_1765 = vec_14;

									vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

									vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_1766);
									mem_vec_1766 = vec_17;

									vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

									vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_1767);
									mem_vec_1767 = vec_19;

									vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

									vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_1768);
									mem_vec_1768 = vec_21;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
									vec_24 = _mm512_set1_ps(scal_3);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_1769);
									mem_vec_1769 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_1770);
									mem_vec_1770 = vec_25;



									vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_1771);
									mem_vec_1771 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_1772);
									mem_vec_1772 = vec_27;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
									vec_29 = _mm512_set1_ps(scal_4);
									vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

									vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_1765);
									mem_vec_1765 = vec_28;

									vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

									vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_1766);
									mem_vec_1766 = vec_31;

									vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

									vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_1767);
									mem_vec_1767 = vec_33;

									vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

									vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_1768);
									mem_vec_1768 = vec_35;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
									vec_38 = _mm512_set1_ps(scal_5);


									vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_1769);
									mem_vec_1769 = vec_37;



									vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_1770);
									mem_vec_1770 = vec_39;



									vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_1771);
									mem_vec_1771 = vec_40;



									vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_1772);
									mem_vec_1772 = vec_41;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1765);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1766);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1767);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1768);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1769);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1770);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1771);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1772);
					}
				}
			}
		}
	}
}


}