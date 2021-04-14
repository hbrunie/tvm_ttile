
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (7, y); T (2, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (4, y); T (2, f); T (8, c); T (2, f); T (16, c); T (4, x);
  T (1, f)]
*/
IND_TYPE c, cp_0, c184_p_0, c185_p_0, cp_1, c184_p_1, cp_2, c184, c185, f, fp_0, f172_p_0, f173_p_0, fp_1, f172_p_1, fp_2, f172, f173, h, hp_0, w, wp_0, x, xp_0, x138_p_0, xp_1, x138, y, yp_0;
IND_TYPE y92 = 0;
IND_TYPE x139 = 0;
IND_TYPE h92 = 0;
IND_TYPE w92 = 0;
IND_TYPE c186 = 0;
IND_TYPE f174 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1288 ,mem_vec_1289 ,mem_vec_1290 ,mem_vec_1291 ,mem_vec_1292 ,mem_vec_1293 ,mem_vec_1294 ,mem_vec_1295 ,mem_vec_1296 ,mem_vec_1297 ,mem_vec_1298 ,mem_vec_1299 ,mem_vec_1300 ,mem_vec_1301 ,mem_vec_1302 ,mem_vec_1303 ,mem_vec_1304 ,mem_vec_1305 ,mem_vec_1306 ,mem_vec_1307 ,mem_vec_1308 ,mem_vec_1309 ,mem_vec_1310 ,mem_vec_1311 ,mem_vec_1312 ,mem_vec_1313 ,mem_vec_1314 ,mem_vec_1315 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
f173 = 0;
f173_p_0 = 0;
x138 = 0;
x138_p_0 = 0;
c185 = 0;
c185_p_0 = 0;
f172 = 0;
f172_p_1 = 0;
c184 = 0;
c184_p_1 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
							for (h = h92, hp_0 = 0;h < h92 + 3;h += 1, hp_0 += 1){
								// y = 7, x = 7, h = 1, w = 3, c = 2, f = 64
								// T (w, 3) (3 / 1)
								for (w = w92, wp_0 = 0;w < w92 + 3;w += 1, wp_0 += 1){
									// y = 7, x = 7, h = 1, w = 1, c = 2, f = 64
									// T (x, 7) (7 / 1)
									for (x = x138, xp_1 = x138_p_0, xp_0 = 0;x < x138 + 7;x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1288 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_1289 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_1290 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
												mem_vec_1291 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
												mem_vec_1292 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_1293 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_1294 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
												mem_vec_1295 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
												mem_vec_1296 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_1297 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_1298 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
												mem_vec_1299 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
												mem_vec_1300 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_1301 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_1302 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
												mem_vec_1303 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
												mem_vec_1304 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_1305 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_1306 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
												mem_vec_1307 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
												mem_vec_1308 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_1309 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_1310 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
												mem_vec_1311 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
												mem_vec_1312 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_1313 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_1314 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
												mem_vec_1315 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
												// y = 7, x = 1, h = 1, w = 1, c = 2, f = 64
												// T (c, 2) (2 / 1)
												for (c = c184, cp_2 = c184_p_1, cp_1 = c184_p_0, cp_0 = 0;c < c184 + 2;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1288);
													mem_vec_1288 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1289);
													mem_vec_1289 = vec_3;
													vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1290);
													mem_vec_1290 = vec_5;
													vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1291);
													mem_vec_1291 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);
													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1292);
													mem_vec_1292 = vec_9;
													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1293);
													mem_vec_1293 = vec_11;
													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1294);
													mem_vec_1294 = vec_12;
													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1295);
													mem_vec_1295 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1296);
													mem_vec_1296 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1297);
													mem_vec_1297 = vec_16;
													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1298);
													mem_vec_1298 = vec_17;
													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1299);
													mem_vec_1299 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);
													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1300);
													mem_vec_1300 = vec_19;
													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1301);
													mem_vec_1301 = vec_21;
													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1302);
													mem_vec_1302 = vec_22;
													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1303);
													mem_vec_1303 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);
													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1304);
													mem_vec_1304 = vec_24;
													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1305);
													mem_vec_1305 = vec_26;
													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1306);
													mem_vec_1306 = vec_27;
													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1307);
													mem_vec_1307 = vec_28;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);
													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1308);
													mem_vec_1308 = vec_29;
													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1309);
													mem_vec_1309 = vec_31;
													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1310);
													mem_vec_1310 = vec_32;
													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1311);
													mem_vec_1311 = vec_33;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_35 = _mm512_set1_ps(scal_6);
													vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_1312);
													mem_vec_1312 = vec_34;
													vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_1313);
													mem_vec_1313 = vec_36;
													vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_1314);
													mem_vec_1314 = vec_37;
													vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_1315);
													mem_vec_1315 = vec_38;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1288);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1289);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_1290);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_1291);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1292);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1293);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_1294);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_1295);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1296);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1297);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_1298);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_1299);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1300);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1301);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_1302);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_1303);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1304);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1305);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_1306);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_1307);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1308);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1309);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_1310);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_1311);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1312);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_1313);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_1314);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_1315);
									}
								}
							}
}
