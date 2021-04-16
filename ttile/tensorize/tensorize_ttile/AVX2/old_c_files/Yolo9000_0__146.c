#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (3, w); T (3, h); T (17, y); T (544, x); T (1, y); T (8, y)]
*/
IND_TYPE c, cp_0, c265_p_0, cp_1, c265, h, hp_0, w, wp_0, x, xp_0, x317_p_0, xp_1, x317, y, yp_0, y362_p_0, y363_p_0, yp_1, y362_p_1, yp_2, y362, y363;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y364 = 0;
IND_TYPE x318 = 0;
IND_TYPE h151 = 0;
IND_TYPE w177 = 0;
IND_TYPE c266 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_2112 ,mem_vec_2113 ,mem_vec_2114 ,mem_vec_2115 ,mem_vec_2116 ,mem_vec_2117 ,mem_vec_2118 ,mem_vec_2119 ,mem_vec_2120 ,mem_vec_2121 ,mem_vec_2122 ,mem_vec_2123 ,mem_vec_2124 ,mem_vec_2125 ,mem_vec_2126 ,mem_vec_2127 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 8) (544 / 68)
for (y363 = y364, y363_p_0 = 0;
	y363 < y364 + 544;
	y363 += 68, y363_p_0 += 68){
	// y = 68, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (y, 1) (68 / 68)
	for (y362 = y363, y362_p_1 = y363_p_0, y362_p_0 = 0;
		y362 < y363 + 68;
		y362 += 68, y362_p_1 += 68, y362_p_0 += 68){
		// y = 68, x = 544, h = 3, w = 3, c = 3, f = 32
		// T (x, 544) (544 / 1)
		for (x317 = x318, x317_p_0 = 0;
			x317 < x318 + 544;
			x317 += 1, x317_p_0 += 1){
			// y = 68, x = 1, h = 3, w = 3, c = 3, f = 32
			// T (y, 17) (68 / 4)
			for (y = y362, yp_2 = y362_p_1, yp_1 = y362_p_0, yp_0 = 0;
				y < y362 + 68;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 1, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h151, hp_0 = 0;
					h < h151 + 3;
					h += 1, hp_0 += 1){
					// y = 4, x = 1, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w177, wp_0 = 0;
						w < w177 + 3;
						w += 1, wp_0 += 1){
						// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c265 = c266, c265_p_0 = 0;
							c265 < c266 + 3;
							c265 += 3, c265_p_0 += 3){
							// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
							// T (x, 1) (1 / 1)
							for (x = x317, xp_1 = x317_p_0, xp_0 = 0;
								x < x317 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2112 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2113 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_2114 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2115 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_2116 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2117 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_2118 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2119 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_2120 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2121 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_2122 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2123 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_2124 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2125 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_2126 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2127 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c265, cp_1 = c265_p_0, cp_0 = 0;
											c < c265 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2112);
											mem_vec_2112 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2113);
											mem_vec_2113 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2114);
											mem_vec_2114 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2115);
											mem_vec_2115 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2116);
											mem_vec_2116 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2117);
											mem_vec_2117 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2118);
											mem_vec_2118 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2119);
											mem_vec_2119 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2120);
											mem_vec_2120 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2121);
											mem_vec_2121 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2122);
											mem_vec_2122 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2123);
											mem_vec_2123 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2124);
											mem_vec_2124 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2125);
											mem_vec_2125 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2126);
											mem_vec_2126 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2127);
											mem_vec_2127 = vec_23;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2112);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2113);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2114);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2115);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2116);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2117);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2118);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2119);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2120);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2121);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2122);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2123);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2124);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2125);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2126);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2127);
							}
						}
					}
				}
			}
		}
	}
}


}