#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (4, x); T (2, f); T (1, c); T (2, y); T (68, x); T (17, y)]
*/
IND_TYPE c, cp_0, c267_p_0, cp_1, c267, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x320_p_0, xp_1, x320, y, yp_0, y308_p_0, yp_1, y308;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y309 = 0;
IND_TYPE x321 = 0;
IND_TYPE h137 = 0;
IND_TYPE w166 = 0;
IND_TYPE c268 = 0;
IND_TYPE f166 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_2665 ,mem_vec_2666 ,mem_vec_2667 ,mem_vec_2668 ,mem_vec_2669 ,mem_vec_2670 ,mem_vec_2671 ,mem_vec_2672 ,mem_vec_2673 ,mem_vec_2674 ,mem_vec_2675 ,mem_vec_2676 ,mem_vec_2677 ,mem_vec_2678 ,mem_vec_2679 ,mem_vec_2680 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 17) (272 / 16)
for (y308 = y309, y308_p_0 = 0;
	y308 < y309 + 272;
	y308 += 16, y308_p_0 += 16){
	// y = 16, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 68) (272 / 4)
	for (x320 = x321, x320_p_0 = 0;
		x320 < x321 + 272;
		x320 += 4, x320_p_0 += 4){
		// y = 16, x = 4, h = 3, w = 3, c = 32, f = 64
		// T (y, 2) (16 / 8)
		for (y = y308, yp_1 = y308_p_0, yp_0 = 0;
			y < y308 + 16;
			y += 8, yp_1 += 8, yp_0 += 8){
			// y = 8, x = 4, h = 3, w = 3, c = 32, f = 64
			// T (c, 1) (32 / 32)
			for (c267 = c268, c267_p_0 = 0;
				c267 < c268 + 32;
				c267 += 32, c267_p_0 += 32){
				// y = 8, x = 4, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f166, fp_0 = 0;
					f < f166 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 4, h = 3, w = 3, c = 32, f = 32
					// T (x, 4) (4 / 1)
					for (x = x320, xp_1 = x320_p_0, xp_0 = 0;
						x < x320 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
						// y = 8, x = 1, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h137, hp_0 = 0;
							h < h137 + 3;
							h += 1, hp_0 += 1){
							// y = 8, x = 1, h = 1, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w166, wp_0 = 0;
								w < w166 + 3;
								w += 1, wp_0 += 1){
										mem_vec_2665 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2666 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_2679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_2680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c267, cp_1 = c267_p_0, cp_0 = 0;
											c < c267 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2665);
											mem_vec_2665 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2666);
											mem_vec_2666 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2667);
											mem_vec_2667 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2668);
											mem_vec_2668 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2669);
											mem_vec_2669 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2670);
											mem_vec_2670 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2671);
											mem_vec_2671 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2672);
											mem_vec_2672 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2673);
											mem_vec_2673 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2674);
											mem_vec_2674 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2675);
											mem_vec_2675 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2676);
											mem_vec_2676 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2677);
											mem_vec_2677 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2678);
											mem_vec_2678 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2679);
											mem_vec_2679 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2680);
											mem_vec_2680 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2665);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2666);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2667);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2668);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2669);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2670);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2671);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2672);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2673);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2674);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2675);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2676);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2677);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2678);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2679);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2680);
							}
						}
					}
				}
			}
		}
	}
}


}