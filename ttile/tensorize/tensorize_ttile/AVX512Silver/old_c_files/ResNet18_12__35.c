#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (7, x); T (16, c); T (4, f); T (4, f)]
*/
IND_TYPE c, cp_0, c171_p_0, cp_1, c171, f, fp_0, f93_p_0, fp_1, f93, h, hp_0, w, wp_0, x, xp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y = 0;
IND_TYPE x88 = 0;
IND_TYPE h68 = 0;
IND_TYPE w68 = 0;
IND_TYPE c172 = 0;
IND_TYPE f94 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (f, 4) (512 / 128)
for (f93 = f94, f93_p_0 = 0;
	f93 < f94 + 512;
	f93 += 128, f93_p_0 += 128){
	// y = 7, x = 7, h = 3, w = 3, c = 512, f = 128
	// T (f, 4) (128 / 32)
	for (f = f93, fp_1 = f93_p_0, fp_0 = 0;
		f < f93 + 128;
		f += 32, fp_1 += 32, fp_0 += 32){
		// y = 7, x = 7, h = 3, w = 3, c = 512, f = 32
		// T (c, 16) (512 / 32)
		for (c171 = c172, c171_p_0 = 0;
			c171 < c172 + 512;
			c171 += 32, c171_p_0 += 32){
			// y = 7, x = 7, h = 3, w = 3, c = 32, f = 32
			// T (x, 7) (7 / 1)
			for (x = x88, xp_0 = 0;
				x < x88 + 7;
				x += 1, xp_0 += 1){
				// y = 7, x = 1, h = 3, w = 3, c = 32, f = 32
				// T (h, 3) (3 / 1)
				for (h = h68, hp_0 = 0;
					h < h68 + 3;
					h += 1, hp_0 += 1){
					// y = 7, x = 1, h = 1, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w68, wp_0 = 0;
						w < w68 + 3;
						w += 1, wp_0 += 1){
								mem_vec_721 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_722 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c171, cp_1 = c171_p_0, cp_0 = 0;
									c < c171 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_721);
									mem_vec_721 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_722);
									mem_vec_722 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_723);
									mem_vec_723 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_724);
									mem_vec_724 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_725);
									mem_vec_725 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_726);
									mem_vec_726 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_727);
									mem_vec_727 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_728);
									mem_vec_728 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_729);
									mem_vec_729 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_730);
									mem_vec_730 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_731);
									mem_vec_731 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_732);
									mem_vec_732 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_733);
									mem_vec_733 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_734);
									mem_vec_734 = vec_22;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_721);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_722);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_723);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_724);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_725);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_726);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_727);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_728);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_729);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_730);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_731);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_732);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_733);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_734);
					}
				}
			}
		}
	}
}


}