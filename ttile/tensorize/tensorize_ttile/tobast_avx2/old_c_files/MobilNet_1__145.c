#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (2, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (28, y); T (16, c); T (8, x)]
*/
IND_TYPE c, cp_0, c18_p_0, cp_1, c18, h, hp_0, w, wp_0, x, xp_0, x18_p_0, xp_1, x18, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y12 = 0;
IND_TYPE x19 = 0;
IND_TYPE h12 = 0;
IND_TYPE w12 = 0;
IND_TYPE c19 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_100 ,mem_vec_101 ,mem_vec_102 ,mem_vec_103 ,mem_vec_104 ,mem_vec_105 ,mem_vec_106 ,mem_vec_107 ,mem_vec_108 ,mem_vec_109 ,mem_vec_110 ,mem_vec_111 ,mem_vec_96 ,mem_vec_97 ,mem_vec_98 ,mem_vec_99 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 8) (112 / 14)
for (x18 = x19, x18_p_0 = 0;
	x18 < x19 + 112;
	x18 += 14, x18_p_0 += 14){
	// y = 112, x = 14, h = 3, w = 3, c = 32, f = 32
	// T (c, 16) (32 / 2)
	for (c18 = c19, c18_p_0 = 0;
		c18 < c19 + 32;
		c18 += 2, c18_p_0 += 2){
		// y = 112, x = 14, h = 3, w = 3, c = 2, f = 32
		// T (y, 28) (112 / 4)
		for (y = y12, yp_0 = 0;
			y < y12 + 112;
			y += 4, yp_0 += 4){
			// y = 4, x = 14, h = 3, w = 3, c = 2, f = 32
			// T (h, 3) (3 / 1)
			for (h = h12, hp_0 = 0;
				h < h12 + 3;
				h += 1, hp_0 += 1){
				// y = 4, x = 14, h = 1, w = 3, c = 2, f = 32
				// T (w, 3) (3 / 1)
				for (w = w12, wp_0 = 0;
					w < w12 + 3;
					w += 1, wp_0 += 1){
					// y = 4, x = 14, h = 1, w = 1, c = 2, f = 32
					// T (x, 14) (14 / 1)
					for (x = x18, xp_1 = x18_p_0, xp_0 = 0;
						x < x18 + 14;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_96 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_97 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
								mem_vec_98 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_99 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
								mem_vec_100 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_101 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
								mem_vec_102 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_103 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
								mem_vec_104 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_105 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
								mem_vec_106 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_107 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
								mem_vec_108 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_109 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
								mem_vec_110 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_111 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
								// y = 4, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (c, 2) (2 / 1)
								for (c = c18, cp_1 = c18_p_0, cp_0 = 0;
									c < c18 + 2;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_96);
									mem_vec_96 = vec_0;

									vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_97);
									mem_vec_97 = vec_3;

									vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_98);
									mem_vec_98 = vec_5;

									vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_99);
									mem_vec_99 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm256_set1_ps(scal_1);


									vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_100);
									mem_vec_100 = vec_9;



									vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_101);
									mem_vec_101 = vec_11;



									vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_102);
									mem_vec_102 = vec_12;



									vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_103);
									mem_vec_103 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm256_set1_ps(scal_2);


									vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_104);
									mem_vec_104 = vec_14;



									vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_105);
									mem_vec_105 = vec_16;



									vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_106);
									mem_vec_106 = vec_17;



									vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_107);
									mem_vec_107 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm256_set1_ps(scal_3);


									vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_108);
									mem_vec_108 = vec_19;



									vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_109);
									mem_vec_109 = vec_21;



									vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_110);
									mem_vec_110 = vec_22;



									vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_111);
									mem_vec_111 = vec_23;
								}
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_96);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_97);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_98);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_99);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_100);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_101);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_102);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_103);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_104);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_105);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_106);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_107);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_108);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_109);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_110);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_111);
					}
				}
			}
		}
	}
}


}