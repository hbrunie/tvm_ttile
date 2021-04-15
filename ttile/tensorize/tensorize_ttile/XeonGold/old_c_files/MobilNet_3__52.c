#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (32, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (4, c); T (4, f); T (1, x); T (7, y); T (2, x)]
*/
IND_TYPE c, cp_0, c21_p_0, cp_1, c21, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x26_p_0, x27_p_0, xp_1, x26_p_1, xp_2, x26, x27, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y14 = 0;
IND_TYPE x28 = 0;
IND_TYPE h13 = 0;
IND_TYPE w14 = 0;
IND_TYPE c22 = 0;
IND_TYPE f14 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_160 ,mem_vec_161 ,mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,mem_vec_168 ,mem_vec_169 ,mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 2) (56 / 28)
for (x27 = x28, x27_p_0 = 0;
	x27 < x28 + 56;
	x27 += 28, x27_p_0 += 28){
	// y = 56, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (y, 7) (56 / 8)
	for (y = y14, yp_0 = 0;
		y < y14 + 56;
		y += 8, yp_0 += 8){
		// y = 8, x = 28, h = 3, w = 3, c = 128, f = 128
		// T (x, 1) (28 / 28)
		for (x26 = x27, x26_p_1 = x27_p_0, x26_p_0 = 0;
			x26 < x27 + 28;
			x26 += 28, x26_p_1 += 28, x26_p_0 += 28){
			// y = 8, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (f, 4) (128 / 32)
			for (f = f14, fp_0 = 0;
				f < f14 + 128;
				f += 32, fp_0 += 32){
				// y = 8, x = 28, h = 3, w = 3, c = 128, f = 32
				// T (c, 4) (128 / 32)
				for (c21 = c22, c21_p_0 = 0;
					c21 < c22 + 128;
					c21 += 32, c21_p_0 += 32){
					// y = 8, x = 28, h = 3, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w14, wp_0 = 0;
						w < w14 + 3;
						w += 1, wp_0 += 1){
						// y = 8, x = 28, h = 3, w = 1, c = 32, f = 32
						// T (x, 28) (28 / 1)
						for (x = x26, xp_2 = x26_p_1, xp_1 = x26_p_0, xp_0 = 0;
							x < x26 + 28;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
							// y = 8, x = 1, h = 3, w = 1, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h13, hp_0 = 0;
								h < h13 + 3;
								h += 1, hp_0 += 1){
										mem_vec_160 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_161 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c21, cp_1 = c21_p_0, cp_0 = 0;
											c < c21 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_160);
											mem_vec_160 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_161);
											mem_vec_161 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_162);
											mem_vec_162 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_163);
											mem_vec_163 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_164);
											mem_vec_164 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_165);
											mem_vec_165 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_166);
											mem_vec_166 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_167);
											mem_vec_167 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_168);
											mem_vec_168 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_169);
											mem_vec_169 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_170);
											mem_vec_170 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_171);
											mem_vec_171 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_172);
											mem_vec_172 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_173);
											mem_vec_173 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_174);
											mem_vec_174 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_175);
											mem_vec_175 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_160);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_161);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_162);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_163);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_164);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_165);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_166);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_167);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_168);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_169);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_170);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_171);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_172);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_173);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_174);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_175);
							}
						}
					}
				}
			}
		}
	}
}


}