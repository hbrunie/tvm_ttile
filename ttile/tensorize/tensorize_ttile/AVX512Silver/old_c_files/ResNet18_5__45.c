#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (1, x); T (4, c);
  T (28, x); T (7, y); T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c124_p_0, cp_1, c124, f, fp_0, f124_p_0, fp_1, f124, x, xp_0, x135_p_0, xp_1, x135, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y90 = 0;
IND_TYPE x136 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c125 = 0;
IND_TYPE f125 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_768 ,mem_vec_769 ,mem_vec_770 ,mem_vec_771 ,mem_vec_772 ,mem_vec_773 ,mem_vec_774 ,mem_vec_775 ,mem_vec_776 ,mem_vec_777 ,mem_vec_778 ,mem_vec_779 ,mem_vec_780 ,mem_vec_781 ,mem_vec_782 ,mem_vec_783 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 1) (128 / 128)
for (f124 = f125, f124_p_0 = 0;
	f124 < f125 + 128;
	f124 += 128, f124_p_0 += 128){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
	// T (f, 2) (128 / 64)
	for (f = f124, fp_1 = f124_p_0, fp_0 = 0;
		f < f124 + 128;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 7) (28 / 4)
		for (y = y90, yp_0 = 0;
			y < y90 + 28;
			y += 4, yp_0 += 4){
			// y = 4, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 28) (28 / 1)
			for (x135 = x136, x135_p_0 = 0;
				x135 < x136 + 28;
				x135 += 1, x135_p_0 += 1){
				// y = 4, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (c, 4) (64 / 16)
				for (c124 = c125, c124_p_0 = 0;
					c124 < c125 + 64;
					c124 += 16, c124_p_0 += 16){
					// y = 4, x = 1, h = 1, w = 1, c = 16, f = 64
					// T (x, 1) (1 / 1)
					for (x = x135, xp_1 = x135_p_0, xp_0 = 0;
						x < x135 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_768 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_769 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_770 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_771 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 1, c = 16, f = 64
								// T (c, 16) (16 / 1)
								for (c = c124, cp_1 = c124_p_0, cp_0 = 0;
									c < c124 + 16;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_768);
									mem_vec_768 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_769);
									mem_vec_769 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_770);
									mem_vec_770 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_771);
									mem_vec_771 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_772);
									mem_vec_772 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_773);
									mem_vec_773 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_774);
									mem_vec_774 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_775);
									mem_vec_775 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_776);
									mem_vec_776 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_777);
									mem_vec_777 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_778);
									mem_vec_778 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_779);
									mem_vec_779 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_780);
									mem_vec_780 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_781);
									mem_vec_781 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_782);
									mem_vec_782 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_783);
									mem_vec_783 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_768);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_769);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_770);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_771);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_772);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_773);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_774);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_775);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_776);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_777);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_778);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_779);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_780);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_781);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_782);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_783);
					}
				}
			}
		}
	}
}


}