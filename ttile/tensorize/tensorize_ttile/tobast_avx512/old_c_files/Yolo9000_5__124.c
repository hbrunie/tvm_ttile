#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (128, c); Hoist_vars [c]; T (17, x); T (34, y);
  T (1, c); T (8, x)]
*/
IND_TYPE c, cp_0, c134_p_0, cp_1, c134, x, xp_0, x190_p_0, xp_1, x190, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y108 = 0;
IND_TYPE x191 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c135 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,mem_vec_868 ,mem_vec_869 ,mem_vec_870 ,mem_vec_871 ,mem_vec_872 ,mem_vec_873 ,mem_vec_874 ,mem_vec_875 ,mem_vec_876 ,mem_vec_877 ,mem_vec_878 ,mem_vec_879 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 8) (136 / 17)
for (x190 = x191, x190_p_0 = 0;
	x190 < x191 + 136;
	x190 += 17, x190_p_0 += 17){
	// y = 136, x = 17, h = 1, w = 1, c = 128, f = 64
	// T (c, 1) (128 / 128)
	for (c134 = c135, c134_p_0 = 0;
		c134 < c135 + 128;
		c134 += 128, c134_p_0 += 128){
		// y = 136, x = 17, h = 1, w = 1, c = 128, f = 64
		// T (y, 34) (136 / 4)
		for (y = y108, yp_0 = 0;
			y < y108 + 136;
			y += 4, yp_0 += 4){
			// y = 4, x = 17, h = 1, w = 1, c = 128, f = 64
			// T (x, 17) (17 / 1)
			for (x = x190, xp_1 = x190_p_0, xp_0 = 0;
				x < x190 + 17;
				x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_864 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
						mem_vec_865 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
						mem_vec_866 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
						mem_vec_867 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
						mem_vec_868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
						mem_vec_869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
						mem_vec_870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
						mem_vec_871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
						mem_vec_872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
						mem_vec_873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
						mem_vec_874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
						mem_vec_875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
						mem_vec_876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
						mem_vec_877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
						mem_vec_878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
						mem_vec_879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
						// y = 4, x = 1, h = 1, w = 1, c = 128, f = 64
						// T (c, 128) (128 / 1)
						for (c = c134, cp_1 = c134_p_0, cp_0 = 0;
							c < c134 + 128;
							c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_864);
							mem_vec_864 = vec_0;

							vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_865);
							mem_vec_865 = vec_3;

							vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

							vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_866);
							mem_vec_866 = vec_5;

							vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

							vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_867);
							mem_vec_867 = vec_7;
							scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
							vec_10 = _mm512_set1_ps(scal_1);


							vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_868);
							mem_vec_868 = vec_9;



							vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_869);
							mem_vec_869 = vec_11;



							vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_870);
							mem_vec_870 = vec_12;



							vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_871);
							mem_vec_871 = vec_13;
							scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
							vec_15 = _mm512_set1_ps(scal_2);


							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_872);
							mem_vec_872 = vec_14;



							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_873);
							mem_vec_873 = vec_16;



							vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_874);
							mem_vec_874 = vec_17;



							vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_875);
							mem_vec_875 = vec_18;
							scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
							vec_20 = _mm512_set1_ps(scal_3);


							vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_876);
							mem_vec_876 = vec_19;



							vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_877);
							mem_vec_877 = vec_21;



							vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_878);
							mem_vec_878 = vec_22;



							vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_879);
							mem_vec_879 = vec_23;
						}
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_864);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_865);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_866);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_867);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_868);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_869);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_870);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_871);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_872);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_873);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_874);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_875);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_876);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_877);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_878);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_879);
			}
		}
	}
}


}