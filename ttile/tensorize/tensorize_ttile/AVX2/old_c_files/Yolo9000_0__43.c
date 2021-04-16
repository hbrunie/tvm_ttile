#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (3, w); T (3, h); T (17, y); T (544, x); T (2, y); T (4, y)]
*/
IND_TYPE c, cp_0, c262_p_0, cp_1, c262, h, hp_0, w, wp_0, x, xp_0, x314_p_0, xp_1, x314, y, yp_0, y358_p_0, y359_p_0, yp_1, y358_p_1, yp_2, y358, y359;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y360 = 0;
IND_TYPE x315 = 0;
IND_TYPE h149 = 0;
IND_TYPE w175 = 0;
IND_TYPE c263 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_2096 ,mem_vec_2097 ,mem_vec_2098 ,mem_vec_2099 ,mem_vec_2100 ,mem_vec_2101 ,mem_vec_2102 ,mem_vec_2103 ,mem_vec_2104 ,mem_vec_2105 ,mem_vec_2106 ,mem_vec_2107 ,mem_vec_2108 ,mem_vec_2109 ,mem_vec_2110 ,mem_vec_2111 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 4) (544 / 136)
for (y359 = y360, y359_p_0 = 0;
	y359 < y360 + 544;
	y359 += 136, y359_p_0 += 136){
	// y = 136, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (y, 2) (136 / 68)
	for (y358 = y359, y358_p_1 = y359_p_0, y358_p_0 = 0;
		y358 < y359 + 136;
		y358 += 68, y358_p_1 += 68, y358_p_0 += 68){
		// y = 68, x = 544, h = 3, w = 3, c = 3, f = 32
		// T (x, 544) (544 / 1)
		for (x314 = x315, x314_p_0 = 0;
			x314 < x315 + 544;
			x314 += 1, x314_p_0 += 1){
			// y = 68, x = 1, h = 3, w = 3, c = 3, f = 32
			// T (y, 17) (68 / 4)
			for (y = y358, yp_2 = y358_p_1, yp_1 = y358_p_0, yp_0 = 0;
				y < y358 + 68;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 1, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h149, hp_0 = 0;
					h < h149 + 3;
					h += 1, hp_0 += 1){
					// y = 4, x = 1, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w175, wp_0 = 0;
						w < w175 + 3;
						w += 1, wp_0 += 1){
						// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c262 = c263, c262_p_0 = 0;
							c262 < c263 + 3;
							c262 += 3, c262_p_0 += 3){
							// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
							// T (x, 1) (1 / 1)
							for (x = x314, xp_1 = x314_p_0, xp_0 = 0;
								x < x314 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2096 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2097 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_2098 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2099 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_2100 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2101 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_2102 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2103 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_2104 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2105 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_2106 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2107 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_2108 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2109 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_2110 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2111 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c262, cp_1 = c262_p_0, cp_0 = 0;
											c < c262 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2096);
											mem_vec_2096 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2097);
											mem_vec_2097 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2098);
											mem_vec_2098 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2099);
											mem_vec_2099 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2100);
											mem_vec_2100 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2101);
											mem_vec_2101 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2102);
											mem_vec_2102 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2103);
											mem_vec_2103 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2104);
											mem_vec_2104 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2105);
											mem_vec_2105 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2106);
											mem_vec_2106 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2107);
											mem_vec_2107 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2108);
											mem_vec_2108 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2109);
											mem_vec_2109 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2110);
											mem_vec_2110 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2111);
											mem_vec_2111 = vec_23;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2096);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2097);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2098);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2099);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2100);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2101);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2102);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2103);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2104);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2105);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2106);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2107);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2108);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2109);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2110);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2111);
							}
						}
					}
				}
			}
		}
	}
}


}