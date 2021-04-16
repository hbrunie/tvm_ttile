#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (16, c); Hoist_vars [c]; T (1, x); T (16, f);
  T (16, c); T (7, x)]
*/
IND_TYPE c, cp_0, c81_p_0, cp_1, c81, f, fp_0, x, xp_0, x61_p_0, xp_1, x61;

assert((Y == 7));
assert((X == 7));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 512));
IND_TYPE y = 0;
IND_TYPE x62 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c82 = 0;
IND_TYPE f74 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_658 ,mem_vec_659 ,mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,mem_vec_664 ,mem_vec_665 ,mem_vec_666 ,mem_vec_667 ,mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 1, w = 1, c = 256, f = 512
// T (x, 7) (7 / 1)
for (x61 = x62, x61_p_0 = 0;
	x61 < x62 + 7;
	x61 += 1, x61_p_0 += 1){
	// y = 7, x = 1, h = 1, w = 1, c = 256, f = 512
	// T (c, 16) (256 / 16)
	for (c81 = c82, c81_p_0 = 0;
		c81 < c82 + 256;
		c81 += 16, c81_p_0 += 16){
		// y = 7, x = 1, h = 1, w = 1, c = 16, f = 512
		// T (f, 16) (512 / 32)
		for (f = f74, fp_0 = 0;
			f < f74 + 512;
			f += 32, fp_0 += 32){
			// y = 7, x = 1, h = 1, w = 1, c = 16, f = 32
			// T (x, 1) (1 / 1)
			for (x = x61, xp_1 = x61_p_0, xp_0 = 0;
				x < x61 + 1;
				x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_658 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
						mem_vec_659 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
						mem_vec_660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
						mem_vec_661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
						mem_vec_662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
						mem_vec_663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
						mem_vec_664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
						mem_vec_665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
						mem_vec_666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
						mem_vec_667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
						mem_vec_668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
						mem_vec_669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
						mem_vec_670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
						mem_vec_671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
						// y = 7, x = 1, h = 1, w = 1, c = 16, f = 32
						// T (c, 16) (16 / 1)
						for (c = c81, cp_1 = c81_p_0, cp_0 = 0;
							c < c81 + 16;
							c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_658);
							mem_vec_658 = vec_0;

							vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_659);
							mem_vec_659 = vec_3;
							scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
							vec_6 = _mm512_set1_ps(scal_1);


							vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_660);
							mem_vec_660 = vec_5;



							vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_661);
							mem_vec_661 = vec_7;
							scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
							vec_9 = _mm512_set1_ps(scal_2);


							vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_662);
							mem_vec_662 = vec_8;



							vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_663);
							mem_vec_663 = vec_10;
							scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
							vec_12 = _mm512_set1_ps(scal_3);


							vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_664);
							mem_vec_664 = vec_11;



							vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_665);
							mem_vec_665 = vec_13;
							scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
							vec_15 = _mm512_set1_ps(scal_4);


							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_666);
							mem_vec_666 = vec_14;



							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_667);
							mem_vec_667 = vec_16;
							scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
							vec_18 = _mm512_set1_ps(scal_5);


							vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_668);
							mem_vec_668 = vec_17;



							vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_669);
							mem_vec_669 = vec_19;
							scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
							vec_21 = _mm512_set1_ps(scal_6);


							vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_670);
							mem_vec_670 = vec_20;



							vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_671);
							mem_vec_671 = vec_22;
						}
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_658);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_659);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_660);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_661);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_662);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_663);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_664);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_665);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_666);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_667);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_668);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_669);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_670);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_671);
			}
		}
	}
}


}