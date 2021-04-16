#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (7, y); U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (14, x); T (8, c); T (2, f); T (2, y); T (8, f)]
*/
IND_TYPE c, cp_0, c339_p_0, cp_1, c339, f, fp_0, f339_p_0, fp_1, f339, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y226 = 0;
IND_TYPE x226 = 0;
IND_TYPE h = 0;
IND_TYPE w174 = 0;
IND_TYPE c340 = 0;
IND_TYPE f340 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1918 ,mem_vec_1919 ,mem_vec_1920 ,mem_vec_1921 ,mem_vec_1922 ,mem_vec_1923 ,mem_vec_1924 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 8) (256 / 32)
for (f339 = f340, f339_p_0 = 0;
	f339 < f340 + 256;
	f339 += 32, f339_p_0 += 32){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 32
	// T (y, 2) (14 / 7)
	for (y = y226, yp_0 = 0;
		y < y226 + 14;
		y += 7, yp_0 += 7){
		// y = 7, x = 14, h = 3, w = 3, c = 256, f = 32
		// T (f, 2) (32 / 16)
		for (f = f339, fp_1 = f339_p_0, fp_0 = 0;
			f < f339 + 32;
			f += 16, fp_1 += 16, fp_0 += 16){
			// y = 7, x = 14, h = 3, w = 3, c = 256, f = 16
			// T (c, 8) (256 / 32)
			for (c339 = c340, c339_p_0 = 0;
				c339 < c340 + 256;
				c339 += 32, c339_p_0 += 32){
				// y = 7, x = 14, h = 3, w = 3, c = 32, f = 16
				// T (x, 14) (14 / 1)
				for (x = x226, xp_0 = 0;
					x < x226 + 14;
					x += 1, xp_0 += 1){
					// y = 7, x = 1, h = 3, w = 3, c = 32, f = 16
					// T (w, 3) (3 / 1)
					for (w = w174, wp_0 = 0;
						w < w174 + 3;
						w += 1, wp_0 += 1){
								mem_vec_1918 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_1919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_1920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_1921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_1922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_1923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_1924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								// y = 7, x = 1, h = 3, w = 1, c = 32, f = 16
								// T (c, 32) (32 / 1)
								for (c = c339, cp_1 = c339_p_0, cp_0 = 0;
									c < c339 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1918);
									mem_vec_1918 = vec_0;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_4 = _mm512_set1_ps(scal_1);


									vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1919);
									mem_vec_1919 = vec_3;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_6 = _mm512_set1_ps(scal_2);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1920);
									mem_vec_1920 = vec_5;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_8 = _mm512_set1_ps(scal_3);


									vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1921);
									mem_vec_1921 = vec_7;
									scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
									vec_10 = _mm512_set1_ps(scal_4);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1922);
									mem_vec_1922 = vec_9;
									scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
									vec_12 = _mm512_set1_ps(scal_5);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1923);
									mem_vec_1923 = vec_11;
									scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
									vec_14 = _mm512_set1_ps(scal_6);


									vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_1924);
									mem_vec_1924 = vec_13;
									scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
									vec_16 = _mm512_set1_ps(scal_7);
									vec_17 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

									vec_15 = _mm512_fmadd_ps(vec_16, vec_17, mem_vec_1918);
									mem_vec_1918 = vec_15;
									scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
									vec_19 = _mm512_set1_ps(scal_8);


									vec_18 = _mm512_fmadd_ps(vec_19, vec_17, mem_vec_1919);
									mem_vec_1919 = vec_18;
									scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
									vec_21 = _mm512_set1_ps(scal_9);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_17, mem_vec_1920);
									mem_vec_1920 = vec_20;
									scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
									vec_23 = _mm512_set1_ps(scal_10);


									vec_22 = _mm512_fmadd_ps(vec_23, vec_17, mem_vec_1921);
									mem_vec_1921 = vec_22;
									scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
									vec_25 = _mm512_set1_ps(scal_11);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_17, mem_vec_1922);
									mem_vec_1922 = vec_24;
									scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
									vec_27 = _mm512_set1_ps(scal_12);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_17, mem_vec_1923);
									mem_vec_1923 = vec_26;
									scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
									vec_29 = _mm512_set1_ps(scal_13);


									vec_28 = _mm512_fmadd_ps(vec_29, vec_17, mem_vec_1924);
									mem_vec_1924 = vec_28;
									scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
									vec_31 = _mm512_set1_ps(scal_14);
									vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

									vec_30 = _mm512_fmadd_ps(vec_31, vec_32, mem_vec_1918);
									mem_vec_1918 = vec_30;
									scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
									vec_34 = _mm512_set1_ps(scal_15);


									vec_33 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_1919);
									mem_vec_1919 = vec_33;
									scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
									vec_36 = _mm512_set1_ps(scal_16);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_32, mem_vec_1920);
									mem_vec_1920 = vec_35;
									scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
									vec_38 = _mm512_set1_ps(scal_17);


									vec_37 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_1921);
									mem_vec_1921 = vec_37;
									scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
									vec_40 = _mm512_set1_ps(scal_18);


									vec_39 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_1922);
									mem_vec_1922 = vec_39;
									scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
									vec_42 = _mm512_set1_ps(scal_19);


									vec_41 = _mm512_fmadd_ps(vec_42, vec_32, mem_vec_1923);
									mem_vec_1923 = vec_41;
									scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
									vec_44 = _mm512_set1_ps(scal_20);


									vec_43 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_1924);
									mem_vec_1924 = vec_43;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1918);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1919);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1920);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1921);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1922);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1923);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1924);
					}
				}
			}
		}
	}
}


}