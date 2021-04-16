#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (2, x); T (4, c);
  T (14, x); T (7, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c109_p_0, cp_1, c109, f, fp_0, f109_p_0, fp_1, f109, x, xp_0, x120_p_0, xp_1, x120, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y80 = 0;
IND_TYPE x121 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c110 = 0;
IND_TYPE f110 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_688 ,mem_vec_689 ,mem_vec_690 ,mem_vec_691 ,mem_vec_692 ,mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f109 = f110, f109_p_0 = 0;
	f109 < f110 + 128;
	f109 += 64, f109_p_0 += 64){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
	// T (f, 1) (64 / 64)
	for (f = f109, fp_1 = f109_p_0, fp_0 = 0;
		f < f109 + 64;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 7) (28 / 4)
		for (y = y80, yp_0 = 0;
			y < y80 + 28;
			y += 4, yp_0 += 4){
			// y = 4, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 14) (28 / 2)
			for (x120 = x121, x120_p_0 = 0;
				x120 < x121 + 28;
				x120 += 2, x120_p_0 += 2){
				// y = 4, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (c, 4) (64 / 16)
				for (c109 = c110, c109_p_0 = 0;
					c109 < c110 + 64;
					c109 += 16, c109_p_0 += 16){
					// y = 4, x = 2, h = 1, w = 1, c = 16, f = 64
					// T (x, 2) (2 / 1)
					for (x = x120, xp_1 = x120_p_0, xp_0 = 0;
						x < x120 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_688 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_689 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_690 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_691 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 1, c = 16, f = 64
								// T (c, 16) (16 / 1)
								for (c = c109, cp_1 = c109_p_0, cp_0 = 0;
									c < c109 + 16;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_688);
									mem_vec_688 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_689);
									mem_vec_689 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_690);
									mem_vec_690 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_691);
									mem_vec_691 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_692);
									mem_vec_692 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_693);
									mem_vec_693 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_694);
									mem_vec_694 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_695);
									mem_vec_695 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_696);
									mem_vec_696 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_697);
									mem_vec_697 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_698);
									mem_vec_698 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_699);
									mem_vec_699 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_700);
									mem_vec_700 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_701);
									mem_vec_701 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_702);
									mem_vec_702 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_703);
									mem_vec_703 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_688);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_689);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_690);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_691);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_692);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_693);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_694);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_695);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_696);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_697);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_698);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_699);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_700);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_701);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_702);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_703);
					}
				}
			}
		}
	}
}


}