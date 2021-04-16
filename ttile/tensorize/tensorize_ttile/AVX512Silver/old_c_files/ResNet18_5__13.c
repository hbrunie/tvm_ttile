#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (28, x); T (7, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c115_p_0, cp_1, c115, f, fp_0, f115_p_0, fp_1, f115, x, xp_0, x126_p_0, xp_1, x126, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y84 = 0;
IND_TYPE x127 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c116 = 0;
IND_TYPE f116 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f115 = f116, f115_p_0 = 0;
	f115 < f116 + 128;
	f115 += 64, f115_p_0 += 64){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
	// T (f, 1) (64 / 64)
	for (f = f115, fp_1 = f115_p_0, fp_0 = 0;
		f < f115 + 64;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 7) (28 / 4)
		for (y = y84, yp_0 = 0;
			y < y84 + 28;
			y += 4, yp_0 += 4){
			// y = 4, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 28) (28 / 1)
			for (x126 = x127, x126_p_0 = 0;
				x126 < x127 + 28;
				x126 += 1, x126_p_0 += 1){
				// y = 4, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (c, 1) (64 / 64)
				for (c115 = c116, c115_p_0 = 0;
					c115 < c116 + 64;
					c115 += 64, c115_p_0 += 64){
					// y = 4, x = 1, h = 1, w = 1, c = 64, f = 64
					// T (x, 1) (1 / 1)
					for (x = x126, xp_1 = x126_p_0, xp_0 = 0;
						x < x126 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_720 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_721 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_722 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_723 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 64
								// T (c, 64) (64 / 1)
								for (c = c115, cp_1 = c115_p_0, cp_0 = 0;
									c < c115 + 64;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_720);
									mem_vec_720 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_721);
									mem_vec_721 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_722);
									mem_vec_722 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_723);
									mem_vec_723 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_724);
									mem_vec_724 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_725);
									mem_vec_725 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_726);
									mem_vec_726 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_727);
									mem_vec_727 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_728);
									mem_vec_728 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_729);
									mem_vec_729 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_730);
									mem_vec_730 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_731);
									mem_vec_731 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_732);
									mem_vec_732 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_733);
									mem_vec_733 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_734);
									mem_vec_734 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_735);
									mem_vec_735 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_720);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_721);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_722);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_723);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_724);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_725);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_726);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_727);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_728);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_729);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_730);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_731);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_732);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_733);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_734);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_735);
					}
				}
			}
		}
	}
}


}