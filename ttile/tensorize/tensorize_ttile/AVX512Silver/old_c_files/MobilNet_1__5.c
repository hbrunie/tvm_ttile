#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (112, x); T (2, y); T (1, c); T (7, y)]
*/
IND_TYPE c, cp_0, c159_p_0, cp_1, c159, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y120_p_0, yp_1, y120;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y121 = 0;
IND_TYPE x184 = 0;
IND_TYPE h98 = 0;
IND_TYPE w63 = 0;
IND_TYPE c160 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_719 ,mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (y, 7) (112 / 16)
for (y120 = y121, y120_p_0 = 0;
	y120 < y121 + 112;
	y120 += 16, y120_p_0 += 16){
	// y = 16, x = 112, h = 3, w = 3, c = 32, f = 32
	// T (c, 1) (32 / 32)
	for (c159 = c160, c159_p_0 = 0;
		c159 < c160 + 32;
		c159 += 32, c159_p_0 += 32){
		// y = 16, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (y, 2) (16 / 8)
		for (y = y120, yp_1 = y120_p_0, yp_0 = 0;
			y < y120 + 16;
			y += 8, yp_1 += 8, yp_0 += 8){
			// y = 8, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (x, 112) (112 / 1)
			for (x = x184, xp_0 = 0;
				x < x184 + 112;
				x += 1, xp_0 += 1){
				// y = 8, x = 1, h = 3, w = 3, c = 32, f = 32
				// T (h, 3) (3 / 1)
				for (h = h98, hp_0 = 0;
					h < h98 + 3;
					h += 1, hp_0 += 1){
					// y = 8, x = 1, h = 1, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w63, wp_0 = 0;
						w < w63 + 3;
						w += 1, wp_0 += 1){
								mem_vec_719 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_720 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c159, cp_1 = c159_p_0, cp_0 = 0;
									c < c159 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_719);
									mem_vec_719 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_720);
									mem_vec_720 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_721);
									mem_vec_721 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_722);
									mem_vec_722 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_723);
									mem_vec_723 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_724);
									mem_vec_724 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_725);
									mem_vec_725 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_726);
									mem_vec_726 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_727);
									mem_vec_727 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_728);
									mem_vec_728 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_729);
									mem_vec_729 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_730);
									mem_vec_730 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_731);
									mem_vec_731 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_732);
									mem_vec_732 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_733);
									mem_vec_733 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_734);
									mem_vec_734 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_719);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_720);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_721);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_722);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_723);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_724);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_725);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_726);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_727);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_728);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_729);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_730);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_731);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_732);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_733);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_734);
					}
				}
			}
		}
	}
}


}