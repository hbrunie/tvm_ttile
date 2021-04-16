#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (2, x); T (1, c);
  T (3, w); T (3, h); T (34, y); T (272, x); T (2, y); T (2, y)]
*/
IND_TYPE c, cp_0, c37_p_0, cp_1, c37, h, hp_0, w, wp_0, x, xp_0, x41_p_0, xp_1, x41, y, yp_0, y50_p_0, y51_p_0, yp_1, y50_p_1, yp_2, y50, y51;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y52 = 0;
IND_TYPE x42 = 0;
IND_TYPE h22 = 0;
IND_TYPE w24 = 0;
IND_TYPE c38 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,mem_vec_232 ,mem_vec_233 ,mem_vec_234 ,mem_vec_235 ,mem_vec_236 ,mem_vec_237 ,mem_vec_238 ,mem_vec_239 ,mem_vec_240 ,mem_vec_241 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 2) (544 / 272)
for (y51 = y52, y51_p_0 = 0;
	y51 < y52 + 544;
	y51 += 272, y51_p_0 += 272){
	// y = 272, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (y, 2) (272 / 136)
	for (y50 = y51, y50_p_1 = y51_p_0, y50_p_0 = 0;
		y50 < y51 + 272;
		y50 += 136, y50_p_1 += 136, y50_p_0 += 136){
		// y = 136, x = 544, h = 3, w = 3, c = 3, f = 32
		// T (x, 272) (544 / 2)
		for (x41 = x42, x41_p_0 = 0;
			x41 < x42 + 544;
			x41 += 2, x41_p_0 += 2){
			// y = 136, x = 2, h = 3, w = 3, c = 3, f = 32
			// T (y, 34) (136 / 4)
			for (y = y50, yp_2 = y50_p_1, yp_1 = y50_p_0, yp_0 = 0;
				y < y50 + 136;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 2, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h22, hp_0 = 0;
					h < h22 + 3;
					h += 1, hp_0 += 1){
					// y = 4, x = 2, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w24, wp_0 = 0;
						w < w24 + 3;
						w += 1, wp_0 += 1){
						// y = 4, x = 2, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c37 = c38, c37_p_0 = 0;
							c37 < c38 + 3;
							c37 += 3, c37_p_0 += 3){
							// y = 4, x = 2, h = 1, w = 1, c = 3, f = 32
							// T (x, 2) (2 / 1)
							for (x = x41, xp_1 = x41_p_0, xp_0 = 0;
								x < x41 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_226 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_227 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_228 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_229 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_230 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_231 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_232 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_233 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_234 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_235 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_236 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_237 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_240 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_241 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c37, cp_1 = c37_p_0, cp_0 = 0;
											c < c37 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_226);
											mem_vec_226 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_227);
											mem_vec_227 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_228);
											mem_vec_228 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_229);
											mem_vec_229 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_230);
											mem_vec_230 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_231);
											mem_vec_231 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_232);
											mem_vec_232 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_233);
											mem_vec_233 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_234);
											mem_vec_234 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_235);
											mem_vec_235 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_236);
											mem_vec_236 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_237);
											mem_vec_237 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_238);
											mem_vec_238 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_239);
											mem_vec_239 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_240);
											mem_vec_240 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_241);
											mem_vec_241 = vec_23;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_226);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_227);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_228);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_229);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_230);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_231);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_232);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_233);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_234);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_235);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_236);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_237);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_238);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_239);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_240);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_241);
							}
						}
					}
				}
			}
		}
	}
}


}