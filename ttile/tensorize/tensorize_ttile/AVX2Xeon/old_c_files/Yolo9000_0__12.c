#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (4, x); T (1, c);
  T (3, w); T (3, h); T (34, y); T (136, x); T (1, y); T (4, y)]
*/
IND_TYPE c, cp_0, c31_p_0, cp_1, c31, h, hp_0, w, wp_0, x, xp_0, x35_p_0, xp_1, x35, y, yp_0, y42_p_0, y43_p_0, yp_1, y42_p_1, yp_2, y42, y43;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y44 = 0;
IND_TYPE x36 = 0;
IND_TYPE h18 = 0;
IND_TYPE w20 = 0;
IND_TYPE c32 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_194 ,mem_vec_195 ,mem_vec_196 ,mem_vec_197 ,mem_vec_198 ,mem_vec_199 ,mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,mem_vec_208 ,mem_vec_209 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 4) (544 / 136)
for (y43 = y44, y43_p_0 = 0;
	y43 < y44 + 544;
	y43 += 136, y43_p_0 += 136){
	// y = 136, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (y, 1) (136 / 136)
	for (y42 = y43, y42_p_1 = y43_p_0, y42_p_0 = 0;
		y42 < y43 + 136;
		y42 += 136, y42_p_1 += 136, y42_p_0 += 136){
		// y = 136, x = 544, h = 3, w = 3, c = 3, f = 32
		// T (x, 136) (544 / 4)
		for (x35 = x36, x35_p_0 = 0;
			x35 < x36 + 544;
			x35 += 4, x35_p_0 += 4){
			// y = 136, x = 4, h = 3, w = 3, c = 3, f = 32
			// T (y, 34) (136 / 4)
			for (y = y42, yp_2 = y42_p_1, yp_1 = y42_p_0, yp_0 = 0;
				y < y42 + 136;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 4, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h18, hp_0 = 0;
					h < h18 + 3;
					h += 1, hp_0 += 1){
					// y = 4, x = 4, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w20, wp_0 = 0;
						w < w20 + 3;
						w += 1, wp_0 += 1){
						// y = 4, x = 4, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c31 = c32, c31_p_0 = 0;
							c31 < c32 + 3;
							c31 += 3, c31_p_0 += 3){
							// y = 4, x = 4, h = 1, w = 1, c = 3, f = 32
							// T (x, 4) (4 / 1)
							for (x = x35, xp_1 = x35_p_0, xp_0 = 0;
								x < x35 + 4;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_194 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_195 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_196 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_197 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_198 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_199 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_200 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_201 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_202 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_203 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_204 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_205 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_206 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_207 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_208 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_209 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c31, cp_1 = c31_p_0, cp_0 = 0;
											c < c31 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_194);
											mem_vec_194 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_195);
											mem_vec_195 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_196);
											mem_vec_196 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_197);
											mem_vec_197 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_198);
											mem_vec_198 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_199);
											mem_vec_199 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_200);
											mem_vec_200 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_201);
											mem_vec_201 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_202);
											mem_vec_202 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_203);
											mem_vec_203 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_204);
											mem_vec_204 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_205);
											mem_vec_205 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_206);
											mem_vec_206 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_207);
											mem_vec_207 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_208);
											mem_vec_208 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_209);
											mem_vec_209 = vec_23;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_194);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_195);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_196);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_197);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_198);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_199);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_200);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_201);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_202);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_203);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_204);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_205);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_206);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_207);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_208);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_209);
							}
						}
					}
				}
			}
		}
	}
}


}