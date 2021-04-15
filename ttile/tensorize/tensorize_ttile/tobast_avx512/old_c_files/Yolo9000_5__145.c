#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (34, x); T (34, y);
  T (8, c); T (4, x)]
*/
IND_TYPE c, cp_0, c128_p_0, cp_1, c128, x, xp_0, x184_p_0, xp_1, x184, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y104 = 0;
IND_TYPE x185 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c129 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_832 ,mem_vec_833 ,mem_vec_834 ,mem_vec_835 ,mem_vec_836 ,mem_vec_837 ,mem_vec_838 ,mem_vec_839 ,mem_vec_840 ,mem_vec_841 ,mem_vec_842 ,mem_vec_843 ,mem_vec_844 ,mem_vec_845 ,mem_vec_846 ,mem_vec_847 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 4) (136 / 34)
for (x184 = x185, x184_p_0 = 0;
	x184 < x185 + 136;
	x184 += 34, x184_p_0 += 34){
	// y = 136, x = 34, h = 1, w = 1, c = 128, f = 64
	// T (c, 8) (128 / 16)
	for (c128 = c129, c128_p_0 = 0;
		c128 < c129 + 128;
		c128 += 16, c128_p_0 += 16){
		// y = 136, x = 34, h = 1, w = 1, c = 16, f = 64
		// T (y, 34) (136 / 4)
		for (y = y104, yp_0 = 0;
			y < y104 + 136;
			y += 4, yp_0 += 4){
			// y = 4, x = 34, h = 1, w = 1, c = 16, f = 64
			// T (x, 34) (34 / 1)
			for (x = x184, xp_1 = x184_p_0, xp_0 = 0;
				x < x184 + 34;
				x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_832 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
						mem_vec_833 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
						mem_vec_834 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
						mem_vec_835 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
						mem_vec_836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
						mem_vec_837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
						mem_vec_838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
						mem_vec_839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
						mem_vec_840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
						mem_vec_841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
						mem_vec_842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
						mem_vec_843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
						mem_vec_844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
						mem_vec_845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
						mem_vec_846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
						mem_vec_847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
						// y = 4, x = 1, h = 1, w = 1, c = 16, f = 64
						// T (c, 16) (16 / 1)
						for (c = c128, cp_1 = c128_p_0, cp_0 = 0;
							c < c128 + 16;
							c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_832);
							mem_vec_832 = vec_0;

							vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_833);
							mem_vec_833 = vec_3;

							vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

							vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_834);
							mem_vec_834 = vec_5;

							vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

							vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_835);
							mem_vec_835 = vec_7;
							scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
							vec_10 = _mm512_set1_ps(scal_1);


							vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_836);
							mem_vec_836 = vec_9;



							vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_837);
							mem_vec_837 = vec_11;



							vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_838);
							mem_vec_838 = vec_12;



							vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_839);
							mem_vec_839 = vec_13;
							scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
							vec_15 = _mm512_set1_ps(scal_2);


							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_840);
							mem_vec_840 = vec_14;



							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_841);
							mem_vec_841 = vec_16;



							vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_842);
							mem_vec_842 = vec_17;



							vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_843);
							mem_vec_843 = vec_18;
							scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
							vec_20 = _mm512_set1_ps(scal_3);


							vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_844);
							mem_vec_844 = vec_19;



							vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_845);
							mem_vec_845 = vec_21;



							vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_846);
							mem_vec_846 = vec_22;



							vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_847);
							mem_vec_847 = vec_23;
						}
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_832);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_833);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_834);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_835);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_836);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_837);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_838);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_839);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_840);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_841);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_842);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_843);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_844);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_845);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_846);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_847);
			}
		}
	}
}


}