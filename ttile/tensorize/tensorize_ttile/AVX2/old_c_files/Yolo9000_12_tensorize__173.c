
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (34, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (16, c); T (1, f); T (2, y); T (16, f)]
*/
IND_TYPE c, cp_0, c194_p_0, cp_1, c194, f, fp_0, f156_p_0, f157_p_0, fp_1, f156_p_1, fp_2, f156, f157, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y115_p_0, yp_1, y115;
IND_TYPE y116 = 0;
IND_TYPE x100 = 0;
IND_TYPE h77 = 0;
IND_TYPE w88 = 0;
IND_TYPE c195 = 0;
IND_TYPE f158 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_2168 ,mem_vec_2169 ,mem_vec_2170 ,mem_vec_2171 ,mem_vec_2172 ,mem_vec_2173 ,mem_vec_2174 ,mem_vec_2175 ,mem_vec_2176 ,mem_vec_2177 ,mem_vec_2178 ,mem_vec_2179 ,mem_vec_2180 ,mem_vec_2181 ,mem_vec_2182 ,mem_vec_2183 ,mem_vec_2184 ,mem_vec_2185 ,mem_vec_2186 ,mem_vec_2187 ,mem_vec_2188 ,mem_vec_2189 ,mem_vec_2190 ,mem_vec_2191 ,mem_vec_2192 ,mem_vec_2193 ,mem_vec_2194 ,mem_vec_2195 ,mem_vec_2196 ,mem_vec_2197 ,mem_vec_2198 ,mem_vec_2199 ,mem_vec_2200 ,mem_vec_2201 ,mem_vec_2202 ,mem_vec_2203 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 16) (512 / 32)
f157 = 0;
f157_p_0 = 0;
y115 = 0;
y115_p_0 = 0;
f156 = 0;
f156_p_1 = 0;
c194 = 0;
c194_p_0 = 0;
				for (f = f156, fp_2 = f156_p_1, fp_1 = f156_p_0, fp_0 = 0;f < f156 + 32;f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y115, yp_1 = y115_p_0, yp_0 = 0;y < y115 + 12;y += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (x, 34) (34 / 1)
							for (x = x100, xp_0 = 0;x < x100 + 34;x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h77, hp_0 = 0;h < h77 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
									// T (w, 3) (3 / 1)
									for (w = w88, wp_0 = 0;w < w88 + 3;w += 1, wp_0 += 1){
												mem_vec_2168 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_2169 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_2170 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_2171 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_2172 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_2173 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_2174 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_2175 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_2176 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_2177 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_2178 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_2179 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_2180 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_2181 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_2182 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_2183 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c194, cp_1 = c194_p_0, cp_0 = 0;c < c194 + 16;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2168);
													mem_vec_2168 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2169);
													mem_vec_2169 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2170);
													mem_vec_2170 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2171);
													mem_vec_2171 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2172);
													mem_vec_2172 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2173);
													mem_vec_2173 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2174);
													mem_vec_2174 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2175);
													mem_vec_2175 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2176);
													mem_vec_2176 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2177);
													mem_vec_2177 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2178);
													mem_vec_2178 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2179);
													mem_vec_2179 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2180);
													mem_vec_2180 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2181);
													mem_vec_2181 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2182);
													mem_vec_2182 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2183);
													mem_vec_2183 = vec_23;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2168);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_2169);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2170);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_2171);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2172);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_2173);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2174);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_2175);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2176);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_2177);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2178);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_2179);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2180);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_2181);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2182);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_2183);
									}
								}
							}
						}
						for (y = y115 + 12, yp_1 = y115_p_0, yp_0 = 0;y < y115 + 12 + 5;y += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (x, 34) (34 / 1)
							for (x = x100, xp_0 = 0;x < x100 + 34;x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h77, hp_0 = 0;h < h77 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
									// T (w, 3) (3 / 1)
									for (w = w88, wp_0 = 0;w < w88 + 3;w += 1, wp_0 += 1){
												mem_vec_2184 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_2185 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_2186 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_2187 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_2188 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_2189 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_2190 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_2191 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_2192 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_2193 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_2194 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_2195 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_2196 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_2197 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_2198 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_2199 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												mem_vec_2200 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_2201 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
												mem_vec_2202 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_2203 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c194, cp_1 = c194_p_0, cp_0 = 0;c < c194 + 16;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2184);
													mem_vec_2184 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2185);
													mem_vec_2185 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2186);
													mem_vec_2186 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2187);
													mem_vec_2187 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2188);
													mem_vec_2188 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2189);
													mem_vec_2189 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2190);
													mem_vec_2190 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2191);
													mem_vec_2191 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2192);
													mem_vec_2192 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2193);
													mem_vec_2193 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2194);
													mem_vec_2194 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2195);
													mem_vec_2195 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2196);
													mem_vec_2196 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2197);
													mem_vec_2197 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2198);
													mem_vec_2198 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2199);
													mem_vec_2199 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2200);
													mem_vec_2200 = vec_24;
													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2201);
													mem_vec_2201 = vec_26;
													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2202);
													mem_vec_2202 = vec_27;
													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2203);
													mem_vec_2203 = vec_28;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2184);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_2185);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2186);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_2187);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2188);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_2189);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2190);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_2191);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2192);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_2193);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2194);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_2195);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2196);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_2197);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2198);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_2199);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2200);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_2201);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2202);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_2203);
									}
								}
							}
						}
				}
}
