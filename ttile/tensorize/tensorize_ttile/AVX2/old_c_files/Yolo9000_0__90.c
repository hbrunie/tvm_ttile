#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (8, x); T (1, c);
  T (3, w); T (3, h); T (17, y); T (68, x); T (8, y); T (1, y)]
*/
IND_TYPE c, cp_0, c220_p_0, cp_1, c220, h, hp_0, w, wp_0, x, xp_0, x272_p_0, xp_1, x272, y, yp_0, y302_p_0, y303_p_0, yp_1, y302_p_1, yp_2, y302, y303;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y304 = 0;
IND_TYPE x273 = 0;
IND_TYPE h121 = 0;
IND_TYPE w147 = 0;
IND_TYPE c221 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_1872 ,mem_vec_1873 ,mem_vec_1874 ,mem_vec_1875 ,mem_vec_1876 ,mem_vec_1877 ,mem_vec_1878 ,mem_vec_1879 ,mem_vec_1880 ,mem_vec_1881 ,mem_vec_1882 ,mem_vec_1883 ,mem_vec_1884 ,mem_vec_1885 ,mem_vec_1886 ,mem_vec_1887 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 1) (544 / 544)
for (y303 = y304, y303_p_0 = 0;
	y303 < y304 + 544;
	y303 += 544, y303_p_0 += 544){
	// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (y, 8) (544 / 68)
	for (y302 = y303, y302_p_1 = y303_p_0, y302_p_0 = 0;
		y302 < y303 + 544;
		y302 += 68, y302_p_1 += 68, y302_p_0 += 68){
		// y = 68, x = 544, h = 3, w = 3, c = 3, f = 32
		// T (x, 68) (544 / 8)
		for (x272 = x273, x272_p_0 = 0;
			x272 < x273 + 544;
			x272 += 8, x272_p_0 += 8){
			// y = 68, x = 8, h = 3, w = 3, c = 3, f = 32
			// T (y, 17) (68 / 4)
			for (y = y302, yp_2 = y302_p_1, yp_1 = y302_p_0, yp_0 = 0;
				y < y302 + 68;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 8, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h121, hp_0 = 0;
					h < h121 + 3;
					h += 1, hp_0 += 1){
					// y = 4, x = 8, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w147, wp_0 = 0;
						w < w147 + 3;
						w += 1, wp_0 += 1){
						// y = 4, x = 8, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c220 = c221, c220_p_0 = 0;
							c220 < c221 + 3;
							c220 += 3, c220_p_0 += 3){
							// y = 4, x = 8, h = 1, w = 1, c = 3, f = 32
							// T (x, 8) (8 / 1)
							for (x = x272, xp_1 = x272_p_0, xp_0 = 0;
								x < x272 + 8;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1872 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1873 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_1874 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1875 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_1876 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1877 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_1878 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1879 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_1880 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1881 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_1882 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1883 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_1884 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1885 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_1886 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1887 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c220, cp_1 = c220_p_0, cp_0 = 0;
											c < c220 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1872);
											mem_vec_1872 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1873);
											mem_vec_1873 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1874);
											mem_vec_1874 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1875);
											mem_vec_1875 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1876);
											mem_vec_1876 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1877);
											mem_vec_1877 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1878);
											mem_vec_1878 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1879);
											mem_vec_1879 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1880);
											mem_vec_1880 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1881);
											mem_vec_1881 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1882);
											mem_vec_1882 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1883);
											mem_vec_1883 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1884);
											mem_vec_1884 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1885);
											mem_vec_1885 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1886);
											mem_vec_1886 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1887);
											mem_vec_1887 = vec_23;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1872);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1873);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1874);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1875);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1876);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1877);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1878);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1879);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1880);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1881);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1882);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1883);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1884);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1885);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1886);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1887);
							}
						}
					}
				}
			}
		}
	}
}


}