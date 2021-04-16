#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (7, x); T (8, c); T (1, f); T (16, f)]
*/
IND_TYPE c, cp_0, c165_p_0, cp_1, c165, f, fp_0, f87_p_0, fp_1, f87, h, hp_0, w, wp_0, x, xp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y = 0;
IND_TYPE x84 = 0;
IND_TYPE h64 = 0;
IND_TYPE w64 = 0;
IND_TYPE c166 = 0;
IND_TYPE f88 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (f, 16) (512 / 32)
for (f87 = f88, f87_p_0 = 0;
	f87 < f88 + 512;
	f87 += 32, f87_p_0 += 32){
	// y = 7, x = 7, h = 3, w = 3, c = 512, f = 32
	// T (f, 1) (32 / 32)
	for (f = f87, fp_1 = f87_p_0, fp_0 = 0;
		f < f87 + 32;
		f += 32, fp_1 += 32, fp_0 += 32){
		// y = 7, x = 7, h = 3, w = 3, c = 512, f = 32
		// T (c, 8) (512 / 64)
		for (c165 = c166, c165_p_0 = 0;
			c165 < c166 + 512;
			c165 += 64, c165_p_0 += 64){
			// y = 7, x = 7, h = 3, w = 3, c = 64, f = 32
			// T (x, 7) (7 / 1)
			for (x = x84, xp_0 = 0;
				x < x84 + 7;
				x += 1, xp_0 += 1){
				// y = 7, x = 1, h = 3, w = 3, c = 64, f = 32
				// T (h, 3) (3 / 1)
				for (h = h64, hp_0 = 0;
					h < h64 + 3;
					h += 1, hp_0 += 1){
					// y = 7, x = 1, h = 1, w = 3, c = 64, f = 32
					// T (w, 3) (3 / 1)
					for (w = w64, wp_0 = 0;
						w < w64 + 3;
						w += 1, wp_0 += 1){
								mem_vec_693 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_694 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (c, 64) (64 / 1)
								for (c = c165, cp_1 = c165_p_0, cp_0 = 0;
									c < c165 + 64;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_693);
									mem_vec_693 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_694);
									mem_vec_694 = vec_3;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_695);
									mem_vec_695 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_696);
									mem_vec_696 = vec_7;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_697);
									mem_vec_697 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_698);
									mem_vec_698 = vec_10;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_699);
									mem_vec_699 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_700);
									mem_vec_700 = vec_13;
									scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_701);
									mem_vec_701 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_702);
									mem_vec_702 = vec_16;
									scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_703);
									mem_vec_703 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_704);
									mem_vec_704 = vec_19;
									scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_705);
									mem_vec_705 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_706);
									mem_vec_706 = vec_22;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_693);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_694);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_695);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_696);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_697);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_698);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_699);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_700);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_701);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_702);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_703);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_704);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_705);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_706);
					}
				}
			}
		}
	}
}


}