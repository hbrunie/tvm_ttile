#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (2, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (1, c); T (4, f); T (8, c); T (8, f); T (64, c)]
*/
IND_TYPE c, cp_0, c100_p_0, c101_p_0, c102_p_0, cp_1, c100_p_1, c101_p_1, cp_2, c100_p_2, cp_3, c100, c101, c102, f, fp_0, f60_p_0, fp_1, f60, h, hp_0, w, wp_0, x, xp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y = 0;
IND_TYPE x40 = 0;
IND_TYPE h40 = 0;
IND_TYPE w40 = 0;
IND_TYPE c103 = 0;
IND_TYPE f61 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_280 ,mem_vec_281 ,mem_vec_282 ,mem_vec_283 ,mem_vec_284 ,mem_vec_285 ,mem_vec_286 ,mem_vec_287 ,mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 64) (1024 / 16)
for (c102 = c103, c102_p_0 = 0;
	c102 < c103 + 1024;
	c102 += 16, c102_p_0 += 16){
	// y = 7, x = 7, h = 3, w = 3, c = 16, f = 1024
	// T (f, 8) (1024 / 128)
	for (f60 = f61, f60_p_0 = 0;
		f60 < f61 + 1024;
		f60 += 128, f60_p_0 += 128){
		// y = 7, x = 7, h = 3, w = 3, c = 16, f = 128
		// T (c, 8) (16 / 2)
		for (c101 = c102, c101_p_1 = c102_p_0, c101_p_0 = 0;
			c101 < c102 + 16;
			c101 += 2, c101_p_1 += 2, c101_p_0 += 2){
			// y = 7, x = 7, h = 3, w = 3, c = 2, f = 128
			// T (f, 4) (128 / 32)
			for (f = f60, fp_1 = f60_p_0, fp_0 = 0;
				f < f60 + 128;
				f += 32, fp_1 += 32, fp_0 += 32){
				// y = 7, x = 7, h = 3, w = 3, c = 2, f = 32
				// T (c, 1) (2 / 2)
				for (c100 = c101, c100_p_2 = c101_p_1, c100_p_1 = c101_p_0, c100_p_0 = 0;
					c100 < c101 + 2;
					c100 += 2, c100_p_2 += 2, c100_p_1 += 2, c100_p_0 += 2){
					// y = 7, x = 7, h = 3, w = 3, c = 2, f = 32
					// T (h, 3) (3 / 1)
					for (h = h40, hp_0 = 0;
						h < h40 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 7, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w40, wp_0 = 0;
							w < w40 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 7, h = 1, w = 1, c = 2, f = 32
							// T (x, 7) (7 / 1)
							for (x = x40, xp_0 = 0;
								x < x40 + 7;
								x += 1, xp_0 += 1){
										mem_vec_280 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_281 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = 7, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c100, cp_3 = c100_p_2, cp_2 = c100_p_1, cp_1 = c100_p_0, cp_0 = 0;
											c < c100 + 2;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_280);
											mem_vec_280 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_281);
											mem_vec_281 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_282);
											mem_vec_282 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_283);
											mem_vec_283 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_284);
											mem_vec_284 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_285);
											mem_vec_285 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_286);
											mem_vec_286 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_287);
											mem_vec_287 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_288);
											mem_vec_288 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_289);
											mem_vec_289 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_290);
											mem_vec_290 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_291);
											mem_vec_291 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_292);
											mem_vec_292 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_293);
											mem_vec_293 = vec_22;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_280);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_281);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_282);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_283);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_284);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_285);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_286);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_287);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_288);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_289);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_290);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_291);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_292);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_293);
							}
						}
					}
				}
			}
		}
	}
}


}