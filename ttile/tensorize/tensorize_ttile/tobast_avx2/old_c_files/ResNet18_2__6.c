#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (2, f); T (1, x); T (14, y); T (4, c); T (4, x)]
*/
IND_TYPE c, cp_0, c12_p_0, cp_1, c12, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x16_p_0, x17_p_0, xp_1, x16_p_1, xp_2, x16, x17, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y8 = 0;
IND_TYPE x18 = 0;
IND_TYPE h8 = 0;
IND_TYPE w8 = 0;
IND_TYPE c13 = 0;
IND_TYPE f8 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_64 ,mem_vec_65 ,mem_vec_66 ,mem_vec_67 ,mem_vec_68 ,mem_vec_69 ,mem_vec_70 ,mem_vec_71 ,mem_vec_72 ,mem_vec_73 ,mem_vec_74 ,mem_vec_75 ,mem_vec_76 ,mem_vec_77 ,mem_vec_78 ,mem_vec_79 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 4) (56 / 14)
for (x17 = x18, x17_p_0 = 0;
	x17 < x18 + 56;
	x17 += 14, x17_p_0 += 14){
	// y = 56, x = 14, h = 3, w = 3, c = 64, f = 64
	// T (c, 4) (64 / 16)
	for (c12 = c13, c12_p_0 = 0;
		c12 < c13 + 64;
		c12 += 16, c12_p_0 += 16){
		// y = 56, x = 14, h = 3, w = 3, c = 16, f = 64
		// T (y, 14) (56 / 4)
		for (y = y8, yp_0 = 0;
			y < y8 + 56;
			y += 4, yp_0 += 4){
			// y = 4, x = 14, h = 3, w = 3, c = 16, f = 64
			// T (x, 1) (14 / 14)
			for (x16 = x17, x16_p_1 = x17_p_0, x16_p_0 = 0;
				x16 < x17 + 14;
				x16 += 14, x16_p_1 += 14, x16_p_0 += 14){
				// y = 4, x = 14, h = 3, w = 3, c = 16, f = 64
				// T (f, 2) (64 / 32)
				for (f = f8, fp_0 = 0;
					f < f8 + 64;
					f += 32, fp_0 += 32){
					// y = 4, x = 14, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h8, hp_0 = 0;
						h < h8 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 14, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w8, wp_0 = 0;
							w < w8 + 3;
							w += 1, wp_0 += 1){
							// y = 4, x = 14, h = 1, w = 1, c = 16, f = 32
							// T (x, 14) (14 / 1)
							for (x = x16, xp_2 = x16_p_1, xp_1 = x16_p_0, xp_0 = 0;
								x < x16 + 14;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_64 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_65 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_66 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_67 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_68 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_69 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_70 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_71 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_72 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_73 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_74 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_75 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_76 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_77 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_78 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_79 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c12, cp_1 = c12_p_0, cp_0 = 0;
											c < c12 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_64);
											mem_vec_64 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_65);
											mem_vec_65 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_66);
											mem_vec_66 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_67);
											mem_vec_67 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_68);
											mem_vec_68 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_69);
											mem_vec_69 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_70);
											mem_vec_70 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_71);
											mem_vec_71 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_72);
											mem_vec_72 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_73);
											mem_vec_73 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_74);
											mem_vec_74 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_75);
											mem_vec_75 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_76);
											mem_vec_76 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_77);
											mem_vec_77 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_78);
											mem_vec_78 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_79);
											mem_vec_79 = vec_23;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_64);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_65);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_66);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_67);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_68);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_69);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_70);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_71);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_72);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_73);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_74);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_75);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_76);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_77);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_78);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_79);
							}
						}
					}
				}
			}
		}
	}
}


}