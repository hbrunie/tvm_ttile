#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (3, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (3, w); T (3, h); T (34, y); T (2, x); T (4, x); T (2, y)]
*/
IND_TYPE c, cp_0, c513_p_0, cp_1, c513, h, hp_0, w, wp_0, x, xp_0, x732_p_0, x733_p_0, xp_1, x732_p_1, xp_2, x732, x733, y, yp_0, y585_p_0, yp_1, y585;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y586 = 0;
IND_TYPE x734 = 0;
IND_TYPE h330 = 0;
IND_TYPE w366 = 0;
IND_TYPE c514 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_6018 ,mem_vec_6019 ,mem_vec_6020 ,mem_vec_6021 ,mem_vec_6022 ,mem_vec_6023 ,mem_vec_6024 ,mem_vec_6025 ,mem_vec_6026 ,mem_vec_6027 ,mem_vec_6028 ,mem_vec_6029 ,mem_vec_6030 ,mem_vec_6031 ,mem_vec_6032 ,mem_vec_6033 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 2) (544 / 272)
for (y585 = y586, y585_p_0 = 0;
	y585 < y586 + 544;
	y585 += 272, y585_p_0 += 272){
	// y = 272, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (x, 4) (544 / 136)
	for (x733 = x734, x733_p_0 = 0;
		x733 < x734 + 544;
		x733 += 136, x733_p_0 += 136){
		// y = 272, x = 136, h = 3, w = 3, c = 3, f = 32
		// T (x, 2) (136 / 68)
		for (x732 = x733, x732_p_1 = x733_p_0, x732_p_0 = 0;
			x732 < x733 + 136;
			x732 += 68, x732_p_1 += 68, x732_p_0 += 68){
			// y = 272, x = 68, h = 3, w = 3, c = 3, f = 32
			// T (y, 34) (272 / 8)
			for (y = y585, yp_1 = y585_p_0, yp_0 = 0;
				y < y585 + 272;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = 8, x = 68, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h330, hp_0 = 0;
					h < h330 + 3;
					h += 1, hp_0 += 1){
					// y = 8, x = 68, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w366, wp_0 = 0;
						w < w366 + 3;
						w += 1, wp_0 += 1){
						// y = 8, x = 68, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c513 = c514, c513_p_0 = 0;
							c513 < c514 + 3;
							c513 += 3, c513_p_0 += 3){
							// y = 8, x = 68, h = 1, w = 1, c = 3, f = 32
							// T (x, 68) (68 / 1)
							for (x = x732, xp_2 = x732_p_1, xp_1 = x732_p_0, xp_0 = 0;
								x < x732 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6018 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6019 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6028 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6029 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_6032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_6033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c513, cp_1 = c513_p_0, cp_0 = 0;
											c < c513 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6018);
											mem_vec_6018 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6019);
											mem_vec_6019 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6020);
											mem_vec_6020 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6021);
											mem_vec_6021 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6022);
											mem_vec_6022 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6023);
											mem_vec_6023 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6024);
											mem_vec_6024 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6025);
											mem_vec_6025 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6026);
											mem_vec_6026 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6027);
											mem_vec_6027 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6028);
											mem_vec_6028 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6029);
											mem_vec_6029 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6030);
											mem_vec_6030 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6031);
											mem_vec_6031 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6032);
											mem_vec_6032 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6033);
											mem_vec_6033 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6018);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6019);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6020);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6021);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6022);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6023);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6024);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6025);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6026);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6027);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6028);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6029);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6030);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6031);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6032);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6033);
							}
						}
					}
				}
			}
		}
	}
}


}