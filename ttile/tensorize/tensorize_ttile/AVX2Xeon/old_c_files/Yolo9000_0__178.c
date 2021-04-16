#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (2, x); T (1, c);
  T (3, w); T (3, h); T (34, y); T (272, x); T (1, y); T (4, y)]
*/
IND_TYPE c, cp_0, c40_p_0, cp_1, c40, h, hp_0, w, wp_0, x, xp_0, x44_p_0, xp_1, x44, y, yp_0, y54_p_0, y55_p_0, yp_1, y54_p_1, yp_2, y54, y55;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y56 = 0;
IND_TYPE x45 = 0;
IND_TYPE h24 = 0;
IND_TYPE w26 = 0;
IND_TYPE c41 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_242 ,mem_vec_243 ,mem_vec_244 ,mem_vec_245 ,mem_vec_246 ,mem_vec_247 ,mem_vec_248 ,mem_vec_249 ,mem_vec_250 ,mem_vec_251 ,mem_vec_252 ,mem_vec_253 ,mem_vec_254 ,mem_vec_255 ,mem_vec_256 ,mem_vec_257 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 4) (544 / 136)
for (y55 = y56, y55_p_0 = 0;
	y55 < y56 + 544;
	y55 += 136, y55_p_0 += 136){
	// y = 136, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (y, 1) (136 / 136)
	for (y54 = y55, y54_p_1 = y55_p_0, y54_p_0 = 0;
		y54 < y55 + 136;
		y54 += 136, y54_p_1 += 136, y54_p_0 += 136){
		// y = 136, x = 544, h = 3, w = 3, c = 3, f = 32
		// T (x, 272) (544 / 2)
		for (x44 = x45, x44_p_0 = 0;
			x44 < x45 + 544;
			x44 += 2, x44_p_0 += 2){
			// y = 136, x = 2, h = 3, w = 3, c = 3, f = 32
			// T (y, 34) (136 / 4)
			for (y = y54, yp_2 = y54_p_1, yp_1 = y54_p_0, yp_0 = 0;
				y < y54 + 136;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 2, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h24, hp_0 = 0;
					h < h24 + 3;
					h += 1, hp_0 += 1){
					// y = 4, x = 2, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w26, wp_0 = 0;
						w < w26 + 3;
						w += 1, wp_0 += 1){
						// y = 4, x = 2, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c40 = c41, c40_p_0 = 0;
							c40 < c41 + 3;
							c40 += 3, c40_p_0 += 3){
							// y = 4, x = 2, h = 1, w = 1, c = 3, f = 32
							// T (x, 2) (2 / 1)
							for (x = x44, xp_1 = x44_p_0, xp_0 = 0;
								x < x44 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_242 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_243 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_244 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_245 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_248 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_249 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_250 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_251 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_252 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_253 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_254 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_255 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_256 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_257 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c40, cp_1 = c40_p_0, cp_0 = 0;
											c < c40 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_242);
											mem_vec_242 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_243);
											mem_vec_243 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_244);
											mem_vec_244 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_245);
											mem_vec_245 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_246);
											mem_vec_246 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_247);
											mem_vec_247 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_248);
											mem_vec_248 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_249);
											mem_vec_249 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_250);
											mem_vec_250 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_251);
											mem_vec_251 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_252);
											mem_vec_252 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_253);
											mem_vec_253 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_254);
											mem_vec_254 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_255);
											mem_vec_255 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_256);
											mem_vec_256 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_257);
											mem_vec_257 = vec_23;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_242);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_243);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_244);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_245);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_246);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_247);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_248);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_249);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_250);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_251);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_252);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_253);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_254);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_255);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_256);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_257);
							}
						}
					}
				}
			}
		}
	}
}


}