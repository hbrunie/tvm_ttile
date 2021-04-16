
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (512, c); Hoist_vars [c]; T (1, x); T (1, y);
  T (16, f); T (2, c); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c105_p_0, cp_1, c105, f, fp_0, x, xp_0, x105_p_0, xp_1, x105, y, yp_0, y105_p_0, yp_1, y105;
IND_TYPE y106 = 0;
IND_TYPE x106 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c106 = 0;
IND_TYPE f70 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1260 ,mem_vec_1261 ,mem_vec_1262 ,mem_vec_1263 ,mem_vec_1264 ,mem_vec_1265 ,mem_vec_1266 ,mem_vec_1267 ,mem_vec_1268 ,mem_vec_1269 ,mem_vec_1270 ,mem_vec_1271 ,mem_vec_1272 ,mem_vec_1273 ,mem_vec_1274 ,mem_vec_1275 ,mem_vec_1276 ,mem_vec_1277 ,mem_vec_1278 ,mem_vec_1279 ,mem_vec_1280 ,mem_vec_1281 ,mem_vec_1282 ,mem_vec_1283 ,mem_vec_1284 ,mem_vec_1285 ,mem_vec_1286 ,mem_vec_1287 ,mem_vec_1288 ,mem_vec_1289 ,mem_vec_1290 ,mem_vec_1291 ,mem_vec_1292 ,mem_vec_1293 ,mem_vec_1294 ,mem_vec_1295 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y105 = 0;
y105_p_0 = 0;
x105 = 0;
x105_p_0 = 0;
c105 = 0;
c105_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_1 = 0;
						for (x = x105, xp_1 = x105_p_0, xp_0 = 0;x < x105 + 1;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1260 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_1261 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_1262 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_1263 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_1264 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_1265 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_1266 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_1267 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_1268 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_1269 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_1270 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_1271 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_1272 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_1273 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_1274 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_1275 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
									// T (c, 512) (512 / 1)
									for (c = c105, cp_1 = c105_p_0, cp_0 = 0;c < c105 + 512;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1260);
										mem_vec_1260 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1261);
										mem_vec_1261 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1262);
										mem_vec_1262 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1263);
										mem_vec_1263 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1264);
										mem_vec_1264 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1265);
										mem_vec_1265 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1266);
										mem_vec_1266 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1267);
										mem_vec_1267 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1268);
										mem_vec_1268 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1269);
										mem_vec_1269 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1270);
										mem_vec_1270 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1271);
										mem_vec_1271 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1272);
										mem_vec_1272 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1273);
										mem_vec_1273 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1274);
										mem_vec_1274 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1275);
										mem_vec_1275 = vec_23;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1260);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_1261);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1262);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_1263);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1264);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_1265);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1266);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_1267);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1268);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_1269);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1270);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_1271);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1272);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_1273);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1274);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_1275);
						}
}
