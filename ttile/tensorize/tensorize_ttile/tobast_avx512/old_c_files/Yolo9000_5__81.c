#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (4, c); Hoist_vars [c]; T (68, x); T (34, y);
  T (32, c); T (2, x)]
*/
IND_TYPE c, cp_0, c104_p_0, cp_1, c104, x, xp_0, x160_p_0, xp_1, x160, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y88 = 0;
IND_TYPE x161 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c105 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 2) (136 / 68)
for (x160 = x161, x160_p_0 = 0;
	x160 < x161 + 136;
	x160 += 68, x160_p_0 += 68){
	// y = 136, x = 68, h = 1, w = 1, c = 128, f = 64
	// T (c, 32) (128 / 4)
	for (c104 = c105, c104_p_0 = 0;
		c104 < c105 + 128;
		c104 += 4, c104_p_0 += 4){
		// y = 136, x = 68, h = 1, w = 1, c = 4, f = 64
		// T (y, 34) (136 / 4)
		for (y = y88, yp_0 = 0;
			y < y88 + 136;
			y += 4, yp_0 += 4){
			// y = 4, x = 68, h = 1, w = 1, c = 4, f = 64
			// T (x, 68) (68 / 1)
			for (x = x160, xp_1 = x160_p_0, xp_0 = 0;
				x < x160 + 68;
				x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_704 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
						mem_vec_705 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
						mem_vec_706 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
						mem_vec_707 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
						mem_vec_708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
						mem_vec_709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
						mem_vec_710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
						mem_vec_711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
						mem_vec_712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
						mem_vec_713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
						mem_vec_714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
						mem_vec_715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
						mem_vec_716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
						mem_vec_717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
						mem_vec_718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
						mem_vec_719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
						// y = 4, x = 1, h = 1, w = 1, c = 4, f = 64
						// T (c, 4) (4 / 1)
						for (c = c104, cp_1 = c104_p_0, cp_0 = 0;
							c < c104 + 4;
							c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_704);
							mem_vec_704 = vec_0;

							vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_705);
							mem_vec_705 = vec_3;

							vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

							vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_706);
							mem_vec_706 = vec_5;

							vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

							vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_707);
							mem_vec_707 = vec_7;
							scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
							vec_10 = _mm512_set1_ps(scal_1);


							vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_708);
							mem_vec_708 = vec_9;



							vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_709);
							mem_vec_709 = vec_11;



							vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_710);
							mem_vec_710 = vec_12;



							vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_711);
							mem_vec_711 = vec_13;
							scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
							vec_15 = _mm512_set1_ps(scal_2);


							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_712);
							mem_vec_712 = vec_14;



							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_713);
							mem_vec_713 = vec_16;



							vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_714);
							mem_vec_714 = vec_17;



							vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_715);
							mem_vec_715 = vec_18;
							scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
							vec_20 = _mm512_set1_ps(scal_3);


							vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_716);
							mem_vec_716 = vec_19;



							vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_717);
							mem_vec_717 = vec_21;



							vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_718);
							mem_vec_718 = vec_22;



							vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_719);
							mem_vec_719 = vec_23;
						}
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_704);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_705);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_706);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_707);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_708);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_709);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_710);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_711);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_712);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_713);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_714);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_715);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_716);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_717);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_718);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_719);
			}
		}
	}
}


}