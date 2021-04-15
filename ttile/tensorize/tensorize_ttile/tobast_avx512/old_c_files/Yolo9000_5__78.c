#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (68, x); T (34, y);
  T (2, c); T (2, x)]
*/
IND_TYPE c, cp_0, c86_p_0, cp_1, c86, x, xp_0, x142_p_0, xp_1, x142, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y76 = 0;
IND_TYPE x143 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c87 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_608 ,mem_vec_609 ,mem_vec_610 ,mem_vec_611 ,mem_vec_612 ,mem_vec_613 ,mem_vec_614 ,mem_vec_615 ,mem_vec_616 ,mem_vec_617 ,mem_vec_618 ,mem_vec_619 ,mem_vec_620 ,mem_vec_621 ,mem_vec_622 ,mem_vec_623 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 2) (136 / 68)
for (x142 = x143, x142_p_0 = 0;
	x142 < x143 + 136;
	x142 += 68, x142_p_0 += 68){
	// y = 136, x = 68, h = 1, w = 1, c = 128, f = 64
	// T (c, 2) (128 / 64)
	for (c86 = c87, c86_p_0 = 0;
		c86 < c87 + 128;
		c86 += 64, c86_p_0 += 64){
		// y = 136, x = 68, h = 1, w = 1, c = 64, f = 64
		// T (y, 34) (136 / 4)
		for (y = y76, yp_0 = 0;
			y < y76 + 136;
			y += 4, yp_0 += 4){
			// y = 4, x = 68, h = 1, w = 1, c = 64, f = 64
			// T (x, 68) (68 / 1)
			for (x = x142, xp_1 = x142_p_0, xp_0 = 0;
				x < x142 + 68;
				x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_608 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
						mem_vec_609 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
						mem_vec_610 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
						mem_vec_611 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
						mem_vec_612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
						mem_vec_613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
						mem_vec_614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
						mem_vec_615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
						mem_vec_616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
						mem_vec_617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
						mem_vec_618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
						mem_vec_619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
						mem_vec_620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
						mem_vec_621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
						mem_vec_622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
						mem_vec_623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
						// y = 4, x = 1, h = 1, w = 1, c = 64, f = 64
						// T (c, 64) (64 / 1)
						for (c = c86, cp_1 = c86_p_0, cp_0 = 0;
							c < c86 + 64;
							c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_608);
							mem_vec_608 = vec_0;

							vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_609);
							mem_vec_609 = vec_3;

							vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

							vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_610);
							mem_vec_610 = vec_5;

							vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

							vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_611);
							mem_vec_611 = vec_7;
							scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
							vec_10 = _mm512_set1_ps(scal_1);


							vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_612);
							mem_vec_612 = vec_9;



							vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_613);
							mem_vec_613 = vec_11;



							vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_614);
							mem_vec_614 = vec_12;



							vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_615);
							mem_vec_615 = vec_13;
							scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
							vec_15 = _mm512_set1_ps(scal_2);


							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_616);
							mem_vec_616 = vec_14;



							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_617);
							mem_vec_617 = vec_16;



							vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_618);
							mem_vec_618 = vec_17;



							vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_619);
							mem_vec_619 = vec_18;
							scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
							vec_20 = _mm512_set1_ps(scal_3);


							vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_620);
							mem_vec_620 = vec_19;



							vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_621);
							mem_vec_621 = vec_21;



							vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_622);
							mem_vec_622 = vec_22;



							vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_623);
							mem_vec_623 = vec_23;
						}
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_608);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_609);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_610);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_611);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_612);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_613);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_614);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_615);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_616);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_617);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_618);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_619);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_620);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_621);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_622);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_623);
			}
		}
	}
}


}