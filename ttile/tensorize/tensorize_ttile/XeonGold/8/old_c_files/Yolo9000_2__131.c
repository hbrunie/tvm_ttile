#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (8, x); T (2, f); T (2, c); T (2, y); T (34, x); T (17, y)]
*/
IND_TYPE c, cp_0, c261_p_0, cp_1, c261, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x314_p_0, xp_1, x314, y, yp_0, y302_p_0, yp_1, y302;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y303 = 0;
IND_TYPE x315 = 0;
IND_TYPE h133 = 0;
IND_TYPE w162 = 0;
IND_TYPE c262 = 0;
IND_TYPE f162 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_2633 ,mem_vec_2634 ,mem_vec_2635 ,mem_vec_2636 ,mem_vec_2637 ,mem_vec_2638 ,mem_vec_2639 ,mem_vec_2640 ,mem_vec_2641 ,mem_vec_2642 ,mem_vec_2643 ,mem_vec_2644 ,mem_vec_2645 ,mem_vec_2646 ,mem_vec_2647 ,mem_vec_2648 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 17) (272 / 16)
for (y302 = y303, y302_p_0 = 0;
	y302 < y303 + 272;
	y302 += 16, y302_p_0 += 16){
	// y = 16, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 34) (272 / 8)
	for (x314 = x315, x314_p_0 = 0;
		x314 < x315 + 272;
		x314 += 8, x314_p_0 += 8){
		// y = 16, x = 8, h = 3, w = 3, c = 32, f = 64
		// T (y, 2) (16 / 8)
		for (y = y302, yp_1 = y302_p_0, yp_0 = 0;
			y < y302 + 16;
			y += 8, yp_1 += 8, yp_0 += 8){
			// y = 8, x = 8, h = 3, w = 3, c = 32, f = 64
			// T (c, 2) (32 / 16)
			for (c261 = c262, c261_p_0 = 0;
				c261 < c262 + 32;
				c261 += 16, c261_p_0 += 16){
				// y = 8, x = 8, h = 3, w = 3, c = 16, f = 64
				// T (f, 2) (64 / 32)
				for (f = f162, fp_0 = 0;
					f < f162 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 8, h = 3, w = 3, c = 16, f = 32
					// T (x, 8) (8 / 1)
					for (x = x314, xp_1 = x314_p_0, xp_0 = 0;
						x < x314 + 8;
						x += 1, xp_1 += 1, xp_0 += 1){
						// y = 8, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h133, hp_0 = 0;
							h < h133 + 3;
							h += 1, hp_0 += 1){
							// y = 8, x = 1, h = 1, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w162, wp_0 = 0;
								w < w162 + 3;
								w += 1, wp_0 += 1){
										mem_vec_2633 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2634 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_2647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_2648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c261, cp_1 = c261_p_0, cp_0 = 0;
											c < c261 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2633);
											mem_vec_2633 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2634);
											mem_vec_2634 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2635);
											mem_vec_2635 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2636);
											mem_vec_2636 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2637);
											mem_vec_2637 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2638);
											mem_vec_2638 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2639);
											mem_vec_2639 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2640);
											mem_vec_2640 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2641);
											mem_vec_2641 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2642);
											mem_vec_2642 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2643);
											mem_vec_2643 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2644);
											mem_vec_2644 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2645);
											mem_vec_2645 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2646);
											mem_vec_2646 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2647);
											mem_vec_2647 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2648);
											mem_vec_2648 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2633);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2634);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2635);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2636);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2637);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2638);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2639);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2640);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2641);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2642);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2643);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2644);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2645);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2646);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2647);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2648);
							}
						}
					}
				}
			}
		}
	}
}


}