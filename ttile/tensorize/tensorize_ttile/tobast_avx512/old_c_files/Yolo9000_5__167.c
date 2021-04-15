#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (136, x); T (34, y);
  T (4, c); T (1, x)]
*/
IND_TYPE c, cp_0, c68_p_0, cp_1, c68, x, xp_0, x124_p_0, xp_1, x124, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y64 = 0;
IND_TYPE x125 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c69 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_512 ,mem_vec_513 ,mem_vec_514 ,mem_vec_515 ,mem_vec_516 ,mem_vec_517 ,mem_vec_518 ,mem_vec_519 ,mem_vec_520 ,mem_vec_521 ,mem_vec_522 ,mem_vec_523 ,mem_vec_524 ,mem_vec_525 ,mem_vec_526 ,mem_vec_527 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 1) (136 / 136)
for (x124 = x125, x124_p_0 = 0;
	x124 < x125 + 136;
	x124 += 136, x124_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (c, 4) (128 / 32)
	for (c68 = c69, c68_p_0 = 0;
		c68 < c69 + 128;
		c68 += 32, c68_p_0 += 32){
		// y = 136, x = 136, h = 1, w = 1, c = 32, f = 64
		// T (y, 34) (136 / 4)
		for (y = y64, yp_0 = 0;
			y < y64 + 136;
			y += 4, yp_0 += 4){
			// y = 4, x = 136, h = 1, w = 1, c = 32, f = 64
			// T (x, 136) (136 / 1)
			for (x = x124, xp_1 = x124_p_0, xp_0 = 0;
				x < x124 + 136;
				x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_512 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
						mem_vec_513 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
						mem_vec_514 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
						mem_vec_515 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
						mem_vec_516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
						mem_vec_517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
						mem_vec_518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
						mem_vec_519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
						mem_vec_520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
						mem_vec_521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
						mem_vec_522 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
						mem_vec_523 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
						mem_vec_524 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
						mem_vec_525 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
						mem_vec_526 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
						mem_vec_527 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
						// y = 4, x = 1, h = 1, w = 1, c = 32, f = 64
						// T (c, 32) (32 / 1)
						for (c = c68, cp_1 = c68_p_0, cp_0 = 0;
							c < c68 + 32;
							c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_512);
							mem_vec_512 = vec_0;

							vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_513);
							mem_vec_513 = vec_3;

							vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

							vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_514);
							mem_vec_514 = vec_5;

							vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

							vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_515);
							mem_vec_515 = vec_7;
							scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
							vec_10 = _mm512_set1_ps(scal_1);


							vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_516);
							mem_vec_516 = vec_9;



							vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_517);
							mem_vec_517 = vec_11;



							vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_518);
							mem_vec_518 = vec_12;



							vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_519);
							mem_vec_519 = vec_13;
							scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
							vec_15 = _mm512_set1_ps(scal_2);


							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_520);
							mem_vec_520 = vec_14;



							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_521);
							mem_vec_521 = vec_16;



							vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_522);
							mem_vec_522 = vec_17;



							vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_523);
							mem_vec_523 = vec_18;
							scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
							vec_20 = _mm512_set1_ps(scal_3);


							vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_524);
							mem_vec_524 = vec_19;



							vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_525);
							mem_vec_525 = vec_21;



							vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_526);
							mem_vec_526 = vec_22;



							vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_527);
							mem_vec_527 = vec_23;
						}
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_512);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_513);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_514);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_515);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_516);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_517);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_518);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_519);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_520);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_521);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_522);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_523);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_524);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_525);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_526);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_527);
			}
		}
	}
}


}