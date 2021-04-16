#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (7, x); T (16, c); T (16, f); T (1, f)]
*/
IND_TYPE c, cp_0, c168_p_0, cp_1, c168, f, fp_0, f90_p_0, fp_1, f90, h, hp_0, w, wp_0, x, xp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y = 0;
IND_TYPE x86 = 0;
IND_TYPE h66 = 0;
IND_TYPE w66 = 0;
IND_TYPE c169 = 0;
IND_TYPE f91 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,mem_vec_720 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (f, 1) (512 / 512)
for (f90 = f91, f90_p_0 = 0;
	f90 < f91 + 512;
	f90 += 512, f90_p_0 += 512){
	// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
	// T (f, 16) (512 / 32)
	for (f = f90, fp_1 = f90_p_0, fp_0 = 0;
		f < f90 + 512;
		f += 32, fp_1 += 32, fp_0 += 32){
		// y = 7, x = 7, h = 3, w = 3, c = 512, f = 32
		// T (c, 16) (512 / 32)
		for (c168 = c169, c168_p_0 = 0;
			c168 < c169 + 512;
			c168 += 32, c168_p_0 += 32){
			// y = 7, x = 7, h = 3, w = 3, c = 32, f = 32
			// T (x, 7) (7 / 1)
			for (x = x86, xp_0 = 0;
				x < x86 + 7;
				x += 1, xp_0 += 1){
				// y = 7, x = 1, h = 3, w = 3, c = 32, f = 32
				// T (h, 3) (3 / 1)
				for (h = h66, hp_0 = 0;
					h < h66 + 3;
					h += 1, hp_0 += 1){
					// y = 7, x = 1, h = 1, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w66, wp_0 = 0;
						w < w66 + 3;
						w += 1, wp_0 += 1){
								mem_vec_707 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_708 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c168, cp_1 = c168_p_0, cp_0 = 0;
									c < c168 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_707);
									mem_vec_707 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_708);
									mem_vec_708 = vec_3;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_709);
									mem_vec_709 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_710);
									mem_vec_710 = vec_7;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_711);
									mem_vec_711 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_712);
									mem_vec_712 = vec_10;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_713);
									mem_vec_713 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_714);
									mem_vec_714 = vec_13;
									scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_715);
									mem_vec_715 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_716);
									mem_vec_716 = vec_16;
									scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_717);
									mem_vec_717 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_718);
									mem_vec_718 = vec_19;
									scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_719);
									mem_vec_719 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_720);
									mem_vec_720 = vec_22;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_707);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_708);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_709);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_710);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_711);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_712);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_713);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_714);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_715);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_716);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_717);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_718);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_719);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_720);
					}
				}
			}
		}
	}
}


}