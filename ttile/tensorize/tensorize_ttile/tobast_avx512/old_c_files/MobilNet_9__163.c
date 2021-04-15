#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (2, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (8, c); T (8, f); T (4, c); T (4, f); T (16, c)]
*/
IND_TYPE c, cp_0, c70_p_0, c71_p_0, c72_p_0, cp_1, c70_p_1, c71_p_1, cp_2, c70_p_2, cp_3, c70, c71, c72, f, fp_0, f42_p_0, fp_1, f42, h, hp_0, w, wp_0, x, xp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y = 0;
IND_TYPE x28 = 0;
IND_TYPE h28 = 0;
IND_TYPE w28 = 0;
IND_TYPE c73 = 0;
IND_TYPE f43 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_196 ,mem_vec_197 ,mem_vec_198 ,mem_vec_199 ,mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,mem_vec_208 ,mem_vec_209 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 16) (1024 / 64)
for (c72 = c73, c72_p_0 = 0;
	c72 < c73 + 1024;
	c72 += 64, c72_p_0 += 64){
	// y = 7, x = 7, h = 3, w = 3, c = 64, f = 1024
	// T (f, 4) (1024 / 256)
	for (f42 = f43, f42_p_0 = 0;
		f42 < f43 + 1024;
		f42 += 256, f42_p_0 += 256){
		// y = 7, x = 7, h = 3, w = 3, c = 64, f = 256
		// T (c, 4) (64 / 16)
		for (c71 = c72, c71_p_1 = c72_p_0, c71_p_0 = 0;
			c71 < c72 + 64;
			c71 += 16, c71_p_1 += 16, c71_p_0 += 16){
			// y = 7, x = 7, h = 3, w = 3, c = 16, f = 256
			// T (f, 8) (256 / 32)
			for (f = f42, fp_1 = f42_p_0, fp_0 = 0;
				f < f42 + 256;
				f += 32, fp_1 += 32, fp_0 += 32){
				// y = 7, x = 7, h = 3, w = 3, c = 16, f = 32
				// T (c, 8) (16 / 2)
				for (c70 = c71, c70_p_2 = c71_p_1, c70_p_1 = c71_p_0, c70_p_0 = 0;
					c70 < c71 + 16;
					c70 += 2, c70_p_2 += 2, c70_p_1 += 2, c70_p_0 += 2){
					// y = 7, x = 7, h = 3, w = 3, c = 2, f = 32
					// T (h, 3) (3 / 1)
					for (h = h28, hp_0 = 0;
						h < h28 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 7, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w28, wp_0 = 0;
							w < w28 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 7, h = 1, w = 1, c = 2, f = 32
							// T (x, 7) (7 / 1)
							for (x = x28, xp_0 = 0;
								x < x28 + 7;
								x += 1, xp_0 += 1){
										mem_vec_196 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_197 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = 7, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c70, cp_3 = c70_p_2, cp_2 = c70_p_1, cp_1 = c70_p_0, cp_0 = 0;
											c < c70 + 2;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_196);
											mem_vec_196 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_197);
											mem_vec_197 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_198);
											mem_vec_198 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_199);
											mem_vec_199 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_200);
											mem_vec_200 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_201);
											mem_vec_201 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_202);
											mem_vec_202 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_203);
											mem_vec_203 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_204);
											mem_vec_204 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_205);
											mem_vec_205 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_206);
											mem_vec_206 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_207);
											mem_vec_207 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_208);
											mem_vec_208 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_209);
											mem_vec_209 = vec_22;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_196);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_197);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_198);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_199);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_200);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_201);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_202);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_203);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_204);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_205);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_206);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_207);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_208);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_209);
							}
						}
					}
				}
			}
		}
	}
}


}