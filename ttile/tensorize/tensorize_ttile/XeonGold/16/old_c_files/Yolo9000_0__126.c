#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (3, c); Hoist_vars [c]; T (4, x); T (1, c);
  T (3, w); T (3, h); T (17, y); T (34, x); T (4, x); T (4, y)]
*/
IND_TYPE c, cp_0, c243_p_0, cp_1, c243, h, hp_0, w, wp_0, x, xp_0, x372_p_0, x373_p_0, xp_1, x372_p_1, xp_2, x372, x373, y, yp_0, y315_p_0, yp_1, y315;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y316 = 0;
IND_TYPE x374 = 0;
IND_TYPE h150 = 0;
IND_TYPE w186 = 0;
IND_TYPE c244 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_2720 ,mem_vec_2721 ,mem_vec_2722 ,mem_vec_2723 ,mem_vec_2724 ,mem_vec_2725 ,mem_vec_2726 ,mem_vec_2727 ,mem_vec_2728 ,mem_vec_2729 ,mem_vec_2730 ,mem_vec_2731 ,mem_vec_2732 ,mem_vec_2733 ,mem_vec_2734 ,mem_vec_2735 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 4) (544 / 136)
for (y315 = y316, y315_p_0 = 0;
	y315 < y316 + 544;
	y315 += 136, y315_p_0 += 136){
	// y = 136, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (x, 4) (544 / 136)
	for (x373 = x374, x373_p_0 = 0;
		x373 < x374 + 544;
		x373 += 136, x373_p_0 += 136){
		// y = 136, x = 136, h = 3, w = 3, c = 3, f = 32
		// T (x, 34) (136 / 4)
		for (x372 = x373, x372_p_1 = x373_p_0, x372_p_0 = 0;
			x372 < x373 + 136;
			x372 += 4, x372_p_1 += 4, x372_p_0 += 4){
			// y = 136, x = 4, h = 3, w = 3, c = 3, f = 32
			// T (y, 17) (136 / 8)
			for (y = y315, yp_1 = y315_p_0, yp_0 = 0;
				y < y315 + 136;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = 8, x = 4, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h150, hp_0 = 0;
					h < h150 + 3;
					h += 1, hp_0 += 1){
					// y = 8, x = 4, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w186, wp_0 = 0;
						w < w186 + 3;
						w += 1, wp_0 += 1){
						// y = 8, x = 4, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c243 = c244, c243_p_0 = 0;
							c243 < c244 + 3;
							c243 += 3, c243_p_0 += 3){
							// y = 8, x = 4, h = 1, w = 1, c = 3, f = 32
							// T (x, 4) (4 / 1)
							for (x = x372, xp_2 = x372_p_1, xp_1 = x372_p_0, xp_0 = 0;
								x < x372 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2720 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2721 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_2734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_2735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c243, cp_1 = c243_p_0, cp_0 = 0;
											c < c243 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2720);
											mem_vec_2720 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2721);
											mem_vec_2721 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2722);
											mem_vec_2722 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2723);
											mem_vec_2723 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2724);
											mem_vec_2724 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2725);
											mem_vec_2725 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2726);
											mem_vec_2726 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2727);
											mem_vec_2727 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2728);
											mem_vec_2728 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2729);
											mem_vec_2729 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2730);
											mem_vec_2730 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2731);
											mem_vec_2731 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2732);
											mem_vec_2732 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2733);
											mem_vec_2733 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2734);
											mem_vec_2734 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2735);
											mem_vec_2735 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2720);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2721);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2722);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2723);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2724);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2725);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2726);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2727);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2728);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2729);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2730);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2731);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2732);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2733);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2734);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2735);
							}
						}
					}
				}
			}
		}
	}
}


}