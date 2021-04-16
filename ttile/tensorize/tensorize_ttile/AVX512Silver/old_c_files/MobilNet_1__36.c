#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (112, x); T (7, y); T (1, c); T (2, y)]
*/
IND_TYPE c, cp_0, c156_p_0, cp_1, c156, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y117_p_0, yp_1, y117;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y118 = 0;
IND_TYPE x182 = 0;
IND_TYPE h96 = 0;
IND_TYPE w61 = 0;
IND_TYPE c157 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (y, 2) (112 / 56)
for (y117 = y118, y117_p_0 = 0;
	y117 < y118 + 112;
	y117 += 56, y117_p_0 += 56){
	// y = 56, x = 112, h = 3, w = 3, c = 32, f = 32
	// T (c, 1) (32 / 32)
	for (c156 = c157, c156_p_0 = 0;
		c156 < c157 + 32;
		c156 += 32, c156_p_0 += 32){
		// y = 56, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (y, 7) (56 / 8)
		for (y = y117, yp_1 = y117_p_0, yp_0 = 0;
			y < y117 + 56;
			y += 8, yp_1 += 8, yp_0 += 8){
			// y = 8, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (x, 112) (112 / 1)
			for (x = x182, xp_0 = 0;
				x < x182 + 112;
				x += 1, xp_0 += 1){
				// y = 8, x = 1, h = 3, w = 3, c = 32, f = 32
				// T (h, 3) (3 / 1)
				for (h = h96, hp_0 = 0;
					h < h96 + 3;
					h += 1, hp_0 += 1){
					// y = 8, x = 1, h = 1, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w61, wp_0 = 0;
						w < w61 + 3;
						w += 1, wp_0 += 1){
								mem_vec_703 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_704 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c156, cp_1 = c156_p_0, cp_0 = 0;
									c < c156 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_703);
									mem_vec_703 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_704);
									mem_vec_704 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_705);
									mem_vec_705 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_706);
									mem_vec_706 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_707);
									mem_vec_707 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_708);
									mem_vec_708 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_709);
									mem_vec_709 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_710);
									mem_vec_710 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_711);
									mem_vec_711 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_712);
									mem_vec_712 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_713);
									mem_vec_713 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_714);
									mem_vec_714 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_715);
									mem_vec_715 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_716);
									mem_vec_716 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_717);
									mem_vec_717 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_718);
									mem_vec_718 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_703);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_704);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_705);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_706);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_707);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_708);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_709);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_710);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_711);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_712);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_713);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_714);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_715);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_716);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_717);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_718);
					}
				}
			}
		}
	}
}


}