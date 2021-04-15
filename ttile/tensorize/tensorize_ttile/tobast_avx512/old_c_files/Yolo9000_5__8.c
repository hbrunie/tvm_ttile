#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (8, c); Hoist_vars [c]; T (68, x); T (34, y);
  T (16, c); T (2, x)]
*/
IND_TYPE c, cp_0, c98_p_0, cp_1, c98, x, xp_0, x154_p_0, xp_1, x154, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y84 = 0;
IND_TYPE x155 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c99 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_672 ,mem_vec_673 ,mem_vec_674 ,mem_vec_675 ,mem_vec_676 ,mem_vec_677 ,mem_vec_678 ,mem_vec_679 ,mem_vec_680 ,mem_vec_681 ,mem_vec_682 ,mem_vec_683 ,mem_vec_684 ,mem_vec_685 ,mem_vec_686 ,mem_vec_687 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 2) (136 / 68)
for (x154 = x155, x154_p_0 = 0;
	x154 < x155 + 136;
	x154 += 68, x154_p_0 += 68){
	// y = 136, x = 68, h = 1, w = 1, c = 128, f = 64
	// T (c, 16) (128 / 8)
	for (c98 = c99, c98_p_0 = 0;
		c98 < c99 + 128;
		c98 += 8, c98_p_0 += 8){
		// y = 136, x = 68, h = 1, w = 1, c = 8, f = 64
		// T (y, 34) (136 / 4)
		for (y = y84, yp_0 = 0;
			y < y84 + 136;
			y += 4, yp_0 += 4){
			// y = 4, x = 68, h = 1, w = 1, c = 8, f = 64
			// T (x, 68) (68 / 1)
			for (x = x154, xp_1 = x154_p_0, xp_0 = 0;
				x < x154 + 68;
				x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_672 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
						mem_vec_673 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
						mem_vec_674 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
						mem_vec_675 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
						mem_vec_676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
						mem_vec_677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
						mem_vec_678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
						mem_vec_679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
						mem_vec_680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
						mem_vec_681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
						mem_vec_682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
						mem_vec_683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
						mem_vec_684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
						mem_vec_685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
						mem_vec_686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
						mem_vec_687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
						// y = 4, x = 1, h = 1, w = 1, c = 8, f = 64
						// T (c, 8) (8 / 1)
						for (c = c98, cp_1 = c98_p_0, cp_0 = 0;
							c < c98 + 8;
							c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_672);
							mem_vec_672 = vec_0;

							vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_673);
							mem_vec_673 = vec_3;

							vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

							vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_674);
							mem_vec_674 = vec_5;

							vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

							vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_675);
							mem_vec_675 = vec_7;
							scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
							vec_10 = _mm512_set1_ps(scal_1);


							vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_676);
							mem_vec_676 = vec_9;



							vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_677);
							mem_vec_677 = vec_11;



							vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_678);
							mem_vec_678 = vec_12;



							vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_679);
							mem_vec_679 = vec_13;
							scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
							vec_15 = _mm512_set1_ps(scal_2);


							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_680);
							mem_vec_680 = vec_14;



							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_681);
							mem_vec_681 = vec_16;



							vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_682);
							mem_vec_682 = vec_17;



							vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_683);
							mem_vec_683 = vec_18;
							scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
							vec_20 = _mm512_set1_ps(scal_3);


							vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_684);
							mem_vec_684 = vec_19;



							vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_685);
							mem_vec_685 = vec_21;



							vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_686);
							mem_vec_686 = vec_22;



							vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_687);
							mem_vec_687 = vec_23;
						}
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_672);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_673);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_674);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_675);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_676);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_677);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_678);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_679);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_680);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_681);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_682);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_683);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_684);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_685);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_686);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_687);
			}
		}
	}
}


}