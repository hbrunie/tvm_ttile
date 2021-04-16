#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (4, x); T (1, c);
  T (3, w); T (3, h); T (34, y); T (136, x); T (4, y); T (1, y)]
*/
IND_TYPE c, cp_0, c25_p_0, cp_1, c25, h, hp_0, w, wp_0, x, xp_0, x29_p_0, xp_1, x29, y, yp_0, y34_p_0, y35_p_0, yp_1, y34_p_1, yp_2, y34, y35;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y36 = 0;
IND_TYPE x30 = 0;
IND_TYPE h14 = 0;
IND_TYPE w16 = 0;
IND_TYPE c26 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,mem_vec_168 ,mem_vec_169 ,mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,mem_vec_176 ,mem_vec_177 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 1) (544 / 544)
for (y35 = y36, y35_p_0 = 0;
	y35 < y36 + 544;
	y35 += 544, y35_p_0 += 544){
	// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (y, 4) (544 / 136)
	for (y34 = y35, y34_p_1 = y35_p_0, y34_p_0 = 0;
		y34 < y35 + 544;
		y34 += 136, y34_p_1 += 136, y34_p_0 += 136){
		// y = 136, x = 544, h = 3, w = 3, c = 3, f = 32
		// T (x, 136) (544 / 4)
		for (x29 = x30, x29_p_0 = 0;
			x29 < x30 + 544;
			x29 += 4, x29_p_0 += 4){
			// y = 136, x = 4, h = 3, w = 3, c = 3, f = 32
			// T (y, 34) (136 / 4)
			for (y = y34, yp_2 = y34_p_1, yp_1 = y34_p_0, yp_0 = 0;
				y < y34 + 136;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 4, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h14, hp_0 = 0;
					h < h14 + 3;
					h += 1, hp_0 += 1){
					// y = 4, x = 4, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w16, wp_0 = 0;
						w < w16 + 3;
						w += 1, wp_0 += 1){
						// y = 4, x = 4, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c25 = c26, c25_p_0 = 0;
							c25 < c26 + 3;
							c25 += 3, c25_p_0 += 3){
							// y = 4, x = 4, h = 1, w = 1, c = 3, f = 32
							// T (x, 4) (4 / 1)
							for (x = x29, xp_1 = x29_p_0, xp_0 = 0;
								x < x29 + 4;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_162 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_163 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_164 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_165 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_166 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_167 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_168 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_169 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_170 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_171 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_172 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_173 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_174 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_175 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_176 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_177 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c25, cp_1 = c25_p_0, cp_0 = 0;
											c < c25 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_162);
											mem_vec_162 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_163);
											mem_vec_163 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_164);
											mem_vec_164 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_165);
											mem_vec_165 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_166);
											mem_vec_166 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_167);
											mem_vec_167 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_168);
											mem_vec_168 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_169);
											mem_vec_169 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_170);
											mem_vec_170 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_171);
											mem_vec_171 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_172);
											mem_vec_172 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_173);
											mem_vec_173 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_174);
											mem_vec_174 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_175);
											mem_vec_175 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_176);
											mem_vec_176 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_177);
											mem_vec_177 = vec_23;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_162);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_163);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_164);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_165);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_166);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_167);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_168);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_169);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_170);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_171);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_172);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_173);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_174);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_175);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_176);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_177);
							}
						}
					}
				}
			}
		}
	}
}


}