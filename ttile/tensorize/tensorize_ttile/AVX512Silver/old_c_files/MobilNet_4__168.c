#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (8, c); T (1, f); T (1, x); T (7, y); T (2, f)]
*/
IND_TYPE c, cp_0, c279_p_0, cp_1, c279, f, fp_0, f279_p_0, fp_1, f279, h, hp_0, w, wp_0, x, xp_0, x236_p_0, xp_1, x236, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y186 = 0;
IND_TYPE x237 = 0;
IND_TYPE h134 = 0;
IND_TYPE w142 = 0;
IND_TYPE c280 = 0;
IND_TYPE f280 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_1685 ,mem_vec_1686 ,mem_vec_1687 ,mem_vec_1688 ,mem_vec_1689 ,mem_vec_1690 ,mem_vec_1691 ,mem_vec_1692 ,mem_vec_1693 ,mem_vec_1694 ,mem_vec_1695 ,mem_vec_1696 ,mem_vec_1697 ,mem_vec_1698 ,mem_vec_1699 ,mem_vec_1700 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f279 = f280, f279_p_0 = 0;
	f279 < f280 + 128;
	f279 += 64, f279_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 64
	// T (y, 7) (28 / 4)
	for (y = y186, yp_0 = 0;
		y < y186 + 28;
		y += 4, yp_0 += 4){
		// y = 4, x = 28, h = 3, w = 3, c = 128, f = 64
		// T (x, 1) (28 / 28)
		for (x236 = x237, x236_p_0 = 0;
			x236 < x237 + 28;
			x236 += 28, x236_p_0 += 28){
			// y = 4, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (f, 1) (64 / 64)
			for (f = f279, fp_1 = f279_p_0, fp_0 = 0;
				f < f279 + 64;
				f += 64, fp_1 += 64, fp_0 += 64){
				// y = 4, x = 28, h = 3, w = 3, c = 128, f = 64
				// T (c, 8) (128 / 16)
				for (c279 = c280, c279_p_0 = 0;
					c279 < c280 + 128;
					c279 += 16, c279_p_0 += 16){
					// y = 4, x = 28, h = 3, w = 3, c = 16, f = 64
					// T (w, 3) (3 / 1)
					for (w = w142, wp_0 = 0;
						w < w142 + 3;
						w += 1, wp_0 += 1){
						// y = 4, x = 28, h = 3, w = 1, c = 16, f = 64
						// T (x, 28) (28 / 1)
						for (x = x236, xp_1 = x236_p_0, xp_0 = 0;
							x < x236 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = 4, x = 1, h = 3, w = 1, c = 16, f = 64
							// T (h, 3) (3 / 1)
							for (h = h134, hp_0 = 0;
								h < h134 + 3;
								h += 1, hp_0 += 1){
										mem_vec_1685 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1686 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1687 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_1688 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_1689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_1692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_1693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_1696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_1697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_1700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = 4, x = 1, h = 1, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c279, cp_1 = c279_p_0, cp_0 = 0;
											c < c279 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1685);
											mem_vec_1685 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1686);
											mem_vec_1686 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1687);
											mem_vec_1687 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1688);
											mem_vec_1688 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1689);
											mem_vec_1689 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1690);
											mem_vec_1690 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1691);
											mem_vec_1691 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1692);
											mem_vec_1692 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1693);
											mem_vec_1693 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1694);
											mem_vec_1694 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1695);
											mem_vec_1695 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1696);
											mem_vec_1696 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1697);
											mem_vec_1697 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1698);
											mem_vec_1698 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1699);
											mem_vec_1699 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1700);
											mem_vec_1700 = vec_23;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1685);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1686);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1687);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1688);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1689);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1690);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1691);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1692);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1693);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1694);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1695);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1696);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1697);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1698);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1699);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1700);
							}
						}
					}
				}
			}
		}
	}
}


}