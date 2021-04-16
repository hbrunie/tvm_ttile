#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (32, c); Hoist_vars [c]; T (7, x); T (16, f);
  T (8, c); T (1, x)]
*/
IND_TYPE c, cp_0, c69_p_0, cp_1, c69, f, fp_0, x, xp_0, x49_p_0, xp_1, x49;

assert((Y == 7));
assert((X == 7));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 512));
IND_TYPE y = 0;
IND_TYPE x50 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c70 = 0;
IND_TYPE f66 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_602 ,mem_vec_603 ,mem_vec_604 ,mem_vec_605 ,mem_vec_606 ,mem_vec_607 ,mem_vec_608 ,mem_vec_609 ,mem_vec_610 ,mem_vec_611 ,mem_vec_612 ,mem_vec_613 ,mem_vec_614 ,mem_vec_615 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 1, w = 1, c = 256, f = 512
// T (x, 1) (7 / 7)
for (x49 = x50, x49_p_0 = 0;
	x49 < x50 + 7;
	x49 += 7, x49_p_0 += 7){
	// y = 7, x = 7, h = 1, w = 1, c = 256, f = 512
	// T (c, 8) (256 / 32)
	for (c69 = c70, c69_p_0 = 0;
		c69 < c70 + 256;
		c69 += 32, c69_p_0 += 32){
		// y = 7, x = 7, h = 1, w = 1, c = 32, f = 512
		// T (f, 16) (512 / 32)
		for (f = f66, fp_0 = 0;
			f < f66 + 512;
			f += 32, fp_0 += 32){
			// y = 7, x = 7, h = 1, w = 1, c = 32, f = 32
			// T (x, 7) (7 / 1)
			for (x = x49, xp_1 = x49_p_0, xp_0 = 0;
				x < x49 + 7;
				x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_602 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
						mem_vec_603 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
						mem_vec_604 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
						mem_vec_605 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
						mem_vec_606 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
						mem_vec_607 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
						mem_vec_608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
						mem_vec_609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
						mem_vec_610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
						mem_vec_611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
						mem_vec_612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
						mem_vec_613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
						mem_vec_614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
						mem_vec_615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
						// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
						// T (c, 32) (32 / 1)
						for (c = c69, cp_1 = c69_p_0, cp_0 = 0;
							c < c69 + 32;
							c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_602);
							mem_vec_602 = vec_0;

							vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_603);
							mem_vec_603 = vec_3;
							scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
							vec_6 = _mm512_set1_ps(scal_1);


							vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_604);
							mem_vec_604 = vec_5;



							vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_605);
							mem_vec_605 = vec_7;
							scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
							vec_9 = _mm512_set1_ps(scal_2);


							vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_606);
							mem_vec_606 = vec_8;



							vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_607);
							mem_vec_607 = vec_10;
							scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
							vec_12 = _mm512_set1_ps(scal_3);


							vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_608);
							mem_vec_608 = vec_11;



							vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_609);
							mem_vec_609 = vec_13;
							scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
							vec_15 = _mm512_set1_ps(scal_4);


							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_610);
							mem_vec_610 = vec_14;



							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_611);
							mem_vec_611 = vec_16;
							scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
							vec_18 = _mm512_set1_ps(scal_5);


							vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_612);
							mem_vec_612 = vec_17;



							vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_613);
							mem_vec_613 = vec_19;
							scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
							vec_21 = _mm512_set1_ps(scal_6);


							vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_614);
							mem_vec_614 = vec_20;



							vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_615);
							mem_vec_615 = vec_22;
						}
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_602);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_603);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_604);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_605);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_606);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_607);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_608);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_609);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_610);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_611);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_612);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_613);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_614);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_615);
			}
		}
	}
}


}